begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Tahoe version.    Copyright (C) 1989 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * File: tahoe.h  *  * Original port made at the University of Buffalo by Devon Bowen,  * Dale Wiles and Kevin Zachmann.  *  * HCX/UX version by Piet van Oostrum (piet@cs.ruu.nl)  *  * Performance hacking by Michael Tiemann (tiemann@lurch.stanford.edu)  *  * Mail bugs reports or fixes to:	gcc@cs.buffalo.edu  */
end_comment

begin_comment
comment|/* define this for the HCX/UX version */
end_comment

begin_comment
comment|/* #define HCX_UX */
end_comment

begin_comment
comment|/*  * Run-time Target Specification  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

begin_comment
comment|/* no predefines, see Makefile and hcx-universe.c */
end_comment

begin_comment
comment|/* have cc1 print that this is the hcx version */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|printf (" (hcx)");
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* we want "tahoe" and "unix" defined for all future compilations */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dtahoe -Dunix"
end_define

begin_comment
comment|/* have cc1 print that this is the tahoe version */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|printf (" (tahoe)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* this is required in all tm files to hold flags */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Zero if it is safe to output .dfloat and .float pseudos.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_HEX_FLOAT
value|(target_flags& 1)
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"hex-float", 1},		\     {"no-hex-float", -1},	\     { "", TARGET_DEFAULT} }
end_define

begin_escape
end_escape

begin_comment
comment|/*  * Storage Layout  */
end_comment

begin_comment
comment|/* This symbol was previously not mentioned, so apparently the tahoe    is little-endian for bits, or else doesn't care.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* tahoe uses a big endian byte order */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* tahoe uses a big endian word order */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* standard byte size is usable on tahoe */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_comment
comment|/* longs on the tahoe are 4 byte groups */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_comment
comment|/* from the last two params we get 4 bytes per word */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|4
end_define

begin_comment
comment|/* addresses are 32 bits (one word) */
end_comment

begin_define
define|#
directive|define
name|POINTER_SIZE
value|32
end_define

begin_comment
comment|/* all parameters line up on 32 boundaries */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|32
end_define

begin_comment
comment|/* stack should line up on 32 boundaries */
end_comment

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|32
end_define

begin_comment
comment|/* line functions up on 32 bits */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|32
end_define

begin_comment
comment|/* the biggest alignment the tahoe needs in 32 bits */
end_comment

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|32
end_define

begin_comment
comment|/* we have to align after an 'int : 0' in a structure */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

begin_comment
comment|/* structures must be made of full words */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|32
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* structures must be made of full bytes */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* tahoe is picky about data alignment */
end_comment

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_comment
comment|/* keep things standard with pcc */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* this section is borrowed from the vax version since the */
end_comment

begin_comment
comment|/* formats are the same in both of the architectures	   */
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
value|if ((mode) == SFmode) \     { \       if ((d)> 1.7014117331926443e+38) \ 	{ error ("magnitude of constant too large for `float'"); \ 	  (d) = 1.7014117331926443e+38; } \       else if ((d)< -1.7014117331926443e+38) \ 	{ error ("magnitude of constant too large for `float'"); \ 	  (d) = -1.7014117331926443e+38; } \       else if (((d)> 0)&& ((d)< 2.9387358770557188e-39)) \ 	{ warning ("`float' constant truncated to zero"); \ 	  (d) = 0.0; } \       else if (((d)< 0)&& ((d)> -2.9387358770557188e-39)) \ 	{ warning ("`float' constant truncated to zero"); \ 	  (d) = 0.0; } \     }
end_define

begin_comment
comment|/*  * Register Usage  */
end_comment

begin_comment
comment|/* define 15 general regs plus one for the floating point reg (FPP) */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|17
end_define

begin_comment
comment|/* let the compiler know what the fp, sp and pc are */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
value|{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0}
end_define

begin_comment
comment|/* lots of regs aren't guaranteed to return from a call. The FPP reg */
end_comment

begin_comment
comment|/* must be included in these since it can't be saved by the reg mask */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
value|{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1}
end_define

