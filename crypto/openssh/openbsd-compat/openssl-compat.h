begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: openssl-compat.h,v 1.26 2014/02/13 05:38:33 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005 Darren Tucker<dtucker@zip.com.au>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER  * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_include
include|#
directive|include
file|"includes.h"
end_include

begin_include
include|#
directive|include
file|<openssl/opensslv.h>
end_include

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_include
include|#
directive|include
file|<openssl/rsa.h>
end_include

begin_include
include|#
directive|include
file|<openssl/dsa.h>
end_include

begin_comment
comment|/* Only in 0.9.8 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_DSA_MAX_MODULUS_BITS
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_DSA_MAX_MODULUS_BITS
value|10000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_RSA_MAX_MODULUS_BITS
end_ifndef

begin_define
define|#
directive|define
name|OPENSSL_RSA_MAX_MODULUS_BITS
value|16384
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OPENSSL_free() is Free() in versions before OpenSSL 0.9.6 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OPENSSL_VERSION_NUMBER
argument_list|)
operator|||
operator|(
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x0090600f
operator|)
end_if

begin_define
define|#
directive|define
name|OPENSSL_free
parameter_list|(
name|x
parameter_list|)
value|Free(x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x00906000L
end_if

begin_define
define|#
directive|define
name|SSH_OLD_EVP
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_get_app_data
parameter_list|(
name|e
parameter_list|)
value|((e)->app_data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x10000001L
end_if

begin_define
define|#
directive|define
name|LIBCRYPTO_EVP_INL_TYPE
value|unsigned int
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBCRYPTO_EVP_INL_TYPE
value|size_t
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|(
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x00907000L
operator|)
operator|||
name|defined
argument_list|(
name|OPENSSL_LOBOTOMISED_AES
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_BUILTIN_RIJNDAEL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_BUILTIN_RIJNDAEL
end_ifdef

begin_include
include|#
directive|include
file|"rijndael.h"
end_include

begin_define
define|#
directive|define
name|AES_KEY
value|rijndael_ctx
end_define

begin_define
define|#
directive|define
name|AES_BLOCK_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|AES_encrypt
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|rijndael_encrypt(c, a, b)
end_define

begin_define
define|#
directive|define
name|AES_set_encrypt_key
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|rijndael_set_key(c, (char *)a, b, 1)
end_define

begin_define
define|#
directive|define
name|EVP_aes_128_cbc
value|evp_rijndael
end_define

begin_define
define|#
directive|define
name|EVP_aes_192_cbc
value|evp_rijndael
end_define

begin_define
define|#
directive|define
name|EVP_aes_256_cbc
value|evp_rijndael
end_define

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|evp_rijndael
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_rijndael_iv
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OPENSSL_HAVE_EVPCTR
end_ifndef

begin_define
define|#
directive|define
name|EVP_aes_128_ctr
value|evp_aes_128_ctr
end_define

begin_define
define|#
directive|define
name|EVP_aes_192_ctr
value|evp_aes_128_ctr
end_define

begin_define
define|#
directive|define
name|EVP_aes_256_ctr
value|evp_aes_128_ctr
end_define

begin_function_decl
specifier|const
name|EVP_CIPHER
modifier|*
name|evp_aes_128_ctr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_aes_ctr_iv
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|int
parameter_list|,
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Avoid some #ifdef. Code that uses these is unreachable without GCM */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|OPENSSL_HAVE_EVPGCM
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EVP_CTRL_GCM_SET_IV_FIXED
argument_list|)
end_if

begin_define
define|#
directive|define
name|EVP_CTRL_GCM_SET_IV_FIXED
value|-1
end_define

begin_define
define|#
directive|define
name|EVP_CTRL_GCM_IV_GEN
value|-1
end_define

begin_define
define|#
directive|define
name|EVP_CTRL_GCM_SET_TAG
value|-1
end_define

begin_define
define|#
directive|define
name|EVP_CTRL_GCM_GET_TAG
value|-1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Replace missing EVP_CIPHER_CTX_ctrl() with something that returns failure */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EVP_CIPHER_CTX_CTRL
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_HAVE_EVPGCM
end_ifdef

begin_error
error|#
directive|error
error|AES-GCM enabled without EVP_CIPHER_CTX_ctrl
end_error

begin_comment
comment|/* shouldn't happen */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_ctrl
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|OPENSSL_VERSION_NUMBER
operator|<
literal|0x00907000L
end_if

begin_define
define|#
directive|define
name|EVP_X_STATE
parameter_list|(
name|evp
parameter_list|)
value|&(evp).c
end_define

