begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for IBM RS/6000.    Copyright (C) 1992 Free Software Foundation, Inc.    Contributed by Richard Kenner (kenner@nyu.edu)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
value|"-D_IBMR2 -D_AIX"
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
comment|/* Tell the assembler to assume that all undefined names are external.     Don't do this until the fixed IBM assembler is more generally available.    When this becomes permanently defined, the ASM_OUTPUT_EXTERNAL,    ASM_OUTPUT_EXTERNAL_LIBCALL, and RS6000_OUTPUT_BASENAME macros will no    longer be needed.  */
end_comment

begin_comment
comment|/* #define ASM_SPEC "-u" */
end_comment

begin_comment
comment|/* Define the options for the binder: Start text at 512, align all segments    to 512 bytes, and warn if there is text relocation.     The -bhalt:4 option supposedly changes the level at which ld will abort,    but it also suppresses warnings about multiply defined symbols and is    used by the AIX cc command.  So we use it here.     -bnodelcsect undoes a poor choice of default relating to multiply-defined    csects.  See AIX documentation for more information about this.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-T512 -H512 -btextro -bhalt:4 -bnodelcsect\    %{static:-bnso -bI:/lib/syscalls.exp}"
end_define

begin_comment
comment|/* Profiled library versions are used by linking with special directories.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{pg:-L/lib/profiled -L/usr/lib/profiled}\    %{p:-L/lib/profiled -L/usr/lib/profiled} %{g*:-lg} -lc"
end_define

begin_comment
comment|/* gcc must do the search itself to find libgcc.a, not use -l.  */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL_1
end_define

begin_comment
comment|/* Don't turn -B into -L if the argument specifies a relative file name.  */
end_comment

begin_define
define|#
directive|define
name|RELATIVE_PREFIX_NOT_LINKDIR
end_define

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.  */
end_comment

