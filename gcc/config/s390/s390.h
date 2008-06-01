begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for IBM S/390    Copyright (C) 1999, 2000, 2001, 2002, 2003, 2004, 2005, 2006    Free Software Foundation, Inc.    Contributed by Hartmut Penner (hpenner@de.ibm.com) and                   Ulrich Weigand (uweigand@de.ibm.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_S390_H
end_ifndef

begin_define
define|#
directive|define
name|_S390_H
end_define

begin_comment
comment|/* Override the __fixdfdi etc. routines when building libgcc2.    ??? This should be done in a cleaner way ...  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IN_LIBGCC2
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__s390x__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<config/s390/fixdfdi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Which processor to generate code or schedule for. The cpu attribute    defines a list that mirrors this list, so changes to s390.md must be    made at the same time.  */
end_comment

begin_enum
enum|enum
name|processor_type
block|{
name|PROCESSOR_9672_G5
block|,
name|PROCESSOR_9672_G6
block|,
name|PROCESSOR_2064_Z900
block|,
name|PROCESSOR_2084_Z990
block|,
name|PROCESSOR_2094_Z9_109
block|,
name|PROCESSOR_max
block|}
enum|;
end_enum

begin_comment
comment|/* Optional architectural facilities supported by the processor.  */
end_comment

begin_enum
enum|enum
name|processor_flags
block|{
name|PF_IEEE_FLOAT
init|=
literal|1
block|,
name|PF_ZARCH
init|=
literal|2
block|,
name|PF_LONG_DISPLACEMENT
init|=
literal|4
block|,
name|PF_EXTIMM
init|=
literal|8
block|}
enum|;
end_enum

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|s390_tune
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|processor_flags
name|s390_tune_flags
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|processor_type
name|s390_arch
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|processor_flags
name|s390_arch_flags
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_CPU_IEEE_FLOAT
define|\
value|(s390_arch_flags& PF_IEEE_FLOAT)
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_ZARCH
define|\
value|(s390_arch_flags& PF_ZARCH)
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_LONG_DISPLACEMENT
define|\
value|(s390_arch_flags& PF_LONG_DISPLACEMENT)
end_define

begin_define
define|#
directive|define
name|TARGET_CPU_EXTIMM
define|\
value|(s390_arch_flags& PF_EXTIMM)
end_define

begin_define
define|#
directive|define
name|TARGET_LONG_DISPLACEMENT
define|\
value|(TARGET_ZARCH&& TARGET_CPU_LONG_DISPLACEMENT)
end_define

begin_define
define|#
directive|define
name|TARGET_EXTIMM
define|\
value|(TARGET_ZARCH&& TARGET_CPU_EXTIMM)
end_define

begin_comment
comment|/* Run-time target specification.  */
end_comment

begin_comment
comment|/* Defaults for option flags defined only on some subtargets.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_TPF_PROFILING
end_ifndef

begin_define
define|#
directive|define
name|TARGET_TPF_PROFILING
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This will be overridden by OS headers.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_TPF
value|0
end_define

begin_comment
comment|/* Target CPU builtins.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do							\     {							\       builtin_assert ("cpu=s390");			\       builtin_assert ("machine=s390");			\       builtin_define ("__s390__");			\       if (TARGET_64BIT)					\         builtin_define ("__s390x__");			\       if (TARGET_LONG_DOUBLE_128)			\         builtin_define ("__LONG_DOUBLE_128__");		\     }							\   while (0)
end_define

begin_comment
comment|/* ??? Once this actually works, it could be made a runtime option.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_IBM_FLOAT
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_IEEE_FLOAT
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_64BIT | MASK_ZARCH | MASK_HARD_FLOAT)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|MASK_HARD_FLOAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Support for configure-time defaults.  */
end_comment

begin_define
define|#
directive|define
name|OPTION_DEFAULT_SPECS
define|\
value|{ "mode", "%{!mesa:%{!mzarch:-m%(VALUE)}}" },			\   { "arch", "%{!march=*:-march=%(VALUE)}" },			\   { "tune", "%{!mtune=*:-mtune=%(VALUE)}" }
end_define

begin_comment
comment|/* Defaulting rules.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_define
define|#
directive|define
name|DRIVER_SELF_SPECS
define|\
value|"%{!m31:%{!m64:-m64}}",					\   "%{!mesa:%{!mzarch:%{m31:-mesa}%{m64:-mzarch}}}",		\   "%{!march=*:%{mesa:-march=g5}%{mzarch:-march=z900}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DRIVER_SELF_SPECS
define|\
value|"%{!m31:%{!m64:-m31}}",					\   "%{!mesa:%{!mzarch:%{m31:-mesa}%{m64:-mzarch}}}",		\   "%{!march=*:%{mesa:-march=g5}%{mzarch:-march=z900}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target version string.  Overridden by the OS header.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (zSeries)");
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (S/390)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hooks to override options.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|,
name|SIZE
parameter_list|)
value|optimization_options(LEVEL, SIZE)
end_define

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
value|override_options ()
end_define

begin_comment
comment|/* Frame pointer is not used for debugging.  */
end_comment

begin_define
define|#
directive|define
name|CAN_DEBUG_WITHOUT_FP
end_define

begin_comment
comment|/* In libgcc2, determine target settings as compile-time constants.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_64BIT
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|__s390x__
end_ifdef

begin_define
define|#
directive|define
name|TARGET_64BIT
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_64BIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target machine storage layout.  */
end_comment

begin_comment
comment|/* Everything is big-endian.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|(TARGET_64BIT ? 8 : 4)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|IN_LIBGCC2
end_ifndef

begin_define
define|#
directive|define
name|MIN_UNITS_PER_WORD
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MAX_BITS_PER_WORD
value|64
end_define

begin_comment
comment|/* Function arguments and return values are promoted to word size.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_MODE
parameter_list|(
name|MODE
parameter_list|,
name|UNSIGNEDP
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|if (INTEGRAL_MODE_P (MODE)&&	        	    	\     GET_MODE_SIZE (MODE)< UNITS_PER_WORD) { 		\   (MODE) = Pmode;					\ 	  }
end_define

begin_comment
comment|/* Allocation boundary (in *bits*) for storing arguments in argument list.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|(TARGET_64BIT ? 64 : 32)
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
comment|/* There is no point aligning anything to a rounder boundary than this.  */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|64
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
comment|/* Alignment on even addresses for LARL instruction.  */
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
value|(ALIGN)< 16 ? 16 : (ALIGN)
end_define

begin_define
define|#
directive|define
name|DATA_ALIGNMENT
parameter_list|(
name|TYPE
parameter_list|,
name|ALIGN
parameter_list|)
value|(ALIGN)< 16 ? 16 : (ALIGN)
end_define

begin_comment
comment|/* Alignment is not required by the hardware.  */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|0
end_define

begin_comment
comment|/* Mode of stack savearea.    FUNCTION is VOIDmode because calling convention maintains SP.    BLOCK needs Pmode for SP.    NONLOCAL needs twice Pmode to maintain both backchain and SP.  */
end_comment

begin_define
define|#
directive|define
name|STACK_SAVEAREA_MODE
parameter_list|(
name|LEVEL
parameter_list|)
define|\
value|(LEVEL == SAVE_FUNCTION ? VOIDmode    \   : LEVEL == SAVE_NONLOCAL ? (TARGET_64BIT ? OImode : TImode) : Pmode)
end_define

begin_comment
comment|/* Define target floating point format.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FLOAT_FORMAT
define|\
value|(TARGET_IEEE_FLOAT? IEEE_FLOAT_FORMAT : IBM_FLOAT_FORMAT)
end_define

begin_comment
comment|/* Type layout.  */
end_comment

begin_comment
comment|/* Sizes in bits of the source language data types.  */
end_comment

begin_define
define|#
directive|define
name|SHORT_TYPE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|(TARGET_64BIT ? 64 : 32)
end_define

begin_define
define|#
directive|define
name|LONG_LONG_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|FLOAT_TYPE_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|DOUBLE_TYPE_SIZE
value|64
end_define

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|(TARGET_LONG_DOUBLE_128 ? 128 : 64)
end_define

begin_comment
comment|/* Define this to set long double type size to use in libgcc2.c, which can    not depend on target_flags.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LONG_DOUBLE_128__
end_ifdef

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|128
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIBGCC2_LONG_DOUBLE_TYPE_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Work around target_flags dependency in ada/targtyps.c.  */
end_comment

begin_define
define|#
directive|define
name|WIDEST_HARDWARE_FP_SIZE
value|64
end_define

begin_comment
comment|/* We use "unsigned char" as default.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|0
end_define

begin_comment
comment|/* Register usage.  */
end_comment

begin_comment
comment|/* We have 16 general purpose registers (registers 0-15),    and 16 floating point registers (registers 16-31).    (On non-IEEE machines, we have only 4 fp registers.)     Amongst the general purpose registers, some are used    for specific purposes:    GPR 11: Hard frame pointer (if needed)    GPR 12: Global offset table pointer (if needed)    GPR 13: Literal pool base register    GPR 14: Return address register    GPR 15: Stack pointer     Registers 32-35 are 'fake' hard registers that do not    correspond to actual hardware:    Reg 32: Argument pointer    Reg 33: Condition code    Reg 34: Frame pointer      Reg 35: Return address pointer     Registers 36 and 37 are mapped to access registers     0 and 1, used to implement thread-local storage.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|38
end_define

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_define
define|#
directive|define
name|GENERAL_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((int)(N)>= 0&& (N)< 16)
end_define

begin_define
define|#
directive|define
name|ADDR_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= 1&& (N)< 16)
end_define

begin_define
define|#
directive|define
name|FP_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N)>= 16&& (N)< (TARGET_IEEE_FLOAT? 32 : 20))
end_define

begin_define
define|#
directive|define
name|CC_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 33)
end_define

begin_define
define|#
directive|define
name|FRAME_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 32 || (N) == 34 || (N) == 35)
end_define

begin_define
define|#
directive|define
name|ACCESS_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 36 || (N) == 37)
end_define

begin_define
define|#
directive|define
name|GENERAL_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& GENERAL_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|ADDR_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& ADDR_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|FP_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& FP_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|CC_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& CC_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|FRAME_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& FRAME_REGNO_P (REGNO (X)))
end_define

begin_define
define|#
directive|define
name|ACCESS_REG_P
parameter_list|(
name|X
parameter_list|)
value|(REG_P (X)&& ACCESS_REGNO_P (REGNO (X)))
end_define

begin_comment
comment|/* Set up fixed registers and calling convention:     GPRs 0-5 are always call-clobbered,    GPRs 6-15 are always call-saved.    GPR 12 is fixed if used as GOT pointer.    GPR 13 is always fixed (as literal pool pointer).    GPR 14 is always fixed on S/390 machines (as return address).    GPR 15 is always fixed (as stack pointer).    The 'fake' hard registers are call-clobbered and fixed.    The access registers are call-saved and fixed.     On 31-bit, FPRs 18-19 are call-clobbered;    on 64-bit, FPRs 24-31 are call-clobbered.    The remaining FPRs are call-saved.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{ 0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   0, 1, 1, 1,					\   0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   1, 1, 1, 1,					\   1, 1 }
end_define

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{ 1, 1, 1, 1, 					\   1, 1, 0, 0, 					\   0, 0, 0, 0, 					\   0, 1, 1, 1,					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1,					\   1, 1 }
end_define

begin_define
define|#
directive|define
name|CALL_REALLY_USED_REGISTERS
define|\
value|{ 1, 1, 1, 1, 					\   1, 1, 0, 0, 					\   0, 0, 0, 0, 					\   0, 0, 0, 0,					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1,					\   0, 0 }
end_define

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
value|s390_conditional_register_usage ()
end_define

begin_comment
comment|/* Preferred register allocation order.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{  1, 2, 3, 4, 5, 0, 12, 11, 10, 9, 8, 7, 6, 14, 13,            \    16, 17, 18, 19, 20, 21, 22, 23,                              \    24, 25, 26, 27, 28, 29, 30, 31,                              \    15, 32, 33, 34, 35, 36, 37 }
end_define

begin_comment
comment|/* Fitting values into registers.  */
end_comment

begin_comment
comment|/* Integer modes<= word size fit into any GPR.    Integer modes> word size fit into successive GPRs, starting with    an even-numbered register.    SImode and DImode fit into FPRs as well.     Floating point modes<= word size fit into any FPR or GPR.    Floating point modes> word size (i.e. DFmode on 32-bit) fit    into any FPR, or an even-odd GPR pair.    TFmode fits only into an even-odd FPR pair.     Complex floating point modes fit either into two FPRs, or into    successive GPRs (again starting with an even number).    TCmode fits only into two successive even-odd FPR pairs.     Condition code modes fit only into the CC register.  */
end_comment

begin_comment
comment|/* Because all registers in a class have the same size HARD_REGNO_NREGS    is equivalent to CLASS_MAX_NREGS.  */
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
value|s390_class_max_nregs (REGNO_REG_CLASS (REGNO), (MODE))
end_define

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
value|s390_hard_regno_mode_ok ((REGNO), (MODE))
end_define

begin_define
define|#
directive|define
name|HARD_REGNO_RENAME_OK
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|s390_hard_regno_rename_ok (FROM, TO)
end_define

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
value|(((MODE1) == SFmode || (MODE1) == DFmode)	\    == ((MODE2) == SFmode || (MODE2) == DFmode))
end_define

begin_comment
comment|/* Maximum number of registers to represent a value of mode MODE    in a register of class CLASS.  */
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
value|s390_class_max_nregs ((CLASS), (MODE))
end_define

begin_comment
comment|/* If a 4-byte value is loaded into a FPR, it is placed into the    *upper* half of the register, not the lower.  Therefore, we    cannot use SUBREGs to switch between modes in FP registers.    Likewise for access registers, since they have only half the    word size on 64-bit.  */
end_comment

begin_define
define|#
directive|define
name|CANNOT_CHANGE_MODE_CLASS
parameter_list|(
name|FROM
parameter_list|,
name|TO
parameter_list|,
name|CLASS
parameter_list|)
define|\
value|(GET_MODE_SIZE (FROM) != GET_MODE_SIZE (TO)			        \    ? ((reg_classes_intersect_p (FP_REGS, CLASS)				\&& (GET_MODE_SIZE (FROM)< 8 || GET_MODE_SIZE (TO)< 8))		\       || reg_classes_intersect_p (ACCESS_REGS, CLASS)) : 0)
end_define

begin_comment
comment|/* Register classes.  */
end_comment

begin_comment
comment|/* We use the following register classes:    GENERAL_REGS     All general purpose registers    ADDR_REGS        All general purpose registers except %r0                     (These registers can be used in address generation)    FP_REGS          All floating point registers    CC_REGS          The condition code register    ACCESS_REGS      The access registers     GENERAL_FP_REGS  Union of GENERAL_REGS and FP_REGS    ADDR_FP_REGS     Union of ADDR_REGS and FP_REGS    GENERAL_CC_REGS  Union of GENERAL_REGS and CC_REGS    ADDR_CC_REGS     Union of ADDR_REGS and CC_REGS     NO_REGS          No registers    ALL_REGS         All registers     Note that the 'fake' frame pointer and argument pointer registers    are included amongst the address registers here.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|CC_REGS
block|,
name|ADDR_REGS
block|,
name|GENERAL_REGS
block|,
name|ACCESS_REGS
block|,
name|ADDR_CC_REGS
block|,
name|GENERAL_CC_REGS
block|,
name|FP_REGS
block|,
name|ADDR_FP_REGS
block|,
name|GENERAL_FP_REGS
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

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{ "NO_REGS", "CC_REGS", "ADDR_REGS", "GENERAL_REGS", "ACCESS_REGS",	\   "ADDR_CC_REGS", "GENERAL_CC_REGS",					\   "FP_REGS", "ADDR_FP_REGS", "GENERAL_FP_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Class -> register mapping.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{				       			\   { 0x00000000, 0x00000000 },
comment|/* NO_REGS */
value|\   { 0x00000000, 0x00000002 },
comment|/* CC_REGS */
value|\   { 0x0000fffe, 0x0000000d },
comment|/* ADDR_REGS */
value|\   { 0x0000ffff, 0x0000000d },
comment|/* GENERAL_REGS */
value|\   { 0x00000000, 0x00000030 },
comment|/* ACCESS_REGS */
value|\   { 0x0000fffe, 0x0000000f },
comment|/* ADDR_CC_REGS */
value|\   { 0x0000ffff, 0x0000000f },
comment|/* GENERAL_CC_REGS */
value|\   { 0xffff0000, 0x00000000 },
comment|/* FP_REGS */
value|\   { 0xfffffffe, 0x0000000d },
comment|/* ADDR_FP_REGS */
value|\   { 0xffffffff, 0x0000000d },
comment|/* GENERAL_FP_REGS */
value|\   { 0xffffffff, 0x0000003f },
comment|/* ALL_REGS */
value|\ }
end_define

