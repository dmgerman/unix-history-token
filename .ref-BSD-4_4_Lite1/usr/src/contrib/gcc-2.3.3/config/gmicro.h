begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Gmicro (TRON) version.    Ported by Masanobu Yuhara, Fujitsu Laboratories LTD.    (yuhara@flab.fujitsu.co.jp)     Copyright (C) 1987, 1988, 1989 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  Among other things, the copyright notice and this notice must be preserved on all copies.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_comment
comment|/* Note that some other tm.h files include this one and then override    many of the definitions that relate to assembler syntax.  */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dgmicro"
end_define

begin_comment
comment|/* #define CPP_SPEC    ** currently not defined **/
end_comment

begin_comment
comment|/* #define CC1_SPEC    ** currently not defined **/
end_comment

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_comment
comment|/* #define TARGET_VERSION fprintf (stderr, " (Gmicro syntax)"); */
end_comment

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macros used in the machine description to test the flags.  */
end_comment

begin_comment
comment|/* Compile for a Gmicro/300.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_G300
value|(target_flags& 1)
end_define

begin_comment
comment|/* Compile for a Gmicro/200. */
end_comment

begin_define
define|#
directive|define
name|TARGET_G200
value|(target_flags& 2)
end_define

begin_comment
comment|/* Compile for a Gmicro/100. */
end_comment

begin_define
define|#
directive|define
name|TARGET_G100
value|(target_flags& 4)
end_define

begin_comment
comment|/* Compile FPU insns for floating point (not library calls).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FPU
value|(target_flags& 8)
end_define

begin_comment
comment|/* Pop up arguments by called function. */
end_comment

begin_define
define|#
directive|define
name|TARGET_RTD
value|(target_flags& 0x10)
end_define

begin_comment
comment|/* Compile passing first args in regs 0 and 1.    This exists only to test compiler features that will be needed for    RISC chips. It is not usable and is not intended to be usable on    this cpu ;-< */
end_comment

begin_define
define|#
directive|define
name|TARGET_REGPARM
value|(target_flags& 0x20)
end_define

begin_define
define|#
directive|define
name|TARGET_BITFIELD
value|(target_flags& 0x40)
end_define

begin_define
define|#
directive|define
name|TARGET_NEWRETURN
value|(target_flags& 0x80)
end_define

begin_comment
comment|/* Do not expand __builtin_smov (strcpy) to multiple movs.    Use the smov instruction. */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORCE_SMOV
value|(target_flags& 0x100)
end_define

begin_comment
comment|/* default options are -m300, -mFPU,    with bitfield instructions added because it won't always work otherwise.    If there are versions of the gmicro that don't support bitfield instructions    then it will take some thinking to figure out how to make them work.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0x49
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ { "g300", 1},				\     { "g200", 2},				\     { "g100", 4},				\     { "fpu", 8},				\     { "soft-float", -8},			\     { "rtd", 0x10},				\     { "no-rtd", -0x10},				\     { "regparm", 0x20},				\     { "no-regparm", -0x20},			\ #if 0
end_define

begin_comment
comment|/* Since we don't define PCC_BITFIELD_TYPE_MATTERS or use a large 	 STRUCTURE_SIZE_BOUNDARY, we must have bitfield instructions.  */
end_comment

begin_block
block|{
literal|"bitfield"
operator|,
literal|0x40
block|}
end_block

begin_operator
operator|,
end_operator

begin_block
unit|\
block|{
literal|"no-bitfield"
operator|,
operator|-
literal|0x40
block|}
end_block

begin_operator
operator|,
end_operator

begin_expr_stmt
unit|\
operator|#
name|endif
block|{
literal|"newreturn"
block|,
literal|0x80
block|}
operator|,
expr_stmt|\
block|{
literal|"no-newreturn"
block|,
operator|-
literal|0x80
block|}
operator|,
expr_stmt|\
block|{
literal|"force-smov"
block|,
literal|0x100
block|}
operator|,
expr_stmt|\
block|{
literal|"no-force-smov"
block|,
operator|-
literal|0x100
block|}
operator|,
expr_stmt|\
block|{
literal|""
block|,
name|TARGET_DEFAULT
block|}
end_expr_stmt