begin_comment
comment|/* A single fp reg can handle any type of float.    CPU regs hold just 32 bits.  */
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
value|(REGNO != 16 ? ((GET_MODE_SIZE(MODE)+UNITS_PER_WORD-1) / UNITS_PER_WORD)  \   : GET_MODE_NUNITS ((MODE)))
end_define

begin_comment
comment|/* any mode greater than 4 bytes (doubles) can only go in an even regs */
end_comment

begin_comment
comment|/* and the FPP can only hold SFmode and DFmode 			       */
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
value|(REGNO != 16							\   ? (GET_MODE_UNIT_SIZE (MODE)<= 4 ? 1 : (REGNO % 2 - 1))	\   : ((MODE) == SFmode || (MODE) == DFmode			\      || (MODE) == SCmode || (MODE) == DCmode))
end_define

begin_comment
comment|/* if mode1 or mode2, but not both, are doubles then modes cannot be tied */
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
value|(((MODE1) == DFmode || (MODE1) == DCmode)	\   == ((MODE2) == DFmode || (MODE2) == DCmode))
end_define

begin_comment
comment|/* return nonzero if register variable of mode MODE is not    a priori a bad idea.  Used only if defined.  */
end_comment

begin_define
define|#
directive|define
name|MODE_OK_FOR_USERVAR
parameter_list|(
name|MODE
parameter_list|)
define|\
value|((MODE) == SImode)
end_define

begin_comment
comment|/* the program counter is reg 15 */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|15
end_define

begin_comment
comment|/* the stack pointer is reg 14 */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|14
end_define

begin_comment
comment|/* the frame pointer is reg 13 */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|13
end_define

begin_comment
comment|/* tahoe does require an fp */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REQUIRED
value|1
end_define

begin_comment
comment|/* since tahoe doesn't have a argument pointer, make it the fp */
end_comment

begin_define
define|#
directive|define
name|ARG_POINTER_REGNUM
value|13
end_define

begin_comment
comment|/* this isn't currently used since C doesn't support this feature */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|0
end_define

begin_comment
comment|/* we'll use reg 1 for structure passing cause the destination */
end_comment

begin_comment
comment|/* of the eventual movblk requires it to be there anyway.      */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|1
end_define

begin_comment
comment|/*  * Register Classes  */
end_comment

begin_comment
comment|/* tahoe has two types of regs. GENERAL_REGS are all the regs up */
end_comment

begin_comment
comment|/* to number 15. FPP_REG is the special floating point processor  */
end_comment

begin_comment
comment|/* register class (only one reg).				  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|GENERAL_REGS
block|,
name|FPP_REG
block|,
name|ALL_REGS
block|,
name|LIM_REG_CLASSES
block|}
enum|;
end_enum

begin_comment
comment|/* defines the number of reg classes.				    */
end_comment

begin_define
define|#
directive|define
name|N_REG_CLASSES
value|(int) LIM_REG_CLASSES
end_define

begin_comment
comment|/* this defines what the classes are officially named for debugging */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_NAMES
define|\
value|{"NO_REGS","GENERAL_REGS","FPP_REG","ALL_REGS"}
end_define

begin_comment
comment|/* set general regs to be the first 16 regs and the fpp reg to be 17th */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
value|{0,0xffff,0x10000,0x1ffff}
end_define

begin_comment
comment|/* register class for the fpp reg is FPP_REG, all others are GENERAL_REGS */
end_comment

begin_define
define|#
directive|define
name|REGNO_REG_CLASS
parameter_list|(
name|REGNO
parameter_list|)
value|(REGNO == 16 ? FPP_REG : GENERAL_REGS)
end_define

begin_comment
comment|/* only general registers can be used as a base reg */
end_comment

begin_define
define|#
directive|define
name|BASE_REG_CLASS
value|GENERAL_REGS
end_define

begin_comment
comment|/* only general registers can be used to index */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|GENERAL_REGS
end_define

begin_comment
comment|/* 'a' as a constraint in the md file means the FFP_REG class */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
value|(C == 'a' ? FPP_REG : NO_REGS)
end_define

