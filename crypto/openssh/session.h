begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: session.h,v 1.19 2002/06/30 21:59:45 deraadt Exp $	*/
end_comment

begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_comment
comment|/*  * Copyright (c) 2000, 2001 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SESSION_H
end_ifndef

begin_define
define|#
directive|define
name|SESSION_H
end_define

begin_define
define|#
directive|define
name|TTYSZ
value|64
end_define

begin_typedef
typedef|typedef
name|struct
name|Session
name|Session
typedef|;
end_typedef

begin_struct
struct|struct
name|Session
block|{
name|int
name|used
decl_stmt|;
name|int
name|self
decl_stmt|;
name|struct
name|passwd
modifier|*
name|pw
decl_stmt|;
name|Authctxt
modifier|*
name|authctxt
decl_stmt|;
name|pid_t
name|pid
decl_stmt|;
comment|/* tty */
name|char
modifier|*
name|term
decl_stmt|;
name|int
name|ptyfd
decl_stmt|,
name|ttyfd
decl_stmt|,
name|ptymaster
decl_stmt|;
name|u_int
name|row
decl_stmt|,
name|col
decl_stmt|,
name|xpixel
decl_stmt|,
name|ypixel
decl_stmt|;
name|char
name|tty
index|[
name|TTYSZ
index|]
decl_stmt|;
comment|/* last login */
name|char
name|hostname
index|[
name|MAXHOSTNAMELEN
index|]
decl_stmt|;
name|time_t
name|last_login_time
decl_stmt|;
comment|/* X11 */
name|u_int
name|display_number
decl_stmt|;
name|char
modifier|*
name|display
decl_stmt|;
name|u_int
name|screen
decl_stmt|;
name|char
modifier|*
name|auth_display
decl_stmt|;
name|char
modifier|*
name|auth_proto
decl_stmt|;
name|char
modifier|*
name|auth_data
decl_stmt|;
name|int
name|single_connection
decl_stmt|;
comment|/* proto 2 */
name|int
name|chanid
decl_stmt|;
name|int
name|is_subsystem
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|do_authenticated
parameter_list|(
name|Authctxt
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|session_open
parameter_list|(
name|Authctxt
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|session_input_channel_req
parameter_list|(
name|Channel
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|session_close_by_pid
parameter_list|(
name|pid_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|session_close_by_channel
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|session_destroy_all
parameter_list|(
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|Session
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|session_pty_cleanup2
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Session
modifier|*
name|session_new
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|Session
modifier|*
name|session_by_tty
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|session_close
parameter_list|(
name|Session
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|do_setusercontext
parameter_list|(
name|struct
name|passwd
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

