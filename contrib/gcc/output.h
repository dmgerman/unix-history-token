begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for insn-output.c.  These functions are defined in recog.c,    final.c, and varasm.c.    Copyright (C) 1987, 1991, 1994, 1997, 1998,    1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Compute branch alignments based on frequency information in the CFG.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|compute_alignments
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize data in final at the beginning of a compilation.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_final
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Called at end of source file,    to output the block-profiling table for this entire compilation.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|end_final
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Enable APP processing of subsequent output.    Used before the output from an `asm' statement.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|app_enable
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Disable APP processing of subsequent output.    Called from varasm.c before most kinds of output.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|app_disable
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the number of slots filled in the current    delayed branch sequence (we don't count the insn needing the    delay slot).   Zero if not in a delayed branch sequence.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dbr_sequence_length
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Indicate that branch shortening hasn't yet been done.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_insn_lengths
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RTX_CODE
end_ifdef

begin_comment
comment|/* Obtain the current length of an insn.  If branch shortening has been done,    get its actual length.  Otherwise, get its maximum length.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|get_attr_length
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Make a pass over all insns and compute their actual lengths by shortening    any branches of variable length if possible.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|shorten_branches
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output assembler code for the start of a function,    and initialize some of the variables in this file    for the new function.  The label for the function and associated    assembler pseudo-ops have already been output in    `assemble_start_function'.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|final_start_function
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

begin_comment
comment|/* Output assembler code for the end of a function.    For clarity, args are same as those of `final_start_function'    even though not all of them are needed.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|final_end_function
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output assembler code for some insns: all or part of a function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|final
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The final scan for one insn, INSN.  Args are same as in `final', except    that INSN is the insn being scanned.  Value returned is the next insn to    be scanned.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|final_scan_insn
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|FILE
operator|*
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Replace a SUBREG with a REG or a MEM, based on the thing it is a    subreg of.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|alter_subreg
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
comment|/* Report inconsistency between the assembler template and the operands.    In an `asm', it's the user's fault; otherwise, the compiler's fault.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_operand_lossage
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a string of assembler code, substituting insn operands.    Defined in final.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_asm_insn
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Compute a worst-case reference address of a branch so that it    can be safely used in the presence of aligned labels.    Defined in final.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|insn_current_reference_address
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Find the alignment associated with a CODE_LABEL.    Defined in final.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|label_to_alignment
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a LABEL_REF, or a bare CODE_LABEL, as an assembler symbol.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_asm_label
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print a memory reference operand for address X    using machine-dependent assembler syntax.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_address
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print an integer constant expression in assembler syntax.    Addition and subtraction are the only arithmetic    that may appear in these expressions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_addr_const
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a string of assembler code, substituting numbers, strings    and fixed syntactic prefixes.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|asm_fprintf
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
name|file
operator|,
specifier|const
name|char
operator|*
name|p
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Split up a CONST_DOUBLE or integer constant rtx into two rtx's for single    words.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|split_double
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|rtx
operator|*
operator|,
name|rtx
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return nonzero if this function has no function calls.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|leaf_function_p
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if branch is an forward branch.    Uses insn_shuid array, so it works only in the final pass.  May be used by    output templates to add branch prediction hints, for example.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|final_forward_branch_p
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return 1 if this function uses only the registers that can be    safely renumbered.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|only_leaf_regs_used
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Scan IN_RTX and its subexpressions, and renumber all regs into those    available in leaf functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|leaf_renumber_regs_insn
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Locate the proper template for the given insn-code.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|get_insn_template
name|PARAMS
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
comment|/* Add function NAME to the weak symbols list.  VALUE is a weak alias    associated with NAME.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|add_weak
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Functions in flow.c */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|allocate_for_life_analysis
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
name|regno_uninitialized
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|regno_clobbered_at_setjmp
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
name|find_basic_blocks
name|PARAMS
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

begin_decl_stmt
specifier|extern
name|bool
name|cleanup_cfg
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
name|check_function_return_warnings
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Functions in varasm.c.  */
end_comment

