begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine sub-parameters for SPARC, for GDB, the GNU debugger.    This is included by other tm-*.h files to define SPARC cpu-related info.    Copyright 1986, 1987, 1989, 1991, 1992, 1993, 1994, 1995, 1996, 1997,    1998, 1999, 2000    Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@mcc.com)     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|value
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The following enums are purely for the convenience of the GDB   * developer, when debugging GDB.  */
end_comment

begin_enum
enum|enum
block|{
comment|/* Sparc general registers, for all sparc versions.  */
name|G0_REGNUM
block|,
name|G1_REGNUM
block|,
name|G2_REGNUM
block|,
name|G3_REGNUM
block|,
name|G4_REGNUM
block|,
name|G5_REGNUM
block|,
name|G6_REGNUM
block|,
name|G7_REGNUM
block|,
name|O0_REGNUM
block|,
name|O1_REGNUM
block|,
name|O2_REGNUM
block|,
name|O3_REGNUM
block|,
name|O4_REGNUM
block|,
name|O5_REGNUM
block|,
name|O6_REGNUM
block|,
name|O7_REGNUM
block|,
name|L0_REGNUM
block|,
name|L1_REGNUM
block|,
name|L2_REGNUM
block|,
name|L3_REGNUM
block|,
name|L4_REGNUM
block|,
name|L5_REGNUM
block|,
name|L6_REGNUM
block|,
name|L7_REGNUM
block|,
name|I0_REGNUM
block|,
name|I1_REGNUM
block|,
name|I2_REGNUM
block|,
name|I3_REGNUM
block|,
name|I4_REGNUM
block|,
name|I5_REGNUM
block|,
name|I6_REGNUM
block|,
name|I7_REGNUM
block|,
name|FP0_REGNUM
comment|/* Floating point register 0 */
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* Sparc general registers, alternate names.  */
name|R0_REGNUM
block|,
name|R1_REGNUM
block|,
name|R2_REGNUM
block|,
name|R3_REGNUM
block|,
name|R4_REGNUM
block|,
name|R5_REGNUM
block|,
name|R6_REGNUM
block|,
name|R7_REGNUM
block|,
name|R8_REGNUM
block|,
name|R9_REGNUM
block|,
name|R10_REGNUM
block|,
name|R11_REGNUM
block|,
name|R12_REGNUM
block|,
name|R13_REGNUM
block|,
name|R14_REGNUM
block|,
name|R15_REGNUM
block|,
name|R16_REGNUM
block|,
name|R17_REGNUM
block|,
name|R18_REGNUM
block|,
name|R19_REGNUM
block|,
name|R20_REGNUM
block|,
name|R21_REGNUM
block|,
name|R22_REGNUM
block|,
name|R23_REGNUM
block|,
name|R24_REGNUM
block|,
name|R25_REGNUM
block|,
name|R26_REGNUM
block|,
name|R27_REGNUM
block|,
name|R28_REGNUM
block|,
name|R29_REGNUM
block|,
name|R30_REGNUM
block|,
name|R31_REGNUM
block|}
enum|;
end_enum

begin_enum
enum|enum
block|{
comment|/* Sparc32 control registers.  */
name|PS_REGNUM
init|=
literal|65
block|,
comment|/* PC, NPC, and Y are omitted because */
name|WIM_REGNUM
init|=
literal|66
block|,
comment|/* they have different values depending on */
name|TBR_REGNUM
init|=
literal|67
block|,
comment|/* 32-bit / 64-bit mode.  */
name|FPS_REGNUM
init|=
literal|70
block|,
name|CPS_REGNUM
init|=
literal|71
block|}
enum|;
end_enum

begin_comment
comment|/* v9 misc. and priv. regs */
end_comment

begin_comment
comment|/* Note: specifying values explicitly for documentation purposes.  */
end_comment

