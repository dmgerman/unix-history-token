begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  NS32000 version.    Copyright (C) 1988 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@mcc.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Note that some other tm.h files include this one and then override    many of the definitions that relate to assembler syntax.  */
end_comment

begin_function_decl
specifier|extern
name|enum
name|reg_class
name|secondary_reload_class
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dns32000 -Dunix"
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (32000, GAS syntax)");
end_define

begin_escape
end_escape

begin_comment
comment|/* ABSOLUTE PREFIX, IMMEDIATE_PREFIX and EXTERNAL_PREFIX can be defined    to cover most NS32k addressing syntax variations.  This way we don't    need to redefine long macros in all the tm.h files for just slight    variations in assembler syntax. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ABSOLUTE_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|ABSOLUTE_PREFIX
value|'@'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IMMEDIATE_PREFIX
argument_list|)
operator|&&
name|IMMEDIATE_PREFIX
end_if

begin_define
define|#
directive|define
name|PUT_IMMEDIATE_PREFIX
parameter_list|(
name|FILE
parameter_list|)
value|putc(IMMEDIATE_PREFIX, FILE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PUT_IMMEDIATE_PREFIX
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ABSOLUTE_PREFIX
argument_list|)
operator|&&
name|ABSOLUTE_PREFIX
end_if

begin_define
define|#
directive|define
name|PUT_ABSOLUTE_PREFIX
parameter_list|(
name|FILE
parameter_list|)
value|putc(ABSOLUTE_PREFIX, FILE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PUT_ABSOLUTE_PREFIX
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXTERNAL_PREFIX
argument_list|)
operator|&&
name|EXTERNAL_PREFIX
end_if

begin_define
define|#
directive|define
name|PUT_EXTERNAL_PREFIX
parameter_list|(
name|FILE
parameter_list|)
value|putc(EXTERNAL_PREFIX, FILE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PUT_EXTERNAL_PREFIX
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Compile 32081 insns for floating point (not library calls). */
end_comment

begin_define
define|#
directive|define
name|TARGET_32081
value|(target_flags& 1)
end_define

begin_comment
comment|/* Compile using rtd insn calling sequence.    This will not work unless you use prototypes at least    for all functions that can take varying numbers of args.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_RTD
value|(target_flags& 2)
end_define

begin_comment
comment|/* Compile passing first two args in regs 0 and 1.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_REGPARM
value|(target_flags& 4)
end_define

begin_comment
comment|/* Options to select type of CPU, for better optimization.    The output is correct for any kind of 32000 regardless of these options.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_32532
value|(target_flags& 8)
end_define

begin_define
define|#
directive|define
name|TARGET_32332
value|(target_flags& 16)
end_define

begin_comment
comment|/* Ok to use the static base register (and presume it's 0) */
end_comment

begin_define
define|#
directive|define
name|TARGET_SB
value|((target_flags& 32) == 0)
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ { "32081", 1},				\     { "soft-float", -1},			\     { "rtd", 2},				\     { "nortd", -2},				\     { "regparm", 4},				\     { "noregparm", -4},				\     { "32532", 24},				\     { "32332", -16},				\     { "32332", 8},				\     { "32032", -24},				\     { "sb", -32},				\     { "nosb", 32},				\     { "", TARGET_DEFAULT}}
end_define

begin_comment
comment|/* TARGET_DEFAULT is defined in encore.h, pc532.h, etc.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.    This is not true on the ns32k.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_comment
comment|/* That is not true on the ns32k.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is lowest    numbered. This is not true on the ns32k.  */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Number of bits in an addressable storage unit */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_comment
comment|/* Width in bits of a "word", which is the contents of a machine register.    Note that this is not necessarily the width of data type `int';    if using 16-bit ints on a 32000, this would still be 32.    But on a machine with 16-bit registers, this would be 16.  */
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

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|16
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
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|32
end_define

begin_comment
comment|/* Set this nonzero if move instructions will actually fail to work    when given unaligned data.  National claims that the NS32032    works without strict alignment, but rumor has it that operands    crossing a page boundary cause unpredictable results.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_comment
comment|/* If bit field type is int, dont let it cross an int,    and give entire struct the alignment of an int.  */
end_comment

