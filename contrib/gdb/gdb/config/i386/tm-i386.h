begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on an Intel i[345]86.    Copyright 1995, 1996, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_define
define|#
directive|define
name|GDB_MULTI_ARCH
value|GDB_MULTI_ARCH_PARTIAL
end_define

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_comment
comment|/* Forward declarations for prototypes.  */
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
name|value
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|type
struct_decl|;
end_struct_decl

begin_comment
comment|/* The format used for `long double' on almost all i386 targets is the    i387 extended floating-point format.  In fact, of all targets in the    GCC 2.95 tree, only OSF/1 does it different, and insists on having    a `long double' that's not `long' at all.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_LONG_DOUBLE_FORMAT
value|&floatformat_i387_ext
end_define

begin_comment
comment|/* Although the i386 extended floating-point has only 80 significant    bits, a `long double' actually takes up 96, probably to enforce    alignment.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_LONG_DOUBLE_BIT
value|96
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
value|(i386_skip_prologue (frompc))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_skip_prologue
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Immediately after a function call, return the saved pc.  */
end_comment

begin_define
define|#
directive|define
name|SAVED_PC_AFTER_CALL
parameter_list|(
name|frame
parameter_list|)
value|i386_saved_pc_after_call (frame)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_saved_pc_after_call
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

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
comment|/* This register file is parameterized by two macros:    HAVE_I387_REGS --- register file should include i387 registers    HAVE_SSE_REGS  --- register file should include SSE registers    If HAVE_SSE_REGS is #defined, then HAVE_I387_REGS must also be #defined.        However, GDB code should not test those macros with #ifdef, since    that makes code which is annoying to multi-arch.  Instead, GDB code    should check the values of NUM_GREGS, NUM_FREGS, and NUM_SSE_REGS,    which will eventually get mapped onto architecture vector entries.     It's okay to use the macros in tm-*.h files, though, since those    files will get completely replaced when we multi-arch anyway.  */
end_comment

begin_comment
comment|/* Number of general registers, present on every 32-bit x86 variant.  */
end_comment

begin_define
define|#
directive|define
name|NUM_GREGS
value|(16)
end_define

begin_comment
comment|/* Number of floating-point unit registers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_I387_REGS
end_ifdef

begin_define
define|#
directive|define
name|NUM_FREGS
value|(16)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NUM_FREGS
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of SSE registers.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SSE_REGS
end_ifdef

begin_define
define|#
directive|define
name|NUM_SSE_REGS
value|(9)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NUM_SSE_REGS
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Largest number of registers we could have in any configuration.  */
end_comment

begin_define
define|#
directive|define
name|MAX_NUM_REGS
value|(16 + 16 + 9)
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
comment|/* (ebp) Contains address of executing stack 				   frame */
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

begin_comment
comment|/* First FPU data register.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_I387_REGS
end_ifdef

begin_define
define|#
directive|define
name|FP0_REGNUM
value|16
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FP0_REGNUM
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return the name of register REG.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAME
parameter_list|(
name|reg
parameter_list|)
value|i386_register_name ((reg))
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|i386_register_name
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use the "default" register numbering scheme for stabs and COFF.  */
end_comment

begin_define
define|#
directive|define
name|STAB_REG_TO_REGNUM
parameter_list|(
name|reg
parameter_list|)
value|i386_stab_reg_to_regnum ((reg))
end_define

begin_define
define|#
directive|define
name|SDB_REG_TO_REGNUM
parameter_list|(
name|reg
parameter_list|)
value|i386_stab_reg_to_regnum ((reg))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_stab_reg_to_regnum
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use the DWARF register numbering scheme for DWARF and DWARF 2.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_REG_TO_REGNUM
parameter_list|(
name|reg
parameter_list|)
value|i386_dwarf_reg_to_regnum ((reg))
end_define

begin_define
define|#
directive|define
name|DWARF2_REG_TO_REGNUM
parameter_list|(
name|reg
parameter_list|)
value|i386_dwarf_reg_to_regnum ((reg))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_dwarf_reg_to_regnum
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* We don't define ECOFF_REG_TO_REGNUM, since ECOFF doesn't seem to be    in use on any of the supported i386 targets.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Sizes of individual register sets.  These cover the entire register    file, so summing up the sizes of those portions actually present    yields REGISTER_BYTES.  */
end_comment

begin_define
define|#
directive|define
name|SIZEOF_GREGS
value|(NUM_GREGS * 4)
end_define

