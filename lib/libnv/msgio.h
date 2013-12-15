begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Pawel Jakub Dawidek under sponsorship from  * the FreeBSD Foundation.  *  * Copyright (c) 2013 Mariusz Zaborski<oshogbo@FreeBSD.org>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MSGIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_MSGIO_H_
end_define

begin_struct_decl
struct_decl|struct
name|cmsgcred
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|iovec
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|msghdr
struct_decl|;
end_struct_decl

begin_function_decl
name|int
name|cred_send
parameter_list|(
name|int
name|sock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cred_recv
parameter_list|(
name|int
name|sock
parameter_list|,
name|struct
name|cmsgcred
modifier|*
name|cred
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fd_send
parameter_list|(
name|int
name|sock
parameter_list|,
specifier|const
name|int
modifier|*
name|fds
parameter_list|,
name|size_t
name|nfds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fd_recv
parameter_list|(
name|int
name|sock
parameter_list|,
name|int
modifier|*
name|fds
parameter_list|,
name|size_t
name|nfds
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buf_send
parameter_list|(
name|int
name|sock
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|buf_recv
parameter_list|(
name|int
name|sock
parameter_list|,
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MSGIO_H_ */
end_comment

end_unit

