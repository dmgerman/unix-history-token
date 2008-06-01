begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Loop optimizations over tree-ssa.    Copyright (C) 2003, 2005 Free Software Foundation, Inc.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.     You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"diagnostic.h"
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
file|"cfgloop.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"tree-inline.h"
end_include

begin_include
include|#
directive|include
file|"tree-scalar-evolution.h"
end_include

begin_comment
comment|/* The loop tree currently optimized.  */
end_comment

begin_decl_stmt
name|struct
name|loops
modifier|*
name|current_loops
init|=
name|NULL
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initializes the loop structures.  */
end_comment

begin_function
specifier|static
name|struct
name|loops
modifier|*
name|tree_loop_optimizer_init
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|loops
modifier|*
name|loops
decl_stmt|;
name|loops
operator|=
name|loop_optimizer_init
argument_list|(
name|LOOPS_NORMAL
operator||
name|LOOPS_HAVE_MARKED_SINGLE_EXITS
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|loops
condition|)
return|return
name|NULL
return|;
name|rewrite_into_loop_closed_ssa
argument_list|(
name|NULL
argument_list|,
name|TODO_update_ssa
argument_list|)
expr_stmt|;
return|return
name|loops
return|;
block|}
end_function

begin_comment
comment|/* The loop superpass.  */
end_comment

