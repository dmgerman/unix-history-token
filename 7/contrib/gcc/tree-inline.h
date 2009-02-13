begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Tree inlining hooks and declarations.    Copyright 2001, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Alexandre Oliva<aoliva@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_TREE_INLINE_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_TREE_INLINE_H
end_define

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_include
include|#
directive|include
file|"splay-tree.h"
end_include

begin_comment
comment|/* Data required for function body duplication.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|copy_body_data
block|{
comment|/* FUNCTION_DECL for function being inlined, or in general the      source function providing the original trees.  */
name|tree
name|src_fn
decl_stmt|;
comment|/* FUNCTION_DECL for function being inlined into, or in general      the destination function receiving the new trees.  */
name|tree
name|dst_fn
decl_stmt|;
comment|/* Callgraph node of the source function.  */
name|struct
name|cgraph_node
modifier|*
name|src_node
decl_stmt|;
comment|/* Callgraph node of the destination function.  */
name|struct
name|cgraph_node
modifier|*
name|dst_node
decl_stmt|;
comment|/* struct function for function being inlined.  Usually this is the same      as DECL_STRUCT_FUNCTION (src_fn), but can be different if saved_cfg      and saved_eh are in use.  */
name|struct
name|function
modifier|*
name|src_cfun
decl_stmt|;
comment|/* The VAR_DECL for the return value.  */
name|tree
name|retvar
decl_stmt|;
comment|/* The map from local declarations in the inlined function to      equivalents in the function into which it is being inlined.  */
name|splay_tree
name|decl_map
decl_stmt|;
comment|/* Create a new decl to replace DECL in the destination function.  */
name|tree
function_decl|(
modifier|*
name|copy_decl
function_decl|)
parameter_list|(
name|tree
parameter_list|,
name|struct
name|copy_body_data
modifier|*
parameter_list|)
function_decl|;
comment|/* Current BLOCK.  */
name|tree
name|block
decl_stmt|;
comment|/* Exception region the inlined call lie in.  */
name|int
name|eh_region
decl_stmt|;
comment|/* Take region number in the function being copied, add this value and      get eh region number of the duplicate in the function we inline into.  */
name|int
name|eh_region_offset
decl_stmt|;
comment|/* We use the same mechanism do all sorts of different things.  Rather      than enumerating the different cases, we categorize the behavior      in the various situations.  */
comment|/* Indicate the desired behavior wrt call graph edges.  We can either      duplicate the edge (inlining, cloning), move the edge (versioning,      parallelization), or move the edges of the clones (saving).  */
enum|enum
name|copy_body_cge_which
block|{
name|CB_CGE_DUPLICATE
block|,
name|CB_CGE_MOVE
block|,
name|CB_CGE_MOVE_CLONES
block|}
name|transform_call_graph_edges
enum|;
comment|/* True if a new CFG should be created.  False for inlining, true for      everything else.  */
name|bool
name|transform_new_cfg
decl_stmt|;
comment|/* True if RETURN_EXPRs should be transformed to just the contained      MODIFY_EXPR.  The branch semantics of the return will be handled      by manipulating the CFG rather than a statement.  */
name|bool
name|transform_return_to_modify
decl_stmt|;
comment|/* True if lang_hooks.decls.insert_block should be invoked when      duplicating BLOCK nodes.  */
name|bool
name|transform_lang_insert_block
decl_stmt|;
block|}
name|copy_body_data
typedef|;
end_typedef

begin_comment
comment|/* Function prototypes.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|copy_body_r
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insert_decl_map
parameter_list|(
name|copy_body_data
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|optimize_inline_calls
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|tree_inlinable_function_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|tree
name|copy_tree_r
parameter_list|(
name|tree
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|clone_body
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|save_body
parameter_list|(
name|tree
parameter_list|,
name|tree
modifier|*
parameter_list|,
name|tree
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|estimate_move_cost
parameter_list|(
name|tree
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|push_cfun
parameter_list|(
name|struct
name|function
modifier|*
name|new_cfun
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pop_cfun
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|estimate_num_insns
parameter_list|(
name|tree
name|expr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|tree_versionable_function_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|tree_function_versioning
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|,
name|varray_type
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|remap_decl
parameter_list|(
name|tree
name|decl
parameter_list|,
name|copy_body_data
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tree
name|remap_type
parameter_list|(
name|tree
name|type
parameter_list|,
name|copy_body_data
modifier|*
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* 0 if we should not perform inlining.    1 if we should expand functions calls inline at the tree level.    2 if we should consider *all* functions to be inline    candidates.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_inline_trees
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_TREE_INLINE_H */
end_comment

end_unit

