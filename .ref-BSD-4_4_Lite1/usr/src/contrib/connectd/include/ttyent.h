begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1993 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Bill Jolitz.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ttyent.h	5.2 (Berkeley) 5/29/93  */
end_comment

begin_struct
struct|struct
name|ttyent
block|{
comment|/* see getttyent(3) */
name|char
modifier|*
name|ty_name
decl_stmt|;
comment|/* terminal device name */
name|char
modifier|*
name|ty_getty
decl_stmt|;
comment|/* command to execute, usually getty */
name|char
modifier|*
name|ty_type
decl_stmt|;
comment|/* terminal type for termcap (3X) */
name|int
name|ty_status
decl_stmt|;
comment|/* status flags (see below for defines) */
name|char
modifier|*
name|ty_window
decl_stmt|;
comment|/* command to start up window manager */
name|char
modifier|*
name|ty_comment
decl_stmt|;
comment|/* usually the location of the terminal */
name|char
modifier|*
modifier|*
name|ty_flags
decl_stmt|;
comment|/* list of flag strings, null terminated */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TTY_ON
value|0x1
end_define

begin_comment
comment|/* enable logins (startup getty) */
end_comment

begin_define
define|#
directive|define
name|TTY_SECURE
value|0x2
end_define

begin_comment
comment|/* allow root to login */
end_comment

begin_function_decl
specifier|extern
name|struct
name|ttyent
modifier|*
name|getttyent
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|ttyent
modifier|*
name|getttynam
parameter_list|()
function_decl|;
end_function_decl

end_unit

