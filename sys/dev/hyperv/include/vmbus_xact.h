begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMBUS_XACT_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMBUS_XACT_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_struct_decl
struct_decl|struct
name|vmbus_xact
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|vmbus_xact_ctx
struct_decl|;
end_struct_decl

begin_function_decl
name|struct
name|vmbus_xact_ctx
modifier|*
name|vmbus_xact_ctx_create
parameter_list|(
name|bus_dma_tag_t
name|dtag
parameter_list|,
name|size_t
name|req_size
parameter_list|,
name|size_t
name|resp_size
parameter_list|,
name|size_t
name|priv_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_xact_ctx_destroy
parameter_list|(
name|struct
name|vmbus_xact_ctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vmbus_xact
modifier|*
name|vmbus_xact_get
parameter_list|(
name|struct
name|vmbus_xact_ctx
modifier|*
name|ctx
parameter_list|,
name|size_t
name|req_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_xact_put
parameter_list|(
name|struct
name|vmbus_xact
modifier|*
name|xact
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|vmbus_xact_req_data
parameter_list|(
specifier|const
name|struct
name|vmbus_xact
modifier|*
name|xact
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bus_addr_t
name|vmbus_xact_req_paddr
parameter_list|(
specifier|const
name|struct
name|vmbus_xact
modifier|*
name|xact
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|vmbus_xact_priv
parameter_list|(
specifier|const
name|struct
name|vmbus_xact
modifier|*
name|xact
parameter_list|,
name|size_t
name|priv_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_xact_activate
parameter_list|(
name|struct
name|vmbus_xact
modifier|*
name|xact
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_xact_deactivate
parameter_list|(
name|struct
name|vmbus_xact
modifier|*
name|xact
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|void
modifier|*
name|vmbus_xact_wait
parameter_list|(
name|struct
name|vmbus_xact
modifier|*
name|xact
parameter_list|,
name|size_t
modifier|*
name|resp_len
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_xact_wakeup
parameter_list|(
name|struct
name|vmbus_xact
modifier|*
name|xact
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|dlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmbus_xact_ctx_wakeup
parameter_list|(
name|struct
name|vmbus_xact_ctx
modifier|*
name|ctx
parameter_list|,
specifier|const
name|void
modifier|*
name|data
parameter_list|,
name|size_t
name|dlen
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VMBUS_XACT_H_ */
end_comment

end_unit

