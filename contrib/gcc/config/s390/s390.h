begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for IBM S/390    Copyright (C) 1999, 2000, 2001, 2002, 2003 Free Software Foundation, Inc.    Contributed by Hartmut Penner (hpenner@de.ibm.com) and                   Ulrich Weigand (uweigand@de.ibm.com). This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|<s390/fixdfdi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Run-time target specification.  */
end_comment

begin_comment
comment|/* Target CPU builtins.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|do							\     {							\       builtin_assert ("cpu=s390");			\       builtin_assert ("machine=s390");			\       builtin_define ("__s390__");			\       if (TARGET_64BIT)					\         builtin_define ("__s390x__");			\     }							\   while (0)
end_define

begin_comment
comment|/* Optional target features.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TARGET_HARD_FLOAT
value|(target_flags& 1)
end_define

begin_define
define|#
directive|define
name|TARGET_SOFT_FLOAT
value|(!(target_flags& 1))
end_define

begin_define
define|#
directive|define
name|TARGET_BACKCHAIN
value|(target_flags& 2)
end_define

begin_define
define|#
directive|define
name|TARGET_SMALL_EXEC
value|(target_flags& 4)
end_define

begin_define
define|#
directive|define
name|TARGET_DEBUG_ARG
value|(target_flags& 8)
end_define

begin_define
define|#
directive|define
name|TARGET_64BIT
value|(target_flags& 16)
end_define

begin_define
define|#
directive|define
name|TARGET_MVCLE
value|(target_flags& 32)
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
value|0x13
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0x3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ { "hard-float",    1, N_("Use hardware fp")},         		       \   { "soft-float",   -1, N_("Don't use hardware fp")},	      	       \   { "backchain",     2, N_("Set backchain")},           		       \   { "no-backchain", -2, N_("Don't set backchain (faster, but debug harder")}, \   { "small-exec",    4, N_("Use bras for executable< 64k")},           \   { "no-small-exec",-4, N_("Don't use bras")},            	       \   { "debug",         8, N_("Additional debug prints")},        	       \   { "no-debug",     -8, N_("Don't print additional debug prints")},     \   { "64",           16, N_("64 bit mode")},         	               \   { "31",          -16, N_("31 bit mode")},                             \   { "mvcle",        32, N_("mvcle use")},         	               \   { "no-mvcle",    -32, N_("mvc&ex")},                                  \   { "", TARGET_DEFAULT, 0 } }
end_define

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
name|PROMOTE_FUNCTION_ARGS
end_define

begin_define
define|#
directive|define
name|PROMOTE_FUNCTION_RETURN
end_define

begin_define
define|#
directive|define
name|PROMOTE_FOR_CALL_ONLY
end_define

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
value|(LEVEL == SAVE_FUNCTION ? VOIDmode    \   : LEVEL == SAVE_NONLOCAL ? (TARGET_64BIT ? TImode : DImode) : Pmode)
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
name|MAX_LONG_TYPE_SIZE
value|64
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
value|64
end_define

begin_comment
comment|/* ??? Should support extended format.  */
end_comment

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
comment|/* We have 16 general purpose registers (registers 0-15),    and 16 floating point registers (registers 16-31).    (On non-IEEE machines, we have only 4 fp registers.)      Amongst the general purpose registers, some are used    for specific purposes:    GPR 11: Hard frame pointer (if needed)    GPR 12: Global offset table pointer (if needed)    GPR 13: Literal pool base register    GPR 14: Return address register    GPR 15: Stack pointer      Registers 32-34 are 'fake' hard registers that do not    correspond to actual hardware:    Reg 32: Argument pointer    Reg 33: Condition code    Reg 34: Frame pointer  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|35
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
value|((N) == 32 || (N) == 34)
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
name|BASE_REGISTER
value|13
end_define

begin_define
define|#
directive|define
name|RETURN_REGNUM
value|14
end_define

begin_define
define|#
directive|define
name|CC_REGNUM
value|33
end_define

begin_comment
comment|/* Set up fixed registers and calling convention:     GPRs 0-5 are always call-clobbered,    GPRs 6-15 are always call-saved.    GPR 12 is fixed if used as GOT pointer.    GPR 13 is always fixed (as literal pool pointer).    GPR 14 is always fixed (as return address).    GPR 15 is always fixed (as stack pointer).    The 'fake' hard registers are call-clobbered and fixed.     On 31-bit, FPRs 18-19 are call-clobbered;    on 64-bit, FPRs 24-31 are call-clobbered.    The remaining FPRs are call-saved.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{ 0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   0, 1, 1, 1,					\   0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   0, 0, 0, 0, 					\   1, 1, 1 }
end_define

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{ 1, 1, 1, 1, 					\   1, 1, 0, 0, 					\   0, 0, 0, 0, 					\   0, 1, 1, 1,					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1 }
end_define

begin_define
define|#
directive|define
name|CALL_REALLY_USED_REGISTERS
define|\
value|{ 1, 1, 1, 1, 					\   1, 1, 0, 0, 					\   0, 0, 0, 0, 					\   0, 0, 0, 0,					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1, 1, 					\   1, 1, 1 }
end_define

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|do								\   {								\     int i;							\ 								\     if (flag_pic)						\       {								\ 	fixed_regs[PIC_OFFSET_TABLE_REGNUM] = 1;		\ 	call_used_regs[PIC_OFFSET_TABLE_REGNUM] = 1;		\       }								\     if (TARGET_64BIT)						\       {								\         for (i = 24; i< 32; i++)				\ 	    call_used_regs[i] = call_really_used_regs[i] = 0;	\       }								\     else							\       {								\         for (i = 18; i< 20; i++)				\ 	    call_used_regs[i] = call_really_used_regs[i] = 0;	\       }								\  } while (0)
end_define

begin_comment
comment|/* Preferred register allocation order.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{  1, 2, 3, 4, 5, 0, 14, 13, 12, 11, 10, 9, 8, 7, 6,            \    16, 17, 18, 19, 20, 21, 22, 23,                              \    24, 25, 26, 27, 28, 29, 30, 31,                              \    15, 32, 33, 34 }
end_define

begin_comment
comment|/* Fitting values into registers.  */
end_comment