begin_comment
unit|}
comment|/* Blow away G100 flag silently off TARGET_fpu (since we can't clear    any bits in TARGET_SWITCHES above) */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|{					\   if (TARGET_G100) target_flags&= ~8;	\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.    This is true for Gmicro insns.    We make it true always by avoiding using the single-bit insns    except in special cases with constant bit numbers.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_comment
comment|/* That is true on the Gmicro.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is the lowest    numbered.  */
end_comment

begin_comment
comment|/* For Gmicro we can decide arbitrarily    since there are no machine instructions for them.  ????? */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* number of bits in an addressable storage unit */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_comment
comment|/* Width in bits of a "word", which is the contents of a machine register. */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_comment
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|4
end_define

begin_comment
comment|/* Width in bits of a pointer.    See also the macro `Pmode' defined below.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
value|32
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|32
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|32
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for the code of a function.  */
end_comment

begin_comment
comment|/* Instructions of the Gmicro should be on half-word boundary */
end_comment

begin_comment
comment|/* But word boundary gets better performance */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|32
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure.  */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this. */
end_comment

begin_comment
comment|/* This is not necessarily 32 on the Gmicro */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|32
end_define

begin_comment
comment|/* Set this non-zero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_decl_stmt
unit|Unaligned
name|data
name|is
name|allowed
name|on
name|Gmicro
decl_stmt|,
name|though
name|the
name|access
name|is
name|slow
operator|.
modifier|*
decl|/
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
define|#
directive|define
name|SLOW_UNALIGNED_ACCESS
value|1
comment|/* Make strings word-aligned so strcpy from constants will be faster.  */
define|#
directive|define
name|CONSTANT_ALIGNMENT
parameter_list|(
name|EXP
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|(TREE_CODE (EXP) == STRING_CST	\&& (ALIGN)< BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))
comment|/* Make arrays of chars word-aligned for the same reasons.  */
define|#
directive|define
name|DATA_ALIGNMENT
parameter_list|(
name|TYPE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == ARRAY_TYPE		\&& TYPE_MODE (TREE_TYPE (TYPE)) == QImode	\&& (ALIGN)< BITS_PER_WORD ? BITS_PER_WORD : (ALIGN))
comment|/* Define number of bits in most basic integer type.    (If undefined, default is BITS_PER_WORD).  */
define|#
directive|define
name|INT_TYPE_SIZE
value|32
comment|/* #define PCC_BITFIELD_TYPE_MATTERS 1 ????? */
comment|/* #define CHECK_FLOAT_VALUE (MODE, VALUE) ????? */
comment|/* Standard register usage.  */
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.    For the Gmicro, we give the general registers numbers 0-15,    and the FPU floating point registers numbers 16-31.  */
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|32
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the Gmicro, the stack pointer and the frame pointer are    such registers.  */
comment|/* frame pointer is not indicated as fixed, because fp may be used freely    when a frame is not built. */
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 1, \
comment|/* FPU registers.  */
value|\   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, }
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 1, \
comment|/* FPU registers.  */
value|\   1, 1, 1, 1, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, }
comment|/* Make sure everything's fine if we *don't* have a given processor.    This assumes that putting a register in fixed_regs will keep the    compilers mitt's completely off it.  We don't bother to zero it out    of register classes.  If TARGET_FPU is not set,    the compiler won't touch since no instructions that use these    registers will be valid.  */
comment|/*  This Macro is not defined now.     #define CONDITIONAL_REGISTER_USAGE */
comment|/* The Gmicro has no overlapping register */
comment|/* #define OVERLAPPING_REGNO_P(REGNO) */
comment|/* #define INSN_CLOBBERS_REGNO_P(INSN,REGNO)  */
comment|/* #define PRESERVE_DEATH_INFO_REGNO_P(REGNO)  */
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On the Gmicro, ordinary registers hold 32 bits worth;    for the Gmicro/FPU registers, a single register is always enough for    anything that can be stored in them at all.  */
define|#
directive|define
name|HARD_REGNO_NREGS
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((REGNO)>= 16 ? 1				\    : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On the Gmicro, the cpu registers can hold any mode but the FPU registers    can hold only SFmode or DFmode.  And the FPU registers can't hold anything    if FPU use is disabled. */
define|#
directive|define
name|HARD_REGNO_MODE_OK
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((REGNO)< 16								\    || ((REGNO)< 32							\        ? TARGET_FPU&& (GET_MODE_CLASS (MODE) == MODE_FLOAT ||		\ 			GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT)	\        : 0 ))
comment|/* Value is 1 if it is a good idea to tie two pseudo registers    when one has mode MODE1 and one has mode MODE2.    If HARD_REGNO_MODE_OK could produce different values for MODE1 and MODE2,    for any hard reg, then this must be 0 for correct output.  */
define|#
directive|define
name|MODES_TIEABLE_P
parameter_list|(
name|MODE1
parameter_list|,
name|MODE2
parameter_list|)
define|\
value|(! TARGET_FPU						\    || ((GET_MODE_CLASS (MODE1) == MODE_FLOAT ||		\ 	GET_MODE_CLASS (MODE1) == MODE_COMPLEX_FLOAT)	\        == ((MODE2) == SFmode || (MODE2) == DFmode)))
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
comment|/* Gmicro pc isn't overloaded on a register.  */
comment|/* #define PC_REGNUM  */
comment|/* Register to use for pushing function arguments.  */
define|#
directive|define
name|STACK_POINTER_REGNUM
value|15
comment|/* Base register for access to local variables of the function.  */
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|14
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|0
comment|/* Base register for access to arguments of the function.  */
comment|/* The Gmicro does not have hardware ap. Fp is treated as ap */
define|#
directive|define
name|ARG_POINTER_REGNUM
value|14
comment|/* Register in which static-chain is passed to a function.  */
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|0
comment|/* Register in which address to store a structure value    is passed to a function.  */
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|1
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
comment|/* The Gmicro has two kinds of registers, so four classes would be    a complete set.  */
decl|enum
name|reg_class
block|{
name|NO_REGS
operator|,
name|FPU_REGS
operator|,
name|GENERAL_REGS
operator|,
name|ALL_REGS
operator|,
name|LIM_REG_CLASSES
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|N_REG_CLASSES
value|(int) LIM_REG_CLASSES
end_define

begin_comment
comment|/* Give names of register classes as strings for dump file.   */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{ "NO_REGS", "FPU_REGS", "GENERAL_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{						\      0,
comment|/* NO_REGS */
value|\      0xffff0000,
comment|/* FPU_REGS */
value|\      0x0000ffff,
comment|/* GENERAL_REGS */
value|\      0xffffffff
comment|/* ALL_REGS */
value|\ }
end_define

begin_comment
comment|/* The same information, inverted:    Return the class number of the smallest class containing    reg number REGNO.  This could be a conditional expression    or could index an array.  */
end_comment

begin_decl_stmt
specifier|extern
name|enum
name|reg_class
name|regno_reg_class
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
value|( (REGNO< 16) ? GENERAL_REGS : FPU_REGS )
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|GENERAL_REGS
end_define

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|GENERAL_REGS
end_define

begin_comment
comment|/* Get reg_class from a letter such as appears in the machine description.    We do a trick here to modify the effective constraints on the    machine description; we zorch the constraint letters that aren't    appropriate for a specific target.  This allows us to guarantee    that a specific kind of register will not be used for a given target    without fiddling with the register classes above. */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|((C) == 'r' ? GENERAL_REGS :			\    ((C) == 'f' ? (TARGET_FPU ? FPU_REGS : NO_REGS) :	\      NO_REGS))
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     For the Gmicro, all immediate value optimizations are done     by assembler, so no machine dependent definition is necessary ??? */
end_comment

begin_comment
comment|/* #define CONST_OK_FOR_LETTER_P(VALUE, C) ((C) == 'I') */
end_comment

begin_define
define|#
directive|define
name|CONST_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
value|0
end_define

begin_comment
comment|/*  * The letters G defines all of the floating constants tha are *NOT*  * Gmicro-FPU constant.  */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'F' ||				\      (C) == 'G'&& !(TARGET_FPU&& standard_fpu_constant_p (VALUE)))
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class. */
end_comment

begin_comment
comment|/* On the Gmicro series, there is no restriction on GENERAL_REGS,    so CLASS is returned. I do not know whether I should treat FPU_REGS    specially or not (at least, m68k does not). */
end_comment

begin_define
define|#
directive|define
name|PREFERRED_RELOAD_CLASS
parameter_list|(
name|X
parameter_list|,
name|CLASS
parameter_list|)
value|CLASS
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On the Gmicro, this is the size of MODE in words,    except in the FPU regs, where a single reg is always enough.  */
end_comment

begin_define
define|#
directive|define
name|CLASS_MAX_NREGS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((CLASS) == FPU_REGS ? \    1 : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_escape
end_escape

begin_comment
comment|/* Stack layout; function entry, exit and calling.  */
end_comment

begin_comment
comment|/* Define this if pushing a word on the stack    makes the stack pointer a smaller address.  */
end_comment

begin_define
define|#
directive|define
name|STACK_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.  */
end_comment

begin_comment
comment|/* On the Gmicro, FP points to the old FP and the first local variables are    at (FP - 4). */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|0
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by. */
end_comment

begin_comment
comment|/* On the Gmicro, sp is decremented by the exact size of the operand */
end_comment

begin_define
define|#
directive|define
name|PUSH_ROUNDING
parameter_list|(
name|BYTES
parameter_list|)
value|(BYTES)
end_define

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.  */
end_comment

begin_comment
comment|/* On the Gmicro, the first argument is found at (ap + 8) where ap is fp. */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|8
end_define

begin_comment
comment|/* Value is the number of byte of arguments automatically    popped when returning from a subroutine call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.      On the Gmicro, the EXITD insn may be used to pop them if the number    of args is fixed, but if the number is variable then the caller must pop    them all. The adjsp operand of the EXITD insn can't be used for library    calls now because the library is compiled with the standard compiler.    Use of adjsp operand is a selectable option, since it is incompatible with    standard Unix calling sequences.  If the option is not selected,    the caller must always pop the args.    On the m68k this is an RTD option, so I use the same name    for the Gmicro. The option name may be changed in the future. */
end_comment

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|((TARGET_RTD&& TREE_CODE (FUNTYPE) != IDENTIFIER_NODE	\&& (TYPE_ARG_TYPES (FUNTYPE) == 0				\ 	|| (TREE_VALUE (tree_last (TYPE_ARG_TYPES (FUNTYPE)))	\ 	    = void_type_node)))					\    ? (SIZE) : 0)
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_comment
comment|/* On the Gmicro the floating return value is in fr0 not r0.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
value|LIBCALL_VALUE (TYPE_MODE (VALTYPE))
end_define

begin_comment
comment|/* Define how to find the value returned by a library function    assuming the value has mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(gen_rtx (REG, (MODE),		\     ((TARGET_FPU&& ((MODE) == SFmode || (MODE) == DFmode)) ? 16 : 0)))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the Gmicro, r0 and fp0 are the possible registers.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 0 || (N) == 16)
end_define

begin_comment
comment|/* Define this if PCC uses the nonreentrant convention for returning    structure and union values.  */
end_comment

begin_define
define|#
directive|define
name|PCC_STATIC_STRUCT_RETURN
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On the Gmicro, no registers are used in this way.  */
end_comment

begin_comment
comment|/* Really? For the performance improvement, registers should be used !! */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the Gmicro, this is a single integer, which is a number of bytes    of arguments scanned so far.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.     On the Gmicro, the offset starts at 0.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|,
name|LIBNAME
parameter_list|)
define|\
value|((CUM) = 0)
end_define

begin_comment
comment|/* Update the data in CUM to advance over an argument    of mode MODE and data type TYPE.    (TYPE is null for libcalls where that information may not be available.)  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_ADVANCE
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|((CUM) += ((MODE) != BLKmode			\ 	    ? (GET_MODE_SIZE (MODE) + 3)& ~3	\ 	    : (int_size_in_bytes (TYPE) + 3)& ~3))
end_define

begin_comment
comment|/* Define where to put the arguments to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).  */
end_comment

begin_comment
comment|/* On the Gmicro all args are pushed, except if -mregparm is specified    then the first two words of arguments are passed in d0, d1.    *NOTE* -mregparm does not work.    It exists only to test register calling conventions.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|((TARGET_REGPARM&& (CUM)< 8) ? gen_rtx (REG, (MODE), (CUM) / 4) : 0)
end_define

begin_comment
comment|/* For an arg passed partly in registers and partly in memory,    this is the number of registers used.    For args passed entirely in registers or entirely in memory, zero.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PARTIAL_NREGS
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|((TARGET_REGPARM&& (CUM)< 8					\&& 8< ((CUM) + ((MODE) == BLKmode				\ 		      ? int_size_in_bytes (TYPE)		\ 		      : GET_MODE_SIZE (MODE))))  		\  ? 2 - (CUM) / 4 : 0)
end_define

begin_comment
comment|/* The following macro is defined to output register list.    The LSB of Mask is the lowest number register.    Regoff is MY_GREG_OFF or MY_FREG_OFF.    Do NOT use<i> in File, Mask, Regoff !!    Should be changed from macros to functions.    M.Yuhara */
end_comment

begin_define
define|#
directive|define
name|MY_GREG_OFF
value|0
end_define

begin_define
define|#
directive|define
name|MY_FREG_OFF
value|16
end_define

begin_define
define|#
directive|define
name|MY_PRINT_MASK
parameter_list|(
name|File
parameter_list|,
name|Mask
parameter_list|,
name|Regoff
parameter_list|)
define|\
value|{							\     int i, first = -1;					\     if ((Mask) == 0) {					\ 	fprintf(File, "#0");				\     } else {						\ 	fprintf(File, "(");				\ 	for (i = 0; i< 16; i++) {			\ 	    if ( (Mask)& (1<< i) ) {			\ 		if (first< 0) {			\ 		    if (first == -2) {			\ 			fprintf(File, ",");		\ 		    }					\ 		    first = i;				\ 		    fprintf(File, "%s", reg_names[Regoff + i]);	\ 		}					\ 	    } else if (first>= 0) {			\ 		if (i> first + 1) {			\ 		    fprintf(File, "-%s", reg_names[Regoff + i - 1]);	\ 		}					\ 		first = -2;				\ 	    }						\ 	}						\ 	if ( (first>= 0)&& (first != 15) )		\ 	    fprintf(File, "-%s", reg_names[Regoff + 15]);\ 	fprintf(File, ")");				\     }							\ }
end_define

begin_define
define|#
directive|define
name|MY_PRINT_ONEREG_L
parameter_list|(
name|FILE
parameter_list|,
name|MASK
parameter_list|)
define|\
value|{   register int i;				\     for (i = 0; i< 16; i++)			\ 	if ( (1<< i)& (MASK)) {		\ 	    fprintf(FILE, "%s", reg_names[i]);	\ 	    (MASK)&= ~(1<< i);		\ 	    break;				\ 	}					\ }
end_define

begin_define
define|#
directive|define
name|MY_PRINT_ONEREG_H
parameter_list|(
name|FILE
parameter_list|,
name|MASK
parameter_list|)
define|\
value|{   register int i;				\     for (i = 15; i>= 0; i--)			\ 	if ( (1<< i)& (MASK)) {		\ 	    fprintf(FILE, "%s", reg_names[i]);	\ 	    (MASK)&= ~(1<< i);		\ 	    break;				\ 	}					\ }
end_define

begin_comment
comment|/* This macro generates the assembly code for function entry.    FILE is a stdio stream to output the code to.    SIZE is an int: how many units of temporary storage to allocate.    Refer to the array `regs_ever_live' to determine which registers    to save; `regs_ever_live[I]' is nonzero if register number I    is ever used in the function.  This macro is responsible for    knowing which registers should not be saved even if used.  */
end_comment

begin_comment
comment|/* The next macro needs much optimization !!    M.Yuhara */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROLOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{ register int regno;						\   register int mask = 0;					\   register int nregs = 0;					\   static char *reg_names[] = REGISTER_NAMES;			\   extern char call_used_regs[];					\   int fsize = ((SIZE) + 3)& -4;				\   for (regno = 0; regno< 16; regno++)				\     if (regs_ever_live[regno]&& !call_used_regs[regno]) {	\ 	mask |= (1<< regno);					\ 	nregs++;						\     }								\   if (frame_pointer_needed) {					\     mask&= ~(1<< FRAME_POINTER_REGNUM);			\     if (nregs> 4) {						\ 	fprintf(FILE, "\tenter.w #%d,", fsize);			\ 	MY_PRINT_MASK(FILE, mask, MY_GREG_OFF);			\ 	fprintf(FILE,"\n");					\     } else {							\ 	fprintf(FILE, "\tmov.w fp,@-sp\n");			\ 	fprintf(FILE, "\tmov.w sp,fp\n");			\ 	if (fsize> 0)						\ 	    myoutput_sp_adjust(FILE, "sub", fsize);		\ 	while (nregs--) {					\ 	    fprintf(FILE, "\tmov.w ");				\ 	    MY_PRINT_ONEREG_H(FILE, mask);			\ 	    fprintf(FILE, ",@-sp\n");				\ 	}							\     }								\   } else {							\     if (fsize> 0)						\ 	myoutput_sp_adjust(FILE, "sub", fsize);			\     if (mask != 0) {						\ 	if (nregs> 4) {					\ 	    fprintf(FILE, "\tstm.w ");				\ 	    MY_PRINT_MASK(FILE, mask, MY_GREG_OFF);		\ 	    fprintf(FILE, ",@-sp\n");				\ 	} else {						\ 	    while (nregs--) {					\ 		fprintf(FILE, "\tmov.w ");			\ 		MY_PRINT_ONEREG_H(FILE, mask);			\ 		fprintf(FILE, ",@-sp\n");			\ 	    }							\ 	}							\     }								\   }								\   mask = 0;							\   for (regno = 16; regno< 32; regno++)				\         if (regs_ever_live[regno]&& !call_used_regs[regno])	\             mask |= 1<< (regno - 16);				\   if (mask != 0) {						\ 	fprintf(FILE, "\tfstm.w ");				\ 	MY_PRINT_MASK(FILE, mask, MY_FREG_OFF);			\ 	fprintf(FILE, ",@-sp\n", mask);				\   }								\ }
end_define

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  */
end_comment

begin_comment
comment|/* ??? M.Yuhara */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fprintf (FILE, "\tmova @LP%d,r0\n\tjsr mcount\n", (LABELNO))
end_define

begin_comment
comment|/* Output assembler code to FILE to initialize this source file's    basic block profiling info, if that has not already been done.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BLOCK_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fprintf (FILE, "\tcmp #0,@LPBX0\n\tbne LPI%d\n\tpusha @LPBX0\n\tjsr ___bb_init_func\n\tadd #4,sp\nLPI%d:\n",  \ 	   LABELNO, LABELNO);
end_define

begin_comment
comment|/* Output assembler code to FILE to increment the entry-count for    the BLOCKNO'th basic block in this source file.  */
end_comment

begin_define
define|#
directive|define
name|BLOCK_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|BLOCKNO
parameter_list|)
define|\
value|fprintf (FILE, "\tadd #1,@(LPBX2+%d)\n", 4 * BLOCKNO)
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_comment
comment|/* This macro generates the assembly code for function exit,    on machines that need it.  If FUNCTION_EPILOGUE is not defined    then individual return instructions are generated for each    return statement.  Args are same as for FUNCTION_PROLOGUE.     The function epilogue should not depend on the current stack pointer (when    frame_pinter_needed)  ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^    It should use the frame pointer only.  This is mandatory because    of alloca; we also take advantage of it to omit stack adjustments    before returning.  */
end_comment

