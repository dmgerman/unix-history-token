begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/val_neg.h - validator aggressive negative caching functions.  *  * Copyright (c) 2008, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains helper functions for the validator module.  * The functions help with aggressive negative caching.  * This creates new denials of existance, and proofs for absence of types  * from cached NSEC records.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VAL_NEG_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VAL_NEG_H
end_define

begin_include
include|#
directive|include
file|"util/locks.h"
end_include

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|val_neg_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reply_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rrset_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dns_msg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * The negative cache.  It is shared between the threads, so locked.   * Kept as validator-environ-state.  It refers back to the rrset cache for  * data elements.  It can be out of date and contain conflicting data   * from zone content changes.    * It contains a tree of zones, every zone has a tree of data elements.  * The data elements are part of one big LRU list, with one memory counter.  */
end_comment

begin_struct
struct|struct
name|val_neg_cache
block|{
comment|/** the big lock on the negative cache.  Because we use a rbtree  	 * for the data (quick lookup), we need a big lock */
name|lock_basic_t
name|lock
decl_stmt|;
comment|/** The zone rbtree. contents sorted canonical, type val_neg_zone */
name|rbtree_t
name|tree
decl_stmt|;
comment|/** the first in linked list of LRU of val_neg_data */
name|struct
name|val_neg_data
modifier|*
name|first
decl_stmt|;
comment|/** last in lru (least recently used element) */
name|struct
name|val_neg_data
modifier|*
name|last
decl_stmt|;
comment|/** current memory in use (bytes) */
name|size_t
name|use
decl_stmt|;
comment|/** max memory to use (bytes) */
name|size_t
name|max
decl_stmt|;
comment|/** max nsec3 iterations allowed */
name|size_t
name|nsec3_max_iter
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Per Zone aggressive negative caching data.  */
end_comment

begin_struct
struct|struct
name|val_neg_zone
block|{
comment|/** rbtree node element, key is this struct: the name, class */
name|rbnode_t
name|node
decl_stmt|;
comment|/** name; the key */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of name */
name|size_t
name|len
decl_stmt|;
comment|/** labels in name */
name|int
name|labs
decl_stmt|;
comment|/** pointer to parent zone in the negative cache */
name|struct
name|val_neg_zone
modifier|*
name|parent
decl_stmt|;
comment|/** the number of elements, including this one and the ones whose 	 * parents (-parents) include this one, that are in_use  	 * No elements have a count of zero, those are removed. */
name|int
name|count
decl_stmt|;
comment|/** if 0: NSEC zone, else NSEC3 hash algorithm in use */
name|int
name|nsec3_hash
decl_stmt|;
comment|/** nsec3 iteration count in use */
name|size_t
name|nsec3_iter
decl_stmt|;
comment|/** nsec3 salt in use */
name|uint8_t
modifier|*
name|nsec3_salt
decl_stmt|;
comment|/** length of salt in bytes */
name|size_t
name|nsec3_saltlen
decl_stmt|;
comment|/** tree of NSEC data for this zone, sorted canonical  	 * by NSEC owner name */
name|rbtree_t
name|tree
decl_stmt|;
comment|/** class of node; host order */
name|uint16_t
name|dclass
decl_stmt|;
comment|/** if this element is in use, boolean */
name|uint8_t
name|in_use
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Data element for aggressive negative caching.  * The tree of these elements acts as an index onto the rrset cache.  * It shows the NSEC records that (may) exist and are (possibly) secure.  * The rbtree allows for logN search for a covering NSEC record.  * To make tree insertion and deletion logN too, all the parent (one label  * less than the name) data elements are also in the rbtree, with a usage  * count for every data element.  * There is no actual data stored in this data element, if it is in_use,  * then the data can (possibly) be found in the rrset cache.  */
end_comment

begin_struct
struct|struct
name|val_neg_data
block|{
comment|/** rbtree node element, key is this struct: the name */
name|rbnode_t
name|node
decl_stmt|;
comment|/** name; the key */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of name */
name|size_t
name|len
decl_stmt|;
comment|/** labels in name */
name|int
name|labs
decl_stmt|;
comment|/** pointer to parent node in the negative cache */
name|struct
name|val_neg_data
modifier|*
name|parent
decl_stmt|;
comment|/** the number of elements, including this one and the ones whose 	 * parents (-parents) include this one, that are in use  	 * No elements have a count of zero, those are removed. */
name|int
name|count
decl_stmt|;
comment|/** the zone that this denial is part of */
name|struct
name|val_neg_zone
modifier|*
name|zone
decl_stmt|;
comment|/** previous in LRU */
name|struct
name|val_neg_data
modifier|*
name|prev
decl_stmt|;
comment|/** next in LRU (next element was less recently used) */
name|struct
name|val_neg_data
modifier|*
name|next
decl_stmt|;
comment|/** if this element is in use, boolean */
name|uint8_t
name|in_use
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create negative cache  * @param cfg: config options.  * @param maxiter: max nsec3 iterations allowed.  * @return neg cache, empty or NULL on failure.  */
end_comment

begin_function_decl
name|struct
name|val_neg_cache
modifier|*
name|val_neg_create
parameter_list|(
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|,
name|size_t
name|maxiter
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * see how much memory is in use by the negative cache.  * @param neg: negative cache  * @return number of bytes in use.  */
end_comment

begin_function_decl
name|size_t
name|val_neg_get_mem
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Destroy negative cache. There must no longer be any other threads.  * @param neg: negative cache.  */
end_comment

begin_function_decl
name|void
name|neg_cache_delete
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Comparison function for rbtree val neg data elements  */
end_comment

begin_function_decl
name|int
name|val_neg_data_compare
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Comparison function for rbtree val neg zone elements  */
end_comment

begin_function_decl
name|int
name|val_neg_zone_compare
parameter_list|(
specifier|const
name|void
modifier|*
name|a
parameter_list|,
specifier|const
name|void
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert NSECs from this message into the negative cache for reference.  * @param neg: negative cache  * @param rep: reply with NSECs.  * Errors are ignored, means that storage is omitted.  */
end_comment

begin_function_decl
name|void
name|val_neg_addreply
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Insert NSECs from this referral into the negative cache for reference.  * @param neg: negative cache  * @param rep: referral reply with NS, NSECs.  * @param zone: bailiwick for the referral.  * Errors are ignored, means that storage is omitted.  */
end_comment

begin_function_decl
name|void
name|val_neg_addreferral
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|uint8_t
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Perform a DLV style lookup  * During the lookup, we could find out that data has expired. In that  * case the neg_cache entries are removed, and lookup fails.  *  * @param neg: negative cache.  * @param qname: name to look for  * @param len: length of qname.  * @param qclass: class to look in.  * @param rrset_cache: the rrset cache, for NSEC lookups.  * @param now: current time for ttl checks.  * @return   *	0 on error  *	0 if no proof of negative  *	1 if indeed negative was proven  *	  thus, qname DLV qclass does not exist.  */
end_comment

begin_function_decl
name|int
name|val_neg_dlvlookup
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint16_t
name|qclass
parameter_list|,
name|struct
name|rrset_cache
modifier|*
name|rrset_cache
parameter_list|,
name|time_t
name|now
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * For the given query, try to get a reply out of the negative cache.  * The reply still needs to be validated.  * @param neg: negative cache.  * @param qinfo: query  * @param region: where to allocate reply.  * @param rrset_cache: rrset cache.  * @param buf: temporary buffer.  * @param now: to check TTLs against.  * @param addsoa: if true, produce result for external consumption.  *	if false, do not add SOA - for unbound-internal consumption.  * @param topname: do not look higher than this name,   * 	so that the result cannot be taken from a zone above the current  * 	trust anchor.  Which could happen with multiple islands of trust.  * 	if NULL, then no trust anchor is used, but also the algorithm becomes  * 	more conservative, especially for opt-out zones, since the receiver  * 	may have a trust-anchor below the optout and thus the optout cannot  * 	be used to create a proof from the negative cache.  * @return a reply message if something was found.   * 	This reply may still need validation.  * 	NULL if nothing found (or out of memory).  */
end_comment

begin_function_decl
name|struct
name|dns_msg
modifier|*
name|val_neg_getmsg
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinfo
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|rrset_cache
modifier|*
name|rrset_cache
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|time_t
name|now
parameter_list|,
name|int
name|addsoa
parameter_list|,
name|uint8_t
modifier|*
name|topname
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**** functions exposed for unit test ****/
end_comment

begin_comment
comment|/**  * Insert data into the data tree of a zone  * Does not do locking.  * @param neg: negative cache  * @param zone: zone to insert into  * @param nsec: record to insert.  */
end_comment

begin_function_decl
name|void
name|neg_insert_data
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|,
name|struct
name|val_neg_zone
modifier|*
name|zone
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|nsec
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete a data element from the negative cache.  * May delete other data elements to keep tree coherent, or  * only mark the element as 'not in use'.  * Does not do locking.  * @param neg: negative cache.  * @param el: data element to delete.  */
end_comment

begin_function_decl
name|void
name|neg_delete_data
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|,
name|struct
name|val_neg_data
modifier|*
name|el
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find the given zone, from the SOA owner name and class  * Does not do locking.  * @param neg: negative cache  * @param nm: what to look for.  * @param len: length of nm  * @param dclass: class to look for.  * @return zone or NULL if not found.  */
end_comment

begin_function_decl
name|struct
name|val_neg_zone
modifier|*
name|neg_find_zone
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Create a new zone.  * Does not do locking.  * @param neg: negative cache  * @param nm: what to look for.  * @param nm_len: length of name.  * @param dclass: class of zone, host order.  * @return zone or NULL if out of memory.  */
end_comment

begin_function_decl
name|struct
name|val_neg_zone
modifier|*
name|neg_create_zone
parameter_list|(
name|struct
name|val_neg_cache
modifier|*
name|neg
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|,
name|size_t
name|nm_len
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * take a zone into use. increases counts of parents.  * Does not do locking.  * @param zone: zone to take into use.  */
end_comment

begin_function_decl
name|void
name|val_neg_zone_take_inuse
parameter_list|(
name|struct
name|val_neg_zone
modifier|*
name|zone
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VAL_NEG_H */
end_comment

end_unit

