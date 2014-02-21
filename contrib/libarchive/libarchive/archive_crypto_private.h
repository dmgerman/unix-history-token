begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*- * Copyright (c) 2003-2007 Tim Kientzle * Copyright (c) 2011 Andres Mejia * All rights reserved. * * Redistribution and use in source and binary forms, with or without * modification, are permitted provided that the following conditions * are met: * 1. Redistributions of source code must retain the above copyright *    notice, this list of conditions and the following disclaimer. * 2. Redistributions in binary form must reproduce the above copyright *    notice, this list of conditions and the following disclaimer in the *    documentation and/or other materials provided with the distribution. * * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT, * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
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
name|ARCHIVE_CRYPTO_PRIVATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_PRIVATE_H_INCLUDED
end_define

begin_comment
comment|/*  * Crypto support in various Operating Systems:  *  * NetBSD:  * - MD5 and SHA1 in libc: without _ after algorithm name  * - SHA2 in libc: with _ after algorithm name  *  * OpenBSD:  * - MD5, SHA1 and SHA2 in libc: without _ after algorithm name  * - OpenBSD 4.4 and earlier have SHA2 in libc with _ after algorithm name  *  * DragonFly and FreeBSD:  * - MD5 libmd: without _ after algorithm name  * - SHA1, SHA256 and SHA512 in libmd: with _ after algorithm name  *  * Mac OS X (10.4 and later):  * - MD5, SHA1 and SHA2 in libSystem: with CC_ prefix and _ after algorithm name  *  * OpenSSL:  * - MD5, SHA1 and SHA2 in libcrypto: with _ after algorithm name  *  * Windows:  * - MD5, SHA1 and SHA2 in archive_crypto.c using Windows crypto API  */
end_comment

begin_comment
comment|/* libc crypto headers */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_LIBC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<rmd160.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBC
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sha1.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBC2
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBC3
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBC2
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBC3
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBC2
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBC3
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sha2.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* libmd crypto headers */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBMD
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_LIBMD
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBMD
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBMD
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBMD
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_LIBMD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBMD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_LIBMD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<ripemd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBMD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sha.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBMD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sha256.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBMD
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sha512.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* libSystem crypto headers */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBSYSTEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBSYSTEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBSYSTEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBSYSTEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBSYSTEM
argument_list|)
end_if

begin_include
include|#
directive|include
file|<CommonCrypto/CommonDigest.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nettle crypto headers */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_NETTLE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<nettle/md5.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_NETTLE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<nettle/ripemd160.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_NETTLE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_NETTLE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_NETTLE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_NETTLE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<nettle/sha.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OpenSSL crypto headers */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_OPENSSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCHIVE_CRYPTO_OPENSSL
value|1
end_define

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Windows crypto headers */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_WIN
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_WIN
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_WIN
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_WIN
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_WIN
argument_list|)
end_if

begin_include
include|#
directive|include
file|<wincrypt.h>
end_include

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|valid
decl_stmt|;
name|HCRYPTPROV
name|cryptProv
decl_stmt|;
name|HCRYPTHASH
name|hash
decl_stmt|;
block|}
name|Digest_CTX
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* typedefs */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBC
argument_list|)
end_if

begin_typedef
typedef|typedef
name|MD5_CTX
name|archive_md5_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBMD
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|MD5_CTX
name|archive_md5_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBSYSTEM
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|CC_MD5_CTX
name|archive_md5_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_NETTLE
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|struct
name|md5_ctx
name|archive_md5_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_OPENSSL
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|EVP_MD_CTX
name|archive_md5_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_WIN
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|Digest_CTX
name|archive_md5_ctx
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
name|archive_md5_ctx
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_LIBC
argument_list|)
end_if

begin_typedef
typedef|typedef
name|RMD160_CTX
name|archive_rmd160_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_LIBMD
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|RIPEMD160_CTX
name|archive_rmd160_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_NETTLE
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|struct
name|ripemd160_ctx
name|archive_rmd160_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_OPENSSL
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|EVP_MD_CTX
name|archive_rmd160_ctx
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
name|archive_rmd160_ctx
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBC
argument_list|)
end_if

begin_typedef
typedef|typedef
name|SHA1_CTX
name|archive_sha1_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBMD
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA1_CTX
name|archive_sha1_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBSYSTEM
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|CC_SHA1_CTX
name|archive_sha1_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_NETTLE
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|struct
name|sha1_ctx
name|archive_sha1_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_OPENSSL
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|EVP_MD_CTX
name|archive_sha1_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_WIN
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|Digest_CTX
name|archive_sha1_ctx
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
name|archive_sha1_ctx
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBC
argument_list|)
end_if

begin_typedef
typedef|typedef
name|SHA256_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBC2
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA256_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBC3
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA2_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBMD
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA256_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBSYSTEM
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|CC_SHA256_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_NETTLE
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|struct
name|sha256_ctx
name|archive_sha256_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_OPENSSL
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|EVP_MD_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_WIN
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|Digest_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
name|archive_sha256_ctx
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBC
argument_list|)
end_if

begin_typedef
typedef|typedef
name|SHA384_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBC2
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA384_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBC3
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA2_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBSYSTEM
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|CC_SHA512_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_NETTLE
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|struct
name|sha384_ctx
name|archive_sha384_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_OPENSSL
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|EVP_MD_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_WIN
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|Digest_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
name|archive_sha384_ctx
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBC
argument_list|)
end_if