begin_comment
comment|/* any general reg but the fpp can be a base reg */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|regno
parameter_list|)
define|\
value|((regno)< FIRST_PSEUDO_REGISTER - 1 || reg_renumber[regno]>= 0)
end_define

begin_comment
comment|/* any general reg except the pc and fpp can be an index reg */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|regno
parameter_list|)
define|\
value|((regno)< FIRST_PSEUDO_REGISTER - 2 || reg_renumber[regno]>= 0)
end_define

begin_comment
comment|/* if your loading a floating point constant, it can't be done */
end_comment

begin_comment
comment|/* through a register. Force it to be a memory constant.       */
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
value|((GET_CODE (X) == CONST_DOUBLE) ? NO_REGS : CLASS)
end_define

begin_comment
comment|/* for the fpp reg, all modes fit; for any others, you need two for doubles */
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
value|(CLASS != FPP_REG ? ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD) : 1)
end_define

begin_comment
comment|/* we don't define any special constant sizes so all should fail */
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
value|0
end_define

begin_comment
comment|/* we don't define any special double sizes so all should fail */
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
comment|/*  * Describing Stack Layout  */
end_comment

begin_comment
comment|/* tahoe stack grows from high to low memory */
end_comment

begin_define
define|#
directive|define
name|STACK_GROWS_DOWNWARD
end_define

begin_comment
comment|/* Define this if longjmp restores from saved registers    rather than from what setjmp saved.  */
end_comment

begin_define
define|#
directive|define
name|LONGJMP_RESTORE_FROM_STACK
end_define

begin_comment
comment|/* tahoe call frames grow from high to low memory on the stack */
end_comment

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
end_define

begin_comment
comment|/* the tahoe fp points to the *top* of the frame instead of the   */
end_comment

begin_comment
comment|/* bottom, so we have to make this offset a constant large enough */
end_comment

begin_comment
comment|/* to jump over the biggest frame possible.			  */
end_comment

begin_define
define|#
directive|define
name|STARTING_FRAME_OFFSET
value|-52
end_define

begin_comment
comment|/* tahoe always pushes 4 bytes unless it's a double in which case */
end_comment

begin_comment
comment|/* it pushes a full 8 bytes.					  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ROUNDING
parameter_list|(
name|BYTES
parameter_list|)
value|(BYTES<= 4 ? 4 : 8)
end_define

begin_comment
comment|/* the first parameter in a function is at the fp + 4 */
end_comment

begin_define
define|#
directive|define
name|FIRST_PARM_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|4
end_define

begin_comment
comment|/* the tahoe return function takes care of everything on the stack */
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
comment|/* function values for all types are returned in register 0 */
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
comment|/* libarary routines also return things in reg 0 */
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
comment|/* Tahoe doesn't return structures in a reentrant way */
end_comment

begin_define
define|#
directive|define
name|PCC_STATIC_STRUCT_RETURN
end_define

begin_comment
comment|/* we only return values from a function in reg 0 */
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
comment|/* we never pass args through a register */
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
comment|/* int is fine to hold the argument summary in FUNCTION_ARG */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* we just set CUM to 0 before the FUNCTION_ARG call. No matter what */
end_comment

begin_comment
comment|/* we make it, FUNCTION_ARG will return 0 anyway		     */
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
comment|/* all modes push their size rounded to the nearest word boundary */
end_comment

begin_comment
comment|/* except block which is the size of the block rounded up	  */
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
comment|/* this is always false since we never pass params in regs */
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

begin_comment
comment|/* this code calculates the register entry mask and sets up    */
end_comment

begin_comment
comment|/* the stack pointer for the function. The stack is set down   */
end_comment

begin_comment
comment|/* far enough from the fp to jump over any push regs and local */
end_comment

begin_comment
comment|/* vars. This is a problem since the tahoe has the fp pointing */
end_comment

begin_comment
comment|/* to the top of the frame and the compiler must know the off- */
end_comment

