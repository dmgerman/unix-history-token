begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a Sequent Symmetry under dynix 3.0,    with Weitek 1167 and i387 support.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Symmetry version by Jay Vosburgh (uunet!sequent!fubar) */
end_comment

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_define
define|#
directive|define
name|SYMMETRY
end_define

begin_comment
comment|/* This machine doesn't have the siginterrupt call.  */
end_comment

begin_define
define|#
directive|define
name|NO_SIGINTERRUPT
end_define

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

begin_comment
comment|/* Define the bit, byte, and word ordering of the machine.  */
end_comment

begin_comment
comment|/* #define BITS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* #define BYTES_BIG_ENDIAN */
end_comment

begin_comment
comment|/* #define WORDS_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Define SFILE_FN_FLAGGED if the source file is flagged with an N_FN    symbol instead of an N_TEXT symbol.  */
end_comment

begin_define
define|#
directive|define
name|OFILE_FN_FLAGGED
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
comment|/* Debugger information will be in DBX format.  */
end_comment

begin_define
define|#
directive|define
name|READ_DBX_FORMAT
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
comment|/* Advance PC across any function entry prologue instructions    to reach some "real" code.  From m-i386.h */
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
value|read_memory_integer(read_register(SP_REGNUM), 4)
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|(0x80000000 - (UPAGES * NBPG))
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0x40000000 - (UPAGES * NBPG))
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
value|0
end_define

begin_comment
comment|/* Nonzero if instruction at PC is a return instruction.  */
end_comment

begin_comment
comment|/* For Symmetry, this is really the 'leave' instruction, which */
end_comment

begin_comment
comment|/* is right before the ret */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
value|(read_memory_integer (pc, 1) == 0xc9)
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value. */
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
comment|/* code for 80387 fpu.  Functions are from i386-dep.c, copied into  * symm-dep.c.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_INFO
value|{ i386_float_info(); }
end_define

begin_comment
comment|/* largest int type */
end_comment

begin_define
define|#
directive|define
name|LONGEST
value|long
end_define

