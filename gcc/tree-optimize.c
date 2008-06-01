begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Top-level control of tree optimizations.    Copyright 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by Diego Novillo<dnovillo@redhat.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
end_include

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"tm_p.h"
end_include

begin_include
include|#
directive|include
file|"hard-reg-set.h"
end_include

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_include
include|#
directive|include
file|"output.h"
end_include

begin_include
include|#
directive|include
file|"expr.h"
end_include

begin_include
include|#
directive|include
file|"diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"tree-flow.h"
end_include

begin_include
include|#
directive|include
file|"tree-dump.h"
end_include

begin_include
include|#
directive|include
file|"timevar.h"
end_include

begin_include
include|#
directive|include
file|"function.h"
end_include

begin_include
include|#
directive|include
file|"langhooks.h"
end_include

begin_include
include|#
directive|include
file|"toplev.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"cgraph.h"
end_include

begin_include
include|#
directive|include
file|"tree-inline.h"
end_include

begin_include
include|#
directive|include
file|"tree-mudflap.h"
end_include

begin_include
include|#
directive|include
file|"tree-pass.h"
end_include

begin_include
include|#
directive|include
file|"ggc.h"
end_include

begin_include
include|#
directive|include
file|"cgraph.h"
end_include

begin_include
include|#
directive|include
file|"graph.h"
end_include

begin_include
include|#
directive|include
file|"cfgloop.h"
end_include

begin_include
include|#
directive|include
file|"except.h"
end_include

begin_comment
comment|/* Gate: execute, or not, all of the non-trivial optimizations.  */
end_comment