begin_comment
comment|/* set off the fp to the local vars.			       */
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
value|{ register int regno;						\   register int mask = 0;					\   extern char call_used_regs[];					\   for (regno = 0; regno< FIRST_PSEUDO_REGISTER-1; regno++)	\     if (regs_ever_live[regno]&& !call_used_regs[regno])	\        mask |= 1<< regno;					\   fprintf (FILE, "\t.word 0x%x\n", mask);			\   if (SIZE != 0) fprintf (FILE, "\tsubl3 $%d,fp,sp\n", (SIZE) - STARTING_FRAME_OFFSET); }
end_define

begin_comment
comment|/* Zero out global variable in case it was used in this function.  */
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
value|{ extern rtx tahoe_reg_conversion_loc;				\   tahoe_reg_conversion_loc = 0;					\ }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

begin_comment
comment|/* to call the profiler, the address of the counter var is placed */
end_comment

begin_comment
comment|/* on the stack and then passed into mcount this way			  */
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
value|fprintf (FILE, "\tpushal LP%d\n\tcallf $8,mcount\n", (LABELNO));
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* to call the profiler, push the variable value onto the stack */
end_comment

begin_comment
comment|/* and call mcount like a regular function.			*/
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
value|fprintf (FILE, "\tpushl $LP%d\n\tcallf $8,mcount\n", (LABELNO));
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* all stack handling at the end of a function is handled by the */
end_comment

begin_comment
comment|/* return command.						 */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|1
end_define

begin_comment
comment|/*  * Library Subroutine Names  */
end_comment

begin_comment
comment|/* udiv is a valid C library routine in libc.a, so we call that */
end_comment

begin_define
define|#
directive|define
name|UDIVSI3_LIBCALL
value|"*udiv"
end_define

begin_comment
comment|/* urem is a valid C library routine in libc.a, so we call that */
end_comment

begin_comment
comment|/* but not so on hcx/ux */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

begin_undef
undef|#
directive|undef
name|UMODSI3_LIBCALL
end_undef

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|UMODSI3_LIBCALL
value|"*urem"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Addressing Modes  */
end_comment

begin_comment
comment|/* constant addresses can be treated exactly the same as normal constants */
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
comment|/* we can have as many as two regs in any given address */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|2
end_define

begin_comment
comment|/* The following is all the code for GO_IF_LEGITIMATE_ADDRESS */
end_comment

begin_comment
comment|/* most of this taken directly from the vax tm file since the */
end_comment

begin_comment
comment|/* tahoe and vax addressing modes are nearly identical.	      */
end_comment

begin_comment
comment|/* Is x an indirectable address? */
end_comment

begin_define
define|#
directive|define
name|INDIRECTABLE_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(CONSTANT_ADDRESS_P (X)						\    || (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))			\    || (GET_CODE (X) == PLUS						\&& GET_CODE (XEXP (X, 0)) == REG					\&& REG_OK_FOR_BASE_P (XEXP (X, 0))				\&& CONSTANT_ADDRESS_P (XEXP (X, 1))))
end_define

begin_comment
comment|/* If x is a non-indexed-address, go to ADDR. */
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
value|{ register rtx xfoob = (X);						\   if (GET_CODE (xfoob) == REG) goto ADDR;				\   if (INDIRECTABLE_ADDRESS_P (xfoob)) goto ADDR;			\   xfoob = XEXP (X, 0);							\   if (GET_CODE (X) == MEM&& INDIRECTABLE_ADDRESS_P (xfoob))		\     goto ADDR;								\   if ((GET_CODE (X) == PRE_DEC || GET_CODE (X) == POST_INC)		\&& GET_CODE (xfoob) == REG&& REGNO (xfoob) == 14)		\     goto ADDR; }
end_define