begin_enum
enum|enum
block|{
comment|/* Sparc64 control registers, excluding Y, PC, and NPC.  */
name|CCR_REGNUM
init|=
literal|82
block|,
comment|/* Condition Code Register (%xcc,%icc) */
name|FSR_REGNUM
init|=
literal|83
block|,
comment|/* Floating Point State */
name|FPRS_REGNUM
init|=
literal|84
block|,
comment|/* Floating Point Registers State */
name|ASI_REGNUM
init|=
literal|86
block|,
comment|/* Alternate Space Identifier */
name|VER_REGNUM
init|=
literal|87
block|,
comment|/* Version register */
name|TICK_REGNUM
init|=
literal|88
block|,
comment|/* Tick register */
name|PIL_REGNUM
init|=
literal|89
block|,
comment|/* Processor Interrupt Level */
name|PSTATE_REGNUM
init|=
literal|90
block|,
comment|/* Processor State */
name|TSTATE_REGNUM
init|=
literal|91
block|,
comment|/* Trap State */
name|TBA_REGNUM
init|=
literal|92
block|,
comment|/* Trap Base Address */
name|TL_REGNUM
init|=
literal|93
block|,
comment|/* Trap Level */
name|TT_REGNUM
init|=
literal|94
block|,
comment|/* Trap Type */
name|TPC_REGNUM
init|=
literal|95
block|,
comment|/* Trap pc */
name|TNPC_REGNUM
init|=
literal|96
block|,
comment|/* Trap npc */
name|WSTATE_REGNUM
init|=
literal|97
block|,
comment|/* Window State */
name|CWP_REGNUM
init|=
literal|98
block|,
comment|/* Current Window Pointer */
name|CANSAVE_REGNUM
init|=
literal|99
block|,
comment|/* Savable Windows */
name|CANRESTORE_REGNUM
init|=
literal|100
block|,
comment|/* Restorable Windows */
name|CLEANWIN_REGNUM
init|=
literal|101
block|,
comment|/* Clean Windows */
name|OTHERWIN_REGNUM
init|=
literal|102
block|,
comment|/* Other Windows */
name|ASR16_REGNUM
init|=
literal|103
block|,
comment|/* Ancillary State Registers */
name|ASR17_REGNUM
init|=
literal|104
block|,
name|ASR18_REGNUM
init|=
literal|105
block|,
name|ASR19_REGNUM
init|=
literal|106
block|,
name|ASR20_REGNUM
init|=
literal|107
block|,
name|ASR21_REGNUM
init|=
literal|108
block|,
name|ASR22_REGNUM
init|=
literal|109
block|,
name|ASR23_REGNUM
init|=
literal|110
block|,
name|ASR24_REGNUM
init|=
literal|111
block|,
name|ASR25_REGNUM
init|=
literal|112
block|,
name|ASR26_REGNUM
init|=
literal|113
block|,
name|ASR27_REGNUM
init|=
literal|114
block|,
name|ASR28_REGNUM
init|=
literal|115
block|,
name|ASR29_REGNUM
init|=
literal|116
block|,
name|ASR30_REGNUM
init|=
literal|117
block|,
name|ASR31_REGNUM
init|=
literal|118
block|,
name|ICC_REGNUM
init|=
literal|119
block|,
comment|/* 32 bit condition codes */
name|XCC_REGNUM
init|=
literal|120
block|,
comment|/* 64 bit condition codes */
name|FCC0_REGNUM
init|=
literal|121
block|,
comment|/* fp cc reg 0 */
name|FCC1_REGNUM
init|=
literal|122
block|,
comment|/* fp cc reg 1 */
name|FCC2_REGNUM
init|=
literal|123
block|,
comment|/* fp cc reg 2 */
name|FCC3_REGNUM
init|=
literal|124
comment|/* fp cc reg 3 */
block|}
enum|;
end_enum

begin_comment
comment|/*  * Make sparc target multi-archable: April 2000  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GDB_MULTI_ARCH
argument_list|)
operator|&&
operator|(
name|GDB_MULTI_ARCH
operator|>
literal|0
operator|)
end_if

begin_comment
comment|/* Multi-arch definition of TARGET_IS_SPARC64, TARGET_ELF64 */
end_comment

begin_undef
undef|#
directive|undef
name|GDB_TARGET_IS_SPARC64
end_undef

begin_define
define|#
directive|define
name|GDB_TARGET_IS_SPARC64
define|\
value|(sparc_intreg_size () == 8)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ELF64
end_undef

begin_define
define|#
directive|define
name|TARGET_ELF64
define|\
value|(sparc_intreg_size () == 8)
end_define

begin_function_decl
specifier|extern
name|int
name|sparc_intreg_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Non-multi-arch: if it isn't defined, define it to zero.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_TARGET_IS_SPARC64
end_ifndef

begin_define
define|#
directive|define
name|GDB_TARGET_IS_SPARC64
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ELF64
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ELF64
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDB_MULTI_ARCH
argument_list|)
operator|||
operator|(
name|GDB_MULTI_ARCH
operator|==
literal|0
operator|)
end_if

begin_comment
comment|/*  * The following defines must go away for MULTI_ARCH  */
end_comment

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{ "g0", "g1", "g2", "g3", "g4", "g5", "g6", "g7",		\   "o0", "o1", "o2", "o3", "o4", "o5", "sp", "o7",		\   "l0", "l1", "l2", "l3", "l4", "l5", "l6", "l7",		\   "i0", "i1", "i2", "i3", "i4", "i5", "fp", "i7",		\ 								\   "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",		\   "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15",		\   "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23",	\   "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31",	\                                                                 \   "y", "psr", "wim", "tbr", "pc", "npc", "fpsr", "cpsr" 	\ }
end_define