begin_define
define|#
directive|define
name|BUILTIN_TYPE_LONGEST
value|builtin_type_long
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
value|49
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_comment
comment|/* Symmetry registers are in this weird order to match the register    numbers in the symbol table entries.  If you change the order,    things will probably break mysteriously for no apparent reason.    Also note that the st(0)...st(7) 387 registers are represented as    st0...st7.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{ "eax", "edx", "ecx", "st0", "st1", \ 			     "ebx", "esi", "edi", "st2", "st3", \ 			     "st4", "st5", "st6", "st7", "esp", \ 			     "ebp", "eip", "eflags", "fp1", "fp2", \ 			     "fp3", "fp4", "fp5", "fp6", "fp7", \ 			     "fp8", "fp9", "fp10", "fp11", "fp12", \ 			     "fp13", "fp14", "fp15", "fp16", "fp17", \ 			     "fp18", "fp19", "fp20", "fp21", "fp22", \ 			     "fp23", "fp24", "fp25", "fp26", "fp27", \ 			     "fp28", "fp29", "fp30", "fp31" }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|FP1_REGNUM
value|18
end_define

begin_comment
comment|/* first 1167 register */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|14
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|15
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|16
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|17
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_comment
comment|/* The magic numbers below are offsets into u_ar0 in the user struct.  * They live in<machine/reg.h>.  Gdb calls this macro with blockend  * holding u.u_ar0 - KERNEL_U_ADDR.  Only the registers listed are  * saved in the u area (along with a few others that aren't useful  * here.  See<machine/reg.h>).  */
end_comment

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
value|{ struct user foo;
comment|/* needed for finding fpu regs */
value|\ switch (regno) { \     case 0: \       addr = blockend + EAX * sizeof(int); break; \   case 1: \       addr = blockend + EDX * sizeof(int); break; \   case 2: \       addr = blockend + ECX * sizeof(int); break; \   case 3:
comment|/* st(0) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[0][0] - (int)&foo); \       break; \   case 4:
comment|/* st(1) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[1][0] - (int)&foo); \       break; \   case 5: \       addr = blockend + EBX * sizeof(int); break; \   case 6: \       addr = blockend + ESI * sizeof(int); break; \   case 7: \       addr = blockend + EDI * sizeof(int); break; \   case 8:
comment|/* st(2) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[2][0] - (int)&foo); \       break; \   case 9:
comment|/* st(3) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[3][0] - (int)&foo); \       break; \   case 10:
comment|/* st(4) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[4][0] - (int)&foo); \       break; \   case 11:
comment|/* st(5) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[5][0] - (int)&foo); \       break; \   case 12:
comment|/* st(6) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[6][0] - (int)&foo); \       break; \   case 13:
comment|/* st(7) */
value|\       addr = blockend - \ 	  ((int)&foo.u_fpusave.fpu_stack[7][0] - (int)&foo); \       break; \   case 14: \       addr = blockend + ESP * sizeof(int); break; \   case 15: \       addr = blockend + EBP * sizeof(int); break; \   case 16: \       addr = blockend + EIP * sizeof(int); break; \   case 17: \       addr = blockend + FLAGS * sizeof(int); break; \   case 18:
comment|/* fp1 */
value|\   case 19:
comment|/* fp2 */
value|\   case 20:
comment|/* fp3 */
value|\   case 21:
comment|/* fp4 */
value|\   case 22:
comment|/* fp5 */
value|\   case 23:
comment|/* fp6 */
value|\   case 24:
comment|/* fp7 */
value|\   case 25:
comment|/* fp8 */
value|\   case 26:
comment|/* fp9 */
value|\   case 27:
comment|/* fp10 */
value|\   case 28:
comment|/* fp11 */
value|\   case 29:
comment|/* fp12 */
value|\   case 30:
comment|/* fp13 */
value|\   case 31:
comment|/* fp14 */
value|\   case 32:
comment|/* fp15 */
value|\   case 33:
comment|/* fp16 */
value|\   case 34:
comment|/* fp17 */
value|\   case 35:
comment|/* fp18 */
value|\   case 36:
comment|/* fp19 */
value|\   case 37:
comment|/* fp20 */
value|\   case 38:
comment|/* fp21 */
value|\   case 39:
comment|/* fp22 */
value|\   case 40:
comment|/* fp23 */
value|\   case 41:
comment|/* fp24 */
value|\   case 42:
comment|/* fp25 */
value|\   case 43:
comment|/* fp26 */
value|\   case 44:
comment|/* fp27 */
value|\   case 45:
comment|/* fp28 */
value|\   case 46:
comment|/* fp29 */
value|\   case 47:
comment|/* fp30 */
value|\   case 48:
comment|/* fp31 */
value|\      addr = blockend - \ 	 ((int)&foo.u_fpasave.fpa_regs[(regno)-18] - (int)&foo); \   } \ }
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_comment
comment|/* 10 i386 registers, 8 i387 registers, and 31 Weitek 1167 registers */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|((10 * 4) + (8 * 10) + (31 * 4))
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
define|\
value|((N< 3) ? (N * 4) :			\ (N< 5) ? (((N - 2) * 10) + 2) :	\ (N< 8) ? (((N - 5) * 4) + 32) :	\ (N< 14) ? (((N - 8) * 10) + 44) :	\     (((N - 14) * 4) + 104))
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation  * for register N.  All registers are 4 bytes, except 387 st(0) - st(7),  * which are 80 bits each.   */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N< 3) ? 4 :	\ (N< 5) ? 10 :	\ (N< 8) ? 4 :	\ (N< 14) ? 10 :	\     4)
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  On the vax, all regs are 4 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|4
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|10
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
define|\
value|((N< 3) ? 0 : \ (N< 5) ? 1  : \ (N< 8) ? 0  : \ (N< 14) ? 1 : \     0)
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
define|\
value|((REGNUM< 3) ? bcopy ((FROM), (TO), 4) : \ (REGNUM< 5) ? i387_to_double((FROM), (TO)) : \ (REGNUM< 8) ? bcopy ((FROM), (TO), 4) : \ (REGNUM< 14) ? i387_to_double((FROM), (TO)) : \     bcopy ((FROM), (TO), 4))
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
define|\
value|((REGNUM< 3) ? bcopy ((FROM), (TO), 4) : \ (REGNUM< 5) ? double_to_i387((FROM), (TO)) : \ (REGNUM< 8) ? bcopy ((FROM), (TO), 4) : \ (REGNUM< 14) ? double_to_i387((FROM), (TO)) : \     bcopy ((FROM), (TO), 4))
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
value|((N< 3) ? builtin_type_int : \ (N< 5) ? builtin_type_double : \ (N< 8) ? builtin_type_int : \ (N< 14) ? builtin_type_double : \     builtin_type_int)
end_define