begin_function
specifier|static
name|bool
name|gate_all_optimizations
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|optimize
operator|>=
literal|1
comment|/* Don't bother doing anything if the program has errors.  */
operator|&&
operator|!
operator|(
name|errorcount
operator|||
name|sorrycount
operator|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_all_optimizations
init|=
block|{
name|NULL
block|,
comment|/* name */
name|gate_all_optimizations
block|,
comment|/* gate */
name|NULL
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
literal|0
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
literal|0
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_early_local_passes
init|=
block|{
name|NULL
block|,
comment|/* name */
name|gate_all_optimizations
block|,
comment|/* gate */
name|NULL
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
literal|0
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
literal|0
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pass: cleanup the CFG just before expanding trees to RTL.    This is just a round of label cleanups and case node grouping    because after the tree optimizers have run such cleanups may    be necessary.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|execute_cleanup_cfg_pre_ipa
parameter_list|(
name|void
parameter_list|)
block|{
name|cleanup_tree_cfg
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_cleanup_cfg
init|=
block|{
literal|"cleanup_cfg"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|execute_cleanup_cfg_pre_ipa
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
name|PROP_cfg
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
name|TODO_dump_func
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pass: cleanup the CFG just before expanding trees to RTL.    This is just a round of label cleanups and case node grouping    because after the tree optimizers have run such cleanups may    be necessary.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|execute_cleanup_cfg_post_optimizing
parameter_list|(
name|void
parameter_list|)
block|{
name|fold_cond_expr_cond
argument_list|()
expr_stmt|;
name|cleanup_tree_cfg
argument_list|()
expr_stmt|;
name|cleanup_dead_labels
argument_list|()
expr_stmt|;
name|group_case_labels
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_cleanup_cfg_post_optimizing
init|=
block|{
literal|"final_cleanup"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|execute_cleanup_cfg_post_optimizing
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
name|PROP_cfg
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
name|TODO_dump_func
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pass: do the actions required to finish with tree-ssa optimization    passes.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|execute_free_datastructures
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* ??? This isn't the right place for this.  Worse, it got computed      more or less at random in various passes.  */
name|free_dominance_info
argument_list|(
name|CDI_DOMINATORS
argument_list|)
expr_stmt|;
name|free_dominance_info
argument_list|(
name|CDI_POST_DOMINATORS
argument_list|)
expr_stmt|;
comment|/* Remove the ssa structures.  Do it here since this includes statement      annotations that need to be intact during disband_implicit_edges.  */
name|delete_tree_ssa
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_free_datastructures
init|=
block|{
name|NULL
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|execute_free_datastructures
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
name|PROP_cfg
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
literal|0
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Pass: free cfg annotations.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|execute_free_cfg_annotations
parameter_list|(
name|void
parameter_list|)
block|{
name|basic_block
name|bb
decl_stmt|;
name|block_stmt_iterator
name|bsi
decl_stmt|;
comment|/* Emit gotos for implicit jumps.  */
name|disband_implicit_edges
argument_list|()
expr_stmt|;
comment|/* Remove annotations from every tree in the function.  */
name|FOR_EACH_BB
argument_list|(
argument|bb
argument_list|)
for|for
control|(
name|bsi
operator|=
name|bsi_start
argument_list|(
name|bb
argument_list|)
init|;
operator|!
name|bsi_end_p
argument_list|(
name|bsi
argument_list|)
condition|;
name|bsi_next
argument_list|(
operator|&
name|bsi
argument_list|)
control|)
block|{
name|tree
name|stmt
init|=
name|bsi_stmt
argument_list|(
name|bsi
argument_list|)
decl_stmt|;
name|ggc_free
argument_list|(
name|stmt
operator|->
name|common
operator|.
name|ann
argument_list|)
expr_stmt|;
name|stmt
operator|->
name|common
operator|.
name|ann
operator|=
name|NULL
expr_stmt|;
block|}
comment|/* And get rid of annotations we no longer need.  */
name|delete_tree_cfg_annotations
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
comment|/* Once the statement annotations have been removed, we can verify      the integrity of statements in the EH throw table.  */
name|verify_eh_throw_table_statements
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_free_cfg_annotations
init|=
block|{
name|NULL
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|execute_free_cfg_annotations
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
name|PROP_cfg
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
literal|0
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return true if BB has at least one abnormal outgoing edge.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|has_abnormal_outgoing_edge_p
parameter_list|(
name|basic_block
name|bb
parameter_list|)
block|{
name|edge
name|e
decl_stmt|;
name|edge_iterator
name|ei
decl_stmt|;
name|FOR_EACH_EDGE
argument_list|(
argument|e
argument_list|,
argument|ei
argument_list|,
argument|bb->succs
argument_list|)
if|if
condition|(
name|e
operator|->
name|flags
operator|&
name|EDGE_ABNORMAL
condition|)
return|return
name|true
return|;
return|return
name|false
return|;
block|}
end_function

begin_comment
comment|/* Pass: fixup_cfg.  IPA passes, compilation of earlier functions or inlining    might have changed some properties, such as marked functions nothrow or    added calls that can potentially go to non-local labels.  Remove redundant    edges and basic blocks, and create new ones if necessary.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|execute_fixup_cfg
parameter_list|(
name|void
parameter_list|)
block|{
name|basic_block
name|bb
decl_stmt|;
name|block_stmt_iterator
name|bsi
decl_stmt|;
if|if
condition|(
name|cfun
operator|->
name|eh
condition|)
name|FOR_EACH_BB
argument_list|(
argument|bb
argument_list|)
block|{
for|for
control|(
name|bsi
operator|=
name|bsi_start
argument_list|(
name|bb
argument_list|)
init|;
operator|!
name|bsi_end_p
argument_list|(
name|bsi
argument_list|)
condition|;
name|bsi_next
argument_list|(
operator|&
name|bsi
argument_list|)
control|)
block|{
name|tree
name|stmt
init|=
name|bsi_stmt
argument_list|(
name|bsi
argument_list|)
decl_stmt|;
name|tree
name|call
init|=
name|get_call_expr_in
argument_list|(
name|stmt
argument_list|)
decl_stmt|;
if|if
condition|(
name|call
operator|&&
name|call_expr_flags
argument_list|(
name|call
argument_list|)
operator|&
operator|(
name|ECF_CONST
operator||
name|ECF_PURE
operator|)
condition|)
name|TREE_SIDE_EFFECTS
argument_list|(
name|call
argument_list|)
operator|=
literal|0
expr_stmt|;
if|if
condition|(
operator|!
name|tree_could_throw_p
argument_list|(
name|stmt
argument_list|)
operator|&&
name|lookup_stmt_eh_region
argument_list|(
name|stmt
argument_list|)
condition|)
name|remove_stmt_from_eh_region
argument_list|(
name|stmt
argument_list|)
expr_stmt|;
block|}
name|tree_purge_dead_eh_edges
argument_list|(
name|bb
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|current_function_has_nonlocal_label
condition|)
name|FOR_EACH_BB
argument_list|(
argument|bb
argument_list|)
block|{
for|for
control|(
name|bsi
operator|=
name|bsi_start
argument_list|(
name|bb
argument_list|)
init|;
operator|!
name|bsi_end_p
argument_list|(
name|bsi
argument_list|)
condition|;
name|bsi_next
argument_list|(
operator|&
name|bsi
argument_list|)
control|)
block|{
name|tree
name|stmt
init|=
name|bsi_stmt
argument_list|(
name|bsi
argument_list|)
decl_stmt|;
if|if
condition|(
name|tree_can_make_abnormal_goto
argument_list|(
name|stmt
argument_list|)
condition|)
block|{
if|if
condition|(
name|stmt
operator|==
name|bsi_stmt
argument_list|(
name|bsi_last
argument_list|(
name|bb
argument_list|)
argument_list|)
condition|)
block|{
if|if
condition|(
operator|!
name|has_abnormal_outgoing_edge_p
argument_list|(
name|bb
argument_list|)
condition|)
name|make_abnormal_goto_edges
argument_list|(
name|bb
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|edge
name|e
init|=
name|split_block
argument_list|(
name|bb
argument_list|,
name|stmt
argument_list|)
decl_stmt|;
name|bb
operator|=
name|e
operator|->
name|src
expr_stmt|;
name|make_abnormal_goto_edges
argument_list|(
name|bb
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
break|break;
block|}
block|}
block|}
name|cleanup_tree_cfg
argument_list|()
expr_stmt|;
comment|/* Dump a textual representation of the flowgraph.  */
if|if
condition|(
name|dump_file
condition|)
name|dump_tree_cfg
argument_list|(
name|dump_file
argument_list|,
name|dump_flags
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_fixup_cfg
init|=
block|{
literal|"fixupcfg"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|execute_fixup_cfg
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
name|PROP_cfg
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
literal|0
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Do the actions required to initialize internal data structures used    in tree-ssa optimization passes.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|execute_init_datastructures
parameter_list|(
name|void
parameter_list|)
block|{
comment|/* Allocate hash tables, arrays and other structures.  */
name|init_tree_ssa
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_init_datastructures
init|=
block|{
name|NULL
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|execute_init_datastructures
block|,
comment|/* execute */
name|NULL
block|,
comment|/* sub */
name|NULL
block|,
comment|/* next */
literal|0
block|,
comment|/* static_pass_number */
literal|0
block|,
comment|/* tv_id */
name|PROP_cfg
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
literal|0
block|,
comment|/* todo_flags_start */
literal|0
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|tree_lowering_passes
parameter_list|(
name|tree
name|fn
parameter_list|)
block|{
name|tree
name|saved_current_function_decl
init|=
name|current_function_decl
decl_stmt|;
name|current_function_decl
operator|=
name|fn
expr_stmt|;
name|push_cfun
argument_list|(
name|DECL_STRUCT_FUNCTION
argument_list|(
name|fn
argument_list|)
argument_list|)
expr_stmt|;
name|tree_register_cfg_hooks
argument_list|()
expr_stmt|;
name|bitmap_obstack_initialize
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|execute_pass_list
argument_list|(
name|all_lowering_passes
argument_list|)
expr_stmt|;
name|free_dominance_info
argument_list|(
name|CDI_POST_DOMINATORS
argument_list|)
expr_stmt|;
name|compact_blocks
argument_list|()
expr_stmt|;
name|current_function_decl
operator|=
name|saved_current_function_decl
expr_stmt|;
name|bitmap_obstack_release
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|pop_cfun
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Update recursively all inlined_to pointers of functions    inlined into NODE to INLINED_TO.  */
end_comment

begin_function
specifier|static
name|void
name|update_inlined_to_pointers
parameter_list|(
name|struct
name|cgraph_node
modifier|*
name|node
parameter_list|,
name|struct
name|cgraph_node
modifier|*
name|inlined_to
parameter_list|)
block|{
name|struct
name|cgraph_edge
modifier|*
name|e
decl_stmt|;
for|for
control|(
name|e
operator|=
name|node
operator|->
name|callees
init|;
name|e
condition|;
name|e
operator|=
name|e
operator|->
name|next_callee
control|)
block|{
if|if
condition|(
name|e
operator|->
name|callee
operator|->
name|global
operator|.
name|inlined_to
condition|)
block|{
name|e
operator|->
name|callee
operator|->
name|global
operator|.
name|inlined_to
operator|=
name|inlined_to
expr_stmt|;
name|update_inlined_to_pointers
argument_list|(
name|e
operator|->
name|callee
argument_list|,
name|inlined_to
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* For functions-as-trees languages, this performs all optimization and    compilation for FNDECL.  */
end_comment

begin_function
name|void
name|tree_rest_of_compilation
parameter_list|(
name|tree
name|fndecl
parameter_list|)
block|{
name|location_t
name|saved_loc
decl_stmt|;
name|struct
name|cgraph_node
modifier|*
name|node
decl_stmt|;
name|timevar_push
argument_list|(
name|TV_EXPAND
argument_list|)
expr_stmt|;
name|gcc_assert
argument_list|(
operator|!
name|flag_unit_at_a_time
operator|||
name|cgraph_global_info_ready
argument_list|)
expr_stmt|;
name|node
operator|=
name|cgraph_node
argument_list|(
name|fndecl
argument_list|)
expr_stmt|;
comment|/* We might need the body of this function so that we can expand      it inline somewhere else.  */
if|if
condition|(
name|cgraph_preserve_function_body_p
argument_list|(
name|fndecl
argument_list|)
condition|)
name|save_inline_function_body
argument_list|(
name|node
argument_list|)
expr_stmt|;
comment|/* Initialize the RTL code for the function.  */
name|current_function_decl
operator|=
name|fndecl
expr_stmt|;
name|saved_loc
operator|=
name|input_location
expr_stmt|;
name|input_location
operator|=
name|DECL_SOURCE_LOCATION
argument_list|(
name|fndecl
argument_list|)
expr_stmt|;
name|init_function_start
argument_list|(
name|fndecl
argument_list|)
expr_stmt|;
comment|/* Even though we're inside a function body, we still don't want to      call expand_expr to calculate the size of a variable-sized array.      We haven't necessarily assigned RTL to all variables yet, so it's      not safe to try to expand expressions involving them.  */
name|cfun
operator|->
name|x_dont_save_pending_sizes_p
operator|=
literal|1
expr_stmt|;
name|cfun
operator|->
name|after_inlining
operator|=
name|true
expr_stmt|;
if|if
condition|(
name|flag_inline_trees
condition|)
block|{
name|struct
name|cgraph_edge
modifier|*
name|e
decl_stmt|;
for|for
control|(
name|e
operator|=
name|node
operator|->
name|callees
init|;
name|e
condition|;
name|e
operator|=
name|e
operator|->
name|next_callee
control|)
if|if
condition|(
operator|!
name|e
operator|->
name|inline_failed
operator|||
name|warn_inline
condition|)
break|break;
if|if
condition|(
name|e
condition|)
block|{
name|timevar_push
argument_list|(
name|TV_INTEGRATION
argument_list|)
expr_stmt|;
name|optimize_inline_calls
argument_list|(
name|fndecl
argument_list|)
expr_stmt|;
name|timevar_pop
argument_list|(
name|TV_INTEGRATION
argument_list|)
expr_stmt|;
block|}
block|}
comment|/* In non-unit-at-a-time we must mark all referenced functions as needed.      */
if|if
condition|(
operator|!
name|flag_unit_at_a_time
condition|)
block|{
name|struct
name|cgraph_edge
modifier|*
name|e
decl_stmt|;
for|for
control|(
name|e
operator|=
name|node
operator|->
name|callees
init|;
name|e
condition|;
name|e
operator|=
name|e
operator|->
name|next_callee
control|)
if|if
condition|(
name|e
operator|->
name|callee
operator|->
name|analyzed
condition|)
name|cgraph_mark_needed_node
argument_list|(
name|e
operator|->
name|callee
argument_list|)
expr_stmt|;
block|}
comment|/* We are not going to maintain the cgraph edges up to date.      Kill it so it won't confuse us.  */
name|cgraph_node_remove_callees
argument_list|(
name|node
argument_list|)
expr_stmt|;
comment|/* Initialize the default bitmap obstack.  */
name|bitmap_obstack_initialize
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|bitmap_obstack_initialize
argument_list|(
operator|&
name|reg_obstack
argument_list|)
expr_stmt|;
comment|/* FIXME, only at RTL generation*/
name|tree_register_cfg_hooks
argument_list|()
expr_stmt|;
comment|/* Perform all tree transforms and optimizations.  */
name|execute_pass_list
argument_list|(
name|all_passes
argument_list|)
expr_stmt|;
name|bitmap_obstack_release
argument_list|(
operator|&
name|reg_obstack
argument_list|)
expr_stmt|;
comment|/* Release the default bitmap obstack.  */
name|bitmap_obstack_release
argument_list|(
name|NULL
argument_list|)
expr_stmt|;
name|DECL_SAVED_TREE
argument_list|(
name|fndecl
argument_list|)
operator|=
name|NULL
expr_stmt|;
name|cfun
operator|=
literal|0
expr_stmt|;
comment|/* If requested, warn about function definitions where the function will      return a value (usually of some struct or union type) which itself will      take up a lot of stack space.  */
if|if
condition|(
name|warn_larger_than
operator|&&
operator|!
name|DECL_EXTERNAL
argument_list|(
name|fndecl
argument_list|)
operator|&&
name|TREE_TYPE
argument_list|(
name|fndecl
argument_list|)
condition|)
block|{
name|tree
name|ret_type
init|=
name|TREE_TYPE
argument_list|(
name|TREE_TYPE
argument_list|(
name|fndecl
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|ret_type
operator|&&
name|TYPE_SIZE_UNIT
argument_list|(
name|ret_type
argument_list|)
operator|&&
name|TREE_CODE
argument_list|(
name|TYPE_SIZE_UNIT
argument_list|(
name|ret_type
argument_list|)
argument_list|)
operator|==
name|INTEGER_CST
operator|&&
literal|0
operator|<
name|compare_tree_int
argument_list|(
name|TYPE_SIZE_UNIT
argument_list|(
name|ret_type
argument_list|)
argument_list|,
name|larger_than_size
argument_list|)
condition|)
block|{
name|unsigned
name|int
name|size_as_int
init|=
name|TREE_INT_CST_LOW
argument_list|(
name|TYPE_SIZE_UNIT
argument_list|(
name|ret_type
argument_list|)
argument_list|)
decl_stmt|;
if|if
condition|(
name|compare_tree_int
argument_list|(
name|TYPE_SIZE_UNIT
argument_list|(
name|ret_type
argument_list|)
argument_list|,
name|size_as_int
argument_list|)
operator|==
literal|0
condition|)
name|warning
argument_list|(
literal|0
argument_list|,
literal|"size of return value of %q+D is %u bytes"
argument_list|,
name|fndecl
argument_list|,
name|size_as_int
argument_list|)
expr_stmt|;
else|else
name|warning
argument_list|(
literal|0
argument_list|,
literal|"size of return value of %q+D is larger than %wd bytes"
argument_list|,
name|fndecl
argument_list|,
name|larger_than_size
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|flag_inline_trees
condition|)
block|{
name|DECL_SAVED_TREE
argument_list|(
name|fndecl
argument_list|)
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|DECL_STRUCT_FUNCTION
argument_list|(
name|fndecl
argument_list|)
operator|==
literal|0
operator|&&
operator|!
name|cgraph_node
argument_list|(
name|fndecl
argument_list|)
operator|->
name|origin
condition|)
block|{
comment|/* Stop pointing to the local nodes about to be freed. 	     But DECL_INITIAL must remain nonzero so we know this 	     was an actual function definition. 	     For a nested function, this is done in c_pop_function_context. 	     If rest_of_compilation set this to 0, leave it 0.  */
if|if
condition|(
name|DECL_INITIAL
argument_list|(
name|fndecl
argument_list|)
operator|!=
literal|0
condition|)
name|DECL_INITIAL
argument_list|(
name|fndecl
argument_list|)
operator|=
name|error_mark_node
expr_stmt|;
block|}
block|}
name|input_location
operator|=
name|saved_loc
expr_stmt|;
name|ggc_collect
argument_list|()
expr_stmt|;
name|timevar_pop
argument_list|(
name|TV_EXPAND
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

