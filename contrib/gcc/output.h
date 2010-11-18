begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Declarations for insn-output.c.  These functions are defined in recog.c,    final.c, and varasm.c.    Copyright (C) 1987, 1991, 1994, 1997, 1998,    1999, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_OUTPUT_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_OUTPUT_H
end_define

begin_comment
comment|/* Initialize data in final at the beginning of a compilation.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_final
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Enable APP processing of subsequent output.    Used before the output from an `asm' statement.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|app_enable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Disable APP processing of subsequent output.    Called from varasm.c before most kinds of output.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|app_disable
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the number of slots filled in the current    delayed branch sequence (we don't count the insn needing the    delay slot).   Zero if not in a delayed branch sequence.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|dbr_sequence_length
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Indicate that branch shortening hasn't yet been done.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|init_insn_lengths
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Obtain the current length of an insn.  If branch shortening has been done,    get its actual length.  Otherwise, get its maximum length.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|get_attr_length
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Obtain the current length of an insn.  If branch shortening has been done,    get its actual length.  Otherwise, get its minimum length.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|get_attr_min_length
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Make a pass over all insns and compute their actual lengths by shortening    any branches of variable length if possible.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|shorten_branches
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output assembler code for the start of a function,    and initialize some of the variables in this file    for the new function.  The label for the function and associated    assembler pseudo-ops have already been output in    `assemble_start_function'.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|final_start_function
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

begin_comment
comment|/* Output assembler code for the end of a function.    For clarity, args are same as those of `final_start_function'    even though not all of them are needed.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|final_end_function
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output assembler code for some insns: all or part of a function.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|final
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

begin_comment
comment|/* The final scan for one insn, INSN.  Args are same as in `final', except    that INSN is the insn being scanned.  Value returned is the next insn to    be scanned.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|final_scan_insn
parameter_list|(
name|rtx
parameter_list|,
name|FILE
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Replace a SUBREG with a REG or a MEM, based on the thing it is a    subreg of.  */
end_comment

