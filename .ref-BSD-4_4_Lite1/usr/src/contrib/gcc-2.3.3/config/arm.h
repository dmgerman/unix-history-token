begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for Acorn RISC Machine.    Copyright (C) 1991 Free Software Foundation, Inc.    Contributed by Pieter `Tiggr' Schoenmakers (rcpieter@win.tue.nl)               and Martin Simmons (@harleqn.co.uk).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Sometimes the directive `riscos' is checked.  This does not imply that this    tm file can be used unchanged to build a GCC for RISC OS.    (Since in fact, it can't.)  */
end_comment

begin_function_decl
specifier|extern
name|void
name|output_prologue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_epilogue
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|arm_output_asm_insn
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|arm_output_llc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_add_immediate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_call
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
name|output_mov_double_fpu_from_arm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_mov_double_arm_from_fpu
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_mov_immediate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_multi_immediate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|output_shifted_move
parameter_list|()
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Translation to find startup files.  On RISCiX boxes, gcrt0.o is in    /usr/lib.  */
end_comment

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{pg:/usr/lib/gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|riscos
end_ifdef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Darm -Driscos"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Darm -Driscix -Dunix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Run-time Target Specification.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
define|\
value|fputs (" (ARM/RISCiX)", stderr);
end_define

begin_comment
comment|/* Run-time compilation parameters selecting different hardware subsets.    On the ARM, misuse it in a different way.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|target_flags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Nonzero if the function prologue (and epilogue) should obey    the ARM Procedure Call Standard.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_APCS
value|(target_flags& 1)
end_define

begin_comment
comment|/* Nonzero if the function prologue should output the function name to enable    the post mortem debugger to print a backtrace (very useful on RISCOS,    unused on RISCiX).  Specifying this flag also enables -mapcs.    XXX Must still be implemented in the prologue.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_POKE_FUNCTION_NAME
value|(target_flags& 2)
end_define

begin_comment
comment|/* Nonzero if floating point instructions are emulated by the FPE, in which    case instruction scheduling becomes very uninteresting.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_FPE
value|(target_flags& 4)
end_define

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{                         			\   {"apcs",		 1},			\   {"poke-function-name", 2},			\   {"fpe",		 4},			\   {"",   		 TARGET_DEFAULT }	\ }
end_define

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
value|1
end_define

begin_comment
comment|/* OVERRIDE_OPTIONS takes care of the following:    - if -mpoke-function-name, then -mapcs.    - if doing debugging, then -mapcs; if RISCOS, then -mpoke-function-name.    - if floating point is done by emulation, forget about instruction      scheduling.  Note that this only saves compilation time; it doesn't      matter for the final code.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|riscos
end_ifdef

begin_define
define|#
directive|define
name|TARGET_WHEN_DEBUGGING
value|3
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_WHEN_DEBUGGING
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OVERRIDE_OPTIONS
define|\
value|{								\   if (write_symbols != NO_DEBUG)				\     target_flags |= TARGET_WHEN_DEBUGGING;			\   else if (TARGET_POKE_FUNCTION_NAME)				\     target_flags |= 1;						\   if (TARGET_FPE)						\     flag_schedule_insns = flag_schedule_insns_after_reload = 0;	\ }
end_define

begin_comment
comment|/* Omitting the frame pointer is a very good idea on the ARM, especially if    not TARGET_APCS, in which case all that pushing on function entry isn't    mandatory anymore.  */
end_comment

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|OPTIMIZE
parameter_list|)
define|\
value|{					\   if (OPTIMIZE)				\     flag_omit_frame_pointer = 1;	\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Target machine storage Layout.  */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.  */
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

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|0
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is the lowest    numbered.  */
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

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|32
end_define

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|4
end_define

begin_define
define|#
directive|define
name|POINTER_SIZE
value|32
end_define

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|32
end_define

begin_define
define|#
directive|define
name|STACK_BOUNDARY
value|32
end_define

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|32
end_define

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_define
define|#
directive|define
name|BIGGEST_ALIGNMENT
value|32
end_define

begin_comment
comment|/* Every structures size must be a multiple of 32 bits.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|32
end_define

begin_define
define|#
directive|define
name|STRICT_ALIGNMENT
value|1
end_define

begin_comment
comment|/* Define number of bits in most basic integer type.    (If undefined, default is BITS_PER_WORD).  */
end_comment

begin_comment
comment|/* #define INT_TYPE_SIZE */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Register allocation in ARM Procedure Call Standard (as used on RISCiX):    (S - saved over call).  	r0	   *	argument word/integer result 	r1-r3		argument word  	r4-r8	     S	register variable 	r9	     S	(rfp) register variable (real frame pointer)  	r10  	   F S	(sl) stack limit (not currently used) 	r11 	   F S	(fp) argument pointer 	r12		(ip) temp workspace 	r13  	   F S	(sp) lower end of current stack frame 	r14		(lr) link address/workspace 	r15	   F	(pc) program counter  	f0		floating point result 	f1-f3		floating point scratch  	f4-f7	     S	floating point variable     *: See CONDITIONAL_REGISTER_USAGE  */
end_comment

begin_comment
comment|/* The number of hard registers is 16 ARM + 8 FPU.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|24
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
value|{                        \   0,0,0,0,0,0,0,0,	 \   0,0,1,1,0,1,0,1,	 \   0,0,0,0,0,0,0,0	 \ }
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
value|{                            \   1,1,1,1,0,0,0,0,	     \   0,0,1,1,1,1,1,1,	     \   1,1,1,1,0,0,0,0	     \ }
end_define

begin_comment
comment|/* If doing stupid life analysis, avoid a bug causing a return value r0 to be    trampled.  This effectively reduces the number of available registers by 1.    XXX It is a hack, I know.    XXX Is this still needed?  */
end_comment

begin_define
define|#
directive|define
name|CONDITIONAL_REGISTER_USAGE
define|\
value|{			\   if (obey_regdecls)	\     fixed_regs[0] = 1;	\ }
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     On the ARM regs are UNITS_PER_WORD bits wide; FPU regs can hold any FP    mode.  */
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
value|((REGNO)>= 16 ? 1							\      : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    This is TRUE for ARM regs since they can hold anything, and TRUE for FPU    regs holding FP.  */
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
value|((REGNO)< 16 || GET_MODE_CLASS (MODE) == MODE_FLOAT)
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
value|(((MODE1) == SFmode || (MODE1) == DFmode)      \    == ((MODE2) == SFmode || (MODE2) == DFmode))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* Define this if the program counter is overloaded on a register.  */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|15
end_define

begin_comment
comment|/* Register to use for pushing function arguments.  */
end_comment

begin_define
define|#
directive|define
name|STACK_POINTER_REGNUM
value|13
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|9
end_define

begin_comment
comment|/* Value should be nonzero if functions must have frame pointers.    Zero means the frame pointer need not be set up (and parms may be accessed    via the stack pointer) in functions that seem suitable.  */
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
value|11
end_define

begin_comment
comment|/* The native (Norcroft) Pascal compiler for the ARM passes the static chain    as an invisible last argument (possible since varargs don't exist in    Pascal), so the following is not true.  */
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
value|0
end_define

begin_comment
comment|/* The order in which register should be allocated.  It is good to use ip    since no saving is required (though calls clobber it).  It is quite good to    use lr since other calls may clobber it anyway.  */
end_comment

begin_define
define|#
directive|define
name|REG_ALLOC_ORDER
define|\
value|{                                   \     0, 1, 2, 3, 12, 14,	4, 5,       \     6, 7, 8, 10, 9, 11, 13, 15,     \     16, 17, 18, 19, 20, 21, 22, 23  \ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Register and constant classes.  */
end_comment

begin_comment
comment|/* Register classes: all ARM regs or all FPU regs---simple! */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|FPU_REGS
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
value|{			\   "NO_REGS",		\   "FPU_REGS",		\   "GENERAL_REGS",	\   "ALL_REGS",		\ }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
define|\
value|{				\   0x000000,
comment|/* NO_REGS  */
value|\   0xFF0000,
comment|/* FPU_REGS */
value|\   0x00FFFF,
comment|/* GENERAL_REGS */
value|\   0xFFFFFF
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
define|\
value|((REGNO)< 16 ? GENERAL_REGS : FPU_REGS)
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
comment|/* Get reg_class from a letter such as appears in the machine description.    We only need constraint `f' for FPU_REGS (`r' == GENERAL_REGS).  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_FROM_LETTER
parameter_list|(
name|C
parameter_list|)
define|\
value|((C)=='f' ? FPU_REGS : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C. 	I: immediate arithmetic operand (i.e. 8 bits shifted as required). 	J: valid indexing constants.  */
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
value|((C) == 'I' ? const_ok_for_arm (VALUE) :		\    (C) == 'J' ? (abs (VALUE)< 4096) : 0)
end_define

begin_comment
comment|/* Constant letter 'G' for the FPU immediate constants. */
end_comment

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_LETTER_P
parameter_list|(
name|X
parameter_list|,
name|C
parameter_list|)
define|\
value|((C) == 'G' ? const_double_rtx_ok_for_fpu (X) : 0)
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
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.    ARM regs are UNITS_PER_WORD bits while FPU regs can hold any FP mode */
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
value|((CLASS) == FPU_REGS ? 1					       \      : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Moves between FPU_REGS and GENERAL_REGS are two insns.  */
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
value|((((CLASS1) == FPU_REGS&& (CLASS2) != FPU_REGS)	\     || ((CLASS2) == FPU_REGS&& (CLASS1) != FPU_REGS))	\    ? 4 : 2)
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
value|1
end_define

begin_comment
comment|/* Define this if the nominal address of the stack frame    is at the high-address end of the local variables;    that is, each additional local variable allocated    goes at a more negative offset in the frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
value|1
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
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ROUNDING
parameter_list|(
name|NPUSHED
parameter_list|)
value|(((NPUSHED) + 3)& ~3)
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
value|4
end_define

begin_comment
comment|/* Value is the number of byte of arguments automatically    popped when returning from a subroutine call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.    SIZE is the number of bytes of arguments passed on the stack.     On the ARM, the caller does not pop any of its arguments that were passed    on the stack.  */
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
value|(GET_MODE_CLASS (TYPE_MODE (VALTYPE)) == MODE_FLOAT  \    ? gen_rtx (REG, TYPE_MODE (VALTYPE), 16)            \    : gen_rtx (REG, TYPE_MODE (VALTYPE), 0))
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
value|(GET_MODE_CLASS (MODE) == MODE_FLOAT  \    ? gen_rtx (REG, MODE, 16)		\    : gen_rtx (REG, MODE, 0))
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the ARM, only r0 and f0 can return results.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_VALUE_REGNO_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO) == 0 || (REGNO) == 16)
end_define

begin_comment
comment|/* Define where to put the arguments to a function.    Value is zero to push the argument on the stack,    or a hard register in which to store the argument.     MODE is the argument's machine mode.    TYPE is the data type of the argument (as a tree).     This is null for libcalls where that information may     not be available.    CUM is a variable of type CUMULATIVE_ARGS which gives info about     the preceding args and about the function being called.    NAMED is nonzero if this argument is a named parameter     (otherwise it is an extra parameter matching an ellipsis).     On the ARM, normally the first 16 bytes are passed in registers r0-r3; all    other arguments are passed on the stack.  If (NAMED == 0) (which happens    only in assign_parms, since SETUP_INCOMING_VARARGS is defined), say it is    passed in the stack (function_prologue will indeed make it pass in the    stack if necessary).  */
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
value|((NAMED)						\    ? ((CUM)>= 16 ? 0 : gen_rtx (REG, MODE, (CUM) / 4))	\    : 0)
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
value|((CUM)< 16&& 16< (CUM) + ((MODE) != BLKmode            \ 			       ? GET_MODE_SIZE (MODE)       \ 			       : int_size_in_bytes (TYPE))  \    ? 4 - (CUM) / 4 : 0)
end_define

begin_comment
comment|/* A C type for declaring a variable that is used as the first argument of    `FUNCTION_ARG' and other related values.  For some target machines, the    type `int' suffices and can hold the number of bytes of argument so far.     On the ARM, this is the number of bytes of arguments scanned so far.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.    On the ARM, the offset starts at 0.  */
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
value|((CUM) = (((FNTYPE)&& aggregate_value_p (FNTYPE)) ? 4 : 0))
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
value|(CUM) += ((MODE) != BLKmode                       \ 	    ? (GET_MODE_SIZE (MODE) + 3)& ~3       \ 	    : (int_size_in_bytes (TYPE) + 3)& ~3)
end_define

begin_comment
unit|\
comment|/* 1 if N is a possible register number for function argument passing.    On the ARM, r0-r3 are used to pass args.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_ARG_REGNO_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)>= 0&& (REGNO)<= 3)
end_define

begin_comment
comment|/* Perform any actions needed for a function that is receiving a variable    number of arguments.  CUM is as above.  MODE and TYPE are the mode and type    of the current parameter.  PRETEND_SIZE is a variable that should be set to    the amount of stack that must be pushed by the prolog to pretend that our    caller pushed it.     Normally, this macro will push all remaining incoming registers on the    stack and set PRETEND_SIZE to the length of the registers pushed.     On the ARM, PRETEND_SIZE is set in order to have the prologue push the last    named arg and all anonymous args onto the stack.    XXX I know the prologue shouldn't be pushing registers, but it is faster    that way.  */
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
value|{									\   extern int current_function_anonymous_args;				\   current_function_anonymous_args = 1;					\   if ((CUM)< 16)							\     (PRETEND_SIZE) = 16 - (CUM);					\ }
end_define

begin_comment
comment|/* Generate assembly output for the start of a function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROLOGUE
parameter_list|(
name|STREAM
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|output_prologue ((STREAM), (SIZE))
end_define

begin_comment
comment|/* Call the function profiler with a given profile label.  The Acorn compiler    puts this BEFORE the prolog but gcc pust it afterwards.  The ``mov ip,lr''    seems like a good idea to stick with cc convention.  ``prof'' doesn't seem    to mind about this!  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|STREAM
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{							\     fprintf(STREAM, "\tmov\tip, lr\n");			\     fprintf(STREAM, "\tbl\tmcount\n");			\     fprintf(STREAM, "\t.word\tLP%d\n", (LABELNO));	\     arm_increase_location (12);				\ }
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.     On the ARM, the function epilogue recovers the stack pointer from the    frame.  */
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
name|STREAM
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|output_epilogue ((STREAM), (SIZE))
end_define

begin_comment
comment|/* Determine if the epilogue should be output as RTL.    You should override this if you define FUNCTION_EXTRA_EPILOGUE.  */
end_comment

begin_comment
comment|/* #define USE_RETURN_INSN use_return_insn () */
end_comment

begin_comment
comment|/* Store in the variable DEPTH the initial difference between the frame    pointer reg contents and the stack pointer reg contents, as of the start of    the function body.  This depends on the layout of the fixed parts of the    stack frame and on how registers are saved.  */
end_comment

begin_define
define|#
directive|define
name|INITIAL_FRAME_POINTER_OFFSET
parameter_list|(
name|DEPTH
parameter_list|)
define|\
value|(DEPTH) = (get_frame_size () + 3)& ~3;
end_define

begin_comment
comment|/* Output assembler code for a block containing the constant parts    of a trampoline, leaving space for the variable parts.     On the ARM, (if r8 is the static chain regnum, and remembering that    referencing pc adds an offset of 8) the trampoline looks like: 	   ldr 		r8, [pc, #0] 	   ldr		pc, [pc] 	   .word	static chain value 	   .word	function's address  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|{						\   fprintf ((FILE), "\tldr\tr8, [pc, #0]\n");	\   fprintf ((FILE), "\tldr\tpc, [pc, #0]\n");	\   fprintf ((FILE), "\t.word\t0\n");		\   fprintf ((FILE), "\t.word\t0\n");		\ }
end_define

begin_comment
comment|/* Length in units of the trampoline for entering a nested function.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|16
end_define

begin_comment
comment|/* Alignment required for a trampoline in units.  */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_ALIGN
value|4
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
value|{									\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant ((TRAMP), 8)),	\ 		  (CXT));						\   emit_move_insn (gen_rtx (MEM, SImode, plus_constant ((TRAMP), 12)),	\ 		  (FNADDR));						\ }
end_define

begin_comment
comment|/* Call the function profiler with a given profile label.  The Acorn compiler    puts this BEFORE the prolog but gcc pust it afterwards.  The ``mov ip,lr''    seems like a good idea to stick with cc convention.  ``prof'' doesn't seem    to mind about this!  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|STREAM
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|{							\     fprintf(STREAM, "\tmov\tip, lr\n");			\     fprintf(STREAM, "\tbl\tmcount\n");			\     fprintf(STREAM, "\t.word\tLP%d\n", (LABELNO));	\     arm_increase_location (12);				\ }
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
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PRE_INCREMENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_POST_DECREMENT
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_PRE_DECREMENT
value|1
end_define

begin_comment
comment|/* Macros to check register numbers against specific register classes.  */
end_comment

begin_comment
comment|/* These assume that REGNO is a hard or pseudo reg number.    They give nonzero only if REGNO is a hard reg of the suitable class    or a pseudo reg currently allocated to a suitable hard reg.    Since they use reg_renumber, they are safe only once reg_renumber    has been allocated, which happens in local-alloc.c.     On the ARM, don't allow the pc to be used.  */
end_comment

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)< 15 || (unsigned) reg_renumber[(REGNO)]< 15)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_INDEX_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|REGNO_OK_FOR_BASE_P(REGNO)
end_define

