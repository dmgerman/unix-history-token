begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMX_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMX_H_
end_define

begin_include
include|#
directive|include
file|"vmcs.h"
end_include

begin_struct_decl
struct_decl|struct
name|pmap
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|GUEST_MSR_MAX_ENTRIES
value|64
end_define

begin_comment
comment|/* arbitrary */
end_comment

begin_struct
struct|struct
name|vmxctx
block|{
name|register_t
name|tmpstk
index|[
literal|32
index|]
decl_stmt|;
comment|/* vmx_return() stack */
name|register_t
name|tmpstktop
decl_stmt|;
name|register_t
name|guest_rdi
decl_stmt|;
comment|/* Guest state */
name|register_t
name|guest_rsi
decl_stmt|;
name|register_t
name|guest_rdx
decl_stmt|;
name|register_t
name|guest_rcx
decl_stmt|;
name|register_t
name|guest_r8
decl_stmt|;
name|register_t
name|guest_r9
decl_stmt|;
name|register_t
name|guest_rax
decl_stmt|;
name|register_t
name|guest_rbx
decl_stmt|;
name|register_t
name|guest_rbp
decl_stmt|;
name|register_t
name|guest_r10
decl_stmt|;
name|register_t
name|guest_r11
decl_stmt|;
name|register_t
name|guest_r12
decl_stmt|;
name|register_t
name|guest_r13
decl_stmt|;
name|register_t
name|guest_r14
decl_stmt|;
name|register_t
name|guest_r15
decl_stmt|;
name|register_t
name|guest_cr2
decl_stmt|;
name|register_t
name|host_r15
decl_stmt|;
comment|/* Host state */
name|register_t
name|host_r14
decl_stmt|;
name|register_t
name|host_r13
decl_stmt|;
name|register_t
name|host_r12
decl_stmt|;
name|register_t
name|host_rbp
decl_stmt|;
name|register_t
name|host_rsp
decl_stmt|;
name|register_t
name|host_rbx
decl_stmt|;
name|register_t
name|host_rip
decl_stmt|;
comment|/* 	 * XXX todo debug registers and fpu state 	 */
name|int
name|launched
decl_stmt|;
comment|/* vmcs launch state */
name|int
name|launch_error
decl_stmt|;
name|long
name|eptgen
index|[
name|MAXCPU
index|]
decl_stmt|;
comment|/* cached pmap->pm_eptgen */
comment|/* 	 * The 'eptp' and the 'pmap' do not change during the lifetime of 	 * the VM so it is safe to keep a copy in each vcpu's vmxctx. 	 */
name|vm_paddr_t
name|eptp
decl_stmt|;
name|struct
name|pmap
modifier|*
name|pmap
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxcap
block|{
name|int
name|set
decl_stmt|;
name|uint32_t
name|proc_ctls
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|vmxstate
block|{
name|int
name|lastcpu
decl_stmt|;
comment|/* host cpu that this 'vcpu' last ran on */
name|uint16_t
name|vpid
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* virtual machine softc */
end_comment

begin_struct
struct|struct
name|vmx
block|{
name|struct
name|vmcs
name|vmcs
index|[
name|VM_MAXCPU
index|]
decl_stmt|;
comment|/* one vmcs per virtual cpu */
name|char
name|msr_bitmap
index|[
name|PAGE_SIZE
index|]
decl_stmt|;
name|struct
name|msr_entry
name|guest_msrs
index|[
name|VM_MAXCPU
index|]
index|[
name|GUEST_MSR_MAX_ENTRIES
index|]
decl_stmt|;
name|struct
name|vmxctx
name|ctx
index|[
name|VM_MAXCPU
index|]
decl_stmt|;
name|struct
name|vmxcap
name|cap
index|[
name|VM_MAXCPU
index|]
decl_stmt|;
name|struct
name|vmxstate
name|state
index|[
name|VM_MAXCPU
index|]
decl_stmt|;
name|uint64_t
name|eptp
decl_stmt|;
name|struct
name|vm
modifier|*
name|vm
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
operator|(
name|offsetof
argument_list|(
expr|struct
name|vmx
argument_list|,
name|vmcs
argument_list|)
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
operator|(
name|offsetof
argument_list|(
expr|struct
name|vmx
argument_list|,
name|msr_bitmap
argument_list|)
operator|&
name|PAGE_MASK
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|CTASSERT
argument_list|(
operator|(
name|offsetof
argument_list|(
expr|struct
name|vmx
argument_list|,
name|guest_msrs
argument_list|)
operator|&
literal|15
operator|)
operator|==
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|VMX_RETURN_DIRECT
value|0
end_define

begin_define
define|#
directive|define
name|VMX_RETURN_LONGJMP
value|1
end_define

begin_define
define|#
directive|define
name|VMX_RETURN_VMRESUME
value|2
end_define

begin_define
define|#
directive|define
name|VMX_RETURN_VMLAUNCH
value|3
end_define

begin_define
define|#
directive|define
name|VMX_RETURN_AST
value|4
end_define

begin_define
define|#
directive|define
name|VMX_RETURN_INVEPT
value|5
end_define

begin_comment
comment|/*  * vmx_setjmp() returns:  * - 0 when it returns directly  * - 1 when it returns from vmx_longjmp  * - 2 when it returns from vmx_resume (which would only be in the error case)  * - 3 when it returns from vmx_launch (which would only be in the error case)  * - 4 when it returns from vmx_resume or vmx_launch because of AST pending  * - 5 when it returns from vmx_launch/vmx_resume because of invept error  */
end_comment

begin_function_decl
name|int
name|vmx_setjmp
parameter_list|(
name|struct
name|vmxctx
modifier|*
name|ctx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vmx_longjmp
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* returns via vmx_setjmp */
end_comment

begin_decl_stmt
name|void
name|vmx_launch
argument_list|(
expr|struct
name|vmxctx
operator|*
name|ctx
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* may return via vmx_setjmp */
end_comment

begin_decl_stmt
name|void
name|vmx_resume
argument_list|(
expr|struct
name|vmxctx
operator|*
name|ctx
argument_list|)
name|__dead2
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* may return via vmx_setjmp */
end_comment

begin_function_decl
name|u_long
name|vmx_fix_cr0
parameter_list|(
name|u_long
name|cr0
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|u_long
name|vmx_fix_cr4
parameter_list|(
name|u_long
name|cr4
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

