begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on an HP 9000 model 320, for GDB, the GNU debugger.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Define the bit, byte, and word ordering of the machine.  */
end_comment

begin_define
define|#
directive|define
name|BITS_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|BYTES_BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|WORDS_BIG_ENDIAN
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HP9K320
end_ifndef

begin_define
define|#
directive|define
name|HP9K320
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this to indicate problems with traps after continuing.  */
end_comment

begin_define
define|#
directive|define
name|HP_OS_BUG
end_define

begin_comment
comment|/* Set flag to indicate whether HP's assembler is in use. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__HPUX_ASM__
end_ifdef

begin_define
define|#
directive|define
name|HPUX_ASM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HPUX_ASM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define this for versions of hp-ux older than 6.0 */
end_comment

begin_comment
comment|/* #define HPUX_VERSION_5 */
end_comment

begin_comment
comment|/* define USG if you are using sys5 /usr/include's */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_comment
comment|/* The hp9k320.h doesn't seem to have this feature.  */
end_comment

begin_comment
comment|/* #define SET_STACK_LIMIT_HUGE */
end_comment

begin_comment
comment|/* So we'll just have to avoid big alloca's.  */
end_comment

begin_define
define|#
directive|define
name|BROKEN_LARGE_ALLOCA
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
value|{ register int op = read_memory_integer (pc, 2);	\   if (op == 0047126)				\     pc += 4;
comment|/* Skip link #word */
value|\   else if (op == 0044016)			\     pc += 6;
comment|/* Skip link #long */
value|\ }
end_define

begin_comment
comment|/* Immediately after a function call, return the saved pc.    Can't go through the frames for this because on some machines    the new frame is not set up until the new function executes    some instructions.  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX_VERSION_5
end_ifdef

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0x00979000
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0x00C01000
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
value|0xFFF00000
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
value|{0x4e, 0x41}
end_define

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.    This is often the number of bytes in BREAKPOINT    but not always.  */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|2
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
value|(read_memory_integer (pc, 2) == 0x4e75)
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
comment|/* Just a first guess; not checked */
end_comment

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
value|29
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7", \   "a0", "a1", "a2", "a3", "a4", "a5", "fp", "sp", \   "ps", "pc",  \   "fp0", "fp1", "fp2", "fp3", "fp4", "fp5", "fp6", "fp7", \   "fpcontrol", "fpstatus", "fpiaddr" }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|14
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|15
end_define

begin_comment
comment|/* Contains address of top of stack */
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
name|PC_REGNUM
value|17
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|18
end_define

begin_comment
comment|/* Floating point register 0 */
end_comment

begin_define
define|#
directive|define
name|FPC_REGNUM
value|26
end_define

begin_comment
comment|/* 68881 control register */
end_comment

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(16*4+8*12+8+12)
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
value|((N)>= FPC_REGNUM ? (((N) - FPC_REGNUM) * 4) + 168	\   : (N)>= FP0_REGNUM ? (((N) - FP0_REGNUM) * 12) + 72	\   : (N) * 4)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the 68000, all regs are 4 bytes    except the floating point regs which are 12 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|(((unsigned)(N) - FP0_REGNUM)< 8 ? 12 : 4)
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  On the 68000, all regs are 4 bytes    except the floating point regs which are 8-byte doubles.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|(((unsigned)(N) - FP0_REGNUM)< 8 ? 8 : 4)
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
value|(((unsigned)(N) - FP0_REGNUM)< 8)
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
value|{ if ((REGNUM)>= FP0_REGNUM&& (REGNUM)< FPC_REGNUM)	\     convert_from_68881 ((FROM), (TO));	\   else					\     bcopy ((FROM), (TO), 4); }
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
value|{ if ((REGNUM)>= FP0_REGNUM&& (REGNUM)< FPC_REGNUM)	\     convert_to_68881 ((FROM), (TO));	\   else					\     bcopy ((FROM), (TO), 4); }
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
value|(((unsigned)(N) - FP0_REGNUM)< 8 ? builtin_type_double : builtin_type_int)
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
value|{ write_register (9, (ADDR)); }
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

