begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Sun 68000/68020 version.    Copyright (C) 1987, 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Note that some other tm.h files include this one and then override    many of the definitions that relate to assembler syntax.  */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_comment
comment|/* See sun3.h, sun2.h, isi.h for different CPP_PREDEFINES.  */
end_comment

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MOTOROLA
end_ifdef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (68k, Motorola syntax)");
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (68k, MIT syntax)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define SUPPORT_SUN_FPA to include support for generating code for    the Sun Floating Point Accelerator, an optional product for Sun 3    machines.  By default, it is not defined.  Avoid defining it unless    you need to output code for the Sun3+FPA architecture, as it has the    effect of slowing down the register set operations in hard-reg-set.h    (total number of registers will exceed number of bits in a long,    if defined, causing the set operations to expand to loops).    SUPPORT_SUN_FPA is typically defined in sun3.h.  */
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
comment|/* Compile for a 68020 (not a 68000 or 68010).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_68020
value|(target_flags& 1)
end_define

begin_comment
comment|/* Compile 68881 insns for floating point (not library calls).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_68881
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
comment|/* Compile using rtd insn calling sequence.    This will not work unless you use prototypes at least    for all functions that can take varying numbers of args.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_RTD
value|(target_flags& 8)
end_define

begin_comment
comment|/* Compile passing first two args in regs 0 and 1.    This exists only to test compiler features that will    be needed for RISC chips.  It is not usable    and is not intended to be usable on this cpu.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_REGPARM
value|(target_flags& 020)
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
comment|/* Compile with special insns for Sun FPA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_SUN_FPA
end_ifdef

begin_define
define|#
directive|define
name|TARGET_FPA
value|(target_flags& 0100)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_FPA
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Compile (actually, link) for Sun SKY board.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SKY
value|(target_flags& 0200)
end_define

begin_comment
comment|/* Optimize for 68040, but still allow execution on 68020    (-m68020-40 or -m68040).    The 68040 will execute all 68030 and 68881/2 instructions, but some    of them must be emulated in software by the OS.  When TARGET_68040 is    turned on, these instructions won't be used.  This code will still    run on a 68030 and 68881/2. */
end_comment

begin_define
define|#
directive|define
name|TARGET_68040
value|(target_flags& 01400)
end_define

begin_comment
comment|/* Use the 68040-only fp instructions (-m68040).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_68040_ONLY
value|(target_flags& 01000)
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ { "68020", 5},				\     { "c68020", 5},				\     { "68881", 2},				\     { "bitfield", 4},				\     { "68000", -5},				\     { "c68000", -5},				\     { "soft-float", -0102},			\     { "nobitfield", -4},			\     { "rtd", 8},				\     { "nortd", -8},				\     { "short", 040},				\     { "noshort", -040},				\     { "fpa", 0100},				\     { "nofpa", -0100},				\     { "sky", 0200},				\     { "nosky", -0200},				\     { "68020-40", 0407},				\     { "68030", -01400},				\     { "68030", 7},				\     { "68040", 01007},			\     { "", TARGET_DEFAULT}}
end_define

begin_comment
comment|/* TARGET_DEFAULT is defined in sun*.h and isi.h, etc.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_SUN_FPA
end_ifdef

begin_comment
comment|/* Blow away 68881 flag silently on TARGET_FPA (since we can't clear    any bits in TARGET_SWITCHES above) */
end_comment

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|{					\   if (TARGET_FPA) target_flags&= ~2;	\   if (! TARGET_68020&& flag_pic == 2)	\     error("-fPIC is not currently supported on the 68000 or 68010\n");	\ }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|{					\   if (! TARGET_68020&& flag_pic == 2)	\     error("-fPIC is not currently supported on the 68000 or 68010\n");	\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

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
comment|/* For 68000 we can decide arbitrarily    since there are no machine instructions for them.    So let's be consistent.  */
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
comment|/* Set this nonzero if move instructions will actually fail to work    when given unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

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
value|{									\   if (!flag_pic)							\     readonly_data_section();						\   else if (LEGITIMATE_PIC_OPERAND_P (X))				\     readonly_data_section();						\   else									\     data_section();							\ }
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
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.    For the 68000, we give the data registers numbers 0-7,    the address registers numbers 010-017,    and the 68881 floating point registers numbers 020-027.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|24
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|56
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This defines the register which is used to hold the offset table for PIC. */
end_comment

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|13
end_define

begin_comment
comment|/* Used to output a (use pic_offset_table_rtx) so that we     always save/restore a5 in functions that use PIC relocation    at *any* time during the compilation process. */
end_comment

begin_define
define|#
directive|define
name|FINALIZE_PIC
value|finalize_pic()
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the 68000, only the stack pointer is such.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{
comment|/* Data registers.  */
value|\   0, 0, 0, 0, 0, 0, 0, 0,      \                                \
comment|/* Address registers.  */
value|\   0, 0, 0, 0, 0, 0, 0, 1,      \                                \
comment|/* Floating point registers  \      (if available).  */
value|\   0, 0, 0, 0, 0, 0, 0, 0 }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 0, 0, 0, 0, 0, 0,   \   1, 1, 0, 0, 0, 0, 0, 1,   \   1, 1, 0, 0, 0, 0, 0, 0 }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SUPPORT_SUN_FPA */
end_comment

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the 68000, only the stack pointer is such.  */
end_comment

