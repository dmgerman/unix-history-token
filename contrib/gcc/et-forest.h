begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Et-forest data structure implementation.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This package implements ET forest data structure. Each tree in    the structure maintains a tree structure and offers logarithmic time    for tree operations (insertion and removal of nodes and edges) and    poly-logarithmic time for nearest common ancestor.     ET tree stores its structure as a sequence of symbols obtained    by dfs(root)     dfs (node)    {      s = node;      for each child c of node do        s = concat (s, c, node);      return s;    }     For example for tree              1           / | \          2  3  4        / |       4  5     the sequence is 1 2 4 2 5 3 1 3 1 4 1.     The sequence is stored in a slightly modified splay tree.    In order to support various types of node values, a hashtable    is used to convert node values to the internal representation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ET_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|_ET_TREE_H
end_define

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
endif|#
directive|endif
comment|/* __cplusplus */
comment|/* The node representing the node in an et tree.  */
struct|struct
name|et_node
block|{
name|void
modifier|*
name|data
decl_stmt|;
comment|/* The data represented by the node.  */
name|int
name|dfs_num_in
decl_stmt|,
name|dfs_num_out
decl_stmt|;
comment|/* Number of the node in the dfs ordering.  */
name|struct
name|et_node
modifier|*
name|father
decl_stmt|;
comment|/* Father of the node.  */
name|struct
name|et_node
modifier|*
name|son
decl_stmt|;
comment|/* The first of the sons of the node.  */
name|struct
name|et_node
modifier|*
name|left
decl_stmt|;
name|struct
name|et_node
modifier|*
name|right
decl_stmt|;
comment|/* The brothers of the node.  */
name|struct
name|et_occ
modifier|*
name|rightmost_occ
decl_stmt|;
comment|/* The rightmost occurence.  */
name|struct
name|et_occ
modifier|*
name|parent_occ
decl_stmt|;
comment|/* The occurence of the parent node.  */
block|}
struct|;
name|struct
name|et_node
modifier|*
name|et_new_tree
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
name|void
name|et_free_tree
parameter_list|(
name|struct
name|et_node
modifier|*
parameter_list|)
function_decl|;
name|void
name|et_set_father
parameter_list|(
name|struct
name|et_node
modifier|*
parameter_list|,
name|struct
name|et_node
modifier|*
parameter_list|)
function_decl|;
name|void
name|et_split
parameter_list|(
name|struct
name|et_node
modifier|*
parameter_list|)
function_decl|;
name|struct
name|et_node
modifier|*
name|et_nca
parameter_list|(
name|struct
name|et_node
modifier|*
parameter_list|,
name|struct
name|et_node
modifier|*
parameter_list|)
function_decl|;
name|bool
name|et_below
parameter_list|(
name|struct
name|et_node
modifier|*
parameter_list|,
name|struct
name|et_node
modifier|*
parameter_list|)
function_decl|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ET_TREE_H */
end_comment

end_unit

