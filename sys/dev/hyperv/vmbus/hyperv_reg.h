begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2016 Microsoft Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HYPERV_REG_H_
end_ifndef

begin_define
define|#
directive|define
name|_HYPERV_REG_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/*  * Hyper-V Synthetic MSRs  */
end_comment

begin_define
define|#
directive|define
name|MSR_HV_GUEST_OS_ID
value|0x40000000
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_BUILD_MASK
value|0xffffULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_VERSION_MASK
value|0x0000ffffffff0000ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_VERSION_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_OSID_MASK
value|0x00ff000000000000ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_OSID_SHIFT
value|48
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_OSTYPE_MASK
value|0x7f00000000000000ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_OSTYPE_SHIFT
value|56
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_OPENSRC
value|0x8000000000000000ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_OSTYPE_LINUX
define|\
value|((0x01ULL<< MSR_HV_GUESTID_OSTYPE_SHIFT) | MSR_HV_GUESTID_OPENSRC)
end_define

begin_define
define|#
directive|define
name|MSR_HV_GUESTID_OSTYPE_FREEBSD
define|\
value|((0x02ULL<< MSR_HV_GUESTID_OSTYPE_SHIFT) | MSR_HV_GUESTID_OPENSRC)
end_define

begin_define
define|#
directive|define
name|MSR_HV_HYPERCALL
value|0x40000001
end_define

begin_define
define|#
directive|define
name|MSR_HV_HYPERCALL_ENABLE
value|0x0001ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_HYPERCALL_RSVD_MASK
value|0x0ffeULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_HYPERCALL_PGSHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MSR_HV_VP_INDEX
value|0x40000002
end_define

begin_define
define|#
directive|define
name|MSR_HV_TIME_REF_COUNT
value|0x40000020
end_define

begin_define
define|#
directive|define
name|MSR_HV_SCONTROL
value|0x40000080
end_define

begin_define
define|#
directive|define
name|MSR_HV_SCTRL_ENABLE
value|0x0001ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SCTRL_RSVD_MASK
value|0xfffffffffffffffeULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SIEFP
value|0x40000082
end_define

begin_define
define|#
directive|define
name|MSR_HV_SIEFP_ENABLE
value|0x0001ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SIEFP_RSVD_MASK
value|0x0ffeULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SIEFP_PGSHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MSR_HV_SIMP
value|0x40000083
end_define

begin_define
define|#
directive|define
name|MSR_HV_SIMP_ENABLE
value|0x0001ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SIMP_RSVD_MASK
value|0x0ffeULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SIMP_PGSHIFT
value|12
end_define

begin_define
define|#
directive|define
name|MSR_HV_EOM
value|0x40000084
end_define

begin_define
define|#
directive|define
name|MSR_HV_SINT0
value|0x40000090
end_define

begin_define
define|#
directive|define
name|MSR_HV_SINT_VECTOR_MASK
value|0x00ffULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SINT_RSVD1_MASK
value|0xff00ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SINT_MASKED
value|0x00010000ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SINT_AUTOEOI
value|0x00020000ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SINT_RSVD2_MASK
value|0xfffffffffffc0000ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_SINT_RSVD_MASK
value|(MSR_HV_SINT_RSVD1_MASK |	\ 					 MSR_HV_SINT_RSVD2_MASK)
end_define

begin_define
define|#
directive|define
name|MSR_HV_STIMER0_CONFIG
value|0x400000b0
end_define

begin_define
define|#
directive|define
name|MSR_HV_STIMER_CFG_ENABLE
value|0x0001ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_STIMER_CFG_PERIODIC
value|0x0002ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_STIMER_CFG_LAZY
value|0x0004ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_STIMER_CFG_AUTOEN
value|0x0008ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_STIMER_CFG_SINT_MASK
value|0x000f0000ULL
end_define

begin_define
define|#
directive|define
name|MSR_HV_STIMER_CFG_SINT_SHIFT
value|16
end_define

begin_define
define|#
directive|define
name|MSR_HV_STIMER0_COUNT
value|0x400000b1
end_define

begin_comment
comment|/*  * CPUID leaves  */
end_comment

begin_define
define|#
directive|define
name|CPUID_LEAF_HV_MAXLEAF
value|0x40000000
end_define

begin_define
define|#
directive|define
name|CPUID_LEAF_HV_INTERFACE
value|0x40000001
end_define

begin_define
define|#
directive|define
name|CPUID_HV_IFACE_HYPERV
value|0x31237648
end_define

begin_comment
comment|/* HV#1 */
end_comment

begin_define
define|#
directive|define
name|CPUID_LEAF_HV_IDENTITY
value|0x40000002
end_define

begin_define
define|#
directive|define
name|CPUID_LEAF_HV_FEATURES
value|0x40000003
end_define

begin_comment
comment|/* EAX: features */
end_comment

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
name|CPUID_HV_MSR_GUEST_IDLE
value|0x0400
end_define

begin_comment
comment|/* MSR_HV_GUEST_IDLE */
end_comment

