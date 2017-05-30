begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2014 Andrew Turner  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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
file|<machine/armreg.h>
end_include

begin_function_decl
name|void
name|pan_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
name|__inline
name|void
name|breakpoint
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm("brk #0");
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|dbg_disable
parameter_list|(
name|void
parameter_list|)
block|{
name|uint32_t
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"mrs %x0, daif   \n"
literal|"msr daifset, #8 \n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
operator|)
return|;
end_return

begin_function
unit|}  static
name|__inline
name|void
name|dbg_enable
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("msr daifclr, #8");
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
comment|/* DAIF is a 32-bit register */
name|uint32_t
name|ret
decl_stmt|;
asm|__asm __volatile(
literal|"mrs %x0, daif   \n"
literal|"msr daifset, #2 \n"
operator|:
literal|"=&r"
operator|(
name|ret
operator|)
block|)
function|;
end_function

begin_return
return|return
operator|(
name|ret
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
name|WRITE_SPECIALREG
argument_list|(
name|daif
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|intr_enable
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("msr daifclr, #2");
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|get_midr
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|midr
decl_stmt|;
name|midr
operator|=
name|READ_SPECIALREG
argument_list|(
name|midr_el1
argument_list|)
expr_stmt|;
return|return
operator|(
name|midr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|register_t
name|get_mpidr
parameter_list|(
name|void
parameter_list|)
block|{
name|uint64_t
name|mpidr
decl_stmt|;
name|mpidr
operator|=
name|READ_SPECIALREG
argument_list|(
name|mpidr_el1
argument_list|)
expr_stmt|;
return|return
operator|(
name|mpidr
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|clrex
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* 	 * Ensure compiler barrier, otherwise the monitor clear might 	 * occur too late for us ? 	 */
asm|__asm __volatile("clrex" : : : "memory");
block|}
end_function

begin_decl_stmt
specifier|extern
name|int64_t
name|dcache_line_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int64_t
name|icache_line_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int64_t
name|idcache_line_size
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int64_t
name|dczva_line_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|cpu_nullop
parameter_list|()
value|arm64_nullop()
end_define

begin_define
define|#
directive|define
name|cpufunc_nullop
parameter_list|()
value|arm64_nullop()
end_define

begin_define
define|#
directive|define
name|cpu_setttb
parameter_list|(
name|a
parameter_list|)
value|arm64_setttb(a)
end_define

begin_define
define|#
directive|define
name|cpu_tlb_flushID
parameter_list|()
value|arm64_tlb_flushID()
end_define

begin_define
define|#
directive|define
name|cpu_tlb_flushID_SE
parameter_list|(
name|e
parameter_list|)
value|arm64_tlb_flushID_SE(e)
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
value|arm64_dcache_wbinv_range((a), (s))
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
value|arm64_dcache_inv_range((a), (s))
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
value|arm64_dcache_wb_range((a), (s))
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
value|arm64_idcache_wbinv_range((a), (s))
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
value|arm64_icache_sync_range((a), (s))
end_define

begin_function_decl
name|void
name|arm64_nullop
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm64_setttb
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm64_tlb_flushID
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm64_tlb_flushID_SE
parameter_list|(
name|vm_offset_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm64_icache_sync_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm64_idcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm64_dcache_wbinv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm64_dcache_inv_range
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|arm64_dcache_wb_range
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

