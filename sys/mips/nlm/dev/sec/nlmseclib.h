begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003-2012 Broadcom Corporation  * All Rights Reserved  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  *   * THIS SOFTWARE IS PROVIDED BY BROADCOM ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  * BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  * OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN  * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NLMSECLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_NLMSECLIB_H_
end_define

begin_comment
comment|/*  * Cryptographic parameter definitions  */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_DES_KEY_LENGTH
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_3DES_KEY_LENGTH
value|24
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_AES128_KEY_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_AES192_KEY_LENGTH
value|24
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_AES256_KEY_LENGTH
value|32
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_AES128F8_KEY_LENGTH
value|32
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_AES192F8_KEY_LENGTH
value|48
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_AES256F8_KEY_LENGTH
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_KASUMI_F8_KEY_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_MAX_CRYPT_KEY_LENGTH
value|XLP_SEC_AES256F8_KEY_LENGTH
end_define

begin_define
define|#
directive|define
name|XLP_SEC_DES_IV_LENGTH
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_AES_IV_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_ARC4_IV_LENGTH
value|0
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_KASUMI_F8_IV_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_MAX_IV_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_IV_LENGTH_BYTES
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_AES_BLOCK_SIZE
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_DES_BLOCK_SIZE
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_3DES_BLOCK_SIZE
value|8
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_MD5_BLOCK_SIZE
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_SHA1_BLOCK_SIZE
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_SHA256_BLOCK_SIZE
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_SHA384_BLOCK_SIZE
value|128
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_SHA512_BLOCK_SIZE
value|128
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_GCM_BLOCK_SIZE
value|16
end_define

begin_comment
comment|/* XXX: Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_KASUMI_F9_BLOCK_SIZE
value|16
end_define

begin_comment
comment|/* XXX: Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_MAX_BLOCK_SIZE
value|64
end_define

begin_comment
comment|/* Max of MD5/SHA */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_MD5_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_SHA1_LENGTH
value|20
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_SHA256_LENGTH
value|32
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_SHA384_LENGTH
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_SHA512_LENGTH
value|64
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_GCM_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_KASUMI_F9_LENGTH
value|16
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_KASUMI_F9_RESULT_LENGTH
value|4
end_define

begin_comment
comment|/* Bytes */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_HMAC_LENGTH
value|64
end_define

begin_comment
comment|/* Max of MD5/SHA/SHA256 */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_MAX_AUTH_KEY_LENGTH
value|XLP_SEC_SHA512_BLOCK_SIZE
end_define

begin_define
define|#
directive|define
name|XLP_SEC_MAX_RC4_STATE_SIZE
value|264
end_define

begin_comment
comment|/* char s[256], int i, int j */
end_comment

begin_define
define|#
directive|define
name|XLP_SEC_SESSION
parameter_list|(
name|sid
parameter_list|)
value|((sid)& 0x000007ff)
end_define

begin_define
define|#
directive|define
name|XLP_SEC_SID
parameter_list|(
name|crd
parameter_list|,
name|ses
parameter_list|)
value|(((crd)<< 28) | ((ses)& 0x7ff))
end_define

begin_define
define|#
directive|define
name|CRYPTO_ERROR
parameter_list|(
name|msg1
parameter_list|)
value|((unsigned int)msg1)
end_define

begin_define
define|#
directive|define
name|NLM_CRYPTO_LEFT_REQS
value|(CMS_DEFAULT_CREDIT/2)
end_define

begin_define
define|#
directive|define
name|NLM_CRYPTO_NUM_SEGS_REQD
parameter_list|(
name|__bufsize
parameter_list|)
define|\
value|((__bufsize + NLM_CRYPTO_MAX_SEG_LEN - 1) / NLM_CRYPTO_MAX_SEG_LEN)
end_define

