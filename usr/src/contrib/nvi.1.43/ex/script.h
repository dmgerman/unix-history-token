begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)script.h	9.2 (Berkeley) 12/2/94  */
end_comment

begin_struct
struct|struct
name|_script
block|{
name|pid_t
name|sh_pid
decl_stmt|;
comment|/* Shell pid. */
name|int
name|sh_master
decl_stmt|;
comment|/* Master pty fd. */
name|int
name|sh_slave
decl_stmt|;
comment|/* Slave pty fd. */
name|char
modifier|*
name|sh_prompt
decl_stmt|;
comment|/* Prompt. */
name|size_t
name|sh_prompt_len
decl_stmt|;
comment|/* Prompt length. */
name|char
name|sh_name
index|[
literal|64
index|]
decl_stmt|;
comment|/* Pty name */
ifdef|#
directive|ifdef
name|TIOCGWINSZ
name|struct
name|winsize
name|sh_win
decl_stmt|;
comment|/* Window size. */
endif|#
directive|endif
name|struct
name|termios
name|sh_term
decl_stmt|;
comment|/* Terminal information. */
block|}
struct|;
end_struct

end_unit