begin_comment
comment|/* Register -> class mapping.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|enum
name|reg_class
name|regclass_map
index|[
name|FIRST_PSEUDO_REGISTER
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
value|(regclass_map[REGNO])
end_define

begin_comment
comment|/* ADDR_REGS can be used as base or index register.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|ADDR_REGS
end_define

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|ADDR_REGS
end_define

begin_comment
comment|/* Check whether REGNO is a hard register of the suitable class    or a pseudo register currently allocated to one such.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|(((REGNO)< FIRST_PSEUDO_REGISTER 					\&& REGNO_REG_CLASS ((REGNO)) == ADDR_REGS) 			\      || ADDR_REGNO_P (reg_renumber[REGNO]))
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
value|REGNO_OK_FOR_INDEX_P (REGNO)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be in class CLASS,    return the class of reg to actually use.  */
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
value|s390_preferred_reload_class ((X), (CLASS))
end_define

begin_comment
comment|/* We need a secondary reload when loading a PLUS which is    not a valid operand for LOAD ADDRESS.  */
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
value|s390_secondary_input_reload_class ((CLASS), (MODE), (IN))
end_define

begin_comment
comment|/* We need a secondary reload when storing a double-word    to a non-offsettable memory address.  */
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
value|s390_secondary_output_reload_class ((CLASS), (MODE), (OUT))
end_define

