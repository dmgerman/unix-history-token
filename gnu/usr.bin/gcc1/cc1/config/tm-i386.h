begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler for Intel 80386.    Copyright (C) 1988 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Note that some other tm- files include this one and then override    many of the definitions that relate to assembler syntax.  */
end_comment

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.  */
end_comment

begin_comment
comment|/* the file tm-compaq.h includes this file */
end_comment

begin_define
define|#
directive|define
name|I386
value|1
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
comment|/* Compile 80387 insns for floating point (not library calls).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_80387
value|(target_flags& 1)
end_define

begin_comment
comment|/* Compile using ret insn that pops args.    This will not work unless you use prototypes at least    for all functions that can take varying numbers of args.  */
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
comment|/* Macro to define tables used to set the flags.    This is a list in braces of pairs in braces,    each pair being { "NAME", VALUE }    where VALUE is the bits to set or minus the bits to clear.    An empty string NAME is used to identify the default VALUE.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_SWITCHES
define|\
value|{ { "80387", 1},				\     { "soft-float", -1},			\     { "rtd", 8},				\     { "nortd", -8},				\     { "regparm", 020},				\     { "noregparm", -020},			\     { "", TARGET_DEFAULT}}
end_define

begin_comment
comment|/* TARGET_DEFAULT is defined in tm-compaq.h, etc.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* target machine storage layout */
end_comment

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_comment
comment|/* That is true on the 80386.  */
end_comment

begin_comment
comment|/* #define BITS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Define this if most significant byte of a word is the lowest numbered.  */
end_comment

begin_comment
comment|/* That is not true on the 80386.  */
end_comment

begin_comment
comment|/* #define BYTES_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Define this if most significant word of a multiword number is numbered.  */
end_comment

begin_comment
comment|/* Not true for 80386 */
end_comment

begin_comment
comment|/* #define WORDS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* number of bits in an addressible storage unit */
end_comment

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_comment
comment|/* Width in bits of a "word", which is the contents of a machine register.    Note that this is not necessarily the width of data type `int';    if using 16-bit ints on a 80386, this would still be 32.    But on a machine with 16-bit registers, this would be 16.  */
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
value|32
end_define

begin_comment
comment|/* Alignment of field after `int : 0' in a structure. */
end_comment

begin_define
define|#
directive|define
name|EMPTY_FIELD_BOUNDARY
value|32
end_define

begin_comment
comment|/* There is no point aligning anything to a rounder boundary than this. */
end_comment

begin_comment
comment|/* Some structures in the ATT libraries are assumed to round up from 16 to 18    bytes, for example the _io_buf */
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

begin_comment
comment|/* #define STRICT_ALIGNMENT */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Standard register usage.  */
end_comment

begin_comment
comment|/* Number of actual hardware registers.    The hardware registers are assigned numbers for the compiler    from 0 to just below FIRST_PSEUDO_REGISTER.    All registers that the compiler knows about must be given numbers,    even those that are not normally considered general registers.    In the 80387 we give the 8 general purpose registers the numbers 0-7,    we assign 6 numbers for floating point registers 8-13,    Note that registers 0-7 can be accessed as a  short or int,    while only 0-3 may be used with mov byte instructions. */
end_comment

begin_define
define|#
directive|define
name|FIRST_PSEUDO_REGISTER
value|10
end_define

begin_comment
comment|/* 1 for registers that have pervasive standard uses    and are not available for the register allocator.    On the 80386, only the stack pointer is such.  */
end_comment

begin_define
define|#
directive|define
name|FIXED_REGISTERS
define|\
comment|/*ax,ad,ac,ab,si,di,bp,sp,fval,fp0*/
define|\
value|{  0, 0, 0, 0, 0, 0, 0, 1, 1, 0}
end_define

begin_comment
comment|/* ;;change-wfs */
end_comment

begin_comment
comment|/* 1 for registers not available across function calls.    These must include the FIXED_REGISTERS and also any    registers that can be used without being saved.    The latter must include the registers where values are returned    and the register where structure-value addresses are passed.    Aside from that, you can include as many other registers as you like.  */
end_comment

begin_define
define|#
directive|define
name|CALL_USED_REGISTERS
define|\
comment|/*ax,ad,ac,ab,si,di,bp,sp,*/
define|\
value|{  1, 1, 1, 0, 0, 0, 0, 1,  \    1, 1}
end_define

