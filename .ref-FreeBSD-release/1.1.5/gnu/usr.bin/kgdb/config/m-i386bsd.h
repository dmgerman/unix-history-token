begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * This code is derived from software copyrighted by the Free Software  * Foundation.  *  * Modified 1991 by Donn Seeley at UUNET Technologies, Inc.  * Modified 1991 by William Jolitz at UUNET Technologies, Inc.  *  *	@(#)m-i386bsd.h	6.7 (Berkeley) 5/8/91  */
end_comment

begin_comment
comment|/* Macro definitions for i386.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Define the bit, byte, and word ordering of the machine.  */
end_comment

begin_comment
comment|/* #define BITS_BIG_ENDIAN  */
end_comment

begin_comment
comment|/* #define BYTES_BIG_ENDIAN */
end_comment

begin_comment
comment|/* #define WORDS_BIG_ENDIAN */
end_comment

begin_comment
comment|/*  * Changes for 80386 by Pace Willisson (pace@prep.ai.mit.edu)  * July 1988  * [ MODIFIED FOR 386BSD W. Jolitz ]  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|i386
end_ifndef

begin_define
define|#
directive|define
name|i386
value|1
end_define

begin_define
define|#
directive|define
name|i386b
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_define
define|#
directive|define
name|LONG_LONG
end_define

begin_comment
comment|/* Library stuff: POSIX tty (not supported yet), V7 tty (sigh), vprintf.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS
value|1
end_define

begin_define
define|#
directive|define
name|USE_OLD_TTY
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* We support local and remote kernel debugging.  */
end_comment

begin_define
define|#
directive|define
name|KERNELDEBUG
value|1
end_define

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
end_define

begin_comment
comment|/* Specify debugger information format.  */
end_comment

begin_define
define|#
directive|define
name|READ_DBX_FORMAT
end_define

begin_comment
comment|/* number of traps that happen between exec'ing the shell   * to run an inferior, and when we finally get to   * the inferior code.  This is 2 on most implementations.  */
end_comment

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|2
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
name|frompc
parameter_list|)
value|{(frompc) = i386_skip_prologue((frompc));}
end_define

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
define|\
value|(read_memory_integer (read_register (SP_REGNUM), 4))
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEWVM
end_ifdef

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|USRSTACK
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0xfdffd000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|KERNEL_U_ADDR
end_define

begin_comment
comment|/* Stack grows downward.  */
end_comment

begin_define
define|#
directive|define
name|INNER_THAN
value|<
end_define

begin_comment
comment|/* Sequence of bytes for breakpoint instruction.  */
end_comment

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0xcc}
end_define

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.    This is often the number of bytes in BREAKPOINT    but not always.  */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|1
end_define

begin_comment
comment|/* Nonzero if instruction at PC is a return instruction.  */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
define|\
value|strchr("\302\303\312\313\317", read_memory_integer(pc, 1))
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.    LEN is the length in bytes -- not relevant on the 386.  */
end_comment

begin_define
define|#
directive|define
name|INVALID_FLOAT
parameter_list|(
name|p
parameter_list|,
name|len
parameter_list|)
value|(0)
end_define

begin_comment
comment|/* code to execute to print interesting information about the  * floating point processor (if any)  * No need to define if there is nothing to do.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_INFO
value|{ i386_float_info (); }
end_define

begin_comment
comment|/* Largest integer type */
end_comment

begin_define
define|#
directive|define
name|LONGEST
value|long long
end_define

begin_comment
comment|/* Name of the builtin type for the LONGEST type above. */
end_comment

begin_define
define|#
directive|define
name|BUILTIN_TYPE_LONGEST
value|builtin_type_long_long
end_define

begin_comment
comment|/* Say how long (ordinary) registers are.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_TYPE
value|long
end_define

begin_comment
comment|/* Number of machine registers */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|16
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_comment
comment|/* the order of the first 8 registers must match the compiler's   * numbering scheme (which is the same as the 386 scheme)  * also, this table must match regmap in i386-pinsn.c.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{ "eax", "ecx", "edx", "ebx", \ 			 "esp", "ebp", "esi", "edi", \ 			 "eip", "ps", "cs", "ss", \ 			 "ds", "es", "fs", "gs", \ 			 }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|5
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|4
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|8
end_define

begin_define
define|#
directive|define
name|PS_REGNUM
value|9
end_define

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|(addr) = i386_register_u_addr ((blockend),(regno));
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(NUM_REGS * 4)
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
comment|/* Number of bytes of storage in the actual machine representation    for register N.  */
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
comment|/* Number of bytes of storage in the program's representation    for register N. */
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
value|4
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|4
end_define

