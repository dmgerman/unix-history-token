begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for the HP Spectrum.    Copyright (C) 1992 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@mcc.com)    and Tim Moore (moore@defmacro.cs.utah.edu) of the Center for    Software Science at the University of Utah.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_enum
enum|enum
name|cmp_type
comment|/* comparison type */
block|{
name|CMP_SI
block|,
comment|/* compare integers */
name|CMP_SF
block|,
comment|/* compare single precision floats */
name|CMP_DF
block|,
comment|/* compare double precision floats */
name|CMP_MAX
comment|/* max comparison type */
block|}
enum|;
end_enum

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (hppa)");
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
comment|/* compile code for HP-PA 1.1 ("Snake") */
end_comment

begin_define
define|#
directive|define
name|TARGET_SNAKE
value|(target_flags& 1)
end_define

begin_comment
comment|/* Force gcc not to use the bss segment.  This is (temporarily) provided     for sites which are using pa-gas-1.36 versions prior to Aug 7, 1992.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_NO_BSS
value|(target_flags& 2)
end_define

begin_comment
comment|/* Force gcc to only use instructions which are safe when compiling kernels.    Specifically, avoid using add instructions with dp (r27) as an argument.    Use addil instructions instead.  Doing so avoids a nasty bug in the     HPUX linker.  When HP fixes their linker take this option out.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_KERNEL
value|(target_flags& 4)
end_define

begin_comment
comment|/* Generate code that will link against HPUX 8.0 shared libraries.    Older linkers and assemblers might not support this. */
end_comment

begin_define
define|#
directive|define
name|TARGET_SHARED_LIBS
value|(target_flags& 8)
end_define

begin_comment
comment|/* Force all function calls to indirect addressing via a register.  This    avoids lossage when the function is very far away from the current PC.     ??? What about simple jumps, they can suffer from the same problem.      Would require significant surgery in pa.md.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_LONG_CALLS
value|(target_flags& 16)
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{{"snake", 1},	\    {"nosnake", -1},	\    {"pa-risc-1-0", -1},	\    {"pa-risc-1-1", 1},	\    {"no-bss", 2},	\    {"kernel", 4},	\    {"shared-libs", 8},	\    {"no-shared-libs", -8},\    {"long-calls", 16},	\    { "", TARGET_DEFAULT}}
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|DEFAULT_GDB_EXTENSIONS
value|0
end_define

begin_if
if|#
directive|if
operator|(
name|TARGET_DEFAULT
operator|&
literal|1
operator|)
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{msnake:-D__hp9000s700 -D_PA_RISC1_1}\  %{mpa-risc-1-1:-D__hp9000s700 -D_PA_RISC1_1}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!mpa-risc-1-0:-D__hp9000s700 -D_PA_RISC1_1}\  %{!mnosnake:-D__hp9000s700 -D_PA_RISC1_1}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Defines for a K&R CC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OLD_CC
end_ifdef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{!gnu:-nostdinc %{!nostinc:-I/usr/include}} \   %{gnu:%{nostdinc}} %{!gnu:-traditional} -Dvolatile=__volatile"
end_define

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{!gnu:-traditional -fwritable-strings -fno-defer-pop} \   %{pg:} %{p:}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{pg:} %{p:}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-u main"
end_define

begin_comment
comment|/* Make gcc agree with<machine/ansi.h> */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
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
value|{  								\   if (OPTIMIZE>= 2) 						\     flag_omit_frame_pointer = 1;				\ }
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dhppa -Dhp9000s800 -D__hp9000s800 -Dhp9k8 -Dunix -D_HPUX_SOURCE -Dhp9000 -Dhp800 -Dspectrum -DREVARGV"
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
comment|/* That is true on the HP-PA.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is lowest    numbered.  */
end_comment

begin_comment
comment|/* For the HP-PA we can decide arbitrarily    since there are no machine instructions for them.  */
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
comment|/* Largest alignment required for any stack parameter, in bits.    Don't define this if it is equal to PARM_BOUNDARY */
end_comment

begin_define
define|#
directive|define
name|MAX_PARM_BOUNDARY
value|64
end_define

begin_comment
comment|/* Boundary (in *bits*) on which stack pointer should be aligned.  */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|(TARGET_SNAKE ? 512 : 64)
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
comment|/* Get around hp-ux assembler bug, and make strcpy of constants fast. */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_ALIGNMENT
parameter_list|(
name|CODE
parameter_list|,
name|TYPEALIGN
parameter_list|)
define|\
value|((TYPEALIGN)< 32 ? 32 : (TYPEALIGN))
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

begin_comment
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.     HP-PA 1.0 has 32 fullword registers and 16 floating point    registers. The floating point registers hold either word or double    word values.        16 additional registers are reserved.        HP-PA 1.1 has 32 fullword registers and 32 floating point    registers. However, the floating point registers behave    differently: the left and right halves of registers are addressable    as 32 bit registers. So, we will set things up like the 68k which    has different fp units: define separate register sets for the 1.0    and 1.1 fp units. */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|113
end_define

begin_comment
comment|/* 32 + 16 1.0 regs + 64 1.1 regs + */
end_comment

begin_comment
comment|/* 1 shift reg */
end_comment

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.     On the HP-PA, these are:    Reg 0	= 0 (hardware). However, 0 is used for condition code,                   so is not fixed.    Reg 1	= ADDIL target/Temporary (hardware).    Reg 2	= Return Pointer    Reg 3	= Unused    Reg 4	= Frame Pointer (Gnu)    Reg 5-18	= Preserved Registers    Reg 19	= Linkage Table Register in HPUX 8.0 shared library scheme.    Reg 20-22	= Temporary Registers    Reg 23-26	= Temporary/Parameter Registers    Reg 27	= Global Data Pointer (hp)    Reg 28	= Temporary/???/Return Value register    Reg 29	= Temporary/Static Chain/Return Value register    Reg 30	= stack pointer    Reg 31	= Temporary/Millicode Return Pointer (hp)     Freg 0-3	= Status Registers    Freg 4-7	= Arguments/Return Value    Freg 8-11	= Temporary Registers    Freg 12-15	= Preserved Registers     Freg 16-31	= Reserved     On the Snake, fp regs are     Freg 0-3	= Status Registers    Freg 4L-7R	= Arguments/Return Value    Freg 8L-11R	= Temporary Registers    Freg 12L-15R	= Preserved Registers     Freg 16L-31R	= ?? Some partition of temporary and preserved; assume    preserved for now.      */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{0, 0, 1, 1, 1, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 1, 0, 0, 1, 1, \
comment|/* 1.0 fp registers */
value|\   1, 1, 1, 1, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \
comment|/* 1.1 fp registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   1}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 1, 1, 1, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, \
comment|/* 1.0 fp registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 0, 0, 0, 0, \
comment|/* 1.1 fp registers */
value|\   1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, \   1, 1, 1, 1, 1, 1, 1, 1, \   1}
end_define

