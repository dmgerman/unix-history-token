begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Kenneth Almquist.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)main.h	8.2 (Berkeley) 5/4/95  * $FreeBSD$  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rootpid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pid of main shell */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rootshell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if we aren't a child of the main shell */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|jmploc
name|main_handler
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* top level exception handler */
end_comment

begin_function_decl
name|void
name|readcmdfile
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cmdloop
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|dotcmd
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
name|exitcmd
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

