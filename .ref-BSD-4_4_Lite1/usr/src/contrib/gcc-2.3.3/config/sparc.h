begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for Sun SPARC.    Copyright (C) 1987, 1988, 1989, 1992 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@cygnus.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Note that some other tm.h files include this one and then override    many of the definitions that relate to assembler syntax.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} %{g:-lg}"
end_define

begin_comment
comment|/* Provide required defaults for linker -e and -d switches.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{!nostdlib:%{!r*:%{!e*:-e start}}} -dc -dp %{static:-Bstatic} %{assert*}"
end_define

begin_comment
comment|/* Special flags to the Sun-4 assembler when using pipe for input.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SPEC
value|" %{pipe:-} %{fpic:-k} %{fPIC:-k}"
end_define

begin_comment
comment|/* Define macros to distinguish architectures.  */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{msparclite:-D__sparclite__} %{mv8:-D__sparc_v8__}"
end_define

begin_comment
comment|/* Prevent error on `-sun4' and `-target sun4' options.  */
end_comment

begin_comment
comment|/* This used to translate -dalign to -malign, but that is no good    because it can't turn off the usual meaning of making debugging dumps.  */
end_comment

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{sun4:} %{target:}"
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Sparc ABI says that long double is 4 words.    ??? This doesn't work yet.  */
end_comment

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
end_define

begin_comment
comment|/* Omit frame pointer at high optimization levels.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|OPTIMIZE
parameter_list|)
define|\
value|{  								\   if (OPTIMIZE>= 2) 						\     {								\       flag_omit_frame_pointer = 1;				\     }								\ }
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
define|\
value|(!strcmp (STR, "Tdata") || !strcmp (STR, "Ttext")		\   || !strcmp (STR, "Tbss") || !strcmp (STR, "include")		\   || !strcmp (STR, "imacros") || !strcmp (STR, "target")	\   || !strcmp (STR, "assert") || !strcmp (STR, "aux-info"))
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
comment|/* Nonzero means that reference doublewords as if they were guaranteed    to be aligned...if they aren't, too bad for the user!    Like -dalign in Sun cc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_HOPE_ALIGN
value|(target_flags& 16)
end_define

begin_comment
comment|/* Nonzero means make sure all doubles are on 8-byte boundaries.    This option results in a calling convention that is incompatible with    every other sparc compiler in the world, and thus should only ever be    used for experimenting.  Also, varargs won't work with it, but it doesn't    seem worth trying to fix.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FORCE_ALIGN
value|(target_flags& 32)
end_define

begin_comment
comment|/* Nonzero means that we should generate code for a v8 sparc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_V8
value|(target_flags& 64)
end_define

begin_comment
comment|/* Nonzero means that we should generate code for a sparclite.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SPARCLITE
value|(target_flags& 128)
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"fpu", 1},			\     {"soft-float", -1},		\     {"epilogue", 2},		\     {"no-epilogue", -2},	\     {"hope-align", 16},		\     {"force-align", 48},	\     {"v8", 64},			\     {"no-v8", -64},		\     {"sparclite", 128},		\     {"no-sparclite", -128},	\     { "", TARGET_DEFAULT}}
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
value|1
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
value|1
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is the lowest    numbered.  */
end_comment

begin_comment
comment|/* Doubles are stored in memory with the high order word first.  This    matters when cross-compiling.  */
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

begin_define
define|#
directive|define
name|MAX_BITS_PER_WORD
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
value|64
end_define

begin_comment
comment|/* ALIGN FRAMES on double word boundaries */
end_comment

begin_define
define|#
directive|define
name|SPARC_STACK_ALIGN
parameter_list|(
name|LOC
parameter_list|)
value|(((LOC)+7)& 0xfffffff8)
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
comment|/* The best alignment to use in cases where we have a choice.  */
end_comment

begin_define
define|#
directive|define
name|FASTEST_ALIGNMENT
value|64
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
value|((TREE_CODE (EXP) == STRING_CST	\&& (ALIGN)< FASTEST_ALIGNMENT)	\    ? FASTEST_ALIGNMENT : (ALIGN))
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
value|(TREE_CODE (TYPE) == ARRAY_TYPE		\&& TYPE_MODE (TREE_TYPE (TYPE)) == QImode	\&& (ALIGN)< FASTEST_ALIGNMENT ? FASTEST_ALIGNMENT : (ALIGN))
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
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|{									\   if (TREE_CODE (T) == VAR_DECL)					\     {									\       if (TREE_READONLY (T)&& ! TREE_SIDE_EFFECTS (T)			\&& DECL_ALIGN (T)<= MAX_TEXT_ALIGN				\&& ! (flag_pic&& (RELOC)))					\ 	text_section ();						\       else								\ 	data_section ();						\     }									\   else if (TREE_CODE (T) == CONSTRUCTOR)				\     {									\       if (flag_pic != 0&& (RELOC) != 0)				\ 	data_section ();						\     }									\   else if (*tree_code_type[(int) TREE_CODE (T)] == 'c')			\     {									\       if ((TREE_CODE (T) == STRING_CST&& flag_writable_strings)	\ 	  || TYPE_ALIGN (TREE_TYPE (T))> MAX_TEXT_ALIGN)		\ 	data_section ();						\       else								\ 	text_section ();						\     }									\ }
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
value|{						\   if (GET_MODE_BITSIZE (MODE)<= MAX_TEXT_ALIGN \&& ! (flag_pic&& symbolic_operand (X)))  \     text_section ();				\   else						\     data_section ();				\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     SPARC has 32 integer registers and 32 floating point registers.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|64
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    0 is used for the condition code and not to represent %g0, which is    hardwired to 0, so reg 0 is *not* fixed.    g1 through g4 are free to use as temporaries.    g5 through g7 are reserved for the operating system.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 0, 0, 0, 0, 1, 1, 1,	\   0, 0, 0, 0, 0, 0, 1, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 1, 1,	\ 				\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   0, 0, 0, 0, 0, 0, 0, 0}
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
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On SPARC, ordinary registers hold 32 bits worth;    this means both integer and floating point registers.     We use vectors to keep this information about registers.  */
end_comment

