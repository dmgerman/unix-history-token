begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003, Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Machine dependent interfaces */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_PMC_MDEP_H
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_PMC_MDEP_H
value|1
end_define

begin_include
include|#
directive|include
file|<machine/cpufunc.h>
end_include

begin_include
include|#
directive|include
file|<machine/specialreg.h>
end_include

begin_comment
comment|/* AMD K7 PMCs */
end_comment

begin_define
define|#
directive|define
name|K7_NPMCS
value|5
end_define

begin_comment
comment|/* 1 TSC + 4 PMCs */
end_comment

begin_define
define|#
directive|define
name|K7_PMC_COUNTERMASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|K7_PMC_TO_COUNTER
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 24)& K7_PMC_COUNTERMASK)
end_define

begin_define
define|#
directive|define
name|K7_PMC_INVERT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|K7_PMC_ENABLE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|K7_PMC_INT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|K7_PMC_PC
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|K7_PMC_EDGE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|K7_PMC_OS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|K7_PMC_USR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|K7_PMC_UNITMASK_M
value|0x10
end_define

begin_define
define|#
directive|define
name|K7_PMC_UNITMASK_O
value|0x08
end_define

begin_define
define|#
directive|define
name|K7_PMC_UNITMASK_E
value|0x04
end_define

begin_define
define|#
directive|define
name|K7_PMC_UNITMASK_S
value|0x02
end_define

begin_define
define|#
directive|define
name|K7_PMC_UNITMASK_I
value|0x01
end_define

begin_define
define|#
directive|define
name|K7_PMC_UNITMASK_MOESI
value|0x1F
end_define

begin_define
define|#
directive|define
name|K7_PMC_UNITMASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|K7_PMC_EVENTMASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|K7_PMC_TO_UNITMASK
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 8)& K7_PMC_UNITMASK)
end_define

begin_define
define|#
directive|define
name|K7_PMC_TO_EVENTMASK
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_define
define|#
directive|define
name|K7_VALID_BITS
value|(K7_PMC_COUNTERMASK | K7_PMC_INVERT |      \ 	K7_PMC_ENABLE | K7_PMC_INT | K7_PMC_PC | K7_PMC_EDGE | K7_PMC_OS | \ 	K7_PMC_USR | K7_PMC_UNITMASK | K7_PMC_EVENTMASK)
end_define

begin_comment
comment|/* Intel P4 PMCs */
end_comment

begin_define
define|#
directive|define
name|P4_NPMCS
value|19
end_define

begin_comment
comment|/* 1 TSC + 18 PMCS */
end_comment

begin_define
define|#
directive|define
name|P4_NESCR
value|45
end_define

begin_define
define|#
directive|define
name|P4_INVALID_PMC_INDEX
value|-1
end_define

begin_define
define|#
directive|define
name|P4_MAX_ESCR_PER_EVENT
value|2
end_define

begin_define
define|#
directive|define
name|P4_MAX_PMC_PER_ESCR
value|3
end_define

begin_define
define|#
directive|define
name|P4_CCCR_OVF
value|(1<< 31)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_CASCADE
value|(1<< 30)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_OVF_PMI_T1
value|(1<< 27)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_OVF_PMI_T0
value|(1<< 26)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_FORCE_OVF
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_EDGE
value|(1<< 24)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_THRESHOLD_SHIFT
value|20
end_define

begin_define
define|#
directive|define
name|P4_CCCR_THRESHOLD_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|P4_CCCR_TO_THRESHOLD
parameter_list|(
name|C
parameter_list|)
value|(((C)<< P4_CCCR_THRESHOLD_SHIFT)& \ 	P4_CCCR_THRESHOLD_MASK)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_COMPLEMENT
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_COMPARE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_ACTIVE_THREAD_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|P4_CCCR_ACTIVE_THREAD_MASK
value|0x00030000
end_define

begin_define
define|#
directive|define
name|P4_CCCR_TO_ACTIVE_THREAD
parameter_list|(
name|T
parameter_list|)
value|(((T)<< P4_CCCR_ACTIVE_THREAD_SHIFT)& \ 	P4_CCCR_ACTIVE_THREAD_MASK)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_ESCR_SELECT_SHIFT
value|13
end_define

