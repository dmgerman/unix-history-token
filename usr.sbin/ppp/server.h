begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1997 Brian Somers<brian@Awfulhak.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_struct_decl
struct_decl|struct
name|bundle
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|server
block|{
name|struct
name|descriptor
name|desc
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|char
name|passwd
index|[
literal|50
index|]
decl_stmt|;
name|struct
name|sockaddr_un
name|ifsun
decl_stmt|;
comment|/* local socket */
name|char
modifier|*
name|rm
decl_stmt|;
comment|/* Points to local socket path */
name|u_short
name|port
decl_stmt|;
comment|/* tcp socket */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|descriptor2server
parameter_list|(
name|d
parameter_list|)
define|\
value|((d)->type == SERVER_DESCRIPTOR ? (struct server *)(d) : NULL)
end_define

begin_decl_stmt
specifier|extern
name|struct
name|server
name|server
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|server_LocalOpen
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|mode_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|server_TcpOpen
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|server_Close
parameter_list|(
name|struct
name|bundle
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

