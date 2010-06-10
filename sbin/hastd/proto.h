begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2010 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROTO_H_
end_ifndef

begin_define
define|#
directive|define
name|_PROTO_H_
end_define

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_comment
comment|/* bool */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_comment
comment|/* size_t */
end_comment

begin_struct_decl
struct_decl|struct
name|proto_conn
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|proto_client
parameter_list|(
specifier|const
name|char
modifier|*
name|addr
parameter_list|,
name|struct
name|proto_conn
modifier|*
modifier|*
name|connp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_connect
parameter_list|(
name|struct
name|proto_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_server
parameter_list|(
specifier|const
name|char
modifier|*
name|addr
parameter_list|,
name|struct
name|proto_conn
modifier|*
modifier|*
name|connp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_accept
parameter_list|(
name|struct
name|proto_conn
modifier|*
name|conn
parameter_list|,
name|struct
name|proto_conn
modifier|*
modifier|*
name|newconnp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_send
parameter_list|(
name|struct
name|proto_conn
modifier|*
name|conn
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_recv
parameter_list|(
name|struct
name|proto_conn
modifier|*
name|conn
parameter_list|,
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_descriptor
parameter_list|(
specifier|const
name|struct
name|proto_conn
modifier|*
name|conn
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|proto_address_match
parameter_list|(
specifier|const
name|struct
name|proto_conn
modifier|*
name|conn
parameter_list|,
specifier|const
name|char
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proto_local_address
parameter_list|(
specifier|const
name|struct
name|proto_conn
modifier|*
name|conn
parameter_list|,
name|char
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proto_remote_address
parameter_list|(
specifier|const
name|struct
name|proto_conn
modifier|*
name|conn
parameter_list|,
name|char
modifier|*
name|addr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|proto_timeout
parameter_list|(
specifier|const
name|struct
name|proto_conn
modifier|*
name|conn
parameter_list|,
name|int
name|timeout
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|proto_close
parameter_list|(
name|struct
name|proto_conn
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
comment|/* !_PROTO_H_ */
end_comment

end_unit