begin_define
define|#
directive|define
name|P4_CCCR_ESCR_SELECT_MASK
value|0x0000E000
end_define

begin_define
define|#
directive|define
name|P4_CCCR_TO_ESCR_SELECT
parameter_list|(
name|E
parameter_list|)
value|(((E)<< P4_CCCR_ESCR_SELECT_SHIFT)& \ 	P4_CCCR_ESCR_SELECT_MASK)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_ENABLE
value|(1<< 12)
end_define

begin_define
define|#
directive|define
name|P4_CCCR_VALID_BITS
value|(P4_CCCR_OVF | P4_CCCR_CASCADE | \     P4_CCCR_OVF_PMI_T1 | P4_CCCR_OVF_PMI_T0 | P4_CCCR_FORCE_OVF | 	 \     P4_CCCR_EDGE | P4_CCCR_THRESHOLD_MASK | P4_CCCR_COMPLEMENT |	 \     P4_CCCR_COMPARE | P4_CCCR_ESCR_SELECT_MASK | P4_CCCR_ENABLE)
end_define

begin_define
define|#
directive|define
name|P4_ESCR_EVENT_SELECT_SHIFT
value|25
end_define

begin_define
define|#
directive|define
name|P4_ESCR_EVENT_SELECT_MASK
value|0x7E000000
end_define

begin_define
define|#
directive|define
name|P4_ESCR_TO_EVENT_SELECT
parameter_list|(
name|E
parameter_list|)
value|(((E)<< P4_ESCR_EVENT_SELECT_SHIFT)& \ 	P4_ESCR_EVENT_SELECT_MASK)
end_define

begin_define
define|#
directive|define
name|P4_ESCR_EVENT_MASK_SHIFT
value|9
end_define

begin_define
define|#
directive|define
name|P4_ESCR_EVENT_MASK_MASK
value|0x01FFFE00
end_define

begin_define
define|#
directive|define
name|P4_ESCR_TO_EVENT_MASK
parameter_list|(
name|M
parameter_list|)
value|(((M)<< P4_ESCR_EVENT_MASK_SHIFT)& \ 	P4_ESCR_EVENT_MASK_MASK)
end_define

begin_define
define|#
directive|define
name|P4_ESCR_TAG_VALUE_SHIFT
value|5
end_define

begin_define
define|#
directive|define
name|P4_ESCR_TAG_VALUE_MASK
value|0x000001E0
end_define

begin_define
define|#
directive|define
name|P4_ESCR_TO_TAG_VALUE
parameter_list|(
name|T
parameter_list|)
value|(((T)<< P4_ESCR_TAG_VALUE_SHIFT)& \ 	P4_ESCR_TAG_VALUE_MASK)
end_define

begin_define
define|#
directive|define
name|P4_ESCR_TAG_ENABLE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|P4_ESCR_T0_OS
value|0x00000008
end_define

begin_define
define|#
directive|define
name|P4_ESCR_T0_USR
value|0x00000004
end_define

begin_define
define|#
directive|define
name|P4_ESCR_T1_OS
value|0x00000002
end_define

begin_define
define|#
directive|define
name|P4_ESCR_T1_USR
value|0x00000001
end_define

begin_define
define|#
directive|define
name|P4_ESCR_OS
value|P4_ESCR_T0_OS
end_define

begin_define
define|#
directive|define
name|P4_ESCR_USR
value|P4_ESCR_T0_USR
end_define

begin_define
define|#
directive|define
name|P4_ESCR_VALID_BITS
value|(P4_ESCR_EVENT_SELECT_MASK |	\     P4_ESCR_EVENT_MASK_MASK | P4_ESCR_TAG_VALUE_MASK | 			\     P4_ESCR_TAG_ENABLE | P4_ESCR_T0_OS | P4_ESCR_T0_USR | P4_ESCR_T1_OS \     P4_ESCR_T1_USR)
end_define

begin_define
define|#
directive|define
name|P4_PERFCTR_MASK
value|0xFFFFFFFFFFLL
end_define

begin_comment
comment|/* 40 bits */
end_comment

begin_define
define|#
directive|define
name|P4_CCCR_MSR_FIRST
value|0x360
end_define

begin_comment
comment|/* MSR_BPU_CCCR0 */
end_comment