begin_typedef
typedef|typedef
name|SHA512_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBC2
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA512_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBC3
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA2_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBMD
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|SHA512_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBSYSTEM
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|CC_SHA512_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_NETTLE
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|struct
name|sha512_ctx
name|archive_sha512_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_OPENSSL
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|EVP_MD_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_WIN
argument_list|)
end_elif

begin_typedef
typedef|typedef
name|Digest_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
name|archive_sha512_ctx
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defines */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBMD
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_LIBSYSTEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_NETTLE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_MD5_WIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCHIVE_HAS_MD5
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|archive_md5_init
parameter_list|(
name|ctx
parameter_list|)
define|\
value|__archive_crypto.md5init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_md5_final
parameter_list|(
name|ctx
parameter_list|,
name|md
parameter_list|)
define|\
value|__archive_crypto.md5final(ctx, md)
end_define

begin_define
define|#
directive|define
name|archive_md5_update
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
define|\
value|__archive_crypto.md5update(ctx, buf, n)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_LIBC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_NETTLE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_RMD160_OPENSSL
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCHIVE_HAS_RMD160
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|archive_rmd160_init
parameter_list|(
name|ctx
parameter_list|)
define|\
value|__archive_crypto.rmd160init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_rmd160_final
parameter_list|(
name|ctx
parameter_list|,
name|md
parameter_list|)
define|\
value|__archive_crypto.rmd160final(ctx, md)
end_define

begin_define
define|#
directive|define
name|archive_rmd160_update
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
define|\
value|__archive_crypto.rmd160update(ctx, buf, n)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBMD
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_LIBSYSTEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_NETTLE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA1_WIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|archive_sha1_init
parameter_list|(
name|ctx
parameter_list|)
define|\
value|__archive_crypto.sha1init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha1_final
parameter_list|(
name|ctx
parameter_list|,
name|md
parameter_list|)
define|\
value|__archive_crypto.sha1final(ctx, md)
end_define

begin_define
define|#
directive|define
name|archive_sha1_update
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
define|\
value|__archive_crypto.sha1update(ctx, buf, n)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBC2
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBC3
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBMD
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_LIBSYSTEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_NETTLE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA256_WIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA256
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|archive_sha256_init
parameter_list|(
name|ctx
parameter_list|)
define|\
value|__archive_crypto.sha256init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha256_final
parameter_list|(
name|ctx
parameter_list|,
name|md
parameter_list|)
define|\
value|__archive_crypto.sha256final(ctx, md)
end_define

begin_define
define|#
directive|define
name|archive_sha256_update
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
define|\
value|__archive_crypto.sha256update(ctx, buf, n)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBC2
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBC3
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_LIBSYSTEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_NETTLE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA384_WIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA384
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|archive_sha384_init
parameter_list|(
name|ctx
parameter_list|)
define|\
value|__archive_crypto.sha384init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha384_final
parameter_list|(
name|ctx
parameter_list|,
name|md
parameter_list|)
define|\
value|__archive_crypto.sha384final(ctx, md)
end_define

begin_define
define|#
directive|define
name|archive_sha384_update
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
define|\
value|__archive_crypto.sha384update(ctx, buf, n)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBC
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBC2
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBC3
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBMD
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_LIBSYSTEM
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_NETTLE
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_OPENSSL
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|ARCHIVE_CRYPTO_SHA512_WIN
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|archive_sha512_init
parameter_list|(
name|ctx
parameter_list|)
define|\
value|__archive_crypto.sha512init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha512_final
parameter_list|(
name|ctx
parameter_list|,
name|md
parameter_list|)
define|\
value|__archive_crypto.sha512final(ctx, md)
end_define

begin_define
define|#
directive|define
name|archive_sha512_update
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|,
name|n
parameter_list|)
define|\
value|__archive_crypto.sha512update(ctx, buf, n)
end_define

begin_comment
comment|/* Minimal interface to crypto functionality for internal use in libarchive */
end_comment

begin_struct
struct|struct
name|archive_crypto
block|{
comment|/* Message Digest */
name|int
function_decl|(
modifier|*
name|md5init
function_decl|)
parameter_list|(
name|archive_md5_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|md5update
function_decl|)
parameter_list|(
name|archive_md5_ctx
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|md5final
function_decl|)
parameter_list|(
name|archive_md5_ctx
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|rmd160init
function_decl|)
parameter_list|(
name|archive_rmd160_ctx
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|rmd160update
function_decl|)
parameter_list|(
name|archive_rmd160_ctx
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|rmd160final
function_decl|)
parameter_list|(
name|archive_rmd160_ctx
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha1init
function_decl|)
parameter_list|(
name|archive_sha1_ctx
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha1update
function_decl|)
parameter_list|(
name|archive_sha1_ctx
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha1final
function_decl|)
parameter_list|(
name|archive_sha1_ctx
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha256init
function_decl|)
parameter_list|(
name|archive_sha256_ctx
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha256update
function_decl|)
parameter_list|(
name|archive_sha256_ctx
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha256final
function_decl|)
parameter_list|(
name|archive_sha256_ctx
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha384init
function_decl|)
parameter_list|(
name|archive_sha384_ctx
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha384update
function_decl|)
parameter_list|(
name|archive_sha384_ctx
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha384final
function_decl|)
parameter_list|(
name|archive_sha384_ctx
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha512init
function_decl|)
parameter_list|(
name|archive_sha512_ctx
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha512update
function_decl|)
parameter_list|(
name|archive_sha512_ctx
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|sha512final
function_decl|)
parameter_list|(
name|archive_sha512_ctx
modifier|*
parameter_list|,
name|void
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
name|archive_crypto
name|__archive_crypto
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