begin_comment
comment|/* Required on the 386 since it doesn't have a full set of bitfield insns.    (There is no signed extv insn.)  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|18
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the ns32k, these are the FP, SP, (SB and PC are not included here).  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
value|{0, 0, 0, 0, 0, 0, 0, 0, \ 			 0, 0, 0, 0, 0, 0, 0, 0, \ 			 1, 1}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
value|{1, 1, 1, 0, 0, 0, 0, 0, \ 			     1, 1, 1, 1, 0, 0, 0, 0, \ 			     1, 1}
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.    On the ns32k, all registers are 32 bits long.  */
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
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE. */
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
value|hard_regno_mode_ok (REGNO, MODE)
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
value|(((MODE1) == DFmode || (MODE1) == DCmode || (MODE1) == DImode) ==	\    ((MODE2) == DFmode || (MODE2) == DCmode || (MODE2) == DImode))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* NS32000 pc is not overloaded on a register.  */
end_comment

begin_comment
comment|/* #define PC_REGNUM */
end_comment

begin_comment
comment|/* Register to use for pushing function arguments. */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|17
end_define

begin_comment
comment|/* Base register for access to local variables of the function. */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|16
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|0
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|16
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|1
end_define

begin_comment
comment|/* Register in which address to store a structure value    is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|2
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|GENERAL_REGS
block|,
name|FLOAT_REGS
block|,
name|FRAME_POINTER_REG
block|,
name|STACK_POINTER_REG
block|,
name|GEN_AND_MEM_REGS
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
value|{"NO_REGS", "GENERAL_REGS", "FLOAT_REGS", "FRAME_POINTER_REG", "STACK_POINTER_REG", "GEN_AND_MEM_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
value|{0, 0x00ff, 0xff00, 0x10000, 0x20000, 0x300ff, 0x3ffff }
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
value|((REGNO)< 8 ? GENERAL_REGS          \    : (REGNO)< 16 ? FLOAT_REGS         \    : (REGNO) == 16 ? FRAME_POINTER_REG \    : (REGNO) == 17 ? STACK_POINTER_REG \    : NO_REGS)
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
value|GEN_AND_MEM_REGS
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
value|((C) == 'f' ? FLOAT_REGS		\   : (C) == 'x' ? FRAME_POINTER_REG	\   : (C) == 'y' ? STACK_POINTER_REG      \   : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     On the ns32k, these letters are used as follows:     I : Matches integers which are valid shift amounts for scaled indexing.        These are 0, 1, 2, 3 for byte, word, double, and quadword.        Used for matching arithmetic shifts only on 32032& 32332.    J : Matches integers which fit a "quick" operand.    K : Matches integers 0 to 7 (for inss and exts instructions).   */
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
define|\
value|((VALUE)< 8&& (VALUE) + 8>= 0 ?		\    ((C) == 'I' ? (!TARGET_32532&& 0<= (VALUE)&& (VALUE)<= 3) : \     (C) == 'J' ? (VALUE)<= 7 :			\     (C) == 'K' ? 0<= (VALUE) : 0) : 0)
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
value|1
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.  */
end_comment

begin_comment
comment|/* We return GENERAL_REGS instead of GEN_AND_MEM_REGS.    The latter offers no real additional possibilities    and can cause spurious secondary reloading.  */
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
define|\
value|((CLASS) == GEN_AND_MEM_REGS ? GENERAL_REGS : (CLASS))
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On the 32000, this is the size of MODE in words */
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
value|0
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On the 32000, sp@- in a byte insn really pushes a BYTE.  */
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
comment|/* Value is the number of byte of arguments automatically    popped when returning from a subroutine call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.     On the 32000, the RET insn may be used to pop them if the number      of args is fixed, but if the number is variable then the caller      must pop them all.  RET can't be used for library calls now      because the library is compiled with the Unix compiler.    Use of RET is a selectable option, since it is incompatible with    standard Unix calling sequences.  If the option is not selected,    the caller must always pop the args.  */
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
value|((TARGET_RTD&& TREE_CODE (FUNTYPE) != IDENTIFIER_NODE	\&& (TYPE_ARG_TYPES (FUNTYPE) == 0				\ 	|| (TREE_VALUE (tree_last (TYPE_ARG_TYPES (FUNTYPE)))	\ 	    == void_type_node)))				\    ? (SIZE) : 0)
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_comment
comment|/* On the 32000 the return value is in R0,    or perhaps in F0 is there is fp support.  */
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
value|(TREE_CODE (VALTYPE) == REAL_TYPE&& TARGET_32081 \    ? gen_rtx (REG, TYPE_MODE (VALTYPE), 8) \    : gen_rtx (REG, TYPE_MODE (VALTYPE), 0))
end_define

