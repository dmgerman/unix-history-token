begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Communication between reload.c and reload1.c.    Copyright (C) 1987, 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
name|reload_strict_low
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
name|reload_needed_for_multiple
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|rtx
name|reload_needed_for
index|[
name|MAX_RELOADS
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|reload_secondary_reload
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

begin_ifdef
ifdef|#
directive|ifdef
name|MAX_INSN_CODE
end_ifdef

begin_decl_stmt
specifier|extern
name|enum
name|insn_code
name|reload_secondary_icode
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

begin_enum
enum|enum
name|reload_when_needed
block|{
name|RELOAD_FOR_INPUT_RELOAD_ADDRESS
block|,
name|RELOAD_FOR_OUTPUT_RELOAD_ADDRESS
block|,
name|RELOAD_FOR_OPERAND_ADDRESS
block|,
comment|/* The following two are not fully implemented.      They are used in emitting insns, but they aren't distinguished from      RELOAD_OTHER when computing the number of spills.  What they accomplish      is to avoid precluding inheritance of already loaded values      for input reloads when there are also output reloads.  */
name|RELOAD_FOR_INPUT
block|,
name|RELOAD_FOR_OUTPUT
block|,
name|RELOAD_OTHER
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|reload_when_needed
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

begin_function_decl
specifier|extern
name|void
name|init_reload
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|find_reloads
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|subst_reloads
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_secondary_mem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|eliminate_regs
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|gen_input_reload
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|find_replacement
parameter_list|()
function_decl|;
end_function_decl

end_unit