begin_comment
comment|/* The Gmicro FPU seems to be unable to fldm/fstm double or single    floating. It only allows extended !! */
end_comment

begin_comment
comment|/* Optimization is not enough, especially FREGs load !! M.Yuhara */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{ register int regno;						\   register int mask, fmask;					\   register int nregs, nfregs;					\   int offset, foffset;						\   extern char call_used_regs[];					\   static char *reg_names[] = REGISTER_NAMES;			\   int fsize = ((SIZE) + 3)& -4;				\   FUNCTION_EXTRA_EPILOGUE (FILE, SIZE);				\   nfregs = 0;  fmask = 0; 					\   for (regno = 16; regno< 31; regno++)				\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       { nfregs++; fmask |= 1<< (regno - 16); }			\   foffset = nfregs * 12;					\   nregs = 0;  mask = 0;						\   if (frame_pointer_needed) regs_ever_live[FRAME_POINTER_REGNUM] = 0; \   for (regno = 0; regno< 16; regno++)				\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       { nregs++; mask |= 1<< regno; }				\   if (frame_pointer_needed) {					\     offset = nregs * 4 + fsize;					\     if (nfregs> 0) {						\ 	fprintf(FILE, "\tfldm.x @(%d,fp),", -(foffset + offset));\ 	MY_PRINT_MASK(FILE, fmask, MY_FREG_OFF);		\ 	fprintf(FILE, "\n");					\     }								\     if (nregs> 4						\ 	|| current_function_pops_args) {			\ 	fprintf(FILE, "\tmova @(%d,fp),sp\n", -offset);		\ 	fprintf(FILE, "\texitd ");				\ 	MY_PRINT_MASK(FILE, mask, MY_GREG_OFF);			\ 	fprintf(FILE, ",#%d\n", current_function_pops_args);	\     } else {							\ 	while (nregs--) {					\ 	    fprintf(FILE, "\tmov:l.w @(%d,fp),", -offset);	\ 	    MY_PRINT_ONEREG_L(FILE, mask);			\ 	    fprintf(FILE, "\n");				\ 	    offset -= 4;					\ 	}							\ 	if (TARGET_NEWRETURN) {					\ 	    fprintf(FILE, "\tmova.w @(4,fp),sp\n");		\ 	    fprintf(FILE, "\tmov:l.w @fp,fp\n");		\ 	} else {						\ 	    fprintf(FILE, "\tmov.w fp,sp\n");			\ 	    fprintf(FILE, "\tmov.w @sp+,fp\n");			\ 	}							\ 	fprintf(FILE, "\trts\n");				\     }								\   } else {							\     if (nfregs> 0) {						\ 	fprintf(FILE, "\tfldm.w @sp+,");			\ 	MY_PRINT_MASK(FILE, fmask, MY_FREG_OFF);		\ 	fprintf(FILE, "\n");					\     }								\     if (nregs> 4) {						\ 	fprintf(FILE, "\tldm.w @sp+,");				\ 	MY_PRINT_MASK(FILE, mask, MY_GREG_OFF);			\ 	fprintf(FILE, "\n");					\     } else {							\ 	while (nregs--) {					\ 	    fprintf(FILE, "\tmov.w @sp+,");			\ 	    MY_PRINT_ONEREG_L(FILE,mask);			\ 	    fprintf(FILE, "\n");				\ 	}							\     }								\       if (current_function_pops_args) {				\ 	myoutput_sp_adjust(FILE, "add", 			\ 	    (fsize + 4 + current_function_pops_args));		\ 	fprintf(FILE, "\tjmp @(%d,sp)\n", current_function_pops_args);\     } else {							\ 	if (fsize> 0)						\ 	    myoutput_sp_adjust(FILE, "add", fsize);		\ 	fprintf(FILE, "\trts\n");				\     }								\   }								\ }
end_define