begin_comment
comment|/* Define how to find the value returned by a library function    assuming the value has mode MODE.  */
end_comment

begin_comment
comment|/* On the 32000 the return value is in R0,    or perhaps F0 is there is fp support.  */
end_comment

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(((MODE) == DFmode || (MODE) == SFmode)&& TARGET_32081 \    ? gen_rtx (REG, MODE, 8) \    : gen_rtx (REG, MODE, 0))
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
comment|/* 1 if N is a possible register number for a function value.    On the 32000, R0 and F0 are the only registers thus used.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|(((N)& ~8) == 0)
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On the 32000, no registers are used in this way.  */
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
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the ns32k, this is a single integer, which is a number of bytes    of arguments scanned so far.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.     On the ns32k, the offset starts at 0.  */
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
comment|/* On the 32000 all args are pushed, except if -mregparm is specified    then the first two words of arguments are passed in r0, r1.    *NOTE* -mregparm does not work.    It exists only to test register calling conventions.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|MAIN_FUNCTION_PROLOGUE
end_ifndef

begin_define
define|#
directive|define
name|MAIN_FUNCTION_PROLOGUE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The function prologue for the ns32k is fairly simple.  * If a frame pointer is needed (decided in reload.c ?) then  * we need assembler of the form  *  *  # Save the oldframe pointer, set the new frame pointer, make space  *  # on the stack and save any general purpose registers necessary  *  *  enter [<general purpose regs to save>],<local stack space>  *  *  movf  fn, tos    # Save any floating point registers necessary  *  .  *  .  *  * If a frame pointer is not needed we need assembler of the form  *  # Save any general purpose registers necessary  *  *  save [<general purpose regs to save>]  *  *  movf  fn, tos    # Save any floating point registers necessary  *  .  *  .  */
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
value|{ register int regno, g_regs_used = 0;				\   int used_regs_buf[8], *bufp = used_regs_buf;			\   int used_fregs_buf[8], *fbufp = used_fregs_buf;		\   extern char call_used_regs[];					\   MAIN_FUNCTION_PROLOGUE;					\   for (regno = 0; regno< 8; regno++)				\     if (regs_ever_live[regno]					\&& ! call_used_regs[regno])				\     {								\       *bufp++ = regno; g_regs_used++;				\     }								\   *bufp = -1;							\   for (; regno< 16; regno++)					\     if (regs_ever_live[regno]&& !call_used_regs[regno]) {	\       *fbufp++ = regno;						\     }								\   *fbufp = -1;							\   bufp = used_regs_buf;						\   if (frame_pointer_needed)					\     fprintf (FILE, "\tenter [");				\   else if (g_regs_used)						\     fprintf (FILE, "\tsave [");					\   while (*bufp>= 0)						\     {								\       fprintf (FILE, "r%d", *bufp++);				\       if (*bufp>= 0)						\ 	fputc (',', FILE);					\     }								\   if (frame_pointer_needed)					\     fprintf (FILE, "],%d\n", SIZE);				\   else if (g_regs_used)						\     fprintf (FILE, "]\n");					\   fbufp = used_fregs_buf;					\   while (*fbufp>= 0)						\     {								\       if ((*fbufp& 1) || (fbufp[0] != fbufp[1] - 1))		\ 	fprintf (FILE, "\tmovf f%d,tos\n", *fbufp++ - 8);	\       else							\ 	{							\ 	  fprintf (FILE, "\tmovl f%d,tos\n", fbufp[0] - 8);	\ 	  fbufp += 2;						\ 	}							\     }								\ }
end_define

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.     THIS DEFINITION FOR THE 32000 IS A GUESS.  IT HAS NOT BEEN TESTED.  */
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
value|fprintf (FILE, "\taddr LP%d,r0\n\tbsr mcount\n", (LABELNO))
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.     We use 0, because using 1 requires hair in FUNCTION_EPILOGUE    that is worse than the stack adjust we could save.  */
end_comment

begin_comment
comment|/* #define EXIT_IGNORE_STACK 1 */
end_comment

