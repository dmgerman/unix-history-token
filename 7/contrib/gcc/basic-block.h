begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define control and data flow tables, and regsets.    Copyright (C) 1987, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004, 2005    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_BASIC_BLOCK_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_BASIC_BLOCK_H
end_define

begin_include
include|#
directive|include
file|"bitmap.h"
end_include

begin_include
include|#
directive|include
file|"sbitmap.h"
end_include

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_include
include|#
directive|include
file|"partition.h"
end_include

begin_include
include|#
directive|include
file|"hard-reg-set.h"
end_include

begin_include
include|#
directive|include
file|"predict.h"
end_include

begin_include
include|#
directive|include
file|"vec.h"
end_include

begin_include
include|#
directive|include
file|"function.h"
end_include

begin_comment
comment|/* Head of register set linked list.  */
end_comment

begin_typedef
typedef|typedef
name|bitmap_head
name|regset_head
typedef|;
end_typedef

begin_comment
comment|/* A pointer to a regset_head.  */
end_comment

begin_typedef
typedef|typedef
name|bitmap
name|regset
typedef|;
end_typedef

begin_comment
comment|/* Allocate a register set with oballoc.  */
end_comment

begin_define
define|#
directive|define
name|ALLOC_REG_SET
parameter_list|(
name|OBSTACK
parameter_list|)
value|BITMAP_ALLOC (OBSTACK)
end_define

begin_comment
comment|/* Do any cleanup needed on a regset when it is no longer used.  */
end_comment

begin_define
define|#
directive|define
name|FREE_REG_SET
parameter_list|(
name|REGSET
parameter_list|)
value|BITMAP_FREE (REGSET)
end_define

begin_comment
comment|/* Initialize a new regset.  */
end_comment

begin_define
define|#
directive|define
name|INIT_REG_SET
parameter_list|(
name|HEAD
parameter_list|)
value|bitmap_initialize (HEAD,&reg_obstack)
end_define

begin_comment
comment|/* Clear a register set by freeing up the linked list.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_REG_SET
parameter_list|(
name|HEAD
parameter_list|)
value|bitmap_clear (HEAD)
end_define

begin_comment
comment|/* Copy a register set to another register set.  */
end_comment

begin_define
define|#
directive|define
name|COPY_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|bitmap_copy (TO, FROM)
end_define

begin_comment
comment|/* Compare two register sets.  */
end_comment

begin_define
define|#
directive|define
name|REG_SET_EQUAL_P
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|bitmap_equal_p (A, B)
end_define

begin_comment
comment|/* `and' a register set with a second register set.  */
end_comment

begin_define
define|#
directive|define
name|AND_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|bitmap_and_into (TO, FROM)
end_define

begin_comment
comment|/* `and' the complement of a register set with a register set.  */
end_comment

begin_define
define|#
directive|define
name|AND_COMPL_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|bitmap_and_compl_into (TO, FROM)
end_define

begin_comment
comment|/* Inclusive or a register set with a second register set.  */
end_comment

begin_define
define|#
directive|define
name|IOR_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|bitmap_ior_into (TO, FROM)
end_define

begin_comment
comment|/* Exclusive or a register set with a second register set.  */
end_comment

begin_define
define|#
directive|define
name|XOR_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
value|bitmap_xor_into (TO, FROM)
end_define

begin_comment
comment|/* Or into TO the register set FROM1 `and'ed with the complement of FROM2.  */
end_comment

begin_define
define|#
directive|define
name|IOR_AND_COMPL_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM1
parameter_list|,
name|FROM2
parameter_list|)
define|\
value|bitmap_ior_and_compl_into (TO, FROM1, FROM2)
end_define

begin_comment
comment|/* Clear a single register in a register set.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_REGNO_REG_SET
parameter_list|(
name|HEAD
parameter_list|,
name|REG
parameter_list|)
value|bitmap_clear_bit (HEAD, REG)
end_define

begin_comment
comment|/* Set a single register in a register set.  */
end_comment

begin_define
define|#
directive|define
name|SET_REGNO_REG_SET
parameter_list|(
name|HEAD
parameter_list|,
name|REG
parameter_list|)
value|bitmap_set_bit (HEAD, REG)
end_define

begin_comment
comment|/* Return true if a register is set in a register set.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_REG_SET_P
parameter_list|(
name|TO
parameter_list|,
name|REG
parameter_list|)
value|bitmap_bit_p (TO, REG)
end_define

begin_comment
comment|/* Copy the hard registers in a register set to the hard register set.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|reg_set_to_hard_reg_set
parameter_list|(
name|HARD_REG_SET
modifier|*
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|REG_SET_TO_HARD_REG_SET
parameter_list|(
name|TO
parameter_list|,
name|FROM
parameter_list|)
define|\
value|do {									\   CLEAR_HARD_REG_SET (TO);						\   reg_set_to_hard_reg_set (&TO, FROM);					\ } while (0)
end_define

begin_typedef
typedef|typedef
name|bitmap_iterator
name|reg_set_iterator
typedef|;
end_typedef

begin_comment
comment|/* Loop over all registers in REGSET, starting with MIN, setting REGNUM to the    register number and executing CODE for all registers that are set.  */
end_comment

begin_define
define|#
directive|define
name|EXECUTE_IF_SET_IN_REG_SET
parameter_list|(
name|REGSET
parameter_list|,
name|MIN
parameter_list|,
name|REGNUM
parameter_list|,
name|RSI
parameter_list|)
define|\
value|EXECUTE_IF_SET_IN_BITMAP (REGSET, MIN, REGNUM, RSI)
end_define

begin_comment
comment|/* Loop over all registers in REGSET1 and REGSET2, starting with MIN, setting    REGNUM to the register number and executing CODE for all registers that are    set in the first regset and not set in the second.  */
end_comment

begin_define
define|#
directive|define
name|EXECUTE_IF_AND_COMPL_IN_REG_SET
parameter_list|(
name|REGSET1
parameter_list|,
name|REGSET2
parameter_list|,
name|MIN
parameter_list|,
name|REGNUM
parameter_list|,
name|RSI
parameter_list|)
define|\
value|EXECUTE_IF_AND_COMPL_IN_BITMAP (REGSET1, REGSET2, MIN, REGNUM, RSI)
end_define

begin_comment
comment|/* Loop over all registers in REGSET1 and REGSET2, starting with MIN, setting    REGNUM to the register number and executing CODE for all registers that are    set in both regsets.  */
end_comment

begin_define
define|#
directive|define
name|EXECUTE_IF_AND_IN_REG_SET
parameter_list|(
name|REGSET1
parameter_list|,
name|REGSET2
parameter_list|,
name|MIN
parameter_list|,
name|REGNUM
parameter_list|,
name|RSI
parameter_list|)
define|\
value|EXECUTE_IF_AND_IN_BITMAP (REGSET1, REGSET2, MIN, REGNUM, RSI)
end_define

begin_comment
unit|\
comment|/* Type we use to hold basic block counters.  Should be at least    64bit.  Although a counter cannot be negative, we use a signed    type, because erroneous negative counts can be generated when the    flow graph is manipulated by various optimizations.  A signed type    makes those easy to detect.  */
end_comment

begin_typedef
typedef|typedef
name|HOST_WIDEST_INT
name|gcov_type
typedef|;
end_typedef

begin_comment
comment|/* Control flow edge information.  */
end_comment

begin_decl_stmt
name|struct
name|edge_def
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The two blocks at the ends of the edge.  */
name|struct
name|basic_block_def
modifier|*
name|src
decl_stmt|;
name|struct
name|basic_block_def
modifier|*
name|dest
decl_stmt|;
comment|/* Instructions queued on the edge.  */
union|union
name|edge_def_insns
block|{
name|rtx
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"0"
argument_list|)
operator|)
argument_list|)
name|r
decl_stmt|;
name|tree
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|t
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"ir_type ()"
argument_list|)
operator|)
argument_list|)
name|insns
union|;
comment|/* Auxiliary info specific to a pass.  */
name|PTR
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|aux
decl_stmt|;
comment|/* Location of any goto implicit in the edge, during tree-ssa.  */
name|source_locus
name|goto_locus
decl_stmt|;
name|int
name|flags
decl_stmt|;
comment|/* see EDGE_* below  */
name|int
name|probability
decl_stmt|;
comment|/* biased by REG_BR_PROB_BASE */
name|gcov_type
name|count
decl_stmt|;
comment|/* Expected number of executions calculated 				   in profile.c  */
comment|/* The index number corresponding to this edge in the edge vector      dest->preds.  */
name|unsigned
name|int
name|dest_idx
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|edge_def
modifier|*
name|edge
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|edge
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|edge
argument_list|,
name|gc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|EDGE_FALLTHRU
value|1
end_define

