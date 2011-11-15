begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2011 Jeffrey Roberson<jeff@freebsd.org>  * Copyright (c) 2008 Mayur Shardul<mayur.shardul@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_RADIX_H_
end_ifndef

begin_define
define|#
directive|define
name|_VM_RADIX_H_
end_define

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/* Default values of the tree parameters */
end_comment

begin_define
define|#
directive|define
name|VM_RADIX_WIDTH
value|5
end_define

begin_define
define|#
directive|define
name|VM_RADIX_COUNT
value|(1<< VM_RADIX_WIDTH)
end_define

begin_define
define|#
directive|define
name|VM_RADIX_MASK
value|(VM_RADIX_COUNT - 1)
end_define

begin_define
define|#
directive|define
name|VM_RADIX_LIMIT
value|howmany((sizeof(vm_pindex_t) * NBBY), VM_RADIX_WIDTH)
end_define

begin_define
define|#
directive|define
name|VM_RADIX_FLAGS
value|0x3
end_define

begin_comment
comment|/* Flag bits stored in node pointers. */
end_comment

begin_define
define|#
directive|define
name|VM_RADIX_BLACK
value|0x1
end_define

begin_comment
comment|/* Black node. (leaf only) */
end_comment

begin_define
define|#
directive|define
name|VM_RADIX_RED
value|0x2
end_define

begin_comment
comment|/* Red node. (leaf only) */
end_comment

begin_define
define|#
directive|define
name|VM_RADIX_ANY
value|(VM_RADIX_RED | VM_RADIX_BLACK)
end_define

begin_define
define|#
directive|define
name|VM_RADIX_EMPTY
value|0x1
end_define

begin_comment
comment|/* Empty hint. (internal only) */
end_comment

begin_define
define|#
directive|define
name|VM_RADIX_HEIGHT
value|0xf
end_define

begin_comment
comment|/* Bits of height in root */
end_comment

begin_define
define|#
directive|define
name|VM_RADIX_STACK
value|8
end_define

begin_comment
comment|/* Nodes to store on stack. */
end_comment

begin_comment
comment|/* Calculates maximum value for a tree of height h. */
end_comment

begin_define
define|#
directive|define
name|VM_RADIX_MAX
parameter_list|(
name|h
parameter_list|)
define|\
value|((h) == VM_RADIX_LIMIT ? ((vm_pindex_t)-1) :		\ 	    (((vm_pindex_t)1<< ((h) * VM_RADIX_WIDTH)) - 1))
end_define

begin_comment
comment|/*  * Radix tree root.  The height and pointer are set together to permit  * coherent lookups while the root is modified.  */
end_comment

begin_struct
struct|struct
name|vm_radix
block|{
name|uintptr_t
name|rt_root
decl_stmt|;
comment|/* root + height */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_expr_stmt
name|CTASSERT
argument_list|(
name|VM_RADIX_HEIGHT
operator|>=
name|VM_RADIX_LIMIT
argument_list|)
expr_stmt|;
end_expr_stmt

begin_struct
struct|struct
name|vm_radix_node
block|{
name|void
modifier|*
name|rn_child
index|[
name|VM_RADIX_COUNT
index|]
decl_stmt|;
comment|/* child nodes. */
name|uint16_t
name|rn_count
decl_stmt|;
comment|/* Valid children. */
block|}
struct|;
end_struct

begin_function_decl
name|void
name|vm_radix_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions which only work with black nodes. (object lock)  */
end_comment

begin_function_decl
name|int
name|vm_radix_insert
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_radix_shrink
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Functions which work on specified colors. (object, vm_page_queue_free locks)  */
end_comment

begin_function_decl
name|void
modifier|*
name|vm_radix_color
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|vm_radix_lookup
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_radix_lookupn
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|,
name|vm_pindex_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|vm_radix_lookup_le
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_radix_reclaim_allnodes
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|vm_radix_remove
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vm_radix_foreach
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|vm_pindex_t
parameter_list|,
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Look up any entry at a position greater or equal to index.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|vm_radix_lookup_ge
parameter_list|(
name|struct
name|vm_radix
modifier|*
name|rtree
parameter_list|,
name|vm_pindex_t
name|index
parameter_list|,
name|int
name|color
parameter_list|)
block|{
name|void
modifier|*
name|val
decl_stmt|;
if|if
condition|(
name|vm_radix_lookupn
argument_list|(
name|rtree
argument_list|,
name|index
argument_list|,
literal|0
argument_list|,
name|color
argument_list|,
operator|&
name|val
argument_list|,
literal|1
argument_list|,
operator|&
name|index
argument_list|)
condition|)
return|return
operator|(
name|val
operator|)
return|;
return|return
operator|(
name|NULL
operator|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|vm_radix_last
parameter_list|(
name|struct
name|vm_radix
modifier|*
name|rtree
parameter_list|,
name|int
name|color
parameter_list|)
block|{
return|return
name|vm_radix_lookup_le
argument_list|(
name|rtree
argument_list|,
literal|0
argument_list|,
name|color
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|vm_radix_first
parameter_list|(
name|struct
name|vm_radix
modifier|*
name|rtree
parameter_list|,
name|int
name|color
parameter_list|)
block|{
return|return
name|vm_radix_lookup_ge
argument_list|(
name|rtree
argument_list|,
literal|0
argument_list|,
name|color
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|vm_radix_next
parameter_list|(
name|struct
name|vm_radix
modifier|*
name|rtree
parameter_list|,
name|vm_pindex_t
name|index
parameter_list|,
name|int
name|color
parameter_list|)
block|{
if|if
condition|(
name|index
operator|==
operator|-
literal|1
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
return|return
name|vm_radix_lookup_ge
argument_list|(
name|rtree
argument_list|,
name|index
operator|+
literal|1
argument_list|,
name|color
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
modifier|*
name|vm_radix_prev
parameter_list|(
name|struct
name|vm_radix
modifier|*
name|rtree
parameter_list|,
name|vm_pindex_t
name|index
parameter_list|,
name|int
name|color
parameter_list|)
block|{
if|if
condition|(
name|index
operator|==
literal|0
condition|)
return|return
operator|(
name|NULL
operator|)
return|;
return|return
name|vm_radix_lookup_le
argument_list|(
name|rtree
argument_list|,
name|index
operator|-
literal|1
argument_list|,
name|color
argument_list|)
return|;
block|}
end_function

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
comment|/* !_VM_RADIX_H_ */
end_comment

end_unit

