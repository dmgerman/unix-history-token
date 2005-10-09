begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2001-2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Author: Harti Brandt<harti@freebsd.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $Begemot: libunimsg/sscop/common.h,v 1.5 2005/05/23 11:46:16 brandt_h Exp $  *  * Common declaration for the SAAL programs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SAAL_COMMON_H_
end_ifndef

begin_define
define|#
directive|define
name|_SAAL_COMMON_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LIBBEGEMOT
end_ifdef

begin_include
include|#
directive|include
file|<rpoll.h>
end_include

begin_define
define|#
directive|define
name|evFileID
value|int
end_define

begin_define
define|#
directive|define
name|evTimerID
value|int
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<isc/eventlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Writes to a pipe must be in messages (if we don't use framing).  * It is not clear, what is the maximum message size for this. It seems  * to be PIPE_BUF, but be conservative.  */
end_comment

begin_define
define|#
directive|define
name|MAXUSRMSG
value|4096
end_define

begin_define
define|#
directive|define
name|MAXMSG
value|(MAXUSRMSG+4)
end_define

begin_decl_stmt
specifier|extern
name|int
name|useframe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use frame functions */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sscopframe
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* use sscop framing */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|sscop_vflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* be talkative */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sscop_fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for SSCOP protocol */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|user_fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for USER */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|loose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* loose messages */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|user_out_fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descriptor for output to user */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|verbose
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* talk to me */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_LIBBEGEMOT
end_ifndef

begin_decl_stmt
specifier|extern
name|evContext
name|evctx
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|evFileID
name|sscop_h
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|evFileID
name|user_h
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|dump_buf
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|uni_msg
modifier|*
name|proto_msgin
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|uni_msg
modifier|*
name|user_msgin
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proto_msgout
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|user_msgout
parameter_list|(
name|struct
name|uni_msg
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|parse_param
parameter_list|(
name|struct
name|sscop_param
modifier|*
parameter_list|,
name|u_int
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
name|void
name|verb
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|sscop_verbose
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
modifier|...
parameter_list|)
function_decl|__printflike
parameter_list|(
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
modifier|*
name|sscop_start_timer
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sscop_stop_timer
parameter_list|(
name|struct
name|sscop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|VERBOSE
parameter_list|(
name|P
parameter_list|)
value|do { if (verbose& 0x0001) verb P; } while(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SAAL_COMMON_H_ */
end_comment

end_unit

