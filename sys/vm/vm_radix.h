begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2008 Mayur Shardul<mayur.shardul@gmail.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
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

begin_struct
struct|struct
name|vm_radix_node
block|{
name|SLIST_ENTRY
argument_list|(
argument|vm_radix_node
argument_list|)
name|next
expr_stmt|;
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

begin_struct
struct|struct
name|vm_radix
block|{
name|struct
name|vm_radix_node
modifier|*
name|rt_root
decl_stmt|;
comment|/* Root node. */
name|int
name|rt_height
decl_stmt|;
comment|/* Number of levels + 1. */
block|}
struct|;
end_struct

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
modifier|*
name|vm_radix_remove
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|,
name|vm_pindex_t
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
name|rtree
parameter_list|,
name|vm_pindex_t
name|start
parameter_list|,
name|vm_pindex_t
name|end
parameter_list|,
name|void
modifier|*
modifier|*
name|out
parameter_list|,
name|int
name|cnt
parameter_list|,
name|vm_pindex_t
modifier|*
name|next
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|vm_radix_lookup_ge
parameter_list|(
name|struct
name|vm_radix
modifier|*
parameter_list|,
name|vm_pindex_t
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_VM_RADIX_H_ */
end_comment

end_unit