begin_comment
comment|/* This macro generates the assembly code for function exit,    on machines that need it.  If FUNCTION_EPILOGUE is not defined    then individual return instructions are generated for each    return statement.  Args are same as for FUNCTION_PROLOGUE.     The function epilogue should not depend on the current stack pointer,    if EXIT_IGNORE_STACK is nonzero.  That doesn't apply here.     If a frame pointer is needed (decided in reload.c ?) then    we need assembler of the form      movf  tos, fn	# Restore any saved floating point registers     .     .      # Restore any saved general purpose registers, restore the stack     # pointer from the frame pointer, restore the old frame pointer.     exit [<general purpose regs to save>]     If a frame pointer is not needed we need assembler of the form     # Restore any general purpose registers saved      movf  tos, fn	# Restore any saved floating point registers     .     .     .     restore [<general purpose regs to save>]  */
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
value|{ register int regno, g_regs_used = 0, f_regs_used = 0;		\   int used_regs_buf[8], *bufp = used_regs_buf;			\   int used_fregs_buf[8], *fbufp = used_fregs_buf;		\   extern char call_used_regs[];					\   *fbufp++ = -2;						\   for (regno = 8; regno< 16; regno++)				\     if (regs_ever_live[regno]&& !call_used_regs[regno]) {	\        *fbufp++ = regno; f_regs_used++;				\     }								\   fbufp--;							\   for (regno = 0; regno< 8; regno++)				\     if (regs_ever_live[regno]					\&& ! call_used_regs[regno])				\     {                                                         	\       *bufp++ = regno; g_regs_used++;				\     }                                                         	\   while (fbufp> used_fregs_buf)				\     {								\       if ((*fbufp& 1)&& fbufp[0] == fbufp[-1] + 1)		\ 	{							\ 	  fprintf (FILE, "\tmovl tos,f%d\n", fbufp[-1] - 8);	\ 	  fbufp -= 2;						\ 	}							\       else fprintf (FILE, "\tmovf tos,f%d\n", *fbufp-- - 8);	\     }								\   if (frame_pointer_needed)					\     fprintf (FILE, "\texit [");					\   else if (g_regs_used)						\     fprintf (FILE, "\trestore [");				\   while (bufp> used_regs_buf)					\     {								\       fprintf (FILE, "r%d", *--bufp);				\       if (bufp> used_regs_buf)					\ 	fputc (',', FILE);					\     }								\   if (g_regs_used || frame_pointer_needed)			\     fprintf (FILE, "]\n");					\   if (current_function_pops_args)				\     fprintf (FILE, "\tret %d\n", current_function_pops_args);	\   else fprintf (FILE, "\tret 0\n"); }
end_define

begin_comment
comment|/* Store in the variable DEPTH the initial difference between the    frame pointer reg contents and the stack pointer reg contents,    as of the start of the function body.  This depends on the layout    of the fixed parts of the stack frame and on how registers are saved.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_FRAME_POINTER_OFFSET
parameter_list|(
name|DEPTH
parameter_list|)
define|\
value|{								\   int regno;							\   int offset = -4;						\   for (regno = 0; regno< 16; regno++)				\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       offset += 4;						\   (DEPTH) = offset - get_frame_size ();				\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.  */
end_comment

begin_comment
comment|/* On the 32k, the trampoline looks like this:      addr  .,r2      jump  @__trampoline      .int STATIC      .int FUNCTION Doing trampolines with a library assist function is easier than figuring out how to do stores to memory in reverse byte order (the way immediate operands on the 32k are stored).  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{									\   fprintf (FILE, "\taddr .,r2\n" );					\   fprintf (FILE, "\tjump " );						\   PUT_ABSOLUTE_PREFIX (FILE);						\   fprintf (FILE, "__trampoline\n" );					\   ASM_OUTPUT_INT (FILE, const0_rtx);					\   ASM_OUTPUT_INT (FILE, const0_rtx);					\ }
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|20
end_define

begin_comment
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|TRAMP
parameter_list|,
name|FNADDR
parameter_list|,
name|CXT
parameter_list|)
define|\
value|{									     \   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 12)), CXT);    \   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 16)), FNADDR); \ }
end_define

begin_comment
comment|/* This is the library routine that is used    to transfer control from the trampoline    to the actual nested function.  */
end_comment

begin_comment
comment|/* The function name __transfer_from_trampoline is not actually used.    The function definition just permits use of "asm with operands"    (though the operand list is empty).  */
end_comment

