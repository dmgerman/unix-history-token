begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Communication between reload.c and reload1.c.    Copyright (C) 1987, 91-95, 97, 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|PROTO
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
comment|/* See reload.c and reload1.c for comments on these variables.  */
end_comment

begin_comment
comment|/* Maximum number of reloads we can need.  */
end_comment

begin_define
define|#
directive|define
name|MAX_RELOADS
value|(2 * MAX_RECOG_OPERANDS * (MAX_REGS_PER_ADDRESS + 1))
end_define

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reload_address_base_reg_class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reload_address_index_reg_class
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|reload_in
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|reload_out
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|reload_in_reg
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|reload_reg_class
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|reload_inmode
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|machine_mode
name|reload_outmode
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|reload_optional
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
name|reload_nongroup
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reload_inc
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reload_opnum
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reload_secondary_p
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reload_secondary_in_reload
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reload_secondary_out_reload
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|MAX_INSN_CODE
end_ifdef

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|reload_secondary_in_icode
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|reload_secondary_out_icode
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|n_reloads
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|reload_reg_rtx
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|enum
name|reload_type
name|reload_when_needed
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

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
comment|/* Nonzero if indirect addressing is supported when the innermost MEM is    of the form (MEM (SYMBOL_REF sym)).  It is assumed that the level to    which these are valid is the same as spill_indirect_levels, above.   */
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

begin_ifdef
ifdef|#
directive|ifdef
name|MAX_INSN_CODE
end_ifdef

begin_comment
comment|/* These arrays record the insn_code of insns that may be needed to    perform input and output reloads of special objects.  They provide a    place to pass a scratch register.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|reload_in_optab
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|reload_out_optab
index|[]
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
name|PROTO
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
name|PROTO
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

begin_comment
comment|/* Remove all replacements in reload FROM.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|remove_replacements
name|PROTO
argument_list|(
operator|(
name|int
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

begin_comment
comment|/* Return the number of times character C occurs in string S.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|n_occurrences
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if altering OP will not modify the value of CLOBBER. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|safe_from_earlyclobber
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

begin_comment
comment|/* Search the body of INSN for values that need reloading and record them    with push_reload.  REPLACE nonzero means record also where the values occur    so that subst_reloads can be used.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|find_reloads
name|PROTO
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

begin_comment
comment|/* Substitute into the current INSN the registers into which we have reloaded    the things that need reloading.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|subst_reloads
name|PROTO
argument_list|(
operator|(
name|void
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

begin_comment
comment|/* Change any replacements being done to *X to be done to *Y */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|move_replacements
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|int
operator|,
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

begin_comment
comment|/* Return nonzero if anything in X contains a MEM.  Look also for pseudo    registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|refers_to_mem_for_reload_p
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|int
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions in reload1.c:  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|reloads_conflict
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
name|int
name|count_occurrences
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

begin_comment
comment|/* Initialize the reload pass once per compilation.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_reload
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|FILE
operator|*
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
comment|/* Functions in caller-save.c:  */
end_comment

begin_comment
comment|/* Initialize for caller-save.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_caller_save
name|PROTO
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
name|PROTO
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
name|int
name|setup_save_areas
name|PROTO
argument_list|(
operator|(
name|int
operator|*
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
name|PROTO
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

