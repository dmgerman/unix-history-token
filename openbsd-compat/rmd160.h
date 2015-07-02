begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: rmd160.h,v 1.17 2012/12/05 23:19:57 deraadt Exp $	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RMD160_H
end_ifndef

begin_define
define|#
directive|define
name|_RMD160_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|WITH_OPENSSL
end_ifndef

begin_define
define|#
directive|define
name|RMD160_BLOCK_LENGTH
value|64
end_define

begin_define
define|#
directive|define
name|RMD160_DIGEST_LENGTH
value|20
end_define

begin_define
define|#
directive|define
name|RMD160_DIGEST_STRING_LENGTH
value|(RMD160_DIGEST_LENGTH * 2 + 1)
end_define

begin_comment
comment|/* RMD160 context. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|RMD160Context
block|{
name|u_int32_t
name|state
index|[
literal|5
index|]
decl_stmt|;
comment|/* state */
name|u_int64_t
name|count
decl_stmt|;
comment|/* number of bits, mod 2^64 */
name|u_int8_t
name|buffer
index|[
name|RMD160_BLOCK_LENGTH
index|]
decl_stmt|;
comment|/* input buffer */
block|}
name|RMD160_CTX
typedef|;
end_typedef

begin_function_decl
name|void
name|RMD160Init
parameter_list|(
name|RMD160_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RMD160Transform
parameter_list|(
name|u_int32_t
index|[
literal|5
index|]
parameter_list|,
specifier|const
name|u_int8_t
index|[
name|RMD160_BLOCK_LENGTH
index|]
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__bounded__
parameter_list|(
name|__minbytes__
parameter_list|,
function_decl|1
operator|,
function_decl|5
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
literal|2
argument_list|,
name|RMD160_BLOCK_LENGTH
argument_list|)
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|RMD160Update
parameter_list|(
name|RMD160_CTX
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
name|RMD160Pad
parameter_list|(
name|RMD160_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RMD160Final
parameter_list|(
name|u_int8_t
index|[
name|RMD160_DIGEST_LENGTH
index|]
parameter_list|,
name|RMD160_CTX
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
function_decl|RMD160_DIGEST_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|RMD160End
parameter_list|(
name|RMD160_CTX
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
function_decl|RMD160_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|RMD160File
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
function_decl|RMD160_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|RMD160FileChunk
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
function_decl|RMD160_DIGEST_STRING_LENGTH
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|char
modifier|*
name|RMD160Data
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
name|RMD160_DIGEST_STRING_LENGTH
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
comment|/* !WITH_OPENSSL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RMD160_H */
end_comment

end_unit

