begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a merlin under utek 2.1    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ns16000
end_ifndef

begin_define
define|#
directive|define
name|ns16000
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This machine doesn't have the siginterrupt call.  */
end_comment

begin_define
define|#
directive|define
name|NO_SIGINTERRUPT
end_define

begin_comment
comment|/* Under Utek, a ptrace'd process can be the only active process for    an executable.  Therefore instead of /bin/sh use gdb-sh (which should    just be a copy of /bin/sh which is world readable and writeable).  */
end_comment

begin_define
define|#
directive|define
name|SHELL_FILE
value|"/usr/local/lib/gdb-sh"
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

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

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
value|{ register int op = read_memory_integer (pc, 1);	\   if (op == 0x82)					\     { op = read_memory_integer (pc+2,1);		\       if ((op& 0x80) == 0) pc += 3;			\       else if ((op& 0xc0) == 0x80) pc += 4;		\       else pc += 6;					\     }}
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
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|(0xfef000)
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0x800000)
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

begin_comment
comment|/* Return 1 if P points to an invalid floating point value.  */
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
comment|/* Define this to say that the "svc" insn is followed by    codes in memory saying which kind of system call it is.  */
end_comment

begin_define
define|#
directive|define
name|NS32K_SVC_IMMED_OPERANDS
end_define

begin_comment
comment|/* Largest integer type */
end_comment

begin_define
define|#
directive|define
name|LONGEST
value|long
end_define

begin_comment
comment|/* Name of the builtin type for the LONGEST type above. */
end_comment

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
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "r7",	\ 			"pc", "sp", "fp", "ps",				\  			"fsr",						\  			"f0", "f1", "f2", "f3", "f4", "f5", "f6", "f7",	\ 			"l0", "l1", "l2", "l3", "l4",			\  			}
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
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
value|10
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|9
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

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|11
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|FPS_REGNUM
value|12
end_define

begin_comment
comment|/* Floating point status register */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|13
end_define

begin_comment
comment|/* Floating point register 0 */
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
value|{ 									\   switch (regno) {							\   case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:	\ 	addr = blockend + (R0 - regno) * sizeof (int); break;		\   case PC_REGNUM:							\   	addr = blockend + PC * sizeof (int); break;			\   case SP_REGNUM:							\   	addr = blockend + SP * sizeof (int); break;			\   case FP_REGNUM:							\   	addr = blockend + FP * sizeof (int); break;			\   case PS_REGNUM:							\   	addr = blockend + 12 * sizeof (int); break;			\   case FPS_REGNUM:							\   	addr = 108; break;						\   case FP0_REGNUM + 0: case FP0_REGNUM + 1:				\   case FP0_REGNUM + 2: case FP0_REGNUM + 3: 				\   case FP0_REGNUM + 4: case FP0_REGNUM + 5: 				\   case FP0_REGNUM + 6: case FP0_REGNUM + 7: 				\   	addr = 76 + (regno - FP0_REGNUM) * sizeof (float); break;	\   case LP0_REGNUM + 0: case LP0_REGNUM + 1:				\   case LP0_REGNUM + 2: case LP0_REGNUM + 3:				\   	addr = 76 + (regno - LP0_REGNUM) * sizeof (double); break;	\   default:								\   	printf ("bad argument to REGISTER_U_ADDR %d\n", regno);		\ 	abort ();							\   }									\ }
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|((NUM_REGS - 4) * sizeof (int) + 4 * sizeof (double))
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
value|((N)>= FP0_REGNUM ?		\     ((N)>= LP0_REGNUM ?	\      builtin_type_double	\      : builtin_type_float)	\    : builtin_type_int)
end_define

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function.     On this machine this is a no-op, as gcc doesn't run on it yet.    This calling convention is not used. */
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

