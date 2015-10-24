begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2012 Intel Corporation  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|__IOAT_H__
end_ifndef

begin_define
define|#
directive|define
name|__IOAT_H__
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/*  * This file defines the public interface to the IOAT driver.  */
end_comment

begin_comment
comment|/*  * Enables an interrupt for this operation. Typically, you would only enable  * this on the last operation in a group  */
end_comment

begin_define
define|#
directive|define
name|DMA_INT_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|DMA_ALL_FLAGS
value|(DMA_INT_EN)
end_define

begin_typedef
typedef|typedef
name|void
modifier|*
name|bus_dmaengine_t
typedef|;
end_typedef

begin_struct_decl
struct_decl|struct
name|bus_dmadesc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|bus_dmaengine_callback_t
function_decl|)
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * Called first to acquire a reference to the DMA channel  */
end_comment

begin_function_decl
name|bus_dmaengine_t
name|ioat_get_dmaengine
parameter_list|(
name|uint32_t
name|channel_index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Release the DMA channel */
end_comment

begin_function_decl
name|void
name|ioat_put_dmaengine
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Acquire must be called before issuing an operation to perform. Release is  * called after. Multiple operations can be issued within the context of one  * acquire and release  */
end_comment

begin_function_decl
name|void
name|ioat_acquire
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ioat_release
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Issues the copy data operation */
end_comment

begin_function_decl
name|struct
name|bus_dmadesc
modifier|*
name|ioat_copy
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|bus_addr_t
name|dst
parameter_list|,
name|bus_addr_t
name|src
parameter_list|,
name|bus_size_t
name|len
parameter_list|,
name|bus_dmaengine_callback_t
name|callback_fn
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Issues a null operation. This issues the operation to the hardware, but the  * hardware doesn't do anything with it.  */
end_comment

begin_function_decl
name|struct
name|bus_dmadesc
modifier|*
name|ioat_null
parameter_list|(
name|bus_dmaengine_t
name|dmaengine
parameter_list|,
name|bus_dmaengine_callback_t
name|callback_fn
parameter_list|,
name|void
modifier|*
name|callback_arg
parameter_list|,
name|uint32_t
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __IOAT_H__ */
end_comment

end_unit

