begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_RADIX_TREE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_RADIX_TREE_H_
end_define

begin_define
define|#
directive|define
name|RADIX_TREE_MAP_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|RADIX_TREE_MAP_SIZE
value|(1<< RADIX_TREE_MAP_SHIFT)
end_define

begin_define
define|#
directive|define
name|RADIX_TREE_MAP_MASK
value|(RADIX_TREE_MAP_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|RADIX_TREE_MAX_HEIGHT
define|\
value|DIV_ROUND_UP((sizeof(long) * NBBY), RADIX_TREE_MAP_SHIFT)
end_define

begin_struct
struct|struct
name|radix_tree_node
block|{
name|void
modifier|*
name|slots
index|[
name|RADIX_TREE_MAP_SIZE
index|]
decl_stmt|;
name|int
name|count
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|radix_tree_root
block|{
name|struct
name|radix_tree_node
modifier|*
name|rnode
decl_stmt|;
name|gfp_t
name|gfp_mask
decl_stmt|;
name|int
name|height
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RADIX_TREE_INIT
parameter_list|(
name|mask
parameter_list|)
define|\
value|{ .rnode = NULL, .gfp_mask = mask, .height = 0 };
end_define

begin_define
define|#
directive|define
name|INIT_RADIX_TREE
parameter_list|(
name|root
parameter_list|,
name|mask
parameter_list|)
define|\
value|{ (root)->rnode = NULL; (root)->gfp_mask = mask; (root)->height = 0; }
end_define

begin_define
define|#
directive|define
name|RADIX_TREE
parameter_list|(
name|name
parameter_list|,
name|mask
parameter_list|)
define|\
value|struct radix_tree_root name = RADIX_TREE_INIT(mask)
end_define

begin_function_decl
name|void
modifier|*
name|radix_tree_lookup
parameter_list|(
name|struct
name|radix_tree_root
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
modifier|*
name|radix_tree_delete
parameter_list|(
name|struct
name|radix_tree_root
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|radix_tree_insert
parameter_list|(
name|struct
name|radix_tree_root
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_RADIX_TREE_H_ */
end_comment

end_unit

