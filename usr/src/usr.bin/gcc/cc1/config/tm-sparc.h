begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for Sun SPARC.    Copyright (C) 1988 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@mcc.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Note that some other tm- files include this one and then override    many of the definitions that relate to assembler syntax.  */
end_comment

begin_comment
comment|/* Specify library to handle `-a' basic block profiling.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{a:/usr/lib/bb_link.o} \ %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} "
end_define

begin_comment
comment|/* Provide required defaults for linker -e and -d switches.    Also, it is hard to debug with shared libraries,    so don't use them if going to debug.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{!e*:-e start} -dc -dp %{g:-Bstatic} %{static:-Bstatic} %{Bstatic}"
end_define

begin_comment
comment|/* Special flags to the Sun-4 assembler when using pipe for input.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|" %{pipe:-} "
end_define

begin_comment
comment|/* Prevent error on `-dalign', `-sun4' and `-target sun4' options.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{dalign:} %{sun4:} %{target:}"
end_define

begin_comment
comment|/* These compiler options take an argument.  We ignore -target for now.  */
end_comment

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
value|(!strcmp (STR, "target"))
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dsparc -Dsun -Dunix"
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (sparc)");
end_define

begin_comment
comment|/* Generate DBX debugging information.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

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
comment|/* Nonzero if we should generate code to use the fpu.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FPU
value|(target_flags& 1)
end_define

begin_comment
comment|/* Nonzero if we should use FUNCTION_EPILOGUE.  Otherwise, we    use fast return insns, but lose some generality.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_EPILOGUE
value|(target_flags& 2)
end_define

begin_comment
comment|/* Nonzero if we expect to be passed through the Sun    optimizing assembler.  This requires us to generate    code which we otherwise would not.  For example,    calls via pointers-to-functions must be output    specially because Sun assemble does not do proper flow    analysis for this case. */
end_comment

begin_define
define|#
directive|define
name|TARGET_SUN_ASM
value|(target_flags& 4)
end_define

begin_comment
comment|/* Nonzero if we should do eager peepholes for conditional branch    scheduling.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_EAGER
value|(target_flags& 8)
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"fpu", 1},			\     {"soft-float", -1},		\     {"epilogue", 2},		\     {"no-epilogue", -2},	\     {"sun-asm", 4},		\     {"eager", 8},		\     { "", TARGET_DEFAULT}}
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|3
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_comment
comment|/* This is true on the SPARC.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is numbered.  */
end_comment

begin_comment
comment|/* For SPARC we can decide arbitrarily    since there are no machine instructions for them.  */
end_comment

begin_comment
comment|/* #define WORDS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* number of bits in an addressible storage unit */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_comment
comment|/* Width in bits of a "word", which is the contents of a machine register.    Note that this is not necessarily the width of data type `int';    if using 16-bit ints on a 68000, this would still be 32.    But on a machine with 16-bit registers, this would be 16.  */
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
comment|/* Allocation boundary (in *bits*) for storing pointers in memory.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_BOUNDARY
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
value|64
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for the code of a function.  */
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
comment|/* Every structure's size must be a multiple of this.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_comment
comment|/* A bitfield declared as `int' forces `int' alignment for the struct.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|64
end_define

begin_comment
comment|/* Define this if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
end_define

begin_comment
comment|/* Things that must be doubleword aligned cannot go in the text section,    because the linker fails to align the text section enough!    Put them in the data section.  */
end_comment

begin_define
define|#
directive|define
name|MAX_TEXT_ALIGN
value|32
end_define

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|T
parameter_list|)
define|\
value|{									\   if (TREE_CODE (T) == VAR_DECL)					\     {									\       if (TREE_READONLY (T)&& ! TREE_VOLATILE (T)			\&& DECL_ALIGN (T)<= MAX_TEXT_ALIGN)				\ 	text_section ();						\       else								\ 	data_section ();						\     }									\   if (*tree_code_type[(int) TREE_CODE (T)] == 'c')			\     {									\       if ((TREE_CODE (T) == STRING_CST&& flag_writable_strings)	\ 	  || TYPE_ALIGN (TREE_TYPE (T))> MAX_TEXT_ALIGN)		\ 	data_section ();						\       else								\ 	text_section ();						\     }									\ }
end_define

begin_comment
comment|/* Use text section for a constant    unless we need more alignment than that offers.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|{						\   if (GET_MODE_BITSIZE (MODE)<= MAX_TEXT_ALIGN)\     text_section ();				\   else						\     data_section ();				\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     SPARC has 32 fullword registers and 32 floating point registers.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|64
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On SPARC, this includes all the global registers    (registers r[0] through r[7]) and the callee return    address register, r[15].  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1,	\   0, 0, 0, 0, 0, 0, 1, 1,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 1, 1,	\ 				\   1, 1, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 1, 1,	\ 				\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1}
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On SPARC, ordinary registers hold 32 bits worth;    this means both integer and floating point registers.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On SPARC, the cpu registers can hold any mode but the float registers    can only hold SFmode or DFmode.  */
end_comment

begin_define
define|#
directive|define
name|HARD_REGNO_MODE_OK
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((REGNO)< 32 ? ((GET_MODE_SIZE (MODE)<= 4) ? 1 : ((REGNO)& 1) == 0) : \    ((MODE) == SFmode ? 1 : (MODE) == DFmode&& ((REGNO)& 1) == 0))
end_define