begin_comment
comment|/* Is PROD an index term in mode MODE. */
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
value|(GET_MODE_SIZE (MODE) == 1						\  ? (GET_CODE (PROD) == REG&& REG_OK_FOR_BASE_P (PROD))			\  : (GET_CODE (PROD) == MULT						\&&									\     (xfoo0 = XEXP (PROD, 0), xfoo1 = XEXP (PROD, 1),			\      ((GET_CODE (xfoo0) == CONST_INT					\&& INTVAL (xfoo0) == GET_MODE_SIZE (MODE)			\&& GET_CODE (xfoo1) == REG					\&& REG_OK_FOR_INDEX_P (xfoo1))					\       ||								\       (GET_CODE (xfoo1) == CONST_INT					\&& INTVAL (xfoo1) == GET_MODE_SIZE (MODE)			\&& GET_CODE (xfoo0) == REG					\&& REG_OK_FOR_INDEX_P (xfoo0))))))
end_define

begin_comment
comment|/* Is the addition to the index a reg? */
end_comment

begin_define
define|#
directive|define
name|GO_IF_REG_PLUS_INDEX
parameter_list|(
name|X
parameter_list|,
name|MODE
parameter_list|,
name|ADDR
parameter_list|)
define|\
value|{ register rtx xfooa;							\   if (GET_CODE (X) == PLUS)						\     { if (GET_CODE (XEXP (X, 0)) == REG					\&& REG_OK_FOR_BASE_P (XEXP (X, 0))				\&& (xfooa = XEXP (X, 1),					\ 	      INDEX_TERM_P (xfooa, MODE)))				\ 	goto ADDR;							\       if (GET_CODE (XEXP (X, 1)) == REG					\&& REG_OK_FOR_BASE_P (XEXP (X, 1))				\&& (xfooa = XEXP (X, 0),					\ 	      INDEX_TERM_P (xfooa, MODE)))				\ 	goto ADDR; } }
end_define

begin_comment
comment|/* Is the rtx X a valid memory address for operand of mode MODE? */
end_comment

begin_comment
comment|/* If it is, go to ADDR */
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
value|{ register rtx xfoo, xfoo0, xfoo1;					\   GO_IF_NONINDEXED_ADDRESS (X, ADDR);					\   if (GET_CODE (X) == PLUS)						\     { xfoo = XEXP (X, 0);						\       if (INDEX_TERM_P (xfoo, MODE))					\ 	{ GO_IF_NONINDEXED_ADDRESS (XEXP (X, 1), ADDR); }		\       xfoo = XEXP (X, 1);						\       if (INDEX_TERM_P (xfoo, MODE))					\ 	{ GO_IF_NONINDEXED_ADDRESS (XEXP (X, 0), ADDR); }		\       if (CONSTANT_ADDRESS_P (XEXP (X, 0)))				\ 	{ if (GET_CODE (XEXP (X, 1)) == REG				\&& REG_OK_FOR_BASE_P (XEXP (X, 1)))			\ 	    goto ADDR;							\ 	  GO_IF_REG_PLUS_INDEX (XEXP (X, 1), MODE, ADDR); }		\       if (CONSTANT_ADDRESS_P (XEXP (X, 1)))				\ 	{ if (GET_CODE (XEXP (X, 0)) == REG				\&& REG_OK_FOR_BASE_P (XEXP (X, 0)))			\ 	    goto ADDR;							\ 	  GO_IF_REG_PLUS_INDEX (XEXP (X, 0), MODE, ADDR); } } }
end_define

begin_comment
comment|/* Register 16 can never be used for index or base */
end_comment

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
value|(REGNO(X) != 16)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|(REGNO(X) != 16)
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
value|REGNO_OK_FOR_INDEX_P (REGNO (X))
end_define

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

begin_comment
comment|/* Addressing is too simple to allow optimizing here */
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
comment|/* Post_inc and pre_dec always adds 4 */
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
value|{ if (GET_CODE(ADDR) == POST_INC || GET_CODE(ADDR) == PRE_DEC)		\        goto LABEL;							\    if (GET_CODE (ADDR) == PLUS)						\      { if (CONSTANT_ADDRESS_P (XEXP (ADDR, 0))				\&& GET_CODE (XEXP (ADDR, 1)) == REG);			\        else if (CONSTANT_ADDRESS_P (XEXP (ADDR, 1))			\&& GET_CODE (XEXP (ADDR, 0)) == REG);			\        else goto LABEL; }}
end_define

begin_comment
comment|/* Double's are not legitimate as immediate operands */
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
comment|/*  * Miscellaneous Parameters  */
end_comment