begin_function_decl
specifier|extern
name|rtx
name|alter_subreg
parameter_list|(
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Report inconsistency between the assembler template and the operands.    In an `asm', it's the user's fault; otherwise, the compiler's fault.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|output_operand_lossage
argument_list|(
specifier|const
name|char
operator|*
argument_list|,
operator|...
argument_list|)
name|ATTRIBUTE_PRINTF_1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output a string of assembler code, substituting insn operands.    Defined in final.c.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|output_asm_insn
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compute a worst-case reference address of a branch so that it    can be safely used in the presence of aligned labels.    Defined in final.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|insn_current_reference_address
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Find the alignment associated with a CODE_LABEL.    Defined in final.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|label_to_alignment
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output a LABEL_REF, or a bare CODE_LABEL, as an assembler symbol.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|output_asm_label
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print a memory reference operand for address X    using machine-dependent assembler syntax.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|output_address
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print an integer constant expression in assembler syntax.    Addition and subtraction are the only arithmetic    that may appear in these expressions.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|output_addr_const
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output a string of assembler code, substituting numbers, strings    and fixed syntactic prefixes.  */
end_comment

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>=
literal|3004
end_if

begin_define
define|#
directive|define
name|ATTRIBUTE_ASM_FPRINTF
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|__attribute__ ((__format__ (__asm_fprintf__, m, n))) ATTRIBUTE_NONNULL(m)
end_define

begin_comment
comment|/* This is a magic identifier which allows GCC to figure out the type    of HOST_WIDE_INT for %wd specifier checks.  You must issue this    typedef before using the __asm_fprintf__ format attribute.  */
end_comment

begin_typedef
typedef|typedef
name|HOST_WIDE_INT
name|__gcc_host_wide_int__
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ATTRIBUTE_ASM_FPRINTF
parameter_list|(
name|m
parameter_list|,
name|n
parameter_list|)
value|ATTRIBUTE_NONNULL(m)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|asm_fprintf
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
specifier|const
name|char
modifier|*
name|p
parameter_list|,
modifier|...
parameter_list|)
function_decl|ATTRIBUTE_ASM_FPRINTF
parameter_list|(
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Split up a CONST_DOUBLE or integer constant rtx into two rtx's for single    words.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|split_double
parameter_list|(
name|rtx
parameter_list|,
name|rtx
modifier|*
parameter_list|,
name|rtx
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return nonzero if this function has no function calls.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|leaf_function_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return 1 if branch is a forward branch.    Uses insn_shuid array, so it works only in the final pass.  May be used by    output templates to add branch prediction hints, for example.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|final_forward_branch_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return 1 if this function uses only the registers that can be    safely renumbered.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|only_leaf_regs_used
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Scan IN_RTX and its subexpressions, and renumber all regs into those    available in leaf functions.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|leaf_renumber_regs_insn
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Locate the proper template for the given insn-code.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|get_insn_template
parameter_list|(
name|int
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in flow.c */
end_comment

begin_function_decl
specifier|extern
name|int
name|regno_clobbered_at_setjmp
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Functions in varasm.c.  */
end_comment

begin_comment
comment|/* Declare DECL to be a weak symbol.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|declare_weak
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Merge weak status.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|merge_weak
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Emit any pending weak declarations.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|weak_finish
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decode an `asm' spec for a declaration as a register name.    Return the register number, or -1 if nothing specified,    or -2 if the ASMSPEC is not `cc' or `memory' and is not recognized,    or -3 if ASMSPEC is `cc' and is not recognized,    or -4 if ASMSPEC is `memory' and is not recognized.    Accept an exact spelling or a decimal number.    Prefixes such as % are optional.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|decode_reg_name
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|assemble_alias
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_assemble_visibility
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output a string of literal assembler code    for an `asm' keyword used between functions.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_asm
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output assembler code for the constant pool of a function and associated    with defining the name of the function.  DECL describes the function.    NAME is the function's name.  For the constant pool, we use the current    constant pool data.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_start_function
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output assembler code associated with defining the size of the    function.  DECL describes the function.  NAME is the function's name.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_end_function
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assemble everything that is needed for a variable or function declaration.    Not used for automatic variables, and not used for function definitions.    Should not be called for variables of incomplete structure type.     TOP_LEVEL is nonzero if this variable has file scope.    AT_END is nonzero if this is the special handling, at end of compilation,    to define things that have had only tentative definitions.    DONT_OUTPUT_DATA if nonzero means don't actually output the    initial value (that will be done by the caller).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_variable
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Compute the alignment of variable specified by DECL.    DONT_OUTPUT_DATA is from assemble_variable.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|align_variable
parameter_list|(
name|tree
name|decl
parameter_list|,
name|bool
name|dont_output_data
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output something to declare an external symbol to the assembler.    (Most assemblers don't need this, so we normally output nothing.)    Do nothing if DECL is not external.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_external
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assemble code to leave SIZE bytes of zeros.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_zeros
parameter_list|(
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assemble an alignment pseudo op for an ALIGN-bit boundary.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_align
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assemble a string constant with the specified C string as contents.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_string
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Similar, for calling a library function FUN.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_external_libcall
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assemble a label named NAME.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_label
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output to FILE (an assembly file) a reference to NAME.  If NAME    starts with a *, the rest of NAME is output verbatim.  Otherwise    NAME is transformed in a target-specific way (usually by the    addition of an underscore).  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_name_raw
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like assemble_name_raw, but should be used when NAME might refer to    an entity that is also represented as a tree (like a function or    variable).  If NAME does refer to such an entity, that entity will    be marked as referenced.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_name
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the assembler directive for creating a given kind of integer    object.  SIZE is the number of bytes in the object and ALIGNED_P    indicates whether it is known to be aligned.  Return NULL if the    assembly dialect has no such directive.     The returned string should be printed at the start of a new line and    be followed immediately by the object's initial value.  */
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|integer_asm_op
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use directive OP to assemble an integer object X.  Print OP at the    start of the line, followed immediately by the value of X.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_integer_with_op
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The default implementation of the asm_out.integer target hook.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|default_assemble_integer
parameter_list|(
name|rtx
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Assemble the integer constant X into an object of SIZE bytes.  ALIGN is    the alignment of the integer in bits.  Return 1 if we were able to output    the constant, otherwise 0.  If FORCE is nonzero the constant must    be outputable. */
end_comment

begin_function_decl
specifier|extern
name|bool
name|assemble_integer
parameter_list|(
name|rtx
parameter_list|,
name|unsigned
parameter_list|,
name|unsigned
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

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
name|REAL_VALUE_TYPE_SIZE
end_ifdef

begin_comment
comment|/* Assemble the floating-point constant D into an object of size MODE.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|assemble_real
parameter_list|(
name|REAL_VALUE_TYPE
parameter_list|,
name|enum
name|machine_mode
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return the size of the constant pool.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|get_pool_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_peephole
end_ifdef

begin_function_decl
specifier|extern
name|rtx
name|peephole
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|output_shared_constant_pool
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_object_blocks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Whether a constructor CTOR is a valid static constant initializer if all    its elements are.  This used to be internal to initializer_constant_valid_p    and has been exposed to let other functions like categorize_ctor_elements    evaluate the property while walking a constructor for other purposes.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|constructor_static_from_elts_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return nonzero if VALUE is a valid constant-valued expression    for use in initializing a static variable; one that can be an    element of a "constant" initializer.     Return null_pointer_node if the value is absolute;    if it is relocatable, return the variable that determines the relocation.    We assume that VALUE has been folded as much as possible;    therefore, we do not need to check for such things as    arithmetic-combinations of integers.  */
end_comment

begin_function_decl
specifier|extern
name|tree
name|initializer_constant_valid_p
parameter_list|(
name|tree
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Output assembler code for constant EXP to FILE, with no label.    This includes the pseudo-op such as ".int" or ".byte", and a newline.    Assumes output_addressed_constants has been done on EXP already.     Generate exactly SIZE bytes of assembler data, padding at the end    with zeros if necessary.  SIZE must always be specified.     ALIGN is the alignment in bits that may be assumed for the data.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|output_constant
parameter_list|(
name|tree
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* When outputting delayed branch sequences, this rtx holds the    sequence being output.  It is null when no delayed branch    sequence is being output, so it can be used as a test in the    insn output code.     This variable is defined  in final.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|final_sequence
decl_stmt|;
end_decl_stmt

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
name|dump_file
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
name|rtx
name|current_insn_predicate
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last insn processed by final_scan_insn.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|current_output_insn
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero while outputting an `asm' with operands.    This means that inconsistencies are the user's fault, so don't die.    The precise value is the insn being output, to pass to error_for_asm.  */
end_comment

begin_decl_stmt
specifier|extern
name|rtx
name|this_is_asm_operands
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Carry information from ASM_DECLARE_OBJECT_NAME    to ASM_FINISH_DECLARE_OBJECT.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|size_directive_output
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tree
name|last_assemble_variable_decl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|bool
name|first_function_block_is_cold
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Decide whether DECL needs to be in a writable section.    RELOC is the same as for SELECT_SECTION.  */
end_comment

begin_function_decl
specifier|extern
name|bool
name|decl_readonly_section
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* This can be used to compute RELOC for the function above, when    given a constant expression.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|compute_reloc_for_constant
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* Default target function prologue and epilogue assembler output.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|default_function_pro_epilogue
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Default target hook that outputs nothing to a stream.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|no_asm_to_stream
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Flags controlling properties of a section.  */
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
name|SECTION_OVERRIDE
value|0x20000
end_define

begin_comment
comment|/* allow override of default flags */
end_comment

begin_define
define|#
directive|define
name|SECTION_TLS
value|0x40000
end_define

begin_comment
comment|/* contains thread-local storage */
end_comment

begin_define
define|#
directive|define
name|SECTION_NOTYPE
value|0x80000
end_define

begin_comment
comment|/* don't output @progbits */
end_comment

begin_define
define|#
directive|define
name|SECTION_DECLARED
value|0x100000
end_define

begin_comment
comment|/* section has been used */
end_comment

begin_define
define|#
directive|define
name|SECTION_STYLE_MASK
value|0x600000
end_define

begin_comment
comment|/* bits used for SECTION_STYLE */
end_comment

begin_define
define|#
directive|define
name|SECTION_COMMON
value|0x800000
end_define

begin_comment
comment|/* contains common data */
end_comment

begin_define
define|#
directive|define
name|SECTION_MACH_DEP
value|0x1000000
end_define

begin_comment
comment|/* subsequent bits reserved for target */
end_comment

begin_comment
comment|/* This SECTION_STYLE is used for unnamed sections that we can switch    to using a special assembler directive.  */
end_comment

begin_define
define|#
directive|define
name|SECTION_UNNAMED
value|0x000000
end_define

begin_comment
comment|/* This SECTION_STYLE is used for named sections that we can switch    to using a general section directive.  */
end_comment

begin_define
define|#
directive|define
name|SECTION_NAMED
value|0x200000
end_define

begin_comment
comment|/* This SECTION_STYLE is used for sections that we cannot switch to at    all.  The choice of section is implied by the directive that we use    to declare the object.  */
end_comment

begin_define
define|#
directive|define
name|SECTION_NOSWITCH
value|0x400000
end_define

begin_comment
comment|/* A helper function for default_elf_select_section and    default_elf_unique_section.  Categorizes the DECL.  */
end_comment

begin_enum
enum|enum
name|section_category
block|{
name|SECCAT_TEXT
block|,
name|SECCAT_RODATA
block|,
name|SECCAT_RODATA_MERGE_STR
block|,
name|SECCAT_RODATA_MERGE_STR_INIT
block|,
name|SECCAT_RODATA_MERGE_CONST
block|,
name|SECCAT_SRODATA
block|,
name|SECCAT_DATA
block|,
comment|/* To optimize loading of shared programs, define following subsections      of data section: 	_REL	Contains data that has relocations, so they get grouped 		together and dynamic linker will visit fewer pages in memory. 	_RO	Contains data that is otherwise read-only.  This is useful 		with prelinking as most relocations won't be dynamically 		linked and thus stay read only. 	_LOCAL	Marks data containing relocations only to local objects. 		These relocations will get fully resolved by prelinking.  */
name|SECCAT_DATA_REL
block|,
name|SECCAT_DATA_REL_LOCAL
block|,
name|SECCAT_DATA_REL_RO
block|,
name|SECCAT_DATA_REL_RO_LOCAL
block|,
name|SECCAT_SDATA
block|,
name|SECCAT_TDATA
block|,
name|SECCAT_BSS
block|,
name|SECCAT_SBSS
block|,
name|SECCAT_TBSS
block|}
enum|;
end_enum

begin_comment
comment|/* Information that is provided by all instances of the section type.  */
end_comment

begin_decl_stmt
name|struct
name|section_common
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
comment|/* The set of SECTION_* flags that apply to this section.  */
name|unsigned
name|int
name|flags
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Information about a SECTION_NAMED section.  */
end_comment

begin_decl_stmt
name|struct
name|named_section
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|section_common
name|common
decl_stmt|;
comment|/* The name of the section.  */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* If nonnull, the VAR_DECL or FUNCTION_DECL with which the      section is associated.  */
name|tree
name|decl
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* A callback that writes the assembly code for switching to an unnamed    section.  The argument provides callback-specific data.  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|unnamed_section_callback
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Information about a SECTION_UNNAMED section.  */
end_comment

begin_decl_stmt
name|struct
name|unnamed_section
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|section_common
name|common
decl_stmt|;
comment|/* The callback used to switch to the section, and the data that      should be passed to the callback.  */
name|unnamed_section_callback
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|callback
decl_stmt|;
specifier|const
name|void
modifier|*
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|data
decl_stmt|;
comment|/* The next entry in the chain of unnamed sections.  */
name|section
modifier|*
name|next
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* A callback that writes the assembly code for a decl in a    SECTION_NOSWITCH section.  DECL is the decl that should be assembled    and NAME is the name of its SYMBOL_REF.  SIZE is the size of the decl    in bytes and ROUNDED is that size rounded up to the next    BIGGEST_ALIGNMENT / BITS_PER_UNIT boundary.     Return true if the callback used DECL_ALIGN to set the object's    alignment.  A false return value implies that we are relying    on the rounded size to align the decl.  */
end_comment

begin_typedef
typedef|typedef
name|bool
function_decl|(
modifier|*
name|noswitch_section_callback
function_decl|)
parameter_list|(
name|tree
name|decl
parameter_list|,
specifier|const
name|char
modifier|*
name|name
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
name|size
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
name|rounded
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Information about a SECTION_NOSWITCH section.  */
end_comment

begin_decl_stmt
name|struct
name|noswitch_section
name|GTY
argument_list|(
operator|(
operator|)
argument_list|)
block|{
name|struct
name|section_common
name|common
decl_stmt|;
comment|/* The callback used to assemble decls in this section.  */
name|noswitch_section_callback
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|callback
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Information about a section, which may be named or unnamed.  */
end_comment

begin_decl_stmt
name|union
name|section
name|GTY
argument_list|(
operator|(
name|desc
argument_list|(
literal|"SECTION_STYLE (&(%h))"
argument_list|)
operator|)
argument_list|)
block|{
name|struct
name|section_common
name|GTY
argument_list|(
operator|(
name|skip
operator|)
argument_list|)
name|common
decl_stmt|;
name|struct
name|named_section
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"SECTION_NAMED"
argument_list|)
operator|)
argument_list|)
name|named
decl_stmt|;
name|struct
name|unnamed_section
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"SECTION_UNNAMED"
argument_list|)
operator|)
argument_list|)
name|unnamed
decl_stmt|;
name|struct
name|noswitch_section
name|GTY
argument_list|(
operator|(
name|tag
argument_list|(
literal|"SECTION_NOSWITCH"
argument_list|)
operator|)
argument_list|)
name|noswitch
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/* Return the style of section SECT.  */
end_comment