begin_comment
comment|/* from m-i386.h */
end_comment

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
value|{ (SP) -= sizeof (ADDR);		\     write_memory ((SP),&(ADDR), sizeof (ADDR)); \     write_register(0, (ADDR)); }
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
value|symmetry_extract_return_value(TYPE, REGBUF, VALBUF)
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

begin_comment
comment|/* Compensate for lack of `vprintf' function.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_VPRINTF
end_ifndef

begin_define
define|#
directive|define
name|vprintf
parameter_list|(
name|format
parameter_list|,
name|ap
parameter_list|)
value|_doprnt (format, ap, stdout)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not HAVE_VPRINTF */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer.     FRAME_CHAIN_COMBINE takes the chain pointer and the frame's nominal address    and produces the nominal address of the caller frame.     However, if FRAME_CHAIN_VALID returns zero,    it means the given frame is the outermost one and has no caller.    In that case, FRAME_CHAIN_COMBINE is not used.  */
end_comment

begin_comment
comment|/* On Symmetry, %ebp points to caller's %ebp, and the return address    is right on top of that. */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(outside_startup_file ((thisframe)->pc) ? \    read_memory_integer((thisframe)->frame, 4) :\    0)
end_define

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
value|(chain != 0)
end_define

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
name|fi
parameter_list|)
value|(read_memory_integer((fi)->frame + 4, 4))
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
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.       The weirdness in the "addl $imm8" case is due to gcc sometimes    issuing "addl $-int" after function call returns; this would    produce ridiculously huge arg counts.  */
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
define|\
value|{ \   int op = read_memory_integer(FRAME_SAVED_PC((fi)), 4); \   int narg; \   if ((op& 0xff) == 0x59)
comment|/* 0x59  'popl %ecx' */
value|\     { \       numargs = 1; \     } \   else if ((op& 0xffff) == 0xc483)
comment|/* 0xc483 'addl $imm8' */
value|\     { \       narg = ((op>> 16)& 0xff); \       numargs = (narg>= 128) ? -1 : narg / 4; \     } \   else if ((op& 0xffff) == 0xc481)
comment|/* 0xc481 'addl $imm32' */
value|\     { \       narg = read_memory_integer(FRAME_SAVED_PC((fi))+2,4); \       numargs = (narg< 0) ? -1 : narg / 4; \     } \   else \     { \       numargs = -1; \     } \ }
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
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
define|\
value|{  CORE_ADDR sp = read_register (SP_REGNUM); \   int regnum; \   sp = push_word (sp, read_register (PC_REGNUM)); \   sp = push_word (sp, read_register (FP_REGNUM)); \   write_register (FP_REGNUM, sp); \   for (regnum = 0; regnum< NUM_REGS; regnum++) \     sp = push_word (sp, read_register (regnum)); \   write_register (SP_REGNUM, sp); \ }
end_define

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ \   FRAME frame = get_current_frame (); \   CORE_ADDR fp; \   int regnum; \   struct frame_saved_regs fsr; \   struct frame_info *fi; \   fi = get_frame_info (frame); \   fp = fi->frame; \   get_frame_saved_regs (fi,&fsr); \   for (regnum = 0; regnum< NUM_REGS; regnum++) { \       CORE_ADDR adr; \       adr = fsr.regs[regnum]; \       if (adr) \ 	write_register (regnum, read_memory_integer (adr, 4)); \   } \   write_register (FP_REGNUM, read_memory_integer (fp, 4)); \   write_register (PC_REGNUM, read_memory_integer (fp + 4, 4)); \   write_register (SP_REGNUM, fp + 8); \   flush_cached_frames (); \   set_current_frame ( create_new_frame (read_register (FP_REGNUM), \ 					read_pc ())); \ }
end_define

