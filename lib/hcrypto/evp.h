begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2005 - 2008 Kungliga Tekniska HÃ¶gskolan  * (Royal Institute of Technology, Stockholm, Sweden).  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  *  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * 3. Neither the name of the Institute nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE INSTITUTE AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE INSTITUTE OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $Id$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HEIM_EVP_H
end_ifndef

begin_define
define|#
directive|define
name|HEIM_EVP_H
value|1
end_define

begin_include
include|#
directive|include
file|<hcrypto/engine.h>
end_include

begin_comment
comment|/* symbol renaming */
end_comment

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_block_size
value|hc_EVP_CIPHER_CTX_block_size
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_cipher
value|hc_EVP_CIPHER_CTX_cipher
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_cleanup
value|hc_EVP_CIPHER_CTX_cleanup
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_flags
value|hc_EVP_CIPHER_CTX_flags
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_get_app_data
value|hc_EVP_CIPHER_CTX_get_app_data
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_init
value|hc_EVP_CIPHER_CTX_init
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_iv_length
value|hc_EVP_CIPHER_CTX_iv_length
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_key_length
value|hc_EVP_CIPHER_CTX_key_length
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_mode
value|hc_EVP_CIPHER_CTX_mode
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_set_app_data
value|hc_EVP_CIPHER_CTX_set_app_data
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_set_key_length
value|hc_EVP_CIPHER_CTX_set_key_length
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_set_padding
value|hc_EVP_CIPHER_CTX_set_padding
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_block_size
value|hc_EVP_CIPHER_block_size
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_iv_length
value|hc_EVP_CIPHER_iv_length
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_key_length
value|hc_EVP_CIPHER_key_length
end_define

begin_define
define|#
directive|define
name|EVP_Cipher
value|hc_EVP_Cipher
end_define

begin_define
define|#
directive|define
name|EVP_CipherInit_ex
value|hc_EVP_CipherInit_ex
end_define

begin_define
define|#
directive|define
name|EVP_CipherUpdate
value|hc_EVP_CipherUpdate
end_define

begin_define
define|#
directive|define
name|EVP_CipherFinal_ex
value|hc_EVP_CipherFinal_ex
end_define

begin_define
define|#
directive|define
name|EVP_Digest
value|hc_EVP_Digest
end_define

begin_define
define|#
directive|define
name|EVP_DigestFinal_ex
value|hc_EVP_DigestFinal_ex
end_define

begin_define
define|#
directive|define
name|EVP_DigestInit_ex
value|hc_EVP_DigestInit_ex
end_define

begin_define
define|#
directive|define
name|EVP_DigestUpdate
value|hc_EVP_DigestUpdate
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTX_block_size
value|hc_EVP_MD_CTX_block_size
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTX_cleanup
value|hc_EVP_MD_CTX_cleanup
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTX_create
value|hc_EVP_MD_CTX_create
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTX_init
value|hc_EVP_MD_CTX_init
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTX_destroy
value|hc_EVP_MD_CTX_destroy
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTX_md
value|hc_EVP_MD_CTX_md
end_define

begin_define
define|#
directive|define
name|EVP_MD_CTX_size
value|hc_EVP_MD_CTX_size
end_define

begin_define
define|#
directive|define
name|EVP_MD_block_size
value|hc_EVP_MD_block_size
end_define

begin_define
define|#
directive|define
name|EVP_MD_size
value|hc_EVP_MD_size
end_define

begin_define
define|#
directive|define
name|EVP_aes_128_cbc
value|hc_EVP_aes_128_cbc
end_define

begin_define
define|#
directive|define
name|EVP_aes_192_cbc
value|hc_EVP_aes_192_cbc
end_define

begin_define
define|#
directive|define
name|EVP_aes_256_cbc
value|hc_EVP_aes_256_cbc
end_define

begin_define
define|#
directive|define
name|EVP_aes_128_cfb8
value|hc_EVP_aes_128_cfb8
end_define

begin_define
define|#
directive|define
name|EVP_aes_192_cfb8
value|hc_EVP_aes_192_cfb8
end_define

begin_define
define|#
directive|define
name|EVP_aes_256_cfb8
value|hc_EVP_aes_256_cfb8
end_define

