begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2008 Edwin Groothuis. All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *   * THIS SOFTWARE IS PROVIDED BY AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|RP_NONE
value|0
end_define

begin_define
define|#
directive|define
name|RP_RECVFROM
value|-1
end_define

begin_define
define|#
directive|define
name|RP_TOOSMALL
value|-2
end_define

begin_define
define|#
directive|define
name|RP_ERROR
value|-3
end_define

begin_define
define|#
directive|define
name|RP_WRONGSOURCE
value|-4
end_define

begin_define
define|#
directive|define
name|RP_TIMEOUT
value|-5
end_define

begin_define
define|#
directive|define
name|RP_TOOBIG
value|-6
end_define

begin_function_decl
specifier|const
name|char
modifier|*
name|errtomsg
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|send_error
parameter_list|(
name|int
name|peer
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_wrq
parameter_list|(
name|int
name|peer
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_rrq
parameter_list|(
name|int
name|peer
parameter_list|,
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_oack
parameter_list|(
name|int
name|peer
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_ack
parameter_list|(
name|int
name|peer
parameter_list|,
name|unsigned
name|short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|send_data
parameter_list|(
name|int
name|peer
parameter_list|,
name|uint16_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|receive_packet
parameter_list|(
name|int
name|peer
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_storage
name|peer_sock
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|sockaddr_storage
name|me_sock
decl_stmt|;
end_decl_stmt

end_unit

