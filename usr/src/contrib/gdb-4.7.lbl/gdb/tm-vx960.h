begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for VxWorks Intel 960's, for GDB, the GNU debugger.    Copyright (C) 1986-1991 Free Software Foundation, Inc.    Contributed by Cygnus Support.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-i960.h"
end_include

begin_comment
comment|/* Under VxWorks the IP isn't filled in.  Skip it, go with RIP, which has    the real value.  */
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
value|RIP_REGNUM
end_define

begin_define
define|#
directive|define
name|GDBINIT_FILENAME
value|".vxgdbinit"
end_define

begin_define
define|#
directive|define
name|DEFAULT_PROMPT
value|"(vxgdb) "
end_define

begin_comment
comment|/* We have more complex, useful breakpoints on the target.    Amount ip must be decremented by after a breakpoint.  */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_comment
comment|/* We are guaranteed to have a zero frame pointer at bottom of stack, too. */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID
parameter_list|(
name|chain
parameter_list|,
name|thisframe
parameter_list|)
value|(chain != 0)
end_define

begin_comment
comment|/* Breakpoint patching is handled at the target end in VxWorks.  */
end_comment

begin_comment
comment|/* #define BREAKPOINT {0x00, 0x3e, 0x00, 0x66} */
end_comment

end_unit

