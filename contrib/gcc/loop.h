begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Loop optimization definitions for GNU C-Compiler    Copyright (C) 1991, 1995, 1998, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"varray.h"
end_include

begin_comment
comment|/* Get the luid of an insn.  Catch the error of trying to reference the LUID    of an insn added during loop, since these don't have LUIDs.  */
end_comment

begin_define
define|#
directive|define
name|INSN_LUID
parameter_list|(
name|INSN
parameter_list|)
define|\
value|(INSN_UID (INSN)< max_uid_for_loop ? uid_luid[INSN_UID (INSN)] \    : (abort (), -1))
end_define

begin_comment
comment|/* A "basic induction variable" or biv is a pseudo reg that is set    (within this loop) only by incrementing or decrementing it.  */
end_comment

begin_comment
comment|/* A "general induction variable" or giv is a pseudo reg whose    value is a linear function of a biv.  */
end_comment

begin_comment
comment|/* Bivs are recognized by `basic_induction_var';    Givs by `general_induct_var'.  */
end_comment

begin_comment
comment|/* An enum for the two different types of givs, those that are used    as memory addresses and those that are calculated into registers.  */
end_comment

begin_enum
enum|enum
name|g_types
block|{
name|DEST_ADDR
block|,
name|DEST_REG
block|}
enum|;
end_enum

begin_comment
comment|/* A `struct induction' is created for every instruction that sets    an induction variable (either a biv or a giv).  */
end_comment

begin_struct
struct|struct
name|induction
block|{
name|rtx
name|insn
decl_stmt|;
comment|/* The insn that sets a biv or giv */
name|rtx
name|new_reg
decl_stmt|;
comment|/* New register, containing strength reduced 				   version of this giv.  */
name|rtx
name|src_reg
decl_stmt|;
comment|/* Biv from which this giv is computed. 				   (If this is a biv, then this is the biv.) */
name|enum
name|g_types
name|giv_type
decl_stmt|;
comment|/* Indicate whether DEST_ADDR or DEST_REG */
name|rtx
name|dest_reg
decl_stmt|;
comment|/* Destination register for insn: this is the 				   register which was the biv or giv. 				   For a biv, this equals src_reg. 				   For a DEST_ADDR type giv, this is 0.  */
name|rtx
modifier|*
name|location
decl_stmt|;
comment|/* Place in the insn where this giv occurs. 				   If GIV_TYPE is DEST_REG, this is 0.  */
comment|/* For a biv, this is the place where add_val 				   was found.  */
name|enum
name|machine_mode
name|mode
decl_stmt|;
comment|/* The mode of this biv or giv */
name|enum
name|machine_mode
name|mem_mode
decl_stmt|;
comment|/* For DEST_ADDR, mode of the memory object. */
name|rtx
name|mult_val
decl_stmt|;
comment|/* Multiplicative factor for src_reg.  */
name|rtx
name|add_val
decl_stmt|;
comment|/* Additive constant for that product.  */
name|int
name|benefit
decl_stmt|;
comment|/* Gain from eliminating this insn.  */
name|rtx
name|final_value
decl_stmt|;
comment|/* If the giv is used outside the loop, and its 				   final value could be calculated, it is put 				   here, and the giv is made replaceable.  Set 				   the giv to this value before the loop.  */
name|unsigned
name|combined_with
decl_stmt|;
comment|/* The number of givs this giv has been 				   combined with.  If nonzero, this giv 				   cannot combine with any other giv.  */
name|unsigned
name|replaceable
range|:
literal|1
decl_stmt|;
comment|/* 1 if we can substitute the strength-reduced 				   variable for the original variable. 				   0 means they must be kept separate and the 				   new one must be copied into the old pseudo 				   reg each time the old one is set.  */
name|unsigned
name|not_replaceable
range|:
literal|1
decl_stmt|;
comment|/* Used to prevent duplicating work.  This is 				   1 if we know that the giv definitely can 				   not be made replaceable, in which case we 				   don't bother checking the variable again 				   even if further info is available. 				   Both this and the above can be zero.  */
name|unsigned
name|ignore
range|:
literal|1
decl_stmt|;
comment|/* 1 prohibits further processing of giv */
name|unsigned
name|always_computable
range|:
literal|1
decl_stmt|;
comment|/* 1 if this value is computable every 				    iteration.  */
name|unsigned
name|always_executed
range|:
literal|1
decl_stmt|;
comment|/* 1 if this set occurs each iteration.  */
name|unsigned
name|maybe_multiple
range|:
literal|1
decl_stmt|;
comment|/* Only used for a biv and  1 if this biv 				   update may be done multiple times per 				   iteration. */
name|unsigned
name|cant_derive
range|:
literal|1
decl_stmt|;
comment|/* For giv's, 1 if this giv cannot derive 				   another giv.  This occurs in many cases 				   where a giv's lifetime spans an update to 				   a biv. */
name|unsigned
name|maybe_dead
range|:
literal|1
decl_stmt|;
comment|/* 1 if this giv might be dead.  In that case, 				   we won't use it to eliminate a biv, it 				   would probably lose. */
name|unsigned
name|auto_inc_opt
range|:
literal|1
decl_stmt|;
comment|/* 1 if this giv had its increment output next 				   to it to try to form an auto-inc address. */
name|unsigned
name|unrolled
range|:
literal|1
decl_stmt|;
comment|/* 1 if new register has been allocated and 				   initialized in unrolled loop.  */
name|unsigned
name|shared
range|:
literal|1
decl_stmt|;
name|unsigned
name|no_const_addval
range|:
literal|1
decl_stmt|;
comment|/* 1 if add_val does not contain a const. */
name|int
name|lifetime
decl_stmt|;
comment|/* Length of life of this giv */
name|rtx
name|derive_adjustment
decl_stmt|;
comment|/* If nonzero, is an adjustment to be 				   subtracted from add_val when this giv 				   derives another.  This occurs when the 				   giv spans a biv update by incrementation. */
name|struct
name|induction
modifier|*
name|next_iv
decl_stmt|;
comment|/* For givs, links together all givs that are 				   based on the same biv.  For bivs, links 				   together all biv entries that refer to the 				   same biv register.  */
name|struct
name|induction
modifier|*
name|same
decl_stmt|;
comment|/* If this giv has been combined with another 				   giv, this points to the base giv.  The base 				   giv will have COMBINED_WITH non-zero.  */
name|struct
name|induction
modifier|*
name|derived_from
decl_stmt|;
comment|/* For a giv, if we decided to derive this 				   giv from another one.  */
name|HOST_WIDE_INT
name|const_adjust
decl_stmt|;
comment|/* Used by loop unrolling, when an address giv 				   is split, and a constant is eliminated from 				   the address, the -constant is stored here 				   for later use. */
name|int
name|ix
decl_stmt|;
comment|/* Used by recombine_givs, as n index into 				   the stats array.  */
name|struct
name|induction
modifier|*
name|same_insn
decl_stmt|;
comment|/* If there are multiple identical givs in 				   the same insn, then all but one have this 				   field set, and they all point to the giv 				   that doesn't have this field set.  */
name|rtx
name|last_use
decl_stmt|;
comment|/* For a giv made from a biv increment, this is 				   a substitute for the lifetime information. */
block|}
struct|;
end_struct