begin_define
define|#
directive|define
name|REGISTER_ADDR
parameter_list|(
name|u_ar0
parameter_list|,
name|regno
parameter_list|)
define|\
value|(((regno)< PS_REGNUM)						\    ? (&((struct exception_stack *) (u_ar0))->e_regs[(regno + R0)])	\    : (((regno) == PS_REGNUM)						\       ? ((int *) (&((struct exception_stack *) (u_ar0))->e_PS))		\       : (&((struct exception_stack *) (u_ar0))->e_PC)))
end_define

begin_define
define|#
directive|define
name|FP_REGISTER_ADDR
parameter_list|(
name|u
parameter_list|,
name|regno
parameter_list|)
define|\
value|(((char *)								\     (((regno)< FPC_REGNUM)						\      ? (&u.u_pcb.pcb_mc68881[FMC68881_R0 + (((regno) - FP0_REGNUM) * 3)]) \      : (&u.u_pcb.pcb_mc68881[FMC68881_C + ((regno) - FPC_REGNUM)])))	\    - ((char *) (& u)))
end_define

begin_escape
end_escape

begin_comment
comment|/* Do implement the attach and detach commands.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
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
comment|/* In the case of the Sun, the frame's nominal address    is the address of a 4-byte word containing the calling frame's address.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(outside_startup_file ((thisframe)->pc) ?		\    read_memory_integer ((thisframe)->frame, 4) :	\    0)
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
comment|/* Set VAL to the number of args passed to frame described by FI.    Can set VAL to -1, meaning no way to tell.  */
end_comment

