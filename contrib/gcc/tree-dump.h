begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Tree-dumping functionality for intermediate representation.    Copyright (C) 1999, 2000 Free Software Foundation, Inc.    Written by Mark Mitchell<mark@codesourcery.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_DUMP_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_DUMP_H
end_define

begin_comment
comment|/* Flags used with queue functions.  */
end_comment

begin_define
define|#
directive|define
name|DUMP_NONE
value|0
end_define

begin_define
define|#
directive|define
name|DUMP_BINFO
value|1
end_define

begin_comment
comment|/* Information about a node to be dumped.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dump_node_info
block|{
comment|/* The index for the node.  */
name|unsigned
name|int
name|index
decl_stmt|;
comment|/* Nonzero if the node is a binfo.  */
name|unsigned
name|int
name|binfo_p
range|:
literal|1
decl_stmt|;
block|}
typedef|*
name|dump_node_info_p
typedef|;
end_typedef

begin_comment
comment|/* A dump_queue is a link in the queue of things to be dumped.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|dump_queue
block|{
comment|/* The queued tree node.  */
name|splay_tree_node
name|node
decl_stmt|;
comment|/* The next node in the queue.  */
name|struct
name|dump_queue
modifier|*
name|next
decl_stmt|;
block|}
typedef|*
name|dump_queue_p
typedef|;
end_typedef

begin_comment
comment|/* A dump_info gives information about how we should perform the dump     and about the current state of the dump.  */
end_comment

begin_struct
struct|struct
name|dump_info
block|{
comment|/* The stream on which to dump the information.  */
name|FILE
modifier|*
name|stream
decl_stmt|;
comment|/* The original node.  */
name|tree
name|node
decl_stmt|;
comment|/* User flags.  */
name|int
name|flags
decl_stmt|;
comment|/* The next unused node index.  */
name|unsigned
name|int
name|index
decl_stmt|;
comment|/* The next column.  */
name|unsigned
name|int
name|column
decl_stmt|;
comment|/* The first node in the queue of nodes to be written out.  */
name|dump_queue_p
name|queue
decl_stmt|;
comment|/* The last node in the queue.  */
name|dump_queue_p
name|queue_end
decl_stmt|;
comment|/* Free queue nodes.  */
name|dump_queue_p
name|free_list
decl_stmt|;
comment|/* The tree nodes which we have already written out.  The       keys are the addresses of the nodes; the values are the integer      indices we assigned them.  */
name|splay_tree
name|nodes
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Dump the CHILD and its children.  */
end_comment

begin_define
define|#
directive|define
name|dump_child
parameter_list|(
name|field
parameter_list|,
name|child
parameter_list|)
define|\
value|queue_and_dump_index (di, field, child, DUMP_NONE)
end_define

begin_decl_stmt
specifier|extern
name|void
name|dump_pointer
name|PARAMS
argument_list|(
operator|(
name|dump_info_p
operator|,
specifier|const
name|char
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_int
name|PARAMS
argument_list|(
operator|(
name|dump_info_p
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_string
name|PARAMS
argument_list|(
operator|(
name|dump_info_p
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_stmt
name|PARAMS
argument_list|(
operator|(
name|dump_info_p
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_next_stmt
name|PARAMS
argument_list|(
operator|(
name|dump_info_p
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|queue_and_dump_index
name|PARAMS
argument_list|(
operator|(
name|dump_info_p
operator|,
specifier|const
name|char
operator|*
operator|,
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|queue_and_dump_type
name|PARAMS
argument_list|(
operator|(
name|dump_info_p
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_TREE_DUMP_H */
end_comment

end_unit

