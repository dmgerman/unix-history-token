begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a vax under 4.2bsd.    Copyright (C) 1986, 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* There is one known bug with VAX support that I don't know how to    fix:  if you do a backtrace from a signal handler, you get something    like: #0  0xbc in kill (592, 3) #1  0x7f in hand (...) (...) #2  0x7fffec7e in ?? (2, 0, 2147478112, 94)                   ^^ GDB doesn't know about sigtramp #3  0x7fffec70 in ?? (592, 2)     ^^^^^^^^^^ wrong address #4  0xae in main (...) (...)  when the correct backtrace (as given by adb) is: _kill(250,3) from _hand+21 _hand(2,0,7fffea60,5e) from 7fffec7e sigtramp(2,0,7fffea60,5e) from _kill+4 _kill(250,2) from _main+2e _main(1,7fffeac4,7fffeacc) from start+3d  If anyone knows enough about VAX BSD to fix this, please send the fix to bug-gdb@prep.ai.mit.edu.  */
end_comment

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
value|\   if (op == 0x31) pc += 3;
comment|/* skip brw */
value|\   if (op == 0xC2&&						  \       ((unsigned char) read_memory_integer (pc+2, 1)) == 0x5E)	  \     pc += 3;
comment|/* skip subl2 */
value|\   if (op == 0x9E&&						  \       ((unsigned char) read_memory_integer (pc+1, 1)) == 0xAE&&  \       ((unsigned char) read_memory_integer(pc+3, 1)) == 0x5E)	  \      pc += 4;
comment|/* skip movab */
value|\   if (op == 0x9E&&						  \       ((unsigned char) read_memory_integer (pc+1, 1)) == 0xCE&&  \       ((unsigned char) read_memory_integer(pc+4, 1)) == 0x5E)	  \     pc += 5;
comment|/* skip movab */
value|\   if (op == 0x9E&&						  \       ((unsigned char) read_memory_integer (pc+1, 1)) == 0xEE&&  \       ((unsigned char) read_memory_integer(pc+6, 1)) == 0x5E)	  \     pc += 7;
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

begin_define
define|#
directive|define
name|TARGET_UPAGES
value|10
end_define

begin_define
define|#
directive|define
name|TARGET_NBPG
value|512
end_define

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0x80000000 - (TARGET_UPAGES * TARGET_NBPG))
end_define

begin_comment
comment|/* On the VAX, sigtramp is in the u area.  Can't check the exact    addresses because for cross-debugging we don't have VAX include    files around.  This should be close enough.  */
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
value|((pc)>= STACK_END_ADDR&& (pc< 0x80000000))
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
value|{3}
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
value|(read_memory_integer (pc, 1) == 04)
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.    LEN is the length in bytes -- not relevant on the Vax.  */
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
value|17
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7", "r8", "r9", "r10", "r11", "ap", "fp", "sp", "pc", "ps"}
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|AP_REGNUM
value|12
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

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(17*4)
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
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the vax, all regs are 4 bytes.  */
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

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer. */
end_comment

begin_comment
comment|/* In the case of the Vax, the frame's nominal address is the FP value,    and 12 bytes later comes the saved previous FP value as a 4-byte word.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(!inside_entry_file ((thisframe)->pc) ? \    read_memory_integer ((thisframe)->frame + 12, 4) :\    0)
end_define

begin_comment
comment|/* Define other aspects of the stack frame.  */
end_comment

begin_comment
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.  */
end_comment

begin_comment
comment|/* On the vax, all functions have frames.  */
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
value|(read_memory_integer ((FRAME)->frame + 16, 4))
end_define

begin_comment
comment|/* Cannot find the AP register value directly from the FP value.  Must    find it saved in the frame called by this one, or in the AP    register for the innermost frame.  However, there is no way to tell    the difference between the innermost frame and a frame for which we    just don't know the frame that it called (e.g. "info frame    0x7ffec789").  For the sake of argument suppose that the stack is    somewhat trashed (which is one reason that "info frame" exists).    So return 0 (indicating we don't know the address of    the arglist) if we don't know what frame this frame calls.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS_CORRECT
parameter_list|(
name|fi
parameter_list|)
define|\
value|(((fi)->next_frame                                  \    ? read_memory_integer ((fi)->next_frame + 8, 4)   \    :
comment|/* read_register (AP_REGNUM) */
value|0))
end_define

