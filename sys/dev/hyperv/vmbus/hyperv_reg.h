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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_HYPERV_REG_H_ */
end_comment

end_unit