begin_comment
comment|/* How many hard registers it takes to make a register of this mode.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hard_regno_nregs
index|[]
decl_stmt|;
end_decl_stmt

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
comment|/* Value is 1 if register/mode pair is acceptable on sparc.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|hard_regno_mode_ok
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On SPARC, the cpu registers can hold any mode but the float registers    can only hold SFmode or DFmode.  See sparc.c for how we    initialize this.  */
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
value|((hard_regno_mode_ok[REGNO]& (1<<(int)(MODE))) != 0)
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
value|((MODE1) == (MODE2) || GET_MODE_CLASS (MODE1) == GET_MODE_CLASS (MODE2))
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
comment|/* Actual top-of-stack address is 92 greater than the contents    of the stack pointer register.  92 = 68 + 24.  64 bytes reserving space    for the ins and local registers, 4 byte for structure return address, and    24 bytes for the 6 register parameters.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|FIRST_PARM_OFFSET(0)
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Register that is used for the return address.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_ADDR_REGNUM
value|15
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.     Used in flow.c, global.c, and reload1.c.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|leaf_function
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
define|\
value|(! (leaf_function_p ()&& only_leaf_regs_used ()))
end_define

begin_comment
comment|/* C statement to store the difference between the frame pointer    and the stack pointer values immediately after the function prologue.     Note, we always pretend that this is a leaf function because if    it's not, there's no point in trying to eliminate the    frame pointer.  If it is a leaf function, we guessed right!  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_FRAME_POINTER_OFFSET
parameter_list|(
name|VAR
parameter_list|)
define|\
value|do { (VAR) = compute_frame_size (get_frame_size (), 1); } while (0)
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
comment|/* Register which holds offset table for position-independent    data references.  */
end_comment

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|23
end_define

begin_define
define|#
directive|define
name|INITIALIZE_PIC
value|initialize_pic ()
end_define

begin_define
define|#
directive|define
name|FINALIZE_PIC
value|finalize_pic ()
end_define

begin_comment
comment|/* Sparc ABI says that quad-precision floats and all structures are returned    in memory.  We go along regarding floats, but for structures    we follow GCC's normal policy.  Use -fpcc-struct-value    if you want to follow the ABI.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TYPE_MODE (TYPE) == TFmode)
end_define

begin_comment
comment|/* Functions which return large structures get the address    to place the wanted value at offset 64 from the frame.    Must reserve 64 bytes for the in and local registers.  */
end_comment

begin_comment
comment|/* Used only in other #defines in this file.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_OFFSET
value|64
end_define

begin_define
define|#
directive|define
name|STRUCT_VALUE
define|\
value|gen_rtx (MEM, Pmode,					\ 	   gen_rtx (PLUS, Pmode, stack_pointer_rtx,	\ 		    gen_rtx (CONST_INT, VOIDmode, STRUCT_VALUE_OFFSET)))
end_define

begin_define
define|#
directive|define
name|STRUCT_VALUE_INCOMING
define|\
value|gen_rtx (MEM, Pmode,					\ 	   gen_rtx (PLUS, Pmode, frame_pointer_rtx,	\ 		    gen_rtx (CONST_INT, VOIDmode, STRUCT_VALUE_OFFSET)))
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

begin_if
if|#
directive|if
literal|0
operator|&&
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
value|{0LL, 0xfffffffeLL, 0xffffffff00000000LL, 0xfffffffffffffffeLL}
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
value|{{0, 0}, {-2, 0}, {0, -1}, {-2, -1}}
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|((REGNO)>= 32 ? FP_REGS : (REGNO) == 0 ? NO_REGS : GENERAL_REGS)
end_define

begin_comment
comment|/* This is the order in which to allocate registers    normally.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{ 8, 9, 10, 11, 12, 13, 2, 3, 		\   15, 16, 17, 18, 19, 20, 21, 22, 	\   23, 24, 25, 26, 27, 28, 29, 31,	\   32, 33, 34, 35, 36, 37, 38, 39,	\   40, 41, 42, 43, 44, 45, 46, 47,	\   48, 49, 50, 51, 52, 53, 54, 55,	\   56, 57, 58, 59, 60, 61, 62, 63,	\   1, 4, 5, 6, 7, 0, 14, 30}
end_define

begin_comment
comment|/* This is the order in which to allocate registers for    leaf functions.  If all registers can fit in the "i" registers,    then we have the possibility of having a leaf function.  */
end_comment

begin_define
define|#
directive|define
name|REG_LEAF_ALLOC_ORDER
define|\
value|{ 2, 3, 24, 25, 26, 27, 28, 29,		\   15, 8, 9, 10, 11, 12, 13,		\   16, 17, 18, 19, 20, 21, 22, 23,	\   32, 33, 34, 35, 36, 37, 38, 39,	\   40, 41, 42, 43, 44, 45, 46, 47,	\   48, 49, 50, 51, 52, 53, 54, 55,	\   56, 57, 58, 59, 60, 61, 62, 63,	\   1, 4, 5, 6, 7, 0, 14, 30, 31}
end_define

begin_define
define|#
directive|define
name|ORDER_REGS_FOR_LOCAL_ALLOC
value|order_regs_for_local_alloc ()
end_define

begin_define
define|#
directive|define
name|LEAF_REGISTERS
define|\
value|{ 1, 1, 1, 1, 1, 1, 1, 1,	\   0, 0, 0, 0, 0, 0, 1, 0,	\   0, 0, 0, 0, 0, 0, 0, 0,	\   1, 1, 1, 1, 1, 1, 0, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1,	\   1, 1, 1, 1, 1, 1, 1, 1}
end_define

begin_decl_stmt
specifier|extern
name|char
name|leaf_reg_remap
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LEAF_REG_REMAP
parameter_list|(
name|REGNO
parameter_list|)
value|(leaf_reg_remap[REGNO])
end_define

begin_decl_stmt
specifier|extern
name|char
name|leaf_reg_backmap
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LEAF_REG_BACKMAP
parameter_list|(
name|REGNO
parameter_list|)
value|(leaf_reg_backmap[REGNO])
end_define

