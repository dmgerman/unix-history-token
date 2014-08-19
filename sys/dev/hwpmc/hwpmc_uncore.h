begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Fabien Thomas  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_HWPMC_UNCORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_HWPMC_UNCORE_H_
value|1
end_define

begin_comment
comment|/*  * Fixed-function PMCs.  */
end_comment

begin_struct
struct|struct
name|pmc_md_ucf_op_pmcallocate
block|{
name|uint16_t
name|pm_ucf_flags
decl_stmt|;
comment|/* additional flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UCF_EN
value|0x1
end_define

begin_define
define|#
directive|define
name|UCF_PMI
value|0x4
end_define

begin_comment
comment|/*  * Programmable PMCs.  */
end_comment

begin_struct
struct|struct
name|pmc_md_ucp_op_pmcallocate
block|{
name|uint32_t
name|pm_ucp_config
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UCP_EVSEL
parameter_list|(
name|C
parameter_list|)
value|((C)& 0xFF)
end_define

begin_define
define|#
directive|define
name|UCP_UMASK
parameter_list|(
name|C
parameter_list|)
value|((C)& 0xFF00)
end_define

begin_define
define|#
directive|define
name|UCP_CTRR
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|UCP_EDGE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|UCP_INT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|UCP_EN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|UCP_INV
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|UCP_CMASK
parameter_list|(
name|C
parameter_list|)
value|(((C)& 0xFF)<< 24)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|DCTL_FLAG_UNC_PMI
value|(1ULL<< 13)
end_define

begin_comment
comment|/*  * Fixed-function counters.  */
end_comment

begin_define
define|#
directive|define
name|UCF_MASK
value|0xF
end_define

begin_define
define|#
directive|define
name|UCF_CTR0
value|0x394
end_define

begin_define
define|#
directive|define
name|UCF_OFFSET
value|32
end_define

begin_define
define|#
directive|define
name|UCF_OFFSET_SB
value|29
end_define

begin_define
define|#
directive|define
name|UCF_CTRL
value|0x395
end_define

begin_comment
comment|/*  * Programmable counters.  */
end_comment

begin_define
define|#
directive|define
name|UCP_PMC0
value|0x3B0
end_define

begin_define
define|#
directive|define
name|UCP_EVSEL0
value|0x3C0
end_define

begin_define
define|#
directive|define
name|UCP_OPCODE_MATCH
value|0x396
end_define

begin_define
define|#
directive|define
name|UCP_CB0_EVSEL0
value|0x700
end_define

begin_comment
comment|/*  * Simplified programming interface in Intel Performance Architecture  * v2 and later.  */
end_comment

begin_define
define|#
directive|define
name|UC_GLOBAL_STATUS
value|0x392
end_define

begin_define
define|#
directive|define
name|UC_GLOBAL_CTRL
value|0x391
end_define

begin_define
define|#
directive|define
name|UC_GLOBAL_OVF_CTRL
value|0x393
end_define

begin_define
define|#
directive|define
name|UC_GLOBAL_STATUS_FLAG_CLRCHG
value|(1ULL<< 63)
end_define

begin_define
define|#
directive|define
name|UC_GLOBAL_STATUS_FLAG_OVFPMI
value|(1ULL<< 61)
end_define

begin_define
define|#
directive|define
name|UC_GLOBAL_CTRL_FLAG_FRZ
value|(1ULL<< 63)
end_define

begin_define
define|#
directive|define
name|UC_GLOBAL_CTRL_FLAG_ENPMICORE0
value|(1ULL<< 48)
end_define

begin_comment
comment|/*  * Model specific registers.  */
end_comment

begin_define
define|#
directive|define
name|MSR_GQ_SNOOP_MESF
value|0x301
end_define

begin_struct
struct|struct
name|pmc_md_ucf_pmc
block|{
name|uint64_t
name|pm_ucf_ctrl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmc_md_ucp_pmc
block|{
name|uint32_t
name|pm_ucp_evsel
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Prototypes.  */
end_comment

begin_function_decl
name|int
name|pmc_uncore_initialize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|,
name|int
name|_maxcpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_uncore_finalize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_ucf_initialize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|,
name|int
name|_maxcpu
parameter_list|,
name|int
name|_npmc
parameter_list|,
name|int
name|_width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_ucf_finalize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|pmc_ucp_initialize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
parameter_list|,
name|int
name|_maxcpu
parameter_list|,
name|int
name|_npmc
parameter_list|,
name|int
name|_width
parameter_list|,
name|int
name|_flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_ucp_finalize
parameter_list|(
name|struct
name|pmc_mdep
modifier|*
name|_md
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
comment|/* _DEV_HWPMC_UNCORE_H */
end_comment

end_unit