begin_comment
comment|/* Value is 1 if it is a good idea to tie two pseudo registers    when one has mode MODE1 and one has mode MODE2.    If HARD_REGNO_MODE_OK could produce different values for MODE1 and MODE2,    for any hard reg, then this must be 0 for correct output.  */
end_comment

begin_define
define|#
directive|define
name|MODES_TIEABLE_P
parameter_list|(
name|MODE1
parameter_list|,
name|MODE2
parameter_list|)
define|\
value|(((MODE1) == SFmode || (MODE1) == DFmode) \    == ((MODE2) == SFmode || (MODE2) == DFmode))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* SPARC pc isn't overloaded on a register that the compiler knows about.  */
end_comment

begin_comment
comment|/* #define PC_REGNUM  */
end_comment

begin_comment
comment|/* Register to use for pushing function arguments.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|14
end_define

begin_comment
comment|/* Actual top-of-stack address is 92 greater    than the contents of the stack pointer register.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|92
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|30
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|1
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|30
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|1
end_define

begin_comment
comment|/* Functions which return large structures get the address    to place the wanted value at offset 64 from the frame.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_OFFSET
value|64
end_define

begin_comment
comment|/* Used only in other #defines in this file.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE
define|\
value|gen_rtx (MEM, Pmode,					\ 	   gen_rtx (PLUS, SImode, stack_pointer_rtx,	\ 		    gen_rtx (CONST_INT, VOIDmode, STRUCT_VALUE_OFFSET)))
end_define

begin_define
define|#
directive|define
name|STRUCT_VALUE_INCOMING
define|\
value|gen_rtx (MEM, Pmode,					\ 	   gen_rtx (PLUS, SImode, frame_pointer_rtx,	\ 		    gen_rtx (CONST_INT, VOIDmode, STRUCT_VALUE_OFFSET)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_comment
comment|/* The SPARC has two kinds of registers, general and floating point.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|GENERAL_REGS
block|,
name|FP_REGS
block|,
name|ALL_REGS
block|,
name|LIM_REG_CLASSES
block|}
enum|;
end_enum

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
value|{"NO_REGS", "GENERAL_REGS", "FP_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
value|{{0, 0}, {-1, 0}, {0, -1}, {-1, -1}}
end_define

begin_comment
comment|/* The same information, inverted:    Return the class number of the smallest class containing    reg number REGNO.  This could be a conditional expression    or could index an array.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)>= 32 ? FP_REGS : GENERAL_REGS)
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
comment|/* Get reg_class from a letter such as appears in the machine description.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|((C) == 'f' ? FP_REGS : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     For SPARC, `I' is used for the range of constants an insn    can actually contain.    `J' is used for the range which is just zero (since that is R0).    `K' is used for the 5-bit operand of a compare insns.  */
end_comment

begin_define
define|#
directive|define
name|SMALL_INT
parameter_list|(
name|X
parameter_list|)
value|((unsigned) (INTVAL (X) + 0x1000)< 0x2000)
end_define

begin_define
define|#
directive|define
name|CONST_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'I' ? (unsigned) ((VALUE) + 0x1000)< 0x2000	\    : (C) == 'J' ? (VALUE) == 0				\    : (C) == 'K' ? (unsigned) (VALUE)< 0x20		\    : 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.  */
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
value|((C) == 'G'&& XINT (VALUE, 0) == 0&& XINT (VALUE, 1) == 0)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.  */
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
value|(CLASS)
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On SPARC, this is the size of MODE in words,    except in the FP regs, where a single reg is always enough.  */
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
value|((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
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

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|-16
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On SPARC, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/*  #define PUSH_ROUNDING(BYTES) */
end_comment

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.    This is 64 for the ins and locals, plus 4 for the struct-return reg    if this function isn't going to use it.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
define|\
value|(DECL_MODE (DECL_RESULT (fndecl)) == BLKmode	\    ? STRUCT_VALUE_OFFSET : STRUCT_VALUE_OFFSET + 4)
end_define

begin_comment
comment|/* Offset from top-of-stack address to location to store the    function parameter if it can't go in a register.    Addresses for following parameters are computed relative to this one.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_CALLER_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
define|\
value|(STRUCT_VALUE_OFFSET + 4 - STACK_POINTER_OFFSET)
end_define

begin_comment
comment|/* When a parameter is passed in a register, stack space is still    allocated for it.  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
end_define

begin_comment
comment|/* Value is 1 if returning from a function call automatically    pops the arguments described by the number-of-args field in the call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNTYPE
parameter_list|)
value|0
end_define

begin_comment
comment|/* Some subroutine macros specific to this machine.  */
end_comment

begin_define
define|#
directive|define
name|BASE_RETURN_VALUE_REG
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == SFmode || (MODE) == DFmode ? 32 : 8)
end_define

begin_define
define|#
directive|define
name|BASE_OUTGOING_VALUE_REG
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == SFmode || (MODE) == DFmode ? 32 : 24)
end_define

begin_define
define|#
directive|define
name|BASE_PASSING_ARG_REG
parameter_list|(
name|MODE
parameter_list|)
value|(8)
end_define

begin_define
define|#
directive|define
name|BASE_INCOMING_ARG_REG
parameter_list|(
name|MODE
parameter_list|)
value|(24)
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_comment
comment|/* On SPARC the value is found in the first "output" register.  */
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
define|\
value|gen_rtx (REG, TYPE_MODE (VALTYPE), BASE_RETURN_VALUE_REG (TYPE_MODE (VALTYPE)))
end_define

