begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define control and data flow tables, and regsets.    Copyright (C) 1987, 1997, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"bitmap.h"
end_include

begin_typedef
typedef|typedef
name|bitmap
name|regset
typedef|;
end_typedef

begin_comment
comment|/* Head of register set linked list.  */
end_comment

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
value|do {									\   int i_;								\   CLEAR_HARD_REG_SET (TO);						\   for (i_ = 0; i_< FIRST_PSEUDO_REGISTER; i_++)			\     if (REGNO_REG_SET_P (FROM, i_))					\       SET_HARD_REG_BIT (TO, i_);					\ } while (0)
end_define

begin_comment
comment|/* Loop over all registers in REGSET, starting with MIN, setting REGNUM to the    register number and executing CODE for all registers that are set. */
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
comment|/* Loop over all registers in REGSET1 and REGSET2, starting with MIN, setting    REGNUM to the register number and executing CODE for all registers that are    set in the first regset and not set in the second. */
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
comment|/* Loop over all registers in REGSET1 and REGSET2, starting with MIN, setting    REGNUM to the register number and executing CODE for all registers that are    set in both regsets. */
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
comment|/* Allocate a register set with alloca.  */
end_comment

begin_define
define|#
directive|define
name|ALLOCA_REG_SET
parameter_list|()
value|BITMAP_ALLOCA ()
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
comment|/* Number of basic blocks in the current function.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_basic_blocks
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index by basic block number, get first insn in the block.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|basic_block_head
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index by basic block number, get last insn in the block.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|basic_block_end
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index by basic block number, determine whether the block can be reached    through a computed jump.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|basic_block_computed_jump_target
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Index by basic block number, get address of regset    describing the registers live at the start of that block.  */
end_comment

begin_decl_stmt
specifier|extern
name|regset
modifier|*
name|basic_block_live_at_start
decl_stmt|;
end_decl_stmt

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

begin_comment
comment|/* List of integers.    These are used for storing things like predecessors, etc.     This scheme isn't very space efficient, especially on 64 bit machines.    The interface is designed so that the implementation can be replaced with    something more efficient if desirable.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|int_list
block|{
name|struct
name|int_list
modifier|*
name|next
decl_stmt|;
name|int
name|val
decl_stmt|;
block|}
name|int_list
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int_list
modifier|*
name|int_list_ptr
typedef|;
end_typedef

begin_comment
comment|/* Integer list elements are allocated in blocks to reduce the frequency    of calls to malloc and to reduce the associated space overhead.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|int_list_block
block|{
name|struct
name|int_list_block
modifier|*
name|next
decl_stmt|;
name|int
name|nodes_left
decl_stmt|;
define|#
directive|define
name|INT_LIST_NODES_IN_BLK
value|500
name|struct
name|int_list
name|nodes
index|[
name|INT_LIST_NODES_IN_BLK
index|]
decl_stmt|;
block|}
name|int_list_block
typedef|;
end_typedef

begin_comment
comment|/* Given a pointer to the list, return pointer to first element.  */
end_comment

begin_define
define|#
directive|define
name|INT_LIST_FIRST
parameter_list|(
name|il
parameter_list|)
value|(il)
end_define

begin_comment
comment|/* Given a pointer to a list element, return pointer to next element.  */
end_comment

begin_define
define|#
directive|define
name|INT_LIST_NEXT
parameter_list|(
name|p
parameter_list|)
value|((p)->next)
end_define

begin_comment
comment|/* Return non-zero if P points to the end of the list.  */
end_comment

begin_define
define|#
directive|define
name|INT_LIST_END
parameter_list|(
name|p
parameter_list|)
value|((p) == NULL)
end_define

begin_comment
comment|/* Return element pointed to by P.  */
end_comment

begin_define
define|#
directive|define
name|INT_LIST_VAL
parameter_list|(
name|p
parameter_list|)
value|((p)->val)
end_define

begin_define
define|#
directive|define
name|INT_LIST_SET_VAL
parameter_list|(
name|p
parameter_list|,
name|new_val
parameter_list|)
value|((p)->val = (new_val))
end_define

