begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)expand.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_struct
struct|struct
name|strlist
block|{
name|struct
name|strlist
modifier|*
name|next
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|arglist
block|{
name|struct
name|strlist
modifier|*
name|list
decl_stmt|;
name|struct
name|strlist
modifier|*
modifier|*
name|lastp
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
name|EXP_FULL
value|0x1
end_define

begin_comment
comment|/* perform word splitting& file globbing */
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
name|EXP_REDIR
value|0x8
end_define

begin_comment
comment|/* file glob for a redirection (1 match only) */
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

begin_union_decl
union_decl|union
name|node
union_decl|;
end_union_decl

begin_function_decl
name|void
name|expandhere
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
name|expari
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|patmatch
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
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
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