begin_comment
comment|/* But the called function leaves it in the first "input" register.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_OUTGOING_VALUE
parameter_list|(
name|VALTYPE
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|gen_rtx (REG, TYPE_MODE (VALTYPE), BASE_OUTGOING_VALUE_REG (TYPE_MODE (VALTYPE)))
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
value|gen_rtx (REG, MODE, BASE_RETURN_VALUE_REG (MODE))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value    as seen by the caller.    On SPARC, the first "output" reg is used for integer values,    and the first floating point register is used for floating point values.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 8 || (N) == 32)
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On SPARC, these are the "output" registers.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)< 14&& (N)> 7)
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On SPARC, this is a single integer, which is a number of words    of arguments scanned so far (including the invisible argument,    if any, which holds the structure-value-address).    Thus 7 or more means all following args should go on the stack.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* Define the number of register that can hold parameters.    This macro is used only in other macro definitions below.  */
end_comment

begin_define
define|#
directive|define
name|NPARM_REGS
value|6
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.     On SPARC, the offset always starts at 0: the first parm reg is always    the same reg.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|)
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
value|((CUM) += ((MODE) != BLKmode				\ 	    ? (GET_MODE_SIZE (MODE) + 3) / 4		\ 	    : (int_size_in_bytes (TYPE) + 3) / 4))
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).  */
end_comment

begin_comment
comment|/* On SPARC the first six args are normally in registers    and the rest are pushed.  Any arg that starts within the first 6 words    is at least partially passed in a register unless its data type forbids.  */
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
value|((CUM)< NPARM_REGS							\&& ((TYPE)==0 || ! TREE_ADDRESSABLE ((tree)(TYPE)))			\&& ((MODE) != BLKmode || (TYPE_ALIGN ((TYPE)) % 32 == 0))		\  ? gen_rtx (REG, (MODE), BASE_PASSING_ARG_REG (MODE) + (CUM)) : 0)
end_define