begin_define
define|#
directive|define
name|TRANSFER_FROM_TRAMPOLINE
define|\
value|void					\ __transfer_from_trampoline ()		\ {					\   asm ("___trampoline:");		\   asm ("movd 16(r2),tos");		\   asm ("movd 12(r2),r2");		\   asm ("ret 0");			\ }
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
comment|/* note that FP and SP cannot be used as an index. What about PC? */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 8 || (unsigned)reg_renumber[REGNO]< 8)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 8 || (unsigned)reg_renumber[REGNO]< 8 \  || (REGNO) == FRAME_POINTER_REGNUM || (REGNO) == STACK_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|FP_REG_P
parameter_list|(
name|X
parameter_list|)
value|(GET_CODE (X) == REG&& REGNO (X)> 7&& REGNO (X)< 16)
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
comment|/* Recognize any constant value that is a valid address.    This might not work on future ns32k processors as negative    displacements are not officially allowed but a mode reserved    to National.  This works on processors up to 32532, though. */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == LABEL_REF || GET_CODE (X) == SYMBOL_REF		\    || GET_CODE (X) == CONST						\    || (GET_CODE (X) == CONST_INT					\&& ((unsigned)INTVAL (X)>= 0xe0000000				\ 	   || (unsigned)INTVAL (X)< 0x20000000)))
end_define

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_NO_LABEL_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == CONST_INT						\&& ((unsigned)INTVAL (X)>= 0xe0000000				\        || (unsigned)INTVAL (X)< 0x20000000))
end_define

begin_comment
comment|/* Return the register class of a scratch register needed to copy IN into    or out of a register in CLASS in MODE.  If it can be done directly,    NO_REGS is returned.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|IN
parameter_list|)
define|\
value|secondary_reload_class (CLASS, MODE, IN)
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
define|\
value|(REGNO (X)< 8 || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as a base reg    of if it is a pseudo reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|(REGNO (X)< 8 || REGNO (X)>= FRAME_POINTER_REGNUM)
end_define

begin_comment
comment|/* Nonzero if X is a floating point reg or a pseudo reg.  */
end_comment

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
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     The other macros defined here are used only in GO_IF_LEGITIMATE_ADDRESS.  */
end_comment

begin_comment
comment|/* 1 if X is an address that we could indirect through.  */
end_comment

begin_comment
comment|/***** NOTE ***** There is a bug in the Sequent assembler which fails  to fixup addressing information for symbols used as offsets  from registers which are not FP or SP (or SB or PC).  This  makes _x(fp) valid, while _x(r0) is invalid.  */
end_comment

begin_define
define|#
directive|define
name|INDIRECTABLE_1_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(CONSTANT_ADDRESS_P (X)						\    || (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))			\    || (GET_CODE (X) == PLUS						\&& GET_CODE (XEXP (X, 0)) == REG					\&& REG_OK_FOR_BASE_P (XEXP (X, 0))				\&& CONSTANT_ADDRESS_P (XEXP (X, 1))				\&& (GET_CODE (X) != CONST_INT || NS32K_DISPLACEMENT_P (INTVAL (X)))))
end_define

begin_comment
comment|/* 1 if integer I will fit in a 4 byte displacement field.    Strictly speaking, we can't be sure that a symbol will fit this range.    But, in practice, it always will.  */
end_comment

begin_comment
comment|/* idall@eleceng.adelaide.edu.au says that the 32016 and 32032    can handle the full range of displacements--it is only the addresses    that have a limited range.  So the following was deleted:  (((i)<= 16777215&& (i)>= -16777216)   || ((TARGET_32532 || TARGET_32332)&& ...))  */
end_comment

begin_define
define|#
directive|define
name|NS32K_DISPLACEMENT_P
parameter_list|(
name|i
parameter_list|)
define|\
value|((i)< (1<< 29)&& (i)>= - (1<< 29))
end_define

begin_comment
comment|/* Check for frame pointer or stack pointer.  */
end_comment

begin_define
define|#
directive|define
name|MEM_REG
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& (REGNO (X) ^ 16)< 2)
end_define

begin_comment
comment|/* A memory ref whose address is the FP or SP, with optional integer offset,    or (on certain machines) a constant address.  */
end_comment

begin_define
define|#
directive|define
name|INDIRECTABLE_2_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == MEM							\&& (((xfoo0 = XEXP (X, 0), MEM_REG (xfoo0))				\        || (GET_CODE (xfoo0) == PLUS					\&& MEM_REG (XEXP (xfoo0, 0))					\&& CONSTANT_ADDRESS_NO_LABEL_P (XEXP (xfoo0, 1))))		\        || (TARGET_SB&& CONSTANT_ADDRESS_P (xfoo0))))
end_define

