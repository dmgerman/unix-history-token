begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011-2012 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FMAN_H_
end_ifndef

begin_define
define|#
directive|define
name|FMAN_H_
end_define

begin_include
include|#
directive|include
file|<dev/fdt/simplebus.h>
end_include

begin_comment
comment|/**  * FMan driver instance data.  */
end_comment

begin_struct
struct|struct
name|fman_softc
block|{
name|struct
name|simplebus_softc
name|sc_base
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|err_irq_res
decl_stmt|;
name|int
name|mem_rid
decl_stmt|;
name|int
name|irq_rid
decl_stmt|;
name|int
name|err_irq_rid
decl_stmt|;
name|int
name|qman_chan_base
decl_stmt|;
name|int
name|qman_chan_count
decl_stmt|;
name|t_Handle
name|fm_handle
decl_stmt|;
name|t_Handle
name|muram_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/**  * @group QMan bus interface.  * @{  */
end_comment

begin_function_decl
name|int
name|fman_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_resume_dev
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_shutdown
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_read_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|index
parameter_list|,
name|uintptr_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_qman_channel_id
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_function_decl
name|uint32_t
name|fman_get_clock
parameter_list|(
name|struct
name|fman_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_get_handle
parameter_list|(
name|t_Handle
modifier|*
name|fmh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_get_muram_handle
parameter_list|(
name|t_Handle
modifier|*
name|muramh
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_get_bushandle
parameter_list|(
name|vm_offset_t
modifier|*
name|fm_base
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fman_get_dev
parameter_list|(
name|device_t
modifier|*
name|fmd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FMAN_H_ */
end_comment

end_unit

