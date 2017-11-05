begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2016 Svatopluk Kraus<skra@FreeBSD.org>  * Copyright 2016 Michal Meloun<mmel@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_CPU_V4_H
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_CPU_V4_H
end_define

begin_comment
comment|/* There are no user serviceable parts here, they may change without notice */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
error|Only include this file in the kernel
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<machine/atomic.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpuinfo.h>
end_include

begin_include
include|#
directive|include
file|<machine/sysreg.h>
end_include

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|6
end_if

begin_error
error|#
directive|error
error|Never include this file for ARMv6
end_error

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPU_ASID_KERNEL
value|0
end_define

begin_comment
comment|/*  * Macros to generate CP15 (system control processor) read/write functions.  */
end_comment

begin_define
define|#
directive|define
name|_FX
parameter_list|(
name|s
modifier|...
parameter_list|)
value|#s
end_define

begin_define
define|#
directive|define
name|_RF0
parameter_list|(
name|fname
parameter_list|,
name|aname
modifier|...
parameter_list|)
define|\
value|static __inline uint32_t						\ fname(void)								\ {									\ 	uint32_t reg;							\ 	__asm __volatile("mrc\t" _FX(aname): "=r" (reg));		\ 	return(reg);							\ }
end_define

begin_define
define|#
directive|define
name|_R64F0
parameter_list|(
name|fname
parameter_list|,
name|aname
parameter_list|)
define|\
value|static __inline uint64_t						\ fname(void)								\ {									\ 	uint64_t reg;							\ 	__asm __volatile("mrrc\t" _FX(aname): "=r" (reg));		\ 	return(reg);							\ }
end_define

begin_define
define|#
directive|define
name|_WF0
parameter_list|(
name|fname
parameter_list|,
name|aname
modifier|...
parameter_list|)
define|\
value|static __inline void							\ fname(void)								\ {									\ 	__asm __volatile("mcr\t" _FX(aname));				\ }
end_define

begin_define
define|#
directive|define
name|_WF1
parameter_list|(
name|fname
parameter_list|,
name|aname
modifier|...
parameter_list|)
define|\
value|static __inline void							\ fname(uint32_t reg)							\ {									\ 	__asm __volatile("mcr\t" _FX(aname):: "r" (reg));		\ }
end_define

begin_comment
comment|/*  * Publicly accessible functions  */
end_comment

begin_comment
comment|/* Various control registers */
end_comment

begin_macro
name|_RF0
argument_list|(
argument|cp15_cpacr_get
argument_list|,
argument|CP15_CPACR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cpacr_set
argument_list|,
argument|CP15_CPACR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_dfsr_get
argument_list|,
argument|CP15_DFSR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_ttbr_get
argument_list|,
argument|CP15_TTBR0(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_dfar_get
argument_list|,
argument|CP15_DFAR(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* XScale */
end_comment

begin_macro
name|_RF0
argument_list|(
argument|cp15_actlr_get
argument_list|,
argument|CP15_ACTLR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_actlr_set
argument_list|,
argument|CP15_ACTLR(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/*CPU id registers */
end_comment

begin_macro
name|_RF0
argument_list|(
argument|cp15_midr_get
argument_list|,
argument|CP15_MIDR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_ctr_get
argument_list|,
argument|CP15_CTR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_tcmtr_get
argument_list|,
argument|CP15_TCMTR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_tlbtr_get
argument_list|,
argument|CP15_TLBTR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_sctlr_get
argument_list|,
argument|CP15_SCTLR(%
literal|0
argument|)
argument_list|)
end_macro

begin_undef
undef|#
directive|undef
name|_FX
end_undef

begin_undef
undef|#
directive|undef
name|_RF0
end_undef

begin_undef
undef|#
directive|undef
name|_WF0
end_undef

begin_undef
undef|#
directive|undef
name|_WF1
end_undef

begin_comment
comment|/*  * armv4/5 compatibility shims.  *  * These functions provide armv4 cache maintenance using the new armv6 names.  * Included here are just the functions actually used now in common code; it may  * be necessary to add things here over time.  *  * The callers of the dcache functions expect these routines to handle address  * and size values which are not aligned to cacheline boundaries; the armv4 and  * armv5 asm code handles that.  */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|tlb_flush_all
parameter_list|(
name|void
parameter_list|)
block|{
name|cpu_tlb_flushID
argument_list|()
expr_stmt|;
name|cpu_cpwait
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|icache_sync
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|cpu_icache_sync_range
argument_list|(
name|va
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|dcache_inv_poc
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|cpu_dcache_inv_range
argument_list|(
name|va
argument_list|,
name|size
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ARM_L2_PIPT
name|cpu_l2cache_inv_range
argument_list|(
name|pa
argument_list|,
name|size
argument_list|)
expr_stmt|;
else|#
directive|else
name|cpu_l2cache_inv_range
argument_list|(
name|va
argument_list|,
name|size
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|dcache_inv_poc_dma
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
comment|/* See armv6 code, above, for why we do L2 before L1 in this case. */
ifdef|#
directive|ifdef
name|ARM_L2_PIPT
name|cpu_l2cache_inv_range
argument_list|(
name|pa
argument_list|,
name|size
argument_list|)
expr_stmt|;
else|#
directive|else
name|cpu_l2cache_inv_range
argument_list|(
name|va
argument_list|,
name|size
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|cpu_dcache_inv_range
argument_list|(
name|va
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|dcache_wb_poc
parameter_list|(
name|vm_offset_t
name|va
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|cpu_dcache_wb_range
argument_list|(
name|va
argument_list|,
name|size
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ARM_L2_PIPT
name|cpu_l2cache_wb_range
argument_list|(
name|pa
argument_list|,
name|size
argument_list|)
expr_stmt|;
else|#
directive|else
name|cpu_l2cache_wb_range
argument_list|(
name|va
argument_list|,
name|size
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|dcache_wbinv_poc_all
parameter_list|(
name|void
parameter_list|)
block|{
name|cpu_idcache_wbinv_all
argument_list|()
expr_stmt|;
name|cpu_l2cache_wbinv_all
argument_list|()
expr_stmt|;
block|}
end_function

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
comment|/* MACHINE_CPU_V4_H */
end_comment

end_unit

