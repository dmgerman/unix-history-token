begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VMM_HOST_H_
end_ifndef

begin_define
define|#
directive|define
name|_VMM_HOST_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|_KERNEL
end_ifndef

begin_error
error|#
directive|error
literal|"no user-servicable parts inside"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|xsave_limits
block|{
name|int
name|xsave_enabled
decl_stmt|;
name|uint64_t
name|xcr0_allowed
decl_stmt|;
name|uint32_t
name|xsave_max_size
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|vmm_host_state_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_pat
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_efer
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_cr0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_cr4
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_xcr0
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_datasel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_codesel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_tsssel
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_fsbase
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|vmm_get_host_idtrbase
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|xsave_limits
modifier|*
name|vmm_get_xsave_limits
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Inline access to host state that is used on every VM entry  */
end_comment

begin_function
specifier|static
name|__inline
name|uint64_t
name|vmm_get_host_trbase
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|uint64_t
operator|)
name|PCPU_GET
argument_list|(
name|tssp
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|uint64_t
name|vmm_get_host_gdtrbase
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|uint64_t
operator|)
operator|&
name|gdt
index|[
name|NGDT
operator|*
name|curcpu
index|]
operator|)
return|;
block|}
end_function

begin_struct_decl
struct_decl|struct
name|pcpu
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|struct
name|pcpu
name|__pcpu
index|[]
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
name|__inline
name|uint64_t
name|vmm_get_host_gsbase
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
operator|(
name|uint64_t
operator|)
operator|&
name|__pcpu
index|[
name|curcpu
index|]
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

