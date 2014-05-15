begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/validator.h - secure validator DNS query response module  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains a module that performs validation of DNS queries.  * According to RFC 4034.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VALIDATOR_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VALIDATOR_H
end_define

begin_include
include|#
directive|include
file|"util/module.h"
end_include

begin_include
include|#
directive|include
file|"util/data/msgreply.h"
end_include

begin_include
include|#
directive|include
file|"validator/val_utils.h"
end_include

begin_struct_decl
struct_decl|struct
name|val_anchors
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|key_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|key_entry_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|val_neg_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|config_strlist
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * This is the TTL to use when a trust anchor fails to prime. A trust anchor  * will be primed no more often than this interval.  Used when harden-  * dnssec-stripped is off and the trust anchor fails.  */
end_comment

begin_define
define|#
directive|define
name|NULL_KEY_TTL
value|60
end_define

begin_comment
comment|/* seconds */
end_comment

begin_comment
comment|/**  * TTL for bogus key entries.  When a DS or DNSKEY fails in the chain of  * trust the entire zone for that name is blacked out for this TTL.  */
end_comment

begin_define
define|#
directive|define
name|BOGUS_KEY_TTL
value|60
end_define

begin_comment
comment|/* seconds */
end_comment

begin_comment
comment|/** max number of query restarts, number of IPs to probe */
end_comment

begin_define
define|#
directive|define
name|VAL_MAX_RESTART_COUNT
value|5
end_define

begin_comment
comment|/**  * Global state for the validator.   */
end_comment

