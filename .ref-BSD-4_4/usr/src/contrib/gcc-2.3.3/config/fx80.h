begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Alliant FX version.    Copyright (C) 1989 Free Software Foundation, Inc.    Adapted from m68k.h by Paul Petersen (petersen@uicsrd.csrd.uiuc.edu)    and Joe Weening (weening@gang-of-four.stanford.edu).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This file is based on m68k.h, simplified by removing support for    the Sun FPA and other things not applicable to the Alliant.  Some    remnants of these features remain.  */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmc68000 -Dalliant -Dunix"
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (Alliant)");
end_define

begin_comment
comment|/* Run-time compilation parameters selecting different hardware    subsets.  The Alliant IP is an mc68020.  (Older mc68010-based IPs    are no longer supported.)  The Alliant CE is 68020-compatible, and    also has floating point, vector and concurrency instructions.     Although the IP doesn't have floating point, it emulates it in the    operating system.  Using this generally is faster than running code    compiled with -msoft-float, because the soft-float code still uses    (simulated) FP registers and ends up emulating several fmove{s,d}    instructions per call.  So I don't recommend using soft-float for    any Alliant code.  -- JSW */
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
comment|/* Compile for a 68020 (not a 68000 or 68010).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_68020
value|(target_flags& 1)
end_define

begin_comment
comment|/* Compile CE insns for floating point (not library calls).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CE
value|(target_flags& 2)
end_define

begin_comment
comment|/* Compile using 68020 bitfield insns.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BITFIELD
value|(target_flags& 4)
end_define

begin_comment
comment|/* Compile with 16-bit `int'.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SHORT
value|(target_flags& 040)
end_define

begin_comment
comment|/* Default 3 means compile 68020 and CE instructions.  We don't use    bitfield instructions because there appears to be a bug in the    implementation of bfins on the CE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|3
end_define

begin_comment
comment|/* Define __HAVE_CE__ in preprocessor according to the -m flags.    This will control the use of inline FP insns in certain macros.    Also inform the program which CPU this is for.  */
end_comment

begin_if
if|#
directive|if
name|TARGET_DEFAULT
operator|&
literal|02
end_if

begin_comment
comment|/* -mce is the default */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{!msoft-float:-D__HAVE_CE__ }\ %{m68000:-Dmc68010}%{mc68000:-Dmc68010}%{!mc68000:%{!m68000:-Dmc68020}}"
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* -msoft-float is the default */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
define|\
value|"%{mce:-D__HAVE_CE__ }\ %{m68000:-Dmc68010}%{mc68000:-Dmc68010}%{!mc68000:%{!m68000:-Dmc68020}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Link with libg.a when debugging, for dbx's sake.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{g:-lg} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} "
end_define

begin_comment
comment|/* Make the linker remove temporary labels, since the Alliant assembler    doesn't.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-X"
end_define

begin_comment
comment|/* Every structure or union's size must be a multiple of 2 bytes.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|16
end_define

begin_comment
comment|/* This is BSD, so it wants DBX format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ { "68020", 5},				\     { "c68020", 5},				\     { "bitfield", 4},				\     { "68000", -7},				\     { "c68000", -7},				\     { "soft-float", -2},			\     { "nobitfield", -4},			\     { "short", 040},				\     { "noshort", -040},				\     { "", TARGET_DEFAULT}}
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.    This is true for 68020 insns such as bfins and bfexts.    We make it true always by avoiding using the single-bit insns    except in special cases with constant bit numbers.  */
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
comment|/* That is true on the 68000.  */
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
comment|/* For 68000 we can decide arbitrarily    since there are no machine instructions for them.  */
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
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|(TARGET_SHORT ? 16 : 32)
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|16
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
value|16
end_define

begin_comment
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|16
end_define

begin_comment
comment|/* Set this non-zero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_comment
comment|/* Define number of bits in most basic integer type.    (If undefined, default is BITS_PER_WORD).  */
end_comment

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|(TARGET_SHORT ? 16 : 32)
end_define

