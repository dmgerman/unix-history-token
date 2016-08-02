begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Ruslan Bukin<br@bsdpad.com>  * All rights reserved.  *  * Portions of this software were developed by SRI International and the  * University of Cambridge Computer Laboratory under DARPA/AFRL contract  * FA8750-10-C-0237 ("CTSRD"), as part of the DARPA CRASH research programme.  *  * Portions of this software were developed by the University of Cambridge  * Computer Laboratory as part of the CTSRD Project, with support from the  * UK Higher Education Innovation Fund (HEIF).  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_CPUFUNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_CPUFUNC_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<machine/riscvreg.h>
end_include

begin_function
specifier|static
name|__inline
name|void
name|breakpoint
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm("ebreak");
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|intr_disable
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"csrrci %0, sstatus, %1"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
operator|:
literal|"i"
operator|(
name|SSTATUS_SIE
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|&
operator|(
name|SSTATUS_SIE
operator|)
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|intr_restore
parameter_list|(
name|register_t
name|s
parameter_list|)
block|{
asm|__asm __volatile(
literal|"csrs sstatus, %0"
operator|::
literal|"r"
operator|(
name|s
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|void
name|intr_enable
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile(
literal|"csrsi sstatus, %0"
operator|::
literal|"i"
operator|(
name|SSTATUS_SIE
operator|)
block|)
function|;
end_function

begin_function
unit|}  static
name|__inline
name|register_t
name|machine_command
parameter_list|(
name|uint64_t
name|cmd
parameter_list|,
name|uint64_t
name|arg
parameter_list|)
block|{
name|uint64_t
name|res
decl_stmt|;
asm|__asm __volatile(
literal|"mv	t5, %2\n"
literal|"mv	t6, %1\n"
literal|"ecall\n"
literal|"mv	%0, t6"
operator|:
literal|"=&r"
operator|(
name|res
operator|)
operator|:
literal|"r"
operator|(
name|arg
operator|)
operator|,
literal|"r"
operator|(
name|cmd
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|res
operator|)
return|;
end_return

begin_define
unit|}
define|#
directive|define
name|cpu_nullop
parameter_list|()
value|riscv_nullop()
end_define

begin_define
define|#
directive|define
name|cpufunc_nullop
parameter_list|()
value|riscv_nullop()
end_define

begin_define
define|#
directive|define
name|cpu_setttb
parameter_list|(
name|a
parameter_list|)
value|riscv_setttb(a)
end_define

begin_define
define|#
directive|define
name|cpu_tlb_flushID
parameter_list|()
value|riscv_tlb_flushID()
end_define

begin_define
define|#
directive|define
name|cpu_tlb_flushID_SE
parameter_list|(
name|e
parameter_list|)
value|riscv_tlb_flushID_SE(e)
end_define

begin_define
define|#
directive|define
name|cpu_dcache_wbinv_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|riscv_dcache_wbinv_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_dcache_inv_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|riscv_dcache_inv_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_dcache_wb_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|riscv_dcache_wb_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_idcache_wbinv_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|riscv_idcache_wbinv_range((a), (s))
end_define

begin_define
define|#
directive|define
name|cpu_icache_sync_range
parameter_list|(
name|a
parameter_list|,
name|s
parameter_list|)
value|riscv_icache_sync_range((a), (s))
end_define

begin_expr_stmt
unit|void
name|riscv_nullop
argument_list|(
name|void
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|void
name|riscv_setttb
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|riscv_tlb_flushID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|riscv_tlb_flushID_SE
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|riscv_icache_sync_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|riscv_idcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|riscv_dcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|riscv_dcache_inv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|riscv_dcache_wb_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_CPUFUNC_H_ */
end_comment

end_unit