begin_comment
comment|/* Go to ADDR if X is a valid address not using indexing.    (This much is the easy part.)  */
end_comment

begin_define
define|#
directive|define
name|GO_IF_NONINDEXED_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ register rtx xfoob = (X);						\   if (INDIRECTABLE_1_ADDRESS_P (X)) goto ADDR;				\   if (INDIRECTABLE_2_ADDRESS_P (X)) goto ADDR;				\   if (GET_CODE (X) == PLUS)						\     if (CONSTANT_ADDRESS_NO_LABEL_P (XEXP (X, 1)))			\       if (INDIRECTABLE_2_ADDRESS_P (XEXP (X, 0)))			\ 	goto ADDR;							\ }
end_define

begin_comment
comment|/* Go to ADDR if X is a valid address not using indexing.    (This much is the easy part.)  */
end_comment

begin_define
define|#
directive|define
name|GO_IF_INDEXING
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ register rtx xfoob = (X);						\   if (GET_CODE (xfoob) == PLUS&& INDEX_TERM_P (XEXP (xfoob, 0), MODE))	\     GO_IF_INDEXABLE_ADDRESS (XEXP (xfoob, 1), ADDR);			\   if (GET_CODE (xfoob) == PLUS&& INDEX_TERM_P (XEXP (xfoob, 1), MODE))	\     GO_IF_INDEXABLE_ADDRESS (XEXP (xfoob, 0), ADDR); }			\  #define GO_IF_INDEXABLE_ADDRESS(X, ADDR) \ { if (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X)) goto ADDR;		\   if (INDIRECTABLE_2_ADDRESS_P (X)) goto ADDR;				\ }
end_define

begin_comment
comment|/* 1 if PROD is either a reg times size of mode MODE    or just a reg, if MODE is just one byte. Actually, on the ns32k,    since the index mode is independent of the operand size,    we can match more stuff...     This macro's expansion uses the temporary variables xfoo0, xfoo1    and xfoo2 that must be declared in the surrounding context.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_TERM_P
parameter_list|(
name|PROD
parameter_list|,
name|MODE
parameter_list|)
define|\
value|((GET_CODE (PROD) == REG&& REG_OK_FOR_INDEX_P (PROD))			\  || (GET_CODE (PROD) == MULT						\&&	(xfoo0 = XEXP (PROD, 0), xfoo1 = XEXP (PROD, 1),		\ 	 (GET_CODE (xfoo1) == CONST_INT					\&& GET_CODE (xfoo0) == REG					\&& FITS_INDEX_RANGE (INTVAL (xfoo1))				\&& REG_OK_FOR_INDEX_P (xfoo0)))))
end_define

begin_define
define|#
directive|define
name|FITS_INDEX_RANGE
parameter_list|(
name|X
parameter_list|)
define|\
value|((xfoo2 = (unsigned)(X)-1),						\    ((xfoo2< 4&& xfoo2 != 2) || xfoo2 == 7))
end_define

begin_comment
comment|/* Note that xfoo0, xfoo1, xfoo2 are used in some of the submacros above.  */
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
value|{ register rtx xfooy, xfoo0, xfoo1;					\   unsigned xfoo2;							\   xfooy = X;								\   GO_IF_NONINDEXED_ADDRESS (xfooy, ADDR);				\   if (GET_CODE (xfooy) == PLUS)						\     {									\       if (CONSTANT_ADDRESS_NO_LABEL_P (XEXP (xfooy, 1))			\&& GET_CODE (XEXP (xfooy, 0)) == PLUS)			\ 	xfooy = XEXP (xfooy, 0);					\       else if (CONSTANT_ADDRESS_NO_LABEL_P (XEXP (xfooy, 0))		\&& GET_CODE (XEXP (xfooy, 1)) == PLUS)			\ 	xfooy = XEXP (xfooy, 1);					\       GO_IF_INDEXING (xfooy, MODE, ADDR);				\     }									\   else if (INDEX_TERM_P (xfooy, MODE))					\     goto ADDR;								\   else if (GET_CODE (xfooy) == PRE_DEC)					\     if (REGNO (XEXP (xfooy, 0)) == STACK_POINTER_REGNUM) goto ADDR;	\   else abort ();							\ }
end_define

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     For the ns32k, we do nothing */
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
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the ns32k, only predecrement and postincrement address depend thus    (the amount of decrement or increment being the length of the operand).  */
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
value|{ if (GET_CODE (ADDR) == POST_INC || GET_CODE (ADDR) == PRE_DEC)	\      goto LABEL;}
end_define

