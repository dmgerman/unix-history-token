begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB target for an ARM under RISCiX (4.3bsd).    Copyright (C) 1986, 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_comment
comment|/* IEEE format floating point */
end_comment

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_comment
comment|/* I provide my own xfer_core_file to cope with shared libraries */
end_comment

begin_define
define|#
directive|define
name|XFER_CORE_FILE
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
comment|/* Advance PC across any function entry prologue instructions    to reach some "real" code.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
value|pc = skip_prologue(pc)
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
value|(read_register (LR_REGNUM)& 0x03fffffc)
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
value|(0x01000000 - (TARGET_UPAGES * TARGET_NBPG))
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
value|{0x00,0x00,0x18,0xef}
end_define

begin_comment
comment|/* BKPT_SWI from<sys/ptrace.h> */
end_comment

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
define|\
value|((read_memory_integer(pc, 4)& 0x0fffffff == 0x01b0f00e) || \        (read_memory_integer(pc, 4)& 0x0ffff800 == 0x09eba800))
end_define

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.    LEN is the length in bytes.  */
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
value|0
end_define

begin_comment
comment|/* code to execute to print interesting information about the  * floating point processor (if any)  * No need to define if there is nothing to do.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_INFO
value|{ arm_float_info (); }
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

begin_comment
comment|/* Note: I make a fake copy of the pc in register 25 (calling it ps) so    that I can clear the status bits from pc (register 15) */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|26
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{ "a1", "a2", "a3", "a4",					\ 	"v1", "v2", "v3", "v4", "v5", "v6",			\         "sl", "fp", "ip", "sp", "lr", "pc",			\         "f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7", "fps", "ps" }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|AP_REGNUM
value|11
end_define

begin_define
define|#
directive|define
name|FP_REGNUM
value|11
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|13
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|LR_REGNUM
value|14
end_define

begin_comment
comment|/* address to return to from a function call */
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
name|F0_REGNUM
value|16
end_define

begin_comment
comment|/* first floating point register */
end_comment

begin_define
define|#
directive|define
name|FPS_REGNUM
value|24
end_define

