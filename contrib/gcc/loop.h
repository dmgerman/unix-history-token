begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Loop optimization definitions for GNU C-Compiler    Copyright (C) 1991, 1995, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

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
file|"hard-reg-set.h"
end_include

begin_include
include|#
directive|include
file|"basic-block.h"
end_include

begin_comment
comment|/* Flags passed to loop_optimize.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_UNROLL
value|1
end_define

begin_define
define|#
directive|define
name|LOOP_BCT
value|2
end_define

begin_define
define|#
directive|define
name|LOOP_PREFETCH
value|4
end_define

begin_comment
comment|/* Get the loop info pointer of a loop.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_INFO
parameter_list|(
name|LOOP
parameter_list|)
value|((struct loop_info *) (LOOP)->aux)
end_define

begin_comment
comment|/* Get a pointer to the loop movables structure.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_MOVABLES
parameter_list|(
name|LOOP
parameter_list|)
value|(&LOOP_INFO (LOOP)->movables)
end_define

begin_comment
comment|/* Get a pointer to the loop registers structure.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_REGS
parameter_list|(
name|LOOP
parameter_list|)
value|(&LOOP_INFO (LOOP)->regs)
end_define

begin_comment
comment|/* Get a pointer to the loop induction variables structure.  */
end_comment

begin_define
define|#
directive|define
name|LOOP_IVS
parameter_list|(
name|LOOP
parameter_list|)
value|(&LOOP_INFO (LOOP)->ivs)
end_define

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

begin_define
define|#
directive|define
name|REGNO_FIRST_LUID
parameter_list|(
name|REGNO
parameter_list|)
value|uid_luid[REGNO_FIRST_UID (REGNO)]
end_define

begin_define
define|#
directive|define
name|REGNO_LAST_LUID
parameter_list|(
name|REGNO
parameter_list|)
value|uid_luid[REGNO_LAST_UID (REGNO)]
end_define

begin_comment
comment|/* A "basic induction variable" or biv is a pseudo reg that is set    (within this loop) only by incrementing or decrementing it.  */
end_comment

begin_comment
comment|/* A "general induction variable" or giv is a pseudo reg whose    value is a linear function of a biv.  */
end_comment

begin_comment
comment|/* Bivs are recognized by `basic_induction_var';    Givs by `general_induction_var'.  */
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
name|rtx
name|mem
decl_stmt|;
comment|/* For DEST_ADDR, the memory object.  */
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
comment|/* Only used for a biv and  1 if this biv 				   update may be done multiple times per 				   iteration.  */
name|unsigned
name|cant_derive
range|:
literal|1
decl_stmt|;
comment|/* For giv's, 1 if this giv cannot derive 				   another giv.  This occurs in many cases 				   where a giv's lifetime spans an update to 				   a biv.  */
name|unsigned
name|maybe_dead
range|:
literal|1
decl_stmt|;
comment|/* 1 if this giv might be dead.  In that case, 				   we won't use it to eliminate a biv, it 				   would probably lose.  */
name|unsigned
name|auto_inc_opt
range|:
literal|1
decl_stmt|;
comment|/* 1 if this giv had its increment output next 				   to it to try to form an auto-inc address.  */
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
comment|/* 1 if add_val does not contain a const.  */
name|int
name|lifetime
decl_stmt|;
comment|/* Length of life of this giv */
name|rtx
name|derive_adjustment
decl_stmt|;
comment|/* If nonzero, is an adjustment to be 				   subtracted from add_val when this giv 				   derives another.  This occurs when the 				   giv spans a biv update by incrementation.  */
name|rtx
name|ext_dependent
decl_stmt|;
comment|/* If nonzero, is a sign or zero extension 				   if a biv on which this giv is dependent.  */
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
name|HOST_WIDE_INT
name|const_adjust
decl_stmt|;
comment|/* Used by loop unrolling, when an address giv 				   is split, and a constant is eliminated from 				   the address, the -constant is stored here 				   for later use.  */
name|struct
name|induction
modifier|*
name|same_insn
decl_stmt|;
comment|/* If there are multiple identical givs in 				   the same insn, then all but one have this 				   field set, and they all point to the giv 				   that doesn't have this field set.  */
name|rtx
name|last_use
decl_stmt|;
comment|/* For a giv made from a biv increment, this is 				   a substitute for the lifetime information.  */
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
name|unsigned
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
comment|/* Sum of BENEFITs of all those givs.  */
name|rtx
name|initial_value
decl_stmt|;
comment|/* Value of reg at loop start.  */
name|rtx
name|initial_test
decl_stmt|;
comment|/* Test performed on BIV before loop.  */
name|rtx
name|final_value
decl_stmt|;
comment|/* Value of reg at loop end, if known.  */
name|struct
name|iv_class
modifier|*
name|next
decl_stmt|;
comment|/* Links all class structures together.  */
name|rtx
name|init_insn
decl_stmt|;
comment|/* insn which initializes biv, 0 if none.  */
name|rtx
name|init_set
decl_stmt|;
comment|/* SET of INIT_INSN, if any.  */
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
comment|/* 1 if plausible candidate for                                    elimination.  */
name|unsigned
name|nonneg
range|:
literal|1
decl_stmt|;
comment|/* 1 if we added a REG_NONNEG note for                                    this.  */
name|unsigned
name|reversed
range|:
literal|1
decl_stmt|;
comment|/* 1 if we reversed the loop that this 				   biv controls.  */
name|unsigned
name|all_reduced
range|:
literal|1
decl_stmt|;
comment|/* 1 if all givs using this biv have                                    been reduced.  */
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
comment|/* A `struct iv' is created for every register.  */
end_comment