begin_define
define|#
directive|define
name|SECTION_STYLE
parameter_list|(
name|SECT
parameter_list|)
value|((SECT)->common.flags& SECTION_STYLE_MASK)
end_define

begin_struct_decl
struct_decl|struct
name|object_block
struct_decl|;
end_struct_decl

begin_comment
comment|/* Special well-known sections.  */
end_comment

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|text_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|data_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|readonly_data_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|sdata_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|ctors_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|dtors_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|bss_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|sbss_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|exception_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|eh_frame_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|tls_comm_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|comm_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|lcomm_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|bss_noswitch_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|section
modifier|*
name|in_section
decl_stmt|;
end_decl_stmt

begin_extern
extern|extern GTY((
end_extern

begin_decl_stmt
unit|))
name|bool
name|in_cold_section_p
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|section
modifier|*
name|get_unnamed_section
parameter_list|(
name|unsigned
name|int
parameter_list|,
name|void
function_decl|(
modifier|*
function_decl|)
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|get_section
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|get_named_section
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|place_block_symbol
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|rtx
name|get_section_anchor
parameter_list|(
name|struct
name|object_block
modifier|*
parameter_list|,
name|HOST_WIDE_INT
parameter_list|,
name|enum
name|tls_model
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|mergeable_constant_section
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|,
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|function_section
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|unlikely_text_section
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|current_function_section
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|unlikely_text_section_p
parameter_list|(
name|section
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|switch_to_section
parameter_list|(
name|section
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_section_asm_op
parameter_list|(
specifier|const
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|unsigned
name|int
name|default_section_type_flags
parameter_list|(
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|have_global_bss_p
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_no_named_section
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_elf_asm_named_section
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|enum
name|section_category
name|categorize_decl_for_section
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_coff_asm_named_section
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_pe_asm_named_section
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|int
parameter_list|,
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_stabs_asm_out_destructor
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_named_section_asm_out_destructor
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_dtor_section_asm_out_destructor
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_stabs_asm_out_constructor
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_named_section_asm_out_constructor
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_ctor_section_asm_out_constructor
parameter_list|(
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|default_select_section
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|default_elf_select_section
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_unique_section
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|default_function_rodata_section
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|default_no_function_rodata_section
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|default_select_rtx_section
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|section
modifier|*
name|default_elf_select_rtx_section
parameter_list|(
name|enum
name|machine_mode
parameter_list|,
name|rtx
parameter_list|,
name|unsigned
name|HOST_WIDE_INT
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_encode_section_info
parameter_list|(
name|tree
parameter_list|,
name|rtx
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|default_strip_name_encoding
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_asm_output_anchor
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|default_use_anchors_for_symbol_p
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|default_binds_local_p
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|default_binds_local_p_1
parameter_list|(
name|tree
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_globalize_label
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_emit_unwind_label
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|tree
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
name|default_emit_except_table_label
parameter_list|(
name|FILE
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_internal_label
parameter_list|(
name|FILE
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|default_file_start
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|file_end_indicate_exec_stack
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|bool
name|default_valid_pointer_mode
parameter_list|(
name|enum
name|machine_mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|default_address_cost
parameter_list|(
name|rtx
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* dbxout helper functions */
end_comment

begin_if
if|#
directive|if
name|defined
name|DBX_DEBUGGING_INFO
operator|||
name|defined
name|XCOFF_DEBUGGING_INFO
end_if

begin_function_decl
specifier|extern
name|void
name|dbxout_int
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_stabd
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_begin_stabn
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_begin_stabn_sline
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_begin_empty_stabs
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_begin_simple_stabs
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_begin_simple_stabs_desc
parameter_list|(
specifier|const
name|char
modifier|*
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
name|dbxout_stab_value_zero
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_stab_value_label
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_stab_value_label_diff
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|dbxout_stab_value_internal_label
parameter_list|(
specifier|const
name|char
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
name|dbxout_stab_value_internal_label_diff
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|,
name|int
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_OUTPUT_H */
end_comment

end_unit