begin_struct
struct|struct
name|val_env
block|{
comment|/** key cache; these are validated keys. trusted keys only 	 * end up here after being primed. */
name|struct
name|key_cache
modifier|*
name|kcache
decl_stmt|;
comment|/** aggressive negative cache. index into NSECs in rrset cache. */
name|struct
name|val_neg_cache
modifier|*
name|neg_cache
decl_stmt|;
comment|/** for debug testing a fixed validation date can be entered. 	 * if 0, current time is used for rrsig validation */
name|int32_t
name|date_override
decl_stmt|;
comment|/** clock skew min for signatures */
name|int32_t
name|skew_min
decl_stmt|;
comment|/** clock skew max for signatures */
name|int32_t
name|skew_max
decl_stmt|;
comment|/** TTL for bogus data; used instead of untrusted TTL from data. 	 * Bogus data will not be verified more often than this interval.  	 * seconds. */
name|uint32_t
name|bogus_ttl
decl_stmt|;
comment|/** If set, the validator should clean the additional section of 	 * secure messages. 	 */
name|int
name|clean_additional
decl_stmt|;
comment|/** 	 * If set, the validator will not make messages bogus, instead 	 * indeterminate is issued, so that no clients receive SERVFAIL. 	 * This allows an operator to run validation 'shadow' without 	 * hurting responses to clients. 	 */
name|int
name|permissive_mode
decl_stmt|;
comment|/** 	 * Number of entries in the NSEC3 maximum iteration count table. 	 * Keep this table short, and sorted by size 	 */
name|int
name|nsec3_keyiter_count
decl_stmt|;
comment|/** 	 * NSEC3 maximum iteration count per signing key size. 	 * This array contains key size values (in increasing order) 	 */
name|size_t
modifier|*
name|nsec3_keysize
decl_stmt|;
comment|/** 	 * NSEC3 maximum iteration count per signing key size. 	 * This array contains the maximum iteration count for the keysize 	 * in the keysize array. 	 */
name|size_t
modifier|*
name|nsec3_maxiter
decl_stmt|;
comment|/** lock on bogus counter */
name|lock_basic_t
name|bogus_lock
decl_stmt|;
comment|/** number of times rrsets marked bogus */
name|size_t
name|num_rrset_bogus
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * State of the validator for a query.  */
end_comment

begin_enum
enum|enum
name|val_state
block|{
comment|/** initial state for validation */
name|VAL_INIT_STATE
init|=
literal|0
block|,
comment|/** find the proper keys for validation, follow trust chain */
name|VAL_FINDKEY_STATE
block|,
comment|/** validate the answer, using found key entry */
name|VAL_VALIDATE_STATE
block|,
comment|/** finish up */
name|VAL_FINISHED_STATE
block|,
comment|/** DLV lookup state, processing DLV queries */
name|VAL_DLVLOOKUP_STATE
block|}
enum|;
end_enum

begin_comment
comment|/**  * Per query state for the validator module.  */
end_comment

begin_struct
struct|struct
name|val_qstate
block|{
comment|/**  	 * State of the validator module. 	 */
name|enum
name|val_state
name|state
decl_stmt|;
comment|/** 	 * The original message we have been given to validate. 	 */
name|struct
name|dns_msg
modifier|*
name|orig_msg
decl_stmt|;
comment|/** 	 * The query restart count 	 */
name|int
name|restart_count
decl_stmt|;
comment|/** The blacklist saved for chainoftrust elements */
name|struct
name|sock_list
modifier|*
name|chain_blacklist
decl_stmt|;
comment|/** 	 * The query name we have chased to; qname after following CNAMEs 	 */
name|struct
name|query_info
name|qchase
decl_stmt|;
comment|/** 	 * The chased reply, extract from original message. Can be: 	 * 	o CNAME 	 * 	o DNAME + CNAME 	 * 	o answer  	 * 	plus authority, additional (nsecs) that have same signature. 	 */
name|struct
name|reply_info
modifier|*
name|chase_reply
decl_stmt|;
comment|/** 	 * The cname skip value; the number of rrsets that have been skipped 	 * due to chasing cnames. This is the offset into the  	 * orig_msg->rep->rrsets array, into the answer section. 	 * starts at 0 - for the full original message. 	 * if it is>0 - qchase followed the cname, chase_reply setup to be 	 * that message and relevant authority rrsets. 	 * 	 * The skip is also used for referral messages, where it will 	 * range from 0, over the answer, authority and additional sections. 	 */
name|size_t
name|rrset_skip
decl_stmt|;
comment|/** trust anchor name */
name|uint8_t
modifier|*
name|trust_anchor_name
decl_stmt|;
comment|/** trust anchor labels */
name|int
name|trust_anchor_labs
decl_stmt|;
comment|/** trust anchor length */
name|size_t
name|trust_anchor_len
decl_stmt|;
comment|/** the DS rrset */
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
decl_stmt|;
comment|/** domain name for empty nonterminal detection */
name|uint8_t
modifier|*
name|empty_DS_name
decl_stmt|;
comment|/** length of empty_DS_name */
name|size_t
name|empty_DS_len
decl_stmt|;
comment|/** the current key entry */
name|struct
name|key_entry_key
modifier|*
name|key_entry
decl_stmt|;
comment|/** subtype */
name|enum
name|val_classification
name|subtype
decl_stmt|;
comment|/** signer name */
name|uint8_t
modifier|*
name|signer_name
decl_stmt|;
comment|/** length of signer_name */
name|size_t
name|signer_len
decl_stmt|;
comment|/** true if this state is waiting to prime a trust anchor */
name|int
name|wait_prime_ta
decl_stmt|;
comment|/** have we already checked the DLV? */
name|int
name|dlv_checked
decl_stmt|;
comment|/** The name for which the DLV is looked up. For the current message 	 * or for the current RRset (for CNAME, REFERRAL types). 	 * If there is signer name, that may be it, else a domain name */
name|uint8_t
modifier|*
name|dlv_lookup_name
decl_stmt|;
comment|/** length of dlv lookup name */
name|size_t
name|dlv_lookup_name_len
decl_stmt|;
comment|/** Name at which chain of trust stopped with insecure, starting DLV 	 * DLV must result in chain going further down */
name|uint8_t
modifier|*
name|dlv_insecure_at
decl_stmt|;
comment|/** length of dlv insecure point name */
name|size_t
name|dlv_insecure_at_len
decl_stmt|;
comment|/** status of DLV lookup. Indication to VAL_DLV_STATE what to do */
enum|enum
name|dlv_status
block|{
name|dlv_error
block|,
comment|/* server failure */
name|dlv_success
block|,
comment|/* got a DLV */
name|dlv_ask_higher
block|,
comment|/* ask again */
name|dlv_there_is_no_dlv
comment|/* got no DLV, sure of it */
block|}
name|dlv_status
enum|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Get the validator function block.  * @return: function block with function pointers to validator methods.  */
end_comment

begin_function_decl
name|struct
name|module_func_block
modifier|*
name|val_get_funcblock
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get validator state as a string  * @param state: to convert  * @return constant string that is printable.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|val_state_to_string
parameter_list|(
name|enum
name|val_state
name|state
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** validator init */
end_comment

begin_function_decl
name|int
name|val_init
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** validator deinit */
end_comment

begin_function_decl
name|void
name|val_deinit
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** validator operate on a query */
end_comment

begin_function_decl
name|void
name|val_operate
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|enum
name|module_ev
name|event
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|outbound_entry
modifier|*
name|outbound
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * inform validator super.  *   * @param qstate: query state that finished.  * @param id: module id.  * @param super: the qstate to inform.  */
end_comment

begin_function_decl
name|void
name|val_inform_super
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|,
name|struct
name|module_qstate
modifier|*
name|super
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** validator cleanup query state */
end_comment

begin_function_decl
name|void
name|val_clear
parameter_list|(
name|struct
name|module_qstate
modifier|*
name|qstate
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Debug helper routine that assists worker in determining memory in   * use.  * @param env: module environment   * @param id: module id.  * @return memory in use in bytes.  */
end_comment

begin_function_decl
name|size_t
name|val_get_mem
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VALIDATOR_H */
end_comment

end_unit