begin_comment
comment|/* fpa0 is also reserved so that it can be used to move shit back and    forth between high fpa regs and everything else. */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{
comment|/* Data registers.  */
value|\   0, 0, 0, 0, 0, 0, 0, 0,      \                                \
comment|/* Address registers.  */
value|\   0, 0, 0, 0, 0, 0, 0, 1,      \                                \
comment|/* Floating point registers  \      (if available).  */
value|\   0, 0, 0, 0, 0, 0, 0, 0,      \                                \
comment|/* Sun3 FPA registers.  */
value|\   1, 0, 0, 0, 0, 0, 0, 0,      \   0, 0, 0, 0, 0, 0, 0, 0,      \   0, 0, 0, 0, 0, 0, 0, 0,      \   0, 0, 0, 0, 0, 0, 0, 0 }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{1, 1, 0, 0, 0, 0, 0, 0, \   1, 1, 0, 0, 0, 0, 0, 1, \   1, 1, 0, 0, 0, 0, 0, 0, \
comment|/* FPA registers.  */
value|\   1, 1, 1, 1, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0  }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

begin_comment
comment|/* Make sure everything's fine if we *don't* have a given processor.    This assumes that putting a register in fixed_regs will keep the    compiler's mitts completely off it.  We don't bother to zero it out    of register classes.  If neither TARGET_FPA or TARGET_68881 is set,    the compiler won't touch since no instructions that use these    registers will be valid.       Reserve PIC_OFFSET_TABLE_REGNUM (a5) for doing PIC relocation if    position independent code is being generated by making it a     fixed register */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|{                                               \   if (flag_pic)                                 \     fixed_regs[PIC_OFFSET_TABLE_REGNUM] = 1;    \ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|{ 						\   int i; 					\   HARD_REG_SET x; 				\   if (!TARGET_FPA)				\     { 						\       COPY_HARD_REG_SET (x, reg_class_contents[(int)FPA_REGS]); \       for (i = 0; i< FIRST_PSEUDO_REGISTER; i++ ) \        if (TEST_HARD_REG_BIT (x, i)) 		\ 	fixed_regs[i] = call_used_regs[i] = 1; 	\     } 						\   if (TARGET_FPA)				\     { 						\       COPY_HARD_REG_SET (x, reg_class_contents[(int)FP_REGS]); \       for (i = 0; i< FIRST_PSEUDO_REGISTER; i++ ) \        if (TEST_HARD_REG_BIT (x, i)) 		\ 	fixed_regs[i] = call_used_regs[i] = 1; 	\     } 						\   if (flag_pic)                                 \     fixed_regs[PIC_OFFSET_TABLE_REGNUM] = 1;    \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On the 68000, ordinary registers hold 32 bits worth;    for the 68881 registers, a single register is always enough for    anything that can be stored in them at all.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On the 68000, the cpu registers can hold any mode but the 68881 registers    can hold only SFmode or DFmode.  The 68881 registers can't hold anything    if 68881 use is disabled.  */
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
value|(((REGNO)< 16)                                       \    || ((REGNO)< 24				        \&& TARGET_68881                                  \&& (GET_MODE_CLASS (MODE) == MODE_FLOAT		\ 	   || GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On the 68000, the cpu registers can hold any mode but the 68881 registers    can hold only SFmode or DFmode.  And the 68881 registers can't hold anything    if 68881 use is disabled.  However, the Sun FPA register can    (apparently) hold whatever you feel like putting in them.    If using the fpa, don't put a double in d7/a0.  */
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
value|(((REGNO)< 16								\&& !(TARGET_FPA							\&& GET_MODE_CLASS ((MODE)) != MODE_INT				\&& GET_MODE_UNIT_SIZE ((MODE))> 4				\&& (REGNO)< 8&& (REGNO) + GET_MODE_SIZE ((MODE)) / 4> 8	\&& (REGNO) % (GET_MODE_UNIT_SIZE ((MODE)) / 4) != 0))		\  || ((REGNO)< 24							\      ? TARGET_68881&& (GET_MODE_CLASS (MODE) == MODE_FLOAT		\ 			|| GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT)	\      : ((REGNO)< 56 ? TARGET_FPA : 0)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

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
value|(! TARGET_68881					\    || ((GET_MODE_CLASS (MODE1) == MODE_FLOAT		\ 	|| GET_MODE_CLASS (MODE1) == MODE_COMPLEX_FLOAT)	\        == (GET_MODE_CLASS (MODE2) == MODE_FLOAT		\ 	   || GET_MODE_CLASS (MODE2) == MODE_COMPLEX_FLOAT)))
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
value|14
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|8
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
comment|/* The 68000 has three kinds of registers, so eight classes would be    a complete set.  One of them is not needed.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|DATA_REGS
block|,
name|ADDR_REGS
block|,
name|FP_REGS
block|,
name|GENERAL_REGS
block|,
name|DATA_OR_FP_REGS
block|,
name|ADDR_OR_FP_REGS
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
value|{ "NO_REGS", "DATA_REGS",              \    "ADDR_REGS", "FP_REGS",              \    "GENERAL_REGS", "DATA_OR_FP_REGS",   \    "ADDR_OR_FP_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{					\  0x00000000,
comment|/* NO_REGS */
value|\  0x000000ff,
comment|/* DATA_REGS */
value|\  0x0000ff00,
comment|/* ADDR_REGS */
value|\  0x00ff0000,
comment|/* FP_REGS */
value|\  0x0000ffff,
comment|/* GENERAL_REGS */
value|\  0x00ff00ff,
comment|/* DATA_OR_FP_REGS */
value|\  0x00ffff00,
comment|/* ADDR_OR_FP_REGS */
value|\  0x00ffffff,
comment|/* ALL_REGS */
value|\ }
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
value|(((REGNO)>>3)+1)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

begin_comment
comment|/*  * Notes on final choices:  *  *   1) Didn't feel any need to union-ize LOW_FPA_REGS with anything  * else.  *   2) Removed all unions that involve address registers with  * floating point registers (left in unions of address and data with  * floating point).  *   3) Defined GENERAL_REGS as ADDR_OR_DATA_REGS.  *   4) Defined ALL_REGS as FPA_OR_FP_OR_GENERAL_REGS.  *   4) Left in everything else.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|LO_FPA_REGS
block|,
name|FPA_REGS
block|,
name|FP_REGS
block|,
name|FP_OR_FPA_REGS
block|,
name|DATA_REGS
block|,
name|DATA_OR_FPA_REGS
block|,
name|DATA_OR_FP_REGS
block|,
name|DATA_OR_FP_OR_FPA_REGS
block|,
name|ADDR_REGS
block|,
name|GENERAL_REGS
block|,
name|GENERAL_OR_FPA_REGS
block|,
name|GENERAL_OR_FP_REGS
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
value|{ "NO_REGS", "LO_FPA_REGS", "FPA_REGS", "FP_REGS",  \    "FP_OR_FPA_REGS", "DATA_REGS", "DATA_OR_FPA_REGS", "DATA_OR_FP_REGS",  \    "DATA_OR_FP_OR_FPA_REGS", "ADDR_REGS", "GENERAL_REGS",  \    "GENERAL_OR_FPA_REGS", "GENERAL_OR_FP_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{							\  {0, 0},
comment|/* NO_REGS */
value|\  {0xff000000, 0x000000ff},
comment|/* LO_FPA_REGS */
value|\  {0xff000000, 0x00ffffff},
comment|/* FPA_REGS */
value|\  {0x00ff0000, 0x00000000},
comment|/* FP_REGS */
value|\  {0xffff0000, 0x00ffffff},
comment|/* FP_OR_FPA_REGS */
value|\  {0x000000ff, 0x00000000},
comment|/* DATA_REGS */
value|\  {0xff0000ff, 0x00ffffff},
comment|/* DATA_OR_FPA_REGS */
value|\  {0x00ff00ff, 0x00000000},
comment|/* DATA_OR_FP_REGS */
value|\  {0xffff00ff, 0x00ffffff},
comment|/* DATA_OR_FP_OR_FPA_REGS */
value|\  {0x0000ff00, 0x00000000},
comment|/* ADDR_REGS */
value|\  {0x0000ffff, 0x00000000},
comment|/* GENERAL_REGS */
value|\  {0xff00ffff, 0x00ffffff},
comment|/* GENERAL_OR_FPA_REGS */
value|\  {0x00ffffff, 0x00000000},
comment|/* GENERAL_OR_FP_REGS */
value|\  {0xffffffff, 0x00ffffff},
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUPPORT_SUN_FPA */
end_comment

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
comment|/* Get reg_class from a letter such as appears in the machine description.    We do a trick here to modify the effective constraints on the    machine description; we zorch the constraint letters that aren't    appropriate for a specific target.  This allows us to guarantee    that a specific kind of register will not be used for a given target    without fiddling with the register classes above. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|((C) == 'a' ? ADDR_REGS :			\    ((C) == 'd' ? DATA_REGS :			\     ((C) == 'f' ? (TARGET_68881 ? FP_REGS :	\ 		   NO_REGS) :			\      NO_REGS)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|((C) == 'a' ? ADDR_REGS :			\    ((C) == 'd' ? DATA_REGS :			\     ((C) == 'f' ? (TARGET_68881 ? FP_REGS :	\ 		   NO_REGS) :			\      ((C) == 'x' ? (TARGET_FPA ? FPA_REGS :	\ 		    NO_REGS) :			\       ((C) == 'y' ? (TARGET_FPA ? LO_FPA_REGS :	\ 		     NO_REGS) :			\        NO_REGS)))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

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

begin_comment
comment|/*  * A small bit of explanation:  * "G" defines all of the floating constants that are *NOT* 68881  * constants.  this is so 68881 constants get reloaded and the  * fpmovecr is used.  "H" defines *only* the class of constants that  * the fpa can use, because these can be gotten at in any fpa  * instruction and there is no need to force reloads.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

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
value|((C) == 'G' ? ! (TARGET_68881&& standard_68881_constant_p (VALUE)) : 0 )
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
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
value|((C) == 'G' ? ! (TARGET_68881&& standard_68881_constant_p (VALUE)) : \    (C) == 'H' ? (TARGET_FPA&& standard_sun_fpa_constant_p (VALUE)) : 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.    On the 68000 series, use a data reg if possible when the    value is a constant in the range where moveq could be used    and we ensure that QImodes are reloaded into data regs.    Also, if a floating constant needs reloading, put it in memory    if possible.  */
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
value|((GET_CODE (X) == CONST_INT			\&& (unsigned) (INTVAL (X) + 0x80)< 0x100	\&& (CLASS) != ADDR_REGS)			\    ? DATA_REGS					\    : (GET_MODE (X) == QImode&& (CLASS) != ADDR_REGS) \    ? DATA_REGS					\    : (GET_CODE (X) == CONST_DOUBLE		\&& GET_MODE_CLASS (GET_MODE (X)) == MODE_FLOAT) \    ? NO_REGS					\    : (CLASS))
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On the 68000, this is the size of MODE in words,    except in the FP regs, where a single reg is always enough.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

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
value|(((CLASS1) == FP_REGS&& (CLASS2) != FP_REGS)	        \     || ((CLASS2) == FP_REGS&& (CLASS1) != FP_REGS)	\     ? 4 : 2)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
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
value|((CLASS) == FP_REGS || (CLASS) == FPA_REGS || (CLASS) == LO_FPA_REGS ? 1 \   : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Moves between fp regs and other regs are two insns.  */
end_comment

begin_comment
comment|/* Likewise for high fpa regs and other regs.  */
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
value|((((CLASS1) == FP_REGS&& (CLASS2) != FP_REGS)	\     || ((CLASS2) == FP_REGS&& (CLASS1) != FP_REGS)	\     || ((CLASS1) == FPA_REGS&& (CLASS2) != FPA_REGS)	\     || ((CLASS2) == FPA_REGS&& (CLASS1) != FPA_REGS))	\    ? 4 : 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* define SUPPORT_SUN_FPA */
end_comment

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
comment|/* Nonzero if we need to generate stack-probe insns.    On most systems they are not needed.    When they are needed, define this as the stack offset to probe at.  */
end_comment

begin_define
define|#
directive|define
name|NEED_PROBE
value|0
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
value|8
end_define

begin_comment
comment|/* Value is the number of byte of arguments automatically    popped when returning from a subroutine call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.     On the 68000, the RTS insn cannot pop anything.    On the 68010, the RTD insn may be used to pop them if the number      of args is fixed, but if the number is variable then the caller      must pop them all.  RTD can't be used for library calls now      because the library is compiled with the Unix compiler.    Use of RTD is a selectable option, since it is incompatible with    standard Unix calling sequences.  If the option is not selected,    the caller must always pop the args.  */
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
comment|/* On the 68000 the return value is in D0 regardless.  */
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
value|gen_rtx (REG, TYPE_MODE (VALTYPE), 0)
end_define

begin_comment
comment|/* Define how to find the value returned by a library function    assuming the value has mode MODE.  */
end_comment

begin_comment
comment|/* On the 68000 the return value is in D0 regardless.  */
end_comment

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
value|gen_rtx (REG, MODE, 0)
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the 68000, d0 is the only register thus used.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 0)
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
comment|/* 1 if N is a possible register number for function argument passing.    On the 68000, no registers are used in this way.  */
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
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the m68k, this is a single integer, which is a number of bytes    of arguments scanned so far.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.     On the m68k, the offset starts at 0.  */
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
comment|/* On the 68000 all args are pushed, except if -mregparm is specified    then the first two words of arguments are passed in d0, d1.    *NOTE* -mregparm does not work.    It exists only to test register calling conventions.  */
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
comment|/* Generate the assembly code for function entry. */
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
value|output_function_prologue(FILE, SIZE)
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
value|asm_fprintf (FILE, "\tlea %LLP%d,%Ra0\n\tjsr mcount\n", (LABELNO))
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
value|asm_fprintf (FILE, "\ttstl %LLPBX0\n\tbne %LLPI%d\n\tpea %LLPBX0\n\tjsr %U__bb_init_func\n\taddql %I4,%Rsp\n%LLPI%d:\n",  \ 	   LABELNO, LABELNO);
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
value|asm_fprintf (FILE, "\taddql %I1,%LLPBX2+%d\n", 4 * BLOCKNO)
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
comment|/* Generate the assembly code for function exit. */
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
value|output_function_epilogue (FILE, SIZE)
end_define

begin_comment
comment|/* This is a hook for other tm files to change.  */
end_comment

begin_comment
comment|/* #define FUNCTION_EXTRA_EPILOGUE(FILE, SIZE) */
end_comment

begin_comment
comment|/* Determine if the epilogue should be output as RTL.    You should override this if you define FUNCTION_EXTRA_EPILOGUE.  */
end_comment

begin_define
define|#
directive|define
name|USE_RETURN_INSN
value|use_return_insn ()
end_define

begin_comment
comment|/* Store in the variable DEPTH the initial difference between the    frame pointer reg contents and the stack pointer reg contents,    as of the start of the function body.  This depends on the layout    of the fixed parts of the stack frame and on how registers are saved.     On the 68k, if we have a frame, we must add one word to its length    to allow for the place that a6 is stored when we do have a frame pointer.    Otherwise, we would need to compute the offset from the frame pointer    of a local variable as a function of frame_pointer_needed, which    is hard.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_FRAME_POINTER_OFFSET
parameter_list|(
name|DEPTH
parameter_list|)
define|\
value|{ int regno;							\   int offset = -4;						\   for (regno = 16; regno< FIRST_PSEUDO_REGISTER; regno++)	\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       offset += 12;						\   for (regno = 0; regno< 16; regno++)				\     if (regs_ever_live[regno]&& ! call_used_regs[regno])	\       offset += 4;						\   (DEPTH) = (offset + ((get_frame_size () + 3)& -4)		\ 	     + (get_frame_size () == 0 ? 0 : 4));		\ }
end_define

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.  */
end_comment

begin_comment
comment|/* On the 68k, the trampoline looks like this:      mov  @#.,a0      jsr  @#___trampoline      jsr  @#___trampoline      .long STATIC      .long FUNCTION The reason for having three jsr insns is so that an entire line of the instruction cache is filled in a predictable way that will always be the same.  We always use the assembler label ___trampoline regardless of whether the system adds underscores.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{									\   ASM_OUTPUT_SHORT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x207c));	\   ASM_OUTPUT_SHORT (FILE, const0_rtx);					\   ASM_OUTPUT_SHORT (FILE, const0_rtx);					\   ASM_OUTPUT_SHORT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x4eb9));	\   ASM_OUTPUT_INT (FILE, gen_rtx (SYMBOL_REF, SImode, "*___trampoline"));\   ASM_OUTPUT_SHORT (FILE, gen_rtx (CONST_INT, VOIDmode, 0x4eb9));	\   ASM_OUTPUT_INT (FILE, gen_rtx (SYMBOL_REF, SImode, "*___trampoline"));\   ASM_OUTPUT_SHORT (FILE, const0_rtx);					\   ASM_OUTPUT_SHORT (FILE, const0_rtx);					\   ASM_OUTPUT_SHORT (FILE, const0_rtx);					\   ASM_OUTPUT_SHORT (FILE, const0_rtx);					\ }
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|26
end_define

begin_comment
comment|/* Alignment required for a trampoline.  16 is used to find the    beginning of a line in the instruction cache.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_ALIGN
value|16
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
value|{									\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 2)), TRAMP); \   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 18)), CXT); \   emit_move_insn (gen_rtx (MEM, SImode, plus_constant (TRAMP, 22)), FNADDR); \ }
end_define

begin_comment
comment|/* This is the library routine that is used    to transfer control from the trampoline    to the actual nested function.  */
end_comment

begin_comment
comment|/* A colon is used with no explicit operands    to cause the template string to be scanned for %-constructs.  */
end_comment

begin_comment
comment|/* The function name __transfer_from_trampoline is not actually used.    The function definition just permits use of "asm with operands"    (though the operand list is empty).  */
end_comment

begin_define
define|#
directive|define
name|TRANSFER_FROM_TRAMPOLINE
define|\
value|void								\ __transfer_from_trampoline ()					\ {								\   register char *a0 asm ("%a0");				\   asm (GLOBAL_ASM_OP " ___trampoline");				\   asm ("___trampoline:");					\   asm volatile ("move%.l %0,%@" : : "m" (a0[22]));		\   asm volatile ("move%.l %1,%0" : "=a" (a0) : "m" (a0[18]));	\   asm ("rts":);							\ }
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

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_SUN_FPA
end_ifdef

begin_define
define|#
directive|define
name|REGNO_OK_FOR_FPA_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO)>= 24&& (REGNO)< 56) || (reg_renumber[REGNO]>= 24&& reg_renumber[REGNO]< 56))
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|SUPPORT_SUN_FPA
end_ifdef

begin_comment
comment|/* 1 if X is a register in the Sun FPA.  */
end_comment

begin_define
define|#
directive|define
name|FPA_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& REGNO_OK_FOR_FPA_P (REGNO (X)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Answer must be no if we don't have an FPA.  */
end_comment

begin_define
define|#
directive|define
name|FPA_REG_P
parameter_list|(
name|X
parameter_list|)
value|0
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
comment|/* Nonzero if the constant value X is a legitimate general operand    when generating PIC code.  It is given that flag_pic is on and     that X satisfies CONSTANT_P or is a CONST_DOUBLE.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_PIC_OPERAND_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(! symbolic_operand (X, VOIDmode))
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
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     When generating PIC, an address involving a SYMBOL_REF is legitimate    if and only if it is the sum of pic_offset_table_rtx and the SYMBOL_REF.    We use LEGITIMATE_PIC_OPERAND_P to throw out the illegitimate addresses,    and we explicitly check for the sum of pic_offset_table_rtx and a SYMBOL_REF.     Likewise for a LABEL_REF when generating PIC.     The other macros defined here are used only in GO_IF_LEGITIMATE_ADDRESS.  */
end_comment

begin_define
define|#
directive|define
name|INDIRECTABLE_1_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((CONSTANT_ADDRESS_P (X)&& (!flag_pic || LEGITIMATE_PIC_OPERAND_P (X))) \    || (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))			\    || ((GET_CODE (X) == PRE_DEC || GET_CODE (X) == POST_INC)		\&& REG_P (XEXP (X, 0))						\&& REG_OK_FOR_BASE_P (XEXP (X, 0)))				\    || (GET_CODE (X) == PLUS						\&& REG_P (XEXP (X, 0))&& REG_OK_FOR_BASE_P (XEXP (X, 0))	\&& GET_CODE (XEXP (X, 1)) == CONST_INT				\&& ((unsigned) INTVAL (XEXP (X, 1)) + 0x8000)< 0x10000)		\    || (GET_CODE (X) == PLUS&& XEXP (X, 0) == pic_offset_table_rtx 	\&& flag_pic&& GET_CODE (XEXP (X, 1)) == SYMBOL_REF)		\    || (GET_CODE (X) == PLUS&& XEXP (X, 0) == pic_offset_table_rtx 	\&& flag_pic&& GET_CODE (XEXP (X, 1)) == LABEL_REF))		\  #if 0
end_define

begin_comment
comment|/* This should replace the last two (non-pic) lines    except that Sun's assembler does not seem to handle such operands.  */
end_comment

begin_expr_stmt
operator|&&
operator|(
name|TARGET_68020
condition|?
name|CONSTANT_ADDRESS_P
argument_list|(
name|XEXP
argument_list|(
name|X
argument_list|,
literal|1
argument_list|)
argument_list|)
then|\
else|:
operator|(
name|GET_CODE
argument_list|(
name|XEXP
argument_list|(
name|X
argument_list|,
literal|1
argument_list|)
argument_list|)
operator|==
name|CONST_INT
expr|\
operator|&&
operator|(
operator|(
name|unsigned
operator|)
name|INTVAL
argument_list|(
name|XEXP
argument_list|(
name|X
argument_list|,
literal|1
argument_list|)
argument_list|)
operator|+
literal|0x8000
operator|)
operator|<
literal|0x10000
operator|)
operator|)
end_expr_stmt

begin_endif
unit|))
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Only labels on dispatch tables are valid for indexing from.  */
end_comment

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
value|{ rtx temp;							\   if (GET_CODE (X) == LABEL_REF					\&& (temp = next_nonnote_insn (XEXP (X, 0))) != 0		\&& GET_CODE (temp) == JUMP_INSN				\&& (GET_CODE (PATTERN (temp)) == ADDR_VEC			\ 	  || GET_CODE (PATTERN (temp)) == ADDR_DIFF_VEC))	\     goto ADDR;							\   if (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X)) goto ADDR; }
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
name|COPY_ONCE
parameter_list|(
name|Y
parameter_list|)
value|if (!copied) { Y = copy_rtx (Y); copied = ch = 1; }
end_define

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
value|{ register int ch = (X) != (OLDX);					\   if (GET_CODE (X) == PLUS)						\     { int copied = 0;							\       if (GET_CODE (XEXP (X, 0)) == MULT)				\ 	{ COPY_ONCE (X); XEXP (X, 0) = force_operand (XEXP (X, 0), 0);}	\       if (GET_CODE (XEXP (X, 1)) == MULT)				\ 	{ COPY_ONCE (X); XEXP (X, 1) = force_operand (XEXP (X, 1), 0);}	\       if (ch&& GET_CODE (XEXP (X, 1)) == REG				\&& GET_CODE (XEXP (X, 0)) == REG)				\ 	goto WIN;							\       if (ch) { GO_IF_LEGITIMATE_ADDRESS (MODE, X, WIN); }		\       if (GET_CODE (XEXP (X, 0)) == REG					\ 	       || (GET_CODE (XEXP (X, 0)) == SIGN_EXTEND		\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == REG		\&& GET_MODE (XEXP (XEXP (X, 0), 0)) == HImode))	\ 	{ register rtx temp = gen_reg_rtx (Pmode);			\ 	  register rtx val = force_operand (XEXP (X, 1), 0);		\ 	  emit_move_insn (temp, val);					\ 	  COPY_ONCE (X);						\ 	  XEXP (X, 1) = temp;						\ 	  goto WIN; }							\       else if (GET_CODE (XEXP (X, 1)) == REG				\ 	       || (GET_CODE (XEXP (X, 1)) == SIGN_EXTEND		\&& GET_CODE (XEXP (XEXP (X, 1), 0)) == REG		\&& GET_MODE (XEXP (XEXP (X, 1), 0)) == HImode))	\ 	{ register rtx temp = gen_reg_rtx (Pmode);			\ 	  register rtx val = force_operand (XEXP (X, 0), 0);		\ 	  emit_move_insn (temp, val);					\ 	  COPY_ONCE (X);						\ 	  XEXP (X, 0) = temp;						\ 	  goto WIN; }}}
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
comment|/* Don't cse the address of the function being compiled.  */
end_comment

begin_define
define|#
directive|define
name|NO_RECURSIVE_FUNCTION_CSE
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
value|\     if (RTX == const0_rtx) return 0;				\
comment|/* Constants between -128 and 127 are cheap due to moveq */
value|\     if (INTVAL (RTX)>= -128&& INTVAL (RTX)<= 127) return 1;	\
comment|/* Constants between -136 and 254 are easily generated */
value|\
comment|/* by intelligent uses of moveq, add[q], and subq 	   */
value|\     if ((OUTER_CODE) == SET&& INTVAL (RTX)>= -136		\&& INTVAL (RTX)<= 254) return 2;			\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 3;							\   case CONST_DOUBLE:						\     return 5;
end_define

begin_comment
comment|/* Compute the cost of various arithmetic operations.    These are vaguely right for a 68020.  */
end_comment

begin_comment
comment|/* The costs for long multiply have been adjusted to    work properly in synth_mult on the 68020,    relative to an average of the time for add and the time for shift,    taking away a little more because sometimes move insns are needed.  */
end_comment

begin_define
define|#
directive|define
name|MULL_COST
value|(TARGET_68040 ? 5 : 13)
end_define

begin_define
define|#
directive|define
name|MULW_COST
value|(TARGET_68040 ? 3 : 8)
end_define

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
value|case PLUS:							\
comment|/* An lea costs about three times as much as a simple add.  */
value|\     if (GET_MODE (X) == SImode					\&& GET_CODE (XEXP (X, 0)) == REG			\&& GET_CODE (XEXP (X, 1)) == MULT			\&& GET_CODE (XEXP (XEXP (X, 1), 0)) == REG		\&& GET_CODE (XEXP (XEXP (X, 1), 1)) == CONST_INT	\&& (INTVAL (XEXP (XEXP (X, 1), 1)) == 2			\ 	    || INTVAL (XEXP (XEXP (X, 1), 1)) == 4		\ 	    || INTVAL (XEXP (XEXP (X, 1), 1)) == 8))		\       return COSTS_N_INSNS (3);
comment|/* lea an@(dx:l:i),am */
value|\     break;							\   case ASHIFT:							\   case ASHIFTRT:						\   case LSHIFT:							\   case LSHIFTRT:						\
comment|/* A shift by a big integer takes an extra instruction.  */
value|\     if (GET_CODE (XEXP (X, 1)) == CONST_INT			\&& (INTVAL (XEXP (X, 1)) == 16))			\       return COSTS_N_INSNS (2);
comment|/* clrw;swap */
value|\     if (GET_CODE (XEXP (X, 1)) == CONST_INT			\&& !(INTVAL (XEXP (X, 1))> 0				\&& INTVAL (XEXP (X, 1))<= 8))			\       return COSTS_N_INSNS (3);
comment|/* lsr #i,dn */
value|\     break;							\   case MULT:							\     if (GET_CODE (XEXP (x, 1)) == CONST_INT			\&& exact_log2 (INTVAL (XEXP (x, 1)))>= 0)		\       {								\
comment|/* A shift by a big integer takes an extra instruction.  */
value|\ 	if (GET_CODE (XEXP (X, 1)) == CONST_INT			\&& (INTVAL (XEXP (X, 1)) == (1<< 16)))		\ 	  return COSTS_N_INSNS (2);
comment|/* clrw;swap */
value|\ 	if (GET_CODE (XEXP (X, 1)) == CONST_INT			\&& !(INTVAL (XEXP (X, 1))> 1			\&& INTVAL (XEXP (X, 1))<= 256))		\ 	  return COSTS_N_INSNS (3);
comment|/* lsr #i,dn */
value|\ 	break;							\       }								\     else if (GET_MODE (X) == QImode || GET_MODE (X) == HImode)	\       return COSTS_N_INSNS (MULW_COST);				\     else							\       return COSTS_N_INSNS (MULL_COST);				\     break;							\   case DIV:							\   case UDIV:							\   case MOD:							\   case UMOD:							\     if (GET_MODE (X) == QImode || GET_MODE (X) == HImode)	\       return COSTS_N_INSNS (27);
comment|/* div.w */
value|\     return COSTS_N_INSNS (43);
end_define

begin_comment
comment|/* div.l */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.  */
end_comment

begin_comment
comment|/* Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').  */
end_comment

begin_comment
comment|/* Set if the cc value is actually in the 68881, so a floating point    conditional branch must be output.  */
end_comment

begin_define
define|#
directive|define
name|CC_IN_68881
value|04000
end_define

begin_comment
comment|/* Store in cc_status the expressions that the condition codes will    describe after execution of an instruction whose pattern is EXP.    Do not alter them if the instruction would not alter the cc's.  */
end_comment

begin_comment
comment|/* On the 68000, all the insns to store in an address register fail to    set the cc's.  However, in some cases these instructions can make it    possibly invalid to use the saved cc's.  In those cases we clear out    some or all of the saved cc's so they won't be used.  */
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
value|notice_update_cc (EXP, INSN)
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
value|{ if (cc_prev_status.flags& CC_IN_68881)			\     return FLOAT;						\   if (cc_prev_status.flags& CC_NO_OVERFLOW)			\     return NO_OV;						\   return NORMAL; }
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
comment|/* Here are four prefixes that are used by asm_fprintf to    facilitate customization for alternate assembler syntaxes.    Machines with no likelihood of an alternate syntax need not    define these and need not use asm_fprintf.  */
end_comment

begin_comment
comment|/* The prefix for register names.  Note that REGISTER_NAMES    is supposed to include this prefix.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|""
end_define

begin_comment
comment|/* The prefix for local labels.  You should be able to define this as    an empty string, or any arbitrary string (such as ".", ".L%", etc)    without having to make any other changes to account for the specific    definition.  Note it is a string literal, not interpreted by printf    and friends. */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* The prefix to add to user-visible assembler symbols.  */
end_comment

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|"_"
end_define

begin_comment
comment|/* The prefix for immediate operands.  */
end_comment

begin_define
define|#
directive|define
name|IMMEDIATE_PREFIX
value|"#"
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORT_SUN_FPA
end_ifndef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7",	\  "a0", "a1", "a2", "a3", "a4", "a5", "a6", "sp",	\  "fp0", "fp1", "fp2", "fp3", "fp4", "fp5", "fp6", "fp7" }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* SUPPORTED_SUN_FPA */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7",	\  "a0", "a1", "a2", "a3", "a4", "a5", "a6", "sp",	\  "fp0", "fp1", "fp2", "fp3", "fp4", "fp5", "fp6", "fp7", \  "fpa0", "fpa1", "fpa2", "fpa3", "fpa4", "fpa5", "fpa6", "fpa7", \  "fpa8", "fpa9", "fpa10", "fpa11", "fpa12", "fpa13", "fpa14", "fpa15", \  "fpa16", "fpa17", "fpa18", "fpa19", "fpa20", "fpa21", "fpa22", "fpa23", \  "fpa24", "fpa25", "fpa26", "fpa27", "fpa28", "fpa29", "fpa30", "fpa31" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* defined SUPPORT_SUN_FPA */
end_comment

begin_comment
comment|/* How to renumber registers for dbx and gdb.    On the Sun-3, the floating point registers have numbers    18 to 25, not 16 to 23 as they do in the compiler.  */
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
name|GLOBAL_ASM_OP
value|".globl"
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
value|do { fprintf (FILE, "%s ", GLOBAL_ASM_OP);		\        assemble_name (FILE, NAME);			\        fputs ("\n", FILE);} while (0)
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
value|asm_fprintf (FILE, "%0U%s", NAME)
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
value|asm_fprintf (FILE, "%0L%s%d:\n", PREFIX, NUM)
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
value|sprintf (LABEL, "*%s%s%d", LOCAL_LABEL_PREFIX, PREFIX, NUM)
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
value|fprintf (FILE, "\t.double 0r%.20g\n", (VALUE))
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_comment
comment|/* Sun's assembler can't handle floating constants written as floating.    However, when cross-compiling, always use that in case format differs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

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
value|fprintf (FILE, "\t.float 0r%.10g\n", (VALUE))
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not CROSS_COMPILE */
end_comment

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
value|asm_fprintf (FILE, "\tmovel %s,%Rsp@-\n", reg_names[REGNO])
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
value|asm_fprintf (FILE, "\tmovel %Rsp@+,%s\n", reg_names[REGNO])
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
value|asm_fprintf (FILE, "\t.long %LL%d\n", VALUE)
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
value|asm_fprintf (FILE, "\t.word %LL%d-%LL%d\n", VALUE, REL)
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
end_comment

begin_comment
comment|/* We don't have a way to align to more than a two-byte boundary, so do the    best we can and don't complain.  */
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
value|if ((LOG)>= 1)			\     fprintf (FILE, "\t.even\n");
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
comment|/* Output a float value (represented as a C double) as an immediate operand.    This macro is a 68k-specific macro.  */
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
value|asm_fprintf (FILE, "%I0r%.9g", (VALUE))
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
value|asm_fprintf (FILE, "%I0r%.20g", (VALUE))
end_define

begin_comment
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    For `%' followed by punctuation, CODE is the punctuation and X is null.     On the 68000, we use several CODE characters:    '.' for dot needed in Motorola-style opcode names.    '-' for an operand pushing on the stack:        sp@-, -(sp) or -(%sp) depending on the style of syntax.    '+' for an operand pushing on the stack:        sp@+, (sp)+ or (%sp)+ depending on the style of syntax.    '@' for a reference to the top word on the stack:        sp@, (sp) or (%sp) depending on the style of syntax.    '#' for an immediate operand prefix (# in MIT and Motorola syntax        but& in SGS syntax).    '!' for the fpcr register (used in some float-to-fixed conversions).    '$' for the letter `s' in an op code, but only on the 68040.    '&' for the letter `d' in an op code, but only on the 68040.    '/' for register prefix needed by longlong.h.     'b' for byte insn (no effect, on the Sun; this is for the ISI).    'd' to force memory addressing to be absolute, not relative.    'f' for float insn (print a CONST_DOUBLE as a float rather than in hex)    'w' for FPA insn (print a CONST_DOUBLE as a SunFPA constant rather        than directly).  Second part of 'y' below.    'x' for float insn (print a CONST_DOUBLE as a float rather than in hex),        or print pair of registers as rx:ry.    'y' for a FPA insn (print pair of registers as rx:ry).  This also outputs        CONST_DOUBLE's as SunFPA constant RAM registers if        possible, so it should not be used except for the SunFPA. */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '.' || (CODE) == '#' || (CODE) == '-'			\    || (CODE) == '+' || (CODE) == '@' || (CODE) == '!'			\    || (CODE) == '$' || (CODE) == '&' || (CODE) == '/')
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HOST_WORDS_BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|PRINT_OPERAND_EXTRACT_FLOAT
parameter_list|(
name|X
parameter_list|)
define|\
value|u.i[0] = CONST_DOUBLE_LOW (X); u.i[1] = CONST_DOUBLE_HIGH (X);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PRINT_OPERAND_EXTRACT_FLOAT
parameter_list|(
name|X
parameter_list|)
define|\
value|u.i[0] = CONST_DOUBLE_HIGH (X); u.i[1] = CONST_DOUBLE_LOW (X);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_define
define|#
directive|define
name|PRINT_OPERAND_PRINT_FLOAT
parameter_list|(
name|CODE
parameter_list|,
name|FILE
parameter_list|)
define|\
value|ASM_OUTPUT_FLOAT_OPERAND (FILE, u1.f);
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PRINT_OPERAND_PRINT_FLOAT
parameter_list|(
name|CODE
parameter_list|,
name|FILE
parameter_list|)
define|\
value|{ if (CODE == 'f')							\     ASM_OUTPUT_FLOAT_OPERAND (FILE, u1.f);				\   else									\     asm_fprintf (FILE, "%I0x%x", u1.i); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A C compound statement to output to stdio stream STREAM the    assembler syntax for an instruction operand X.  X is an RTL    expression.     CODE is a value that can be used to specify one of several ways    of printing the operand.  It is used when identical operands    must be printed differently depending on the context.  CODE    comes from the `%' specification that was used to request    printing of the operand.  If the specification was just `%DIGIT'    then CODE is 0; if the specification was `%LTR DIGIT' then CODE    is the ASCII code for LTR.     If X is a register, this macro should print the register's name.    The names can be found in an array `reg_names' whose type is    `char *[]'.  `reg_names' is initialized from `REGISTER_NAMES'.     When the machine description has a specification `%PUNCT' (a `%'    followed by a punctuation character), this macro is called with    a null pointer for X and the punctuation character for CODE.     See m68k.c for the m68k specific codes.  */
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
comment|/* A C compound statement to output to stdio stream STREAM the    assembler syntax for an instruction operand that is a memory    reference whose address is ADDR.  ADDR is an RTL expression.     On some machines, the syntax for a symbolic address depends on    the section that the address refers to.  On these machines,    define the macro `ENCODE_SECTION_INFO' to store the information    into the `symbol_ref', and then check for it here.  */
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
comment|/* Define functions defined in aux-output.c and used in templates.  */
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
name|output_move_const_single
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_move_const_double
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_btst
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Local variables: version-control: t End: */
end_comment

end_unit

