begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Loop optimizer initialization routines and RTL loop optimization passes.    Copyright (C) 2002, 2003, 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"rtl.h"
end_include

begin_include
include|#
directive|include
file|"hard-reg-set.h"
end_include

begin_include
include|#
directive|include
file|"obstack.h"
end_include

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_include
include|#
directive|include
file|"cfgloop.h"
end_include

begin_include
include|#
directive|include
file|"cfglayout.h"
end_include

begin_include
include|#
directive|include
file|"tree-pass.h"
end_include

begin_include
include|#
directive|include
file|"timevar.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Initialize loop optimizer.  This is used by the tree and RTL loop    optimizers.  FLAGS specify what properties to compute and/or ensure for    loops.  */
end_comment

begin_function
name|struct
name|loops
modifier|*
name|loop_optimizer_init
parameter_list|(
name|unsigned
name|flags
parameter_list|)
block|{
name|struct
name|loops
modifier|*
name|loops
init|=
name|XCNEW
argument_list|(
expr|struct
name|loops
argument_list|)
decl_stmt|;
name|edge
name|e
decl_stmt|;
name|edge_iterator
name|ei
decl_stmt|;
specifier|static
name|bool
name|first_time
init|=
name|true
decl_stmt|;
if|if
condition|(
name|first_time
condition|)
block|{
name|first_time
operator|=
name|false
expr_stmt|;
name|init_set_costs
argument_list|()
expr_stmt|;
block|}
comment|/* Avoid annoying special cases of edges going to exit      block.  */
for|for
control|(
name|ei
operator|=
name|ei_start
argument_list|(
name|EXIT_BLOCK_PTR
operator|->
name|preds
argument_list|)
init|;
operator|(
name|e
operator|=
name|ei_safe_edge
argument_list|(
name|ei
argument_list|)
operator|)
condition|;
control|)
if|if
condition|(
operator|(
name|e
operator|->
name|flags
operator|&
name|EDGE_FALLTHRU
operator|)
operator|&&
operator|!
name|single_succ_p
argument_list|(
name|e
operator|->
name|src
argument_list|)
condition|)
name|split_edge
argument_list|(
name|e
argument_list|)
expr_stmt|;
else|else
name|ei_next
argument_list|(
operator|&
name|ei
argument_list|)
expr_stmt|;
comment|/* Find the loops.  */
if|if
condition|(
name|flow_loops_find
argument_list|(
name|loops
argument_list|)
operator|<=
literal|1
condition|)
block|{
comment|/* No loops.  */
name|flow_loops_free
argument_list|(
name|loops
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|loops
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
comment|/* Not going to update these.  */
name|free
argument_list|(
name|loops
operator|->
name|cfg
operator|.
name|rc_order
argument_list|)
expr_stmt|;
name|loops
operator|->
name|cfg
operator|.
name|rc_order
operator|=
name|NULL
expr_stmt|;
name|free
argument_list|(
name|loops
operator|->
name|cfg
operator|.
name|dfs_order
argument_list|)
expr_stmt|;
name|loops
operator|->
name|cfg
operator|.
name|dfs_order
operator|=
name|NULL
expr_stmt|;
comment|/* Create pre-headers.  */
if|if
condition|(
name|flags
operator|&
name|LOOPS_HAVE_PREHEADERS
condition|)
name|create_preheaders
argument_list|(
name|loops
argument_list|,
name|CP_SIMPLE_PREHEADERS
argument_list|)
expr_stmt|;
comment|/* Force all latches to have only single successor.  */
if|if
condition|(
name|flags
operator|&
name|LOOPS_HAVE_SIMPLE_LATCHES
condition|)
name|force_single_succ_latches
argument_list|(
name|loops
argument_list|)
expr_stmt|;
comment|/* Mark irreducible loops.  */
if|if
condition|(
name|flags
operator|&
name|LOOPS_HAVE_MARKED_IRREDUCIBLE_REGIONS
condition|)
name|mark_irreducible_loops
argument_list|(
name|loops
argument_list|)
expr_stmt|;
if|if
condition|(
name|flags
operator|&
name|LOOPS_HAVE_MARKED_SINGLE_EXITS
condition|)
name|mark_single_exit_loops
argument_list|(
name|loops
argument_list|)
expr_stmt|;
comment|/* Dump loops.  */
name|flow_loops_dump
argument_list|(
name|loops
argument_list|,
name|dump_file
argument_list|,
name|NULL
argument_list|,
literal|1
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
name|verify_dominators
argument_list|(
name|CDI_DOMINATORS
argument_list|)
expr_stmt|;
name|verify_loop_structure
argument_list|(
name|loops
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|loops
return|;
block|}
end_function

begin_comment
comment|/* Finalize loop optimizer.  */
end_comment

begin_function
name|void
name|loop_optimizer_finalize
parameter_list|(
name|struct
name|loops
modifier|*
name|loops
parameter_list|)
block|{
name|unsigned
name|i
decl_stmt|;
if|if
condition|(
operator|!
name|loops
condition|)
return|return;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|loops
operator|->
name|num
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|loops
operator|->
name|parray
index|[
name|i
index|]
condition|)
name|free_simple_loop_desc
argument_list|(
name|loops
operator|->
name|parray
index|[
name|i
index|]
argument_list|)
expr_stmt|;
comment|/* Clean up.  */
name|flow_loops_free
argument_list|(
name|loops
argument_list|)
expr_stmt|;
name|free
argument_list|(
name|loops
argument_list|)
expr_stmt|;
comment|/* Checking.  */
ifdef|#
directive|ifdef
name|ENABLE_CHECKING
name|verify_flow_info
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_escape
end_escape

begin_comment
comment|/* Gate for the RTL loop superpass.  The actual passes are subpasses.    See passes.c for more on that.  */
end_comment

begin_function
specifier|static
name|bool
name|gate_handle_loop2
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|optimize
operator|>
literal|0
operator|&&
operator|(
name|flag_move_loop_invariants
operator|||
name|flag_unswitch_loops
operator|||
name|flag_peel_loops
operator|||
name|flag_unroll_loops
ifdef|#
directive|ifdef
name|HAVE_doloop_end
operator|||
operator|(
name|flag_branch_on_count_reg
operator|&&
name|HAVE_doloop_end
operator|)
endif|#
directive|endif
operator|)
operator|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_loop2
init|=
block|{
literal|"loop2"
block|,
comment|/* name */
name|gate_handle_loop2
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
name|TV_LOOP
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
name|TODO_dump_func
operator||
name|TODO_ggc_collect
block|,
comment|/* todo_flags_finish */
literal|'L'
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Initialization of the RTL loop passes.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|rtl_loop_init
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|dump_file
condition|)
name|dump_flow_info
argument_list|(
name|dump_file
argument_list|,
name|dump_flags
argument_list|)
expr_stmt|;
comment|/* Initialize structures for layout changes.  */
name|cfg_layout_initialize
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|current_loops
operator|=
name|loop_optimizer_init
argument_list|(
name|LOOPS_NORMAL
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
name|pass_rtl_loop_init
init|=
block|{
literal|"loop2_init"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|rtl_loop_init
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
name|TV_LOOP
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
name|TODO_dump_func
block|,
comment|/* todo_flags_finish */
literal|'L'
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Finalization of the RTL loop passes.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|rtl_loop_done
parameter_list|(
name|void
parameter_list|)
block|{
name|basic_block
name|bb
decl_stmt|;
if|if
condition|(
name|current_loops
condition|)
name|loop_optimizer_finalize
argument_list|(
name|current_loops
argument_list|)
expr_stmt|;
name|free_dominance_info
argument_list|(
name|CDI_DOMINATORS
argument_list|)
expr_stmt|;
comment|/* Finalize layout changes.  */
name|FOR_EACH_BB
argument_list|(
argument|bb
argument_list|)
if|if
condition|(
name|bb
operator|->
name|next_bb
operator|!=
name|EXIT_BLOCK_PTR
condition|)
name|bb
operator|->
name|aux
operator|=
name|bb
operator|->
name|next_bb
expr_stmt|;
name|cfg_layout_finalize
argument_list|()
expr_stmt|;
name|cleanup_cfg
argument_list|(
name|CLEANUP_EXPENSIVE
argument_list|)
expr_stmt|;
name|delete_trivially_dead_insns
argument_list|(
name|get_insns
argument_list|()
argument_list|,
name|max_reg_num
argument_list|()
argument_list|)
expr_stmt|;
name|reg_scan
argument_list|(
name|get_insns
argument_list|()
argument_list|,
name|max_reg_num
argument_list|()
argument_list|)
expr_stmt|;
if|if
condition|(
name|dump_file
condition|)
name|dump_flow_info
argument_list|(
name|dump_file
argument_list|,
name|dump_flags
argument_list|)
expr_stmt|;
name|current_loops
operator|=
name|NULL
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_rtl_loop_done
init|=
block|{
literal|"loop2_done"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|rtl_loop_done
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
name|TV_LOOP
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
name|TODO_dump_func
block|,
comment|/* todo_flags_finish */
literal|'L'
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Loop invariant code motion.  */
end_comment

begin_function
specifier|static
name|bool
name|gate_rtl_move_loop_invariants
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_move_loop_invariants
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|int
name|rtl_move_loop_invariants
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|current_loops
condition|)
name|move_loop_invariants
argument_list|(
name|current_loops
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
name|pass_rtl_move_loop_invariants
init|=
block|{
literal|"loop2_invariant"
block|,
comment|/* name */
name|gate_rtl_move_loop_invariants
block|,
comment|/* gate */
name|rtl_move_loop_invariants
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
name|TV_LOOP
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
name|TODO_dump_func
block|,
comment|/* todo_flags_finish */
literal|'L'
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Loop unswitching for RTL.  */
end_comment

begin_function
specifier|static
name|bool
name|gate_rtl_unswitch
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_unswitch_loops
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|int
name|rtl_unswitch
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|current_loops
condition|)
name|unswitch_loops
argument_list|(
name|current_loops
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
name|pass_rtl_unswitch
init|=
block|{
literal|"loop2_unswitch"
block|,
comment|/* name */
name|gate_rtl_unswitch
block|,
comment|/* gate */
name|rtl_unswitch
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
name|TV_LOOP
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
name|TODO_dump_func
block|,
comment|/* todo_flags_finish */
literal|'L'
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Loop unswitching for RTL.  */
end_comment

begin_function
specifier|static
name|bool
name|gate_rtl_unroll_and_peel_loops
parameter_list|(
name|void
parameter_list|)
block|{
return|return
operator|(
name|flag_peel_loops
operator|||
name|flag_unroll_loops
operator|||
name|flag_unroll_all_loops
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|unsigned
name|int
name|rtl_unroll_and_peel_loops
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|current_loops
condition|)
block|{
name|int
name|flags
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|flag_peel_loops
condition|)
name|flags
operator||=
name|UAP_PEEL
expr_stmt|;
if|if
condition|(
name|flag_unroll_loops
condition|)
name|flags
operator||=
name|UAP_UNROLL
expr_stmt|;
if|if
condition|(
name|flag_unroll_all_loops
condition|)
name|flags
operator||=
name|UAP_UNROLL_ALL
expr_stmt|;
name|unroll_and_peel_loops
argument_list|(
name|current_loops
argument_list|,
name|flags
argument_list|)
expr_stmt|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_rtl_unroll_and_peel_loops
init|=
block|{
literal|"loop2_unroll"
block|,
comment|/* name */
name|gate_rtl_unroll_and_peel_loops
block|,
comment|/* gate */
name|rtl_unroll_and_peel_loops
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
name|TV_LOOP
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
name|TODO_dump_func
block|,
comment|/* todo_flags_finish */
literal|'L'
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* The doloop optimization.  */
end_comment

begin_function
specifier|static
name|bool
name|gate_rtl_doloop
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_doloop_end
return|return
operator|(
name|flag_branch_on_count_reg
operator|&&
name|HAVE_doloop_end
operator|)
return|;
else|#
directive|else
return|return
literal|0
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|static
name|unsigned
name|int
name|rtl_doloop
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|HAVE_doloop_end
if|if
condition|(
name|current_loops
condition|)
name|doloop_optimize_loops
argument_list|(
name|current_loops
argument_list|)
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
name|pass_rtl_doloop
init|=
block|{
literal|"loop2_doloop"
block|,
comment|/* name */
name|gate_rtl_doloop
block|,
comment|/* gate */
name|rtl_doloop
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
name|TV_LOOP
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
name|TODO_dump_func
block|,
comment|/* todo_flags_finish */
literal|'L'
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

end_unit