begin_define
define|#
directive|define
name|EVP_des_cbc
value|hc_EVP_des_cbc
end_define

begin_define
define|#
directive|define
name|EVP_des_ede3_cbc
value|hc_EVP_des_ede3_cbc
end_define

begin_define
define|#
directive|define
name|EVP_enc_null
value|hc_EVP_enc_null
end_define

begin_define
define|#
directive|define
name|EVP_md2
value|hc_EVP_md2
end_define

begin_define
define|#
directive|define
name|EVP_md4
value|hc_EVP_md4
end_define

begin_define
define|#
directive|define
name|EVP_md5
value|hc_EVP_md5
end_define

begin_define
define|#
directive|define
name|EVP_md_null
value|hc_EVP_md_null
end_define

begin_define
define|#
directive|define
name|EVP_rc2_40_cbc
value|hc_EVP_rc2_40_cbc
end_define

begin_define
define|#
directive|define
name|EVP_rc2_64_cbc
value|hc_EVP_rc2_64_cbc
end_define

begin_define
define|#
directive|define
name|EVP_rc2_cbc
value|hc_EVP_rc2_cbc
end_define

begin_define
define|#
directive|define
name|EVP_rc4
value|hc_EVP_rc4
end_define

begin_define
define|#
directive|define
name|EVP_rc4_40
value|hc_EVP_rc4_40
end_define

begin_define
define|#
directive|define
name|EVP_camellia_128_cbc
value|hc_EVP_camellia_128_cbc
end_define

begin_define
define|#
directive|define
name|EVP_camellia_192_cbc
value|hc_EVP_camellia_192_cbc
end_define

begin_define
define|#
directive|define
name|EVP_camellia_256_cbc
value|hc_EVP_camellia_256_cbc
end_define

begin_define
define|#
directive|define
name|EVP_sha
value|hc_EVP_sha
end_define

begin_define
define|#
directive|define
name|EVP_sha1
value|hc_EVP_sha1
end_define

begin_define
define|#
directive|define
name|EVP_sha256
value|hc_EVP_sha256
end_define

begin_define
define|#
directive|define
name|EVP_sha384
value|hc_EVP_sha384
end_define

begin_define
define|#
directive|define
name|EVP_sha512
value|hc_EVP_sha512
end_define

begin_define
define|#
directive|define
name|PKCS5_PBKDF2_HMAC_SHA1
value|hc_PKCS5_PBKDF2_HMAC_SHA1
end_define

begin_define
define|#
directive|define
name|EVP_BytesToKey
value|hc_EVP_BytesToKey
end_define

begin_define
define|#
directive|define
name|EVP_get_cipherbyname
value|hc_EVP_get_cipherbyname
end_define

begin_define
define|#
directive|define
name|OpenSSL_add_all_algorithms
value|hc_OpenSSL_add_all_algorithms
end_define

begin_define
define|#
directive|define
name|OpenSSL_add_all_algorithms_conf
value|hc_OpenSSL_add_all_algorithms_conf
end_define

begin_define
define|#
directive|define
name|OpenSSL_add_all_algorithms_noconf
value|hc_OpenSSL_add_all_algorithms_noconf
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_ctrl
value|hc_EVP_CIPHER_CTX_ctrl
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_rand_key
value|hc_EVP_CIPHER_CTX_rand_key
end_define

begin_define
define|#
directive|define
name|hcrypto_validate
value|hc_hcrypto_validate
end_define

