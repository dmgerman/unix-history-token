begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on an Intel i[345]86.    Copyright (C) 1995, 1996 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386_H
value|1
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_comment
comment|/* Forward decl's for prototypes */
end_comment

begin_struct_decl
struct_decl|struct
name|frame_info
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|frame_saved_regs
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_comment
comment|/* Used for example in valprint.c:print_floating() to enable checking    for NaN's */
end_comment

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_comment
comment|/* Number of traps that happen between exec'ing the shell to run an    inferior, and when we finally get to the inferior code.  This is 2    on most implementations. */
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
comment|/* Advance PC across any function entry prologue instructions to reach some    "real" code.  */
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
comment|/* Immediately after a function call, return the saved pc.  Can't always go    through the frames for this because on some machines the new frame is not    set up until the new function executes some instructions.  */
end_comment

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
value|(read_memory_integer (read_register (SP_REGNUM), 4))
end_define

begin_comment
comment|/* Stack grows downward.  */
end_comment

begin_define
define|#
directive|define
name|INNER_THAN
parameter_list|(
name|lhs
parameter_list|,
name|rhs
parameter_list|)
value|((lhs)< (rhs))
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
comment|/* Amount PC must be decremented by after a breakpoint.  This is often the    number of bytes in BREAKPOINT but not always. */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|1
end_define

begin_comment
comment|/* Say how long (ordinary) registers are.  This is a piece of bogosity    used in push_word and a few other places; REGISTER_RAW_SIZE is the    real way to know how big a register is.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_SIZE
value|4
end_define

begin_comment
comment|/* Number of machine registers */
end_comment

begin_define
define|#
directive|define
name|NUM_FREGS
value|0
end_define

begin_comment
comment|/*8*/
end_comment

begin_comment
comment|/* Number of FP regs */
end_comment

begin_define
define|#
directive|define
name|NUM_REGS
value|(16 + NUM_FREGS)
end_define

begin_comment
comment|/* Basic i*86 regs + FP regs */
end_comment

begin_comment
comment|/* Initializer for an array of names of registers.  There should be at least    NUM_REGS strings in this initializer.  Any excess ones are simply ignored.    The order of the first 8 registers must match the compiler's numbering    scheme (which is the same as the 386 scheme) and also regmap in the various    *-nat.c files. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{ "eax",   "ecx",    "edx",   "ebx", \ 			 "esp",   "ebp",    "esi",   "edi", \ 			 "eip",   "eflags", "cs",    "ss", \ 			 "ds",    "es",     "fs",    "gs", \ 			 "st0",   "st1",    "st2",   "st3", \ 			 "st4",   "st5",    "st6",   "st7", \ 			 }
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
comment|/* (ebp) Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|4
end_define

begin_comment
comment|/* (usp) Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|8
end_define

begin_comment
comment|/* (eip) Contains program counter */
end_comment

begin_define
define|#
directive|define
name|PS_REGNUM
value|9
end_define

begin_comment
comment|/* (ps)  Contains processor status */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|16
end_define

begin_comment
comment|/* (st0) 387 register */
end_comment

begin_define
define|#
directive|define
name|FPC_REGNUM
value|25
end_define

begin_comment
comment|/* 80387 control register */
end_comment

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's register    state, the array `registers'. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|((NUM_REGS - NUM_FREGS)*4 + NUM_FREGS*10)
end_define

