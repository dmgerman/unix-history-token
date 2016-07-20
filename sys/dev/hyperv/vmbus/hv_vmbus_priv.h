begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012,2016 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HYPERV_PRIV_H__
end_ifndef

begin_define
define|#
directive|define
name|__HYPERV_PRIV_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/sema.h>
end_include

begin_include
include|#
directive|include
file|<sys/_iovec.h>
end_include

begin_include
include|#
directive|include
file|<dev/hyperv/vmbus/vmbus_chanvar.h>
end_include

begin_struct_decl
struct_decl|struct
name|vmbus_softc
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Private, VM Bus functions  */
end_comment

begin_struct_decl
struct_decl|struct
name|sysctl_ctx_list
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|sysctl_oid_list
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|hv_ring_buffer_stat
parameter_list|(
name|struct
name|sysctl_ctx_list
modifier|*
name|ctx
parameter_list|,
name|struct
name|sysctl_oid_list
modifier|*
name|tree_node
parameter_list|,
name|hv_vmbus_ring_buffer_info
modifier|*
name|rbi
parameter_list|,
specifier|const
name|char
modifier|*
name|desc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_vmbus_ring_buffer_init
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_ring_buffer_cleanup
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_ring_buffer_write
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|,
specifier|const
name|struct
name|iovec
name|iov
index|[]
parameter_list|,
name|uint32_t
name|iovlen
parameter_list|,
name|boolean_t
modifier|*
name|need_sig
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_ring_buffer_peek
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|hv_ring_buffer_read
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|,
name|void
modifier|*
name|buffer
parameter_list|,
name|uint32_t
name|buffer_len
parameter_list|,
name|uint32_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|hv_ring_buffer_read_begin
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|hv_ring_buffer_read_end
parameter_list|(
name|hv_vmbus_ring_buffer_info
modifier|*
name|ring_info
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __HYPERV_PRIV_H__ */
end_comment

end_unit