begin_comment
comment|/* We need secondary memory to move data between GPRs and FPRs.  */
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
value|((CLASS1) != (CLASS2)&& ((CLASS1) == FP_REGS || (CLASS2) == FP_REGS))
end_define

begin_comment
comment|/* Get_secondary_mem widens its argument to BITS_PER_WORD which loses on 64bit    because the movsi and movsf patterns don't handle r/f moves.  */
end_comment

begin_define
define|#
directive|define
name|SECONDARY_MEMORY_NEEDED_MODE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(GET_MODE_BITSIZE (MODE)< 32				\   ? mode_for_size (32, GET_MODE_CLASS (MODE), 0)	\   : MODE)
end_define

begin_comment
comment|/* Stack layout and calling conventions.  */
end_comment

begin_comment
comment|/* Our stack grows from higher to lower addresses.  However, local variables    are accessed by positive offsets, and function arguments are stored at    increasing addresses.  */
end_comment

begin_define
define|#
directive|define
name|STACK_GROWS_DOWNWARD
end_define

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
value|1
end_define

begin_comment
comment|/* #undef ARGS_GROW_DOWNWARD */
end_comment

begin_comment
comment|/* The basic stack layout looks like this: the stack pointer points    to the register save area for called functions.  Above that area    is the location to place outgoing arguments.  Above those follow    dynamic allocations (alloca), and finally the local variables.  */
end_comment