begin_comment
comment|/* A `struct iv_class' is created for each biv.  */
end_comment

begin_struct
struct|struct
name|iv_class
block|{
name|int
name|regno
decl_stmt|;
comment|/* Pseudo reg which is the biv.  */
name|int
name|biv_count
decl_stmt|;
comment|/* Number of insns setting this reg.  */
name|struct
name|induction
modifier|*
name|biv
decl_stmt|;
comment|/* List of all insns that set this reg.  */
name|int
name|giv_count
decl_stmt|;
comment|/* Number of DEST_REG givs computed from this 				   biv.  The resulting count is only used in 				   check_dbra_loop.  */
name|struct
name|induction
modifier|*
name|giv
decl_stmt|;
comment|/* List of all insns that compute a giv 				   from this reg.  */
name|int
name|total_benefit
decl_stmt|;
comment|/* Sum of BENEFITs of all those givs */
name|rtx
name|initial_value
decl_stmt|;
comment|/* Value of reg at loop start */
name|rtx
name|initial_test
decl_stmt|;
comment|/* Test performed on BIV before loop */
name|struct
name|iv_class
modifier|*
name|next
decl_stmt|;
comment|/* Links all class structures together */
name|rtx
name|init_insn
decl_stmt|;
comment|/* insn which initializes biv, 0 if none. */
name|rtx
name|init_set
decl_stmt|;
comment|/* SET of INIT_INSN, if any. */
name|unsigned
name|incremented
range|:
literal|1
decl_stmt|;
comment|/* 1 if somewhere incremented/decremented */
name|unsigned
name|eliminable
range|:
literal|1
decl_stmt|;
comment|/* 1 if plausible candidate for elimination. */
name|unsigned
name|nonneg
range|:
literal|1
decl_stmt|;
comment|/* 1 if we added a REG_NONNEG note for this. */
name|unsigned
name|reversed
range|:
literal|1
decl_stmt|;
comment|/* 1 if we reversed the loop that this 				   biv controls. */
block|}
struct|;
end_struct

