begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Jakub Wojciech Klama<jceel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ARM_RT_RTVAR_H
end_ifndef

begin_define
define|#
directive|define
name|_ARM_RT_RTVAR_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/* Clocking and power control */
end_comment

begin_function_decl
name|uint32_t
name|lpc_pwr_read
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|lpc_pwr_write
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* GPIO */
end_comment

begin_function_decl
name|void
name|rt1310_gpio_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rt1310_gpio_set_flags
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rt1310_gpio_set_state
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|rt1310_gpio_get_state
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* DMA */
end_comment

begin_struct
struct|struct
name|lpc_dmac_channel_config
block|{
name|int
name|ldc_fcntl
decl_stmt|;
name|int
name|ldc_src_periph
decl_stmt|;
name|int
name|ldc_src_width
decl_stmt|;
name|int
name|ldc_src_incr
decl_stmt|;
name|int
name|ldc_src_burst
decl_stmt|;
name|int
name|ldc_dst_periph
decl_stmt|;
name|int
name|ldc_dst_width
decl_stmt|;
name|int
name|ldc_dst_incr
decl_stmt|;
name|int
name|ldc_dst_burst
decl_stmt|;
name|void
function_decl|(
modifier|*
name|ldc_success_handler
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|ldc_error_handler
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|ldc_handler_arg
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|lpc_dmac_config_channel
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|struct
name|lpc_dmac_channel_config
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lpc_dmac_setup_transfer
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_addr_t
parameter_list|,
name|bus_size_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lpc_dmac_enable_channel
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lpc_dmac_disable_channel
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|lpc_dmac_start_burst
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|uint32_t
name|rt1310_master_clock
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ARM_RT_RTVAR_H */
end_comment

end_unit