begin_comment
comment|/*  *  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|hc_EVP_MD_CTX
name|EVP_MD_CTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hc_evp_pkey
name|EVP_PKEY
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hc_evp_md
name|EVP_MD
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hc_CIPHER
name|EVP_CIPHER
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|hc_CIPHER_CTX
name|EVP_CIPHER_CTX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EVP_MAX_IV_LENGTH
value|16
end_define

begin_define
define|#
directive|define
name|EVP_MAX_BLOCK_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|EVP_MAX_MD_SIZE
value|64
end_define

begin_struct
struct|struct
name|hc_CIPHER
block|{
name|int
name|nid
decl_stmt|;
name|int
name|block_size
decl_stmt|;
name|int
name|key_len
decl_stmt|;
name|int
name|iv_len
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* The lowest 3 bits is used as integer field for the mode the      * cipher is used in (use EVP_CIPHER.._mode() to extract the      * mode). The rest of the flag field is a bitfield.      */
define|#
directive|define
name|EVP_CIPH_STREAM_CIPHER
value|0
define|#
directive|define
name|EVP_CIPH_CBC_MODE
value|2
define|#
directive|define
name|EVP_CIPH_CFB8_MODE
value|4
define|#
directive|define
name|EVP_CIPH_MODE
value|0x7
define|#
directive|define
name|EVP_CIPH_VARIABLE_LENGTH
value|0x008
comment|/* variable key length */
define|#
directive|define
name|EVP_CIPH_ALWAYS_CALL_INIT
value|0x020
define|#
directive|define
name|EVP_CIPH_RAND_KEY
value|0x200
name|int
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|do_cipher
function_decl|)
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|cleanup
function_decl|)
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
name|int
name|ctx_size
decl_stmt|;
name|void
modifier|*
name|set_asn1_parameters
decl_stmt|;
name|void
modifier|*
name|get_asn1_parameters
decl_stmt|;
name|int
function_decl|(
modifier|*
name|ctrl
function_decl|)
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|arg
parameter_list|,
name|void
modifier|*
name|ptr
parameter_list|)
function_decl|;
define|#
directive|define
name|EVP_CTRL_RAND_KEY
value|0x6
name|void
modifier|*
name|app_data
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|hc_CIPHER_CTX
block|{
specifier|const
name|EVP_CIPHER
modifier|*
name|cipher
decl_stmt|;
name|ENGINE
modifier|*
name|engine
decl_stmt|;
name|int
name|encrypt
decl_stmt|;
name|int
name|buf_len
decl_stmt|;
comment|/* bytes stored in buf for EVP_CipherUpdate */
name|unsigned
name|char
name|oiv
index|[
name|EVP_MAX_IV_LENGTH
index|]
decl_stmt|;
name|unsigned
name|char
name|iv
index|[
name|EVP_MAX_IV_LENGTH
index|]
decl_stmt|;
name|unsigned
name|char
name|buf
index|[
name|EVP_MAX_BLOCK_LENGTH
index|]
decl_stmt|;
name|int
name|num
decl_stmt|;
name|void
modifier|*
name|app_data
decl_stmt|;
name|int
name|key_len
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
name|void
modifier|*
name|cipher_data
decl_stmt|;
name|int
name|final_used
decl_stmt|;
name|int
name|block_mask
decl_stmt|;
name|unsigned
name|char
name|final
index|[
name|EVP_MAX_BLOCK_LENGTH
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|hc_evp_md_init
function_decl|)
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|hc_evp_md_update
function_decl|)
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|hc_evp_md_final
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|hc_evp_md_cleanup
function_decl|)
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|hc_evp_md
block|{
name|int
name|hash_size
decl_stmt|;
name|int
name|block_size
decl_stmt|;
name|int
name|ctx_size
decl_stmt|;
name|hc_evp_md_init
name|init
decl_stmt|;
name|hc_evp_md_update
name|update
decl_stmt|;
name|hc_evp_md_final
name|final
decl_stmt|;
name|hc_evp_md_cleanup
name|cleanup
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__attribute__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HC_DEPRECATED
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|(
operator|(
name|__GNUC__
operator|>
literal|3
operator|)
operator|||
operator|(
operator|(
name|__GNUC__
operator|==
literal|3
operator|)
operator|&&
operator|(
name|__GNUC_MINOR__
operator|>=
literal|1
operator|)
operator|)
operator|)
end_if

begin_define
define|#
directive|define
name|HC_DEPRECATED
value|__attribute__((deprecated))
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|(
name|_MSC_VER
operator|>
literal|1200
operator|)
end_elif

begin_define
define|#
directive|define
name|HC_DEPRECATED
value|__declspec(deprecated)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HC_DEPRECATED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HC_DEPRECATED_CRYPTO
end_ifndef

begin_define
define|#
directive|define
name|HC_DEPRECATED_CRYPTO
value|HC_DEPRECATED
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_define
define|#
directive|define
name|HC_CPP_BEGIN
value|extern "C" {
end_define

begin_define
define|#
directive|define
name|HC_CPP_END
value|}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HC_CPP_BEGIN
end_define

begin_define
define|#
directive|define
name|HC_CPP_END
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|HC_CPP_BEGIN
comment|/*  * Avaible crypto algs  */
specifier|const
name|EVP_MD
modifier|*
name|EVP_md_null
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HC_DEPRECATED_CRYPTO
specifier|const
name|EVP_MD
modifier|*
name|EVP_md2
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HC_DEPRECATED_CRYPTO
specifier|const
name|EVP_MD
modifier|*
name|EVP_md4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HC_DEPRECATED_CRYPTO
specifier|const
name|EVP_MD
modifier|*
name|EVP_md5
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_sha
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_sha1
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_sha256
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_sha384
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_sha512
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_128_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_192_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_256_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_128_cfb8
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_192_cfb8
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_aes_256_cfb8
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HC_DEPRECATED_CRYPTO
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_des_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_des_ede3_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_enc_null
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HC_DEPRECATED_CRYPTO
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_rc2_40_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HC_DEPRECATED_CRYPTO
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_rc2_64_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HC_DEPRECATED_CRYPTO
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_rc2_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_rc4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|HC_DEPRECATED_CRYPTO
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_rc4_40
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_camellia_128_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_camellia_192_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_camellia_256_cbc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_MD_size
parameter_list|(
specifier|const
name|EVP_MD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_MD_block_size
parameter_list|(
specifier|const
name|EVP_MD
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_MD
modifier|*
name|EVP_MD_CTX_md
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_MD_CTX_size
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_MD_CTX_block_size
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|EVP_MD_CTX
modifier|*
name|EVP_MD_CTX_create
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|HC_DEPRECATED
name|EVP_MD_CTX_init
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EVP_MD_CTX_destroy
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|HC_DEPRECATED
name|EVP_MD_CTX_cleanup
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_DigestInit_ex
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
parameter_list|,
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_DigestUpdate
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_DigestFinal_ex
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_Digest
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
parameter_list|,
name|ENGINE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  */
end_comment

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_get_cipherbyname
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_CIPHER_block_size
parameter_list|(
specifier|const
name|EVP_CIPHER
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_CIPHER_key_length
parameter_list|(
specifier|const
name|EVP_CIPHER
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_CIPHER_iv_length
parameter_list|(
specifier|const
name|EVP_CIPHER
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EVP_CIPHER_CTX_init
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_CIPHER_CTX_cleanup
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_CIPHER_CTX_set_key_length
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_CIPHER_CTX_set_padding
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|long
name|EVP_CIPHER_CTX_flags
parameter_list|(
specifier|const
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_CIPHER_CTX_mode
parameter_list|(
specifier|const
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|EVP_CIPHER_CTX_cipher
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_CIPHER_CTX_block_size
parameter_list|(
specifier|const
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_CIPHER_CTX_key_length
parameter_list|(
specifier|const
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|EVP_CIPHER_CTX_iv_length
parameter_list|(
specifier|const
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|EVP_CIPHER_CTX_get_app_data
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EVP_CIPHER_CTX_set_app_data
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_CIPHER_CTX_ctrl
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_CIPHER_CTX_rand_key
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_CipherInit_ex
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
specifier|const
name|EVP_CIPHER
modifier|*
parameter_list|,
name|ENGINE
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_CipherUpdate
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_CipherFinal_ex
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_Cipher
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|PKCS5_PBKDF2_HMAC_SHA1
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|size_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|EVP_BytesToKey
parameter_list|(
specifier|const
name|EVP_CIPHER
modifier|*
parameter_list|,
specifier|const
name|EVP_MD
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  *  */
end_comment

begin_function_decl
name|void
name|OpenSSL_add_all_algorithms
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OpenSSL_add_all_algorithms_conf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|OpenSSL_add_all_algorithms_noconf
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hcrypto_validate
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|HC_CPP_END
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HEIM_EVP_H */
end_comment

end_unit

