begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for target machine Intel 960, for GDB, the GNU debugger.    Copyright (C) 1990-1991 Free Software Foundation, Inc.    Contributed by Intel Corporation. This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Definitions to target GDB to any i960.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|I80960
end_ifndef

begin_define
define|#
directive|define
name|I80960
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Hook for the SYMBOL_CLASS of a parameter when decoding DBX symbol    information.  In the i960, parameters can be stored as locals or as    args, depending on the type of the debug record.     From empirical observation, gcc960 uses N_LSYM to indicate    arguments passed in registers and then copied immediately    to the frame, and N_PSYM to indicate arguments passed in a    g14-relative argument block.  */
end_comment

begin_define
define|#
directive|define
name|DBX_PARM_SYMBOL_CLASS
parameter_list|(
name|type
parameter_list|)
value|((type == N_LSYM)? LOC_LOCAL_ARG: LOC_ARG)
end_define

begin_comment
comment|/* Byte order is configurable, but this machine runs little-endian.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_comment
comment|/* We have IEEE floating point, if we have any float at all.  */
end_comment

begin_define
define|#
directive|define
name|IEEE_FLOAT
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
comment|/* Advance ip across any function entry prologue instructions    to reach some "real" code.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|ip
parameter_list|)
value|{ ip = skip_prologue (ip); }
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|skip_prologue
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Immediately after a function call, return the saved ip.    Can't always go through the frames for this because on some machines    the new frame is not set up until the new function    executes some instructions.  */
end_comment

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
value|(saved_pc_after_call (frame))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|saved_pc_after_call
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Stack grows upward */
end_comment

begin_define
define|#
directive|define
name|INNER_THAN
value|>
end_define

begin_comment
comment|/* Nonzero if instruction at ip is a return instruction.  */
end_comment

begin_define
define|#
directive|define
name|ABOUT_TO_RETURN
parameter_list|(
name|ip
parameter_list|)
value|(read_memory_integer(ip,4) == 0x0a000000)
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
value|(0)
end_define

begin_comment
comment|/* How long (ordinary) registers are */
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
value|40
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{ \
comment|/*  0 */
value|"pfp", "sp",  "rip", "r3",  "r4",  "r5",  "r6",  "r7", \
comment|/*  8 */
value|"r8",  "r9",  "r10", "r11", "r12", "r13", "r14", "r15",\
comment|/* 16 */
value|"g0",  "g1",  "g2",  "g3",  "g4",  "g5",  "g6",  "g7", \
comment|/* 24 */
value|"g8",  "g9",  "g10", "g11", "g12", "g13", "g14", "fp", \
comment|/* 32 */
value|"pcw", "ac",  "tc",  "ip",  "fp0", "fp1", "fp2", "fp3",\ }
end_define

begin_comment
comment|/* Register numbers of various important registers (used to index    into arrays of register names and register values).  */
end_comment

begin_define
define|#
directive|define
name|R0_REGNUM
value|0
end_define

begin_comment
comment|/* First local register		*/
end_comment

begin_define
define|#
directive|define
name|SP_REGNUM
value|1
end_define

begin_comment
comment|/* Contains address of top of stack */
end_comment

begin_define
define|#
directive|define
name|RIP_REGNUM
value|2
end_define

begin_comment
comment|/* Return instruction pointer (local r2) */
end_comment

begin_define
define|#
directive|define
name|R15_REGNUM
value|15
end_define

begin_comment
comment|/* Last local register		*/
end_comment

begin_define
define|#
directive|define
name|G0_REGNUM
value|16
end_define

begin_comment
comment|/* First global register	*/
end_comment

begin_define
define|#
directive|define
name|G13_REGNUM
value|29
end_define

begin_comment
comment|/* g13 - holds struct return address */
end_comment

begin_define
define|#
directive|define
name|G14_REGNUM
value|30
end_define

begin_comment
comment|/* g14 - ptr to arg block / leafproc return address */
end_comment

begin_define
define|#
directive|define
name|FP_REGNUM
value|31
end_define

begin_comment
comment|/* Contains address of executing stack frame */
end_comment

begin_define
define|#
directive|define
name|PCW_REGNUM
value|32
end_define

begin_comment
comment|/* process control word */
end_comment

begin_define
define|#
directive|define
name|ACW_REGNUM
value|33
end_define

begin_comment
comment|/* arithmetic control word */
end_comment

begin_define
define|#
directive|define
name|TCW_REGNUM
value|34
end_define

begin_comment
comment|/* trace control word */
end_comment

begin_define
define|#
directive|define
name|IP_REGNUM
value|35
end_define

begin_comment
comment|/* instruction pointer */
end_comment

begin_define
define|#
directive|define
name|FP0_REGNUM
value|36
end_define

