begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine sub-parameters for SPARC64, for GDB, the GNU debugger.    This is included by other tm-*.h files to define SPARC64 cpu-related info.    Copyright 1994, 1995, 1996, 1998, 1999, 2000    Free Software Foundation, Inc.    This is (obviously) based on the SPARC Vn (n<9) port.    Contributed by Doug Evans (dje@cygnus.com).    Further modified by Bob Manson (manson@cygnus.com).     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|GDB_MULTI_ARCH
value|GDB_MULTI_ARCH_PARTIAL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_TARGET_IS_SPARC64
end_ifndef

begin_define
define|#
directive|define
name|GDB_TARGET_IS_SPARC64
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"sparc/tm-sparc.h"
end_include

begin_comment
comment|/* Eeeew. Ok, we have to assume (for now) that the processor really is    in sparc64 mode. While this is the same instruction sequence as    on the Sparc, the stack frames are offset by +2047 (and the arguments    are 8 bytes instead of 4). */
end_comment

begin_comment
comment|/* Instructions are:    std  %f10, [ %fp + 0x7a7 ]    std  %f8, [ %fp + 0x79f ]    std  %f6, [ %fp + 0x797 ]    std  %f4, [ %fp + 0x78f ]    std  %f2, [ %fp + 0x787 ]    std  %f0, [ %fp + 0x77f ]    std  %g6, [ %fp + 0x777 ]    std  %g4, [ %fp + 0x76f ]    std  %g2, [ %fp + 0x767 ]    std  %g0, [ %fp + 0x75f ]    std  %fp, [ %fp + 0x757 ]    std  %i4, [ %fp + 0x74f ]    std  %i2, [ %fp + 0x747 ]    std  %i0, [ %fp + 0x73f ]    nop    nop    nop    nop    rd  %tbr, %o0    st  %o0, [ %fp + 0x72b ]    rd  %tpc, %o0    st  %o0, [ %fp + 0x727 ]    rd  %psr, %o0    st  %o0, [ %fp + 0x723 ]    rd  %y, %o0    st  %o0, [ %fp + 0x71f ]    ldx  [ %sp + 0x8a7 ], %o5    ldx  [ %sp + 0x89f ], %o4    ldx  [ %sp + 0x897 ], %o3    ldx  [ %sp + 0x88f ], %o2    ldx  [ %sp + 0x887 ], %o1    call  %g0    ldx  [ %sp + 0x87f ], %o0    nop    ta  1    nop    nop  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|DO_CALL_DUMMY_ON_STACK
end_ifndef

begin_comment
comment|/*  * These defines will suffice for the AT_ENTRY_POINT call dummy method.  */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0}
end_define

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_LENGTH
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|0
end_define

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_CALL_OFFSET
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_CALL_OFFSET
value|0
end_define

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_START_OFFSET
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|0
end_define

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_BREAKPOINT_OFFSET
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET
value|0
end_define

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
value|1
end_define

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_LOCATION
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_LOCATION
value|AT_ENTRY_POINT
end_define

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_STACK_ADJUST
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_STACK_ADJUST
value|128
end_define

begin_undef
undef|#
directive|undef
name|SIZEOF_CALL_DUMMY_WORDS
end_undef

begin_define
define|#
directive|define
name|SIZEOF_CALL_DUMMY_WORDS
value|0
end_define

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_ADDRESS
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_ADDRESS
parameter_list|()
value|entry_point_address()
end_define

begin_undef
undef|#
directive|undef
name|FIX_CALL_DUMMY
end_undef

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
end_define

begin_undef
undef|#
directive|undef
name|PUSH_RETURN_ADDRESS
end_undef