begin_comment
comment|/* Offset from address of function to start of its code.    Zero on most machines.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_START_OFFSET
value|0
end_define

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.    This is often the number of bytes in BREAKPOINT    but not always.  */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_comment
comment|/* Say how long (ordinary) registers are.  This is a piece of bogosity    used in push_word and a few other places; REGISTER_RAW_SIZE is the    real way to know how big a register is.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_SIZE
value|4
end_define

begin_comment
comment|/* Number of machine registers */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|72
end_define

begin_define
define|#
directive|define
name|SP_REGNUM
value|14
end_define

begin_comment
comment|/* Contains address of top of stack, \ 				   which is also the bottom of the frame.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|30
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|32
end_define

begin_comment
comment|/* Floating point register 0 */
end_comment

begin_define
define|#
directive|define
name|Y_REGNUM
value|64
end_define

begin_comment
comment|/* Temp register for multiplication, etc.  */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|68
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|NPC_REGNUM
value|69
end_define

begin_comment
comment|/* Contains next PC */
end_comment

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  On the sparc, `registers'    contains the ins and locals, even though they are saved on the    stack rather than with the other registers, and this causes hair    and confusion in places like pop_frame.  It might be better to    remove the ins and locals from `registers', make sure that    get_saved_register can get them from the stack (even in the    innermost frame), and make this the way to access them.  For the    frame pointer we would do that via TARGET_READ_FP.  On the other    hand, that is likely to be confusing or worse for flat frames.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(32*4+32*4+8*4)
end_define

begin_comment
comment|/* Index within `registers' of the first byte of the space for    register N.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|N
parameter_list|)
value|((N)*4)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation for    register N.  */
end_comment

begin_comment
comment|/* On the SPARC, all regs are 4 bytes (except Sparc64, where they're 8).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|(4)
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  */
end_comment

begin_comment
comment|/* On the SPARC, all regs are 4 bytes (except Sparc64, where they're 8).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|(4)
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|8
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|8
end_define

begin_comment
comment|/* Return the GDB type object for the "standard" data type    of data in register N.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_TYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)< 32 ? builtin_type_int : (N)< 64 ? builtin_type_float : \       builtin_type_int)
end_define

begin_comment
comment|/* Sun /bin/cc gets this right as of SunOS 4.1.x.  We need to define    BELIEVE_PCC_PROMOTION to get this right now that the code which    detects gcc2_compiled. is broken.  This loses for SunOS 4.0.x and    earlier.  */
end_comment

begin_define
define|#
directive|define
name|BELIEVE_PCC_PROMOTION
value|1
end_define

begin_comment
comment|/* Advance PC across any function entry prologue instructions    to reach some "real" code.  SKIP_PROLOGUE_FRAMELESS_P advances    the PC past some of the prologue, but stops as soon as it    knows that the function has a frame.  Its result is equal    to its input PC if the function is frameless, unequal otherwise.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|PC
parameter_list|)
value|sparc_skip_prologue (PC, 0)
end_define

begin_comment
comment|/* Immediately after a function call, return the saved pc.    Can't go through the frames for this because on some machines    the new frame is not set up until the new function executes    some instructions.  */
end_comment

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|FRAME
parameter_list|)
value|PC_ADJUST (read_register (RP_REGNUM))
end_define

begin_comment
comment|/* Stack grows downward.  */
end_comment

begin_define
define|#
directive|define
name|INNER_THAN
parameter_list|(
name|LHS
parameter_list|,
name|RHS
parameter_list|)
value|((LHS)< (RHS))
end_define

begin_comment
comment|/* Write into appropriate registers a function return value of type    TYPE, given in virtual format.  */
end_comment

begin_define
define|#
directive|define
name|STORE_RETURN_VALUE
parameter_list|(
name|TYPE
parameter_list|,
name|VALBUF
parameter_list|)
define|\
value|sparc_store_return_value (TYPE, VALBUF)
end_define

begin_function_decl
specifier|extern
name|void
name|sparc_store_return_value
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    the address in which a function should return its structure value,    as a CORE_ADDR (or an expression that can be used as one).  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS
parameter_list|(
name|REGBUF
parameter_list|)
define|\
value|sparc_extract_struct_value_address (REGBUF)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc_extract_struct_value_address
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If the current gcc for for this target does not produce correct    debugging information for float parameters, both prototyped and    unprototyped, then define this macro.  This forces gdb to always    assume that floats are passed as doubles and then converted in the    callee. */
end_comment

begin_define
define|#
directive|define
name|COERCE_FLOAT_TO_DOUBLE
parameter_list|(
name|FORMAL
parameter_list|,
name|ACTUAL
parameter_list|)
value|(1)
end_define

begin_comment
comment|/* Stack must be aligned on 64-bit boundaries when synthesizing    function calls (128-bit for sparc64).  */
end_comment