begin_comment
comment|/* the elements in the case jump table are all words */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_MODE
value|HImode
end_define

begin_comment
comment|/* each of the table elements in a case are relative to the jump address */
end_comment

begin_define
define|#
directive|define
name|CASE_VECTOR_PC_RELATIVE
end_define

begin_comment
comment|/* tahoe case instructions just fall through to the next instruction */
end_comment

begin_comment
comment|/* if not satisfied. It doesn't support a default action	     */
end_comment

begin_define
define|#
directive|define
name|CASE_DROPS_THROUGH
end_define

begin_comment
comment|/* the standard answer is given here and work ok */
end_comment

begin_define
define|#
directive|define
name|IMPLICIT_FIX_EXPR
value|FIX_ROUND_EXPR
end_define

begin_comment
comment|/* in a general div case, it's easiest to use TRUNC_DIV_EXPR */
end_comment

begin_define
define|#
directive|define
name|EASY_DIV_EXPR
value|TRUNC_DIV_EXPR
end_define

begin_comment
comment|/* the standard seems to be leaving char's as signed so we left it */
end_comment

begin_comment
comment|/* this way even though we think they should be unsigned!	   */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_comment
comment|/* the most we can move without cutting down speed is 4 bytes */
end_comment

begin_define
define|#
directive|define
name|MOVE_MAX
value|4
end_define

begin_comment
comment|/* our int is 32 bits */
end_comment

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* byte access isn't really slower than anything else */
end_comment

begin_define
define|#
directive|define
name|SLOW_BYTE_ACCESS
value|0
end_define

begin_comment
comment|/* zero extension is more than one instruction so try to avoid it */
end_comment

begin_define
define|#
directive|define
name|SLOW_ZERO_EXTEND
end_define

begin_comment
comment|/* any bits higher than the low 4 are ignored in the shift count */
end_comment

begin_comment
comment|/* so don't bother zero extending or sign extending them         */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
end_define

begin_comment
comment|/* we don't need to officially convert from one fixed type to another */
end_comment

begin_comment
comment|/* in order to use it as that type. We can just assume it's the same  */
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
comment|/* pass chars as ints */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
end_define

begin_comment
comment|/* pointers can be represented by an si mode expression */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|SImode
end_define

begin_comment
comment|/* function addresses are made by specifying a byte address */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|QImode
end_define

begin_comment
comment|/* Define this if addresses of constant functions    shouldn't be put through pseudo regs where they can be cse'd.    On the tahoe a call with a constant address is much faster than one with a    register. */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
end_define

begin_comment
comment|/* specify the costs of various sorts of constants,    and also indicate that multiplication is cheap on this machine.  */
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
value|\     if (RTX == const0_rtx) return 0;				\     if ((unsigned) INTVAL (RTX)< 077) return 1;		\     if (INTVAL (RTX)<= 127&& INTVAL (RTX)>= -128) return 2;	\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 3;							\   case CONST_DOUBLE:						\     return 5;							\   case MULT:							\     total = 2;
end_define

begin_comment
comment|/*  * Condition Code Information  */
end_comment

begin_comment
comment|/* Nonzero if the results of the previous comparison are    in the floating point condition code register.  */
end_comment

