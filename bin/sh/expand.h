begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)expand.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|arglist
block|{
name|char
modifier|*
modifier|*
name|args
decl_stmt|;
name|int
name|count
decl_stmt|;
name|int
name|capacity
decl_stmt|;
name|char
modifier|*
name|smallarg
index|[
literal|1
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * expandarg() flags  */
end_comment

begin_define
define|#
directive|define
name|EXP_SPLIT
value|0x1
end_define

begin_comment
comment|/* perform word splitting */
end_comment

begin_define
define|#
directive|define
name|EXP_TILDE
value|0x2
end_define

begin_comment
comment|/* do normal tilde expansion */
end_comment

begin_define
define|#
directive|define
name|EXP_VARTILDE
value|0x4
end_define

begin_comment
comment|/* expand tildes in an assignment */
end_comment

begin_define
define|#
directive|define
name|EXP_CASE
value|0x10
end_define

begin_comment
comment|/* keeps quotes around for CASE pattern */
end_comment

begin_define
define|#
directive|define
name|EXP_SPLIT_LIT
value|0x20
end_define

begin_comment
comment|/* IFS split literal text ${v+-a b c} */
end_comment

begin_define
define|#
directive|define
name|EXP_LIT_QUOTED
value|0x40
end_define

begin_comment
comment|/* for EXP_SPLIT_LIT, start off quoted */
end_comment

begin_define
define|#
directive|define
name|EXP_GLOB
value|0x80
end_define

begin_comment
comment|/* perform file globbing */
end_comment

begin_define
define|#
directive|define
name|EXP_FULL
value|(EXP_SPLIT | EXP_GLOB)
end_define

begin_function_decl
name|void
name|emptyarglist
parameter_list|(
name|struct
name|arglist
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|appendarglist
parameter_list|(
name|struct
name|arglist
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_union_decl
union_decl|union
name|node
union_decl|;
end_union_decl

begin_function_decl
name|void
name|expandarg
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|struct
name|arglist
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|rmescapes
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|casematch
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

