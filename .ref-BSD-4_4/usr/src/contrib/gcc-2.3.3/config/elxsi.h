begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Elxsi version.    Copyright (C) 1987, 1988, 1992 Free Software Foundation, Inc.    This port, done by Mike Stump<mrs@cygnus.com> in 1988, and is the first    64 bit port of GNU CC.    Based upon the VAX port.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Delxsi -Dunix"
end_define

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (elxsi)");
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
comment|/* Macros used in the machine description to test the flags.  */
end_comment

begin_comment
comment|/* Nonzero if compiling code that Unix assembler can assemble.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_UNIX_ASM
value|(target_flags& 1)
end_define

begin_comment
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ {"unix", 1},  \     {"embos", -1},  \     { "", TARGET_DEFAULT}}
end_define

begin_comment
comment|/* Default target_flags if no switches specified.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Target machine storage layout */
end_comment

begin_comment
comment|/* Define this if most significant bit is lowest numbered    in instructions that operate on numbered bit-fields.    This is not true on the vax.  */
end_comment

begin_comment
comment|/* #define BITS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Define this if most significant word of a multiword number is numbered.  */
end_comment

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
value|1
end_define

begin_comment
comment|/* Number of bits in an addressible storage unit */
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
value|64
end_define

begin_define
define|#
directive|define
name|Rmode
value|DImode
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
value|32
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
comment|/* Width of a word, in units (bytes).  */
end_comment

begin_define
define|#
directive|define
name|UNITS_PER_WORD
value|8
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
comment|/* Allocation boundary (in *bits*) for storing pointers in memory.  */
end_comment

begin_define
define|#
directive|define
name|POINTER_BOUNDARY
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
comment|/* Allocation boundary (in *bits*) for the code of a function.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_BOUNDARY
value|8
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure.  */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|8
end_define

begin_comment
comment|/* Every structure's size must be a multiple of this.  */
end_comment

begin_define
define|#
directive|define
name|STRUCTURE_SIZE_BOUNDARY
value|32
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
value|32
end_define

