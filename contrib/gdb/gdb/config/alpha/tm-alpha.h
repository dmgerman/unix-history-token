begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on an Alpha box under OSF1.  This is    also used by the Alpha/Netware and Alpha/Linux targets.    Copyright 1993, 1994, 1995, 1996 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_ALPHA_H
end_ifndef

begin_define
define|#
directive|define
name|TM_ALPHA_H
end_define

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"coff/sym.h"
end_include

begin_comment
comment|/* Needed for PDR below.  */
end_comment

begin_include
include|#
directive|include
file|"coff/symconst.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

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
name|symbol
struct_decl|;
end_struct_decl

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
name|TARGET_BYTE_ORDER
argument_list|)
end_if

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Redefine some target bit sizes from the default.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_LONG_BIT
value|64
end_define

begin_define
define|#
directive|define
name|TARGET_LONG_LONG_BIT
value|64
end_define

begin_define
define|#
directive|define
name|TARGET_PTR_BIT
value|64
end_define

begin_comment
comment|/* Floating point is IEEE compliant */
end_comment

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_comment
comment|/* Number of traps that happen between exec'ing the shell   * to run an inferior, and when we finally get to   * the inferior code.  This is 2 on most implementations.  */
end_comment

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|3
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
comment|/* Advance PC across any function entry prologue instructions    to reach some "real" code.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
value|pc = alpha_skip_prologue(pc, 0)
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|alpha_skip_prologue
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|addr
operator|,
name|int
name|lenient
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Immediately after a function call, return the saved pc.    Can't always go through the frames for this because on some machines    the new frame is not set up until the new function executes    some instructions.  */
end_comment

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
value|alpha_saved_pc_after_call(frame)
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|alpha_saved_pc_after_call
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Are we currently handling a signal ?  */
end_comment

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|((name)&& STREQ ("__sigtramp", (name)))
end_define

begin_comment
comment|/* Stack grows downward.  */
end_comment

begin_define
define|#
directive|define
name|INNER_THAN
parameter_list|(
name|lhs
parameter_list|,
name|rhs
parameter_list|)
value|((lhs)< (rhs))
end_define

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x80, 0, 0, 0}
end_define

begin_comment
comment|/* call_pal bpt */
end_comment

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.    This is often the number of bytes in BREAKPOINT    but not always.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DECR_PC_AFTER_BREAK
end_ifndef

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Say how long (ordinary) registers are.  This is a piece of bogosity    used in push_word and a few other places; REGISTER_RAW_SIZE is the    real way to know how big a register is.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_SIZE
value|8
end_define

begin_comment
comment|/* Number of machine registers */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|66
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{	"v0",	"t0",	"t1",	"t2",	"t3",	"t4",	"t5",	"t6", \ 	"t7",	"s0",	"s1",	"s2",	"s3",	"s4",	"s5",	"fp", \ 	"a0",	"a1",	"a2",	"a3",	"a4",	"a5",	"t8",	"t9", \ 	"t10",	"t11",	"ra",	"t12",	"at",	"gp",	"sp",	"zero", \ 	"f0",   "f1",   "f2",   "f3",   "f4",   "f5",   "f6",   "f7", \ 	"f8",   "f9",   "f10",  "f11",  "f12",  "f13",  "f14",  "f15", \ 	"f16",  "f17",  "f18",  "f19",  "f20",  "f21",  "f22",  "f23",\ 	"f24",  "f25",  "f26",  "f27",  "f28",  "f29",  "f30",  "f31",\ 	"pc",	"vfp",						\     }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that most of these values are "real" register numbers,    and correspond to the general registers of the machine,    and FP_REGNUM is a "phony" register number which is too large    to be an actual register number as far as the user is concerned    but serves to get the desired value when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|V0_REGNUM
value|0
end_define

begin_comment
comment|/* Function integer return value */
end_comment

begin_define
define|#
directive|define
name|T7_REGNUM
value|8
end_define

begin_comment
comment|/* Return address register for OSF/1 __add* */
end_comment

begin_define
define|#
directive|define
name|GCC_FP_REGNUM
value|15
end_define

begin_comment
comment|/* Used by gcc as frame register */
end_comment

begin_define
define|#
directive|define
name|A0_REGNUM
value|16
end_define

begin_comment
comment|/* Loc of first arg during a subr call */
end_comment

begin_define
define|#
directive|define
name|T9_REGNUM
value|23
end_define

begin_comment
comment|/* Return address register for OSF/1 __div* */
end_comment

begin_define
define|#
directive|define
name|T12_REGNUM
value|27
end_define

begin_comment
comment|/* Contains start addr of current proc */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|30
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|RA_REGNUM
value|26
end_define

begin_comment
comment|/* Contains return address value */
end_comment