begin_define
define|#
directive|define
name|REG_USED_SO_FAR
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)>= 24&& (REGNO)< 30	\    ? (regs_ever_live[24]		\       || regs_ever_live[25]		\       || regs_ever_live[26]		\       || regs_ever_live[27]		\       || regs_ever_live[28]		\       || regs_ever_live[29]) : 0)
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
value|((C) == 'f' ? FP_REGS : (C) == 'r' ? GENERAL_REGS : NO_REGS)
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
value|((C) == 'I' ? (unsigned) ((VALUE) + 0x1000)< 0x2000	\    : (C) == 'J' ? (VALUE) == 0				\    : (C) == 'K' ? ((VALUE)& 0x3ff) == 0		\    : 0)
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
value|((C) == 'G' ? CONST_DOUBLE_HIGH (VALUE) == 0		\&& CONST_DOUBLE_LOW (VALUE) == 0			\    : (C) == 'H' ? arith_double_operand (VALUE, DImode)	\    : 0)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.  */
end_comment

begin_comment
comment|/* We can't load constants into FP registers.  We can't load any FP constant    if an 'E' constraint fails to match it.  */
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
value|(CONSTANT_P (X)					\&& ((CLASS) == FP_REGS				\        || (GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT	\&& (HOST_FLOAT_FORMAT != IEEE_FLOAT_FORMAT	\ 	       || HOST_BITS_PER_INT != BITS_PER_WORD)))	\    ? NO_REGS : (CLASS))
end_define

begin_comment
comment|/* Return the register class of a scratch register needed to load IN into    a register of class CLASS in MODE.     On the SPARC, when PIC, we need a temporary when loading some addresses    into a register.     Also, we need a temporary when loading/storing a HImode/QImode value    between memory and the FPU registers.  This can happen when combine puts    a paradoxical subreg in a float/fix conversion insn.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_INPUT_RELOAD_CLASS
parameter_list|(
name|CLASS
parameter_list|,
name|MODE
parameter_list|,
name|IN
parameter_list|)
define|\
value|(flag_pic&& pic_address_needs_scratch (IN) ? GENERAL_REGS	\    : ((CLASS) == FP_REGS&& ((MODE) == HImode || (MODE) == QImode)\&& (GET_CODE (IN) == MEM					\ 	  || ((GET_CODE (IN) == REG || GET_CODE (IN) == SUBREG)	\&& true_regnum (IN) == -1))) ? GENERAL_REGS : NO_REGS)
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
name|IN
parameter_list|)
define|\
value|((CLASS) == FP_REGS&& ((MODE) == HImode || (MODE) == QImode)	\&& (GET_CODE (IN) == MEM					\        || ((GET_CODE (IN) == REG || GET_CODE (IN) == SUBREG)	\&& true_regnum (IN) == -1)) ? GENERAL_REGS : NO_REGS)
end_define

begin_comment
comment|/* On SPARC it is not possible to directly move data between     GENERAL_REGS and FP_REGS.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_MEMORY_NEEDED
parameter_list|(
name|CLASS1
parameter_list|,
name|CLASS2
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(((CLASS1) == FP_REGS&& (CLASS2) == GENERAL_REGS)	\    || ((CLASS1) == GENERAL_REGS&& (CLASS2) == FP_REGS))
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On SPARC, this is the size of MODE in words.  */
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
comment|/* Define the number of register that can hold parameters.    These two macros are used only in other macro definitions below.  */
end_comment

begin_define
define|#
directive|define
name|NPARM_REGS
value|6
end_define

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
value|(-16)
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On SPARC, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/*  #define PUSH_ROUNDING(BYTES) */
end_comment

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.    This is 64 for the ins and locals, plus 4 for the struct-return reg    even if this function isn't going to use it.    If TARGET_FORCE_ALIGN, we must reserve 4 more bytes to ensure that the    stack remains aligned.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
define|\
value|(STRUCT_VALUE_OFFSET + UNITS_PER_WORD + (TARGET_FORCE_ALIGN ? 4 : 0))
end_define

begin_comment
comment|/* When a parameter is passed in a register, stack space is still    allocated for it.  */
end_comment

begin_define
define|#
directive|define
name|REG_PARM_STACK_SPACE
parameter_list|(
name|DECL
parameter_list|)
value|(NPARM_REGS * UNITS_PER_WORD)
end_define

begin_comment
comment|/* Keep the stack pointer constant throughout the function.    This is both an optimization and a necessity: longjmp    doesn't behave itself when the stack pointer moves within    the function!  */
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

