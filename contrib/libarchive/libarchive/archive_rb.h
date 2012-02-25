begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2001 The NetBSD Foundation, Inc.  * All rights reserved.  *  * This code is derived from software contributed to The NetBSD Foundation  * by Matt Thomas<matt@3am-software.com>.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED  * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  * Based on NetBSD: rb.h,v 1.13 2009/08/16 10:57:01 yamt Exp  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARCHIVE_RB_H_
end_ifndef

begin_define
define|#
directive|define
name|ARCHIVE_RB_H_
end_define

begin_struct
struct|struct
name|archive_rb_node
block|{
name|struct
name|archive_rb_node
modifier|*
name|rb_nodes
index|[
literal|2
index|]
decl_stmt|;
comment|/* 	 * rb_info contains the two flags and the parent back pointer. 	 * We put the two flags in the low two bits since we know that 	 * rb_node will have an alignment of 4 or 8 bytes. 	 */
name|uintptr_t
name|rb_info
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ARCHIVE_RB_DIR_LEFT
value|0
end_define

begin_define
define|#
directive|define
name|ARCHIVE_RB_DIR_RIGHT
value|1
end_define

begin_define
define|#
directive|define
name|ARCHIVE_RB_TREE_MIN
parameter_list|(
name|T
parameter_list|)
define|\
value|__archive_rb_tree_iterate((T), NULL, ARCHIVE_RB_DIR_LEFT)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_RB_TREE_MAX
parameter_list|(
name|T
parameter_list|)
define|\
value|__archive_rb_tree_iterate((T), NULL, ARCHIVE_RB_DIR_RIGHT)
end_define

begin_define
define|#
directive|define
name|ARCHIVE_RB_TREE_FOREACH
parameter_list|(
name|N
parameter_list|,
name|T
parameter_list|)
define|\
value|for ((N) = ARCHIVE_RB_TREE_MIN(T); (N); \ 	(N) = __archive_rb_tree_iterate((T), (N), ARCHIVE_RB_DIR_RIGHT))
end_define

begin_define
define|#
directive|define
name|ARCHIVE_RB_TREE_FOREACH_REVERSE
parameter_list|(
name|N
parameter_list|,
name|T
parameter_list|)
define|\
value|for ((N) = ARCHIVE_RB_TREE_MAX(T); (N); \ 	(N) = __archive_rb_tree_iterate((T), (N), ARCHIVE_RB_DIR_LEFT))
end_define

begin_comment
comment|/*  * archive_rbto_compare_nodes_fn:  *	return a positive value if the first node< the second node.  *	return a negative value if the first node> the second node.  *	return 0 if they are considered same.  *  * archive_rbto_compare_key_fn:  *	return a positive value if the node< the key.  *	return a negative value if the node> the key.  *	return 0 if they are considered same.  */
end_comment

begin_typedef
typedef|typedef
name|signed
name|int
argument_list|(
operator|*
specifier|const
name|archive_rbto_compare_nodes_fn
argument_list|)
argument_list|(
specifier|const
expr|struct
name|archive_rb_node
operator|*
argument_list|,
specifier|const
expr|struct
name|archive_rb_node
operator|*
argument_list|)
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|signed
name|int
argument_list|(
operator|*
specifier|const
name|archive_rbto_compare_key_fn
argument_list|)
argument_list|(
specifier|const
expr|struct
name|archive_rb_node
operator|*
argument_list|,
specifier|const
name|void
operator|*
argument_list|)
typedef|;
end_typedef

begin_struct
struct|struct
name|archive_rb_tree_ops
block|{
name|archive_rbto_compare_nodes_fn
name|rbto_compare_nodes
decl_stmt|;
name|archive_rbto_compare_key_fn
name|rbto_compare_key
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|archive_rb_tree
block|{
name|struct
name|archive_rb_node
modifier|*
name|rbt_root
decl_stmt|;
specifier|const
name|struct
name|archive_rb_tree_ops
modifier|*
name|rbt_ops
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|__archive_rb_tree_init
parameter_list|(
name|struct
name|archive_rb_tree
modifier|*
parameter_list|,
specifier|const
name|struct
name|archive_rb_tree_ops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__archive_rb_tree_insert_node
parameter_list|(
name|struct
name|archive_rb_tree
modifier|*
parameter_list|,
name|struct
name|archive_rb_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_rb_node
modifier|*
name|__archive_rb_tree_find_node
parameter_list|(
name|struct
name|archive_rb_tree
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_rb_node
modifier|*
name|__archive_rb_tree_find_node_geq
parameter_list|(
name|struct
name|archive_rb_tree
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_rb_node
modifier|*
name|__archive_rb_tree_find_node_leq
parameter_list|(
name|struct
name|archive_rb_tree
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|__archive_rb_tree_remove_node
parameter_list|(
name|struct
name|archive_rb_tree
modifier|*
parameter_list|,
name|struct
name|archive_rb_node
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|archive_rb_node
modifier|*
name|__archive_rb_tree_iterate
parameter_list|(
name|struct
name|archive_rb_tree
modifier|*
parameter_list|,
name|struct
name|archive_rb_node
modifier|*
parameter_list|,
specifier|const
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ARCHIVE_RB_H_*/
end_comment

end_unit