begin_comment
comment|/* In most of GDB, getting the args address is too important to    just say "I don't know".  This is sometimes wrong for functions    that aren't on top of the stack, but c'est la vie.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
define|\
value|(((fi)->next_frame                                  \    ? read_memory_integer ((fi)->next_frame + 8, 4)   \    : read_register (AP_REGNUM)
comment|/* 0 */
value|))
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
define|\
value|{ numargs = (0xff& read_memory_integer (FRAME_ARGS_ADDRESS (fi), 1)); }
end_define

begin_comment
comment|/* Return number of bytes at start of arglist that are not really args.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_SKIP
value|4
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
value|{ register int regnum;     \   register int regmask = read_memory_integer ((frame_info)->frame+4, 4)>> 16; \   register CORE_ADDR next_addr;     \   bzero (&frame_saved_regs, sizeof frame_saved_regs);     \   next_addr = (frame_info)->frame + 16;     \
comment|/* Regmask's low bit is for register 0,     \      which is the first one that would be pushed.  */
value|\   for (regnum = 0; regnum< 12; regnum++, regmask>>= 1)  \     (frame_saved_regs).regs[regnum] = (regmask& 1) ? (next_addr += 4) : 0;  \   (frame_saved_regs).regs[SP_REGNUM] = next_addr + 4;  \   if (read_memory_integer ((frame_info)->frame + 4, 4)& 0x20000000)   \     (frame_saved_regs).regs[SP_REGNUM] += 4 + 4 * read_memory_integer (next_addr + 4, 4);  \   (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame + 16;  \   (frame_saved_regs).regs[FP_REGNUM] = (frame_info)->frame + 12;  \   (frame_saved_regs).regs[AP_REGNUM] = (frame_info)->frame + 8;  \   (frame_saved_regs).regs[PS_REGNUM] = (frame_info)->frame + 4;  \ }
end_define

begin_escape
end_escape

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
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);\   register int regnum;				    \   sp = push_word (sp, 0);
comment|/* arglist */
value|\   for (regnum = 11; regnum>= 0; regnum--)	    \     sp = push_word (sp, read_register (regnum));    \   sp = push_word (sp, read_register (PC_REGNUM));   \   sp = push_word (sp, read_register (FP_REGNUM));   \   sp = push_word (sp, read_register (AP_REGNUM));   \   sp = push_word (sp, (read_register (PS_REGNUM)& 0xffef)   \ 		      + 0x2fff0000);		    \   sp = push_word (sp, 0); 			    \   write_register (SP_REGNUM, sp);		    \   write_register (FP_REGNUM, sp);		    \   write_register (AP_REGNUM, sp + 17 * sizeof (int)); }
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register CORE_ADDR fp = read_register (FP_REGNUM);		 \   register int regnum;						 \   register int regmask = read_memory_integer (fp + 4, 4);	 \   write_register (PS_REGNUM, 					 \ 		  (regmask& 0xffff)				 \ 		  | (read_register (PS_REGNUM)& 0xffff0000));	 \   write_register (PC_REGNUM, read_memory_integer (fp + 16, 4));  \   write_register (FP_REGNUM, read_memory_integer (fp + 12, 4));  \   write_register (AP_REGNUM, read_memory_integer (fp + 8, 4));   \   fp += 16;							 \   for (regnum = 0; regnum< 12; regnum++)			 \     if (regmask& (0x10000<< regnum))				 \       write_register (regnum, read_memory_integer (fp += 4, 4)); \   fp = fp + 4 + ((regmask>> 30)& 3);				 \   if (regmask& 0x20000000)					 \     { regnum = read_memory_integer (fp, 4);			 \       fp += (regnum + 1) * 4; }					 \   write_register (SP_REGNUM, fp);				 \   flush_cached_frames ();					 \   set_current_frame (create_new_frame (read_register (FP_REGNUM),\ 					read_pc ())); }
end_define

begin_comment
comment|/* This sequence of words is the instructions      calls #69, @#32323232      bpt    Note this is 8 bytes.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0x329f69fb, 0x03323232}
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
value|{ *((char *) dummyname + 1) = nargs;		\   *(int *)((char *) dummyname + 3) = fun; }
end_define

end_unit

