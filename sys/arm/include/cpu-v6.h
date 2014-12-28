begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright 2014 Svatopluk Kraus<onwahe@gmail.com>  * Copyright 2014 Michal Meloun<meloun@miracle.cz>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_CPU_V6_H
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_CPU_V6_H
end_define

begin_include
include|#
directive|include
file|"machine/atomic.h"
end_include

begin_include
include|#
directive|include
file|"machine/cpufunc.h"
end_include

begin_include
include|#
directive|include
file|"machine/cpuinfo.h"
end_include

begin_include
include|#
directive|include
file|"machine/sysreg.h"
end_include

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
value|static __inline register_t						\ fname(void)								\ {									\ 	register_t reg;							\ 	__asm __volatile("mrc\t" _FX(aname): "=r" (reg));		\ 	return(reg);							\ }
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
value|static __inline void							\ fname(register_t reg)							\ {									\ 	__asm __volatile("mcr\t" _FX(aname):: "r" (reg));		\ }
end_define

begin_comment
comment|/*  * Raw CP15  maintenance operations  * !!! not for external use !!!  */
end_comment

begin_comment
comment|/* TLB */
end_comment

begin_macro
name|_WF0
argument_list|(
argument|_CP15_TLBIALL
argument_list|,
argument|CP15_TLBIALL
argument_list|)
end_macro

begin_comment
comment|/* Invalidate entire unified TLB */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
operator|&&
name|defined
name|SMP
end_if

begin_macro
name|_WF0
argument_list|(
argument|_CP15_TLBIALLIS
argument_list|,
argument|CP15_TLBIALLIS
argument_list|)
end_macro

begin_comment
comment|/* Invalidate entire unified TLB IS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_WF1
argument_list|(
argument|_CP15_TLBIASID
argument_list|,
argument|CP15_TLBIASID(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Invalidate unified TLB by ASID */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
operator|&&
name|defined
name|SMP
end_if