begin_comment
comment|/* Make sure everything's fine if we *don't* have a given processor.    This assumes that putting a register in fixed_regs will keep the    compiler's mitts completely off it.  We don't bother to zero it out    of register classes.      Make register 27 global for now.  We'll undo this kludge after 2.1.  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|{						\   int i;					\   HARD_REG_SET x;				\   global_regs[27] = 1;				\   if (!TARGET_SNAKE)				\     {						\       COPY_HARD_REG_SET (x, reg_class_contents[(int)SNAKE_FP_REGS]);\       for (i = 0; i< FIRST_PSEUDO_REGISTER; i++ ) \        if (TEST_HARD_REG_BIT (x, i)) 		\ 	fixed_regs[i] = call_used_regs[i] = 1; 	\     }						\   else						\     { 						\       COPY_HARD_REG_SET (x, reg_class_contents[(int)FP_REGS]); \       for (i = 0; i< FIRST_PSEUDO_REGISTER; i++ ) \        if (TEST_HARD_REG_BIT (x, i)) 		\ 	fixed_regs[i] = call_used_regs[i] = 1; 	\     } 						\ }
end_define

begin_comment
comment|/* Allocated the call used registers first.  This should minimize    the number of registers that need to be saved (as call used    registers will generally not be allocated across a call).     It is possible that it would be wise to allocate the floating point    registers before the regular ones, but I doubt it matters.  Same    comment for parameters versus normal.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{19, 20, 21, 22, 23, 24, 25, 26,	\   27, 28, 29, 30, 31, 40, 41, 42,	\   43, 36, 37, 38, 39,			\   56, 57, 58, 59, 60, 61, 62, 63, 	\   64, 65, 66, 67, 68, 69, 70, 71, 	\   72, 73, 74, 75, 76, 77, 78, 79, 	\   80, 81, 82, 83, 84, 85, 86, 87, 	\   88, 89, 90, 91, 92, 93, 94, 95, 	\   96, 97, 98, 99, 100, 101, 102, 103, 	\   104, 105, 106, 107, 108, 109, 110, 111,\    5,  6,  7,				\    8,  9, 10, 11, 12, 13, 14, 15,	\   16, 17, 18, 44, 45, 46, 47,		\   48, 49, 50, 51, 52, 53, 54, 55,	\      1,	\    2,  3,  4, 32, 33, 34, 35,  0,	\    112}
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On the HP-PA, ordinary registers hold 32 bits worth;    The floating point registers are 64 bits wide. Snake fp regs are 32    bits wide */
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
value|(((REGNO)< 32 || (REGNO)>= 48)	\    ? ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD) : 1)
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On the HP-PA, the cpu registers can hold any mode.  We    force this to be an even register is it cannot hold the full mode.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

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
value|((REGNO) == 0 ? (MODE) == CCmode || (MODE) == CCFPmode		\    : (REGNO)< 32 ? ((GET_MODE_SIZE (MODE)<= 4) ? 1 : ((REGNO)& 1) == 0)\    : (REGNO)< 48 ? (GET_MODE_SIZE (MODE)>= 4)				\    : (GET_MODE_SIZE (MODE)> 4 ? ((REGNO)& 1) == 0			\       : GET_MODE_SIZE (MODE) == 4))
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|((REGNO) == 0 ? (MODE) == CCmode || (MODE) == CCFPmode		\    : (REGNO)< 32 ? ((GET_MODE_SIZE (MODE)<= 4) ? 1 : ((REGNO)& 1) == 0)\    : (REGNO)< 48 ? (GET_MODE_SIZE (MODE)>= 4)				\    : (GET_MODE_SIZE (MODE)> 4 ? ((REGNO)& 1) == 0			\       : 1))
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
comment|/* The HP-PA pc isn't overloaded on a register that the compiler knows about.  */
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
value|30
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|4
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms    may be accessed via the stack pointer) in functions that seem suitable.    This is computed in `reload', in reload1.c.  */
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
value|(current_function_calls_alloca)
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
value|do { int __fsize = compute_frame_size (get_frame_size (), 1, 0) + 32;	\        (VAR) = -(TARGET_SNAKE ? (__fsize + 63)& ~63 : __fsize); } while (0)
end_define

begin_comment
comment|/* Base register for access to arguments of the function.  */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|4
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
value|29
end_define

begin_comment
comment|/* Register which holds offset table for position-independent    data references.  */
end_comment

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|19
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
comment|/* Register in which address to store a structure value    is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|28
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_comment
comment|/* The HP-PA has four kinds of registers: general regs, 1.0 fp regs,      1.1 fp regs, and the high 1.1 fp regs, to which the operands of      fmpyadd and fmpysub are restricted.       FP_OR_SNAKE_FP_REGS is for reload_{in,out}di only and isn't used      anywhere else.*/
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|R1_REGS
block|,
name|GENERAL_REGS
block|,
name|FP_REGS
block|,
name|GENERAL_OR_FP_REGS
block|,
name|HI_SNAKE_FP_REGS
block|,
name|SNAKE_FP_REGS
block|,
name|GENERAL_OR_SNAKE_FP_REGS
block|,
name|FP_OR_SNAKE_FP_REGS
block|,
name|SHIFT_REGS
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
value|{ "NO_REGS", "R1_REGS", "GENERAL_REGS", "FP_REGS", "GENERAL_OR_FP_REGS",\     "HI_SNAKE_FP_REGS", "SNAKE_FP_REGS", "GENERAL_OR_SNAKE_FP_REGS",\     "FP_OR_SNAKE_FP_REGS","SHIFT_REGS", "ALL_REGS"}
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES. Register 0, the "condition code" register,    is in no class. */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{ {0, 0, 0, 0},
comment|/* NO_REGS */
value|\   {0x2, 0, 0, 0},
comment|/* R1_REGS */
value|\   {-2, 0, 0, 0},
comment|/* GENERAL_REGS */
value|\   {0, 0xffff, 0, 0},
comment|/* FP_REGS */
value|\   {-2, 0xffff, 0, 0},
comment|/* GENERAL_OR_FP_REGS */
value|\   {0, 0, 0xffff0000, 0xffff},
comment|/* HI_SNAKE_FP_REGS */
value|\   {0, 0xffff0000, ~0, 0xffff},
comment|/* SNAKE_FP_REGS */
value|\   {-2, 0xffff0000, ~0, 0xffff},
comment|/* GENERAL_OR_SNAKE_FP_REGS */
value|\   {0, ~0, ~0, 0xffff},
comment|/* FP_OR_SNAKE_FP_REGS */
value|\   {0, 0, 0, 0x10000},
comment|/* SHIFT_REGS */
value|\   {-2, ~0, ~0, 0x1ffff}}
end_define

begin_comment
comment|/* ALL_REGS */
end_comment

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
value|((REGNO) == 0 ? NO_REGS 		\    : (REGNO) == 1 ? R1_REGS		\    : (REGNO)< 32 ? GENERAL_REGS	\    : (REGNO)< 48 ? FP_REGS		\    : (REGNO)< 80 ? SNAKE_FP_REGS	\    : (REGNO)< 112 ? HI_SNAKE_FP_REGS	\    : SHIFT_REGS)
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
value|((C) == 'f' ? (!TARGET_SNAKE ? FP_REGS : NO_REGS) :		\    ((C) == 'x' ? (TARGET_SNAKE ? SNAKE_FP_REGS : NO_REGS) :	\     ((C) == 'y' ? (TARGET_SNAKE ? HI_SNAKE_FP_REGS : NO_REGS) :	\      ((C) == 'q' ? SHIFT_REGS :					\       ((C) == 'a' ? R1_REGS :					\        ((C) == 'z' ? FP_OR_SNAKE_FP_REGS : NO_REGS))))))
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.  HP-PA immediate field sizes:   5 bits: scalar/floating short loads + stores; deposit; conditional branch   11 bits: arithmetic immediate, compare immediate   14 bits: loads and stores; load offset   21 bits: load and add immediate long (but this isn't really used)   (there are also 13-bit and 26-bit immediates but only in system instructions)     `I' is used for the 11 bit constants.    `J' is used for the 14 bit constants.    `K' is used for unsigned 5 bit constants (extract/deposit operands).    `L' is used for the 5 bit constants.    `M' is used for 0.  */
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
value|((C) == 'I' ? (unsigned) ((VALUE) + 0x400)< 0x800		\    : (C) == 'J' ? (unsigned) ((VALUE) + 0x2000)< 0x4000	\    : (C) == 'K' ? (unsigned) (VALUE)< 0x20			\    : (C) == 'L' ? (unsigned) ((VALUE) + 0x10)< 0x20		\    : (C) == 'M' ? (VALUE) == 0					\    : (C) == 'O' ? (((VALUE)& ((VALUE) + 1)) == 0)		\    : (C) == 'P' ? consec_zeros_p (VALUE)			\    : 0)
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
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
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
value|((CLASS) == FP_REGS ? 1 : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_escape
end_escape

begin_comment
comment|/* Stack layout; function entry, exit and calling.  */
end_comment

begin_comment
comment|/* Define this if pushing a word on the stack    makes the stack pointer a smaller address.  */
end_comment

begin_comment
comment|/* #define STACK_GROWS_DOWNWARD */
end_comment

begin_comment
comment|/* Believe it or not.  */
end_comment

begin_define
define|#
directive|define
name|ARGS_GROW_DOWNWARD
end_define

begin_comment
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
end_comment

begin_comment
comment|/* #define FRAME_GROWS_DOWNWARD */
end_comment

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.    If FRAME_GROWS_DOWNWARD, this is the offset to the END of the    first local allocated.  Otherwise, it is the offset to the BEGINNING    of the first local allocated.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|8
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On the HP-PA, don't define this because there are no push insns.  */
end_comment

begin_comment
comment|/*  #define PUSH_ROUNDING(BYTES) */
end_comment

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.    This value will be negated because the arguments grow down.    Also note that on STACK_GROWS_UPWARD machines (such as this one)    this is the distance from the frame pointer to the end of the first    argument, not it's beginning.  To get the real offset of the first    argument, the size of the argument must be added.     ??? Have to check on this.*/
end_comment

begin_comment
comment|/* #define FIRST_PARM_OFFSET(FNDECL) 36  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|-32
end_define

begin_comment
comment|/* Absolute value of offset from top-of-stack address to location to store the    function parameter if it can't go in a register.    Addresses for following parameters are computed relative to this one.  */
end_comment

begin_comment
comment|/* #define FIRST_PARM_CALLER_OFFSET(FNDECL) 36 */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_CALLER_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|-32
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
value|16
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
comment|/* Keep the stack pointer constant throughout the function.    This is both an optimization and a necessity: longjmp    doesn't behave itself when the stack pointer moves within    the function!  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
end_define

begin_comment
comment|/* The weird HPPA calling conventions require a minimum of 48 bytes on     the stack: 16 bytes for register saves, and 32 bytes for magic.    This is the difference between the logical top of stack and the    actual sp. */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|-32
end_define

begin_define
define|#
directive|define
name|STACK_DYNAMIC_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
define|\
value|((STACK_POINTER_OFFSET) - current_function_outgoing_args_size)
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
parameter_list|,
name|SIZE
parameter_list|)
value|0
end_define

