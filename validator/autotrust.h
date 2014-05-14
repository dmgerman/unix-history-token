begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/autotrust.h - RFC5011 trust anchor management for unbound.  *  * Copyright (c) 2009, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * Contains autotrust definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_AUTOTRUST_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_AUTOTRUST_H
end_define

begin_include
include|#
directive|include
file|"util/rbtree.h"
end_include

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

begin_struct_decl
struct_decl|struct
name|val_anchors
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|trust_anchor
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|val_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/** Autotrust anchor states */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|AUTR_STATE_START
init|=
literal|0
block|,
name|AUTR_STATE_ADDPEND
init|=
literal|1
block|,
name|AUTR_STATE_VALID
init|=
literal|2
block|,
name|AUTR_STATE_MISSING
init|=
literal|3
block|,
name|AUTR_STATE_REVOKED
init|=
literal|4
block|,
name|AUTR_STATE_REMOVED
init|=
literal|5
block|}
name|autr_state_t
typedef|;
end_typedef

begin_comment
comment|/**   * Autotrust metadata for one trust anchor key.  */
end_comment

begin_struct
struct|struct
name|autr_ta
block|{
comment|/** next key */
name|struct
name|autr_ta
modifier|*
name|next
decl_stmt|;
comment|/** the RR */
name|uint8_t
modifier|*
name|rr
decl_stmt|;
comment|/** length of rr */
name|size_t
name|rr_len
decl_stmt|,
name|dname_len
decl_stmt|;
comment|/** last update of key state (new pending count keeps date the same) */
name|time_t
name|last_change
decl_stmt|;
comment|/** 5011 state */
name|autr_state_t
name|s
decl_stmt|;
comment|/** pending count */
name|uint8_t
name|pending_count
decl_stmt|;
comment|/** fresh TA was seen */
name|uint8_t
name|fetched
decl_stmt|;
comment|/** revoked TA was seen */
name|uint8_t
name|revoked
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Autotrust metadata for a trust point.  * This is part of the struct trust_anchor data.  */
end_comment

begin_struct
struct|struct
name|autr_point_data
block|{
comment|/** file to store the trust point in. chrootdir already applied. */
name|char
modifier|*
name|file
decl_stmt|;
comment|/** rbtree node for probe sort, key is struct trust_anchor */
name|rbnode_t
name|pnode
decl_stmt|;
comment|/** the keys */
name|struct
name|autr_ta
modifier|*
name|keys
decl_stmt|;
comment|/** last queried DNSKEY set  	 * Not all failures are captured in this entry. 	 * If the validator did not even start (e.g. timeout or localservfail), 	 * then the last_queried and query_failed values are not updated. 	 */
name|time_t
name|last_queried
decl_stmt|;
comment|/** last successful DNSKEY set */
name|time_t
name|last_success
decl_stmt|;
comment|/** next probe time */
name|time_t
name|next_probe_time
decl_stmt|;
comment|/** when to query if !failed */
name|time_t
name|query_interval
decl_stmt|;
comment|/** when to retry if failed */
name|time_t
name|retry_time
decl_stmt|;
comment|/**  	 * How many times did it fail. diagnostic only (has no effect). 	 * Only updated if there was a dnskey rrset that failed to verify. 	 */
name|uint8_t
name|query_failed
decl_stmt|;
comment|/** true if the trust point has been revoked */
name|uint8_t
name|revoked
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**   * Autotrust global metadata.  */
end_comment

begin_struct
struct|struct
name|autr_global_data
block|{
comment|/** rbtree of autotrust anchors sorted by next probe time. 	 * When time is equal, sorted by anchor class, name. */
name|rbtree_t
name|probe
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Create new global 5011 data structure.  * @return new structure or NULL on malloc failure.  */
end_comment

begin_function_decl
name|struct
name|autr_global_data
modifier|*
name|autr_global_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete global 5011 data structure.  * @param global: global autotrust state to delete.  */
end_comment

begin_function_decl
name|void
name|autr_global_delete
parameter_list|(
name|struct
name|autr_global_data
modifier|*
name|global
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See if autotrust anchors are configured and how many.  * @param anchors: the trust anchors structure.  * @return number of autotrust trust anchors  */
end_comment

begin_function_decl
name|size_t
name|autr_get_num_anchors
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Process probe timer.  Add new probes if needed.  * @param env: module environment with time, with anchors and with the mesh.  * @return time of next probe (in seconds from now).  * 	If 0, then there is no next probe anymore (trust points deleted).  */
end_comment

begin_function_decl
name|time_t
name|autr_probe_timer
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** probe tree compare function */
end_comment

begin_function_decl
name|int
name|probetree_cmp
parameter_list|(
specifier|const
name|void
modifier|*
name|x
parameter_list|,
specifier|const
name|void
modifier|*
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Read autotrust file.  * @param anchors: the anchors structure.  * @param nm: name of the file (copied).  * @return false on failure.  */
end_comment

begin_function_decl
name|int
name|autr_read_file
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|,
specifier|const
name|char
modifier|*
name|nm
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Write autotrust file.  * @param env: environment with scratch space.  * @param tp: trust point to write.  */
end_comment

begin_function_decl
name|void
name|autr_write_file
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|trust_anchor
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Delete autr anchor, deletes the autr data but does not do  * unlinking from trees, caller does that.  * @param tp: trust point to delete.  */
end_comment

begin_function_decl
name|void
name|autr_point_delete
parameter_list|(
name|struct
name|trust_anchor
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Perform autotrust processing.  * @param env: qstate environment with the anchors structure.  * @param ve: validator environment for verification of rrsigs.  * @param tp: trust anchor to process.  * @param dnskey_rrset: DNSKEY rrset probed (can be NULL if bad prime result).  * 	allocated in a region. Has not been validated yet.  * @return false if trust anchor was revoked completely.  * 	Otherwise logs errors to log, does not change return value.  * 	On errors, likely the trust point has been unchanged.  */
end_comment

begin_function_decl
name|int
name|autr_process_prime
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|val_env
modifier|*
name|ve
parameter_list|,
name|struct
name|trust_anchor
modifier|*
name|tp
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|dnskey_rrset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Debug printout of rfc5011 tracked anchors  * @param anchors: all the anchors.  */
end_comment

begin_function_decl
name|void
name|autr_debug_print
parameter_list|(
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** callback for query answer to 5011 probe */
end_comment

begin_function_decl
name|void
name|probe_answer_cb
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|int
name|rcode
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|enum
name|sec_status
name|sec
parameter_list|,
name|char
modifier|*
name|errinf
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_AUTOTRUST_H */
end_comment

end_unit

