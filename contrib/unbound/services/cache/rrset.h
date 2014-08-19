begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * services/cache/rrset.h - Resource record set cache.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains the rrset cache.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SERVICES_CACHE_RRSET_H
end_ifndef

begin_define
define|#
directive|define
name|SERVICES_CACHE_RRSET_H
end_define

begin_include
include|#
directive|include
file|"util/storage/lruhash.h"
end_include

begin_include
include|#
directive|include
file|"util/storage/slabhash.h"
end_include

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|alloc_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rrset_ref
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * The rrset cache  * Thin wrapper around hashtable, like a typedef.  */
end_comment

begin_struct
struct|struct
name|rrset_cache
block|{
comment|/** uses partitioned hash table */
name|struct
name|slabhash
name|table
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create rrset cache  * @param cfg: config settings or NULL for defaults.  * @param alloc: initial default rrset key allocation.  * @return: NULL on error.  */
end_comment

begin_function_decl
name|struct
name|rrset_cache
modifier|*
name|rrset_cache_create
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete rrset cache  * @param r: rrset cache to delete.  */
end_comment

begin_function_decl
name|void
name|rrset_cache_delete
parameter_list|(
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Adjust settings of the cache to settings from the config file.  * May purge the cache. May recreate the cache.  * There may be no threading or use by other threads.  * @param r: rrset cache to adjust (like realloc).  * @param cfg: config settings or NULL for defaults.  * @param alloc: initial default rrset key allocation.  * @return 0 on error, or new rrset cache pointer on success.  */
end_comment

begin_function_decl
name|struct
name|rrset_cache
modifier|*
name|rrset_cache_adjust
parameter_list|(
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Touch rrset, with given pointer and id.  * Caller may not hold a lock on ANY rrset, this could give deadlock.  *  * This routine is faster than a hashtable lookup:  *	o no bin_lock is acquired.  *	o no walk through the bin-overflow-list.   *	o no comparison of the entry key to find it.  *  * @param r: rrset cache.  * @param key: rrset key. Marked recently used (if it was not deleted  *	before the lock is acquired, in that case nothing happens).  * @param hash: hash value of the item. Please read it from the key when  *	you have it locked. Used to find slab from slabhash.  * @param id: used to check that the item is unchanged and not deleted.  */
end_comment

begin_function_decl
name|void
name|rrset_cache_touch
parameter_list|(
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|key
parameter_list|,
name|hashvalue_t
name|hash
parameter_list|,
name|rrset_id_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Update an rrset in the rrset cache. Stores the information for later use.  * Will lookup if the rrset is in the cache and perform an update if necessary.  * If the item was present, and superior, references are returned to that.  * The passed item is then deallocated with rrset_parsedelete.  *  * A superior rrset is:  *	o rrset with better trust value.  *	o same trust value, different rdata, newly passed rrset is inserted.  * If rdata is the same, TTL in the cache is updated.  *  * @param r: the rrset cache.  * @param ref: reference (ptr and id) to the rrset. Pass reference setup for  *	the new rrset. The reference may be changed if the cached rrset is  *	superior.  *	Before calling the rrset is presumed newly allocated and changeable.  *	Afer calling you do not hold a lock, and the rrset is inserted in  *	the hashtable so you need a lock to change it.  * @param alloc: how to allocate (and deallocate) the special rrset key.  * @param timenow: current time (to see if ttl in cache is expired).  * @return: true if the passed reference is updated, false if it is unchanged.  * 	0: reference unchanged, inserted in cache.  * 	1: reference updated, item is inserted in cache.  * 	2: reference updated, item in cache is considered superior.  *	   also the rdata is equal (but other parameters in cache are superior).  */
end_comment

begin_function_decl
name|int
name|rrset_cache_update
parameter_list|(
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|struct
name|rrset_ref
modifier|*
name|ref
parameter_list|,
name|struct
name|alloc_cache
modifier|*
name|alloc
parameter_list|,
name|time_t
name|timenow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Lookup rrset. You obtain read/write lock. You must unlock before lookup  * anything of else.  * @param r: the rrset cache.  * @param qname: name of rrset to lookup.  * @param qnamelen: length of name of rrset to lookup.  * @param qtype: type of rrset to lookup (host order).  * @param qclass: class of rrset to lookup (host order).  * @param flags: rrset flags, or 0.  * @param timenow: used to compare with TTL.  * @param wr: set true to get writelock.  * @return packed rrset key pointer. Remember to unlock the key.entry.lock.  * 	or NULL if could not be found or it was timed out.  */
end_comment

begin_function_decl
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset_cache_lookup
parameter_list|(
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|size_t
name|qnamelen
parameter_list|,
name|uint16_t
name|qtype
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|uint32_t
name|flags
parameter_list|,
name|time_t
name|timenow
parameter_list|,
name|int
name|wr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Obtain readlock on a (sorted) list of rrset references.  * Checks TTLs and IDs of the rrsets and rollbacks locking if not Ok.  * @param ref: array of rrset references (key pointer and ID value).  *	duplicate references are allowed and handled.  * @param count: size of array.  * @param timenow: used to compare with TTL.  * @return true on success, false on a failure, which can be that some  * 	RRsets have timed out, or that they do not exist any more, the  *	RRsets have been purged from the cache.  *	If true, you hold readlocks on all the ref items.   */
end_comment

begin_function_decl
name|int
name|rrset_array_lock
parameter_list|(
name|struct
name|rrset_ref
modifier|*
name|ref
parameter_list|,
name|size_t
name|count
parameter_list|,
name|time_t
name|timenow
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Unlock array (sorted) of rrset references.  * @param ref: array of rrset references (key pointer and ID value).  *	duplicate references are allowed and handled.  * @param count: size of array.  */
end_comment

begin_function_decl
name|void
name|rrset_array_unlock
parameter_list|(
name|struct
name|rrset_ref
modifier|*
name|ref
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Unlock array (sorted) of rrset references and at the same time  * touch LRU on the rrsets. It needs the scratch region for temporary  * storage as it uses the initial locks to obtain hash values.  * @param r: the rrset cache. In this cache LRU is updated.  * @param scratch: region for temporary storage of hash values.  *	if memory allocation fails, the lru touch fails silently,  *	but locks are released. memory errors are logged.  * @param ref: array of rrset references (key pointer and ID value).  *	duplicate references are allowed and handled.  * @param count: size of array.  */
end_comment

begin_function_decl
name|void
name|rrset_array_unlock_touch
parameter_list|(
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|struct
name|regional
modifier|*
name|scratch
parameter_list|,
name|struct
name|rrset_ref
modifier|*
name|ref
parameter_list|,
name|size_t
name|count
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Update security status of an rrset. Looks up the rrset.  * If found, checks if rdata is equal.  * If so, it will update the security, trust and rrset-ttl values.  * The values are only updated if security is increased (towards secure).  * @param r: the rrset cache.   * @param rrset: which rrset to attempt to update. This rrset is left   * 	untouched. The rrset in the cache is updated in-place.  * @param now: current time.  */
end_comment

begin_function_decl
name|void
name|rrset_update_sec_status
parameter_list|(
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Looks up security status of an rrset. Looks up the rrset.  * If found, checks if rdata is equal, and entry did not expire.  * If so, it will update the security, trust and rrset-ttl values.  * @param r: the rrset cache.   * @param rrset: This rrset may change security status due to the cache.  * 	But its status will only improve, towards secure.  * @param now: current time.  */
end_comment

begin_function_decl
name|void
name|rrset_check_sec_status
parameter_list|(
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove an rrset from the cache, by name and type and flags  * @param r: rrset cache  * @param nm: name of rrset  * @param nmlen: length of name  * @param type: type of rrset  * @param dclass: class of rrset, host order  * @param flags: flags of rrset, host order  */
end_comment

begin_function_decl
name|void
name|rrset_cache_remove
parameter_list|(
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|,
name|size_t
name|nmlen
parameter_list|,
name|uint16_t
name|type
parameter_list|,
name|uint16_t
name|dclass
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** mark rrset to be deleted, set id=0 */
end_comment

begin_function_decl
name|void
name|rrset_markdel
parameter_list|(
name|void
modifier|*
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SERVICES_CACHE_RRSET_H */
end_comment

end_unit