begin_define
define|#
directive|define
name|NLM_CRYPTO_PKT_DESC_SIZE
parameter_list|(
name|nsegs
parameter_list|)
value|(32 + (nsegs * 16))
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|creditleft
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|xlp_sec_command
block|{
name|uint16_t
name|session_num
decl_stmt|;
name|struct
name|cryptop
modifier|*
name|crp
decl_stmt|;
name|struct
name|cryptodesc
modifier|*
name|enccrd
decl_stmt|,
modifier|*
name|maccrd
decl_stmt|;
name|struct
name|xlp_sec_session
modifier|*
name|ses
decl_stmt|;
name|struct
name|nlm_crypto_pkt_ctrl
modifier|*
name|ctrlp
decl_stmt|;
name|struct
name|nlm_crypto_pkt_param
modifier|*
name|paramp
decl_stmt|;
name|void
modifier|*
name|iv
decl_stmt|;
name|uint8_t
name|des3key
index|[
literal|24
index|]
decl_stmt|;
name|uint8_t
modifier|*
name|hashdest
decl_stmt|;
name|uint8_t
name|hashsrc
decl_stmt|;
name|uint8_t
name|hmacpad
decl_stmt|;
name|uint32_t
name|hashoff
decl_stmt|;
name|uint32_t
name|hashlen
decl_stmt|;
name|uint32_t
name|cipheroff
decl_stmt|;
name|uint32_t
name|cipherlen
decl_stmt|;
name|uint32_t
name|ivoff
decl_stmt|;
name|uint32_t
name|ivlen
decl_stmt|;
name|uint32_t
name|hashalg
decl_stmt|;
name|uint32_t
name|hashmode
decl_stmt|;
name|uint32_t
name|cipheralg
decl_stmt|;
name|uint32_t
name|ciphermode
decl_stmt|;
name|uint32_t
name|nsegs
decl_stmt|;
name|uint32_t
name|hash_dst_len
decl_stmt|;
comment|/* used to store hash alg dst size */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|xlp_sec_session
block|{
name|uint32_t
name|sessionid
decl_stmt|;
name|int
name|hs_used
decl_stmt|;
name|int
name|hs_mlen
decl_stmt|;
name|uint8_t
name|ses_iv
index|[
name|EALG_MAX_BLOCK_LEN
index|]
decl_stmt|;
name|struct
name|xlp_sec_command
name|cmd
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Holds data specific to nlm security accelerators  */
end_comment

begin_struct
struct|struct
name|xlp_sec_softc
block|{
name|device_t
name|sc_dev
decl_stmt|;
comment|/* device backpointer */
name|uint64_t
name|sec_base
decl_stmt|;
name|int32_t
name|sc_cid
decl_stmt|;
name|struct
name|xlp_sec_session
modifier|*
name|sc_sessions
decl_stmt|;
name|int
name|sc_nsessions
decl_stmt|;
name|int
name|sc_needwakeup
decl_stmt|;
name|uint32_t
name|sec_vc_start
decl_stmt|;
name|uint32_t
name|sec_vc_end
decl_stmt|;
name|uint32_t
name|sec_msgsz
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|NLM_SEC_DEBUG
end_ifdef

begin_function_decl
name|void
name|print_crypto_params
parameter_list|(
name|struct
name|xlp_sec_command
modifier|*
name|cmd
parameter_list|,
name|struct
name|nlm_fmn_msg
name|m
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|xlp_sec_print_data
parameter_list|(
name|struct
name|cryptop
modifier|*
name|crp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_cmd
parameter_list|(
name|struct
name|xlp_sec_command
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|nlm_crypto_form_srcdst_segs
parameter_list|(
name|struct
name|xlp_sec_command
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_crypto_do_cipher
parameter_list|(
name|struct
name|xlp_sec_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|xlp_sec_command
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_crypto_do_digest
parameter_list|(
name|struct
name|xlp_sec_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|xlp_sec_command
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_crypto_do_cipher_digest
parameter_list|(
name|struct
name|xlp_sec_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|xlp_sec_command
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_get_digest_param
parameter_list|(
name|struct
name|xlp_sec_command
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|nlm_get_cipher_param
parameter_list|(
name|struct
name|xlp_sec_command
modifier|*
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NLMSECLIB_H_ */
end_comment

end_unit