begin_define
define|#
directive|define
name|PUSH_RETURN_ADDRESS
parameter_list|(
name|PC
parameter_list|,
name|SP
parameter_list|)
value|sparc_at_entry_push_return_address (PC, SP)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc_at_entry_push_return_address
parameter_list|(
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|STORE_STRUCT_RETURN
end_undef

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
value|sparc_at_entry_store_struct_return (ADDR, SP)
end_define

begin_function_decl
specifier|extern
name|void
name|sparc_at_entry_store_struct_return
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * Old call dummy method, with CALL_DUMMY on the stack.  */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{		 0x9de3bec0fd3fa7f7LL, 0xf93fa7eff53fa7e7LL,\ 				 0xf13fa7dfed3fa7d7LL, 0xe93fa7cfe53fa7c7LL,\ 				 0xe13fa7bfdd3fa7b7LL, 0xd93fa7afd53fa7a7LL,\ 				 0xd13fa79fcd3fa797LL, 0xc93fa78fc53fa787LL,\ 				 0xc13fa77fcc3fa777LL, 0xc83fa76fc43fa767LL,\ 				 0xc03fa75ffc3fa757LL, 0xf83fa74ff43fa747LL,\ 				 0xf03fa73f01000000LL, 0x0100000001000000LL,\ 				 0x0100000091580000LL, 0xd027a72b93500000LL,\ 				 0xd027a72791480000LL, 0xd027a72391400000LL,\ 				 0xd027a71fda5ba8a7LL, 0xd85ba89fd65ba897LL,\ 				 0xd45ba88fd25ba887LL, 0x9fc02000d05ba87fLL,\ 				 0x0100000091d02001LL, 0x0100000001000000LL }
end_define

begin_comment
comment|/* 128 is to reserve space to write the %i/%l registers that will be restored    when we resume. */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_STACK_ADJUST
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_STACK_ADJUST
value|128
end_define

begin_comment
comment|/* Size of the call dummy in bytes. */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_LENGTH
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|192
end_define

begin_comment
comment|/* Offset within CALL_DUMMY of the 'call' instruction. */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_START_OFFSET
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|148
end_define

begin_comment
comment|/* Offset within CALL_DUMMY of the 'call' instruction. */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_CALL_OFFSET
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_CALL_OFFSET
value|(CALL_DUMMY_START_OFFSET + (5 * 4))
end_define

begin_comment
comment|/* Offset within CALL_DUMMY of the 'ta 1' instruction. */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_BREAKPOINT_OFFSET
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET
value|(CALL_DUMMY_START_OFFSET + (8 * 4))
end_define

begin_comment
comment|/* Let's GDB know that it can make a call_dummy breakpoint.  */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET_P
value|1
end_define

begin_comment
comment|/* Call dummy will be located on the stack.  */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_LOCATION
end_undef

begin_define
define|#
directive|define
name|CALL_DUMMY_LOCATION
value|ON_STACK
end_define

begin_comment
comment|/* Insert the function address into the call dummy.  */
end_comment

begin_undef
undef|#
directive|undef
name|FIX_CALL_DUMMY
end_undef

begin_define
define|#
directive|define
name|FIX_CALL_DUMMY
parameter_list|(
name|dummyname
parameter_list|,
name|pc
parameter_list|,
name|fun
parameter_list|,
name|nargs
parameter_list|,
name|args
parameter_list|,
name|type
parameter_list|,
name|gcc_p
parameter_list|)
define|\
value|sparc_fix_call_dummy (dummyname, pc, fun, type, gcc_p)
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
comment|/* The remainder of these will accept the default definition.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZEOF_CALL_DUMMY_WORDS
end_undef

begin_undef
undef|#
directive|undef
name|PUSH_RETURN_ADDRESS
end_undef

begin_undef
undef|#
directive|undef
name|CALL_DUMMY_ADDRESS
end_undef

begin_undef
undef|#
directive|undef
name|STORE_STRUCT_RETURN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Does the specified function use the "struct returning" convention    or the "value returning" convention?  The "value returning" convention    almost invariably returns the entire value in registers.  The    "struct returning" convention often returns the entire value in    memory, and passes a pointer (out of or into the function) saying    where the value (is or should go).     Since this sometimes depends on whether it was compiled with GCC,    this is also an argument.  This is used in call_function to build a    stack, and in value_being_returned to print return values.      On Sparc64, we only pass pointers to structs if they're larger than    32 bytes. Otherwise they're stored in %o0-%o3 (floating-point    values go into %fp0-%fp3).  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_STRUCT_CONVENTION
end_undef

begin_define
define|#
directive|define
name|USE_STRUCT_CONVENTION
parameter_list|(
name|gcc_p
parameter_list|,
name|type
parameter_list|)
value|(TYPE_LENGTH (type)> 32)
end_define

begin_function_decl
name|CORE_ADDR
name|sparc64_push_arguments
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

begin_undef
undef|#
directive|undef
name|PUSH_ARGUMENTS
end_undef

begin_define
define|#
directive|define
name|PUSH_ARGUMENTS
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|)
define|\
value|(sparc64_push_arguments ((A), (B), (C), (D), (E)))
end_define

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function. */
end_comment

begin_comment
comment|/* FIXME: V9 uses %o0 for this.  */
end_comment

begin_undef
undef|#
directive|undef
name|STORE_STRUCT_RETURN
end_undef

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
value|{ target_write_memory ((SP)+(16*8), (char *)&(ADDR), 8); }
end_define

begin_comment
comment|/* Stack must be aligned on 128-bit boundaries when synthesizing    function calls. */
end_comment

begin_undef
undef|#
directive|undef
name|STACK_ALIGN
end_undef

begin_define
define|#
directive|define
name|STACK_ALIGN
parameter_list|(
name|ADDR
parameter_list|)
value|(((ADDR) + 15 )& -16)
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_comment
comment|/* Some of these registers are only accessible from priviledged mode.    They are here for kernel debuggers, etc.  */
end_comment

begin_comment
comment|/* FIXME: icc and xcc are currently considered separate registers.    This may have to change and consider them as just one (ccr).    Let's postpone this as long as we can.  It's nice to be able to set    them individually.  */
end_comment

begin_comment
comment|/* FIXME: fcc0-3 are currently separate, even though they are also part of    fsr.  May have to remove them but let's postpone this as long as    possible.  It's nice to be able to set them individually.  */
end_comment

begin_comment
comment|/* FIXME: Whether to include f33, f35, etc. here is not clear.    There are advantages and disadvantages.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{ "g0", "g1", "g2", "g3", "g4", "g5", "g6", "g7",	\   "o0", "o1", "o2", "o3", "o4", "o5", "sp", "o7",	\   "l0", "l1", "l2", "l3", "l4", "l5", "l6", "l7",	\   "i0", "i1", "i2", "i3", "i4", "i5", "fp", "i7",	\ 								\   "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",		\   "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15",		\   "f16", "f17", "f18", "f19", "f20", "f21", "f22", "f23",	\   "f24", "f25", "f26", "f27", "f28", "f29", "f30", "f31",	\   "f32", "f34", "f36", "f38", "f40", "f42", "f44", "f46",	\   "f48", "f50", "f52", "f54", "f56", "f58", "f60", "f62",	\                                                                 \   "pc", "npc", "ccr", "fsr", "fprs", "y", "asi",		\   "ver", "tick", "pil", "pstate",				\   "tstate", "tba", "tl", "tt", "tpc", "tnpc", "wstate",		\   "cwp", "cansave", "canrestore", "cleanwin", "otherwin",	\   "asr16", "asr17", "asr18", "asr19", "asr20", "asr21",		\   "asr22", "asr23", "asr24", "asr25", "asr26", "asr27",		\   "asr28", "asr29", "asr30", "asr31",				\
comment|/* These are here at the end to simplify removing them if we have to.  */
value|\   "icc", "xcc", "fcc0", "fcc1", "fcc2", "fcc3"			\ }
end_define

