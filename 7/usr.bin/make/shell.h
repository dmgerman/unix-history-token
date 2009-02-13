begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1988, 1989, 1990, 1993  *	The Regents of the University of California.  All rights reserved.  * Copyright (c) 1988, 1989 by Adam de Boor  * Copyright (c) 1989 by Berkeley Softworks  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Adam de Boor.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|shell_h_6002e3b8
end_ifndef

begin_define
define|#
directive|define
name|shell_h_6002e3b8
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|"str.h"
end_include

begin_include
include|#
directive|include
file|"util.h"
end_include

begin_comment
comment|/**  * Shell Specifications:  *  * Some special stuff goes on if a shell doesn't have error control. In such  * a case, errCheck becomes a printf template for echoing the command,  * should echoing be on and ignErr becomes another printf template for  * executing the command while ignoring the return status. If either of these  * strings is empty when hasErrCtl is FALSE, the command will be executed  * anyway as is and if it causes an error, so be it.  */
end_comment

begin_struct
struct|struct
name|Shell
block|{
name|TAILQ_ENTRY
argument_list|(
argument|Shell
argument_list|)
name|link
expr_stmt|;
comment|/* link all shell descriptions */
comment|/* 	 * the name of the shell. For Bourne and C shells, this is used 	 * only to find the shell description when used as the single 	 * source of a .SHELL target. 	 */
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|path
decl_stmt|;
comment|/* full path to the shell */
comment|/* True if both echoOff and echoOn defined */
name|Boolean
name|hasEchoCtl
decl_stmt|;
name|char
modifier|*
name|echoOff
decl_stmt|;
comment|/* command to turn off echo */
name|char
modifier|*
name|echoOn
decl_stmt|;
comment|/* command to turn it back on */
comment|/* 	 * What the shell prints, and its length, when given the 	 * echo-off command. This line will not be printed when 	 * received from the shell. This is usually the command which 	 * was executed to turn off echoing 	 */
name|char
modifier|*
name|noPrint
decl_stmt|;
comment|/* set if can control error checking for individual commands */
name|Boolean
name|hasErrCtl
decl_stmt|;
comment|/* string to turn error checking on */
name|char
modifier|*
name|errCheck
decl_stmt|;
comment|/* string to turn off error checking */
name|char
modifier|*
name|ignErr
decl_stmt|;
name|char
modifier|*
name|echo
decl_stmt|;
comment|/* command line flag: echo commands */
name|char
modifier|*
name|exit
decl_stmt|;
comment|/* command line flag: exit on error */
name|ArgArray
name|builtins
decl_stmt|;
comment|/* ordered list of shell builtins */
name|char
modifier|*
name|meta
decl_stmt|;
comment|/* shell meta characters */
name|Boolean
name|unsetenv
decl_stmt|;
comment|/* unsetenv("ENV") before exec */
block|}
struct|;
end_struct

begin_expr_stmt
name|TAILQ_HEAD
argument_list|(
name|Shells
argument_list|,
name|Shell
argument_list|)
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|extern
name|struct
name|Shell
modifier|*
name|commandShell
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|Shell_Init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Boolean
name|Shell_Parse
parameter_list|(
specifier|const
name|char
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* shell_h_6002e3b8 */
end_comment

end_unit