begin_define
define|#
directive|define
name|STACK_ALIGN
parameter_list|(
name|ADDR
parameter_list|)
value|sparc32_stack_align (ADDR)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc32_stack_align
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The Sparc returns long doubles on the stack.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_VALUE_ON_STACK
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|(TYPE_CODE(TYPE) == TYPE_CODE_FLT \&& TYPE_LENGTH(TYPE)> 8)
end_define

begin_comment
comment|/* When passing a structure to a function, Sun cc passes the address    not the structure itself.  It (under SunOS4) creates two symbols,    which we need to combine to a LOC_REGPARM.  Gcc version two (as of    1.92) behaves like sun cc.  REG_STRUCT_HAS_ADDR is smart enough to    distinguish between Sun cc, gcc version 1 and gcc version 2.  */
end_comment

begin_define
define|#
directive|define
name|REG_STRUCT_HAS_ADDR
parameter_list|(
name|GCC_P
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|sparc_reg_struct_has_addr (GCC_P, TYPE)
end_define

begin_function_decl
specifier|extern
name|int
name|sparc_reg_struct_has_addr
parameter_list|(
name|int
parameter_list|,
name|struct
name|type
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDB_MULTI_ARCH */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GDB_MULTI_ARCH
argument_list|)
operator|&&
operator|(
name|GDB_MULTI_ARCH
operator|>
literal|0
operator|)
end_if

begin_comment
comment|/*  * The following defines should ONLY appear for MULTI_ARCH.  */
end_comment

begin_comment
comment|/* Multi-arch the nPC and Y registers.  */
end_comment

begin_define
define|#
directive|define
name|Y_REGNUM
value|(sparc_y_regnum ())
end_define

begin_function_decl
specifier|extern
name|int
name|sparc_npc_regnum
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sparc_y_regnum
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDB_MULTI_ARCH */
end_comment

begin_comment
comment|/* On the Sun 4 under SunOS, the compile will leave a fake insn which    encodes the structure size being returned.  If we detect such    a fake insn, step past it.  */
end_comment

begin_define
define|#
directive|define
name|PC_ADJUST
parameter_list|(
name|PC
parameter_list|)
value|sparc_pc_adjust (PC)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc_pc_adjust
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Advance PC across any function entry prologue instructions to reach    some "real" code.  SKIP_PROLOGUE_FRAMELESS_P advances the PC past    some of the prologue, but stops as soon as it knows that the    function has a frame.  Its result is equal to its input PC if the    function is frameless, unequal otherwise.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE_FRAMELESS_P
parameter_list|(
name|PC
parameter_list|)
value|sparc_skip_prologue (PC, 1)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc_skip_prologue
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If an argument is declared "register", Sun cc will keep it in a register,    never saving it onto the stack.  So we better not believe the "p" symbol    descriptor stab.  */
end_comment

begin_define
define|#
directive|define
name|USE_REGISTER_NOT_ARG
end_define

begin_comment
comment|/* For acc, there's no need to correct LBRAC entries by guessing how    they should work.  In fact, this is harmful because the LBRAC    entries now all appear at the end of the function, not intermixed    with the SLINE entries.  n_opt_found detects acc for Solaris binaries;    function_stab_type detects acc for SunOS4 binaries.     For binary from SunOS4 /bin/cc, need to correct LBRAC's.     For gcc, like acc, don't correct.  */
end_comment

begin_define
define|#
directive|define
name|SUN_FIXED_LBRAC_BUG
define|\
value|(n_opt_found \    || function_stab_type == N_STSYM \    || function_stab_type == N_GSYM \    || processing_gcc_compilation)
end_define

begin_comment
comment|/* Do variables in the debug stabs occur after the N_LBRAC or before it?    acc: after, gcc: before, SunOS4 /bin/cc: before.  */
end_comment

begin_define
define|#
directive|define
name|VARIABLES_INSIDE_BLOCK
parameter_list|(
name|desc
parameter_list|,
name|gcc_p
parameter_list|)
define|\
value|(!(gcc_p) \&& (n_opt_found \        || function_stab_type == N_STSYM \        || function_stab_type == N_GSYM))
end_define

begin_comment
comment|/* Sequence of bytes for breakpoint instruction (ta 1). */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x91, 0xd0, 0x20, 0x01}
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|G0_REGNUM
value|0
end_define

begin_comment
comment|/* %g0 */
end_comment

begin_define
define|#
directive|define
name|G1_REGNUM
value|1
end_define

begin_comment
comment|/* %g1 */
end_comment

begin_define
define|#
directive|define
name|O0_REGNUM
value|8
end_define

begin_comment
comment|/* %o0 */
end_comment

begin_define
define|#
directive|define
name|RP_REGNUM
value|15
end_define

