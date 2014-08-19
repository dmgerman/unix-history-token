begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2008 Joseph Koshy  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_HWPMC_CORE_H_
end_ifndef

begin_define
define|#
directive|define
name|_DEV_HWPMC_CORE_H_
value|1
end_define

begin_comment
comment|/*  * Fixed-function PMCs.  */
end_comment

begin_struct
struct|struct
name|pmc_md_iaf_op_pmcallocate
block|{
name|uint16_t
name|pm_iaf_flags
decl_stmt|;
comment|/* additional flags */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IAF_OS
value|0x1
end_define

begin_define
define|#
directive|define
name|IAF_USR
value|0x2
end_define

begin_define
define|#
directive|define
name|IAF_ANY
value|0x4
end_define

begin_define
define|#
directive|define
name|IAF_PMI
value|0x8
end_define

begin_comment
comment|/*  * Programmable PMCs.  */
end_comment

begin_struct
struct|struct
name|pmc_md_iap_op_pmcallocate
block|{
name|uint32_t
name|pm_iap_config
decl_stmt|;
name|uint64_t
name|pm_iap_rsp
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IAP_EVSEL
parameter_list|(
name|C
parameter_list|)
value|((C)& 0xFF)
end_define

begin_define
define|#
directive|define
name|IAP_UMASK
parameter_list|(
name|C
parameter_list|)
value|((C)& 0xFF00)
end_define

begin_define
define|#
directive|define
name|IAP_USR
value|(1<< 16)
end_define

begin_define
define|#
directive|define
name|IAP_OS
value|(1<< 17)
end_define

begin_define
define|#
directive|define
name|IAP_EDGE
value|(1<< 18)
end_define

begin_define
define|#
directive|define
name|IAP_INT
value|(1<< 20)
end_define

begin_define
define|#
directive|define
name|IAP_ANY
value|(1<< 21)
end_define

begin_define
define|#
directive|define
name|IAP_EN
value|(1<< 22)
end_define

begin_define
define|#
directive|define
name|IAP_INV
value|(1<< 23)
end_define

begin_define
define|#
directive|define
name|IAP_CMASK
parameter_list|(
name|C
parameter_list|)
value|(((C)& 0xFF)<< 24)
end_define

begin_define
define|#
directive|define
name|IA_OFFCORE_RSP_MASK_I7WM
value|0x000000F7FF
end_define

begin_define
define|#
directive|define
name|IA_OFFCORE_RSP_MASK_SBIB
value|0x3F807F8FFF
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Fixed-function counters.  */
end_comment

begin_define
define|#
directive|define
name|IAF_MASK
value|0xF
end_define

begin_define
define|#
directive|define
name|IAF_COUNTER_MASK
value|0x0000ffffffffffff
end_define

begin_define
define|#
directive|define
name|IAF_CTR0
value|0x309
end_define

begin_define
define|#
directive|define
name|IAF_CTR1
value|0x30A
end_define

begin_define
define|#
directive|define
name|IAF_CTR2
value|0x30B
end_define

begin_comment
comment|/*  * The IAF_CTRL MSR is laid out in the following way.  *  * Bit Position    Use  * 63 - 12         Reserved (do not touch)  * 11              Ctr 2 PMI  * 10              Reserved (do not touch)  * 9-8             Ctr 2 Enable  * 7               Ctr 1 PMI  * 6               Reserved (do not touch)  * 5-4             Ctr 1 Enable  * 3               Ctr 0 PMI  * 2               Reserved (do not touch)  * 1-0             Ctr 0 Enable (3: All Levels, 2: User, 1: OS, 0: Disable)  */
end_comment

begin_define
define|#
directive|define
name|IAF_OFFSET
value|32
end_define

begin_define
define|#
directive|define
name|IAF_CTRL
value|0x38D
end_define

begin_define
define|#
directive|define
name|IAF_CTRL_MASK
value|0x0000000000000bbb
end_define

begin_comment
comment|/*  * Programmable counters.  */
end_comment

begin_define
define|#
directive|define
name|IAP_PMC0
value|0x0C1
end_define

begin_comment
comment|/*  * IAP_EVSEL(n) is laid out in the following way.  *  * Bit Position    Use  * 63-31           Reserved (do not touch)  * 31-24           Counter Mask  * 23              Invert  * 22              Enable  * 21              Reserved (do not touch)  * 20              APIC Interrupt Enable  * 19              Pin Control  * 18              Edge Detect  * 17              OS  * 16              User  * 15-8            Unit Mask  * 7-0             Event Select  */
end_comment

begin_define
define|#
directive|define
name|IAP_EVSEL_MASK
value|0x00000000ffdfffff
end_define

begin_define
define|#
directive|define
name|IAP_EVSEL0
value|0x186
end_define

begin_comment
comment|/*  * Simplified programming interface in Intel Performance Architecture  * v2 and later.  */
end_comment

begin_define
define|#
directive|define
name|IA_GLOBAL_STATUS
value|0x38E
end_define

begin_define
define|#
directive|define
name|IA_GLOBAL_CTRL
value|0x38F
end_define

begin_comment
comment|/*  * IA_GLOBAL_CTRL is layed out in the following way.  *   * Bit Position    Use  * 63-35           Reserved (do not touch)  * 34              IAF Counter 2 Enable  * 33              IAF Counter 1 Enable  * 32              IAF Counter 0 Enable  * 31-0            Depends on programmable counters  */
end_comment

begin_comment
comment|/* The mask is only for the fixed porttion of the register. */
end_comment

begin_define
define|#
directive|define
name|IAF_GLOBAL_CTRL_MASK
value|0x0000000700000000
end_define

begin_comment
comment|/* The mask is only for the programmable porttion of the register. */
end_comment

begin_define
define|#
directive|define
name|IAP_GLOBAL_CTRL_MASK
value|0x00000000ffffffff
end_define

begin_comment
comment|/* The mask is for both the fixed and programmable porttions of the register. */
end_comment

begin_define
define|#
directive|define
name|IA_GLOBAL_CTRL_MASK
value|0x00000007ffffffff
end_define

begin_define
define|#
directive|define
name|IA_GLOBAL_OVF_CTRL
value|0x390
end_define

begin_define
define|#
directive|define
name|IA_GLOBAL_STATUS_FLAG_CONDCHG
value|(1ULL<< 63)
end_define

begin_define
define|#
directive|define
name|IA_GLOBAL_STATUS_FLAG_OVFBUF
value|(1ULL<< 62)
end_define

begin_comment
comment|/*  * Offcore response configuration.  */
end_comment

begin_define
define|#
directive|define
name|IA_OFFCORE_RSP0
value|0x1A6
end_define

begin_define
define|#
directive|define
name|IA_OFFCORE_RSP1
value|0x1A7
end_define

begin_struct
struct|struct
name|pmc_md_iaf_pmc
block|{
name|uint64_t
name|pm_iaf_ctrl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|pmc_md_iap_pmc
block|{
name|uint32_t
name|pm_iap_evsel
decl_stmt|;
name|uint64_t
name|pm_iap_rsp
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Prototypes.  */
end_comment

begin_function_decl
name|int
name|pmc_core_initialize
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
name|_version_override
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pmc_core_finalize
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
name|pmc_iaf_initialize
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
name|pmc_iaf_finalize
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
name|pmc_iap_initialize
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
name|pmc_iap_finalize
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
comment|/* _DEV_HWPMC_CORE_H */
end_comment

end_unit

