begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on VxWorks 68k's, for GDB, the GNU debugger.    Copyright (C) 1986, 1987, 1989, 1991 Free Software Foundation, Inc.    Contributed by Cygnus Support.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|GDBINIT_FILENAME
value|".os68gdbinit"
end_define

begin_define
define|#
directive|define
name|DEFAULT_PROMPT
value|"(os68k) "
end_define

begin_include
include|#
directive|include
file|"tm-68k.h"
end_include

begin_comment
comment|/* We have more complex, useful breakpoints on the target.  */
end_comment

begin_undef
undef|#
directive|undef
name|DECR_PC_AFTER_BREAK
end_undef

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_comment
comment|/* We are guaranteed to have a zero frame pointer at bottom of stack, too. */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_CHAIN
end_undef

begin_undef
undef|#
directive|undef
name|FRAME_CHAIN_VALID
end_undef

begin_comment
comment|/* Takes the current frame-struct pointer and returns the chain-pointer    to get to the calling frame.     If our current frame pointer is zero, we're at the top; else read out    the saved FP from memory pointed to by the current FP.  */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN
parameter_list|(
name|thisframe
parameter_list|)
value|((thisframe)->frame? read_memory_integer ((thisframe)->frame, 4): 0)
end_define

begin_comment
comment|/* If the chain pointer is zero (either because the saved value fetched    by FRAME_CHAIN was zero, or because the current FP was zero so FRAME_CHAIN    never fetched anything), we are at the top of the stack.  */
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

end_unit

