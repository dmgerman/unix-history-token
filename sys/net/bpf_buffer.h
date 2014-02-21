begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007 Seccuris Inc.  * All rights reserved.  *  * This software was developed by Robert N. M. Watson under contract to  * Seccuris Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NET_BPF_BUFFER_H_
end_ifndef

begin_define
define|#
directive|define
name|_NET_BPF_BUFFER_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-serviceable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|bpf_buffer_append_bytes
parameter_list|(
name|struct
name|bpf_d
modifier|*
name|d
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|u_int
name|offset
parameter_list|,
name|void
modifier|*
name|src
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpf_buffer_append_mbuf
parameter_list|(
name|struct
name|bpf_d
modifier|*
name|d
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|u_int
name|offset
parameter_list|,
name|void
modifier|*
name|src
parameter_list|,
name|u_int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpf_buffer_free
parameter_list|(
name|struct
name|bpf_d
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bpf_buffer_init
parameter_list|(
name|struct
name|bpf_d
modifier|*
name|d
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bpf_buffer_ioctl_sblen
parameter_list|(
name|struct
name|bpf_d
modifier|*
name|d
parameter_list|,
name|u_int
modifier|*
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bpf_buffer_uiomove
parameter_list|(
name|struct
name|bpf_d
modifier|*
name|d
parameter_list|,
name|caddr_t
name|buf
parameter_list|,
name|u_int
name|len
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_NET_BPF_BUFFER_H_ */
end_comment

end_unit