begin_comment
comment|/* Offset from stack-pointer to first location of outgoing args.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|(TARGET_64BIT ? 160 : 96)
end_define

begin_comment
comment|/* Offset within stack frame to start allocating local variables at.  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|0
end_define

begin_comment
comment|/* Offset from the stack pointer register to an item dynamically    allocated on the stack, e.g., by `alloca'.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|current_function_outgoing_args_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STACK_DYNAMIC_OFFSET
parameter_list|(
name|FUNDECL
parameter_list|)
define|\
value|(STACK_POINTER_OFFSET + current_function_outgoing_args_size)
end_define

begin_comment
comment|/* Offset of first parameter from the argument pointer register value.    We have a fake argument pointer register that points directly to    the argument area.  */
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
comment|/* Defining this macro makes __builtin_frame_address(0) and     __builtin_return_address(0) work with -fomit-frame-pointer.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_FRAME_ADDRESS_RTX
define|\
value|(TARGET_PACKED_STACK ?                                                      \    plus_constant (arg_pointer_rtx, -UNITS_PER_WORD) :                         \    plus_constant (arg_pointer_rtx, -STACK_POINTER_OFFSET))
end_define

begin_comment
comment|/* The return address of the current frame is retrieved    from the initial value of register RETURN_REGNUM.    For frames farther back, we use the stack slot where    the corresponding RETURN_REGNUM register was saved.  */
end_comment

