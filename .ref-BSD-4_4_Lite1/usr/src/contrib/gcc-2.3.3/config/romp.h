begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for ROMP chip.    Copyright (C) 1989, 1991 Free Software Foundation, Inc.    Contributed by Richard Kenner (kenner@nyu.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dibm032 -Dunix"
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|;
end_define

begin_comment
comment|/* Add -lfp_p when running with -p or -pg.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{pg:-lfp_p}%{p:-lfp_p} %{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p}"
end_define

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

begin_comment
comment|/* Flag to generate all multiplies as an in-line sequence of multiply-step    insns instead of calling a library routine.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_IN_LINE_MUL
value|(target_flags& 1)
end_define

begin_comment
comment|/* Flag to generate padded floating-point data blocks.  Otherwise, we generate    them the minimum size.  This trades off execution speed against size.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FULL_FP_BLOCKS
value|(target_flags& 2)
end_define

begin_comment
comment|/* Flag to pass and return floating point values in floating point registers.    Since this violates the linkage convention, we feel free to destroy fr2    and fr3 on function calls.    fr1-fr3 are used to pass the arguments. */
end_comment

begin_define
define|#
directive|define
name|TARGET_FP_REGS
value|(target_flags& 4)
end_define

begin_comment
comment|/* Flag to return structures of more than one word in memory.  This is for    compatibility with the MetaWare HighC (hc) compiler.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_HC_STRUCT_RETURN
value|(target_flags& 010)
end_define

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"in-line-mul", 1},		\     {"call-lib-mul", -1},	\     {"full-fp-blocks", 2},	\     {"minimum-fp-blocks", -2},	\     {"fp-arg-in-fpregs", 4},	\     {"fp-arg-in-gregs", -4},	\     {"hc-struct-return", 010},  \     {"nohc-struct-return", - 010}, \     { "", TARGET_DEFAULT}}
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|3
end_define

begin_comment
comment|/* Define this to change the optimizations performed by default.     This used to depend on the value of write_symbols,    but that is contrary to the general plan for GCC options.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|)
define|\
value|{					\   if ((LEVEL)> 0)			\     {					\       flag_force_addr = 1;		\       flag_force_mem = 1;		\     }					\ }
end_define

begin_comment
comment|/* Match<sys/types.h>'s definition.  */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long int"
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields. */
end_comment

begin_comment
comment|/* That is true on ROMP. */
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
comment|/* That is true on ROMP.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is lowest    numbered.      For ROMP we can decide arbitrarily since there are no machine instructions    for them.  Might as well be consistent with bits and bytes. */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
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
comment|/* No data type wants to be aligned rounder than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
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
comment|/* Make strings word-aligned so strcpy from constants will be faster.  */
end_comment

begin_define
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
end_define

begin_comment
comment|/* Make arrays of chars word-aligned for the same reasons.  */
end_comment

begin_define
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
end_define

begin_comment
comment|/* Set this nonzero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     ROMP has 16 fullword registers and 8 floating point registers.     In addition, the difference between the frame and argument pointers is    a function of the number of registers saved, so we need to have a register    to use for AP that will later be eliminated in favor of sp or fp.  This is    a normal register, but it is fixed.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|25
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.     On ROMP, r1 is used for the stack and r14 is used for a    data area pointer.     HACK WARNING:  On the RT, there is a bug in code generation for    the MC68881 when the first and third operands are the same floating-point    register.  See the definition of the FINAL_PRESCAN_INSN macro for details.    Here we need to reserve fr0 for this purpose.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	\   1,							\   1, 0, 0, 0, 0, 0, 0, 0}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,	\   1,							\   1, 1, 0, 0, 0, 0, 0, 0}
end_define

begin_comment
comment|/* List the order in which to allocate registers.  Each register must be    listed once, even those in FIXED_REGISTERS.     We allocate in the following order: 	fr0, fr1	(not saved) 	fr2 ... fr6 	fr7		(more expensive for some FPA's) 	r0		(not saved and won't conflict with parameter register) 	r4, r3, r2	(not saved, highest used first to make less conflict) 	r5		(not saved, but forces r6 to be saved if DI/DFmode) 	r15, r14, r13, r12, r11, r10, r9, r8, r7, r6 (less to save) 	r1, ap 			*/
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{17, 18,			\    19, 20, 21, 22, 23,		\    24,				\    0,				\    4, 3, 2,			\    5,				\    15, 14, 13, 12, 11, 10,	\    9, 8, 7, 6, 			\    1, 16}
end_define

begin_comment
comment|/* True if register is floating-point.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= 17)
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On ROMP, ordinary registers hold 32 bits worth;    a single floating point register is always enough for    anything that can be stored in them at all.  */
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
value|(FP_REGNO_P (REGNO) ? GET_MODE_NUNITS (MODE)	\    : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On ROMP, the cpu registers can hold any mode but the float registers    can hold only floating point. */
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
value|(! FP_REGNO_P (REGNO) || GET_MODE_CLASS (MODE) == MODE_FLOAT	\    || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT)
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
value|((GET_MODE_CLASS (MODE1) == MODE_FLOAT		\     || GET_MODE_CLASS (MODE1) == MODE_COMPLEX_FLOAT)	\    == (GET_MODE_CLASS (MODE2) == MODE_FLOAT		\        || GET_MODE_CLASS (MODE2) == MODE_COMPLEX_FLOAT))
end_define

begin_comment
comment|/* A C expression returning the cost of moving data from a register of class    CLASS1 to one of CLASS2.     On the ROMP, access to floating-point registers is expensive (even between    two FP regs.)  */
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
value|(2 + 10 * ((CLASS1) == FP_REGS) + 10 * (CLASS2 == FP_REGS))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* ROMP pc isn't overloaded on a register that the compiler knows about.  */
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
value|1
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|13
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
comment|/* Place to put static chain when calling a function that requires it.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN
define|\
value|gen_rtx (MEM, Pmode, gen_rtx (PLUS, Pmode, stack_pointer_rtx,		\ 				gen_rtx (CONST_INT, VOIDmode, -36)))
end_define

begin_comment
comment|/* Place where static chain is found upon entry to routine.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_INCOMING
define|\
value|gen_rtx (MEM, Pmode, gen_rtx (PLUS, Pmode, arg_pointer_rtx,		\ 				gen_rtx (CONST_INT, VOIDmode, -20)))
end_define

begin_comment
comment|/* Place that structure value return address is placed.     On the ROMP, it is passed as an extra parameter.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_comment
comment|/* The ROMP has two types of registers, general and floating-point.     However, r0 is special in that it cannot be used as a base register.    So make a class for registers valid as base registers.     For floating-point support, add classes that just consist of r0 and    r15, respectively.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|R0_REGS
block|,
name|R15_REGS
block|,
name|BASE_REGS
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
value|{"NO_REGS", "R0_REGS", "R15_REGS", "BASE_REGS", "GENERAL_REGS", \   "FP_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
value|{0, 0x00001, 0x08000, 0x1fffe, 0x1ffff,  \ 			    0x1fe0000, 0x1ffffff }
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
value|((REGNO) == 0 ? GENERAL_REGS : FP_REGNO_P (REGNO) ? FP_REGS : BASE_REGS)
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|BASE_REGS
end_define

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|BASE_REGS
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
value|((C) == 'f' ? FP_REGS		\    : (C) == 'b' ? BASE_REGS	\    : (C) == 'z' ? R0_REGS	\    : (C) == 't' ? R15_REGS	\    : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L, M, N, and P in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     `I' is constants less than 16    `J' is negative constants greater than -16    `K' is the range for a normal D insn.    `L' is a constant with only the low-order 16 bits set    `M' is a constant with only the high-order 16 bits set    `N' is a single-bit constant    `O' is a constant with either the high-order or low-order 16 bits all ones    `P' is the complement of a single-bit constant   */
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
value|( (C) == 'I' ? (unsigned) (VALUE)< 0x10		   \    : (C) == 'J' ? (VALUE)< 0&& (VALUE)> -16		   \    : (C) == 'K' ? (unsigned) ((VALUE) + 0x8000)< 0x10000  \    : (C) == 'L' ? ((VALUE)& 0xffff0000) == 0		   \    : (C) == 'M' ? ((VALUE)& 0xffff) == 0		   \    : (C) == 'N' ? exact_log2 (VALUE)>= 0		   \    : (C) == 'O' ? ((VALUE)& 0xffff) == 0xffff		   \ 		  || ((VALUE)& 0xffff0000) == 0xffff0000  \    : (C) == 'P' ? exact_log2 (~ (VALUE))>= 0		   \    : 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.    No floating-point constants on ROMP.  */
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
value|0
end_define

begin_comment
comment|/* Optional extra constraints for this machine.     For the ROMP, `Q' means that this is a memory operand but not a symbolic    memory operand.  Note that an unassigned pseudo register is such a    memory operand.  If register allocation has not been done, we reject    pseudos, since we assume (hope) that they will get hard registers.     `R' means that this is a constant pool reference to the current function.    This is just r14 and so can be treated as a register.  We bother with this    just in move insns as that is the only place it is likely to occur.     `S' means that this is the address of a constant pool location.  This is    equal to r14 plus a constant.  We also only check for this in move insns. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT
parameter_list|(
name|OP
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'Q' ?						\    ((GET_CODE (OP) == REG				\&& REGNO (OP)>= FIRST_PSEUDO_REGISTER		\&& reg_renumber != 0				\&& reg_renumber[REGNO (OP)]< 0)			\     || (GET_CODE (OP) == MEM				\&& ! symbolic_memory_operand (OP, VOIDmode)))	\    : (C) == 'R' ? current_function_operand (OP, VOIDmode) \    : (C) == 'S' ? constant_pool_address_operand (OP, VOIDmode) \    : 0)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.     For the ROMP, if X is a memory reference that involves a symbol,    we must use a BASE_REGS register instead of GENERAL_REGS    to do the reload. The argument of MEM be either REG, PLUS, or SYMBOL_REF    to be valid, so we assume that this is the case.     Also, if X is an integer class, ensure that floating-point registers    aren't used.  */
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
value|((CLASS) == FP_REGS&& GET_MODE_CLASS (GET_MODE (X)) == MODE_INT	\    ? GENERAL_REGS :							\    (CLASS) != GENERAL_REGS ? (CLASS) :					\    GET_CODE (X) != MEM ? GENERAL_REGS :					\    GET_CODE (XEXP (X, 0)) == SYMBOL_REF ? BASE_REGS :			\    GET_CODE (XEXP (X, 0)) == LABEL_REF ? BASE_REGS :			\    GET_CODE (XEXP (X, 0)) == CONST ? BASE_REGS :			\    GET_CODE (XEXP (X, 0)) == REG ? GENERAL_REGS :			\    GET_CODE (XEXP (X, 0)) != PLUS ? GENERAL_REGS :			\    GET_CODE (XEXP (XEXP (X, 0), 1)) == SYMBOL_REF ? BASE_REGS :		\    GET_CODE (XEXP (XEXP (X, 0), 1)) == LABEL_REF ? BASE_REGS :		\    GET_CODE (XEXP (XEXP (X, 0), 1)) == CONST ? BASE_REGS : GENERAL_REGS)
end_define

begin_comment
comment|/* Return the register class of a scratch register needed to store into    OUT from a register of class CLASS in MODE.       On the ROMP, we cannot store into a symbolic memory address from an    integer register; we need a BASE_REGS register as a scratch to do it.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_OUTPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|OUT
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_INT&& symbolic_memory_operand (OUT, MODE) \    ? BASE_REGS : NO_REGS)
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.     On ROMP, this is the size of MODE in words,    except in the FP regs, where a single reg is always enough.  */
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
value|((CLASS) == FP_REGS ? 1			\   : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
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
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.    On the ROMP, if we set the frame pointer to 15 words below the highest    address of the highest local variable, the first 16 words will be    addressable via D-short insns. */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|64
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On ROMP, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/*  #define PUSH_ROUNDING(BYTES) */
end_comment

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.    On the ROMP, we define the argument pointer to the start of the argument    area.  */
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
comment|/* Define this if stack space is still allocated for a parameter passed    in a register.  The value is the number of bytes.  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|FNDECL
parameter_list|)
value|16
end_define

begin_comment
comment|/* This is the difference between the logical top of stack and the actual sp.     For the ROMP, sp points past the words allocated for the first four outgoing    arguments (they are part of the callee's frame).  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|-16
end_define

begin_comment
comment|/* Define this if the maximum size of all the outgoing args is to be    accumulated and pushed during the prologue.  The amount can be    found in the variable current_function_outgoing_args_size.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
end_define

begin_comment
comment|/* Value is the number of bytes of arguments automatically    popped when returning from a subroutine call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.  */
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
value|0
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.     On ROMP the value is found in r2, unless the machine specific option    fp-arg-in-fpregs is selected, in which case FP return values are in fr1 */
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
value|gen_rtx (REG, TYPE_MODE (VALTYPE),	\ 	   (TARGET_FP_REGS&&		\ 	    GET_MODE_CLASS (TYPE_MODE (VALTYPE)) == MODE_FLOAT) ? 18 : 2)
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
value|gen_rtx (REG, MODE, 2)
end_define

begin_comment
comment|/* The definition of this macro implies that there are cases where    a scalar value cannot be returned in registers.     For the ROMP, if compatibility with HC is required, anything of    type DImode is returned in memory.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|type
parameter_list|)
define|\
value|(TARGET_HC_STRUCT_RETURN&& TYPE_MODE (type) == DImode)
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value    as seen by the caller.     On ROMP, r2 is the only register thus used unless fp values are to be    returned in fp regs, in which case fr1 is also used.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 2 || ((N) == 18&& TARGET_FP_REGS))
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On ROMP, these are r2-r5 (and fr1-fr4 if fp regs are used).  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|(((N)<= 5&& (N)>= 2) || (TARGET_FP_REGS&& (N)> 17&& (N)< 21))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the ROMP, this is a structure.  The first word is the number of    words of (integer only if -mfp-arg-in-fpregs is specified) arguments    scanned so far (including the invisible argument, if any, which holds    the structure-value-address).  The second word hold the corresponding    value for floating-point arguments, except that both single and double    count as one register.  */
end_comment

begin_struct
struct|struct
name|rt_cargs
block|{
name|int
name|gregs
decl_stmt|,
name|fregs
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|struct rt_cargs
end_define

begin_define
define|#
directive|define
name|USE_FP_REG
parameter_list|(
name|MODE
parameter_list|,
name|CUM
parameter_list|)
define|\
value|(TARGET_FP_REGS&& GET_MODE_CLASS (MODE) == MODE_FLOAT	\&& (CUM).fregs< 3)
end_define

begin_comment
comment|/* Define intermediate macro to compute the size (in registers) of an argument    for the ROMP.  */
end_comment

begin_define
define|#
directive|define
name|ROMP_ARG_SIZE
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|(! (NAMED) ? 0								\  : (MODE) != BLKmode							\  ? (GET_MODE_SIZE (MODE) + (UNITS_PER_WORD - 1)) / UNITS_PER_WORD 	\  : (int_size_in_bytes (TYPE) + (UNITS_PER_WORD - 1)) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.     On ROMP, the offset normally starts at 0, but starts at 4 bytes    when the function gets a structure-value-address as an    invisible first argument.  */
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
value|(CUM).gregs = 0,				\   (CUM).fregs = 0
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
value|{ if (NAMED)						\     {							\       if (USE_FP_REG(MODE, CUM))			\ 	(CUM).fregs++;					\       else						\ 	(CUM).gregs += ROMP_ARG_SIZE (MODE, TYPE, NAMED); \     }							\ }
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).     On ROMP the first four words of args are normally in registers    and the rest are pushed.  */
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
value|(! (NAMED) ? 0							\    : ((TYPE) != 0&& TREE_CODE (TYPE_SIZE (TYPE)) != INTEGER_CST) ? 0	\    : USE_FP_REG(MODE,CUM) ? gen_rtx(REG, (MODE),(CUM.fregs) + 17)	\    : (CUM).gregs< 4 ? gen_rtx(REG, (MODE), 2 + (CUM).gregs) : 0)
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
value|(! (NAMED) ? 0							\    : USE_FP_REG(MODE,CUM) ? 0						\    : (((CUM).gregs< 4							\&& 4< ((CUM).gregs + ROMP_ARG_SIZE (MODE, TYPE, NAMED)))	\       ? 4 - (CUM).gregs : 0))
end_define

begin_comment
comment|/* Perform any needed actions needed for a function that is receiving a    variable number of arguments.      CUM is as above.     MODE and TYPE are the mode and type of the current parameter.     PRETEND_SIZE is a variable that should be set to the amount of stack    that must be pushed by the prolog to pretend that our caller pushed    it.     Normally, this macro will push all remaining incoming registers on the    stack and set PRETEND_SIZE to the length of the registers pushed.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_INCOMING_VARARGS
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|PRETEND_SIZE
parameter_list|,
name|NO_RTL
parameter_list|)
define|\
value|{ if (TARGET_FP_REGS)							\     error ("can't have varargs with -mfp-arg-in-fp-regs");		\   else if ((CUM).gregs< 4)						\     {									\       int first_reg_offset = (CUM).gregs;				\ 									\       if (MUST_PASS_IN_STACK (MODE, TYPE))				\ 	first_reg_offset += ROMP_ARG_SIZE (TYPE_MODE (TYPE), TYPE, 1);	\ 									\       if (first_reg_offset> 4)						\ 	first_reg_offset = 4;						\ 									\       if (! NO_RTL&& first_reg_offset != 4)				\ 	move_block_from_reg						\ 	  (2 + first_reg_offset,					\ 	   gen_rtx (MEM, BLKmode,					\ 		    plus_constant (virtual_incoming_args_rtx,		\ 				   first_reg_offset * 4)), 		\ 	   4 - first_reg_offset);					\       PRETEND_SIZE = (4 - first_reg_offset) * UNITS_PER_WORD;		\     }									\ }
end_define

begin_comment
comment|/* This macro produces the initial definition of a function name.    On the ROMP, we need to place an extra '.' in the function name.  */
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
value|{ if (TREE_PUBLIC(DECL))				\     fprintf (FILE, "\t.globl _.%s\n", NAME);		\   fprintf (FILE, "_.%s:\n", NAME);			\ }
end_define

begin_comment
comment|/* This macro is used to output the start of the data area.     On the ROMP, the _name is a pointer to the data area.  At that    location is the address of _.name, which is really the name of    the function.  We need to set all this up here.     The global declaration of the data area, if needed, is done in     `assemble_function', where it thinks it is globalizing the function    itself.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_POOL_PROLOGUE
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|{ extern int data_offset;					\   data_section ();						\   fprintf (FILE, "\t.align 2\n");				\   ASM_OUTPUT_LABEL (FILE, NAME);				\   fprintf (FILE, "\t.long _.%s, 0, ", NAME);			\   if (current_function_calls_alloca)				\     fprintf (FILE, "0x%x\n",					\ 	     0xf6900000 + current_function_outgoing_args_size); \   else								\     fprintf (FILE, "0\n");					\   data_offset = ((SIZE) + 12 + 3) / 4;				\ }
end_define

begin_comment
comment|/* Select section for constant in constant pool.     On ROMP, all constants are in the data area.  */
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
value|data_section ()
end_define

begin_comment
comment|/* This macro generates the assembly code for function entry.    FILE is a stdio stream to output the code to.    SIZE is an int: how many units of temporary storage to allocate.    Refer to the array `regs_ever_live' to determine which registers    to save; `regs_ever_live[I]' is nonzero if register number I    is ever used in the function.  This macro is responsible for    knowing which registers should not be saved even if used.  */
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
value|output_prolog (FILE, SIZE)
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
value|fprintf(FILE, "\tcas r0,r15,r0\n\tbali r15,mcount\n");
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_comment
comment|/* #define EXIT_IGNORE_STACK	1	*/
end_comment

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
value|output_epilog (FILE, SIZE)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     The trampoline should set the static chain pointer to value placed    into the trampoline and should branch to the specified routine.     On the ROMP, we have a problem.  There are no free registers to use    to construct the static chain and function addresses.  Hence we use    the following kludge:  r15 (the return address) is first saved in mq.    Then we use r15 to form the function address.  We then branch to the    function and restore r15 in the delay slot.  This makes it appear that    the function was called directly from the caller.     (Note that the function address built is actually that of the data block.    This is passed in r0 and the actual routine address is loaded into r15.)     In addition, note that the address of the "called function", in this case    the trampoline, is actually the address of the data area.  So we need to    make a fake data area that will contain the address of the trampoline.    Note that this must be defined as two half-words, since the trampoline    template (as opposed to the trampoline on the stack) is only half-word    aligned.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{					\   fprintf (FILE, "\t.short 0,0\n");	\   fprintf (FILE, "\tcau r0,0(r0)\n");	\   fprintf (FILE, "\toil r0,r0,0\n");	\   fprintf (FILE, "\tmts r10,r15\n");	\   fprintf (FILE, "\tst r0,-36(r1)\n");	\   fprintf (FILE, "\tcau r15,0(r0)\n");	\   fprintf (FILE, "\toil r15,r15,0\n");	\   fprintf (FILE, "\tcas r0,r15,r0\n");	\   fprintf (FILE, "\tls r15,0(r15)\n");	\   fprintf (FILE, "\tbrx r15\n");	\   fprintf (FILE, "\tmfs r10,r15\n");	\ }
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|36
end_define

begin_comment
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.     On the RT, the static chain and function addresses are written in    two 16-bit sections.     We also need to write the address of the first instruction in    the trampoline into the first word of the trampoline to simulate a    data area.  */
end_comment

begin_define
define|#
directive|define
name|INITIALIZE_TRAMPOLINE
parameter_list|(
name|ADDR
parameter_list|,
name|FNADDR
parameter_list|,
name|CXT
parameter_list|)
define|\
value|{								\   rtx _addr, _temp;						\   rtx _val;							\ 								\   _temp = expand_binop (SImode, add_optab, ADDR,		\ 			gen_rtx (CONST_INT, VOIDmode, 4),	\ 			0, 1, OPTAB_LIB_WIDEN);			\   emit_move_insn (gen_rtx (MEM, SImode,				\ 			   memory_address (SImode, ADDR)), _temp); \ 								\   _val = force_reg (SImode, CXT);				\   _addr = memory_address (HImode, plus_constant (ADDR, 10));	\   emit_move_insn (gen_rtx (MEM, HImode, _addr),			\ 		  gen_lowpart (HImode, _val));			\   _temp = expand_shift (RSHIFT_EXPR, SImode, _val,		\ 			build_int_2 (16, 0), 0, 1);		\   _addr = memory_address (HImode, plus_constant (ADDR, 6));	\   emit_move_insn (gen_rtx (MEM, HImode, _addr),			\ 		  gen_lowpart (HImode, _temp));			\ 								\   _val = force_reg (SImode, FNADDR);				\   _addr = memory_address (HImode, plus_constant (ADDR, 24));	\   emit_move_insn (gen_rtx (MEM, HImode, _addr),			\ 		  gen_lowpart (HImode, _val));			\   _temp = expand_shift (RSHIFT_EXPR, SImode, _val,		\ 			build_int_2 (16, 0), 0, 1);		\   _addr = memory_address (HImode, plus_constant (ADDR, 20));	\   emit_move_insn (gen_rtx (MEM, HImode, _addr),			\ 		  gen_lowpart (HImode, _temp));			\ 								\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Definitions for register eliminations.     We have two registers that can be eliminated on the ROMP.  First, the    frame pointer register can often be eliminated in favor of the stack    pointer register.  Secondly, the argument pointer register can always be    eliminated; it is replaced with either the stack or frame pointer.     In addition, we use the elimination mechanism to see if r14 is needed.    Initially we assume that it isn't.  If it is, we spill it.  This is done    by making it an eliminable register.  It doesn't matter what we replace    it with, since it will never occur in the rtl at this point.  */
end_comment

begin_comment
comment|/* This is an array of structures.  Each structure initializes one pair    of eliminable registers.  The "from" register number is given first,    followed by "to".  Eliminations of the same "from" register are listed    in order of preference.  */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM},	\  { ARG_POINTER_REGNUM, STACK_POINTER_REGNUM},	\  { ARG_POINTER_REGNUM, FRAME_POINTER_REGNUM},	\  { 14, 0}}
end_define

begin_comment
comment|/* Given FROM and TO register numbers, say whether this elimination is allowed.    Frame pointer elimination is automatically handled.     For the ROMP, if frame pointer elimination is being done, we would like to    convert ap into fp, not sp.     We need r14 if various conditions (tested in romp_using_r14) are true.     All other eliminations are valid.  */
end_comment

begin_define
define|#
directive|define
name|CAN_ELIMINATE
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|((FROM) == ARG_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM	\   ? ! frame_pointer_needed					\   : (FROM) == 14 ? ! romp_using_r14 ()				\   : 1)
end_define

begin_comment
comment|/* Define the offset between two registers, one to be eliminated, and the other    its replacement, at the start of a routine.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_ELIMINATION_OFFSET
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|{ if ((FROM) == FRAME_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM)	\     {									\       if (romp_pushes_stack ())						\ 	(OFFSET) = ((get_frame_size () - 64)				\ 		    + current_function_outgoing_args_size);		\       else								\ 	(OFFSET) = - (romp_sa_size () + 64);				\     }									\   else if ((FROM) == ARG_POINTER_REGNUM&& (TO) == FRAME_POINTER_REGNUM) \     (OFFSET) = romp_sa_size () - 16 + 64;				\   else if ((FROM) == ARG_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM) \     {									\       if (romp_pushes_stack ())						\ 	(OFFSET) = (get_frame_size () + (romp_sa_size () - 16)		\ 		    + current_function_outgoing_args_size);		\       else								\ 	(OFFSET) = -16;							\     }									\   else if ((FROM) == 14)						\     (OFFSET) = 0;							\   else									\     abort ();								\ }
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
value|0
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< FIRST_PSEUDO_REGISTER				\  ? (REGNO)< 16&& (REGNO) != 0&& (REGNO) != 16		\  : (reg_renumber[REGNO]< 16&& reg_renumber[REGNO]>= 0	\&& reg_renumber[REGNO] != 16))
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
value|1
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
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.     On the ROMP, there is a bit of a hack here.  Basically, we wish to    only issue instructions that are not `as' macros.  However, in the    case of `get', `load', and `store', if the operand is a relocatable    symbol (possibly +/- an integer), there is no way to express the    resulting split-relocation except with the macro.  Therefore, allow    either a constant valid in a normal (sign-extended) D-format insn or    a relocatable expression.     Also, for DFmode and DImode, we must ensure that both words are    addressable.     We define two macros: The first is given an offset (0 or 4) and indicates    that the operand is a CONST_INT that is valid for that offset.  The second    indicates a valid non-CONST_INT constant.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_ADDRESS_INTEGER_P
parameter_list|(
name|X
parameter_list|,
name|OFFSET
parameter_list|)
define|\
value|(GET_CODE (X) == CONST_INT						\&& (unsigned) (INTVAL (X) + (OFFSET) + 0x8000)< 0x10000)
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_ADDRESS_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == SYMBOL_REF						\   || GET_CODE (X) == LABEL_REF						\   || (GET_CODE (X) == CONST						\&& (GET_CODE (XEXP (XEXP (X, 0), 0)) == SYMBOL_REF		\           || GET_CODE (XEXP (XEXP (X, 0), 0)) == LABEL_REF)		\&& GET_CODE (XEXP (XEXP (X, 0), 1)) == CONST_INT))
end_define

begin_comment
comment|/* Include all constant integers and constant double, but exclude     SYMBOL_REFs that are to be obtained from the data area (see below).  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((LEGITIMATE_ADDRESS_CONSTANT_P (X)		\     || GET_CODE (X) == CONST_INT		\     || GET_CODE (X) == CONST_DOUBLE)		\&& ! (GET_CODE (X) == SYMBOL_REF&& SYMBOL_REF_FLAG (X)))
end_define

begin_comment
comment|/* For no good reason, we do the same as the other RT compilers and load    the addresses of data areas for a function from our data area.  That means    that we need to mark such SYMBOL_REFs.  We do so here.  */
end_comment

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|if (TREE_CODE (TREE_TYPE (DECL)) == FUNCTION_TYPE)	\     SYMBOL_REF_FLAG (XEXP (DECL_RTL (DECL), 0)) = 1;
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
value|0
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
define|\
value|(REGNO (X) != 0&& (REGNO (X)< 17 || REGNO (X)>= FIRST_PSEUDO_REGISTER))
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
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     On the ROMP, a legitimate address is either a legitimate constant,    a register plus a legitimate constant, or a register.  See the    discussion at the LEGITIMATE_ADDRESS_CONSTANT_P macro.  */
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
value|{ if (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))			\     goto ADDR;								\   if (GET_CODE (X) != CONST_INT&& LEGITIMATE_ADDRESS_CONSTANT_P (X))	\     goto ADDR;								\   if (GET_CODE (X) == PLUS						\&& GET_CODE (XEXP (X, 0)) == REG					\&& REG_OK_FOR_BASE_P (XEXP (X, 0))				\&& LEGITIMATE_ADDRESS_CONSTANT_P (XEXP (X, 1)))			\ 	goto ADDR;							\   if (GET_CODE (X) == PLUS						\&& GET_CODE (XEXP (X, 0)) == REG					\&& REG_OK_FOR_BASE_P (XEXP (X, 0))				\&& LEGITIMATE_ADDRESS_INTEGER_P (XEXP (X, 1), 0)			\&& (((MODE) != DFmode&& (MODE) != DImode)			\ 	  || (LEGITIMATE_ADDRESS_INTEGER_P (XEXP (X, 1), 4))))		\ 	goto ADDR;							\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     On ROMP, check for the sum of a register with a constant    integer that is out of range.  If so, generate code to add the    constant with the low-order 16 bits masked to the register and force    this result into another register (this can be done with `cau').    Then generate an address of REG+(CONST&0xffff), allowing for the     possibility of bit 16 being a one.     If the register is not OK for a base register, abort.  */
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
value|{ if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == REG	\&& GET_CODE (XEXP (X, 1)) == CONST_INT			\&& (unsigned) (INTVAL (XEXP (X, 1)) + 0x8000)>= 0x10000)	\     { int high_int, low_int;					\       if (! REG_OK_FOR_BASE_P (XEXP (X, 0)))			\ 	abort ();						\       high_int = INTVAL (XEXP (X, 1))>> 16;			\       low_int = INTVAL (XEXP (X, 1))& 0xffff;			\       if (low_int& 0x8000)					\ 	high_int += 1, low_int |= 0xffff0000;			\       (X) = gen_rtx (PLUS, SImode,				\ 		     force_operand				\ 		     	(gen_rtx (PLUS, SImode, XEXP (X, 0), \ 				  gen_rtx (CONST_INT, VOIDmode, \ 						      high_int<< 16)), 0),\ 		     gen_rtx (CONST_INT, VOIDmode, low_int));	\     }								\ }
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.     On the ROMP this is true only if the address is valid with a zero offset    but not with an offset of four (this means it cannot be used as an    address for DImode or DFmode).  Since we know it is valid, we just check    for an address that is not valid with an offset of four.  */
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
value|{ if (GET_CODE (ADDR) == PLUS					\&& ! LEGITIMATE_ADDRESS_CONSTANT_P (XEXP (ADDR, 1))	\&& ! LEGITIMATE_ADDRESS_INTEGER_P (XEXP (ADDR, 1), 4))	\     goto LABEL;							\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Define this if some processing needs to be done immediately before    emitting code for an insn.     This is used on the ROMP, to compensate for a bug in the floating-point    code.  When a floating-point operation is done with the first and third    operands both the same floating-point register, it will generate bad code    for the MC68881.  So we must detect this.  If it occurs, we patch the     first operand to be fr0 and insert a move insn to move it to the desired    destination.  */
end_comment

begin_define
define|#
directive|define
name|FINAL_PRESCAN_INSN
parameter_list|(
name|INSN
parameter_list|,
name|OPERANDS
parameter_list|,
name|NOPERANDS
parameter_list|)
define|\
value|{ rtx op0, op1, op2, operation, tem;					\     if (NOPERANDS>= 3&& get_attr_type (INSN) == TYPE_FP)		\       {									\ 	op0 = OPERANDS[0];						\ 	operation = OPERANDS[1];					\ 	if (float_conversion (operation, VOIDmode))			\ 	  operation = XEXP (operation, 0);				\         if (float_binary (operation, VOIDmode))				\ 	  {								\ 	    op1 = XEXP (operation, 0), op2 = XEXP (operation, 1);	\ 	    if (float_conversion (op1, VOIDmode))			\ 	      op1 = XEXP (op1, 0);					\ 	    if (float_conversion (op2, VOIDmode))			\ 	      op2 = XEXP (op2, 0);					\ 	    if (rtx_equal_p (op0, op2)					\&& (GET_CODE (operation) == PLUS			\ 		    || GET_CODE (operation) == MULT))			\ 	      tem = op1, op1 = op2, op2 = tem;				\ 	    if (GET_CODE (op0) == REG&& FP_REGNO_P (REGNO (op0))	\&& GET_CODE (op2) == REG&& FP_REGNO_P (REGNO (op2))	\&& REGNO (op0) == REGNO (op2))				\ 	      {								\ 		tem = gen_rtx (REG, GET_MODE (op0), 17);		\ 		emit_insn_after (gen_move_insn (op0, tem), INSN);	\ 		SET_DEST (XVECEXP (PATTERN (INSN), 0, 0)) = tem; 	\ 		OPERANDS[0] = tem;					\ 	      }								\ 	  }								\       }									\   }
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
value|0
end_define

begin_comment
comment|/* This flag, if defined, says the same insns that convert to a signed fixnum    also convert validly to an unsigned one.     We actually lie a bit here as overflow conditions are different.  But    they aren't being checked anyway.  */
end_comment

begin_define
define|#
directive|define
name|FIXUNS_TRUNC_LIKE_FIX_TRUNC
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
comment|/* Nonzero if access to memory by bytes is no faster than for words.    Also non-zero if doing byte operations (specifically shifts) in registers    is undesirable.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|1
end_define

begin_comment
comment|/* Define if normal loads of shorter-than-word items from memory clears    the rest of the bigs in the register.  */
end_comment

begin_define
define|#
directive|define
name|BYTE_LOADS_ZERO_EXTEND
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
comment|/* We don't have GAS for the RT yet, so don't write out special    .stabs in cc1plus.  */
end_comment

begin_define
define|#
directive|define
name|FASCIST_ASSEMBLER
end_define

begin_comment
comment|/* Do not break .stabs pseudos into continuations.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* Don't try to use the `x' type-cross-reference character in DBX data.    Also has the consequence of putting each struct, union or enum    into a separate .stabs, containing only cross-refs to the others.  */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
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
comment|/* Mode of a function address in a call instruction (for indexing purposes).     Doesn't matter on ROMP.  */
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
comment|/* Define this if shift instructions ignore all but the low-order    few bits.     This is not true on the RT since it uses the low-order 6, not 5, bits.    At some point, this should be extended to see how to express that.  */
end_comment

begin_comment
comment|/* #define SHIFT_COUNT_TRUNCATED */
end_comment

begin_comment
comment|/* Compute the cost of computing a constant rtl expression RTX whose    rtx-code is CODE, contained within an expression of code OUTER_CODE.    The body of this macro is a portion of a switch statement.  If the    code is computed here, return it with a return statement.  Otherwise,    break from the switch.  */
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
value|case CONST_INT:						\     if ((OUTER_CODE) == IOR&& exact_log2 (INTVAL (RTX))>= 0	\ 	|| (OUTER_CODE) == AND&& exact_log2 (~INTVAL (RTX))>= 0 \ 	|| (((OUTER_CODE) == PLUS || (OUTER_CODE) == MINUS)	\&& (unsigned int) (INTVAL (RTX) + 15)< 31)		\ 	|| ((OUTER_CODE) == SET&& (unsigned int) INTVAL (RTX)< 16))\       return 0;							\     return ((unsigned int) (INTVAL(RTX) + 0x8000)< 0x10000		\ 	    || (INTVAL (RTX)& 0xffff0000) == 0) ? 0 : COSTS_N_INSNS (2);\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     if (current_function_operand (RTX, Pmode)) return 0;	\     return COSTS_N_INSNS (2);					\   case CONST_DOUBLE:						\     if ((RTX) == CONST0_RTX (GET_MODE (RTX))) return 2;		\     return ((GET_MODE_CLASS (GET_MODE (RTX)) == MODE_FLOAT)	\ 	    ? COSTS_N_INSNS (5) : COSTS_N_INSNS (4));
end_define

begin_comment
comment|/* Provide the costs of a rtl expression.  This is in the body of a    switch on CODE.      References to our own data area are really references to r14, so they    are very cheap.  Multiples and divides are very expensive.  */
end_comment

begin_define
define|#
directive|define
name|RTX_COSTS
parameter_list|(
name|X
parameter_list|,
name|CODE
parameter_list|,
name|OUTER_CODE
parameter_list|)
define|\
value|case MEM:						\     return current_function_operand (X, Pmode) ? 0 : COSTS_N_INSNS (2);	\   case MULT:						\     return (TARGET_IN_LINE_MUL&& GET_MODE_CLASS (GET_MODE (X)) == MODE_INT)\ 	   ? COSTS_N_INSNS (19) : COSTS_N_INSNS (25);	\   case DIV:						\   case UDIV:						\   case MOD:						\   case UMOD:						\     return COSTS_N_INSNS (45);
end_define

begin_comment
comment|/* Compute the cost of an address.  This is meant to approximate the size    and/or execution delay of an insn using that address.  If the cost is    approximated by the RTL complexity, including CONST_COSTS above, as    is usually the case for CISC machines, this macro should not be defined.    For aggressively RISCy machines, only one insn format is allowed, so    this macro should be a constant.  The value of this macro only matters    for valid addresses.     For the ROMP, everything is cost 0 except for addresses involving    symbolic constants, which are cost 1.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|RTX
parameter_list|)
define|\
value|((GET_CODE (RTX) == SYMBOL_REF			\&& ! CONSTANT_POOL_ADDRESS_P (RTX))			\    || GET_CODE (RTX) == LABEL_REF			\    || (GET_CODE (RTX) == CONST				\&& ! constant_pool_address_operand (RTX, Pmode))	\    || (GET_CODE (RTX) == PLUS				\&& ((GET_CODE (XEXP (RTX, 1)) == SYMBOL_REF	\&& ! CONSTANT_POOL_ADDRESS_P (XEXP (RTX, 0))) \ 	   || GET_CODE (XEXP (RTX, 1)) == LABEL_REF	\ 	   || GET_CODE (XEXP (RTX, 1)) == CONST)))
end_define

begin_comment
comment|/* Adjust the length of an INSN.  LENGTH is the currently-computed length and    should be adjusted to reflect any required changes.  This macro is used when    there is some systematic length adjustment required that would be difficult    to express in the length attribute.     On the ROMP, there are two adjustments:  First, a 2-byte insn in the delay    slot of a CALL (including floating-point operations) actually takes four    bytes.  Second, we have to make the worst-case alignment assumption for    address vectors.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_INSN_LENGTH
parameter_list|(
name|X
parameter_list|,
name|LENGTH
parameter_list|)
define|\
value|if (GET_CODE (X) == INSN&& GET_CODE (PATTERN (X)) == SEQUENCE	\&& GET_CODE (XVECEXP (PATTERN (X), 0, 0)) != JUMP_INSN		\&& get_attr_length (XVECEXP (PATTERN (X), 0, 1)) == 2)		\     (LENGTH) += 2;							\   else if (GET_CODE (X) == JUMP_INSN&& GET_CODE (PATTERN (X)) == ADDR_VEC) \     (LENGTH) += 2;
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
comment|/* Set if condition code (really not-Z) is stored in `test bit'.  */
end_comment

begin_define
define|#
directive|define
name|CC_IN_TB
value|01000
end_define

begin_comment
comment|/* Set if condition code is set by an unsigned compare. */
end_comment

begin_define
define|#
directive|define
name|CC_UNSIGNED
value|02000
end_define

begin_comment
comment|/* Store in cc_status the expressions    that the condition codes will describe    after execution of an instruction whose pattern is EXP.    Do not alter them if the instruction would not alter the cc's.  */
end_comment

begin_define
define|#
directive|define
name|NOTICE_UPDATE_CC
parameter_list|(
name|BODY
parameter_list|,
name|INSN
parameter_list|)
define|\
value|update_cc (BODY, INSN)
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
value|{ extern char *version_string;				\   char *p;						\ 							\   fprintf (FILE, "\t.globl .oVncs\n\t.set .oVncs,0\n") ; \   fprintf (FILE, "\t.globl .oVgcc");			\   for (p = version_string; *p != ' '&& *p != 0; p++)	\     fprintf (FILE, "%c", *p);				\   fprintf (FILE, "\n\t.set .oVgcc");			\   for (p = version_string; *p != ' '&& *p != 0; p++)	\     fprintf (FILE, "%c", *p);				\   fprintf (FILE, ",0\n");				\ }
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
comment|/* Output before instructions and read-only data.  */
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
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9",	\  "r10", "r11", "r12", "r13", "r14", "r15", "ap",		\  "fr0", "fr1", "fr2", "fr3", "fr4", "fr5", "fr6", "fr7" }
end_define

begin_comment
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
comment|/* This is how to output a label for a jump table.  Arguments are the same as    for ASM_OUTPUT_INTERNAL_LABEL, except the insn for the jump table is    passed. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|TABLEINSN
parameter_list|)
define|\
value|{ ASM_OUTPUT_ALIGN (FILE, 2); ASM_OUTPUT_INTERNAL_LABEL (FILE, PREFIX, NUM); }
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
value|fprintf (FILE, "\t.double 0d%.20e\n", (VALUE))
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.     WARNING:  Believe it or not, the ROMP assembler has a bug in its    handling of single-precision floating-point values making it impossible    to output such values in the expected way.  Therefore, it must be output    in hex.  THIS WILL NOT WORK IF CROSS-COMPILING FROM A MACHINE THAT DOES    NOT USE IEEE-FORMAT FLOATING-POINT, but there is nothing that can be done    about it short of fixing the assembler.  */
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
value|do { union { int i; float f; } u_i_f;		\        u_i_f.f = (VALUE);			\        fprintf (FILE, "\t.long 0x%x\n", u_i_f.i);\      } while (0)
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
value|( fprintf (FILE, "\t.short "),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
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
comment|/* This is how to output code to push a register on the stack.    It need not be very fast code.  */
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
value|fprintf (FILE, "\tsis r1,4\n\tsts %s,0(r1)\n", reg_names[REGNO])
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
value|fprintf (FILE, "\tls r1,0(r1)\n\tais r1,4\n", reg_names[REGNO])
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
value|fprintf (FILE, "\t.long L%d\n", VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    (ROMP does not use such vectors,    but we must define this macro anyway.)  */
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
value|abort ()
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
value|if ((LOG) != 0)			\     fprintf (FILE, "\t.align %d\n", (LOG))
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
value|fprintf (FILE, "\t.space %d\n", (SIZE))
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
value|( fputs (".comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%d\n", (SIZE)))
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
value|( fputs (".lcomm ", (FILE)),				\   assemble_name ((FILE), (NAME)),			\   fprintf ((FILE), ",%d\n", (SIZE)))
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
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    For `%' followed by punctuation, CODE is the punctuation and X is null.  */
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
value|print_operand (FILE, X, CODE)
end_define

begin_comment
comment|/* Define which CODE values are valid.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '.' || (CODE) == '#')
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
value|{ register rtx addr = ADDR;					\   register rtx base = 0, offset = addr;				\   if (GET_CODE (addr) == REG)					\     base = addr, offset = const0_rtx;				\   else if (GET_CODE (addr) == PLUS				\&& GET_CODE (XEXP (addr, 0)) == REG)			\     base = XEXP (addr, 0), offset = XEXP (addr, 1);		\   else if (GET_CODE (addr) == SYMBOL_REF			\&& CONSTANT_POOL_ADDRESS_P (addr))			\     {								\       offset = gen_rtx (CONST_INT, VOIDmode, get_pool_offset (addr) + 12);  \       base = gen_rtx (REG, SImode, 14);				\     }								\   else if (GET_CODE (addr) == CONST				\&& GET_CODE (XEXP (addr, 0)) == PLUS			\&& GET_CODE (XEXP (XEXP (addr, 0), 1)) == CONST_INT	\&& GET_CODE (XEXP (XEXP (addr, 0), 0)) == SYMBOL_REF	\&& CONSTANT_POOL_ADDRESS_P (XEXP (XEXP (addr, 0), 0))) \     {								\       offset = plus_constant (XEXP (XEXP (addr, 0), 1),		\ 			      (get_pool_offset (XEXP (XEXP (addr, 0), 0)) \ 			       + 12));				\       base = gen_rtx (REG, SImode, 14);				\     }								\   output_addr_const (FILE, offset);				\   if (base)							\     fprintf (FILE, "(%s)", reg_names [REGNO (base)]);		\ }
end_define

begin_comment
comment|/* Define the codes that are matched by predicates in aux-output.c.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"zero_memory_operand", {SUBREG, MEM}},			\   {"short_memory_operand", {SUBREG, MEM}},			\   {"symbolic_memory_operand", {SUBREG, MEM}},			\   {"current_function_operand", {MEM}},				\   {"constant_pool_address_operand", {SUBREG, CONST}},		\   {"romp_symbolic_operand", {LABEL_REF, SYMBOL_REF, CONST}},	\   {"constant_operand", {LABEL_REF, SYMBOL_REF, PLUS, CONST, CONST_INT}}, \   {"reg_or_cint_operand", {SUBREG, REG, CONST_INT}},		\   {"reg_or_any_cint_operand", {SUBREG, REG, CONST_INT}},	\   {"short_cint_operand", {CONST_INT}},				\   {"reg_or_D_operand", {SUBREG, REG, CONST_INT}},		\   {"reg_or_add_operand", {SUBREG, REG, LABEL_REF, SYMBOL_REF,	\ 			  PLUS, CONST, CONST_INT}}, 		\   {"reg_or_and_operand", {SUBREG, REG, CONST_INT}},		\   {"reg_or_mem_operand", {SUBREG, REG, MEM}},			\   {"reg_or_nonsymb_mem_operand", {SUBREG, REG, MEM}},		\   {"romp_operand", {SUBREG, MEM, REG, CONST_INT, CONST, LABEL_REF, \ 		    SYMBOL_REF, CONST_DOUBLE}},			\   {"reg_0_operand", {REG}},					\   {"reg_15_operand", {REG}},					\   {"float_binary", {PLUS, MINUS, MULT, DIV}},			\   {"float_unary", {NEG, ABS}},					\   {"float_conversion", {FLOAT_TRUNCATE, FLOAT_EXTEND, FLOAT, FIX}},
end_define

begin_comment
comment|/* Define functions defined in aux-output.c and used in templates.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_in_line_mul
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_fpop
parameter_list|()
function_decl|;
end_function_decl

end_unit

