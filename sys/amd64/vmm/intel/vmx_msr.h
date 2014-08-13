begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMX_MSR_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMX_MSR_H_
end_define

begin_function_decl
name|uint32_t
name|vmx_revision
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vmx_set_ctlreg
parameter_list|(
name|int
name|ctl_reg
parameter_list|,
name|int
name|true_ctl_reg
parameter_list|,
name|uint32_t
name|ones_mask
parameter_list|,
name|uint32_t
name|zeros_mask
parameter_list|,
name|uint32_t
modifier|*
name|retval
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * According to Section 21.10.4 "Software Access to Related Structures",  * changes to data structures pointed to by the VMCS must be made only when  * there is no logical processor with a current VMCS that points to the  * data structure.  *  * This pretty much limits us to configuring the MSR bitmap before VMCS  * initialization for SMP VMs. Unless of course we do it the hard way - which  * would involve some form of synchronization between the vcpus to vmclear  * all VMCSs' that point to the bitmap.  */
end_comment

begin_define
define|#
directive|define
name|MSR_BITMAP_ACCESS_NONE
value|0x0
end_define

begin_define
define|#
directive|define
name|MSR_BITMAP_ACCESS_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|MSR_BITMAP_ACCESS_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|MSR_BITMAP_ACCESS_RW
value|(MSR_BITMAP_ACCESS_READ|MSR_BITMAP_ACCESS_WRITE)
end_define

begin_function_decl
name|void
name|msr_bitmap_initialize
parameter_list|(
name|char
modifier|*
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|msr_bitmap_change_access
parameter_list|(
name|char
modifier|*
name|bitmap
parameter_list|,
name|u_int
name|msr
parameter_list|,
name|int
name|access
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