begin_comment
comment|/* Define how to find the value returned by a function.    VALTYPE is the data type of the value (as a tree).    If the precise function being called is known, FUNC is its FUNCTION_DECL;    otherwise, FUNC is 0.  */
end_comment

begin_comment
comment|/* On the HP-PA the value is found in register(s) 28(-29), unless    the mode is SF or DF. Then the value is returned in fr4 (36, ) */
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
value|gen_rtx (REG, TYPE_MODE (VALTYPE), ((TYPE_MODE (VALTYPE) == SFmode ||\ 				       TYPE_MODE (VALTYPE) == DFmode) ? \ 				      (TARGET_SNAKE ? 56 : 36) : 28))
end_define

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
value|FUNCTION_VALUE(VALTYPE, FUNC)
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
value|gen_rtx (REG, MODE, (MODE == SFmode || MODE == DFmode ?\ 		       (TARGET_SNAKE ? 56 : 36) : 28))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value    as seen by the caller.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 28 || (N) == 36 || (N) == 56)
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|(((N)>= 23&& (N)<= 26) || \ 				 ((N)>= 36&& (N)<= 39) || \ 				 ((N)>= 56&& (N)<= 63))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the HP-PA, this is a single integer, which is a number of words    of arguments scanned so far (including the invisible argument,    if any, which holds the structure-value-address).    Thus 4 or more means all following args should go on the stack.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0. */
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
comment|/* Figure out the size in words of the function argument. */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_SIZE
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|((((MODE) != BLKmode ? GET_MODE_SIZE (MODE) : int_size_in_bytes (TYPE))+3)/4)
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
value|(((((CUM)& 01)&& (TYPE) != 0&& FUNCTION_ARG_SIZE(MODE, TYPE)> 1)\&& (CUM)++), (CUM) += FUNCTION_ARG_SIZE(MODE, TYPE))
end_define