begin_comment
comment|/* Return number of consecutive hard regs needed starting at reg REGNO    to hold something of mode MODE.    This is ordinarily the length in words of a value of mode MODE    but can be less for certain modes in special long registers.     Actually there are no two word move instructions for consecutive     registers.  And only registers 0-3 may have mov byte instructions    applied to them.    */
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
value|((REGNO)>= 8 ? 1				\    : ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
end_define

begin_comment
comment|/* Value is 1 if hard register REGNO can hold a value of machine-mode MODE.    On the 80386, the first 4 cpu registers can hold any mode.    While the floating point registers may hold SFmode or DFmode only.    */
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
value|hard_regno_mode_ok(REGNO,MODE)
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
value|((MODE1) == (MODE2))
end_define

begin_comment
comment|/* Specify the registers used for certain standard purposes.    The values of these macros are register numbers.  */
end_comment

begin_comment
comment|/* on the 386 the pc register is %eip, and is not usable as a general    register.  The ordinary mov instructions won't work */
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
value|7
end_define

begin_comment
comment|/* Base register for access to local variables of the function.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_POINTER_REGNUM
value|6
end_define

begin_comment
comment|/* First floating point reg */
end_comment

begin_define
define|#
directive|define
name|FIRST_FLOAT_REG
value|8
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
value|6
end_define

begin_comment
comment|/* Register in which static-chain is passed to a function.  */
end_comment

begin_define
define|#
directive|define
name|STATIC_CHAIN_REGNUM
value|2
end_define

begin_comment
comment|/* Register in which address to store a structure value    arrives in the function.  On the 386, the prologue    copies this from the stack to register %eax.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE_INCOMING
define|\
value|gen_rtx (MEM, Pmode, gen_rtx (PLUS, Pmode, frame_pointer_rtx,	\ 				 gen_rtx (CONST_INT, VOIDmode, 8)))
end_define

begin_comment
comment|/* Place in which caller passes the structure value address.    Actually, all that matters about this value is it its rtx_code:    MEM means push the value on the stack like an argument.  */
end_comment

begin_define
define|#
directive|define
name|STRUCT_VALUE
define|\
value|gen_rtx (MEM, Pmode, gen_rtx (PRE_DEC, Pmode, stack_pointer_rtx))
end_define

begin_escape
end_escape

begin_comment
comment|/* Define the classes of registers for register constraints in the    machine description.  Also define ranges of constants.     One of the classes must always be named ALL_REGS and include all hard regs.    If there is more than one class, another class must be named NO_REGS    and contain no registers.     The name GENERAL_REGS must be the name of a class (or an alias for    another name such as ALL_REGS).  This is the class of registers    that is allowed by "g" or "r" in a register constraint.    Also, registers outside this class are allocated only when    instructions express preferences for them.     The classes must be numbered in nondecreasing order; that is,    a larger-numbered class must never be contained completely    in a smaller-numbered class.     For any two classes, it is very desirable that there be another    class that represents their union.  */
end_comment

begin_enum
enum|enum
name|reg_class
block|{
name|NO_REGS
block|,
name|AREG
block|,
name|DREG
block|,
name|ADREG
block|,
name|CREG
block|,
name|BREG
block|,
name|Q_REGS
block|,
name|SIREG
block|,
name|DIREG
block|,
name|INDEX_REGS
block|,
name|GENERAL_REGS
block|,
name|FLOAT_REGS
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
value|{  "NO_REGS", "AREG", "DREG", "ADREG", "CREG", "BREG","Q_REGS", \    "SIREG", "DIREG",						\    "INDEX_REGS", "GENERAL_REGS", "FLOAT_REGS", "ALL_REGS"}
end_define

begin_comment
comment|/* Define which registers fit in which classes.    This is an initializer for a vector of HARD_REG_SET    of length N_REG_CLASSES.  */
end_comment

begin_define
define|#
directive|define
name|REG_CLASS_CONTENTS
value|{0, 0x1, 0x2, 0x3, 0x4, 0x8, 0xf,\ 			    0x10, 0x20, 0x7f, 0xff, 0x300, 0x3ff}
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
value|((REGNO) == 0 ? AREG : \   (REGNO) == 1 ? DREG : \   (REGNO) == 2 ? CREG : \   (REGNO) == 3 ? BREG : \   (REGNO) == 4 ? SIREG : \   (REGNO) == 5 ? DIREG : \   (REGNO) == 7 ? GENERAL_REGS : \   (REGNO)< 8 ? INDEX_REGS : \   FLOAT_REGS)
end_define

begin_define
define|#
directive|define
name|NON_QI_REG_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REG_P (X)&& REGNO (X)>= 4&& REGNO (X)< FIRST_PSEUDO_REGISTER)
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
name|FP_REGNO_P
parameter_list|(
name|n
parameter_list|)
value|((n)>= FIRST_FLOAT_REG&& (n)< FIRST_PSEUDO_REGISTER)
end_define

begin_comment
comment|/* Try to maintain the accuracy of the death notes for regs satisfying the    following.  Important for stack like regs, to know when to pop. */
end_comment

begin_define
define|#
directive|define
name|PRESERVE_DEATH_INFO_REGNO_P
parameter_list|(
name|x
parameter_list|)
value|FP_REGNO_P(x)
end_define

begin_comment
comment|/* 1 if register REGNO can magically overlap other regs.    Note that nonzero values work only in very special circumstances.    We return 1 for an FP reg because "both" our FP regs    are really the same reg.  */
end_comment

begin_define
define|#
directive|define
name|OVERLAPPING_REGNO_P
parameter_list|(
name|REGNO
parameter_list|)
value|FP_REGNO_P (REGNO)
end_define

begin_comment
comment|/* The class value for index registers, and the one for base regs.  */
end_comment

begin_define
define|#
directive|define
name|INDEX_REG_CLASS
value|INDEX_REGS
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
value|((C) == 'r' ? GENERAL_REGS :			\    (C) == 'q' ? Q_REGS :			\    (C) == 'f' ? FLOAT_REGS :			\    (C) == 'a' ? AREG : (C) == 'b' ? BREG :	\    (C) == 'c' ? CREG : (C) == 'd' ? DREG :	\    (C) == 'A' ? ADREG :				\    (C) == 'S' ? SIREG :				\    (C) == 'D' ? DIREG : NO_REGS)
end_define

begin_comment
comment|/* The letters I, J, K, L and M in a register constraint string    can be used to stand for particular ranges of immediate operands.    This macro defines what the ranges are.    C is the letter, and VALUE is a constant value.    Return 1 if VALUE is in the range specified by C.     I is for the maximum shifts.     */
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
value|((C) == 'I' ? (VALUE)>= 0&& (VALUE)<= 31 :0)
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
value|((C) == 'G' ? ! (TARGET_80387&& standard_80387_constant_p (VALUE)) : 1)
end_define

begin_comment
comment|/* Given an rtx X being reloaded into a reg required to be    in class CLASS, return the class of reg to actually use.    In general this is just CLASS; but on some machines    in some cases it is preferable to use a more restrictive class.    On the 80386 series, we prevent floating constants from being    reloaded into floating registers (since no move-insn can do that)    and we ensure that QImodes aren't reloaded into the esi or edi reg.  */
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
value|(GET_CODE (X) == CONST_DOUBLE				\    ? ((CLASS) == GENERAL_REGS || (CLASS) == ALL_REGS	\       ? GENERAL_REGS : NO_REGS)				\    : GET_MODE (X) == QImode				\    ? ((CLASS) == GENERAL_REGS || (CLASS) == ALL_REGS	\       ? Q_REGS						\       : (CLASS) == INDEX_REGS ? (abort (), INDEX_REGS)	\       : (CLASS))					\    : (CLASS))
end_define

begin_comment
comment|/* Return the maximum number of consecutive registers    needed to represent mode MODE in a register of class CLASS.  */
end_comment

begin_comment
comment|/* On the 80386, this is the size of MODE in words,    except in the FP regs, where a single reg is always enough.  */
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
value|((CLASS) == FLOAT_REGS ? 1 :			\    ((GET_MODE_SIZE (MODE) + UNITS_PER_WORD - 1) / UNITS_PER_WORD))
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
value|0
end_define

begin_comment
comment|/* If we generate an insn to push BYTES bytes,    this says how many the stack pointer really advances by.    On 386 pushw decrements by exactly 2 no matter what the position was.    On the 386 there is no pushb; we use pushw instead, and this    has the effect of rounding up to 2.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ROUNDING
parameter_list|(
name|BYTES
parameter_list|)
value|(((BYTES) + 1)& (-2))
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
comment|/* Value is 1 if returning from a function call automatically    pops the arguments described by the number-of-args field in the call.    FUNTYPE is the data type of the function (as a tree),    or for a library call it is an identifier node for the subroutine name.     On the 80386, the RTD insn may be used to pop them if the number      of args is fixed, but if the number is variable then the caller      must pop them all.  RTD can't be used for library calls now      because the library is compiled with the Unix compiler.    Use of RTD is a selectable option, since it is incompatible with    standard Unix calling sequences.  If the option is not selected,    the caller must always pop the args.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_POPS_ARGS
parameter_list|(
name|FUNTYPE
parameter_list|)
define|\
value|(TARGET_RTD&& TREE_CODE (FUNTYPE) != IDENTIFIER_NODE		\&& (TYPE_ARG_TYPES (FUNTYPE) == 0				\        || TREE_VALUE (tree_last (TYPE_ARG_TYPES (FUNTYPE))) == void_type_node))
end_define

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
value|gen_rtx (REG, TYPE_MODE (VALTYPE), \ 	    VALUE_REGNO(TYPE_MODE(VALTYPE)))
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
value|gen_rtx (REG, MODE, VALUE_REGNO(MODE))
end_define

begin_comment
comment|/* 1 if N is a possible register number for function argument passing.    On the 80386, no registers are used in this way.       *NOTE* -mregparm does not work.    It exists only to test register calling conventions.  */
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
comment|/* Define a data type for recording info about an argument list    during the scan of that argument list.  This data type should    hold all necessary information about the function itself    and about the args processed so far, enough to enable macros    such as FUNCTION_ARG to determine where the next arg should go.     On the 80386, this is a single integer, which is a number of bytes    of arguments scanned so far.  */
end_comment

begin_define
define|#
directive|define
name|CUMULATIVE_ARGS
value|int
end_define

begin_comment
comment|/* Initialize a variable CUM of type CUMULATIVE_ARGS    for a call to a function whose data type is FNTYPE.    For a library call, FNTYPE is 0.     On the 80386, the offset starts at 0.  */
end_comment

begin_define
define|#
directive|define
name|INIT_CUMULATIVE_ARGS
parameter_list|(
name|CUM
parameter_list|,
name|FNTYPE
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
comment|/* On the 80386 all args are pushed, except if -mregparm is specified    then the first two words of arguments are passed in EAX, EDX.    *NOTE* -mregparm does not work.    It exists only to test register calling conventions.  */
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
value|function_prologue (FILE, SIZE)
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
value|fprintf (FILE, "\tmovl $%sP%d,%%edx\n\tcall _mcount\n", LPREFIX, (LABELNO));
end_define

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.    No definition is equivalent to always zero.  */
end_comment

begin_comment
comment|/* Note on the 386 it might be more efficient not to define this since     we have to restore it ourselves from the frame pointer, in order to    use pop */
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
define|\
value|function_epilogue (FILE, SIZE)
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
value|{ int offset = -1;							\   rtx regs = stack_pointer_rtx;						\   if (ADDR == frame_pointer_rtx)					\     offset = 0;								\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 0) == frame_pointer_rtx \&& GET_CODE (XEXP (ADDR, 1)) == CONST_INT)			\     offset = INTVAL (XEXP (ADDR, 1));					\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 0) == frame_pointer_rtx) \     { rtx other_reg = XEXP (ADDR, 1);					\       offset = 0;							\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   else if (GET_CODE (ADDR) == PLUS&& XEXP (ADDR, 1) == frame_pointer_rtx) \     { rtx other_reg = XEXP (ADDR, 0);					\       offset = 0;							\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   else if (GET_CODE (ADDR) == PLUS					\&& GET_CODE (XEXP (ADDR, 0)) == PLUS				\&& XEXP (XEXP (ADDR, 0), 0) == frame_pointer_rtx		\&& GET_CODE (XEXP (ADDR, 1)) == CONST_INT)			\     { rtx other_reg = XEXP (XEXP (ADDR, 0), 1);				\       offset = INTVAL (XEXP (ADDR, 1));					\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   else if (GET_CODE (ADDR) == PLUS					\&& GET_CODE (XEXP (ADDR, 0)) == PLUS				\&& XEXP (XEXP (ADDR, 0), 1) == frame_pointer_rtx		\&& GET_CODE (XEXP (ADDR, 1)) == CONST_INT)			\     { rtx other_reg = XEXP (XEXP (ADDR, 0), 0);				\       offset = INTVAL (XEXP (ADDR, 1));					\       regs = gen_rtx (PLUS, Pmode, stack_pointer_rtx, other_reg); }	\   if (offset>= 0)							\     { int regno;							\       extern char call_used_regs[];					\       for (regno = FIRST_FLOAT_REG; regno< FIRST_PSEUDO_REGISTER; regno++)\ 	if (regs_ever_live[regno]&& ! call_used_regs[regno])		\ 	  offset += 8;							\       for (regno=0 ; regno<FIRST_FLOAT_REG ; regno++)   		\ 	if (regs_ever_live[regno]&& ! call_used_regs[regno])		\ 	  offset += 4;							\       offset -= 4;							\       ADDR = plus_constant (regs, offset + (DEPTH)); } }
end_define

begin_escape
unit|\
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
value|((REGNO)< STACK_POINTER_REGNUM || (unsigned) reg_renumber[REGNO]< STACK_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_BASE_P
parameter_list|(
name|REGNO
parameter_list|)
define|\
value|((REGNO)<= STACK_POINTER_REGNUM || (unsigned) reg_renumber[REGNO]<= STACK_POINTER_REGNUM)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_SIREG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO) == 4 || reg_renumber[REGNO] == 4)
end_define

begin_define
define|#
directive|define
name|REGNO_OK_FOR_DIREG_P
parameter_list|(
name|REGNO
parameter_list|)
value|((REGNO) == 5 || reg_renumber[REGNO] == 5)
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
comment|/* Nonzero if X is a hard reg that can be used as an index or if    it is a pseudo reg.  */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_INDEX_P
parameter_list|(
name|X
parameter_list|)
value|(REGNO (X)< STACK_POINTER_REGNUM || REGNO (X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_comment
comment|/* Nonzero if X is a hard reg that can be used as a base reg    of if it is a pseudo reg.  */
end_comment

begin_comment
comment|/* ?wfs */
end_comment

begin_define
define|#
directive|define
name|REG_OK_FOR_BASE_P
parameter_list|(
name|X
parameter_list|)
value|(REGNO (X)<= STACK_POINTER_REGNUM || REGNO(X)>= FIRST_PSEUDO_REGISTER)
end_define

begin_define
define|#
directive|define
name|REG_OK_FOR_STRREG_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO (X) == 4 || REGNO (X) == 5 || REGNO (X)>= FIRST_PSEUDO_REGISTER)
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
name|REG_OK_FOR_STRREG_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(REGNO_OK_FOR_DIREG_P (REGNO (X)) || REGNO_OK_FOR_SIREG_P (REGNO (X)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GO_IF_LEGITIMATE_ADDRESS recognizes an RTL expression    that is a valid memory address for an instruction.    The MODE argument is the machine mode for the MEM expression    that wants to use this address.     The other macros defined here are used only in GO_IF_LEGITIMATE_ADDRESS,    except for CONSTANT_ADDRESS_P which is usually machine-independent.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGS_PER_ADDRESS
value|2
end_define

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
value|if (GET_CODE (X) == REG&& REG_OK_FOR_BASE_P (X)) goto ADDR
end_define

begin_define
define|#
directive|define
name|LEGITIMATE_INDEX_REG_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(GET_CODE (X) == REG&& REG_OK_FOR_INDEX_P (X))
end_define

begin_comment
comment|/* Return 1 if X is an index or an index times a scale.  */
end_comment

begin_define
define|#
directive|define
name|LEGITIMATE_INDEX_P
parameter_list|(
name|X
parameter_list|)
define|\
value|(LEGITIMATE_INDEX_REG_P (X)				\     || (GET_CODE (X) == MULT				\&& LEGITIMATE_INDEX_REG_P (XEXP (X, 0))		\&& GET_CODE (XEXP (X, 1)) == CONST_INT		\&& (INTVAL (XEXP (X, 1)) == 2			\ 	    || INTVAL (XEXP (X, 1)) == 4		\ 	    || INTVAL (XEXP (X, 1)) == 8)))
end_define

begin_comment
comment|/* Go to ADDR if X is an index term, a base reg, or a sum of those.  */
end_comment

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
value|{ if (LEGITIMATE_INDEX_P (X)) goto ADDR;				\   GO_IF_INDEXABLE_BASE (X, ADDR);					\   if (GET_CODE (X) == PLUS&& LEGITIMATE_INDEX_P (XEXP (X, 0)))		\     { GO_IF_INDEXABLE_BASE (XEXP (X, 1), ADDR); }			\   if (GET_CODE (X) == PLUS&& LEGITIMATE_INDEX_P (XEXP (X, 1)))		\     { GO_IF_INDEXABLE_BASE (XEXP (X, 0), ADDR); } }
end_define

begin_comment
comment|/* We used to allow this, but it isn't ever used.    || ((GET_CODE (X) == POST_DEC || GET_CODE (X) == POST_INC)		\&& REG_P (XEXP (X, 0))						\&& REG_OK_FOR_STRREG_P (XEXP (X, 0)))				\ */
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
value|{ if (CONSTANT_ADDRESS_P (X)) goto ADDR;				\   GO_IF_INDEXING (X, ADDR);						\   if (GET_CODE (X) == PLUS)						\     { if (CONSTANT_ADDRESS_P (XEXP (X, 1)))				\ 	GO_IF_INDEXING (XEXP (X, 0), ADDR);				\       if (CONSTANT_ADDRESS_P (XEXP (X, 0)))				\ 	GO_IF_INDEXING (XEXP (X, 1), ADDR); } }
end_define

begin_comment
comment|/* Try machine-dependent ways of modifying an illegitimate address    to be legitimate.  If we find one, return the new, valid address.    This macro is used in only one place: `memory_address' in explow.c.     OLDX is the address as it was before break_out_memory_refs was called.    In some cases it is useful to look at this to decide what needs to be done.     MODE and WIN are passed so that this macro can use    GO_IF_LEGITIMATE_ADDRESS.     It is always safe for this macro to do nothing.  It exists to recognize    opportunities to optimize the output.     For the 80386, we handle X+REG by loading X into a register R and    using R+REG.  R will go in a general reg and indexing will be used.    However, if REG is a broken-out memory address or multiplication,    nothing needs to be done because REG can certainly go in a general reg.  */
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
value|{ register int ch = (X) != (OLDX);					\   if (GET_CODE (X) == PLUS)						\     { if (GET_CODE (XEXP (X, 0)) == MULT)				\ 	ch = 1, XEXP (X, 0) = force_operand (XEXP (X, 0), 0);		\       if (GET_CODE (XEXP (X, 1)) == MULT)				\ 	ch = 1, XEXP (X, 1) = force_operand (XEXP (X, 1), 0);		\       if (ch&& GET_CODE (XEXP (X, 1)) == REG				\&& GET_CODE (XEXP (X, 0)) == REG)				\ 	return X;							\       if (ch) { GO_IF_LEGITIMATE_ADDRESS (MODE, X, WIN); }		\       if (GET_CODE (XEXP (X, 0)) == REG                                 \ 	  || (GET_CODE (XEXP (X, 0)) == SIGN_EXTEND	        	\&& GET_CODE (XEXP (XEXP (X, 0), 0)) == REG		\&& GET_MODE (XEXP (XEXP (X, 0), 0)) == HImode))	\ 	{ register rtx temp = gen_reg_rtx (Pmode);			\ 	  register rtx val = force_operand (XEXP (X, 1), temp);		\ 	  if (val != temp) emit_move_insn (temp, val, 0);		\ 	  XEXP (X, 1) = temp;						\ 	  return X; }							\       else if (GET_CODE (XEXP (X, 1)) == REG				\ 	       || (GET_CODE (XEXP (X, 1)) == SIGN_EXTEND		\&& GET_CODE (XEXP (XEXP (X, 1), 0)) == REG		\&& GET_MODE (XEXP (XEXP (X, 1), 0)) == HImode))	\ 	{ register rtx temp = gen_reg_rtx (Pmode);			\ 	  register rtx val = force_operand (XEXP (X, 0), temp);		\ 	  if (val != temp) emit_move_insn (temp, val, 0);		\ 	  XEXP (X, 0) = temp;						\ 	  return X; }}}
end_define

begin_comment
comment|/* Go to LABEL if ADDR (a legitimate address expression)    has an effect that depends on the machine mode it is used for.    On the 80386, only postdecrement and postincrement address depend thus    (the amount of decrement or increment being the length of the operand).  */
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
value|if (GET_CODE (ADDR) == POST_INC || GET_CODE (ADDR) == POST_DEC) goto LABEL
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
value|Pmode
end_define

begin_comment
comment|/* Define this if the tablejump instruction expects the table    to contain offsets from the address of the table.    Do not define this if the table should contain absolute addresses.  */
end_comment

begin_comment
comment|/* #define CASE_VECTOR_PC_RELATIVE */
end_comment

begin_comment
comment|/* Specify the tree operation to be used to convert reals to integers.    This should be changed to take advantage of fist --wfs ??  */
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
value|4
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
comment|/* We assume that the store-condition-codes instructions store 0 for false    and some other value for true.  This is the value stored for true.  */
end_comment

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_comment
comment|/* When a prototype says `char' or `short', really pass an `int'.    (The 386 can't easily push less than an int.)  */
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
comment|/* Define this if addresses of constant functions    shouldn't be put through pseudo regs where they can be cse'd.    Desirable on the 386 because a CALL with a constant address is    not much slower than one with a register address.  */
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
parameter_list|)
define|\
value|case CONST_INT:						\     if (RTX == const0_rtx) return 0;				\     if ((unsigned) INTVAL (RTX)< 077) return 1;		\   case CONST:							\   case LABEL_REF:						\   case SYMBOL_REF:						\     return 3;							\   case CONST_DOUBLE:						\     return 5;							\   case PLUS:							\     if (GET_CODE (XEXP (RTX, 0)) == REG				\&& GET_CODE (XEXP (RTX, 1)) == CONST_INT)		\       return 2;
end_define

begin_escape
end_escape

begin_comment
comment|/* Tell final.c how to eliminate redundant test instructions.  */
end_comment

begin_comment
comment|/* ??? Find a better place to put this.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

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
value|fp_hook (INSN, OPERANDS, NOPERANDS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Here we define machine-dependent flags and fields in cc_status    (see `conditions.h').  */
end_comment

begin_comment
comment|/* Set if the cc value is actually in the 80387, so a floating point    conditional branch must be output.  */
end_comment

begin_define
define|#
directive|define
name|CC_IN_80387
value|04000
end_define

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
value|notice_update_cc((EXP))
end_define

begin_comment
comment|/* Output a signed jump insn.  Use template NORMAL ordinarily, or    FLOAT following a floating point comparison.    Use NO_OV following an arithmetic insn that set the cc's    before a test insn that was deleted.    NO_OV may be zero, meaning final should reinsert the test insn    because the jump cannot be handled properly without it.  */
end_comment

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
value|{								\   if (cc_status.flags& CC_IN_80387)				\     return FLOAT;						\   if (cc_status.flags& CC_NO_OVERFLOW)				\     return NO_OV;						\   return NORMAL;						\ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Control the assembler format that we output.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATT
end_ifdef

begin_include
include|#
directive|include
file|<syms.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FILNMLEN
value|14
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* How to refer to registers in assembler output.    This sequence is indexed by compiler's hard-register-number (see above). */
end_comment

begin_comment
comment|/* In order to refer to the first 8 regs as 32 bit regs prefix an "e"    For non floating point regs, the following are the HImode names.    */
end_comment

begin_define
define|#
directive|define
name|HI_REGISTER_NAMES
define|\
value|{"ax","dx","cx","bx","si","di","bp","sp",          \  "st","st(1)"}
end_define

begin_comment
comment|/* ,"st(2)","st(3)","st(4)","st(5)" } */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|HI_REGISTER_NAMES
end_define

begin_comment
comment|/* Note we are omitting these since currently I don't know how to get gcc to use these, since they want the same but different number as al, and ax. */
end_comment

begin_comment
comment|/* note the last four are not really qi_registsers, but    the md will have to never output movb into one of them    only a movw .  There is no movb into the hardware reg    esi that I can find */
end_comment

begin_define
define|#
directive|define
name|QI_REGISTER_NAMES
define|\
value|{"al", "dl", "cl", "bl", "si", "di", "bp", "sp",}
end_define

begin_comment
comment|/*   Don't know how to use these, yet.   They overlap with ax,dx,cx,bx   and so would clobber al,dl,cl,bl  #define QI_REGISTER_NAMES_TOP \ {"ah", \  "dh", \  "ch", \  "bh", } */
end_comment

begin_comment
comment|/* How to renumber registers for dbxand gdb.  */
end_comment

begin_comment
comment|/* {0,2,1,3,6,7,4,5,12,13,14,15,16,17}  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
define|\
value|((n)==0?0 :(n)==1?2 :(n)==2?1 :(n)==3?3 :(n)==4?6 :(n)==5?7 :(n)==6?4 :(n)==7?5 :(n)==8?12 :(n)==9?12 :(n))
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
value|(assemble_name (FILE, NAME), fputs (":\n", FILE))
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
value|fprintf (FILE, "%s%.22e\n",ASM_DOUBLE, (VALUE))
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
value|do { union { float f; long l;} tem;			\      tem.f = (VALUE); \      fputs(ASM_LONG,FILE); \      fprintf((FILE), "0x%x\n", tem.l); \    } while (0)
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
value|( fprintf (FILE,ASM_LONG),			\    output_addr_const (FILE,(VALUE)),		\   putc('\n',FILE))
end_define

begin_comment
comment|/* Likewise for `char' and `short' constants.  */
end_comment

begin_comment
comment|/* is this supposed to do align too?? */
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
value|( fprintf (FILE,ASM_SHORT),			\    output_addr_const (FILE,(VALUE)),		\   putc('\n',FILE))
end_define

begin_comment
comment|/* #define ASM_OUTPUT_SHORT(FILE,VALUE)  \ ( fputs (ASM_BYTE,FILE),			\    output_addr_const (FILE,(VALUE)),		\   fputs ( ",",FILE),			\    output_addr_const (FILE,(VALUE)),		\   fputs (">> 8\n",FILE)) */
end_comment

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
value|( fprintf (FILE, ASM_BYTE),			\    output_addr_const (FILE,(VALUE)),		\   putc('\n',FILE))
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
value|fprintf ((FILE), "%s0x%x\n", ASM_BYTE, (VALUE))
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
value|fprintf (FILE, "\tpushl e%s\n", reg_names[REGNO])
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
value|fprintf (FILE, "\tpopl e%s\n", reg_names[REGNO])
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.      */
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
value|fprintf (FILE, "%s%s%d\n",ASM_LONG,LPREFIX, VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    We don't use these on the 386 yet, because the ATT assembler can't do    forward reference the differences.    */
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
value|abort(); \   fprintf (FILE, "\t.word %s%d-%s%d\n",LPREFIX, VALUE,LPREFIX, REL)
end_define

begin_comment
comment|/* Define the parentheses used to group arithmetic operations    in assembler code.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OPEN_PAREN
value|""
end_define

begin_define
define|#
directive|define
name|ASM_CLOSE_PAREN
value|""
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
comment|/* Print operand X (an rtx) in assembler syntax to file FILE.    CODE is a letter or dot (`z' in `%z0') or 0 if no letter was specified.    The CODE z takes the size of operand from the following digit, and    outputs b,w,or l respectively.     On the 80386, we use several such letters:    f -- float insn (print a CONST_DOUBLE as a float rather than in hex).    L,W,B,Q,S -- print the opcode suffix for specified size of operand.    R -- print the prefix for register names.    z -- print the opcode suffix for the size of the current operand.    * -- print a star (in certain assembler syntax)    w -- print the operand as if it's a "word" (HImode) even if it isn't.    w -- print the operand as if it's a byte (QImode) even if it isn't.    c -- don't print special prefixes before constant operands.  */
end_comment

begin_define
define|#
directive|define
name|PRINT_OPERAND_PUNCT_VALID_P
parameter_list|(
name|CODE
parameter_list|)
define|\
value|((CODE) == '*')
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
value|print_operand (FILE, X, CODE)
end_define

begin_escape
end_escape

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
comment|/* Routines in gnulib that return floats must return them in an fp reg,    just as other functions do which return such values.    These macros make that happen.  */
end_comment

begin_define
define|#
directive|define
name|SFVALUE
value|float
end_define

begin_define
define|#
directive|define
name|INTIFY
parameter_list|(
name|FLOATVAL
parameter_list|)
value|FLOATVAL
end_define

begin_comment
comment|/* Nonzero if INSN magically clobbers register REGNO.  */
end_comment

begin_define
define|#
directive|define
name|INSN_CLOBBERS_REGNO_P
parameter_list|(
name|INSN
parameter_list|,
name|REGNO
parameter_list|)
define|\
value|(FP_REGNO_P (REGNO)				\&& (GET_CODE (INSN) == JUMP_INSN || GET_CODE (INSN) == BARRIER))
end_define

begin_comment
comment|/* a letter which is not needed by the normal asm syntax, which    we can use for operand syntax in the extended asm */
end_comment

begin_define
define|#
directive|define
name|ASM_OPERAND_LETTER
value|'#'
end_define

begin_escape
end_escape

begin_comment
comment|/* Local variables: version-control: t End: */
end_comment

end_unit

