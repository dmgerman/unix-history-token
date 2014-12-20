begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2005-2007, 2009  Internet Systems Consortium, Inc. ("ISC")  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: sha2.h,v 1.12 2009/10/22 02:21:31 each Exp $ */
end_comment

begin_comment
comment|/*	$FreeBSD: src/sys/crypto/sha2/sha2.h,v 1.1.2.1 2001/07/03 11:01:36 ume Exp $	*/
end_comment

begin_comment
comment|/*	$KAME: sha2.h,v 1.3 2001/03/12 08:27:48 itojun Exp $	*/
end_comment

begin_comment
comment|/*  * sha2.h  *  * Version 1.0.0beta1  *  * Written by Aaron D. Gifford<me@aarongifford.com>  *  * Copyright 2000 Aaron D. Gifford.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the copyright holder nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR(S) AND CONTRIBUTOR(S) ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR(S) OR CONTRIBUTOR(S) BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ISC_SHA2_H
end_ifndef

begin_define
define|#
directive|define
name|ISC_SHA2_H
end_define

begin_include
include|#
directive|include
file|<isc/lang.h>
end_include

begin_include
include|#
directive|include
file|<isc/platform.h>
end_include

begin_include
include|#
directive|include
file|<isc/types.h>
end_include

begin_comment
comment|/*** SHA-224/256/384/512 Various Length Definitions ***********************/
end_comment

begin_define
define|#
directive|define
name|ISC_SHA224_BLOCK_LENGTH
value|64U
end_define

begin_define
define|#
directive|define
name|ISC_SHA224_DIGESTLENGTH
value|28U
end_define

begin_define
define|#
directive|define
name|ISC_SHA224_DIGESTSTRINGLENGTH
value|(ISC_SHA224_DIGESTLENGTH * 2 + 1)
end_define

begin_define
define|#
directive|define
name|ISC_SHA256_BLOCK_LENGTH
value|64U
end_define

begin_define
define|#
directive|define
name|ISC_SHA256_DIGESTLENGTH
value|32U
end_define

begin_define
define|#
directive|define
name|ISC_SHA256_DIGESTSTRINGLENGTH
value|(ISC_SHA256_DIGESTLENGTH * 2 + 1)
end_define

begin_define
define|#
directive|define
name|ISC_SHA384_BLOCK_LENGTH
value|128
end_define

begin_define
define|#
directive|define
name|ISC_SHA384_DIGESTLENGTH
value|48U
end_define

begin_define
define|#
directive|define
name|ISC_SHA384_DIGESTSTRINGLENGTH
value|(ISC_SHA384_DIGESTLENGTH * 2 + 1)
end_define

begin_define
define|#
directive|define
name|ISC_SHA512_BLOCK_LENGTH
value|128U
end_define

begin_define
define|#
directive|define
name|ISC_SHA512_DIGESTLENGTH
value|64U
end_define

begin_define
define|#
directive|define
name|ISC_SHA512_DIGESTSTRINGLENGTH
value|(ISC_SHA512_DIGESTLENGTH * 2 + 1)
end_define

