begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on an Intel i386 running SVR4.    Copyright (C) 1991, Free Software Foundation, Inc.    Written by Fred Fish at Cygnus Support (fnf@cygint)  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Use the alternate method of determining valid frame chains. */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID_ALTERNATE
end_define

begin_comment
comment|/* number of traps that happen between exec'ing the shell   * to run an inferior, and when we finally get to   * the inferior code.  This is 2 on most implementations.  */
end_comment

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|2
end_define

begin_comment
comment|/* Pick up most of what we need from the generic i386 target include file. */
end_comment

begin_include
include|#
directive|include
file|"tm-i386v.h"
end_include

begin_comment
comment|/* Pick up more stuff from the generic SVR4 host include file. */
end_comment

begin_include
include|#
directive|include
file|"tm-sysv4.h"
end_include

begin_comment
comment|/* We can't tell how many args there are    now that the C compiler delays popping them.  */
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
name|val
parameter_list|,
name|fi
parameter_list|)
value|(val = -1)
end_define

begin_comment
comment|/* Offsets (in target ints) into jmp_buf.  Not defined in any system header    file, so we have to step through setjmp/longjmp with a debugger and figure    them out.  Note that<setjmp> defines _JBLEN as 10, which is the default    if no specific machine is selected, even though we only use 6 slots. */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|sizeof(int)
end_define

begin_comment
comment|/* jmp_buf[_JBLEN] is array of ints */
end_comment

begin_define
define|#
directive|define
name|JB_EBX
value|0
end_define

begin_define
define|#
directive|define
name|JB_ESI
value|1
end_define

begin_define
define|#
directive|define
name|JB_EDI
value|2
end_define

begin_define
define|#
directive|define
name|JB_EBP
value|3
end_define

begin_define
define|#
directive|define
name|JB_ESP
value|4
end_define

begin_define
define|#
directive|define
name|JB_EDX
value|5
end_define

begin_define
define|#
directive|define
name|JB_PC
value|JB_EDX
end_define

begin_comment
comment|/* Setjmp()'s return PC saved in EDX */
end_comment

begin_comment
comment|/* Figure out where the longjmp will land.  Slurp the args out of the stack.    We expect the first arg to be a pointer to the jmp_buf structure from which    we extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.    This routine returns true on success */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|get_longjmp_target
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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