begin_escape
end_escape

begin_comment
comment|/* Specify the machine mode that this machine uses    for the index in the tablejump instruction.    Can do SImode, but HI mode is more efficient. */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|HImode
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

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
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
value|QImode
end_define

begin_comment
comment|/* Compute the cost of address ADDRESS. */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|RTX
parameter_list|)
value|calc_address_cost (RTX)
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
value|case CONST_INT:						\     if (INTVAL (RTX)<= 7&& INTVAL (RTX)>= -8) return 0;	\     if (INTVAL (RTX)< 0x4000&& INTVAL (RTX)>= -0x4000)	\       return 1;							\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 3;							\   case CONST_DOUBLE:						\     return 5;
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
comment|/* This bit means that what ought to be in the Z bit    should be tested in the F bit.  */
end_comment

begin_define
define|#
directive|define
name|CC_Z_IN_F
value|04000
end_define

begin_comment
comment|/* This bit means that what ought to be in the Z bit    is complemented in the F bit.  */
end_comment

begin_define
define|#
directive|define
name|CC_Z_IN_NOT_F
value|010000
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
value|{ if (GET_CODE (EXP) == SET)					\     { if (GET_CODE (SET_DEST (EXP)) == CC0)			\ 	{ cc_status.flags = 0;					\ 	  cc_status.value1 = SET_DEST (EXP);			\ 	  cc_status.value2 = SET_SRC (EXP);			\ 	}							\       else if (GET_CODE (SET_SRC (EXP)) == CALL)		\ 	{ CC_STATUS_INIT; }					\       else if (GET_CODE (SET_DEST (EXP)) == REG)		\ 	{ if (cc_status.value1					\&& reg_overlap_mentioned_p (SET_DEST (EXP), cc_status.value1)) \ 	    cc_status.value1 = 0;				\ 	  if (cc_status.value2					\&& reg_overlap_mentioned_p (SET_DEST (EXP), cc_status.value2)) \ 	    cc_status.value2 = 0;				\ 	}							\       else if (GET_CODE (SET_DEST (EXP)) == MEM)		\ 	{ CC_STATUS_INIT; }					\     }								\   else if (GET_CODE (EXP) == PARALLEL				\&& GET_CODE (XVECEXP (EXP, 0, 0)) == SET)		\     { if (GET_CODE (SET_DEST (XVECEXP (EXP, 0, 0))) == CC0)	\ 	{ cc_status.flags = 0;					\ 	  cc_status.value1 = SET_DEST (XVECEXP (EXP, 0, 0));	\ 	  cc_status.value2 = SET_SRC (XVECEXP (EXP, 0, 0));	\ 	}							\       else if (GET_CODE (SET_DEST (XVECEXP (EXP, 0, 0))) == REG) \ 	{ if (cc_status.value1					\&& reg_overlap_mentioned_p (SET_DEST (XVECEXP (EXP, 0, 0)), cc_status.value1)) \ 	    cc_status.value1 = 0;				\ 	  if (cc_status.value2					\&& reg_overlap_mentioned_p (SET_DEST (XVECEXP (EXP, 0, 0)), cc_status.value2)) \ 	    cc_status.value2 = 0;				\ 	}							\       else if (GET_CODE (SET_DEST (XVECEXP (EXP, 0, 0))) == MEM) \ 	{ CC_STATUS_INIT; }					\     }								\   else if (GET_CODE (EXP) == CALL)				\     {
comment|/* all bets are off */
value|CC_STATUS_INIT; }			\   else {
comment|/* nothing happens? CC_STATUS_INIT; */
value|}		\   if (cc_status.value1&& GET_CODE (cc_status.value1) == REG	\&& cc_status.value2					\&& reg_overlap_mentioned_p (cc_status.value1, cc_status.value2))	\     abort ();			\ }
end_define

