begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2012 Ian Lepore  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * A buffer pool manager, for use by a platform's busdma implementation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BUSDMA_BUFALLOC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BUSDMA_BUFALLOC_H_
end_define

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<vm/uma.h>
end_include

begin_comment
comment|/*  * Information about a buffer zone, returned by busdma_bufalloc_findzone().  */
end_comment

begin_struct
struct|struct
name|busdma_bufzone
block|{
name|bus_size_t
name|size
decl_stmt|;
name|uma_zone_t
name|umazone
decl_stmt|;
name|char
name|name
index|[
literal|24
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Opaque handle type returned by busdma_bufalloc_create().  */
end_comment

begin_struct_decl
struct_decl|struct
name|busdma_bufalloc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|struct
name|busdma_bufalloc
modifier|*
name|busdma_bufalloc_t
typedef|;
end_typedef

begin_comment
comment|/*  * Create an allocator that manages a pool of DMA buffers.  *  * The allocator manages a collection of uma(9) zones of buffers in power-of-two  * sized increments ranging from minimum_alignment to the platform's PAGE_SIZE.  * The buffers within each zone are aligned on boundaries corresponding to the  * buffer size, and thus by implication each buffer is contiguous within a page  * and does not cross a power of two boundary larger than the buffer size.  * These rules are intended to make it easy for a busdma implementation to  * check whether a tag's constraints allow use of a buffer from the allocator.  *  * minimum_alignment is also the minimum buffer allocation size.  For platforms  * with software-assisted cache coherency, this is typically the data cache line  * size (and MUST not be smaller than the cache line size).  *  * name appears in zone stats as 'dma name nnnnn' where 'dma' is fixed and  * 'nnnnn' is the size of buffers in that zone.  *  * If if the alloc/free function pointers are NULL, the regular uma internal  * allocators are used (I.E., you get "plain old kernel memory").  On a platform  * with an exclusion zone that applies to all DMA operations, a custom allocator  * could be used to ensure no buffer memory is ever allocated from that zone,  * allowing the bus_dmamem_alloc() implementation to make the assumption that  * buffers provided by the allocation could never lead to the need for a bounce.  */
end_comment

begin_function_decl
name|busdma_bufalloc_t
name|busdma_bufalloc_create
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|bus_size_t
name|minimum_alignment
parameter_list|,
name|uma_alloc
name|uma_alloc_func
parameter_list|,
name|uma_free
name|uma_free_func
parameter_list|,
name|u_int32_t
name|uma_zcreate_flags
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Destroy an allocator created by busdma_bufalloc_create().  * Safe to call with a NULL pointer.  */
end_comment

begin_function_decl
name|void
name|busdma_bufalloc_destroy
parameter_list|(
name|busdma_bufalloc_t
name|ba
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Return a pointer to the busdma_bufzone that should be used to allocate or  * free a buffer of the given size.  Returns NULL if the size is larger than the  * largest zone handled by the allocator.  */
end_comment

begin_function_decl
name|struct
name|busdma_bufzone
modifier|*
name|busdma_bufalloc_findzone
parameter_list|(
name|busdma_bufalloc_t
name|ba
parameter_list|,
name|bus_size_t
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * These built-in allocation routines are available for managing a pools of  * uncacheable memory on platforms that support VM_MEMATTR_UNCACHEABLE.  *  * Allocation is done using kmem_alloc_attr() with these parameters:  *   lowaddr  = 0  *   highaddr = BUS_SPACE_MAXADDR  *   memattr  = VM_MEMATTR_UNCACHEABLE.  *  * If your platform has no exclusion region (lowaddr/highaddr), and its pmap  * routines support pmap_page_set_memattr() and the VM_MEMATTR_UNCACHEABLE flag  * you can probably use these when you need uncacheable buffers.  */
end_comment

begin_function_decl
name|void
modifier|*
name|busdma_bufalloc_alloc_uncacheable
parameter_list|(
name|uma_zone_t
name|zone
parameter_list|,
name|int
name|size
parameter_list|,
name|u_int8_t
modifier|*
name|pflag
parameter_list|,
name|int
name|wait
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|busdma_bufalloc_free_uncacheable
parameter_list|(
name|void
modifier|*
name|item
parameter_list|,
name|int
name|size
parameter_list|,
name|u_int8_t
name|pflag
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_BUSDMA_BUFALLOC_H_ */
end_comment

end_unit

