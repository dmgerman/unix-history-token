begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/val_sigcrypt.h - validator signature crypto functions.  *  * Copyright (c) 2007, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains helper functions for the validator module.  * The functions help with signature verification and checking, the  * bridging between RR wireformat data and crypto calls.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VAL_SIGCRYPT_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VAL_SIGCRYPT_H
end_define

begin_include
include|#
directive|include
file|"util/data/packed_rrset.h"
end_include

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
name|rbtree_t
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|regional
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/** number of entries in algorithm needs array */
end_comment

begin_define
define|#
directive|define
name|ALGO_NEEDS_MAX
value|256
end_define

begin_comment
comment|/**  * Storage for algorithm needs.  DNSKEY algorithms.  */
end_comment

begin_struct
struct|struct
name|algo_needs
block|{
comment|/** the algorithms (8-bit) with each a number. 	 * 0: not marked. 	 * 1: marked 'necessary but not yet fulfilled' 	 * 2: marked bogus. 	 * Indexed by algorithm number. 	 */
name|uint8_t
name|needs
index|[
name|ALGO_NEEDS_MAX
index|]
decl_stmt|;
comment|/** the number of entries in the array that are unfulfilled */
name|size_t
name|num
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * Initialize algo needs structure, set algos from rrset as needed.  * Results are added to an existing need structure.  * @param n: struct with storage.  * @param dnskey: algos from this struct set as necessary. DNSKEY set.  * @param sigalg: adds to signalled algorithm list too.  */
end_comment

begin_function_decl
name|void
name|algo_needs_init_dnskey_add
parameter_list|(
name|struct
name|algo_needs
modifier|*
name|n
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|dnskey
parameter_list|,
name|uint8_t
modifier|*
name|sigalg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize algo needs structure from a signalled algo list.  * @param n: struct with storage.  * @param sigalg: signalled algorithm list, numbers ends with 0.  */
end_comment

begin_function_decl
name|void
name|algo_needs_init_list
parameter_list|(
name|struct
name|algo_needs
modifier|*
name|n
parameter_list|,
name|uint8_t
modifier|*
name|sigalg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Initialize algo needs structure, set algos from rrset as needed.  * @param n: struct with storage.  * @param ds: algos from this struct set as necessary. DS set.  * @param fav_ds_algo: filter to use only this DS algo.  * @param sigalg: list of signalled algos, constructed as output,  *	provide size ALGO_NEEDS_MAX+1. list of algonumbers, ends with a zero.  */
end_comment

begin_function_decl
name|void
name|algo_needs_init_ds
parameter_list|(
name|struct
name|algo_needs
modifier|*
name|n
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds
parameter_list|,
name|int
name|fav_ds_algo
parameter_list|,
name|uint8_t
modifier|*
name|sigalg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Mark this algorithm as a success, sec_secure, and see if we are done.  * @param n: storage structure processed.  * @param algo: the algorithm processed to be secure.  * @return if true, processing has finished successfully, we are satisfied.  */
end_comment

begin_function_decl
name|int
name|algo_needs_set_secure
parameter_list|(
name|struct
name|algo_needs
modifier|*
name|n
parameter_list|,
name|uint8_t
name|algo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Mark this algorithm a failure, sec_bogus.  It can later be overridden  * by a success for this algorithm (with a different signature).  * @param n: storage structure processed.  * @param algo: the algorithm processed to be bogus.  */
end_comment

begin_function_decl
name|void
name|algo_needs_set_bogus
parameter_list|(
name|struct
name|algo_needs
modifier|*
name|n
parameter_list|,
name|uint8_t
name|algo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See how many algorithms are missing (not bogus or secure, but not processed)  * @param n: storage structure processed.  * @return number of algorithms missing after processing.  */
end_comment

begin_function_decl
name|size_t
name|algo_needs_num_missing
parameter_list|(
name|struct
name|algo_needs
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * See which algo is missing.  * @param n: struct after processing.  * @return if 0 an algorithm was bogus, if a number, this algorithm was  *   missing.  So on 0, report why that was bogus, on number report a missing  *   algorithm.  There could be multiple missing, this reports the first one.  */
end_comment

begin_function_decl
name|int
name|algo_needs_missing
parameter_list|(
name|struct
name|algo_needs
modifier|*
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Format error reason for algorithm missing.  * @param env: module env with scratch for temp storage of string.  * @param alg: DNSKEY-algorithm missing.  * @param reason: destination.  * @param s: string, appended with 'with algorithm ..'.  */
end_comment

begin_function_decl
name|void
name|algo_needs_reason
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|int
name|alg
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|,
name|char
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Check if dnskey matches a DS digest   * Does not check dnskey-keyid footprint, just the digest.  * @param env: module environment. Uses scratch space.  * @param dnskey_rrset: DNSKEY rrset.  * @param dnskey_idx: index of RR in rrset.  * @param ds_rrset: DS rrset  * @param ds_idx: index of RR in DS rrset.  * @return true if it matches, false on error, not supported or no match.  */
end_comment

begin_function_decl
name|int
name|ds_digest_match_dnskey
parameter_list|(
name|struct
name|module_env
modifier|*
name|env
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|dnskey_rrset
parameter_list|,
name|size_t
name|dnskey_idx
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
parameter_list|,
name|size_t
name|ds_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Get dnskey keytag, footprint value  * @param dnskey_rrset: DNSKEY rrset.  * @param dnskey_idx: index of RR in rrset.  * @return the keytag or 0 for badly formatted DNSKEYs.  */
end_comment

begin_function_decl
name|uint16_t
name|dnskey_calc_keytag
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|dnskey_rrset
parameter_list|,
name|size_t
name|dnskey_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get DS keytag, footprint value that matches the DNSKEY keytag it signs.  * @param ds_rrset: DS rrset  * @param ds_idx: index of RR in DS rrset.  * @return the keytag or 0 for badly formatted DSs.  */
end_comment

begin_function_decl
name|uint16_t
name|ds_get_keytag
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
parameter_list|,
name|size_t
name|ds_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * See if DNSKEY algorithm is supported   * @param dnskey_rrset: DNSKEY rrset.  * @param dnskey_idx: index of RR in rrset.  * @return true if supported.  */
end_comment

begin_function_decl
name|int
name|dnskey_algo_is_supported
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|dnskey_rrset
parameter_list|,
name|size_t
name|dnskey_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * See if DS digest algorithm is supported   * @param ds_rrset: DS rrset  * @param ds_idx: index of RR in DS rrset.  * @return true if supported.  */
end_comment

begin_function_decl
name|int
name|ds_digest_algo_is_supported
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
parameter_list|,
name|size_t
name|ds_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get DS RR digest algorithm  * @param ds_rrset: DS rrset.  * @param ds_idx: which DS.  * @return algorithm or 0 if DS too short.  */
end_comment

begin_function_decl
name|int
name|ds_get_digest_algo
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
parameter_list|,
name|size_t
name|ds_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * See if DS key algorithm is supported   * @param ds_rrset: DS rrset  * @param ds_idx: index of RR in DS rrset.  * @return true if supported.  */
end_comment

begin_function_decl
name|int
name|ds_key_algo_is_supported
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|ds_rrset
parameter_list|,
name|size_t
name|ds_idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get DS RR key algorithm. This value should match with the DNSKEY algo.  * @param k: DS rrset.  * @param idx: which DS.  * @return algorithm or 0 if DS too short.  */
end_comment

begin_function_decl
name|int
name|ds_get_key_algo
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|k
parameter_list|,
name|size_t
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get DNSKEY RR signature algorithm  * @param k: DNSKEY rrset.  * @param idx: which DNSKEY RR.  * @return algorithm or 0 if DNSKEY too short.  */
end_comment

begin_function_decl
name|int
name|dnskey_get_algo
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|k
parameter_list|,
name|size_t
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Get DNSKEY RR flags   * @param k: DNSKEY rrset.  * @param idx: which DNSKEY RR.  * @return flags or 0 if DNSKEY too short.  */
end_comment

begin_function_decl
name|uint16_t
name|dnskey_get_flags
parameter_list|(
name|struct
name|ub_packed_rrset_key
modifier|*
name|k
parameter_list|,
name|size_t
name|idx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * Verify rrset against dnskey rrset.   * @param env: module environment, scratch space is used.  * @param ve: validator environment, date settings.  * @param rrset: to be validated.  * @param dnskey: DNSKEY rrset, keyset to try.  * @param sigalg: if nonNULL provide downgrade protection otherwise one  *   algorithm is enough.  * @param reason: if bogus, a string returned, fixed or alloced in scratch.  * @return SECURE if one key in the set verifies one rrsig.  *	UNCHECKED on allocation errors, unsupported algorithms, malformed data,  *	and BOGUS on verification failures (no keys match any signatures).  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|dnskeyset_verify_rrset
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
name|dnskey
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
comment|/**   * verify rrset against one specific dnskey (from rrset)   * @param env: module environment, scratch space is used.  * @param ve: validator environment, date settings.  * @param rrset: to be validated.  * @param dnskey: DNSKEY rrset, keyset.  * @param dnskey_idx: which key from the rrset to try.  * @param reason: if bogus, a string returned, fixed or alloced in scratch.  * @return secure if *this* key signs any of the signatures on rrset.  *	unchecked on error or and bogus on bad signature.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|dnskey_verify_rrset
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
name|dnskey
parameter_list|,
name|size_t
name|dnskey_idx
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * verify rrset, with dnskey rrset, for a specific rrsig in rrset  * @param env: module environment, scratch space is used.  * @param ve: validator environment, date settings.  * @param now: current time for validation (can be overridden).  * @param rrset: to be validated.  * @param dnskey: DNSKEY rrset, keyset to try.  * @param sig_idx: which signature to try to validate.  * @param sortree: reused sorted order. Stored in region. Pass NULL at start,  * 	and for a new rrset.  * @param reason: if bogus, a string returned, fixed or alloced in scratch.  * @return secure if any key signs *this* signature. bogus if no key signs it,  *	or unchecked on error.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|dnskeyset_verify_rrset_sig
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
name|time_t
name|now
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|dnskey
parameter_list|,
name|size_t
name|sig_idx
parameter_list|,
name|struct
name|rbtree_t
modifier|*
modifier|*
name|sortree
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**   * verify rrset, with specific dnskey(from set), for a specific rrsig   * @param region: scratch region used for temporary allocation.  * @param buf: scratch buffer used for canonicalized rrset data.  * @param ve: validator environment, date settings.  * @param now: current time for validation (can be overridden).  * @param rrset: to be validated.  * @param dnskey: DNSKEY rrset, keyset.  * @param dnskey_idx: which key from the rrset to try.  * @param sig_idx: which signature to try to validate.  * @param sortree: pass NULL at start, the sorted rrset order is returned.  * 	pass it again for the same rrset.  * @param buf_canon: if true, the buffer is already canonical.  * 	pass false at start. pass old value only for same rrset and same  * 	signature (but perhaps different key) for reuse.  * @param reason: if bogus, a string returned, fixed or alloced in scratch.  * @return secure if this key signs this signature. unchecked on error or   *	bogus if it did not validate.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|dnskey_verify_rrset_sig
parameter_list|(
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|struct
name|val_env
modifier|*
name|ve
parameter_list|,
name|time_t
name|now
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|rrset
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|dnskey
parameter_list|,
name|size_t
name|dnskey_idx
parameter_list|,
name|size_t
name|sig_idx
parameter_list|,
name|struct
name|rbtree_t
modifier|*
modifier|*
name|sortree
parameter_list|,
name|int
modifier|*
name|buf_canon
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * canonical compare for two tree entries  */
end_comment

begin_function_decl
name|int
name|canonical_tree_compare
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
comment|/**  * Compare two rrsets and see if they are the same, canonicalised.  * The rrsets are not altered.  * @param region: temporary region.  * @param k1: rrset1  * @param k2: rrset2  * @return true if equal.  */
end_comment

begin_function_decl
name|int
name|rrset_canonical_equal
parameter_list|(
name|struct
name|regional
modifier|*
name|region
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|k1
parameter_list|,
name|struct
name|ub_packed_rrset_key
modifier|*
name|k2
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VAL_SIGCRYPT_H */
end_comment

end_unit