begin_comment
comment|/* Determine where to put an argument to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).  */
end_comment

begin_comment
comment|/* On the HP-PA the first four words of args are normally in registers    and the rest are pushed.  But any arg that won't entirely fit in regs    is pushed.     Arguments passed in registers are either 1 or 2 words long. */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_PADDING
parameter_list|(
name|MODE
parameter_list|,
name|TYPE
parameter_list|)
value|function_arg_padding ((MODE), (TYPE))
end_define

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
value|(4>= ((CUM) + FUNCTION_ARG_SIZE ((MODE), (TYPE)))			\    ? gen_rtx (REG, (MODE),						\ 	      (FUNCTION_ARG_SIZE ((MODE), (TYPE))> 1			\ 	       ? ((MODE) == DFmode					\ 		  ? ((CUM) ? (TARGET_SNAKE ? 62 : 39)			\ 		     : (TARGET_SNAKE ? 58 : 37))			\ 		  : ((CUM) ? 23 : 25))					\ 	       : ((MODE) == SFmode					\ 		  ? (TARGET_SNAKE ? 56 + 2 * (CUM) : 36  + (CUM))	\ 		  : (27 - (CUM) - FUNCTION_ARG_SIZE ((MODE), (TYPE))))))\    : 0)
end_define

begin_comment
comment|/* Define where a function finds its arguments.    This would be different from FUNCTION_ARG if we had register windows.  */
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
value|FUNCTION_ARG (CUM, MODE, TYPE, NAMED)
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
comment|/* If defined, a C expression that gives the alignment boundary, in    bits, of an argument with the specified mode and type.  If it is    not defined,  `PARM_BOUNDARY' is used for all arguments.  */
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
value|(((TYPE) != 0)							\ 	? ((TYPE_ALIGN(TYPE)<= PARM_BOUNDARY)				\ 		? PARM_BOUNDARY						\ 		: TYPE_ALIGN(TYPE))					\ 	: ((GET_MODE_ALIGNMENT(MODE)<= PARM_BOUNDARY)			\ 		? PARM_BOUNDARY						\ 		: GET_MODE_ALIGNMENT(MODE)))
end_define

begin_comment
comment|/* Arguments larger than eight bytes are passed by invisible reference */
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
value|((TYPE)&& int_size_in_bytes (TYPE)> 8)
end_define

begin_escape
end_escape

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|hppa_compare_op0
decl_stmt|,
modifier|*
name|hppa_compare_op1
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|cmp_type
name|hppa_branch_type
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Output the label for a function definition.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HP_FP_ARG_DESCRIPTOR_REVERSED
end_ifdef

begin_define
define|#
directive|define
name|ASM_DOUBLE_ARG_DESCRIPTORS
parameter_list|(
name|FILE
parameter_list|,
name|ARG0
parameter_list|,
name|ARG1
parameter_list|)
define|\
value|do { fprintf (FILE, ",ARGW%d=FR", (ARG0));		\        fprintf (FILE, ",ARGW%d=FU", (ARG1));} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_DOUBLE_ARG_DESCRIPTORS
parameter_list|(
name|FILE
parameter_list|,
name|ARG0
parameter_list|,
name|ARG1
parameter_list|)
define|\
value|do { fprintf (FILE, ",ARGW%d=FU", (ARG0));		\        fprintf (FILE, ",ARGW%d=FR", (ARG1));} while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|do { tree fntype = TREE_TYPE (TREE_TYPE (DECL));			\ 	 tree tree_type = TREE_TYPE (DECL);				\ 	 tree parm;							\ 	 int i;								\ 	 if (TREE_PUBLIC (DECL))					\ 	   { extern int current_function_varargs;			\ 	     fputs ("\t.EXPORT ", FILE); assemble_name (FILE, NAME);	\ 	     fputs (",ENTRY,PRIV_LEV=3", FILE);				\ 	     for (parm = DECL_ARGUMENTS (DECL), i = 0; parm&& i< 4;	\ 		  parm = TREE_CHAIN (parm))				\ 	       {							\ 		 if (TYPE_MODE (DECL_ARG_TYPE (parm)) == SFmode)	\ 		   fprintf (FILE, ",ARGW%d=FR", i++);			\ 		 else if (TYPE_MODE (DECL_ARG_TYPE (parm)) == DFmode)	\ 		   {							\ 		     if (i<= 2)					\ 		       {						\ 			 if (i == 1) i++;				\ 			 ASM_DOUBLE_ARG_DESCRIPTORS (FILE, i++, i++);	\ 		       }						\ 		     else						\ 		       break;						\ 		   }							\ 		 else							\ 		   {							\ 		     int arg_size =					\ 		       FUNCTION_ARG_SIZE (TYPE_MODE (DECL_ARG_TYPE (parm)),\ 					  DECL_ARG_TYPE (parm));	\ 		     if (arg_size == 2&& i<= 2)			\ 		       {						\ 			 if (i == 1) i++;				\ 			 fprintf (FILE, ",ARGW%d=GR", i++);		\ 			 fprintf (FILE, ",ARGW%d=GR", i++);		\ 		       }						\ 		     else if (arg_size == 1)				\ 		       fprintf (FILE, ",ARGW%d=GR", i++);		\ 		     else						\ 		       i += arg_size;					\ 		   }							\ 	       }							\
comment|/* anonymous args */
value|\ 	     if ((TYPE_ARG_TYPES (tree_type) != 0			\&& (TREE_VALUE (tree_last (TYPE_ARG_TYPES (tree_type)))\ 		      != void_type_node))				\ 		 || current_function_varargs)				\ 	       {							\ 		 for (; i< 4; i++)					\ 		   fprintf (FILE, ",ARGW%d=GR", i);			\ 	       }							\ 	     if (TYPE_MODE (fntype) == DFmode)				\ 	       fprintf (FILE, ",RTNVAL=FR");				\ 	     else if (TYPE_MODE (fntype) == SFmode)			\ 	       fprintf (FILE, ",RTNVAL=FU");				\ 	     else if (fntype != void_type_node)				\ 	       fprintf (FILE, ",RTNVAL=GR");				\ 	     fputs ("\n", FILE);					\ 	   }								\ 	 ASM_OUTPUT_LABEL (FILE, NAME);} while (0)
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
comment|/* On HP-PA, move-double insns between fpu and cpu need an 8-byte block    of memory.  If any fpu reg is used in the function, we allocate    such a block here, at the bottom of the frame, just in case it's needed.     If this function is a leaf procedure, then we may choose not    to do a "save" insn.  The decision about whether or not    to do this is made in regclass.c.  */
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
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.     Because HPUX _mcount is so different, we actually emit the    profiling code in function_prologue. This just stores LABELNO for    that. */
end_comment

