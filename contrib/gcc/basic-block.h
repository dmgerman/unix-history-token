begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define control and data flow tables, and regsets.    Copyright (C) 1987, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Initialize a new regset.  */
end_comment

begin_define
define|#
directive|define
name|INIT_REG_SET
parameter_list|(
name|HEAD
parameter_list|)
value|bitmap_initialize (HEAD)
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
value|bitmap_operation (TO, TO, FROM, BITMAP_AND)
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
define|\
value|bitmap_operation (TO, TO, FROM, BITMAP_AND_COMPL)
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
value|bitmap_operation (TO, TO, FROM, BITMAP_IOR)
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
value|bitmap_operation (TO, TO, FROM, BITMAP_XOR)
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
value|bitmap_ior_and_compl (TO, FROM1, FROM2)
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

begin_decl_stmt
specifier|extern
name|void
name|reg_set_to_hard_reg_set
name|PARAMS
argument_list|(
operator|(
name|HARD_REG_SET
operator|*
operator|,
name|bitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|CODE
parameter_list|)
define|\
value|EXECUTE_IF_SET_IN_BITMAP (REGSET, MIN, REGNUM, CODE)
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
name|CODE
parameter_list|)
define|\
value|EXECUTE_IF_AND_COMPL_IN_BITMAP (REGSET1, REGSET2, MIN, REGNUM, CODE)
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
name|CODE
parameter_list|)
define|\
value|EXECUTE_IF_AND_IN_BITMAP (REGSET1, REGSET2, MIN, REGNUM, CODE)
end_define

begin_comment
comment|/* Allocate a register set with oballoc.  */
end_comment

begin_define
define|#
directive|define
name|OBSTACK_ALLOC_REG_SET
parameter_list|(
name|OBSTACK
parameter_list|)
value|BITMAP_OBSTACK_ALLOC (OBSTACK)
end_define

begin_comment
comment|/* Initialize a register set.  Returns the new register set.  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_REG_SET
parameter_list|(
name|HEAD
parameter_list|)
value|bitmap_initialize (&HEAD)
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
value|BITMAP_FREE(REGSET)
end_define

begin_comment
comment|/* Do any one-time initializations needed for regsets.  */
end_comment

begin_define
define|#
directive|define
name|INIT_ONCE_REG_SET
parameter_list|()
value|BITMAP_INIT_ONCE ()
end_define

begin_comment
comment|/* Grow any tables needed when the number of registers is calculated    or extended.  For the linked list allocation, nothing needs to    be done, other than zero the statistics on the first allocation.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGNO_REG_SET
parameter_list|(
name|NUM_REGS
parameter_list|,
name|NEW_P
parameter_list|,
name|RENUMBER_P
parameter_list|)
end_define

begin_comment
comment|/* Type we use to hold basic block counters.  Should be at least 64bit.  */
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

begin_typedef
typedef|typedef
struct|struct
name|edge_def
block|{
comment|/* Links through the predecessor and successor lists.  */
name|struct
name|edge_def
modifier|*
name|pred_next
decl_stmt|,
modifier|*
name|succ_next
decl_stmt|;
comment|/* The two blocks at the ends of the edge.  */
name|struct
name|basic_block_def
modifier|*
name|src
decl_stmt|,
modifier|*
name|dest
decl_stmt|;
comment|/* Instructions queued on the edge.  */
name|rtx
name|insns
decl_stmt|;
comment|/* Auxiliary info specific to a pass.  */
name|void
modifier|*
name|aux
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
block|}
typedef|*
name|edge
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EDGE_FALLTHRU
value|1
end_define

begin_define
define|#
directive|define
name|EDGE_ABNORMAL
value|2
end_define

begin_define
define|#
directive|define
name|EDGE_ABNORMAL_CALL
value|4
end_define

begin_define
define|#
directive|define
name|EDGE_EH
value|8
end_define

begin_define
define|#
directive|define
name|EDGE_FAKE
value|16
end_define

begin_define
define|#
directive|define
name|EDGE_DFS_BACK
value|32
end_define

begin_define
define|#
directive|define
name|EDGE_COMPLEX
value|(EDGE_ABNORMAL | EDGE_ABNORMAL_CALL | EDGE_EH)
end_define

