begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)main.h	8.1 (Berkeley) 6/6/93  */
end_comment

begin_comment
comment|/*  * Definitions for main program.  *  * The main program just handles the command arguments and then  * gives control to the command module.  It's also the center of  * error recovery, since non-fatal errors longjmp into the main routine.  */
end_comment

begin_decl_stmt
name|BOOLEAN
name|opt
index|[
literal|26
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if command line option given */
end_comment

begin_define
define|#
directive|define
name|option
parameter_list|(
name|c
parameter_list|)
value|opt[(c)-'a']
end_define

begin_define
define|#
directive|define
name|isterm
parameter_list|(
name|file
parameter_list|)
value|(option('i') || isatty(fileno(file)))
end_define

begin_function_decl
name|int
name|main
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* debugger main routine */
end_comment

begin_function_decl
name|int
name|init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* read in source and object data */
end_comment

begin_function_decl
name|int
name|erecover
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* does non-local goto for error recovery */
end_comment

begin_function_decl
name|int
name|quit
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* clean-up before exiting */
end_comment

end_unit