begin_define
define|#
directive|define
name|ZERO_REGNUM
value|31
end_define

begin_comment
comment|/* Read-only register, always 0 */
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
name|FPA0_REGNUM
value|48
end_define

begin_comment
comment|/* First float arg during a subr call */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|64
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|65
end_define

begin_comment
comment|/* Virtual frame pointer */
end_comment

begin_define
define|#
directive|define
name|CANNOT_FETCH_REGISTER
parameter_list|(
name|regno
parameter_list|)
define|\
value|((regno) == FP_REGNUM || (regno) == ZERO_REGNUM)
end_define

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regno
parameter_list|)
define|\
value|((regno) == FP_REGNUM || (regno) == ZERO_REGNUM)
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(NUM_REGS * 8)
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
value|((N) * 8)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On Alphas, all regs are 8 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|8
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  On Alphas, all regs are 8 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|8
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
comment|/* Nonzero if register N requires conversion    from raw format to virtual format.    The alpha needs a conversion between register and memory format if    the register is a floating point register and       memory format is float, as the register format must be double    or       memory format is an integer with 4 bytes or less, as the representation       of integers in floating point registers is different. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|N
parameter_list|)
value|((N)>= FP0_REGNUM&& (N)< FP0_REGNUM + 32)
end_define

begin_comment
comment|/* Convert data from raw format for register REGNUM in buffer FROM    to virtual format with type TYPE in buffer TO.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|REGNUM
parameter_list|,
name|TYPE
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|alpha_register_convert_to_virtual (REGNUM, TYPE, FROM, TO)
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_register_convert_to_virtual
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert data from virtual format with type TYPE in buffer FROM    to raw format for register REGNUM in buffer TO.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_RAW
parameter_list|(
name|TYPE
parameter_list|,
name|REGNUM
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|alpha_register_convert_to_raw (TYPE, REGNUM, FROM, TO)
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_register_convert_to_raw
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|int
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|(((N)>= FP0_REGNUM&& (N)< FP0_REGNUM+32)  \ 	 ? builtin_type_double : builtin_type_long)
end_define

begin_comment
unit|\
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  Handled by alpha_push_arguments.  */
end_comment

begin_define
define|#
directive|define
name|STORE_STRUCT_RETURN
parameter_list|(
name|addr
parameter_list|,
name|sp
parameter_list|)
end_define

begin_comment
comment|/**/
end_comment

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  */
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
value|alpha_extract_return_value(TYPE, REGBUF, VALBUF)
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_extract_return_value
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write into appropriate registers a function return value    of type TYPE, given in virtual format.  */
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
value|alpha_store_return_value(TYPE, VALBUF)
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_store_return_value
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    the address in which a function should return its structure value,    as a CORE_ADDR (or an expression that can be used as one).  */
end_comment

begin_comment
comment|/* The address is passed in a0 upon entry to the function, but when    the function exits, the compiler has copied the value to v0.  This    convention is specified by the System V ABI, so I think we can rely    on it.  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS
parameter_list|(
name|REGBUF
parameter_list|)
define|\
value|(extract_address (REGBUF + REGISTER_BYTE (V0_REGNUM), \ 		    REGISTER_RAW_SIZE (V0_REGNUM)))
end_define

begin_comment
comment|/* Structures are returned by ref in extra arg0 */
end_comment

begin_define
define|#
directive|define
name|USE_STRUCT_CONVENTION
parameter_list|(
name|gcc_p
parameter_list|,
name|type
parameter_list|)
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer. */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
value|(CORE_ADDR) alpha_frame_chain (thisframe)
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|alpha_frame_chain
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Define other aspects of the stack frame.  */
end_comment

begin_comment
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.  */
end_comment

begin_comment
comment|/* We handle this differently for alpha, and maybe we should not */
end_comment

begin_define
define|#
directive|define
name|FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|FI
parameter_list|,
name|FRAMELESS
parameter_list|)
value|{(FRAMELESS) = 0;}
end_define

begin_comment
comment|/* Saved Pc.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|(alpha_frame_saved_pc(FRAME))
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|alpha_frame_saved_pc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* The alpha has two different virtual pointers for arguments and locals.     The virtual argument pointer is pointing to the bottom of the argument    transfer area, which is located immediately below the virtual frame    pointer. Its size is fixed for the native compiler, it is either zero    (for the no arguments case) or large enough to hold all argument registers.    gcc uses a variable sized argument transfer area. As it has    to stay compatible with the native debugging tools it has to use the same    virtual argument pointer and adjust the argument offsets accordingly.     The virtual local pointer is localoff bytes below the virtual frame    pointer, the value of localoff is obtained from the PDR.  */
end_comment