begin_define
define|#
directive|define
name|PROFILE_BEFORE_PROLOGUE
end_define

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
value|{ extern int hp_profile_labelno; hp_profile_labelno = (LABELNO);}
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

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
value|{}
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|0
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
value|{}
end_define

begin_comment
comment|/* Emit code for a call to builtin_saveregs.  We must emit USE insns which    reference the 4 integer arg registers and 4 fp arg registers.    Ordinarily they are not call used registers, but they are for    _builtin_saveregs, so we must make this explicit.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_SAVEREGS
parameter_list|(
name|ARGLIST
parameter_list|)
define|\
value|(emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, TImode, 23))),	\    (TARGET_SNAKE ?							\     (emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, DFmode, 56))),	\      emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, DFmode, 58))),	\      emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, DFmode, 60))),	\      emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, DFmode, 62)))) :	\     (emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, DFmode, 36))),	\      emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, DFmode, 37))),	\      emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, DFmode, 38))),	\      emit_insn (gen_rtx (USE, VOIDmode, gen_rtx (REG, DFmode, 39))))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_SAVEREGS
parameter_list|(
name|ARGLIST
parameter_list|)
value|(rtx)hppa_builtin_saveregs (ARGLIST)
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

begin_define
define|#
directive|define
name|HAVE_POST_DECREMENT
end_define

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
value|((REGNO)&& ((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< 32))
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)&& ((REGNO)< 32 || (unsigned) reg_renumber[REGNO]< 32))
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_FP_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO)>= 32&& (REGNO)<= 111)\    || (reg_renumber[REGNO]>= 32&& reg_renumber[REGNO]<= 111))
end_define

begin_comment
comment|/* Now macros that check whether X is a register and also,    strictly, whether it is in a specified class.     These macros are specific to the the HP-PA, and may be used only    in code for printing assembler insns and in conditions for    define_optimization.  */
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
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */
end_comment

begin_comment
comment|/*#define LEGITIMATE_CONSTANT_P(X) (1)*/
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