begin_comment
comment|/* We can't tell how many args there are    now that the C compiler delays popping them.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|val
parameter_list|,
name|fi
parameter_list|)
value|(val = -1)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|val
parameter_list|,
name|fi
parameter_list|)
define|\
value|{ register CORE_ADDR pc = FRAME_SAVED_PC (fi);		\   register int insn = 0177777& read_memory_integer (pc, 2);	\   val = 0;							\   if (insn == 0047757 || insn == 0157374)
comment|/* lea W(sp),sp or addaw #W,sp */
value|\     val = read_memory_integer (pc + 2, 2);			\   else if ((insn& 0170777) == 0050217
comment|/* addql #N, sp */
value|\ 	   || (insn& 0170777) == 0050117)
comment|/* addqw */
value|\     { val = (insn>> 9)& 7; if (val == 0) val = 8; }		\   else if (insn == 0157774)
comment|/* addal #WW, sp */
value|\     val = read_memory_integer (pc + 2, 4);			\   val>>= 2; }
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|{ register int regnum;							\   register int regmask;							\   register CORE_ADDR next_addr;						\   register CORE_ADDR pc;						\   int nextinsn;								\   bzero (&frame_saved_regs, sizeof frame_saved_regs);			\   if ((frame_info)->pc>= (frame_info)->frame - CALL_DUMMY_LENGTH - FP_REGNUM*4 - 8*12 - 4 \&& (frame_info)->pc<= (frame_info)->frame)			\     { next_addr = (frame_info)->frame;					\       pc = (frame_info)->frame - CALL_DUMMY_LENGTH - FP_REGNUM * 4 - 8*12 - 4; }\   else   								\     { pc = get_pc_function_start ((frame_info)->pc); 			\
comment|/* Verify we have a link a6 instruction next;			\ 	 if not we lose.  If we win, find the address above the saved   \ 	 regs using the amount of storage from the link instruction.  */
value|\       if (044016 == read_memory_integer (pc, 2))			\ 	next_addr = (frame_info)->frame + read_memory_integer (pc += 2, 4), pc+=4; \       else if (047126 == read_memory_integer (pc, 2))			\ 	next_addr = (frame_info)->frame + read_memory_integer (pc += 2, 2), pc+=2; \       else goto lose;							\
comment|/* If have an addal #-n, sp next, adjust next_addr.  */
value|\       if ((0177777& read_memory_integer (pc, 2)) == 0157774)		\ 	next_addr += read_memory_integer (pc += 2, 4), pc += 4;		\     }									\
comment|/* next should be a moveml to (sp) or -(sp) or a movl r,-(sp) */
value|\   regmask = read_memory_integer (pc + 2, 2);				\
comment|/* But before that can come an fmovem.  Check for it.  */
value|\   nextinsn = 0xffff& read_memory_integer (pc, 2);			\   if (0xf227 == nextinsn						\&& (regmask& 0xff00) == 0xe000)					\     { pc += 4;
comment|/* Regmask's low bit is for register fp7, the first pushed */
value|\       for (regnum = FP0_REGNUM + 7; regnum>= FP0_REGNUM; regnum--, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr -= 12);		\       regmask = read_memory_integer (pc + 2, 2); }			\   if (0044327 == read_memory_integer (pc, 2))				\     { pc += 4;
comment|/* Regmask's low bit is for register 0, the first written */
value|\       for (regnum = 0; regnum< 16; regnum++, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr += 4) - 4; }	\   else if (0044347 == read_memory_integer (pc, 2))			\     { pc += 4;
comment|/* Regmask's low bit is for register 15, the first pushed */
value|\       for (regnum = 15; regnum>= 0; regnum--, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr -= 4); }		\   else if (0x2f00 == 0xfff0& read_memory_integer (pc, 2))		\     { regnum = 0xf& read_memory_integer (pc, 2); pc += 2;		\       (frame_saved_regs).regs[regnum] = (next_addr -= 4); }		\
comment|/* fmovemx to index of sp may follow.  */
value|\   regmask = read_memory_integer (pc + 2, 2);				\   nextinsn = 0xffff& read_memory_integer (pc, 2);			\   if (0xf236 == nextinsn						\&& (regmask& 0xff00) == 0xf000)					\     { pc += 10;
comment|/* Regmask's low bit is for register fp0, the first written */
value|\       for (regnum = FP0_REGNUM + 7; regnum>= FP0_REGNUM; regnum--, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr += 12) - 12;	\       regmask = read_memory_integer (pc + 2, 2); }			\
comment|/* clrw -(sp); movw ccr,-(sp) may follow.  */
value|\   if (0x426742e7 == read_memory_integer (pc, 4))			\     (frame_saved_regs).regs[PS_REGNUM] = (next_addr -= 4);		\   lose: ;								\   (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame + 8;		\   (frame_saved_regs).regs[FP_REGNUM] = (frame_info)->frame;		\   (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame + 4;		\ }
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
value|{ register CORE_ADDR sp = read_register (SP_REGNUM);			\   register int regnum;							\   char raw_buffer[12];							\   sp = push_word (sp, read_register (PC_REGNUM));			\   sp = push_word (sp, read_register (FP_REGNUM));			\   write_register (FP_REGNUM, sp);					\   for (regnum = FP0_REGNUM + 7; regnum>= FP0_REGNUM; regnum--)		\     { read_register_bytes (REGISTER_BYTE (regnum), raw_buffer, 12);	\       sp = push_bytes (sp, raw_buffer, 12); }				\   for (regnum = FP_REGNUM - 1; regnum>= 0; regnum--)			\     sp = push_word (sp, read_register (regnum));			\   sp = push_word (sp, read_register (PS_REGNUM));			\   write_register (SP_REGNUM, sp);  }
end_define

begin_comment
comment|/* Discard from the stack the innermost frame,     restoring all saved registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|{ register FRAME frame = get_current_frame ();			 \   register CORE_ADDR fp;					 \   register int regnum;						 \   struct frame_saved_regs fsr;					 \   struct frame_info *fi;					 \   char raw_buffer[12];						 \   fi = get_frame_info (frame);					 \   fp = fi->frame;						 \   get_frame_saved_regs (fi,&fsr);				 \   for (regnum = FP0_REGNUM + 7; regnum>= FP0_REGNUM; regnum--)	 \     if (fsr.regs[regnum])					 \       { read_memory (fsr.regs[regnum], raw_buffer, 12);		 \         write_register_bytes (REGISTER_BYTE (regnum), raw_buffer, 12); }\   for (regnum = FP_REGNUM - 1; regnum>= 0; regnum--)		 \     if (fsr.regs[regnum])					 \       write_register (regnum, read_memory_integer (fsr.regs[regnum], 4)); \   if (fsr.regs[PS_REGNUM])					 \     write_register (PS_REGNUM, read_memory_integer (fsr.regs[PS_REGNUM], 4)); \   write_register (FP_REGNUM, read_memory_integer (fp, 4));	 \   write_register (PC_REGNUM, read_memory_integer (fp + 4, 4));   \   write_register (SP_REGNUM, fp + 8);				 \   flush_cached_frames ();					 \   set_current_frame (create_new_frame (read_register (FP_REGNUM),\ 				       read_pc ()));}
end_define

begin_comment
comment|/* This sequence of words is the instructions      fmovem 0xff,-(sp)      moveml 0xfffc,-(sp)      clrw -(sp)      movew ccr,-(sp)      /..* The arguments are pushed at this point by GDB; 	no code is needed in the dummy for this. 	The CALL_DUMMY_START_OFFSET gives the position of  	the following jsr instruction.  *../      jsr @#32323232      addl #69696969,sp      bpt      nop Note this is 28 bytes. We actually start executing at the jsr, since the pushing of the registers is done by PUSH_DUMMY_FRAME.  If this were real code, the arguments for the function called by the jsr would be pushed between the moveml and the jsr, and we could allow it to execute through. But the arguments have to be pushed by GDB after the PUSH_DUMMY_FRAME is done, and we cannot allow the moveml to push the registers again lest they be taken for the arguments.  */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0xf227e0ff, 0x48e7fffc, 0x426742e7, 0x4eb93232, 0x3232dffc, 0x69696969, 0x4e414e71}
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|28
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|12
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
value|{ *(int *)((char *) dummyname + 20) = nargs * 4;  \   *(int *)((char *) dummyname + 14) = fun; }
end_define

begin_escape
end_escape

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
value|{ 0, 0, 0, 0, SIGTRAP, 0, 0, 0, \   0, SIGTRAP, 0, 0, 0, 0, 0, SIGKILL, \   0, 0, 0, 0, 0, 0, 0, 0, \   SIGILL }
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|HPUX_ASM
end_ifndef

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
value|{ asm (".globl end");         \   asm ("movel $ end, sp");      \   asm ("clrl fp"); }
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("movel fp, -(sp)");
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
value|{ asm ("clrw -(sp)");	      \   asm ("pea 10(sp)");	      \   asm ("movem $ 0xfffe,-(sp)"); }
end_define

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("subil $8,28(sp)");     \   asm ("movem (sp),$ 0xffff"); \   asm ("rte"); }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* HPUX_ASM */
end_comment

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
value|{ asm ("global end");							\   asm ("mov.l&end,%sp");						\   asm ("clr.l %a6"); }
end_define

begin_comment
comment|/* Push the frame pointer register on the stack.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_FRAME_PTR
define|\
value|asm ("mov.l %fp,-(%sp)");
end_define

begin_comment
comment|/* Copy the top-of-stack to the frame pointer register.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME_PTR
define|\
value|asm ("mov.l (%sp),%fp");
end_define

begin_comment
comment|/* After KDB is entered by a fault, push all registers    that GDB thinks about (all NUM_REGS of them),    so that they appear in order of ascending GDB register number.    The fault code will be on the stack beyond the last register.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_REGISTERS
define|\
value|{ asm ("clr.w -(%sp)");							\   asm ("pea 10(%sp)");							\   asm ("movm.l&0xfffe,-(%sp)"); }
end_define

begin_comment
comment|/* Assuming the registers (including processor status) have been    pushed on the stack in order of ascending GDB register number,    restore them and return to the address in the saved PC register.  */
end_comment

begin_define
define|#
directive|define
name|POP_REGISTERS
define|\
value|{ asm ("subi.l&8,28(%sp)");						\   asm ("mov.m (%sp),&0xffff");						\   asm ("rte"); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX_ASM */
end_comment

end_unit

