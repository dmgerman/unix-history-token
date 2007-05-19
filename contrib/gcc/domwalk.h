begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Generic dominator tree walker    Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Diego Novillo<dnovillo@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|void_p
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|void_p
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|void_p
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* This is the main data structure for the dominator walker.  It provides    the callback hooks as well as a convenient place to hang block local    data and pass-global data.  */
end_comment

begin_struct
struct|struct
name|dom_walk_data
block|{
comment|/* This is the direction of the dominator tree we want to walk.  i.e.,      if it is set to CDI_DOMINATORS, then we walk the dominator tree,      if it is set to CDI_POST_DOMINATORS, then we walk the post      dominator tree.  */
name|ENUM_BITFIELD
argument_list|(
argument|cdi_direction
argument_list|)
name|dom_direction
label|:
literal|2
expr_stmt|;
comment|/* Nonzero if the statement walker should walk the statements from      last to first within a basic block instead of first to last.       Note this affects both statement walkers.  We haven't yet needed      to use the second statement walker for anything, so it's hard to      predict if we really need the ability to select their direction      independently.  */
name|BOOL_BITFIELD
name|walk_stmts_backward
range|:
literal|1
decl_stmt|;
comment|/* Function to initialize block local data.       Note that the dominator walker infrastructure may provide a new      fresh, and zero'd block local data structure, or it may re-use an      existing block local data structure.       If the block local structure has items such as virtual arrays, then      that allows your optimizer to re-use those arrays rather than      creating new ones.  */
name|void
function_decl|(
modifier|*
name|initialize_block_local_data
function_decl|)
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|bool
parameter_list|)
function_decl|;
comment|/* Function to call before the statement walk occurring before the      recursive walk of the dominator children.        This typically initializes a block local data and pushes that      data onto BLOCK_DATA_STACK.  */
name|void
function_decl|(
modifier|*
name|before_dom_children_before_stmts
function_decl|)
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
comment|/* Function to call to walk statements before the recursive walk      of the dominator children.  */
name|void
function_decl|(
modifier|*
name|before_dom_children_walk_stmts
function_decl|)
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|block_stmt_iterator
parameter_list|)
function_decl|;
comment|/* Function to call after the statement walk occurring before the      recursive walk of the dominator children.  */
name|void
function_decl|(
modifier|*
name|before_dom_children_after_stmts
function_decl|)
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
comment|/* Function to call before the statement walk occurring after the      recursive walk of the dominator children.  */
name|void
function_decl|(
modifier|*
name|after_dom_children_before_stmts
function_decl|)
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
comment|/* Function to call to walk statements after the recursive walk      of the dominator children.  */
name|void
function_decl|(
modifier|*
name|after_dom_children_walk_stmts
function_decl|)
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|block_stmt_iterator
parameter_list|)
function_decl|;
comment|/* Function to call after the statement walk occurring after the      recursive walk of the dominator children.        This typically finalizes any block local data and pops      that data from BLOCK_DATA_STACK.  */
name|void
function_decl|(
modifier|*
name|after_dom_children_after_stmts
function_decl|)
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
comment|/* Global data for a walk through the dominator tree.  */
name|void
modifier|*
name|global_data
decl_stmt|;
comment|/* Stack of any data we need to keep on a per-block basis.       If you have no local data, then BLOCK_DATA_STACK will be NULL.  */
name|VEC
argument_list|(
name|void_p
argument_list|,
name|heap
argument_list|)
operator|*
name|block_data_stack
expr_stmt|;
comment|/* Size of the block local data.   If this is zero, then it is assumed      you have no local data and thus no BLOCK_DATA_STACK as well.  */
name|size_t
name|block_local_data_size
decl_stmt|;
comment|/* From here below are private data.  Please do not use this      information/data outside domwalk.c.  */
comment|/* Stack of available block local structures.  */
name|VEC
argument_list|(
name|void_p
argument_list|,
name|heap
argument_list|)
operator|*
name|free_block_data
expr_stmt|;
comment|/* Interesting blocks to process.  If this field is not NULL, this      set is used to determine which blocks to walk.  If we encounter      block I in the dominator traversal, but block I is not present in      INTERESTING_BLOCKS, then none of the callback functions are      invoked on it.  This is useful when a particular traversal wants      to filter out non-interesting blocks from the dominator tree.  */
name|sbitmap
name|interesting_blocks
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|void
name|walk_dominator_tree
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|init_walk_dominator_tree
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fini_walk_dominator_tree
parameter_list|(
name|struct
name|dom_walk_data
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