begin_comment
comment|/* First floating point register */
end_comment

begin_comment
comment|/* Some registers have more than one name */
end_comment

begin_define
define|#
directive|define
name|PC_REGNUM
value|IP_REGNUM
end_define

begin_comment
comment|/* GDB refers to ip as the Program Counter */
end_comment

begin_define
define|#
directive|define
name|PFP_REGNUM
value|R0_REGNUM
end_define

begin_comment
comment|/* Previous frame pointer	*/
end_comment

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|((36*4) + (4*10))
end_define

begin_comment
comment|/* Index within `registers' of the first byte of the space for register N.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|N
parameter_list|)
value|( (N)< FP0_REGNUM ? \ 				(4*(N)) : ((10*(N)) - (6*FP0_REGNUM)) )
end_define

begin_comment
comment|/* The i960 has register windows, sort of.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGISTER_WINDOWS
end_define

begin_comment
comment|/* Is this register part of the register window system?  A yes answer    implies that 1) The name of this register will not be the same in    other frames, and 2) This register is automatically "saved" upon    subroutine calls and thus there is no need to search more than one    stack frame for it.        On the i960, in fact, the name of this register in another frame is    "mud" -- there is no overlap between the windows.  Each window is    simply saved into the stack (true for our purposes, after having been    flushed; normally they reside on-chip and are restored from on-chip    without ever going to memory).  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_IN_WINDOW_P
parameter_list|(
name|regnum
parameter_list|)
value|((regnum)<= R15_REGNUM)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  On the i960, all regs are 4 bytes except for floating    point, which are 10.  NINDY only sends us 8 byte values for these,    which is a pain, but VxWorks handles this correctly, so we must.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|( (N)< FP0_REGNUM ? 4 : 10 )
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation for register N. */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|( (N)< FP0_REGNUM ? 4 : 8 )
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
value|8
end_define

begin_comment
comment|/* Nonzero if register N requires conversion from raw format to virtual    format.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|N
parameter_list|)
value|((N)>= FP0_REGNUM)
end_define

begin_comment
comment|/* Convert data from raw format for register REGNUM    to virtual format for register REGNUM.  */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|ext_format
name|ext_format_i960
decl_stmt|;
end_decl_stmt

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
value|{ \   if ((REGNUM)>= FP0_REGNUM)   \     ieee_extended_to_double (&ext_format_i960, (FROM), (double *)(TO));     \   else                                  \     bcopy ((FROM), (TO), 4);	\ }
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
value|{ \   if ((REGNUM)>= FP0_REGNUM)   \     double_to_ieee_extended (&ext_format_i960, (double *)(FROM), (TO));     \   else                                  \     bcopy ((FROM), (TO), 4); 	\ }
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
value|((N)< FP0_REGNUM ? \ 					builtin_type_int : builtin_type_double)
end_define

begin_escape
end_escape

begin_comment
comment|/* Macros for understanding function return values... */
end_comment

begin_comment
comment|/* Does the specified function use the "struct returning" convention    or the "value returning" convention?  The "value returning" convention    almost invariably returns the entire value in registers.  The    "struct returning" convention often returns the entire value in    memory, and passes a pointer (out of or into the function) saying    where the value (is or should go).     Since this sometimes depends on whether it was compiled with GCC,    this is also an argument.  This is used in call_function to build a    stack, and in value_being_returned to print return values.     On i960, a structure is returned in registers g0-g3, if it will fit.    If it's more than 16 bytes long, g13 pointed to it on entry.  */
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
value|(TYPE_LENGTH (type)> 16)
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  This is only called if USE_STRUCT_CONVENTION for this    type is 0.     On the i960 we just take as many bytes as we need from G0 through G3.  */
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
value|bcopy(REGBUF+REGISTER_BYTE(G0_REGNUM), VALBUF, TYPE_LENGTH (TYPE))
end_define