begin_comment
comment|/* Flag to allow putting fp constants in the TOC; can be turned off when    the TOC overflows.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FP_IN_TOC
value|(target_flags& 1)
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
value|{{"fp-in-toc", 1},		\    {"no-fp-in-toc", -1},	\    { "", TARGET_DEFAULT}}
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_comment
comment|/* On the RS/6000, we turn on various flags if optimization is selected.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|)
define|\
value|{					\   if ((LEVEL)> 0)			\     {					\       flag_force_mem = 1;		\       flag_omit_frame_pointer = 1;	\     }					\ }
end_define

begin_comment
comment|/* Define this to modify the options specified by the user.  */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|{					\    profile_block_flag = 0;		\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define this macro if it is advisible to hold scalars in registers    in a wider mode than that declared by the program.  In such cases,     the value is constrained to be within the bounds of the declared    type, but kept valid in the wider mode.  The signedness of the    extension may differ from that of the type.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_MODE
parameter_list|(
name|MODE
parameter_list|,
name|UNSIGNEDP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|if (GET_MODE_CLASS (MODE) == MODE_INT	\&& GET_MODE_SIZE (MODE)< 4)  	\     (MODE) == SImode;
end_define

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields. */
end_comment

begin_comment
comment|/* That is true on RS/6000. */
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
comment|/* That is true on RS/6000.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is lowest    numbered.      For RS/6000 we can decide arbitrarily since there are no machine    instructions for them.  Might as well be consistent with bits and bytes. */
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
comment|/* Type used for ptrdiff_t, as a string used in a declaration.  */
end_comment

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_comment
comment|/* Type used for wchar_t, as a string used in a declaration.  */
end_comment

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_comment
comment|/* Width of wchar_t in bits.  */
end_comment

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
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
comment|/* Non-zero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|0
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     RS/6000 has 32 fixed-point registers, 32 floating-point registers,    an MQ register, a count register, a link register, and 8 condition    register fields, which we view here as separate registers.     In addition, the difference between the frame and argument pointers is    a function of the number of registers saved, so we need to have a    register for AP that will later be eliminated in favor of SP or FP.    This is a normal register, but it is fixed.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|76
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.     On RS/6000, r1 is used for the stack and r2 is used as the TOC pointer.       cr5 is not supposed to be used.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, \    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, \    1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1}
end_define

begin_comment
comment|/* List the order in which to allocate registers.  Each register must be    listed once, even those in FIXED_REGISTERS.     We allocate in the following order: 	fp0		(not saved or used for anything) 	fp13 - fp2	(not saved; incoming fp arg registers) 	fp1		(not saved; return value)  	fp31 - fp14	(saved; order given to save least number) 	cr1, cr6, cr7	(not saved or special) 	cr0		(not saved, but used for arithmetic operations) 	cr2, cr3, cr4	(saved)         r0		(not saved; cannot be base reg) 	r9		(not saved; best for TImode) 	r11, r10, r8-r4	(not saved; highest used first to make less conflict) 	r3     		(not saved; return value register) 	r31 - r13	(saved; order given to save least number) 	r12		(not saved; if used for DImode or DFmode would use r13) 	mq		(not saved; best to use it if we can) 	ctr		(not saved; when we have the choice ctr is better) 	lr		(saved)         cr5, r1, r2, ap	(fixed)  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{32, 							\    45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34,	\    33,							\    63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51,	\    50, 49, 48, 47, 46, 					\    69, 74, 75, 68, 70, 71, 72,				\    0,							\    9, 11, 10, 8, 7, 6, 5, 4,				\    3,							\    31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19,	\    18, 17, 16, 15, 14, 13, 12,				\    64, 66, 65, 						\    73, 1, 2, 67}
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
value|((N)>= 32&& (N)<= 63)
end_define

begin_comment
comment|/* True if register is a condition register.  */
end_comment

begin_define
define|#
directive|define
name|CR_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= 68&& (N)<= 75)
end_define

begin_comment
comment|/* True if register is an integer register.  */
end_comment

begin_define
define|#
directive|define
name|INT_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)<= 31 || (N) == 67)
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On RS/6000, ordinary registers hold 32 bits worth;    a single floating point register holds 64 bits worth.  */
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
value|(FP_REGNO_P (REGNO)			\    ? ((GET_MODE_SIZE (MODE) + 2 * UNITS_PER_WORD - 1) / (2 * UNITS_PER_WORD)) \    : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On RS/6000, the cpu registers can hold any mode but the float registers    can hold only floating modes and CR register can only hold CC modes.  We    cannot put DImode or TImode anywhere except general register and they    must be able to fit within the register set.  */
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
value|(FP_REGNO_P (REGNO) ? GET_MODE_CLASS (MODE) == MODE_FLOAT	\    : CR_REGNO_P (REGNO) ? GET_MODE_CLASS (MODE) == MODE_CC	\    : ! INT_REGNO_P (REGNO) ? GET_MODE_CLASS (MODE) == MODE_INT	\    : 1)
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
value|(GET_MODE_CLASS (MODE1) == MODE_FLOAT		\    ? GET_MODE_CLASS (MODE2) == MODE_FLOAT	\    : GET_MODE_CLASS (MODE2) == MODE_FLOAT	\    ? GET_MODE_CLASS (MODE1) == MODE_FLOAT	\    : GET_MODE_CLASS (MODE1) == MODE_CC		\    ? GET_MODE_CLASS (MODE2) == MODE_CC		\    : GET_MODE_CLASS (MODE2) == MODE_CC		\    ? GET_MODE_CLASS (MODE1) == MODE_CC		\    : 1)
end_define

begin_comment
comment|/* A C expression returning the cost of moving data from a register of class    CLASS1 to one of CLASS2.     On the RS/6000, copying between floating-point and fixed-point    registers is expensive.  */
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
value|((CLASS1) == FLOAT_REGS&& (CLASS2) == FLOAT_REGS ? 2		\    : (CLASS1) == FLOAT_REGS&& (CLASS2) != FLOAT_REGS ? 10	\    : (CLASS1) != FLOAT_REGS&& (CLASS2) == FLOAT_REGS ? 10	\    : 2)
end_define

begin_comment
comment|/* A C expressions returning the cost of moving data of MODE from a register to    or from memory.     On the RS/6000, bump this up a bit.  */
end_comment

begin_define
define|#
directive|define
name|MEMORY_MOVE_COST
parameter_list|(
name|MODE
parameter_list|)
value|6
end_define

begin_comment
comment|/* Specify the cost of a branch insn; roughly the number of extra insns that    should be added to avoid a branch.     Set this to 3 on the RS/6000 since that is roughly the average cost of an    unscheduled conditional branch.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_COST
value|3
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* RS/6000 pc isn't overloaded on a register that the compiler knows about.  */
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
value|31
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
value|67
end_define

begin_comment
comment|/* Place to put static chain when calling a function that requires it.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|11
end_define

begin_comment
comment|/* Place that structure value return address is placed.     On the RS/6000, it is passed as an extra parameter.  */
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
comment|/* The RS/6000 has three types of registers, fixed-point, floating-point,    and condition registers, plus three special registers, MQ, CTR, and the    link register.     However, r0 is special in that it cannot be used as a base register.    So make a class for registers valid as base registers.     Also, cr0 is the only condition code register that can be used in    arithmetic insns, so make a separate class for it. */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|BASE_REGS
block|,
name|GENERAL_REGS
block|,
name|FLOAT_REGS
block|,
name|NON_SPECIAL_REGS
block|,
name|MQ_REGS
block|,
name|LINK_REGS
block|,
name|CTR_REGS
block|,
name|LINK_OR_CTR_REGS
block|,
name|SPECIAL_REGS
block|,
name|SPEC_OR_GEN_REGS
block|,
name|CR0_REGS
block|,
name|CR_REGS
block|,
name|NON_FLOAT_REGS
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
value|{ "NO_REGS", "BASE_REGS", "GENERAL_REGS", "FLOAT_REGS",	\     "NON_SPECIAL_REGS", "MQ_REGS", "LINK_REGS", "CTR_REGS",	\     "LINK_OR_CTR_REGS", "SPECIAL_REGS", "SPEC_OR_GEN_REGS",	\     "CR0_REGS", "CR_REGS", "NON_FLOAT_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{ {0, 0, 0}, {0xfffffffe, 0, 8}, {~0, 0, 8},		\     {0, ~0, 0}, {~0, ~0, 8}, {0, 0, 1}, {0, 0, 2},	\     {0, 0, 4}, {0, 0, 6}, {0, 0, 7}, {~0, 0, 15},	\     {0, 0, 16}, {0, 0, 0xff0}, {~0, 0, 0xffff},		\     {~0, ~0, 0xffff} }
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
value|((REGNO) == 0 ? GENERAL_REGS	\   : (REGNO)< 32 ? BASE_REGS	\   : FP_REGNO_P (REGNO) ? FLOAT_REGS \   : (REGNO) == 68 ? CR0_REGS	\   : CR_REGNO_P (REGNO) ? CR_REGS \   : (REGNO) == 64 ? MQ_REGS	\   : (REGNO) == 65 ? LINK_REGS	\   : (REGNO) == 66 ? CTR_REGS	\   : (REGNO) == 67 ? BASE_REGS	\   : NO_REGS)
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
value|((C) == 'f' ? FLOAT_REGS	\    : (C) == 'b' ? BASE_REGS	\    : (C) == 'h' ? SPECIAL_REGS	\    : (C) == 'q' ? MQ_REGS	\    : (C) == 'c' ? CTR_REGS	\    : (C) == 'l' ? LINK_REGS	\    : (C) == 'x' ? CR0_REGS	\    : (C) == 'y' ? CR_REGS	\    : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L, M, N, and P in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     `I' is signed 16-bit constants     `J' is a constant with only the high-order 16 bits non-zero    `K' is a constant with only the low-order 16 bits non-zero    `L' is a constant that can be placed into a mask operand    `M' is a constant that is greater than 31    `N' is a constant that is an exact power of two    `O' is the constant zero    `P' is a constant whose negation is a signed 16-bit constant */
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
value|( (C) == 'I' ? (unsigned) ((VALUE) + 0x8000)< 0x10000	\    : (C) == 'J' ? ((VALUE)& 0xffff) == 0			\    : (C) == 'K' ? ((VALUE)& 0xffff0000) == 0			\    : (C) == 'L' ? mask_constant (VALUE)				\    : (C) == 'M' ? (VALUE)> 31					\    : (C) == 'N' ? exact_log2 (VALUE)>= 0			\    : (C) == 'O' ? (VALUE) == 0					\    : (C) == 'P' ? (unsigned) ((- (VALUE)) + 0x8000)< 0x1000	\    : 0)
end_define

begin_comment
comment|/* Similar, but for floating constants, and defining letters G and H.    Here VALUE is the CONST_DOUBLE rtx itself.     We flag for special constants when we can copy the constant into    a general register in two insns for DF and one insn for SF.  */
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
value|((C) == 'G' ? easy_fp_constant (VALUE, GET_MODE (VALUE)) : 0)
end_define

begin_comment
comment|/* Optional extra constraints for this machine.     For the RS/6000, `Q' means that this is a memory operand that is just    an offset from a register.  */
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
value|((C) == 'Q' ? GET_CODE (OP) == MEM&& GET_CODE (XEXP (OP, 0)) == REG	\    : 0)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.      On the RS/6000, we have to return NO_REGS when we want to reload a    floating-point CONST_DOUBLE to force it to be copied to memory.  */
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
value|((GET_CODE (X) == CONST_DOUBLE			\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT)	\    ? NO_REGS : (CLASS))
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
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.     On RS/6000, this is the size of MODE in words,    except in the FP regs, where a single reg is enough for two words.  */
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
value|((CLASS) == FLOAT_REGS			\   ? ((GET_MODE_SIZE (MODE) + 2 * UNITS_PER_WORD - 1) / (2 * UNITS_PER_WORD)) \   : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
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
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.     On the RS/6000, we grow upwards, from the area after the outgoing    arguments.  */
end_comment

begin_comment
comment|/* #define FRAME_GROWS_DOWNWARD */
end_comment

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.      On the RS/6000, the frame pointer is the same as the stack pointer,    except for dynamic allocations.  So we start after the fixed area and    outgoing parameter area.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|(current_function_outgoing_args_size + 24)
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On RS/6000, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/*  #define PUSH_ROUNDING(BYTES) */
end_comment

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.    On the RS/6000, we define the argument pointer to the start of the fixed    area.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|24
end_define

begin_comment
comment|/* Define this if stack space is still allocated for a parameter passed    in a register.  The value is the number of bytes allocated to this    area.  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|FNDECL
parameter_list|)
value|32
end_define

begin_comment
comment|/* Define this if the above stack space is to be considered part of the    space allocated by the caller.  */
end_comment

begin_define
define|#
directive|define
name|OUTGOING_REG_PARM_STACK_SPACE
end_define

begin_comment
comment|/* This is the difference between the logical top of stack and the actual sp.     For the RS/6000, sp points past the fixed area. */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|24
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
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.     On RS/6000 an integer value is in r3 and a floating-point value is in     fp1.  */
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
value|gen_rtx (REG, TYPE_MODE (VALTYPE),	\ 	   TREE_CODE (VALTYPE) == REAL_TYPE ? 33 : 3)
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
value|gen_rtx (REG, MODE, GET_MODE_CLASS (MODE) == MODE_FLOAT ? 33 : 3)
end_define

begin_comment
comment|/* The definition of this macro implies that there are cases where    a scalar value cannot be returned in registers.     For the RS/6000, any structure or union type is returned in memory.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TREE_CODE (TYPE) == RECORD_TYPE || TREE_CODE (TYPE) == UNION_TYPE)
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value    as seen by the caller.     On RS/6000, this is r3 and fp1.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 3 || ((N) == 33))
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On RS/6000, these are r3-r10 and fp1-fp13.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
define|\
value|(((N)<= 10&& (N)>= 3) || ((N)>= 33&& (N)<= 45))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the RS/6000, this is a structure.  The first element is the number of    total argument words, the second is used to store the next    floating-point register number, and the third says how many more args we    have prototype types for.  */
end_comment

begin_struct
struct|struct
name|rs6000_args
block|{
name|int
name|words
decl_stmt|,
name|fregno
decl_stmt|,
name|nargs_prototype
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|struct rs6000_args
end_define

begin_comment
comment|/* Define intermediate macro to compute the size (in registers) of an argument    for the RS/6000.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_ARG_SIZE
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
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.  */
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
value|(CUM).words = 0,				\   (CUM).fregno = 33,				\   (CUM).nargs_prototype = (FNTYPE&& TYPE_ARG_TYPES (FNTYPE)		\ 			   ? (list_length (TYPE_ARG_TYPES (FNTYPE)) - 1 \ 			      + (TYPE_MODE (TREE_TYPE (FNTYPE)) == BLKmode \ 				 || RETURN_IN_MEMORY (TREE_TYPE (FNTYPE)))) \ 			   : 0)
end_define

begin_comment
comment|/* Similar, but when scanning the definition of a procedure.  We always    set NARGS_PROTOTYPE large so we never return an EXPR_LIST.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_INCOMING_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
parameter_list|,
name|IGNORE
parameter_list|)
define|\
value|(CUM).words = 0,				\   (CUM).fregno = 33,				\   (CUM).nargs_prototype = 1000
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
value|{ (CUM).nargs_prototype--;				\   if (NAMED)						\     {							\       (CUM).words += RS6000_ARG_SIZE (MODE, TYPE, NAMED); \       if (GET_MODE_CLASS (MODE) == MODE_FLOAT)		\ 	(CUM).fregno++;					\     }							\ }
end_define

begin_comment
comment|/* Non-zero if we can use a floating-point register to pass this arg.  */
end_comment

begin_define
define|#
directive|define
name|USE_FP_FOR_ARG_P
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(GET_MODE_CLASS (MODE) == MODE_FLOAT&& (CUM).fregno< 46)
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).     On RS/6000 the first eight words of non-FP are normally in registers    and the rest are pushed.  The first 13 FP args are in registers.     If this is floating-point and no prototype is specified, we use    both an FP and integer register (or possibly FP reg and stack).  Library    functions (when TYPE is zero) always have the proper types for args,    so we can pass the FP value just in one register.  emit_library_function    doesn't support EXPR_LIST anyway.  */
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
value|(! (NAMED) ? 0							\    : ((TYPE) != 0&& TREE_CODE (TYPE_SIZE (TYPE)) != INTEGER_CST) ? 0	\    : USE_FP_FOR_ARG_P (CUM, MODE, TYPE)					\    ? ((CUM).nargs_prototype> 0 || (TYPE) == 0				\       ? gen_rtx (REG, MODE, (CUM).fregno)				\       : ((CUM).words< 8						\ 	 ? gen_rtx (EXPR_LIST, VOIDmode,				\ 		    gen_rtx (REG, (MODE), 3 + (CUM).words),		\ 		    gen_rtx (REG, (MODE), (CUM).fregno))		\ 	 : gen_rtx (EXPR_LIST, VOIDmode, 0,				\ 		    gen_rtx (REG, (MODE), (CUM).fregno))))		\    : (CUM).words< 8 ? gen_rtx(REG, (MODE), 3 + (CUM).words) : 0)
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
value|(! (NAMED) ? 0							\    : USE_FP_FOR_ARG_P (CUM, MODE, TYPE)&& (CUM).nargs_prototype>= 0 ? 0 \    : (((CUM).words< 8							\&& 8< ((CUM).words + RS6000_ARG_SIZE (MODE, TYPE, NAMED)))	\       ? 8 - (CUM).words : 0))
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
value|{ if ((CUM).words< 8)							\     {									\       int first_reg_offset = (CUM).words;				\ 									\       if (MUST_PASS_IN_STACK (MODE, TYPE))				\ 	first_reg_offset += RS6000_ARG_SIZE (TYPE_MODE (TYPE), TYPE, 1); \ 									\       if (first_reg_offset> 8)						\ 	first_reg_offset = 8;						\ 									\       if (! (NO_RTL)&& first_reg_offset != 8)				\ 	move_block_from_reg						\ 	  (3 + first_reg_offset,					\ 	   gen_rtx (MEM, BLKmode,					\ 		    plus_constant (virtual_incoming_args_rtx,		\ 				   first_reg_offset * 4)),		\ 	   8 - first_reg_offset);					\       PRETEND_SIZE = (8 - first_reg_offset) * UNITS_PER_WORD;		\     }									\ }
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
value|output_function_profiler ((FILE), (LABELNO));
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter. No definition is equivalent to    always zero.     On the RS/6000, this is non-zero because we can restore the stack from    its backpointer, which we maintain.  */
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
value|output_epilog (FILE, SIZE)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     The trampoline should set the static chain pointer to value placed    into the trampoline and should branch to the specified routine.     On the RS/6000, this is not code at all, but merely a data area,    since that is the way all functions are called.  The first word is    the address of the function, the second word is the TOC pointer (r2),    and the third word is the static chain value.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
value|{ fprintf (FILE, "\t.long 0, 0, 0\n"); }
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|12
end_define

begin_comment
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.  */
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
value|{								\   emit_move_insn (gen_rtx (MEM, SImode,				\ 			   memory_address (SImode, (ADDR))),	\ 		  gen_rtx (MEM, SImode,				\ 			   memory_address (SImode, (FNADDR))));	\   emit_move_insn (gen_rtx (MEM, SImode,				\ 			   memory_address (SImode,		\ 					   plus_constant ((ADDR), 4))), \ 		  gen_rtx (MEM, SImode,				\ 			   memory_address (SImode,		\ 					   plus_constant ((FNADDR), 4)))); \   emit_move_insn (gen_rtx (MEM, SImode,				\ 			   memory_address (SImode,		\ 					   plus_constant ((ADDR), 8))), \ 		  force_reg (SImode, (CXT)));			\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Definitions for register eliminations.     We have two registers that can be eliminated on the RS/6000.  First, the    frame pointer register can often be eliminated in favor of the stack    pointer register.  Secondly, the argument pointer register can always be    eliminated; it is replaced with either the stack or frame pointer.  */
end_comment

begin_comment
comment|/* This is an array of structures.  Each structure initializes one pair    of eliminable registers.  The "from" register number is given first,    followed by "to".  Eliminations of the same "from" register are listed    in order of preference.  */
end_comment

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM},	\  { ARG_POINTER_REGNUM, STACK_POINTER_REGNUM},	\  { ARG_POINTER_REGNUM, FRAME_POINTER_REGNUM} }
end_define

begin_comment
comment|/* Given FROM and TO register numbers, say whether this elimination is allowed.    Frame pointer elimination is automatically handled.     For the RS/6000, if frame pointer elimination is being done, we would like    to convert ap into fp, not sp.  */
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
value|((FROM) == ARG_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM	\   ? ! frame_pointer_needed					\   : 1)
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
value|{									\   int total_stack_size = (rs6000_sa_size () + get_frame_size ()		\ 			  + current_function_outgoing_args_size);	\ 									\   total_stack_size = (total_stack_size + 7)& ~7;			\ 									\  if ((FROM) == FRAME_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM)	\     {									\       if (rs6000_pushes_stack ())					\ 	(OFFSET) = 0;							\       else								\ 	(OFFSET) = - total_stack_size;					\     }									\   else if ((FROM) == ARG_POINTER_REGNUM&& (TO) == FRAME_POINTER_REGNUM) \       (OFFSET) = total_stack_size;					\   else if ((FROM) == ARG_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM) \     {									\       if (rs6000_pushes_stack ())					\ 	(OFFSET) = total_stack_size;					\       else								\ 	(OFFSET) = 0;							\     }									\   else									\     abort ();								\ }
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

begin_define
define|#
directive|define
name|HAVE_PRE_DECREMENT
end_define

begin_define
define|#
directive|define
name|HAVE_PRE_INCREMENT
end_define

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
value|((REGNO)< FIRST_PSEUDO_REGISTER				\  ? (REGNO)<= 31 || (REGNO) == 67				\  : (reg_renumber[REGNO]>= 0					\&& (reg_renumber[REGNO]<= 31 || reg_renumber[REGNO] == 67)))
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< FIRST_PSEUDO_REGISTER				\  ? ((REGNO)> 0&& (REGNO)<= 31) || (REGNO) == 67		\  : (reg_renumber[REGNO]> 0					\&& (reg_renumber[REGNO]<= 31 || reg_renumber[REGNO] == 67)))
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
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.     On the RS/6000, all integer constants are acceptable, most won't be valid    for particular insns, though.  Only easy FP constants are    acceptable.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) != CONST_DOUBLE || GET_MODE (X) == VOIDmode	\    || easy_fp_constant (X, GET_MODE (X)))
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
value|(REGNO (X)<= 31 || REGNO (X) == 67 || REGNO (X)>= FIRST_PSEUDO_REGISTER)
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
value|(REGNO (X)> 0&& REG_OK_FOR_INDEX_P (X))
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
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     On the RS/6000, there are four valid address: a SYMBOL_REF that    refers to a constant pool entry of an address (or the sum of it    plus a constant), a short (16-bit signed) constant plus a register,    the sum of two registers, or a register indirect, possibly with an    auto-increment.  For DFmode and DImode with an constant plus register,    we must ensure that both words are addressable.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_POOL_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == SYMBOL_REF&& CONSTANT_POOL_ADDRESS_P (X)		\&& ASM_OUTPUT_SPECIAL_POOL_ENTRY_P (get_pool_constant (X)))
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_POOL_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(LEGITIMATE_CONSTANT_POOL_BASE_P (X)					\    || (GET_CODE (X) == CONST&& GET_CODE (XEXP (X, 0)) == PLUS		\&& GET_CODE (XEXP (XEXP (X, 0), 1)) == CONST_INT			\&& LEGITIMATE_CONSTANT_POOL_BASE_P (XEXP (XEXP (X, 0), 0))))
end_define

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
name|LEGITIMATE_OFFSET_ADDRESS_P
parameter_list|(
name|MODE
parameter_list|,
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == PLUS					\&& GET_CODE (XEXP (X, 0)) == REG			\&& REG_OK_FOR_BASE_P (XEXP (X, 0))			\&& LEGITIMATE_ADDRESS_INTEGER_P (XEXP (X, 1), 0)	\&& (((MODE) != DFmode&& (MODE) != DImode)		\       || LEGITIMATE_ADDRESS_INTEGER_P (XEXP (X, 1), 4)))
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_INDEXED_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == PLUS				\&& GET_CODE (XEXP (X, 0)) == REG		\&& GET_CODE (XEXP (X, 1)) == REG		\&& ((REG_OK_FOR_BASE_P (XEXP (X, 0))		\&& REG_OK_FOR_INDEX_P (XEXP (X, 1)))	\       || (REG_OK_FOR_BASE_P (XEXP (X, 1))	\&& REG_OK_FOR_INDEX_P (XEXP (X, 0)))))
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_INDIRECT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))
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
value|{ if (LEGITIMATE_INDIRECT_ADDRESS_P (X))		\     goto ADDR;						\   if (GET_CODE (X) == PRE_INC				\&& LEGITIMATE_INDIRECT_ADDRESS_P (XEXP (X, 0)))	\     goto ADDR;						\   if (GET_CODE (X) == PRE_DEC				\&& LEGITIMATE_INDIRECT_ADDRESS_P (XEXP (X, 0)))	\     goto ADDR;						\   if (LEGITIMATE_CONSTANT_POOL_ADDRESS_P (X))		\     goto ADDR;						\   if (LEGITIMATE_OFFSET_ADDRESS_P (MODE, X))		\     goto ADDR;						\   if ((MODE) != DImode&& (MODE) != TImode		\&& LEGITIMATE_INDEXED_ADDRESS_P (X))		\     goto ADDR;						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     On RS/6000, first check for the sum of a register with a constant    integer that is out of range.  If so, generate code to add the    constant with the low-order 16 bits masked to the register and force    this result into another register (this can be done with `cau').    Then generate an address of REG+(CONST&0xffff), allowing for the     possibility of bit 16 being a one.     Then check for the sum of a register and something not constant, try to    load the other things into a register and return the sum.  */
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
value|{ if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == REG	\&& GET_CODE (XEXP (X, 1)) == CONST_INT			\&& (unsigned) (INTVAL (XEXP (X, 1)) + 0x8000)>= 0x10000)	\     { int high_int, low_int;					\       high_int = INTVAL (XEXP (X, 1))>> 16;			\       low_int = INTVAL (XEXP (X, 1))& 0xffff;			\       if (low_int& 0x8000)					\ 	high_int += 1, low_int |= 0xffff0000;			\       (X) = gen_rtx (PLUS, SImode,				\ 		     force_operand				\ 		     	(gen_rtx (PLUS, SImode, XEXP (X, 0), \ 				  gen_rtx (CONST_INT, VOIDmode, \ 						      high_int<< 16)), 0),\ 		     gen_rtx (CONST_INT, VOIDmode, low_int));	\       goto WIN;							\     }								\   else if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == REG \&& GET_CODE (XEXP (X, 1)) != CONST_INT		\&& (MODE) != DImode&& (MODE) != TImode) 		\     {								\       (X) = gen_rtx (PLUS, SImode, XEXP (X, 0),			\ 		     force_reg (SImode, force_operand (XEXP (X, 1), 0))); \       goto WIN;							\     }								\ }
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.     On the RS/6000 this is true if the address is valid with a zero offset    but not with an offset of four (this means it cannot be used as an    address for DImode or DFmode) or is a pre-increment or decrement.  Since    we know it is valid, we just check for an address that is not valid with    an offset of four.  */
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
value|{ if (GET_CODE (ADDR) == PLUS					\&& LEGITIMATE_ADDRESS_INTEGER_P (XEXP (ADDR, 1), 0)	\&& ! LEGITIMATE_ADDRESS_INTEGER_P (XEXP (ADDR, 1), 4))	\     goto LABEL;							\   if (GET_CODE (ADDR) == PRE_INC)				\     goto LABEL;							\   if (GET_CODE (ADDR) == PRE_DEC)				\     goto LABEL;							\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Define this if some processing needs to be done immediately before    emitting code for an insn. */
end_comment

begin_comment
comment|/* #define FINAL_PRESCAN_INSN(INSN,OPERANDS,NOPERANDS) */
end_comment

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
value|0
end_define

begin_comment
comment|/* This flag, if defined, says the same insns that convert to a signed fixnum    also convert validly to an unsigned one.  */
end_comment

begin_comment
comment|/* #define FIXUNS_TRUNC_LIKE_FIX_TRUNC */
end_comment

begin_comment
comment|/* Max number of bytes we can move from memory to memory    in one reasonably fast instruction.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|16
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

begin_escape
end_escape

begin_comment
comment|/* The RS/6000 uses the XCOFF format.  */
end_comment

begin_define
define|#
directive|define
name|XCOFF_DEBUGGING_INFO
end_define

begin_comment
comment|/* Define if the object format being used is COFF or a superset.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_COFF
end_define

begin_comment
comment|/* We don't have GAS for the RS/6000 yet, so don't write out special    .stabs in cc1plus.  */
end_comment

begin_define
define|#
directive|define
name|FASCIST_ASSEMBLER
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
comment|/* Mode of a function address in a call instruction (for indexing purposes).     Doesn't matter on RS/6000.  */
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
comment|/* Define this if shift instructions ignore all but the low-order    few bits. */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
end_define

begin_comment
comment|/* Use atexit for static constructors/destructors, instead of defining    our own exit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Compute the cost of computing a constant rtl expression RTX    whose rtx-code is CODE.  The body of this macro is a portion    of a switch statement.  If the code is computed here,    return it with a return statement.  Otherwise, break from the switch.     On the RS/6000, if it is legal in the insn, it is free.  So this    always returns 0.  */
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
value|case CONST_INT:						\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\   case CONST_DOUBLE:						\     return 0;
end_define

begin_comment
comment|/* Provide the costs of a rtl expression.  This is in the body of a    switch on CODE.  */
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
value|case MULT:						\     return (GET_CODE (XEXP (X, 1)) != CONST_INT		\ 	    ? COSTS_N_INSNS (5)				\ 	    : INTVAL (XEXP (X, 1))>= -256&& INTVAL (XEXP (X, 1))<= 255 \ 	    ? COSTS_N_INSNS (3) : COSTS_N_INSNS (4));	\   case DIV:						\   case MOD:						\     if (GET_CODE (XEXP (X, 1)) == CONST_INT		\&& exact_log2 (INTVAL (XEXP (X, 1)))>= 0)	\       return COSTS_N_INSNS (2);				\
comment|/* otherwise fall through to normal divide.  */
value|\   case UDIV:						\   case UMOD:						\     return COSTS_N_INSNS (19);				\   case MEM:						\
comment|/* MEM should be slightly more expensive than (plus (reg) (const)) */
value|\     return 5;
end_define

begin_comment
comment|/* Compute the cost of an address.  This is meant to approximate the size    and/or execution delay of an insn using that address.  If the cost is    approximated by the RTL complexity, including CONST_COSTS above, as    is usually the case for CISC machines, this macro should not be defined.    For aggressively RISCy machines, only one insn format is allowed, so    this macro should be a constant.  The value of this macro only matters    for valid addresses.     For the RS/6000, everything is cost 0.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|RTX
parameter_list|)
value|0
end_define

begin_comment
comment|/* Adjust the length of an INSN.  LENGTH is the currently-computed length and    should be adjusted to reflect any required changes.  This macro is used when    there is some systematic length adjustment required that would be difficult    to express in the length attribute.  */
end_comment

begin_comment
comment|/* #define ADJUST_INSN_LENGTH(X,LENGTH) */
end_comment

begin_comment
comment|/* Add any extra modes needed to represent the condition code.     For the RS/6000, we need separate modes when unsigned (logical) comparisons    are being done and we need a separate mode for floating-point.  We also    use a mode for the case when we are comparing the results of two    comparisons.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_MODES
value|CCUNSmode, CCFPmode, CCEQmode
end_define

begin_comment
comment|/* Define the names for the modes specified above.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_NAMES
value|"CCUNS", "CCFP", "CCEQ"
end_define

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.  For floating-point, CCFPmode    should be used.  CCUNSmode should be used for unsigned comparisons.    CCEQmode should be used when we are doing an inequality comparison on    the result of a comparison. CCmode should be used in all other cases.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_CC_MODE
parameter_list|(
name|OP
parameter_list|,
name|X
parameter_list|,
name|Y
parameter_list|)
define|\
value|(GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT ? CCFPmode	\    : (OP) == GTU || (OP) == LTU || (OP) == GEU || (OP) == LEU ? CCUNSmode \    : (((OP) == EQ || (OP) == NE)&& GET_RTX_CLASS (GET_CODE (X)) == '<'   \       ? CCEQmode : CCmode))
end_define

begin_comment
comment|/* Define the information needed to generate branch and scc insns.  This is    stored from the compare operation.  Note that we can't use "rtx" here    since it hasn't been defined!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|rs6000_compare_op0
decl_stmt|,
modifier|*
name|rs6000_compare_op1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|rs6000_compare_fp_p
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Set to non-zero by "fix" operation to indicate that itrunc and    uitrunc must be defined.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|rs6000_trunc_used
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* Output at beginning of assembler file.     On the RS/6000, we want to go into the TOC section so at least one    .toc will be emitted.     Also initialize the section names for the RS/6000 at this point.     Also, in order to output proper .bs/.es pairs, we need at least one static    [RW] section emitted.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{								\   rs6000_gen_section_name (&xcoff_bss_section_name,		\ 			   main_input_filename, ".bss_");	\   rs6000_gen_section_name (&xcoff_private_data_section_name,	\ 			   main_input_filename, ".rw_");	\   rs6000_gen_section_name (&xcoff_read_only_section_name,	\ 			   main_input_filename, ".ro_");	\ 								\   toc_section ();						\   if (write_symbols != NO_DEBUG)				\     private_data_section ();					\ }
end_define

begin_comment
comment|/* Output at end of assembler file.     On the RS/6000, referencing data should automatically pull in text.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{								\   text_section ();						\   fprintf (FILE, "_section_.text:\n");				\   data_section ();						\   fprintf (FILE, "\t.long _section_.text\n");			\ }
end_define

begin_comment
comment|/* We define this to prevent the name mangler from putting dollar signs into    function names.  */
end_comment

begin_define
define|#
directive|define
name|NO_DOLLAR_IN_LABEL
end_define

begin_comment
comment|/* We define this to 0 so that gcc will never accept a dollar sign in a    variable name.  This is needed because the AIX assembler will not accept    dollar signs.  */
end_comment

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|0
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Define the extra sections we need.  We define three: one is the read-only    data section which is used for constants.  This is a csect whose name is    derived from the name of the input file.  The second is for initialized    global variables.  This is a csect whose name is that of the variable.    The third is the TOC.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
define|\
value|read_only_data, private_data, read_only_private_data, toc, bss
end_define

begin_comment
comment|/* Define the name of our readonly data section.  */
end_comment

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION
value|read_only_data_section
end_define

begin_comment
comment|/* Indicate that jump tables go in the text section.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
end_define

begin_comment
comment|/* Define the routines to implement these extra sections.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\ 							\
value|void							\ read_only_data_section ()				\ {							\   if (in_section != read_only_data)			\     {							\       fprintf (asm_out_file, "\t.csect %s[RO]\n",	\ 	       xcoff_read_only_section_name);		\       in_section = read_only_data;			\     }							\ }							\ 							\ void							\ private_data_section ()					\ {							\   if (in_section != private_data)			\     {							\       fprintf (asm_out_file, "\t.csect %s[RW]\n",	\ 	       xcoff_private_data_section_name);	\ 							\       in_section = private_data;			\     }							\ }							\ 							\ void							\ read_only_private_data_section ()			\ {							\   if (in_section != read_only_private_data)		\     {							\       fprintf (asm_out_file, "\t.csect %s[RO]\n",	\ 	       xcoff_private_data_section_name);	\       in_section = read_only_private_data;		\     }							\ }							\ 							\ void							\ toc_section ()						\ {							\   if (in_section != toc)				\     fprintf (asm_out_file, "\t.toc\n");			\ 							\   in_section = toc;					\ }
end_define

begin_comment
comment|/* This macro produces the initial definition of a function name.    On the RS/6000, we need to place an extra '.' in the function name and    output the function descriptor.       The csect for the function will have already been created by the    `text_section' call previously done.  We do have to go back to that    csect, however.  */
end_comment

begin_comment
comment|/* ??? What do the 16 and 044 in the .function line really mean?  */
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
value|{ if (TREE_PUBLIC (DECL))					\     {								\       fprintf (FILE, "\t.globl .");				\       RS6000_OUTPUT_BASENAME (FILE, NAME);			\       fprintf (FILE, "\n");					\     }								\   else if (write_symbols == XCOFF_DEBUG)			\     {								\       fprintf (FILE, "\t.lglobl .");				\       RS6000_OUTPUT_BASENAME (FILE, NAME);			\       fprintf (FILE, "\n");					\     }								\   fprintf (FILE, "\t.csect ");					\   RS6000_OUTPUT_BASENAME (FILE, NAME);				\   fprintf (FILE, "[DS]\n");					\   RS6000_OUTPUT_BASENAME (FILE, NAME);				\   fprintf (FILE, ":\n");					\   fprintf (FILE, "\t.long .");					\   RS6000_OUTPUT_BASENAME (FILE, NAME);				\   fprintf (FILE, ", TOC[tc0], 0\n");				\   fprintf (FILE, "\t.csect [PR]\n.");				\   RS6000_OUTPUT_BASENAME (FILE, NAME);				\   fprintf (FILE, ":\n");					\   if (write_symbols == XCOFF_DEBUG)				\     xcoffout_declare_function (FILE, DECL, NAME);		\ }
end_define

begin_comment
comment|/* Return non-zero if this entry is to be written into the constant pool    in a special way.  We do so if this is a SYMBOL_REF, LABEL_REF or a CONST    containing one of them.  If -mfp-in-toc (the default), we also do    this for floating-point constants.  We actually can only do this    if the FP formats of the target and host machines are the same, but    we can't check that since not every file that uses    GO_IF_LEGITIMATE_ADDRESS_P includes real.h.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == SYMBOL_REF					\    || (GET_CODE (X) == CONST&& GET_CODE (XEXP (X, 0)) == PLUS	\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == SYMBOL_REF)	\    || GET_CODE (X) == LABEL_REF					\    || (TARGET_FP_IN_TOC&& GET_CODE (X) == CONST_DOUBLE		\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT		\&& BITS_PER_WORD == HOST_BITS_PER_INT))
end_define

begin_comment
comment|/* Select section for constant in constant pool.     On RS/6000, all constants are in the private read-only data area.    However, if this is being placed in the TOC it must be output as a    toc entry.  */
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
value|{ if (ASM_OUTPUT_SPECIAL_POOL_ENTRY_P (X))	\     toc_section ();				\   else						\     read_only_private_data_section ();		\ }
end_define

begin_comment
comment|/* Macro to output a special constant pool entry.  Go to WIN if we output    it.  Otherwise, it is written the usual way.     On the RS/6000, toc entries are handled this way.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|MODE
parameter_list|,
name|ALIGN
parameter_list|,
name|LABELNO
parameter_list|,
name|WIN
parameter_list|)
define|\
value|{ if (ASM_OUTPUT_SPECIAL_POOL_ENTRY_P (X))	\     {						\       output_toc (FILE, X, LABELNO);		\       goto WIN;					\     }						\ }
end_define

begin_comment
comment|/* Select the section for an initialized data object.     On the RS/6000, we have a special section for all variables except those    that are static.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|EXP
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|{							\   if ((TREE_READONLY (EXP)				\        || (TREE_CODE (EXP) == STRING_CST		\&& !flag_writable_strings))			\&& ! TREE_THIS_VOLATILE (EXP)			\&& ! (RELOC))					\     {							\       if (TREE_PUBLIC (EXP))				\         read_only_data_section ();			\       else						\         read_only_private_data_section ();		\     }							\   else							\     {							\       if (TREE_PUBLIC (EXP))				\         data_section ();				\       else						\         private_data_section ();			\     }							\ }
end_define

begin_comment
comment|/* This outputs NAME to FILE up to the first null or '['.  */
end_comment

begin_define
define|#
directive|define
name|RS6000_OUTPUT_BASENAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|if ((NAME)[0] == '*')				\     assemble_name (FILE, NAME);  		\   else						\     {						\       char *_p;					\       for (_p = (NAME); *_p&& *_p != '['; _p++) \         fputc (*_p, FILE);				\     }
end_define

begin_comment
comment|/* Output something to declare an external symbol to the assembler.  Most    assemblers don't need this.       If we haven't already, add "[RW]" (or "[DS]" for a function) to the    name.  Normally we write this out along with the name.  In the few cases    where we can't, it gets stripped off.  */
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
define|\
value|{ rtx _symref = XEXP (DECL_RTL (DECL), 0);	\   if ((TREE_CODE (DECL) == VAR_DECL		\        || TREE_CODE (DECL) == FUNCTION_DECL)	\&& (NAME)[0] != '*'			\&& (NAME)[strlen (NAME) - 1] != ']')	\     {						\       char *_name = (char *) permalloc (strlen (XSTR (_symref, 0)) + 5); \       strcpy (_name, XSTR (_symref, 0));	\       strcat (_name, TREE_CODE (DECL) == FUNCTION_DECL ? "[DS]" : "[RW]"); \       XSTR (_symref, 0) = _name;		\     }						\   fprintf (FILE, "\t.extern ");			\   assemble_name (FILE, XSTR (_symref, 0));	\   if (TREE_CODE (DECL) == FUNCTION_DECL)	\     {						\       fprintf (FILE, "\n\t.extern .");		\       RS6000_OUTPUT_BASENAME (FILE, XSTR (_symref, 0));	\     }						\   fprintf (FILE, "\n");				\ }
end_define

begin_comment
comment|/* Similar, but for libcall.  We only have to worry about the function name,    not that of the descriptor. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL_LIBCALL
parameter_list|(
name|FILE
parameter_list|,
name|FUN
parameter_list|)
define|\
value|{ fprintf (FILE, "\t.extern .");		\   assemble_name (FILE, XSTR (FUN, 0));		\   fprintf (FILE, "\n");				\ }
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
comment|/* Output before instructions.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".csect [PR]"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".csect .data[RW]"
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"0", "1", "2", "3", "4", "5", "6", "7", 		\   "8", "9", "10", "11", "12", "13", "14", "15",		\   "16", "17", "18", "19", "20", "21", "22", "23",	\   "24", "25", "26", "27", "28", "29", "30", "31",	\   "0", "1", "2", "3", "4", "5", "6", "7",		\   "8", "9", "10", "11", "12", "13", "14", "15",		\   "16", "17", "18", "19", "20", "21", "22", "23",	\   "24", "25", "26", "27", "28", "29", "30", "31",	\   "mq", "lr", "ctr", "ap",				\   "0", "1", "2", "3", "4", "5", "6", "7" }
end_define

begin_comment
comment|/* Table of additional register names to use in user input.  */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_REGISTER_NAMES
define|\
value|{"r0",    0, "r1",    1, "r2",    2, "r3",    3,	\   "r4",    4, "r5",    5, "r6",    6, "r7",    7,	\   "r8",    8, "r9",    9, "r10",  10, "r11",  11,	\   "r12",  12, "r13",  13, "r14",  14, "r15",  15,	\   "r16",  16, "r17",  17, "r18",  18, "r19",  19,	\   "r20",  20, "r21",  21, "r22",  22, "r23",  23,	\   "r24",  24, "r25",  25, "r26",  26, "r27",  27,	\   "r28",  28, "r29",  29, "r30",  30, "r31",  31,	\   "fr0",  32, "fr1",  33, "fr2",  34, "fr3",  35,	\   "fr4",  36, "fr5",  37, "fr6",  38, "fr7",  39,	\   "fr8",  40, "fr9",  41, "fr10", 42, "fr11", 43,	\   "fr12", 44, "fr13", 45, "fr14", 46, "fr15", 47,	\   "fr16", 48, "fr17", 49, "fr18", 50, "fr19", 51,	\   "fr20", 52, "fr21", 53, "fr22", 54, "fr23", 55,	\   "fr24", 56, "fr25", 57, "fr26", 58, "fr27", 59,	\   "fr28", 60, "fr29", 61, "fr30", 62, "fr31", 63,	\
comment|/* no additional names for: mq, lr, ctr, ap */
value|\   "cr0",  68, "cr1",  69, "cr2",  70, "cr3",  71,	\   "cr4",  72, "cr5",  73, "cr6",  74, "cr7",  75,	\   "cc",   68 }
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
value|do { RS6000_OUTPUT_BASENAME (FILE, NAME); fputs (":\n", FILE); } while (0)
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
value|do { fputs ("\t.globl ", FILE);	\        RS6000_OUTPUT_BASENAME (FILE, NAME); fputs ("\n", FILE);} while (0)
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
value|fprintf (FILE, NAME)
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
value|fprintf (FILE, "%s..%d:\n", PREFIX, NUM)
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
value|sprintf (LABEL, "%s..%d", PREFIX, NUM)
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
value|fprintf (FILE, "\t.float 0d%.20e\n", (VALUE))
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
comment|/* This is how to output an assembler line to define N characters starting    at P to FILE.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|P
parameter_list|,
name|N
parameter_list|)
value|output_ascii ((FILE), (P), (N))
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
value|fprintf (FILE, "\tstu %s,-4(r1)\n", reg_names[REGNO]);
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
value|fprintf (FILE, "\tl %s,0(r1)\n\tai r1,r1,4\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.     (RS/6000 does not use such vectors, but we must define this macro    anyway.)   */
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
value|fprintf (FILE, "\t.long L..%d\n", VALUE)
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
value|fprintf (FILE, "\t.long L..%d-L..%d\n", VALUE, REL)
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
value|do { fputs (".comm ", (FILE));			\        RS6000_OUTPUT_BASENAME ((FILE), (NAME));		\        fprintf ((FILE), ",%d\n", (SIZE)); } while (0)
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
value|do { fputs (".lcomm ", (FILE));			\        RS6000_OUTPUT_BASENAME ((FILE), (NAME));		\        fprintf ((FILE), ",%d,%s\n", (SIZE), xcoff_bss_section_name); \      } while (0)
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
value|0
end_define

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
value|print_operand_address (FILE, ADDR)
end_define

begin_comment
comment|/* Define the codes that are matched by predicates in rs6000.c.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"short_cint_operand", {CONST_INT}},				\   {"u_short_cint_operand", {CONST_INT}},			\   {"non_short_cint_operand", {CONST_INT}},			\   {"gpc_reg_operand", {SUBREG, REG}},				\   {"cc_reg_operand", {SUBREG, REG}},				\   {"reg_or_short_operand", {SUBREG, REG, CONST_INT}},		\   {"reg_or_neg_short_operand", {SUBREG, REG, CONST_INT}},	\   {"reg_or_u_short_operand", {SUBREG, REG, CONST_INT}},		\   {"reg_or_cint_operand", {SUBREG, REG, CONST_INT}},		\   {"easy_fp_constant", {CONST_DOUBLE}},				\   {"reg_or_mem_operand", {SUBREG, MEM, REG}},			\   {"fp_reg_or_mem_operand", {SUBREG, MEM, REG}},		\   {"mem_or_easy_const_operand", {SUBREG, MEM, CONST_DOUBLE}},	\   {"add_operand", {SUBREG, REG, CONST_INT}},			\   {"non_add_cint_operand", {CONST_INT}},			\   {"and_operand", {SUBREG, REG, CONST_INT}},			\   {"non_and_cint_operand", {CONST_INT}},			\   {"logical_operand", {SUBREG, REG, CONST_INT}},		\   {"non_logical_cint_operand", {CONST_INT}},			\   {"mask_operand", {CONST_INT}},				\   {"call_operand", {SYMBOL_REF, REG}},				\   {"input_operand", {SUBREG, MEM, REG, CONST_INT}},		\   {"branch_comparison_operation", {EQ, NE, LE, LT, GE,		\ 				   LT, LEU, LTU, GEU, GTU}},	\   {"scc_comparison_operation", {EQ, NE, LE, LT, GE,		\ 				LT, LEU, LTU, GEU, GTU}},
end_define

end_unit

