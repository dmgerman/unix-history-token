begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2002 Benno Rice.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY Benno Rice ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL TOOLS GMBH BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,  * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;  * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR  * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF  * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_INTR_MACHDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_INTR_MACHDEP_H_
end_define

begin_define
define|#
directive|define
name|INTR_VECTORS
value|256
end_define

begin_define
define|#
directive|define
name|MAX_PICS
value|5
end_define

begin_define
define|#
directive|define
name|MAP_IRQ
parameter_list|(
name|node
parameter_list|,
name|pin
parameter_list|)
value|powerpc_get_irq(node, pin)
end_define

begin_comment
comment|/*  * Default base address for MSI messages on PowerPC  */
end_comment

begin_define
define|#
directive|define
name|MSI_INTEL_ADDR_BASE
value|0xfee00000
end_define

begin_decl_stmt
specifier|extern
name|device_t
name|root_pic
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|trapframe
struct_decl|;
end_struct_decl

begin_decl_stmt
name|driver_filter_t
name|powerpc_ipi_handler
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|intrcnt_add
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|u_long
modifier|*
modifier|*
name|countp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|powerpc_register_pic
parameter_list|(
name|device_t
parameter_list|,
name|uint32_t
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_int
name|powerpc_get_irq
parameter_list|(
name|uint32_t
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|powerpc_dispatch_intr
parameter_list|(
name|u_int
parameter_list|,
name|struct
name|trapframe
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|powerpc_enable_intr
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|powerpc_setup_intr
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|driver_filter_t
parameter_list|,
name|driver_intr_t
parameter_list|,
name|void
modifier|*
parameter_list|,
name|enum
name|intr_type
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|powerpc_teardown_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|powerpc_bind_intr
parameter_list|(
name|u_int
name|irq
parameter_list|,
name|u_char
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|powerpc_config_intr
parameter_list|(
name|int
parameter_list|,
name|enum
name|intr_trigger
parameter_list|,
name|enum
name|intr_polarity
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|powerpc_fw_config_intr
parameter_list|(
name|int
name|irq
parameter_list|,
name|int
name|sense_code
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_INTR_MACHDEP_H_ */
end_comment

end_unit