begin_comment
comment|/* Index within `registers' of the first byte of the space for register N. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|N
parameter_list|)
define|\
value|(((N)< FP0_REGNUM) ? ((N) * 4) : ((((N) - FP0_REGNUM) * 10) + 64))
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation for    register N.  All registers are 4 bytes, except 387 st(0) - st(7),    which are 80 bits each. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|(((N)< FP0_REGNUM) ? 4 : 10)
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
comment|/* Number of bytes of storage in the program's representation    for register N. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|(((N)< FP0_REGNUM) ? 4 : 8)
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
comment|/* Return the GDB type object for the "standard" data type of data in     register N.  Perhaps si and di should go here, but potentially they    could be used for things other than address.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_TYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|(((N) == PC_REGNUM || (N) == FP_REGNUM || (N) == SP_REGNUM) \    ? lookup_pointer_type (builtin_type_void) \    : (((N)< FP0_REGNUM) \       ? builtin_type_int \       : builtin_type_double))
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
value|{ char buf[REGISTER_SIZE];	\     (SP) -= sizeof (ADDR);	\     store_address (buf, sizeof (ADDR), ADDR);	\     write_memory ((SP), buf, sizeof (ADDR)); }
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
value|i386_extract_return_value ((TYPE),(REGBUF),(VALBUF))
end_define

begin_decl_stmt
specifier|extern
name|void
name|i386_extract_return_value
name|PARAMS
argument_list|(
operator|(
expr|struct
name|type
operator|*
operator|,
name|char
index|[]
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Write into appropriate registers a function return value of type TYPE, given    in virtual format.  */
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
value|{    	       	       	       	       	       	       	       	       	     \     if (TYPE_CODE (TYPE) == TYPE_CODE_FLT)				     \       write_register_bytes (REGISTER_BYTE (FP0_REGNUM), (VALBUF),	     \ 			    TYPE_LENGTH (TYPE));			     \     else								     \       write_register_bytes (0, (VALBUF), TYPE_LENGTH (TYPE));  		     \   }
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state the address    in which a function should return its structure value, as a CORE_ADDR (or an    expression that can be used as one).  */
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
comment|/* The following redefines make backtracing through sigtramp work.    They manufacture a fake sigtramp frame and obtain the saved pc in sigtramp    from the sigcontext structure which is pushed by the kernel on the    user stack, along with a pointer to it.  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address and produces the frame's    chain-pointer.    In the case of the i386, the frame's nominal address    is the address of a 4-byte word containing the calling frame's address.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|((thisframe)->signal_handler_caller \    ? (thisframe)->frame \    : (!inside_entry_file ((thisframe)->pc) \       ? read_memory_integer ((thisframe)->frame, 4) \       : 0))
end_define

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
value|do { \     if ((FI)->signal_handler_caller) \       (FRAMELESS) = 0; \     else \       (FRAMELESS) = frameless_look_for_prologue(FI); \   } while (0)
end_define

begin_comment
comment|/* Saved Pc.  Get it from sigcontext if within sigtramp.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
define|\
value|(((FRAME)->signal_handler_caller \     ? sigtramp_saved_pc (FRAME) \     : read_memory_integer ((FRAME)->frame + 4, 4)) \    )
end_define

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|sigtramp_saved_pc
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
comment|/* Return number of args passed to a frame.  Can return -1, meaning no way    to tell, which is typical now that the C compiler delays popping them.  */
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

begin_decl_stmt
specifier|extern
name|int
name|i386_frame_num_args
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

begin_decl_stmt
specifier|extern
name|void
name|i386_frame_find_saved_regs
name|PARAMS
argument_list|(
operator|(
expr|struct
name|frame_info
operator|*
operator|,
expr|struct
name|frame_saved_regs
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|{ i386_push_dummy_frame (); }
end_define

begin_decl_stmt
specifier|extern
name|void
name|i386_push_dummy_frame
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
value|{ i386_pop_frame (); }
end_define

begin_decl_stmt
specifier|extern
name|void
name|i386_pop_frame
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/* this is   *   call 11223344 (32 bit relative)  *   int3  */
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

begin_define
define|#
directive|define
name|CALL_DUMMY_BREAKPOINT_OFFSET
value|5
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
value|{ \ 	int from, to, delta, loc; \ 	loc = (int)(read_register (SP_REGNUM) - CALL_DUMMY_LENGTH); \ 	from = loc + 5; \ 	to = (int)(fun); \ 	delta = to - from; \ 	*((char *)(dummyname) + 1) = (delta& 0xff); \ 	*((char *)(dummyname) + 2) = ((delta>> 8)& 0xff); \ 	*((char *)(dummyname) + 3) = ((delta>> 16)& 0xff); \ 	*((char *)(dummyname) + 4) = ((delta>> 24)& 0xff); \ }
end_define

begin_decl_stmt
specifier|extern
name|void
name|print_387_control_word
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|print_387_status_word
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Offset from SP to first arg on stack at first instruction of a function */
end_comment

begin_define
define|#
directive|define
name|SP_ARG0
value|(1 * 4)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef TM_I386_H */
end_comment

end_unit