begin_comment
comment|/* Integer modes<= word size fit into any GPR.    Integer modes> word size fit into successive GPRs, starting with    an even-numbered register.    SImode and DImode fit into FPRs as well.      Floating point modes<= word size fit into any FPR or GPR.    Floating point modes> word size (i.e. DFmode on 32-bit) fit    into any FPR, or an even-odd GPR pair.      Complex floating point modes fit either into two FPRs, or into    successive GPRs (again starting with an even number).      Condition code modes fit only into the CC register.  */
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
value|(FP_REGNO_P(REGNO)?                                           \     (GET_MODE_CLASS(MODE) == MODE_COMPLEX_FLOAT ? 2 : 1) :      \    GENERAL_REGNO_P(REGNO)?                                      \     ((GET_MODE_SIZE(MODE)+UNITS_PER_WORD-1) / UNITS_PER_WORD) : \    1)
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
value|(FP_REGNO_P(REGNO)?                                               \    ((MODE) == SImode || (MODE) == DImode ||                         \     GET_MODE_CLASS(MODE) == MODE_FLOAT ||                           \     GET_MODE_CLASS(MODE) == MODE_COMPLEX_FLOAT) :                   \    GENERAL_REGNO_P(REGNO)?                                          \     (HARD_REGNO_NREGS(REGNO, MODE) == 1 || !((REGNO)& 1)) :        \    CC_REGNO_P(REGNO)?                                               \      GET_MODE_CLASS (MODE) == MODE_CC :                             \    FRAME_REGNO_P(REGNO)?                                            \      (enum machine_mode) (MODE) == Pmode :                          \    0)
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
value|((CLASS) == FP_REGS ? 						\       (GET_MODE_CLASS (MODE) == MODE_COMPLEX_FLOAT ? 2 : 1) :  		\       (GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* If a 4-byte value is loaded into a FPR, it is placed into the    *upper* half of the register, not the lower.  Therefore, we    cannot use SUBREGs to switch between modes in FP registers.  */
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
value|(GET_MODE_SIZE (FROM) != GET_MODE_SIZE (TO)			\    ? reg_classes_intersect_p (FP_REGS, CLASS) : 0)
end_define

begin_comment
comment|/* Register classes.  */
end_comment

begin_comment
comment|/* We use the following register classes:    GENERAL_REGS     All general purpose registers    ADDR_REGS        All general purpose registers except %r0                     (These registers can be used in address generation)    FP_REGS          All floating point registers      GENERAL_FP_REGS  Union of GENERAL_REGS and FP_REGS    ADDR_FP_REGS     Union of ADDR_REGS and FP_REGS      NO_REGS          No registers    ALL_REGS         All registers      Note that the 'fake' frame pointer and argument pointer registers    are included amongst the address registers here.  The condition    code register is only included in ALL_REGS.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|ADDR_REGS
block|,
name|GENERAL_REGS
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
value|{ "NO_REGS", "ADDR_REGS", "GENERAL_REGS", 				\   "FP_REGS", "ADDR_FP_REGS", "GENERAL_FP_REGS", "ALL_REGS" }
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
value|\   { 0x0000fffe, 0x00000005 },
comment|/* ADDR_REGS */
value|\   { 0x0000ffff, 0x00000005 },
comment|/* GENERAL_REGS */
value|\   { 0xffff0000, 0x00000000 },
comment|/* FP_REGS */
value|\   { 0xfffffffe, 0x00000005 },
comment|/* ADDR_FP_REGS */
value|\   { 0xffffffff, 0x00000005 },
comment|/* GENERAL_FP_REGS */
value|\   { 0xffffffff, 0x00000007 },
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
value|(((REGNO)< FIRST_PSEUDO_REGISTER 					\&& REGNO_REG_CLASS ((REGNO)) == ADDR_REGS) 			\     || (reg_renumber[REGNO]> 0&& reg_renumber[REGNO]< 16))
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
comment|/* Define various machine-dependent constraint letters.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|((C) == 'a' ? ADDR_REGS :                                             \    (C) == 'd' ? GENERAL_REGS :                                          \    (C) == 'f' ? FP_REGS : NO_REGS)
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
value|((C) == 'I' ? (unsigned long) (VALUE)< 256 :                         \    (C) == 'J' ? (unsigned long) (VALUE)< 4096 :                        \    (C) == 'K' ? (VALUE)>= -32768&& (VALUE)< 32768 :                  \    (C) == 'L' ? (unsigned long) (VALUE)< 65536 : 0)
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
value|1
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
value|((C) == 'Q' ?  q_constraint (OP) : 			\       (C) == 'S' ?  larl_operand (OP, GET_MODE (OP)) : 0)
end_define

begin_define
define|#
directive|define
name|EXTRA_MEMORY_CONSTRAINT
parameter_list|(
name|C
parameter_list|)
value|((C) == 'Q')
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

begin_comment
comment|/* #undef FRAME_GROWS_DOWNWARD */
end_comment

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

begin_decl_stmt
specifier|extern
name|int
name|current_function_outgoing_args_size
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
define|\
value|(STACK_POINTER_OFFSET + current_function_outgoing_args_size)
end_define

begin_comment
comment|/* Offset from the stack pointer register to an item dynamically    allocated on the stack, e.g., by `alloca'.  */
end_comment

begin_define
define|#
directive|define
name|STACK_DYNAMIC_OFFSET
parameter_list|(
name|FUNDECL
parameter_list|)
value|(STARTING_FRAME_OFFSET)
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
comment|/* The return address of the current frame is retrieved     from the initial value of register RETURN_REGNUM.    For frames farther back, we use the stack slot where    the corresponding RETURN_REGNUM register was saved.  */
end_comment

begin_define
define|#
directive|define
name|DYNAMIC_CHAIN_ADDRESS
parameter_list|(
name|FRAME
parameter_list|)
define|\
value|((FRAME) != hard_frame_pointer_rtx ? (FRAME) :				\    plus_constant (arg_pointer_rtx, -STACK_POINTER_OFFSET))
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
value|(TARGET_64BIT ? GEN_INT (-1) : GEN_INT (0x7fffffff))
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
define|\
value|gen_rtx_MEM (Pmode, plus_constant (arg_pointer_rtx, \                                      TARGET_64BIT? -48 : -40))
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

begin_comment
comment|/* The static chain must be call-clobbered, but not used for     function argument passing.  As register 1 is clobbered by     the trampoline code, we only have one option.  */
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
name|INITIAL_FRAME_POINTER_OFFSET
parameter_list|(
name|DEPTH
parameter_list|)
value|(DEPTH) = 0
end_define

begin_define
define|#
directive|define
name|ELIMINABLE_REGS
define|\
value|{{ FRAME_POINTER_REGNUM, STACK_POINTER_REGNUM},	        \  { FRAME_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM},    \  { ARG_POINTER_REGNUM, STACK_POINTER_REGNUM},	        \  { ARG_POINTER_REGNUM, HARD_FRAME_POINTER_REGNUM}}
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
value|(1)
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
value|{ if ((FROM) == FRAME_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM) 	  \   { (OFFSET) = 0; }     						  \   else  if ((FROM) == FRAME_POINTER_REGNUM                                \&& (TO) == HARD_FRAME_POINTER_REGNUM)                	  \   { (OFFSET) = 0; }     						  \   else if ((FROM) == ARG_POINTER_REGNUM                                   \&& (TO) == HARD_FRAME_POINTER_REGNUM)                         \   { (OFFSET) = s390_arg_frame_offset (); }     				  \   else if ((FROM) == ARG_POINTER_REGNUM&& (TO) == STACK_POINTER_REGNUM)  \   { (OFFSET) = s390_arg_frame_offset (); }     				  \   else									  \     abort();								  \ }
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
value|s390_function_arg_pass_by_reference (MODE, TYPE)
end_define

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

begin_comment
comment|/* We return scalars in general purpose register 2 for integral values,    and floating point register 0 for fp values.  */
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
value|gen_rtx_REG ((INTEGRAL_TYPE_P (VALTYPE)			\&& TYPE_PRECISION (VALTYPE)< BITS_PER_WORD)	\ 	       || POINTER_TYPE_P (VALTYPE)			\ 	       ? word_mode : TYPE_MODE (VALTYPE),		\ 	       TREE_CODE (VALTYPE) == REAL_TYPE&& TARGET_HARD_FLOAT ? 16 : 2)
end_define

begin_comment
comment|/* Define how to find the value returned by a library function assuming    the value has mode MODE.  */
end_comment

begin_define
define|#
directive|define
name|RET_REG
parameter_list|(
name|MODE
parameter_list|)
value|((GET_MODE_CLASS (MODE) == MODE_INT       \                        || TARGET_SOFT_FLOAT ) ? 2 : 16)
end_define

begin_define
define|#
directive|define
name|LIBCALL_VALUE
parameter_list|(
name|MODE
parameter_list|)
value|gen_rtx (REG, MODE, RET_REG (MODE))
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
comment|/* Aggregate return values.  */
end_comment

begin_comment
comment|/* The definition of this macro implies that there are cases where    a scalar value cannot be returned in registers.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_IN_MEMORY
parameter_list|(
name|type
parameter_list|)
define|\
value|(TYPE_MODE (type) == BLKmode || 				\    GET_MODE_CLASS (TYPE_MODE (type)) == MODE_COMPLEX_INT  ||	\    GET_MODE_CLASS (TYPE_MODE (type)) == MODE_COMPLEX_FLOAT)
end_define

begin_comment
comment|/* Structure value address is passed as invisible first argument (gpr 2).  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE
value|0
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
name|BUILD_VA_LIST_TYPE
parameter_list|(
name|VALIST
parameter_list|)
define|\
value|(VALIST) = s390_build_va_list ()
end_define

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

begin_define
define|#
directive|define
name|EXPAND_BUILTIN_VA_ARG
parameter_list|(
name|valist
parameter_list|,
name|type
parameter_list|)
define|\
value|s390_va_arg (valist, type)
end_define

begin_comment
comment|/* Trampolines for nested functions.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|(TARGET_64BIT ? 36 : 20)
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
comment|/* Library calls.  */
end_comment

begin_comment
comment|/* We should use memcpy, not bcopy.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
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
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx and check    its validity for a certain class.  We have two alternate definitions    for each of them.  The usual definition accepts all pseudo regs; the    other rejects them all.  The symbol REG_OK_STRICT causes the latter    definition to be used.     Most source files want to accept pseudo regs in the hope that they will    get allocated to the class that the insn wants them to be in.    Some source files that are used after register allocation    need to be strict.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_NONSTRICT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_MODE (X) == Pmode)&&			\  ((REGNO (X)>= FIRST_PSEUDO_REGISTER) 		\   || REGNO_REG_CLASS (REGNO (X)) == ADDR_REGS))
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_NONSTRICT_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_INDEX_NONSTRICT_P (X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_STRICT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_MODE (X) == Pmode)&& (REGNO_OK_FOR_INDEX_P (REGNO (X))))
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_STRICT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|((GET_MODE (X) == Pmode)&& (REGNO_OK_FOR_BASE_P (REGNO (X))))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_INDEX_NONSTRICT_P(X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_BASE_NONSTRICT_P(X)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_INDEX_STRICT_P(X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|REG_OK_FOR_BASE_STRICT_P(X)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Relative costs of operations.  */
end_comment

begin_comment
comment|/* A part of a C `switch' statement that describes the relative costs    of constant RTL expressions.  It must contain `case' labels for    expression codes `const_int', `const', `symbol_ref', `label_ref'    and `const_double'.  Each case must ultimately reach a `return'    statement to return the relative cost of the use of that kind of    constant value in an expression.  The cost may depend on the    precise value of the constant, which is available for examination    in X, and the rtx code of the expression in which it is contained,    found in OUTER_CODE.     CODE is the expression code--redundant, since it can be obtained    with `GET_CODE (X)'.  */
end_comment

begin_comment
comment|/* Force_const_mem does not work out of reload, because the saveable_obstack    is set to reload_obstack, which does not live long enough.     Because of this we cannot use force_const_mem in addsi3.    This leads to problems with gen_add2_insn with a constant greater    than a short. Because of that we give an addition of greater    constants a cost of 3 (reload1.c 10096).  */
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
value|case CONST:                                                   \     if ((GET_CODE (XEXP (RTX, 0)) == MINUS)&&                  \ 	(GET_CODE (XEXP (XEXP (RTX, 0), 1)) != CONST_INT))      \      return 1000;                                               \   case CONST_INT:                                               \        if ((OUTER_CODE == PLUS)&&                              \ 	   ((INTVAL (RTX)> 32767) ||                           \ 	   (INTVAL (RTX)< -32768))) 	                        \          return COSTS_N_INSNS (3);                              \   case LABEL_REF:                                               \   case SYMBOL_REF:                                              \   case CONST_DOUBLE:                                            \     return 0;
end_define

begin_comment
unit|\
comment|/* Like `CONST_COSTS' but applies to nonconstant RTL expressions.    This can be used, for example, to indicate how costly a multiply    instruction is.  In writing this macro, you can use the construct    `COSTS_N_INSNS (N)' to specify a cost equal to N fast    instructions.  OUTER_CODE is the code of the expression in which X    is contained.  */
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
value|case ASHIFT:                                                          \   case ASHIFTRT:                                                        \   case LSHIFTRT:                                                        \   case PLUS:                                                            \   case AND:                                                             \   case IOR:                                                             \   case XOR:                                                             \   case MINUS:                                                           \   case NEG:                                                             \   case NOT:                                                             \     return COSTS_N_INSNS (1);                                           \   case MULT:                                                            \     if (GET_MODE (XEXP (X, 0)) == DImode)                               \       return COSTS_N_INSNS (40);                                        \     else                                                                \       return COSTS_N_INSNS (7);                                         \   case DIV:                                                             \   case UDIV:                                                            \   case MOD:                                                             \   case UMOD:                                                            \     return COSTS_N_INSNS (33);
end_define

begin_comment
comment|/* An expression giving the cost of an addressing mode that contains    ADDRESS.  If not defined, the cost is computed from the ADDRESS    expression and the `CONST_COSTS' values.  */
end_comment

begin_define
define|#
directive|define
name|ADDRESS_COST
parameter_list|(
name|RTX
parameter_list|)
value|s390_address_cost ((RTX))
end_define

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
comment|/* The maximum number of bytes that a single instruction can move quickly    between memory and registers or between two memory locations. */
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
value|fprintf ((FILE), "\t.set\t.,.+%u\n", (SIZE))
end_define

begin_comment
comment|/* Output a reference to a user-level label named NAME.  */
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
value|asm_fprintf ((FILE), "%U%s", (*targetm.strip_name_encoding) (NAME))
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
value|((OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),	\    sprintf ((OUTPUT), "%s.%d", (NAME), (LABELNO)))
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
comment|/* Either simplify a location expression, or return the original.  */
end_comment

begin_define
define|#
directive|define
name|ASM_SIMPLIFY_DWARF_ADDR
parameter_list|(
name|X
parameter_list|)
define|\
value|s390_simplify_dwarf_addr (X)
end_define

begin_comment
comment|/* How to refer to registers in assembler output.  This sequence is    indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{ "%r0",  "%r1",  "%r2",  "%r3",  "%r4",  "%r5",  "%r6",  "%r7",	\   "%r8",  "%r9", "%r10", "%r11", "%r12", "%r13", "%r14", "%r15",	\   "%f0",  "%f2",  "%f4",  "%f6",  "%f1",  "%f3",  "%f5",  "%f7",	\   "%f8",  "%f10", "%f12", "%f14", "%f9", "%f11", "%f13", "%f15",	\   "%ap",  "%cc",  "%fp"							\ }
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
comment|/* Constant Pool for all symbols operands which are changed with    force_const_mem during insn generation (expand_insn).  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|s390_pool_count
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|s390_nr_constants
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ASM_OUTPUT_POOL_PROLOGUE
parameter_list|(
name|FILE
parameter_list|,
name|FUNNAME
parameter_list|,
name|fndecl
parameter_list|,
name|size
parameter_list|)
define|\
value|{								       	\   struct pool_constant *pool;					       	\ 								        \     if (s390_pool_count == -1)                                        	\      {							                \        s390_nr_constants = 0;				                \        for (pool = first_pool; pool; pool = pool->next)	                \ 	 if (pool->mark) s390_nr_constants++;		                \        return;                                      	                \      }                                                                  \ }
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_SPECIAL_POOL_ENTRY
parameter_list|(
name|FILE
parameter_list|,
name|EXP
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
value|{									    \   fprintf (FILE, ".LC%d:\n", LABELNO);					    \ 									    \
comment|/* Output the value of the constant itself.  */
value|\   switch (GET_MODE_CLASS (MODE))					    \     {									    \     case MODE_FLOAT:							    \       if (GET_CODE (EXP) != CONST_DOUBLE)				    \ 	abort ();							    \ 									    \       REAL_VALUE_FROM_CONST_DOUBLE (r, EXP);				    \       assemble_real (r, MODE, ALIGN);					    \       break;								    \ 									    \     case MODE_INT:							    \     case MODE_PARTIAL_INT:						    \       if (GET_CODE (EXP) == CONST					    \ 	  || GET_CODE (EXP) == SYMBOL_REF				    \ 	  || GET_CODE (EXP) == LABEL_REF)				    \         {								    \ 	  fputs (integer_asm_op (UNITS_PER_WORD, TRUE), FILE);		    \           s390_output_symbolic_const (FILE, EXP);			    \           fputc ('\n', (FILE));						    \ 	}								    \       else								    \ 	{								    \ 	  assemble_integer (EXP, GET_MODE_SIZE (MODE), ALIGN, 1);	    \ 	  if (GET_MODE_SIZE (MODE) == 1)				    \ 	    ASM_OUTPUT_SKIP ((FILE), 1);				    \ 	}								    \       break;								    \ 									    \     default:								    \       abort ();								    \     }									    \   goto WIN;								    \ }
end_define

begin_comment
comment|/* Miscellaneous parameters.  */
end_comment

begin_comment
comment|/* Define the codes that are matched by predicates in aux-output.c.  */
end_comment

begin_define
define|#
directive|define
name|PREDICATE_CODES
define|\
value|{"s_operand",       { SUBREG, MEM }},					\   {"s_imm_operand",   { CONST_INT, CONST_DOUBLE, SUBREG, MEM }},	\   {"bras_sym_operand",{ SYMBOL_REF, CONST }},				\   {"larl_operand",    { SYMBOL_REF, CONST, CONST_INT, CONST_DOUBLE }},	\   {"load_multiple_operation", {PARALLEL}},			        \   {"store_multiple_operation", {PARALLEL}},			        \   {"const0_operand",  { CONST_INT, CONST_DOUBLE }},			\   {"consttable_operand", { SYMBOL_REF, LABEL_REF, CONST, 		\ 			   CONST_INT, CONST_DOUBLE }},			\   {"s390_plus_operand", { PLUS }},
end_define

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
comment|/* Load from integral MODE< SI from memory into register makes sign_extend    or zero_extend      In our case sign_extension happens for Halfwords, other no extension.  */
end_comment

begin_define
define|#
directive|define
name|LOAD_EXTEND_OP
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(TARGET_64BIT ? ((MODE) == QImode ? ZERO_EXTEND :               \                  (MODE) == HImode ? SIGN_EXTEND : NIL)          \               : ((MODE) == HImode ? SIGN_EXTEND : NIL))
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
comment|/* A function address in a call instruction is a byte address (for    indexing purposes) so give the MEM rtx a byte's mode.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|QImode
end_define

begin_comment
comment|/* This macro definition sets up a default value for `main' to return.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_MAIN_RETURN
value|c_expand_return (integer_zero_node)
end_define

begin_comment
comment|/* In rare cases, correct code generation requires extra machine dependent    processing between the second jump optimization pass and delayed branch    scheduling.  On those machines, define this macro as a C statement to act on    the code starting at INSN.  */
end_comment

begin_define
define|#
directive|define
name|MACHINE_DEPENDENT_REORG
parameter_list|(
name|INSN
parameter_list|)
value|s390_machine_dependent_reorg (INSN)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

