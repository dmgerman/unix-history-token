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
name|_DEV_HWPMC_PPRO_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_HWPMC_PPRO_H_
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
name|P6_PERFCTR_READ_MASK
value|0xFFFFFFFFFFLL
end_define

begin_comment
comment|/* 40 bits */
end_comment

begin_define
define|#
directive|define
name|P6_PERFCTR_WRITE_MASK
value|0xFFFFFFFFU
end_define

begin_comment
comment|/* 32 bits */
end_comment

begin_define
define|#
directive|define
name|P6_RELOAD_COUNT_TO_PERFCTR_VALUE
parameter_list|(
name|R
parameter_list|)
value|(-(R))
end_define

begin_define
define|#
directive|define
name|P6_PERFCTR_VALUE_TO_RELOAD_COUNT
parameter_list|(
name|P
parameter_list|)
value|(-(P))
end_define

begin_define
define|#
directive|define
name|P6_PMC_HAS_OVERFLOWED
parameter_list|(
name|P
parameter_list|)
value|((rdpmc(P)& (1LL<< 39)) == 0)
end_define

begin_struct
struct|struct
name|pmc_md_ppro_op_pmcallocate
block|{
name|uint32_t
name|pm_ppro_config
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
name|pmc_md_ppro_pmc
block|{
name|uint32_t
name|pm_ppro_evsel
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Prototypes  */
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
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _DEV_HWPMC_PPRO_H_ */
end_comment

end_unit

