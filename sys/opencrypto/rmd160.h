begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*	$OpenBSD: rmd160.h,v 1.3 2002/03/14 01:26:51 millert Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 2001 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
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
comment|/* number of bits, modulo 2^64 */
name|u_char
name|buffer
index|[
literal|64
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
name|u_char
index|[
literal|64
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RMD160Update
parameter_list|(
name|RMD160_CTX
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|RMD160Final
parameter_list|(
name|u_char
index|[
literal|20
index|]
parameter_list|,
name|RMD160_CTX
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RMD160_H */
end_comment

end_unit