begin_comment
comment|/* In the case of the Merlin, the frame's nominal address is the FP value,    and at that address is saved previous FP value as a 4-byte word.  */
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
comment|/* compute base of arguments */
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
value|{ CORE_ADDR pc;						\   int insn;						\   int addr_mode;					\   int width;						\ 							\   pc = FRAME_SAVED_PC (fi);				\   insn = read_memory_integer (pc,2);			\   addr_mode = (insn>> 11)& 0x1f;			\   insn = insn& 0x7ff;					\   if ((insn& 0x7fc) == 0x57c				\&& addr_mode == 0x14)
comment|/* immediate */
value|\     { if (insn == 0x57c)
comment|/* adjspb */
value|\ 	width = 1;					\       else if (insn == 0x57d)
comment|/* adjspw */
value|\ 	width = 2;					\       else if (insn == 0x57f)
comment|/* adjspd */
value|\ 	width = 4;					\       numargs = read_memory_integer (pc+2,width);	\       if (width> 1)					\ 	flip_bytes (&numargs, width);			\       numargs = - sign_extend (numargs, width*8) / 4; }	\   else numargs = -1;					\ }
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
value|{ int regmask,regnum;						\   int localcount;						\   CORE_ADDR enter_addr;						\   CORE_ADDR next_addr;						\ 								\   enter_addr = get_pc_function_start ((frame_info)->pc);	\   regmask = read_memory_integer (enter_addr+1, 1);		\   localcount = ns32k_localcount (enter_addr);			\   next_addr = (frame_info)->frame + localcount;			\   for (regnum = 0; regnum< 8; regnum++, regmask>>= 1)		\     (frame_saved_regs).regs[regnum]				\       = (regmask& 1) ? (next_addr -= 4) : 0;			\   (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame + 4;	\   (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame + 4;	\   (frame_saved_regs).regs[FP_REGNUM]				\      = read_memory_integer ((frame_info)->frame, 4); }
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
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);	\   register int regnum;					\   sp = push_word (sp, read_register (PC_REGNUM));	\   sp = push_word (sp, read_register (FP_REGNUM));	\   write_register (FP_REGNUM, sp);			\   for (regnum = 0; regnum< 8; regnum++)  		\     sp = push_word (sp, read_register (regnum));	\   write_register (SP_REGNUM, sp);  			\ }
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register FRAME frame = get_current_frame ();			 \   register CORE_ADDR fp;					 \   register int regnum;						 \   struct frame_saved_regs fsr;					 \   struct frame_info *fi;						 \   fi = get_frame_info (frame);					 \   fp = fi->frame;						 \   get_frame_saved_regs (fi,&fsr);				 \   for (regnum = 0; regnum< 8; regnum++)			 \     if (fsr.regs[regnum])					 \       write_register (regnum, read_memory_integer (fsr.regs[regnum], 4)); \   write_register (FP_REGNUM, read_memory_integer (fp, 4));	 \   write_register (PC_REGNUM, read_memory_integer (fp + 4, 4));   \   write_register (SP_REGNUM, fp + 8);				 \   flush_cached_frames ();					 \   set_current_frame (create_new_frame (read_register (FP_REGNUM),\ 				       read_pc ()));		 \ }
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
name|type
parameter_list|)
define|\
value|{ int flipped = fun | 0xc0000000;				\   flip_bytes (&flipped, 4);					\   *((int *) (((char *) dummyname)+CALL_DUMMY_ADDR)) = flipped;	\   flipped = - nargs * 4;					\   flip_bytes (&flipped, 4);					\   *((int *) (((char *) dummyname)+CALL_DUMMY_NARGS)) = flipped;	\ }
end_define

begin_escape
end_escape

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

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
value|{ asm (".globl end");         \   asm ("movl $ end, sp");      \   asm ("clrl fp"); }
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("pushl fp");
end_define

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("movl (sp), fp");
end_define

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm ("pushl 8(sp)");        \   asm ("pushl 8(sp)");        \   asm ("pushal 0x14(sp)");    \   asm ("pushr $037777"); }
end_define

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("popr $037777");    \   asm ("subl2 $8,(sp)");   \   asm ("movl (sp),sp");    \   asm ("rei"); }
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