begin_comment
comment|/* ECX: power management features */
end_comment

begin_define
define|#
directive|define
name|CPUPM_HV_CSTATE_MASK
value|0x000f
end_define

begin_comment
comment|/* deepest C-state */
end_comment

begin_define
define|#
directive|define
name|CPUPM_HV_C3_HPET
value|0x0010
end_define

begin_comment
comment|/* C3 requires HPET */
end_comment

begin_define
define|#
directive|define
name|CPUPM_HV_CSTATE
parameter_list|(
name|f
parameter_list|)
value|((f)& CPUPM_HV_CSTATE_MASK)
end_define

begin_comment
comment|/* EDX: features3 */
end_comment

begin_define
define|#
directive|define
name|CPUID3_HV_MWAIT
value|0x0001
end_define

begin_comment
comment|/* MWAIT */
end_comment

begin_define
define|#
directive|define
name|CPUID3_HV_XMM_HYPERCALL
value|0x0010
end_define

begin_comment
comment|/* Hypercall input through 						 * XMM regs */
end_comment

begin_define
define|#
directive|define
name|CPUID3_HV_GUEST_IDLE
value|0x0020
end_define

begin_comment
comment|/* guest idle */
end_comment

begin_define
define|#
directive|define
name|CPUID3_HV_NUMA
value|0x0080
end_define

begin_comment
comment|/* NUMA distance query */
end_comment

begin_define
define|#
directive|define
name|CPUID3_HV_TIME_FREQ
value|0x0100
end_define

begin_comment
comment|/* timer frequency query 						 * (TSC, LAPIC) */
end_comment

begin_define
define|#
directive|define
name|CPUID3_HV_MSR_CRASH
value|0x0400
end_define

begin_comment
comment|/* MSRs for guest crash */
end_comment

begin_define
define|#
directive|define
name|CPUID_LEAF_HV_RECOMMENDS
value|0x40000004
end_define

begin_define
define|#
directive|define
name|CPUID_LEAF_HV_LIMITS
value|0x40000005
end_define

begin_define
define|#
directive|define
name|CPUID_LEAF_HV_HWFEATURES
value|0x40000006
end_define

begin_comment
comment|/*  * Hyper-V message types  */
end_comment

begin_define
define|#
directive|define
name|HYPERV_MSGTYPE_NONE
value|0
end_define

begin_define
define|#
directive|define
name|HYPERV_MSGTYPE_CHANNEL
value|1
end_define

begin_define
define|#
directive|define
name|HYPERV_MSGTYPE_TIMER_EXPIRED
value|0x80000010
end_define

begin_comment
comment|/*  * Hypercall status codes  */
end_comment

begin_define
define|#
directive|define
name|HYPERCALL_STATUS_SUCCESS
value|0x0000
end_define

begin_comment
comment|/*  * Hypercall input values  */
end_comment

begin_define
define|#
directive|define
name|HYPERCALL_POST_MESSAGE
value|0x005c
end_define

begin_define
define|#
directive|define
name|HYPERCALL_SIGNAL_EVENT
value|0x005d
end_define

begin_comment
comment|/*  * Hypercall input parameters  */
end_comment

begin_define
define|#
directive|define
name|HYPERCALL_PARAM_ALIGN
value|8
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/*  * XXX  *<<Hypervisor Top Level Functional Specification 4.0b>> requires  * input parameters size to be multiple of 8, however, many post  * message input parameters do _not_ meet this requirement.  */
end_comment

begin_define
define|#
directive|define
name|HYPERCALL_PARAM_SIZE_ALIGN
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * HYPERCALL_POST_MESSAGE  */
end_comment

begin_define
define|#
directive|define
name|HYPERCALL_POSTMSGIN_DSIZE_MAX
value|240
end_define

begin_define
define|#
directive|define
name|HYPERCALL_POSTMSGIN_SIZE
value|256
end_define

begin_struct
struct|struct
name|hypercall_postmsg_in
block|{
name|uint32_t
name|hc_connid
decl_stmt|;
name|uint32_t
name|hc_rsvd
decl_stmt|;
name|uint32_t
name|hc_msgtype
decl_stmt|;
comment|/* HYPERV_MSGTYPE_ */
name|uint32_t
name|hc_dsize
decl_stmt|;
name|uint8_t
name|hc_data
index|[
name|HYPERCALL_POSTMSGIN_DSIZE_MAX
index|]
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|hypercall_postmsg_in
argument_list|)
operator|==
name|HYPERCALL_POSTMSGIN_SIZE
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * HYPERCALL_SIGNAL_EVENT  */
end_comment

begin_struct
struct|struct
name|hypercall_sigevt_in
block|{
name|uint32_t
name|hc_connid
decl_stmt|;
name|uint16_t
name|hc_evtflag_ofs
decl_stmt|;
name|uint16_t
name|hc_rsvd
decl_stmt|;
block|}
name|__packed
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_HYPERV_REG_H_ */
end_comment

end_unit

