begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on an encore under umax 4.2    Copyright (C) 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
comment|/* Need to get function ends by adding this to epilogue address from .bf    record, not using x_fsize field.  */
end_comment

begin_define
define|#
directive|define
name|FUNCTION_EPILOGUE_SIZE
value|4
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
define|\
value|{ register unsigned char op = read_memory_integer (pc, 1);	\   if (op == 0x82) { op = read_memory_integer (pc+2,1);  \   		    if ((op& 0x80) == 0) pc += 3;	\ 		    else if ((op& 0xc0) == 0x80) pc += 4;	\ 		    else pc += 6;			\ 		   }					\ }
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
value|read_memory_integer (read_register (SP_REGNUM), 4)
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0xfffff000)
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
value|{0xf2}
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
value|(read_memory_integer (pc, 1) == 0x12)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NaN
end_ifndef

begin_include
include|#
directive|include
file|<nan.h>
end_include

begin_endif
endif|#
directive|endif
endif|NaN
end_endif

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.  */
end_comment

begin_comment
comment|/* Surely wrong for cross-debugging.  */
end_comment

begin_define
define|#
directive|define
name|INVALID_FLOAT
parameter_list|(
name|p
parameter_list|,
name|s
parameter_list|)
define|\
value|((s == sizeof (float))?	\ 		NaF (*(float *) p) :	\ 		NaD (*(double *) p))
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
value|25
end_define

begin_define
define|#
directive|define
name|NUM_GENERAL_REGS
value|8
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",	\  			"f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",	\ 			"sp", "fp", "pc", "ps",				\  			"fsr",						\ 			"l0", "l1", "l2", "l3", "xx",			\  			}
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|R0_REGNUM
value|0
end_define

begin_comment
comment|/* General register 0 */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|8
end_define

begin_comment
comment|/* Floating point register 0 */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|16
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|AP_REGNUM
value|FP_REGNUM
end_define

begin_define
define|#
directive|define
name|FP_REGNUM
value|17
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|18
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|19
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|FPS_REGNUM
value|20
end_define

begin_comment
comment|/* Floating point status register */
end_comment

begin_define
define|#
directive|define
name|LP0_REGNUM
value|21
end_define

begin_comment
comment|/* Double register 0 (same as FP0) */
end_comment

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
define|\
value|((NUM_REGS - 4) * REGISTER_RAW_SIZE(R0_REGNUM) \    + 4            * REGISTER_RAW_SIZE(LP0_REGNUM))
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
value|((N)>= LP0_REGNUM ? \ 	LP0_REGNUM * 4 + ((N) - LP0_REGNUM) * 8 : (N) * 4)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the 32000, all regs are 4 bytes    except for the doubled floating registers. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|((N)>= LP0_REGNUM ? 8 : 4)
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  On the 32000, all regs are 4 bytes    except for the doubled floating registers. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|((N)>= LP0_REGNUM ? 8 : 4)
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
value|bcopy ((FROM), (TO), REGISTER_VIRTUAL_SIZE(REGNUM));
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
value|bcopy ((FROM), (TO), REGISTER_VIRTUAL_SIZE(REGNUM));
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
value|(((N)< FP0_REGNUM) ?				\ 		builtin_type_int :			\ 		((N)< FP0_REGNUM + 8) ?		\ 			builtin_type_float :		\ 			((N)< LP0_REGNUM) ?		\ 				builtin_type_int :	\ 				builtin_type_double)
end_define

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function.     On this machine this is a no-op, because gcc isn't used on it    yet.  So this calling convention is not used. */
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
value|bcopy (REGBUF+REGISTER_BYTE (TYPE_CODE (TYPE) == TYPE_CODE_FLT ? FP0_REGNUM : 0), VALBUF, TYPE_LENGTH (TYPE))
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
value|write_register_bytes (REGISTER_BYTE (TYPE_CODE (TYPE) == TYPE_CODE_FLT ? FP0_REGNUM : 0), VALBUF, TYPE_LENGTH (TYPE))
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
comment|/* In the case of the ns32000 series, the frame's nominal address is the FP    value, and at that address is saved previous FP value as a 4-byte word.  */
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

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|(read_memory_integer ((FRAME)->frame + 4, 4))
end_define

begin_comment
comment|/* Compute base of arguments. */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
define|\
value|((ns32k_get_enter_addr ((fi)->pc)> 1) ? \ 	((fi)->frame) : (read_register (SP_REGNUM) - 4))
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
comment|/* Get the address of the enter opcode for this function, if it is active.    Returns positive address> 1 if pc is between enter/exit,    1 if pc before enter or after exit, 0 otherwise. */
end_comment