begin_comment
comment|/* Define this if move instructions will actually fail to work    when given unaligned data.  */
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
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.  */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|16
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the elxsi, these is the .r15 (aka .sp).  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
value|{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
end_define

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
value|{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1}
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.    On the vax, all registers are one word long.  */
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
value|((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD)
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE. */
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
value|1
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
value|1
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
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

begin_define
define|#
directive|define
name|INITIAL_FRAME_POINTER_OFFSET
parameter_list|(
name|DEPTH
parameter_list|)
define|\
value|{ int regno;							\   int offset = 0;						\   for( regno=0; regno< FIRST_PSEUDO_REGISTER;  regno++ )	\     if( regs_ever_live[regno]&& !call_used_regs[regno] )	\       offset += 8;						\   (DEPTH) = (offset + ((get_frame_size() + 3)& ~3) );		\   (DEPTH) = 0;							\ }
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
value|0
end_define

begin_comment
comment|/* Register in which address to store a structure value    is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_REGNUM
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_comment
comment|/* The vax has only one kind of registers, so NO_REGS and ALL_REGS    are the only classes.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
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
value|{"NO_REGS", "GENERAL_REGS", "ALL_REGS" }
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
value|{0, 0x07fff, 0xffff}
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
value|(REGNO == 15 ? ALL_REGS : GENERAL_REGS)
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
value|NO_REGS
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.  */
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
value|((C) == 'I' ? (VALUE)>=-16&& (VALUE)<=15 : 0)
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
value|1
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
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On the vax, this is always the size of MODE in words,    since all registers are the same size.  */
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
value|-4
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
comment|/* Value is 1 if returning from a function call automatically    pops the arguments described by the number-of-args field in the call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.     On the Vax, the RET insn always pops all the args for any function.  */
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
comment|/* On the Vax the return value is in R0 regardless.  */
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
comment|/* On the Vax the return value is in R0 regardless.  */
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
comment|/* Define this if PCC uses the nonreentrant convention for returning    structure and union values.  */
end_comment

begin_define
define|#
directive|define
name|PCC_STATIC_STRUCT_RETURN
end_define

begin_comment
comment|/* 1 if N is a possible register number for a function value.    On the Vax, R0 is the only register thus used.  */
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
comment|/* 1 if N is a possible register number for function argument passing.    On the Vax, no registers are used in this way.  */
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
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the vax, this is a single integer, which is a number of bytes    of arguments scanned so far.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.     On the vax, the offset starts at 0.  */
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
name|x
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
comment|/* On the vax all args are pushed.  */
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
define|\
value|{ register int regno;							\   register int cnt = 0;							\   extern char call_used_regs[];						\
comment|/* the below two lines are a HACK, and should be deleted, but 	\      for now are very much needed (1.35) */
value|\   if (frame_pointer_needed)						\     regs_ever_live[14]=1, call_used_regs[14]=0;				\   for (regno = 0; regno< FIRST_PSEUDO_REGISTER; regno++)		\     if (regs_ever_live[regno]&& !call_used_regs[regno])		\ 	cnt+=8;								\   if ((SIZE)+cnt)							\     fprintf (FILE, "\tadd.64\t.sp,=%d\n", -(SIZE)-cnt);			\   cnt = 0;								\   for (regno = 0; regno< FIRST_PSEUDO_REGISTER; regno++)		\     if (regs_ever_live[regno]&& !call_used_regs[regno])		\       fprintf (FILE, "\tst.64\t.r%d,[.sp]%d\n", regno, (cnt+=8)-12); 	\   if (frame_pointer_needed)						\     fprintf (FILE, "\tadd.64\t.r14,.sp,=%d\n", (SIZE)+cnt);		\ }
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
value|fprintf (FILE, "\tld.64\t.r0,.LP%d\n\tcall\tmcount\n", (LABELNO));
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|0
end_define

begin_comment
comment|/* This macro generates the assembly code for function exit,    on machines that need it.  If FUNCTION_EPILOGUE is not defined    then individual return instructions are generated for each    return statement.  Args are same as for FUNCTION_PROLOGUE.  */
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
value|{ register int regno;							\   register int cnt = 0;							\   extern char call_used_regs[];						\   extern int current_function_calls_alloca;						\
comment|/* this conditional is ONLY here because there is a BUG;		\ 	     EXIT_IGNORE_STACK is ignored itself when the first part of		\ 	     the condition is true! (atleast in version 1.35) */
value|\
comment|/* the 8*10 is for 64 bits of .r5 - .r14 */
value|\   if (current_function_calls_alloca || (SIZE)>=(256-8*10)) {		\
comment|/* use .r4 as a temporary! Ok for now.... */
value|\     fprintf (FILE, "\tld.64\t.r4,.r14\n");				\     for (regno = FIRST_PSEUDO_REGISTER-1; regno>= 0; --regno)		\       if (regs_ever_live[regno]&& !call_used_regs[regno])		\        	cnt+=8;								\     for (regno = 0; regno< FIRST_PSEUDO_REGISTER; ++regno)		\       if (regs_ever_live[regno]&& !call_used_regs[regno])		\        fprintf (FILE, "\tld.64\t.r%d,[.r14]%d\n", regno,		\ 		-((cnt-=8) + 8)-4-(SIZE));				\     fprintf (FILE, "\tld.64\t.sp,.r4\n\texit\t0\n");			\   } else {								\     for (regno = 0; regno< FIRST_PSEUDO_REGISTER; ++regno)		\       if (regs_ever_live[regno]&& !call_used_regs[regno])		\          fprintf (FILE, "\tld.64\t.r%d,[.sp]%d\n", regno, (cnt+=8)-12);	\     fprintf (FILE, "\texit\t%d\n", (SIZE)+cnt);				\   } }
end_define

begin_comment
comment|/* If the memory address ADDR is relative to the frame pointer,    correct it to be relative to the stack pointer instead.    This is for when we don't use a frame pointer.    ADDR should be a variable name.  */
end_comment

begin_define
define|#
directive|define
name|FIX_FRAME_POINTER_ADDRESS
parameter_list|(
name|ADDR
parameter_list|,
name|DEPTH
parameter_list|)
define|\
value|{ int offset = -1;							\   rtx regs = stack_pointer_rtx;						\   if (ADDR == frame_pointer_rtx)					\     offset = 0;								\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 1) == frame_pointer_rtx \&& GET_CODE (XEXP (ADDR, 0)) == CONST_INT)			\     offset = INTVAL (XEXP (ADDR, 0));					\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 0) == frame_pointer_rtx \&& GET_CODE (XEXP (ADDR, 1)) == CONST_INT)			\     offset = INTVAL (XEXP (ADDR, 1));					\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 0) == frame_pointer_rtx) \     { rtx other_reg = XEXP (ADDR, 1);					\       offset = 0;							\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 1) == frame_pointer_rtx) \     { rtx other_reg = XEXP (ADDR, 0);					\       offset = 0;							\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   if (offset>= 0)							\     { int regno;							\       extern char call_used_regs[];					\       offset += 4;
comment|/* I don't know why??? */
value|\       for (regno = 0; regno< FIRST_PSEUDO_REGISTER; regno++)		\         if (regs_ever_live[regno]&& ! call_used_regs[regno])		\           offset += 8;							\       ADDR = plus_constant (regs, offset + (DEPTH)); } }
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
name|regno
parameter_list|)
define|\
value|((regno)< FIRST_PSEUDO_REGISTER || reg_renumber[regno]>= 0)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|regno
parameter_list|)
define|\
value|((regno)< FIRST_PSEUDO_REGISTER || reg_renumber[regno]>= 0)
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
comment|/* 1 if X is an rtx for a constant that is a valid address.  */
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
define|\
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
value|1
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
value|1
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
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     CONSTANT_ADDRESS_P is actually machine-independent.  */
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
value|{ 									\   if (GET_CODE (X) == REG) goto ADDR;					\   if (CONSTANT_ADDRESS_P (X)) goto ADDR; 				\   if (GET_CODE (X) == PLUS)						\     {									\
comment|/* Handle [index]<address> represented with index-sum outermost */
value|\       if (GET_CODE (XEXP (X, 0)) == REG					\&& REG_OK_FOR_BASE_P (XEXP (X, 0))				\&& GET_CODE (XEXP (X, 1)) == CONST_INT)			\ 	goto ADDR;							\       if (GET_CODE (XEXP (X, 1)) == REG					\&& REG_OK_FOR_BASE_P (XEXP (X, 0))				\&& GET_CODE (XEXP (X, 0)) == CONST_INT)			\ 	goto ADDR;							\     }									\  }
end_define