begin_define
define|#
directive|define
name|DYNAMIC_CHAIN_ADDRESS
parameter_list|(
name|FRAME
parameter_list|)
define|\
value|(TARGET_PACKED_STACK ?                                                      \    plus_constant ((FRAME), STACK_POINTER_OFFSET - UNITS_PER_WORD) : (FRAME))
end_define

begin_define
define|#
directive|define
name|RETURN_ADDR_RTX
parameter_list|(
name|COUNT
parameter_list|,
name|FRAME
parameter_list|)
define|\
value|s390_return_addr_rtx ((COUNT), DYNAMIC_CHAIN_ADDRESS ((FRAME)))
end_define

begin_comment
comment|/* In 31-bit mode, we need to mask off the high bit of return addresses.  */
end_comment

begin_define
define|#
directive|define
name|MASK_RETURN_ADDR
value|(TARGET_64BIT ? constm1_rtx : GEN_INT (0x7fffffff))
end_define

begin_comment
comment|/* Exception handling.  */
end_comment

begin_comment
comment|/* Describe calling conventions for DWARF-2 exception handling.  */
end_comment

begin_define
define|#
directive|define
name|INCOMING_RETURN_ADDR_RTX
value|gen_rtx_REG (Pmode, RETURN_REGNUM)
end_define

begin_define
define|#
directive|define
name|INCOMING_FRAME_SP_OFFSET
value|STACK_POINTER_OFFSET
end_define

begin_define
define|#
directive|define
name|DWARF_FRAME_RETURN_COLUMN
value|14
end_define

begin_comment
comment|/* Describe how we implement __builtin_eh_return.  */
end_comment

begin_define
define|#
directive|define
name|EH_RETURN_DATA_REGNO
parameter_list|(
name|N
parameter_list|)
value|((N)< 4 ? (N) + 6 : INVALID_REGNUM)
end_define

begin_define
define|#
directive|define
name|EH_RETURN_HANDLER_RTX
value|gen_rtx_MEM (Pmode, return_address_pointer_rtx)
end_define

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  */
end_comment

begin_define
define|#
directive|define
name|ASM_PREFERRED_EH_DATA_FORMAT
parameter_list|(
name|CODE
parameter_list|,
name|GLOBAL
parameter_list|)
define|\
value|(flag_pic								    \     ? ((GLOBAL) ? DW_EH_PE_indirect : 0) | DW_EH_PE_pcrel | DW_EH_PE_sdata4 \    : DW_EH_PE_absptr)
end_define

begin_comment
comment|/* Frame registers.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|15
end_define

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|34
end_define

begin_define
define|#
directive|define
name|HARD_FRAME_POINTER_REGNUM
value|11
end_define

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|32
end_define

begin_define
define|#
directive|define
name|RETURN_ADDRESS_POINTER_REGNUM
value|35
end_define

begin_comment
comment|/* The static chain must be call-clobbered, but not used for    function argument passing.  As register 1 is clobbered by    the trampoline code, we only have one option.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|0
end_define

begin_comment
comment|/* Number of hardware registers that go into the DWARF-2 unwind info.    To avoid ABI incompatibility, this number must not change even as    'fake' hard registers are added or removed.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_FRAME_REGISTERS
value|34
end_define

begin_comment
comment|/* Frame pointer and argument pointer elimination.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|0
end_define

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM },		\  { FRAME_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM },		\  { ARG_POINTER_REGNUM, STACK_POINTER_REGNUM },			\  { ARG_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM },		\  { RETURN_ADDRESS_POINTER_REGNUM, STACK_POINTER_REGNUM },	\  { RETURN_ADDRESS_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM },	\  { BASE_REGNUM, BASE_REGNUM }}
end_define

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
value|s390_can_eliminate ((FROM), (TO))
end_define

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
value|(OFFSET) = s390_initial_elimination_offset ((FROM), (TO))
end_define

begin_comment
comment|/* Stack arguments.  */
end_comment