begin_function
specifier|static
name|bool
name|gate_tree_loop
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_tree_loop_optimize
operator|!=
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_tree_loop
init|=
block|{
literal|"loop"
block|,
comment|/* name */
name|gate_tree_loop
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
name|TV_TREE_LOOP
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
name|TODO_ggc_collect
block|,
comment|/* todo_flags_start */
name|TODO_dump_func
operator||
name|TODO_verify_ssa
operator||
name|TODO_ggc_collect
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Loop optimizer initialization.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_ssa_loop_init
parameter_list|(
name|void
parameter_list|)
block|{
name|current_loops
operator|=
name|tree_loop_optimizer_init
argument_list|()
expr_stmt|;
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
name|scev_initialize
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
name|pass_tree_loop_init
init|=
block|{
literal|"loopinit"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|tree_ssa_loop_init
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
name|TV_TREE_LOOP_INIT
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
operator||
name|TODO_verify_loops
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Loop invariant motion pass.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_ssa_loop_im
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
name|tree_ssa_lim
argument_list|(
name|current_loops
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|gate_tree_ssa_loop_im
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_tree_loop_im
operator|!=
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_lim
init|=
block|{
literal|"lim"
block|,
comment|/* name */
name|gate_tree_ssa_loop_im
block|,
comment|/* gate */
name|tree_ssa_loop_im
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
name|TV_LIM
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
operator||
name|TODO_verify_loops
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Loop unswitching pass.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_ssa_loop_unswitch
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
return|return
name|tree_ssa_unswitch_loops
argument_list|(
name|current_loops
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|gate_tree_ssa_loop_unswitch
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_unswitch_loops
operator|!=
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_tree_unswitch
init|=
block|{
literal|"unswitch"
block|,
comment|/* name */
name|gate_tree_ssa_loop_unswitch
block|,
comment|/* gate */
name|tree_ssa_loop_unswitch
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
name|TV_TREE_LOOP_UNSWITCH
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
operator||
name|TODO_verify_loops
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Loop autovectorization.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_vectorize
parameter_list|(
name|void
parameter_list|)
block|{
name|vectorize_loops
argument_list|(
name|current_loops
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|gate_tree_vectorize
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_tree_vectorize
operator|&&
name|current_loops
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_vectorize
init|=
block|{
literal|"vect"
block|,
comment|/* name */
name|gate_tree_vectorize
block|,
comment|/* gate */
name|tree_vectorize
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
name|TV_TREE_VECTORIZATION
block|,
comment|/* tv_id */
name|PROP_cfg
operator||
name|PROP_ssa
block|,
comment|/* properties_required */
literal|0
block|,
comment|/* properties_provided */
literal|0
block|,
comment|/* properties_destroyed */
name|TODO_verify_loops
block|,
comment|/* todo_flags_start */
name|TODO_dump_func
operator||
name|TODO_update_ssa
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Loop nest optimizations.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_linear_transform
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
name|linear_transform_loops
argument_list|(
name|current_loops
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|gate_tree_linear_transform
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_tree_loop_linear
operator|!=
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_linear_transform
init|=
block|{
literal|"ltrans"
block|,
comment|/* name */
name|gate_tree_linear_transform
block|,
comment|/* gate */
name|tree_linear_transform
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
name|TV_TREE_LINEAR_TRANSFORM
block|,
comment|/* tv_id */
name|PROP_cfg
operator||
name|PROP_ssa
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
name|TODO_verify_loops
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Canonical induction variable creation pass.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_ssa_loop_ivcanon
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
return|return
name|canonicalize_induction_variables
argument_list|(
name|current_loops
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|gate_tree_ssa_loop_ivcanon
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_tree_loop_ivcanon
operator|!=
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_iv_canon
init|=
block|{
literal|"ivcanon"
block|,
comment|/* name */
name|gate_tree_ssa_loop_ivcanon
block|,
comment|/* gate */
name|tree_ssa_loop_ivcanon
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
name|TV_TREE_LOOP_IVCANON
block|,
comment|/* tv_id */
name|PROP_cfg
operator||
name|PROP_ssa
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
name|TODO_verify_loops
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Propagation of constants using scev.  */
end_comment

begin_function
specifier|static
name|bool
name|gate_scev_const_prop
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_scev_cprop
init|=
block|{
literal|"sccp"
block|,
comment|/* name */
name|gate_scev_const_prop
block|,
comment|/* gate */
name|scev_const_prop
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
name|TV_SCEV_CONST
block|,
comment|/* tv_id */
name|PROP_cfg
operator||
name|PROP_ssa
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
name|TODO_cleanup_cfg
operator||
name|TODO_update_ssa_only_virtuals
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Remove empty loops.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_ssa_empty_loop
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
return|return
name|remove_empty_loops
argument_list|(
name|current_loops
argument_list|)
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_empty_loop
init|=
block|{
literal|"empty"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|tree_ssa_empty_loop
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
name|TV_COMPLETE_UNROLL
block|,
comment|/* tv_id */
name|PROP_cfg
operator||
name|PROP_ssa
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
name|TODO_verify_loops
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record bounds on numbers of iterations of loops.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_ssa_loop_bounds
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
name|estimate_numbers_of_iterations
argument_list|(
name|current_loops
argument_list|)
expr_stmt|;
name|scev_reset
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
name|pass_record_bounds
init|=
block|{
name|NULL
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|tree_ssa_loop_bounds
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
name|TV_TREE_LOOP_BOUNDS
block|,
comment|/* tv_id */
name|PROP_cfg
operator||
name|PROP_ssa
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
comment|/* Complete unrolling of loops.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_complete_unroll
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
return|return
name|tree_unroll_loops_completely
argument_list|(
name|current_loops
argument_list|,
name|flag_unroll_loops
operator|||
name|flag_peel_loops
operator|||
name|optimize
operator|>=
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|gate_tree_complete_unroll
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|true
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_complete_unroll
init|=
block|{
literal|"cunroll"
block|,
comment|/* name */
name|gate_tree_complete_unroll
block|,
comment|/* gate */
name|tree_complete_unroll
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
name|TV_COMPLETE_UNROLL
block|,
comment|/* tv_id */
name|PROP_cfg
operator||
name|PROP_ssa
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
name|TODO_verify_loops
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Prefetching.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_ssa_loop_prefetch
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
return|return
name|tree_ssa_prefetch_arrays
argument_list|(
name|current_loops
argument_list|)
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|gate_tree_ssa_loop_prefetch
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_prefetch_loop_arrays
operator|!=
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_loop_prefetch
init|=
block|{
literal|"prefetch"
block|,
comment|/* name */
name|gate_tree_ssa_loop_prefetch
block|,
comment|/* gate */
name|tree_ssa_loop_prefetch
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
name|TV_TREE_PREFETCH
block|,
comment|/* tv_id */
name|PROP_cfg
operator||
name|PROP_ssa
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
name|TODO_verify_loops
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Induction variable optimizations.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_ssa_loop_ivopts
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
name|tree_ssa_iv_optimize
argument_list|(
name|current_loops
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

begin_function
specifier|static
name|bool
name|gate_tree_ssa_loop_ivopts
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|flag_ivopts
operator|!=
literal|0
return|;
block|}
end_function

begin_decl_stmt
name|struct
name|tree_opt_pass
name|pass_iv_optimize
init|=
block|{
literal|"ivopts"
block|,
comment|/* name */
name|gate_tree_ssa_loop_ivopts
block|,
comment|/* gate */
name|tree_ssa_loop_ivopts
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
name|TV_TREE_LOOP_IVOPTS
block|,
comment|/* tv_id */
name|PROP_cfg
operator||
name|PROP_ssa
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
name|TODO_verify_loops
operator||
name|TODO_update_ssa
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Loop optimizer finalization.  */
end_comment

begin_function
specifier|static
name|unsigned
name|int
name|tree_ssa_loop_done
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|current_loops
condition|)
return|return
literal|0
return|;
name|free_numbers_of_iterations_estimates
argument_list|(
name|current_loops
argument_list|)
expr_stmt|;
name|scev_finalize
argument_list|()
expr_stmt|;
name|loop_optimizer_finalize
argument_list|(
name|current_loops
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
name|pass_tree_loop_done
init|=
block|{
literal|"loopdone"
block|,
comment|/* name */
name|NULL
block|,
comment|/* gate */
name|tree_ssa_loop_done
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
name|TV_TREE_LOOP_FINI
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
name|TODO_cleanup_cfg
operator||
name|TODO_dump_func
block|,
comment|/* todo_flags_finish */
literal|0
comment|/* letter */
block|}
decl_stmt|;
end_decl_stmt

end_unit

