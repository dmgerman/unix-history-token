begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1999, 2000 Mitsuru IWASAKI<iwasaki@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: aml_memman.h,v 1.9 2000/08/09 14:47:43 iwasaki Exp $  *	$FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MEMMAN_H_
end_ifndef

begin_define
define|#
directive|define
name|_MEMMAN_H_
end_define

begin_comment
comment|/*  * Generic Memory Management  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* memory block */
end_comment

begin_struct
struct|struct
name|memman_block
block|{
name|LIST_ENTRY
argument_list|(
argument|memman_block
argument_list|)
name|links
expr_stmt|;
name|void
modifier|*
name|block
decl_stmt|;
name|unsigned
name|static_mem
decl_stmt|;
comment|/* static memory or not */
name|unsigned
name|int
name|allocated
decl_stmt|;
comment|/* number of allocated chunks */
name|unsigned
name|int
name|available
decl_stmt|;
comment|/* number of available chunks */
name|unsigned
name|int
name|allocated_mem
decl_stmt|;
comment|/* block + misc (in bytes) */
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|memman_block_list
argument_list|,
name|memman_block
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* memory node in block */
end_comment

begin_struct
struct|struct
name|memman_node
block|{
name|LIST_ENTRY
argument_list|(
argument|memman_node
argument_list|)
name|links
expr_stmt|;
name|void
modifier|*
name|node
decl_stmt|;
name|struct
name|memman_block
modifier|*
name|memblock
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|memman_node_list
argument_list|,
name|memman_node
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* memory type id */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|memid_unkown
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* memory block manager */
end_comment

begin_struct
struct|struct
name|memman_blockman
block|{
name|unsigned
name|int
name|size
decl_stmt|;
comment|/* size of chunk */
name|unsigned
name|int
name|available
decl_stmt|;
comment|/* total # of available chunks */
name|void
modifier|*
name|initial_block
decl_stmt|;
comment|/* initial memory storage */
name|unsigned
name|initialized
decl_stmt|;
comment|/* initialized or not */
name|struct
name|memman_block_list
name|block_list
decl_stmt|;
name|struct
name|memman_node_list
name|free_node_list
decl_stmt|;
name|struct
name|memman_node_list
name|occupied_node_list
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* memory size histogram */
end_comment

begin_define
define|#
directive|define
name|MEMMAN_HISTOGRAM_SIZE
value|20
end_define

begin_struct
struct|struct
name|memman_histogram
block|{
name|int
name|mem_size
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* flex size memory allocation info */
end_comment

begin_struct
struct|struct
name|memman_flexmem_info
block|{
name|LIST_ENTRY
argument_list|(
argument|memman_flexmem_info
argument_list|)
name|links
expr_stmt|;
name|void
modifier|*
name|addr
decl_stmt|;
name|size_t
name|mem_size
decl_stmt|;
block|}
name|__attribute__
argument_list|(
operator|(
name|packed
operator|)
argument_list|)
struct|;
end_struct

begin_expr_stmt
name|LIST_HEAD
argument_list|(
name|memman_flexmem_info_list
argument_list|,
name|memman_flexmem_info
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* memory manager */
end_comment

begin_struct
struct|struct
name|memman
block|{
name|struct
name|memman_blockman
modifier|*
name|blockman
decl_stmt|;
name|unsigned
name|int
name|max_memid
decl_stmt|;
comment|/* max number of valid memid */
comment|/* fixed size memory blocks */
name|unsigned
name|int
name|alloc_called
decl_stmt|;
comment|/* memman_alloc() calling */
name|unsigned
name|int
name|free_called
decl_stmt|;
comment|/* memman_free() calling */
name|unsigned
name|int
name|salloc_called
decl_stmt|;
comment|/* malloc() calling */
name|unsigned
name|int
name|sfree_called
decl_stmt|;
comment|/* free() calling */
name|size_t
name|required_mem
decl_stmt|;
comment|/* total required memory (in bytes) */
name|size_t
name|allocated_mem
decl_stmt|;
comment|/* total malloc()ed memory */
name|size_t
name|reclaimed_mem
decl_stmt|;
comment|/* total free()ed memory */
comment|/* flex size memory blocks */
name|unsigned
name|int
name|flex_alloc_called
decl_stmt|;
comment|/* memman_alloc_flexsize() calling */
name|unsigned
name|int
name|flex_free_called
decl_stmt|;
comment|/* memman_free_flexsize() calling */
name|unsigned
name|int
name|flex_salloc_called
decl_stmt|;
comment|/* malloc() calling */
name|unsigned
name|int
name|flex_sfree_called
decl_stmt|;
comment|/* free() calling */
name|size_t
name|flex_required_mem
decl_stmt|;
comment|/* total required memory (in bytes) */
name|size_t
name|flex_allocated_mem
decl_stmt|;
comment|/* total malloc()ed memory */
name|size_t
name|flex_reclaimed_mem
decl_stmt|;
comment|/* total free()ed memory */
name|size_t
name|flex_mem_size_min
decl_stmt|;
comment|/* min size of allocated memory */
name|size_t
name|flex_mem_size_max
decl_stmt|;
comment|/* max size of allocated memory */
name|size_t
name|flex_peak_mem_usage
decl_stmt|;
comment|/* memory usage at a peak period */
comment|/* stuff for more detailed statistical information */
name|struct
name|memman_histogram
modifier|*
name|flex_mem_histogram
decl_stmt|;
name|unsigned
name|int
name|flex_mem_histogram_ptr
decl_stmt|;
name|int
name|flex_mem_histogram_initial_tolerance
decl_stmt|;
name|unsigned
name|flex_mem_initialized
decl_stmt|;
name|struct
name|memman_flexmem_info_list
name|flexmem_info_list
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MEMMAN_BLOCKNODE_SIZE
parameter_list|(
name|entries
parameter_list|)
value|sizeof(struct memman_block) + \     sizeof(struct memman_node) * entries
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ROUNDUP_UNIT
end_ifndef

begin_define
define|#
directive|define
name|ROUNDUP_UNIT
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MEMMAN_INITIAL_SIZE
argument_list|)
operator|||
name|MEMMAN_INITIAL_SIZE
operator|<
literal|2048
end_if

begin_define
define|#
directive|define
name|MEMMAN_INITIAL_SIZE
value|2048
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|MEMMAN_INCR_SIZE
argument_list|)
operator|||
name|MEMMAN_INCR_SIZE
operator|<
literal|512
end_if

begin_define
define|#
directive|define
name|MEMMAN_INCR_SIZE
value|512
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MEMMAN_INITIALSTORAGE_DESC
parameter_list|(
name|type
parameter_list|,
name|name
parameter_list|)
define|\
value|static struct { \ 	char	blocknodes[MEMMAN_BLOCKNODE_SIZE(MEMMAN_INITIAL_SIZE)]; \ 	type	realblock[MEMMAN_INITIAL_SIZE]; \ } name
end_define

begin_define
define|#
directive|define
name|MEMMAN_MEMBLOCK_DESC
parameter_list|(
name|size
parameter_list|,
name|initial_storage
parameter_list|)
define|\
value|{ size, MEMMAN_INITIAL_SIZE,&initial_storage, 0 }
end_define

begin_define
define|#
directive|define
name|MEMMAN_MEMMANAGER_DESC
parameter_list|(
name|blockman
parameter_list|,
name|max_memid
parameter_list|,
name|histogram
parameter_list|,
name|tolerance
parameter_list|)
define|\
value|{ blockman, max_memid, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \ 	  0, 0, 0, histogram, 0, tolerance, 0}
end_define

begin_function_decl
name|void
modifier|*
name|memman_alloc
parameter_list|(
name|struct
name|memman
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|memman_alloc_flexsize
parameter_list|(
name|struct
name|memman
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memman_free
parameter_list|(
name|struct
name|memman
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memman_free_flexsize
parameter_list|(
name|struct
name|memman
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memman_freeall
parameter_list|(
name|struct
name|memman
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|memman_statistics
parameter_list|(
name|struct
name|memman
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|size_t
name|memman_memid2size
parameter_list|(
name|struct
name|memman
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_define
define|#
directive|define
name|MEMMAN_SYSMALLOC
parameter_list|(
name|size
parameter_list|)
value|malloc(size, M_MEMMAN, M_WAITOK)
end_define

begin_define
define|#
directive|define
name|MEMMAN_SYSFREE
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr, M_MEMMAN)
end_define

begin_define
define|#
directive|define
name|MEMMAN_SYSABORT
parameter_list|()
end_define

begin_comment
comment|/* no abort in kernel */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|MEMMAN_SYSMALLOC
parameter_list|(
name|size
parameter_list|)
value|malloc(size)
end_define

begin_define
define|#
directive|define
name|MEMMAN_SYSFREE
parameter_list|(
name|ptr
parameter_list|)
value|free(ptr)
end_define

begin_define
define|#
directive|define
name|MEMMAN_SYSABORT
parameter_list|()
value|abort()
end_define

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
comment|/* !_MEMMAN_H_ */
end_comment

end_unit