begin_define
define|#
directive|define
name|P4_PERFCTR_MSR_FIRST
value|0x300
end_define

begin_comment
comment|/* MSR_BPU_COUNTER0 */
end_comment

begin_define
define|#
directive|define
name|P4_RELOAD_COUNT_TO_PERFCTR_VALUE
parameter_list|(
name|V
parameter_list|)
value|(1 - (V))
end_define

begin_define
define|#
directive|define
name|P4_PERFCTR_VALUE_TO_RELOAD_COUNT
parameter_list|(
name|P
parameter_list|)
value|(1 - (P))
end_define

begin_comment
comment|/* Intel PPro, Celeron, P-II, P-III, Pentium-M PMCS */
end_comment

begin_define
define|#
directive|define
name|P6_NPMCS
value|3
end_define

begin_comment
comment|/* 1 TSC + 2 PMCs */
end_comment

begin_define
define|#
directive|define
name|P6_EVSEL_CMASK_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_TO_CMASK
parameter_list|(
name|C
parameter_list|)
value|(((C)& 0xFF)<< 24)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_INV
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_EN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_INT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_PC
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_E
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_OS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_USR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_UMASK_MASK
value|0x0000FF00
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_TO_UMASK
parameter_list|(
name|U
parameter_list|)
value|(((U)& 0xFF)<< 8)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_EVENT_SELECT
parameter_list|(
name|ES
parameter_list|)
value|((ES)& 0xFF)
end_define

begin_define
define|#
directive|define
name|P6_EVSEL_RESERVED
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|P6_MSR_EVSEL0
value|0x0186
end_define

begin_define
define|#
directive|define
name|P6_MSR_EVSEL1
value|0x0187
end_define

begin_define
define|#
directive|define
name|P6_MSR_PERFCTR0
value|0x00C1
end_define

begin_define
define|#
directive|define
name|P6_MSR_PERFCTR1
value|0x00C2
end_define

begin_define
define|#
directive|define
name|P6_PERFCTR_MASK
value|0xFFFFFFFFFFLL
end_define

begin_comment
comment|/* 40 bits */
end_comment

begin_comment
comment|/* Intel Pentium PMCs */
end_comment

begin_define
define|#
directive|define
name|PENTIUM_NPMCS
value|3
end_define

begin_comment
comment|/* 1 TSC + 2 PMCs */
end_comment

begin_define
define|#
directive|define
name|PENTIUM_CESR_PC1
value|(1<< 25)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_CC1_MASK
value|0x01C00000
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_TO_CC1
parameter_list|(
name|C
parameter_list|)
value|(((C)& 0x07)<< 22)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_ES1_MASK
value|0x003F0000
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_TO_ES1
parameter_list|(
name|E
parameter_list|)
value|(((E)& 0x3F)<< 16)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_PC0
value|(1<< 9)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_CC0_MASK
value|0x000001C0
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_TO_CC0
parameter_list|(
name|C
parameter_list|)
value|(((C)& 0x07)<< 6)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_ES0_MASK
value|0x0000003F
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_TO_ES0
parameter_list|(
name|E
parameter_list|)
value|((E)& 0x3F)
end_define

begin_define
define|#
directive|define
name|PENTIUM_CESR_RESERVED
value|0xFC00FC00
end_define

begin_define
define|#
directive|define
name|PENTIUM_MSR_CESR
value|0x11
end_define

begin_define
define|#
directive|define
name|PENTIUM_MSR_CTR0
value|0x12
end_define

begin_define
define|#
directive|define
name|PENTIUM_MSR_CTR1
value|0x13
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Prototypes  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_function_decl
name|struct
name|pmc_mdep
modifier|*
name|pmc_amd_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* AMD K7/K8 PMCs */
end_comment

begin_function_decl
name|struct
name|pmc_mdep
modifier|*
name|pmc_intel_initialize
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Intel PMCs */
end_comment

begin_function_decl
name|int
name|pmc_initialize_p4
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pentium IV PMCs */
end_comment

begin_function_decl
name|int
name|pmc_initialize_p5
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pentium PMCs */
end_comment

begin_function_decl
name|int
name|pmc_initialize_p6
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Pentium Pro PMCs */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined(__i386__) */
end_comment

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
comment|/* _MACHINE_PMC_MDEP_H */
end_comment

end_unit