begin_comment
comment|/*** SHA-256/384/512 Context Structures *******************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISC_PLATFORM_OPENSSLHASH
end_ifdef

begin_include
include|#
directive|include
file|<openssl/evp.h>
end_include

begin_typedef
typedef|typedef
name|EVP_MD_CTX
name|isc_sha256_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|EVP_MD_CTX
name|isc_sha512_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Keep buffer immediately after bitcount to preserve alignment.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isc_uint32_t
name|state
index|[
literal|8
index|]
decl_stmt|;
name|isc_uint64_t
name|bitcount
decl_stmt|;
name|isc_uint8_t
name|buffer
index|[
name|ISC_SHA256_BLOCK_LENGTH
index|]
decl_stmt|;
block|}
name|isc_sha256_t
typedef|;
end_typedef

begin_comment
comment|/*  * Keep buffer immediately after bitcount to preserve alignment.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|isc_uint64_t
name|state
index|[
literal|8
index|]
decl_stmt|;
name|isc_uint64_t
name|bitcount
index|[
literal|2
index|]
decl_stmt|;
name|isc_uint8_t
name|buffer
index|[
name|ISC_SHA512_BLOCK_LENGTH
index|]
decl_stmt|;
block|}
name|isc_sha512_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
name|isc_sha256_t
name|isc_sha224_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|isc_sha512_t
name|isc_sha384_t
typedef|;
end_typedef

begin_function_decl
name|ISC_LANG_BEGINDECLS
comment|/*** SHA-224/256/384/512 Function Prototypes ******************************/
name|void
name|isc_sha224_init
parameter_list|(
name|isc_sha224_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha224_invalidate
parameter_list|(
name|isc_sha224_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha224_update
parameter_list|(
name|isc_sha224_t
modifier|*
parameter_list|,
specifier|const
name|isc_uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha224_final
parameter_list|(
name|isc_uint8_t
index|[
name|ISC_SHA224_DIGESTLENGTH
index|]
parameter_list|,
name|isc_sha224_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isc_sha224_end
parameter_list|(
name|isc_sha224_t
modifier|*
parameter_list|,
name|char
index|[
name|ISC_SHA224_DIGESTSTRINGLENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isc_sha224_data
parameter_list|(
specifier|const
name|isc_uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
index|[
name|ISC_SHA224_DIGESTSTRINGLENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha256_init
parameter_list|(
name|isc_sha256_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha256_invalidate
parameter_list|(
name|isc_sha256_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha256_update
parameter_list|(
name|isc_sha256_t
modifier|*
parameter_list|,
specifier|const
name|isc_uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha256_final
parameter_list|(
name|isc_uint8_t
index|[
name|ISC_SHA256_DIGESTLENGTH
index|]
parameter_list|,
name|isc_sha256_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isc_sha256_end
parameter_list|(
name|isc_sha256_t
modifier|*
parameter_list|,
name|char
index|[
name|ISC_SHA256_DIGESTSTRINGLENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isc_sha256_data
parameter_list|(
specifier|const
name|isc_uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
index|[
name|ISC_SHA256_DIGESTSTRINGLENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha384_init
parameter_list|(
name|isc_sha384_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha384_invalidate
parameter_list|(
name|isc_sha384_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha384_update
parameter_list|(
name|isc_sha384_t
modifier|*
parameter_list|,
specifier|const
name|isc_uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha384_final
parameter_list|(
name|isc_uint8_t
index|[
name|ISC_SHA384_DIGESTLENGTH
index|]
parameter_list|,
name|isc_sha384_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isc_sha384_end
parameter_list|(
name|isc_sha384_t
modifier|*
parameter_list|,
name|char
index|[
name|ISC_SHA384_DIGESTSTRINGLENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isc_sha384_data
parameter_list|(
specifier|const
name|isc_uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
index|[
name|ISC_SHA384_DIGESTSTRINGLENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha512_init
parameter_list|(
name|isc_sha512_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha512_invalidate
parameter_list|(
name|isc_sha512_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha512_update
parameter_list|(
name|isc_sha512_t
modifier|*
parameter_list|,
specifier|const
name|isc_uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|isc_sha512_final
parameter_list|(
name|isc_uint8_t
index|[
name|ISC_SHA512_DIGESTLENGTH
index|]
parameter_list|,
name|isc_sha512_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isc_sha512_end
parameter_list|(
name|isc_sha512_t
modifier|*
parameter_list|,
name|char
index|[
name|ISC_SHA512_DIGESTSTRINGLENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|isc_sha512_data
parameter_list|(
specifier|const
name|isc_uint8_t
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
index|[
name|ISC_SHA512_DIGESTSTRINGLENGTH
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|ISC_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISC_SHA2_H */
end_comment

end_unit

