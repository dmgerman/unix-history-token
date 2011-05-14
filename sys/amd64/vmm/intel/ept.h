begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_EPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_EPT_H_
end_define

begin_struct_decl
struct_decl|struct
name|vmx
struct_decl|;
end_struct_decl

begin_define
define|#
directive|define
name|EPT_PWLEVELS
value|4
end_define

begin_comment
comment|/* page walk levels */
end_comment

begin_define
define|#
directive|define
name|EPTP
parameter_list|(
name|pml4
parameter_list|)
value|((pml4) | (EPT_PWLEVELS - 1)<< 3 | PAT_WRITE_BACK)
end_define

begin_function_decl
name|int
name|ept_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ept_vmmmap
parameter_list|(
name|void
modifier|*
name|arg
parameter_list|,
name|vm_paddr_t
name|gpa
parameter_list|,
name|vm_paddr_t
name|hpa
parameter_list|,
name|size_t
name|length
parameter_list|,
name|vm_memattr_t
name|attr
parameter_list|,
name|int
name|prot
parameter_list|,
name|boolean_t
name|allow_superpage_mappings
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ept_invalidate_mappings
parameter_list|(
name|u_long
name|ept_pml4
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ept_vmcleanup
parameter_list|(
name|struct
name|vmx
modifier|*
name|vmx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

