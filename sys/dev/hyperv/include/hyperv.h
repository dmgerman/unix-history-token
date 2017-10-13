begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2009-2012,2016-2017 Microsoft Corp.  * Copyright (c) 2012 NetApp Inc.  * Copyright (c) 2012 Citrix Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HYPERV_H_
end_ifndef

begin_define
define|#
directive|define
name|_HYPERV_H_
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_define
define|#
directive|define
name|MSR_HV_TIME_REF_COUNT
value|0x40000020
end_define

begin_define
define|#
directive|define
name|CPUID_HV_MSR_TIME_REFCNT
value|0x0002
end_define

begin_comment
comment|/* MSR_HV_TIME_REF_COUNT */
end_comment

begin_define
define|#
directive|define
name|CPUID_HV_MSR_SYNIC
value|0x0004
end_define

begin_comment
comment|/* MSRs for SynIC */
end_comment

begin_define
define|#
directive|define
name|CPUID_HV_MSR_SYNTIMER
value|0x0008
end_define

begin_comment
comment|/* MSRs for SynTimer */
end_comment

begin_define
define|#
directive|define
name|CPUID_HV_MSR_APIC
value|0x0010
end_define

begin_comment
comment|/* MSR_HV_{EOI,ICR,TPR} */
end_comment

begin_define
define|#
directive|define
name|CPUID_HV_MSR_HYPERCALL
value|0x0020
end_define

begin_comment
comment|/* MSR_HV_GUEST_OS_ID 						 * MSR_HV_HYPERCALL */
end_comment

begin_define
define|#
directive|define
name|CPUID_HV_MSR_VP_INDEX
value|0x0040
end_define

begin_comment
comment|/* MSR_HV_VP_INDEX */
end_comment

begin_define
define|#
directive|define
name|CPUID_HV_MSR_REFERENCE_TSC
value|0x0200
end_define

begin_comment
comment|/* MSR_HV_REFERENCE_TSC */
end_comment

begin_define
define|#
directive|define
name|CPUID_HV_MSR_GUEST_IDLE
value|0x0400
end_define

begin_comment
comment|/* MSR_HV_GUEST_IDLE */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NANOSEC
end_ifndef

begin_define
define|#
directive|define
name|NANOSEC
value|1000000000ULL
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HYPERV_TIMER_NS_FACTOR
value|100ULL
end_define

begin_define
define|#
directive|define
name|HYPERV_TIMER_FREQ
value|(NANOSEC / HYPERV_TIMER_NS_FACTOR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_define
define|#
directive|define
name|HYPERV_REFTSC_DEVNAME
value|"hv_tsc"
end_define

begin_comment
comment|/*  * Hyper-V Reference TSC  */
end_comment

begin_struct
struct|struct
name|hyperv_reftsc
block|{
specifier|volatile
name|uint32_t
name|tsc_seq
decl_stmt|;
specifier|volatile
name|uint32_t
name|tsc_rsvd1
decl_stmt|;
specifier|volatile
name|uint64_t
name|tsc_scale
decl_stmt|;
specifier|volatile
name|int64_t
name|tsc_ofs
decl_stmt|;
block|}
name|__packed
name|__aligned
argument_list|(
name|PAGE_SIZE
argument_list|)
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CTASSERT
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|hyperv_reftsc
argument_list|)
operator|==
name|PAGE_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_struct
struct|struct
name|hyperv_guid
block|{
name|uint8_t
name|hv_guid
index|[
literal|16
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_define
define|#
directive|define
name|HYPERV_GUID_STRLEN
value|40
end_define

begin_typedef
typedef|typedef
name|uint64_t
function_decl|(
modifier|*
name|hyperv_tc64_t
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_typedef

begin_function_decl
name|int
name|hyperv_guid2str
parameter_list|(
specifier|const
name|struct
name|hyperv_guid
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * hyperv_tc64 could be NULL, if there were no suitable Hyper-V  * specific timecounter.  */
end_comment

begin_decl_stmt
specifier|extern
name|hyperv_tc64_t
name|hyperv_tc64
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_int
name|hyperv_features
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* CPUID_HV_MSR_ */
end_comment

begin_decl_stmt
specifier|extern
name|u_int
name|hyperv_ver_major
decl_stmt|;
end_decl_stmt

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
comment|/* _HYPERV_H_ */
end_comment

end_unit