begin_struct
struct|struct
name|iv
block|{
name|enum
name|iv_mode
name|type
decl_stmt|;
union|union
block|{
name|struct
name|iv_class
modifier|*
name|class
decl_stmt|;
name|struct
name|induction
modifier|*
name|info
decl_stmt|;
block|}
name|iv
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|REG_IV_TYPE
parameter_list|(
name|ivs
parameter_list|,
name|n
parameter_list|)
value|ivs->regs[n].type
end_define

begin_define
define|#
directive|define
name|REG_IV_INFO
parameter_list|(
name|ivs
parameter_list|,
name|n
parameter_list|)
value|ivs->regs[n].iv.info
end_define

begin_define
define|#
directive|define
name|REG_IV_CLASS
parameter_list|(
name|ivs
parameter_list|,
name|n
parameter_list|)
value|ivs->regs[n].iv.class
end_define

begin_struct
struct|struct
name|loop_ivs
block|{
comment|/* Indexed by register number, contains pointer to `struct      iv' if register is an induction variable.  */
name|struct
name|iv
modifier|*
name|regs
decl_stmt|;
comment|/* Size of regs array.  */
name|unsigned
name|int
name|n_regs
decl_stmt|;
comment|/* The head of a list which links together (via the next field)      every iv class for the current loop.  */
name|struct
name|iv_class
modifier|*
name|list
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
struct|struct
name|loop_mem_info
block|{
name|rtx
name|mem
decl_stmt|;
comment|/* The MEM itself.  */
name|rtx
name|reg
decl_stmt|;
comment|/* Corresponding pseudo, if any.  */
name|int
name|optimize
decl_stmt|;
comment|/* Nonzero if we can optimize access to this MEM.  */
block|}
name|loop_mem_info
typedef|;
end_typedef

begin_struct
struct|struct
name|loop_reg
block|{
comment|/* Number of times the reg is set during the loop being scanned.      During code motion, a negative value indicates a reg that has      been made a candidate; in particular -2 means that it is an      candidate that we know is equal to a constant and -1 means that      it is an candidate not known equal to a constant.  After code      motion, regs moved have 0 (which is accurate now) while the      failed candidates have the original number of times set.       Therefore, at all times, == 0 indicates an invariant register;< 0 a conditionally invariant one.  */
name|int
name|set_in_loop
decl_stmt|;
comment|/* Original value of set_in_loop; same except that this value      is not set negative for a reg whose sets have been made candidates      and not set to 0 for a reg that is moved.  */
name|int
name|n_times_set
decl_stmt|;
comment|/* Contains the insn in which a register was used if it was used      exactly once; contains const0_rtx if it was used more than once.  */
name|rtx
name|single_usage
decl_stmt|;
comment|/* Nonzero indicates that the register cannot be moved or strength      reduced.  */
name|char
name|may_not_optimize
decl_stmt|;
comment|/* Nonzero means reg N has already been moved out of one loop.      This reduces the desire to move it out of another.  */
name|char
name|moved_once
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|loop_regs
block|{
name|int
name|num
decl_stmt|;
comment|/* Number of regs used in table.  */
name|int
name|size
decl_stmt|;
comment|/* Size of table.  */
name|struct
name|loop_reg
modifier|*
name|array
decl_stmt|;
comment|/* Register usage info. array.  */
name|int
name|multiple_uses
decl_stmt|;
comment|/* Nonzero if a reg has multiple uses.  */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|loop_movables
block|{
comment|/* Head of movable chain.  */
name|struct
name|movable
modifier|*
name|head
decl_stmt|;
comment|/* Last movable in chain.  */
name|struct
name|movable
modifier|*
name|last
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Information pertaining to a loop.  */
end_comment

begin_struct
struct|struct
name|loop_info
block|{
comment|/* Nonzero if there is a subroutine call in the current loop.  */
name|int
name|has_call
decl_stmt|;
comment|/* Nonzero if there is a libcall in the current loop.  */
name|int
name|has_libcall
decl_stmt|;
comment|/* Nonzero if there is a non constant call in the current loop.  */
name|int
name|has_nonconst_call
decl_stmt|;
comment|/* Nonzero if there is a volatile memory reference in the current      loop.  */
name|int
name|has_volatile
decl_stmt|;
comment|/* Nonzero if there is a tablejump in the current loop.  */
name|int
name|has_tablejump
decl_stmt|;
comment|/* Nonzero if there are ways to leave the loop other than falling      off the end.  */
name|int
name|has_multiple_exit_targets
decl_stmt|;
comment|/* Nonzero if there is an indirect jump in the current function.  */
name|int
name|has_indirect_jump
decl_stmt|;
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
comment|/* The number of times the loop body was unrolled.  */
name|unsigned
name|int
name|unroll_number
decl_stmt|;
name|int
name|used_count_register
decl_stmt|;
comment|/* The loop iterator induction variable.  */
name|struct
name|iv_class
modifier|*
name|iv
decl_stmt|;
comment|/* List of MEMs that are stored in this loop.  */
name|rtx
name|store_mems
decl_stmt|;
comment|/* Array of MEMs that are used (read or written) in this loop, but      cannot be aliased by anything in this loop, except perhaps      themselves.  In other words, if mems[i] is altered during      the loop, it is altered by an expression that is rtx_equal_p to      it.  */
name|loop_mem_info
modifier|*
name|mems
decl_stmt|;
comment|/* The index of the next available slot in MEMS.  */
name|int
name|mems_idx
decl_stmt|;
comment|/* The number of elements allocated in MEMS.  */
name|int
name|mems_allocated
decl_stmt|;
comment|/* Nonzero if we don't know what MEMs were changed in the current      loop.  This happens if the loop contains a call (in which case      `has_call' will also be set) or if we store into more than      NUM_STORES MEMs.  */
name|int
name|unknown_address_altered
decl_stmt|;
comment|/* The above doesn't count any readonly memory locations that are      stored.  This does.  */
name|int
name|unknown_constant_address_altered
decl_stmt|;
comment|/* Count of memory write instructions discovered in the loop.  */
name|int
name|num_mem_sets
decl_stmt|;
comment|/* The insn where the first of these was found.  */
name|rtx
name|first_loop_store_insn
decl_stmt|;
comment|/* The chain of movable insns in loop.  */
name|struct
name|loop_movables
name|movables
decl_stmt|;
comment|/* The registers used the in loop.  */
name|struct
name|loop_regs
name|regs
decl_stmt|;
comment|/* The induction variable information in loop.  */
name|struct
name|loop_ivs
name|ivs
decl_stmt|;
comment|/* Non-zero if call is in pre_header extended basic block.  */
name|int
name|pre_header_has_call
decl_stmt|;
block|}
struct|;
end_struct

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
name|unsigned
name|int
name|max_reg_before_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|loop
modifier|*
modifier|*
name|uid_loop
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|loop_dump_stream
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declarations for non-static functions declared in loop.c and    unroll.c.  */
end_comment

begin_decl_stmt
name|int
name|loop_invariant_p
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|get_condition_for_loop
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|loop_iv_add_mult_hoist
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
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
name|void
name|loop_iv_add_mult_sink
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
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
name|void
name|loop_iv_add_mult_emit_before
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|,
name|basic_block
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|express_from
name|PARAMS
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
name|rtx
name|extend_value_for_giv
name|PARAMS
argument_list|(
operator|(
expr|struct
name|induction
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|unroll_loop
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loop
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|biv_total_increment
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|iv_class
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|HOST_WIDE_INT
name|loop_iterations
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loop
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|precondition_loop_p
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
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
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
expr|struct
name|iv_class
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|final_giv_value
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
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
name|emit_unrolled_add
name|PARAMS
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
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|loop_insn_first_p
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|rtx
argument_list|(
argument|*loop_insn_callback
argument_list|)
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loop
operator|*
operator|,
name|rtx
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
expr_stmt|;
end_typedef

begin_decl_stmt
name|void
name|for_each_insn_in_loop
name|PARAMS
argument_list|(
operator|(
expr|struct
name|loop
operator|*
operator|,
name|loop_insn_callback
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|loop_insn_emit_before
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
name|basic_block
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
name|loop_insn_sink
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|rtx
name|loop_insn_hoist
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declarations for non-static functions declared in doloop.c.  */
end_comment

begin_decl_stmt
name|int
name|doloop_optimize
name|PARAMS
argument_list|(
operator|(
specifier|const
expr|struct
name|loop
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

