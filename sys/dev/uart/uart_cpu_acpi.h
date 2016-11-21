begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015 Michal Meloun  * Copyright (c) 2016 The FreeBSD Foundation  * All rights reserved.  *  * This software was developed by Andrew Turner under  * sponsorship from the FreeBSD Foundation.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_UART_CPU_ACPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_UART_CPU_ACPI_H_
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_struct_decl
struct_decl|struct
name|uart_class
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|acpi_uart_compat_data
block|{
specifier|const
name|char
modifier|*
name|hid
decl_stmt|;
name|struct
name|uart_class
modifier|*
name|clas
decl_stmt|;
name|uint16_t
name|port_subtype
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * If your UART driver implements only uart_class and uses uart_cpu_acpi.c  * for device instantiation, then use UART_ACPI_CLASS_AND_DEVICE for its  * declaration  */
end_comment

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|uart_acpi_class_and_device_set
argument_list|,
expr|struct
name|acpi_uart_compat_data
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|UART_ACPI_CLASS_AND_DEVICE
parameter_list|(
name|data
parameter_list|)
define|\
value|DATA_SET(uart_acpi_class_and_device_set, data)
end_define

begin_comment
comment|/*  * If your UART driver implements uart_class and custom device layer,  * then use UART_ACPI_CLASS for its declaration  */
end_comment

begin_expr_stmt
name|SET_DECLARE
argument_list|(
name|uart_acpi_class_set
argument_list|,
expr|struct
name|acpi_uart_compat_data
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|UART_ACPI_CLASS
parameter_list|(
name|data
parameter_list|)
define|\
value|DATA_SET(uart_acpi_class_set, data)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_UART_CPU_ACPI_H_ */
end_comment

end_unit