begin_comment
comment|/* Tell assembler to switch to text section.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|text_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell assembler to switch to data section.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|data_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell assembler to make sure its in the data section.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|force_data_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell assembler to switch to read-only data section.  This is normally    the text section.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|readonly_data_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Determine if we're in the text section.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in_text_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|CTORS_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|ctors_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DTORS_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|dtors_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BSS_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|bss_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONST_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|const_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INIT_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|init_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|FINI_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|fini_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|EXPORTS_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|exports_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TDESC_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|tdesc_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DRECTVE_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|drectve_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SDATA_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|sdata_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RDATA_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|rdata_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Tell assembler to change to section NAME for DECL.    If DECL is NULL, just switch to section NAME.    If NAME is NULL, get the name from DECL.    If RELOC is 1, the initializer for DECL contains relocs.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|named_section
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell assembler to switch to the section for function DECL.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|function_section
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell assembler to switch to the section for string merging.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mergeable_string_section
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell assembler to switch to the section for constant merging.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|mergeable_constant_section
name|PARAMS
argument_list|(
operator|(
expr|enum
name|machine_mode
operator|,
name|unsigned
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Declare DECL to be a weak symbol.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|declare_weak
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TREE_CODE */
end_comment

begin_comment
comment|/* Emit any pending weak declarations.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|weak_finish
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Decode an `asm' spec for a declaration as a register name.    Return the register number, or -1 if nothing specified,    or -2 if the ASMSPEC is not `cc' or `memory' and is not recognized,    or -3 if ASMSPEC is `cc' and is not recognized,    or -4 if ASMSPEC is `memory' and is not recognized.    Accept an exact spelling or a decimal number.    Prefixes such as % are optional.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|decode_reg_name
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Make the rtl for variable VAR be volatile.    Use this only for static variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|make_var_volatile
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output alignment directive to align for constant expression EXP.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_constant_align
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|assemble_alias
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a string of literal assembler code    for an `asm' keyword used between functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_asm
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output assembler code for the constant pool of a function and associated    with defining the name of the function.  DECL describes the function.    NAME is the function's name.  For the constant pool, we use the current    constant pool data.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_start_function
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output assembler code associated with defining the size of the    function.  DECL describes the function.  NAME is the function's name.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_end_function
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assemble everything that is needed for a variable or function declaration.    Not used for automatic variables, and not used for function definitions.    Should not be called for variables of incomplete structure type.     TOP_LEVEL is nonzero if this variable has file scope.    AT_END is nonzero if this is the special handling, at end of compilation,    to define things that have had only tentative definitions.    DONT_OUTPUT_DATA if nonzero means don't actually output the    initial value (that will be done by the caller).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_variable
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|,
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output something to declare an external symbol to the assembler.    (Most assemblers don't need this, so we normally output nothing.)    Do nothing if DECL is not external.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_external
name|PARAMS
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TREE_CODE */
end_comment

begin_comment
comment|/* Assemble code to leave SIZE bytes of zeros.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_zeros
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assemble an alignment pseudo op for an ALIGN-bit boundary.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_align
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
name|assemble_eh_align
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assemble a string constant with the specified C string as contents.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_string
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RTX_CODE
end_ifdef

begin_comment
comment|/* Similar, for calling a library function FUN.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_external_libcall
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Declare the label NAME global.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_global
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assemble a label named NAME.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_label
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|assemble_eh_label
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output to FILE a reference to the assembler name of a C-level name NAME.    If NAME starts with a *, the rest of NAME is output verbatim.    Otherwise NAME is transformed in an implementation-defined way    (usually by the addition of an underscore).    Many macros in the tm file are defined to call this function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_name
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the assembler directive for creating a given kind of integer    object.  SIZE is the number of bytes in the object and ALIGNED_P    indicates whether it is known to be aligned.  Return NULL if the    assembly dialect has no such directive.     The returned string should be printed at the start of a new line and    be followed immediately by the object's initial value.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|integer_asm_op
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

begin_ifdef
ifdef|#
directive|ifdef
name|RTX_CODE
end_ifdef

begin_comment
comment|/* Use directive OP to assemble an integer object X.  Print OP at the    start of the line, followed immediately by the value of X.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_integer_with_op
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The default implementation of the asm_out.integer target hook.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|default_assemble_integer
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|unsigned
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assemble the integer constant X into an object of SIZE bytes.  ALIGN is    the alignment of the integer in bits.  Return 1 if we were able to output    the constant, otherwise 0.  If FORCE is non-zero, abort if we can't output    the constant.  */
end_comment