begin_comment
comment|/* Contains return address value, *before* \ 				   any windows get switched.  */
end_comment

begin_define
define|#
directive|define
name|O7_REGNUM
value|15
end_define

begin_comment
comment|/* Last local reg not saved on stack frame */
end_comment

begin_define
define|#
directive|define
name|L0_REGNUM
value|16
end_define

begin_comment
comment|/* First local reg that's saved on stack frame 				   rather than in machine registers */
end_comment

begin_define
define|#
directive|define
name|I0_REGNUM
value|24
end_define

begin_comment
comment|/* %i0 */
end_comment

begin_define
define|#
directive|define
name|I7_REGNUM
value|31
end_define

begin_comment
comment|/* Last local reg saved on stack frame */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|65
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|PS_FLAG_CARRY
value|0x100000
end_define

begin_comment
comment|/* Carry bit in PS */
end_comment

begin_define
define|#
directive|define
name|WIM_REGNUM
value|66
end_define

begin_comment
comment|/* Window Invalid Mask (not really supported) */
end_comment

begin_define
define|#
directive|define
name|TBR_REGNUM
value|67
end_define

begin_comment
comment|/* Trap Base Register (not really supported) */
end_comment

begin_define
define|#
directive|define
name|FPS_REGNUM
value|70
end_define

begin_comment
comment|/* Floating point status register */
end_comment

begin_define
define|#
directive|define
name|CPS_REGNUM
value|71
end_define

begin_comment
comment|/* Coprocessor status register */
end_comment

begin_comment
comment|/* Writing to %g0 is a noop (not an error or exception or anything like    that, however).  */
end_comment

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|((regno) == G0_REGNUM)
end_define

begin_comment
comment|/*  * FRAME_CHAIN and FRAME_INFO definitions, collected here for convenience.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDB_MULTI_ARCH
argument_list|)
operator|||
operator|(
name|GDB_MULTI_ARCH
operator|==
literal|0
operator|)
end_if

begin_comment
comment|/*  * The following defines must go away for MULTI_ARCH.  */
end_comment

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer. */
end_comment

begin_comment
comment|/* In the case of the Sun 4, the frame-chain's nominal address    is held in the frame pointer register.     On the Sun4, the frame (in %fp) is %sp for the previous frame.    From the previous frame's %sp, we can find the previous frame's    %fp: it is in the save area just above the previous frame's %sp.     If we are setting up an arbitrary frame, we'll need to know where    it ends.  Hence the following.  This part of the frame cache    structure should be checked before it is assumed that this frame's    bottom is in the stack pointer.     If there isn't a frame below this one, the bottom of this frame is    in the stack pointer.     If there is a frame below this one, and the frame pointers are    identical, it's a leaf frame and the bottoms are the same also.     Otherwise the bottom of this frame is the top of the next frame.     The bottom field is misnamed, since it might imply that memory from    bottom to frame contains this frame.  That need not be true if    stack frames are allocated in different segments (e.g. some on a    stack, some on a heap in the data segment).     GCC 2.6 and later can generate ``flat register window'' code that    makes frames by explicitly saving those registers that need to be    saved.  %i7 is used as the frame pointer, and the frame is laid out    so that flat and non-flat calls can be intermixed freely within a    program.  Unfortunately for GDB, this means it must detect and    record the flatness of frames.     Since the prologue in a flat frame also tells us where fp and pc    have been stashed (the frame is of variable size, so their location    is not fixed), it's convenient to record them in the frame info.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
define|\
value|CORE_ADDR bottom;      \   int in_prologue;       \   int flat;              \
comment|/* Following fields only relevant for flat frames.  */
value|\   CORE_ADDR pc_addr;     \   CORE_ADDR fp_addr;     \
comment|/* Add this to ->frame to get the value of the stack pointer at the */
value|\
comment|/* time of the register saves.  */
value|\   int sp_offset;
end_define

begin_comment
comment|/* We need to override GET_SAVED_REGISTER so that we can deal with the way    outs change into ins in different frames.  HAVE_REGISTER_WINDOWS can't    deal with this case and also handle flat frames at the same time.  */
end_comment