begin_comment
comment|/* Define these to avoid dependence on meaning of `int'.    Note that WCHAR_TYPE_SIZE is used in cexp.y,    where TARGET_SHORT is not available.  */
end_comment

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"long int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.    For the Alliant, we give the data registers numbers 0-7,    the address registers numbers 010-017,    and the floating point registers numbers 020-027.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|24
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the Alliant, these are a0 (argument pointer),    a6 (frame pointer) and a7 (stack pointer).  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 0, 0, 0, 0, 0, 0, 0, \   1, 0, 0, 0, 0, 0, 1, 1, \   0, 0, 0, 0, 0, 0, 0, 0  }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.    The Alliant calling sequence allows a function to use any register,    so we include them all here.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1  }
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On the Alliant, ordinary registers hold 32 bits worth;    for the FP registers, a single register is always enough for    any floating-point value.  */
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
value|((REGNO)>= 16 ? GET_MODE_NUNITS (MODE)	\    : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On the Alliant, the cpu registers can hold any mode but the FP registers    can hold only floating point.  */
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
value|((REGNO)< 16 || GET_MODE_CLASS (MODE) == MODE_FLOAT	\    || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT)
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
value|(((MODE1) == SFmode || (MODE1) == DFmode		\      || (MODE1) == SCmode || (MODE1) == DCmode)		\        == ((MODE2) == SFmode || (MODE2) == DFmode	\ 	   || (MODE2) == SCmode || (MODE2) == DCmode))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* m68000 pc isn't overloaded on a register.  */
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
value|15
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|14
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
end_comment

begin_comment
comment|/* Set for now on Alliant until we find a way to make this work with    their calling sequence.  */
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
value|8
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|10
end_define

begin_comment
comment|/* Register in which address to store a structure value    is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|9
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_comment
comment|/* The Alliant has three kinds of registers, so eight classes would be    a complete set.  One of them is not needed.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|FP_REGS
block|,
name|DATA_REGS
block|,
name|DATA_OR_FP_REGS
block|,
name|ADDR_REGS
block|,
name|GENERAL_REGS
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
value|{ "NO_REGS", "FP_REGS", "DATA_REGS", "DATA_OR_FP_REGS",  \    "ADDR_REGS", "GENERAL_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{					\  0,
comment|/* NO_REGS */
value|\  0x00ff0000,
comment|/* FP_REGS */
value|\  0x000000ff,
comment|/* DATA_REGS */
value|\  0x00ff00ff,
comment|/* DATA_OR_FP_REGS */
value|\  0x0000ff00,
comment|/* ADDR_REGS */
value|\  0x0000ffff,
comment|/* GENERAL_REGS */
value|\  0x00ffffff
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
value|(regno_reg_class[(REGNO)>>3])
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
value|ADDR_REGS
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
value|((C) == 'a' ? ADDR_REGS :			\    ((C) == 'd' ? DATA_REGS :			\     ((C) == 'f' ? FP_REGS :			\      NO_REGS)))
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     For the 68000, `I' is used for the range 1 to 8    allowed as immediate shift counts and in addq.    `J' is used for the range of signed numbers that fit in 16 bits.    `K' is for numbers that moveq can't handle.    `L' is for range -8 to -1, range of values that can be added with subq.  */
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
value|((C) == 'I' ? (VALUE)> 0&& (VALUE)<= 8 :    \    (C) == 'J' ? (VALUE)>= -0x8000&& (VALUE)<= 0x7FFF :	\    (C) == 'K' ? (VALUE)< -0x80 || (VALUE)>= 0x80 :	\    (C) == 'L' ? (VALUE)< 0&& (VALUE)>= -8 : 0)
end_define

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_LETTER_P
parameter_list|(
name|VALUE
parameter_list|,
name|C
parameter_list|)
value|0
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.    On the 68000 series, use a data reg if possible when the    value is a constant in the range where moveq could be used    and we ensure that QImodes are reloaded into data regs.  */
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
value|((GET_CODE (X) == CONST_INT			\&& (unsigned) (INTVAL (X) + 0x80)< 0x100	\&& (CLASS) != ADDR_REGS)			\    ? DATA_REGS					\    : GET_MODE (X) == QImode			\    ? DATA_REGS					\    : (CLASS))
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On the 68000, this is the size of MODE in words,    except in the FP regs, where a single reg is always enough.  */
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
value|((CLASS) == FP_REGS ? 1 \   : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Moves between fp regs and other regs are two insns.  */
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
value|((((CLASS1) == FP_REGS&& (CLASS2) != FP_REGS)	\     || ((CLASS2) == FP_REGS&& (CLASS1) != FP_REGS))	\    ? 4 : 2)
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
comment|/* The Alliant uses -fcaller-saves by default.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CALLER_SAVES
end_define

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|-4
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On the 68000, sp@- in a byte insn really pushes a word.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ROUNDING
parameter_list|(
name|BYTES
parameter_list|)
value|(((BYTES) + 1)& ~1)
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
value|0
end_define

begin_comment
comment|/* Value is the number of bytes of arguments automatically    popped when returning from a subroutine call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.      On the Alliant we define this as SIZE and make the calling sequence    (in alliant.md) pop the args.  This wouldn't be necessary if we    could add to the pending stack adjustment the size of the argument    descriptors that are pushed after the arguments.  */
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
value|(SIZE)
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_comment
comment|/* On the Alliant the return value is in FP0 if real, else D0.  */
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
value|(TREE_CODE (VALTYPE) == REAL_TYPE \    ? gen_rtx (REG, TYPE_MODE (VALTYPE), 16) \    : gen_rtx (REG, TYPE_MODE (VALTYPE), 0))
end_define

begin_comment
comment|/* Define how to find the value returned by a library function    assuming the value has mode MODE.  */
end_comment

begin_comment
comment|/* On the Alliant the return value is in FP0 if real, else D0.  The    Alliant library functions for floating-point emulation return their    values both in FP0 and in D0/D1.  But since not all libgcc functions    return the results of these directly, we cannot assume that D0/D1    contain the values we expect on return from a libgcc function.  */
end_comment

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(((MODE) == DFmode || (MODE) == SFmode) \    ? gen_rtx (REG, MODE, 16) \    : gen_rtx (REG, MODE, 0))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the Alliant, D0 and FP0 are the only registers thus used.    (No need to mention D1 when used as a pair with D0.)  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|(((N)& ~16) == 0)
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
comment|/* 1 if N is a possible register number for function argument passing.    On the Alliant, no registers are used in this way.  */
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
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the Alliant, this is a single integer, which is a number of bytes    of arguments scanned so far.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.     On the Alliant, the offset starts at 0.  */
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
comment|/* On the Alliant all args are pushed.  */
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
value|0
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
value|0
end_define

begin_comment
comment|/* This macro generates the assembly code for function entry.    FILE is a stdio stream to output the code to.    SIZE is an int: how many units of temporary storage to allocate.    Refer to the array `regs_ever_live' to determine which registers    to save; `regs_ever_live[I]' is nonzero if register number I    is ever used in the function.  This macro is responsible for    knowing which registers should not be saved even if used.    The Alliant uses caller-saves, so this macro is very simple.  */
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
value|{ int fsize = ((SIZE) - STARTING_FRAME_OFFSET + 3)& -4;	\   if (frame_pointer_needed)					\     {								\       if (fsize< 0x8000)					\ 	fprintf(FILE,"\tlinkw a6,#%d\n", -fsize);		\       else if (TARGET_68020)					\ 	fprintf(FILE,"\tlinkl a6,#%d\n", -fsize);		\       else							\ 	fprintf(FILE,"\tlinkw a6,#0\n\tsubl #%d,sp\n", fsize);  \       fprintf(FILE, "\tmovl a0,a6@(-4)\n" ); }}
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
value|fprintf (FILE, "\tjbsr __mcount_\n")
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
comment|/* This macro generates the assembly code for function exit,    on machines that need it.  If FUNCTION_EPILOGUE is not defined    then individual return instructions are generated for each    return statement.  Args are same as for FUNCTION_PROLOGUE.     The function epilogue should not depend on the current stack pointer!    It should use the frame pointer only.  This is mandatory because    of alloca; we also take advantage of it to omit stack adjustments    before returning.  */
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
value|{ if (frame_pointer_needed)					\     fprintf (FILE, "\tunlk a6\n");				\   fprintf (FILE, "\trts\n"); }
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
value|{								\   int regno;							\   int offset = -4;						\   for (regno = 16; regno< FIRST_PSEUDO_REGISTER; regno++)	\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       offset += 12;						\   for (regno = 0; regno< 16; regno++)				\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       offset += 4;						\   (DEPTH) = offset - ((get_frame_size () + 3)& -4);		\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_POST_INCREMENT
end_define

begin_comment
comment|/* #define HAVE_POST_DECREMENT */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRE_DECREMENT
end_define

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
value|((REGNO)< 16 || (unsigned) reg_renumber[REGNO]< 16)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO) ^ 010)< 8 || (unsigned) (reg_renumber[REGNO] ^ 010)< 8)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_DATA_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 8 || (unsigned) reg_renumber[REGNO]< 8)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_FP_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO) ^ 020)< 8 || (unsigned) (reg_renumber[REGNO] ^ 020)< 8)
end_define

