begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 NetApp, Inc.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY NETAPP, INC ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL NETAPP, INC OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MEM_H_
end_ifndef

begin_define
define|#
directive|define
name|_MEM_H_
end_define

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_struct_decl
struct_decl|struct
name|vmctx
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|mem_func_t
function_decl|)
parameter_list|(
name|struct
name|vmctx
modifier|*
name|ctx
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|int
name|dir
parameter_list|,
name|uint64_t
name|addr
parameter_list|,
name|int
name|size
parameter_list|,
name|uint64_t
modifier|*
name|val
parameter_list|,
name|void
modifier|*
name|arg1
parameter_list|,
name|long
name|arg2
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|mem_range
block|{
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|flags
decl_stmt|;
name|mem_func_t
name|handler
decl_stmt|;
name|void
modifier|*
name|arg1
decl_stmt|;
name|long
name|arg2
decl_stmt|;
name|uint64_t
name|base
decl_stmt|;
name|uint64_t
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MEM_F_READ
value|0x1
end_define

begin_define
define|#
directive|define
name|MEM_F_WRITE
value|0x2
end_define

begin_define
define|#
directive|define
name|MEM_F_RW
value|0x3
end_define

begin_function_decl
name|void
name|init_mem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|emulate_mem
parameter_list|(
name|struct
name|vmctx
modifier|*
parameter_list|,
name|int
name|vcpu
parameter_list|,
name|uint64_t
name|paddr
parameter_list|,
name|struct
name|vie
modifier|*
name|vie
parameter_list|,
name|struct
name|vm_guest_paging
modifier|*
name|paging
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|register_mem
parameter_list|(
name|struct
name|mem_range
modifier|*
name|memp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|register_mem_fallback
parameter_list|(
name|struct
name|mem_range
modifier|*
name|memp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|unregister_mem
parameter_list|(
name|struct
name|mem_range
modifier|*
name|memp
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MEM_H_ */
end_comment

end_unit