begin_comment
comment|/* Maximum number of registers that can appear in a valid memory address.    The addressing mode [ra,rb,<shift> rc] uses the greatest number of    registers.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|3
end_define

begin_comment
comment|/* Recognize any constant value that is a valid address.  */
end_comment

begin_comment
comment|/* XXX We can address any constant, eventually...  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|( GET_CODE(X) == LABEL_REF	\   ||  GET_CODE(X) == SYMBOL_REF \   ||  GET_CODE(X) == CONST_INT	\   ||  GET_CODE(X) == CONST )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|CONSTANT_ADDRESS_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == SYMBOL_REF&& CONSTANT_POOL_ADDRESS_P (X))
end_define

begin_comment
comment|/* Nonzero if the constant value X is a legitimate general operand.    It is given that X satisfies CONSTANT_P or is a CONST_DOUBLE.     On the ARM, allow any integer (invalid ones are removed later by insn    patterns), nice doubles and symbol_refs which refer to the function's    constant pool XXX.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_CONSTANT_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == CONST_INT					\    || (GET_CODE (X) == CONST_DOUBLE				\&&  const_double_rtx_ok_for_fpu (X)))
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit||| GET_CODE(X) == SYMBOL_REF&& CONSTANT_POOL_ADDRESS_P(X))
endif|#
directive|endif
end_endif

begin_comment
comment|/* The macros REG_OK_FOR..._P assume that the arg is a REG rtx    and check its validity for a certain class.    We have two alternate definitions for each of them.    The usual definition accepts all pseudo regs; the other rejects    them unless they have been allocated suitable hard regs.    The symbol REG_OK_STRICT causes the latter definition to be used.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REG_OK_STRICT
end_ifndef

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
value|(REGNO (X)< 16 || REGNO (X)>= 24)
end_define

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
value|REG_OK_FOR_BASE_P(X)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_PRE_POST_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X)< 16 || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_else
else|#
directive|else
end_else

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

begin_define
define|#
directive|define
name|REG_OK_FOR_PRE_POST_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X)< 16 || (unsigned) reg_renumber[REGNO (X)]< 16)
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
name|BASE_REGISTER_RTX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X))
end_define

begin_define
define|#
directive|define
name|INDEX_REGISTER_RTX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& REG_OK_FOR_INDEX_P (X))
end_define

begin_comment
comment|/* A C statement (sans semicolon) to jump to LABEL for legitimate index RTXs    used by the macro GO_IF_LEGITIMATE_ADDRESS.  Floating point indices can    only be small constants. */
end_comment

