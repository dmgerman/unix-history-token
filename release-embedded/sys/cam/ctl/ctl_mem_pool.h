begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003, 2004 Silicon Graphics International Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_mem_pool.h#1 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CAM Target Layer memory pool code.  *  * Author: Ken Merry<ken@FreeBSD.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_MEMPOOL_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_MEMPOOL_H_
end_define

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_MEM_POOL_NONE
block|,
name|CTL_MEM_POOL_PERM_GROW
block|}
name|ctl_mem_pool_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_mem_pool
block|{
name|ctl_mem_pool_flags
name|flags
decl_stmt|;
name|int
name|chunk_size
decl_stmt|;
name|int
name|grow_inc
decl_stmt|;
name|struct
name|mtx
name|lock
decl_stmt|;
name|struct
name|cv
name|wait_mem
decl_stmt|;
name|STAILQ_HEAD
argument_list|(
argument_list|,
argument|ctl_mem_element
argument_list|)
name|free_mem_list
expr_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_MEM_ELEMENT_NONE
block|,
name|CTL_MEM_ELEMENT_PREALLOC
block|}
name|ctl_mem_element_flags
typedef|;
end_typedef

begin_struct
struct|struct
name|ctl_mem_element
block|{
name|ctl_mem_element_flags
name|flags
decl_stmt|;
name|struct
name|ctl_mem_pool
modifier|*
name|pool
decl_stmt|;
name|uint8_t
modifier|*
name|bytes
decl_stmt|;
name|STAILQ_ENTRY
argument_list|(
argument|ctl_mem_element
argument_list|)
name|links
expr_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_CTL_POOL
argument_list|)
expr_stmt|;
end_expr_stmt

begin_function_decl
name|int
name|ctl_init_mem_pool
parameter_list|(
name|struct
name|ctl_mem_pool
modifier|*
name|pool
parameter_list|,
name|int
name|chunk_size
parameter_list|,
name|ctl_mem_pool_flags
name|flags
parameter_list|,
name|int
name|grow_inc
parameter_list|,
name|int
name|initial_pool_size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|ctl_mem_element
modifier|*
name|ctl_alloc_mem_element
parameter_list|(
name|struct
name|ctl_mem_pool
modifier|*
name|pool
parameter_list|,
name|int
name|can_wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_free_mem_element
parameter_list|(
name|struct
name|ctl_mem_element
modifier|*
name|mem
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_grow_mem_pool
parameter_list|(
name|struct
name|ctl_mem_pool
modifier|*
name|pool
parameter_list|,
name|int
name|count
parameter_list|,
name|int
name|can_wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ctl_shrink_mem_pool
parameter_list|(
name|struct
name|ctl_mem_pool
modifier|*
name|pool
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CTL_MEMPOOL_H_ */
end_comment

end_unit

