begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)exec.h	8.3 (Berkeley) 6/8/95  * $FreeBSD$  */
end_comment

begin_comment
comment|/* values of cmdtype */
end_comment

begin_define
define|#
directive|define
name|CMDUNKNOWN
value|-1
end_define

begin_comment
comment|/* no entry in table for command */
end_comment

begin_define
define|#
directive|define
name|CMDNORMAL
value|0
end_define

begin_comment
comment|/* command is an executable program */
end_comment

begin_define
define|#
directive|define
name|CMDBUILTIN
value|1
end_define

begin_comment
comment|/* command is a shell builtin */
end_comment

begin_define
define|#
directive|define
name|CMDFUNCTION
value|2
end_define

begin_comment
comment|/* command is a shell function */
end_comment

begin_struct
struct|struct
name|cmdentry
block|{
name|int
name|cmdtype
decl_stmt|;
union|union
name|param
block|{
name|int
name|index
decl_stmt|;
name|union
name|node
modifier|*
name|func
decl_stmt|;
block|}
name|u
union|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|pathopt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by padvance */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|exerrno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* last exec error */
end_comment

begin_function_decl
name|void
name|shellexec
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
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
name|char
modifier|*
name|padvance
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hashcmd
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
name|find_command
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|cmdentry
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_builtin
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hashcd
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|changepath
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|deletefuncs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|getcmdentry
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|cmdentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|addcmdentry
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|cmdentry
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|defun
parameter_list|(
name|char
modifier|*
parameter_list|,
name|union
name|node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unsetfunc
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|typecmd
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
name|clearcmdentry
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