begin_define
define|#
directive|define
name|GO_IF_LEGITIMATE_INDEX
parameter_list|(
name|MODE
parameter_list|,
name|BASE_REGNO
parameter_list|,
name|INDEX
parameter_list|,
name|LABEL
parameter_list|)
define|\
value|do \ {										      \   int range;									      \ 										      \   if (GET_MODE_CLASS (MODE) == MODE_FLOAT)					      \     range = 1024;								      \   else										      \     {										      \       if (INDEX_REGISTER_RTX_P (INDEX))						      \ 	goto LABEL;								      \       if (GET_MODE_SIZE (MODE)<= 4&&  GET_CODE (INDEX) == MULT)		      \ 	{									      \ 	  rtx xiop0 = XEXP (INDEX, 0);						      \ 	  rtx xiop1 = XEXP (INDEX, 1);						      \ 	  if (INDEX_REGISTER_RTX_P (xiop0)&&  power_of_two_operand (xiop1, SImode))  \ 	    goto LABEL;								      \ 	  if (INDEX_REGISTER_RTX_P (xiop1)&&  power_of_two_operand (xiop0, SImode))  \ 	    goto LABEL;								      \ 	}									      \       range = 4096;								      \     }										      \ 										      \     if (GET_CODE (INDEX) == CONST_INT&& abs (INTVAL (INDEX))< range)  	      \       goto LABEL;								      \ } while (0)
end_define

