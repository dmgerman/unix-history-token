begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/storage/lruhash.h - hashtable, hash function, LRU keeping.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains a hashtable with LRU keeping of entries.  *  * The hash table keeps a maximum memory size. Old entries are removed  * to make space for new entries.  *  * The locking strategy is as follows:  * 	o since (almost) every read also implies a LRU update, the  *	  hashtable lock is a spinlock, not rwlock.  *	o the idea is to move every thread through the hash lock quickly,  *	  so that the next thread can access the lookup table.  *	o User performs hash function.  *  * For read:  *	o lock hashtable.  *		o lookup hash bin.  *		o lock hash bin.  *			o find entry (if failed, unlock hash, unl bin, exit).  *			o swizzle pointers for LRU update.  *		o unlock hashtable.  *		o lock entry (rwlock).  *		o unlock hash bin.  *		o work on entry.  *	o unlock entry.  *  * To update an entry, gain writelock and change the entry.  * (the entry must keep the same hashvalue, so a data update.)  * (you cannot upgrade a readlock to a writelock, because the item may  *  be deleted, it would cause race conditions. So instead, unlock and  *  relookup it in the hashtable.)  *  * To delete an entry:  *	o unlock the entry if you hold the lock already.  *	o lock hashtable.  *		o lookup hash bin.  *		o lock hash bin.  *			o find entry (if failed, unlock hash, unl bin, exit).  *			o remove entry from hashtable bin overflow chain.  *		o unlock hashtable.  *		o lock entry (writelock).  *		o unlock hash bin.  *	o unlock entry (nobody else should be waiting for this lock,  *	  since you removed it from hashtable, and you got writelock while  *	  holding the hashbinlock so you are the only one.)  * 	  Note you are only allowed to obtain a lock while holding hashbinlock.  *	o delete entry.  *  * The above sequence is:  *	o race free, works with read, write and delete.  *	o but has a queue, imagine someone needing a writelock on an item.  *	  but there are still readlocks. The writelocker waits, but holds  *	  the hashbinlock. The next thread that comes in and needs the same  * 	  hashbin will wait for the lock while holding the hashtable lock.  *	  thus halting the entire system on hashtable.  *	  This is because of the delete protection.   *	  Readlocks will be easier on the rwlock on entries.  *	  While the writer is holding writelock, similar problems happen with  *	  a reader or writer needing the same item.  *	  the scenario requires more than three threads.  * 	o so the queue length is 3 threads in a bad situation. The fourth is  *	  unable to use the hashtable.  *  * If you need to acquire locks on multiple items from the hashtable.  *	o you MUST release all locks on items from the hashtable before  *	  doing the next lookup/insert/delete/whatever.  *	o To acquire multiple items you should use a special routine that  *	  obtains the locks on those multiple items in one go.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_STORAGE_LRUHASH_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_STORAGE_LRUHASH_H
end_define

begin_include
include|#
directive|include
file|"util/locks.h"
end_include

begin_struct_decl
struct_decl|struct
name|lruhash_bin
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|lruhash_entry
struct_decl|;
end_struct_decl

begin_comment
comment|/** default start size for hash arrays */
end_comment

begin_define
define|#
directive|define
name|HASH_DEFAULT_STARTARRAY
value|1024
end_define

begin_comment
comment|/* entries in array */
end_comment

begin_comment
comment|/** default max memory for hash arrays */
end_comment

begin_define
define|#
directive|define
name|HASH_DEFAULT_MAXMEM
value|4*1024*1024
end_define

begin_comment
comment|/* bytes */
end_comment

begin_comment
comment|/** the type of a hash value */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|hashvalue_t
typedef|;
end_typedef

begin_comment
comment|/**   * Type of function that calculates the size of an entry.  * Result must include the size of struct lruhash_entry.   * Keys that are identical must also calculate to the same size.  * size = func(key, data).  */
end_comment

