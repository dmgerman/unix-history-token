begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2005, Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* Machine dependent interfaces */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_HWPMC_AMD_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_HWPMC_AMD_H_
value|1
end_define

begin_comment
comment|/* AMD K7 and K8 PMCs */
end_comment

begin_define
define|#
directive|define
name|AMD_PMC_EVSEL_0
value|0xC0010000
end_define

begin_define
define|#
directive|define
name|AMD_PMC_EVSEL_1
value|0xC0010001
end_define

begin_define
define|#
directive|define
name|AMD_PMC_EVSEL_2
value|0xC0010002
end_define

begin_define
define|#
directive|define
name|AMD_PMC_EVSEL_3
value|0xC0010003
end_define

begin_define
define|#
directive|define
name|AMD_PMC_PERFCTR_0
value|0xC0010004
end_define

begin_define
define|#
directive|define
name|AMD_PMC_PERFCTR_1
value|0xC0010005
end_define

begin_define
define|#
directive|define
name|AMD_PMC_PERFCTR_2
value|0xC0010006
end_define

begin_define
define|#
directive|define
name|AMD_PMC_PERFCTR_3
value|0xC0010007
end_define

begin_define
define|#
directive|define
name|AMD_NPMCS
value|5
end_define

begin_comment
comment|/* 1 TSC + 4 PMCs */
end_comment

begin_define
define|#
directive|define
name|AMD_PMC_COUNTERMASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|AMD_PMC_TO_COUNTER
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 24)& AMD_PMC_COUNTERMASK)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_INVERT
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_ENABLE
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_INT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_PC
value|(1<< 19)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_EDGE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_OS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_USR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_UNITMASK_M
value|0x10
end_define

begin_define
define|#
directive|define
name|AMD_PMC_UNITMASK_O
value|0x08
end_define

begin_define
define|#
directive|define
name|AMD_PMC_UNITMASK_E
value|0x04
end_define

begin_define
define|#
directive|define
name|AMD_PMC_UNITMASK_S
value|0x02
end_define

begin_define
define|#
directive|define
name|AMD_PMC_UNITMASK_I
value|0x01
end_define

begin_define
define|#
directive|define
name|AMD_PMC_UNITMASK_MOESI
value|0x1F
end_define

begin_define
define|#
directive|define
name|AMD_PMC_UNITMASK
value|0xFF00
end_define

begin_define
define|#
directive|define
name|AMD_PMC_EVENTMASK
value|0x00FF
end_define

begin_define
define|#
directive|define
name|AMD_PMC_TO_UNITMASK
parameter_list|(
name|x
parameter_list|)
value|(((x)<< 8)& AMD_PMC_UNITMASK)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_TO_EVENTMASK
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xFF)
end_define

begin_define
define|#
directive|define
name|AMD_VALID_BITS
value|(AMD_PMC_COUNTERMASK | AMD_PMC_INVERT |	\ 	AMD_PMC_ENABLE | AMD_PMC_INT | AMD_PMC_PC | AMD_PMC_EDGE | 	\ 	AMD_PMC_OS | AMD_PMC_USR | AMD_PMC_UNITMASK | AMD_PMC_EVENTMASK)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_CAPS
value|(PMC_CAP_INTERRUPT | PMC_CAP_USER | 	\ 	PMC_CAP_SYSTEM | PMC_CAP_EDGE | PMC_CAP_THRESHOLD | 		\ 	PMC_CAP_READ | PMC_CAP_WRITE | PMC_CAP_INVERT | PMC_CAP_QUALIFIER)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_IS_STOPPED
parameter_list|(
name|evsel
parameter_list|)
value|((rdmsr((evsel))& AMD_PMC_ENABLE) == 0)
end_define

begin_define
define|#
directive|define
name|AMD_PMC_HAS_OVERFLOWED
parameter_list|(
name|pmc
parameter_list|)
value|((rdpmc(pmc)& (1ULL<< 47)) == 0)
end_define

begin_define
define|#
directive|define
name|AMD_RELOAD_COUNT_TO_PERFCTR_VALUE
parameter_list|(
name|V
parameter_list|)
value|(-(V))
end_define

begin_define
define|#
directive|define
name|AMD_PERFCTR_VALUE_TO_RELOAD_COUNT
parameter_list|(
name|P
parameter_list|)
value|(-(P))
end_define

begin_struct
struct|struct
name|pmc_md_amd_op_pmcallocate
block|{
name|uint32_t
name|pm_amd_config
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/* MD extension for 'struct pmc' */
end_comment

begin_struct
struct|struct
name|pmc_md_amd_pmc
block|{
name|uint32_t
name|pm_amd_evsel
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Prototypes  */
end_comment

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
comment|/* _DEV_HWPMC_AMD_H_ */
end_comment

end_unit