begin_define
define|#
directive|define
name|CC_UNCHANGED
value|04000
end_define

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
value|{ if (cc_status.flags& CC_UNCHANGED)				\
comment|/* Happens for cvtld and a few other insns.  */
value|\     cc_status.flags&= ~CC_UNCHANGED;				\   else if (GET_CODE (EXP) == SET)				\     { if (GET_CODE (SET_SRC (EXP)) == CALL)			\ 	CC_STATUS_INIT;						\       else if (GET_CODE (SET_DEST (EXP)) != PC)			\ 	{ cc_status.flags = 0;					\ 	  cc_status.value1 = SET_DEST (EXP);			\ 	  cc_status.value2 = SET_SRC (EXP); } }			\   else if (GET_CODE (EXP) == PARALLEL				\&& GET_CODE (XVECEXP (EXP, 0, 0)) == SET		\&& GET_CODE (SET_DEST (XVECEXP (EXP, 0, 0))) != PC)	\     { cc_status.flags = 0;					\       cc_status.value1 = SET_DEST (XVECEXP (EXP, 0, 0));	\       cc_status.value2 = SET_SRC (XVECEXP (EXP, 0, 0)); }	\
comment|/* PARALLELs whose first element sets the PC are aob, sob insns.	\      They do change the cc's.  So drop through and forget the cc's.  */
value|\   else CC_STATUS_INIT;						\   if (cc_status.value1&& GET_CODE (cc_status.value1) == REG	\&& cc_status.value2					\&& reg_overlap_mentioned_p (cc_status.value1, cc_status.value2))	\     cc_status.value2 = 0;					\   if (cc_status.value1&& GET_CODE (cc_status.value1) == MEM	\&& cc_status.value2					\&& GET_CODE (cc_status.value2) == MEM)			\     cc_status.value2 = 0; }
end_define

begin_comment
comment|/* Actual condition, one line up, should be that value2's address    depends on value1, but that is too much of a pain.  */
end_comment

begin_comment
comment|/*  * Output of Assembler Code  */
end_comment

begin_comment
comment|/* print which tahoe version compiled this code and print a directive */
end_comment

begin_comment
comment|/* to the gnu assembler to say that the following is normal assembly  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{ fprintf (FILE, "#gcc hcx 1.0\n\n");	\   output_file_directive ((FILE), main_input_filename);} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
value|fprintf (FILE, "#gcc tahoe 1.0\n#NO_APP\n");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* the instruction that turns on the APP for the gnu assembler */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_comment
comment|/* the instruction that turns off the APP for the gnu assembler */
end_comment

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_comment
comment|/* what to output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_comment
comment|/* what to output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_comment
comment|/* this is what we call each of the regs. notice that the FPP reg is   */
end_comment

begin_comment
comment|/* called "ac". This should never get used due to the way we've set    */
end_comment

begin_comment
comment|/* up FPP instructions in the md file. But we call it "ac" here to     */
end_comment

begin_comment
comment|/* fill the list.						       */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", \  "r9", "r10", "r11", "r12", "fp", "sp", "pc", "ac"}
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

begin_comment
comment|/* allow generation of sdb info in the assembly */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* allow generation of dbx info in the assembly */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* our dbx doesn't support this */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
end_define

begin_comment
comment|/* we don't want symbols broken up */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* this'll really never be used, but we'll leave it at this */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_CHAR
value|'?'
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HCX_UX */
end_comment

begin_comment
comment|/* registers are called the same thing in dbx anything else */
end_comment

begin_comment
comment|/* This is necessary even if we generate SDB output */
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
comment|/* labels are the label followed by a colon and a newline */
end_comment