begin_define
define|#
directive|define
name|ROUND_ADVANCE
parameter_list|(
name|SIZE
parameter_list|)
define|\
value|((SIZE + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* Round a register number up to a proper boundary for an arg of mode MODE.    Note that we need an odd/even pair for a two-word arg,    since that will become 8-byte aligned when stored in memory.  */
end_comment

begin_define
define|#
directive|define
name|ROUND_REG
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|)
define|\
value|(TARGET_FORCE_ALIGN&& GET_MODE_UNIT_SIZE ((MODE))> 4		\   ? ((X) + ! ((X)& 1)) : (X))
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
parameter_list|,
name|LIBNAME
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
value|((CUM) = (ROUND_REG ((CUM), (MODE))			\ 	   + ((MODE) != BLKmode				\ 	      ? ROUND_ADVANCE (GET_MODE_SIZE (MODE))	\ 	      : ROUND_ADVANCE (int_size_in_bytes (TYPE)))))
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
value|(ROUND_REG ((CUM), (MODE))< NPARM_REGS					\&& ((TYPE)==0 || ! TREE_ADDRESSABLE ((tree)(TYPE)))			\&& ((TYPE)==0 || (MODE) != BLKmode					\      || (TYPE_ALIGN ((TYPE)) % PARM_BOUNDARY == 0))			\  ? gen_rtx (REG, (MODE),						\ 	    (BASE_PASSING_ARG_REG (MODE) + ROUND_REG ((CUM), (MODE))))	\  : 0)
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
value|(ROUND_REG ((CUM), (MODE))< NPARM_REGS					\&& ((TYPE)==0 || ! TREE_ADDRESSABLE ((tree)(TYPE)))			\&& ((TYPE)==0 || (MODE) != BLKmode					\      || (TYPE_ALIGN ((TYPE)) % PARM_BOUNDARY == 0))			\  ? gen_rtx (REG, (MODE),						\ 	    (BASE_INCOMING_ARG_REG (MODE) + ROUND_REG ((CUM), (MODE))))	\  : 0)
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
value|((ROUND_REG ((CUM), (MODE))< NPARM_REGS				\&& ((TYPE)==0 || ! TREE_ADDRESSABLE ((tree)(TYPE)))			\&& ((TYPE)==0 || (MODE) != BLKmode					\ 	|| (TYPE_ALIGN ((TYPE)) % PARM_BOUNDARY == 0))			\&& (ROUND_REG ((CUM), (MODE))					\ 	+ ((MODE) == BLKmode						\ 	   ? ROUND_ADVANCE (int_size_in_bytes (TYPE))			\ 	   : ROUND_ADVANCE (GET_MODE_SIZE (MODE)))) - NPARM_REGS> 0)	\    ? (NPARM_REGS - ROUND_REG ((CUM), (MODE)))				\    : 0)
end_define

begin_comment
comment|/* The SPARC ABI stipulates passing struct arguments (of any size) and    quad-precision floats by invisible reference.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PASS_BY_REFERENCE
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
value|((TYPE&& (TREE_CODE (TYPE) == RECORD_TYPE				\ 	    || TREE_CODE (TYPE) == UNION_TYPE))				\    || (MODE == TFmode))
end_define

begin_comment
comment|/* If defined, a C expression that gives the alignment boundary, in    bits, of an argument with the specified mode and type.  If it is    not defined,  `PARM_BOUNDARY' is used for all arguments.     This definition does nothing special unless TARGET_FORCE_ALIGN;    in that case, it aligns each arg to the natural boundary.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_BOUNDARY
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|(! TARGET_FORCE_ALIGN						\   ? PARM_BOUNDARY						\   : (((TYPE) != 0)						\      ? (TYPE_ALIGN (TYPE)<= PARM_BOUNDARY			\ 	? PARM_BOUNDARY						\ 	: TYPE_ALIGN (TYPE))					\      : (GET_MODE_ALIGNMENT (MODE)<= PARM_BOUNDARY		\ 	? PARM_BOUNDARY						\ 	: GET_MODE_ALIGNMENT (MODE))))
end_define

begin_comment
comment|/* Define the information needed to generate branch and scc insns.  This is    stored from the compare operation.  Note that we can't use "rtx" here    since it hasn't been defined!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|sparc_compare_op0
decl_stmt|,
modifier|*
name|sparc_compare_op1
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define the function that build the compare insn for scc and bcc.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|gen_compare_reg
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Generate the special assembly code needed to tell the assembler whatever    it might need to know about the return value of a function.     For Sparc assemblers, we need to output a .proc pseudo-op which conveys    information to the assembler relating to peephole optimization (done in    the assembler).  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_RESULT
parameter_list|(
name|FILE
parameter_list|,
name|RESULT
parameter_list|)
define|\
value|fprintf ((FILE), "\t.proc\t0%o\n", sparc_type_code (TREE_TYPE (RESULT)))
end_define

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
value|do {									\   ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\   ASM_OUTPUT_LABEL (FILE, NAME);					\ } while (0)
end_define

begin_comment
comment|/* Two views of the size of the current frame.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|actual_fsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|apparent_fsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This macro generates the assembly code for function entry.    FILE is a stdio stream to output the code to.    SIZE is an int: how many units of temporary storage to allocate.    Refer to the array `regs_ever_live' to determine which registers    to save; `regs_ever_live[I]' is nonzero if register number I    is ever used in the function.  This macro is responsible for    knowing which registers should not be saved even if used.  */
end_comment

begin_comment
comment|/* On SPARC, move-double insns between fpu and cpu need an 8-byte block    of memory.  If any fpu reg is used in the function, we allocate    such a block here, at the bottom of the frame, just in case it's needed.     If this function is a leaf procedure, then we may choose not    to do a "save" insn.  The decision about whether or not    to do this is made in regclass.c.  */
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
value|output_function_prologue (FILE, SIZE, leaf_function)
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
value|do {								\     fputs ("\tsethi %hi(", (FILE));				\     ASM_OUTPUT_INTERNAL_LABELREF (FILE, "LP", LABELNO);		\     fputs ("),%o0\n\tcall mcount\n\tor %lo(", (FILE));		\     ASM_OUTPUT_INTERNAL_LABELREF (FILE, "LP", LABELNO);		\     fputs ("),%o0,%o0\n", (FILE));				\   } while (0)
end_define

begin_comment
comment|/* Output assembler code to FILE to initialize this source file's    basic block profiling info, if that has not already been done.  */
end_comment

begin_comment
comment|/* FIXME -- this does not parameterize how it generates labels (like the    above FUNCTION_PROFILER).  Broken on Solaris-2.   --gnu@cygnus.com */
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
value|fprintf (FILE, "\tsethi %%hi(LPBX0),%%o0\n\tld [%%lo(LPBX0)+%%o0],%%o1\n\ttst %%o1\n\tbne LPY%d\n\tadd %%o0,%%lo(LPBX0),%%o0\n\tcall ___bb_init_func\n\tnop\nLPY%d:\n",  \ 	   (LABELNO), (LABELNO))
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
value|{								\   int blockn = (BLOCKNO);					\   fprintf (FILE, "\tsethi %%hi(LPBX2+%d),%%g1\n\tld [%%lo(LPBX2+%d)+%%g1],%%g2\n\ \tadd %%g2,1,%%g2\n\tst %%g2,[%%lo(LPBX2+%d)+%%g1]\n",		\ 	   4 * blockn, 4 * blockn, 4 * blockn);			\ }
end_define

begin_comment
comment|/* Output rtl to increment the entry-count for the LABELNO'th instrumented    arc in this source file.  */
end_comment

begin_define
define|#
directive|define
name|ARC_PROFILER
parameter_list|(
name|ARCNO
parameter_list|,
name|INSERT_AFTER
parameter_list|)
define|\
value|output_arc_profiler (ARCNO, INSERT_AFTER)
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_calls_alloca
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|current_function_outgoing_args_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
define|\
value|(get_frame_size () != 0	\   || current_function_calls_alloca || current_function_outgoing_args_size)
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
value|output_function_epilogue (FILE, SIZE, leaf_function)
end_define

begin_define
define|#
directive|define
name|DELAY_SLOTS_FOR_EPILOGUE
value|1
end_define

begin_define
define|#
directive|define
name|ELIGIBLE_FOR_EPILOGUE_DELAY
parameter_list|(
name|trial
parameter_list|,
name|slots_filled
parameter_list|)
define|\
value|eligible_for_epilogue_delay (trial, slots_filled)
end_define

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.  */
end_comment

begin_comment
comment|/* On the sparc, the trampoline contains five instructions:      sethi #TOP_OF_FUNCTION,%g2      or #BOTTOM_OF_FUNCTION,%g2,%g2      sethi #TOP_OF_STATIC,%g1      jmp g2      or #BOTTOM_OF_STATIC,%g1,%g1  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{									\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x00000000));	\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x00000000));	\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x00000000));	\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x81C08000));	\   ASM_OUTPUT_INT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x00000000));	\ }
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
comment|/* Emit RTL insns to initialize the variable parts of a trampoline.    FNADDR is an RTX for the address of the function's pure code.    CXT is an RTX for the static chain value for the function.     This takes 16 insns: 2 shifts& 2 ands (to split up addresses), 4 sethi    (to load in opcodes), 4 iors (to merge address and opcodes), and 4 writes    (to store insns).  This is a bit excessive.  Perhaps a different    mechanism would be better here.  */
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
value|{									\   rtx high_cxt = expand_shift (RSHIFT_EXPR, SImode, CXT,		\ 			      size_int (10), 0, 1);			\   rtx high_fn = expand_shift (RSHIFT_EXPR, SImode, FNADDR,		\ 			     size_int (10), 0, 1);			\   rtx low_cxt = expand_and (CXT, gen_rtx (CONST_INT, VOIDmode, 0x3ff), 0); \   rtx low_fn = expand_and (FNADDR, gen_rtx (CONST_INT, VOIDmode, 0x3ff), 0); \   rtx g1_sethi = gen_rtx (HIGH, SImode,					\ 			  gen_rtx (CONST_INT, VOIDmode, 0x03000000));	\   rtx g2_sethi = gen_rtx (HIGH, SImode,					\ 			  gen_rtx (CONST_INT, VOIDmode, 0x05000000));	\   rtx g1_ori = gen_rtx (HIGH, SImode,					\ 			gen_rtx (CONST_INT, VOIDmode, 0x82106000));	\   rtx g2_ori = gen_rtx (HIGH, SImode,					\ 			gen_rtx (CONST_INT, VOIDmode, 0x8410A000));	\   rtx tem = gen_reg_rtx (SImode);					\   emit_move_insn (tem, g2_sethi);					\   emit_insn (gen_iorsi3 (high_fn, high_fn, tem));			\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 0)), high_fn);\   emit_move_insn (tem, g2_ori);						\   emit_insn (gen_iorsi3 (low_fn, low_fn, tem));				\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 4)), low_fn);\   emit_move_insn (tem, g1_sethi);					\   emit_insn (gen_iorsi3 (high_cxt, high_cxt, tem));			\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 8)), high_cxt);\   emit_move_insn (tem, g1_ori);						\   emit_insn (gen_iorsi3 (low_cxt, low_cxt, tem));			\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 16)), low_cxt);\ }
end_define

