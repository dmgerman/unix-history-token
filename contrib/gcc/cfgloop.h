begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Natural loop functions    Copyright (C) 1987, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
comment|/* Description of loop for simple loop unrolling.  */
end_comment

begin_struct
struct|struct
name|loop_desc
block|{
name|int
name|postincr
decl_stmt|;
comment|/* 1 if increment/decrement is done after loop exit condition.  */
name|rtx
name|stride
decl_stmt|;
comment|/* Value added to VAR in each iteration.  */
name|rtx
name|var
decl_stmt|;
comment|/* Loop control variable.  */
name|enum
name|machine_mode
name|inner_mode
decl_stmt|;
comment|/* The mode from that it is extended.  */
name|enum
name|rtx_code
name|extend
decl_stmt|;
comment|/* With this extend.  */
name|rtx
name|var_alts
decl_stmt|;
comment|/* List of definitions of its initial value.  */
name|rtx
name|lim
decl_stmt|;
comment|/* Expression var is compared with.  */
name|rtx
name|lim_alts
decl_stmt|;
comment|/* List of definitions of its initial value.  */
name|bool
name|const_iter
decl_stmt|;
comment|/* True if it iterates constant number of times.  */
name|unsigned
name|HOST_WIDE_INT
name|niter
decl_stmt|;
comment|/* Number of iterations if it is constant.  */
name|bool
name|may_be_zero
decl_stmt|;
comment|/* If we cannot determine that the first iteration will pass.  */
name|enum
name|rtx_code
name|cond
decl_stmt|;
comment|/* Exit condition.  */
name|int
name|neg
decl_stmt|;
comment|/* Set to 1 if loop ends when condition is satisfied.  */
name|edge
name|out_edge
decl_stmt|;
comment|/* The exit edge.  */
name|edge
name|in_edge
decl_stmt|;
comment|/* And the other one.  */
name|int
name|n_branches
decl_stmt|;
comment|/* Number of branches inside the loop.  */
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
comment|/* Basic block of loop preheader or NULL if it does not exist.  */
name|basic_block
name|pre_header
decl_stmt|;
comment|/* For loop unrolling/peeling decision.  */
name|struct
name|lpt_decision
name|lpt_decision
decl_stmt|;
comment|/* Simple loop description.  */
name|int
name|simple
decl_stmt|;
name|struct
name|loop_desc
name|desc
decl_stmt|;
name|int
name|has_desc
decl_stmt|;
comment|/* Number of loop insns.  */
name|unsigned
name|ninsns
decl_stmt|;
comment|/* Average number of executed insns per iteration.  */
name|unsigned
name|av_ninsns
decl_stmt|;
comment|/* Array of edges along the preheader extended basic block trace.      The source of the first edge is the root node of preheader      extended basic block, if it exists.  */
name|edge
modifier|*
name|pre_header_edges
decl_stmt|;
comment|/* Number of edges along the pre_header extended basic block trace.  */
name|int
name|num_pre_header_edges
decl_stmt|;
comment|/* The first block in the loop.  This is not necessarily the same as      the loop header.  */
name|basic_block
name|first
decl_stmt|;
comment|/* The last block in the loop.  This is not necessarily the same as      the loop latch.  */
name|basic_block
name|last
decl_stmt|;
comment|/* Bitmap of blocks contained within the loop.  */
name|sbitmap
name|nodes
decl_stmt|;
comment|/* Number of blocks contained within the loop.  */
name|unsigned
name|num_nodes
decl_stmt|;
comment|/* Array of edges that enter the loop.  */
name|edge
modifier|*
name|entry_edges
decl_stmt|;
comment|/* Number of edges that enter the loop.  */
name|int
name|num_entries
decl_stmt|;
comment|/* Array of edges that exit the loop.  */
name|edge
modifier|*
name|exit_edges
decl_stmt|;
comment|/* Number of edges that exit the loop.  */
name|int
name|num_exits
decl_stmt|;
comment|/* Bitmap of blocks that dominate all exits of the loop.  */
name|sbitmap
name|exits_doms
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
comment|/* Nonzero if the loop is invalid (e.g., contains setjmp.).  */
name|int
name|invalid
decl_stmt|;
comment|/* Auxiliary info specific to a pass.  */
name|void
modifier|*
name|aux
decl_stmt|;
comment|/* The following are currently used by loop.c but they are likely to      disappear as loop.c is converted to use the CFG.  */
comment|/* Nonzero if the loop has a NOTE_INSN_LOOP_VTOP.  */
name|rtx
name|vtop
decl_stmt|;
comment|/* Nonzero if the loop has a NOTE_INSN_LOOP_CONT.      A continue statement will generate a branch to NEXT_INSN (cont).  */
name|rtx
name|cont
decl_stmt|;
comment|/* The dominator of cont.  */
name|rtx
name|cont_dominator
decl_stmt|;
comment|/* The NOTE_INSN_LOOP_BEG.  */
name|rtx
name|start
decl_stmt|;
comment|/* The NOTE_INSN_LOOP_END.  */
name|rtx
name|end
decl_stmt|;
comment|/* For a rotated loop that is entered near the bottom,      this is the label at the top.  Otherwise it is zero.  */
name|rtx
name|top
decl_stmt|;
comment|/* Place in the loop where control enters.  */
name|rtx
name|scan_start
decl_stmt|;
comment|/* The position where to sink insns out of the loop.  */
name|rtx
name|sink
decl_stmt|;
comment|/* List of all LABEL_REFs which refer to code labels outside the      loop.  Used by routines that need to know all loop exits, such as      final_biv_value and final_giv_value.       This does not include loop exits due to return instructions.      This is because all bivs and givs are pseudos, and hence must be      dead after a return, so the presence of a return does not affect      any of the optimizations that use this info.  It is simpler to      just not include return instructions on this list.  */
name|rtx
name|exit_labels
decl_stmt|;
comment|/* The number of LABEL_REFs on exit_labels for this loop and all      loops nested inside it.  */
name|int
name|exit_count
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
block|}
enum|;
end_enum

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
comment|/* Maximum nested loop level in the function.  */
name|unsigned
name|levels
decl_stmt|;
comment|/* Array of natural loop descriptors (scanning this array in reverse order      will find the inner loops before their enclosing outer loops).  */
name|struct
name|loop
modifier|*
name|array
decl_stmt|;
comment|/* The above array is unused in new loop infrastructure and is kept only for      purposes of the old loop optimizer.  Instead we store just pointers to      loops here.  */
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
comment|/* State of loops.  */
name|int
name|state
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Flags for loop discovery.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_TREE
value|1
end_define

