begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for i386, Unix System V.    Copyright 1986, 1987, 1989, 1991, 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386V_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386V_H
value|1
end_define

begin_comment
comment|/* First pick up the generic *86 target file. */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_comment
comment|/* Number of traps that happen between exec'ing the shell to run an    inferior, and when we finally get to the inferior code.  This is    2 on most implementations.  Override here to 4. */
end_comment

begin_undef
undef|#
directive|undef
name|START_INFERIOR_TRAPS_EXPECTED
end_undef

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|4
end_define

begin_comment
comment|/* Number of machine registers */
end_comment

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_define
define|#
directive|define
name|NUM_REGS
value|16
end_define

begin_comment
comment|/* Initializer for an array of names of registers.    There should be NUM_REGS strings in this initializer.  */
end_comment

begin_comment
comment|/* the order of the first 8 registers must match the compiler's   * numbering scheme (which is the same as the 386 scheme)  * also, this table must match regmap in i386-pinsn.c.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_NAMES
end_undef

begin_define
define|#
directive|define
name|REGISTER_NAMES
value|{ "eax", "ecx", "edx", "ebx", \ 			 "esp", "ebp", "esi", "edi", \ 			 "eip", "ps", "cs", "ss", \ 			 "ds", "es", "fs", "gs", \ 			 }
end_define

begin_comment
comment|/* Total amount of space needed to store our copies of the machine's    register state, the array `registers'.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_BYTES
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTES
value|(NUM_REGS * 4)
end_define

begin_comment
comment|/* Index within `registers' of the first byte of the space for    register N.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_BYTE
end_undef

begin_define
define|#
directive|define
name|REGISTER_BYTE
parameter_list|(
name|N
parameter_list|)
value|((N)*4)
end_define

begin_comment
comment|/* Number of bytes of storage in the actual machine representation    for register N.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_RAW_SIZE
end_undef

begin_define
define|#
directive|define
name|REGISTER_RAW_SIZE
parameter_list|(
name|N
parameter_list|)
value|(4)
end_define

begin_comment
comment|/* Number of bytes of storage in the program's representation    for register N. */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_VIRTUAL_SIZE
end_undef

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_SIZE
parameter_list|(
name|N
parameter_list|)
value|(4)
end_define

begin_comment
comment|/* Largest value REGISTER_RAW_SIZE can have.  */
end_comment

begin_undef
undef|#
directive|undef
name|MAX_REGISTER_RAW_SIZE
end_undef

begin_define
define|#
directive|define
name|MAX_REGISTER_RAW_SIZE
value|4
end_define

begin_comment
comment|/* Largest value REGISTER_VIRTUAL_SIZE can have.  */
end_comment

begin_undef
undef|#
directive|undef
name|MAX_REGISTER_VIRTUAL_SIZE
end_undef

begin_define
define|#
directive|define
name|MAX_REGISTER_VIRTUAL_SIZE
value|4
end_define

begin_comment
comment|/* Return the GDB type object for the "standard" data type    of data in register N.  */
end_comment

begin_comment
comment|/* Perhaps si and di should go here, but potentially they could be    used for things other than address.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_VIRTUAL_TYPE
end_undef

begin_define
define|#
directive|define
name|REGISTER_VIRTUAL_TYPE
parameter_list|(
name|N
parameter_list|)
define|\
value|((N) == PC_REGNUM || (N) == FP_REGNUM || (N) == SP_REGNUM ?         \    lookup_pointer_type (builtin_type_void) : builtin_type_int)
end_define

begin_comment
comment|/* Store the address of the place in which to copy the structure the    subroutine will return.  This is called from call_function. */
end_comment

begin_undef
undef|#
directive|undef
name|STORE_STRUCT_RETURN
end_undef

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

begin_undef
undef|#
directive|undef
name|EXTRACT_RETURN_VALUE
end_undef

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
value|memcpy ((VALBUF), (REGBUF), TYPE_LENGTH (TYPE))
end_define

begin_comment
comment|/* Write into appropriate registers a function return value    of type TYPE, given in virtual format.  */
end_comment

begin_undef
undef|#
directive|undef
name|STORE_RETURN_VALUE
end_undef

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

begin_escape
end_escape

begin_comment
comment|/* Describe the pointer in each stack frame to the previous stack frame    (its caller).  */
end_comment

begin_comment
comment|/* FRAME_CHAIN takes a frame's nominal address    and produces the frame's chain-pointer. */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_CHAIN
end_undef

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

begin_comment
comment|/* A macro that tells us whether the function invocation represented    by FI does not have a frame on the stack associated with it.  If it    does not, FRAMELESS is set to 1, else 0.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAMELESS_FUNCTION_INVOCATION
end_undef

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

begin_undef
undef|#
directive|undef
name|FRAME_SAVED_PC
end_undef

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
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_NUM_ARGS
end_undef

begin_define
define|#
directive|define
name|FRAME_NUM_ARGS
parameter_list|(
name|numargs
parameter_list|,
name|fi
parameter_list|)
value|(numargs) = -1
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

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef TM_I386V_H */
end_comment

end_unit