begin_define
define|#
directive|define
name|ALPHA_NUM_ARG_REGS
value|6
end_define

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|((fi)->frame - (ALPHA_NUM_ARG_REGS * 8))
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|((fi)->frame - (fi)->localoff)
end_define

begin_comment
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|num
parameter_list|,
name|fi
parameter_list|)
value|((num) = -1)
end_define

begin_comment
comment|/* Return number of bytes at start of arglist that are not really args.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_SKIP
value|0
end_define

begin_comment
comment|/* Put here the code to store, into a struct frame_saved_regs,    the addresses of the saved registers of frame described by FRAME_INFO.    This includes special registers such as pc and fp saved in special    ways in the stack frame.  sp is even more special:    the address we return for it IS the sp for the next frame.  */
end_comment

begin_decl_stmt
specifier|extern
name|void
name|alpha_find_saved_regs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FRAME_INIT_SAVED_REGS
parameter_list|(
name|frame_info
parameter_list|)
define|\
value|do { \     if ((frame_info)->saved_regs == NULL) \       alpha_find_saved_regs (frame_info); \     (frame_info)->saved_regs[SP_REGNUM] = (frame_info)->frame; \   } while (0)
end_define

begin_escape
end_escape

begin_comment
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_ARGUMENTS
parameter_list|(
name|nargs
parameter_list|,
name|args
parameter_list|,
name|sp
parameter_list|,
name|struct_return
parameter_list|,
name|struct_addr
parameter_list|)
define|\
value|sp = alpha_push_arguments((nargs), (args), (sp), (struct_return), (struct_addr))
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|alpha_push_arguments
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|value
operator|*
operator|*
operator|,
name|CORE_ADDR
operator|,
name|int
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
value|alpha_push_dummy_frame()
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_push_dummy_frame
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
value|alpha_pop_frame()
end_define

begin_decl_stmt
specifier|extern
name|void
name|alpha_pop_frame
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Alpha OSF/1 inhibits execution of code on the stack.    But there is no need for a dummy on the alpha. PUSH_ARGUMENTS    takes care of all argument handling and bp_call_dummy takes care    of stopping the dummy.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_LOCATION
value|AT_ENTRY_POINT
end_define

begin_comment
comment|/* On the Alpha the call dummy code is never copied to user space,    stopping the user call is achieved via a bp_call_dummy breakpoint.    But we need a fake CALL_DUMMY definition to enable the proper    call_function_by_hand and to avoid zero length array warnings    in valops.c  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{ 0 }
end_define

begin_comment
comment|/* Content doesn't matter. */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|(0)
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET
value|(0)
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|alpha_call_dummy_address
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|CALL_DUMMY_ADDRESS
parameter_list|()
value|alpha_call_dummy_address()
end_define

begin_comment
comment|/* Insert the specified number of args and function address    into a call sequence of the above form stored at DUMMYNAME.    We only have to set RA_REGNUM to the dummy breakpoint address    and T12_REGNUM (the `procedure value register') to the function address.  */
end_comment

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
value|{									\   CORE_ADDR bp_address = CALL_DUMMY_ADDRESS ();			\   if (bp_address == 0)							\     error ("no place to put call");					\   write_register (RA_REGNUM, bp_address);				\   write_register (T12_REGNUM, fun);					\ }
end_define

begin_comment
comment|/* There's a mess in stack frame creation.  See comments in blockframe.c    near reference to INIT_FRAME_PC_FIRST.  */
end_comment

begin_define
define|#
directive|define
name|INIT_FRAME_PC
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
end_define

begin_comment
comment|/* nada */
end_comment

begin_define
define|#
directive|define
name|INIT_FRAME_PC_FIRST
parameter_list|(
name|fromleaf
parameter_list|,
name|prev
parameter_list|)
define|\
value|(prev)->pc = ((fromleaf) ? SAVED_PC_AFTER_CALL ((prev)->next) : \ 	      (prev)->next ? FRAME_SAVED_PC ((prev)->next) : read_pc ());
end_define

begin_comment
comment|/* Special symbol found in blocks associated with routines.  We can hang    alpha_extra_func_info_t's off of this.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_EFI_SYMBOL_NAME
value|"__GDB_EFI_INFO__"
end_define

begin_decl_stmt
specifier|extern
name|void
name|ecoff_relocate_efi
name|PARAMS
argument_list|(
operator|(
expr|struct
name|symbol
operator|*
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Specific information about a procedure.    This overlays the ALPHA's PDR records,     alpharead.c (ab)uses this to save memory */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|alpha_extra_func_info
block|{
name|long
name|numargs
decl_stmt|;
comment|/* number of args to procedure (was iopt) */
name|PDR
name|pdr
decl_stmt|;
comment|/* Procedure descriptor record */
block|}
typedef|*
name|alpha_extra_func_info_t
typedef|;
end_typedef