begin_comment
comment|/* from i386-dep.c, worked better than my original... */
end_comment

begin_comment
comment|/* This sequence of words is the instructions  * call (32-bit offset)  * int 3  * This is 6 bytes.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{ 0x223344e8, 0xcc11 }
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|8
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|0
end_define

begin_comment
comment|/* Start execution at beginning of dummy */
end_comment

begin_comment
comment|/* Insert the specified number of args and function address    into a call sequence of the above form stored at DUMMYNAME.  */
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
name|type
parameter_list|)
define|\
value|{ \ 	int from, to, delta, loc; \ 	loc = (int)(read_register (SP_REGNUM) - CALL_DUMMY_LENGTH); \ 	from = loc + 5; \ 	to = (int)(fun); \ 	delta = to - from; \ 	*(int *)((char *)(dummyname) + 1) = delta; \ }
end_define

begin_escape
end_escape

begin_comment
comment|/* Interface definitions for kernel debugger KDB.  */
end_comment

begin_comment
comment|/* This doesn't work... */
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
value|{ 0, SIGKILL, SIGSEGV, 0, 0, 0, 0, 0, \   0, 0, SIGTRAP, SIGTRAP, 0, 0, 0, 0, \   0, 0, 0, 0, 0, 0, 0, 0}
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
define|\
value|{ asm (".globl end");         \   asm ("movl $ end, %esp");      \   asm ("movl %ebp, $0"); }
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("pushl %ebp");
end_define

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("movl (%esp), %ebp");
end_define

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm("pushad"); }
end_define

begin_comment
comment|/* { asm("pushl %eax"); \   asm("pushl %edx"); \   asm("pushl %ecx"); \   asm("pushl %st(0)"); \   asm("pushl %st(1)"); \   asm("pushl %ebx"); \   asm("pushl %esi"); \   asm("pushl %edi"); \   asm("pushl %st(2)"); \   asm("pushl %st(3)"); \   asm("pushl %st(4)"); \   asm("pushl %st(5)"); \   asm("pushl %st(6)"); \   asm("pushl %st(7)"); \   asm("pushl %esp"); \   asm("pushl %ebp"); \   asm("pushl %eip"); \   asm("pushl %eflags"); \   asm("pushl %fp1"); \   asm("pushl %fp2"); \   asm("pushl %fp3"); \   asm("pushl %fp4"); \   asm("pushl %fp5"); \   asm("pushl %fp6"); \   asm("pushl %fp7"); \   asm("pushl %fp8"); \    asm("pushl %fp9"); \   asm("pushl %fp10"); \   asm("pushl %fp11"); \   asm("pushl %fp12"); \   asm("pushl %fp13"); \   asm("pushl %fp14"); \   asm("pushl %fp15"); \   asm("pushl %fp16"); \   asm("pushl %fp17"); \   asm("pushl %fp18"); \   asm("pushl %fp19"); \   asm("pushl %fp20"); \   asm("pushl %fp21"); \   asm("pushl %fp22"); \    asm("pushl %fp23"); \   asm("pushl %fp24"); \   asm("pushl %fp25"); \   asm("pushl %fp26"); \   asm("pushl %fp27"); \   asm("pushl %fp28"); \   asm("pushl %fp29"); \   asm("pushl %fp30"); \   asm("pushl %fp31"); \ } */
end_comment

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("popad"); }
end_define

end_unit