begin_escape
end_escape

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     For the vax, nothing needs to be done.  */
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
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for. */
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
comment|/* Define this if the case instruction expects the table    to contain offsets from the address of the table.    Do not define this if the table should contain absolute addresses.  */
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
comment|/* This flag, if defined, says the same insns that convert to a signed fixnum    also convert validly to an unsigned one.  */
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
value|8
end_define

begin_comment
comment|/* Define this if zero-extension is slow (more than one real instruction).  */
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
comment|/* Define if shifts truncate the shift count    which implies one can omit a sign-extension or zero-extension    of a shift count.  */
end_comment

begin_comment
comment|/* #define SHIFT_COUNT_TRUNCATED */
end_comment

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
comment|/*  * We can use the BSD C library routines for the gnulib calls that are  * still generated, since that's what they boil down to anyways.  */
end_comment

begin_comment
comment|/* #define UDIVSI3_LIBCALL "*udiv" */
end_comment

begin_comment
comment|/* #define UMODSI3_LIBCALL "*urem" */
end_comment

begin_comment
comment|/* Check a `double' value for validity for a particular machine mode.  */
end_comment

begin_comment
comment|/* note that it is very hard to accidently create a number that fits in a    double but not in a float, since their ranges are almost the same */
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

begin_escape
end_escape

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.  */
end_comment

begin_comment
comment|/* Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').  No extra ones are needed for the vax.  */
end_comment

begin_comment
comment|/* Store in cc_status the expressions    that the condition codes will describe    after execution of an instruction whose pattern is EXP.    Do not alter them if the instruction would not alter the cc's.  */
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
value|CC_STATUS_INIT;
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_comment
comment|/* Output the name of the file we are compiling.  */
end_comment

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
value|fprintf(STREAM, "\t.file\t\"%s\"\n", NAME);
end_define

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
value|fprintf (FILE, "");
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
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|"\t.inst"
end_define

begin_comment
comment|/* Output before writable data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|"\t.var"
end_define

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{".r0", ".r1", ".r2", ".r3", ".r4", ".r5", ".r6", ".r7", ".r8", \  ".r9", ".r10", ".r11", ".r12", ".r13", ".r14", ".sp"}
end_define

begin_comment
comment|/* This is BSD, so it wants DBX format.  */
end_comment

begin_comment
comment|/* #define DBX_DEBUGGING_INFO */
end_comment

begin_comment
comment|/* How to renumber registers for dbx and gdb.    Vax needs no change in the numeration.  */
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
comment|/* Do not break .stabs pseudos into continuations.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* This is the char to use for continuation (in case we need to turn    continuation back on).  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_CHAR
value|'?'
end_define

begin_comment
comment|/* Don't use the `xsfoo;' construct in DBX output; this system    doesn't support it.  */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
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
value|do { fputs ("\t.extdef\t", FILE); assemble_name (FILE, NAME); fputs ("\n", FILE);} while (0)
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.  */
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
value|fprintf (FILE, "%s", NAME)
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
value|fprintf (FILE, ".%s%d:\n", PREFIX, NUM)
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
value|sprintf (LABEL, ".%s%d", PREFIX, NUM)
end_define

