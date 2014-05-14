begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * util/storage/slabhash.h - hashtable consisting of several smaller tables.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * Hash table that consists of smaller hash tables.  * It cannot grow, but that gives it the ability to have multiple  * locks. Also this means there are multiple LRU lists.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UTIL_STORAGE_SLABHASH_H
end_ifndef

begin_define
define|#
directive|define
name|UTIL_STORAGE_SLABHASH_H
end_define

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_comment
comment|/** default number of slabs */
end_comment

begin_define
define|#
directive|define
name|HASH_DEFAULT_SLABS
value|4
end_define

begin_comment
comment|/**  * Hash table formed from several smaller ones.   * This results in a partitioned lruhash table, a 'slashtable'.  * None of the data inside the slabhash may be altered.  * Therefore, no locks are needed to access the structure.  */
end_comment

begin_struct
struct|struct
name|slabhash
block|{
comment|/** the size of the array - must be power of 2 */
name|size_t
name|size
decl_stmt|;
comment|/** size bitmask - uses high bits. */
name|uint32_t
name|mask
decl_stmt|;
comment|/** shift right this many bits to get index into array. */
name|unsigned
name|int
name|shift
decl_stmt|;
comment|/** lookup array of hash tables */
name|struct
name|lruhash
modifier|*
modifier|*
name|array
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create new slabbed hash table.  * @param numtables: number of hash tables to use, other parameters used to  *	initialize these smaller hashtables.  * @param start_size: size of hashtable array at start, must be power of 2.  * @param maxmem: maximum amount of memory this table is allowed to use.  *	so every table gets maxmem/numtables to use for itself.  * @param sizefunc: calculates memory usage of entries.  * @param compfunc: compares entries, 0 on equality.  * @param delkeyfunc: deletes key.  * @param deldatafunc: deletes data.   * @param arg: user argument that is passed to user function calls.  * @return: new hash table or NULL on malloc failure.  */
end_comment

begin_function_decl
name|struct
name|slabhash
modifier|*
name|slabhash_create
parameter_list|(
name|size_t
name|numtables
parameter_list|,
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
name|slabhash_delete
parameter_list|(
name|struct
name|slabhash
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Clear hash table. Entries are all deleted.  * @param table: to make empty.  */
end_comment

begin_function_decl
name|void
name|slabhash_clear
parameter_list|(
name|struct
name|slabhash
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert a new element into the hashtable, uses lruhash_insert.   * If key is already present data pointer in that entry is updated.  *  * @param table: hash table.  * @param hash: hash value. User calculates the hash.  * @param entry: identifies the entry.  * 	If key already present, this entry->key is deleted immediately.  *	But entry->data is set to NULL before deletion, and put into  * 	the existing entry. The data is then freed.  * @param data: the data.  * @param cb_override: if not NULL overrides the cb_arg for deletfunc.  */
end_comment

begin_function_decl
name|void
name|slabhash_insert
parameter_list|(
name|struct
name|slabhash
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
comment|/**  * Lookup an entry in the hashtable. Uses lruhash_lookup.  * At the end of the function you hold a (read/write)lock on the entry.  * The LRU is updated for the entry (if found).  * @param table: hash table.  * @param hash: hash of key.  * @param key: what to look for, compared against entries in overflow chain.  *    the hash value must be set, and must work with compare function.  * @param wr: set to true if you desire a writelock on the entry.  *    with a writelock you can update the data part.  * @return: pointer to the entry or NULL. The entry is locked.  *    The user must unlock the entry when done.  */
end_comment

begin_function_decl
name|struct
name|lruhash_entry
modifier|*
name|slabhash_lookup
parameter_list|(
name|struct
name|slabhash
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
comment|/**  * Remove entry from hashtable. Does nothing if not found in hashtable.  * Delfunc is called for the entry. Uses lruhash_remove.  * @param table: hash table.  * @param hash: hash of key.  * @param key: what to look for.   */
end_comment

begin_function_decl
name|void
name|slabhash_remove
parameter_list|(
name|struct
name|slabhash
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
comment|/**  * Output debug info to the log as to state of the hash table.  * @param table: hash table.  * @param id: string printed with table to identify the hash table.  * @param extended: set to true to print statistics on overflow bin lengths.  */
end_comment

begin_function_decl
name|void
name|slabhash_status
parameter_list|(
name|struct
name|slabhash
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
comment|/**  * Retrieve slab hash total size.  * @param table: hash table.  * @return size configured as max.  */
end_comment

begin_function_decl
name|size_t
name|slabhash_get_size
parameter_list|(
name|struct
name|slabhash
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Retrieve slab hash current memory use.  * @param table: hash table.  * @return memory in use.  */
end_comment

begin_function_decl
name|size_t
name|slabhash_get_mem
parameter_list|(
name|struct
name|slabhash
modifier|*
name|table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get lruhash table for a given hash value  * @param table: slabbed hash table.  * @param hash: hash value.  * @return the lru hash table.  */
end_comment

begin_function_decl
name|struct
name|lruhash
modifier|*
name|slabhash_gettable
parameter_list|(
name|struct
name|slabhash
modifier|*
name|table
parameter_list|,
name|hashvalue_t
name|hash
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Set markdel function  * @param table: slabbed hash table.  * @param md: markdel function ptr.  */
end_comment

begin_function_decl
name|void
name|slabhash_setmarkdel
parameter_list|(
name|struct
name|slabhash
modifier|*
name|table
parameter_list|,
name|lruhash_markdelfunc_t
name|md
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Traverse a slabhash.  * @param table: slabbed hash table.  * @param wr: if true, writelock is obtained, otherwise readlock.  * @param func: function to call for every element.  * @param arg: user argument to function.  */
end_comment

begin_function_decl
name|void
name|slabhash_traverse
parameter_list|(
name|struct
name|slabhash
modifier|*
name|table
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

begin_comment
comment|/* --- test representation --- */
end_comment

begin_comment
comment|/** test structure contains test key */
end_comment

begin_struct
struct|struct
name|slabhash_testkey
block|{
comment|/** the key id */
name|int
name|id
decl_stmt|;
comment|/** the entry */
name|struct
name|lruhash_entry
name|entry
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** test structure contains test data */
end_comment

begin_struct
struct|struct
name|slabhash_testdata
block|{
comment|/** data value */
name|int
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/** test sizefunc for lruhash */
end_comment

begin_function_decl
name|size_t
name|test_slabhash_sizefunc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** test comparefunc for lruhash */
end_comment

begin_function_decl
name|int
name|test_slabhash_compfunc
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** test delkey for lruhash */
end_comment

begin_function_decl
name|void
name|test_slabhash_delkey
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** test deldata for lruhash */
end_comment

begin_function_decl
name|void
name|test_slabhash_deldata
parameter_list|(
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* --- end test representation --- */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTIL_STORAGE_SLABHASH_H */
end_comment

end_unit

