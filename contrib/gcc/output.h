begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for insn-output.c.  These functions are defined in recog.c,    final.c, and varasm.c.    Copyright (C) 1987, 1991, 1994, 97-98, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Initialize data in final at the beginning of a compilation.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_final
name|PROTO
argument_list|(
operator|(
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
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the number of slots filled in the current     delayed branch sequence (we don't count the insn needing the    delay slot).   Zero if not in a delayed branch sequence.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|dbr_sequence_length
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
comment|/* Output assembler code for some insns: all or part of a function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|final
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|rtx
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PVPROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|void
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|rtx
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
name|int
name|regno_uninitialized
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
name|int
name|regno_clobbered_at_setjmp
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
name|void
name|dump_flow_info
name|PROTO
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
name|find_basic_blocks
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
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
name|free_basic_block_vars
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
name|void
name|set_block_num
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|life_analysis
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
name|int
operator|,
name|FILE
operator|*
operator|,
name|int
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Determine if we're in the text section. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in_text_section
name|PROTO
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
name|EH_FRAME_SECTION_ASM_OP
end_ifdef

begin_decl_stmt
specifier|extern
name|void
name|eh_frame_section
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
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
name|exception_section
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Create the rtl to represent a function, for a function definition.    DECL is a FUNCTION_DECL node which describes which function.    The rtl is stored into DECL.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|make_function_rtl
name|PROTO
argument_list|(
operator|(
name|tree
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
name|PROTO
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
name|PROTO
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
name|PROTO
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
comment|/* Create the DECL_RTL for a declaration for a static or external variable    or static or external function.    ASMSPEC, if not 0, is the string which the user specified    as the assembler symbol name.    TOP_LEVEL is nonzero if this is a file-scope variable.     This is never called for PARM_DECL nodes.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|make_decl_rtl
name|PROTO
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
comment|/* Make the rtl for variable VAR be volatile.    Use this only for static variables.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|make_var_volatile
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Record an element in the table of global destructors.    How this is done depends on what sort of assembler and linker    are in use.     NAME should be the name of a global function to be called    at exit time.  This name is output using assemble_name.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_destructor
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Likewise for global constructors.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_constructor
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Likewise for entries we want to record for garbage collection.    Garbage collection is still under development.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_gc_entry
name|PROTO
argument_list|(
operator|(
name|char
operator|*
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
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
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
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Assemble code to leave SIZE bytes of zeros.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_zeros
name|PROTO
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
name|PROTO
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
name|PROTO
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

begin_comment
comment|/* Assemble everything that is needed for a variable or function declaration.    Not used for automatic variables, and not used for function definitions.    Should not be called for variables of incomplete structure type.     TOP_LEVEL is nonzero if this variable has file scope.    AT_END is nonzero if this is the special handling, at end of compilation,    to define things that have had only tentative definitions.    DONT_OUTPUT_DATA if nonzero means don't actually output the    initial value (that will be done by the caller).  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_variable
name|PROTO
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
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
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
name|PROTO
argument_list|(
operator|(
name|FILE
operator|*
operator|,
name|char
operator|*
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
comment|/* Assemble the integer constant X into an object of SIZE bytes.    X must be either a CONST_INT or CONST_DOUBLE.     Return 1 if we were able to output the constant, otherwise 0.  If FORCE is    non-zero, abort if we can't output the constant.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|assemble_integer
name|PROTO
argument_list|(
operator|(
name|rtx
operator|,
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
name|EMUSHORT
end_ifdef

begin_comment
comment|/* Assemble the floating-point constant D into an object of size MODE.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|assemble_real
name|PROTO
argument_list|(
operator|(
name|REAL_VALUE_TYPE
operator|,
expr|enum
name|machine_mode
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
name|PROTO
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
name|PROTO
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
name|PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Initialize constant pool hashing for next function.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|init_const_rtx_hash_table
name|PROTO
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
name|PROTO
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
name|TREE_CODE
end_ifdef

begin_comment
comment|/* Write all the constants in the constant pool.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_constant_pool
name|PROTO
argument_list|(
operator|(
name|char
operator|*
operator|,
name|tree
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output assembler code for constant EXP to FILE, with no label.    This includes the pseudo-op such as ".int" or ".byte", and a newline.    Assumes output_addressed_constants has been done on EXP already.     Generate exactly SIZE bytes of assembler data, padding at the end    with zeros if necessary.  SIZE must always be specified.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_constant
name|PROTO
argument_list|(
operator|(
name|tree
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* When outputting assembler code, indicates which alternative    of the constraints was actually satisfied.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|which_alternative
decl_stmt|;
end_decl_stmt

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
comment|/* Number of bytes of args popped by function being compiled on its return.    Zero if no bytes are to be popped.    May affect compilation of return insn or of function epilogue.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_pops_args
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled needs to be given an address    where the value should be stored.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_struct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled needs to    return the address of where it has put a structure value.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_pcc_struct
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled needs to be passed a static chain.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_needs_context
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled can call setjmp.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_setjmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled can call longjmp.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_longjmp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled can call alloca,    either as a subroutine or builtin.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_alloca
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled receives nonlocal gotos    from nested functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_has_nonlocal_label
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled contains nested functions.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_contains_functions
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled doesn't contain any calls    (ignoring the prologue and epilogue).  This is set prior to    local register allocation and is valid for the remaining    compiler passes. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_is_leaf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if function being compiled doesn't modify the stack pointer    (ignoring the prologue and epilogue).  This is only valid after    life_analysis has run. */
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
comment|/* Nonzero if the function being compiled issues a computed jump.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_has_computed_jump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if the current function returns a pointer type */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_returns_pointer
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If function's args have a fixed size, this is that size, in bytes.    Otherwise, it is -1.    May affect compilation of return insn or of function epilogue.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_args_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # bytes the prologue should push and pretend that the caller pushed them.    The prologue must do this, but only if parms can be passed in registers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_pretend_args_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of bytes of outgoing arguments required to be pushed by the prologue.    If this is non-zero, it means that ACCUMULATE_OUTGOING_ARGS was defined    and no stack adjusts will be done on function calls.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_outgoing_args_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if current function uses varargs.h or equivalent.    Zero for functions that use stdarg.h.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_varargs
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if current function uses stdarg.h or equivalent.    Zero for functions that use varargs.h.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_stdarg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Quantities of various kinds of registers    used for the current function's args.  */
end_comment

begin_decl_stmt
specifier|extern
name|CUMULATIVE_ARGS
name|current_function_args_info
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of function now being compiled.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_function_name
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|RTX_CODE
end_ifdef

begin_comment
comment|/* If non-zero, an RTL expression for that location at which the current    function returns its result.  Usually equal to    DECL_RTL (DECL_RESULT (current_function_decl)).  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|current_function_return_rtx
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* If some insns can be deferred to the delay slots of the epilogue, the    delay list for them is recorded here.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|current_function_epilogue_delay_list
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero means generate position-independent code.    This is not fully implemented yet.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is nonzero if the current function uses pic_offset_table_rtx.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_uses_pic_offset_table
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is nonzero if the current function uses the constant pool.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_uses_const_pool
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Language-specific reason why the current function cannot be made inline.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|current_function_cannot_inline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The line number of the beginning of the current function.    sdbout.c needs this so that it can output relative linenumbers.  */
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

end_unit