begin_decl_stmt
specifier|extern
name|bool
name|assemble_integer
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|,
name|unsigned
operator|,
name|unsigned
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* An interface to assemble_integer for the common case in which a value is    fully aligned and must be printed.  VALUE is the value of the integer    object and SIZE is the number of bytes it contains.  */
end_comment

begin_define
define|#
directive|define
name|assemble_aligned_integer
parameter_list|(
name|SIZE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|assemble_integer (VALUE, SIZE, (SIZE) * BITS_PER_UNIT, 1)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|REAL_VALUE_TYPE
end_ifdef

begin_comment
comment|/* Assemble the floating-point constant D into an object of size MODE.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_real
name|PARAMS
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
expr|enum
name|machine_mode
operator|,
name|unsigned
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* At the end of a function, forget the memory-constants    previously made for CONST_DOUBLEs.  Mark them as not on real_constant_chain.    Also clear out real_constant_chain and clear out all the chain-pointers.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|clear_const_double_mem
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Start deferring output of subconstants.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|defer_addressed_constants
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Stop deferring output of subconstants,    and output now all those that have been deferred.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_deferred_addressed_constants
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the size of the constant pool.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|get_pool_size
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_peephole
end_ifdef

begin_decl_stmt
specifier|extern
name|rtx
name|peephole
name|PARAMS
argument_list|(
operator|(
name|rtx
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Write all the constants in the constant pool.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_constant_pool
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return nonzero if VALUE is a valid constant-valued expression    for use in initializing a static variable; one that can be an    element of a "constant" initializer.     Return null_pointer_node if the value is absolute;    if it is relocatable, return the variable that determines the relocation.    We assume that VALUE has been folded as much as possible;    therefore, we do not need to check for such things as    arithmetic-combinations of integers.  */
end_comment

begin_decl_stmt
specifier|extern
name|tree
name|initializer_constant_valid_p
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output assembler code for constant EXP to FILE, with no label.    This includes the pseudo-op such as ".int" or ".byte", and a newline.    Assumes output_addressed_constants has been done on EXP already.     Generate exactly SIZE bytes of assembler data, padding at the end    with zeros if necessary.  SIZE must always be specified.     ALIGN is the alignment in bits that may be assumed for the data.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_constant
name|PARAMS
argument_list|(
operator|(
name|tree
operator|,
name|HOST_WIDE_INT
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|RTX_CODE
end_ifdef

begin_comment
comment|/* When outputting delayed branch sequences, this rtx holds the    sequence being output.  It is null when no delayed branch    sequence is being output, so it can be used as a test in the    insn output code.     This variable is defined  in final.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|final_sequence
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The line number of the beginning of the current function.  Various    md code needs this so that it can output relative linenumbers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SDB_DEBUGGING_INFO
end_ifdef

begin_comment
comment|/* Avoid undef sym in certain broken linkers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|sdb_begin_function_line
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* File in which assembler code is being written.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|asm_out_file
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The first global object in the file.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|first_global_object_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The first weak object in the file.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|weak_global_object_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled doesn't contain any calls    (ignoring the prologue and epilogue).  This is set prior to    local register allocation and is valid for the remaining    compiler passes.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_is_leaf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled doesn't contain any instructions    that can throw an exception.  This is set prior to final.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_nothrow
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled doesn't modify the stack pointer    (ignoring the prologue and epilogue).  This is only valid after    life_analysis has run.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_sp_is_unchanging
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if the function being compiled is a leaf function which only    uses leaf registers.  This is valid after reload (specifically after    sched2) and is useful only if the port defines LEAF_REGISTERS.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_uses_only_leaf_regs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default file in which to dump debug output.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BUFSIZ
end_ifdef

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|rtl_dump_file
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonnull if the insn currently being emitted was a COND_EXEC pattern.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|current_insn_predicate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last insn processed by final_scan_insn.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|current_output_insn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Decide whether DECL needs to be in a writable section.  RELOC is the same    as for SELECT_SECTION.  */
end_comment

begin_define
define|#
directive|define
name|DECL_READONLY_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|(TREE_READONLY (DECL)					\&& ! TREE_THIS_VOLATILE (DECL)			\&& DECL_INITIAL (DECL)				\&& (DECL_INITIAL (DECL) == error_mark_node		\        || TREE_CONSTANT (DECL_INITIAL (DECL)))		\&& ! (RELOC&& (flag_pic || DECL_ONE_ONLY (DECL))))
end_define

begin_comment
comment|/* User label prefix in effect for this compilation.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|user_label_prefix
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This macro gets just the user-specified name    out of the string in a SYMBOL_REF.  On most machines,    we discard the * if any and that's all.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STRIP_NAME_ENCODING
end_ifndef

begin_define
define|#
directive|define
name|STRIP_NAME_ENCODING
parameter_list|(
name|VAR
parameter_list|,
name|SYMBOL_NAME
parameter_list|)
define|\
value|(VAR) = ((SYMBOL_NAME) + ((SYMBOL_NAME)[0] == '*'))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Assign unique numbers to labels generated for profiling.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|profile_label_no
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default target function prologue and epilogue assembler output.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|default_function_pro_epilogue
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell assembler to switch to the section for the exception table.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|default_exception_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell assembler to switch to the section for the EH frames.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|default_eh_frame_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Default target hook that outputs nothing to a stream.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|no_asm_to_stream
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
comment|/* Flags controling properties of a section.  */
end_comment

begin_define
define|#
directive|define
name|SECTION_ENTSIZE
value|0x000ff
end_define

begin_comment
comment|/* entity size in section */
end_comment

begin_define
define|#
directive|define
name|SECTION_CODE
value|0x00100
end_define

begin_comment
comment|/* contains code */
end_comment

begin_define
define|#
directive|define
name|SECTION_WRITE
value|0x00200
end_define

begin_comment
comment|/* data is writable */
end_comment

begin_define
define|#
directive|define
name|SECTION_DEBUG
value|0x00400
end_define

begin_comment
comment|/* contains debug data */
end_comment

begin_define
define|#
directive|define
name|SECTION_LINKONCE
value|0x00800
end_define

begin_comment
comment|/* is linkonce */
end_comment

begin_define
define|#
directive|define
name|SECTION_SMALL
value|0x01000
end_define

begin_comment
comment|/* contains "small data" */
end_comment

begin_define
define|#
directive|define
name|SECTION_BSS
value|0x02000
end_define

begin_comment
comment|/* contains zeros only */
end_comment

begin_define
define|#
directive|define
name|SECTION_FORGET
value|0x04000
end_define

begin_comment
comment|/* forget that we've entered the section */
end_comment

begin_define
define|#
directive|define
name|SECTION_MERGE
value|0x08000
end_define

begin_comment
comment|/* contains mergeable data */
end_comment

begin_define
define|#
directive|define
name|SECTION_STRINGS
value|0x10000
end_define

begin_comment
comment|/* contains zero terminated strings without 					   embedded zeros */
end_comment

begin_define
define|#
directive|define
name|SECTION_MACH_DEP
value|0x20000
end_define

begin_comment
comment|/* subsequent bits reserved for target */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|get_named_section_flags
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|set_named_section_flags
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|named_section_flags
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|named_section_first_declaration
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_union_decl
union_decl|union
name|tree_node
union_decl|;
end_union_decl

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|default_section_type_flags
name|PARAMS
argument_list|(
operator|(
expr|union
name|tree_node
operator|*
operator|,
specifier|const
name|char
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
name|default_no_named_section
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|default_elf_asm_named_section
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|default_coff_asm_named_section
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|default_pe_asm_named_section
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|,
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|default_stabs_asm_out_destructor
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
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
name|default_named_section_asm_out_destructor
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
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
name|default_dtor_section_asm_out_destructor
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
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
name|default_stabs_asm_out_constructor
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
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
name|default_named_section_asm_out_constructor
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
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
name|default_ctor_section_asm_out_constructor
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Emit data for vtable gc for GNU binutils.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_vtable_entry
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
operator|*
operator|,
name|HOST_WIDE_INT
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|assemble_vtable_inherit
name|PARAMS
argument_list|(
operator|(
expr|struct
name|rtx_def
operator|*
operator|,
expr|struct
name|rtx_def
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

