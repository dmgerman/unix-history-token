begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMM_KTR_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMM_KTR_H_
end_define

begin_include
include|#
directive|include
file|<sys/ktr.h>
end_include

begin_include
include|#
directive|include
file|<sys/pcpu.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|KTR_VMM
end_ifndef

begin_define
define|#
directive|define
name|KTR_VMM
value|KTR_GEN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|VCPU_CTR0
parameter_list|(
name|vm
parameter_list|,
name|vcpuid
parameter_list|,
name|format
parameter_list|)
define|\
value|CTR2(KTR_VMM, "vm %s[%d]: " format, vm_name((vm)), (vcpuid))
end_define

begin_define
define|#
directive|define
name|VCPU_CTR1
parameter_list|(
name|vm
parameter_list|,
name|vcpuid
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|)
define|\
value|CTR3(KTR_VMM, "vm %s[%d]: " format, vm_name((vm)), (vcpuid), (p1))
end_define

begin_define
define|#
directive|define
name|VCPU_CTR2
parameter_list|(
name|vm
parameter_list|,
name|vcpuid
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|CTR4(KTR_VMM, "vm %s[%d]: " format, vm_name((vm)), (vcpuid), (p1), (p2))
end_define

begin_define
define|#
directive|define
name|VCPU_CTR3
parameter_list|(
name|vm
parameter_list|,
name|vcpuid
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
define|\
value|CTR5(KTR_VMM, "vm %s[%d]: " format, vm_name((vm)), (vcpuid), (p1), (p2), (p3))
end_define

begin_define
define|#
directive|define
name|VCPU_CTR4
parameter_list|(
name|vm
parameter_list|,
name|vcpuid
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
define|\
value|CTR6(KTR_VMM, "vm %s[%d]: " format, vm_name((vm)), (vcpuid),		\     (p1), (p2), (p3), (p4))
end_define

begin_define
define|#
directive|define
name|VM_CTR0
parameter_list|(
name|vm
parameter_list|,
name|format
parameter_list|)
define|\
value|CTR1(KTR_VMM, "vm %s: " format, vm_name((vm)))
end_define

begin_define
define|#
directive|define
name|VM_CTR1
parameter_list|(
name|vm
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|)
define|\
value|CTR2(KTR_VMM, "vm %s: " format, vm_name((vm)), (p1))
end_define

begin_define
define|#
directive|define
name|VM_CTR2
parameter_list|(
name|vm
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|)
define|\
value|CTR3(KTR_VMM, "vm %s: " format, vm_name((vm)), (p1), (p2))
end_define

begin_define
define|#
directive|define
name|VM_CTR3
parameter_list|(
name|vm
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|)
define|\
value|CTR4(KTR_VMM, "vm %s: " format, vm_name((vm)), (p1), (p2), (p3))
end_define

begin_define
define|#
directive|define
name|VM_CTR4
parameter_list|(
name|vm
parameter_list|,
name|format
parameter_list|,
name|p1
parameter_list|,
name|p2
parameter_list|,
name|p3
parameter_list|,
name|p4
parameter_list|)
define|\
value|CTR5(KTR_VMM, "vm %s: " format, vm_name((vm)), (p1), (p2), (p3), (p4))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

