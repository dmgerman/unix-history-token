begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB target for a tahoe running 4.3-Reno.    Copyright 1986, 1987, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Ported by the State University of New York at Buffalo by the Distributed  * Computer Systems Lab, Department of Computer Science, 1991.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
value|0
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
value|2
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
define|\
value|{ register int op = (unsigned char) read_memory_integer (pc, 1);  \   if (op == 0x11) pc += 2;
comment|/* skip brb */
value|\   if (op == 0x13) pc += 3;
comment|/* skip brw */
value|\   if (op == 0x2c&&						  \       ((unsigned char) read_memory_integer (pc+2, 1)) == 0x5e)	  \     pc += 3;
comment|/* skip subl2 */
value|\   if (op == 0xe9&&						  \       ((unsigned char) read_memory_integer (pc+1, 1)) == 0xae&&  \       ((unsigned char) read_memory_integer(pc+3, 1)) == 0x5e)	  \      pc += 4;
comment|/* skip movab */
value|\   if (op == 0xe9&&						  \       ((unsigned char) read_memory_integer (pc+1, 1)) == 0xce&&  \       ((unsigned char) read_memory_integer(pc+4, 1)) == 0x5e)	  \     pc += 5;
comment|/* skip movab */
value|\   if (op == 0xe9&&						  \       ((unsigned char) read_memory_integer (pc+1, 1)) == 0xee&&  \       ((unsigned char) read_memory_integer(pc+6, 1)) == 0x5e)	  \     pc += 7;
comment|/* skip movab */
value|\ }
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
value|FRAME_SAVED_PC(frame)
end_define

begin_comment
comment|/* Wrong for cross-debugging.  I don't know the real values.  */
end_comment

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

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
value|(0xc0000000 - (TARGET_UPAGES * TARGET_NBPG))
end_define

begin_comment
comment|/* On BSD, sigtramp is in the u area.  Can't check the exact    addresses because for cross-debugging we don't have target include    files around.  This should be close enough.  */
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
value|((pc)>= STACK_END_ADDR&& (pc< 0xc0000000))
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
value|{0x30}
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

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
value|(read_memory_integer (pc, 1) == 0x40)
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.    LEN is the length in bytes -- not relevant on the Tahoe. */
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
value|((*(short *) p& 0xff80) == 0x8000)
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
value|19
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "r12", "fp", "sp", "pc", "ps", "al", "ah"}
end_define

begin_define
define|#
directive|define
name|FP_REGNUM
value|13
end_define

begin_comment
comment|/* Contains address of executing stack frame */
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
name|PC_REGNUM
value|15
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|16
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|AL_REGNUM
value|17
end_define

begin_comment
comment|/* Contains accumulator */
end_comment

begin_define
define|#
directive|define
name|AH_REGNUM
value|18
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(19*4)
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
value|((N) * 4)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the tahoe, all regs are 4 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|4
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  On the tahoe, all regs are 4 bytes.  */
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
value|0
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
value|bcopy ((FROM), (TO), 4);
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
value|bcopy ((FROM), (TO), 4);
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
value|builtin_type_int
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
value|{ write_register (1, (ADDR)); }
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

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).     FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer. */
end_comment

begin_comment
comment|/* In the case of the Tahoe, the frame's nominal address is the FP value,    and it points to the old FP */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(!inside_entry_file ((thisframe)->pc) ? \    read_memory_integer ((thisframe)->frame, 4) :\    0)
end_define

begin_comment
comment|/* Define other aspects of the stack frame.  */
end_comment

begin_comment
comment|/* Saved PC */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|(read_memory_integer ((FRAME)->frame - 8, 4))
end_define

begin_comment
comment|/* In most of GDB, getting the args address is too important to    just say "I don't know". */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|((fi)->frame)
end_define

begin_comment
comment|/* Address to use as an anchor for finding local variables */
end_comment

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
define|\
value|{ numargs = ((0xffff& read_memory_integer(((fi)->frame-4),4)) - 4)>> 2; }
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
value|{ register int regnum;     \   register int rmask = read_memory_integer ((frame_info)->frame-4, 4)>> 16;\   register CORE_ADDR next_addr;     \   bzero (&frame_saved_regs, sizeof frame_saved_regs);     \   next_addr = (frame_info)->frame - 8;     \   for (regnum = 12; regnum>= 0; regnum--, rmask<<= 1)  \     (frame_saved_regs).regs[regnum] = (rmask& 0x1000) ? (next_addr -= 4) : 0;\   (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame + 4;  \   (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame - 8;  \   (frame_saved_regs).regs[FP_REGNUM] = (frame_info)->frame;      \ }
end_define

begin_comment
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
define|\
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);	\   register int regnum;					\ printf("PUSH_DUMMY_FRAME\n");				\   sp = push_word (sp, read_register (FP_REGNUM));	\   write_register (FP_REGNUM, sp);			\   sp = push_word (sp, 0x1fff0004);
comment|/*SAVE MASK*/
value|\   sp = push_word (sp, read_register (PC_REGNUM));	\   for (regnum = 12; regnum>= 0; regnum--)		\     sp = push_word (sp, read_register (regnum));	\   write_register (SP_REGNUM, sp);			\ }
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register CORE_ADDR fp = read_register (FP_REGNUM);			\   register int regnum;							\   register int regmask = read_memory_integer (fp-4, 4);			\ printf("POP_FRAME\n");							\   regmask>>= 16;                                               	\   write_register (SP_REGNUM, fp+4);	                           	\   write_register (PC_REGNUM, read_memory_integer(fp-8, 4));	  	\   write_register (FP_REGNUM, read_memory_integer(fp, 4));  		\   fp -= 8;								\   for (regnum = 12; regnum>= 0; regnum--, regmask<<= 1)		\     if (regmask& 0x1000)                                            	\       write_register (regnum, read_memory_integer (fp-=4, 4));		\   flush_cached_frames ();						\   set_current_frame (create_new_frame (read_register (FP_REGNUM),	\ 					read_pc ())); }
end_define

begin_comment
comment|/* This sequence of words is the instructions      calls #69, @#32323232      bpt    Note this is 8 bytes.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0xbf699f32, 0x32323230}
end_define

begin_comment
comment|/* Start execution at beginning of dummy */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|0
end_define

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
name|valtype
parameter_list|,
name|using_gcc
parameter_list|)
define|\
value|{ int temp = (int) fun;				\   *((char *) dummyname + 1) = nargs;		\   bcopy(&temp,(char *)dummyname+3,4); }
end_define

end_unit