begin_comment
comment|/* If USE_STRUCT_CONVENTION produces a 1,     extract from an array REGBUF containing the (raw) register state    the address in which a function should return its structure value,    as a CORE_ADDR (or an expression that can be used as one).     Address of where to put structure was passed in in global    register g13 on entry.  God knows what's in g13 now.  The    (..., 0) below is to make it appear to return a value, though    actually all it does is call error().  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS
parameter_list|(
name|REGBUF
parameter_list|)
define|\
value|(error("Don't know where large structure is returned on i960"), 0)
end_define

begin_comment
comment|/* Write into appropriate registers a function return value    of type TYPE, given in virtual format, for "value returning" functions.       For 'return' command:  not (yet) implemented for i960.  */
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
value|error ("Returning values from functions is not implemented in i960 gdb")
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
value|error ("Returning values from functions is not implemented in i960 gdb")
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
comment|/* We cache information about saved registers in the frame structure,    to save us from having to re-scan function prologues every time    a register in a non-current frame is accessed.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_FRAME_INFO
define|\
value|struct frame_saved_regs *fsr;	\ 	CORE_ADDR arg_pointer;
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
value|((fi)->fsr = 0, (fi)->arg_pointer = -1)
end_define

begin_comment
comment|/* On the i960, we get the chain pointer by reading the PFP saved    on the stack and clearing the status bits.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
define|\
value|(read_memory_integer (FRAME_FP(thisframe), 4)& ~0xf)
end_define

begin_comment
comment|/* FRAME_CHAIN_VALID returns zero if the given frame is the outermost one    and has no caller.     On the i960, each various target system type must define FRAME_CHAIN_VALID,    since it differs between NINDY and VxWorks, the two currently supported    targets types.  We leave it undefined here.  */
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
value|{ (FRAMELESS) = (leafproc_return ((FI)->pc) != 0); }
end_define

begin_comment
comment|/* Note that in the i960 architecture the return pointer is saved in the    *caller's* stack frame.       Make sure to zero low-order bits because of bug in 960CA A-step part    (instruction addresses should always be word-aligned anyway).  */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|frame
parameter_list|)
define|\
value|((read_memory_integer(FRAME_CHAIN(frame)+8,4))& ~3)
end_define

begin_comment
comment|/* On the i960, FRAME_ARGS_ADDRESS should return the value of    g14 as passed into the frame, if known.  We need a function for this.    We cache this value in the frame info if we've already looked it up.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
define|\
value|(((fi)->arg_pointer != -1)? (fi)->arg_pointer: frame_args_address (fi, 0))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|frame_args_address
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* i960-tdep.c */
end_comment

begin_comment
comment|/* This is the same except it should return 0 when    it does not really know where the args are, rather than guessing.    This value is not cached since it is only used infrequently.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_ARGS_ADDRESS_CORRECT
parameter_list|(
name|fi
parameter_list|)
value|(frame_args_address (fi, 1))
end_define

begin_define
define|#
directive|define
name|FRAME_LOCALS_ADDRESS
parameter_list|(
name|fi
parameter_list|)
value|(fi)->frame
end_define

begin_comment
comment|/* Set NUMARGS to the number of args passed to a frame.    Can return -1, meaning no way to tell.  */
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
comment|/* Produce the positions of the saved registers in a stack frame.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_FIND_SAVED_REGS
parameter_list|(
name|frame_info_addr
parameter_list|,
name|sr
parameter_list|)
define|\
value|frame_find_saved_regs (frame_info_addr,&sr)
end_define

begin_function_decl
specifier|extern
name|void
name|frame_find_saved_regs
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* See i960-tdep.c */
end_comment

begin_comment
comment|/* Print status when we get a random unexpected signal.  We have more    kinds of signals than Unix does... */
end_comment

begin_define
define|#
directive|define
name|PRINT_RANDOM_SIGNAL
parameter_list|(
name|stop_signal
parameter_list|)
value|print_fault (stop_signal)
end_define

begin_escape
end_escape

begin_comment
comment|/* Things needed for making calls to functions in the inferior process */
end_comment

begin_comment
comment|/* Push an empty stack frame, to record the current ip, etc.       Not (yet?) implemented for i960.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
define|\
value|error("Function calls into the inferior process are not supported on the i960")
end_define

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
define|\
value|pop_frame ()
end_define

begin_comment
comment|/* This sequence of words is the instructions      	callx 0x00000000   	fmark  */
end_comment

begin_comment
comment|/* #define CALL_DUMMY { 0x86003000, 0x00000000, 0x66003e00 } */
end_comment

begin_comment
comment|/* #define CALL_DUMMY_START_OFFSET 0 */
end_comment

begin_comment
comment|/* Start execution at beginning of dummy */
end_comment

begin_comment
comment|/* Indicate that we don't support calling inferior child functions.  */
end_comment

begin_undef
undef|#
directive|undef
name|CALL_DUMMY
end_undef

begin_comment
comment|/* Insert the specified number of args and function address    into a call sequence of the above form stored at 'dummyname'.       Ignore arg count on i960.  */
end_comment

begin_comment
comment|/* #define FIX_CALL_DUMMY(dummyname, fun, nargs) *(((int *)dummyname)+1) = fun */
end_comment

begin_undef
undef|#
directive|undef
name|FIX_CALL_DUMMY
end_undef

begin_comment
comment|/* Interface definitions for kernel debugger KDB */
end_comment

begin_comment
comment|/* (Not relevant to i960.) */
end_comment

end_unit

