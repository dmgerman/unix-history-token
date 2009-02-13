begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: progressbar.h,v 1.5 2005/02/10 16:00:38 jmc Exp $	*/
end_comment

begin_comment
comment|/*-  * Copyright (c) 1996-2003 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Luke Mewburn.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the NetBSD  *	Foundation, Inc. and its contributors.  * 4. Neither the name of The NetBSD Foundation nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STANDALONE_PROGRESS
end_ifndef

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !STANDALONE_PROGRESS */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|GLOBAL
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|STALLTIME
value|5
end_define

begin_comment
comment|/* # of seconds of no xfer before "stalling" */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|sigfunc
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_decl_stmt
name|GLOBAL
name|FILE
modifier|*
name|ttyout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stdout, or stderr if retrieving to stdout */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|progress
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display transfer progress bar */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|ttywidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* width of tty */
end_comment

begin_decl_stmt
name|GLOBAL
name|off_t
name|bytes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current # of bytes read */
end_comment

begin_decl_stmt
name|GLOBAL
name|off_t
name|filesize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size of file being transferred */
end_comment

begin_decl_stmt
name|GLOBAL
name|off_t
name|restart_point
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset to restart transfer */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|prefix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Text written left of progress bar */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STANDALONE_PROGRESS
end_ifndef

begin_decl_stmt
name|GLOBAL
name|int
name|fromatty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input is from a terminal */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print messages coming back from server */
end_comment

begin_decl_stmt
name|GLOBAL
name|int
name|quit_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* maximum time to wait if stalled */
end_comment

begin_decl_stmt
name|GLOBAL
name|char
modifier|*
name|direction
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* direction transfer is occurring */
end_comment

begin_decl_stmt
name|GLOBAL
name|sigjmp_buf
name|toplevel
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* non-local goto stuff for cmd scanner */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !STANDALONE_PROGRESS */
end_comment

begin_function_decl
name|int
name|foregroundproc
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|alarmtimer
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|progressmeter
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sigfunc
name|xsignal
parameter_list|(
name|int
parameter_list|,
name|sigfunc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|sigfunc
name|xsignal_restart
parameter_list|(
name|int
parameter_list|,
name|sigfunc
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifndef
ifndef|#
directive|ifndef
name|STANDALONE_PROGRESS
end_ifndef

begin_function_decl
name|void
name|psummary
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ptransfer
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !STANDALONE_PROGRESS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NO_LONG_LONG
end_ifdef

begin_define
define|#
directive|define
name|LLF
value|"%ld"
end_define

begin_define
define|#
directive|define
name|LLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "ld"
end_define

begin_define
define|#
directive|define
name|LLT
value|long
end_define

begin_define
define|#
directive|define
name|ULLF
value|"%lu"
end_define

begin_define
define|#
directive|define
name|ULLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "lu"
end_define

begin_define
define|#
directive|define
name|ULLT
value|unsigned long
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LLF
value|"%lld"
end_define

begin_define
define|#
directive|define
name|LLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "lld"
end_define

begin_define
define|#
directive|define
name|LLT
value|long long
end_define

begin_define
define|#
directive|define
name|ULLF
value|"%llu"
end_define

begin_define
define|#
directive|define
name|ULLFP
parameter_list|(
name|x
parameter_list|)
value|"%" x "llu"
end_define

begin_define
define|#
directive|define
name|ULLT
value|unsigned long long
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

