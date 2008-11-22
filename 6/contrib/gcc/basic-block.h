begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define control and data flow tables, and regsets.    Copyright (C) 1987, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|bitmap_initialize (HEAD, 1)
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
value|bitmap_initialize (&HEAD, 1)
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
name|EDGE_ALL_FLAGS
value|1023
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
name|head_
decl_stmt|,
name|end_
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
comment|/* Previous and next blocks in the chain.  */
name|struct
name|basic_block_def
modifier|*
name|prev_bb
decl_stmt|,
modifier|*
name|next_bb
decl_stmt|;
comment|/* The loop depth of this block.  */
name|int
name|loop_depth
decl_stmt|;
comment|/* Outermost loop containing the block.  */
name|struct
name|loop
modifier|*
name|loop_father
decl_stmt|;
comment|/* The dominance and postdominance information node.  */
name|struct
name|et_node
modifier|*
name|dom
index|[
literal|2
index|]
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
comment|/* Additional data maintained by cfg_layout routines.  */
name|struct
name|reorder_block_def
modifier|*
name|rbi
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
name|BB_DIRTY
value|1
end_define

begin_define
define|#
directive|define
name|BB_NEW
value|2
end_define

begin_define
define|#
directive|define
name|BB_REACHABLE
value|4
end_define

begin_define
define|#
directive|define
name|BB_VISITED
value|8
end_define

begin_define
define|#
directive|define
name|BB_IRREDUCIBLE_LOOP
value|16
end_define

begin_define
define|#
directive|define
name|BB_SUPERBLOCK
value|32
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
comment|/* First free basic block number.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|last_basic_block
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
name|FOR_EACH_BB
parameter_list|(
name|BB
parameter_list|)
define|\
value|FOR_BB_BETWEEN (BB, ENTRY_BLOCK_PTR->next_bb, EXIT_BLOCK_PTR, next_bb)
end_define

begin_define
define|#
directive|define
name|FOR_EACH_BB_REVERSE
parameter_list|(
name|BB
parameter_list|)
define|\
value|FOR_BB_BETWEEN (BB, EXIT_BLOCK_PTR->prev_bb, ENTRY_BLOCK_PTR, prev_bb)
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

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
name|label_value_list
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|rtx
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
name|BB_HEAD
parameter_list|(
name|B
parameter_list|)
value|(B)->head_
end_define

begin_define
define|#
directive|define
name|BB_END
parameter_list|(
name|B
parameter_list|)
value|(B)->end_
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
name|void
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
name|int
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
name|bool
name|safe_insert_insn_on_edge
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
name|int
name|flow_call_edges_add
parameter_list|(
name|sbitmap
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
modifier|*
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
name|void
name|tidy_fallthru_edge
parameter_list|(
name|edge
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
name|tidy_fallthru_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flow_reverse_top_sort_order_compute
parameter_list|(
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|flow_depth_first_order_compute
parameter_list|(
name|int
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|flow_preorder_transversal_compute
parameter_list|(
name|int
modifier|*
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
name|clear_edges
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mark_critical_edges
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
name|PROP_SCAN_DEAD_STORES
value|256
end_define

begin_comment
comment|/* Scan for dead code.  */
end_comment

begin_define
define|#
directive|define
name|PROP_ASM_SCAN
value|512
end_define

begin_comment
comment|/* Internal flag used within flow.c 					   to flag analysis of asms.  */
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
value|(PROP_DEATH_NOTES  \ 				 | PROP_KILL_DEAD_CODE  \ 				 | PROP_SCAN_DEAD_CODE | PROP_AUTOINC \ 				 | PROP_SCAN_DEAD_STORES)
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

begin_define
define|#
directive|define
name|CLEANUP_NO_INSN_DEL
value|128
end_define

begin_comment
comment|/* Do not try to delete trivially dead 					   insns.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_CFGLAYOUT
value|256
end_define

begin_comment
comment|/* Do cleanup in cfglayout mode.  */
end_comment

begin_define
define|#
directive|define
name|CLEANUP_LOG_LINKS
value|512
end_define

begin_comment
comment|/* Update log links.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|life_analysis
parameter_list|(
name|rtx
parameter_list|,
name|FILE
modifier|*
parameter_list|,
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
name|FILE
modifier|*
parameter_list|,
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
name|FILE
modifier|*
parameter_list|,
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

begin_function_decl
specifier|extern
name|int
name|optimize_mode_switching
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In emit-rtl.c.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|emit_block_insn_after
parameter_list|(
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
name|rtx
name|emit_block_insn_before
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|basic_block
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In predict.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|estimate_probability
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
name|note_prediction_to_br_prob
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
name|dump_bb
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
name|allocate_bb_life_data
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
name|rtx
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
name|int
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
name|find_sub_basic_blocks
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

begin_comment
comment|/* This function is always defined so it can be called from the    debugger, and it is declared extern so we don't get warnings about    it being unused.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|verify_flow_info
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
name|conflict_graph
name|conflict_graph_compute
parameter_list|(
name|regset
parameter_list|,
name|partition
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
name|can_hoist_insn_p
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|regset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|hoist_insn_after
parameter_list|(
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|hoist_insn_to_edge
parameter_list|(
name|rtx
parameter_list|,
name|edge
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
name|DOM_CONS_OK
block|,
comment|/* The data is conservatively OK, i.e. if it says you that A dominates B, 			   it indeed does.  */
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
specifier|extern
name|bool
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

begin_include
include|#
directive|include
file|"cfghooks.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GCC_BASIC_BLOCK_H */
end_comment

end_unit

