begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1998 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|physical
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|datalink
struct_decl|;
end_struct_decl

begin_comment
comment|/* fsm states */
end_comment

begin_define
define|#
directive|define
name|CBCP_CLOSED
value|(0)
end_define

begin_comment
comment|/* Not in use */
end_comment

begin_define
define|#
directive|define
name|CBCP_STOPPED
value|(1)
end_define

begin_comment
comment|/* Waiting for a REQ */
end_comment

begin_define
define|#
directive|define
name|CBCP_REQSENT
value|(2)
end_define

begin_comment
comment|/* Waiting for a RESP */
end_comment

begin_define
define|#
directive|define
name|CBCP_RESPSENT
value|(3)
end_define

begin_comment
comment|/* Waiting for an ACK */
end_comment

begin_define
define|#
directive|define
name|CBCP_ACKSENT
value|(4)
end_define

begin_comment
comment|/* Waiting for an LCP Term REQ */
end_comment

begin_struct
struct|struct
name|cbcpcfg
block|{
name|u_char
name|delay
decl_stmt|;
name|char
name|phone
index|[
name|SCRIPT_LEN
index|]
decl_stmt|;
name|long
name|fsmretry
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|cbcp
block|{
name|unsigned
name|required
range|:
literal|1
decl_stmt|;
comment|/* Are we gonna call back ? */
name|struct
name|physical
modifier|*
name|p
decl_stmt|;
comment|/* On this physical link */
struct|struct
block|{
name|u_char
name|type
decl_stmt|;
comment|/* cbcp_data::type (none/me/him/list) */
name|u_char
name|delay
decl_stmt|;
comment|/* How long to delay */
name|char
name|phone
index|[
name|SCRIPT_LEN
index|]
decl_stmt|;
comment|/* What to dial */
name|int
name|state
decl_stmt|;
comment|/* Our FSM state */
name|u_char
name|id
decl_stmt|;
comment|/* Our FSM ID */
name|u_char
name|restart
decl_stmt|;
comment|/* FSM Send again ? */
name|struct
name|pppTimer
name|timer
decl_stmt|;
comment|/* Resend last option */
block|}
name|fsm
struct|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|cbcp_Init
parameter_list|(
name|struct
name|cbcp
modifier|*
parameter_list|,
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cbcp_Up
parameter_list|(
name|struct
name|cbcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|mbuf
modifier|*
name|cbcp_Input
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|struct
name|link
modifier|*
parameter_list|,
name|struct
name|mbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cbcp_Down
parameter_list|(
name|struct
name|cbcp
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cbcp_ReceiveTerminateReq
parameter_list|(
name|struct
name|physical
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