begin_comment
comment|/* Nonzero if register N requires conversion    from raw format to virtual format.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|N
parameter_list|)
value|(0)
end_define

begin_comment
comment|/* Convert data from raw format for register REGNUM    to virtual format for register REGNUM.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|REGNUM
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
value|{bcopy ((FROM), (TO), 4);}
end_define

begin_comment
comment|/* Convert data from virtual format for register REGNUM    to raw format for register REGNUM.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_RAW
parameter_list|(
name|REGNUM
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
value|{bcopy ((FROM), (TO), 4);}
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
value|(builtin_type_int)
end_define

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function. */
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
value|{ (SP) -= sizeof (ADDR);		\     write_memory ((SP),&(ADDR), sizeof (ADDR)); }
end_define

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
value|bcopy (REGBUF, VALBUF, TYPE_LENGTH (TYPE))
end_define

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
value|write_register_bytes (0, VALBUF, TYPE_LENGTH (TYPE))
end_define

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
value|(*(int *)(REGBUF))
end_define

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer.     FRAME_CHAIN_COMBINE takes the chain pointer and the frame's nominal address    and produces the nominal address of the caller frame.     However, if FRAME_CHAIN_VALID returns zero,    it means the given frame is the outermost one and has no caller.    In that case, FRAME_CHAIN_COMBINE is not used.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(outside_startup_file ((thisframe)->pc) ? \    read_memory_integer ((thisframe)->frame, 4) :\    0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNELDEBUG
end_ifdef

begin_define
define|#
directive|define
name|KERNTEXT_BASE
value|0xfe000000
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|NEWVM
end_ifdef

begin_define
define|#
directive|define
name|KERNSTACK_TOP
value|(read_register(SP_REGNUM) + 0x2000)
end_define

begin_comment
comment|/* approximate */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* #define KERNSTACK_TOP (P1PAGES<< PGSHIFT) */
end_comment

begin_define
define|#
directive|define
name|KERNSTACK_TOP
value|0xfe000000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|int
name|kernel_debugging
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
define|\
value|(chain != 0&& \ 	 !kernel_debugging ? outside_startup_file(FRAME_SAVED_PC(thisframe)) :\ 	 (chain>= read_register(SP_REGNUM)&& chain< KERNSTACK_TOP))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
define|\
value|(chain != 0&& (outside_startup_file (FRAME_SAVED_PC (thisframe))))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FRAME_CHAIN_COMBINE
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
value|(chain)
end_define

begin_comment
comment|/* Define other aspects of the stack frame.  */
end_comment

begin_comment
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.  */
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
define|\
value|FRAMELESS_LOOK_FOR_PROLOGUE(FI, FRAMELESS)
end_define

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|(read_memory_integer ((FRAME)->frame + 4, 4))
end_define

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|((fi)->frame)
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|((fi)->frame)
end_define

begin_comment
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|numargs
parameter_list|,
name|fi
parameter_list|)
value|(numargs) = i386_frame_num_args(fi)
end_define

begin_comment
comment|/* Return number of bytes at start of arglist that are not really args.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_SKIP
value|8
end_define

begin_comment
comment|/* Put here the code to store, into a struct frame_saved_regs,    the addresses of the saved registers of frame described by FRAME_INFO.    This includes special registers such as pc and fp saved in special    ways in the stack frame.  sp is even more special:    the address we return for it IS the sp for the next frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_FIND_SAVED_REGS
parameter_list|(
name|frame_info
parameter_list|,
name|frame_saved_regs
parameter_list|)
define|\
value|{ i386_frame_find_saved_regs ((frame_info),&(frame_saved_regs)); }
end_define

begin_escape
end_escape

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
value|{ i386_pop_frame (); }
end_define

begin_define
define|#
directive|define
name|NEW_CALL_FUNCTION
end_define

begin_escape
end_escape

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Interface definitions for kernel debugger KDB.  */
end_comment

begin_comment
comment|/* Map machine fault codes into signal numbers.    First subtract 0, divide by 4, then index in a table.    Faults for which the entry in this table is 0    are not handled by KDB; the program's own trap handler    gets to handle then.  */
end_comment

begin_define
define|#
directive|define
name|FAULT_CODE_ORIGIN
value|0
end_define

begin_define
define|#
directive|define
name|FAULT_CODE_UNITS
value|4
end_define

begin_define
define|#
directive|define
name|FAULT_TABLE
define|\
value|{ 0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0}
end_define

begin_comment
comment|/* Start running with a stack stretching from BEG to END.    BEG and END should be symbols meaningful to the assembler.    This is used only for kdb.  */
end_comment

begin_define
define|#
directive|define
name|INIT_STACK
parameter_list|(
name|beg
parameter_list|,
name|end
parameter_list|)
value|{}
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
value|{}
end_define

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME_PTR
value|{}
end_define

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_REGISTERS
value|{}
end_define

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
value|{}
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