begin_function_decl
name|void
name|sparc_get_saved_register
parameter_list|(
name|char
modifier|*
name|raw_buffer
parameter_list|,
name|int
modifier|*
name|optimized
parameter_list|,
name|CORE_ADDR
modifier|*
name|addrp
parameter_list|,
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|,
name|int
name|regnum
parameter_list|,
name|enum
name|lval_type
modifier|*
name|lvalp
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_SAVED_REGISTER
parameter_list|(
name|RAW_BUFFER
parameter_list|,
name|OPTIMIZED
parameter_list|,
name|ADDRP
parameter_list|,
name|FRAME
parameter_list|,
name|REGNUM
parameter_list|,
name|LVAL
parameter_list|)
define|\
value|sparc_get_saved_register (RAW_BUFFER, OPTIMIZED, ADDRP, \ 			       FRAME, REGNUM, LVAL)
end_define

begin_define
define|#
directive|define
name|FRAME_INIT_SAVED_REGS
parameter_list|(
name|FP
parameter_list|)
end_define

begin_comment
comment|/*no-op */
end_comment

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO
parameter_list|(
name|FROMLEAF
parameter_list|,
name|FCI
parameter_list|)
define|\
value|sparc_init_extra_frame_info (FROMLEAF, FCI)
end_define

begin_function_decl
specifier|extern
name|void
name|sparc_init_extra_frame_info
parameter_list|(
name|int
parameter_list|,
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|THISFRAME
parameter_list|)
value|(sparc_frame_chain (THISFRAME))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc_frame_chain
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.  */
end_comment

begin_define
define|#
directive|define
name|FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|FI
parameter_list|)
define|\
value|frameless_look_for_prologue (FI)
end_define

begin_comment
comment|/* Where is the PC for a specific frame */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|sparc_frame_saved_pc (FRAME)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If the argument is on the stack, it will be here.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|FI
parameter_list|)
value|((FI)->frame)
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|FI
parameter_list|)
value|((FI)->frame)
end_define

begin_comment
comment|/* Set VAL to the number of args passed to frame described by FI.    Can set VAL to -1, meaning no way to tell.  */
end_comment

begin_comment
comment|/* We can't tell how many args there are    now that the C compiler delays popping them.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|FI
parameter_list|)
value|(-1)
end_define

begin_comment
comment|/* Return number of bytes at start of arglist that are not really args.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_SKIP
value|68
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDB_MULTI_ARCH */
end_comment

begin_define
define|#
directive|define
name|PRINT_EXTRA_FRAME_INFO
parameter_list|(
name|FI
parameter_list|)
define|\
value|sparc_print_extra_frame_info (FI)
end_define

begin_function_decl
specifier|extern
name|void
name|sparc_print_extra_frame_info
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* INIT_EXTRA_FRAME_INFO needs the PC to detect flat frames.  */
end_comment

