begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on an Altos 3068 (m68k running SVR2)    Copyright (C) 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Define BPT_VECTOR if it is different than the default.    This is the vector number used by traps to indicate a breakpoint. */
end_comment

begin_define
define|#
directive|define
name|BPT_VECTOR
value|0xe
end_define

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_undef
undef|#
directive|undef
name|NAMES_HAVE_UNDERSCORE
end_undef

begin_comment
comment|/* COFF files don't have long filenames.  */
end_comment

begin_define
define|#
directive|define
name|COFF_NO_LONG_FILE_NAMES
end_define

begin_comment
comment|/* Address of end of stack space.  */
end_comment

begin_comment
comment|/*#define STACK_END_ADDR (0xffffff)*/
end_comment

begin_define
define|#
directive|define
name|STACK_END_ADDR
value|(0x1000000)
end_define

begin_comment
comment|/* Amount PC must be decremented by after a breakpoint.    On the Altos, the kernel resets the pc to the trap instr */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_comment
comment|/* The only reason this is here is the tm-altos.h reference below.  It    was moved back here from tm-68k.h.  FIXME? */
end_comment

begin_define
define|#
directive|define
name|SKIP_PROLOGUE
parameter_list|(
name|pc
parameter_list|)
define|\
value|{ register int op = read_memory_integer (pc, 2);	\   if (op == 0047126)					\     pc += 4;
comment|/* Skip link #word */
value|\   else if (op == 0044016)				\     pc += 6;
comment|/* Skip link #long */
value|\
comment|/* Not sure why branches are here.  */
value|\
comment|/* From tm-isi.h, tm-altos.h */
value|\   else if (op == 0060000)				\     pc += 4;
comment|/* Skip bra #word */
value|\   else if (op == 00600377)				\     pc += 6;
comment|/* skip bra #long */
value|\   else if ((op& 0177400) == 0060000)			\     pc += 2;
comment|/* skip bra #char */
value|\ }
end_define

begin_include
include|#
directive|include
file|"tm-68k.h"
end_include

end_unit

