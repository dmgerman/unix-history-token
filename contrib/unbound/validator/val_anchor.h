begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/val_anchor.h - validator trust anchor storage.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains storage for the trust anchors for the validator.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VAL_ANCHOR_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VAL_ANCHOR_H
end_define

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_include
include|#
directive|include
file|"util/locks.h"
end_include

begin_struct_decl
struct_decl|struct
name|trust_anchor
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_file
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|autr_point_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|autr_global_data
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Trust anchor store.  * The tree must be locked, while no other locks (from trustanchors) are held.  * And then an anchor searched for.  Which can be locked or deleted.  Then  * the tree can be unlocked again.  This means you have to release the lock  * on a trust anchor and look it up again to delete it.  */
end_comment

begin_struct
struct|struct
name|val_anchors
block|{
comment|/** lock on trees */
name|lock_basic_t
name|lock
decl_stmt|;
comment|/** 	 * Anchors are store in this tree. Sort order is chosen, so that 	 * dnames are in nsec-like order. A lookup on class, name will return 	 * an exact match of the closest match, with the ancestor needed. 	 * contents of type trust_anchor. 	 */
name|rbtree_t
modifier|*
name|tree
decl_stmt|;
comment|/** The DLV trust anchor (if one is configured, else NULL) */
name|struct
name|trust_anchor
modifier|*
name|dlv_anchor
decl_stmt|;
comment|/** Autotrust global data, anchors sorted by next probe time */
name|struct
name|autr_global_data
modifier|*
name|autr
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Trust anchor key  */
end_comment

begin_struct
struct|struct
name|ta_key
block|{
comment|/** next in list */
name|struct
name|ta_key
modifier|*
name|next
decl_stmt|;
comment|/** rdata, in wireformat of the key RR. starts with rdlength. */
name|uint8_t
modifier|*
name|data
decl_stmt|;
comment|/** length of the rdata (including rdlength). */
name|size_t
name|len
decl_stmt|;
comment|/** DNS type (host format) of the key, DS or DNSKEY */
name|uint16_t
name|type
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * A trust anchor in the trust anchor store.  * Unique by name, class.  */
end_comment

begin_struct
struct|struct
name|trust_anchor
block|{
comment|/** rbtree node, key is this structure */
name|rbnode_t
name|node
decl_stmt|;
comment|/** lock on the entire anchor and its keys; for autotrust changes */
name|lock_basic_t
name|lock
decl_stmt|;
comment|/** name of this trust anchor */
name|uint8_t
modifier|*
name|name
decl_stmt|;
comment|/** length of name */
name|size_t
name|namelen
decl_stmt|;
comment|/** number of labels in name of rrset */
name|int
name|namelabs
decl_stmt|;
comment|/** the ancestor in the trustanchor tree */
name|struct
name|trust_anchor
modifier|*
name|parent
decl_stmt|;
comment|/**  	 * List of DS or DNSKEY rrs that form the trust anchor. 	 */
name|struct
name|ta_key
modifier|*
name|keylist
decl_stmt|;
comment|/** Autotrust anchor point data, or NULL */
name|struct
name|autr_point_data
modifier|*
name|autr
decl_stmt|;
comment|/** number of DSs in the keylist */
name|size_t
name|numDS
decl_stmt|;
comment|/** number of DNSKEYs in the keylist */
name|size_t
name|numDNSKEY
decl_stmt|;
comment|/** the DS RRset */
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
decl_stmt|;
comment|/** The DNSKEY RRset */
name|struct
name|ub_packed_rrset_key
modifier|*
name|dnskey_rrset
decl_stmt|;
comment|/** class of the trust anchor */
name|uint16_t
name|dclass
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create trust anchor storage  * @return new storage or NULL on error.  */
end_comment

begin_function_decl
name|struct
name|val_anchors
modifier|*
name|anchors_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete trust anchor storage.  * @param anchors: to delete.  */
end_comment

begin_function_decl
name|void
name|anchors_delete
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Process trust anchor config.  * @param anchors: struct anchor storage  * @param cfg: config options.  * @return 0 on error.  */
end_comment

begin_function_decl
name|int
name|anchors_apply_cfg
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|,
name|struct
name|config_file
modifier|*
name|cfg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Recalculate parent pointers.  The caller must hold the lock on the  * anchors structure (say after removing an item from the rbtree).  * Caller must not hold any locks on trust anchors.  * After the call is complete the parent pointers are updated and an item  * just removed is no longer referenced in parent pointers.  * @param anchors: the structure to update.  */
end_comment

begin_function_decl
name|void
name|anchors_init_parents_locked
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Given a qname/qclass combination, find the trust anchor closest above it.  * Or return NULL if none exists.  *  * @param anchors: struct anchor storage  * @param qname: query name, uncompressed wireformat.  * @param qname_len: length of qname.  * @param qclass: class to query for.  * @return the trust anchor or NULL if none is found. The anchor is locked.  */
end_comment

begin_function_decl
name|struct
name|trust_anchor
modifier|*
name|anchors_lookup
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|,
name|uint8_t
modifier|*
name|qname
parameter_list|,
name|size_t
name|qname_len
parameter_list|,
name|uint16_t
name|qclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find a trust anchor. Exact matching.  * @param anchors: anchor storage.  * @param name: name of trust anchor (wireformat)  * @param namelabs: labels in name  * @param namelen: length of name  * @param dclass: class of trust anchor  * @return NULL if not found. The anchor is locked.  */
end_comment

begin_function_decl
name|struct
name|trust_anchor
modifier|*
name|anchor_find
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|int
name|namelabs
parameter_list|,
name|size_t
name|namelen
parameter_list|,
name|uint16_t
name|dclass
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Store one string as trust anchor RR.  * @param anchors: anchor storage.  * @param buffer: parsing buffer, to generate the RR wireformat in.  * @param str: string.  * @return NULL on error.  */
end_comment

begin_function_decl
name|struct
name|trust_anchor
modifier|*
name|anchor_store_str
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buffer
parameter_list|,
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get memory in use by the trust anchor storage  * @param anchors: anchor storage.  * @return memory in use in bytes.  */
end_comment

begin_function_decl
name|size_t
name|anchors_get_mem
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** compare two trust anchors */
end_comment

begin_function_decl
name|int
name|anchor_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|k1
parameter_list|,
specifier|const
name|void
modifier|*
name|k2
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add insecure point trust anchor.  For external use (locks and init_parents)  * @param anchors: anchor storage.  * @param c: class.  * @param nm: name of insecure trust point.  * @return false on alloc failure.  */
end_comment

begin_function_decl
name|int
name|anchors_add_insecure
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|,
name|uint16_t
name|c
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete insecure point trust anchor.  Does not remove if no such point.  * For external use (locks and init_parents)  * @param anchors: anchor storage.  * @param c: class.  * @param nm: name of insecure trust point.  */
end_comment

begin_function_decl
name|void
name|anchors_delete_insecure
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|,
name|uint16_t
name|c
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VAL_ANCHOR_H */
end_comment

end_unit