begin_comment
comment|/* This is a hook for other tm files to change.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_EXTRA_EPILOGUE
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
end_define

begin_comment
comment|/* If the memory address ADDR is relative to the frame pointer,    correct it to be relative to the stack pointer instead.    This is for when we don't use a frame pointer.    ADDR should be a variable name.  */
end_comment

begin_comment
comment|/* You have to change the next macro if you want to use more complex    addressing modes (such as double indirection and  more than one    chain-addressing stages). */
end_comment

begin_define
define|#
directive|define
name|FIX_FRAME_POINTER_ADDRESS
parameter_list|(
name|ADDR
parameter_list|,
name|DEPTH
parameter_list|)
define|\
value|{ int offset = -1;							\   rtx regs = stack_pointer_rtx;						\   if (ADDR == frame_pointer_rtx)					\     offset = 0;								\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 0) == frame_pointer_rtx \&& GET_CODE (XEXP (ADDR, 1)) == CONST_INT)			\     offset = INTVAL (XEXP (ADDR, 1));					\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 0) == frame_pointer_rtx) \     { rtx other_reg = XEXP (ADDR, 1);					\       offset = 0;							\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 1) == frame_pointer_rtx) \     { rtx other_reg = XEXP (ADDR, 0);					\       offset = 0;							\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   else if (GET_CODE (ADDR) == PLUS					\&& GET_CODE (XEXP (ADDR, 0)) == PLUS				\&& XEXP (XEXP (ADDR, 0), 0) == frame_pointer_rtx		\&& GET_CODE (XEXP (ADDR, 1)) == CONST_INT)			\     { rtx other_reg = XEXP (XEXP (ADDR, 0), 1);				\       offset = INTVAL (XEXP (ADDR, 1));					\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   else if (GET_CODE (ADDR) == PLUS					\&& GET_CODE (XEXP (ADDR, 0)) == PLUS				\&& XEXP (XEXP (ADDR, 0), 1) == frame_pointer_rtx		\&& GET_CODE (XEXP (ADDR, 1)) == CONST_INT)			\     { rtx other_reg = XEXP (XEXP (ADDR, 0), 0);				\       offset = INTVAL (XEXP (ADDR, 1));					\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   if (offset>= 0)							\     { int regno;							\       extern char call_used_regs[];					\       for (regno = 16; regno< 32; regno++)				\         if (regs_ever_live[regno]&& ! call_used_regs[regno])		\           offset += 12;							\       for (regno = 0; regno< 16; regno++)				\ 	if (regs_ever_live[regno]&& ! call_used_regs[regno])		\ 	  offset += 4;							\       offset -= 4;							\       ADDR = plus_constant (regs, offset + (DEPTH)); } }
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

begin_comment
comment|/* #define HAVE_POST_INCREMENT */
end_comment

begin_comment
comment|/* #define HAVE_POST_DECREMENT */
end_comment

begin_comment
comment|/* #define HAVE_PRE_DECREMENT */
end_comment

begin_comment
comment|/* #define HAVE_PRE_INCREMENT */
end_comment

begin_comment
comment|/* Macros to check register numbers against specific register classes.  */
end_comment

begin_comment
comment|/* These assume that REGNO is a hard or pseudo reg number.    They give nonzero only if REGNO is a hard reg of the suitable class    or a pseudo reg currently allocated to a suitable hard reg.    Since they use reg_renumber, they are safe only once reg_renumber    has been allocated, which happens in local-alloc.c.  */
end_comment

begin_comment
comment|/* Gmicro */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_GREG_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 16 || (unsigned) reg_renumber[REGNO]< 16)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_FPU_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO) ^ 0x10)< 16 || (unsigned) (reg_renumber[REGNO] ^ 0x10)< 16)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|REGNO
parameter_list|)
value|REGNO_OK_FOR_GREG_P(REGNO)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
value|REGNO_OK_FOR_GREG_P(REGNO)
end_define