begin_comment
comment|/* Emit code for a call to builtin_saveregs.  We must emit USE insns which    reference the 6 input registers.  Ordinarily they are not call used    registers, but they are for _builtin_saveregs, so we must make this    explicit.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_SAVEREGS
parameter_list|(
name|ARGLIST
parameter_list|)
define|\
value|(emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, TImode, 24))),	\    emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, DImode, 28))),	\    expand_call (exp, target, ignore))
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
value|(((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< 32)&& (REGNO) != 0)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< 32)&& (REGNO) != 0)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_FP_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO) ^ 0x20)< 32	\  || (((REGNO) != 0)&& (unsigned) (reg_renumber[REGNO] ^ 0x20)< 32))
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
value|(CONSTANT_P (X))
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    Anything can be made to work except floating point constants.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) != CONST_DOUBLE || GET_MODE (X) == VOIDmode)
end_define

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects    them unless they have been allocated suitable hard regs.    The symbol REG_OK_STRICT causes the latter definition to be used.     Most source files want to accept pseudo regs in the hope that    they will get allocated to the class that the insn wants them to be in.    Source files for reload pass need to be strict.    After reload, it makes no difference, since pseudo regs have    been eliminated by then.  */
end_comment

begin_comment
comment|/* Optional extra constraints for this machine.  Borrowed from romp.h.     For the SPARC, `Q' means that this is a memory operand but not a    symbolic memory operand.  Note that an unassigned pseudo register    is such a memory operand.  Needed because reload will generate    these things in insns and then not re-recognize the insns, causing    constrain_operands to fail.     `R' handles the LO_SUM which can be an address for `Q'.     `S' handles constraints for calls.  */
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
value|(((unsigned) REGNO (X)) - 32>= 32&& REGNO (X) != 0)
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
value|(((unsigned) REGNO (X)) - 32>= 32&& REGNO (X) != 0)
end_define

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
value|((C) == 'Q'						\    ? ((GET_CODE (OP) == MEM				\&& memory_address_p (GET_MODE (OP), XEXP (OP, 0))	\&& ! symbolic_memory_operand (OP, VOIDmode))	\       || (reload_in_progress&& GET_CODE (OP) == REG	\&& REGNO (OP)>= FIRST_PSEUDO_REGISTER))	\    : (C) == 'R'						\    ? (GET_CODE (OP) == LO_SUM				\&& GET_CODE (XEXP (OP, 0)) == REG			\&& REG_OK_FOR_BASE_P (XEXP (OP, 0)))		\    : (C) == 'S'						\    ? (CONSTANT_P (OP) || memory_address_p (Pmode, OP))	\    : (C) == 'T'						\    ? (mem_aligned_8 (OP))				\    : (C) == 'U'						\    ? (register_ok_for_ldd (OP))				\    : 0)
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
value|((C) == 'Q' ?						\    (GET_CODE (OP) == REG ?				\     (REGNO (OP)>= FIRST_PSEUDO_REGISTER		\&& reg_renumber[REGNO (OP)]< 0)			\     : GET_CODE (OP) == MEM)				\    : ((C) == 'R' ?					\       (GET_CODE (OP) == LO_SUM				\&& GET_CODE (XEXP (OP, 0)) == REG		\&& REG_OK_FOR_BASE_P (XEXP (OP, 0)))		\       : ((C) == 'S'					\ 	 ? (CONSTANT_P (OP)				\ 	    || (GET_CODE (OP) == REG&& reg_renumber[REGNO (OP)]> 0)\ 	    || strict_memory_address_p (Pmode, OP)) 	\ 	 : ((C) == 'T' ?				\ 	    mem_aligned_8 (OP)&& strict_memory_address_p (Pmode, OP) \ 	    : ((C) == 'U' ?				\ 	       register_ok_for_ldd (OP) : 0)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     On SPARC, the actual legitimate addresses must be REG+REG or REG+SMALLINT    ordinarily.  This changes a bit when generating PIC.     If you change this, execute "rm explow.o recog.o reload.o".  */
end_comment

begin_define
define|#
directive|define
name|RTX_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))			\   || (GET_CODE (X) == SUBREG						\&& GET_CODE (SUBREG_REG (X)) == REG				\&& REG_OK_FOR_BASE_P (SUBREG_REG (X))))
end_define

begin_define
define|#
directive|define
name|RTX_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_CODE (X) == REG&& REG_OK_FOR_INDEX_P (X))			\   || (GET_CODE (X) == SUBREG						\&& GET_CODE (SUBREG_REG (X)) == REG				\&& REG_OK_FOR_INDEX_P (SUBREG_REG (X))))
end_define

