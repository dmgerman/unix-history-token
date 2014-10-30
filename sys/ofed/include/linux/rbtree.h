begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2010 Isilon Systems, Inc.  * Copyright (c) 2010 iX Systems, Inc.  * Copyright (c) 2010 Panasas, Inc.  * Copyright (c) 2013, 2014 Mellanox Technologies, Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice unmodified, this list of conditions, and the following  *    disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_RBTREE_H_
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_RBTREE_H_
end_define

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/tree.h>
end_include

begin_struct
struct|struct
name|rb_node
block|{
name|RB_ENTRY
argument_list|(
argument|rb_node
argument_list|)
name|__entry
expr_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|rb_left
value|__entry.rbe_left
end_define

begin_define
define|#
directive|define
name|rb_right
value|__entry.rbe_right
end_define

begin_comment
comment|/*  * We provide a false structure that has the same bit pattern as tree.h  * presents so it matches the member names expected by linux.  */
end_comment

begin_struct
struct|struct
name|rb_root
block|{
name|struct
name|rb_node
modifier|*
name|rb_node
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * In linux all of the comparisons are done by the caller.  */
end_comment

begin_function_decl
name|int
name|panic_cmp
parameter_list|(
name|struct
name|rb_node
modifier|*
name|one
parameter_list|,
name|struct
name|rb_node
modifier|*
name|two
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|RB_HEAD
argument_list|(
name|linux_root
argument_list|,
name|rb_node
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RB_PROTOTYPE
argument_list|(
name|linux_root
argument_list|,
name|rb_node
argument_list|,
name|__entry
argument_list|,
name|panic_cmp
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|rb_parent
parameter_list|(
name|r
parameter_list|)
value|RB_PARENT(r, __entry)
end_define

begin_define
define|#
directive|define
name|rb_color
parameter_list|(
name|r
parameter_list|)
value|RB_COLOR(r, __entry)
end_define

begin_define
define|#
directive|define
name|rb_is_red
parameter_list|(
name|r
parameter_list|)
value|(rb_color(r) == RB_RED)
end_define

begin_define
define|#
directive|define
name|rb_is_black
parameter_list|(
name|r
parameter_list|)
value|(rb_color(r) == RB_BLACK)
end_define

begin_define
define|#
directive|define
name|rb_set_parent
parameter_list|(
name|r
parameter_list|,
name|p
parameter_list|)
value|rb_parent((r)) = (p)
end_define

begin_define
define|#
directive|define
name|rb_set_color
parameter_list|(
name|r
parameter_list|,
name|c
parameter_list|)
value|rb_color((r)) = (c)
end_define

begin_define
define|#
directive|define
name|rb_entry
parameter_list|(
name|ptr
parameter_list|,
name|type
parameter_list|,
name|member
parameter_list|)
value|container_of(ptr, type, member)
end_define

begin_define
define|#
directive|define
name|RB_EMPTY_ROOT
parameter_list|(
name|root
parameter_list|)
value|RB_EMPTY((struct linux_root *)root)
end_define

begin_define
define|#
directive|define
name|RB_EMPTY_NODE
parameter_list|(
name|node
parameter_list|)
value|(rb_parent(node) == node)
end_define

begin_define
define|#
directive|define
name|RB_CLEAR_NODE
parameter_list|(
name|node
parameter_list|)
value|(rb_set_parent(node, node))
end_define

begin_define
define|#
directive|define
name|rb_insert_color
parameter_list|(
name|node
parameter_list|,
name|root
parameter_list|)
define|\
value|linux_root_RB_INSERT_COLOR((struct linux_root *)(root), (node))
end_define

begin_define
define|#
directive|define
name|rb_erase
parameter_list|(
name|node
parameter_list|,
name|root
parameter_list|)
define|\
value|linux_root_RB_REMOVE((struct linux_root *)(root), (node))
end_define

begin_define
define|#
directive|define
name|rb_next
parameter_list|(
name|node
parameter_list|)
value|RB_NEXT(linux_root, NULL, (node))
end_define

begin_define
define|#
directive|define
name|rb_prev
parameter_list|(
name|node
parameter_list|)
value|RB_PREV(linux_root, NULL, (node))
end_define

begin_define
define|#
directive|define
name|rb_first
parameter_list|(
name|root
parameter_list|)
value|RB_MIN(linux_root, (struct linux_root *)(root))
end_define

begin_define
define|#
directive|define
name|rb_last
parameter_list|(
name|root
parameter_list|)
value|RB_MAX(linux_root, (struct linux_root *)(root))
end_define

begin_function
specifier|static
specifier|inline
name|void
name|rb_link_node
parameter_list|(
name|struct
name|rb_node
modifier|*
name|node
parameter_list|,
name|struct
name|rb_node
modifier|*
name|parent
parameter_list|,
name|struct
name|rb_node
modifier|*
modifier|*
name|rb_link
parameter_list|)
block|{
name|rb_set_parent
argument_list|(
name|node
argument_list|,
name|parent
argument_list|)
expr_stmt|;
name|rb_set_color
argument_list|(
name|node
argument_list|,
name|RB_RED
argument_list|)
expr_stmt|;
name|node
operator|->
name|__entry
operator|.
name|rbe_left
operator|=
name|node
operator|->
name|__entry
operator|.
name|rbe_right
operator|=
name|NULL
expr_stmt|;
operator|*
name|rb_link
operator|=
name|node
expr_stmt|;
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|rb_replace_node
parameter_list|(
name|struct
name|rb_node
modifier|*
name|victim
parameter_list|,
name|struct
name|rb_node
modifier|*
name|new
parameter_list|,
name|struct
name|rb_root
modifier|*
name|root
parameter_list|)
block|{
name|struct
name|rb_node
modifier|*
name|p
decl_stmt|;
name|p
operator|=
name|rb_parent
argument_list|(
name|victim
argument_list|)
expr_stmt|;
if|if
condition|(
name|p
condition|)
block|{
if|if
condition|(
name|p
operator|->
name|rb_left
operator|==
name|victim
condition|)
name|p
operator|->
name|rb_left
operator|=
name|new
expr_stmt|;
else|else
name|p
operator|->
name|rb_right
operator|=
name|new
expr_stmt|;
block|}
else|else
name|root
operator|->
name|rb_node
operator|=
name|new
expr_stmt|;
if|if
condition|(
name|victim
operator|->
name|rb_left
condition|)
name|rb_set_parent
argument_list|(
name|victim
operator|->
name|rb_left
argument_list|,
name|new
argument_list|)
expr_stmt|;
if|if
condition|(
name|victim
operator|->
name|rb_right
condition|)
name|rb_set_parent
argument_list|(
name|victim
operator|->
name|rb_right
argument_list|,
name|new
argument_list|)
expr_stmt|;
operator|*
name|new
operator|=
operator|*
name|victim
expr_stmt|;
block|}
end_function

begin_undef
undef|#
directive|undef
name|RB_ROOT
end_undef

begin_define
define|#
directive|define
name|RB_ROOT
value|(struct rb_root) { NULL }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _LINUX_RBTREE_H_ */
end_comment

end_unit