begin_comment
comment|/* A basic block is a sequence of instructions with only entry and    only one exit.  If any one of the instructions are executed, they    will all be executed, and in sequence from first to last.     There may be COND_EXEC instructions in the basic block.  The    COND_EXEC *instructions* will be executed -- but if the condition    is false the conditionally executed *expressions* will of course    not be executed.  We don't consider the conditionally executed    expression (which might have side-effects) to be in a separate    basic block because the program counter will always be at the same    location after the COND_EXEC instruction, regardless of whether the    condition is true or not.     Basic blocks need not start with a label nor end with a jump insn.    For example, a previous basic block may just "conditionally fall"    into the succeeding basic block, and the last basic block need not    end with a jump insn.  Block 0 is a descendant of the entry block.     A basic block beginning with two labels cannot have notes between    the labels.     Data for jump tables are stored in jump_insns that occur in no    basic block even though these insns can follow or precede insns in    basic blocks.  */
end_comment

begin_comment
comment|/* Basic block information indexed by block number.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|basic_block_def
block|{
comment|/* The first and last insns of the block.  */
name|rtx
name|head
decl_stmt|,
name|end
decl_stmt|;
comment|/* The first and last trees of the block.  */
name|tree
name|head_tree
decl_stmt|;
name|tree
name|end_tree
decl_stmt|;
comment|/* The edges into and out of the block.  */
name|edge
name|pred
decl_stmt|,
name|succ
decl_stmt|;
comment|/* Liveness info.  */
comment|/* The registers that are modified within this in block.  */
name|regset
name|local_set
decl_stmt|;
comment|/* The registers that are conditionally modified within this block.      In other words, registers that are set only as part of a      COND_EXEC.  */
name|regset
name|cond_local_set
decl_stmt|;
comment|/* The registers that are live on entry to this block.       Note that in SSA form, global_live_at_start does not reflect the      use of regs in phi functions, since the liveness of these regs      may depend on which edge was taken into the block.  */
name|regset
name|global_live_at_start
decl_stmt|;
comment|/* The registers that are live on exit from this block.  */
name|regset
name|global_live_at_end
decl_stmt|;
comment|/* Auxiliary info specific to a pass.  */
name|void
modifier|*
name|aux
decl_stmt|;
comment|/* The index of this block.  */
name|int
name|index
decl_stmt|;
comment|/* The loop depth of this block.  */
name|int
name|loop_depth
decl_stmt|;
comment|/* Expected number of executions: calculated in profile.c.  */
name|gcov_type
name|count
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
typedef|*
name|basic_block
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BB_FREQ_MAX
value|10000
end_define

begin_comment
comment|/* Masks for basic_block.flags.  */
end_comment

begin_define
define|#
directive|define
name|BB_REACHABLE
value|1
end_define

begin_comment
comment|/* Number of basic blocks in the current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_basic_blocks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of edges in the current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_edges
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index by basic block number, get basic block struct info.  */
end_comment

begin_decl_stmt
specifier|extern
name|varray_type
name|basic_block_info
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BASIC_BLOCK
parameter_list|(
name|N
parameter_list|)
value|(VARRAY_BB (basic_block_info, (N)))
end_define

begin_comment
comment|/* What registers are live at the setjmp call.  */
end_comment

begin_decl_stmt
specifier|extern
name|regset
name|regs_live_at_setjmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Special labels found during CFG build.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|label_value_list
decl_stmt|,
name|tail_recursion_label_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|obstack
name|flow_obstack
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
value|(VARRAY_REG (reg_n_info, N)->basic_block)
end_define

begin_escape
end_escape

begin_comment
comment|/* Stuff for recording basic block info.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_HEAD
parameter_list|(
name|B
parameter_list|)
value|(BASIC_BLOCK (B)->head)
end_define

begin_define
define|#
directive|define
name|BLOCK_END
parameter_list|(
name|B
parameter_list|)
value|(BASIC_BLOCK (B)->end)
end_define

begin_define
define|#
directive|define
name|BLOCK_HEAD_TREE
parameter_list|(
name|B
parameter_list|)
value|(BASIC_BLOCK (B)->head_tree)
end_define

begin_define
define|#
directive|define
name|BLOCK_END_TREE
parameter_list|(
name|B
parameter_list|)
value|(BASIC_BLOCK (B)->end_tree)
end_define

begin_comment
comment|/* Special block numbers [markers] for entry and exit.  */
end_comment

