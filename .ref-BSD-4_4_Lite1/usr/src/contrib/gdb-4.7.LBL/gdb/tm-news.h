begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on a Sony/NEWS, for GDB, the GNU debugger.    Copyright (C) 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* See following cpu type determination macro to get the machine type.    Here is an m-news.h file for gdb.  It supports the 68881 registers.                                            by hikichi@srava.sra.junet    * Support Sun assembly format instead of Motorola one. * Ptrace for handling floating register has a bug(before NEWS OS version 2.2), * After NEWS OS version 3.2, some of ptrace's bug is fixed.   But we cannot change the floating register(see adb(1) in OS 3.2) yet.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_68881
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
comment|/* Use to compute STACK_END_ADDR.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_UPAGES
value|2
end_define

begin_define
define|#
directive|define
name|TARGET_NBPG
value|4096
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0x80000000 - TARGET_UPAGES * TARGET_NBPG)
end_define

begin_comment
comment|/* Extract from an array REGBUF containing the (raw) register state    a function return value of type TYPE, and copy that, in virtual format,    into VALBUF.  */
end_comment

begin_comment
comment|/* when it return the floating value, use the FP0 in NEWS.  */
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
value|{ if (TYPE_CODE (TYPE) == TYPE_CODE_FLT) \       { \ 	REGISTER_CONVERT_TO_VIRTUAL (FP0_REGNUM, \&REGBUF[REGISTER_BYTE (FP0_REGNUM)], VALBUF); \       } \     else \       bcopy (REGBUF, VALBUF, TYPE_LENGTH (TYPE)); }
end_define

begin_comment
comment|/* Write into appropriate registers a function return value    of type TYPE, given in virtual format.  */
end_comment

begin_comment
comment|/* when it return the floating value, use the FP0 in NEWS.  */
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
value|{ if (TYPE_CODE (TYPE) == TYPE_CODE_FLT) \       { \ 	char raw_buf[REGISTER_RAW_SIZE (FP0_REGNUM)]; \ 	REGISTER_CONVERT_TO_RAW (FP0_REGNUM, VALBUF, raw_buf); \ 	write_register_bytes (FP0_REGNUM, \ 			      raw_buf, REGISTER_RAW_SIZE (FP0_REGNUM)); \       } \     else \       write_register_bytes (0, VALBUF, TYPE_LENGTH (TYPE)); }
end_define

begin_comment
comment|/* Return number of args passed to a frame.    Can return -1, meaning no way to tell.  */
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
define|\
value|{ register CORE_ADDR pc = FRAME_SAVED_PC (fi);			\   register int insn = 0177777& read_memory_integer (pc, 2);	\   val = 0;							\   if (insn == 0047757 || insn == 0157374)
comment|/* lea W(sp),sp or addaw #W,sp */
value|\     val = read_memory_integer (pc + 2, 2);			\   else if ((insn& 0170777) == 0050217
comment|/* addql #N, sp */
value|\ 	   || (insn& 0170777) == 0050117)
comment|/* addqw */
value|\     { val = (insn>> 9)& 7; if (val == 0) val = 8; }		\   else if (insn == 0157774)
comment|/* addal #WW, sp */
value|\     val = read_memory_integer (pc + 2, 4);			\   val>>= 2; }
end_define

begin_include
include|#
directive|include
file|"tm-68k.h"
end_include

end_unit