begin_comment
comment|/* Now macros that check whether X is a register and also,    strictly, whether it is in a specified class.     These macros are specific to the 68000, and may be used only    in code for printing assembler insns and in conditions for    define_optimization.  */
end_comment

begin_comment
comment|/* 1 if X is a data register.  */
end_comment

begin_define
define|#
directive|define
name|DATA_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& REGNO_OK_FOR_DATA_P (REGNO (X)))
end_define

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

begin_comment
comment|/* 1 if X is an address register  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& REGNO_OK_FOR_BASE_P (REGNO (X)))
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
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */
end_comment

begin_comment
comment|/* Alliant FP instructions don't take immediate operands, so this    forces them into memory.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
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
value|((REGNO (X) ^ 020)>= 8)
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
value|((REGNO (X)& ~027) != 0)
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
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     The other macros defined here are used only in GO_IF_LEGITIMATE_ADDRESS.  */
end_comment

begin_define
define|#
directive|define
name|INDIRECTABLE_1_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(CONSTANT_ADDRESS_P (X)						\    || (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))			\    || ((GET_CODE (X) == PRE_DEC || GET_CODE (X) == POST_INC)		\&& REG_P (XEXP (X, 0))						\&& REG_OK_FOR_BASE_P (XEXP (X, 0)))				\    || (GET_CODE (X) == PLUS						\&& REG_P (XEXP (X, 0))&& REG_OK_FOR_BASE_P (XEXP (X, 0))	\&& GET_CODE (XEXP (X, 1)) == CONST_INT				\&& ((unsigned) INTVAL (XEXP (X, 1)) + 0x8000)< 0x10000))
end_define

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
value|{ if (INDIRECTABLE_1_ADDRESS_P (X)) goto ADDR; }
end_define