begin_comment
comment|/* Define the extra_func_info that mipsread.c needs.    FIXME: We should define our own PDR interface, perhaps in a separate    header file. This would get rid of the<bfd.h> inclusion in all sources    and would abstract the mips/alpha interface from ecoff.  */
end_comment

begin_define
define|#
directive|define
name|mips_extra_func_info
value|alpha_extra_func_info
end_define

begin_define
define|#
directive|define
name|mips_extra_func_info_t
value|alpha_extra_func_info_t
end_define

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
define|\
value|int localoff; \   int pc_reg; \   alpha_extra_func_info_t proc_desc;
end_define

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO
parameter_list|(
name|fromleaf
parameter_list|,
name|fci
parameter_list|)
value|init_extra_frame_info(fci)
end_define

begin_decl_stmt
specifier|extern
name|void
name|init_extra_frame_info
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PRINT_EXTRA_FRAME_INFO
parameter_list|(
name|fi
parameter_list|)
define|\
value|{ \     if (fi&& fi->proc_desc&& fi->proc_desc->pdr.framereg< NUM_REGS) \       printf_filtered (" frame pointer is at %s+%d\n", \                        REGISTER_NAME (fi->proc_desc->pdr.framereg), \                                  fi->proc_desc->pdr.frameoffset); \   }
end_define

begin_comment
comment|/* It takes two values to specify a frame on the ALPHA.  Sigh.     In fact, at the moment, the *PC* is the primary value that sets up    a frame.  The PC is looked up to see what function it's in; symbol    information from that function tells us which register is the frame    pointer base, and what offset from there is the "virtual frame pointer".    (This is usually an offset from SP.)  FIXME -- this should be cleaned    up so that the primary value is the SP, and the PC is used to disambiguate    multiple functions with the same SP that are at different stack levels. */
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

begin_decl_stmt
specifier|extern
name|struct
name|frame_info
modifier|*
name|setup_arbitrary_frame
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* This is used by heuristic_proc_start.  It should be shot it the head.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FreeBSD__
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|VM_MIN_ADDRESS
end_ifndef

begin_define
define|#
directive|define
name|VM_MIN_ADDRESS
value|(CORE_ADDR)0x120000000
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
comment|/* If PC is in a shared library trampoline code, return the PC    where the function itself actually starts.  If not, return 0.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_TRAMPOLINE_CODE
parameter_list|(
name|pc
parameter_list|)
value|find_solib_trampoline_target (pc)
end_define

begin_comment
comment|/* If the current gcc for for this target does not produce correct debugging    information for float parameters, both prototyped and unprototyped, then    define this macro.  This forces gdb to  always assume that floats are    passed as doubles and then converted in the callee.     For the alpha, it appears that the debug info marks the parameters as    floats regardless of whether the function is prototyped, but the actual    values are always passed in as doubles.  Thus by setting this to 1, both    types of calls will work. */
end_comment

begin_define
define|#
directive|define
name|COERCE_FLOAT_TO_DOUBLE
value|1
end_define

begin_comment
comment|/* Return TRUE if procedure descriptor PROC is a procedure descriptor    that refers to a dynamically generated sigtramp function.     OSF/1 doesn't use dynamic sigtramp functions, so this is always    FALSE.  */
end_comment

begin_define
define|#
directive|define
name|PROC_DESC_IS_DYN_SIGTRAMP
parameter_list|(
name|proc
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|SET_PROC_DESC_IS_DYN_SIGTRAMP
parameter_list|(
name|proc
parameter_list|)
end_define

begin_comment
comment|/* If PC is inside a dynamically generated sigtramp function, return    how many bytes the program counter is beyond the start of that    function.  Otherwise, return a negative value.     OSF/1 doesn't use dynamic sigtramp functions, so this always    returns -1.  */
end_comment

begin_define
define|#
directive|define
name|DYNAMIC_SIGTRAMP_OFFSET
parameter_list|(
name|pc
parameter_list|)
value|(-1)
end_define

begin_comment
comment|/* Translate a signal handler frame into the address of the sigcontext    structure.  */
end_comment

begin_define
define|#
directive|define
name|SIGCONTEXT_ADDR
parameter_list|(
name|frame
parameter_list|)
define|\
value|(read_memory_integer ((frame)->next ? frame->next->frame : frame->frame, 8))
end_define

begin_comment
comment|/* If FRAME refers to a sigtramp frame, return the address of the next    frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_PAST_SIGTRAMP_FRAME
parameter_list|(
name|frame
parameter_list|,
name|pc
parameter_list|)
define|\
value|(alpha_osf_skip_sigtramp_frame (frame, pc))
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|alpha_osf_skip_sigtramp_frame
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|,
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_ALPHA_H */
end_comment

end_unit

