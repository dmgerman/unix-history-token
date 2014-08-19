begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/val_utils.h - validator utility functions.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains helper functions for the validator module.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VAL_UTILS_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VAL_UTILS_H
end_define

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

begin_struct_decl
struct_decl|struct
name|query_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reply_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|val_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|module_env
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ub_packed_rrset_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|key_entry_key
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|val_anchors
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rrset_cache
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sock_list
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Response classifications for the validator. The different types of proofs.  */
end_comment

begin_enum
enum|enum
name|val_classification
block|{
comment|/** Not subtyped yet. */
name|VAL_CLASS_UNTYPED
init|=
literal|0
block|,
comment|/** Not a recognized subtype. */
name|VAL_CLASS_UNKNOWN
block|,
comment|/** A positive, direct, response */
name|VAL_CLASS_POSITIVE
block|,
comment|/** A positive response, with a CNAME/DNAME chain. */
name|VAL_CLASS_CNAME
block|,
comment|/** A NOERROR/NODATA response. */
name|VAL_CLASS_NODATA
block|,
comment|/** A NXDOMAIN response. */
name|VAL_CLASS_NAMEERROR
block|,
comment|/** A CNAME/DNAME chain, and the offset is at the end of it, 	 * but there is no answer here, it can be NAMERROR or NODATA. */
name|VAL_CLASS_CNAMENOANSWER
block|,
comment|/** A referral, from cache with a nonRD query. */
name|VAL_CLASS_REFERRAL
block|,
comment|/** A response to a qtype=ANY query. */
name|VAL_CLASS_ANY
block|}
enum|;
end_enum

begin_comment
comment|/**  * Given a response, classify ANSWER responses into a subtype.  * @param query_flags: query flags for the original query.  * @param origqinf: query info. The original query name.  * @param qinf: query info. The chased query name.  * @param rep: response. The original response.  * @param skip: offset into the original response answer section.  * @return A subtype, all values possible except UNTYPED .  * 	Once CNAME type is returned you can increase skip.  * 	Then, another CNAME type, CNAME_NOANSWER or POSITIVE are possible.  */
end_comment