begin_comment
comment|/* Optional extra constraints for this machine. Borrowed from sparc.h.     For the HPPA, `Q' means that this is a memory operand but not a    symbolic memory operand.  Note that an unassigned pseudo register    is such a memory operand.  Needed because reload will generate    these things in insns and then not re-recognize the insns, causing    constrain_operands to fail.     `R' handles the LO_SUM which can be an address for `Q'.     `S' handles constraints for calls.     `T' is for fp load and store addresses.*/
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
value|(REGNO (X)&& (REGNO (X)< 32 || REGNO (X)> FIRST_PSEUDO_REGISTER))
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
value|(REGNO (X)&& (REGNO (X)< 32 || REGNO (X)> FIRST_PSEUDO_REGISTER))
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
value|((C) == 'Q' ?						\    ((GET_CODE (OP) == MEM				\&& memory_address_p (GET_MODE (OP), XEXP (OP, 0))	\&& ! symbolic_memory_operand (OP, VOIDmode)))	\    : ((C) == 'R' ?					\       (GET_CODE (OP) == LO_SUM				\&& GET_CODE (XEXP (OP, 0)) == REG		\&& REG_OK_FOR_BASE_P (XEXP (OP, 0)))		\       : ((C) == 'S'					\ 	 ? CONSTANT_P (OP) || memory_address_p (Pmode, OP)\ 	 : ((C) == 'T' ? short_memory_operand (OP, VOIDmode) : 0))))\   #else
end_define

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
value|(((C) == 'Q' || (C) == 'T') ?				\    (GET_CODE (OP) == REG ?				\     (REGNO (OP)>= FIRST_PSEUDO_REGISTER		\&& reg_renumber[REGNO (OP)]< 0)			\     : GET_CODE (OP) == MEM)				\    : ((C) == 'R' ?					\       (GET_CODE (OP) == LO_SUM				\&& GET_CODE (XEXP (OP, 0)) == REG		\&& REG_OK_FOR_BASE_P (XEXP (OP, 0)))		\       : (CONSTANT_P (OP)				\ 	    || (GET_CODE (OP) == REG&& reg_renumber[REGNO (OP)]> 0)\ 	    || strict_memory_address_p (Pmode, OP))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     On the HP-PA, the actual legitimate addresses must be    REG+REG, REG+(REG*SCALE) or REG+SMALLINT.    But we can treat a SYMBOL_REF as legitimate if it is part of this    function's constant-pool, because such addresses can actually    be output as REG+SMALLINT.  */
end_comment

begin_define
define|#
directive|define
name|VAL_5_BITS_P
parameter_list|(
name|X
parameter_list|)
value|((unsigned)(X) + 0x10< 0x20)
end_define

begin_define
define|#
directive|define
name|INT_5_BITS
parameter_list|(
name|X
parameter_list|)
value|VAL_5_BITS_P (INTVAL (X))
end_define

begin_define
define|#
directive|define
name|VAL_U5_BITS_P
parameter_list|(
name|X
parameter_list|)
value|((unsigned)(X)< 0x20)
end_define

begin_define
define|#
directive|define
name|INT_U5_BITS
parameter_list|(
name|X
parameter_list|)
value|VAL_U5_BITS_P (INTVAL (X))
end_define

begin_define
define|#
directive|define
name|VAL_11_BITS_P
parameter_list|(
name|X
parameter_list|)
value|((unsigned)(X) + 0x400< 0x800)
end_define

begin_define
define|#
directive|define
name|INT_11_BITS
parameter_list|(
name|X
parameter_list|)
value|VAL_11_BITS_P (INTVAL (X))
end_define

begin_define
define|#
directive|define
name|VAL_14_BITS_P
parameter_list|(
name|X
parameter_list|)
value|((unsigned)(X) + 0x2000< 0x4000)
end_define

begin_define
define|#
directive|define
name|INT_14_BITS
parameter_list|(
name|X
parameter_list|)
value|VAL_14_BITS_P (INTVAL (X))
end_define

begin_define
define|#
directive|define
name|FITS_14_BITS
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == CONST_INT&& INT_14_BITS (X))
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
value|{							\   if ((REG_P (X)&& REG_OK_FOR_BASE_P (X))		\       || ((GET_CODE (X) == PRE_DEC || GET_CODE (X) == POST_DEC		\ 	   || GET_CODE (X) == PRE_INC || GET_CODE (X) == POST_INC)	\&& REG_P (XEXP (X, 0))			\&& REG_OK_FOR_BASE_P (XEXP (X, 0))))		\     goto ADDR;						\   else if (GET_CODE (X) == PLUS)			\     {							\       rtx base = 0, index;				\       if (flag_pic&& XEXP (X, 0) == pic_offset_table_rtx)\ 	{						\ 	  if (GET_CODE (XEXP (X, 1)) == REG		\&& REG_OK_FOR_BASE_P (XEXP (X, 1)))	\ 	    goto ADDR;					\ 	  else if (flag_pic == 1			\&& GET_CODE (XEXP (X, 1)) != REG	\&& GET_CODE (XEXP (X, 1)) != LO_SUM	\&& GET_CODE (XEXP (X, 1)) != MEM)	\ 	    goto ADDR;					\ 	}						\       else if (REG_P (XEXP (X, 0))			\&& REG_OK_FOR_BASE_P (XEXP (X, 0)))		\ 	base = XEXP (X, 0), index = XEXP (X, 1);	\       else if (REG_P (XEXP (X, 1))			\&& REG_OK_FOR_BASE_P (XEXP (X, 1)))	\ 	base = XEXP (X, 1), index = XEXP (X, 0);	\       if (base != 0)					\ 	if (GET_CODE (index) == CONST_INT		\&& ((INT_14_BITS (index)&& (MODE) != SFmode&& (MODE) != DFmode) \ 		|| INT_5_BITS (index)))			\ 	  goto ADDR;					\     }							\   else if (GET_CODE (X) == LO_SUM			\&& GET_CODE (XEXP (X, 0)) == REG		\&& REG_OK_FOR_BASE_P (XEXP (X, 0))		\&& CONSTANT_P (XEXP (X, 1))			\&& (MODE) != SFmode				\&& (MODE) != DFmode)				\     goto ADDR;						\   else if (GET_CODE (X) == LO_SUM			\&& GET_CODE (XEXP (X, 0)) == SUBREG		\&& GET_CODE (SUBREG_REG (XEXP (X, 0))) == REG\&& REG_OK_FOR_BASE_P (SUBREG_REG (XEXP (X, 0)))\&& CONSTANT_P (XEXP (X, 1))			\&& (MODE) != SFmode				\&& (MODE) != DFmode)				\     goto ADDR;						\   else if (GET_CODE (X) == LABEL_REF			\ 	   || (GET_CODE (X) == CONST_INT		\&& INT_14_BITS (X)))			\     goto ADDR;						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.  */
end_comment

begin_comment
comment|/* On the HP-PA, change REG+N into REG+REG, and REG+(X*Y) into REG+REG.  */
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
value|{ if (GET_CODE (X) == PLUS&& CONSTANT_ADDRESS_P (XEXP (X, 1)))	\     (X) = gen_rtx (PLUS, SImode, XEXP (X, 0),			\ 		   copy_to_mode_reg (SImode, XEXP (X, 1)));	\   if (GET_CODE (X) == PLUS&& CONSTANT_ADDRESS_P (XEXP (X, 0)))	\     (X) = gen_rtx (PLUS, SImode, XEXP (X, 1),			\ 		   copy_to_mode_reg (SImode, XEXP (X, 0)));	\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 0)) == MULT)	\     (X) = gen_rtx (PLUS, SImode, XEXP (X, 1),			\ 		   force_operand (XEXP (X, 0), 0));		\   if (GET_CODE (X) == PLUS&& GET_CODE (XEXP (X, 1)) == MULT)	\     (X) = gen_rtx (PLUS, SImode, XEXP (X, 0),			\ 		   force_operand (XEXP (X, 1), 0));		\   if (memory_address_p (MODE, X))				\     goto WIN;							\   if (flag_pic) (X) = legitimize_pic_address (X, MODE, gen_reg_rtx (Pmode));\   else if ((GET_CODE (X) == SYMBOL_REF&& read_only_operand (X))\ 	    || GET_CODE (X) == LABEL_REF)			\     (X) = gen_rtx (LO_SUM, Pmode,				\ 		   copy_to_mode_reg (Pmode, gen_rtx (HIGH, Pmode, X)), X); \   else if (GET_CODE (X) == SYMBOL_REF)				\     {								\       rtx temp2 = gen_reg_rtx (Pmode);				\       emit_insn (gen_rtx (SET, VOIDmode, temp2, 		\ 			  gen_rtx (PLUS, Pmode, gen_rtx (REG, Pmode, 27),\ 				   gen_rtx (HIGH, Pmode, X))));	\       (X) = gen_rtx (LO_SUM, Pmode, temp2, X);	 		\     }								\   if (memory_address_p (MODE, X))				\     goto WIN;}
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.  */
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
value|if (GET_CODE (ADDR) == PRE_DEC	\       || GET_CODE (ADDR) == POST_DEC	\       || GET_CODE (ADDR) == PRE_INC	\       || GET_CODE (ADDR) == POST_INC)	\     goto LABEL
end_define

begin_escape
end_escape