begin_define
define|#
directive|define
name|ENTRY_BLOCK
value|(-1)
end_define

begin_define
define|#
directive|define
name|EXIT_BLOCK
value|(-2)
end_define

begin_comment
comment|/* Special block number not valid for any block.  */
end_comment

begin_define
define|#
directive|define
name|INVALID_BLOCK
value|(-3)
end_define

begin_comment
comment|/* Similarly, block pointers for the edge list.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|basic_block_def
name|entry_exit_blocks
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ENTRY_BLOCK_PTR
value|(&entry_exit_blocks[0])
end_define

begin_define
define|#
directive|define
name|EXIT_BLOCK_PTR
value|(&entry_exit_blocks[1])
end_define

begin_decl_stmt
specifier|extern
name|varray_type
name|basic_block_for_insn
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BLOCK_FOR_INSN
parameter_list|(
name|INSN
parameter_list|)
value|VARRAY_BB (basic_block_for_insn, INSN_UID (INSN))
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

begin_decl_stmt
specifier|extern
name|void
name|compute_bb_for_insn
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_bb_for_insn
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|update_bb_for_insn
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|set_block_for_insn
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_basic_block_vars
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|edge
name|split_block
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|basic_block
name|split_edge
name|PARAMS
argument_list|(
operator|(
name|edge
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|insert_insn_on_edge
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|edge
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|commit_edge_insertions
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|remove_fake_edges
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|add_noreturn_fake_exit_edges
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|connect_infinite_loops_to_exit
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flow_call_edges_add
name|PARAMS
argument_list|(
operator|(
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|edge
name|cached_make_edge
name|PARAMS
argument_list|(
operator|(
name|sbitmap
operator|*
operator|,
name|basic_block
operator|,
name|basic_block
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|edge
name|make_edge
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|,
name|basic_block
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|edge
name|make_single_succ_edge
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|,
name|basic_block
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|remove_edge
name|PARAMS
argument_list|(
operator|(
name|edge
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|redirect_edge_succ
name|PARAMS
argument_list|(
operator|(
name|edge
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|edge
name|redirect_edge_succ_nodup
name|PARAMS
argument_list|(
operator|(
name|edge
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|redirect_edge_pred
name|PARAMS
argument_list|(
operator|(
name|edge
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|basic_block
name|create_basic_block_structure
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|basic_block
name|create_basic_block
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flow_delete_block
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|merge_blocks_nomove
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tidy_fallthru_edge
name|PARAMS
argument_list|(
operator|(
name|edge
operator|,
name|basic_block
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|tidy_fallthru_edges
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flow_reverse_top_sort_order_compute
name|PARAMS
argument_list|(
operator|(
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flow_depth_first_order_compute
name|PARAMS
argument_list|(
operator|(
name|int
operator|*
operator|,
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flow_preorder_transversal_compute
name|PARAMS
argument_list|(
operator|(
name|int
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_edge_info
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|edge
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_edges
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|mark_critical_edges
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|first_insn_after_basic_block_note
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* Basic block of loop pre-header or NULL if it does not exist.  */
name|basic_block
name|pre_header
decl_stmt|;
comment|/* Array of edges along the pre-header extended basic block trace.      The source of the first edge is the root node of pre-header      extended basic block, if it exists.  */
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
name|int
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
comment|/* Non-zero if the loop shares a header with another loop.  */
name|int
name|shared
decl_stmt|;
comment|/* Non-zero if the loop is invalid (e.g., contains setjmp.).  */
name|int
name|invalid
decl_stmt|;
comment|/* Auxiliary info specific to a pass.  */
name|void
modifier|*
name|aux
decl_stmt|;
comment|/* The following are currently used by loop.c but they are likely to      disappear as loop.c is converted to use the CFG.  */
comment|/* Non-zero if the loop has a NOTE_INSN_LOOP_VTOP.  */
name|rtx
name|vtop
decl_stmt|;
comment|/* Non-zero if the loop has a NOTE_INSN_LOOP_CONT.      A continue statement will generate a branch to NEXT_INSN (cont).  */
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
comment|/* List of all LABEL_REFs which refer to code labels outside the      loop.  Used by routines that need to know all loop exits, such as      final_biv_value and final_giv_value.       This does not include loop exits due to return instructions.      This is because all bivs and givs are pseudos, and hence must be      dead after a return, so the presense of a return does not affect      any of the optimizations that use this info.  It is simpler to      just not include return instructions on this list.  */
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
comment|/* Structure to hold CFG information about natural loops within a function.  */
end_comment

