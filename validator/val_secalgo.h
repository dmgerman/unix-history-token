begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * validator/val_secalgo.h - validator security algorithm functions.  *  * Copyright (c) 2012, NLnet Labs. All rights reserved.  *  * This software is open source.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * Redistributions of source code must retain the above copyright notice,  * this list of conditions and the following disclaimer.  *   * Redistributions in binary form must reproduce the above copyright notice,  * this list of conditions and the following disclaimer in the documentation  * and/or other materials provided with the distribution.  *   * Neither the name of the NLNET LABS nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_comment
comment|/**  * \file  *  * This file contains helper functions for the validator module.  * The functions take buffers with raw data and convert to library calls.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|VALIDATOR_VAL_SECALGO_H
end_ifndef

begin_define
define|#
directive|define
name|VALIDATOR_VAL_SECALGO_H
end_define

begin_struct_decl
struct_decl|struct
name|sldns_buffer
struct_decl|;
end_struct_decl

begin_comment
comment|/**  * Return size of DS digest according to its hash algorithm.  * @param algo: DS digest algo.  * @return size in bytes of digest, or 0 if not supported.   */
end_comment

begin_function_decl
name|size_t
name|ds_digest_size_supported
parameter_list|(
name|int
name|algo
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * @param algo: the DS digest algo  * @param buf: the buffer to digest  * @param len: length of buffer to digest.  * @param res: result stored here (must have sufficient space).  * @return false on failure.  */
end_comment

begin_function_decl
name|int
name|secalgo_ds_digest
parameter_list|(
name|int
name|algo
parameter_list|,
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|,
name|unsigned
name|char
modifier|*
name|res
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** return true if DNSKEY algorithm id is supported */
end_comment

begin_function_decl
name|int
name|dnskey_algo_id_is_supported
parameter_list|(
name|int
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * Check a canonical sig+rrset and signature against a dnskey  * @param buf: buffer with data to verify, the first rrsig part and the  *	canonicalized rrset.  * @param algo: DNSKEY algorithm.  * @param sigblock: signature rdata field from RRSIG  * @param sigblock_len: length of sigblock data.  * @param key: public key data from DNSKEY RR.  * @param keylen: length of keydata.  * @param reason: bogus reason in more detail.  * @return secure if verification succeeded, bogus on crypto failure,  *	unchecked on format errors and alloc failures.  */
end_comment

begin_function_decl
name|enum
name|sec_status
name|verify_canonrrset
parameter_list|(
name|struct
name|sldns_buffer
modifier|*
name|buf
parameter_list|,
name|int
name|algo
parameter_list|,
name|unsigned
name|char
modifier|*
name|sigblock
parameter_list|,
name|unsigned
name|int
name|sigblock_len
parameter_list|,
name|unsigned
name|char
modifier|*
name|key
parameter_list|,
name|unsigned
name|int
name|keylen
parameter_list|,
name|char
modifier|*
modifier|*
name|reason
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VALIDATOR_VAL_SECALGO_H */
end_comment

end_unit

