begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for a Sun 386i target machine, for GDB, the GNU debugger.    Copyright 1986, 1987, 1991, 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TM_SUN386_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|TM_SUN386_H
value|1
end_define

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|sun386
end_ifndef

begin_define
define|#
directive|define
name|sun386
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GDB_TARGET_IS_SUN386
value|1
end_define

begin_define
define|#
directive|define
name|SUNOS4
end_define

begin_define
define|#
directive|define
name|USE_MACHINE_REG_H
end_define

begin_comment
comment|/* Perhaps some day this will work even without the following #define */
end_comment

begin_define
define|#
directive|define
name|COFF_ENCAPSULATE
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|COFF_ENCAPSULATE
end_ifdef

begin_comment
comment|/* Avoid conflicts between our include files and<sys/exec.h>    (maybe not needed anymore).  */
end_comment

begin_define
define|#
directive|define
name|_EXEC_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun386 ptrace seems unable to change the frame pointer */
end_comment

begin_define
define|#
directive|define
name|PTRACE_FP_BUG
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|0xfc000000
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
value|35
end_define

begin_comment
comment|/* Initializer for an array of names of registers.  There should be NUM_REGS    strings in this initializer.  The order of the first 8 registers must match    the compiler's numbering scheme (which is the same as the 386 scheme) also,    this table must match regmap in i386-pinsn.c. */
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
value|{ "gs", "fs", "es", "ds",		\ 			 "edi", "esi", "ebp", "esp",		\ 			 "ebx", "edx", "ecx", "eax",		\ 			 "retaddr", "trapnum", "errcode", "ip",	\ 			 "cs", "ps", "sp", "ss",		\ 			 "fst0", "fst1", "fst2", "fst3",	\ 			 "fst4", "fst5", "fst6", "fst7",	\ 			 "fctrl", "fstat", "ftag", "fip",	\ 			 "fcs", "fopoff", "fopsel"		\ 			 }
end_define

begin_comment
comment|/* Register numbers of various important registers.    Note that some of these values are "real" register numbers,    and correspond to the general registers of the machine,    and some are "phony" register numbers which are too large    to be actual register numbers as far as the user is concerned    but do serve to get the desired values when passed to read_register.  */
end_comment

begin_undef
undef|#
directive|undef
name|FP_REGNUM
end_undef

begin_define
define|#
directive|define
name|FP_REGNUM
value|6
end_define

begin_comment
comment|/* (ebp) Contains address of executing stack frame */
end_comment

begin_undef
undef|#
directive|undef
name|SP_REGNUM
end_undef

begin_define
define|#
directive|define
name|SP_REGNUM
value|18
end_define

begin_comment
comment|/* (usp) Contains address of top of stack */
end_comment

begin_undef
undef|#
directive|undef
name|PS_REGNUM
end_undef

begin_define
define|#
directive|define
name|PS_REGNUM
value|17
end_define

begin_comment
comment|/* (ps)  Contains processor status */
end_comment

begin_undef
undef|#
directive|undef
name|PC_REGNUM
end_undef

begin_define
define|#
directive|define
name|PC_REGNUM
value|15
end_define

begin_comment
comment|/* (eip) Contains program counter */
end_comment

begin_undef
undef|#
directive|undef
name|FP0_REGNUM
end_undef

begin_define
define|#
directive|define
name|FP0_REGNUM
value|20
end_define

begin_comment
comment|/* Floating point register 0 */
end_comment

begin_undef
undef|#
directive|undef
name|FPC_REGNUM
end_undef

begin_define
define|#
directive|define
name|FPC_REGNUM
value|28
end_define

begin_comment
comment|/* 80387 control register */
end_comment

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
value|(20*4+8*10+7*4)
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
define|\
value|((N)>= FPC_REGNUM ? (((N) - FPC_REGNUM) * 4) + 160	\   : (N)>= FP0_REGNUM ? (((N) - FP0_REGNUM) * 10) + 80	\   : (N) * 4)
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
value|(((unsigned)((N) - FP0_REGNUM))< 8 ? 10 : 4)
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
value|(((unsigned)((N) - FP0_REGNUM))< 8 ? 8 : 4)
end_define

begin_comment
comment|/* Nonzero if register N requires conversion    from raw format to virtual format.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERTIBLE
end_undef

begin_define
define|#
directive|define
name|REGISTER_CONVERTIBLE
parameter_list|(
name|N
parameter_list|)
value|(((unsigned)((N) - FP0_REGNUM))< 8)
end_define

begin_comment
comment|/* Convert data from raw format for register REGNUM in buffer FROM    to virtual format with type TYPE in buffer TO.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERT_TO_VIRTUAL
end_undef

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_VIRTUAL
parameter_list|(
name|REGNUM
parameter_list|,
name|TYPE
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|{ \   double val; \   i387_to_double ((FROM), (char *)&val); \   store_floating ((TO), TYPE_LENGTH (TYPE), val); \ }
end_define

begin_decl_stmt
specifier|extern
name|void
name|i387_to_double
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Convert data from virtual format with type TYPE in buffer FROM    to raw format for register REGNUM in buffer TO.  */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_CONVERT_TO_RAW
end_undef

begin_define
define|#
directive|define
name|REGISTER_CONVERT_TO_RAW
parameter_list|(
name|TYPE
parameter_list|,
name|REGNUM
parameter_list|,
name|FROM
parameter_list|,
name|TO
parameter_list|)
define|\
value|{ \   double val = extract_floating ((FROM), TYPE_LENGTH (TYPE)); \   double_to_i387((char *)&val, (TO)); \ }
end_define

begin_decl_stmt
specifier|extern
name|void
name|double_to_i387
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the GDB type object for the "standard" data type    of data in register N.  */
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
value|(((unsigned)((N) - FP0_REGNUM))< 8 ? builtin_type_double : builtin_type_int)
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
value|memcpy (VALBUF, REGBUF + REGISTER_BYTE (TYPE_CODE (TYPE) == TYPE_CODE_FLT ? FP0_REGNUM : 11), TYPE_LENGTH (TYPE))
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
value|write_register_bytes (REGISTER_BYTE (TYPE_CODE (TYPE) == TYPE_CODE_FLT ? FP0_REGNUM : 11), VALBUF, TYPE_LENGTH (TYPE))
end_define

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
value|{ (FRAMELESS) = frameless_look_for_prologue (FI); }
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
comment|/* Insert the specified number of args and function address    into a call sequence of the above form stored at DUMMYNAME.  */
end_comment

begin_undef
undef|#
directive|undef
name|FIX_CALL_DUMMY
end_undef

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
value|{ \ 	*(int *)((char *)(dummyname) + 1) = (int)(fun) - (pc) - 5; \ }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined (TM_SUN386_H) */
end_comment

end_unit