begin_comment
comment|/* We need current_function_outgoing_args to be valid.  */
end_comment

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
value|1
end_define

begin_comment
comment|/* Return doesn't modify the stack.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNDECL
parameter_list|,
name|FUNTYPE
parameter_list|,
name|SIZE
parameter_list|)
value|0
end_define

begin_comment
comment|/* Register arguments.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|s390_arg_structure
block|{
name|int
name|gprs
decl_stmt|;
comment|/* gpr so far */
name|int
name|fprs
decl_stmt|;
comment|/* fpr so far */
block|}
name|CUMULATIVE_ARGS
typedef|;
end_typedef

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
parameter_list|,
name|NN
parameter_list|,
name|N_NAMED_ARGS
parameter_list|)
define|\
value|((CUM).gprs=0, (CUM).fprs=0)
end_define

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
value|s390_function_arg_advance (&CUM, MODE, TYPE, NAMED)
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
value|s390_function_arg (&CUM, MODE, TYPE, NAMED)
end_define

begin_comment
comment|/* Arguments can be placed in general registers 2 to 6,    or in floating point registers 0 and 2.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|(((N)>=2&& (N)<7) || \                                  (N) == 16 || (N) == 17)
end_define

begin_comment
comment|/* Scalar return values.  */
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
value|s390_function_value ((VALTYPE), VOIDmode)
end_define

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
define|\
value|s390_function_value (NULL, (MODE))
end_define

begin_comment
comment|/* Only gpr 2 and fpr 0 are ever used as return registers.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|N
parameter_list|)
value|((N) == 2 || (N) == 16)
end_define

begin_comment
comment|/* Function entry and exit.  */
end_comment

begin_comment
comment|/* When returning from a function, the stack pointer does not matter.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_comment
comment|/* Profiling.  */
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
value|s390_function_profiler ((FILE), ((LABELNO)))
end_define

begin_define
define|#
directive|define
name|PROFILE_BEFORE_PROLOGUE
value|1
end_define

begin_comment
comment|/* Implementing the varargs macros.  */
end_comment

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_START
parameter_list|(
name|valist
parameter_list|,
name|nextarg
parameter_list|)
define|\
value|s390_va_start (valist, nextarg)
end_define

begin_comment
comment|/* Trampolines for nested functions.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|(TARGET_64BIT ? 32 : 16)
end_define

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
value|s390_initialize_trampoline ((ADDR), (FNADDR), (CXT))
end_define

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|s390_trampoline_template (FILE)
end_define

begin_comment
comment|/* Addressing modes, and classification of registers for them.  */
end_comment

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
value|0
end_define

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
comment|/* S/390 has no mode dependent addresses.  */
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

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression that is a    valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|REG_OK_STRICT
end_ifdef

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
value|{                                                                       \   if (legitimate_address_p (MODE, X, 1))                                \     goto ADDR;                                                          \ }
end_define

