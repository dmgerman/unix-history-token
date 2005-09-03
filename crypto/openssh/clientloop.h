begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$OpenBSD: clientloop.h,v 1.14 2005/07/04 00:58:43 djm Exp $	*/
end_comment

begin_comment
comment|/*  * Author: Tatu Ylonen<ylo@cs.hut.fi>  * Copyright (c) 1995 Tatu Ylonen<ylo@cs.hut.fi>, Espoo, Finland  *                    All rights reserved  *  * As far as I am concerned, the code I have written for this software  * can be used freely for any purpose.  Any derived versions of this  * software must be clearly marked as such, and if the derived work is  * incompatible with the protocol description in the RFC file, it must be  * called by a name other than "ssh" or "Secure Shell".  */
end_comment

begin_comment
comment|/*  * Copyright (c) 2001 Markus Friedl.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

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
parameter_list|,
name|dispatch_fn
modifier|*
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
value|1
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
name|SSHMUX_FLAG_TTY
value|(1)
end_define

begin_comment
comment|/* Request tty on open */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_FLAG_SUBSYS
value|(1<<1)
end_define

begin_comment
comment|/* Subsystem request on open */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_FLAG_X11_FWD
value|(1<<2)
end_define

begin_comment
comment|/* Request X11 forwarding */
end_comment

begin_define
define|#
directive|define
name|SSHMUX_FLAG_AGENT_FWD
value|(1<<3)
end_define

begin_comment
comment|/* Request agent forwarding */
end_comment

end_unit

