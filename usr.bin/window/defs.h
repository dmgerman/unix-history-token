begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Edward Wang at The University of California, Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)defs.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|"ww.h"
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_define
define|#
directive|define
name|NWINDOW
value|9
end_define

begin_decl_stmt
name|struct
name|timeval
name|starttime
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|ww
modifier|*
name|window
index|[
name|NWINDOW
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the windows */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|selwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the selected window */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|lastselwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last selected window */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|cmdwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the command window */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|framewin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the window for framing */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|boxwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the window for the box */
end_comment

begin_decl_stmt
name|struct
name|ww
modifier|*
name|fgwin
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the last foreground window */
end_comment

begin_define
define|#
directive|define
name|isfg
parameter_list|(
name|w
parameter_list|)
value|((w)->ww_order<= fgwin->ww_order)
end_define

begin_decl_stmt
name|char
modifier|*
name|default_shell
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default shell argv */
end_comment

begin_decl_stmt
name|char
modifier|*
name|default_shellfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default shell program */
end_comment

begin_decl_stmt
name|int
name|default_nline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default buffer size for new windows */
end_comment

begin_decl_stmt
name|int
name|default_smooth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* default "smooth" parameter */
end_comment

begin_decl_stmt
name|char
name|escapec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the escape character */
end_comment

begin_comment
comment|/* flags */
end_comment

begin_decl_stmt
name|char
name|quit
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* quit command issued */
end_comment

begin_decl_stmt
name|char
name|terse
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* terse mode */
end_comment

begin_decl_stmt
name|char
name|debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debug mode */
end_comment

begin_decl_stmt
name|char
name|incmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in command mode */
end_comment

begin_function_decl
name|struct
name|ww
modifier|*
name|getwin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|openwin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|vtowin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ww
modifier|*
name|openiwin
parameter_list|()
function_decl|;
end_function_decl

end_unit

