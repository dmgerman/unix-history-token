begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on a 68000 series machine.    Copyright 1986, 1987, 1989, 1990, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Generic 68000 stuff, to be included by other tm-*.h files.    Define HAVE_68881 if that is the case.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_68881
argument_list|)
end_if

begin_define
define|#
directive|define
name|IEEE_FLOAT
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define the bit, byte, and word ordering of the machine.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|BIG_ENDIAN
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SKIP_PROLOGUE
argument_list|)
end_if

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|ip
parameter_list|)
value|{(ip) = m68k_skip_prologue(ip);}
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|m68k_skip_prologue
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
name|ip
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* Stack grows downward.  */
end_comment

begin_define
define|#
directive|define
name|INNER_THAN
value|<
end_define

begin_comment
comment|/* Sequence of bytes for breakpoint instruction.    This is a TRAP instruction.  The last 4 bits (0xf below) is the    vector.  Systems which don't use 0xf should define BPT_VECTOR    themselves before including this file.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BPT_VECTOR
argument_list|)
end_if

begin_define
define|#
directive|define
name|BPT_VECTOR
value|0xf
end_define

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
name|BREAKPOINT
argument_list|)
end_if

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x4e, (0x40 | BPT_VECTOR)}
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If your kernel resets the pc after the trap happens you may need to    define this before including this file.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DECR_PC_AFTER_BREAK
argument_list|)
end_if

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Nonzero if instruction at PC is a return instruction.  */
end_comment

begin_comment
comment|/* Allow any of the return instructions, including a trapv and a return    from interupt.  */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|pc
parameter_list|)
value|((read_memory_integer (pc, 2)& ~0x3) == 0x4e74)
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
comment|/* Say how long registers are.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_TYPE
value|long
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_68881
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|GDB_TARGET_IS_SUN3
argument_list|)
end_if

begin_comment
comment|/* Sun3 status includes fpflags, which shows whether the FPU has been used        by the process, and whether the FPU was done with an instruction or         was interrupted in the middle of a long instruction.  See<machine/reg.h>.  */
end_comment

