begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	@(#)ttyent.h	8.1 (Berkeley) 6/2/93  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TTYENT_H_
end_ifndef

begin_define
define|#
directive|define
name|_TTYENT_H_
end_define

begin_define
define|#
directive|define
name|_PATH_TTYS
value|"/etc/ttys"
end_define

begin_define
define|#
directive|define
name|_TTYS_OFF
value|"off"
end_define

begin_define
define|#
directive|define
name|_TTYS_ON
value|"on"
end_define

begin_define
define|#
directive|define
name|_TTYS_SECURE
value|"secure"
end_define

begin_define
define|#
directive|define
name|_TTYS_INSECURE
value|"insecure"
end_define

begin_define
define|#
directive|define
name|_TTYS_WINDOW
value|"window"
end_define

begin_define
define|#
directive|define
name|_TTYS_GROUP
value|"group"
end_define

begin_define
define|#
directive|define
name|_TTYS_NOGROUP
value|"none"
end_define

begin_define
define|#
directive|define
name|_TTYS_DIALUP
value|"dialup"
end_define

begin_define
define|#
directive|define
name|_TTYS_NETWORK
value|"network"
end_define

begin_struct
struct|struct
name|ttyent
block|{
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
comment|/* terminal type for termcap */
define|#
directive|define
name|TTY_ON
value|0x01
comment|/* enable logins (start ty_getty program) */
define|#
directive|define
name|TTY_SECURE
value|0x02
comment|/* allow uid of 0 to login */
define|#
directive|define
name|TTY_DIALUP
value|0x04
comment|/* is a dialup tty */
define|#
directive|define
name|TTY_NETWORK
value|0x08
comment|/* is a network tty */
name|int
name|ty_status
decl_stmt|;
comment|/* status flags */
name|char
modifier|*
name|ty_window
decl_stmt|;
comment|/* command to start up window manager */
name|char
modifier|*
name|ty_comment
decl_stmt|;
comment|/* comment field */
name|char
modifier|*
name|ty_group
decl_stmt|;
comment|/* tty group */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_function_decl
name|__BEGIN_DECLS
name|struct
name|ttyent
modifier|*
name|getttyent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ttyent
modifier|*
name|getttynam
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|setttyent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|endttyent
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isdialuptty
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isnettty
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__END_DECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TTYENT_H_ */
end_comment

end_unit

