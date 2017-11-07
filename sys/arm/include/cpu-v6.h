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
operator|<
literal|6
end_if

begin_error
error|#
directive|error
error|Only include this file for ARMv6
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Some kernel modules (dtrace all for example) are compiled  * unconditionally with -DSMP. Although it looks like a bug,  * handle this case here and in #elif condition in ARM_SMP_UP macro.  */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|<=
literal|6
operator|&&
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|KLD_MODULE
argument_list|)
end_if

begin_error
error|#
directive|error
error|SMP option is not supported on ARMv6
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|<=
literal|6
operator|&&
name|defined
argument_list|(
name|SMP_ON_UP
argument_list|)
end_if

begin_error
error|#
directive|error
error|SMP_ON_UP option is only supported on ARMv7+ CPUs
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
name|defined
argument_list|(
name|SMP_ON_UP
argument_list|)
end_if

begin_error
error|#
directive|error
error|SMP option must be defined for SMP_ON_UP option
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CPU_ASID_KERNEL
value|0
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SMP_ON_UP
argument_list|)
end_if

begin_define
define|#
directive|define
name|ARM_SMP_UP
parameter_list|(
name|smp_code
parameter_list|,
name|up_code
parameter_list|)
define|\
value|do {								\ 	if (cpuinfo.mp_ext != 0) {				\ 		smp_code;					\ 	} else {						\ 		up_code;					\ 	}							\ } while (0)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|SMP
argument_list|)
operator|&&
name|__ARM_ARCH
operator|>
literal|6
end_elif

