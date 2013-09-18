begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $OpenBSD: clientloop.h,v 1.31 2013/06/02 23:36:29 dtucker Exp $ */
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_comment
comment|/* Client side main loop for the interactive session. */
end_comment

begin_function_decl
name|int
name|client_loop
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|client_x11_get_proto
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|client_global_request_reply_fwd
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|client_session2_setup
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|,
name|int
parameter_list|,
name|Buffer
modifier|*
parameter_list|,
name|char
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|client_request_tun_fwd
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|client_stop_mux
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Escape filter for protocol 2 sessions */
end_comment

begin_function_decl
name|void
modifier|*
name|client_new_escape_filter_ctx
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|client_filter_cleanup
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|client_simple_escape_filter
parameter_list|(
name|Channel
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Global request confirmation callbacks */
end_comment

begin_typedef
typedef|typedef
name|void
name|global_confirm_cb
parameter_list|(
name|int
parameter_list|,
name|u_int32_t
name|seq
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|void
name|client_register_global_confirm
parameter_list|(
name|global_confirm_cb
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Channel request confirmation callbacks */
end_comment

begin_enum
enum|enum
name|confirm_action
block|{
name|CONFIRM_WARN
init|=
literal|0
block|,
name|CONFIRM_CLOSE
block|,
name|CONFIRM_TTY
block|}
enum|;
end_enum

begin_function_decl
name|void
name|client_expect_confirm
parameter_list|(
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|enum
name|confirm_action
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Multiplexing protocol version */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_VER
value|4
end_define

begin_comment
comment|/* Multiplexing control protocol flags */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_COMMAND_OPEN
value|1
end_define

begin_comment
comment|/* Open new connection */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_COMMAND_ALIVE_CHECK
value|2
end_define

begin_comment
comment|/* Check master is alive */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_COMMAND_TERMINATE
value|3
end_define

begin_comment
comment|/* Ask master to exit */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_COMMAND_STDIO_FWD
value|4
end_define

begin_comment
comment|/* Open stdio fwd (ssh -W) */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_COMMAND_FORWARD
value|5
end_define

begin_comment
comment|/* Forward only, no command */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_COMMAND_STOP
value|6
end_define

begin_comment
comment|/* Disable mux but not conn */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_COMMAND_CANCEL_FWD
value|7
end_define

begin_comment
comment|/* Cancel forwarding(s) */
end_comment

begin_function_decl
name|void
name|muxserver_listen
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|muxclient
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mux_exit_message
parameter_list|(
name|Channel
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mux_tty_alloc_failed
parameter_list|(
name|Channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