begin_comment
comment|/* Now macros that check whether X is a register and also,    strictly, whether it is in a specified class.     These macros are specific to the Gmicro, and may be used only    in code for printing assembler insns and in conditions for    define_optimization.  */
end_comment

begin_comment
comment|/* 1 if X is an fpu register.  */
end_comment

begin_define
define|#
directive|define
name|FPU_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& REGNO_OK_FOR_FPU_P (REGNO (X)))
end_define

begin_comment
comment|/* I used GREG_P in the gmicro.md file. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REG_OK_STRICT
end_ifdef

begin_define
define|#
directive|define
name|GREG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& REGNO_OK_FOR_GREG_P (REGNO(X)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GREG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& ((REGNO (X)& ~0xf) != 0x10))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Maximum number of registers that can appear in a valid memory address.  */
end_comment

begin_comment
comment|/* The Gmicro allows more registers in the chained addressing mode.    But I do not know gcc supports such an architecture. */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|2
end_define

begin_comment
comment|/* Recognize any constant value that is a valid address.  */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
value|CONSTANT_P (X)
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
value|1
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects    them unless they have been allocated suitable hard regs.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Source files for reload pass need to be strict.    After reload, it makes no difference, since pseudo regs have    been eliminated by then.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as an index    or if it is a pseudo reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|((REGNO (X)& ~0xf) != 0x10)
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as a base reg    or if it is a pseudo reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|((REGNO (X)& ~0xf) != 0x10)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as an index.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_INDEX_P (REGNO (X))
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as a base reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REGNO_OK_FOR_BASE_P (REGNO (X))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* The gcc uses the following effective address of the Gmicro. 					       (without using PC!!).    {@} ( {Rbase} + {Disp} + {Rindex * [1,2,4,8]} ) 	where 		@:     memory indirection. 		Rbase: Base Register = General Register. 		Disp:  Displacement (up to 32bits) 		Rindex: Index Register = General Register. 		[1,2,4,8]: Scale of Index. 1 or 2 or 4 or 8. 		The inside of { } can be omitted.     This restricts the chained addressing up to 1 stage.  */
end_comment

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     The other macros defined here are used only in GO_IF_LEGITIMATE_ADDRESS,    except for CONSTANT_ADDRESS_P which is actually machine-independent.  */
end_comment

begin_define
define|#
directive|define
name|REG_CODE_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))
end_define

begin_define
define|#
directive|define
name|REG_CODE_INDEX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& REG_OK_FOR_INDEX_P (X))
end_define

begin_comment
comment|/* GET_CODE(X) must be PLUS. This macro does not check for PLUS! */
end_comment

begin_define
define|#
directive|define
name|BASE_PLUS_DISP_P
parameter_list|(
name|X
parameter_list|)
define|\
value|( REG_CODE_BASE_P (XEXP (X, 0)) 		\&& CONSTANT_ADDRESS_P (XEXP (X, 1))	\     ||						\      REG_CODE_BASE_P (XEXP (X, 1)) 		\&& CONSTANT_ADDRESS_P (XEXP (X, 0)) )
end_define

begin_comment
comment|/* 1 if X is {0,Rbase} + {0,disp}.  */
end_comment

begin_define
define|#
directive|define
name|BASED_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(CONSTANT_ADDRESS_P (X)	\    || REG_CODE_BASE_P (X)	\    || (GET_CODE (X) == PLUS)	\&& BASE_PLUS_DISP_P (X))
end_define

begin_comment
comment|/* 1 if X is 1 or 2 or 4 or 8. GET_CODE(X) must be CONST_INT. */
end_comment

begin_define
define|#
directive|define
name|SCALE_OF_INDEX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|( INTVAL(X) == 4	\     || INTVAL(X) == 2	\     || INTVAL(X) == 8	\     || INTVAL(X) == 1 )
end_define

begin_comment
comment|/* #define INDEX_TERM_P(X,MODE)  */
end_comment