begin_undef
undef|#
directive|undef
name|REG_STRUCT_HAS_ADDR
end_undef

begin_define
define|#
directive|define
name|REG_STRUCT_HAS_ADDR
parameter_list|(
name|gcc_p
parameter_list|,
name|type
parameter_list|)
value|(TYPE_LENGTH (type)> 32)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc64_read_sp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|sparc64_read_fp
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sparc64_write_sp
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sparc64_write_fp
parameter_list|(
name|CORE_ADDR
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|TARGET_READ_SP
parameter_list|()
value|(sparc64_read_sp ())
end_define

begin_define
define|#
directive|define
name|TARGET_READ_FP
parameter_list|()
value|(sparc64_read_fp ())
end_define

begin_define
define|#
directive|define
name|TARGET_WRITE_SP
parameter_list|(
name|X
parameter_list|)
value|(sparc64_write_sp (X))
end_define

begin_define
define|#
directive|define
name|TARGET_WRITE_FP
parameter_list|(
name|X
parameter_list|)
value|(sparc64_write_fp (X))
end_define

begin_undef
undef|#
directive|undef
name|EXTRACT_RETURN_VALUE
end_undef

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
value|sp64_extract_return_value(TYPE, REGBUF, VALBUF, 0)
end_define

begin_function_decl
specifier|extern
name|void
name|sp64_extract_return_value
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
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* defined in tm-sparc.h, replicated 				   for doc purposes */
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
name|SP_REGNUM
value|14
end_define

begin_comment
comment|/* Contains address of top of stack, \ 				   which is also the bottom of the frame.  */
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
name|FP_REGNUM
value|30
end_define

begin_comment
comment|/* Contains address of executing stack frame */
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
name|FP0_REGNUM
value|32
end_define

begin_comment
comment|/* Floating point register 0 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*#define FP_MAX_REGNUM 80*/
end_comment

begin_comment
comment|/* 1 + last fp reg number */
end_comment

begin_comment
comment|/* #undef v8 misc. regs */
end_comment

begin_undef
undef|#
directive|undef
name|Y_REGNUM
end_undef

begin_undef
undef|#
directive|undef
name|PS_REGNUM
end_undef

begin_undef
undef|#
directive|undef
name|WIM_REGNUM
end_undef

begin_undef
undef|#
directive|undef
name|TBR_REGNUM
end_undef

begin_undef
undef|#
directive|undef
name|PC_REGNUM
end_undef

begin_undef
undef|#
directive|undef
name|NPC_REGNUM
end_undef

begin_undef
undef|#
directive|undef
name|FPS_REGNUM
end_undef

begin_undef
undef|#
directive|undef
name|CPS_REGNUM
end_undef

begin_comment
comment|/* v9 misc. and priv. regs */
end_comment

begin_define
define|#
directive|define
name|C0_REGNUM
value|80
end_define

begin_comment
comment|/* Start of control registers */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|(C0_REGNUM + 0)
end_define

begin_comment
comment|/* Current PC */
end_comment

begin_define
define|#
directive|define
name|NPC_REGNUM
value|(C0_REGNUM + 1)
end_define

begin_comment
comment|/* Next PC */
end_comment

begin_define
define|#
directive|define
name|CCR_REGNUM
value|(C0_REGNUM + 2)
end_define

begin_comment
comment|/* Condition Code Register (%xcc,%icc) */
end_comment

begin_define
define|#
directive|define
name|FSR_REGNUM
value|(C0_REGNUM + 3)
end_define

begin_comment
comment|/* Floating Point State */
end_comment

begin_define
define|#
directive|define
name|FPRS_REGNUM
value|(C0_REGNUM + 4)
end_define

begin_comment
comment|/* Floating Point Registers State */
end_comment

begin_define
define|#
directive|define
name|Y_REGNUM
value|(C0_REGNUM + 5)
end_define

begin_comment
comment|/* Temp register for multiplication, etc.  */
end_comment

begin_define
define|#
directive|define
name|ASI_REGNUM
value|(C0_REGNUM + 6)
end_define

begin_comment
comment|/* Alternate Space Identifier */
end_comment

begin_define
define|#
directive|define
name|VER_REGNUM
value|(C0_REGNUM + 7)
end_define

begin_comment
comment|/* Version register */
end_comment

begin_define
define|#
directive|define
name|TICK_REGNUM
value|(C0_REGNUM + 8)
end_define

begin_comment
comment|/* Tick register */
end_comment

begin_define
define|#
directive|define
name|PIL_REGNUM
value|(C0_REGNUM + 9)
end_define

begin_comment
comment|/* Processor Interrupt Level */
end_comment

begin_define
define|#
directive|define
name|PSTATE_REGNUM
value|(C0_REGNUM + 10)
end_define

begin_comment
comment|/* Processor State */
end_comment

begin_define
define|#
directive|define
name|TSTATE_REGNUM
value|(C0_REGNUM + 11)
end_define

begin_comment
comment|/* Trap State */
end_comment

begin_define
define|#
directive|define
name|TBA_REGNUM
value|(C0_REGNUM + 12)
end_define

begin_comment
comment|/* Trap Base Address */
end_comment

begin_define
define|#
directive|define
name|TL_REGNUM
value|(C0_REGNUM + 13)
end_define

begin_comment
comment|/* Trap Level */
end_comment

begin_define
define|#
directive|define
name|TT_REGNUM
value|(C0_REGNUM + 14)
end_define

begin_comment
comment|/* Trap Type */
end_comment

begin_define
define|#
directive|define
name|TPC_REGNUM
value|(C0_REGNUM + 15)
end_define

begin_comment
comment|/* Trap pc */
end_comment

begin_define
define|#
directive|define
name|TNPC_REGNUM
value|(C0_REGNUM + 16)
end_define

begin_comment
comment|/* Trap npc */
end_comment

begin_define
define|#
directive|define
name|WSTATE_REGNUM
value|(C0_REGNUM + 17)
end_define

begin_comment
comment|/* Window State */
end_comment

begin_define
define|#
directive|define
name|CWP_REGNUM
value|(C0_REGNUM + 18)
end_define

begin_comment
comment|/* Current Window Pointer */
end_comment

begin_define
define|#
directive|define
name|CANSAVE_REGNUM
value|(C0_REGNUM + 19)
end_define

begin_comment
comment|/* Savable Windows */
end_comment

begin_define
define|#
directive|define
name|CANRESTORE_REGNUM
value|(C0_REGNUM + 20)
end_define

begin_comment
comment|/* Restorable Windows */
end_comment

begin_define
define|#
directive|define
name|CLEANWIN_REGNUM
value|(C0_REGNUM + 21)
end_define

begin_comment
comment|/* Clean Windows */
end_comment

begin_define
define|#
directive|define
name|OTHERWIN_REGNUM
value|(C0_REGNUM + 22)
end_define

begin_comment
comment|/* Other Windows */
end_comment

begin_define
define|#
directive|define
name|ASR_REGNUM
parameter_list|(
name|n
parameter_list|)
value|(C0_REGNUM+(23-16)+(n))
end_define

begin_comment
comment|/* Ancillary State Register 						   (n = 16...31) */
end_comment

begin_define
define|#
directive|define
name|ICC_REGNUM
value|(C0_REGNUM + 39)
end_define

begin_comment
comment|/* 32 bit condition codes */
end_comment

begin_define
define|#
directive|define
name|XCC_REGNUM
value|(C0_REGNUM + 40)
end_define

begin_comment
comment|/* 64 bit condition codes */
end_comment

begin_define
define|#
directive|define
name|FCC0_REGNUM
value|(C0_REGNUM + 41)
end_define

begin_comment
comment|/* fp cc reg 0 */
end_comment

begin_define
define|#
directive|define
name|FCC1_REGNUM
value|(C0_REGNUM + 42)
end_define

begin_comment
comment|/* fp cc reg 1 */
end_comment

begin_define
define|#
directive|define
name|FCC2_REGNUM
value|(C0_REGNUM + 43)
end_define

begin_comment
comment|/* fp cc reg 2 */
end_comment

begin_define
define|#
directive|define
name|FCC3_REGNUM
value|(C0_REGNUM + 44)
end_define

begin_comment
comment|/* fp cc reg 3 */
end_comment

begin_comment
comment|/* Number of machine registers.  */
end_comment

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_define
define|#
directive|define
name|NUM_REGS
value|125
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.    Some of the registers aren't 64 bits, but it's a lot simpler just to assume    they all are (since most of them are).  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_BYTES
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(32*8+32*8+45*8)
end_define

begin_comment
comment|/* Index within `registers' of the first byte of the space for    register N.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_BYTE
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)< 32 ? (N)*8				\    : (N)< 64 ? 32*8 + ((N)-32)*4		\    : (N)< C0_REGNUM ? 32*8 + 32*4 + ((N)-64)*8	\    : 64*8 + ((N)-C0_REGNUM)*8)
end_define

begin_comment
comment|/* Say how long (ordinary) registers are.  This is a piece of bogosity    used in push_word and a few other places; REGISTER_RAW_SIZE is the    real way to know how big a register is.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_SIZE
end_undef

begin_define
define|#
directive|define
name|REGISTER_SIZE
value|8
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_RAW_SIZE
end_undef

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)< 32 ? 8 : (N)< 64 ? 4 : 8)
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_VIRTUAL_SIZE
end_undef

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)< 32 ? 8 : (N)< 64 ? 4 : 8)
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_comment
comment|/* tm-sparc.h defines this as 8, but play it safe.  */
end_comment

begin_undef
undef|#
directive|undef
name|MAX_REGISTER_RAW_SIZE
end_undef

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|8
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_comment
comment|/* tm-sparc.h defines this as 8, but play it safe.  */
end_comment

begin_undef
undef|#
directive|undef
name|MAX_REGISTER_VIRTUAL_SIZE
end_undef

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|8
end_define

begin_comment
comment|/* Return the GDB type object for the "standard" data type    of data in register N.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_VIRTUAL_TYPE
end_undef

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_TYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N)< 32 ? builtin_type_long_long \   : (N)< 64 ? builtin_type_float \   : (N)< 80 ? builtin_type_double \   : builtin_type_long_long)
end_define

begin_comment
comment|/* We use to support both 32 bit and 64 bit pointers.    We can't anymore because TARGET_PTR_BIT must now be a constant.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_PTR_BIT
end_undef

begin_define
define|#
directive|define
name|TARGET_PTR_BIT
value|64
end_define

begin_comment
comment|/* Longs are 64 bits. */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_LONG_BIT
end_undef

begin_define
define|#
directive|define
name|TARGET_LONG_BIT
value|64
end_define

begin_undef
undef|#
directive|undef
name|TARGET_LONG_LONG_BIT
end_undef

begin_define
define|#
directive|define
name|TARGET_LONG_LONG_BIT
value|64
end_define

begin_comment
comment|/* Return number of bytes at start of arglist that are not really args.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_ARGS_SKIP
end_undef

begin_define
define|#
directive|define
name|FRAME_ARGS_SKIP
value|136
end_define

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
comment|/* Offsets into jmp_buf.    FIXME: This was borrowed from the v8 stuff and will probably have to change    for v9.  */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|8
end_define

begin_comment
comment|/* Size of each element in jmp_buf */
end_comment

begin_define
define|#
directive|define
name|JB_ONSSTACK
value|0
end_define

begin_define
define|#
directive|define
name|JB_SIGMASK
value|1
end_define

begin_define
define|#
directive|define
name|JB_SP
value|2
end_define

begin_define
define|#
directive|define
name|JB_PC
value|3
end_define

begin_define
define|#
directive|define
name|JB_NPC
value|4
end_define

begin_define
define|#
directive|define
name|JB_PSR
value|5
end_define

begin_define
define|#
directive|define
name|JB_G1
value|6
end_define

begin_define
define|#
directive|define
name|JB_O0
value|7
end_define

begin_define
define|#
directive|define
name|JB_WBCNT
value|8
end_define

begin_comment
comment|/* Figure out where the longjmp will land.  We expect that we have    just entered longjmp and haven't yet setup the stack frame, so the    args are still in the output regs.  %o0 (O0_REGNUM) points at the    jmp_buf structure from which we extract the pc (JB_PC) that we will    land at.  The pc is copied into ADDR.  This routine returns true on    success */
end_comment

begin_function_decl
specifier|extern
name|int
name|get_longjmp_target
parameter_list|(
name|CORE_ADDR
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|ADDR
parameter_list|)
value|get_longjmp_target(ADDR)
end_define

begin_undef
undef|#
directive|undef
name|TM_PRINT_INSN_MACH
end_undef

begin_define
define|#
directive|define
name|TM_PRINT_INSN_MACH
value|bfd_mach_sparc_v9a
end_define

end_unit