begin_define
define|#
directive|define
name|GO_IF_INDEXABLE_BASE
parameter_list|(
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ if (GET_CODE (X) == LABEL_REF) goto ADDR;				\   if (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X)) goto ADDR; }
end_define

begin_define
define|#
directive|define
name|GO_IF_INDEXING
parameter_list|(
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ if (GET_CODE (X) == PLUS&& LEGITIMATE_INDEX_P (XEXP (X, 0)))		\     { GO_IF_INDEXABLE_BASE (XEXP (X, 1), ADDR); }			\   if (GET_CODE (X) == PLUS&& LEGITIMATE_INDEX_P (XEXP (X, 1)))		\     { GO_IF_INDEXABLE_BASE (XEXP (X, 0), ADDR); } }
end_define

begin_define
define|#
directive|define
name|GO_IF_INDEXED_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ GO_IF_INDEXING (X, ADDR);						\   if (GET_CODE (X) == PLUS)						\     { if (GET_CODE (XEXP (X, 1)) == CONST_INT				\&& (unsigned) INTVAL (XEXP (X, 1)) + 0x80< 0x100)		\ 	{ rtx go_temp = XEXP (X, 0); GO_IF_INDEXING (go_temp, ADDR); }	\       if (GET_CODE (XEXP (X, 0)) == CONST_INT				\&& (unsigned) INTVAL (XEXP (X, 0)) + 0x80< 0x100)		\ 	{ rtx go_temp = XEXP (X, 1); GO_IF_INDEXING (go_temp, ADDR); } } }
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_INDEX_REG_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_CODE (X) == REG&& REG_OK_FOR_INDEX_P (X))	\    || (GET_CODE (X) == SIGN_EXTEND			\&& GET_CODE (XEXP (X, 0)) == REG			\&& GET_MODE (XEXP (X, 0)) == HImode		\&& REG_OK_FOR_INDEX_P (XEXP (X, 0))))
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_INDEX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(LEGITIMATE_INDEX_REG_P (X)				\     || (TARGET_68020&& GET_CODE (X) == MULT		\&& LEGITIMATE_INDEX_REG_P (XEXP (X, 0))		\&& GET_CODE (XEXP (X, 1)) == CONST_INT		\&& (INTVAL (XEXP (X, 1)) == 2			\ 	    || INTVAL (XEXP (X, 1)) == 4		\ 	    || INTVAL (XEXP (X, 1)) == 8)))
end_define

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
value|{ GO_IF_NONINDEXED_ADDRESS (X, ADDR);			\   GO_IF_INDEXED_ADDRESS (X, ADDR); }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     For the 68000, we handle X+REG by loading X into a register R and    using R+REG.  R will go in an address reg and indexing will be used.    However, if REG is a broken-out memory address or multiplication,    nothing needs to be done because REG can certainly go in an address reg.  */
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
value|{ register int ch = (X) != (OLDX);					\   if (GET_CODE (X) == PLUS)						\     { if (GET_CODE (XEXP (X, 0)) == MULT)				\ 	ch = 1, XEXP (X, 0) = force_operand (XEXP (X, 0), 0);		\       if (GET_CODE (XEXP (X, 1)) == MULT)				\ 	ch = 1, XEXP (X, 1) = force_operand (XEXP (X, 1), 0);		\       if (ch&& GET_CODE (XEXP (X, 1)) == REG				\&& GET_CODE (XEXP (X, 0)) == REG)				\ 	goto WIN;							\       if (ch) { GO_IF_LEGITIMATE_ADDRESS (MODE, X, WIN); }		\       if (GET_CODE (XEXP (X, 0)) == REG					\ 	       || (GET_CODE (XEXP (X, 0)) == SIGN_EXTEND		\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == REG		\&& GET_MODE (XEXP (XEXP (X, 0), 0)) == HImode))	\ 	{ register rtx temp = gen_reg_rtx (Pmode);			\ 	  register rtx val = force_operand (XEXP (X, 1), 0);		\ 	  emit_move_insn (temp, val);					\ 	  XEXP (X, 1) = temp;						\ 	  goto WIN; }							\       else if (GET_CODE (XEXP (X, 1)) == REG				\ 	       || (GET_CODE (XEXP (X, 1)) == SIGN_EXTEND		\&& GET_CODE (XEXP (XEXP (X, 1), 0)) == REG		\&& GET_MODE (XEXP (XEXP (X, 1), 0)) == HImode))	\ 	{ register rtx temp = gen_reg_rtx (Pmode);			\ 	  register rtx val = force_operand (XEXP (X, 0), 0);		\ 	  emit_move_insn (temp, val);					\ 	  XEXP (X, 0) = temp;						\ 	  goto WIN; }}}
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the 68000, only predecrement and postincrement address depend thus    (the amount of decrement or increment being the length of the operand).  */
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
value|if (GET_CODE (ADDR) == POST_INC || GET_CODE (ADDR) == PRE_DEC) goto LABEL
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