begin_comment
comment|/* Define where a function finds its arguments.    This is different from FUNCTION_ARG because of register windows.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_INCOMING_ARG
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
value|((CUM)< NPARM_REGS							\&& ((TYPE)==0 || ! TREE_ADDRESSABLE ((tree)(TYPE)))			\&& ((MODE) != BLKmode || (TYPE_ALIGN ((TYPE)) % 32 == 0))		\  ? gen_rtx (REG, (MODE), BASE_INCOMING_ARG_REG (MODE) + (CUM)) : 0)
end_define

begin_comment
comment|/* For an arg passed partly in registers and partly in memory,    this is the number of registers used.    For args passed entirely in registers or entirely in memory, zero.    Any arg that starts in the first 6 regs but won't entirely fit in them    needs partial registers on the Sparc.  */
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
value|(((CUM)< NPARM_REGS							\&& ((TYPE)==0 || ! TREE_ADDRESSABLE ((tree)(TYPE)))			\&& ((MODE) != BLKmode || (TYPE_ALIGN ((TYPE)) % 32 == 0))		\&& ((CUM)								\ 	+ ((MODE) == BLKmode						\ 	   ? (int_size_in_bytes (TYPE) + 3) / 4				\ 	   : (GET_MODE_SIZE (MODE) + 3) / 4)) - NPARM_REGS> 0)		\    ? (NPARM_REGS - (CUM))						\    : 0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output the label for a function definition.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|{							\   extern tree double_type_node, float_type_node;	\   if (TREE_TYPE (DECL) == float_type_node)		\     fprintf (FILE, "\t.proc 6\n");			\   else if (TREE_TYPE (DECL) == double_type_node)	\     fprintf (FILE, "\t.proc 7\n");			\   else if (TREE_TYPE (DECL) == void_type_node)		\     fprintf (FILE, "\t.proc 0\n");			\   else fprintf (FILE, "\t.proc 1\n");			\   ASM_OUTPUT_LABEL (FILE, NAME);			\ }
end_define

begin_comment
comment|/* This macro generates the assembly code for function entry.    FILE is a stdio stream to output the code to.    SIZE is an int: how many units of temporary storage to allocate.    Refer to the array `regs_ever_live' to determine which registers    to save; `regs_ever_live[I]' is nonzero if register number I    is ever used in the function.  This macro is responsible for    knowing which registers should not be saved even if used.  */
end_comment

begin_comment
comment|/* On SPARC, move-double insns between fpu and cpu need an 8-byte block    of memory.  If any fpu reg is used in the function, we allocate    such a block here, at the bottom of the frame, just in case it's needed.     If this function is a leaf procedure, then we may choose not    to do a "save" insn.  Currently we do this only if it touches    the "output" registers.  The "local" and "input" registers    are off limits.  It might be better to allow one such register    to go to the stack, but I doubt it.  */
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
value|{								\   extern char call_used_regs[];					\   extern int current_function_pretend_args_size;		\   extern int frame_pointer_needed;				\   int fsize = (((SIZE) + 7 - STARTING_FRAME_OFFSET)& -8);	\   int actual_fsize;						\   int n_fregs = 0, i;						\   int n_iregs = 64;						\   for (i = 32; i< FIRST_PSEUDO_REGISTER; i++)			\     if (regs_ever_live[i]&& ! call_used_regs[i])		\       n_fregs++;						\   for (i = 16; i< 32; i++)					\     if (regs_ever_live[i]) { n_iregs = 96; break; }		\   fprintf (FILE, "\t!#PROLOGUE# 0\n");				\   actual_fsize = fsize + n_iregs + (n_fregs*4+7& -8);		\   fsize += current_function_pretend_args_size+7& -8;		\   actual_fsize += current_function_pretend_args_size+7& -8;	\   if (actual_fsize< 4096)					\     fprintf (FILE, "\tsave %%sp,-%d,%%sp\n", actual_fsize);	\   else								\     {								\       fprintf (FILE, "\tsethi %%hi(0x%x),%%g1\n\tadd %%g1,%%lo(0x%x),%%g1\n", \ 	       -actual_fsize, -actual_fsize);			\       fprintf (FILE, "\tsave %%sp,%%g1,%%sp\n");		\     }								\   fprintf (FILE, "\t!#PROLOGUE# 1\n");				\   if (n_fregs)							\     {								\       for (i = 32, n_fregs = 0; i< FIRST_PSEUDO_REGISTER; i++)	\         if (regs_ever_live[i]&& ! call_used_regs[i])		\           {							\ 	    if (regs_ever_live[i+1]&& ! call_used_regs[i+1])	\ 	      fprintf (FILE, "\tstd %s,[%%sp+0x%x]\n",		\ 		       reg_names[i], n_iregs + 4 * n_fregs),	\ 	      n_fregs += 2, i += 1;				\ 	    else						\ 	      fprintf (FILE, "\tstf %s,[%%sp+0x%x]\n",		\ 		       reg_names[i], n_iregs + 4 * n_fregs++);	\           }							\     }								\   if (regs_ever_live[32])					\     fprintf (FILE, "\tst %s,[%%fp-16]\n\tst %s,[%%fp-12]\n",	\ 	     reg_names[0], reg_names[0]);			\ }
end_define

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  */
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
value|fprintf (FILE, "\tsethi %%hi(LP%d),%%o0\n\tcall mcount\n\tor %%lo(LP%d),%%o0,%%o0\n", \ 	   (LABELNO), (LABELNO))
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
value|fprintf (FILE, "\tsethi %%hi(LPBX0),%%o0\n\tld [%%lo(LPBX0)+%%o0],%%o1\n\ttst %%o1\n\tbne LPY%d\n\tnop\n\tcall ___bb_init_func\n\tnop\nLPY%d:\n",  \ 	   (LABELNO), (LABELNO))
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
value|{								\   int blockn = (BLOCKNO);					\   fprintf (FILE, "\tsethi %%hi(LPBX2+%d),%%g1\n\tld [%%lo(LPBX2+%d)+%%g1],%%g2\n\ \tadd %%g2,1,%%g2\n\tst %%g2,[%%lo(LPBX2+%d)+%%g1]\n",		\ 	   4 * blockn, 4 * blockn, 4 * blockn);			\   CC_STATUS_INIT;
comment|/* We have clobbered %g1.  Also %g2.  */
value|\ }
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|may_call_alloca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_pretend_args_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
define|\
value|(get_frame_size () != 0	\   || may_call_alloca || current_function_pretend_args_size)
end_define

begin_comment
comment|/* This macro generates the assembly code for function exit,    on machines that need it.  If FUNCTION_EPILOGUE is not defined    then individual return instructions are generated for each    return statement.  Args are same as for FUNCTION_PROLOGUE.     The function epilogue should not depend on the current stack pointer!    It should use the frame pointer only.  This is mandatory because    of alloca; we also take advantage of it to omit stack adjustments    before returning.  */
end_comment

begin_comment
comment|/* This declaration is needed due to traditional/ANSI    incompatibilities which cannot be #ifdefed away    because they occur inside of macros.  Sigh.  */
end_comment

begin_decl_stmt
specifier|extern
name|union
name|tree_node
modifier|*
name|current_function_decl
decl_stmt|;
end_decl_stmt

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
value|{								\   extern char call_used_regs[];					\   extern int may_call_alloca;					\   extern int current_function_pretend_args_size;		\   extern int max_pending_stack_adjust;				\   extern int frame_pointer_needed;				\   int fsize = (((SIZE) + 7 - STARTING_FRAME_OFFSET)& -8);	\   int actual_fsize;						\   int n_fregs = 0, i;						\   int n_iregs = 64;						\   for (i = 32, n_fregs = 0; i< FIRST_PSEUDO_REGISTER; i++)	\     if (regs_ever_live[i]&& ! call_used_regs[i])		\       n_fregs++;						\   for (i = 16; i< 32; i++)					\     if (regs_ever_live[i]) { n_iregs = 96; break; }		\   actual_fsize = fsize + n_iregs + (n_fregs*4+7& -8);		\   actual_fsize += current_function_pretend_args_size+7& -8;	\   fsize += current_function_pretend_args_size+7& -8;		\   if (n_fregs)							\     {								\       char *base;						\       int offset;						\       if (fsize< 4096)						\ 	{ base = "%fp"; offset = n_iregs - actual_fsize; }	\       else							\ 	{ base = "%g1"; offset = n_iregs;			\ 	  if (fsize< 4096)					\ 	    fprintf (FILE, "sethi %%hi(0x%x),%%g1\n\tadd %%g1,%%lo(0x%x),%%g1\n\tadd %%fp,%%g1,%%g1\n", -actual_fsize, -actual_fsize);\ 	}							\       for (i = 32, n_fregs = 0; i< FIRST_PSEUDO_REGISTER; i++)	\ 	if (regs_ever_live[i]&& ! call_used_regs[i])		\ 	  {							\ 	    if (regs_ever_live[i+1]&& ! call_used_regs[i+1])	\ 	      fprintf (FILE, "\tldd [%s%+d],%s\n",		\ 		       base, offset + 4 * n_fregs,		\ 		       reg_names[i]),				\ 	      n_fregs += 2, i += 1;				\ 	    else						\ 	      fprintf (FILE, "\tldf [%s%+d],%s\n",		\ 		       base, offset + 4 * n_fregs++,		\ 		       reg_names[i]);				\ 	  }							\     }								\   fprintf (FILE, "\tret\n\trestore\n");				\ }
end_define

begin_comment
comment|/* If the memory address ADDR is relative to the frame pointer,    correct it to be relative to the stack pointer instead.    This is for when we don't use a frame pointer.    ADDR should be a variable name.  */
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
value|{ int offset = -1;							\   rtx regs = stack_pointer_rtx;						\   if (ADDR == frame_pointer_rtx)					\     offset = 0;								\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 0) == frame_pointer_rtx \&& GET_CODE (XEXP (ADDR, 1)) == CONST_INT)			\     offset = INTVAL (XEXP (ADDR, 1));					\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 0) == frame_pointer_rtx) \     { rtx other_reg = XEXP (ADDR, 1);					\       offset = 0;							\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 1) == frame_pointer_rtx) \     { rtx other_reg = XEXP (ADDR, 0);					\       offset = 0;							\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   if (offset>= 0)							\     { int regno;							\       extern char call_used_regs[];					\       for (regno = 0; regno< FIRST_PSEUDO_REGISTER; regno++)		\         if (regs_ever_live[regno]&& ! call_used_regs[regno])		\           offset += 4;							\       offset -= 4;							\       ADDR = plus_constant (regs, offset + (DEPTH)); } }
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

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< 32)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< 32)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_FP_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO) ^ 0x20)< 32 || (unsigned) (reg_renumber[REGNO] ^ 0x20)< 32)
end_define