begin_else
else|#
directive|else
end_else

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
value|{                                                                       \   if (legitimate_address_p (MODE, X, 0))                                \     goto ADDR;                                                          \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.  */
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
value|{                                                                       \   (X) = legitimize_address (X, OLDX, MODE);                             \   if (memory_address_p (MODE, X))                                       \     goto WIN;                                                           \ }
end_define

begin_comment
comment|/* Try a machine-dependent way of reloading an illegitimate address    operand.  If we find one, push the reload and jump to WIN.  This    macro is used in only one place: `find_reloads_address' in reload.c.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMIZE_RELOAD_ADDRESS
parameter_list|(
name|AD
parameter_list|,
name|MODE
parameter_list|,
name|OPNUM
parameter_list|,
name|TYPE
parameter_list|,
name|IND
parameter_list|,
name|WIN
parameter_list|)
define|\
value|do {									\   rtx new = legitimize_reload_address (AD, MODE, OPNUM, (int)(TYPE));	\   if (new)								\     {									\       (AD) = new;							\       goto WIN;								\     }									\ } while (0)
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
define|\
value|legitimate_constant_p (X)
end_define

begin_comment
comment|/* Helper macro for s390.c and s390.md to check for symbolic constants.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOLIC_CONST
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == SYMBOL_REF                                             \  || GET_CODE (X) == LABEL_REF                                           \  || (GET_CODE (X) == CONST&& symbolic_reference_mentioned_p (X)))
end_define

begin_define
define|#
directive|define
name|TLS_SYMBOLIC_CONST
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_CODE (X) == SYMBOL_REF&& tls_symbolic_operand (X))	\  || (GET_CODE (X) == CONST&& tls_symbolic_reference_mentioned_p (X)))
end_define

begin_comment
comment|/* Condition codes.  */
end_comment

begin_comment
comment|/* Given a comparison code (EQ, NE, etc.) and the first operand of a COMPARE,    return the mode to be used for the comparison.  */
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
value|s390_select_ccmode ((OP), (X), (Y))
end_define

begin_comment
comment|/* Canonicalize a comparison from one we don't have to one we do have.  */
end_comment

begin_define
define|#
directive|define
name|CANONICALIZE_COMPARISON
parameter_list|(
name|CODE
parameter_list|,
name|OP0
parameter_list|,
name|OP1
parameter_list|)
define|\
value|s390_canonicalize_comparison (&(CODE),&(OP0),&(OP1))
end_define

begin_comment
comment|/* Define the information needed to generate branch and scc insns.  This is    stored from the compare operation.  Note that we can't use "rtx" here    since it hasn't been defined!  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|rtx_def
modifier|*
name|s390_compare_op0
decl_stmt|,
modifier|*
name|s390_compare_op1
decl_stmt|,
modifier|*
name|s390_compare_emitted
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Relative costs of operations.  */
end_comment

begin_comment
comment|/* On s390, copy between fprs and gprs is expensive.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|MODE
parameter_list|,
name|CLASS1
parameter_list|,
name|CLASS2
parameter_list|)
define|\
value|((   (   reg_classes_intersect_p ((CLASS1), GENERAL_REGS)		\&& reg_classes_intersect_p ((CLASS2), FP_REGS))			\     || (   reg_classes_intersect_p ((CLASS1), FP_REGS)			\&& reg_classes_intersect_p ((CLASS2), GENERAL_REGS))) ? 10 : 1)
end_define

begin_comment
comment|/* A C expression for the cost of moving data of mode M between a    register and memory.  A value of 2 is the default; this cost is    relative to those in `REGISTER_MOVE_COST'.  */
end_comment

begin_define
define|#
directive|define
name|MEMORY_MOVE_COST
parameter_list|(
name|M
parameter_list|,
name|C
parameter_list|,
name|I
parameter_list|)
value|1
end_define

begin_comment
comment|/* A C expression for the cost of a branch instruction.  A value of 1    is the default; other values are interpreted relative to that.  */
end_comment

begin_define
define|#
directive|define
name|BRANCH_COST
value|1
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
comment|/* An integer expression for the size in bits of the largest integer machine    mode that should actually be used.  We allow pairs of registers.  */
end_comment

begin_define
define|#
directive|define
name|MAX_FIXED_MODE_SIZE
value|GET_MODE_BITSIZE (TARGET_64BIT ? TImode : DImode)
end_define

begin_comment
comment|/* The maximum number of bytes that a single instruction can move quickly    between memory and registers or between two memory locations.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|(TARGET_64BIT ? 16 : 8)
end_define

begin_define
define|#
directive|define
name|MOVE_MAX_PIECES
value|(TARGET_64BIT ? 8 : 4)
end_define

begin_define
define|#
directive|define
name|MAX_MOVE_MAX
value|16
end_define

begin_comment
comment|/* Determine whether to use move_by_pieces or block move insn.  */
end_comment

begin_define
define|#
directive|define
name|MOVE_BY_PIECES_P
parameter_list|(
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|( (SIZE) == 1 || (SIZE) == 2 || (SIZE) == 4	\     || (TARGET_64BIT&& (SIZE) == 8) )
end_define

begin_comment
comment|/* Determine whether to use clear_by_pieces or block clear insn.  */
end_comment

begin_define
define|#
directive|define
name|CLEAR_BY_PIECES_P
parameter_list|(
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|( (SIZE) == 1 || (SIZE) == 2 || (SIZE) == 4	\     || (TARGET_64BIT&& (SIZE) == 8) )
end_define

begin_comment
comment|/* This macro is used to determine whether store_by_pieces should be    called to "memset" storage with byte values other than zero, or    to "memcpy" storage when the source is a constant string.  */
end_comment

begin_define
define|#
directive|define
name|STORE_BY_PIECES_P
parameter_list|(
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
value|MOVE_BY_PIECES_P (SIZE, ALIGN)
end_define

begin_comment
comment|/* Don't perform CSE on function addresses.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_comment
comment|/* Sections.  */
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
comment|/* Output before writable (initialized) data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_comment
comment|/* Output before writable (uninitialized) data.  */
end_comment

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|".bss"
end_define

begin_comment
comment|/* S/390 constant pool breaks the devices in crtstuff.c to control section    in where code resides.  We have to write it as asm code.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__s390x__
end_ifndef

begin_define
define|#
directive|define
name|CRT_CALL_STATIC_FUNCTION
parameter_list|(
name|SECTION_OP
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|asm (SECTION_OP "\n\ 	bras\t%r2,1f\n\ 0:	.long\t" USER_LABEL_PREFIX #FUNC " - 0b\n\ 1:	l\t%r3,0(%r2)\n\ 	bas\t%r14,0(%r3,%r2)\n\ 	.previous");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Position independent code.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|flag_pic
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|(flag_pic ? 12 : INVALID_REGNUM)
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_PIC_OPERAND_P
parameter_list|(
name|X
parameter_list|)
value|legitimate_pic_operand_p (X)
end_define

begin_comment
comment|/* Assembler file format.  */
end_comment

begin_comment
comment|/* Character to start a comment.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_comment
comment|/* Declare an uninitialized external linkage data object.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)
end_define

begin_comment
comment|/* Globalizing directive for a label.  */
end_comment

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|".globl "
end_define

begin_comment
comment|/* Advance the location counter to a multiple of 2**LOG bytes.  */
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
value|if ((LOG)) fprintf ((FILE), "\t.align\t%d\n", 1<< (LOG))
end_define

begin_comment
comment|/* Advance the location counter by SIZE bytes.  */
end_comment

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
value|fprintf ((FILE), "\t.set\t.,.+"HOST_WIDE_INT_PRINT_UNSIGNED"\n", (SIZE))
end_define

begin_comment
comment|/* The LOCAL_LABEL_PREFIX variable is used by dbxelf.h.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* How to refer to registers in assembler output.  This sequence is    indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{ "%r0",  "%r1",  "%r2",  "%r3",  "%r4",  "%r5",  "%r6",  "%r7",	\   "%r8",  "%r9",  "%r10", "%r11", "%r12", "%r13", "%r14", "%r15",	\   "%f0",  "%f2",  "%f4",  "%f6",  "%f1",  "%f3",  "%f5",  "%f7",	\   "%f8",  "%f10", "%f12", "%f14", "%f9",  "%f11", "%f13", "%f15",	\   "%ap",  "%cc",  "%fp",  "%rp",  "%a0",  "%a1"				\ }
end_define

begin_comment
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.  */
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
comment|/* Output machine-dependent UNSPECs in address constants.  */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_ADDR_CONST_EXTRA
parameter_list|(
name|FILE
parameter_list|,
name|X
parameter_list|,
name|FAIL
parameter_list|)
define|\
value|do {							\   if (!s390_output_addr_const_extra (FILE, (X)))	\     goto FAIL;						\ } while (0);
end_define

begin_comment
comment|/* Output an element of a case-vector that is absolute.  */
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
value|do {									\   char buf[32];								\   fputs (integer_asm_op (UNITS_PER_WORD, TRUE), (FILE));		\   ASM_GENERATE_INTERNAL_LABEL (buf, "L", (VALUE));			\   assemble_name ((FILE), buf);						\   fputc ('\n', (FILE));							\ } while (0)
end_define

begin_comment
comment|/* Output an element of a case-vector that is relative.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|BODY
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|do {									\   char buf[32];								\   fputs (integer_asm_op (UNITS_PER_WORD, TRUE), (FILE));		\   ASM_GENERATE_INTERNAL_LABEL (buf, "L", (VALUE));			\   assemble_name ((FILE), buf);						\   fputc ('-', (FILE));							\   ASM_GENERATE_INTERNAL_LABEL (buf, "L", (REL));			\   assemble_name ((FILE), buf);						\   fputc ('\n', (FILE));							\ } while (0)
end_define

begin_comment
comment|/* Miscellaneous parameters.  */
end_comment

begin_comment
comment|/* Specify the machine mode that this machine uses for the index in the    tablejump instruction.  */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|(TARGET_64BIT ? DImode : SImode)
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
value|((enum machine_mode) (TARGET_64BIT ? DImode : SImode))
end_define

begin_comment
comment|/* This is -1 for "pointer mode" extend.  See ptr_extend in s390.md.  */
end_comment

begin_define
define|#
directive|define
name|POINTERS_EXTEND_UNSIGNED
value|-1
end_define

begin_comment
comment|/* A function address in a call instruction is a byte address (for    indexing purposes) so give the MEM rtx a byte's mode.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|QImode
end_define

begin_comment
comment|/* Specify the value which is used when clz operand is zero.  */
end_comment

begin_define
define|#
directive|define
name|CLZ_DEFINED_VALUE_AT_ZERO
parameter_list|(
name|MODE
parameter_list|,
name|VALUE
parameter_list|)
value|((VALUE) = 64, 1)
end_define

begin_comment
comment|/* Machine-specific symbol_ref flags.  */
end_comment

begin_define
define|#
directive|define
name|SYMBOL_FLAG_ALIGN1
value|(SYMBOL_FLAG_MACH_DEP<< 0)
end_define

begin_comment
comment|/* Check whether integer displacement is in range.  */
end_comment

begin_define
define|#
directive|define
name|DISP_IN_RANGE
parameter_list|(
name|d
parameter_list|)
define|\
value|(TARGET_LONG_DISPLACEMENT? ((d)>= -524288&& (d)<= 524287) \                            : ((d)>= 0&& (d)<= 4095))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