begin_define
define|#
directive|define
name|SIZEOF_FPU_REGS
value|(8 * 10)
end_define

begin_define
define|#
directive|define
name|SIZEOF_FPU_CTRL_REGS
value|(8 * 4)
end_define

begin_define
define|#
directive|define
name|SIZEOF_SSE_REGS
value|(8 * 16 + 4)
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's register    state, the array `registers'. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SSE_REGS
end_ifdef

begin_define
define|#
directive|define
name|REGISTER_BYTES
define|\
value|(SIZEOF_GREGS + SIZEOF_FPU_REGS + SIZEOF_FPU_CTRL_REGS + SIZEOF_SSE_REGS)
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_I387_REGS
end_ifdef

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(SIZEOF_GREGS + SIZEOF_FPU_REGS + SIZEOF_FPU_CTRL_REGS)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(SIZEOF_GREGS)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Return the offset into the register array of the start of register    number REG.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|reg
parameter_list|)
value|i386_register_byte ((reg))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_register_byte
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the number of bytes of storage in GDB's register array    occupied by register REG.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|reg
parameter_list|)
value|i386_register_raw_size ((reg))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_register_raw_size
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|16
end_define

begin_comment
comment|/* Return the size in bytes of the virtual type of register REG.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|reg
parameter_list|)
value|i386_register_virtual_size ((reg))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_register_virtual_size
parameter_list|(
name|int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|16
end_define

begin_comment
comment|/* Return the GDB type object for the "standard" data type of data in    register REGNUM.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_TYPE
parameter_list|(
name|regnum
parameter_list|)
value|i386_register_virtual_type (regnum)
end_define

begin_function_decl
specifier|extern
name|struct
name|type
modifier|*
name|i386_register_virtual_type
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return true iff register REGNUM's virtual format is different from    its raw format.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|regnum
parameter_list|)
value|i386_register_convertible (regnum)
end_define

begin_function_decl
specifier|extern
name|int
name|i386_register_convertible
parameter_list|(
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert data from raw format for register REGNUM in buffer FROM to    virtual format with type TYPE in buffer TO.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|regnum
parameter_list|,
name|type
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|i386_register_convert_to_virtual ((regnum), (type), (from), (to))
end_define

begin_function_decl
specifier|extern
name|void
name|i386_register_convert_to_virtual
parameter_list|(
name|int
name|regnum
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Convert data from virtual format with type TYPE in buffer FROM to    raw format for register REGNUM in buffer TO.  */
end_comment

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_RAW
parameter_list|(
name|type
parameter_list|,
name|regnum
parameter_list|,
name|from
parameter_list|,
name|to
parameter_list|)
define|\
value|i386_register_convert_to_raw ((type), (regnum), (from), (to))
end_define

