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

begin_function_decl
name|int
name|ept_init
parameter_list|(
name|int
name|ipinum
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ept_invalidate_mappings
parameter_list|(
name|u_long
name|eptp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|vmspace
modifier|*
name|ept_vmspace_alloc
parameter_list|(
name|vm_offset_t
name|min
parameter_list|,
name|vm_offset_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ept_vmspace_free
parameter_list|(
name|struct
name|vmspace
modifier|*
name|vmspace
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|eptp
parameter_list|(
name|uint64_t
name|pml4
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

