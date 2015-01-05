begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: openssl-compat.h,v 1.31 2014/08/29 18:18:29 djm Exp $ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2005 Darren Tucker<dtucker@zip.com.au>  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER  * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING  * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_OPENSSL_COMPAT_H
end_ifndef

begin_define
define|#
directive|define
name|_OPENSSL_COMPAT_H
end_define

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

begin_function_decl
name|int
name|ssh_compatible_openssl
parameter_list|(
name|long
parameter_list|,
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_if
if|#
directive|if
operator|(
name|OPENSSL_VERSION_NUMBER
operator|<=
literal|0x0090805fL
operator|)
end_if

begin_error
error|#
directive|error
error|OpenSSL 0.9.8f or greater is required
end_error

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

begin_comment
comment|/*  * We overload some of the OpenSSL crypto functions with ssh_* equivalents  * to automatically handle OpenSSL engine initialisation.  *  * In order for the compat library to call the real functions, it must  * define SSH_DONT_OVERLOAD_OPENSSL_FUNCS before including this file and  * implement the ssh_* equivalents.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SSH_DONT_OVERLOAD_OPENSSL_FUNCS
end_ifndef

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

begin_function_decl
name|void
name|ssh_OpenSSL_add_all_algorithms
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
comment|/* SSH_DONT_OVERLOAD_OPENSSL_FUNCS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _OPENSSL_COMPAT_H */
end_comment

end_unit