begin_decl_stmt
specifier|extern
name|void
name|free_int_list
name|PROTO
argument_list|(
operator|(
name|int_list_block
operator|*
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|basic_block_head[(B)]
end_define

begin_define
define|#
directive|define
name|BLOCK_END
parameter_list|(
name|B
parameter_list|)
value|basic_block_end[(B)]
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
comment|/* from flow.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|free_regset_vector
name|PROTO
argument_list|(
operator|(
name|regset
operator|*
operator|,
name|int
name|nelts
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|uid_block_number
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BLOCK_NUM
parameter_list|(
name|INSN
parameter_list|)
value|uid_block_number[INSN_UID (INSN)]
end_define

begin_decl_stmt
specifier|extern
name|void
name|compute_preds_succs
name|PROTO
argument_list|(
operator|(
name|int_list_ptr
operator|*
operator|,
name|int_list_ptr
operator|*
operator|,
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
name|dump_bb_data
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|int_list_ptr
operator|*
operator|,
name|int_list_ptr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|free_bb_mem
name|PROTO
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
name|free_basic_block_vars
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Simple bitmaps.    It's not clear yet whether using bitmap.[ch] will be a win.    It should be straightforward to convert so for now we keep things simple    while more important issues are dealt with.  */
end_comment

begin_define
define|#
directive|define
name|SBITMAP_ELT_BITS
value|HOST_BITS_PER_WIDE_INT
end_define

begin_define
define|#
directive|define
name|SBITMAP_ELT_TYPE
value|unsigned HOST_WIDE_INT
end_define

begin_typedef
typedef|typedef
struct|struct
name|simple_bitmap_def
block|{
comment|/* Number of bits.  */
name|int
name|n_bits
decl_stmt|;
comment|/* Size in elements.  */
name|int
name|size
decl_stmt|;
comment|/* Size in bytes.  */
name|int
name|bytes
decl_stmt|;
comment|/* The elements.  */
name|SBITMAP_ELT_TYPE
name|elms
index|[
literal|1
index|]
decl_stmt|;
block|}
typedef|*
name|sbitmap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|SBITMAP_ELT_TYPE
modifier|*
name|sbitmap_ptr
typedef|;
end_typedef

begin_comment
comment|/* Return the set size needed for N elements.  */
end_comment

begin_define
define|#
directive|define
name|SBITMAP_SET_SIZE
parameter_list|(
name|n
parameter_list|)
value|(((n) + SBITMAP_ELT_BITS - 1) / SBITMAP_ELT_BITS)
end_define

begin_comment
comment|/* set bit number bitno in the bitmap */
end_comment

begin_define
define|#
directive|define
name|SET_BIT
parameter_list|(
name|bitmap
parameter_list|,
name|bitno
parameter_list|)
define|\
value|do { \   (bitmap)->elms [(bitno) / SBITMAP_ELT_BITS] |= (SBITMAP_ELT_TYPE) 1<< (bitno) % SBITMAP_ELT_BITS; \ } while (0)
end_define

begin_comment
comment|/* test if bit number bitno in the bitmap is set */
end_comment

begin_define
define|#
directive|define
name|TEST_BIT
parameter_list|(
name|bitmap
parameter_list|,
name|bitno
parameter_list|)
define|\
value|((bitmap)->elms [(bitno) / SBITMAP_ELT_BITS]& ((SBITMAP_ELT_TYPE) 1<< (bitno) % SBITMAP_ELT_BITS))
end_define

begin_comment
comment|/* reset bit number bitno in the bitmap  */
end_comment

begin_define
define|#
directive|define
name|RESET_BIT
parameter_list|(
name|bitmap
parameter_list|,
name|bitno
parameter_list|)
define|\
value|do { \   (bitmap)->elms [(bitno) / SBITMAP_ELT_BITS]&= ~((SBITMAP_ELT_TYPE) 1<< (bitno) % SBITMAP_ELT_BITS); \ } while (0)
end_define

begin_decl_stmt
specifier|extern
name|void
name|dump_sbitmap
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|dump_sbitmap_vector
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sbitmap
name|sbitmap_alloc
name|PROTO
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|sbitmap
modifier|*
name|sbitmap_vector_alloc
name|PROTO
argument_list|(
operator|(
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
name|sbitmap_copy
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_zero
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_ones
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_vector_zero
name|PROTO
argument_list|(
operator|(
name|sbitmap
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
name|sbitmap_vector_ones
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_union_of_diff
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_difference
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_not
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_a_or_b_and_c
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_a_and_b_or_c
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_a_and_b
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|sbitmap_a_or_b
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|,
name|sbitmap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_intersect_of_predsucc
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|*
operator|,
name|int
operator|,
name|int_list_ptr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_intersect_of_predecessors
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|*
operator|,
name|int
operator|,
name|int_list_ptr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_intersect_of_successors
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|*
operator|,
name|int
operator|,
name|int_list_ptr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_union_of_predecessors
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|*
operator|,
name|int
operator|,
name|int_list_ptr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sbitmap_union_of_successors
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|,
name|sbitmap
operator|*
operator|,
name|int
operator|,
name|int_list_ptr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|compute_dominators
name|PROTO
argument_list|(
operator|(
name|sbitmap
operator|*
operator|,
name|sbitmap
operator|*
operator|,
name|int_list_ptr
operator|*
operator|,
name|int_list_ptr
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

