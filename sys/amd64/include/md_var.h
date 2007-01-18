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

begin_comment
comment|/*  * Miscellaneous machine-dependent declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|Maxmem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|basemem
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|busdma_swi_pending
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cpu_exthigh
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cpu_feature
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cpu_feature2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|amd_feature
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|amd_feature2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cpu_fxsr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cpu_high
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cpu_id
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cpu_mxcsr_mask
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cpu_procinfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|cpu_procinfo2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|cpu_vendor
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|kstack
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|sigcode
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|szsigcode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|uint64_t
modifier|*
name|vm_page_dump
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|vm_page_dump_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|pcpu
modifier|*
name|__pcpu
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|alias_for_inthand_t
parameter_list|(
name|u_int
name|cs
parameter_list|,
name|u_int
name|ef
parameter_list|,
name|u_int
name|esp
parameter_list|,
name|u_int
name|ss
parameter_list|)
function_decl|;
end_typedef

begin_struct_decl
struct_decl|struct
name|thread
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|reg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|fpreg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dbreg
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|dumperinfo
struct_decl|;
end_struct_decl

begin_function_decl
name|void
name|busdma_swi
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|cpu_setregs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
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
name|dump_add_page
argument_list|(
name|vm_paddr_t
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|dump_drop_page
parameter_list|(
name|vm_paddr_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|initializecpu
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fillw
parameter_list|(
name|int
comment|/*u_short*/
name|pat
parameter_list|,
name|void
modifier|*
name|base
parameter_list|,
name|size_t
name|cnt
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fpstate_drop
parameter_list|(
name|struct
name|thread
modifier|*
name|td
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|is_physical_memory
parameter_list|(
name|vm_paddr_t
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|isa_nmi
parameter_list|(
name|int
name|cd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pagecopy
parameter_list|(
name|void
modifier|*
name|from
parameter_list|,
name|void
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pagezero
parameter_list|(
name|void
modifier|*
name|addr
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
name|ist
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|user_dbreg_trap
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|minidumpsys
parameter_list|(
name|struct
name|dumperinfo
modifier|*
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

