begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009 Joerg Sonnenberger  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/*  * Hash function support in various Operating Systems:  *  * NetBSD:  * - MD5 and SHA1 in libc: without _ after algorithm name  * - SHA2 in libc: with _ after algorithm name  *  * OpenBSD:  * - MD5, SHA1 and SHA2 in libc: without _ after algorithm name  * - OpenBSD 4.4 and earlier have SHA2 in libc with _ after algorithm name  *  * DragonFly and FreeBSD (XXX not used yet):  * - MD5 and SHA1 in libmd: without _ after algorithm name  * - SHA256: with _ after algorithm name  *  * OpenSSL:  * - MD5, SHA1 and SHA2 in libcrypto: with _ after algorithm name  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_MD5_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_MD5INIT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<md5.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_MD5
end_define

begin_typedef
typedef|typedef
name|MD5_CTX
name|archive_md5_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_md5_init
parameter_list|(
name|ctx
parameter_list|)
value|MD5Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_md5_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|MD5Final(buf, ctx)
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
value|MD5Update(ctx, buf, n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_OPENSSL_MD5_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/md5.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_MD5
end_define

begin_typedef
typedef|typedef
name|MD5_CTX
name|archive_md5_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_md5_init
parameter_list|(
name|ctx
parameter_list|)
value|MD5_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_md5_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|MD5_Final(buf, ctx)
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
value|MD5_Update(ctx, buf, n)
end_define

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
name|CALG_MD5
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ARCHIVE_HAS_MD5
end_define

begin_typedef
typedef|typedef
name|MD5_CTX
name|archive_md5_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_md5_init
parameter_list|(
name|ctx
parameter_list|)
value|MD5_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_md5_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|MD5_Final(buf, ctx)
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
value|MD5_Update(ctx, buf, n)
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
name|HAVE_RMD160_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_RMD160INIT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<rmd160.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_RMD160
end_define

begin_typedef
typedef|typedef
name|RMD160_CTX
name|archive_rmd160_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_rmd160_init
parameter_list|(
name|ctx
parameter_list|)
value|RMD160Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_rmd160_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|RMD160Final(buf, ctx)
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
value|RMD160Update(ctx, buf, n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_OPENSSL_RIPEMD_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/ripemd.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_RMD160
end_define

begin_typedef
typedef|typedef
name|RIPEMD160_CTX
name|archive_rmd160_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_rmd160_init
parameter_list|(
name|ctx
parameter_list|)
value|RIPEMD160_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_rmd160_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|RIPEMD160_Final(buf, ctx)
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
value|RIPEMD160_Update(ctx, buf, n)
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
name|HAVE_SHA1_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SHA1INIT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sha1.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA1
end_define

begin_typedef
typedef|typedef
name|SHA1_CTX
name|archive_sha1_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha1_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA1Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha1_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA1Final(buf, ctx)
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
value|SHA1Update(ctx, buf, n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_OPENSSL_SHA_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/sha.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA1
end_define

begin_typedef
typedef|typedef
name|SHA_CTX
name|archive_sha1_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha1_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA1_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha1_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA1_Final(buf, ctx)
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
value|SHA1_Update(ctx, buf, n)
end_define

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
name|CALG_SHA1
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA1
end_define

begin_typedef
typedef|typedef
name|SHA1_CTX
name|archive_sha1_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha1_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA1_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha1_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA1_Final(buf, ctx)
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
value|SHA1_Update(ctx, buf, n)
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
name|HAVE_SHA2_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SHA256_INIT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sha2.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA256
end_define

begin_typedef
typedef|typedef
name|SHA256_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha256_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA256_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha256_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA256_Final(buf, ctx)
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
value|SHA256_Update(ctx, buf, n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SHA2_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SHA256INIT
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sha2.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA256
end_define

begin_typedef
typedef|typedef
name|SHA256_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha256_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA256Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha256_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA256Final(buf, ctx)
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
value|SHA256Update(ctx, buf, n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_OPENSSL_SHA_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_OPENSSL_SHA256_INIT
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/sha.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA256
end_define

begin_typedef
typedef|typedef
name|SHA256_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha256_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA256_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha256_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA256_Final(buf, ctx)
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
value|SHA256_Update(ctx, buf, n)
end_define

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
name|CALG_SHA_256
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA256
end_define

begin_typedef
typedef|typedef
name|SHA256_CTX
name|archive_sha256_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha256_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA256_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha256_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA256_Final(buf, ctx)
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
value|SHA256_Update(ctx, buf, n)
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
name|HAVE_SHA2_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SHA384_INIT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sha2.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA384
end_define

begin_typedef
typedef|typedef
name|SHA384_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha384_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA384_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha384_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA384_Final(buf, ctx)
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
value|SHA384_Update(ctx, buf, n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SHA2_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SHA384INIT
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sha2.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA384
end_define

begin_typedef
typedef|typedef
name|SHA384_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha384_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA384Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha384_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA384Final(buf, ctx)
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
value|SHA384Update(ctx, buf, n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_OPENSSL_SHA_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_OPENSSL_SHA384_INIT
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/sha.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA384
end_define

begin_typedef
typedef|typedef
name|SHA512_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha384_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA384_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha384_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA384_Final(buf, ctx)
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
value|SHA384_Update(ctx, buf, n)
end_define

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
name|CALG_SHA_384
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA384
end_define

begin_typedef
typedef|typedef
name|SHA512_CTX
name|archive_sha384_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha384_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA384_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha384_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA384_Final(buf, ctx)
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
value|SHA384_Update(ctx, buf, n)
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
name|HAVE_SHA2_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SHA512_INIT
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sha2.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA512
end_define

begin_typedef
typedef|typedef
name|SHA512_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha512_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA512_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha512_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA512_Final(buf, ctx)
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
value|SHA512_Update(ctx, buf, n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SHA2_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_SHA512INIT
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sha2.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA512
end_define

begin_typedef
typedef|typedef
name|SHA512_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha512_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA512Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha512_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA512Final(buf, ctx)
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
value|SHA512Update(ctx, buf, n)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_OPENSSL_SHA_H
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_OPENSSL_SHA512_INIT
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<openssl/sha.h>
end_include

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA512
end_define

begin_typedef
typedef|typedef
name|SHA512_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha512_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA512_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha512_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA512_Final(buf, ctx)
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
value|SHA512_Update(ctx, buf, n)
end_define

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
name|CALG_SHA_512
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ARCHIVE_HAS_SHA512
end_define

begin_typedef
typedef|typedef
name|SHA512_CTX
name|archive_sha512_ctx
typedef|;
end_typedef

begin_define
define|#
directive|define
name|archive_sha512_init
parameter_list|(
name|ctx
parameter_list|)
value|SHA512_Init(ctx)
end_define

begin_define
define|#
directive|define
name|archive_sha512_final
parameter_list|(
name|ctx
parameter_list|,
name|buf
parameter_list|)
value|SHA512_Final(buf, ctx)
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
value|SHA512_Update(ctx, buf, n)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