begin_comment
comment|/* Now macros that check whether X is a register and also,    strictly, whether it is in a specified class.     These macros are specific to the SPARC, and may be used only    in code for printing assembler insns and in conditions for    define_optimization.  */
end_comment

begin_comment
comment|/* 1 if X is an fp register.  */
end_comment

begin_define
define|#
directive|define
name|FP_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& REGNO_OK_FOR_FP_P (REGNO (X)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Maximum number of registers that can appear in a valid memory address.  */
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
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.     Anything but a CONST_DOUBLE can be made to work.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) != CONST_DOUBLE)
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
value|(((unsigned) REGNO (X)) - 32>= 32)
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
value|(((unsigned) REGNO (X)) - 32>= 32)
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
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     On SPARC, the actual legitimate addresses must be REG+REG or REG+SMALLINT.    But we can treat a SYMBOL_REF as legitimate if it is part of this    function's constant-pool, because such addresses can actually    be output as REG+SMALLINT.     Try making SYMBOL_REF (and other things which are CONSTANT_ADDRESS_P)    a legitimate address, regardless.  Because the only insns which can use    memory are load or store insns, the added hair in the machine description    is not that bad.  It should also speed up the compiler by halving the number    of insns it must manage for each (MEM (SYMBOL_REF ...)) involved.  */
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
define|\
value|{ if (GET_CODE (X) == REG)				\     { if (REG_OK_FOR_BASE_P (X)) goto ADDR; }		\   else if (GET_CODE (X) == PLUS)			\     {							\       if (GET_CODE (XEXP (X, 0)) == REG			\&& REG_OK_FOR_BASE_P (XEXP (X, 0)))		\ 	{						\ 	  if (GET_CODE (XEXP (X, 1)) == REG		\&& REG_OK_FOR_INDEX_P (XEXP (X, 1)))	\ 	    goto ADDR;					\ 	  if (GET_CODE (XEXP (X, 1)) == CONST_INT	\&& INTVAL (XEXP (X, 1))>= -0x1000	\&& INTVAL (XEXP (X, 1))< 0x1000)		\ 	    goto ADDR;					\ 	}						\       else if (GET_CODE (XEXP (X, 1)) == REG		\&& REG_OK_FOR_BASE_P (XEXP (X, 1)))		\ 	{						\ 	  if (GET_CODE (XEXP (X, 0)) == REG		\&& REG_OK_FOR_INDEX_P (XEXP (X, 0)))	\ 	    goto ADDR;					\ 	  if (GET_CODE (XEXP (X, 0)) == CONST_INT	\&& INTVAL (XEXP (X, 0))>= -0x1000	\&& INTVAL (XEXP (X, 0))< 0x1000)		\ 	    goto ADDR;					\ 	}						\     }							\   else if (CONSTANT_ADDRESS_P (X))			\     goto ADDR;						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.  */
end_comment

begin_comment
comment|/* On SPARC, change REG+N into REG+REG, and REG+(X*Y) into REG+REG.  */
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
define|\
value|{ if (GET_CODE (X) == PLUS&& CONSTANT_ADDRESS_P (XEXP (X, 1)))	\     (X) = gen_rtx (PLUS, SImode, XEXP (X, 0),			\ 		   copy_to_mode_reg (SImode, XEXP (X, 1)));	\   if (GET_CODE (X) == PLUS&& CONSTANT_ADDRESS_P (XEXP (X, 0)))	\     (X) = gen_rtx (PLUS, SImode, XEXP (X, 1),			\ 		   copy_to_mode_reg (SImode, XEXP (X, 0)));	\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == MULT)	\     (X) = gen_rtx (PLUS, SImode, XEXP (X, 1),			\ 		   force_operand (XEXP (X, 0), 0));		\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 1)) == MULT)	\     (X) = gen_rtx (PLUS, SImode, XEXP (X, 0),			\ 		   force_operand (XEXP (X, 1), 0));		\   if (GET_CODE (x) == SYMBOL_REF)				\     (X) = copy_to_reg (X);					\   if (memory_address_p (MODE, X))				\     goto WIN; }
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the SPARC this is never true.  */
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
end_define

