begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Communication between reload.c and reload1.c.    Copyright (C) 1987, 1991, 1992, 1993, 1994, 1995, 1997, 1998,    1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* If secondary reloads are the same for inputs and outputs, define those    macros here.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SECONDARY_RELOAD_CLASS
end_ifdef

begin_define
define|#
directive|define
name|SECONDARY_INPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|SECONDARY_RELOAD_CLASS (CLASS, MODE, X)
end_define

begin_define
define|#
directive|define
name|SECONDARY_OUTPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|SECONDARY_RELOAD_CLASS (CLASS, MODE, X)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If either macro is defined, show that we need secondary reloads.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SECONDARY_INPUT_RELOAD_CLASS
argument_list|)
operator|||
name|defined
argument_list|(
name|SECONDARY_OUTPUT_RELOAD_CLASS
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_SECONDARY_RELOADS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If MEMORY_MOVE_COST isn't defined, give it a default here.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MEMORY_MOVE_COST
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SECONDARY_RELOADS
end_ifdef

begin_define
define|#
directive|define
name|MEMORY_MOVE_COST
parameter_list|(
name|MODE
parameter_list|,
name|CLASS
parameter_list|,
name|IN
parameter_list|)
define|\
value|(4 + memory_move_secondary_cost ((MODE), (CLASS), (IN)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MEMORY_MOVE_COST
parameter_list|(
name|MODE
parameter_list|,
name|CLASS
parameter_list|,
name|IN
parameter_list|)
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|memory_move_secondary_cost
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
expr|enum
name|reg_class
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Maximum number of reloads we can need.  */
end_comment

begin_define
define|#
directive|define
name|MAX_RELOADS
value|(2 * MAX_RECOG_OPERANDS * (MAX_REGS_PER_ADDRESS + 1))
end_define

begin_comment
comment|/* Encode the usage of a reload.  The following codes are supported:     RELOAD_FOR_INPUT		reload of an input operand    RELOAD_FOR_OUTPUT		likewise, for output    RELOAD_FOR_INSN		a reload that must not conflict with anything 				used in the insn, but may conflict with 				something used before or after the insn    RELOAD_FOR_INPUT_ADDRESS	reload for parts of the address of an object 				that is an input reload    RELOAD_FOR_INPADDR_ADDRESS	reload needed for RELOAD_FOR_INPUT_ADDRESS    RELOAD_FOR_OUTPUT_ADDRESS	like RELOAD_FOR INPUT_ADDRESS, for output    RELOAD_FOR_OUTADDR_ADDRESS	reload needed for RELOAD_FOR_OUTPUT_ADDRESS    RELOAD_FOR_OPERAND_ADDRESS	reload for the address of a non-reloaded 				operand; these don't conflict with 				any other addresses.    RELOAD_FOR_OPADDR_ADDR	reload needed for RELOAD_FOR_OPERAND_ADDRESS                                 reloads; usually secondary reloads    RELOAD_OTHER			none of the above, usually multiple uses    RELOAD_FOR_OTHER_ADDRESS     reload for part of the address of an input    				that is marked RELOAD_OTHER.     This used to be "enum reload_when_needed" but some debuggers have trouble    with an enum tag and variable of the same name.  */
end_comment

begin_enum
enum|enum
name|reload_type
block|{
name|RELOAD_FOR_INPUT
block|,
name|RELOAD_FOR_OUTPUT
block|,
name|RELOAD_FOR_INSN
block|,
name|RELOAD_FOR_INPUT_ADDRESS
block|,
name|RELOAD_FOR_INPADDR_ADDRESS
block|,
name|RELOAD_FOR_OUTPUT_ADDRESS
block|,
name|RELOAD_FOR_OUTADDR_ADDRESS
block|,
name|RELOAD_FOR_OPERAND_ADDRESS
block|,
name|RELOAD_FOR_OPADDR_ADDR
block|,
name|RELOAD_OTHER
block|,
name|RELOAD_FOR_OTHER_ADDRESS
block|}
enum|;
end_enum

begin_ifdef
ifdef|#
directive|ifdef
name|GCC_INSN_CODES_H
end_ifdef

begin_comment
comment|/* Each reload is recorded with a structure like this.  */
end_comment

begin_struct
struct|struct
name|reload
block|{
comment|/* The value to reload from */
name|rtx
name|in
decl_stmt|;
comment|/* Where to store reload-reg afterward if nec (often the same as      reload_in)  */
name|rtx
name|out
decl_stmt|;
comment|/* The class of registers to reload into.  */
name|enum
name|reg_class
name|class
decl_stmt|;
comment|/* The mode this operand should have when reloaded, on input.  */
name|enum
name|machine_mode
name|inmode
decl_stmt|;
comment|/* The mode this operand should have when reloaded, on output.  */
name|enum
name|machine_mode
name|outmode
decl_stmt|;
comment|/* The mode of the reload register.  */
name|enum
name|machine_mode
name|mode
decl_stmt|;
comment|/* the largest number of registers this reload will require.  */
name|unsigned
name|int
name|nregs
decl_stmt|;
comment|/* Positive amount to increment or decrement by if      reload_in is a PRE_DEC, PRE_INC, POST_DEC, POST_INC.      Ignored otherwise (don't assume it is zero).  */
name|int
name|inc
decl_stmt|;
comment|/* A reg for which reload_in is the equivalent.      If reload_in is a symbol_ref which came from      reg_equiv_constant, then this is the pseudo      which has that symbol_ref as equivalent.  */
name|rtx
name|in_reg
decl_stmt|;
name|rtx
name|out_reg
decl_stmt|;
comment|/* Used in find_reload_regs to record the allocated register.  */
name|int
name|regno
decl_stmt|;
comment|/* This is the register to reload into.  If it is zero when `find_reloads'      returns, you must find a suitable register in the class specified by      reload_reg_class, and store here an rtx for that register with mode from      reload_inmode or reload_outmode.  */
name|rtx
name|reg_rtx
decl_stmt|;
comment|/* The operand number being reloaded.  This is used to group related reloads      and need not always be equal to the actual operand number in the insn,      though it current will be; for in-out operands, it is one of the two      operand numbers.  */
name|int
name|opnum
decl_stmt|;
comment|/* Gives the reload number of a secondary input reload, when needed;      otherwise -1.  */
name|int
name|secondary_in_reload
decl_stmt|;
comment|/* Gives the reload number of a secondary output reload, when needed;      otherwise -1.  */
name|int
name|secondary_out_reload
decl_stmt|;
comment|/* If a secondary input reload is required, gives the INSN_CODE that uses the      secondary reload as a scratch register, or CODE_FOR_nothing if the      secondary reload register is to be an intermediate register.  */
name|enum
name|insn_code
name|secondary_in_icode
decl_stmt|;
comment|/* Likewise, for a secondary output reload.  */
name|enum
name|insn_code
name|secondary_out_icode
decl_stmt|;
comment|/* Classifies reload as needed either for addressing an input reload,      addressing an output, for addressing a non-reloaded mem ref, or for      unspecified purposes (i.e., more than one of the above).  */
name|enum
name|reload_type
name|when_needed
decl_stmt|;
comment|/* Nonzero for an optional reload.  Optional reloads are ignored unless the      value is already sitting in a register.  */
name|unsigned
name|int
name|optional
range|:
literal|1
decl_stmt|;
comment|/* nonzero if this reload shouldn't be combined with another reload.  */
name|unsigned
name|int
name|nocombine
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this is a secondary register for one or more reloads.  */
name|unsigned
name|int
name|secondary_p
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this reload must use a register not already allocated to a      group.  */
name|unsigned
name|int
name|nongroup
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|reload
name|rld
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|n_reloads
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|reg_equiv_constant
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|reg_equiv_memory_loc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|reg_equiv_address
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
modifier|*
name|reg_equiv_mem
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* All the "earlyclobber" operands of the current insn    are recorded here.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_earlyclobbers
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|reload_earlyclobbers
index|[
name|MAX_RECOG_OPERANDS
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Save the number of operands.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reload_n_operands
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* First uid used by insns created by reload in this function.    Used in find_equiv_reg.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reload_first_uid
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if indirect addressing is supported when the innermost MEM is    of the form (MEM (SYMBOL_REF sym)).  It is assumed that the level to    which these are valid is the same as spill_indirect_levels, above.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|indirect_symref_ok
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if an address (plus (reg frame_pointer) (reg ...)) is valid.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|double_reg_address_ok
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|num_not_at_initial_offset
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|needs
block|{
comment|/* [0] is normal, [1] is nongroup.  */
name|short
name|regs
index|[
literal|2
index|]
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
name|short
name|groups
index|[
name|N_REG_CLASSES
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
name|SET_HARD_REG_BIT
operator|&&
name|defined
name|CLEAR_REG_SET
end_if

begin_comment
comment|/* This structure describes instructions which are relevant for reload.    Apart from all regular insns, this also includes CODE_LABELs, since they    must be examined for register elimination.  */
end_comment

begin_struct
struct|struct
name|insn_chain
block|{
comment|/* Links to the neighbour instructions.  */
name|struct
name|insn_chain
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
comment|/* Link through a chains set up by calculate_needs_all_insns, containing      all insns that need reloading.  */
name|struct
name|insn_chain
modifier|*
name|next_need_reload
decl_stmt|;
comment|/* The basic block this insn is in.  */
name|int
name|block
decl_stmt|;
comment|/* The rtx of the insn.  */
name|rtx
name|insn
decl_stmt|;
comment|/* Register life information: record all live hard registers, and all      live pseudos that have a hard register.  */
name|regset_head
name|live_throughout
decl_stmt|;
name|regset_head
name|dead_or_set
decl_stmt|;
comment|/* Copies of the global variables computed by find_reloads.  */
name|struct
name|reload
modifier|*
name|rld
decl_stmt|;
name|int
name|n_reloads
decl_stmt|;
comment|/* Indicates which registers have already been used for spills.  */
name|HARD_REG_SET
name|used_spill_regs
decl_stmt|;
comment|/* Describe the needs for reload registers of this insn.  */
name|struct
name|needs
name|need
decl_stmt|;
comment|/* Nonzero if find_reloads said the insn requires reloading.  */
name|unsigned
name|int
name|need_reload
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if find_reloads needs to be run during reload_as_needed to      perform modifications on any operands.  */
name|unsigned
name|int
name|need_operand_change
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if eliminate_regs_in_insn said it requires eliminations.  */
name|unsigned
name|int
name|need_elim
range|:
literal|1
decl_stmt|;
comment|/* Nonzero if this insn was inserted by perform_caller_saves.  */
name|unsigned
name|int
name|is_caller_save_insn
range|:
literal|1
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* A chain of insn_chain structures to describe all non-note insns in    a function.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|insn_chain
modifier|*
name|reload_insn_chain
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate a new insn_chain structure.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|insn_chain
modifier|*
name|new_insn_chain
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
name|compute_use_by_pseudos
name|PARAMS
argument_list|(
operator|(
name|HARD_REG_SET
operator|*
operator|,
name|regset
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Functions from reload.c:  */
end_comment

begin_comment
comment|/* Return a memory location that will be used to copy X in mode MODE.      If we haven't already made a location for this mode in this insn,    call find_reloads_address on the location being returned.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|get_secondary_mem
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|,
expr|enum
name|reload_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Clear any secondary memory locations we've made.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|clear_secondary_mem
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Transfer all replacements that used to be in reload FROM to be in    reload TO.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|transfer_replacements
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* IN_RTX is the value loaded by a reload that we now decided to inherit,    or a subpart of it.  If we have any replacements registered for IN_RTX,    chancel the reloads that were supposed to load them.    Return non-zero if we chanceled any reloads.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|remove_address_replacements
name|PARAMS
argument_list|(
operator|(
name|rtx
name|in_rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like rtx_equal_p except that it allows a REG and a SUBREG to match    if they are the same hard reg, and has special hacks for    autoincrement and autodecrement.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|operands_match_p
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

begin_comment
comment|/* Return 1 if altering OP will not modify the value of CLOBBER.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|safe_from_earlyclobber
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

begin_comment
comment|/* Search the body of INSN for values that need reloading and record them    with push_reload.  REPLACE nonzero means record also where the values occur    so that subst_reloads can be used.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|find_reloads
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
name|short
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compute the sum of X and Y, making canonicalizations assumed in an    address, namely: sum constant integers, surround the sum of two    constants with a CONST, put the constant as the second operand, and    group the constant on the outermost sum.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|form_sum
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

begin_comment
comment|/* Substitute into the current INSN the registers into which we have reloaded    the things that need reloading.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|subst_reloads
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a copy of any replacements being done into X and move those copies    to locations in Y, a copy of X.  We only look at the highest level of    the RTL.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|copy_replacements
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

begin_comment
comment|/* Change any replacements being done to *X to be done to *Y */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|move_replacements
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|*
name|x
operator|,
name|rtx
operator|*
name|y
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If LOC was scheduled to be replaced by something, return the replacement.    Otherwise, return *LOC.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|find_replacement
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return nonzero if register in range [REGNO, ENDREGNO)    appears either explicitly or implicitly in X    other than being stored into.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|refers_to_regno_for_reload_p
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|unsigned
name|int
operator|,
name|rtx
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if modifying X will affect IN.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reg_overlap_mentioned_for_reload_p
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

begin_comment
comment|/* Return nonzero if anything in X contains a MEM.  Look also for pseudo    registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|refers_to_mem_for_reload_p
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Check the insns before INSN to see if there is a suitable register    containing the same value as GOAL.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|find_equiv_reg
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
expr|enum
name|reg_class
operator|,
name|int
operator|,
name|short
operator|*
operator|,
name|int
operator|,
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if register REGNO is the subject of a clobber in insn INSN.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|regno_clobbered_p
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|,
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if X is an operand of an insn that is being earlyclobbered.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|earlyclobber_operand_p
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record one reload that needs to be performed.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|push_reload
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|*
operator|,
expr|enum
name|reg_class
operator|,
expr|enum
name|machine_mode
operator|,
expr|enum
name|machine_mode
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|,
expr|enum
name|reload_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions in reload1.c:  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|reload_cse_regs
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
name|int
name|reloads_conflict
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize the reload pass once per compilation.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_reload
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The reload pass itself.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reload
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Mark the slots in regs_ever_live for the hard regs    used by pseudo-reg number REGNO.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mark_home_live
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scan X and replace any eliminable registers (such as fp) with a    replacement (such as sp), plus an offset.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|eliminate_regs
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
expr|enum
name|machine_mode
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit code to perform a reload from IN (which may be a reload register) to    OUT (which may also be a reload register).  IN or OUT is from operand    OPNUM with reload type TYPE.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|gen_reload
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|,
name|int
operator|,
expr|enum
name|reload_type
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Deallocate the reload register used by reload number R.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|deallocate_reload_reg
name|PARAMS
argument_list|(
operator|(
name|int
name|r
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions in caller-save.c:  */
end_comment

begin_comment
comment|/* Initialize for caller-save.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_caller_save
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize save areas by showing that we haven't allocated any yet.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_save_areas
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Allocate save areas for any hard registers that might need saving.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|setup_save_areas
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find the places where hard regs are live across calls and save them.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|save_call_clobbered_regs
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Replace (subreg (reg)) with the appropriate (reg) for any operands.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|cleanup_subreg_operands
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debugging support.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|debug_reload_to_stream
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|debug_reload
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