begin_comment
comment|/* Build loop hierarchy tree.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_PRE_HEADER
value|2
end_define

begin_comment
comment|/* Analyze loop preheader.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_ENTRY_EDGES
value|4
end_define

begin_comment
comment|/* Find entry edges.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_EXIT_EDGES
value|8
end_define

begin_comment
comment|/* Find exit edges.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_EDGES
value|(LOOP_ENTRY_EDGES | LOOP_EXIT_EDGES)
end_define

begin_define
define|#
directive|define
name|LOOP_ALL
value|15
end_define

begin_comment
comment|/* All of the above  */
end_comment

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
parameter_list|,
name|int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|flow_loops_update
parameter_list|(
name|struct
name|loops
modifier|*
parameter_list|,
name|int
name|flags
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
name|int
name|flow_loop_scan
parameter_list|(
name|struct
name|loop
modifier|*
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
name|void
name|mark_irreducible_loops
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
name|flow_loop_outside_edge_p
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
name|cancel_loop
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
name|simple_loop_p
parameter_list|(
name|struct
name|loop
modifier|*
parameter_list|,
name|struct
name|loop_desc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|count_loop_iterations
parameter_list|(
name|struct
name|loop_desc
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|just_once_each_iteration_p
parameter_list|(
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

begin_function_decl
specifier|extern
name|int
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
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unloop
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

begin_function_decl
specifier|extern
name|edge
name|split_loop_bb
parameter_list|(
name|basic_block
parameter_list|,
name|rtx
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
name|FILE
modifier|*
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
parameter_list|,
name|FILE
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
name|bool
name|is_bct_cond
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_var_set_from_bct
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

end_unit