begin_define
define|#
directive|define
name|INIT_FRAME_PC
parameter_list|(
name|FROMLEAF
parameter_list|,
name|PREV
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_define
define|#
directive|define
name|INIT_FRAME_PC_FIRST
parameter_list|(
name|FROMLEAF
parameter_list|,
name|PREV
parameter_list|)
define|\
value|(PREV)->pc = ((FROMLEAF) ? SAVED_PC_AFTER_CALL ((PREV)->next) : \ 	      (PREV)->next ? FRAME_SAVED_PC ((PREV)->next) : read_pc ());
end_define

begin_comment
comment|/* Define other aspects of the stack frame.  */
end_comment

begin_comment
comment|/* The location of I0 w.r.t SP.  This is actually dependent on how the    system's window overflow/underflow routines are written.  Most    vendors save the L regs followed by the I regs (at the higher    address).  Some vendors get it wrong.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_L0
value|0
end_define

begin_define
define|#
directive|define
name|FRAME_SAVED_I0
value|(8 * REGISTER_RAW_SIZE (L0_REGNUM))
end_define

begin_define
define|#
directive|define
name|FRAME_STRUCT_ARGS_ADDRESS
parameter_list|(
name|FI
parameter_list|)
value|((FI)->frame)
end_define

begin_comment
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_comment
comment|/*  * First of all, let me give my opinion of what the DUMMY_FRAME  * actually looks like.  *  *               |                                 |  *               |                                 |  *               + - - - - - - - - - - - - - - - - +<-- fp (level 0)  *               |                                 |  *               |                                 |  *               |                                 |  *               |                                 |  *               |  Frame of innermost program     |  *               |           function              |  *               |                                 |  *               |                                 |  *               |                                 |  *               |                                 |  *               |                                 |  *               |---------------------------------|<-- sp (level 0), fp (c)  *               |                                 |  *     DUMMY     |             fp0-31              |  *               |                                 |  *               |             ------              |<-- fp - 0x80  *     FRAME     |              g0-7               |<-- fp - 0xa0  *               |              i0-7               |<-- fp - 0xc0  *               |             other               |<-- fp - 0xe0  *               |               ?                 |  *               |               ?                 |  *               |---------------------------------|<-- sp' = fp - 0x140  *               |                                 |  * xcution start |                                 |  * sp' + 0x94 -->|        CALL_DUMMY (x code)      |  *               |                                 |  *               |                                 |  *               |---------------------------------|<-- sp'' = fp - 0x200  *               |  align sp to 8 byte boundary    |  *               |     ==> args to fn<==          |  *  Room for     |                                 |  * i& l's + agg | CALL_DUMMY_STACK_ADJUST = 0x0x44|  *               |---------------------------------|<-- final sp (variable)  *               |                                 |  *               |   Where function called will    |  *               |           build frame.          |  *               |                                 |  *               |                                 |  *  *   I understand everything in this picture except what the space  * between fp - 0xe0 and fp - 0x140 is used for.  Oh, and I don't  * understand why there's a large chunk of CALL_DUMMY that never gets  * executed (its function is superceeded by PUSH_DUMMY_FRAME; they  * are designed to do the same thing).  *  *   PUSH_DUMMY_FRAME saves the registers above sp' and pushes the  * register file stack down one.  *  *   call_function then writes CALL_DUMMY, pushes the args onto the  * stack, and adjusts the stack pointer.  *  *   run_stack_dummy then starts execution (in the middle of  * CALL_DUMMY, as directed by call_function).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CALL_DUMMY
end_ifndef

begin_comment
comment|/* This sequence of words is the instructions     00:   bc 10 00 01     mov  %g1, %fp    04:   9d e3 80 00     save  %sp, %g0, %sp    08:   bc 10 00 02     mov  %g2, %fp    0c:   be 10 00 03     mov  %g3, %i7    10:   da 03 a0 58     ld  [ %sp + 0x58 ], %o5    14:   d8 03 a0 54     ld  [ %sp + 0x54 ], %o4    18:   d6 03 a0 50     ld  [ %sp + 0x50 ], %o3    1c:   d4 03 a0 4c     ld  [ %sp + 0x4c ], %o2    20:   d2 03 a0 48     ld  [ %sp + 0x48 ], %o1    24:   40 00 00 00     call<fun>    28:   d0 03 a0 44     ld  [ %sp + 0x44 ], %o0    2c:   01 00 00 00     nop     30:   91 d0 20 01     ta  1    34:   01 00 00 00     nop     NOTES:    * the first four instructions are necessary only on the simulator.    * this is a multiple of 8 (not only 4) bytes.    * the `call' insn is a relative, not an absolute call.    * the `nop' at the end is needed to keep the trap from      clobbering things (if NPC pointed to garbage instead).  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDB_MULTI_ARCH
argument_list|)
operator|||
operator|(
name|GDB_MULTI_ARCH
operator|==
literal|0
operator|)
end_if

begin_comment
comment|/*  * The following defines must go away for MULTI_ARCH.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{ 0xbc100001, 0x9de38000, 0xbc100002, 0xbe100003,	\ 		     0xda03a058, 0xd803a054, 0xd603a050, 0xd403a04c,	\ 		     0xd203a048, 0x40000000, 0xd003a044, 0x01000000,	\ 		     0x91d02001, 0x01000000 }
end_define

begin_comment
comment|/* Size of the call dummy in bytes. */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|0x38
end_define

begin_comment
comment|/* Offset within call dummy of first instruction to execute. */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|0
end_define

begin_comment
comment|/* Offset within CALL_DUMMY of the 'call' instruction. */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_CALL_OFFSET
value|(CALL_DUMMY_START_OFFSET + 0x24)
end_define

begin_comment
comment|/* Offset within CALL_DUMMY of the 'ta 1' trap instruction. */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET
value|(CALL_DUMMY_START_OFFSET + 0x30)
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_STACK_ADJUST
value|68
end_define

begin_comment
comment|/* Call dummy method (eg. on stack, at entry point, etc.) */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_LOCATION
value|ON_STACK
end_define

begin_comment
comment|/* Method for detecting dummy frames.  */
end_comment

begin_define
define|#
directive|define
name|PC_IN_CALL_DUMMY
parameter_list|(
name|PC
parameter_list|,
name|SP
parameter_list|,
name|FRAME_ADDRESS
parameter_list|)
define|\
value|pc_in_call_dummy_on_stack (PC, SP, FRAME_ADDRESS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDB_MULTI_ARCH */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CALL_DUMMY */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|GDB_MULTI_ARCH
argument_list|)
operator|||
operator|(
name|GDB_MULTI_ARCH
operator|==
literal|0
operator|)
end_if

begin_comment
comment|/*  * The following defines must go away for MULTI_ARCH.   */
end_comment

begin_comment
comment|/* Insert the specified number of args and function address    into a call sequence of the above form stored at DUMMYNAME.  */
end_comment

begin_define
define|#
directive|define
name|FIX_CALL_DUMMY
parameter_list|(
name|DUMMYNAME
parameter_list|,
name|PC
parameter_list|,
name|FUN
parameter_list|,
name|NARGS
parameter_list|,
name|ARGS
parameter_list|,
name|TYPE
parameter_list|,
name|GCC_P
parameter_list|)
define|\
value|sparc_fix_call_dummy (DUMMYNAME, PC, FUN, TYPE, GCC_P)
end_define

begin_function_decl
name|void
name|sparc_fix_call_dummy
parameter_list|(
name|char
modifier|*
name|dummy
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|fun
parameter_list|,
name|struct
name|type
modifier|*
name|value_type
parameter_list|,
name|int
name|using_gcc
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Arguments smaller than an int must be promoted to ints when    synthesizing function calls.  */
end_comment

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
value|sparc_push_dummy_frame ()
end_define

begin_define
define|#
directive|define
name|POP_FRAME
value|sparc_pop_frame ()
end_define

begin_function_decl
name|void
name|sparc_push_dummy_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|sparc_pop_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PUSH_ARGUMENTS
parameter_list|(
name|NARGS
parameter_list|,
name|ARGS
parameter_list|,
name|SP
parameter_list|,
name|STRUCT_RETURN
parameter_list|,
name|STRUCT_ADDR
parameter_list|)
define|\
value|sparc32_push_arguments (NARGS, ARGS, SP, STRUCT_RETURN, STRUCT_ADDR)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc32_push_arguments
parameter_list|(
name|int
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
parameter_list|,
name|CORE_ADDR
parameter_list|,
name|int
parameter_list|,
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function_by_hand.     The ultimate mystery is, tho, what is the value "16"?  */
end_comment

begin_define
define|#
directive|define
name|STORE_STRUCT_RETURN
parameter_list|(
name|ADDR
parameter_list|,
name|SP
parameter_list|)
define|\
value|{ char val[4]; \     store_unsigned_integer (val, 4, (ADDR)); \     write_memory ((SP)+(16*4), val, 4); }
end_define

begin_comment
comment|/* Default definition of USE_STRUCT_CONVENTION.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_STRUCT_CONVENTION
end_ifndef

begin_define
define|#
directive|define
name|USE_STRUCT_CONVENTION
parameter_list|(
name|GCC_P
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|generic_use_struct_convention (GCC_P, TYPE)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state a    function return value of type TYPE, and copy that, in virtual    format, into VALBUF.  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_RETURN_VALUE
parameter_list|(
name|TYPE
parameter_list|,
name|REGBUF
parameter_list|,
name|VALBUF
parameter_list|)
define|\
value|sparc32_extract_return_value (TYPE, REGBUF, VALBUF)
end_define

begin_function_decl
specifier|extern
name|void
name|sparc32_extract_return_value
parameter_list|(
name|struct
name|type
modifier|*
parameter_list|,
name|char
index|[]
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDB_MULTI_ARCH */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Sparc has no reliable single step ptrace call */
end_comment

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP_P
parameter_list|()
value|1
end_define

begin_function_decl
specifier|extern
name|void
name|sparc_software_single_step
parameter_list|(
name|enum
name|target_signal
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|SOFTWARE_SINGLE_STEP
parameter_list|(
name|sig
parameter_list|,
name|bp_p
parameter_list|)
value|sparc_software_single_step (sig,bp_p)
end_define

begin_comment
comment|/* We need more arguments in a frame specification for the    "frame" or "info frame" command.  */
end_comment

begin_define
define|#
directive|define
name|SETUP_ARBITRARY_FRAME
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
value|setup_arbitrary_frame (argc, argv)
end_define

begin_function_decl
specifier|extern
name|struct
name|frame_info
modifier|*
name|setup_arbitrary_frame
parameter_list|(
name|int
parameter_list|,
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* To print every pair of float registers as a double, we use this hook.    We also print the condition code registers in a readable format    (FIXME: can expand this to all control regs).  */
end_comment

begin_undef
undef|#
directive|undef
name|PRINT_REGISTER_HOOK
end_undef

begin_define
define|#
directive|define
name|PRINT_REGISTER_HOOK
parameter_list|(
name|regno
parameter_list|)
define|\
value|sparc_print_register_hook (regno)
end_define

begin_function_decl
specifier|extern
name|void
name|sparc_print_register_hook
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Optimization for storing registers to the inferior.  The hook    DO_DEFERRED_STORES    actually executes any deferred stores.  It is called any time    we are going to proceed the child, or read its registers.    The hook CLEAR_DEFERRED_STORES is called when we want to throw    away the inferior process, e.g. when it dies or we kill it.    FIXME, this does not handle remote debugging cleanly.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|deferred_stores
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DO_DEFERRED_STORES
define|\
value|if (deferred_stores)		\     target_store_registers (-2);
end_define

begin_define
define|#
directive|define
name|CLEAR_DEFERRED_STORES
define|\
value|deferred_stores = 0;
end_define

begin_comment
comment|/* Select the sparc disassembler */
end_comment

begin_define
define|#
directive|define
name|TM_PRINT_INSN_MACH
value|bfd_mach_sparc
end_define

end_unit