begin_define
define|#
directive|define
name|SLOW_ZERO_EXTEND
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
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|-1
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
value|case CONST_INT:						\
comment|/* Constant zero is super cheap due to clr instruction.  */
value|\     if (RTX == const0_rtx) return 0;				\     if ((unsigned) INTVAL (RTX)< 077) return 1;		\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 3;							\   case CONST_DOUBLE:						\     return 5;
end_define

begin_comment
comment|/* Check a `double' value for validity for a particular machine mode.    This is defined to avoid crashes outputting certain constants.  */
end_comment

begin_define
define|#
directive|define
name|CHECK_FLOAT_VALUE
parameter_list|(
name|mode
parameter_list|,
name|d
parameter_list|)
define|\
value|if ((mode) == SFmode)							\     { 									\       if ((d)> 3.4028234663852890e+38)					\ 	{ warning ("magnitude of value too large for `float'");		\ 	  (d) = 3.4028234663852890e+38; }				\       else if ((d)< -3.4028234663852890e+38)				\ 	{ warning ("magnitude of value too large for `float'");		\ 	  (d) = -3.4028234663852890e+38; }				\       else if (((d)> 0)&& ((d)< 1.1754943508222873e-38))		\ 	(d) = 0.0;							\       else if (((d)< 0)&& ((d)> -1.1754943508222873e-38))		\ 	(d) = 0.0;							\     }
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
comment|/* On the Alliant, floating-point instructions do not modify the    ordinary CC register.  Only fcmp and ftest instructions modify the    floating-point CC register.  We should actually keep track of what    both kinds of CC registers contain, but for now we only consider    the most recent instruction that has set either register.  */
end_comment

begin_comment
comment|/* Set if the cc value came from a floating point test, so a floating    point conditional branch must be output.  */
end_comment

begin_define
define|#
directive|define
name|CC_IN_FP
value|04000
end_define

begin_comment
comment|/* Store in cc_status the expressions    that the condition codes will describe    after execution of an instruction whose pattern is EXP.    Do not alter them if the instruction would not alter the cc's.  */
end_comment