begin_function_decl
specifier|extern
name|CORE_ADDR
name|ns32k_get_enter_addr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.    Encore's C compiler often reuses same area on stack for args,    so this will often not work properly.  If the arg names    are known, it's likely most of them will be printed. */
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
value|{ CORE_ADDR	pc;					\   CORE_ADDR	enter_addr;				\   unsigned int	insn;					\   unsigned int	addr_mode;				\   int width;						\ 							\   numargs = -1;						\   enter_addr = ns32k_get_enter_addr ((fi)->pc);		\   if (enter_addr> 0)					\     {							\       pc = (enter_addr == 1) ?				\ 	SAVED_PC_AFTER_CALL (fi) :			\ 	FRAME_SAVED_PC (fi);				\       insn = read_memory_integer (pc,2);		\       addr_mode = (insn>> 11)& 0x1f;			\       insn = insn& 0x7ff;				\       if ((insn& 0x7fc) == 0x57c&&			\ 		addr_mode == 0x14)
comment|/* immediate */
value|\ 	{						\ 	  if (insn == 0x57c)
comment|/* adjspb */
value|\   		width = 1;				\ 	  else if (insn == 0x57d)
comment|/* adjspw */
value|\   		width = 2;				\ 	  else if (insn == 0x57f)
comment|/* adjspd */
value|\   		width = 4;				\ 	  numargs = read_memory_integer (pc+2,width);	\ 	  if (width> 1)				\ 	    flip_bytes (&numargs, width);		\ 	  numargs = - sign_extend (numargs, width*8) / 4;\ 	}						\     }							\ }
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
value|{ 								\   register int	regmask, regnum;				\   int		localcount;					\   register CORE_ADDR	enter_addr;				\   register CORE_ADDR	next_addr;				\ 								\   bzero (&(frame_saved_regs), sizeof (frame_saved_regs));	\   enter_addr = ns32k_get_enter_addr ((frame_info)->pc);		\   if (enter_addr> 1)						\     {								\       regmask = read_memory_integer (enter_addr+1, 1)& 0xff;	\       localcount = ns32k_localcount (enter_addr);		\       next_addr = (frame_info)->frame + localcount;		\       for (regnum = 0; regnum< 8; regnum++, regmask>>= 1)	\ 	(frame_saved_regs).regs[regnum] = (regmask& 1) ?	\ 					  (next_addr -= 4) : 0;	\       (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame + 4;\       (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame + 4;\       (frame_saved_regs).regs[FP_REGNUM] =			\ 		  (read_memory_integer ((frame_info)->frame, 4));\     }								\   else if (enter_addr == 1)					\     {								\       CORE_ADDR sp = read_register (SP_REGNUM);			\       (frame_saved_regs).regs[PC_REGNUM] = sp;			\       (frame_saved_regs).regs[SP_REGNUM] = sp + 4;		\     }								\ }
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
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);\   register int regnum;				    \   sp = push_word (sp, read_register (PC_REGNUM));   \   sp = push_word (sp, read_register (FP_REGNUM));   \   write_register (FP_REGNUM, sp);		    \   for (regnum = 0; regnum< 8; regnum++)  \     sp = push_word (sp, read_register (regnum));    \   write_register (SP_REGNUM, sp);  			\ }
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register FRAME frame = get_current_frame ();			 \   register CORE_ADDR fp;					 \   register int regnum;						 \   struct frame_saved_regs fsr;					 \   struct frame_info *fi;						 \   fi = get_frame_info (frame);					 \   fp = fi->frame;						 \   get_frame_saved_regs (fi,&fsr);				 \   for (regnum = 0; regnum< 8; regnum++)			 \     if (fsr.regs[regnum])					 \       write_register (regnum, read_memory_integer (fsr.regs[regnum], 4)); \   write_register (FP_REGNUM, read_memory_integer (fp, 4));	 \   write_register (PC_REGNUM, read_memory_integer (fp + 4, 4));   \   write_register (SP_REGNUM, fp + 8);				 \   flush_cached_frames ();					 \   set_current_frame (create_new_frame (read_register (FP_REGNUM),\ 				       read_pc ())); }
end_define

begin_comment
comment|/* This sequence of words is the instructions      enter	0xff,0		82 ff 00      jsr	@0x00010203	7f ae c0 01 02 03      adjspd	0x69696969	7f a5 01 02 03 04      bpt			f2    Note this is 16 bytes.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{ 0x7f00ff82, 0x0201c0ae, 0x01a57f03, 0xf2040302 }
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|3
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|16
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_ADDR
value|5
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_NARGS
value|11
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
name|type
parameter_list|,
name|gcc_p
parameter_list|)
define|\
value|{								\ 	int	flipped;					\ 	flipped = fun | 0xc0000000;				\ 	flip_bytes (&flipped, 4);				\ 	*((int *) (((char *) dummyname)+CALL_DUMMY_ADDR)) = flipped;	\ 	flipped = - nargs * 4;					\ 	flip_bytes (&flipped, 4);				\ 	*((int *) (((char *) dummyname)+CALL_DUMMY_NARGS)) = flipped;	\ }
end_define

end_unit