begin_define
define|#
directive|define
name|ARM_SMP_UP
parameter_list|(
name|smp_code
parameter_list|,
name|up_code
parameter_list|)
define|\
value|do {								\ 	smp_code;						\ } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ARM_SMP_UP
parameter_list|(
name|smp_code
parameter_list|,
name|up_code
parameter_list|)
define|\
value|do {								\ 	up_code;						\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|dcache_wbinv_poc_all
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* !!! NOT SMP coherent function !!! */
end_comment

begin_function_decl
name|vm_offset_t
name|dcache_wb_pou_checked
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|vm_offset_t
name|icache_inv_pou_checked
parameter_list|(
name|vm_offset_t
parameter_list|,
name|vm_size_t
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|DEV_PMU
end_ifdef

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_define
define|#
directive|define
name|PMU_OVSR_C
value|0x80000000
end_define

begin_comment
comment|/* Cycle Counter */
end_comment

begin_decl_stmt
specifier|extern
name|uint32_t
name|ccnt_hi
index|[
name|MAXCPU
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|pmu_attched
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DEV_PMU */
end_comment

begin_define
define|#
directive|define
name|sev
parameter_list|()
value|__asm __volatile("sev" : : : "memory")
end_define

begin_define
define|#
directive|define
name|wfe
parameter_list|()
value|__asm __volatile("wfe" : : : "memory")
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

begin_define
define|#
directive|define
name|_W64F1
parameter_list|(
name|fname
parameter_list|,
name|aname
modifier|...
parameter_list|)
define|\
value|static __inline void							\ fname(uint64_t reg)							\ {									\ 	__asm __volatile("mcrr\t" _FX(aname):: "r" (reg));		\ }
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
argument_list|(
name|SMP
argument_list|)
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
argument_list|(
name|SMP
argument_list|)
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
argument_list|(
name|SMP
argument_list|)
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
argument_list|(
name|SMP
argument_list|)
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
argument_list|(
name|SMP
argument_list|)
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
comment|/* CP14 Debug Registers */
end_comment

begin_macro
name|_RF0
argument_list|(
argument|cp14_dbgdidr_get
argument_list|,
argument|CP14_DBGDIDR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp14_dbgprsr_get
argument_list|,
argument|CP14_DBGPRSR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp14_dbgoslsr_get
argument_list|,
argument|CP14_DBGOSLSR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp14_dbgosdlr_get
argument_list|,
argument|CP14_DBGOSDLR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp14_dbgdscrint_get
argument_list|,
argument|CP14_DBGDSCRint(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp14_dbgdscr_v6_set
argument_list|,
argument|CP14_DBGDSCRext_V6(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp14_dbgdscr_v7_set
argument_list|,
argument|CP14_DBGDSCRext_V7(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp14_dbgvcr_set
argument_list|,
argument|CP14_DBGVCR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp14_dbgoslar_set
argument_list|,
argument|CP14_DBGOSLAR(%
literal|0
argument|)
argument_list|)
end_macro

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

begin_macro
name|_RF0
argument_list|(
argument|cp15_l2ctlr_get
argument_list|,
argument|CP15_L2CTLR(%
literal|0
argument|)
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

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

begin_macro
name|_WF1
argument_list|(
argument|cp15_ats1cpr_set
argument_list|,
argument|CP15_ATS1CPR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_ats1cpw_set
argument_list|,
argument|CP15_ATS1CPW(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_ats1cur_set
argument_list|,
argument|CP15_ATS1CUR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_ats1cuw_set
argument_list|,
argument|CP15_ATS1CUW(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_par_get
argument_list|,
argument|CP15_PAR(%
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
argument|cp15_ccsidr_get
argument_list|,
argument|CP15_CCSIDR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_clidr_get
argument_list|,
argument|CP15_CLIDR(%
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
name|_WF1
argument_list|(
argument|cp15_csselr_set
argument_list|,
argument|CP15_CSSELR(%
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

begin_comment
comment|/* Performance Monitor registers */
end_comment

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|==
literal|6
operator|&&
name|defined
argument_list|(
name|CPU_ARM1176
argument_list|)
end_if

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmuserenr_get
argument_list|,
argument|CP15_PMUSERENR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmuserenr_set
argument_list|,
argument|CP15_PMUSERENR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmcr_get
argument_list|,
argument|CP15_PMCR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmcr_set
argument_list|,
argument|CP15_PMCR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmccntr_get
argument_list|,
argument|CP15_PMCCNTR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmccntr_set
argument_list|,
argument|CP15_PMCCNTR(%
literal|0
argument|)
argument_list|)
end_macro

begin_elif
elif|#
directive|elif
name|__ARM_ARCH
operator|>
literal|6
end_elif

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmcr_get
argument_list|,
argument|CP15_PMCR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmcr_set
argument_list|,
argument|CP15_PMCR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmcnten_get
argument_list|,
argument|CP15_PMCNTENSET(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmcnten_set
argument_list|,
argument|CP15_PMCNTENSET(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmcnten_clr
argument_list|,
argument|CP15_PMCNTENCLR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmovsr_get
argument_list|,
argument|CP15_PMOVSR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmovsr_set
argument_list|,
argument|CP15_PMOVSR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmswinc_set
argument_list|,
argument|CP15_PMSWINC(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmselr_get
argument_list|,
argument|CP15_PMSELR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmselr_set
argument_list|,
argument|CP15_PMSELR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmccntr_get
argument_list|,
argument|CP15_PMCCNTR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmccntr_set
argument_list|,
argument|CP15_PMCCNTR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmxevtyper_get
argument_list|,
argument|CP15_PMXEVTYPER(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmxevtyper_set
argument_list|,
argument|CP15_PMXEVTYPER(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmxevcntr_get
argument_list|,
argument|CP15_PMXEVCNTRR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmxevcntr_set
argument_list|,
argument|CP15_PMXEVCNTRR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pmuserenr_get
argument_list|,
argument|CP15_PMUSERENR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pmuserenr_set
argument_list|,
argument|CP15_PMUSERENR(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_pminten_get
argument_list|,
argument|CP15_PMINTENSET(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pminten_set
argument_list|,
argument|CP15_PMINTENSET(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_pminten_clr
argument_list|,
argument|CP15_PMINTENCLR(%
literal|0
argument|)
argument_list|)
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_macro
name|_RF0
argument_list|(
argument|cp15_tpidrurw_get
argument_list|,
argument|CP15_TPIDRURW(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_tpidrurw_set
argument_list|,
argument|CP15_TPIDRURW(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_tpidruro_get
argument_list|,
argument|CP15_TPIDRURO(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_tpidruro_set
argument_list|,
argument|CP15_TPIDRURO(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_tpidrpwr_get
argument_list|,
argument|CP15_TPIDRPRW(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_tpidrpwr_set
argument_list|,
argument|CP15_TPIDRPRW(%
literal|0
argument|)
argument_list|)
end_macro

begin_comment
comment|/* Generic Timer registers - only use when you know the hardware is available */
end_comment

begin_macro
name|_RF0
argument_list|(
argument|cp15_cntfrq_get
argument_list|,
argument|CP15_CNTFRQ(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cntfrq_set
argument_list|,
argument|CP15_CNTFRQ(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_cntkctl_get
argument_list|,
argument|CP15_CNTKCTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cntkctl_set
argument_list|,
argument|CP15_CNTKCTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_cntp_tval_get
argument_list|,
argument|CP15_CNTP_TVAL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cntp_tval_set
argument_list|,
argument|CP15_CNTP_TVAL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_cntp_ctl_get
argument_list|,
argument|CP15_CNTP_CTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cntp_ctl_set
argument_list|,
argument|CP15_CNTP_CTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_cntv_tval_get
argument_list|,
argument|CP15_CNTV_TVAL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cntv_tval_set
argument_list|,
argument|CP15_CNTV_TVAL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_cntv_ctl_get
argument_list|,
argument|CP15_CNTV_CTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cntv_ctl_set
argument_list|,
argument|CP15_CNTV_CTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_cnthctl_get
argument_list|,
argument|CP15_CNTHCTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cnthctl_set
argument_list|,
argument|CP15_CNTHCTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_cnthp_tval_get
argument_list|,
argument|CP15_CNTHP_TVAL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cnthp_tval_set
argument_list|,
argument|CP15_CNTHP_TVAL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_RF0
argument_list|(
argument|cp15_cnthp_ctl_get
argument_list|,
argument|CP15_CNTHP_CTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_WF1
argument_list|(
argument|cp15_cnthp_ctl_set
argument_list|,
argument|CP15_CNTHP_CTL(%
literal|0
argument|)
argument_list|)
end_macro

begin_macro
name|_R64F0
argument_list|(
argument|cp15_cntpct_get
argument_list|,
argument|CP15_CNTPCT(%Q0, %R0)
argument_list|)
end_macro

begin_macro
name|_R64F0
argument_list|(
argument|cp15_cntvct_get
argument_list|,
argument|CP15_CNTVCT(%Q0, %R0)
argument_list|)
end_macro

begin_macro
name|_R64F0
argument_list|(
argument|cp15_cntp_cval_get
argument_list|,
argument|CP15_CNTP_CVAL(%Q0, %R0)
argument_list|)
end_macro

begin_macro
name|_W64F1
argument_list|(
argument|cp15_cntp_cval_set
argument_list|,
argument|CP15_CNTP_CVAL(%Q0, %R0)
argument_list|)
end_macro

begin_macro
name|_R64F0
argument_list|(
argument|cp15_cntv_cval_get
argument_list|,
argument|CP15_CNTV_CVAL(%Q0, %R0)
argument_list|)
end_macro

begin_macro
name|_W64F1
argument_list|(
argument|cp15_cntv_cval_set
argument_list|,
argument|CP15_CNTV_CVAL(%Q0, %R0)
argument_list|)
end_macro

begin_macro
name|_R64F0
argument_list|(
argument|cp15_cntvoff_get
argument_list|,
argument|CP15_CNTVOFF(%Q0, %R0)
argument_list|)
end_macro

begin_macro
name|_W64F1
argument_list|(
argument|cp15_cntvoff_set
argument_list|,
argument|CP15_CNTVOFF(%Q0, %R0)
argument_list|)
end_macro

begin_macro
name|_R64F0
argument_list|(
argument|cp15_cnthp_cval_get
argument_list|,
argument|CP15_CNTHP_CVAL(%Q0, %R0)
argument_list|)
end_macro

begin_macro
name|_W64F1
argument_list|(
argument|cp15_cnthp_cval_set
argument_list|,
argument|CP15_CNTHP_CVAL(%Q0, %R0)
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
name|va
parameter_list|)
block|{
name|KASSERT
argument_list|(
operator|(
name|va
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"%s: va %#x not aligned"
operator|,
name|__func__
operator|,
name|va
operator|)
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|_CP15_TLBIMVA
argument_list|(
name|va
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
name|va
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|eva
init|=
name|va
operator|+
name|size
decl_stmt|;
name|KASSERT
argument_list|(
operator|(
name|va
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"%s: va %#x not aligned"
operator|,
name|__func__
operator|,
name|va
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
operator|(
name|size
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"%s: size %#x not aligned"
operator|,
name|__func__
operator|,
name|size
operator|)
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
for|for
control|(
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
name|va
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

begin_if
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
operator|&&
name|defined
argument_list|(
name|SMP
argument_list|)
end_if

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
name|ARM_SMP_UP
argument_list|(
name|_CP15_TLBIALLIS
argument_list|()
argument_list|,
name|_CP15_TLBIALL
argument_list|()
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
name|tlb_flush_all_ng
parameter_list|(
name|void
parameter_list|)
block|{
name|dsb
argument_list|()
expr_stmt|;
name|ARM_SMP_UP
argument_list|(
name|_CP15_TLBIASIDIS
argument_list|(
name|CPU_ASID_KERNEL
argument_list|)
argument_list|,
name|_CP15_TLBIASID
argument_list|(
name|CPU_ASID_KERNEL
argument_list|)
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
name|va
parameter_list|)
block|{
name|KASSERT
argument_list|(
operator|(
name|va
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"%s: va %#x not aligned"
operator|,
name|__func__
operator|,
name|va
operator|)
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|ARM_SMP_UP
argument_list|(
name|_CP15_TLBIMVAAIS
argument_list|(
name|va
argument_list|)
argument_list|,
name|_CP15_TLBIMVA
argument_list|(
name|va
operator||
name|CPU_ASID_KERNEL
argument_list|)
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
name|va
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|eva
init|=
name|va
operator|+
name|size
decl_stmt|;
name|KASSERT
argument_list|(
operator|(
name|va
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"%s: va %#x not aligned"
operator|,
name|__func__
operator|,
name|va
operator|)
argument_list|)
expr_stmt|;
name|KASSERT
argument_list|(
operator|(
name|size
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|,
operator|(
literal|"%s: size %#x not aligned"
operator|,
name|__func__
operator|,
name|size
operator|)
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|ARM_SMP_UP
argument_list|(
argument|{ 			for (; va< eva; va += PAGE_SIZE) 				_CP15_TLBIMVAAIS(va); 		}
argument_list|,
argument|{ 			for (; va< eva; va += PAGE_SIZE) 				_CP15_TLBIMVA(va | CPU_ASID_KERNEL); 		}
argument_list|)
empty_stmt|;
name|dsb
argument_list|()
expr_stmt|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* __ARM_ARCH< 7 */
end_comment

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
name|va
parameter_list|)
value|tlb_flush_local(va)
end_define

begin_define
define|#
directive|define
name|tlb_flush_range
parameter_list|(
name|va
parameter_list|,
name|size
parameter_list|)
value|tlb_flush_range_local(va, size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ARM_ARCH< 7 */
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
name|va
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|eva
init|=
name|va
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|va
operator|&=
operator|~
name|cpuinfo
operator|.
name|dcache_line_mask
expr_stmt|;
for|for
control|(
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|cpuinfo
operator|.
name|dcache_line_size
control|)
block|{
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
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
name|ARM_SMP_UP
argument_list|(
name|_CP15_ICIALLUIS
argument_list|()
argument_list|,
name|_CP15_ICIALLU
argument_list|()
argument_list|)
expr_stmt|;
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
name|ARM_SMP_UP
argument_list|(
name|_CP15_ICIALLUIS
argument_list|()
argument_list|,
name|_CP15_ICIALLU
argument_list|()
argument_list|)
expr_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Invalidate branch predictor buffer */
end_comment

begin_function
specifier|static
name|__inline
name|void
name|bpb_inv_all
parameter_list|(
name|void
parameter_list|)
block|{
name|ARM_SMP_UP
argument_list|(
name|_CP15_BPIALLIS
argument_list|()
argument_list|,
name|_CP15_BPIALL
argument_list|()
argument_list|)
expr_stmt|;
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
name|va
parameter_list|,
name|vm_size_t
name|size
parameter_list|)
block|{
name|vm_offset_t
name|eva
init|=
name|va
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|va
operator|&=
operator|~
name|cpuinfo
operator|.
name|dcache_line_mask
expr_stmt|;
for|for
control|(
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|cpuinfo
operator|.
name|dcache_line_size
control|)
block|{
if|#
directive|if
name|__ARM_ARCH
operator|>=
literal|7
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
comment|/*  * Invalidate D-cache to PoC  *  * Caches are invalidated from outermost to innermost as fresh cachelines  * flow in this direction. In given range, if there was no dirty cacheline  * in any cache before, no stale cacheline should remain in them after this  * operation finishes.  */
end_comment

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
name|vm_offset_t
name|eva
init|=
name|va
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
comment|/* invalidate L2 first */
name|cpu_l2cache_inv_range
argument_list|(
name|pa
argument_list|,
name|size
argument_list|)
expr_stmt|;
comment|/* then L1 */
name|va
operator|&=
operator|~
name|cpuinfo
operator|.
name|dcache_line_mask
expr_stmt|;
for|for
control|(
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|cpuinfo
operator|.
name|dcache_line_size
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
comment|/*  * Discard D-cache lines to PoC, prior to overwrite by DMA engine.  *  * Normal invalidation does L2 then L1 to ensure that stale data from L2 doesn't  * flow into L1 while invalidating.  This routine is intended to be used only  * when invalidating a buffer before a DMA operation loads new data into memory.  * The concern in this case is that dirty lines are not evicted to main memory,  * overwriting the DMA data.  For that reason, the L1 is done first to ensure  * that an evicted L1 line doesn't flow to L2 after the L2 has been cleaned.  */
end_comment

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
name|vm_offset_t
name|eva
init|=
name|va
operator|+
name|size
decl_stmt|;
comment|/* invalidate L1 first */
name|dsb
argument_list|()
expr_stmt|;
name|va
operator|&=
operator|~
name|cpuinfo
operator|.
name|dcache_line_mask
expr_stmt|;
for|for
control|(
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|cpuinfo
operator|.
name|dcache_line_size
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
block|}
end_function

begin_comment
comment|/*  * Write back D-cache to PoC  *  * Caches are written back from innermost to outermost as dirty cachelines  * flow in this direction. In given range, no dirty cacheline should remain  * in any cache after this operation finishes.  */
end_comment

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
name|vm_offset_t
name|eva
init|=
name|va
operator|+
name|size
decl_stmt|;
name|dsb
argument_list|()
expr_stmt|;
name|va
operator|&=
operator|~
name|cpuinfo
operator|.
name|dcache_line_mask
expr_stmt|;
for|for
control|(
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|cpuinfo
operator|.
name|dcache_line_size
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
name|va
operator|=
name|sva
operator|&
operator|~
name|cpuinfo
operator|.
name|dcache_line_mask
expr_stmt|;
for|for
control|(
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|cpuinfo
operator|.
name|dcache_line_size
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
name|va
operator|=
name|sva
operator|&
operator|~
name|cpuinfo
operator|.
name|dcache_line_mask
expr_stmt|;
for|for
control|(
init|;
name|va
operator|<
name|eva
condition|;
name|va
operator|+=
name|cpuinfo
operator|.
name|dcache_line_size
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

begin_comment
comment|/*  * Functions for address checking:  *  *  cp15_ats1cpr_check() ... check stage 1 privileged (PL1) read access  *  cp15_ats1cpw_check() ... check stage 1 privileged (PL1) write access  *  cp15_ats1cur_check() ... check stage 1 unprivileged (PL0) read access  *  cp15_ats1cuw_check() ... check stage 1 unprivileged (PL0) write access  *  * They must be called while interrupts are disabled to get consistent result.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|cp15_ats1cpr_check
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|)
block|{
name|cp15_ats1cpr_set
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
return|return
operator|(
name|cp15_par_get
argument_list|()
operator|&
literal|0x01
condition|?
name|EFAULT
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|cp15_ats1cpw_check
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|)
block|{
name|cp15_ats1cpw_set
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
return|return
operator|(
name|cp15_par_get
argument_list|()
operator|&
literal|0x01
condition|?
name|EFAULT
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|cp15_ats1cur_check
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|)
block|{
name|cp15_ats1cur_set
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
return|return
operator|(
name|cp15_par_get
argument_list|()
operator|&
literal|0x01
condition|?
name|EFAULT
else|:
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|cp15_ats1cuw_check
parameter_list|(
name|vm_offset_t
name|addr
parameter_list|)
block|{
name|cp15_ats1cuw_set
argument_list|(
name|addr
argument_list|)
expr_stmt|;
name|isb
argument_list|()
expr_stmt|;
return|return
operator|(
name|cp15_par_get
argument_list|()
operator|&
literal|0x01
condition|?
name|EFAULT
else|:
literal|0
operator|)
return|;
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

