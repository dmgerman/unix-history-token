begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1995 Bruce D. Evans.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of the author nor the names of contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MD_VAR_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MD_VAR_H_
end_define

begin_include
include|#
directive|include
file|<x86/x86_var.h>
end_include

begin_decl_stmt
specifier|extern
name|u_int
name|cyrix_did
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|I586_CPU
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|NO_F00F_HACK
argument_list|)
end_if

begin_decl_stmt
specifier|extern
name|int
name|has_f00f_bug
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_FREEBSD4
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|szfreebsd4_sigcode
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|COMPAT_43
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|szosigcode
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|uint32_t
modifier|*
name|vm_page_dump
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|segment_descriptor
struct_decl|;
end_struct_decl

begin_union_decl
union_decl|union
name|savefpu
union_decl|;
end_union_decl

begin_function_decl
name|void
name|bcopyb
parameter_list|(
specifier|const
name|void
modifier|*
name|from
parameter_list|,
name|void
modifier|*
name|to
parameter_list|,
name|size_t
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|void
name|cpu_switch_load_gs
argument_list|(
name|void
argument_list|)
asm|__asm(__STRING(cpu_switch_load_gs));
name|void
name|doreti_iret
argument_list|(
name|void
argument_list|)
asm|__asm(__STRING(doreti_iret));
name|void
name|doreti_iret_fault
argument_list|(
name|void
argument_list|)
asm|__asm(__STRING(doreti_iret_fault));
name|void
name|doreti_popl_ds
argument_list|(
name|void
argument_list|)
asm|__asm(__STRING(doreti_popl_ds));
name|void
name|doreti_popl_ds_fault
argument_list|(
name|void
argument_list|)
asm|__asm(__STRING(doreti_popl_ds_fault));
name|void
name|doreti_popl_es
argument_list|(
name|void
argument_list|)
asm|__asm(__STRING(doreti_popl_es));
name|void
name|doreti_popl_es_fault
argument_list|(
name|void
argument_list|)
asm|__asm(__STRING(doreti_popl_es_fault));
name|void
name|doreti_popl_fs
argument_list|(
name|void
argument_list|)
asm|__asm(__STRING(doreti_popl_fs));
name|void
name|doreti_popl_fs_fault
argument_list|(
name|void
argument_list|)
asm|__asm(__STRING(doreti_popl_fs_fault));
name|void
name|fill_based_sd
argument_list|(
expr|struct
name|segment_descriptor
operator|*
name|sdp
argument_list|,
name|uint32_t
name|base
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|i686_pagezero
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sse2_pagezero
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_AMD_Elan_sc520
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_paddr_t
name|kvtop
parameter_list|(
name|void
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|panicifcpuunsupported
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ppro_reenable_apic
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|setidt
parameter_list|(
name|int
name|idx
parameter_list|,
name|alias_for_inthand_t
modifier|*
name|func
parameter_list|,
name|int
name|typ
parameter_list|,
name|int
name|dpl
parameter_list|,
name|int
name|selec
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|union
name|savefpu
modifier|*
name|get_pcb_user_save_td
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|union
name|savefpu
modifier|*
name|get_pcb_user_save_pcb
parameter_list|(
name|struct
name|pcb
modifier|*
name|pcb
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_MD_VAR_H_ */
end_comment

end_unit