begin_comment
comment|/* On the 68000, all the insns to store in an address register    fail to set the cc's.  However, in some cases these instructions    can make it possibly invalid to use the saved cc's.  In those    cases we clear out some or all of the saved cc's so they won't be used.  */
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
value|{								\   if (GET_CODE (EXP) == SET)					\     { if (ADDRESS_REG_P (SET_DEST (EXP)) || FP_REG_P (SET_DEST (EXP)))	    \ 	{ if (cc_status.value1					\&& reg_overlap_mentioned_p (SET_DEST (EXP), cc_status.value1)) \ 	    cc_status.value1 = 0;				\ 	  if (cc_status.value2					\&& reg_overlap_mentioned_p (SET_DEST (EXP), cc_status.value2)) \ 	    cc_status.value2 = 0; }				\       else if (GET_CODE (SET_SRC (EXP)) == MOD			\ 	       || GET_CODE (SET_SRC (EXP)) == UMOD		\ 	       || (GET_CODE (SET_SRC (EXP)) == TRUNCATE		\&& (GET_CODE (XEXP (SET_SRC (EXP))) == MOD	\ 		       || GET_CODE (XEXP (SET_SRC (EXP))) == UMOD)))	\
comment|/* The swap insn produces cc's that don't correspond to the 	\ 	   result.  */
value|\         CC_STATUS_INIT;						\       else if (SET_DEST (EXP) != cc0_rtx				\&& (FP_REG_P (SET_SRC (EXP))			\ 		   || GET_CODE (SET_SRC (EXP)) == FIX		\ 		   || GET_CODE (SET_SRC (EXP)) == FLOAT_TRUNCATE \ 		   || GET_CODE (SET_SRC (EXP)) == FLOAT_EXTEND)) \ 	{ CC_STATUS_INIT; }					\
comment|/* A pair of move insns doesn't produce a useful overall cc.  */
value|\       else if (!FP_REG_P (SET_DEST (EXP))			\&& !FP_REG_P (SET_SRC (EXP))			\&& GET_MODE_SIZE (GET_MODE (SET_SRC (EXP)))> 4	\&& (GET_CODE (SET_SRC (EXP)) == REG		\ 		   || GET_CODE (SET_SRC (EXP)) == MEM		\ 		   || GET_CODE (SET_SRC (EXP)) == CONST_DOUBLE))\ 	{ CC_STATUS_INIT; }					\       else if (GET_CODE (SET_SRC (EXP)) == CALL)		\ 	{ CC_STATUS_INIT; }					\       else if (XEXP (EXP, 0) != pc_rtx)				\ 	{ cc_status.flags = 0;					\ 	  cc_status.value1 = XEXP (EXP, 0);			\ 	  cc_status.value2 = XEXP (EXP, 1); } }			\   else if (GET_CODE (EXP) == PARALLEL				\&& GET_CODE (XVECEXP (EXP, 0, 0)) == SET)		\     {								\       if (ADDRESS_REG_P (XEXP (XVECEXP (EXP, 0, 0), 0)))	\ 	CC_STATUS_INIT;						\       else if (XEXP (XVECEXP (EXP, 0, 0), 0) != pc_rtx)		\ 	{ cc_status.flags = 0;					\ 	  cc_status.value1 = XEXP (XVECEXP (EXP, 0, 0), 0);	\ 	  cc_status.value2 = XEXP (XVECEXP (EXP, 0, 0), 1); } }	\   else CC_STATUS_INIT;						\   if (cc_status.value2 != 0					\&& ADDRESS_REG_P (cc_status.value2)			\&& GET_MODE (cc_status.value2) == QImode)			\     CC_STATUS_INIT;						\   if (cc_status.value2 != 0)					\     switch (GET_CODE (cc_status.value2))			\       { case PLUS: case MINUS: case MULT:			\ 	case DIV: case UDIV: case MOD: case UMOD: case NEG:	\ 	case ASHIFT: case LSHIFT: case ASHIFTRT: case LSHIFTRT:	\ 	case ROTATE: case ROTATERT:				\ 	  if (GET_MODE (cc_status.value2) != VOIDmode)		\ 	    cc_status.flags |= CC_NO_OVERFLOW;			\ 	  break;						\ 	case ZERO_EXTEND:					\
comment|/* (SET r1 (ZERO_EXTEND r2)) on this machine 	     ends with a move insn moving r2 in r2's mode. 	     Thus, the cc's are set for r2. 	     This can set N bit spuriously. */
value|\ 	  cc_status.flags |= CC_NOT_NEGATIVE; }			\   if (cc_status.value1&& GET_CODE (cc_status.value1) == REG	\&& cc_status.value2					\&& reg_overlap_mentioned_p (cc_status.value1, cc_status.value2))	\     cc_status.value2 = 0;					\   if ((cc_status.value1&& FP_REG_P (cc_status.value1))		\        || (cc_status.value2&& FP_REG_P (cc_status.value2)))	\     cc_status.flags = CC_IN_FP; }
end_define

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
value|{ if (cc_prev_status.flags& CC_IN_FP)			\     return FLOAT;						\   if (cc_prev_status.flags& CC_NO_OVERFLOW)			\     return NO_OV;						\   return NORMAL; }
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
name|FILE
parameter_list|)
define|\
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
value|{"d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7",	\  "a0", "a1", "a2", "a3", "a4", "a5", "a6", "sp",	\  "fp0", "fp1", "fp2", "fp3", "fp4", "fp5", "fp6", "fp7" }
end_define

begin_comment
comment|/* How to renumber registers for dbx and gdb.    On the Sun-3, the floating point registers have numbers    18 to 25, not 16 to 23 as they do in the compiler.  */
end_comment

