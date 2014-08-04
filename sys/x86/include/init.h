begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2013 Roger Pau MonnÃ©<roger.pau@citrix.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__X86_INIT_H__
end_ifndef

begin_define
define|#
directive|define
name|__X86_INIT_H__
end_define

begin_comment
comment|/*  * Struct containing pointers to init functions whose  * implementation is run time selectable.  Selection can be made,  * for example, based on detection of a BIOS variant or  * hypervisor environment.  */
end_comment

begin_struct
struct|struct
name|init_ops
block|{
name|caddr_t
function_decl|(
modifier|*
name|parse_preload_data
function_decl|)
parameter_list|(
name|u_int64_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|early_clock_source_init
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|early_delay
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|parse_memmap
function_decl|)
parameter_list|(
name|caddr_t
parameter_list|,
name|vm_paddr_t
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
name|u_int
function_decl|(
modifier|*
name|mp_bootaddress
function_decl|)
parameter_list|(
name|u_int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|start_all_aps
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|init_ops
name|init_ops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Knob to disable acpi_cpu devices */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|acpi_cpu_disabled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Knob to disable acpi_hpet device */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|acpi_hpet_disabled
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Knob to disable acpi_timer device */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|acpi_timer_disabled
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __X86_INIT_H__ */
end_comment

end_unit