begin_struct
struct|struct
name|loops
block|{
comment|/* Number of natural loops in the function.  */
name|int
name|num
decl_stmt|;
comment|/* Maxium nested loop level in the function.  */
name|int
name|levels
decl_stmt|;
comment|/* Array of natural loop descriptors (scanning this array in reverse order      will find the inner loops before their enclosing outer loops).  */
name|struct
name|loop
modifier|*
name|array
decl_stmt|;
comment|/* Pointer to root of loop heirachy tree.  */
name|struct
name|loop
modifier|*
name|tree_root
decl_stmt|;
comment|/* Information derived from the CFG.  */
struct|struct
name|cfg
block|{
comment|/* The bitmap vector of dominators or NULL if not computed.  */
name|sbitmap
modifier|*
name|dom
decl_stmt|;
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

begin_decl_stmt
specifier|extern
name|int
name|flow_loops_find
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loops
operator|*
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flow_loops_update
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loops
operator|*
operator|,
name|int
name|flags
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flow_loops_free
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loops
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flow_loops_dump
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loops
operator|*
operator|,
name|FILE
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
expr|struct
name|loop
operator|*
argument_list|,
name|FILE
operator|*
argument_list|,
name|int
argument_list|)
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flow_loop_dump
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
name|FILE
operator|*
operator|,
name|void
argument_list|(
operator|*
argument_list|)
argument_list|(
specifier|const
expr|struct
name|loop
operator|*
argument_list|,
name|FILE
operator|*
argument_list|,
name|int
argument_list|)
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flow_loop_scan
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loops
operator|*
operator|,
expr|struct
name|loop
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|((bb)->succ->flags& EDGE_FALLTHRU \ 					 ? (bb)->succ : (bb)->succ->succ_next)
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
value|((bb)->succ->flags& EDGE_FALLTHRU \ 					 ? (bb)->succ->succ_next : (bb)->succ)
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
value|((e)->src->succ->succ_next \&& (e)->dest->pred->pred_next)
end_define

begin_decl_stmt
name|struct
name|edge_list
modifier|*
name|create_edge_list
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|free_edge_list
name|PARAMS
argument_list|(
operator|(
expr|struct
name|edge_list
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|print_edge_list
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
expr|struct
name|edge_list
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|verify_edge_list
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
expr|struct
name|edge_list
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|find_edge_index
name|PARAMS
argument_list|(
operator|(
expr|struct
name|edge_list
operator|*
operator|,
name|basic_block
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
name|PROP_EQUAL_NOTES
value|128
end_define

begin_comment
comment|/* Take into account REG_EQUAL notes.  */
end_comment

begin_define
define|#
directive|define
name|PROP_FINAL
value|127
end_define

begin_comment
comment|/* All of the above.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_EXPENSIVE
value|1
end_define

begin_comment
comment|/* Do relativly expensive optimizations 					   except for edge forwarding */
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
name|CLEANUP_PRE_SIBCALL
value|8
end_define

begin_comment
comment|/* Do not get confused by code hidden 					   inside call_placeholders..  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_PRE_LOOP
value|16
end_define

begin_comment
comment|/* Take care to preserve syntactic loop 					   notes.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_UPDATE_LIFE
value|32
end_define

begin_comment
comment|/* Keep life information up to date.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_THREADING
value|64
end_define

begin_comment
comment|/* Do jump threading.  */
end_comment

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
comment|/* Analyse loop pre-header.  */
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
name|LOOP_EXITS_DOMS
value|16
end_define

begin_comment
comment|/* Find nodes that dom. all exits.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_ALL
value|31
end_define

begin_comment
comment|/* All of the above  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|life_analysis
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|FILE
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|update_life_info
name|PARAMS
argument_list|(
operator|(
name|sbitmap
operator|,
expr|enum
name|update_life_extent
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|count_or_remove_death_notes
name|PARAMS
argument_list|(
operator|(
name|sbitmap
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|propagate_block
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|,
name|regset
operator|,
name|regset
operator|,
name|regset
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|propagate_block_info
struct_decl|;
end_struct_decl

begin_decl_stmt
specifier|extern
name|rtx
name|propagate_one_insn
name|PARAMS
argument_list|(
operator|(
expr|struct
name|propagate_block_info
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|propagate_block_info
modifier|*
name|init_propagate_block_info
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|,
name|regset
operator|,
name|regset
operator|,
name|regset
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_propagate_block_info
name|PARAMS
argument_list|(
operator|(
expr|struct
name|propagate_block_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In lcm.c */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|edge_list
modifier|*
name|pre_edge_lcm
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|*
operator|,
name|sbitmap
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|edge_list
modifier|*
name|pre_edge_rev_lcm
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|*
operator|,
name|sbitmap
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|compute_available
name|PARAMS
argument_list|(
operator|(
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|optimize_mode_switching
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In emit-rtl.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|emit_block_insn_after
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|emit_block_insn_before
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In predict.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|estimate_probability
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loops
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expected_value_to_br_prob
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In flow.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_flow
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|reorder_basic_blocks
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_bb
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_bb
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_bb_n
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_regset
name|PARAMS
argument_list|(
operator|(
name|regset
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_regset
name|PARAMS
argument_list|(
operator|(
name|regset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|allocate_reg_life_data
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|allocate_bb_life_data
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|expunge_block
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|basic_block
name|alloc_block
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|find_unreachable_blocks
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|delete_noop_moves
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|basic_block
name|redirect_edge_and_branch_force
name|PARAMS
argument_list|(
operator|(
name|edge
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|basic_block
name|force_nonfallthru
name|PARAMS
argument_list|(
operator|(
name|edge
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|redirect_edge_and_branch
name|PARAMS
argument_list|(
operator|(
name|edge
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|block_label
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|forwarder_block_p
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|purge_all_dead_edges
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|purge_dead_edges
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|find_sub_basic_blocks
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|find_many_sub_basic_blocks
name|PARAMS
argument_list|(
operator|(
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|can_fallthru
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|,
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flow_nodes_print
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|sbitmap
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|flow_edge_list_print
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|edge
operator|*
operator|,
name|int
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|alloc_aux_for_block
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|alloc_aux_for_blocks
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_aux_for_blocks
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_aux_for_blocks
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|alloc_aux_for_edge
name|PARAMS
argument_list|(
operator|(
name|edge
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|alloc_aux_for_edges
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|clear_aux_for_edges
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_aux_for_edges
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This function is always defined so it can be called from the    debugger, and it is declared extern so we don't get warnings about    it being unused.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|verify_flow_info
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|flow_loop_outside_edge_p
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
name|edge
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|struct
name|conflict_graph_def
modifier|*
name|conflict_graph
typedef|;
end_typedef

begin_comment
comment|/* Callback function when enumerating conflicts.  The arguments are    the smaller and larger regno in the conflict.  Returns zero if    enumeration is to continue, non-zero to halt enumeration.  */
end_comment

begin_typedef
typedef|typedef
name|int
argument_list|(
argument|*conflict_graph_enum_fn
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|,
name|void
operator|*
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_comment
comment|/* Prototypes of operations on conflict graphs.  */
end_comment

begin_decl_stmt
specifier|extern
name|conflict_graph
name|conflict_graph_new
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|conflict_graph_delete
name|PARAMS
argument_list|(
operator|(
name|conflict_graph
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|conflict_graph_add
name|PARAMS
argument_list|(
operator|(
name|conflict_graph
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|conflict_graph_conflict_p
name|PARAMS
argument_list|(
operator|(
name|conflict_graph
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|conflict_graph_enum
name|PARAMS
argument_list|(
operator|(
name|conflict_graph
operator|,
name|int
operator|,
name|conflict_graph_enum_fn
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|conflict_graph_merge_regs
name|PARAMS
argument_list|(
operator|(
name|conflict_graph
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|conflict_graph_print
name|PARAMS
argument_list|(
operator|(
name|conflict_graph
operator|,
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|conflict_graph
name|conflict_graph_compute
name|PARAMS
argument_list|(
operator|(
name|regset
operator|,
name|partition
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|mark_dfs_back_edges
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|update_br_prob_note
name|PARAMS
argument_list|(
operator|(
name|basic_block
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|calculate_dominance_info
name|PARAMS
argument_list|(
operator|(
name|int
operator|*
operator|,
name|sbitmap
operator|*
operator|,
expr|enum
name|cdi_direction
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_BASIC_BLOCK_H */
end_comment

end_unit

