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
name|ARCHIVE_HMAC_PRIVATE_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_HMAC_PRIVATE_H_INCLUDED
end_define

begin_comment
comment|/*  * On systems that do not support any recognized crypto libraries,  * the archive_hmac.c file is expected to define no usable symbols.  *  * But some compilers and linkers choke on empty object files, so  * define a public symbol that will always exist.  This could  * be removed someday if this file gains another always-present  * symbol definition.  */
end_comment

begin_function_decl
name|int
name|__libarchive_hmac_build_hack
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
literal|1060
end_if

begin_define
define|#
directive|define
name|ARCHIVE_HMAC_USE_Apple_CommonCrypto
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
name|ARCHIVE_HMAC_USE_Apple_CommonCrypto
end_ifdef

begin_include
include|#
directive|include
file|<CommonCrypto/CommonHMAC.h>
end_include

begin_typedef
typedef|typedef
name|CCHmacContext
name|archive_hmac_sha1_ctx
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

begin_typedef
typedef|typedef
struct|struct
block|{
name|BCRYPT_ALG_HANDLE
name|hAlg
decl_stmt|;
name|BCRYPT_HASH_HANDLE
name|hHash
decl_stmt|;
name|DWORD
name|hash_len
decl_stmt|;
name|PBYTE
name|hash
decl_stmt|;
block|}
name|archive_hmac_sha1_ctx
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
name|HAVE_NETTLE_HMAC_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<nettle/hmac.h>
end_include

begin_typedef
typedef|typedef
name|struct
name|hmac_sha1_ctx
name|archive_hmac_sha1_ctx
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
file|<openssl/hmac.h>
end_include

begin_typedef
typedef|typedef
name|HMAC_CTX
name|archive_hmac_sha1_ctx
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|int
name|archive_hmac_sha1_ctx
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HMAC */
end_comment

begin_define
define|#
directive|define
name|archive_hmac_sha1_init
parameter_list|(
name|ctx
parameter_list|,
name|key
parameter_list|,
name|key_len
parameter_list|)
define|\
value|__archive_hmac.__hmac_sha1_init(ctx, key, key_len)
end_define

begin_define
define|#
directive|define
name|archive_hmac_sha1_update
parameter_list|(
name|ctx
parameter_list|,
name|data
parameter_list|,
name|data_len
parameter_list|)
define|\
value|__archive_hmac.__hmac_sha1_update(ctx, data, data_len)
end_define

begin_define
define|#
directive|define
name|archive_hmac_sha1_final
parameter_list|(
name|ctx
parameter_list|,
name|out
parameter_list|,
name|out_len
parameter_list|)
define|\
value|__archive_hmac.__hmac_sha1_final(ctx, out, out_len)
end_define

begin_define
define|#
directive|define
name|archive_hmac_sha1_cleanup
parameter_list|(
name|ctx
parameter_list|)
define|\
value|__archive_hmac.__hmac_sha1_cleanup(ctx)
end_define

begin_struct
struct|struct
name|archive_hmac
block|{
comment|/* HMAC */
name|int
function_decl|(
modifier|*
name|__hmac_sha1_init
function_decl|)
parameter_list|(
name|archive_hmac_sha1_ctx
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|__hmac_sha1_update
function_decl|)
parameter_list|(
name|archive_hmac_sha1_ctx
modifier|*
parameter_list|,
specifier|const
name|uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|__hmac_sha1_final
function_decl|)
parameter_list|(
name|archive_hmac_sha1_ctx
modifier|*
parameter_list|,
name|uint8_t
modifier|*
parameter_list|,
name|size_t
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|__hmac_sha1_cleanup
function_decl|)
parameter_list|(
name|archive_hmac_sha1_ctx
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
name|archive_hmac
name|__archive_hmac
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARCHIVE_HMAC_PRIVATE_H_INCLUDED */
end_comment

end_unit