begin_comment
comment|/* This is how to output an assembler line defining a `double' constant.    It is .dfloat or .gfloat, depending.  */
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
value|{ union {double d; int i[2]; } tem;				\   tem.d = (VALUE);						\   fprintf (FILE, "\t.data\t%d{32}, %d{32}\n", tem.i[0], tem.i[1]); }
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
value|{ union {float f; int i; } tem;					\   tem.f = (VALUE);						\   fprintf (FILE, "\t.data %d{32}\n", tem.i); }
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
value|( \ 	fprintf (FILE, "\t.data\t"),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "{32}\n"))
end_define

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
value|{								\ 	fprintf (FILE, "\t.data\t");				\ 	if (GET_CODE (VALUE) == CONST_DOUBLE)			\ 	{							\ 		fprintf (FILE, "%d", CONST_DOUBLE_HIGH (VALUE)); \ 		fprintf (FILE, "{32}, ");			\ 		fprintf (FILE, "%d", CONST_DOUBLE_LOW (VALUE)); \ 		fprintf (FILE, "{32}\n");			\ 	} else if (GET_CODE (VALUE) == CONST_INT)		\ 	{							\ 		int val = INTVAL (VALUE);			\ 		fprintf (FILE, "%d", val< 0 ? -1 : 0);		\ 		fprintf (FILE, "{32}, ");			\ 		fprintf (FILE, "%d", val);			\ 		fprintf (FILE, "{32}\n");			\ 	} else abort ();					\ }
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
value|( fprintf (FILE, "\t.data\t"),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "{16}\n"))
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
value|( fprintf (FILE, "\t.data\t"),			\   output_addr_const (FILE, (VALUE)),		\   fprintf (FILE, "{8}\n"))
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
value|fprintf (FILE, "\t.data\t%d{8}\n", (VALUE))
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
value|fprintf (FILE, "\tsubi.64\t4,.sp\n\tst.32\t%s,[.sp]\n", reg_names[REGNO])
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
value|fprintf (FILE, "\tld.32\t%s,[.sp]\n\taddi.64\t4,.sp\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.    (The Vax does not use such vectors,    but we must define this macro anyway.)  */
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
value|fprintf (FILE, "\t.data .L%d{32}\n", VALUE)
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
value|fprintf (FILE, "\t.data .L%d-.L%d{32}\n", VALUE, REL)
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
value|if (LOG!=0) fprintf (FILE, "\t.align\t%d\n", (LOG)); else 0
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter by SIZE bytes.  */
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
value|( fputs (".comm ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%d\n", (ROUNDED)))
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
value|( fputs (".bss ", (FILE)),			\   assemble_name ((FILE), (NAME)),		\   fprintf ((FILE), ",%d,%d\n", (SIZE),(ROUNDED)))
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
comment|/* Print an instruction operand X on file FILE.    CODE is the code from the %-spec that requested printing this operand;    if `%z3' was used to print operand 3, then CODE is 'z'.  */
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
define|\
value|{ \   if (CODE == 'r'&& GET_CODE (X) == MEM&& GET_CODE (XEXP (X, 0)) == REG)							\     fprintf (FILE, "%s", reg_names[REGNO (XEXP (X, 0))]);		\   else if (GET_CODE (X) == REG)						\     fprintf (FILE, "%s", reg_names[REGNO (X)]);				\   else if (GET_CODE (X) == MEM)						\     output_address (XEXP (X, 0));					\   else \   { \
comment|/*debug_rtx(X);*/
value|\ 	putc ('=', FILE); \ 	output_addr_const (FILE, X); } \    }
end_define

begin_comment
comment|/* Print a memory operand whose address is X, on file FILE.    This uses a function in output-vax.c.  */
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
comment|/* Functions used in the md file. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|cmp_set
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|cmp_jmp
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* These are stubs, and have yet to bee written. */
end_comment

begin_define
define|#
directive|define
name|TRAMPOLINE_SIZE
value|26
end_define

begin_define
define|#
directive|define
name|TRAMPOLINE_TEMPLATE
parameter_list|(
name|FILE
parameter_list|)
end_define

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
end_define

end_unit