begin_comment
comment|/* Jump to LABEL if X is a valid address RTX.  This must also take    REG_OK_STRICT into account when deciding about valid registers, but it uses    the above macros so we are in luck.  Allow REG, REG+REG, REG+INDEX,    INDEX+REG, REG-INDEX, and non floating SYMBOL_REF to the constant pool.    Allow REG-only and AUTINC-REG if handling TImode.  Other symbol refs must    be forced though a static cell to ensure addressability.  */
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
name|LABEL
parameter_list|)
define|\
value|{									\   if (BASE_REGISTER_RTX_P (X))						\     goto LABEL;								\   else if ((GET_CODE (X) == POST_INC || GET_CODE (X) == PRE_DEC)	\&& GET_CODE (XEXP (X, 0)) == REG				\&& REG_OK_FOR_PRE_POST_P (XEXP (X, 0)))			\     goto LABEL;								\   else if ((MODE) == TImode)						\     ;									\   else if (GET_CODE (X) == PLUS)					\     {									\       rtx xop0 = XEXP(X,0);						\       rtx xop1 = XEXP(X,1);						\ 									\       if (BASE_REGISTER_RTX_P (xop0))					\ 	GO_IF_LEGITIMATE_INDEX (MODE, REGNO (xop0), xop1, LABEL);	\       else if (BASE_REGISTER_RTX_P (xop1))				\ 	GO_IF_LEGITIMATE_INDEX (MODE, REGNO (xop1), xop0, LABEL);	\     }									\   else if (GET_CODE (X) == MINUS)					\     {									\       rtx xop0 = XEXP (X,0);						\       rtx xop1 = XEXP (X,1);						\ 									\       if (BASE_REGISTER_RTX_P (xop0))					\ 	GO_IF_LEGITIMATE_INDEX (MODE, -1, xop1, LABEL);			\     }									\   else if (GET_MODE_CLASS (MODE) != MODE_FLOAT				\&& GET_CODE (X) == SYMBOL_REF				\&& CONSTANT_POOL_ADDRESS_P (X))				\     goto LABEL;								\   else if ((GET_CODE (X) == PRE_INC || GET_CODE (X) == POST_DEC)	\&& GET_CODE (XEXP (X, 0)) == REG				\&& REG_OK_FOR_PRE_POST_P (XEXP (X, 0)))			\     goto LABEL;								\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     On the ARM, try to convert [REG, #BIGCONST]    into ADD BASE, REG, #UPPERCONST and [BASE, #VALIDCONST],    where VALIDCONST == 0 in case of TImode.  */
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
value|{						        		     \   if (GET_CODE (X) == PLUS)			        		     \     {						        		     \       rtx xop0 = XEXP (X, 0);			        		     \       rtx xop1 = XEXP (X, 1);			        		     \ 						        		     \       if (BASE_REGISTER_RTX_P (xop0)&& GET_CODE (xop1) == CONST_INT)	     \ 	{					        		     \ 	  int n = INTVAL (xop1);		        		     \ 	  int low_n = ((MODE) == TImode ? 0	        		     \ 		       : n>= 0 ? (n& 0xFFF) : -((-n)& 0xFFF));	     \ 	  rtx base_reg = gen_reg_rtx (SImode);	        		     \ 	  rtx val = force_operand (gen_rtx (PLUS, SImode, xop0,		     \ 					    gen_rtx (CONST_INT,		     \ 						     VOIDmode, n - low_n)),  \ 				   0);					     \           emit_move_insn (base_reg, val);				     \ 	  (X) = (low_n == 0 ? base_reg					     \ 		 : gen_rtx (PLUS, SImode, base_reg,			     \ 			    gen_rtx (CONST_INT, VOIDmode, low_n)));	     \ 	}								     \       else if (BASE_REGISTER_RTX_P (xop1)&& GET_CODE (xop0) == CONST_INT)   \ 	{								     \ 	  int n = INTVAL (xop0);					     \ 	  int low_n = ((MODE) == TImode ? 0				     \ 		       : n>= 0 ? (n& 0xFFF) : -((-n)& 0xFFF));	     \ 	  rtx base_reg = gen_reg_rtx (SImode);				     \ 	  rtx val = force_operand (gen_rtx (PLUS, SImode, xop1,		     \ 					    gen_rtx (CONST_INT,		     \ 						     VOIDmode, n - low_n)),  \ 				   0);					     \ 	  emit_move_insn (base_reg, val);				     \ 	  (X) = (low_n == 0 ? base_reg					     \ 		 : gen_rtx (PLUS, SImode, base_reg,			     \ 			    gen_rtx (CONST_INT, VOIDmode, low_n)));	     \ 	}								     \     }									     \   if (memory_address_p (MODE, X))					     \     goto win;								     \ }
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
value|{									\   if (GET_CODE(ADDR) == PRE_DEC || GET_CODE(ADDR) == POST_DEC		\       || GET_CODE(ADDR) == PRE_INC || GET_CODE(ADDR) == POST_INC)	\     goto LABEL;								\ }
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
comment|/* 'char' is signed by default on RISCiX, unsigned on RISCOS.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|riscos
end_ifdef

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|0
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Don't cse the address of the function being compiled.  */
end_comment

begin_define
define|#
directive|define
name|NO_RECURSIVE_FUNCTION_CSE
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
comment|/* Define if normal loads of shorter-than-word items from memory clears    the rest of the bigs in the register.    On the ARM, movhi does a garbage extend.  */
end_comment

begin_comment
comment|/* #define BYTE_LOADS_ZERO_EXTEND */
end_comment

begin_comment
comment|/* Define this if zero-extension is slow (more than one real instruction).    On the ARM, it is more than one instruction only if not fetching from    memory.  */
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
comment|/* Immediate shift counts are truncated by the output routines (or was it    the assembler?).  Shift counts in a register are truncated by ARM.  Note    that the native compiler puts too large (> 32) immediate shift counts    into a register and shifts by the register, letting the ARM decide what    to do instead of doing that itself.  */
end_comment

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
value|1
end_define

begin_comment
comment|/* We have the vprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* XX This is not true, is it?  */
end_comment

begin_comment
comment|/* All integers have the same format so truncation is easy.  */
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
comment|/* Calling from registers is a massive pain.  */
end_comment

begin_define
define|#
directive|define
name|NO_FUNCTION_CSE
value|1
end_define

begin_comment
comment|/* Chars and shorts should be passed as ints.  */
end_comment

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
value|1
end_define

begin_comment
comment|/* The machine modes of pointers and functions */
end_comment

begin_define
define|#
directive|define
name|Pmode
value|SImode
end_define

begin_define
define|#
directive|define
name|FUNCTION_MODE
value|Pmode
end_define

begin_comment
comment|/* The structure type of the machine dependent info field of insns    No uses for this yet.  */
end_comment

begin_comment
comment|/* #define INSN_MACHINE_INFO  struct machine_info  */
end_comment

begin_comment
comment|/* The relative costs of various types of constants.  Note that cse.c defines    REG = 1, SUBREG = 2, any node = (2 + sum of subnodes).  */
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
value|case CONST_INT:				\     if (const_ok_for_arm (INTVAL (RTX)))	\       return (2);				\     else					\       return (5);				\ 						\   case CONST: 					\   case LABEL_REF:				\   case SYMBOL_REF:				\     return (6);					\ 						\   case CONST_DOUBLE:				\     if (const_double_rtx_ok_for_fpu (RTX))	\       return(2);				\     else					\       return(7);
end_define

begin_escape
end_escape

begin_comment
comment|/* Condition code information.  */
end_comment

begin_comment
comment|/* Store in cc_status the expressions    that the condition codes will describe    after execution of an instruction whose pattern is EXP.    Do not alter them if the instruction would not alter the cc's.  */
end_comment

begin_comment
comment|/* On the ARM nothing sets the condition code implicitly---apart from DImode    operations excluding moves---but we have to watch for registers in the    condition code value being clobbered.  This clobbering includes (alas)    function calls.  XXX They could just be considered to clobber regs 0-3 and    10-15 with extra work.  */
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
value|{									\   if (GET_MODE (EXP) == DImode						\&& GET_CODE (EXP) == SET						\&& GET_CODE (SET_SRC (EXP)) != REG				\&& GET_CODE (SET_SRC (EXP)) != MEM				\&& GET_CODE (SET_SRC (EXP)) != CONST_INT)				\     CC_STATUS_INIT;							\   else if (GET_CODE (EXP) == SET)					\     {									\       rtx dest = SET_DEST (EXP);					\       if (dest == cc0_rtx)						\ 	{								\ 	  cc_status.flags = 0;						\ 	  cc_status.value1 = SET_DEST (EXP);				\ 	  cc_status.value2 = SET_SRC (EXP);				\ 	}								\       if (BASE_REGISTER_RTX_P (dest))					\ 	{								\ 	  if (cc_status.value1						\&& reg_overlap_mentioned_p (dest, cc_status.value1))	\ 	    cc_status.value1 = 0;					\ 	  if (cc_status.value2						\&& reg_overlap_mentioned_p (dest, cc_status.value2)) 	\ 	    cc_status.value2 = 0;				        \ 	}							        \     }								        \   else if (GET_CODE (INSN) != JUMP_INSN&& GET_CODE (EXP) == PARALLEL)	\     {									\       CC_STATUS_INIT;							\     }									\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Assembler output control */
end_comment

begin_comment
comment|/* The text to go at the start of the assembler file */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|{                                                                             \   extern char *version_string;                                                \                                                                               \   fprintf (STREAM,"@ Generated by gcc %s for ARM/RISCiX\n", version_string);  \   fprintf (STREAM,"rfp\t.req\tr9\n");                                         \   fprintf (STREAM,"fp\t.req\tr11\n");				              \   fprintf (STREAM,"ip\t.req\tr12\n");				              \   fprintf (STREAM,"sp\t.req\tr13\n");				              \   fprintf (STREAM,"lr\t.req\tr14\n");					      \   fprintf (STREAM,"pc\t.req\tr15\n");				              \ }
end_define

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

begin_comment
comment|/* Switch to the text or data segment.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_comment
comment|/* The assembler's names for the registers.  RFP need not always be used as    the Real framepointer; it can also be used as a normal general register.    Note that the name `fp' is horribly misleading since `fp' is in fact only    the argument-and-return-context pointer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{				                   \   "r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",  \   "r8","rfp", "sl", "fp", "ip", "sp", "lr", "pc",  \   "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7"   \ }
end_define

begin_comment
comment|/* DBX register number for a given compiler register number */
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
comment|/* Generate DBX debugging information.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
end_define

begin_comment
comment|/* Acorn dbx moans about continuation chars, so don't use any.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* Output a label definition.  */
end_comment

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
value|arm_asm_output_label ((STREAM), (NAME))
end_define

begin_comment
comment|/* Output a function label definition.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|ASM_OUTPUT_LABEL(STREAM, NAME)
end_define

begin_comment
comment|/* Output a globalising directive for a label.  */
end_comment

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
value|(fprintf (STREAM, "\t.global\t"),	  \    assemble_name (STREAM, NAME),	  \    fputc ('\n',STREAM))
end_define

begin_comment
unit|\
comment|/* Output a reference to a label.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (STREAM, "_%s", NAME)
end_define

begin_comment
comment|/* Make an internal label into a string.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|STRING
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf (STRING, "*%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* Output an internal label definition.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|do                                    	      	   		\     {						      	   		\       char *s = (char *) alloca (11 + strlen (PREFIX));	   		\       extern int arm_target_label, arm_ccfsm_state;	   		\ 						           		\       if (arm_ccfsm_state == 3&& arm_target_label == (NUM))   		\ 	arm_ccfsm_state = 0;				        	\       strcpy (s, "*");				           		\       sprintf (&s[strlen (s)], "%s%d", (PREFIX), (NUM));   		\       arm_asm_output_label (STREAM, s);		                        \     } while (0)
end_define

begin_comment
comment|/* Nothing special is done about jump tables */
end_comment

begin_comment
comment|/* #define ASM_OUTPUT_CASE_LABEL(STREAM,PREFIX,NUM,TABLE)   */
end_comment

begin_comment
comment|/* #define ASM_OUTPUT_CASE_END(STREAM,NUM,TABLE)	    */
end_comment

begin_comment
comment|/* Construct a private name.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTVAR
parameter_list|,
name|NAME
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|((OUTVAR) = (char *) alloca (strlen (NAME) + 10),  \    sprintf ((OUTVAR), "%s.%d", (NAME), (NUMBER)))
end_define

begin_comment
comment|/* Output a push or a pop instruction (only used when profiling).  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_PUSH
parameter_list|(
name|STREAM
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|(arm_increase_location (4)                                   \    , fprintf(STREAM,"\tstmfd\tsp!,{%s}\n", reg_names[REGNO]))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_REG_POP
parameter_list|(
name|STREAM
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|(arm_increase_location (4)                                   \    , fprintf(STREAM,"\tldmfd\tsp!,{%s}\n", reg_names[REGNO]))
end_define

begin_comment
comment|/* Output a relative address. Not needed since jump tables are absolute    but we must define it anyway.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fputs ("- - - ASM_OUTPUT_ADDR_DIFF_ELT called!\n", STREAM)
end_define

begin_comment
comment|/* Output an element of a dispatch table.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(arm_increase_location (4)                     \    , fprintf (STREAM, "\t.word\tL%d\n", VALUE))
end_define

begin_comment
comment|/* Output various types of constants.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(arm_increase_location (sizeof (double))        \    , fprintf (STREAM, "\t.double\t%20.20f\n", VALUE))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(arm_increase_location (sizeof (float))        \    , fprintf (STREAM, "\t.float\t%20.20f\n", VALUE))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_INT
parameter_list|(
name|STREAM
parameter_list|,
name|EXP
parameter_list|)
define|\
value|(fprintf (STREAM, "\t.word\t"),      \    output_addr_const (STREAM, (EXP)),  \    arm_increase_location (4),          \    fputc ('\n', STREAM))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_SHORT
parameter_list|(
name|STREAM
parameter_list|,
name|EXP
parameter_list|)
define|\
value|(fprintf (STREAM, "\t.short\t"),     \    output_addr_const (STREAM, (EXP)),  \    arm_increase_location (2),          \    fputc ('\n', STREAM))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_CHAR
parameter_list|(
name|STREAM
parameter_list|,
name|EXP
parameter_list|)
define|\
value|(fprintf (STREAM, "\t.byte\t"),      \    output_addr_const (STREAM, (EXP)),  \    arm_increase_location (1),          \    fputc ('\n', STREAM))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_BYTE
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|(fprintf (STREAM, "\t.byte\t%d\n", VALUE),  \    arm_increase_location (1))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|STREAM
parameter_list|,
name|PTR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|output_ascii_pseudo_op ((STREAM), (PTR), (LEN))
end_define

begin_comment
comment|/* Output a gap.  In fact we fill it with nulls.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|STREAM
parameter_list|,
name|NBYTES
parameter_list|)
define|\
value|(arm_increase_location (NBYTES),              \    fprintf (STREAM, "\t.space\t%d\n", NBYTES))
end_define

begin_comment
comment|/* Align output to a power of two.  Horrible /bin/as.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|POWER
parameter_list|)
define|\
value|do                                                           \     {                                                          \       register int amount = 1<< (POWER);                      \       extern int arm_text_location;			       \                                                                \       if (amount == 2)                                         \ 	fprintf (STREAM, "\t.even\n");                         \       else                                                     \ 	fprintf (STREAM, "\t.align\t%d\n", amount - 4);        \                                                                \       if (in_text_section ())                                  \ 	arm_text_location = ((arm_text_location + amount - 1)  \& ~(amount - 1));                 \     } while (0)
end_define

begin_comment
comment|/* Output a common block */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|(fprintf (STREAM, "\t.comm\t"), 		     \    assemble_name ((STREAM), (NAME)),		     \    fprintf(STREAM, ", %d\t@%d\n", ROUNDED, SIZE))
end_define

begin_comment
comment|/* Output a local common block.  /bin/as can't do this, so hack a `.space' into    the bss segment.  Note that this is *bad* practice.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|output_lcomm_directive (STREAM, NAME, SIZE, ROUNDED)
end_define

begin_comment
comment|/* Output a source filename for the debugger. RISCiX dbx insists that the    ``desc'' field is set to compiler version number>= 315 (sic).  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (STREAM, "\t.stabs\t\"%s\", %d, 0, 315, Ltext\n", (NAME), N_SOL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output a source line for the debugger.  */
end_comment

begin_comment
comment|/* #define ASM_OUTPUT_SOURCE_LINE(STREAM,LINE) */
end_comment

begin_comment
comment|/* Output a #ident directive.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|STREAM
parameter_list|,
name|STRING
parameter_list|)
define|\
value|fprintf (STREAM,"- - - ident %s\n",STRING)
end_define

begin_comment
comment|/* The assembler's parentheses characters.  */
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
comment|/* Target characters.  */
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

begin_escape
end_escape

begin_comment
comment|/* FINAL_PRESCAN_INSN is used to take a look at the insns, in order to delete    small-distance conditional branches and have ASM_OUTPUT_OPCODE make the    instructions conditional.  Suffixes like s (affect flags) and b (bytewise    load/store) need to stay suffixes, so the possible condition code comes    before these suffixes.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_OPCODE
parameter_list|(
name|STREAM
parameter_list|,
name|PTR
parameter_list|)
define|\
value|{					        		      \     extern int arm_ccfsm_state, arm_current_cc;			      \     extern char *arm_condition_codes[];				      \     int i;							      \ 								      \     fflush (STREAM);
comment|/* XXX for debugging only.  */
value|\     if (arm_ccfsm_state == 1 || arm_ccfsm_state == 2)   	      \       {				                        	      \ 	fprintf (STREAM, "@ \t");				      \ 	arm_ccfsm_state += 2;		        		      \       }					        		             \     else if (arm_ccfsm_state == 3 || arm_ccfsm_state == 4)	             \       {					        		             \ 	for (i = 0; *(PTR) != ' '&& *(PTR) != '\t'&& i< 3; i++, (PTR)++)  \ 	  putc (*(PTR), STREAM);	        		             \ 	fprintf (STREAM, "%s", arm_condition_codes[arm_current_cc]);         \ 	for (; *(PTR) != ' '&& *(PTR) != '\t'; (PTR)++)		     \ 	  putc (*(PTR), STREAM);					     \       }								             \   }
end_define

begin_comment
comment|/* Only perform branch elimination (by making instructions conditional) if    we're optimising.  Otherwise it's of no use anyway.  */
end_comment

begin_define
define|#
directive|define
name|FINAL_PRESCAN_INSN
parameter_list|(
name|INSN
parameter_list|,
name|OPVEC
parameter_list|,
name|NOPERANDS
parameter_list|)
define|\
value|if (optimize)					    \     final_prescan_insn (INSN, OPVEC, NOPERANDS)
end_define

begin_comment
comment|/* Output an operand of an instruction.  If X is a REG and CODE is `M', output    a ldm/stm style multi-reg.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND
parameter_list|(
name|STREAM
parameter_list|,
name|X
parameter_list|,
name|CODE
parameter_list|)
define|\
value|{					        		\   if ((CODE) == 'R')			        		\     fputs (reg_names[REGNO (X) + 1], (STREAM));			\   else if (GET_CODE (X) == REG)		        		\     {					        		\       if ((CODE) != 'M')					\ 	fputs (reg_names[REGNO (X)], (STREAM));			\       else				        		\ 	fprintf ((STREAM), "{%s-%s}",	        		\ 		 reg_names[REGNO (X)],	        		\ 		 reg_names[REGNO (X) - 1        		\ 			   + ((GET_MODE_SIZE (GET_MODE (X))	\ 			       + GET_MODE_SIZE (SImode) - 1)	\ 			      / GET_MODE_SIZE (SImode))]);	\     }								\   else if (GET_CODE (X) == MEM)					\     {								\       extern int output_memory_reference_mode;			\       output_memory_reference_mode = GET_MODE (X);		\       output_address (XEXP (X, 0));				\     }								\   else if (GET_CODE(X) == CONST_DOUBLE)				\     {								\       union real_extract u;					\       u.i[0] = CONST_DOUBLE_LOW (X);				\       u.i[1] = CONST_DOUBLE_HIGH (X);				\       fprintf(STREAM,"#%20.20f",u.d);				\     }								\   else if (GET_CODE (X) == NEG)					\     {								\       fputc ('-', (STREAM));					\       output_operand ((X), 0);					\     }								\   else								\     {								\       fputc('#', STREAM);					\       output_addr_const(STREAM, X);				\     }								\ }
end_define

begin_comment
comment|/* Output the address of an operand.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_ADDRESS
parameter_list|(
name|STREAM
parameter_list|,
name|X
parameter_list|)
define|\
value|{									\     int is_minus = GET_CODE (X) == MINUS;				\ 									\     if (GET_CODE (X) == REG)						\ 	fprintf (STREAM, "[%s, #0]", reg_names[REGNO (X)]);		\     else if (GET_CODE (X) == PLUS || is_minus)				\       {									\ 	rtx base = XEXP (X, 0);						\ 	rtx index = XEXP (X, 1);					\ 	char *base_reg_name;						\ 	int offset = 0; 						\ 	int shift;							\ 	if (GET_CODE (base) != REG)					\ 	  {								\
comment|/* Ensure that BASE is a register (one of them must be). */
value|\ 	    rtx temp = base;						\ 	    base = index;						\ 	    index = temp;						\ 	  }								\ 	base_reg_name = reg_names[REGNO (base)];			\ 	switch (GET_CODE (index))					\ 	  {								\ 	  case CONST_INT:						\ 	    offset = INTVAL (index);					\ 	    if (is_minus)						\ 	      offset = -offset;						\ 	    fprintf (STREAM, "[%s, #%d]", base_reg_name, offset);	\ 	    break;							\ 									\ 	  case REG:							\ 	    fprintf (STREAM, "[%s, %s%s]", base_reg_name,		\ 		     is_minus ? "-" : "", reg_names[REGNO (index)] );	\ 	    break;							\ 									\ 	  case MULT:							\ 	    if (GET_CODE (XEXP (index,0)) == CONST_INT)			\ 	      {								\ 		shift = int_log2 (INTVAL (XEXP (index, 0)));		\ 		index = XEXP (index, 1);				\ 	      }								\ 	    else if (GET_CODE(XEXP(index,1)) == CONST_INT)		\ 	      {								\ 		shift = int_log2 (INTVAL (XEXP (index, 1)));		\ 		index = XEXP (index, 0);				\ 	      }								\ 	    else							\ 		abort();						\ 	    fprintf (STREAM, "[%s, %s%s, asl#%d]", base_reg_name,	\ 		     is_minus ? "-" : "", reg_names[REGNO (index)],	\ 		     shift);						\ 	    break;							\ 	    								\ 	  default:							\ 	    abort();							\ 	}								\     }							        	\   else if (GET_CODE (X) == PRE_INC || GET_CODE (X) == POST_INC		\ 	   || GET_CODE (X) == PRE_DEC || GET_CODE (X) == POST_DEC)	\     {									\       extern int output_memory_reference_mode;				\       									\       if (GET_CODE (XEXP (X, 0)) != REG)				\ 	abort ();							\ 									\       if (GET_CODE (X) == PRE_DEC || GET_CODE (X) == PRE_INC)		\ 	fprintf (STREAM, "[%s, #%s%d]!", reg_names[REGNO (XEXP (X, 0))],\ 		 GET_CODE (X) == PRE_DEC ? "-" : "",			\ 		 GET_MODE_SIZE (output_memory_reference_mode));		\       else								\ 	fprintf (STREAM, "[%s], #%s%d", reg_names[REGNO (XEXP (X, 0))],	\ 		 GET_CODE (X) == POST_DEC ? "-" : "",			\ 		 GET_MODE_SIZE (output_memory_reference_mode));		\     }									\   else output_addr_const(STREAM, X);					\ }
end_define

begin_comment
comment|/* EOF arm.h */
end_comment

end_unit

