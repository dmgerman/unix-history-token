begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target machine description for VxWorks 68k's, for GDB, the GNU debugger.    Copyright 1986, 1987, 1989, 1991, 1992 Free Software Foundation, Inc.    Contributed by Cygnus Support.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

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

begin_define
define|#
directive|define
name|HAVE_68881
end_define

begin_comment
comment|/* We have more complex, useful breakpoints on the target.  */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_include
include|#
directive|include
file|"tm-68k.h"
end_include

begin_comment
comment|/* Define this if the C compiler puts an underscore at the front    of external names before giving them to the linker.  */
end_comment

begin_define
define|#
directive|define
name|NAMES_HAVE_UNDERSCORE
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

begin_comment
comment|/* FIXME, Longjmp information stolen from Sun-3 config.  Dunno if right.  */
end_comment

begin_comment
comment|/* Offsets (in target ints) into jmp_buf.  Not defined by Sun, but at least    documented in a comment in<machine/setjmp.h>! */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|JB_ONSSTACK
value|0
end_define

begin_define
define|#
directive|define
name|JB_SIGMASK
value|1
end_define

begin_define
define|#
directive|define
name|JB_SP
value|2
end_define

begin_define
define|#
directive|define
name|JB_PC
value|3
end_define

begin_define
define|#
directive|define
name|JB_PSL
value|4
end_define

begin_define
define|#
directive|define
name|JB_D2
value|5
end_define

begin_define
define|#
directive|define
name|JB_D3
value|6
end_define

begin_define
define|#
directive|define
name|JB_D4
value|7
end_define

begin_define
define|#
directive|define
name|JB_D5
value|8
end_define

begin_define
define|#
directive|define
name|JB_D6
value|9
end_define

begin_define
define|#
directive|define
name|JB_D7
value|10
end_define

begin_define
define|#
directive|define
name|JB_A2
value|11
end_define

begin_define
define|#
directive|define
name|JB_A3
value|12
end_define

begin_define
define|#
directive|define
name|JB_A4
value|13
end_define

begin_define
define|#
directive|define
name|JB_A5
value|14
end_define

begin_define
define|#
directive|define
name|JB_A6
value|15
end_define

begin_comment
comment|/* Figure out where the longjmp will land.  Slurp the args out of the stack.    We expect the first arg to be a pointer to the jmp_buf structure from which    we extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.    This routine returns true on success */
end_comment

begin_define
define|#
directive|define
name|GET_LONGJMP_TARGET
parameter_list|(
name|ADDR
parameter_list|)
value|get_longjmp_target(ADDR)
end_define

end_unit