begin_define
define|#
directive|define
name|RTX_OK_FOR_OFFSET_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == CONST_INT&& INTVAL (X)>= -0x1000&& INTVAL (X)< 0x1000)
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
value|{ if (RTX_OK_FOR_BASE_P (X))				\     goto ADDR;						\   else if (GET_CODE (X) == PLUS)			\     {							\       register rtx op0 = XEXP (X, 0);			\       register rtx op1 = XEXP (X, 1);			\       if (flag_pic&& op0 == pic_offset_table_rtx)	\ 	{						\ 	  if (RTX_OK_FOR_BASE_P (op1))			\ 	    goto ADDR;					\ 	  else if (flag_pic == 1			\&& GET_CODE (op1) != REG		\&& GET_CODE (op1) != LO_SUM		\&& GET_CODE (op1) != MEM)		\ 	    goto ADDR;					\ 	}						\       else if (RTX_OK_FOR_BASE_P (op0))			\ 	{						\ 	  if (RTX_OK_FOR_INDEX_P (op1)			\ 	      || RTX_OK_FOR_OFFSET_P (op1))		\ 	    goto ADDR;					\ 	}						\       else if (RTX_OK_FOR_BASE_P (op1))			\ 	{						\ 	  if (RTX_OK_FOR_INDEX_P (op0)			\ 	      || RTX_OK_FOR_OFFSET_P (op0))		\ 	    goto ADDR;					\ 	}						\     }							\   else if (GET_CODE (X) == LO_SUM)			\     {							\       register rtx op0 = XEXP (X, 0);			\       register rtx op1 = XEXP (X, 1);			\       if (RTX_OK_FOR_BASE_P (op0)			\&& CONSTANT_P (op1))				\ 	goto ADDR;					\     }							\   else if (GET_CODE (X) == CONST_INT&& SMALL_INT (X))	\     goto ADDR;						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.  */
end_comment

begin_comment
comment|/* On SPARC, change REG+N into REG+REG, and REG+(X*Y) into REG+REG.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|legitimize_pic_address
parameter_list|()
function_decl|;
end_function_decl

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
value|{ rtx sparc_x = (X);						\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == MULT)	\     (X) = gen_rtx (PLUS, Pmode, XEXP (X, 1),			\ 		   force_operand (XEXP (X, 0), 0));		\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 1)) == MULT)	\     (X) = gen_rtx (PLUS, Pmode, XEXP (X, 0),			\ 		   force_operand (XEXP (X, 1), 0));		\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == PLUS)	\     (X) = gen_rtx (PLUS, Pmode, force_operand (XEXP (X, 0), 0),\ 		   XEXP (X, 1));				\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 1)) == PLUS)	\     (X) = gen_rtx (PLUS, Pmode, XEXP (X, 0),			\ 		   force_operand (XEXP (X, 1), 0));		\   if (sparc_x != (X)&& memory_address_p (MODE, X))		\     goto WIN;							\   if (flag_pic) (X) = legitimize_pic_address (X, MODE, 0, 0);	\   else if (GET_CODE (X) == PLUS&& CONSTANT_ADDRESS_P (XEXP (X, 1)))	\     (X) = gen_rtx (PLUS, Pmode, XEXP (X, 0),			\ 		   copy_to_mode_reg (Pmode, XEXP (X, 1)));	\   else if (GET_CODE (X) == PLUS&& CONSTANT_ADDRESS_P (XEXP (X, 0)))	\     (X) = gen_rtx (PLUS, Pmode, XEXP (X, 1),			\ 		   copy_to_mode_reg (Pmode, XEXP (X, 0)));	\   else if (GET_CODE (X) == SYMBOL_REF || GET_CODE (X) == CONST	\ 	   || GET_CODE (X) == LABEL_REF)			\     (X) = gen_rtx (LO_SUM, Pmode,				\ 		   copy_to_mode_reg (Pmode, gen_rtx (HIGH, Pmode, X)), X); \   if (memory_address_p (MODE, X))				\     goto WIN; }
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
value|8
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Sun 4 has matherr, so this is no good.  */
end_comment

begin_comment
comment|/* This is the value of the error code EDOM for this machine,    used by the sqrt instruction.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_EDOM
value|33
end_define

begin_comment
comment|/* This is how to refer to the variable errno.  */
end_comment

begin_define
define|#
directive|define
name|GEN_ERRNO_RTX
define|\
value|gen_rtx (MEM, SImode, gen_rtx (SYMBOL_REF, Pmode, "errno"))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* Define if normal loads of shorter-than-word items from memory clears    the rest of the bigs in the register.  */
end_comment

begin_define
define|#
directive|define
name|BYTE_LOADS_ZERO_EXTEND
end_define

begin_comment
comment|/* Nonzero if access to memory by bytes is slow and undesirable.    For RISC chips, it means that access to memory by bytes is no    better than access by words when possible, so grab a whole word    and maybe make use of that.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
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
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Add any extra modes needed to represent the condition code.     On the Sparc, we have a "no-overflow" mode which is used when an add or    subtract insn is used to set the condition code.  Different branches are    used in this case for some operations.     We also have two modes to indicate that the relevant condition code is    in the floating-point condition code register.  One for comparisons which    will generate an exception if the result is unordered (CCFPEmode) and    one for comparisons which will never trap (CCFPmode).  This really should    be a separate register, but we don't want to go to 65 registers.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_MODES
value|CC_NOOVmode, CCFPmode, CCFPEmode
end_define

begin_comment
comment|/* Define the names for the modes specified above.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_NAMES
value|"CC_NOOV", "CCFP", "CCFPE"
end_define

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.  For floating-point,    CCFP[E]mode is used.  CC_NOOVmode should be used when the first operand is a    PLUS, MINUS, or NEG.  CCmode should be used when no special processing is    needed.  */
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
value|(GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT				\    ? ((OP == EQ || OP == NE) ? CCFPmode : CCFPEmode)		\    : ((GET_CODE (X) == PLUS || GET_CODE (X) == MINUS || GET_CODE (X) == NEG) \       ? CC_NOOVmode : CCmode))
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
comment|/* alloca should avoid clobbering the old register save area.  */
end_comment

begin_define
define|#
directive|define
name|SETJMP_VIA_SAVE_AREA
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

begin_comment
comment|/* .umul is a little faster than .mul.  */
end_comment

begin_define
define|#
directive|define
name|MULSI3_LIBCALL
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
parameter_list|,
name|OUTER_CODE
parameter_list|)
define|\
value|case CONST_INT:						\     if (INTVAL (RTX) == 0)					\       return 0;							\     if (INTVAL (RTX)< 0x1000&& INTVAL (RTX)>= -0x1000)	\       return 1;							\   case HIGH:							\     return 2;							\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 4;							\   case CONST_DOUBLE:						\     if (GET_MODE (RTX) == DImode)				\       if ((XINT (RTX, 3) == 0					\&& (unsigned) XINT (RTX, 2)< 0x1000)		\ 	  || (XINT (RTX, 3) == -1				\&& XINT (RTX, 2)< 0				\&& XINT (RTX, 2)>= -0x1000))			\ 	return 1;						\     return 8;
end_define

