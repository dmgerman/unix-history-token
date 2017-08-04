begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- * Copyright (c) 2014 Michihiro NAKAJIMA * All rights reserved. * * Redistribution and use in source and binary forms, with or without * modification, are permitted provided that the following conditions * are met: * 1. Redistributions of source code must retain the above copyright *    notice, this list of conditions and the following disclaimer. * 2. Redistributions in binary form must reproduce the above copyright *    notice, this list of conditions and the following disclaimer in the *    documentation and/or other materials provided with the distribution. * * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT, * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LIBARCHIVE_BUILD
end_ifndef

begin_error
error|#
directive|error
error|This header is only to be used internally to libarchive.
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_CRYPTOR_PRIVATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTOR_PRIVATE_H_INCLUDED
end_define

begin_comment
comment|/*  * On systems that do not support any recognized crypto libraries,  * the archive_cryptor.c file will normally define no usable symbols.  *  * But some compilers and linkers choke on empty object files, so  * define a public symbol that will always exist.  This could  * be removed someday if this file gains another always-present  * symbol definition.  */
end_comment

begin_function_decl
name|int
name|__libarchive_cryptor_build_hack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|__APPLE__
end_ifdef

begin_include
include|#
directive|include
file|<AvailabilityMacros.h>
end_include

begin_if
if|#
directive|if
name|MAC_OS_X_VERSION_MAX_ALLOWED
operator|>=
literal|1080
end_if

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTOR_USE_Apple_CommonCrypto
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|ARCHIVE_CRYPTOR_USE_Apple_CommonCrypto
end_ifdef

begin_include
include|#
directive|include
file|<CommonCrypto/CommonCryptor.h>
end_include

begin_include
include|#
directive|include
file|<CommonCrypto/CommonKeyDerivation.h>
end_include

begin_define
define|#
directive|define
name|AES_BLOCK_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|AES_MAX_KEY_SIZE
value|kCCKeySizeAES256
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|CCCryptorRef
name|ctx
decl_stmt|;
name|uint8_t
name|key
index|[
name|AES_MAX_KEY_SIZE
index|]
decl_stmt|;
name|unsigned
name|key_len
decl_stmt|;
name|uint8_t
name|nonce
index|[
name|AES_BLOCK_SIZE
index|]
decl_stmt|;
name|uint8_t
name|encr_buf
index|[
name|AES_BLOCK_SIZE
index|]
decl_stmt|;
name|unsigned
name|encr_pos
decl_stmt|;
block|}
name|archive_crypto_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_BCRYPT_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<bcrypt.h>
end_include

begin_comment
comment|/* Common in other bcrypt implementations, but missing from VS2008. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BCRYPT_SUCCESS
end_ifndef

begin_define
define|#
directive|define
name|BCRYPT_SUCCESS
parameter_list|(
name|r
parameter_list|)
value|((NTSTATUS)(r) == STATUS_SUCCESS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|AES_MAX_KEY_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|AES_BLOCK_SIZE
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|BCRYPT_ALG_HANDLE
name|hAlg
decl_stmt|;
name|BCRYPT_KEY_HANDLE
name|hKey
decl_stmt|;
name|PBYTE
name|keyObj
decl_stmt|;
name|DWORD
name|keyObj_len
decl_stmt|;
name|uint8_t
name|nonce
index|[
name|AES_BLOCK_SIZE
index|]
decl_stmt|;
name|uint8_t
name|encr_buf
index|[
name|AES_BLOCK_SIZE
index|]
decl_stmt|;
name|unsigned
name|encr_pos
decl_stmt|;
block|}
name|archive_crypto_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_LIBNETTLE
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_NETTLE_AES_H
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_NETTLE_PBKDF2_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<nettle/pbkdf2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<nettle/aes.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|aes_ctx
name|ctx
decl_stmt|;
name|uint8_t
name|key
index|[
name|AES_MAX_KEY_SIZE
index|]
decl_stmt|;
name|unsigned
name|key_len
decl_stmt|;
name|uint8_t
name|nonce
index|[
name|AES_BLOCK_SIZE
index|]
decl_stmt|;
name|uint8_t
name|encr_buf
index|[
name|AES_BLOCK_SIZE
index|]
decl_stmt|;
name|unsigned
name|encr_pos
decl_stmt|;
block|}
name|archive_crypto_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_LIBCRYPTO
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"archive_openssl_evp_private.h"
end_include

begin_define
define|#
directive|define
name|AES_BLOCK_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|AES_MAX_KEY_SIZE
value|32
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|EVP_CIPHER_CTX
modifier|*
name|ctx
decl_stmt|;
specifier|const
name|EVP_CIPHER
modifier|*
name|type
decl_stmt|;
name|uint8_t
name|key
index|[
name|AES_MAX_KEY_SIZE
index|]
decl_stmt|;
name|unsigned
name|key_len
decl_stmt|;
name|uint8_t
name|nonce
index|[
name|AES_BLOCK_SIZE
index|]
decl_stmt|;
name|uint8_t
name|encr_buf
index|[
name|AES_BLOCK_SIZE
index|]
decl_stmt|;
name|unsigned
name|encr_pos
decl_stmt|;
block|}
name|archive_crypto_ctx
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|AES_BLOCK_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|AES_MAX_KEY_SIZE
value|32
end_define

begin_typedef
typedef|typedef
name|int
name|archive_crypto_ctx
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defines */
end_comment