begin_typedef
typedef|typedef
name|size_t
function_decl|(
modifier|*
name|lruhash_sizefunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** type of function that compares two keys. return 0 if equal. */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|lruhash_compfunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** old keys are deleted.   * The RRset type has to revoke its ID number, markdel() is used first.  * This function is called: func(key, userarg) */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|lruhash_delkeyfunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** old data is deleted. This function is called: func(data, userarg). */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|lruhash_deldatafunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/** mark a key as pending to be deleted (and not to be used by anyone).   * called: func(key) */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|lruhash_markdelfunc_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**  * Hash table that keeps LRU list of entries.  */
end_comment

begin_struct
struct|struct
name|lruhash
block|{
comment|/** lock for exclusive access, to the lookup array */
name|lock_quick_t
name|lock
decl_stmt|;
comment|/** the size function for entries in this table */
name|lruhash_sizefunc_t
name|sizefunc
decl_stmt|;
comment|/** the compare function for entries in this table. */
name|lruhash_compfunc_t
name|compfunc
decl_stmt|;
comment|/** how to delete keys. */
name|lruhash_delkeyfunc_t
name|delkeyfunc
decl_stmt|;
comment|/** how to delete data. */
name|lruhash_deldatafunc_t
name|deldatafunc
decl_stmt|;
comment|/** how to mark a key pending deletion */
name|lruhash_markdelfunc_t
name|markdelfunc
decl_stmt|;
comment|/** user argument for user functions */
name|void
modifier|*
name|cb_arg
decl_stmt|;
comment|/** the size of the lookup array */
name|size_t
name|size
decl_stmt|;
comment|/** size bitmask - since size is a power of 2 */
name|int
name|size_mask
decl_stmt|;
comment|/** lookup array of bins */
name|struct
name|lruhash_bin
modifier|*
name|array
decl_stmt|;
comment|/** the lru list, start and end, noncyclical double linked list. */
name|struct
name|lruhash_entry
modifier|*
name|lru_start
decl_stmt|;
comment|/** lru list end item (least recently used) */
name|struct
name|lruhash_entry
modifier|*
name|lru_end
decl_stmt|;
comment|/** the number of entries in the hash table. */
name|size_t
name|num
decl_stmt|;
comment|/** the amount of space used, roughly the number of bytes in use. */
name|size_t
name|space_used
decl_stmt|;
comment|/** the amount of space the hash table is maximally allowed to use. */
name|size_t
name|space_max
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * A single bin with a linked list of entries in it.  */
end_comment

begin_struct
struct|struct
name|lruhash_bin
block|{
comment|/**  	 * Lock for exclusive access to the linked list 	 * This lock makes deletion of items safe in this overflow list. 	 */
name|lock_quick_t
name|lock
decl_stmt|;
comment|/** linked list of overflow entries */
name|struct
name|lruhash_entry
modifier|*
name|overflow_list
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * An entry into the hash table.  * To change overflow_next you need to hold the bin lock.  * To change the lru items you need to hold the hashtable lock.  * This structure is designed as part of key struct. And key pointer helps  * to get the surrounding structure. Data should be allocated on its own.  */
end_comment

begin_struct
struct|struct
name|lruhash_entry
block|{
comment|/**  	 * rwlock for access to the contents of the entry 	 * Note that it does _not_ cover the lru_ and overflow_ ptrs. 	 * Even with a writelock, you cannot change hash and key. 	 * You need to delete it to change hash or key. 	 */
name|lock_rw_t
name|lock
decl_stmt|;
comment|/** next entry in overflow chain. Covered by hashlock and binlock. */
name|struct
name|lruhash_entry
modifier|*
name|overflow_next
decl_stmt|;
comment|/** next entry in lru chain. covered by hashlock. */
name|struct
name|lruhash_entry
modifier|*
name|lru_next
decl_stmt|;
comment|/** prev entry in lru chain. covered by hashlock. */
name|struct
name|lruhash_entry
modifier|*
name|lru_prev
decl_stmt|;
comment|/** hash value of the key. It may not change, until entry deleted. */
name|hashvalue_t
name|hash
decl_stmt|;
comment|/** key */
name|void
modifier|*
name|key
decl_stmt|;
comment|/** data */
name|void
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create new hash table.  * @param start_size: size of hashtable array at start, must be power of 2.  * @param maxmem: maximum amount of memory this table is allowed to use.  * @param sizefunc: calculates memory usage of entries.  * @param compfunc: compares entries, 0 on equality.  * @param delkeyfunc: deletes key.  *   Calling both delkey and deldata will also free the struct lruhash_entry.  *   Make it part of the key structure and delete it in delkeyfunc.  * @param deldatafunc: deletes data.   * @param arg: user argument that is passed to user function calls.  * @return: new hash table or NULL on malloc failure.  */
end_comment

begin_function_decl
name|struct
name|lruhash
modifier|*
name|lruhash_create
parameter_list|(
name|size_t
name|start_size
parameter_list|,
name|size_t
name|maxmem
parameter_list|,
name|lruhash_sizefunc_t
name|sizefunc
parameter_list|,
name|lruhash_compfunc_t
name|compfunc
parameter_list|,
name|lruhash_delkeyfunc_t
name|delkeyfunc
parameter_list|,
name|lruhash_deldatafunc_t
name|deldatafunc
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete hash table. Entries are all deleted.  * @param table: to delete.  */
end_comment

begin_function_decl
name|void
name|lruhash_delete
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Clear hash table. Entries are all deleted, while locking them before   * doing so. At end the table is empty.  * @param table: to make empty.  */
end_comment

begin_function_decl
name|void
name|lruhash_clear
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert a new element into the hashtable.   * If key is already present data pointer in that entry is updated.  * The space calculation function is called with the key, data.  * If necessary the least recently used entries are deleted to make space.  * If necessary the hash array is grown up.  *  * @param table: hash table.  * @param hash: hash value. User calculates the hash.  * @param entry: identifies the entry.  * 	If key already present, this entry->key is deleted immediately.  *	But entry->data is set to NULL before deletion, and put into  * 	the existing entry. The data is then freed.  * @param data: the data.  * @param cb_override: if not null overrides the cb_arg for the deletefunc.  */
end_comment

begin_function_decl
name|void
name|lruhash_insert
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|hashvalue_t
name|hash
parameter_list|,
name|struct
name|lruhash_entry
modifier|*
name|entry
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|void
modifier|*
name|cb_override
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup an entry in the hashtable.  * At the end of the function you hold a (read/write)lock on the entry.  * The LRU is updated for the entry (if found).  * @param table: hash table.  * @param hash: hash of key.  * @param key: what to look for, compared against entries in overflow chain.  *    the hash value must be set, and must work with compare function.  * @param wr: set to true if you desire a writelock on the entry.  *    with a writelock you can update the data part.  * @return: pointer to the entry or NULL. The entry is locked.  *    The user must unlock the entry when done.  */
end_comment

begin_function_decl
name|struct
name|lruhash_entry
modifier|*
name|lruhash_lookup
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|hashvalue_t
name|hash
parameter_list|,
name|void
modifier|*
name|key
parameter_list|,
name|int
name|wr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Touch entry, so it becomes the most recently used in the LRU list.  * Caller must hold hash table lock. The entry must be inserted already.  * @param table: hash table.  * @param entry: entry to make first in LRU.  */
end_comment

begin_function_decl
name|void
name|lru_touch
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|struct
name|lruhash_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set the markdelfunction (or NULL)  */
end_comment

begin_function_decl
name|void
name|lruhash_setmarkdel
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|lruhash_markdelfunc_t
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/************************* Internal functions ************************/
end_comment

begin_comment
comment|/*** these are only exposed for unit tests. ***/
end_comment

begin_comment
comment|/**  * Remove entry from hashtable. Does nothing if not found in hashtable.  * Delfunc is called for the entry.  * @param table: hash table.  * @param hash: hash of key.  * @param key: what to look for.   */
end_comment

begin_function_decl
name|void
name|lruhash_remove
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|hashvalue_t
name|hash
parameter_list|,
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** init the hash bins for the table */
end_comment

begin_function_decl
name|void
name|bin_init
parameter_list|(
name|struct
name|lruhash_bin
modifier|*
name|array
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** delete the hash bin and entries inside it */
end_comment

begin_function_decl
name|void
name|bin_delete
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|struct
name|lruhash_bin
modifier|*
name|bin
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Find entry in hash bin. You must have locked the bin.  * @param table: hash table with function pointers.  * @param bin: hash bin to look into.  * @param hash: hash value to look for.  * @param key: key to look for.  * @return: the entry or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|lruhash_entry
modifier|*
name|bin_find_entry
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|struct
name|lruhash_bin
modifier|*
name|bin
parameter_list|,
name|hashvalue_t
name|hash
parameter_list|,
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove entry from bin overflow chain.  * You must have locked the bin.  * @param bin: hash bin to look into.  * @param entry: entry ptr that needs removal.  */
end_comment

begin_function_decl
name|void
name|bin_overflow_remove
parameter_list|(
name|struct
name|lruhash_bin
modifier|*
name|bin
parameter_list|,
name|struct
name|lruhash_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Split hash bin into two new ones. Based on increased size_mask.  * Caller must hold hash table lock.  * At the end the routine acquires all hashbin locks (in the old array).  * This makes it wait for other threads to finish with the bins.  * So the bins are ready to be deleted after this function.  * @param table: hash table with function pointers.  * @param newa: new increased array.  * @param newmask: new lookup mask.  */
end_comment

begin_function_decl
name|void
name|bin_split
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|struct
name|lruhash_bin
modifier|*
name|newa
parameter_list|,
name|int
name|newmask
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Try to make space available by deleting old entries.  * Assumes that the lock on the hashtable is being held by caller.  * Caller must not hold bin locks.  * @param table: hash table.  * @param list: list of entries that are to be deleted later.  *	Entries have been removed from the hash table and writelock is held.  */
end_comment

begin_function_decl
name|void
name|reclaim_space
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|struct
name|lruhash_entry
modifier|*
modifier|*
name|list
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Grow the table lookup array. Becomes twice as large.  * Caller must hold the hash table lock. Must not hold any bin locks.  * Tries to grow, on malloc failure, nothing happened.  * @param table: hash table.  */
end_comment

begin_function_decl
name|void
name|table_grow
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Put entry at front of lru. entry must be unlinked from lru.  * Caller must hold hash table lock.  * @param table: hash table with lru head and tail.  * @param entry: entry to make most recently used.  */
end_comment

begin_function_decl
name|void
name|lru_front
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|struct
name|lruhash_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove entry from lru list.  * Caller must hold hash table lock.  * @param table: hash table with lru head and tail.  * @param entry: entry to remove from lru.  */
end_comment

begin_function_decl
name|void
name|lru_remove
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
name|struct
name|lruhash_entry
modifier|*
name|entry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Output debug info to the log as to state of the hash table.  * @param table: hash table.  * @param id: string printed with table to identify the hash table.  * @param extended: set to true to print statistics on overflow bin lengths.  */
end_comment

begin_function_decl
name|void
name|lruhash_status
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|,
specifier|const
name|char
modifier|*
name|id
parameter_list|,
name|int
name|extended
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory in use now by the lruhash table.  * @param table: hash table. Will be locked before use. And unlocked after.  * @return size in bytes.  */
end_comment

begin_function_decl
name|size_t
name|lruhash_get_mem
parameter_list|(
name|struct
name|lruhash
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Traverse a lruhash. Call back for every element in the table.  * @param h: hash table.  Locked before use.  * @param wr: if true writelock is obtained on element, otherwise readlock.  * @param func: function for every element. Do not lock or unlock elements.  * @param arg: user argument to func.  */
end_comment

begin_function_decl
name|void
name|lruhash_traverse
parameter_list|(
name|struct
name|lruhash
modifier|*
name|h
parameter_list|,
name|int
name|wr
parameter_list|,
name|void
function_decl|(
modifier|*
name|func
function_decl|)
parameter_list|(
name|struct
name|lruhash_entry
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_STORAGE_LRUHASH_H */
end_comment

end_unit