begin_comment
comment|/* floating point status register */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|25
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
value|(16*4 + 12*8 + 4 + 4)
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
value|(((N)< F0_REGNUM) ? (N)*4 : \ 			  (((N)< PS_REGNUM) ? 16*4 + ((N) - 16)*12 : \ 			   16*4 + 8*12 + ((N) - FPS_REGNUM) * 4))
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
value|(((N)< F0_REGNUM || (N)>= FPS_REGNUM) ? 4 : 12)
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
value|(((N)< F0_REGNUM || (N)>= FPS_REGNUM) ? 4 : 8)
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|12
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
comment|/* Nonzero if register N requires conversion    from raw format to virtual format.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|N
parameter_list|)
value|((unsigned)(N) - F0_REGNUM< 8)
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
value|if (REGISTER_CONVERTIBLE(REGNUM))					\       convert_from_extended((FROM), (TO));				\   else									\       bcopy ((FROM), (TO), 4);
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
value|if (REGISTER_CONVERTIBLE(REGNUM)) 			\     convert_to_extended((FROM), (TO)); 		\   else							\     bcopy ((FROM), (TO), 4);
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
value|(((unsigned)(N) - F0_REGNUM)< 8 ? builtin_type_double : builtin_type_int)
end_define

begin_escape
end_escape

begin_comment
comment|/* The system C compiler uses a similar structure return convention to gcc */
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
value|(TYPE_LENGTH (type)> 4)
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
value|{ write_register (0, (ADDR)); }
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
value|if (TYPE_CODE (TYPE) == TYPE_CODE_FLT)				\     convert_from_extended(REGBUF + REGISTER_BYTE (F0_REGNUM), VALBUF);	\   else									\     bcopy (REGBUF, VALBUF, TYPE_LENGTH (TYPE))
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
value|if (TYPE_CODE (TYPE) == TYPE_CODE_FLT) {				\     char _buf[MAX_REGISTER_RAW_SIZE];					\     convert_to_extended(VALBUF, _buf);					\     write_register_bytes (REGISTER_BYTE (F0_REGNUM), _buf, MAX_REGISTER_RAW_SIZE); \   } else								\     write_register_bytes (0, VALBUF, TYPE_LENGTH (TYPE))
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
comment|/* Specify that for the native compiler variables for a particular    lexical context are listed after the beginning LBRAC instead of    before in the executables list of symbols.  */
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
value|(!(gcc_p))
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
comment|/* In the case of the ARM, the frame's nominal address is the FP value,    and 12 bytes before comes the saved previous FP value as a 4-byte word.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|((thisframe)->pc>= first_object_file_end ? \    read_memory_integer ((thisframe)->frame - 12, 4) :\    0)
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
value|(chain != 0&& (FRAME_SAVED_PC (thisframe)>= first_object_file_end))
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
value|{							\   CORE_ADDR func_start, after_prologue;			\   func_start = (get_pc_function_start ((FI)->pc) +	\ 		FUNCTION_START_OFFSET);			\   after_prologue = func_start;				\   SKIP_PROLOGUE (after_prologue);			\   (FRAMELESS) = (after_prologue == func_start);		\ }
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
define|\
value|(read_memory_integer ((FRAME)->frame - 4, 4)& 0x03fffffc)
end_define

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|(fi->frame)
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
value|(numargs = -1)
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
value|{							      			\     register int regnum;							\     register int frame;								\     register int next_addr;							\     register int return_data_save;						\     register int saved_register_mask;						\     bzero (&frame_saved_regs, sizeof frame_saved_regs);				\     frame = (frame_info)->frame;						\     return_data_save = read_memory_integer(frame, 4)& 0x03fffffc - 12;		\     saved_register_mask =							\ 	read_memory_integer(return_data_save, 4);				\     next_addr = frame - 12;							\     for (regnum = 4; regnum< 10; regnum++)					\ 	if (saved_register_mask& (1<<regnum)) {				\ 	    next_addr -= 4;							\ 	    (frame_saved_regs).regs[regnum] = next_addr;			\ 	}									\     if (read_memory_integer(return_data_save + 4, 4) == 0xed6d7103) {		\ 	next_addr -= 12;							\ 	(frame_saved_regs).regs[F0_REGNUM + 7] = next_addr;			\     }										\     if (read_memory_integer(return_data_save + 8, 4) == 0xed6d6103) {		\ 	next_addr -= 12;							\ 	(frame_saved_regs).regs[F0_REGNUM + 6] = next_addr;			\     }										\     if (read_memory_integer(return_data_save + 12, 4) == 0xed6d5103) {		\ 	next_addr -= 12;							\ 	(frame_saved_regs).regs[F0_REGNUM + 5] = next_addr;			\     }										\     if (read_memory_integer(return_data_save + 16, 4) == 0xed6d4103) {		\ 	next_addr -= 12;							\ 	(frame_saved_regs).regs[F0_REGNUM + 4] = next_addr;			\     }										\     (frame_saved_regs).regs[SP_REGNUM] = next_addr;				\     (frame_saved_regs).regs[PC_REGNUM] = frame - 4;				\     (frame_saved_regs).regs[PS_REGNUM] = frame - 4;				\     (frame_saved_regs).regs[FP_REGNUM] = frame - 12;				\ }
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
value|{								\     register CORE_ADDR sp = read_register (SP_REGNUM);		\     register int regnum;					\
comment|/* opcode for ldmdb fp,{v1-v6,fp,ip,lr,pc}^ */
value|\     sp = push_word(sp, 0xe92dbf0);
comment|/* dummy return_data_save ins */
value|\
comment|/* push a pointer to the dummy instruction minus 12 */
value|\     sp = push_word(sp, read_register (SP_REGNUM) - 16);		\     sp = push_word(sp, read_register (PS_REGNUM));		\     sp = push_word(sp, read_register (SP_REGNUM));		\     sp = push_word(sp, read_register (FP_REGNUM));		\     for (regnum = 9; regnum>= 4; regnum --)			\ 	sp = push_word(sp, read_register (regnum));		\     write_register (FP_REGNUM, read_register (SP_REGNUM) - 8);	\     write_register (SP_REGNUM, sp); }
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{									\     register CORE_ADDR fp = read_register (FP_REGNUM);			\     register unsigned long return_data_save =				\ 	read_memory_integer ( (read_memory_integer (fp, 4)&		\ 			       0x03fffffc)  - 12, 4);			\     register int regnum;						\     write_register (PS_REGNUM, read_memory_integer (fp - 4, 4));	\     write_register (PC_REGNUM, read_register (PS_REGNUM)& 0x03fffffc);	\     write_register (SP_REGNUM, read_memory_integer (fp - 8, 4));	\     write_register (FP_REGNUM, read_memory_integer (fp - 12, 4));	\     fp -= 12;								\     for (regnum = 9; regnum>= 4; regnum--)				\ 	if (return_data_save& (1<<regnum)) {				\ 	    fp -= 4;							\ 	    write_register (regnum, read_memory_integer(fp, 4));	\ 	}								\     flush_cached_frames ();						\     set_current_frame (create_new_frame (read_register (FP_REGNUM),	\ 					 read_pc ()));			\ }
end_define

begin_comment
comment|/* This sequence of words is the instructions       ldmia	sp!,{a1-a4}      mov 	lk,pc      bl		*+8      swi	bkpt_swi     Note this is 16 bytes.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0xe8bd000f, 0xe1a0e00f, 0xeb000000, 0xef180000}
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
value|{										\     register enum type_code code = TYPE_CODE (type);				\     register nargs_in_registers, struct_return = 0;				\
comment|/* fix the load-arguments mask to move the first 4 or less arguments	\        into a1-a4 but make sure the structure return address in a1 is		\        not disturbed if the function is returning a structure */
value|\     if ((code == TYPE_CODE_STRUCT ||						\ 	 code == TYPE_CODE_UNION ||						\ 	 code == TYPE_CODE_ARRAY)&&						\ 	TYPE_LENGTH (type)> 4) {						\ 	nargs_in_registers = min(nargs + 1, 4);					\ 	struct_return = 1;							\     } else									\ 	nargs_in_registers = min(nargs, 4);					\     *(char *) dummyname = (1<< nargs_in_registers) - 1 - struct_return;	\     *(int *)((char *) dummyname + 8) =						\ 	(((fun - (pc + 16)) / 4)& 0x00ffffff) | 0xeb000000; }
end_define

end_unit