begin_comment
comment|/* SPARC offers addressing modes which are "as cheap as a register".    See sparc.c (or gcc.texinfo) for details.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|RTX
parameter_list|)
define|\
value|(GET_CODE (RTX) == REG ? 1 : sparc_address_cost (RTX))
end_define

begin_comment
comment|/* Compute extra cost of moving data between one register class    and another.  */
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
value|(((CLASS1 == FP_REGS&& CLASS2 == GENERAL_REGS) \     || (CLASS1 == GENERAL_REGS&& CLASS2 == FP_REGS)) ? 6 : 2)
end_define

begin_comment
comment|/* Provide the costs of a rtl expression.  This is in the body of a    switch on CODE.  The purpose for the cost of MULT is to encourage    `synth_mult' to find a synthetic multiply when reasonable.     If we need more than 12 insns to do a multiply, then go out-of-line,    since the call overhead will be< 10% of the cost of the multiply.  */
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
value|case MULT:						\     return COSTS_N_INSNS (25);				\   case DIV:						\   case UDIV:						\   case MOD:						\   case UMOD:						\     return COSTS_N_INSNS (20);				\
comment|/* Make FLOAT more expensive than CONST_DOUBLE,	\      so that cse will favor the latter.  */
value|\   case FLOAT:						\     return 19;
end_define

begin_comment
comment|/* Conditional branches with empty delay slots have a length of two.  */
end_comment

begin_define
define|#
directive|define
name|ADJUST_INSN_LENGTH
parameter_list|(
name|INSN
parameter_list|,
name|LENGTH
parameter_list|)
define|\
value|if (GET_CODE (INSN) == CALL_INSN					\       || (GET_CODE (INSN) == JUMP_INSN&& ! simplejump_p (insn)))	\     LENGTH += 1;
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

begin_define
define|#
directive|define
name|ASM_LONG
value|".word"
end_define

begin_define
define|#
directive|define
name|ASM_SHORT
value|".half"
end_define

begin_define
define|#
directive|define
name|ASM_BYTE_OP
value|".byte"
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
comment|/* Define additional names for use in asm clobbers and asm declarations.     We define the fake Condition Code register as an alias for reg 0 (which    is our `condition code' register), so that condition codes can easily    be clobbered by an asm.  No such register actually exists.  Condition    codes are partly stored in the PSR and partly in the FSR.  */
end_comment