begin_escape
end_escape

begin_comment
comment|/* Specify the machine mode that this machine uses    for the index in the tablejump instruction.  */
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

begin_comment
comment|/* #define CASE_VECTOR_PC_RELATIVE */
end_comment

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
comment|/* Nonzero if access to memory by bytes is slow and undesirable.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|0
end_define

begin_comment
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_comment
comment|/* When a prototype says `char' or `short', really pass an `int'.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
end_define

begin_comment
comment|/* Define if shifts truncate the shift count    which implies one can omit a sign-extension or zero-extension    of a shift count.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
end_define

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
value|SImode
end_define

begin_comment
comment|/* Define this if addresses of constant functions    shouldn't be put through pseudo regs where they can be cse'd.    Desirable on machines where ordinary constants are expensive    but a CALL with constant address is cheap.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_comment
comment|/* Define subroutines to call to handle multiply and divide.    Use the subroutines that Sun's library provides.    The `*' prevents an underscore from being prepended by the compiler.  */
end_comment

begin_define
define|#
directive|define
name|DIVSI3_LIBCALL
value|"*.div"
end_define

begin_define
define|#
directive|define
name|UDIVSI3_LIBCALL
value|"*.udiv"
end_define

begin_define
define|#
directive|define
name|MODSI3_LIBCALL
value|"*.rem"
end_define

begin_define
define|#
directive|define
name|UMODSI3_LIBCALL
value|"*.urem"
end_define

begin_define
define|#
directive|define
name|MULSI3_LIBCALL
value|"*.mul"
end_define

begin_define
define|#
directive|define
name|UMULSI3_LIBCALL
value|"*.umul"
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
parameter_list|)
define|\
value|case CONST_INT:						\     if (INTVAL (RTX)< 0x1000&& INTVAL (RTX)>= -0x1000) return 0; \   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 2;							\   case CONST_DOUBLE:						\     return 4;
end_define

begin_escape
end_escape

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.  */
end_comment

begin_comment
comment|/* Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').  */
end_comment

begin_comment
comment|/* This holds the value sourcing %hi(%g1).  We keep this info    around so that mem/mem ops, such as increment and decrement,    etc, can be performed reasonably.  */
end_comment

begin_define
define|#
directive|define
name|CC_STATUS_MDEP
value|rtx
end_define

begin_comment
comment|/* Nonzero if the results of the previous comparison are    in the floating point condition code register.  */
end_comment

begin_define
define|#
directive|define
name|CC_IN_FCCR
value|04000
end_define

begin_comment
comment|/* Nonzero if the results of the previous comparison are    int the coprocessor's condition code register.  */
end_comment

begin_define
define|#
directive|define
name|CC_IN_CCCR
value|010000
end_define

begin_comment
comment|/* Nonzero if we know (easily) that floating point register f0    (f1) contains the value 0.  */
end_comment

begin_define
define|#
directive|define
name|CC_F0_IS_0
value|020000
end_define

begin_define
define|#
directive|define
name|CC_F1_IS_0
value|040000
end_define

begin_comment
comment|/* Nonzero if we know the value of %hi(%g1).  */
end_comment

begin_define
define|#
directive|define
name|CC_KNOW_HI_G1
value|0100000
end_define

begin_define
define|#
directive|define
name|CC_STATUS_MDEP_INIT
value|(cc_status.mdep = 0)
end_define

