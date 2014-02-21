begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_X86_H_
end_ifndef

begin_define
define|#
directive|define
name|_X86_H_
end_define

begin_define
define|#
directive|define
name|CPUID_0000_0000
value|(0x0)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_0001
value|(0x1)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_0002
value|(0x2)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_0003
value|(0x3)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_0004
value|(0x4)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_0006
value|(0x6)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_0007
value|(0x7)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_000A
value|(0xA)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_000B
value|(0xB)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_000D
value|(0xD)
end_define

begin_define
define|#
directive|define
name|CPUID_8000_0000
value|(0x80000000)
end_define

begin_define
define|#
directive|define
name|CPUID_8000_0001
value|(0x80000001)
end_define

begin_define
define|#
directive|define
name|CPUID_8000_0002
value|(0x80000002)
end_define

begin_define
define|#
directive|define
name|CPUID_8000_0003
value|(0x80000003)
end_define

begin_define
define|#
directive|define
name|CPUID_8000_0004
value|(0x80000004)
end_define

begin_define
define|#
directive|define
name|CPUID_8000_0006
value|(0x80000006)
end_define

begin_define
define|#
directive|define
name|CPUID_8000_0007
value|(0x80000007)
end_define

begin_define
define|#
directive|define
name|CPUID_8000_0008
value|(0x80000008)
end_define

begin_comment
comment|/*  * CPUID instruction Fn0000_0001:  */
end_comment

begin_define
define|#
directive|define
name|CPUID_0000_0001_APICID_MASK
value|(0xff<<24)
end_define

begin_define
define|#
directive|define
name|CPUID_0000_0001_APICID_SHIFT
value|24
end_define

begin_comment
comment|/*  * CPUID instruction Fn0000_0001 ECX  */
end_comment

begin_define
define|#
directive|define
name|CPUID_0000_0001_FEAT0_VMX
value|(1<<5)
end_define

begin_function_decl
name|int
name|x86_emulate_cpuid
parameter_list|(
name|struct
name|vm
modifier|*
name|vm
parameter_list|,
name|int
name|vcpu_id
parameter_list|,
name|uint32_t
modifier|*
name|eax
parameter_list|,
name|uint32_t
modifier|*
name|ebx
parameter_list|,
name|uint32_t
modifier|*
name|ecx
parameter_list|,
name|uint32_t
modifier|*
name|edx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