begin_function_decl
specifier|extern
name|void
name|i386_register_convert_to_raw
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|regnum
parameter_list|,
name|char
modifier|*
name|from
parameter_list|,
name|char
modifier|*
name|to
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Print out the i387 floating point state.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_I387_REGS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|i387_float_info
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FLOAT_INFO
value|{ i387_float_info (); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_define
define|#
directive|define
name|PUSH_ARGUMENTS
parameter_list|(
name|nargs
parameter_list|,
name|args
parameter_list|,
name|sp
parameter_list|,
name|struct_return
parameter_list|,
name|struct_addr
parameter_list|)
define|\
value|i386_push_arguments ((nargs), (args), (sp), (struct_return), (struct_addr))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_push_arguments
parameter_list|(
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|,
name|int
name|struct_return
parameter_list|,
name|CORE_ADDR
name|struct_addr
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function.  */
end_comment

begin_define
define|#
directive|define
name|STORE_STRUCT_RETURN
parameter_list|(
name|addr
parameter_list|,
name|sp
parameter_list|)
define|\
value|i386_store_struct_return ((addr), (sp))
end_define

begin_function_decl
specifier|extern
name|void
name|i386_store_struct_return
parameter_list|(
name|CORE_ADDR
name|addr
parameter_list|,
name|CORE_ADDR
name|sp
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_RETURN_VALUE
parameter_list|(
name|type
parameter_list|,
name|regbuf
parameter_list|,
name|valbuf
parameter_list|)
define|\
value|i386_extract_return_value ((type), (regbuf), (valbuf))
end_define

begin_function_decl
specifier|extern
name|void
name|i386_extract_return_value
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|regbuf
parameter_list|,
name|char
modifier|*
name|valbuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Write into the appropriate registers a function return value stored    in VALBUF of type TYPE, given in virtual format.  */
end_comment

begin_define
define|#
directive|define
name|STORE_RETURN_VALUE
parameter_list|(
name|type
parameter_list|,
name|valbuf
parameter_list|)
define|\
value|i386_store_return_value ((type), (valbuf))
end_define

begin_function_decl
specifier|extern
name|void
name|i386_store_return_value
parameter_list|(
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|char
modifier|*
name|valbuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    the address in which a function should return its structure value,    as a CORE_ADDR.  */
end_comment

begin_define
define|#
directive|define
name|EXTRACT_STRUCT_VALUE_ADDRESS
parameter_list|(
name|regbuf
parameter_list|)
define|\
value|i386_extract_struct_value_address ((regbuf))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_extract_struct_value_address
parameter_list|(
name|char
modifier|*
name|regbuf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The following redefines make backtracing through sigtramp work.    They manufacture a fake sigtramp frame and obtain the saved pc in sigtramp    from the sigcontext structure which is pushed by the kernel on the    user stack, along with a pointer to it.  */
end_comment

begin_comment
comment|/* Return the chain-pointer for FRAME.  In the case of the i386, the    frame's nominal address is the address of a 4-byte word containing    the calling frame's address.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|frame
parameter_list|)
value|i386_frame_chain ((frame))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_frame_chain
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Determine whether the function invocation represented by FRAME does    not have a from on the stack associated with it.  If it does not,    return non-zero, otherwise return zero.  */
end_comment

begin_define
define|#
directive|define
name|FRAMELESS_FUNCTION_INVOCATION
parameter_list|(
name|frame
parameter_list|)
define|\
value|i386_frameless_function_invocation (frame)
end_define

begin_function_decl
specifier|extern
name|int
name|i386_frameless_function_invocation
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Return the saved program counter for FRAME.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_SAVED_PC
parameter_list|(
name|frame
parameter_list|)
value|i386_frame_saved_pc (frame)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|i386_frame_saved_pc
parameter_list|(
name|struct
name|frame_info
modifier|*
name|frame
parameter_list|)
function_decl|;
end_function_decl

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
name|fi
parameter_list|)
value|(i386_frame_num_args(fi))
end_define

begin_function_decl
specifier|extern
name|int
name|i386_frame_num_args
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|void
name|i386_frame_init_saved_regs
parameter_list|(
name|struct
name|frame_info
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FRAME_INIT_SAVED_REGS
parameter_list|(
name|FI
parameter_list|)
value|i386_frame_init_saved_regs (FI)
end_define

begin_escape
end_escape

begin_comment
comment|/* Things needed for making the inferior call functions.  */
end_comment

begin_comment
comment|/* "An argument's size is increased, if necessary, to make it a    multiple of [32 bit] words.  This may require tail padding,    depending on the size of the argument" - from the x86 ABI.  */
end_comment

begin_define
define|#
directive|define
name|PARM_BOUNDARY
value|32
end_define

begin_comment
comment|/* Push an empty stack frame, to record the current PC, etc.  */
end_comment

begin_define
define|#
directive|define
name|PUSH_DUMMY_FRAME
value|{ i386_push_dummy_frame (); }
end_define

begin_function_decl
specifier|extern
name|void
name|i386_push_dummy_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Discard from the stack the innermost frame, restoring all registers.  */
end_comment

begin_define
define|#
directive|define
name|POP_FRAME
value|{ i386_pop_frame (); }
end_define

begin_function_decl
specifier|extern
name|void
name|i386_pop_frame
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

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
value|i386_fix_call_dummy (dummyname, pc, fun, nargs, args, type, gcc_p)
end_define

begin_function_decl
specifier|extern
name|void
name|i386_fix_call_dummy
parameter_list|(
name|char
modifier|*
name|dummy
parameter_list|,
name|CORE_ADDR
name|pc
parameter_list|,
name|CORE_ADDR
name|fun
parameter_list|,
name|int
name|nargs
parameter_list|,
name|struct
name|value
modifier|*
modifier|*
name|args
parameter_list|,
name|struct
name|type
modifier|*
name|type
parameter_list|,
name|int
name|gcc_p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* FIXME: kettenis/2000-06-12: These do not belong here.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|print_387_control_word
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|print_387_status_word
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

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