begin_comment
comment|/*                      a&d, pc,sr, fp, fpstat, fpflags   */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|31
end_define

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(16*4 + 8 + 8*12 + 3*4 + 4)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Not sun3.  */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|29
end_define

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(16*4 + 8 + 8*12 + 3*4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Not sun3.  */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* No 68881.  */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|18
end_define

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(16*4 + 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* No 68881.  */
end_comment

begin_comment
comment|/* Index within `registers' of the first byte of the space for    register N.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_68881
argument_list|)
end_if

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

begin_comment
comment|/* Note that the unsigned cast here forces the result of the    subtraction to very high positive values if N< FP0_REGNUM */
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
comment|/* Put the declaration out here because if it's in the macros, PCC    will complain.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|ext_format
name|ext_format_68881
decl_stmt|;
end_decl_stmt

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
value|{ \   if ((REGNUM)>= FP0_REGNUM&& (REGNUM)< FPC_REGNUM)	\     ieee_extended_to_double (&ext_format_68881, (FROM), (double *)(TO)); \   else					\     memcpy ((TO), (FROM), 4);	\ }
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
value|{ \   if ((REGNUM)>= FP0_REGNUM&& (REGNUM)< FPC_REGNUM)	\     double_to_ieee_extended (&ext_format_68881, (double *)(FROM), (TO)); \   else					\     memcpy ((TO), (FROM), 4);	\ }
end_define

begin_comment
comment|/* Return the GDB type object for the "standard" data type    of data in register N.  */
end_comment

begin_comment
comment|/* Note, for registers which contain addresses return    pointer to void, not pointer to char, because we don't    want to attempt to print the string after printing the address.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_TYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|(((unsigned)(N) - FP0_REGNUM)< 8 ? builtin_type_double :           \   (N) == PC_REGNUM || (N) == FP_REGNUM || (N) == SP_REGNUM ?         \   lookup_pointer_type (builtin_type_void) : builtin_type_int)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no 68881.  */
end_comment

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
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the 68000, all regs are 4 bytes.  */
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
comment|/* Number of bytes of storage in the program's representation    for register N.  On the 68000, all regs are 4 bytes.  */
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
value|memcpy ((TO), (FROM), 4);
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
value|memcpy ((TO), (FROM), 4);
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* No 68881.  */
end_comment

begin_comment
comment|/* Initializer for an array of names of registers.    Entries beyond the first NUM_REGS are ignored.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"d0", "d1", "d2", "d3", "d4", "d5", "d6", "d7", \   "a0", "a1", "a2", "a3", "a4", "a5", "fp", "sp", \   "ps", "pc",  \   "fp0", "fp1", "fp2", "fp3", "fp4", "fp5", "fp6", "fp7", \   "fpcontrol", "fpstatus", "fpiaddr", "fpcode", "fpflags" }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|A1_REGNUM
value|9
end_define

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_68881
argument_list|)
end_if

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

begin_define
define|#
directive|define
name|FPS_REGNUM
value|27
end_define

begin_comment
comment|/* 68881 status register */
end_comment

begin_define
define|#
directive|define
name|FPI_REGNUM
value|28
end_define

begin_comment
comment|/* 68881 iaddr register */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 68881.  */
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
value|{ write_register (A1_REGNUM, (ADDR)); }
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  This is assuming that floating point values are returned    as doubles in d0/d1.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|EXTRACT_RETURN_VALUE
argument_list|)
end_if

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
value|memcpy ((VALBUF),							\ 	  (char *)(REGBUF) +						\ 	         (TYPE_LENGTH(TYPE)>= 4 ? 0 : 4 - TYPE_LENGTH(TYPE)),	\ 	  TYPE_LENGTH(TYPE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Write into appropriate registers a function return value    of type TYPE, given in virtual format.  Assumes floats are passed    in d0/d1.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|STORE_RETURN_VALUE
argument_list|)
end_if

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

begin_endif
endif|#
directive|endif
end_endif

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
value|(*(CORE_ADDR *)(REGBUF))
end_define

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address and produces the frame's    chain-pointer.    In the case of the 68000, the frame's nominal address    is the address of a 4-byte word containing the calling frame's address.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
value|(FRAME_ADDR)m68k_frame_chain(thisframe)
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FRAME_NUM_ARGS
argument_list|)
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
value|(val = -1)
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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|FRAME_FIND_SAVED_REGS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_68881
argument_list|)
end_if

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
value|{ register int regnum;							\   register int regmask;							\   register CORE_ADDR next_addr;						\   register CORE_ADDR pc;						\   int nextinsn;								\   bzero (&frame_saved_regs, sizeof frame_saved_regs);			\   if ((frame_info)->pc>= (frame_info)->frame - CALL_DUMMY_LENGTH - FP_REGNUM*4 - 8*12 - 4 \&& (frame_info)->pc<= (frame_info)->frame)				\     { next_addr = (frame_info)->frame;					\       pc = (frame_info)->frame - CALL_DUMMY_LENGTH - FP_REGNUM * 4 - 8*12 - 4; }\   else   								\     { pc = get_pc_function_start ((frame_info)->pc); 			\
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
value|\       for (regnum = 15; regnum>= 0; regnum--, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr -= 4); }		\   else if (0x2f00 == (0xfff0& read_memory_integer (pc, 2)))		\     { regnum = 0xf& read_memory_integer (pc, 2); pc += 2;		\       (frame_saved_regs).regs[regnum] = (next_addr -= 4); }		\
comment|/* fmovemx to index of sp may follow.  */
value|\   regmask = read_memory_integer (pc + 2, 2);				\   nextinsn = 0xffff& read_memory_integer (pc, 2);			\   if (0xf236 == nextinsn						\&& (regmask& 0xff00) == 0xf000)					\     { pc += 10;
comment|/* Regmask's low bit is for register fp0, the first written */
value|\       for (regnum = FP0_REGNUM + 7; regnum>= FP0_REGNUM; regnum--, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr += 12) - 12;	\       regmask = read_memory_integer (pc + 2, 2); }			\
comment|/* clrw -(sp); movw ccr,-(sp) may follow.  */
value|\   if (0x426742e7 == read_memory_integer (pc, 4))			\     (frame_saved_regs).regs[PS_REGNUM] = (next_addr -= 4);		\   lose: ;								\   (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame + 8;		\   (frame_saved_regs).regs[FP_REGNUM] = (frame_info)->frame;		\   (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame + 4;		\ }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* no 68881.  */
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
value|{ register int regnum;							\   register int regmask;							\   register CORE_ADDR next_addr;						\   register CORE_ADDR pc;						\   bzero (&frame_saved_regs, sizeof frame_saved_regs);			\   if ((frame_info)->pc>= (frame_info)->frame - CALL_DUMMY_LENGTH - FP_REGNUM*4 - 4 \&& (frame_info)->pc<= (frame_info)->frame)				\     { next_addr = (frame_info)->frame;					\       pc = (frame_info)->frame - CALL_DUMMY_LENGTH - FP_REGNUM * 4 - 4; }\   else   								\     { pc = get_pc_function_start ((frame_info)->pc); 			\
comment|/* Verify we have a link a6 instruction next;			\ 	 if not we lose.  If we win, find the address above the saved   \ 	 regs using the amount of storage from the link instruction.  */
value|\       if (044016 == read_memory_integer (pc, 2))			\ 	next_addr = (frame_info)->frame + read_memory_integer (pc += 2, 4), pc+=4; \       else if (047126 == read_memory_integer (pc, 2))			\ 	next_addr = (frame_info)->frame + read_memory_integer (pc += 2, 2), pc+=2; \       else goto lose;							\
comment|/* If have an addal #-n, sp next, adjust next_addr.  */
value|\       if ((0177777& read_memory_integer (pc, 2)) == 0157774)		\ 	next_addr += read_memory_integer (pc += 2, 4), pc += 4;		\     }									\
comment|/* next should be a moveml to (sp) or -(sp) or a movl r,-(sp) */
value|\   regmask = read_memory_integer (pc + 2, 2);				\   if (0044327 == read_memory_integer (pc, 2))				\     { pc += 4;
comment|/* Regmask's low bit is for register 0, the first written */
value|\       for (regnum = 0; regnum< 16; regnum++, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr += 4) - 4; }	\   else if (0044347 == read_memory_integer (pc, 2))			\     { pc += 4;
comment|/* Regmask's low bit is for register 15, the first pushed */
value|\       for (regnum = 15; regnum>= 0; regnum--, regmask>>= 1)		\ 	if (regmask& 1)						\           (frame_saved_regs).regs[regnum] = (next_addr -= 4); }		\   else if (0x2f00 == (0xfff0& read_memory_integer (pc, 2)))		\     { regnum = 0xf& read_memory_integer (pc, 2); pc += 2;		\       (frame_saved_regs).regs[regnum] = (next_addr -= 4); }		\
comment|/* clrw -(sp); movw ccr,-(sp) may follow.  */
value|\   if (0x426742e7 == read_memory_integer (pc, 4))			\     (frame_saved_regs).regs[PS_REGNUM] = (next_addr -= 4);		\   lose: ;								\   (frame_saved_regs).regs[SP_REGNUM] = (frame_info)->frame + 8;		\   (frame_saved_regs).regs[FP_REGNUM] = (frame_info)->frame;		\   (frame_saved_regs).regs[PC_REGNUM] = (frame_info)->frame + 4;		\ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no 68881.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no FIND_FRAME_SAVED_REGS.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Things needed for making the inferior call functions.    It seems like every m68k based machine has almost identical definitions    in the individual machine's configuration files.  Most other cpu types    (mips, i386, etc) have routines in their *-tdep.c files to handle this    for most configurations.  The m68k family should be able to do this as    well.  These macros can still be overridden when necessary.  */
end_comment

begin_comment
comment|/* The CALL_DUMMY macro is the sequence of instructions, as disassembled    by gdb itself:  	fmovemx fp0-fp7,sp@-			0xf227 0xe0ff 	moveml d0-a5,sp@-			0x48e7 0xfffc 	clrw sp@-				0x4267 	movew ccr,sp@-				0x42e7  	/..* The arguments are pushed at this point by GDB; 	no code is needed in the dummy for this. 	The CALL_DUMMY_START_OFFSET gives the position of  	the following jsr instruction.  *../  	jsr @#0x32323232			0x4eb9 0x3232 0x3232 	addal #0x69696969,sp			0xdffc 0x6969 0x6969 	trap #<your BPT_VECTOR number here>	0x4e4? 	nop					0x4e71     Note this is CALL_DUMMY_LENGTH bytes (28 for the above example).    We actually start executing at the jsr, since the pushing of the    registers is done by PUSH_DUMMY_FRAME.  If this were real code,    the arguments for the function called by the jsr would be pushed    between the moveml and the jsr, and we could allow it to execute through.    But the arguments have to be pushed by GDB after the PUSH_DUMMY_FRAME is    done, and we cannot allow the moveml to push the registers again lest    they be taken for the arguments.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_68881
argument_list|)
end_if

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0xf227e0ff, 0x48e7fffc, 0x426742e7, 0x4eb93232, 0x3232dffc, 0x69696969, (0x4e404e71 | (BPT_VECTOR<< 16))}
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|28
end_define

begin_comment
comment|/* Size of CALL_DUMMY */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|12
end_define

begin_comment
comment|/* Offset to jsr instruction*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CALL_DUMMY
value|{0x48e7fffc, 0x426742e7, 0x4eb93232, 0x3232dffc, 0x69696969, (0x4e404e71 | (BPT_VECTOR<< 16))}
end_define

begin_define
define|#
directive|define
name|CALL_DUMMY_LENGTH
value|24
end_define

begin_comment
comment|/* Size of CALL_DUMMY */
end_comment

begin_define
define|#
directive|define
name|CALL_DUMMY_START_OFFSET
value|8
end_define

begin_comment
comment|/* Offset to jsr instruction*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_68881 */
end_comment

begin_comment
comment|/* Insert the specified number of args and function address    into a call sequence of the above form stored at DUMMYNAME.    We use the BFD routines to store a big-endian value of known size.  */
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
value|{ _do_putb32 (fun,     (char *) dummyname + CALL_DUMMY_START_OFFSET + 2);  \   _do_putb32 (nargs*4, (char *) dummyname + CALL_DUMMY_START_OFFSET + 8); }
end_define

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
value|{ m68k_push_dummy_frame (); }
end_define

begin_decl_stmt
specifier|extern
name|void
name|m68k_push_dummy_frame
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|m68k_pop_frame
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
value|{ m68k_pop_frame (); }
end_define

begin_comment
comment|/* Offset from SP to first arg on stack at first instruction of a function */
end_comment

begin_define
define|#
directive|define
name|SP_ARG0
value|(1 * 4)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNELDEBUG
end_ifdef

begin_decl_stmt
specifier|extern
name|int
name|kernel_debugging
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|FRAME_CHAIN_VALID
end_undef

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
value|(chain != 0&& \ 	 kernel_debugging ? inside_kernstack(chain) : \ 		(!inside_entry_file(FRAME_SAVED_PC(thisframe))))
end_define

begin_function_decl
specifier|extern
name|int
name|Xkernel_xfer_memory
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KERNEL_XFER_MEMORY
value|Xkernel_xfer_memory
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

