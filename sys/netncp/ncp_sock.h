begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1999, Boris Popov  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Boris Popov.  * 4. Neither the name of the author nor the names of any co-contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETNCP_NCP_SOCK_H_
end_ifndef

begin_define
define|#
directive|define
name|_NETNCP_NCP_SOCK_H_
end_define

begin_struct_decl
struct_decl|struct
name|ncp_conn
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|mbuf
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|ncp_rq
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|proc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|socket
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|timeval
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|ncp_sock_connect_ipx
parameter_list|(
name|struct
name|ncp_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_sock_connect_in
parameter_list|(
name|struct
name|ncp_conn
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_sock_recv
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|mbuf
modifier|*
modifier|*
name|mp
parameter_list|,
name|int
modifier|*
name|rlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_sock_send
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|mbuf
modifier|*
name|data
parameter_list|,
name|struct
name|ncp_rq
modifier|*
name|rqp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_sock_disconnect
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_poll
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|int
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_sock_rselect
parameter_list|(
name|struct
name|socket
modifier|*
name|so
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|,
name|struct
name|timeval
modifier|*
name|tv
parameter_list|,
name|int
name|events
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ncp_sock_checksum
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|,
name|int
name|enable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncp_check_rq
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncp_check_conn
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ncp_check_wd
parameter_list|(
name|struct
name|ncp_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _NCP_SOCK_H_ */
end_comment

end_unit

