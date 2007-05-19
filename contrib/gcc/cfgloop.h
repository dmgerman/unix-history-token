begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Natural loop functions    Copyright (C) 1987, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_CFGLOOP_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_CFGLOOP_H
end_define

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_comment
comment|/* For rtx_code.  */
end_comment

begin_include
include|#
directive|include
file|"rtl.h"
end_include

begin_comment
comment|/* Structure to hold decision about unrolling/peeling.  */
end_comment

begin_enum
enum|enum
name|lpt_dec
block|{
name|LPT_NONE
block|,
name|LPT_PEEL_COMPLETELY
block|,
name|LPT_PEEL_SIMPLE
block|,
name|LPT_UNROLL_CONSTANT
block|,
name|LPT_UNROLL_RUNTIME
block|,
name|LPT_UNROLL_STUPID
block|}
enum|;
end_enum

begin_struct
struct|struct
name|lpt_decision
block|{
name|enum
name|lpt_dec
name|decision
decl_stmt|;
name|unsigned
name|times
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The structure describing a bound on number of iterations of a loop.  */
end_comment

begin_struct
struct|struct
name|nb_iter_bound
block|{
name|tree
name|bound
decl_stmt|;
comment|/* The constant expression whose value is an upper 			   bound on the number of executions of ...  */
name|tree
name|at_stmt
decl_stmt|;
comment|/* ... this statement during one execution of 			   a loop.  */
name|struct
name|nb_iter_bound
modifier|*
name|next
decl_stmt|;
comment|/* The next bound in a list.  */
block|}
struct|;
end_struct

begin_comment
comment|/* Structure to hold information for each natural loop.  */
end_comment

begin_struct
struct|struct
name|loop
block|{
comment|/* Index into loops array.  */
name|int
name|num
decl_stmt|;
comment|/* Basic block of loop header.  */
name|basic_block
name|header
decl_stmt|;
comment|/* Basic block of loop latch.  */
name|basic_block
name|latch
decl_stmt|;
comment|/* For loop unrolling/peeling decision.  */
name|struct
name|lpt_decision
name|lpt_decision
decl_stmt|;
comment|/* Number of loop insns.  */
name|unsigned
name|ninsns
decl_stmt|;
comment|/* Average number of executed insns per iteration.  */
name|unsigned
name|av_ninsns
decl_stmt|;
comment|/* Number of blocks contained within the loop.  */
name|unsigned
name|num_nodes
decl_stmt|;
comment|/* The loop nesting depth.  */
name|int
name|depth
decl_stmt|;
comment|/* Superloops of the loop.  */
name|struct
name|loop
modifier|*
modifier|*
name|pred
decl_stmt|;
comment|/* The height of the loop (enclosed loop levels) within the loop      hierarchy tree.  */
name|int
name|level
decl_stmt|;
comment|/* The outer (parent) loop or NULL if outermost loop.  */
name|struct
name|loop
modifier|*
name|outer
decl_stmt|;
comment|/* The first inner (child) loop or NULL if innermost loop.  */
name|struct
name|loop
modifier|*
name|inner
decl_stmt|;
comment|/* Link to the next (sibling) loop.  */
name|struct
name|loop
modifier|*
name|next
decl_stmt|;
comment|/* Loop that is copy of this loop.  */
name|struct
name|loop
modifier|*
name|copy
decl_stmt|;
comment|/* Auxiliary info specific to a pass.  */
name|void
modifier|*
name|aux
decl_stmt|;
comment|/* The probable number of times the loop is executed at runtime.      This is an INTEGER_CST or an expression containing symbolic      names.  Don't access this field directly:      number_of_iterations_in_loop computes and caches the computed      information in this field.  */
name|tree
name|nb_iterations
decl_stmt|;
comment|/* An INTEGER_CST estimation of the number of iterations.  NULL_TREE      if there is no estimation.  */
name|tree
name|estimated_nb_iterations
decl_stmt|;
comment|/* Upper bound on number of iterations of a loop.  */
name|struct
name|nb_iter_bound
modifier|*
name|bounds
decl_stmt|;
comment|/* If not NULL, loop has just single exit edge stored here (edges to the      EXIT_BLOCK_PTR do not count.  */
name|edge
name|single_exit
decl_stmt|;
comment|/* True when the loop does not carry data dependences, and      consequently the iterations can be executed in any order.  False      when the loop carries data dependences, or when the property is      not decidable.  */
name|bool
name|parallel_p
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags for state of loop structure.  */
end_comment

begin_enum
enum|enum
block|{
name|LOOPS_HAVE_PREHEADERS
init|=
literal|1
block|,
name|LOOPS_HAVE_SIMPLE_LATCHES
init|=
literal|2
block|,
name|LOOPS_HAVE_MARKED_IRREDUCIBLE_REGIONS
init|=
literal|4
block|,
name|LOOPS_HAVE_MARKED_SINGLE_EXITS
init|=
literal|8
block|}
enum|;
end_enum

begin_define
define|#
directive|define
name|LOOPS_NORMAL
value|(LOOPS_HAVE_PREHEADERS | LOOPS_HAVE_SIMPLE_LATCHES \ 		      | LOOPS_HAVE_MARKED_IRREDUCIBLE_REGIONS)
end_define

begin_comment
comment|/* Structure to hold CFG information about natural loops within a function.  */
end_comment

begin_struct
struct|struct
name|loops
block|{
comment|/* Number of natural loops in the function.  */
name|unsigned
name|num
decl_stmt|;
comment|/* State of loops.  */
name|int
name|state
decl_stmt|;
comment|/* We store just pointers to loops here.        Note that a loop in this array may actually be NULL, if the loop      has been removed and the entire loops structure has not been      recomputed since that time.  */
name|struct
name|loop
modifier|*
modifier|*
name|parray
decl_stmt|;
comment|/* Pointer to root of loop hierarchy tree.  */
name|struct
name|loop
modifier|*
name|tree_root
decl_stmt|;
comment|/* Information derived from the CFG.  */
struct|struct
name|cfg
block|{
comment|/* The ordering of the basic blocks in a depth first search.  */
name|int
modifier|*
name|dfs_order
decl_stmt|;
comment|/* The reverse completion ordering of the basic blocks found in a        depth first search.  */
name|int
modifier|*
name|rc_order
decl_stmt|;
block|}
name|cfg
struct|;
comment|/* Headers shared by multiple loops that should be merged.  */
name|sbitmap
name|shared_headers
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The loop tree currently optimized.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|loops
modifier|*
name|current_loops
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Loop recognition.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|flow_loops_find
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flow_loops_free
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flow_loops_dump
parameter_list|(
specifier|const
name|struct
name|loops
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flow_loop_dump
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flow_loop_free
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|flow_loop_nodes_find
parameter_list|(
name|basic_block
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fix_loop_structure
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|bitmap
name|changed_bbs
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mark_irreducible_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|mark_single_exit_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Loop data structure manipulation/querying.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|flow_loop_tree_node_add
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flow_loop_tree_node_remove
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|flow_loop_nested_p
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|,
specifier|const
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|flow_bb_inside_loop_p
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|,
specifier|const
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|loop
modifier|*
name|find_common_loop
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|loop
modifier|*
name|superloop_at_depth
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|tree_num_loop_insns
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|num_loop_insns
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|average_num_loop_insns
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|get_loop_level
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|loop_exit_edge_p
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_loop_exit_edges
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Loops& cfg manipulation.  */
end_comment

begin_function_decl
specifier|extern
name|basic_block
modifier|*
name|get_loop_body
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
modifier|*
name|get_loop_body_in_dom_order
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
modifier|*
name|get_loop_body_in_bfs_order
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
modifier|*
name|get_loop_exit_edges
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|,
name|unsigned
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|num_loop_branches
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|loop_preheader_edge
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|loop_latch_edge
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_bb_to_loop
parameter_list|(
name|basic_block
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_bb_from_loops
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cancel_loop_tree
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|loop_split_edge_with
parameter_list|(
name|edge
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|fix_loop_placement
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|CP_SIMPLE_PREHEADERS
init|=
literal|1
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|void
name|create_preheaders
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|force_single_succ_latches
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|verify_loop_structure
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Loop analysis.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|just_once_each_iteration_p
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|expected_loop_iterations
parameter_list|(
specifier|const
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|doloop_condition_get
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Loop manipulation.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|can_duplicate_loop_p
parameter_list|(
name|struct
name|loop
modifier|*
name|loop
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DLTHE_FLAG_UPDATE_FREQ
value|1
end_define

begin_comment
comment|/* Update frequencies in 					   duplicate_loop_to_header_edge.  */
end_comment

begin_define
define|#
directive|define
name|DLTHE_RECORD_COPY_NUMBER
value|2
end_define

begin_comment
comment|/* Record copy number in the aux 					   field of newly create BB.  */
end_comment

begin_define
define|#
directive|define
name|DLTHE_FLAG_COMPLETTE_PEEL
value|4
end_define

begin_comment
comment|/* Update frequencies expecting 					   a complete peeling.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|loop
modifier|*
name|duplicate_loop
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|duplicate_loop_to_header_edge
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|edge
parameter_list|,
name|struct
name|loops
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|sbitmap
parameter_list|,
name|edge
parameter_list|,
name|edge
modifier|*
parameter_list|,
name|unsigned
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|loop
modifier|*
name|loopify
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|edge
parameter_list|,
name|edge
parameter_list|,
name|basic_block
parameter_list|,
name|edge
parameter_list|,
name|edge
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|loop
modifier|*
name|loop_version
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|struct
name|loop
modifier|*
parameter_list|,
name|void
modifier|*
parameter_list|,
name|basic_block
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|remove_path
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Induction variable analysis.  */
end_comment

begin_comment
comment|/* The description of induction variable.  The things are a bit complicated    due to need to handle subregs and extends.  The value of the object described    by it can be obtained as follows (all computations are done in extend_mode):     Value in i-th iteration is      delta + mult * extend_{extend_mode} (subreg_{mode} (base + i * step)).     If first_special is true, the value in the first iteration is      delta + mult * base     If extend = UNKNOWN, first_special must be false, delta 0, mult 1 and value is      subreg_{mode} (base + i * step)     The get_iv_value function can be used to obtain these expressions.     ??? Add a third mode field that would specify the mode in that inner    computation is done, which would enable it to be different from the    outer one?  */
end_comment

begin_struct
struct|struct
name|rtx_iv
block|{
comment|/* Its base and step (mode of base and step is supposed to be extend_mode,      see the description above).  */
name|rtx
name|base
decl_stmt|,
name|step
decl_stmt|;
comment|/* The type of extend applied to it (SIGN_EXTEND, ZERO_EXTEND or UNKNOWN).  */
name|enum
name|rtx_code
name|extend
decl_stmt|;
comment|/* Operations applied in the extended mode.  */
name|rtx
name|delta
decl_stmt|,
name|mult
decl_stmt|;
comment|/* The mode it is extended to.  */
name|enum
name|machine_mode
name|extend_mode
decl_stmt|;
comment|/* The mode the variable iterates in.  */
name|enum
name|machine_mode
name|mode
decl_stmt|;
comment|/* Whether the first iteration needs to be handled specially.  */
name|unsigned
name|first_special
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The description of an exit from the loop and of the number of iterations    till we take the exit.  */
end_comment

begin_struct
struct|struct
name|niter_desc
block|{
comment|/* The edge out of the loop.  */
name|edge
name|out_edge
decl_stmt|;
comment|/* The other edge leading from the condition.  */
name|edge
name|in_edge
decl_stmt|;
comment|/* True if we are able to say anything about number of iterations of the      loop.  */
name|bool
name|simple_p
decl_stmt|;
comment|/* True if the loop iterates the constant number of times.  */
name|bool
name|const_iter
decl_stmt|;
comment|/* Number of iterations if constant.  */
name|unsigned
name|HOST_WIDEST_INT
name|niter
decl_stmt|;
comment|/* Upper bound on the number of iterations.  */
name|unsigned
name|HOST_WIDEST_INT
name|niter_max
decl_stmt|;
comment|/* Assumptions under that the rest of the information is valid.  */
name|rtx
name|assumptions
decl_stmt|;
comment|/* Assumptions under that the loop ends before reaching the latch,      even if value of niter_expr says otherwise.  */
name|rtx
name|noloop_assumptions
decl_stmt|;
comment|/* Condition under that the loop is infinite.  */
name|rtx
name|infinite
decl_stmt|;
comment|/* Whether the comparison is signed.  */
name|bool
name|signed_p
decl_stmt|;
comment|/* The mode in that niter_expr should be computed.  */
name|enum
name|machine_mode
name|mode
decl_stmt|;
comment|/* The number of iterations of the loop.  */
name|rtx
name|niter_expr
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|void
name|iv_analysis_loop_init
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|iv_analyze
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|struct
name|rtx_iv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|iv_analyze_result
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|struct
name|rtx_iv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|iv_analyze_expr
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|struct
name|rtx_iv
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_iv_value
parameter_list|(
name|struct
name|rtx_iv
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|biv_p
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_simple_exit
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|struct
name|niter_desc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iv_analysis_done
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|df
modifier|*
name|iv_current_loop_df
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|niter_desc
modifier|*
name|get_simple_loop_desc
parameter_list|(
name|struct
name|loop
modifier|*
name|loop
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_simple_loop_desc
parameter_list|(
name|struct
name|loop
modifier|*
name|loop
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|struct
name|niter_desc
modifier|*
name|simple_loop_desc
parameter_list|(
name|struct
name|loop
modifier|*
name|loop
parameter_list|)
block|{
return|return
operator|(
expr|struct
name|niter_desc
operator|*
operator|)
name|loop
operator|->
name|aux
return|;
block|}
end_function

begin_comment
comment|/* The properties of the target.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|target_avail_regs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of available registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|target_res_regs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of reserved registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|target_small_cost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The cost for register when there 					   is a free one.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|target_pres_cost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The cost for register when there are 					   not too many free ones.  */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|target_spill_cost
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The cost for register when we need 					   to spill.  */
end_comment

begin_comment
comment|/* Register pressure estimation for induction variable optimizations& loop    invariant motion.  */
end_comment

begin_function_decl
specifier|extern
name|unsigned
name|global_cost_for_size
parameter_list|(
name|unsigned
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_set_costs
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Loop optimizer initialization.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|loops
modifier|*
name|loop_optimizer_init
parameter_list|(
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|loop_optimizer_finalize
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Optimization passes.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|unswitch_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
block|{
name|UAP_PEEL
init|=
literal|1
block|,
comment|/* Enables loop peeling.  */
name|UAP_UNROLL
init|=
literal|2
block|,
comment|/* Enables peeling of loops if it seems profitable.  */
name|UAP_UNROLL_ALL
init|=
literal|4
comment|/* Enables peeling of all loops.  */
block|}
enum|;
end_enum

begin_function_decl
specifier|extern
name|void
name|unroll_and_peel_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|doloop_optimize_loops
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|move_loop_invariants
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|record_estimate
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_CFGLOOP_H */
end_comment

end_unit