begin_macro
name|_WF1
argument_list|(
argument|_CP15_TLBIASIDIS
argument_list|,
argument|CP15_TLBIASIDIS(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Invalidate unified TLB by ASID IS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_WF1
argument_list|(
argument|_CP15_TLBIMVAA
argument_list|,
argument|CP15_TLBIMVAA(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Invalidate unified TLB by MVA, all ASID */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
operator|&&
name|defined
name|SMP
end_if

begin_macro
name|_WF1
argument_list|(
argument|_CP15_TLBIMVAAIS
argument_list|,
argument|CP15_TLBIMVAAIS(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Invalidate unified TLB by MVA, all ASID IS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_WF1
argument_list|(
argument|_CP15_TLBIMVA
argument_list|,
argument|CP15_TLBIMVA(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Invalidate unified TLB by MVA */
end_comment

begin_macro
name|_WF1
argument_list|(
argument|_CP15_TTB_SET
argument_list|,
argument|CP15_TTBR0(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Cache and Branch predictor */
end_comment

begin_macro
name|_WF0
argument_list|(
argument|_CP15_BPIALL
argument_list|,
argument|CP15_BPIALL
argument_list|)
end_macro

begin_comment
comment|/* Branch predictor invalidate all */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
operator|&&
name|defined
name|SMP
end_if

begin_macro
name|_WF0
argument_list|(
argument|_CP15_BPIALLIS
argument_list|,
argument|CP15_BPIALLIS
argument_list|)
end_macro

begin_comment
comment|/* Branch predictor invalidate all IS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_WF1
argument_list|(
argument|_CP15_BPIMVA
argument_list|,
argument|CP15_BPIMVA(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Branch predictor invalidate by MVA */
end_comment

begin_macro
name|_WF1
argument_list|(
argument|_CP15_DCCIMVAC
argument_list|,
argument|CP15_DCCIMVAC(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Data cache clean and invalidate by MVA PoC */
end_comment

begin_macro
name|_WF1
argument_list|(
argument|_CP15_DCCISW
argument_list|,
argument|CP15_DCCISW(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Data cache clean and invalidate by set/way */
end_comment

begin_macro
name|_WF1
argument_list|(
argument|_CP15_DCCMVAC
argument_list|,
argument|CP15_DCCMVAC(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Data cache clean by MVA PoC */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
end_if

begin_macro
name|_WF1
argument_list|(
argument|_CP15_DCCMVAU
argument_list|,
argument|CP15_DCCMVAU(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Data cache clean by MVA PoU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_WF1
argument_list|(
argument|_CP15_DCCSW
argument_list|,
argument|CP15_DCCSW(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Data cache clean by set/way */
end_comment

begin_macro
name|_WF1
argument_list|(
argument|_CP15_DCIMVAC
argument_list|,
argument|CP15_DCIMVAC(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Data cache invalidate by MVA PoC */
end_comment

begin_macro
name|_WF1
argument_list|(
argument|_CP15_DCISW
argument_list|,
argument|CP15_DCISW(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Data cache invalidate by set/way */
end_comment

begin_macro
name|_WF0
argument_list|(
argument|_CP15_ICIALLU
argument_list|,
argument|CP15_ICIALLU
argument_list|)
end_macro

begin_comment
comment|/* Instruction cache invalidate all PoU */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
operator|&&
name|defined
name|SMP
end_if

begin_macro
name|_WF0
argument_list|(
argument|_CP15_ICIALLUIS
argument_list|,
argument|CP15_ICIALLUIS
argument_list|)
end_macro

begin_comment
comment|/* Instruction cache invalidate all PoU IS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_WF1
argument_list|(
argument|_CP15_ICIMVAU
argument_list|,
argument|CP15_ICIMVAU(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Instruction cache invalidate */
end_comment

begin_comment
comment|/*  * Publicly accessible functions  */
end_comment

begin_comment
comment|/* Various control registers */
end_comment

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
argument|cp15_ifsr_get
argument_list|,
argument|CP15_IFSR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_prrr_set
argument_list|,
argument|CP15_PRRR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_nmrr_set
argument_list|,
argument|CP15_NMRR(%
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

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
end_if

begin_macro
name|_RF0
argument_list|(
argument|cp15_ifar_get
argument_list|,
argument|CP15_IFAR(%
literal|0
argument|)
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

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
argument|cp15_mpidr_get
argument_list|,
argument|CP15_MPIDR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_revidr_get
argument_list|,
argument|CP15_REVIDR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_aidr_get
argument_list|,
argument|CP15_AIDR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_pfr0_get
argument_list|,
argument|CP15_ID_PFR0(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_pfr1_get
argument_list|,
argument|CP15_ID_PFR1(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_dfr0_get
argument_list|,
argument|CP15_ID_DFR0(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_afr0_get
argument_list|,
argument|CP15_ID_AFR0(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_mmfr0_get
argument_list|,
argument|CP15_ID_MMFR0(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_mmfr1_get
argument_list|,
argument|CP15_ID_MMFR1(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_mmfr2_get
argument_list|,
argument|CP15_ID_MMFR2(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_mmfr3_get
argument_list|,
argument|CP15_ID_MMFR3(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_isar0_get
argument_list|,
argument|CP15_ID_ISAR0(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_isar1_get
argument_list|,
argument|CP15_ID_ISAR1(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_isar2_get
argument_list|,
argument|CP15_ID_ISAR2(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_isar3_get
argument_list|,
argument|CP15_ID_ISAR3(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_isar4_get
argument_list|,
argument|CP15_ID_ISAR4(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_id_isar5_get
argument_list|,
argument|CP15_ID_ISAR5(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_cbar_get
argument_list|,
argument|CP15_CBAR(%
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
comment|/*  * TLB maintenance operations.  */
end_comment

begin_comment
comment|/* Local (i.e. not broadcasting ) operations.  */
end_comment

begin_comment
comment|/* Flush all TLB entries (even global). */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|tlb_flush_all_local
parameter_list|(
name|void
parameter_list|)
block|{
name|dsb
argument_list|()
expr_stmt|;
name|_CP15_TLBIALL
argument_list|()
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Flush all not global TLB entries. */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|tlb_flush_all_ng_local
parameter_list|(
name|void
parameter_list|)
block|{
name|dsb
argument_list|()
expr_stmt|;
name|_CP15_TLBIASID
argument_list|(
name|CPU_ASID_KERNEL
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Flush single TLB entry (even global). */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|tlb_flush_local
parameter_list|(
name|vm_offset_t
name|sva
parameter_list|)
block|{
name|dsb
argument_list|()
expr_stmt|;
name|_CP15_TLBIMVA
argument_list|(
operator|(
name|sva
operator|&
operator|~
name|PAGE_MASK
operator|)
operator||
name|CPU_ASID_KERNEL
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Flush range of TLB entries (even global). */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|tlb_flush_range_local
parameter_list|(
name|vm_offset_t
name|sva
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|va
decl_stmt|;
name|vm_offset_t
name|eva
init|=
name|sva
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
for|for
control|(
name|va
operator|=
name|sva
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|PAGE_SIZE
control|)
name|_CP15_TLBIMVA
argument_list|(
operator|(
name|va
operator|&
operator|~
name|PAGE_MASK
operator|)
operator||
name|CPU_ASID_KERNEL
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Broadcasting operations. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SMP
end_ifndef

begin_define
define|#
directive|define
name|tlb_flush_all
parameter_list|()
value|tlb_flush_all_local()
end_define

begin_define
define|#
directive|define
name|tlb_flush_all_ng
parameter_list|()
value|tlb_flush_all_ng_local()
end_define

begin_define
define|#
directive|define
name|tlb_flush
parameter_list|(
name|sva
parameter_list|)
value|tlb_flush_local(sva)
end_define

begin_define
define|#
directive|define
name|tlb_flush_range
parameter_list|(
name|sva
parameter_list|,
name|size
parameter_list|)
value|tlb_flush_range_local(sva, size)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SMP */
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
name|dsb
argument_list|()
expr_stmt|;
name|_CP15_TLBIALLIS
argument_list|()
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|tlb_flush_all_ng
parameter_list|()
block|{
name|dsb
argument_list|()
expr_stmt|;
name|_CP15_TLBIASIDIS
argument_list|(
name|CPU_ASID_KERNEL
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|tlb_flush
parameter_list|(
name|vm_offset_t
name|sva
parameter_list|)
block|{
name|dsb
argument_list|()
expr_stmt|;
name|_CP15_TLBIMVAAIS
argument_list|(
name|sva
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|tlb_flush_range
parameter_list|(
name|vm_offset_t
name|sva
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|va
decl_stmt|;
name|vm_offset_t
name|eva
init|=
name|sva
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
for|for
control|(
name|va
operator|=
name|sva
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|PAGE_SIZE
control|)
name|_CP15_TLBIMVAAIS
argument_list|(
name|va
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SMP */
end_comment

begin_comment
comment|/*  * Cache maintenance operations.  */
end_comment

begin_comment
comment|/*  Sync I and D caches to PoU */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|icache_sync
parameter_list|(
name|vm_offset_t
name|sva
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|va
decl_stmt|;
name|vm_offset_t
name|eva
init|=
name|sva
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
for|for
control|(
name|va
operator|=
name|sva
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|arm_dcache_align
control|)
block|{
ifdef|#
directive|ifdef
name|SMP
name|_CP15_DCCMVAU
argument_list|(
name|va
argument_list|)
expr_stmt|;
else|#
directive|else
name|_CP15_DCCMVAC
argument_list|(
name|va
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|dsb
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|SMP
name|_CP15_ICIALLUIS
argument_list|()
expr_stmt|;
else|#
directive|else
name|_CP15_ICIALLU
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|dsb
argument_list|()
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/*  Invalidate I cache */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|icache_inv_all
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|SMP
name|_CP15_ICIALLUIS
argument_list|()
expr_stmt|;
else|#
directive|else
name|_CP15_ICIALLU
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|dsb
argument_list|()
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Write back D-cache to PoU */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|dcache_wb_pou
parameter_list|(
name|vm_offset_t
name|sva
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|va
decl_stmt|;
name|vm_offset_t
name|eva
init|=
name|sva
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
for|for
control|(
name|va
operator|=
name|sva
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|arm_dcache_align
control|)
block|{
ifdef|#
directive|ifdef
name|SMP
name|_CP15_DCCMVAU
argument_list|(
name|va
argument_list|)
expr_stmt|;
else|#
directive|else
name|_CP15_DCCMVAC
argument_list|(
name|va
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Invalidate D-cache to PoC */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|dcache_inv_poc
parameter_list|(
name|vm_offset_t
name|sva
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|va
decl_stmt|;
name|vm_offset_t
name|eva
init|=
name|sva
operator|+
name|size
decl_stmt|;
comment|/* invalidate L1 first */
for|for
control|(
name|va
operator|=
name|sva
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|arm_dcache_align
control|)
block|{
name|_CP15_DCIMVAC
argument_list|(
name|va
argument_list|)
expr_stmt|;
block|}
name|dsb
argument_list|()
expr_stmt|;
comment|/* then L2 */
name|cpu_l2cache_inv_range
argument_list|(
name|pa
argument_list|,
name|size
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
comment|/* then L1 again */
for|for
control|(
name|va
operator|=
name|sva
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|arm_dcache_align
control|)
block|{
name|_CP15_DCIMVAC
argument_list|(
name|va
argument_list|)
expr_stmt|;
block|}
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Write back D-cache to PoC */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|dcache_wb_poc
parameter_list|(
name|vm_offset_t
name|sva
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|va
decl_stmt|;
name|vm_offset_t
name|eva
init|=
name|sva
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
for|for
control|(
name|va
operator|=
name|sva
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|arm_dcache_align
control|)
block|{
name|_CP15_DCCMVAC
argument_list|(
name|va
argument_list|)
expr_stmt|;
block|}
name|dsb
argument_list|()
expr_stmt|;
name|cpu_l2cache_wb_range
argument_list|(
name|pa
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Write back and invalidate D-cache to PoC */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|dcache_wbinv_poc
parameter_list|(
name|vm_offset_t
name|sva
parameter_list|,
name|vm_paddr_t
name|pa
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|va
decl_stmt|;
name|vm_offset_t
name|eva
init|=
name|sva
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
comment|/* write back L1 first */
for|for
control|(
name|va
operator|=
name|sva
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|arm_dcache_align
control|)
block|{
name|_CP15_DCCMVAC
argument_list|(
name|va
argument_list|)
expr_stmt|;
block|}
name|dsb
argument_list|()
expr_stmt|;
comment|/* then write back and invalidate L2 */
name|cpu_l2cache_wbinv_range
argument_list|(
name|pa
argument_list|,
name|size
argument_list|)
expr_stmt|;
comment|/* then invalidate L1 */
for|for
control|(
name|va
operator|=
name|sva
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|arm_dcache_align
control|)
block|{
name|_CP15_DCIMVAC
argument_list|(
name|va
argument_list|)
expr_stmt|;
block|}
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Set TTB0 register */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|cp15_ttbr_set
parameter_list|(
name|uint32_t
name|reg
parameter_list|)
block|{
name|dsb
argument_list|()
expr_stmt|;
name|_CP15_TTB_SET
argument_list|(
name|reg
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|_CP15_BPIALL
argument_list|()
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
name|tlb_flush_all_ng_local
argument_list|()
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !MACHINE_CPU_V6_H */
end_comment

end_unit

