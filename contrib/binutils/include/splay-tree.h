begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A splay-tree datatype.      Copyright 1998, 1999, 2000 Free Software Foundation, Inc.    Contributed by Mark Mitchell (mark@markmitchell.com).  This file is part of GNU CC.     GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* For an easily readable description of splay-trees, see:       Lewis, Harry R. and Denenberg, Larry.  Data Structures and Their      Algorithms.  Harper-Collins, Inc.  1991.       The major feature of splay trees is that all basic tree operations    are amortized O(log n) time for a tree with n nodes.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SPLAY_TREE_H
end_ifndef

begin_define
define|#
directive|define
name|_SPLAY_TREE_H
end_define

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
include|#
directive|include
file|<ansidecl.h>
comment|/* Use typedefs for the key and data types to facilitate changing    these types, if necessary.  These types should be sufficiently wide    that any pointer or scalar can be cast to these types, and then    cast back, without loss of precision.  */
typedef|typedef
name|unsigned
name|long
name|int
name|splay_tree_key
typedef|;
typedef|typedef
name|unsigned
name|long
name|int
name|splay_tree_value
typedef|;
comment|/* Forward declaration for a node in the tree.  */
typedef|typedef
name|struct
name|splay_tree_node_s
modifier|*
name|splay_tree_node
typedef|;
comment|/* The type of a function which compares two splay-tree keys.  The    function should return values as for qsort.  */
typedef|typedef
name|int
argument_list|(
argument|*splay_tree_compare_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|splay_tree_key
operator|,
name|splay_tree_key
operator|)
argument_list|)
expr_stmt|;
comment|/* The type of a function used to deallocate any resources associated    with the key.  */
typedef|typedef
name|void
argument_list|(
argument|*splay_tree_delete_key_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|splay_tree_key
operator|)
argument_list|)
expr_stmt|;
comment|/* The type of a function used to deallocate any resources associated    with the value.  */
typedef|typedef
name|void
argument_list|(
argument|*splay_tree_delete_value_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|splay_tree_value
operator|)
argument_list|)
expr_stmt|;
comment|/* The type of a function used to iterate over the tree.  */
typedef|typedef
name|int
argument_list|(
argument|*splay_tree_foreach_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|splay_tree_node
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
comment|/* The nodes in the splay tree.  */
struct|struct
name|splay_tree_node_s
block|{
comment|/* The key.  */
name|splay_tree_key
name|key
decl_stmt|;
comment|/* The value.  */
name|splay_tree_value
name|value
decl_stmt|;
comment|/* The left and right children, respectively.  */
name|splay_tree_node
name|left
decl_stmt|;
name|splay_tree_node
name|right
decl_stmt|;
block|}
struct|;
comment|/* The splay tree itself.  */
typedef|typedef
struct|struct
name|splay_tree_s
block|{
comment|/* The root of the tree.  */
name|splay_tree_node
name|root
decl_stmt|;
comment|/* The comparision function.  */
name|splay_tree_compare_fn
name|comp
decl_stmt|;
comment|/* The deallocate-key function.  NULL if no cleanup is necessary.  */
name|splay_tree_delete_key_fn
name|delete_key
decl_stmt|;
comment|/* The deallocate-value function.  NULL if no cleanup is necessary.  */
name|splay_tree_delete_value_fn
name|delete_value
decl_stmt|;
block|}
typedef|*
name|splay_tree
typedef|;
specifier|extern
name|splay_tree
name|splay_tree_new
name|PARAMS
argument_list|(
operator|(
name|splay_tree_compare_fn
operator|,
name|splay_tree_delete_key_fn
operator|,
name|splay_tree_delete_value_fn
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|splay_tree_delete
name|PARAMS
argument_list|(
operator|(
name|splay_tree
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|splay_tree_node
name|splay_tree_insert
name|PARAMS
argument_list|(
operator|(
name|splay_tree
operator|,
name|splay_tree_key
operator|,
name|splay_tree_value
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|void
name|splay_tree_remove
name|PARAMS
argument_list|(
operator|(
name|splay_tree
operator|,
name|splay_tree_key
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|splay_tree_node
name|splay_tree_lookup
name|PARAMS
argument_list|(
operator|(
name|splay_tree
operator|,
name|splay_tree_key
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|splay_tree_node
name|splay_tree_predecessor
name|PARAMS
argument_list|(
operator|(
name|splay_tree
operator|,
name|splay_tree_key
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|splay_tree_node
name|splay_tree_successor
name|PARAMS
argument_list|(
operator|(
name|splay_tree
operator|,
name|splay_tree_key
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|splay_tree_foreach
name|PARAMS
argument_list|(
operator|(
name|splay_tree
operator|,
name|splay_tree_foreach_fn
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|splay_tree_compare_ints
name|PARAMS
argument_list|(
operator|(
name|splay_tree_key
operator|,
name|splay_tree_key
operator|)
argument_list|)
decl_stmt|;
specifier|extern
name|int
name|splay_tree_compare_pointers
name|PARAMS
argument_list|(
operator|(
name|splay_tree_key
operator|,
name|splay_tree_key
operator|)
argument_list|)
decl_stmt|;
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
comment|/* _SPLAY_TREE_H */
end_comment

end_unit