begin_comment
comment|/* 'Straight line' flow */
end_comment

begin_define
define|#
directive|define
name|EDGE_ABNORMAL
value|2
end_define

begin_comment
comment|/* Strange flow, like computed 					   label, or eh */
end_comment

begin_define
define|#
directive|define
name|EDGE_ABNORMAL_CALL
value|4
end_define

begin_comment
comment|/* Call with abnormal exit 					   like an exception, or sibcall */
end_comment

begin_define
define|#
directive|define
name|EDGE_EH
value|8
end_define

begin_comment
comment|/* Exception throw */
end_comment

begin_define
define|#
directive|define
name|EDGE_FAKE
value|16
end_define

begin_comment
comment|/* Not a real edge (profile.c) */
end_comment

begin_define
define|#
directive|define
name|EDGE_DFS_BACK
value|32
end_define

begin_comment
comment|/* A backwards edge */
end_comment

begin_define
define|#
directive|define
name|EDGE_CAN_FALLTHRU
value|64
end_define

begin_comment
comment|/* Candidate for straight line 					   flow.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_IRREDUCIBLE_LOOP
value|128
end_define

begin_comment
comment|/* Part of irreducible loop.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_SIBCALL
value|256
end_define

begin_comment
comment|/* Edge from sibcall to exit.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_LOOP_EXIT
value|512
end_define

begin_comment
comment|/* Exit of a loop.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_TRUE_VALUE
value|1024
end_define

begin_comment
comment|/* Edge taken when controlling 					   predicate is nonzero.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_FALSE_VALUE
value|2048
end_define

begin_comment
comment|/* Edge taken when controlling 					   predicate is zero.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_EXECUTABLE
value|4096
end_define

begin_comment
comment|/* Edge is executable.  Only 					   valid during SSA-CCP.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_CROSSING
value|8192
end_define

begin_comment
comment|/* Edge crosses between hot 					   and cold sections, when we 					   do partitioning.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_ALL_FLAGS
value|16383
end_define

begin_define
define|#
directive|define
name|EDGE_COMPLEX
value|(EDGE_ABNORMAL | EDGE_ABNORMAL_CALL | EDGE_EH)
end_define

begin_comment
comment|/* Counter summary from the last set of coverage counts read by    profile.c.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|gcov_ctr_summary
modifier|*
name|profile_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declared in cfgloop.h.  */
end_comment

begin_struct_decl
struct_decl|struct
name|loop
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|loops
struct_decl|;
end_struct_decl

begin_comment
comment|/* Declared in tree-flow.h.  */
end_comment

begin_struct_decl
struct_decl|struct
name|edge_prediction
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|rtl_bb_info
struct_decl|;
end_struct_decl

begin_comment
comment|/* A basic block is a sequence of instructions with only entry and    only one exit.  If any one of the instructions are executed, they    will all be executed, and in sequence from first to last.     There may be COND_EXEC instructions in the basic block.  The    COND_EXEC *instructions* will be executed -- but if the condition    is false the conditionally executed *expressions* will of course    not be executed.  We don't consider the conditionally executed    expression (which might have side-effects) to be in a separate    basic block because the program counter will always be at the same    location after the COND_EXEC instruction, regardless of whether the    condition is true or not.     Basic blocks need not start with a label nor end with a jump insn.    For example, a previous basic block may just "conditionally fall"    into the succeeding basic block, and the last basic block need not    end with a jump insn.  Block 0 is a descendant of the entry block.     A basic block beginning with two labels cannot have notes between    the labels.     Data for jump tables are stored in jump_insns that occur in no    basic block even though these insns can follow or precede insns in    basic blocks.  */
end_comment

begin_comment
comment|/* Basic block information indexed by block number.  */
end_comment

begin_decl_stmt
name|struct
name|basic_block_def
name|GTY
argument_list|(
operator|(
name|chain_next
argument_list|(
literal|"%h.next_bb"
argument_list|)
operator|,
name|chain_prev
argument_list|(
literal|"%h.prev_bb"
argument_list|)
operator|)
argument_list|)
block|{
comment|/* Pointers to the first and last trees of the block.  */
name|tree
name|stmt_list
decl_stmt|;
comment|/* The edges into and out of the block.  */
name|VEC
argument_list|(
name|edge
argument_list|,
name|gc
argument_list|)
operator|*
name|preds
expr_stmt|;
name|VEC
argument_list|(
name|edge
argument_list|,
name|gc
argument_list|)
operator|*
name|succs
expr_stmt|;
comment|/* Auxiliary info specific to a pass.  */
name|PTR
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|aux
decl_stmt|;
comment|/* Innermost loop containing the block.  */
name|struct
name|loop
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|loop_father
decl_stmt|;
comment|/* The dominance and postdominance information node.  */
name|struct
name|et_node
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|dom
index|[
literal|2
index|]
decl_stmt|;
comment|/* Previous and next blocks in the chain.  */
name|struct
name|basic_block_def
modifier|*
name|prev_bb
decl_stmt|;
name|struct
name|basic_block_def
modifier|*
name|next_bb
decl_stmt|;
union|union
name|basic_block_il_dependent
block|{
name|struct
name|rtl_bb_info
modifier|*
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"1"
argument_list|)
operator|)
argument_list|)
name|rtl
decl_stmt|;
block|}
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"((%1.flags& BB_RTL) != 0)"
argument_list|)
operator|)
argument_list|)
name|il
union|;
comment|/* Chain of PHI nodes for this block.  */
name|tree
name|phi_nodes
decl_stmt|;
comment|/* A list of predictions.  */
name|struct
name|edge_prediction
modifier|*
name|predictions
decl_stmt|;
comment|/* Expected number of executions: calculated in profile.c.  */
name|gcov_type
name|count
decl_stmt|;
comment|/* The index of this block.  */
name|int
name|index
decl_stmt|;
comment|/* The loop depth of this block.  */
name|int
name|loop_depth
decl_stmt|;
comment|/* Expected frequency.  Normalized to be in range 0 to BB_FREQ_MAX.  */
name|int
name|frequency
decl_stmt|;
comment|/* Various flags.  See BB_* below.  */
name|int
name|flags
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|struct
name|rtl_bb_info
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The first and last insns of the block.  */
name|rtx
name|head_
decl_stmt|;
name|rtx
name|end_
decl_stmt|;
comment|/* The registers that are live on entry to this block.  */
name|bitmap
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|global_live_at_start
decl_stmt|;
comment|/* The registers that are live on exit from this block.  */
name|bitmap
name|GTY
argument_list|(
operator|(
name|skip
argument_list|(
literal|""
argument_list|)
operator|)
argument_list|)
name|global_live_at_end
decl_stmt|;
comment|/* In CFGlayout mode points to insn notes/jumptables to be placed just before      and after the block.   */
name|rtx
name|header
decl_stmt|;
name|rtx
name|footer
decl_stmt|;
comment|/* This field is used by the bb-reorder and tracer passes.  */
name|int
name|visited
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_typedef
typedef|typedef
name|struct
name|basic_block_def
modifier|*
name|basic_block
typedef|;
end_typedef

