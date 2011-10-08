begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: sha2.h,v 1.6 2004/06/22 01:57:30 jfb Exp $	*/
end_comment

begin_comment
comment|/*  * FILE:	sha2.h  * AUTHOR:	Aaron D. Gifford<me@aarongifford.com>  *   * Copyright (c) 2000-2001, Aaron D. Gifford  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the copyright holder nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTOR(S) ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTOR(S) BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $From: sha2.h,v 1.1 2001/11/08 00:02:01 adg Exp adg $  */
end_comment

begin_comment
comment|/* OPENBSD ORIGINAL: include/sha2.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SSHSHA2_H
end_ifndef

begin_define
define|#
directive|define
name|_SSHSHA2_H
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_EVP_SHA256
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_SHA256_UPDATE
argument_list|)
operator|&&
expr|\
operator|(
name|OPENSSL_VERSION_NUMBER
operator|>=
literal|0x00907000L
operator|)
end_if

begin_comment
comment|/*** SHA-256/384/512 Various Length Definitions ***********************/
end_comment

begin_define
define|#
directive|define
name|SHA256_BLOCK_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|SHA256_DIGEST_LENGTH
value|32
end_define

begin_define
define|#
directive|define
name|SHA256_DIGEST_STRING_LENGTH
value|(SHA256_DIGEST_LENGTH * 2 + 1)
end_define

begin_define
define|#
directive|define
name|SHA384_BLOCK_LENGTH
value|128
end_define

begin_define
define|#
directive|define
name|SHA384_DIGEST_LENGTH
value|48
end_define

begin_define
define|#
directive|define
name|SHA384_DIGEST_STRING_LENGTH
value|(SHA384_DIGEST_LENGTH * 2 + 1)
end_define

begin_define
define|#
directive|define
name|SHA512_BLOCK_LENGTH
value|128
end_define

begin_define
define|#
directive|define
name|SHA512_DIGEST_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|SHA512_DIGEST_STRING_LENGTH
value|(SHA512_DIGEST_LENGTH * 2 + 1)
end_define

begin_comment
comment|/*** SHA-256/384/512 Context Structures *******************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_SHA256_CTX
block|{
name|u_int32_t
name|state
index|[
literal|8
index|]
decl_stmt|;
name|u_int64_t
name|bitcount
decl_stmt|;
name|u_int8_t
name|buffer
index|[
name|SHA256_BLOCK_LENGTH
index|]
decl_stmt|;
block|}
name|SHA256_CTX
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SHA512_CTX
block|{
name|u_int64_t
name|state
index|[
literal|8
index|]
decl_stmt|;
name|u_int64_t
name|bitcount
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|buffer
index|[
name|SHA512_BLOCK_LENGTH
index|]
decl_stmt|;
block|}
name|SHA512_CTX
typedef|;
end_typedef

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|typedef SHA512_CTX SHA384_CTX;
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|SHA256_Init
parameter_list|(
name|SHA256_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA256_Transform
parameter_list|(
name|u_int32_t
name|state
index|[
literal|8
index|]
parameter_list|,
specifier|const
name|u_int8_t
index|[
name|SHA256_BLOCK_LENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA256_Update
parameter_list|(
name|SHA256_CTX
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__string__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|SHA256_Pad
parameter_list|(
name|SHA256_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA256_Final
parameter_list|(
name|u_int8_t
index|[
name|SHA256_DIGEST_LENGTH
index|]
parameter_list|,
name|SHA256_CTX
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|SHA256_DIGEST_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA256_End
parameter_list|(
name|SHA256_CTX
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|SHA256_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA256_File
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|SHA256_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA256_FileChunk
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|SHA256_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA256_Data
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__string__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|__bounded__
argument_list|(
name|__minbytes__
argument_list|,
literal|3
argument_list|,
name|SHA256_DIGEST_STRING_LENGTH
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|void SHA384_Init(SHA384_CTX *); void SHA384_Transform(u_int64_t state[8], const u_int8_t [SHA384_BLOCK_LENGTH]); void SHA384_Update(SHA384_CTX *, const u_int8_t *, size_t) 	__attribute__((__bounded__(__string__,2,3))); void SHA384_Pad(SHA384_CTX *); void SHA384_Final(u_int8_t [SHA384_DIGEST_LENGTH], SHA384_CTX *) 	__attribute__((__bounded__(__minbytes__,1,SHA384_DIGEST_LENGTH))); char *SHA384_End(SHA384_CTX *, char *) 	__attribute__((__bounded__(__minbytes__,2,SHA384_DIGEST_STRING_LENGTH))); char *SHA384_File(const char *, char *) 	__attribute__((__bounded__(__minbytes__,2,SHA384_DIGEST_STRING_LENGTH))); char *SHA384_FileChunk(const char *, char *, off_t, off_t) 	__attribute__((__bounded__(__minbytes__,2,SHA384_DIGEST_STRING_LENGTH))); char *SHA384_Data(const u_int8_t *, size_t, char *) 	__attribute__((__bounded__(__string__,1,2))) 	__attribute__((__bounded__(__minbytes__,3,SHA384_DIGEST_STRING_LENGTH)));
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_function_decl
name|void
name|SHA512_Init
parameter_list|(
name|SHA512_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA512_Transform
parameter_list|(
name|u_int64_t
name|state
index|[
literal|8
index|]
parameter_list|,
specifier|const
name|u_int8_t
index|[
name|SHA512_BLOCK_LENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA512_Update
parameter_list|(
name|SHA512_CTX
modifier|*
parameter_list|,
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__string__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|SHA512_Pad
parameter_list|(
name|SHA512_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|SHA512_Final
parameter_list|(
name|u_int8_t
index|[
name|SHA512_DIGEST_LENGTH
index|]
parameter_list|,
name|SHA512_CTX
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|SHA512_DIGEST_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA512_End
parameter_list|(
name|SHA512_CTX
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|SHA512_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA512_File
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|SHA512_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA512_FileChunk
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|off_t
parameter_list|,
name|off_t
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|2
operator|,
function_decl|SHA512_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|SHA512_Data
parameter_list|(
specifier|const
name|u_int8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__string__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_expr_stmt
unit|)))
name|__attribute__
argument_list|(
operator|(
name|__bounded__
argument_list|(
name|__minbytes__
argument_list|,
literal|3
argument_list|,
name|SHA512_DIGEST_STRING_LENGTH
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(HAVE_EVP_SHA256)&& !defined(HAVE_SHA256_UPDATE)&& \     (OPENSSL_VERSION_NUMBER>= 0x00907000L) */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SSHSHA2_H */
end_comment

end_unit