begin_define
define|#
directive|define
name|INDEX_TERM_P
parameter_list|(
name|X
parameter_list|)
define|\
value|( REG_CODE_INDEX_P(X)					\     || (GET_CODE (X) == MULT				\&& ( (xfoo0 = XEXP (X, 0)), (xfoo1 = XEXP(X, 1)), \ 	     ( ( (GET_CODE (xfoo0) == CONST_INT)	\&& SCALE_OF_INDEX_P (xfoo0)		\&& REG_CODE_INDEX_P (xfoo1) )		\ 	      ||					\ 	       ( (GET_CODE (xfoo1) == CONST_INT)		\&& SCALE_OF_INDEX_P (xfoo1)		\&& REG_CODE_INDEX_P (xfoo0) ) ))))
end_define

begin_comment
comment|/* Assumes there are no cases such that X = (Ireg + Disp) + Disp */
end_comment

begin_define
define|#
directive|define
name|BASE_DISP_INDEX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|( BASED_ADDRESS_P (X)							\    || ( (GET_CODE (X) == PLUS)						\&& ( ( (xboo0 = XEXP (X, 0)), (xboo1 = XEXP (X, 1)),		\ 	  (REG_CODE_BASE_P (xboo0)					\&& (GET_CODE (xboo1) == PLUS)				\&& ( ( CONSTANT_ADDRESS_P (XEXP (xboo1, 0))			\&& INDEX_TERM_P (XEXP (xboo1, 1)) )			\ 	         || ( CONSTANT_ADDRESS_P (XEXP (xboo1, 1))		\&& INDEX_TERM_P (XEXP (xboo1, 0))) )))		\ 	 ||								\ 	  (CONSTANT_ADDRESS_P (xboo0)					\&& (GET_CODE (xboo1) == PLUS)				\&& ( ( REG_CODE_BASE_P (XEXP (xboo1, 0))			\&& INDEX_TERM_P (XEXP (xboo1, 1)) )			\ 	         || ( REG_CODE_BASE_P (XEXP (xboo1, 1))			\&& INDEX_TERM_P (XEXP (xboo1, 0))) ))		\ 	||								\ 	  (INDEX_TERM_P (xboo0)						\&& ( ( (GET_CODE (xboo1) == PLUS)				\&& ( ( REG_CODE_BASE_P (XEXP (xboo1, 0))		\&& CONSTANT_ADDRESS_P (XEXP (xboo1, 1)) )		\ 	               || ( REG_CODE_BASE_P (XEXP (xboo1, 1))   	\&& CONSTANT_ADDRESS_P (XEXP (xboo1, 0))) ))	\ 		||							\ 		 (CONSTANT_ADDRESS_P (xboo1))				\ 		||							\ 		 (REG_CODE_BASE_P (xboo1)) )))))
end_define

begin_comment
comment|/* 	If you want to allow double-indirection, 	you have to change the<fp-relative> =><sp-relative> conversion 	routine. M.Yuhara  #ifdef REG_OK_STRICT #define DOUBLE_INDIRECTION(X,ADDR) {\     if (BASE_DISP_INDEX_P (XEXP (XEXP (X, 0), 0) )) goto ADDR; \     } #else #define DOUBLE_INDIRECTION(X,ADDR) { } #endif */
end_comment

begin_define
define|#
directive|define
name|GO_IF_LEGITIMATE_ADDRESS
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|,
name|ADDR
parameter_list|)
value|{\   register rtx xboo0, xboo1, xfoo0, xfoo1;		\   if (GET_CODE (X) == MEM) { 				\
comment|/*							\     if (GET_CODE (XEXP (X,0)) == MEM) {			\ 	DOUBLE_INDIRECTION(X,ADDR);			\     } else {						\ 	if (BASE_DISP_INDEX_P (XEXP (X, 0))) goto ADDR;	\     }							\     */
value|\   } else {						\ 	if (BASE_DISP_INDEX_P (X)) goto ADDR;		\ 	if ((GET_CODE (X) == PRE_DEC || GET_CODE (X) == POST_INC)	\&& REG_P (XEXP (X, 0))					\&& (REGNO (XEXP (X, 0)) == STACK_POINTER_REGNUM))		\ 		goto ADDR;						\   }							\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     For the Gmicro, nothing is done now. */
end_comment

begin_define
define|#
directive|define
name|LEGITIMIZE_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|OLDX
parameter_list|,
name|MODE
parameter_list|,
name|WIN
parameter_list|)
value|{}
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the VAX, the predecrement and postincrement address depend thus    (the amount of decrement or increment being the length of the operand)    and all indexed address depend thus (because the index scale factor    is the length of the operand).    The Gmicro mimics the VAX now. Since ADDE is legitimate, it cannot    include auto-inc/dec. */
end_comment

begin_comment
comment|/* Unnecessary ??? */
end_comment