begin_expr_stmt
name|DEF_VEC_P
argument_list|(
name|basic_block
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|basic_block
argument_list|,
name|gc
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|DEF_VEC_ALLOC_P
argument_list|(
name|basic_block
argument_list|,
name|heap
argument_list|)
expr_stmt|;
end_expr_stmt

begin_define
define|#
directive|define
name|BB_FREQ_MAX
value|10000
end_define

begin_comment
comment|/* Masks for basic_block.flags.     BB_HOT_PARTITION and BB_COLD_PARTITION should be preserved throughout    the compilation, so they are never cleared.     All other flags may be cleared by clear_bb_flags().  It is generally    a bad idea to rely on any flags being up-to-date.  */
end_comment

begin_enum
enum|enum
name|bb_flags
block|{
comment|/* Set if insns in BB have are modified.  Used for updating liveness info.  */
name|BB_DIRTY
init|=
literal|1
block|,
comment|/* Only set on blocks that have just been created by create_bb.  */
name|BB_NEW
init|=
literal|2
block|,
comment|/* Set by find_unreachable_blocks.  Do not rely on this being set in any      pass.  */
name|BB_REACHABLE
init|=
literal|4
block|,
comment|/* Set for blocks in an irreducible loop by loop analysis.  */
name|BB_IRREDUCIBLE_LOOP
init|=
literal|8
block|,
comment|/* Set on blocks that may actually not be single-entry single-exit block.  */
name|BB_SUPERBLOCK
init|=
literal|16
block|,
comment|/* Set on basic blocks that the scheduler should not touch.  This is used      by SMS to prevent other schedulers from messing with the loop schedule.  */
name|BB_DISABLE_SCHEDULE
init|=
literal|32
block|,
comment|/* Set on blocks that should be put in a hot section.  */
name|BB_HOT_PARTITION
init|=
literal|64
block|,
comment|/* Set on blocks that should be put in a cold section.  */
name|BB_COLD_PARTITION
init|=
literal|128
block|,
comment|/* Set on block that was duplicated.  */
name|BB_DUPLICATED
init|=
literal|256
block|,
comment|/* Set on blocks that are in RTL format.  */
name|BB_RTL
init|=
literal|1024
block|,
comment|/* Set on blocks that are forwarder blocks.      Only used in cfgcleanup.c.  */
name|BB_FORWARDER_BLOCK
init|=
literal|2048
block|,
comment|/* Set on blocks that cannot be threaded through.      Only used in cfgcleanup.c.  */
name|BB_NONTHREADABLE_BLOCK
init|=
literal|4096
block|}
enum|;
end_enum

begin_comment
comment|/* Dummy flag for convenience in the hot/cold partitioning code.  */
end_comment

begin_define
define|#
directive|define
name|BB_UNPARTITIONED
value|0
end_define

begin_comment
comment|/* Partitions, to be used when partitioning hot and cold basic blocks into    separate sections.  */
end_comment

begin_define
define|#
directive|define
name|BB_PARTITION
parameter_list|(
name|bb
parameter_list|)
value|((bb)->flags& (BB_HOT_PARTITION|BB_COLD_PARTITION))
end_define

begin_define
define|#
directive|define
name|BB_SET_PARTITION
parameter_list|(
name|bb
parameter_list|,
name|part
parameter_list|)
value|do {					\   basic_block bb_ = (bb);						\   bb_->flags = ((bb_->flags& ~(BB_HOT_PARTITION|BB_COLD_PARTITION))	\ 		| (part));						\ } while (0)
end_define

begin_define
define|#
directive|define
name|BB_COPY_PARTITION
parameter_list|(
name|dstbb
parameter_list|,
name|srcbb
parameter_list|)
define|\
value|BB_SET_PARTITION (dstbb, BB_PARTITION (srcbb))
end_define

begin_comment
comment|/* A structure to group all the per-function control flow graph data.    The x_* prefixing is necessary because otherwise references to the    fields of this struct are interpreted as the defines for backward    source compatibility following the definition of this struct.  */
end_comment

begin_decl_stmt
name|struct
name|control_flow_graph
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* Block pointers for the exit and entry of a function.      These are always the head and tail of the basic block list.  */
name|basic_block
name|x_entry_block_ptr
decl_stmt|;
name|basic_block
name|x_exit_block_ptr
decl_stmt|;
comment|/* Index by basic block number, get basic block struct info.  */
name|VEC
argument_list|(
name|basic_block
argument_list|,
name|gc
argument_list|)
operator|*
name|x_basic_block_info
expr_stmt|;
comment|/* Number of basic blocks in this flow graph.  */
name|int
name|x_n_basic_blocks
decl_stmt|;
comment|/* Number of edges in this flow graph.  */
name|int
name|x_n_edges
decl_stmt|;
comment|/* The first free basic block number.  */
name|int
name|x_last_basic_block
decl_stmt|;
comment|/* Mapping of labels to their associated blocks.  At present      only used for the tree CFG.  */
name|VEC
argument_list|(
name|basic_block
argument_list|,
name|gc
argument_list|)
operator|*
name|x_label_to_block_map
expr_stmt|;
enum|enum
name|profile_status
block|{
name|PROFILE_ABSENT
block|,
name|PROFILE_GUESSED
block|,
name|PROFILE_READ
block|}
name|x_profile_status
enum|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Defines for accessing the fields of the CFG structure for function FN.  */
end_comment

begin_define
define|#
directive|define
name|ENTRY_BLOCK_PTR_FOR_FUNCTION
parameter_list|(
name|FN
parameter_list|)
value|((FN)->cfg->x_entry_block_ptr)
end_define

begin_define
define|#
directive|define
name|EXIT_BLOCK_PTR_FOR_FUNCTION
parameter_list|(
name|FN
parameter_list|)
value|((FN)->cfg->x_exit_block_ptr)
end_define

begin_define
define|#
directive|define
name|basic_block_info_for_function
parameter_list|(
name|FN
parameter_list|)
value|((FN)->cfg->x_basic_block_info)
end_define

begin_define
define|#
directive|define
name|n_basic_blocks_for_function
parameter_list|(
name|FN
parameter_list|)
value|((FN)->cfg->x_n_basic_blocks)
end_define

begin_define
define|#
directive|define
name|n_edges_for_function
parameter_list|(
name|FN
parameter_list|)
value|((FN)->cfg->x_n_edges)
end_define

begin_define
define|#
directive|define
name|last_basic_block_for_function
parameter_list|(
name|FN
parameter_list|)
value|((FN)->cfg->x_last_basic_block)
end_define

begin_define
define|#
directive|define
name|label_to_block_map_for_function
parameter_list|(
name|FN
parameter_list|)
value|((FN)->cfg->x_label_to_block_map)
end_define

begin_define
define|#
directive|define
name|BASIC_BLOCK_FOR_FUNCTION
parameter_list|(
name|FN
parameter_list|,
name|N
parameter_list|)
define|\
value|(VEC_index (basic_block, basic_block_info_for_function(FN), (N)))
end_define

begin_comment
comment|/* Defines for textual backward source compatibility.  */
end_comment

begin_define
define|#
directive|define
name|ENTRY_BLOCK_PTR
value|(cfun->cfg->x_entry_block_ptr)
end_define

begin_define
define|#
directive|define
name|EXIT_BLOCK_PTR
value|(cfun->cfg->x_exit_block_ptr)
end_define

begin_define
define|#
directive|define
name|basic_block_info
value|(cfun->cfg->x_basic_block_info)
end_define

begin_define
define|#
directive|define
name|n_basic_blocks
value|(cfun->cfg->x_n_basic_blocks)
end_define

begin_define
define|#
directive|define
name|n_edges
value|(cfun->cfg->x_n_edges)
end_define

begin_define
define|#
directive|define
name|last_basic_block
value|(cfun->cfg->x_last_basic_block)
end_define

begin_define
define|#
directive|define
name|label_to_block_map
value|(cfun->cfg->x_label_to_block_map)
end_define

begin_define
define|#
directive|define
name|profile_status
value|(cfun->cfg->x_profile_status)
end_define

begin_define
define|#
directive|define
name|BASIC_BLOCK
parameter_list|(
name|N
parameter_list|)
value|(VEC_index (basic_block, basic_block_info, (N)))
end_define

begin_define
define|#
directive|define
name|SET_BASIC_BLOCK
parameter_list|(
name|N
parameter_list|,
name|BB
parameter_list|)
value|(VEC_replace (basic_block, basic_block_info, (N), (BB)))
end_define

begin_comment
comment|/* For iterating over basic blocks.  */
end_comment

begin_define
define|#
directive|define
name|FOR_BB_BETWEEN
parameter_list|(
name|BB
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|DIR
parameter_list|)
define|\
value|for (BB = FROM; BB != TO; BB = BB->DIR)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_BB_FN
parameter_list|(
name|BB
parameter_list|,
name|FN
parameter_list|)
define|\
value|FOR_BB_BETWEEN (BB, (FN)->cfg->x_entry_block_ptr->next_bb, (FN)->cfg->x_exit_block_ptr, next_bb)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_BB
parameter_list|(
name|BB
parameter_list|)
value|FOR_EACH_BB_FN (BB, cfun)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_BB_REVERSE_FN
parameter_list|(
name|BB
parameter_list|,
name|FN
parameter_list|)
define|\
value|FOR_BB_BETWEEN (BB, (FN)->cfg->x_exit_block_ptr->prev_bb, (FN)->cfg->x_entry_block_ptr, prev_bb)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_BB_REVERSE
parameter_list|(
name|BB
parameter_list|)
value|FOR_EACH_BB_REVERSE_FN(BB, cfun)
end_define

begin_comment
comment|/* For iterating over insns in basic block.  */
end_comment

begin_define
define|#
directive|define
name|FOR_BB_INSNS
parameter_list|(
name|BB
parameter_list|,
name|INSN
parameter_list|)
define|\
value|for ((INSN) = BB_HEAD (BB);			\        (INSN)&& (INSN) != NEXT_INSN (BB_END (BB));	\        (INSN) = NEXT_INSN (INSN))
end_define

begin_define
define|#
directive|define
name|FOR_BB_INSNS_REVERSE
parameter_list|(
name|BB
parameter_list|,
name|INSN
parameter_list|)
define|\
value|for ((INSN) = BB_END (BB);			\        (INSN)&& (INSN) != PREV_INSN (BB_HEAD (BB));	\        (INSN) = PREV_INSN (INSN))
end_define

begin_comment
comment|/* Cycles through _all_ basic blocks, even the fake ones (entry and    exit block).  */
end_comment

begin_define
define|#
directive|define
name|FOR_ALL_BB
parameter_list|(
name|BB
parameter_list|)
define|\
value|for (BB = ENTRY_BLOCK_PTR; BB; BB = BB->next_bb)
end_define

begin_define
define|#
directive|define
name|FOR_ALL_BB_FN
parameter_list|(
name|BB
parameter_list|,
name|FN
parameter_list|)
define|\
value|for (BB = ENTRY_BLOCK_PTR_FOR_FUNCTION (FN); BB; BB = BB->next_bb)
end_define

begin_decl_stmt
specifier|extern
name|bitmap_obstack
name|reg_obstack
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indexed by n, gives number of basic block that  (REG n) is used in.    If the value is REG_BLOCK_GLOBAL (-2),    it means (REG n) is used in more than one basic block.    REG_BLOCK_UNKNOWN (-1) means it hasn't been seen yet so we don't know.    This information remains valid for the rest of the compilation    of the current function; it is used to control register allocation.  */
end_comment

begin_define
define|#
directive|define
name|REG_BLOCK_UNKNOWN
value|-1
end_define

begin_define
define|#
directive|define
name|REG_BLOCK_GLOBAL
value|-2
end_define

begin_define
define|#
directive|define
name|REG_BASIC_BLOCK
parameter_list|(
name|N
parameter_list|)
define|\
value|(VEC_index (reg_info_p, reg_n_info, N)->basic_block)
end_define

begin_escape
end_escape

begin_comment
comment|/* Stuff for recording basic block info.  */
end_comment

begin_define
define|#
directive|define
name|BB_HEAD
parameter_list|(
name|B
parameter_list|)
value|(B)->il.rtl->head_
end_define

begin_define
define|#
directive|define
name|BB_END
parameter_list|(
name|B
parameter_list|)
value|(B)->il.rtl->end_
end_define

begin_comment
comment|/* Special block numbers [markers] for entry and exit.  */
end_comment

begin_define
define|#
directive|define
name|ENTRY_BLOCK
value|(0)
end_define

begin_define
define|#
directive|define
name|EXIT_BLOCK
value|(1)
end_define

begin_comment
comment|/* The two blocks that are always in the cfg.  */
end_comment

begin_define
define|#
directive|define
name|NUM_FIXED_BLOCKS
value|(2)
end_define

begin_define
define|#
directive|define
name|BLOCK_NUM
parameter_list|(
name|INSN
parameter_list|)
value|(BLOCK_FOR_INSN (INSN)->index + 0)
end_define

begin_define
define|#
directive|define
name|set_block_for_insn
parameter_list|(
name|INSN
parameter_list|,
name|BB
parameter_list|)
value|(BLOCK_FOR_INSN (INSN) = BB)
end_define

begin_function_decl
specifier|extern
name|void
name|compute_bb_for_insn
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|free_bb_for_insn
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|update_bb_for_insn
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_basic_block_vars
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|insert_insn_on_edge
parameter_list|(
name|rtx
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|commit_edge_insertions
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|commit_edge_insertions_watch_calls
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_fake_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_fake_exit_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_noreturn_fake_exit_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|connect_infinite_loops_to_exit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|unchecked_make_edge
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|cached_make_edge
parameter_list|(
name|sbitmap
parameter_list|,
name|basic_block
parameter_list|,
name|basic_block
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|make_edge
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|make_single_succ_edge
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_edge
parameter_list|(
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|redirect_edge_succ
parameter_list|(
name|edge
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|redirect_edge_succ_nodup
parameter_list|(
name|edge
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|redirect_edge_pred
parameter_list|(
name|edge
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|create_basic_block_structure
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_bb_flags
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|post_order_compute
parameter_list|(
name|int
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pre_and_rev_post_order_compute
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|dfs_enumerate_from
parameter_list|(
name|basic_block
parameter_list|,
name|int
parameter_list|,
name|bool
function_decl|(
modifier|*
function_decl|)
parameter_list|(
name|basic_block
parameter_list|,
name|void
modifier|*
parameter_list|)
parameter_list|,
name|basic_block
modifier|*
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|compute_dominance_frontiers
parameter_list|(
name|bitmap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_bb_info
parameter_list|(
name|basic_block
parameter_list|,
name|bool
parameter_list|,
name|bool
parameter_list|,
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_edge_info
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|edge
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|brief_dump_cfg
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|first_insn_after_basic_block_note
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scale_bbs_frequencies_int
parameter_list|(
name|basic_block
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|scale_bbs_frequencies_gcov_type
parameter_list|(
name|basic_block
modifier|*
parameter_list|,
name|int
parameter_list|,
name|gcov_type
parameter_list|,
name|gcov_type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Structure to group all of the information to process IF-THEN and    IF-THEN-ELSE blocks for the conditional execution support.  This    needs to be in a public file in case the IFCVT macros call    functions passing the ce_if_block data structure.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ce_if_block
block|{
name|basic_block
name|test_bb
decl_stmt|;
comment|/* First test block.  */
name|basic_block
name|then_bb
decl_stmt|;
comment|/* THEN block.  */
name|basic_block
name|else_bb
decl_stmt|;
comment|/* ELSE block or NULL.  */
name|basic_block
name|join_bb
decl_stmt|;
comment|/* Join THEN/ELSE blocks.  */
name|basic_block
name|last_test_bb
decl_stmt|;
comment|/* Last bb to hold&& or || tests.  */
name|int
name|num_multiple_test_blocks
decl_stmt|;
comment|/* # of&& and || basic blocks.  */
name|int
name|num_and_and_blocks
decl_stmt|;
comment|/* # of&& blocks.  */
name|int
name|num_or_or_blocks
decl_stmt|;
comment|/* # of || blocks.  */
name|int
name|num_multiple_test_insns
decl_stmt|;
comment|/* # of insns in&& and || blocks.  */
name|int
name|and_and_p
decl_stmt|;
comment|/* Complex test is&&.  */
name|int
name|num_then_insns
decl_stmt|;
comment|/* # of insns in THEN block.  */
name|int
name|num_else_insns
decl_stmt|;
comment|/* # of insns in ELSE block.  */
name|int
name|pass
decl_stmt|;
comment|/* Pass number.  */
ifdef|#
directive|ifdef
name|IFCVT_EXTRA_FIELDS
name|IFCVT_EXTRA_FIELDS
comment|/* Any machine dependent fields.  */
endif|#
directive|endif
block|}
name|ce_if_block_t
typedef|;
end_typedef

begin_comment
comment|/* This structure maintains an edge list vector.  */
end_comment

begin_struct
struct|struct
name|edge_list
block|{
name|int
name|num_blocks
decl_stmt|;
name|int
name|num_edges
decl_stmt|;
name|edge
modifier|*
name|index_to_edge
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* The base value for branch probability notes and edge probabilities.  */
end_comment

begin_define
define|#
directive|define
name|REG_BR_PROB_BASE
value|10000
end_define

begin_comment
comment|/* This is the value which indicates no edge is present.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_INDEX_NO_EDGE
value|-1
end_define

begin_comment
comment|/* EDGE_INDEX returns an integer index for an edge, or EDGE_INDEX_NO_EDGE    if there is no edge between the 2 basic blocks.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_INDEX
parameter_list|(
name|el
parameter_list|,
name|pred
parameter_list|,
name|succ
parameter_list|)
value|(find_edge_index ((el), (pred), (succ)))
end_define

begin_comment
comment|/* INDEX_EDGE_PRED_BB and INDEX_EDGE_SUCC_BB return a pointer to the basic    block which is either the pred or succ end of the indexed edge.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_EDGE_PRED_BB
parameter_list|(
name|el
parameter_list|,
name|index
parameter_list|)
value|((el)->index_to_edge[(index)]->src)
end_define

begin_define
define|#
directive|define
name|INDEX_EDGE_SUCC_BB
parameter_list|(
name|el
parameter_list|,
name|index
parameter_list|)
value|((el)->index_to_edge[(index)]->dest)
end_define

begin_comment
comment|/* INDEX_EDGE returns a pointer to the edge.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_EDGE
parameter_list|(
name|el
parameter_list|,
name|index
parameter_list|)
value|((el)->index_to_edge[(index)])
end_define

begin_comment
comment|/* Number of edges in the compressed edge list.  */
end_comment

begin_define
define|#
directive|define
name|NUM_EDGES
parameter_list|(
name|el
parameter_list|)
value|((el)->num_edges)
end_define

begin_comment
comment|/* BB is assumed to contain conditional jump.  Return the fallthru edge.  */
end_comment

begin_define
define|#
directive|define
name|FALLTHRU_EDGE
parameter_list|(
name|bb
parameter_list|)
value|(EDGE_SUCC ((bb), 0)->flags& EDGE_FALLTHRU \ 					 ? EDGE_SUCC ((bb), 0) : EDGE_SUCC ((bb), 1))
end_define

begin_comment
comment|/* BB is assumed to contain conditional jump.  Return the branch edge.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_EDGE
parameter_list|(
name|bb
parameter_list|)
value|(EDGE_SUCC ((bb), 0)->flags& EDGE_FALLTHRU \ 					 ? EDGE_SUCC ((bb), 1) : EDGE_SUCC ((bb), 0))
end_define

begin_comment
comment|/* Return expected execution frequency of the edge E.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_FREQUENCY
parameter_list|(
name|e
parameter_list|)
value|(((e)->src->frequency \ 					  * (e)->probability \ 					  + REG_BR_PROB_BASE / 2) \ 					 / REG_BR_PROB_BASE)
end_define

begin_comment
comment|/* Return nonzero if edge is critical.  */
end_comment

begin_define
define|#
directive|define
name|EDGE_CRITICAL_P
parameter_list|(
name|e
parameter_list|)
value|(EDGE_COUNT ((e)->src->succs)>= 2 \&& EDGE_COUNT ((e)->dest->preds)>= 2)
end_define

begin_define
define|#
directive|define
name|EDGE_COUNT
parameter_list|(
name|ev
parameter_list|)
value|VEC_length (edge, (ev))
end_define

begin_define
define|#
directive|define
name|EDGE_I
parameter_list|(
name|ev
parameter_list|,
name|i
parameter_list|)
value|VEC_index  (edge, (ev), (i))
end_define

begin_define
define|#
directive|define
name|EDGE_PRED
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|)
value|VEC_index  (edge, (bb)->preds, (i))
end_define

begin_define
define|#
directive|define
name|EDGE_SUCC
parameter_list|(
name|bb
parameter_list|,
name|i
parameter_list|)
value|VEC_index  (edge, (bb)->succs, (i))
end_define

begin_comment
comment|/* Returns true if BB has precisely one successor.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|single_succ_p
parameter_list|(
name|basic_block
name|bb
parameter_list|)
block|{
return|return
name|EDGE_COUNT
argument_list|(
name|bb
operator|->
name|succs
argument_list|)
operator|==
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Returns true if BB has precisely one predecessor.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|single_pred_p
parameter_list|(
name|basic_block
name|bb
parameter_list|)
block|{
return|return
name|EDGE_COUNT
argument_list|(
name|bb
operator|->
name|preds
argument_list|)
operator|==
literal|1
return|;
block|}
end_function

begin_comment
comment|/* Returns the single successor edge of basic block BB.  Aborts if    BB does not have exactly one successor.  */
end_comment

begin_function
specifier|static
specifier|inline
name|edge
name|single_succ_edge
parameter_list|(
name|basic_block
name|bb
parameter_list|)
block|{
name|gcc_assert
argument_list|(
name|single_succ_p
argument_list|(
name|bb
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EDGE_SUCC
argument_list|(
name|bb
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Returns the single predecessor edge of basic block BB.  Aborts    if BB does not have exactly one predecessor.  */
end_comment

begin_function
specifier|static
specifier|inline
name|edge
name|single_pred_edge
parameter_list|(
name|basic_block
name|bb
parameter_list|)
block|{
name|gcc_assert
argument_list|(
name|single_pred_p
argument_list|(
name|bb
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|EDGE_PRED
argument_list|(
name|bb
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Returns the single successor block of basic block BB.  Aborts    if BB does not have exactly one successor.  */
end_comment

begin_function
specifier|static
specifier|inline
name|basic_block
name|single_succ
parameter_list|(
name|basic_block
name|bb
parameter_list|)
block|{
return|return
name|single_succ_edge
argument_list|(
name|bb
argument_list|)
operator|->
name|dest
return|;
block|}
end_function

begin_comment
comment|/* Returns the single predecessor block of basic block BB.  Aborts    if BB does not have exactly one predecessor.*/
end_comment

begin_function
specifier|static
specifier|inline
name|basic_block
name|single_pred
parameter_list|(
name|basic_block
name|bb
parameter_list|)
block|{
return|return
name|single_pred_edge
argument_list|(
name|bb
argument_list|)
operator|->
name|src
return|;
block|}
end_function

begin_comment
comment|/* Iterator object for edges.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|index
decl_stmt|;
name|VEC
argument_list|(
name|edge
argument_list|,
name|gc
argument_list|)
operator|*
operator|*
name|container
expr_stmt|;
block|}
name|edge_iterator
typedef|;
end_typedef

begin_expr_stmt
specifier|static
specifier|inline
name|VEC
argument_list|(
name|edge
argument_list|,
name|gc
argument_list|)
operator|*
name|ei_container
argument_list|(
argument|edge_iterator i
argument_list|)
block|{
name|gcc_assert
argument_list|(
name|i
operator|.
name|container
argument_list|)
block|;
return|return
operator|*
name|i
operator|.
name|container
return|;
block|}
end_expr_stmt

begin_define
define|#
directive|define
name|ei_start
parameter_list|(
name|iter
parameter_list|)
value|ei_start_1 (&(iter))
end_define

begin_define
define|#
directive|define
name|ei_last
parameter_list|(
name|iter
parameter_list|)
value|ei_last_1 (&(iter))
end_define

begin_comment
comment|/* Return an iterator pointing to the start of an edge vector.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|edge_iterator
name|ei_start_1
argument_list|(
name|VEC
argument_list|(
name|edge
argument_list|,
name|gc
argument_list|)
operator|*
operator|*
name|ev
argument_list|)
block|{
name|edge_iterator
name|i
decl_stmt|;
name|i
operator|.
name|index
operator|=
literal|0
expr_stmt|;
name|i
operator|.
name|container
operator|=
name|ev
expr_stmt|;
return|return
name|i
return|;
block|}
end_decl_stmt

begin_comment
comment|/* Return an iterator pointing to the last element of an edge    vector.  */
end_comment

begin_decl_stmt
specifier|static
specifier|inline
name|edge_iterator
name|ei_last_1
argument_list|(
name|VEC
argument_list|(
name|edge
argument_list|,
name|gc
argument_list|)
operator|*
operator|*
name|ev
argument_list|)
block|{
name|edge_iterator
name|i
decl_stmt|;
name|i
operator|.
name|index
operator|=
name|EDGE_COUNT
argument_list|(
operator|*
name|ev
argument_list|)
operator|-
literal|1
expr_stmt|;
name|i
operator|.
name|container
operator|=
name|ev
expr_stmt|;
return|return
name|i
return|;
block|}
end_decl_stmt

begin_comment
comment|/* Is the iterator `i' at the end of the sequence?  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|ei_end_p
parameter_list|(
name|edge_iterator
name|i
parameter_list|)
block|{
return|return
operator|(
name|i
operator|.
name|index
operator|==
name|EDGE_COUNT
argument_list|(
name|ei_container
argument_list|(
name|i
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Is the iterator `i' at one position before the end of the    sequence?  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|ei_one_before_end_p
parameter_list|(
name|edge_iterator
name|i
parameter_list|)
block|{
return|return
operator|(
name|i
operator|.
name|index
operator|+
literal|1
operator|==
name|EDGE_COUNT
argument_list|(
name|ei_container
argument_list|(
name|i
argument_list|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Advance the iterator to the next element.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ei_next
parameter_list|(
name|edge_iterator
modifier|*
name|i
parameter_list|)
block|{
name|gcc_assert
argument_list|(
name|i
operator|->
name|index
operator|<
name|EDGE_COUNT
argument_list|(
name|ei_container
argument_list|(
operator|*
name|i
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
name|i
operator|->
name|index
operator|++
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Move the iterator to the previous element.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ei_prev
parameter_list|(
name|edge_iterator
modifier|*
name|i
parameter_list|)
block|{
name|gcc_assert
argument_list|(
name|i
operator|->
name|index
operator|>
literal|0
argument_list|)
expr_stmt|;
name|i
operator|->
name|index
operator|--
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Return the edge pointed to by the iterator `i'.  */
end_comment

begin_function
specifier|static
specifier|inline
name|edge
name|ei_edge
parameter_list|(
name|edge_iterator
name|i
parameter_list|)
block|{
return|return
name|EDGE_I
argument_list|(
name|ei_container
argument_list|(
name|i
argument_list|)
argument_list|,
name|i
operator|.
name|index
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Return an edge pointed to by the iterator.  Do it safely so that    NULL is returned when the iterator is pointing at the end of the    sequence.  */
end_comment

begin_function
specifier|static
specifier|inline
name|edge
name|ei_safe_edge
parameter_list|(
name|edge_iterator
name|i
parameter_list|)
block|{
return|return
operator|!
name|ei_end_p
argument_list|(
name|i
argument_list|)
condition|?
name|ei_edge
argument_list|(
name|i
argument_list|)
else|:
name|NULL
return|;
block|}
end_function

begin_comment
comment|/* Return 1 if we should continue to iterate.  Return 0 otherwise.    *Edge P is set to the next edge if we are to continue to iterate    and NULL otherwise.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|ei_cond
parameter_list|(
name|edge_iterator
name|ei
parameter_list|,
name|edge
modifier|*
name|p
parameter_list|)
block|{
if|if
condition|(
operator|!
name|ei_end_p
argument_list|(
name|ei
argument_list|)
condition|)
block|{
operator|*
name|p
operator|=
name|ei_edge
argument_list|(
name|ei
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
else|else
block|{
operator|*
name|p
operator|=
name|NULL
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
end_function

begin_comment
comment|/* This macro serves as a convenient way to iterate each edge in a    vector of predecessor or successor edges.  It must not be used when    an element might be removed during the traversal, otherwise    elements will be missed.  Instead, use a for-loop like that shown    in the following pseudo-code:     FOR (ei = ei_start (bb->succs); (e = ei_safe_edge (ei)); )      { 	IF (e != taken_edge) 	  remove_edge (e); 	ELSE 	  ei_next (&ei);      } */
end_comment

begin_define
define|#
directive|define
name|FOR_EACH_EDGE
parameter_list|(
name|EDGE
parameter_list|,
name|ITER
parameter_list|,
name|EDGE_VEC
parameter_list|)
define|\
value|for ((ITER) = ei_start ((EDGE_VEC));		\        ei_cond ((ITER),&(EDGE));		\        ei_next (&(ITER)))
end_define

begin_function_decl
name|struct
name|edge_list
modifier|*
name|create_edge_list
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|free_edge_list
parameter_list|(
name|struct
name|edge_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|print_edge_list
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|edge_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|verify_edge_list
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|struct
name|edge_list
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|find_edge_index
parameter_list|(
name|struct
name|edge_list
modifier|*
parameter_list|,
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|edge
name|find_edge
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|update_life_extent
block|{
name|UPDATE_LIFE_LOCAL
init|=
literal|0
block|,
name|UPDATE_LIFE_GLOBAL
init|=
literal|1
block|,
name|UPDATE_LIFE_GLOBAL_RM_NOTES
init|=
literal|2
block|}
enum|;
end_enum

begin_comment
comment|/* Flags for life_analysis and update_life_info.  */
end_comment

begin_define
define|#
directive|define
name|PROP_DEATH_NOTES
value|1
end_define

begin_comment
comment|/* Create DEAD and UNUSED notes.  */
end_comment

begin_define
define|#
directive|define
name|PROP_LOG_LINKS
value|2
end_define

begin_comment
comment|/* Create LOG_LINKS.  */
end_comment

begin_define
define|#
directive|define
name|PROP_REG_INFO
value|4
end_define

begin_comment
comment|/* Update regs_ever_live et al.  */
end_comment

begin_define
define|#
directive|define
name|PROP_KILL_DEAD_CODE
value|8
end_define

begin_comment
comment|/* Remove dead code.  */
end_comment

begin_define
define|#
directive|define
name|PROP_SCAN_DEAD_CODE
value|16
end_define

begin_comment
comment|/* Scan for dead code.  */
end_comment

begin_define
define|#
directive|define
name|PROP_ALLOW_CFG_CHANGES
value|32
end_define

begin_comment
comment|/* Allow the CFG to be changed 					   by dead code removal.  */
end_comment

begin_define
define|#
directive|define
name|PROP_AUTOINC
value|64
end_define

begin_comment
comment|/* Create autoinc mem references.  */
end_comment

begin_define
define|#
directive|define
name|PROP_SCAN_DEAD_STORES
value|128
end_define

begin_comment
comment|/* Scan for dead code.  */
end_comment

begin_define
define|#
directive|define
name|PROP_ASM_SCAN
value|256
end_define

begin_comment
comment|/* Internal flag used within flow.c 					   to flag analysis of asms.  */
end_comment

begin_define
define|#
directive|define
name|PROP_DEAD_INSN
value|1024
end_define

begin_comment
comment|/* Internal flag used within flow.c 					   to flag analysis of dead insn.  */
end_comment

begin_define
define|#
directive|define
name|PROP_POST_REGSTACK
value|2048
end_define

begin_comment
comment|/* We run after reg-stack and need 					   to preserve REG_DEAD notes for 					   stack regs.  */
end_comment

begin_define
define|#
directive|define
name|PROP_FINAL
value|(PROP_DEATH_NOTES | PROP_LOG_LINKS  \ 				 | PROP_REG_INFO | PROP_KILL_DEAD_CODE  \ 				 | PROP_SCAN_DEAD_CODE | PROP_AUTOINC \ 				 | PROP_ALLOW_CFG_CHANGES \ 				 | PROP_SCAN_DEAD_STORES)
end_define

begin_define
define|#
directive|define
name|PROP_POSTRELOAD
value|(PROP_DEATH_NOTES  \ 				 | PROP_KILL_DEAD_CODE  \ 				 | PROP_SCAN_DEAD_CODE \ 				 | PROP_SCAN_DEAD_STORES)
end_define

begin_define
define|#
directive|define
name|CLEANUP_EXPENSIVE
value|1
end_define

begin_comment
comment|/* Do relatively expensive optimizations 					   except for edge forwarding */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_CROSSJUMP
value|2
end_define

begin_comment
comment|/* Do crossjumping.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_POST_REGSTACK
value|4
end_define

begin_comment
comment|/* We run after reg-stack and need 					   to care REG_DEAD notes.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_UPDATE_LIFE
value|8
end_define

begin_comment
comment|/* Keep life information up to date.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_THREADING
value|16
end_define

begin_comment
comment|/* Do jump threading.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_NO_INSN_DEL
value|32
end_define

begin_comment
comment|/* Do not try to delete trivially dead 					   insns.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_CFGLAYOUT
value|64
end_define

begin_comment
comment|/* Do cleanup in cfglayout mode.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_LOG_LINKS
value|128
end_define

begin_comment
comment|/* Update log links.  */
end_comment

begin_comment
comment|/* The following are ORed in on top of the CLEANUP* flags in calls to    struct_equiv_block_eq.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_EQUIV_START
value|256
end_define

begin_comment
comment|/* Initializes the search range.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_EQUIV_RERUN
value|512
end_define

begin_comment
comment|/* Rerun to find register use in 					   found equivalence.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_EQUIV_FINAL
value|1024
end_define

begin_comment
comment|/* Make any changes necessary to get 					   actual equivalence.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_EQUIV_NEED_FULL_BLOCK
value|2048
end_define

begin_comment
comment|/* struct_equiv_block_eq is required 					     to match only full blocks  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_EQUIV_MATCH_JUMPS
value|4096
end_define

begin_comment
comment|/* Also include the jumps at the end of the block in the comparison.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|life_analysis
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|update_life_info
parameter_list|(
name|sbitmap
parameter_list|,
name|enum
name|update_life_extent
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|update_life_info_in_dirty_blocks
parameter_list|(
name|enum
name|update_life_extent
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|count_or_remove_death_notes
parameter_list|(
name|sbitmap
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|propagate_block
parameter_list|(
name|basic_block
parameter_list|,
name|regset
parameter_list|,
name|regset
parameter_list|,
name|regset
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_struct_decl
struct_decl|struct
name|propagate_block_info
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|rtx
name|propagate_one_insn
parameter_list|(
name|struct
name|propagate_block_info
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|propagate_block_info
modifier|*
name|init_propagate_block_info
parameter_list|(
name|basic_block
parameter_list|,
name|regset
parameter_list|,
name|regset
parameter_list|,
name|regset
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_propagate_block_info
parameter_list|(
name|struct
name|propagate_block_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In lcm.c */
end_comment

begin_function_decl
specifier|extern
name|struct
name|edge_list
modifier|*
name|pre_edge_lcm
parameter_list|(
name|int
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
modifier|*
parameter_list|,
name|sbitmap
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|edge_list
modifier|*
name|pre_edge_rev_lcm
parameter_list|(
name|int
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
modifier|*
parameter_list|,
name|sbitmap
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|compute_available
parameter_list|(
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|,
name|sbitmap
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In predict.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|expected_value_to_br_prob
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|maybe_hot_bb_p
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|probably_cold_bb_p
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|probably_never_executed_bb_p
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|tree_predicted_by_p
parameter_list|(
name|basic_block
parameter_list|,
name|enum
name|br_predictor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|rtl_predicted_by_p
parameter_list|(
name|basic_block
parameter_list|,
name|enum
name|br_predictor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|tree_predict_edge
parameter_list|(
name|edge
parameter_list|,
name|enum
name|br_predictor
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtl_predict_edge
parameter_list|(
name|edge
parameter_list|,
name|enum
name|br_predictor
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|predict_edge_def
parameter_list|(
name|edge
parameter_list|,
name|enum
name|br_predictor
parameter_list|,
name|enum
name|prediction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|guess_outgoing_edge_probabilities
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|remove_predictions_associated_with_edge
parameter_list|(
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|edge_probability_reliable_p
parameter_list|(
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|br_prob_note_reliable_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In flow.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_flow
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_bb
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|debug_bb_n
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dump_regset
parameter_list|(
name|regset
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|debug_regset
parameter_list|(
name|regset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|allocate_reg_life_data
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|expunge_block
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|link_block
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|unlink_block
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|compact_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|alloc_block
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_unreachable_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|delete_noop_moves
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|force_nonfallthru
parameter_list|(
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|block_label
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|forwarder_block_p
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|purge_all_dead_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|purge_dead_edges
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_many_sub_basic_blocks
parameter_list|(
name|sbitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|rtl_make_eh_edge
parameter_list|(
name|sbitmap
parameter_list|,
name|basic_block
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|can_fallthru
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|could_fall_through
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flow_nodes_print
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|sbitmap
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flow_edge_list_print
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|edge
modifier|*
parameter_list|,
name|int
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alloc_aux_for_block
parameter_list|(
name|basic_block
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alloc_aux_for_blocks
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_aux_for_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_aux_for_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alloc_aux_for_edge
parameter_list|(
name|edge
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|alloc_aux_for_edges
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|clear_aux_for_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_aux_for_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_basic_blocks
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|cleanup_cfg
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|delete_unreachable_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|merge_seq_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
name|struct
name|conflict_graph_def
modifier|*
name|conflict_graph
typedef|;
end_typedef

begin_comment
comment|/* Callback function when enumerating conflicts.  The arguments are    the smaller and larger regno in the conflict.  Returns zero if    enumeration is to continue, nonzero to halt enumeration.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|conflict_graph_enum_fn
function_decl|)
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Prototypes of operations on conflict graphs.  */
end_comment

begin_function_decl
specifier|extern
name|conflict_graph
name|conflict_graph_new
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|conflict_graph_delete
parameter_list|(
name|conflict_graph
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|conflict_graph_add
parameter_list|(
name|conflict_graph
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|conflict_graph_conflict_p
parameter_list|(
name|conflict_graph
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|conflict_graph_enum
parameter_list|(
name|conflict_graph
parameter_list|,
name|int
parameter_list|,
name|conflict_graph_enum_fn
parameter_list|,
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|conflict_graph_merge_regs
parameter_list|(
name|conflict_graph
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|conflict_graph_print
parameter_list|(
name|conflict_graph
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|mark_dfs_back_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_edge_can_fallthru_flag
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|update_br_prob_note
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|fixup_abnormal_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|inside_basic_block_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|control_flow_insn_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_last_bb_insn
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In bb-reorder.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|reorder_basic_blocks
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In dominance.c */
end_comment

begin_enum
enum|enum
name|cdi_direction
block|{
name|CDI_DOMINATORS
block|,
name|CDI_POST_DOMINATORS
block|}
enum|;
end_enum

begin_enum
enum|enum
name|dom_state
block|{
name|DOM_NONE
block|,
comment|/* Not computed at all.  */
name|DOM_NO_FAST_QUERY
block|,
comment|/* The data is OK, but the fast query data are not usable.  */
name|DOM_OK
comment|/* Everything is ok.  */
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|dom_state
name|dom_computed
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|bool
name|dom_info_available_p
parameter_list|(
name|enum
name|cdi_direction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|calculate_dominance_info
parameter_list|(
name|enum
name|cdi_direction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_dominance_info
parameter_list|(
name|enum
name|cdi_direction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|nearest_common_dominator
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|nearest_common_dominator_for_set
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|bitmap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_immediate_dominator
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|get_immediate_dominator
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|dominated_by_p
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|get_dominated_by
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|,
name|basic_block
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|get_dominated_by_region
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
modifier|*
parameter_list|,
name|unsigned
parameter_list|,
name|basic_block
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|add_to_dominance_info
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|delete_from_dominance_info
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|basic_block
name|recount_dominator
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|redirect_immediate_dominators
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|iterate_fix_dominators
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|verify_dominators
parameter_list|(
name|enum
name|cdi_direction
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|first_dom_son
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|next_dom_son
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|bb_dom_dfs_in
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|unsigned
name|bb_dom_dfs_out
parameter_list|(
name|enum
name|cdi_direction
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|edge
name|try_redirect_by_replacing_jump
parameter_list|(
name|edge
parameter_list|,
name|basic_block
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|break_superblocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|check_bb_profile
parameter_list|(
name|basic_block
parameter_list|,
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|update_bb_profile_for_threading
parameter_list|(
name|basic_block
parameter_list|,
name|int
parameter_list|,
name|gcov_type
parameter_list|,
name|edge
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_rtl_bb_info
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|initialize_original_copy_tables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|free_original_copy_tables
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_bb_original
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|get_bb_original
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|set_bb_copy
parameter_list|(
name|basic_block
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|basic_block
name|get_bb_copy
parameter_list|(
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|insert_insn_end_bb_new
parameter_list|(
name|rtx
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_include
include|#
directive|include
file|"cfghooks.h"
end_include

begin_comment
comment|/* In struct-equiv.c */
end_comment

begin_comment
comment|/* Constants used to size arrays in struct equiv_info (currently only one).    When these limits are exceeded, struct_equiv returns zero.    The maximum number of pseudo registers that are different in the two blocks,    but appear in equivalent places and are dead at the end (or where one of    a pair is dead at the end).  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_EQUIV_MAX_LOCAL
value|16
end_define

begin_comment
comment|/* The maximum number of references to an input register that struct_equiv    can handle.  */
end_comment

begin_comment
comment|/* Structure used to track state during struct_equiv that can be rolled    back when we find we can't match an insn, or if we want to match part    of it in a different way.    This information pertains to the pair of partial blocks that has been    matched so far.  Since this pair is structurally equivalent, this is    conceptually just one partial block expressed in two potentially    different ways.  */
end_comment

begin_struct
struct|struct
name|struct_equiv_checkpoint
block|{
name|int
name|ninsns
decl_stmt|;
comment|/* Insns are matched so far.  */
name|int
name|local_count
decl_stmt|;
comment|/* Number of block-local registers.  */
name|int
name|input_count
decl_stmt|;
comment|/* Number of inputs to the block.  */
comment|/* X_START and Y_START are the first insns (in insn stream order)      of the partial blocks that have been considered for matching so far.      Since we are scanning backwards, they are also the instructions that      are currently considered - or the last ones that have been considered -      for matching (Unless we tracked back to these because a preceding      instruction failed to match).  */
name|rtx
name|x_start
decl_stmt|,
name|y_start
decl_stmt|;
comment|/*  INPUT_VALID indicates if we have actually set up X_INPUT / Y_INPUT       during the current pass; we keep X_INPUT / Y_INPUT around between passes       so that we can match REG_EQUAL / REG_EQUIV notes referring to these.  */
name|bool
name|input_valid
decl_stmt|;
comment|/* Some information would be expensive to exactly checkpoint, so we      merely increment VERSION any time information about local      registers, inputs and/or register liveness changes.  When backtracking,      it is decremented for changes that can be undone, and if a discrepancy      remains, NEED_RERUN in the relevant struct equiv_info is set to indicate      that a new pass should be made over the entire block match to get      accurate register information.  */
name|int
name|version
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A struct equiv_info is used to pass information to struct_equiv and    to gather state while two basic blocks are checked for structural    equivalence.  */
end_comment

begin_struct
struct|struct
name|equiv_info
block|{
comment|/* Fields set up by the caller to struct_equiv_block_eq */
name|basic_block
name|x_block
decl_stmt|,
name|y_block
decl_stmt|;
comment|/* The two blocks being matched.  */
comment|/* MODE carries the mode bits from cleanup_cfg if we are called from      try_crossjump_to_edge, and additionally it carries the      STRUCT_EQUIV_* bits described above.  */
name|int
name|mode
decl_stmt|;
comment|/* INPUT_COST is the cost that adding an extra input to the matched blocks      is supposed to have, and is taken into account when considering if the      matched sequence should be extended backwards.  input_cost< 0 means      don't accept any inputs at all.  */
name|int
name|input_cost
decl_stmt|;
comment|/* Fields to track state inside of struct_equiv_block_eq.  Some of these      are also outputs.  */
comment|/* X_INPUT and Y_INPUT are used by struct_equiv to record a register that      is used as an input parameter, i.e. where different registers are used      as sources.  This is only used for a register that is live at the end      of the blocks, or in some identical code at the end of the blocks;      Inputs that are dead at the end go into X_LOCAL / Y_LOCAL.  */
name|rtx
name|x_input
decl_stmt|,
name|y_input
decl_stmt|;
comment|/* When a previous pass has identified a valid input, INPUT_REG is set      by struct_equiv_block_eq, and it is henceforth replaced in X_BLOCK      for the input.  */
name|rtx
name|input_reg
decl_stmt|;
comment|/* COMMON_LIVE keeps track of the registers which are currently live      (as we scan backwards from the end) and have the same numbers in both      blocks.  N.B. a register that is in common_live is unsuitable to become      a local reg.  */
name|regset
name|common_live
decl_stmt|;
comment|/* Likewise, X_LOCAL_LIVE / Y_LOCAL_LIVE keep track of registers that are      local to one of the blocks; these registers must not be accepted as      identical when encountered in both blocks.  */
name|regset
name|x_local_live
decl_stmt|,
name|y_local_live
decl_stmt|;
comment|/* EQUIV_USED indicates for which insns a REG_EQUAL or REG_EQUIV note is      being used, to avoid having to backtrack in the next pass, so that we      get accurate life info for this insn then.  For each such insn,      the bit with the number corresponding to the CUR.NINSNS value at the      time of scanning is set.  */
name|bitmap
name|equiv_used
decl_stmt|;
comment|/* Current state that can be saved& restored easily.  */
name|struct
name|struct_equiv_checkpoint
name|cur
decl_stmt|;
comment|/* BEST_MATCH is used to store the best match so far, weighing the      cost of matched insns COSTS_N_INSNS (CUR.NINSNS) against the cost      CUR.INPUT_COUNT * INPUT_COST of setting up the inputs.  */
name|struct
name|struct_equiv_checkpoint
name|best_match
decl_stmt|;
comment|/* If a checkpoint restore failed, or an input conflict newly arises,      NEED_RERUN is set.  This has to be tested by the caller to re-run      the comparison if the match appears otherwise sound.  The state kept in      x_start, y_start, equiv_used and check_input_conflict ensures that      we won't loop indefinitely.  */
name|bool
name|need_rerun
decl_stmt|;
comment|/* If there is indication of an input conflict at the end,      CHECK_INPUT_CONFLICT is set so that we'll check for input conflicts      for each insn in the next pass.  This is needed so that we won't discard      a partial match if there is a longer match that has to be abandoned due      to an input conflict.  */
name|bool
name|check_input_conflict
decl_stmt|;
comment|/* HAD_INPUT_CONFLICT is set if CHECK_INPUT_CONFLICT was already set and we      have passed a point where there were multiple dying inputs.  This helps      us decide if we should set check_input_conflict for the next pass.  */
name|bool
name|had_input_conflict
decl_stmt|;
comment|/* LIVE_UPDATE controls if we want to change any life info at all.  We      set it to false during REG_EQUAL / REG_EUQIV note comparison of the final      pass so that we don't introduce new registers just for the note; if we      can't match the notes without the current register information, we drop      them.  */
name|bool
name|live_update
decl_stmt|;
comment|/* X_LOCAL and Y_LOCAL are used to gather register numbers of register pairs      that are local to X_BLOCK and Y_BLOCK, with CUR.LOCAL_COUNT being the index      to the next free entry.  */
name|rtx
name|x_local
index|[
name|STRUCT_EQUIV_MAX_LOCAL
index|]
decl_stmt|,
name|y_local
index|[
name|STRUCT_EQUIV_MAX_LOCAL
index|]
decl_stmt|;
comment|/* LOCAL_RVALUE is nonzero if the corresponding X_LOCAL / Y_LOCAL entry      was a source operand (including STRICT_LOW_PART) for the last invocation      of struct_equiv mentioning it, zero if it was a destination-only operand.      Since we are scanning backwards, this means the register is input/local      for the (partial) block scanned so far.  */
name|bool
name|local_rvalue
index|[
name|STRUCT_EQUIV_MAX_LOCAL
index|]
decl_stmt|;
comment|/* Additional fields that are computed for the convenience of the caller.  */
comment|/* DYING_INPUTS is set to the number of local registers that turn out      to be inputs to the (possibly partial) block.  */
name|int
name|dying_inputs
decl_stmt|;
comment|/* X_END and Y_END are the last insns in X_BLOCK and Y_BLOCK, respectively,      that are being compared.  A final jump insn will not be included.  */
name|rtx
name|x_end
decl_stmt|,
name|y_end
decl_stmt|;
comment|/* If we are matching tablejumps, X_LABEL in X_BLOCK corresponds to      Y_LABEL in Y_BLOCK.  */
name|rtx
name|x_label
decl_stmt|,
name|y_label
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
specifier|extern
name|bool
name|insns_match_p
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|struct
name|equiv_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|struct_equiv_block_eq
parameter_list|(
name|int
parameter_list|,
name|struct
name|equiv_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|struct_equiv_init
parameter_list|(
name|int
parameter_list|,
name|struct
name|equiv_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|rtx_equiv_p
parameter_list|(
name|rtx
modifier|*
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|,
name|struct
name|equiv_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In cfgrtl.c */
end_comment

begin_function_decl
specifier|extern
name|bool
name|condjump_equiv_p
parameter_list|(
name|struct
name|equiv_info
modifier|*
parameter_list|,
name|bool
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true when one of the predecessor edges of BB is marked with EDGE_EH.  */
end_comment

begin_function
specifier|static
specifier|inline
name|bool
name|bb_has_eh_pred
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
argument|bb->preds
argument_list|)
block|{
if|if
condition|(
name|e
operator|->
name|flags
operator|&
name|EDGE_EH
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_BASIC_BLOCK_H */
end_comment

end_unit