begin_comment
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     The macro definition, if any, is executed immediately after the    rtl for DECL or other node is created.    The value of the rtl will be a `mem' whose address is a    `symbol_ref'.     The usual thing for this macro to do is to a flag in the    `symbol_ref' (such as `SYMBOL_REF_FLAG') or to store a modified    name string in the `symbol_ref' (if one bit is not enough    information).     On the HP-PA we use this to indicate if a symbol is in text or    data space.  Also, function labels need special treatment. */
end_comment

begin_define
define|#
directive|define
name|TEXT_SPACE_P
parameter_list|(
name|DECL
parameter_list|)
define|\
value|(TREE_CODE (DECL) == FUNCTION_DECL					\    || (TREE_CODE (DECL) == VAR_DECL					\&& TREE_READONLY (DECL)&& ! TREE_SIDE_EFFECTS (DECL)		\&& !flag_pic)							\    || (*tree_code_type[(int) TREE_CODE (DECL)] == 'c'			\&& !(TREE_CODE (DECL) == STRING_CST&& flag_writable_strings)))
end_define

begin_define
define|#
directive|define
name|FUNCTION_NAME_P
parameter_list|(
name|NAME
parameter_list|)
define|\
value|(*(NAME) == '@' || (*(NAME) == '*'&& *((NAME) + 1) == '@'))
end_define

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|do							\   { if (TEXT_SPACE_P (DECL))				\       {	rtx _rtl;					\ 	if (TREE_CODE (DECL) == FUNCTION_DECL		\ 	    || TREE_CODE (DECL) == VAR_DECL)		\ 	  _rtl = DECL_RTL (DECL);			\ 	else						\ 	  _rtl = TREE_CST_RTL (DECL);			\ 	SYMBOL_REF_FLAG (XEXP (_rtl, 0)) = 1;		\ 	if (TREE_CODE (DECL) == FUNCTION_DECL)		\ 	  hppa_encode_label (XEXP (DECL_RTL (DECL), 0));\       }							\   }							\ while (0)
end_define

begin_comment
comment|/* Store the user-specified part of SYMBOL_NAME in VAR.    This is sort of inverse to ENCODE_SECTION_INFO.  */
end_comment

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
value|(VAR) = ((SYMBOL_NAME)  + ((SYMBOL_NAME)[0] == '*' ?	\ 			     1 + (SYMBOL_NAME)[1] == '@'\ 			     : (SYMBOL_NAME)[0] == '@'))
end_define

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

begin_comment
comment|/* Define if normal loads of shorter-than-word items from memory clears    the rest of the bigs in the register.  */
end_comment

begin_define
define|#
directive|define
name|BYTE_LOADS_ZERO_EXTEND
end_define

begin_comment
comment|/* Nonzero if access to memory by bytes is slow and undesirable.  */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|1
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
comment|/* Add any extra modes needed to represent the condition code.     HPPA floating comparisons produce condition codes. */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_MODES
value|CCFPmode
end_define

begin_comment
comment|/* Define the names for the modes specified above.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_CC_NAMES
value|"CCFP"
end_define

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.  For floating-point, CCFPmode    should be used.  CC_NOOVmode should be used when the first operand is a    PLUS, MINUS, or NEG.  CCmode should be used when no special processing is    needed.  */
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
value|(GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT ? CCFPmode : CCmode)
end_define

begin_comment
unit|\
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
value|case CONST_INT:						\     if (INTVAL (RTX) == 0) return 0;				\     if (INT_14_BITS (RTX)) return 1;				\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 2;							\   case CONST_DOUBLE:						\     return 4;
end_define

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|RTX
parameter_list|)
define|\
value|(GET_CODE (RTX) == REG ? 1 : hppa_address_cost (RTX))
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
value|((((CLASS1 == FP_REGS || CLASS1 == SNAKE_FP_REGS	\      || CLASS1 == HI_SNAKE_FP_REGS)			\&& (CLASS2 == R1_REGS || CLASS2 == GENERAL_REGS))	\    || ((CLASS1 == R1_REGS || CLASS1 == GENERAL_REGS)	\&& (CLASS2 == FP_REGS || CLASS2 == SNAKE_FP_REGS	\ 	   || CLASS2 == HI_SNAKE_FP_REGS))) ? 6 : 2)
end_define

begin_comment
comment|/* Provide the costs of a rtl expression.  This is in the body of a    switch on CODE.  The purpose for the cost of MULT is to encourage    `synth_mult' to find a synthetic multiply when reasonable.  */
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
value|case MULT:						\     return COSTS_N_INSNS (20);				\   case DIV:						\   case UDIV:						\   case MOD:						\   case UMOD:						\     return COSTS_N_INSNS (60);				\   case PLUS:
comment|/* this includes shNadd insns */
value|\     return COSTS_N_INSNS (1) + 2;
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
name|FILE
parameter_list|)
define|\
value|do { fprintf (FILE, "\t.SPACE $PRIVATE$\n\ \t.SUBSPA $DATA$,QUAD=1,ALIGN=8,ACCESS=31\n\ \t.SUBSPA $BSS$,QUAD=1,ALIGN=8,ACCESS=31,ZERO,SORT=82\n\ \t.SPACE $TEXT$\n\ \t.SUBSPA $LIT$,QUAD=0,ALIGN=8,ACCESS=44\n\ \t.SUBSPA $CODE$,QUAD=0,ALIGN=8,ACCESS=44,CODE_ONLY\n\ \t.IMPORT $global$,DATA\n\ \t.IMPORT $$dyncall,MILLICODE\n");\      if (profile_flag)\        fprintf (FILE, "\t.IMPORT _mcount, CODE\n");\    } while (0)
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
comment|/* We don't yet know how to identify GCC to HP-PA machines.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
value|fprintf (FILE, "; gcc_compiled.:\n")
end_define

begin_comment
comment|/* Output before code.  */
end_comment

begin_comment
comment|/* Supposedly the assembler rejects the command if there is no tab!  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.SPACE $TEXT$\n\t.SUBSPA $CODE$\n"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_comment
comment|/* Supposedly the assembler rejects the command if there is no tab!  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.SPACE $PRIVATE$\n\t.SUBSPA $DATA$\n"
end_define

begin_comment
comment|/* Output before uninitialized data.  */
end_comment

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.SPACE $PRIVATE$\n\t.SUBSPA $BSS$\n"
end_define

begin_comment
comment|/* Define the .bss section for ASM_OUTPUT_LOCAL to use. */
end_comment

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
value|void									\ bss_section ()								\ {									\   if (in_section != in_bss)						\     {									\       fprintf (asm_out_file, "%s\n", BSS_SECTION_ASM_OP);		\       in_section = in_bss;						\     }									\ }
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"0", "%r1", "%r2", "%r3", "%r4", "%r5", "%r6", "%r7",			\  "%r8", "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15",		\  "%r16", "%r17", "%r18", "%r19", "%r20", "%r21", "%r22", "%r23",	\  "%r24", "%r25", "%r26", "%r27", "%r28", "%r29", "%r30", "%r31",	\  "%fr0", "%fr1", "%fr2", "%fr3", "%fr4", "%fr5", "%fr6", "%fr7",	\  "%fr8", "%fr9", "%fr10", "%fr11", "%fr12", "%fr13", "%fr14", "%fr15",	\  "%fr0", "%fr0R", "%fr1", "%fr1R", "%fr2", "%fr2R", "%fr3", "%fr3R",	\  "%fr4", "%fr4R", "%fr5", "%fr5R", "%fr6", "%fr6R", "%fr7", "%fr7R",	\  "%fr8", "%fr8R", "%fr9", "%fr9R", "%fr10", "%fr10R", "%fr11", "%fr11R",\  "%fr12", "%fr12R", "%fr13", "%fr13R", "%fr14", "%fr14R", "%fr15", "%fr15R",\  "%fr16", "%fr16R", "%fr17", "%fr17R", "%fr18", "%fr18R", "%fr19", "%fr19R",\  "%fr20", "%fr20R", "%fr21", "%fr21R", "%fr22", "%fr22R", "%fr23", "%fr23R",\  "%fr24", "%fr24R", "%fr25", "%fr25R", "%fr26", "%fr26R", "%fr27", "%fr27R",\  "%fr28", "%fr28R", "%fr29", "%fr29R", "%fr30", "%fr30R", "%fr31", "%fr31R",\  "SAR"}
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
value|do { assemble_name (FILE, NAME); fputc ('\n', FILE); } while (0)
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
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
value|do { fputs ("\t.IMPORT ", FILE);				\ 	 assemble_name (FILE, NAME);				\        if (FUNCTION_NAME_P (NAME))     				\ 	 fputs (",CODE\n", FILE);				\        else							\ 	 fputs (",DATA\n", FILE);				\      } while (0)
end_define

