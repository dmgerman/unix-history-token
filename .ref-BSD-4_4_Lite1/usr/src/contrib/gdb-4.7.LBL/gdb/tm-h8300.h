begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on a H8/300 series machine.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Contributed by Steve Chamberlain sac@cygnus.com */
end_comment

begin_define
define|#
directive|define
name|UNSIGNED_SHORT
parameter_list|(
name|X
parameter_list|)
value|((X)& 0xffff)
end_define

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
define|\
value|struct frame_saved_regs *fsr;	\ 	CORE_ADDR from_pc; \ 	CORE_ADDR args_pointer;\         CORE_ADDR locals_pointer ;
end_define

begin_comment
comment|/* Zero the frame_saved_regs pointer when the frame is initialized,    so that FRAME_FIND_SAVED_REGS () will know to allocate and    initialize a frame_saved_regs struct the first time it is called.    Set the arg_pointer to -1, which is not valid; 0 and other values    indicate real, cached values.  */
end_comment

begin_define
define|#
directive|define
name|INIT_EXTRA_FRAME_INFO
parameter_list|(
name|fromleaf
parameter_list|,
name|fi
parameter_list|)
define|\
value|init_extra_frame_info (fromleaf, fi)
end_define

begin_function_decl
specifier|extern
name|void
name|init_extra_frame_info
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IEEE_FLOAT
end_define

begin_comment
comment|/* Define the bit, byte, and word ordering of the machine.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_undef
undef|#
directive|undef
name|TARGET_INT_BIT
end_undef

begin_define
define|#
directive|define
name|TARGET_INT_BIT
value|16
end_define

begin_undef
undef|#
directive|undef
name|TARGET_PTR_BIT
end_undef

begin_define
define|#
directive|define
name|TARGET_PTR_BIT
value|16
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
name|ip
parameter_list|)
value|{(ip) = h8300_skip_prologue(ip);}
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|h8300_skip_prologue
parameter_list|()
function_decl|;
end_function_decl

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
value|UNSIGNED_SHORT(read_memory_integer (read_register (SP_REGNUM), 2))
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

begin_define
define|#
directive|define
name|BPT_VECTOR
value|0xf
end_define

begin_define
define|#
directive|define
name|BREAKPOINT
value|{0x4e, (0x40 | BPT_VECTOR)}
end_define

begin_comment
comment|/* If your kernel resets the pc after the trap happens you may need to    define this before including this file.  */
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
value|unsigned short
end_define

begin_define
define|#
directive|define
name|NUM_REGS
value|10
end_define

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(10*2)
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
value|((N) * 2)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the H8/300, all regs are 2 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|2
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N.  On the H8/300, all regs are 2 bytes.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|2
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|2
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|2
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
value|1
end_define

begin_comment
comment|/* Convert data from raw format for register REGNUM    to virtual format for register REGNUM.  */
end_comment

begin_comment
comment|/*#define REGISTER_CONVERT_TO_VIRTUAL(REGNUM,FROM,TO)  */
end_comment

begin_comment
comment|/* Convert data from virtual format for register REGNUM    to raw format for register REGNUM.  */
end_comment

begin_comment
comment|/*#define REGISTER_CONVERT_TO_RAW(REGNUM,FROM,TO)  */
end_comment

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
value|builtin_type_unsigned_short
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    Entries beyond the first NUM_REGS are ignored.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{"r0", "r1", "r2", "r3", "r4", "r5", "r6", "sp","ccr","pc"}
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|6
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|7
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|CCR_REGNUM
value|8
end_define

begin_comment
comment|/* Contains processor status */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|9
end_define

begin_comment
comment|/* Contains program counter */
end_comment

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function. */
end_comment

begin_comment
comment|/*#define STORE_STRUCT_RETURN(ADDR, SP) \   { write_register (0, (ADDR)); abort(); }*/
end_comment

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
value|bcopy ((char *)(REGBUF), VALBUF, TYPE_LENGTH(TYPE))
end_define

begin_comment
comment|/* Write into appropriate registers a function return value    of type TYPE, given in virtual format.  Assumes floats are passed    in d0/d1.  */
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
value|(*(CORE_ADDR *)(REGBUF))
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
comment|/* In the case of the H8/300, the frame's nominal address    is the address of a 2-byte word containing the calling frame's address.  */
end_comment

begin_comment
comment|/* Use the alternate method of avoiding running up off the end of    the frame chain or following frames back into the startup code.    See the comments in objfile.h */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID_ALTERNATE
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

begin_comment
comment|/* Any function with a frame looks like this    SECOND ARG    FIRST ARG    RET PC    SAVED R2    SAVED R3    SAVED FP<-FP POINTS HERE    LOCALS0    LOCALS1<-SP POINTS HERE        */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|FRAME
parameter_list|)
value|frame_saved_pc(FRAME)
end_define

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|frame_args_address(fi)
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|frame_locals_address(fi);
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
value|frame_find_saved_regs(frame_info,&(frame_saved_regs))
end_define

begin_escape
end_escape

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_comment
comment|/*#define PUSH_DUMMY_FRAME	{ h8300_push_dummy_frame (); }*/
end_comment

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
value|{ h8300_pop_frame (); }
end_define

begin_define
define|#
directive|define
name|SHORT_INT_MAX
value|32767
end_define

begin_define
define|#
directive|define
name|SHORT_INT_MIN
value|-32768
end_define

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
value|{ memcpy((TO), (FROM),  2); }
end_define

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
value|{ memcpy((TO), (FROM),  2); }
end_define

begin_define
define|#
directive|define
name|BEFORE_MAIN_LOOP_HOOK
define|\
value|hms_before_main_loop();
end_define

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
end_define

begin_typedef
typedef|typedef
name|unsigned
name|short
name|INSN_WORD
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ADDR_BITS_REMOVE
parameter_list|(
name|addr
parameter_list|)
value|((addr)& 0xffff)
end_define

begin_define
define|#
directive|define
name|ADDR_BITS_SET
parameter_list|(
name|addr
parameter_list|)
value|(((addr)))
end_define

begin_define
define|#
directive|define
name|read_memory_short
parameter_list|(
name|x
parameter_list|)
value|(read_memory_integer(x,2)& 0xffff)
end_define

begin_define
define|#
directive|define
name|DONT_USE_REMOTE
end_define

end_unit