begin_comment
comment|/* Describe the costs of the following register moves which are discouraged:    1.) Moves between the Floating point registers and the frame pointer and stack pointer    2.) Moves between the stack pointer and the frame pointer    3.) Moves between the floating point and general registers */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|CLASS1
parameter_list|,
name|CLASS2
parameter_list|)
define|\
value|((((CLASS1) == FLOAT_REGS&& ((CLASS2) == STACK_POINTER_REG || (CLASS2) == FRAME_POINTER_REG))    \    || ((CLASS2) == FLOAT_REGS&& ((CLASS1) == STACK_POINTER_REG || (CLASS1) == FRAME_POINTER_REG))  \    || ((CLASS1) == STACK_POINTER_REG&& (CLASS2) == FRAME_POINTER_REG)                              \    || ((CLASS2) == STACK_POINTER_REG&& (CLASS1) == FRAME_POINTER_REG)                              \    || ((CLASS1) == FLOAT_REGS&& (CLASS2) == GENERAL_REGS)                                          \    || ((CLASS1) == GENERAL_REGS&& (CLASS2) == FLOAT_REGS))                                         \  ? 4  : 2)
end_define

begin_define
define|#
directive|define
name|OUTPUT_JUMP
parameter_list|(
name|NORMAL
parameter_list|,
name|NO_OV
parameter_list|)
define|\
value|{ if (cc_status.flags& CC_NO_OVERFLOW)				\     return NO_OV;						\   return NORMAL; }
end_define

begin_escape
end_escape

begin_comment
comment|/* Dividing the output into sections */
end_comment

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
comment|/* Define the output Assembly Language */
end_comment

begin_comment
comment|/* Output at beginning of assembler file.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
value|fprintf (FILE, "#NO_APP\n");
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    may contain character constants, extra white space, comments, etc.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_comment
comment|/* Output to assembler file text saying following lines    no longer contain unusual constructs.  */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_comment
comment|/* Output of Data */
end_comment

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
value|fprintf (FILE, "\t.double 0d%.20e\n", (VALUE))
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
value|fprintf (FILE, "\t.float 0f%.20e\n", (VALUE))
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
value|( fprintf (FILE, "\t.long "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
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
value|( fprintf (FILE, "\t.word "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
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
comment|/* This is how to output an assembler line defining an external/static    address which is not in tree format (for collect.c).  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF_AS_INT
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   fprintf (STREAM, "\t.long\t");					\   ASM_OUTPUT_LABELREF (STREAM, NAME);					\   fprintf (STREAM, "\n");						\ } while (0)
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
value|fprintf (FILE, "\tmovd %s,tos\n", reg_names[REGNO])
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
value|fprintf (FILE, "\tmovd tos,%s\n", reg_names[REGNO])
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", \  "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", \  "fp", "sp"}
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb.    NS32000 may need more change in the numeration.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO< 8) ? (REGNO)+4 : (REGNO))
end_define

begin_comment
comment|/* This is how to output the definition of a user-level label named NAME,    such as the label on a static function or variable NAME.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COLLECT
end_ifndef

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

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   fprintf (STREAM, "%s:\n", NAME);					\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|COLLECT
end_ifndef

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
value|do { fputs (".globl ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\   fprintf (STREAM, "\t.globl\t%s\n", NAME);				\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* This is how to align the code that follows an unconditional branch.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN_CODE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf (FILE, "\t.align 2\n")
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.    (The ns32k does not use such vectors,    but we must define this macro anyway.)  */
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
value|fprintf (FILE, "\t.long L%d\n", VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.  */
end_comment

begin_comment
comment|/* ** Notice that the second element is LI format! */
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
value|fprintf (FILE, "\t.word L%d-LI%d\n", VALUE, REL)
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
value|fprintf (FILE, "\t.align %d\n", (LOG))
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
value|fprintf (FILE, "\t.space %u\n", (SIZE))
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
value|( fputs (".comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
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
value|( fputs (".lcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
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
comment|/* Print an instruction operand X on file FILE.    CODE is the code from the %-spec that requested printing this operand;    if `%z3' was used to print operand 3, then CODE is 'z'. */
end_comment

begin_comment
comment|/* %$ means print the prefix for an immediate operand.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '$' || (CODE) == '?')
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
value|print_operand(FILE, X, CODE)
end_define

begin_comment
comment|/* Print a memory operand whose address is X, on file FILE.  */
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
value|print_operand_address(FILE, ADDR)
end_define

begin_comment
comment|/* Define functions in ns32k.c and used in insn-output.c.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_move_double
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_shift_insn
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Local variables: version-control: t End: */
end_comment

end_unit