begin_comment
comment|/* must be a statement, so surround it in a null loop     */
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
comment|/* use the .globl directive to make labels global for the linker */
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
value|do { fputs (".globl ", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)
end_define

begin_comment
comment|/* output a label by appending an underscore to it */
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
comment|/* use the standard format for printing internal labels */
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
comment|/* a * is used for label indirection in unix assembly */
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
comment|/* outputting a double is easy cause we only have one kind */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

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

begin_else
else|#
directive|else
end_else

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
value|{							\   union { int i[2]; double d;} temp;			\   temp.d = (VALUE);					\   if (TARGET_HEX_FLOAT)					\     fprintf ((FILE), "\t.long 0x%x,0x%x  # %.20e\n",	\ 	     temp.i[0], temp.i[1], temp.d);		\   else							\     fprintf (FILE, "\t.dfloat 0d%.20e\n", temp.d);	\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output an assembler line defining a `float' constant.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
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
value|fprintf (FILE, "\t.float 0f%.20e\n", (VALUE))
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
value|{							\   union { int i; float f;} temp;			\   temp.f = (float) (VALUE);				\   if (TARGET_HEX_FLOAT)					\     fprintf ((FILE), "\t.long 0x%x  # %.20e\n",		\ 	     temp.i, temp.f);				\   else							\     fprintf (FILE, "\t.float 0f%.20e\n", temp.f);	\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

begin_comment
comment|/* This is how to output an assembler line for an ASCII string.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|p
parameter_list|,
name|size
parameter_list|)
define|\
value|{	register int i;					\ 	  fprintf ((FILE), "\t.ascii \""); 		\ 	  for (i = 0; i< (size); i++) 			\ 	    {						\ 	      register int c = (p)[i];			\ 	      if (c == '\'' || c == '\\')		\ 		putc ('\\', (FILE));			\ 	      if (c>= ' '&& c< 0177&& c != '\"')	\ 		putc (c, (FILE));			\ 	      else					\ 		{					\ 		  fprintf ((FILE), "\\%03o", c);	\ 		}					\ 	    }						\ 	  fprintf ((FILE), "\"\n"); }
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* this is the insn to push a register onto the stack */
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
value|fprintf (FILE, "\tpushl %s\n", reg_names[REGNO])
end_define

begin_comment
comment|/* this is the insn to pop a register from the stack */
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
value|fprintf (FILE, "\tmovl (sp)+,%s\n", reg_names[REGNO])
end_define

begin_comment
comment|/* this is required even thought tahoe doesn't support it */
end_comment

begin_comment
comment|/* cause the C code expects it to be defined		  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

begin_define
define|#
directive|define
name|CASE_ALIGNMENT
value|2
end_define

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
value|if ((LOG)!=0) fprintf ((FILE), "\t.align %d\n", 1<<(LOG))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CASE_ALIGNMENT
value|1
end_define

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
value|LOG ? fprintf (FILE, "\t.align %d\n", (LOG)) : 0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to skip over some space */
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
value|fprintf (FILE, "\t.space %u\n", (SIZE))
end_define

begin_comment
comment|/* This defines common variables across files */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

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
value|( fputs (".comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u\n", (SIZE)))
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This says how to output an assembler line    to define a local common symbol.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

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
value|( fputs ("\t.bss ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%u,4\n", (SIZE),(ROUNDED)))
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* code to generate a label */
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
comment|/* Print an instruction operand X on file FILE.    CODE is the code from the %-spec that requested printing this operand;    if `%z3' was used to print operand 3, then CODE is 'z'.    On the Vax, the only code used is `#', indicating that either    `d' or `g' should be printed, depending on whether we're using dfloat    or gfloat.  */
end_comment

begin_comment
comment|/* Print an operand.  Some difference from the vax code,    since the tahoe can't support immediate floats and doubles.     %@ means print the proper alignment operand for aligning after a casesi.    This depends on the assembler syntax.    This is 1 for our assembler, since .align is logarithmic.     %s means the number given is supposed to be a shift value, but on    the tahoe it should be converted to a number that can be used as a    multiplicative constant (cause multiplication is a whole lot faster    than shifting). So make the number 2^n instead. */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '@')
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
value|{ if (CODE == '@')							\     putc ('0' + CASE_ALIGNMENT, FILE);					\   else if (CODE == 's')							\     fprintf (FILE, "$%d", 1<< INTVAL(X));				\   else if (GET_CODE (X) == REG)						\     fprintf (FILE, "%s", reg_names[REGNO (X)]);				\   else if (GET_CODE (X) == MEM)						\     output_address (XEXP (X, 0));					\   else { putc ('$', FILE); output_addr_const (FILE, X); }}
end_define

begin_comment
comment|/* When the operand is an address, call print_operand_address to */
end_comment

begin_comment
comment|/* do the work from output-tahoe.c.				 */
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
value|print_operand_address (FILE, ADDR)
end_define

begin_comment
comment|/* This is for G++ */
end_comment

begin_define
define|#
directive|define
name|CRT0_DUMMIES
end_define

begin_define
define|#
directive|define
name|DOT_GLOBAL_START
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HCX_UX
end_ifdef

begin_define
define|#
directive|define
name|NO_GNU_LD
end_define

begin_comment
comment|/* because of COFF format */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-L/usr/staff/lib"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