begin_define
define|#
directive|define
name|GO_IF_MODE_DEPENDENT_ADDRESS
parameter_list|(
name|ADDR
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|{ if (GET_CODE (ADDR) == POST_INC || GET_CODE (ADDR) == PRE_DEC)	\      goto LABEL; }
end_define

begin_escape
end_escape

begin_comment
comment|/* Specify the machine mode that this machine uses    for the index in the tablejump instruction.  */
end_comment

begin_comment
comment|/* #define CASE_VECTOR_MODE HImode */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|SImode
end_define

begin_comment
comment|/* Define this if the tablejump instruction expects the table    to contain offsets from the address of the table.    Do not define this if the table should contain absolute addresses.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_PC_RELATIVE
end_define

begin_comment
comment|/* Specify the tree operation to be used to convert reals to integers.  */
end_comment

begin_define
define|#
directive|define
name|IMPLICIT_FIX_EXPR
value|FIX_ROUND_EXPR
end_define

begin_comment
comment|/* This is the kind of divide that is easiest to do in the general case.  */
end_comment

begin_define
define|#
directive|define
name|EASY_DIV_EXPR
value|TRUNC_DIV_EXPR
end_define

begin_comment
comment|/* Define this as 1 if `char' should by default be signed; else as 0.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_comment
comment|/* Max number of bytes we can move from memory to memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|4
end_define

begin_comment
comment|/* Define this if zero-extension is slow (more than one real instruction).  */
end_comment

begin_comment
comment|/* #define SLOW_ZERO_EXTEND */
end_comment

begin_comment
comment|/* Nonzero if access to memory by bytes is slow and undesirable.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|0
end_define

begin_comment
comment|/* Define if shifts truncate the shift count    which implies one can omit a sign-extension or zero-extension    of a shift count.  */
end_comment

begin_comment
comment|/* #define SHIFT_COUNT_TRUNCATED */
end_comment

begin_comment
comment|/* Value is 1 if truncating an integer of INPREC bits to OUTPREC bits    is done just by pretending it is already truncated.  */
end_comment

begin_define
define|#
directive|define
name|TRULY_NOOP_TRUNCATION
parameter_list|(
name|OUTPREC
parameter_list|,
name|INPREC
parameter_list|)
value|1
end_define

begin_comment
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_comment
comment|/* #define STORE_FLAG_VALUE -1 */
end_comment

begin_comment
comment|/* When a prototype says `char' or `short', really pass an `int'.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
end_define

begin_comment
comment|/* Specify the machine mode that pointers have.    After generation of rtl, the compiler makes no further distinction    between pointers and any other objects of this machine mode.  */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|SImode
end_define

begin_comment
comment|/* A function address in a call instruction    is a byte address (for indexing purposes)    so give the MEM rtx a byte's mode.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|QImode
end_define

begin_comment
comment|/* Compute the cost of computing a constant rtl expression RTX    whose rtx-code is CODE.  The body of this macro is a portion    of a switch statement.  If the code is computed here,    return it with a return statement.  Otherwise, break from the switch.  */
end_comment

begin_define
define|#
directive|define
name|CONST_COSTS
parameter_list|(
name|RTX
parameter_list|,
name|CODE
parameter_list|,
name|OUTER_CODE
parameter_list|)
define|\
value|case CONST_INT:						\     if ((unsigned) INTVAL (RTX)< 8) return 0;			\     if ((unsigned) (INTVAL (RTX) + 0x80)< 0x100) return 1;	\     if ((unsigned) (INTVAL (RTX) + 0x8000)< 0x10000) return 2;	\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 3;							\   case CONST_DOUBLE:						\     return 5;
end_define

begin_escape
end_escape

begin_comment
comment|/* Define subroutines to call to handle multiply and divide.    The `*' prevents an underscore from being prepended by the compiler.  */
end_comment

begin_comment
comment|/* Use libgcc on Gmicro */
end_comment

begin_comment
comment|/* #define UDIVSI3_LIBCALL "*udiv" */
end_comment

begin_comment
comment|/* #define UMODSI3_LIBCALL "*urem" */
end_comment

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.  */
end_comment

begin_comment
comment|/* Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').  */
end_comment

begin_comment
comment|/* Set if the cc value is actually in the FPU, so a floating point    conditional branch must be output.  */
end_comment

begin_define
define|#
directive|define
name|CC_IN_FPU
value|04000
end_define

begin_comment
comment|/* Store in cc_status the expressions    that the condition codes will describe    after execution of an instruction whose pattern is EXP.    Do not alter them if the instruction would not alter the cc's.  */
end_comment

begin_comment
comment|/* Since Gmicro's compare instructions depend on the branch condition,    all branch should be kept.    More work must be done to optimize condition code !! M.Yuhara */
end_comment

begin_define
define|#
directive|define
name|NOTICE_UPDATE_CC
parameter_list|(
name|EXP
parameter_list|,
name|INSN
parameter_list|)
value|{CC_STATUS_INIT;}
end_define

begin_comment
comment|/* The skeleton of the next macro is taken from "vax.h".    FPU-reg manipulation is added.  M.Yuhara */
end_comment

begin_comment
comment|/* Now comment out. #define NOTICE_UPDATE_CC(EXP, INSN) {	\   if (GET_CODE (EXP) == SET) {					\       if ( !FPU_REG_P (XEXP (EXP, 0))				\&& (XEXP (EXP, 0) != cc0_rtx)				\&& (FPU_REG_P (XEXP (EXP, 1))				\ 	      || GET_CODE (XEXP (EXP, 1)) == FIX		\ 	      || GET_CODE (XEXP (EXP, 1)) == FLOAT_TRUNCATE	\ 	      || GET_CODE (XEXP (EXP, 1)) == FLOAT_EXTEND)) {	\ 	 CC_STATUS_INIT;					\       } else if (GET_CODE (SET_SRC (EXP)) == CALL) {		\ 	 CC_STATUS_INIT;					\       } else if (GET_CODE (SET_DEST (EXP)) != PC) {		\ 	  cc_status.flags = 0;					\ 	  cc_status.value1 = SET_DEST (EXP);			\ 	  cc_status.value2 = SET_SRC (EXP);			\       }								\   } else if (GET_CODE (EXP) == PARALLEL				\&& GET_CODE (XVECEXP (EXP, 0, 0)) == SET		\&& GET_CODE (SET_DEST (XVECEXP (EXP, 0, 0))) != PC) {\       cc_status.flags = 0;					\       cc_status.value1 = SET_DEST (XVECEXP (EXP, 0, 0));	\       cc_status.value2 = SET_SRC (XVECEXP (EXP, 0, 0)); 	\   /* PARALLELs whose first element sets the PC are aob, sob VAX insns.	\      They do change the cc's.  So drop through and forget the cc's. * / \   } else CC_STATUS_INIT;						\   if (cc_status.value1&& GET_CODE (cc_status.value1) == REG	\&& cc_status.value2					\&& reg_overlap_mentioned_p (cc_status.value1, cc_status.value2))	\     cc_status.value2 = 0;					\   if (cc_status.value1&& GET_CODE (cc_status.value1) == MEM	\&& cc_status.value2					\&& GET_CODE (cc_status.value2) == MEM)			\     cc_status.value2 = 0;					\   if ( (cc_status.value1&& FPU_REG_P (cc_status.value1))	\       || (cc_status.value2&& FPU_REG_P (cc_status.value2)))	\     cc_status.flags = CC_IN_FPU;				\ } */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_JUMP
parameter_list|(
name|NORMAL
parameter_list|,
name|FLOAT
parameter_list|,
name|NO_OV
parameter_list|)
define|\
value|{ if (cc_prev_status.flags& CC_IN_FPU)		\     return FLOAT;				\   if (cc_prev_status.flags& CC_NO_OVERFLOW)	\     return NO_OV;				\   return NORMAL; }
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".section text,code,align=4"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".section data,data,align=4"
end_define

begin_comment
comment|/* Output before uninitialized data. */
end_comment

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|".section bss,data,align=4"
end_define

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_bss
end_define

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|void								\ bss_section ()							\ {								\     if (in_section != in_bss) {					\ 	fprintf (asm_out_file, "%s\n", BSS_SECTION_ASM_OP);	\ 	in_section = in_bss;					\     }								\ }
end_define

begin_comment
comment|/* Output at beginning of assembler file.    It is not appropriate for this to print a list of the options used,    since that's not the convention that we use.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_comment
comment|/* Output at the end of assembler file. */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
value|fprintf (FILE, "\t.end\n");
end_define

begin_comment
comment|/* Don't try to define `gcc_compiled.' since the assembler do not    accept symbols with periods and GDB doesn't run on this machine anyway.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_comment
comment|/* #define ASM_APP_ON "#APP\n" */
end_comment

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

begin_comment
comment|/* #define ASM_APP_OFF ";#NO_APP\n" */
end_comment

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",	\  "r8", "r9", "r10", "r11", "r12", "r13", "fp", "sp",	\  "fr0", "fr1", "fr2", "fr3", "fr4", "fr5", "fr6", "fr7", \  "fr8", "fr9", "fr10", "fr11", "fr12", "fr13", "fr14", "fr15"}
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb. */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|(REGNO)
end_define

begin_comment
comment|/* Define this if gcc should produce debugging output for dbx in response    to the -g flag. This does not work for the Gmicro now */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* This is how to output the definition of a user-level label named NAME,    such as the label on a static function or variable NAME.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|{	\     assemble_name (FILE, NAME);	\     fputs (":\n", FILE);	\ }
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|{\     fputs ("\t.global ", FILE);	\     assemble_name (FILE, NAME);	\     fputs ("\n", FILE);		\ }
end_define

begin_comment
comment|/* This is how to output a command to make the external label named NAME    which are not defined in the file to be referable */
end_comment

begin_comment
comment|/* ".import" does not work ??? */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|)
value|{ \     fputs ("\t.global ", FILE);	\     assemble_name (FILE, NAME);	\     fputs ("\n", FILE);		\ }
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.    `assemble_name' uses this.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "_%s", NAME)
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, "%s%d:\n", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf (LABEL, "*%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.  */
end_comment

begin_comment
comment|/* do {...} while(0) is necessary, because these macros are used as     if (xxx) MACRO; else .... 		  ^ */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { union { double d; long l[2];} tem;					\      tem.d = (VALUE);							\      fprintf (FILE, "\t.fdata.d h'%x%08x.d\n", tem.l[0], tem.l[1]);	\ } while(0)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { union { float f; long l;} tem;			\      tem.f = (VALUE);					\      fprintf (FILE, "\t.fdata.s h'%x.s\n", tem.l);	\ } while(0)
end_define

begin_comment
comment|/* This is how to output an assembler line defining an `int' constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\t.data.w "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* Likewise for `char' and `short' constants.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHORT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\t.data.h "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_CHAR
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|( fprintf (FILE, "\t.data.b "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* This is how to output an assembler line for a numeric constant byte.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_BYTE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\t.data.b h'%x\n", (VALUE))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|P
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|output_ascii ((FILE), (P), (SIZE))
end_define

begin_comment
comment|/* This is how to output an insn to push a register on the stack.    It need not be very fast code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tmov %s,@-sp\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an insn to pop a register from the stack.    It need not be very fast code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|fprintf (FILE, "\tmov @sp+,%s\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.    (The Gmicro does not use such vectors,    but we must define this macro anyway.)  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\t.data.w L%d\n", VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf (FILE, "\t.data.w L%d-L%d\n", VALUE, REL)
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|fprintf (FILE, "\t.align %d\n", (1<< (LOG)));
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|fprintf (FILE, "\t.res.b %d\n", (SIZE))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( bss_section (),				\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ":\t.res.b %d\n", (ROUNDED)),\   fprintf ((FILE), "\t.export "),		\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), "\n") )
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|( bss_section (),				\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ":\t.res.b %d\n", (ROUNDED)))
end_define

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

begin_comment
comment|/* $__ is unique ????? M.Yuhara */
end_comment

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTPUT
parameter_list|,
name|NAME
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 12),	\   sprintf ((OUTPUT), "$__%s%d", (NAME), (LABELNO)))
end_define

begin_comment
comment|/* Define the parentheses used to group arithmetic operations    in assembler code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OPEN_PAREN
value|"("
end_define

begin_define
define|#
directive|define
name|ASM_CLOSE_PAREN
value|")"
end_define

begin_comment
comment|/* Define results of standard character escape sequences.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BELL
value|007
end_define

begin_define
define|#
directive|define
name|TARGET_BS
value|010
end_define

begin_define
define|#
directive|define
name|TARGET_TAB
value|011
end_define

begin_define
define|#
directive|define
name|TARGET_NEWLINE
value|012
end_define

begin_define
define|#
directive|define
name|TARGET_VT
value|013
end_define

begin_define
define|#
directive|define
name|TARGET_FF
value|014
end_define

begin_define
define|#
directive|define
name|TARGET_CR
value|015
end_define

begin_comment
comment|/* Output a float value (represented as a C double) as an immediate operand.    This macro is a Gmicro/68k-specific macro.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { union { float f; long l;} tem;		\   tem.f = (VALUE);				\   fprintf (FILE, "#h'%x.s", tem.l);		\ } while(0)
end_define

begin_comment
comment|/* Output a double value (represented as a C double) as an immediate operand.    This macro is a 68k-specific macro.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { union { double d; long l[2];} tem;		\   tem.d = (VALUE);				\   fprintf (FILE, "#h'%x%08x.d", tem.l[0], tem.l[1]);	\ } while(0)
end_define

begin_comment
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    For `%' followed by punctuation, CODE is the punctuation and X is null.     On the Gmicro, we use several CODE characters:    'f' for float insn (print a CONST_DOUBLE as a float rather than in hex)    'b' for branch target label.    '-' for an operand pushing on the stack.    '+' for an operand pushing on the stack.    '#' for an immediate operand prefix  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|( (CODE) == '#' || (CODE) == '-'		\      || (CODE) == '+' || (CODE) == '@' || (CODE) == '!')
end_define

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
define|\
value|{ int i;								\   static char *reg_name[] = REGISTER_NAMES;				\
comment|/* fprintf (stderr, "PRINT_OPERAND CODE=%c(0x%x), ", CODE, CODE);\ myprcode(GET_CODE(X)); */
value|\   if (CODE == '#') fprintf (FILE, "#");					\   else if (CODE == '-') fprintf (FILE, "@-sp");				\   else if (CODE == '+') fprintf (FILE, "@sp+");				\   else if (CODE == 's') fprintf (stderr, "err: PRINT_OPERAND<s>\n"); 	\   else if (CODE == '!') fprintf (stderr, "err: PRINT_OPERAND<!>\n"); 	\   else if (CODE == '.') fprintf (stderr, "err: PRINT_OPERAND<.>\n"); 	\   else if (CODE == 'b') {						\     if (GET_CODE (X) == MEM)						\ 	output_addr_const (FILE, XEXP (X, 0));
comment|/* for bsr */
value|\     else								\ 	output_addr_const (FILE, X);
comment|/* for bcc */
value|\   }									\   else if (CODE == 'p')							\     print_operand_address (FILE, X);					\   else if (GET_CODE (X) == REG)						\     fprintf (FILE, "%s", reg_name[REGNO (X)]);				\   else if (GET_CODE (X) == MEM)						\     output_address (XEXP (X, 0));					\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) == SFmode)	\     { union { double d; int i[2]; } u;					\       union { float f; int i; } u1;					\       u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\       u1.f = u.d;							\       if (CODE == 'f')							\ 	ASM_OUTPUT_FLOAT_OPERAND (FILE, u1.f);				\       else								\ 	fprintf (FILE, "#h'%x", u1.i); }				\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) != DImode)	\     { union { double d; int i[2]; } u;					\       u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\       ASM_OUTPUT_DOUBLE_OPERAND (FILE, u.d); }				\   else { putc ('#', FILE);						\ output_addr_const (FILE, X); }}
end_define

begin_escape
end_escape

begin_comment
comment|/* Note that this contains a kludge that knows that the only reason    we have an address (plus (label_ref...) (reg...))    is in the insn before a tablejump, and we know that m68k.md    generates a label LInnn: on such an insn.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|FILE
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ print_operand_address (FILE, ADDR); }
end_define

begin_escape
end_escape

begin_comment
comment|/* Local variables: version-control: t End: */
end_comment

end_unit

