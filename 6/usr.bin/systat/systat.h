begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1980, 1989, 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	From: @(#)systat.h	8.1 (Berkeley) 6/6/93  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<curses.h>
end_include

begin_struct
struct|struct
name|cmdtab
block|{
specifier|const
name|char
modifier|*
name|c_name
decl_stmt|;
comment|/* command name */
name|void
function_decl|(
modifier|*
name|c_refresh
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* display refresh */
name|void
function_decl|(
modifier|*
name|c_fetch
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* sets up data structures */
name|void
function_decl|(
modifier|*
name|c_label
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* label display */
name|int
function_decl|(
modifier|*
name|c_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* initialize namelist, etc. */
name|WINDOW
modifier|*
function_decl|(
modifier|*
name|c_open
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* open display */
name|void
function_decl|(
modifier|*
name|c_close
function_decl|)
parameter_list|(
name|WINDOW
modifier|*
parameter_list|)
function_decl|;
comment|/* close display */
name|int
function_decl|(
modifier|*
name|c_cmd
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
comment|/* display command interpreter */
name|void
function_decl|(
modifier|*
name|c_reset
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
comment|/* reset ``mode since'' display */
name|char
name|c_flags
decl_stmt|;
comment|/* see below */
block|}
struct|;
end_struct

begin_comment
comment|/*  * If we are started with privileges, use a kmem interface for netstat handling,  * otherwise use sysctl.  * In case of many open sockets, the sysctl handling might become slow.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|use_kvm
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CF_INIT
value|0x1
end_define

begin_comment
comment|/* been initialized */
end_comment

begin_define
define|#
directive|define
name|CF_LOADAV
value|0x2
end_define

begin_comment
comment|/* display w/ load average */
end_comment

begin_define
define|#
directive|define
name|TCP
value|0x1
end_define

begin_define
define|#
directive|define
name|UDP
value|0x2
end_define

begin_define
define|#
directive|define
name|MAINWIN_ROW
value|3
end_define

begin_comment
comment|/* top row for the main/lower window */
end_comment

begin_define
define|#
directive|define
name|GETSYSCTL
parameter_list|(
name|name
parameter_list|,
name|var
parameter_list|)
value|getsysctl(name,&(var), sizeof(var))
end_define

begin_define
define|#
directive|define
name|KREAD
parameter_list|(
name|addr
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
value|kvm_ckread((addr), (buf), (len))
end_define

begin_define
define|#
directive|define
name|NVAL
parameter_list|(
name|indx
parameter_list|)
value|namelist[(indx)].n_value
end_define

begin_define
define|#
directive|define
name|NPTR
parameter_list|(
name|indx
parameter_list|)
value|(void *)NVAL((indx))
end_define

begin_define
define|#
directive|define
name|NREAD
parameter_list|(
name|indx
parameter_list|,
name|buf
parameter_list|,
name|len
parameter_list|)
value|kvm_ckread(NPTR((indx)), (buf), (len))
end_define

end_unit

