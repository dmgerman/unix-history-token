begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine definitions for GDB on a Sequent Symmetry under dynix 3.0,    with Weitek 1167 and i387 support.    Copyright 1986, 1987, 1989, 1991, 1992 Free Software Foundation, Inc.    Symmetry version by Jay Vosburgh (uunet!sequent!fubar).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* I don't know if this will work for cross-debugging, even if you do get    a copy of the right include file.  */
end_comment

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|LITTLE_ENDIAN
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

begin_decl_stmt
specifier|extern
name|int
name|i386_skip_prologue
name|PARAMS
argument_list|(
operator|(
name|int
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
define|\
value|read_memory_integer(read_register(SP_REGNUM), 4)
end_define

begin_comment
comment|/* I don't know the real values for these.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_UPAGES
value|UPAGES
end_define

begin_define
define|#
directive|define
name|TARGET_NBPG
value|NBPG
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0x40000000 - (TARGET_UPAGES * TARGET_NBPG))
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

begin_if
if|#
directive|if
literal|0
end_if

begin_define
unit|--- this code can't be used unless we know we are running native,      since it uses host specific ptrace calls. /* code for 80387 fpu.  Functions are from i386-dep.c, copied into  * symm-dep.c.  */ #define FLOAT_INFO { i386_float_info(); } #endif  /* Say how long (ordinary) registers are.  */  #define REGISTER_TYPE long  /* Number of machine registers */ #define NUM_REGS 49  /* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */  /* Symmetry registers are in this weird order to match the register    numbers in the symbol table entries.  If you change the order,    things will probably break mysteriously for no apparent reason.    Also note that the st(0)...st(7) 387 registers are represented as    st0...st7.  */  #define REGISTER_NAMES { "eax", "edx", "ecx", "st0", "st1", \ 			     "ebx", "esi", "edi", "st2", "st3", \ 			     "st4", "st5", "st6", "st7", "esp", \ 			     "ebp", "eip", "eflags", "fp1", "fp2", \ 			     "fp3", "fp4", "fp5", "fp6", "fp7", \ 			     "fp8", "fp9", "fp10", "fp11", "fp12", \ 			     "fp13", "fp14", "fp15", "fp16", "fp17", \ 			     "fp18", "fp19", "fp20", "fp21", "fp22", \ 			     "fp23", "fp24", "fp25", "fp26", "fp27", \ 			     "fp28", "fp29", "fp30", "fp31" }  /* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */  #define FP1_REGNUM 18		/* first 1167 register */ #define SP_REGNUM 14		/* Contains address of top of stack */ #define FP_REGNUM 15		/* Contains address of executing stack frame */ #define PC_REGNUM 16		/* Contains program counter */ #define PS_REGNUM 17		/* Contains processor status */  /* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */ /* 10 i386 registers, 8 i387 registers, and 31 Weitek 1167 registers */ #define REGISTER_BYTES ((10 * 4) + (8 * 10) + (31 * 4))  /* Index within `registers' of the first byte of the space for    register N.  */
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
unit|extern void i387_to_double PARAMS ((char *, char *));
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
unit|extern void double_to_i387 PARAMS ((char *, char *));
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

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer.     However, if FRAME_CHAIN_VALID returns zero,    it means the given frame is the outermost one and has no caller.  */
end_comment

begin_comment
comment|/* On Symmetry, %ebp points to caller's %ebp, and the return address    is right on top of that.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(!inside_entry_file ((thisframe)->pc) ? \    read_memory_integer((thisframe)->frame, 4) :\    0)
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
value|(FRAMELESS) = frameless_look_for_prologue(FI)
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

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Forward decl's for prototypes */
end_comment

begin_endif
unit|struct frame_info; struct frame_saved_regs;
endif|#
directive|endif
end_endif

begin_escape
unit|extern void i386_frame_find_saved_regs PARAMS ((struct frame_info *, 				    struct frame_saved_regs *));
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
name|args
parameter_list|,
name|type
parameter_list|,
name|gcc_p
parameter_list|)
define|\
value|{ \ 	int from, to, delta, loc; \ 	loc = (int)(read_register (SP_REGNUM) - CALL_DUMMY_LENGTH); \ 	from = loc + 5; \ 	to = (int)(fun); \ 	delta = to - from; \ 	*(int *)((char *)(dummyname) + 1) = delta; \ }
end_define

unit|extern void print_387_control_word PARAMS ((unsigned int));  extern void print_387_status_word PARAMS ((unsigned int));
end_unit