begin_comment
comment|/* hpux ld doesn't output the object file name, or anything useful at    all, to indicate the start of an object file's symbols. This screws    up gdb, so we'll output this magic cookie at the end of an object    file with debugging symbols */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do { if (write_symbols == DBX_DEBUG)\ 	 { fputs (TEXT_SECTION_ASM_OP, FILE);\ 	   fputs (".stabs \"end_file.\",4,0,0,Ltext_end\nLtext_end:\n",\ 		  (FILE));\ 	 }\      } while (0)
end_define

begin_comment
comment|/* The bogus HP assembler requires ALL external references to be     "imported", even library calls. They look a bit different, so    here's this macro. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL_LIBCALL
parameter_list|(
name|FILE
parameter_list|,
name|RTL
parameter_list|)
define|\
value|do { fputs ("\t.IMPORT ", FILE);					\        assemble_name (FILE, XSTR ((RTL), 0));		       		\        fputs (",CODE\n", FILE);						\      } while (0)
end_define

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
value|do { fputs ("\t.EXPORT ", FILE); assemble_name (FILE, NAME);		\        if (FUNCTION_NAME_P (NAME))					\ 	 fputs (",CODE\n", FILE);					\        else								\ 	 fputs (",DATA\n", FILE);} while (0)
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
value|fprintf ((FILE), "%s", (NAME) + (FUNCTION_NAME_P (NAME) ? 1 : 0))
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
value|fprintf (FILE, "%s$%04d\n", PREFIX, NUM)
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
value|sprintf (LABEL, "*%s$%04d", PREFIX, NUM)
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
value|do { union { double d; int i[2];} __u;	\     __u.d = (VALUE);				\     fprintf (FILE, "\t; .double %.20e\n\t.word %d ; = 0x%x\n\t.word %d ; = 0x%x\n",	\ 	     __u.d, __u.i[0], __u.i[0], __u.i[1], __u.i[1]);	\   } while (0)
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
value|do { union { float f; int i;} __u;		\     __u.f = (VALUE);				\     fprintf (FILE, "\t; .float %.12e\n\t.word %d ; = 0x%x\n", __u.f, __u.i, __u.i); \   } while (0)
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
comment|/* Likewise for `short' and `char' constants.  */
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

begin_if
if|#
directive|if
literal|0
end_if

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
value|fprintf (FILE, "\tstws,mb %s,4(0,30)\n", reg_names[REGNO])
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
value|fprintf (FILE, "\tldws,ma -4(0,30),%s\n", reg_names[REGNO])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|FILE
parameter_list|,
name|REGNO
parameter_list|)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.    Note that this method makes filling these branch delay slots    virtually impossible.  */
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
value|fprintf (FILE, "\tb L$%04d\n\tnop\n", VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    (The HP-PA does not use such vectors,    but we must define this macro anyway.)  */
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
value|fprintf (FILE, "\tword L%d-L%d\n", VALUE, REL)
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
value|fprintf (FILE, "\t.align %d\n", (1<<(LOG)))
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
value|fprintf (FILE, "\t.blockz %d\n", (SIZE))
end_define

begin_comment
comment|/* This says how to output an assembler line    to define a global common symbol.  */
end_comment

begin_comment
comment|/* Supposedly the assembler rejects the command if there is no tab!  */
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
value|( (TARGET_NO_BSS) ? data_section (): bss_section (),	\   assemble_name ((FILE), (NAME)),			\   fputs ("\t.comm ", (FILE)),				\   fprintf ((FILE), "%d\n", (ROUNDED)))
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
value|( (TARGET_NO_BSS) ? data_section (): bss_section (),	\   fprintf ((FILE), "\t.align %d\n", (SIZE)<= 4 ? 4 : 8),	\   assemble_name ((FILE), (NAME)),				\   (TARGET_NO_BSS) ? fprintf ((FILE), "\n\t.blockz %d\n", (ROUNDED)) \ 		  : fprintf ((FILE), "\n\t.block %d\n", (ROUNDED)))
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
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 12),	\   sprintf ((OUTPUT), "%s___%d", (NAME), (LABELNO)))
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
value|((CHAR) == '@' || (CHAR) == '#' || (CHAR) == '*' || (CHAR) == '^')
end_define

begin_comment
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    For `%' followed by punctuation, CODE is the punctuation and X is null.     On the HP-PA, the CODE can be `r', meaning this is a register-only operand    and an immediate zero should be represented as `r0'.     Several % codes are defined:    O an operation    C compare conditions    N extract conditions    M modifier to handle preincrement addressing for memory refs.    F modifier to handle preincrement addressing for fp memory refs */
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
value|{ register rtx addr = ADDR;						\   register rtx base;							\   int offset;								\   switch (GET_CODE (addr))						\     {									\     case REG:								\       fprintf (FILE, "0(0,%s)", reg_names [REGNO (addr)]);		\       break;								\     case PLUS:								\       if (GET_CODE (XEXP (addr, 0)) == CONST_INT)			\ 	offset = INTVAL (XEXP (addr, 0)), base = XEXP (addr, 1);	\       else if (GET_CODE (XEXP (addr, 1)) == CONST_INT)			\ 	offset = INTVAL (XEXP (addr, 1)), base = XEXP (addr, 0);	\       else								\ 	abort ();							\       fprintf (FILE, "%d(0,%s)", offset, reg_names [REGNO (base)]);	\       break;								\     case LO_SUM:							\       fputs ("R'", FILE);						\       output_global_address (FILE, XEXP (addr, 1));			\       fputs ("(", FILE);						\       output_operand (XEXP (addr, 0), 0);				\       fputs (")", FILE);						\       break;								\     case CONST_INT:							\       fprintf (FILE, "%d(0,0)", INTVAL (addr));				\       break;								\     default:								\       output_addr_const (FILE, addr);					\     }}
end_define

begin_escape
end_escape

begin_define
define|#
directive|define
name|SMALL_INT
parameter_list|(
name|OP
parameter_list|)
value|INT_14_BITS (OP)
end_define

begin_comment
comment|/* Define functions in pa.c and used in insn-output.c.  */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_and
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_ior
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
name|output_fp_move_double
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

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_floatsisf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_floatsidf2
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_mul_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_div_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_mod_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_arg_descriptor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_global_address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|legitimize_pic_address
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|gen_cmp_fp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|rtx_def
modifier|*
name|gen_scond_fp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|hppa_encode_label
parameter_list|()
function_decl|;
end_function_decl

end_unit