begin_define
define|#
directive|define
name|ADDITIONAL_REGISTER_NAMES
value|{"ccr", 0, "cc", 0}
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
value|do { fputs ("\t.global ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)
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
comment|/* This is how to output a definition of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
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
comment|/* This is how to output a reference to an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.  */
end_comment

begin_comment
comment|/* FIXME:  This should be used throughout gcc, and documented in the texinfo    files.  There is no reason you should have to allocate a buffer and    `sprintf' to reference an internal label (as opposed to defining it).  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf (FILE, "%s%d", PREFIX, NUM)
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
comment|/* Assemblers (both gas 1.35 and as in 4.0.3)    seem to treat -0.0 as if it were 0.0.    They reject 99e9999, but accept inf.  */
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
value|{									\     if (REAL_VALUE_ISINF (VALUE)					\         || REAL_VALUE_ISNAN (VALUE)					\ 	|| REAL_VALUE_MINUS_ZERO (VALUE))				\       {									\ 	long t[2];							\ 	REAL_VALUE_TO_TARGET_DOUBLE ((VALUE), t);			\ 	fprintf (FILE, "\t%s\t0x%lx\n\t%s\t0x%lx\n",			\ 		 ASM_LONG, t[0], ASM_LONG, t[1]);			\       }									\     else								\       fprintf (FILE, "\t.double 0r%.17g\n", VALUE);			\   }
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
value|{									\     if (REAL_VALUE_ISINF (VALUE)					\         || REAL_VALUE_ISNAN (VALUE)					\ 	|| REAL_VALUE_MINUS_ZERO (VALUE))				\       {									\ 	long t;								\ 	REAL_VALUE_TO_TARGET_SINGLE ((VALUE), t);			\ 	fprintf (FILE, "\t%s\t0x%lx\n", ASM_LONG, t);			\       }									\     else								\       fprintf (FILE, "\t.single 0r%.9g\n", VALUE);			\   }
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
value|( fprintf (FILE, "\t%s\t", ASM_LONG),		\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
end_define

begin_comment
comment|/* This is how to output an assembler line defining a DImode constant.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE_INT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|output_double_int (FILE, VALUE)
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
value|( fprintf (FILE, "\t%s\t", ASM_SHORT),		\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
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
value|( fprintf (FILE, "\t%s\t", ASM_BYTE_OP),	\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "\n"))
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
value|fprintf (FILE, "\t%s\t0x%x\n", ASM_BYTE_OP, (VALUE))
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
value|do {									\   char label[30];							\   ASM_GENERATE_INTERNAL_LABEL (label, "L", VALUE);			\   fprintf (FILE, "\t.word\t");						\   assemble_name (FILE, label);						\   fprintf (FILE, "\n");							\ } while (0)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    (SPARC uses such vectors only when generating PIC.)  */
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
value|do {									\   char label[30];							\   ASM_GENERATE_INTERNAL_LABEL (label, "L", VALUE);			\   fprintf (FILE, "\t.word\t");						\   assemble_name (FILE, label);						\   fprintf (FILE, "-1b\n");						\ } while (0)
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
value|( fputs ("\t.global ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fputs ("\n\t.common ", (FILE)),		\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u,\"bss\"\n", (ROUNDED)))
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
value|( fputs ("\n\t.reserve ", (FILE)),		\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u,\"bss\"\n", (ROUNDED)))
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

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|((CHAR) == '@' || (CHAR) == '#' || (CHAR) == '*' || (CHAR) == '^' \    || (CHAR) == '(')
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
value|{ register rtx base, index = 0;					\   int offset = 0;						\   register rtx addr = ADDR;					\   if (GET_CODE (addr) == REG)					\     fputs (reg_names[REGNO (addr)], FILE);			\   else if (GET_CODE (addr) == PLUS)				\     {								\       if (GET_CODE (XEXP (addr, 0)) == CONST_INT)		\ 	offset = INTVAL (XEXP (addr, 0)), base = XEXP (addr, 1);\       else if (GET_CODE (XEXP (addr, 1)) == CONST_INT)		\ 	offset = INTVAL (XEXP (addr, 1)), base = XEXP (addr, 0);\       else							\ 	base = XEXP (addr, 0), index = XEXP (addr, 1);		\       fputs (reg_names[REGNO (base)], FILE);			\       if (index == 0)						\ 	fprintf (FILE, "%+d", offset);				\       else if (GET_CODE (index) == REG)				\ 	fprintf (FILE, "+%s", reg_names[REGNO (index)]);	\       else if (GET_CODE (index) == SYMBOL_REF)			\ 	fputc ('+', FILE), output_addr_const (FILE, index);	\       else abort ();						\     }								\   else if (GET_CODE (addr) == MINUS				\&& GET_CODE (XEXP (addr, 1)) == LABEL_REF)		\     {								\       output_addr_const (FILE, XEXP (addr, 0));			\       fputs ("-(", FILE);					\       output_addr_const (FILE, XEXP (addr, 1));			\       fputs ("-.)", FILE);					\     }								\   else if (GET_CODE (addr) == LO_SUM)				\     {								\       output_operand (XEXP (addr, 0), 0);			\       fputs ("+%lo(", FILE);					\       output_address (XEXP (addr, 1));				\       fputc (')', FILE);					\     }								\   else if (flag_pic&& GET_CODE (addr) == CONST			\&& GET_CODE (XEXP (addr, 0)) == MINUS		\&& GET_CODE (XEXP (XEXP (addr, 0), 1)) == CONST	\&& GET_CODE (XEXP (XEXP (XEXP (addr, 0), 1), 0)) == MINUS	\&& XEXP (XEXP (XEXP (XEXP (addr, 0), 1), 0), 1) == pc_rtx)	\     {								\       addr = XEXP (addr, 0);					\       output_addr_const (FILE, XEXP (addr, 0));			\
comment|/* Group the args of the second CONST in parenthesis.  */
value|\       fputs ("-(", FILE);					\
comment|/* Skip past the second CONST--it does nothing for us.  */
value|\       output_addr_const (FILE, XEXP (XEXP (addr, 1), 0));	\
comment|/* Close the parenthesis.  */
value|\       fputc (')', FILE);					\     }								\   else								\     {								\       output_addr_const (FILE, addr);				\     }								\ }
end_define

begin_comment
comment|/* Declare functions defined in sparc.c and used in templates.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|singlemove_string
parameter_list|()
function_decl|;
end_function_decl

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
name|output_move_quad
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_fp_move_double
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_fp_move_quad
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_block_move
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_scc_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_cbranch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_return
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Defined in flags.h, but insn-emit.c does not include flags.h.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pic
decl_stmt|;
end_decl_stmt

end_unit

