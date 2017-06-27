begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2017 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_MM_TYPES_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_MM_TYPES_H_
end_define

begin_include
include|#
directive|include
file|<linux/types.h>
end_include

begin_include
include|#
directive|include
file|<linux/page.h>
end_include

begin_include
include|#
directive|include
file|<linux/rwsem.h>
end_include

begin_include
include|#
directive|include
file|<asm/atomic.h>
end_include

begin_struct_decl
struct_decl|struct
name|vm_area_struct
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|task_struct
struct_decl|;
end_struct_decl

begin_struct
struct|struct
name|mm_struct
block|{
name|struct
name|vm_area_struct
modifier|*
name|mmap
decl_stmt|;
name|atomic_t
name|mm_count
decl_stmt|;
name|atomic_t
name|mm_users
decl_stmt|;
name|size_t
name|pinned_vm
decl_stmt|;
name|struct
name|rw_semaphore
name|mmap_sem
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|linux_mm_dtor
parameter_list|(
name|struct
name|mm_struct
modifier|*
name|mm
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|void
name|mmdrop
parameter_list|(
name|struct
name|mm_struct
modifier|*
name|mm
parameter_list|)
block|{
if|if
condition|(
name|__predict_false
argument_list|(
name|atomic_dec_and_test
argument_list|(
operator|&
name|mm
operator|->
name|mm_count
argument_list|)
argument_list|)
condition|)
name|linux_mm_dtor
argument_list|(
name|mm
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|mmput
parameter_list|(
name|struct
name|mm_struct
modifier|*
name|mm
parameter_list|)
block|{
if|if
condition|(
name|__predict_false
argument_list|(
name|atomic_dec_and_test
argument_list|(
operator|&
name|mm
operator|->
name|mm_users
argument_list|)
argument_list|)
condition|)
name|mmdrop
argument_list|(
name|mm
argument_list|)
expr_stmt|;
block|}
end_function

begin_function_decl
specifier|extern
name|struct
name|mm_struct
modifier|*
name|linux_get_task_mm
parameter_list|(
name|struct
name|task_struct
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|get_task_mm
parameter_list|(
name|task
parameter_list|)
value|linux_get_task_mm(task)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_MM_TYPES_H_ */
end_comment

end_unit