begin_comment
comment|/* Store in cc_status the expressions    that the condition codes will describe    after execution of an instruction whose pattern is EXP.    Do not alter them if the instruction would not alter the cc's.  */
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
define|\
value|{ if (GET_CODE (EXP) == SET)					\     { if (SET_DEST (EXP) == cc0_rtx)				\ 	{ cc_status.flags = 0;					\ 	  cc_status.value1 = SET_DEST (EXP);			\ 	  cc_status.value2 = SET_SRC (EXP); }			\       else if (GET_CODE (SET_SRC (EXP)) == CALL)		\ 	{ CC_STATUS_INIT; }					\       else if (GET_CODE (SET_DEST (EXP)) == REG)		\ 	{ if (cc_status.value1					\&& reg_overlap_mentioned_p (SET_DEST (EXP), cc_status.value1)) \ 	    cc_status.value1 = 0;				\ 	  if (cc_status.value2					\&& reg_overlap_mentioned_p (SET_DEST (EXP), cc_status.value2)) \ 	    cc_status.value2 = 0;				\ 	}							\       else if (GET_CODE (SET_DEST (EXP)) == MEM)		\ 	{ rtx x = cc_status.mdep; int know = cc_status.flags& CC_KNOW_HI_G1;	\ 	  CC_STATUS_INIT;					\ 	  if (x&& know)					\ 	    { cc_status.mdep = x; cc_status.flags |= CC_KNOW_HI_G1; }		\ 	}							\     }								\   else if (GET_CODE (EXP) == PARALLEL				\&& GET_CODE (XVECEXP (EXP, 0, 0)) == SET)		\     { if (SET_DEST (XVECEXP (EXP, 0, 0)) == cc0_rtx)		\ 	{ cc_status.flags = 0;					\ 	  cc_status.value1 = SET_DEST (XVECEXP (EXP, 0, 0));	\ 	  cc_status.value2 = SET_SRC (XVECEXP (EXP, 0, 0));	\ 	}							\       else if (GET_CODE (SET_SRC (XVECEXP (EXP, 0, 0))) == CALL) \ 	{
comment|/* all bets are off */
value|CC_STATUS_INIT; }		\       else if (GET_CODE (SET_DEST (XVECEXP (EXP, 0, 0))) == REG) \ 	{ if (cc_status.value1					\&& reg_overlap_mentioned_p (SET_DEST (XVECEXP (EXP, 0, 0)), cc_status.value1)) \ 	    cc_status.value1 = 0;				\ 	  if (cc_status.value2					\&& reg_overlap_mentioned_p (SET_DEST (XVECEXP (EXP, 0, 0)), cc_status.value2)) \ 	    cc_status.value2 = 0;				\ 	}							\       else if (GET_CODE (SET_DEST (XVECEXP (EXP, 0, 0))) == MEM) \ 	{ rtx x = cc_status.mdep; int know = cc_status.flags& CC_KNOW_HI_G1;	\ 	  CC_STATUS_INIT;					\ 	  if (x&& know)					\ 	    { cc_status.mdep = x; cc_status.flags |= CC_KNOW_HI_G1; }		\ 	}							\     }								\   else if (GET_CODE (EXP) == PARALLEL)				\
comment|/* insn-peep has changed this insn beyond recognition      by NOTICE_UPDATE_CC.  However, we know it is either      a call or a branch with a delay slot filled, so we can      give up on knowing condition codes in any case.  */
value|\     { CC_STATUS_INIT; }						\   else if (GET_CODE (EXP) == CALL)				\     {
comment|/* all bets are off */
value|CC_STATUS_INIT; }			\ }
end_define

begin_define
define|#
directive|define
name|OUTPUT_JUMP
parameter_list|(
name|NORMAL
parameter_list|,
name|NO_OV
parameter_list|,
name|FLOAT
parameter_list|)
define|\
value|{ if (cc_prev_status.flags& CC_IN_FCCR)			\     return FLOAT;						\   if (cc_prev_status.flags& CC_NO_OVERFLOW)			\     return NO_OV;						\   return NORMAL; }
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* Output at beginning of assembler file.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|file
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
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"%g0", "%g1", "%g2", "%g3", "%g4", "%g5", "%g6", "%g7",		\  "%o0", "%o1", "%o2", "%o3", "%o4", "%o5", "%sp", "%o7",		\  "%l0", "%l1", "%l2", "%l3", "%l4", "%l5", "%l6", "%l7",		\  "%i0", "%i1", "%i2", "%i3", "%i4", "%i5", "%fp", "%i7",		\  "%f0", "%f1", "%f2", "%f3", "%f4", "%f5", "%f6", "%f7",		\  "%f8", "%f9", "%f10", "%f11", "%f12", "%f13", "%f14", "%f15",		\  "%f16", "%f17", "%f18", "%f19", "%f20", "%f21", "%f22", "%f23",	\  "%f24", "%f25", "%f26", "%f27", "%f28", "%f29", "%f30", "%f31"}
end_define