begin_function_decl
name|enum
name|val_classification
name|val_classify_response
parameter_list|(
name|uint16_t
name|query_flags
parameter_list|,
name|struct
name|query_info
modifier|*
name|origqinf
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinf
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|size_t
name|skip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Given a response, determine the name of the "signer". This is primarily  * to determine if the response is, in fact, signed at all, and, if so, what  * is the name of the most pertinent keyset.  *  * @param subtype: the type from classify.  * @param qinf: query, the chased query name.  * @param rep: response to that, original response.  * @param cname_skip: how many answer rrsets have been skipped due to CNAME  * 	chains being chased around.  * @param signer_name:  signer name, if the response is signed   * 	(even partially), or null if the response isn't signed.  * @param signer_len: length of signer_name of 0 if signer_name is NULL.  */
end_comment

begin_function_decl
name|void
name|val_find_signer
parameter_list|(
name|enum
name|val_classification
name|subtype
parameter_list|,
name|struct
name|query_info
modifier|*
name|qinf
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|size_t
name|cname_skip
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|signer_name
parameter_list|,
name|size_t
modifier|*
name|signer_len
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Verify RRset with keys  * @param env: module environment (scratch buffer)  * @param ve: validator environment (verification settings)  * @param rrset: what to verify  * @param keys: dnskey rrset to verify with.  * @param sigalg: if nonNULL provide downgrade protection otherwise one  *   algorithm is enough.  Algo list is constructed in here.  * @param reason: reason of failure. Fixed string or alloced in scratch.  * @return security status of verification.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|val_verify_rrset
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
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|keys
parameter_list|,
name|uint8_t
modifier|*
name|sigalg
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Verify RRset with keys from a keyset.  * @param env: module environment (scratch buffer)  * @param ve: validator environment (verification settings)  * @param rrset: what to verify  * @param kkey: key_entry to verify with.  * @param reason: reason of failure. Fixed string or alloced in scratch.  * @return security status of verification.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|val_verify_rrset_entry
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
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|struct
name|key_entry_key
modifier|*
name|kkey
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Verify DNSKEYs with DS rrset. Like val_verify_new_DNSKEYs but  * returns a sec_status instead of a key_entry.  * @param env: module environment (scratch buffer)  * @param ve: validator environment (verification settings)  * @param dnskey_rrset: DNSKEY rrset to verify  * @param ds_rrset: DS rrset to verify with.  * @param sigalg: if nonNULL provide downgrade protection otherwise one  *   algorithm is enough.  The list of signalled algorithms is returned,  *   must have enough space for ALGO_NEEDS_MAX+1.  * @param reason: reason of failure. Fixed string or alloced in scratch.  * @return: sec_status_secure if a DS matches.  *     sec_status_insecure if end of trust (i.e., unknown algorithms).  *     sec_status_bogus if it fails.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|val_verify_DNSKEY_with_DS
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
name|ub_packed_rrset_key
modifier|*
name|dnskey_rrset
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
parameter_list|,
name|uint8_t
modifier|*
name|sigalg
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Verify DNSKEYs with DS and DNSKEY rrset.  Like val_verify_DNSKEY_with_DS  * but for a trust anchor.  * @param env: module environment (scratch buffer)  * @param ve: validator environment (verification settings)  * @param dnskey_rrset: DNSKEY rrset to verify  * @param ta_ds: DS rrset to verify with.  * @param ta_dnskey: DNSKEY rrset to verify with.  * @param sigalg: if nonNULL provide downgrade protection otherwise one  *   algorithm is enough.  The list of signalled algorithms is returned,  *   must have enough space for ALGO_NEEDS_MAX+1.  * @param reason: reason of failure. Fixed string or alloced in scratch.  * @return: sec_status_secure if a DS matches.  *     sec_status_insecure if end of trust (i.e., unknown algorithms).  *     sec_status_bogus if it fails.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|val_verify_DNSKEY_with_TA
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
name|ub_packed_rrset_key
modifier|*
name|dnskey_rrset
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ta_ds
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ta_dnskey
parameter_list|,
name|uint8_t
modifier|*
name|sigalg
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Verify new DNSKEYs with DS rrset. The DS contains hash values that should  * match the DNSKEY keys.  * match the DS to a DNSKEY and verify the DNSKEY rrset with that key.  *  * @param region: where to allocate key entry result.  * @param env: module environment (scratch buffer)  * @param ve: validator environment (verification settings)  * @param dnskey_rrset: DNSKEY rrset to verify  * @param ds_rrset: DS rrset to verify with.  * @param downprot: if true provide downgrade protection otherwise one  *   algorithm is enough.  * @param reason: reason of failure. Fixed string or alloced in scratch.  * @return a KeyEntry. This will either contain the now trusted  *         dnskey_rrset, a "null" key entry indicating that this DS  *         rrset/DNSKEY pair indicate an secure end to the island of trust  *         (i.e., unknown algorithms), or a "bad" KeyEntry if the dnskey  *         rrset fails to verify. Note that the "null" response should  *         generally only occur in a private algorithm scenario: normally  *         this sort of thing is checked before fetching the matching DNSKEY  *         rrset.  *         if downprot is set, a key entry with an algo list is made.  */
end_comment

begin_function_decl
name|struct
name|key_entry_key
modifier|*
name|val_verify_new_DNSKEYs
parameter_list|(
name|struct
name|regional
modifier|*
name|region
parameter_list|,
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
name|ub_packed_rrset_key
modifier|*
name|dnskey_rrset
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
parameter_list|,
name|int
name|downprot
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Verify rrset with trust anchor: DS and DNSKEY rrset.  *  * @param region: where to allocate key entry result.  * @param env: module environment (scratch buffer)  * @param ve: validator environment (verification settings)  * @param dnskey_rrset: DNSKEY rrset to verify  * @param ta_ds_rrset: DS rrset to verify with.  * @param ta_dnskey_rrset: the DNSKEY rrset to verify with.  * @param downprot: if true provide downgrade protection otherwise one  *   algorithm is enough.  * @param reason: reason of failure. Fixed string or alloced in scratch.  * @return a KeyEntry. This will either contain the now trusted  *         dnskey_rrset, a "null" key entry indicating that this DS  *         rrset/DNSKEY pair indicate an secure end to the island of trust  *         (i.e., unknown algorithms), or a "bad" KeyEntry if the dnskey  *         rrset fails to verify. Note that the "null" response should  *         generally only occur in a private algorithm scenario: normally  *         this sort of thing is checked before fetching the matching DNSKEY  *         rrset.  *         if downprot is set, a key entry with an algo list is made.  */
end_comment

begin_function_decl
name|struct
name|key_entry_key
modifier|*
name|val_verify_new_DNSKEYs_with_ta
parameter_list|(
name|struct
name|regional
modifier|*
name|region
parameter_list|,
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
name|ub_packed_rrset_key
modifier|*
name|dnskey_rrset
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ta_ds_rrset
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ta_dnskey_rrset
parameter_list|,
name|int
name|downprot
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine if DS rrset is usable for validator or not.  * Returns true if the algorithms for key and DShash are supported,  * for at least one RR.  *  * @param ds_rrset: the newly received DS rrset.  * @return true or false if not usable.  */
end_comment

begin_function_decl
name|int
name|val_dsset_isusable
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Determine by looking at a signed RRset whether or not the RRset name was  * the result of a wildcard expansion. If so, return the name of the  * generating wildcard.  *   * @param rrset The rrset to chedck.  * @param wc: the wildcard name, if the rrset was synthesized from a wildcard.  *         unchanged if not.  The wildcard name, without "*." in front, is   *         returned. This is a pointer into the rrset owner name.  * @return false if the signatures are inconsistent in indicating the   * 	wildcard status; possible spoofing of wildcard response for other  * 	responses is being tried. We lost the status which rrsig was verified  * 	after the verification routine finished, so we simply check if  * 	the signatures are consistent; inserting a fake signature is a denial  * 	of service; but in that you could also have removed the real   * 	signature anyway.  */
end_comment

begin_function_decl
name|int
name|val_rrset_wildcard
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|wc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Chase the cname to the next query name.  * @param qchase: the current query name, updated to next target.  * @param rep: original message reply to look at CNAMEs.  * @param cname_skip: the skip into the answer section. Updated to skip  * 	DNAME and CNAME to the next part of the answer.  * @return false on error (bad rdata).  */
end_comment

begin_function_decl
name|int
name|val_chase_cname
parameter_list|(
name|struct
name|query_info
modifier|*
name|qchase
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|size_t
modifier|*
name|cname_skip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Fill up the chased reply with the content from the original reply;  * as pointers to those rrsets. Select the part after the cname_skip into  * the answer section, NS and AR sections that are signed with same signer.  *  * @param chase: chased reply, filled up.  * @param orig: original reply.  * @param cname_skip: which part of the answer section to skip.  * 	The skipped part contains CNAME(and DNAME)s that have been chased.  * @param name: the signer name to look for.  * @param len: length of name.  * @param signer: signer name or NULL if an unsigned RRset is considered.  *	If NULL, rrsets with the lookup name are copied over.  */
end_comment

begin_function_decl
name|void
name|val_fill_reply
parameter_list|(
name|struct
name|reply_info
modifier|*
name|chase
parameter_list|,
name|struct
name|reply_info
modifier|*
name|orig
parameter_list|,
name|size_t
name|cname_skip
parameter_list|,
name|uint8_t
modifier|*
name|name
parameter_list|,
name|size_t
name|len
parameter_list|,
name|uint8_t
modifier|*
name|signer
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Remove all unsigned or non-secure status rrsets from NS and AR sections.  * So that unsigned data does not get let through to clients, when we have  * found the data to be secure.  *  * @param ve: validator environment with cleaning options.  * @param rep: reply to dump all nonsecure stuff out of.  */
end_comment

begin_function_decl
name|void
name|val_check_nonsecure
parameter_list|(
name|struct
name|val_env
modifier|*
name|ve
parameter_list|,
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Mark all unchecked rrset entries not below a trust anchor as indeterminate.  * Only security==unchecked rrsets are updated.  * @param rep: the reply with rrsets.  * @param anchors: the trust anchors.  * @param r: rrset cache to store updated security status into.  * @param env: module environment  */
end_comment

begin_function_decl
name|void
name|val_mark_indeterminate
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|struct
name|val_anchors
modifier|*
name|anchors
parameter_list|,
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|struct
name|module_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Mark all unchecked rrset entries below a NULL key entry as insecure.  * Only security==unchecked rrsets are updated.  * @param rep: the reply with rrsets.  * @param kname: end of secure space name.  * @param r: rrset cache to store updated security status into.  * @param env: module environment  */
end_comment

begin_function_decl
name|void
name|val_mark_insecure
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|uint8_t
modifier|*
name|kname
parameter_list|,
name|struct
name|rrset_cache
modifier|*
name|r
parameter_list|,
name|struct
name|module_env
modifier|*
name|env
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find next unchecked rrset position, return it for skip.  * @param rep: the original reply to look into.  * @param skip: the skip now.  * @return new skip, which may be at the rep->rrset_count position to signal  * 	there are no unchecked items.  */
end_comment

begin_function_decl
name|size_t
name|val_next_unchecked
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|size_t
name|skip
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find the signer name for an RRset.  * @param rrset: the rrset.  * @param sname: signer name is returned or NULL if not signed.  * @param slen: length of sname (or 0).  */
end_comment

begin_function_decl
name|void
name|val_find_rrset_signer
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|uint8_t
modifier|*
modifier|*
name|sname
parameter_list|,
name|size_t
modifier|*
name|slen
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get string to denote the classification result.  * @param subtype: from classification function.  * @return static string to describe the classification.  */
end_comment

begin_function_decl
specifier|const
name|char
modifier|*
name|val_classification_to_string
parameter_list|(
name|enum
name|val_classification
name|subtype
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Add existing list to blacklist.  * @param blacklist: the blacklist with result  * @param region: the region where blacklist is allocated.  *	Allocation failures are logged.  * @param origin: origin list to add, if NULL, a cache-entry is added to  *   the blacklist to stop cache from being used.  * @param cross: if true this is a cross-qstate copy, and the 'origin'  *   list is not allocated in the same region as the blacklist.  */
end_comment

begin_function_decl
name|void
name|val_blacklist
parameter_list|(
name|struct
name|sock_list
modifier|*
modifier|*
name|blacklist
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|sock_list
modifier|*
name|origin
parameter_list|,
name|int
name|cross
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * check if has dnssec info, and if it has signed nsecs. gives error reason.  * @param rep: reply to check.  * @param reason: returned on fail.  * @return false if message has no signed nsecs.  Can not prove negatives.  */
end_comment

begin_function_decl
name|int
name|val_has_signed_nsecs
parameter_list|(
name|struct
name|reply_info
modifier|*
name|rep
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Return algo number for favorite (best) algorithm that we support in DS.  * @param ds_rrset: the DSes in this rrset are inspected and best algo chosen.  * @return algo number or 0 if none supported. 0 is unused as algo number.  */
end_comment

begin_function_decl
name|int
name|val_favorite_ds_algo
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Find DS denial message in cache.  Saves new qstate allocation and allows  * the validator to use partial content which is not enough to construct a  * message for network (or user) consumption.  Without SOA for example,  * which is a common occurence in the unbound code since the referrals contain  * NSEC/NSEC3 rrs without the SOA element, thus do not allow synthesis of a  * full negative reply, but do allow synthesis of sufficient proof.  * @param env: query env with caches and time.  * @param nm: name of DS record sought.  * @param nmlen: length of name.  * @param c: class of DS RR.  * @param region: where to allocate result.  * @param topname: name of the key that is currently in use, that will get  *	used to validate the result, and thus no higher entries from the  *	negative cache need to be examined.  * @return a dns_msg on success. NULL on failure.  */
end_comment

begin_function_decl
name|struct
name|dns_msg
modifier|*
name|val_find_DS
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|uint8_t
modifier|*
name|nm
parameter_list|,
name|size_t
name|nmlen
parameter_list|,
name|uint16_t
name|c
parameter_list|,
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|uint8_t
modifier|*
name|topname
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VAL_UTILS_H */
end_comment

end_unit

