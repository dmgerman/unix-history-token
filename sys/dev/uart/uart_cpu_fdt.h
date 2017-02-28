begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2015 Michal Meloun  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_UART_CPU_FDT_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_UART_CPU_FDT_H_
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<dev/ofw/ofw_bus_subr.h>
end_include

begin_comment
comment|/*  * If your UART driver implements only uart_class and uses uart_cpu_fdt.c  * for device instantiation, then use UART_FDT_CLASS_AND_DEVICE for its  * declaration  */
end_comment

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|uart_fdt_class_and_device_set
argument_list|,
expr|struct
name|ofw_compat_data
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|UART_FDT_CLASS_AND_DEVICE
parameter_list|(
name|data
parameter_list|)
define|\
value|DATA_SET(uart_fdt_class_and_device_set, data)
end_define

begin_comment
comment|/*  * If your UART driver implements uart_class and custom device layer,  * then use UART_FDT_CLASS for its declaration  */
end_comment

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|uart_fdt_class_set
argument_list|,
expr|struct
name|ofw_compat_data
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|UART_FDT_CLASS
parameter_list|(
name|data
parameter_list|)
define|\
value|DATA_SET(uart_fdt_class_set, data)
end_define

begin_function_decl
name|int
name|uart_cpu_fdt_probe
parameter_list|(
name|struct
name|uart_class
modifier|*
modifier|*
parameter_list|,
name|bus_space_tag_t
modifier|*
parameter_list|,
name|bus_space_handle_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|,
name|u_int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_fdt_get_clock
parameter_list|(
name|phandle_t
name|node
parameter_list|,
name|pcell_t
modifier|*
name|cell
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_fdt_get_shift
parameter_list|(
name|phandle_t
name|node
parameter_list|,
name|pcell_t
modifier|*
name|cell
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|uart_fdt_get_io_width
parameter_list|(
name|phandle_t
name|node
parameter_list|,
name|pcell_t
modifier|*
name|cell
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_UART_CPU_FDT_H_ */
end_comment

end_unit

