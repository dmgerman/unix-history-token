begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)eval.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|commandname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* currently executing command */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exitstatus
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* exit status of last command */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|strlist
modifier|*
name|cmdenviron
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* environment for builtin command */
end_comment

begin_struct
struct|struct
name|backcmd
block|{
comment|/* result of evalbackcmd */
name|int
name|fd
decl_stmt|;
comment|/* file descriptor to read from */
name|char
modifier|*
name|buf
decl_stmt|;
comment|/* buffer */
name|int
name|nleft
decl_stmt|;
comment|/* number of chars in buffer */
name|struct
name|job
modifier|*
name|jp
decl_stmt|;
comment|/* job structure for command */
block|}
struct|;
end_struct

begin_function_decl
name|int
name|evalcmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|evalstring
parameter_list|(
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

begin_comment
comment|/* BLETCH for ansi C */
end_comment

begin_function_decl
name|void
name|evaltree
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
name|evalbackcmd
parameter_list|(
name|union
name|node
modifier|*
parameter_list|,
name|struct
name|backcmd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bltincmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|breakcmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|returncmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|falsecmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|truecmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|execcmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in_function returns nonzero if we are currently evaluating a function */
end_comment

begin_define
define|#
directive|define
name|in_function
parameter_list|()
value|funcnest
end_define

begin_decl_stmt
specifier|extern
name|int
name|funcnest
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|evalskip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* reasons for skipping commands (see comment on breakcmd routine) */
end_comment

begin_define
define|#
directive|define
name|SKIPBREAK
value|1
end_define

begin_define
define|#
directive|define
name|SKIPCONT
value|2
end_define

begin_define
define|#
directive|define
name|SKIPFUNC
value|3
end_define

begin_define
define|#
directive|define
name|SKIPFILE
value|4
end_define

end_unit