begin_define
define|#
directive|define
name|archive_pbkdf2_sha1
parameter_list|(
name|pw
parameter_list|,
name|pw_len
parameter_list|,
name|salt
parameter_list|,
name|salt_len
parameter_list|,
name|rounds
parameter_list|,
name|dk
parameter_list|,
name|dk_len
parameter_list|)
define|\
value|__archive_cryptor.pbkdf2sha1(pw, pw_len, salt, salt_len, rounds, dk, dk_len)
end_define

begin_define
define|#
directive|define
name|archive_decrypto_aes_ctr_init
parameter_list|(
name|ctx
parameter_list|,
name|key
parameter_list|,
name|key_len
parameter_list|)
define|\
value|__archive_cryptor.decrypto_aes_ctr_init(ctx, key, key_len)
end_define

begin_define
define|#
directive|define
name|archive_decrypto_aes_ctr_update
parameter_list|(
name|ctx
parameter_list|,
name|in
parameter_list|,
name|in_len
parameter_list|,
name|out
parameter_list|,
name|out_len
parameter_list|)
define|\
value|__archive_cryptor.decrypto_aes_ctr_update(ctx, in, in_len, out, out_len)
end_define

begin_define
define|#
directive|define
name|archive_decrypto_aes_ctr_release
parameter_list|(
name|ctx
parameter_list|)
define|\
value|__archive_cryptor.decrypto_aes_ctr_release(ctx)
end_define

begin_define
define|#
directive|define
name|archive_encrypto_aes_ctr_init
parameter_list|(
name|ctx
parameter_list|,
name|key
parameter_list|,
name|key_len
parameter_list|)
define|\
value|__archive_cryptor.encrypto_aes_ctr_init(ctx, key, key_len)
end_define

begin_define
define|#
directive|define
name|archive_encrypto_aes_ctr_update
parameter_list|(
name|ctx
parameter_list|,
name|in
parameter_list|,
name|in_len
parameter_list|,
name|out
parameter_list|,
name|out_len
parameter_list|)
define|\
value|__archive_cryptor.encrypto_aes_ctr_update(ctx, in, in_len, out, out_len)
end_define

begin_define
define|#
directive|define
name|archive_encrypto_aes_ctr_release
parameter_list|(
name|ctx
parameter_list|)
define|\
value|__archive_cryptor.encrypto_aes_ctr_release(ctx)
end_define

begin_comment
comment|/* Minimal interface to cryptographic functionality for internal use in  * libarchive */
end_comment

begin_struct
struct|struct
name|archive_cryptor
block|{
comment|/* PKCS5 PBKDF2 HMAC-SHA1 */
name|int
function_decl|(
modifier|*
name|pbkdf2sha1
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|pw
parameter_list|,
name|size_t
name|pw_len
parameter_list|,
specifier|const
name|uint8_t
modifier|*
name|salt
parameter_list|,
name|size_t
name|salt_len
parameter_list|,
name|unsigned
name|rounds
parameter_list|,
name|uint8_t
modifier|*
name|derived_key
parameter_list|,
name|size_t
name|derived_key_len
parameter_list|)
function_decl|;
comment|/* AES CTR mode(little endian version) */
name|int
function_decl|(
modifier|*
name|decrypto_aes_ctr_init
function_decl|)
parameter_list|(
name|archive_crypto_ctx
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|decrypto_aes_ctr_update
function_decl|)
parameter_list|(
name|archive_crypto_ctx
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|decrypto_aes_ctr_release
function_decl|)
parameter_list|(
name|archive_crypto_ctx
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|encrypto_aes_ctr_init
function_decl|)
parameter_list|(
name|archive_crypto_ctx
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|encrypto_aes_ctr_update
function_decl|)
parameter_list|(
name|archive_crypto_ctx
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|encrypto_aes_ctr_release
function_decl|)
parameter_list|(
name|archive_crypto_ctx
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|archive_cryptor
name|__archive_cryptor
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