begin_comment
comment|/* Information required to calculate the number of loop iterations.     This is set by loop_iterations.  */
end_comment

begin_struct
struct|struct
name|loop_info
block|{
comment|/* Register or constant initial loop value.  */
name|rtx
name|initial_value
decl_stmt|;
comment|/* Register or constant value used for comparison test.  */
name|rtx
name|comparison_value
decl_stmt|;
comment|/* Register or constant approximate final value.  */
name|rtx
name|final_value
decl_stmt|;
comment|/* Register or constant initial loop value with term common to      final_value removed.  */
name|rtx
name|initial_equiv_value
decl_stmt|;
comment|/* Register or constant final loop value with term common to      initial_value removed.  */
name|rtx
name|final_equiv_value
decl_stmt|;
comment|/* Register corresponding to iteration variable.  */
name|rtx
name|iteration_var
decl_stmt|;
comment|/* Constant loop increment.  */
name|rtx
name|increment
decl_stmt|;
name|enum
name|rtx_code
name|comparison_code
decl_stmt|;
comment|/* Holds the number of loop iterations.  It is zero if the number      could not be calculated.  Must be unsigned since the number of      iterations can be as high as 2^wordsize - 1.  For loops with a      wider iterator, this number will be zero if the number of loop      iterations is too large for an unsigned integer to hold.  */
name|unsigned
name|HOST_WIDE_INT
name|n_iterations
decl_stmt|;
comment|/* The loop unrolling factor.      Potential values:      0: unrolled      1: not unrolled.      -1: completely unrolled>0: holds the unroll exact factor.  */
name|unsigned
name|int
name|unroll_number
decl_stmt|;
comment|/* Non-zero if the loop has a NOTE_INSN_LOOP_VTOP.  */
name|rtx
name|vtop
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Definitions used by the basic induction variable discovery code.  */
end_comment

begin_enum
enum|enum
name|iv_mode
block|{
name|UNKNOWN_INDUCT
block|,
name|BASIC_INDUCT
block|,
name|NOT_BASIC_INDUCT
block|,
name|GENERAL_INDUCT
block|}
enum|;
end_enum

begin_comment
comment|/* Variables declared in loop.c, but also needed in unroll.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|uid_luid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|max_uid_for_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|uid_loop_num
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|loop_outer_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|loop_number_exit_labels
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|loop_number_exit_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|max_reg_before_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|loop_dump_stream
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|varray_type
name|reg_iv_type
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|varray_type
name|reg_iv_info
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REG_IV_TYPE
parameter_list|(
name|n
parameter_list|)
define|\
value|(*(enum iv_mode *)&VARRAY_INT(reg_iv_type, (n)))
end_define

begin_define
define|#
directive|define
name|REG_IV_INFO
parameter_list|(
name|n
parameter_list|)
define|\
value|(*(struct induction **)&VARRAY_GENERIC_PTR(reg_iv_info, (n)))
end_define

begin_decl_stmt
specifier|extern
name|struct
name|iv_class
modifier|*
modifier|*
name|reg_biv_class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|iv_class
modifier|*
name|loop_iv_list
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|first_increment_giv
decl_stmt|,
name|last_increment_giv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declarations for non-static functions declared in loop.c and    unroll.c.  */
end_comment

begin_decl_stmt
name|int
name|invariant_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|get_condition_for_loop
name|PROTO
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|emit_iv_add_mult
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
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
name|rtx
name|express_from
name|PROTO
argument_list|(
operator|(
expr|struct
name|induction
operator|*
operator|,
expr|struct
name|induction
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unroll_loop
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|rtx
operator|,
name|rtx
operator|,
expr|struct
name|loop_info
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|biv_total_increment
name|PROTO
argument_list|(
operator|(
expr|struct
name|iv_class
operator|*
operator|,
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|HOST_WIDE_INT
name|loop_iterations
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|struct
name|loop_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|precondition_loop_p
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
expr|struct
name|loop_info
operator|*
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|*
operator|,
expr|enum
name|machine_mode
operator|*
name|mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|final_biv_value
name|PROTO
argument_list|(
operator|(
expr|struct
name|iv_class
operator|*
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|final_giv_value
name|PROTO
argument_list|(
operator|(
expr|struct
name|induction
operator|*
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|emit_unrolled_add
name|PROTO
argument_list|(
operator|(
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
name|int
name|back_branch_in_range_p
name|PROTO
argument_list|(
operator|(
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
name|int
name|loop_insn_first_p
name|PROTO
argument_list|(
operator|(
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
modifier|*
name|loop_unroll_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declarations for non-static functions declared in stmt.c.  */
end_comment

begin_decl_stmt
name|void
name|find_loop_tree_blocks
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unroll_block_trees
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