begin_define
define|#
directive|define
name|EVP_X_STATE_LEN
parameter_list|(
name|evp
parameter_list|)
value|sizeof((evp).c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EVP_X_STATE
parameter_list|(
name|evp
parameter_list|)
value|(evp).cipher_data
end_define

begin_define
define|#
directive|define
name|EVP_X_STATE_LEN
parameter_list|(
name|evp
parameter_list|)
value|(evp).cipher->ctx_size
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OpenSSL 0.9.8e returns cipher key len not context key len */
end_comment

begin_if
if|#
directive|if
operator|(
name|OPENSSL_VERSION_NUMBER
operator|==
literal|0x0090805fL
operator|)
end_if

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_key_length
parameter_list|(
name|c
parameter_list|)
value|((c)->key_len)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_RSA_GET_DEFAULT_METHOD
end_ifndef

begin_function_decl
name|RSA_METHOD
modifier|*
name|RSA_get_default_method
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * We overload some of the OpenSSL crypto functions with ssh_* equivalents  * which cater for older and/or less featureful OpenSSL version.  *  * In order for the compat library to call the real functions, it must  * define SSH_DONT_OVERLOAD_OPENSSL_FUNCS before including this file and  * implement the ssh_* equivalents.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_DONT_OVERLOAD_OPENSSL_FUNCS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SSH_OLD_EVP
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|EVP_Cipher
end_ifdef

begin_undef
undef|#
directive|undef
name|EVP_Cipher
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EVP_CipherInit
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|ssh_EVP_CipherInit((a),(b),(c),(d),(e))
end_define

begin_define
define|#
directive|define
name|EVP_Cipher
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|ssh_EVP_Cipher((a),(b),(c),(d))
end_define

begin_define
define|#
directive|define
name|EVP_CIPHER_CTX_cleanup
parameter_list|(
name|a
parameter_list|)
value|ssh_EVP_CIPHER_CTX_cleanup((a))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SSH_OLD_EVP */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OPENSSL_EVP_DIGESTUPDATE_VOID
end_ifdef

begin_define
define|#
directive|define
name|EVP_DigestUpdate
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|ssh_EVP_DigestUpdate((a),(b),(c))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_OPENSSL_ENGINE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|OpenSSL_add_all_algorithms
end_ifdef

begin_undef
undef|#
directive|undef
name|OpenSSL_add_all_algorithms
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OpenSSL_add_all_algorithms
parameter_list|()
value|ssh_OpenSSL_add_all_algorithms()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_BN_IS_PRIME_EX
end_ifndef

begin_function_decl
name|int
name|BN_is_prime_ex
parameter_list|(
specifier|const
name|BIGNUM
modifier|*
parameter_list|,
name|int
parameter_list|,
name|BN_CTX
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DSA_GENERATE_PARAMETERS_EX
end_ifndef

begin_function_decl
name|int
name|DSA_generate_parameters_ex
parameter_list|(
name|DSA
modifier|*
parameter_list|,
name|int
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|,
name|unsigned
name|long
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_RSA_GENERATE_KEY_EX
end_ifndef

begin_function_decl
name|int
name|RSA_generate_key_ex
parameter_list|(
name|RSA
modifier|*
parameter_list|,
name|int
parameter_list|,
name|BIGNUM
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EVP_DIGESTINIT_EX
end_ifndef

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
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EVP_DISESTFINAL_EX
end_ifndef

begin_function_decl
name|int
name|EVP_DigestFinal_ex
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|EVP_MD_CTX_COPY_EX
end_ifndef

begin_function_decl
name|int
name|EVP_MD_CTX_copy_ex
parameter_list|(
name|EVP_MD_CTX
modifier|*
parameter_list|,
specifier|const
name|EVP_MD_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|ssh_EVP_CipherInit
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
specifier|const
name|EVP_CIPHER
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|unsigned
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_EVP_Cipher
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ssh_EVP_CIPHER_CTX_cleanup
parameter_list|(
name|EVP_CIPHER_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ssh_OpenSSL_add_all_algorithms
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_HMAC_CTX_INIT
end_ifndef

begin_define
define|#
directive|define
name|HMAC_CTX_init
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EVP_MD_CTX_INIT
end_ifndef

begin_define
define|#
directive|define
name|EVP_MD_CTX_init
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_EVP_MD_CTX_CLEANUP
end_ifndef

begin_define
define|#
directive|define
name|EVP_MD_CTX_cleanup
parameter_list|(
name|a
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SSH_DONT_OVERLOAD_OPENSSL_FUNCS */
end_comment

end_unit