begin_comment
unit|\
comment|/* How to renumber registers for dbx and gdb.  */
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
comment|/* On Sun 4, this limit is 2048.  We use 1500 to be safe,    since the length can run past this up to a continuation point.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|1500
end_define

begin_comment
comment|/* This is how to output a note to DBX telling it the line number    to which the following sequence of instructions corresponds.     This is needed for SunOS 4.0, and should not hurt for 3.2    versions either.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|{ static int sym_lineno = 1;				\     fprintf (file, ".stabn 68,0,%d,LM%d\nLM%d:\n",	\ 	     line, sym_lineno, sym_lineno);		\     sym_lineno += 1; }
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
define|\
value|do { assemble_name (FILE, NAME); fputs (":\n", FILE); } while (0)
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
define|\
value|do { fputs (".global ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)
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
value|(isinf ((VALUE))							\    ? fprintf (FILE, "\t.double 0r%s99e999\n", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "\t.double 0r%.20e\n", (VALUE)))
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
value|(isinf ((VALUE))							\    ? fprintf (FILE, "\t.single 0r%s99e999\n", ((VALUE)> 0 ? "" : "-")) \    : fprintf (FILE, "\t.single 0r%.20e\n", (VALUE)))
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
value|( fprintf (FILE, "\t.word "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
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
value|( fprintf (FILE, "\t.half "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
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
value|( fprintf (FILE, "\t.byte "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
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
value|fprintf (FILE, "\t.byte 0x%x\n", (VALUE))
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.  */
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
value|fprintf (FILE, "\t.word L%d\n", VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    (SPARC does not use such vectors,    but we must define this macro anyway.)  */
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
value|fprintf (FILE, "\t.word L%d-L%d\n", VALUE, REL)
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
value|if ((LOG) != 0)			\     fprintf (FILE, "\t.align %d\n", (1<<(LOG)))
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
value|fprintf (FILE, "\t.skip %u\n", (SIZE))
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
value|( fputs (".global ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fputs ("\n.common ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u,\"bss\"\n", (ROUNDED)))
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
value|( fputs ("\n.reserve ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u,\"bss\"\n", (ROUNDED)))
end_define

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
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
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),	\   sprintf ((OUTPUT), "%s.%d", (NAME), (LABELNO)))
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
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    For `%' followed by punctuation, CODE is the punctuation and X is null.     On SPARC, the CODE can be `r', meaning this is a register-only operand    and an immediate zero should be represented as `r0'.    It can also be `m', meaning that X is a memory reference but print    its address as a non-memory operand.     Codes C, N, F, I, and U are used for printing the opcodes of conditional    branches.  C prints the opcode for a given condition; N the negated opcode.    F prints the negated floating point opcode (different because of nans).    I prints the opcode that ignores the overflow bit, and U its negation.  */
end_comment

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
value|{ if (GET_CODE (X) == REG)					\     fprintf (FILE, "%s", reg_names[REGNO (X)]);			\   else if ((CODE) == 'm')					\     output_address (XEXP (X, 0));				\   else if (GET_CODE (X) == MEM)					\     {								\       fputc ('[', FILE);					\       output_address (XEXP (X, 0));				\       fputc (']', FILE);					\     }								\   else if (GET_CODE (X) == CONST_DOUBLE)			\     abort ();							\   else if ((CODE) == 'r'&& (X) == const0_rtx)			\     fprintf (FILE, "%%g0");					\   else if ((CODE) == 'C') switch (GET_CODE (X))			\     {								\     case EQ: fputs ("e", FILE); break;				\     case NE: fputs ("ne", FILE); break;				\     case GT: fputs ("g", FILE); break;				\     case GE: fputs ("ge", FILE); break;				\     case LT: fputs ("l", FILE); break;				\     case LE: fputs ("le", FILE); break;				\     case GTU: fputs ("gu", FILE); break;			\     case GEU: fputs ("geu", FILE); break;			\     case LTU: fputs ("lu", FILE); break;			\     case LEU: fputs ("leu", FILE); break;			\     }								\   else if ((CODE) == 'I') switch (GET_CODE (X))			\     {								\     case EQ: fputs ("e", FILE); break;				\     case NE: fputs ("ne", FILE); break;				\     case GE: fputs ("pos", FILE); break;			\     case LT: fputs ("neg", FILE); break;			\     default:							\        abort ();						\     }								\   else if ((CODE) == 'U') switch (GET_CODE (X))			\     {								\     case EQ: fputs ("ne", FILE); break;				\     case NE: fputs ("e", FILE); break;				\     case GE: fputs ("neg", FILE); break;			\     case LT: fputs ("pos", FILE); break;			\     default:							\        abort ();						\     }								\   else if ((CODE) == 'N') switch (GET_CODE (X))			\     {								\     case EQ: fputs ("ne", FILE); break;				\     case NE: fputs ("e", FILE); break;				\     case GT: fputs ("le", FILE); break;				\     case GE: fputs ("l", FILE); break;				\     case LT: fputs ("ge", FILE); break;				\     case LE: fputs ("g", FILE); break;				\     case GTU: fputs ("leu", FILE); break;			\     case GEU: fputs ("lu", FILE); break;			\     case LTU: fputs ("geu", FILE); break;			\     case LEU: fputs ("gu", FILE); break;			\     }								\   else if ((CODE) == 'F') switch (GET_CODE (X))			\     {								\     case EQ: fputs ("ne", FILE); break;				\     case NE: fputs ("e", FILE); break;				\     case GT: fputs ("ule", FILE); break;			\     case GE: fputs ("ul", FILE); break;				\     case LT: fputs ("uge", FILE); break;			\     case LE: fputs ("ug", FILE); break;				\     default: abort ();						\     }								\   else { output_addr_const (FILE, X); }}
end_define

begin_escape
end_escape

begin_comment
comment|/* Print a memory address as an operand to reference that memory location.  */
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
value|{ register rtx base, index = 0;					\   int offset = 0;						\   register rtx addr = ADDR;					\   if (GET_CODE (addr) == REG)					\     {								\       fprintf (FILE, "%s", reg_names[REGNO (addr)]);		\     }								\   else if (GET_CODE (addr) == PLUS)				\     {								\       if (GET_CODE (XEXP (addr, 0)) == CONST_INT)		\ 	offset = INTVAL (XEXP (addr, 0)), base = XEXP (addr, 1);\       else if (GET_CODE (XEXP (addr, 1)) == CONST_INT)		\ 	offset = INTVAL (XEXP (addr, 1)), base = XEXP (addr, 0);\       else							\ 	base = XEXP (addr, 0), index = XEXP (addr, 1);		\       fprintf (FILE, "%s", reg_names[REGNO (base)]);		\       if (index == 0)						\ 	fprintf (FILE, "%+d", offset);				\       else							\ 	fprintf (FILE, "+%s", reg_names[REGNO (index)]);	\     }								\   else								\     {								\       output_addr_const (FILE, addr);				\     }								\ }
end_define

end_unit

