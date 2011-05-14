begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMX_CPUFUNC_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMX_CPUFUNC_H_
end_define

begin_struct_decl
struct_decl|struct
name|vmcs
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * Section 5.2 "Conventions" from Intel Architecture Manual 2B.  *  *			error  * VMsucceed		  0  * VMFailInvalid	  1  * VMFailValid		  2	see also VMCS VM-Instruction Error Field  */
end_comment

begin_define
define|#
directive|define
name|VM_SUCCESS
value|0
end_define

begin_define
define|#
directive|define
name|VM_FAIL_INVALID
value|1
end_define

begin_define
define|#
directive|define
name|VM_FAIL_VALID
value|2
end_define

begin_define
define|#
directive|define
name|VMX_SET_ERROR_CODE
parameter_list|(
name|varname
parameter_list|)
define|\
value|do {								\ 	__asm __volatile("	jnc 1f;"				\ 			 "	mov $1, %0;"
comment|/* CF: error = 1 */
value|\ 			 "	jmp 3f;"				\ 			 "1:	jnz 2f;"				\ 			 "	mov $2, %0;"
comment|/* ZF: error = 2 */
value|\ 			 "	jmp 3f;"				\ 			 "2:	mov $0, %0;"				\ 			 "3:	nop"					\ 			 :"=r" (varname));				\ 	} while (0)
end_define

begin_comment
comment|/* returns 0 on success and non-zero on failure */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vmxon
parameter_list|(
name|char
modifier|*
name|region
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
name|addr
operator|=
name|vtophys
argument_list|(
name|region
argument_list|)
expr_stmt|;
asm|__asm __volatile("vmxon %0" : : "m" (*(uint64_t *)&addr) : "memory");
name|VMX_SET_ERROR_CODE
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_comment
comment|/* returns 0 on success and non-zero on failure */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|vmclear
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
name|addr
operator|=
name|vtophys
argument_list|(
name|vmcs
argument_list|)
expr_stmt|;
asm|__asm __volatile("vmclear %0" : : "m" (*(uint64_t *)&addr) : "memory");
name|VMX_SET_ERROR_CODE
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vmxoff
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm __volatile("vmxoff");
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|vmptrst
parameter_list|(
name|uint64_t
modifier|*
name|addr
parameter_list|)
block|{
asm|__asm __volatile("vmptrst %0" : : "m" (*addr) : "memory");
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|vmptrld
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|uint64_t
name|addr
decl_stmt|;
name|addr
operator|=
name|vtophys
argument_list|(
name|vmcs
argument_list|)
expr_stmt|;
asm|__asm __volatile("vmptrld %0" : : "m" (*(uint64_t *)&addr) : "memory");
name|VMX_SET_ERROR_CODE
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|vmwrite
parameter_list|(
name|uint64_t
name|reg
parameter_list|,
name|uint64_t
name|val
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
asm|__asm __volatile("vmwrite %0, %1" : : "r" (val), "r" (reg) : "memory");
name|VMX_SET_ERROR_CODE
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|vmread
parameter_list|(
name|uint64_t
name|r
parameter_list|,
name|uint64_t
modifier|*
name|addr
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
asm|__asm __volatile("vmread %0, %1" : : "r" (r), "m" (*addr) : "memory");
name|VMX_SET_ERROR_CODE
argument_list|(
name|error
argument_list|)
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|void
name|__inline
name|VMCLEAR
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|)
block|{
name|int
name|err
decl_stmt|;
name|err
operator|=
name|vmclear
argument_list|(
name|vmcs
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"%s: vmclear(%p) error %d"
argument_list|,
name|__func__
argument_list|,
name|vmcs
argument_list|,
name|err
argument_list|)
expr_stmt|;
name|critical_exit
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|void
name|__inline
name|VMPTRLD
parameter_list|(
name|struct
name|vmcs
modifier|*
name|vmcs
parameter_list|)
block|{
name|int
name|err
decl_stmt|;
name|critical_enter
argument_list|()
expr_stmt|;
name|err
operator|=
name|vmptrld
argument_list|(
name|vmcs
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
name|panic
argument_list|(
literal|"%s: vmptrld(%p) error %d"
argument_list|,
name|__func__
argument_list|,
name|vmcs
argument_list|,
name|err
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|INVVPID_TYPE_ADDRESS
value|0UL
end_define

begin_define
define|#
directive|define
name|INVVPID_TYPE_SINGLE_CONTEXT
value|1UL
end_define

begin_define
define|#
directive|define
name|INVVPID_TYPE_ALL_CONTEXTS
value|2UL
end_define

begin_struct
struct|struct
name|invvpid_desc
block|{
name|uint16_t
name|vpid
decl_stmt|;
name|uint16_t
name|_res1
decl_stmt|;
name|uint32_t
name|_res2
decl_stmt|;
name|uint64_t
name|linear_addr
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|invvpid_desc
argument_list|)
operator|==
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|__inline
name|invvpid
parameter_list|(
name|uint64_t
name|type
parameter_list|,
name|struct
name|invvpid_desc
name|desc
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
asm|__asm __volatile("invvpid %0, %1" :: "m" (desc), "r" (type) : "memory");
name|VMX_SET_ERROR_CODE
argument_list|(
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|panic
argument_list|(
literal|"invvpid error %d"
argument_list|,
name|error
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|INVEPT_TYPE_SINGLE_CONTEXT
value|1UL
end_define

begin_define
define|#
directive|define
name|INVEPT_TYPE_ALL_CONTEXTS
value|2UL
end_define

begin_struct
struct|struct
name|invept_desc
block|{
name|uint64_t
name|eptp
decl_stmt|;
name|uint64_t
name|_res
decl_stmt|;
block|}
struct|;
end_struct

begin_expr_stmt
name|CTASSERT
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|invept_desc
argument_list|)
operator|==
literal|16
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function
specifier|static
name|void
name|__inline
name|invept
parameter_list|(
name|uint64_t
name|type
parameter_list|,
name|struct
name|invept_desc
name|desc
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
asm|__asm __volatile("invept %0, %1" :: "m" (desc), "r" (type) : "memory");
name|VMX_SET_ERROR_CODE
argument_list|(
name|error
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
condition|)
name|panic
argument_list|(
literal|"invept error %d"
argument_list|,
name|error
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