begin_comment
comment|/* (On the Alliant, dbx isn't working yet at all.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO)< 16 ? (REGNO) : (REGNO) + 2)
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
value|do { fputs ("\t.globl ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)
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
value|do { union { double d; long v[2];} tem;			\      tem.d = (VALUE);					\      fprintf (FILE, "\t.long 0x%x,0x%x\n", tem.v[0], tem.v[1]);	\    } while (0)
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
value|do { union { float f; long l;} tem;			\      tem.f = (VALUE);					\      fprintf (FILE, "\t.long 0x%x\n", tem.l);	\    } while (0)
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

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|PTR
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{ int i; unsigned char *pp = (unsigned char *) (PTR);		\   fprintf((FILE), "\t.byte %d", (unsigned int)*pp++);		\   for (i = 1; i< (SIZE); ++i, ++pp) {				\     if ((i % 8) == 0)						\       fprintf((FILE), "\n\t.byte %d", (unsigned int) *pp);	\     else							\       fprintf((FILE), ",%d", (unsigned int) *pp); }		\   fprintf ((FILE), "\n");       }
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
value|fprintf (FILE, "\tmovl %s,sp@-\n", reg_names[REGNO])
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
value|fprintf (FILE, "\tmovl sp@+,%s\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.    (The 68000 does not use such vectors,    but we must define this macro anyway.)  */
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
value|if ((LOG) == 1)			\     fprintf (FILE, "\t.even\n");	\   else if ((LOG) != 0)			\     fprintf (FILE, "\t.align %dn", (LOG));
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
value|fprintf (FILE, "\t. = . + %u\n", (SIZE))
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
value|( fputs ("\t.comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
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
value|( fputs ("\t.lcomm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (ROUNDED)))
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
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    For `%' followed by punctuation, CODE is the punctuation and X is null.     On the Alliant, we use several CODE characters:    '.' for dot needed in Motorola-style opcode names.    '-' for an operand pushing on the stack:        sp@-, -(sp) or -(%sp) depending on the style of syntax.    '+' for an operand pushing on the stack:        sp@+, (sp)+ or (%sp)+ depending on the style of syntax.    '@' for a reference to the top word on the stack:        sp@, (sp) or (%sp) depending on the style of syntax.    '#' for an immediate operand prefix (# in MIT and Motorola syntax        but& in SGS syntax).    '!' for the cc register (used in an `and to cc' insn).     'b' for byte insn (no effect, on the Sun; this is for the ISI).    'd' to force memory addressing to be absolute, not relative.    'f' for float insn (print a CONST_DOUBLE as a float rather than in hex)    'x' for float insn (print a CONST_DOUBLE as a float rather than in hex),        or print pair of registers as rx:ry.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '.' || (CODE) == '#' || (CODE) == '-'			\    || (CODE) == '+' || (CODE) == '@' || (CODE) == '!')
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
value|{ int i;								\   if (CODE == '.') ;							\   else if (CODE == '#') fprintf (FILE, "#");				\   else if (CODE == '-') fprintf (FILE, "sp@-");				\   else if (CODE == '+') fprintf (FILE, "sp@+");				\   else if (CODE == '@') fprintf (FILE, "sp@");				\   else if (CODE == '!') fprintf (FILE, "cc");				\   else if ((X)  == 0  ) ;						\   else if (GET_CODE (X) == REG)						\     { if (REGNO (X)< 16&& (CODE == 'y' || CODE == 'x')&& GET_MODE (X) == DFmode)	\         fprintf (FILE, "%s,%s", reg_names[REGNO (X)], reg_names[REGNO (X)+1]); \       else								\         fprintf (FILE, "%s", reg_names[REGNO (X)]);			\     }									\   else if (GET_CODE (X) == MEM)						\     {									\       output_address (XEXP (X, 0));					\       if (CODE == 'd'&& ! TARGET_68020					\&& CONSTANT_ADDRESS_P (XEXP (X, 0))				\&& !(GET_CODE (XEXP (X, 0)) == CONST_INT			\&& INTVAL (XEXP (X, 0))< 0x8000				\&& INTVAL (XEXP (X, 0))>= -0x8000))			\ 	fprintf (FILE, ":l");						\     }									\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) == SFmode)	\     { union { double d; int i[2]; } u;					\       union { float f; int i; } u1;					\       u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\       u1.f = u.d;							\       if (CODE == 'f')							\         fprintf (FILE, "#0r%.9g", u1.f);				\       else								\         fprintf (FILE, "#0x%x", u1.i); }				\   else if (GET_CODE (X) == CONST_DOUBLE&& GET_MODE (X) != DImode)	\     { union { double d; int i[2]; } u;					\       u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);	\       fprintf (FILE, "#0r%.20g", u.d); }				\   else { putc ('#', FILE); output_addr_const (FILE, X); }}
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
value|{ register rtx reg1, reg2, breg, ireg;					\   register rtx addr = ADDR;						\   static char *sz = ".BW.L...D";					\   rtx offset;								\   switch (GET_CODE (addr))						\     {									\     case REG:								\       fprintf (FILE, "%s@", reg_names[REGNO (addr)]);			\       break;								\     case PRE_DEC:							\       fprintf (FILE, "%s@-", reg_names[REGNO (XEXP (addr, 0))]);	\       break;								\     case POST_INC:							\       fprintf (FILE, "%s@+", reg_names[REGNO (XEXP (addr, 0))]);	\       break;								\     case PLUS:								\       reg1 = 0;	reg2 = 0;						\       ireg = 0;	breg = 0;						\       offset = 0;							\       if (CONSTANT_ADDRESS_P (XEXP (addr, 0)))				\ 	{								\ 	  offset = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (CONSTANT_ADDRESS_P (XEXP (addr, 1)))			\ 	{								\ 	  offset = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       if (GET_CODE (addr) != PLUS) ;					\       else if (GET_CODE (XEXP (addr, 0)) == SIGN_EXTEND)		\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == SIGN_EXTEND)		\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       else if (GET_CODE (XEXP (addr, 0)) == MULT)			\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == MULT)			\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       else if (GET_CODE (XEXP (addr, 0)) == REG)			\ 	{								\ 	  reg1 = XEXP (addr, 0);					\ 	  addr = XEXP (addr, 1);					\ 	}								\       else if (GET_CODE (XEXP (addr, 1)) == REG)			\ 	{								\ 	  reg1 = XEXP (addr, 1);					\ 	  addr = XEXP (addr, 0);					\ 	}								\       if (GET_CODE (addr) == REG || GET_CODE (addr) == MULT		\ 	  || GET_CODE (addr) == SIGN_EXTEND)				\ 	{ if (reg1 == 0) reg1 = addr; else reg2 = addr; addr = 0; }	\
comment|/*  for OLD_INDEXING							\       else if (GET_CODE (addr) == PLUS)					\ 	{								\ 	  if (GET_CODE (XEXP (addr, 0)) == REG)				\ 	    {								\ 	      reg2 = XEXP (addr, 0);					\ 	      addr = XEXP (addr, 1);					\ 	    }								\ 	  else if (GET_CODE (XEXP (addr, 1)) == REG)			\ 	    {								\ 	      reg2 = XEXP (addr, 1);					\ 	      addr = XEXP (addr, 0);					\ 	    }								\ 	}								\   */
value|\       if (offset != 0) { if (addr != 0) abort (); addr = offset; }	\       if ((reg1&& (GET_CODE (reg1) == SIGN_EXTEND			\ 		    || GET_CODE (reg1) == MULT))			\ 	  || (reg2 != 0&& REGNO_OK_FOR_BASE_P (REGNO (reg2))))		\ 	{ breg = reg2; ireg = reg1; }					\       else if (reg1 != 0&& REGNO_OK_FOR_BASE_P (REGNO (reg1)))		\ 	{ breg = reg1; ireg = reg2; }					\       if (ireg != 0&& breg == 0&& GET_CODE (addr) == LABEL_REF)	\         { int scale = 1;						\ 	  if (GET_CODE (ireg) == MULT)					\ 	    { scale = INTVAL (XEXP (ireg, 1));				\ 	      ireg = XEXP (ireg, 0); }					\ 	  if (GET_CODE (ireg) == SIGN_EXTEND)				\ 	    fprintf (FILE, "pc@(L%d-LI%d-2:B)[%s:W",			\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     reg_names[REGNO (XEXP (ireg, 0))]); 		\ 	  else								\ 	    fprintf (FILE, "pc@(L%d-LI%d-2:B)[%s:L",			\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     CODE_LABEL_NUMBER (XEXP (addr, 0)),		\ 		     reg_names[REGNO (ireg)]);				\ 	  fprintf (FILE, ":%c", sz[scale]);				\ 	  putc (']', FILE);						\ 	  break; }							\       if (breg != 0&& ireg == 0&& GET_CODE (addr) == LABEL_REF)	\         { fprintf (FILE, "pc@(L%d-LI%d-2:B)[%s:L:B]",			\ 		   CODE_LABEL_NUMBER (XEXP (addr, 0)),			\ 		   CODE_LABEL_NUMBER (XEXP (addr, 0)),			\ 		   reg_names[REGNO (breg)]);				\ 	  break; }							\       if (ireg != 0 || breg != 0)					\ 	{ int scale = 1;						\ 	  if (breg == 0)						\ 	    abort ();							\ 	  if (addr&& GET_CODE (addr) == LABEL_REF) abort ();		\ 	  fprintf (FILE, "%s@", reg_names[REGNO (breg)]);		\ 	  if (addr != 0) {						\             putc( '(', FILE );						\ 	    output_addr_const (FILE, addr);				\             if (ireg != 0) {						\               if (GET_CODE(addr) == CONST_INT) {			\                 int size_of = 1, val = INTVAL(addr);			\                 if (val< -0x8000 || val>= 0x8000)			\                    size_of = 4;   					\                 else if (val< -0x80 || val>= 0x80)			\                    size_of = 2;						\                 fprintf(FILE, ":%c", sz[size_of]);			\               }        							\               else							\                 fprintf(FILE, ":L"); } 					\             putc( ')', FILE ); }					\ 	  if (ireg != 0) {						\ 	    putc ('[', FILE);						\ 	    if (ireg != 0&& GET_CODE (ireg) == MULT)			\ 	      { scale = INTVAL (XEXP (ireg, 1));			\ 	        ireg = XEXP (ireg, 0); }				\ 	    if (ireg != 0&& GET_CODE (ireg) == SIGN_EXTEND)		\ 	      fprintf (FILE, "%s:W", reg_names[REGNO (XEXP (ireg, 0))]);	\ 	    else if (ireg != 0)						\ 	      fprintf (FILE, "%s:L", reg_names[REGNO (ireg)]);		\ 	    fprintf (FILE, ":%c", sz[scale]);				\ 	    putc (']', FILE);						\           }								\ 	  break;							\ 	}								\       else if (reg1 != 0&& GET_CODE (addr) == LABEL_REF)		\ 	{ fprintf (FILE, "pc@(L%d-LI%d-2:B)[%s:L:B]",			\ 		   CODE_LABEL_NUMBER (XEXP (addr, 0)),			\ 		   CODE_LABEL_NUMBER (XEXP (addr, 0)),			\ 		   reg_names[REGNO (reg1)]);				\ 	  break; }							\     default:								\       if (GET_CODE (addr) == CONST_INT					\&& INTVAL (addr)< 0x8000					\&& INTVAL (addr)>= -0x8000)					\ 	fprintf (FILE, "%d:W", INTVAL (addr));				\       else								\         output_addr_const (FILE, addr);					\     }}
end_define

begin_escape
end_escape

begin_comment
comment|/* Local variables: version-control: t End: */
end_comment

end_unit

