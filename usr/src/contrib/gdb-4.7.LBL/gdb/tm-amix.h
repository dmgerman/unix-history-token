begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on a Commodore Amiga running SVR4 (amix).    Copyright (C) 1991, Free Software Foundation, Inc.    Written by Fred Fish at Cygnus Support (fnf@cygint)  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* All Amiga's (so far) running UNIX have come standard with the floating    point coprocessor. */
end_comment

begin_define
define|#
directive|define
name|HAVE_68881
end_define

begin_comment
comment|/* Define BPT_VECTOR if it is different than the default.    This is the vector number used by traps to indicate a breakpoint. */
end_comment

begin_define
define|#
directive|define
name|BPT_VECTOR
value|0x1
end_define

begin_comment
comment|/* How much to decrement the PC after a trap.  Depends on kernel. */
end_comment

begin_define
define|#
directive|define
name|DECR_PC_AFTER_BREAK
value|0
end_define

begin_comment
comment|/* No decrement required */
end_comment

begin_comment
comment|/* Address of end of stack space.  Actually one byte past it.    This value is typically very OS dependent.    FIXME:  Check to see if SVR4 offers some machine independent way    of discovering this value and use it if so, and if we need it. */
end_comment

begin_comment
comment|/* #define STACK_END_ADDR 0xc0800000 */
end_comment

begin_comment
comment|/* Use the alternate method of determining valid frame chains. */
end_comment

begin_define
define|#
directive|define
name|FRAME_CHAIN_VALID_ALTERNATE
end_define

begin_include
include|#
directive|include
file|"tm-sysv4.h"
end_include

begin_include
include|#
directive|include
file|"tm-68k.h"
end_include

begin_comment
comment|/* Offsets (in target ints) into jmp_buf.  Not defined in any system header    file, so we have to step through setjmp/longjmp with a debugger and figure    them out.  As a double check, note that<setjmp> defines _JBLEN as 13,    which matches the number of elements we see saved by setjmp(). */
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
name|JB_D2
value|0
end_define

begin_define
define|#
directive|define
name|JB_D3
value|1
end_define

begin_define
define|#
directive|define
name|JB_D4
value|2
end_define

begin_define
define|#
directive|define
name|JB_D5
value|3
end_define

begin_define
define|#
directive|define
name|JB_D6
value|4
end_define

begin_define
define|#
directive|define
name|JB_D7
value|5
end_define

begin_define
define|#
directive|define
name|JB_A1
value|6
end_define

begin_define
define|#
directive|define
name|JB_A2
value|7
end_define

begin_define
define|#
directive|define
name|JB_A3
value|8
end_define

begin_define
define|#
directive|define
name|JB_A4
value|9
end_define

begin_define
define|#
directive|define
name|JB_A5
value|10
end_define

begin_define
define|#
directive|define
name|JB_A6
value|11
end_define

begin_define
define|#
directive|define
name|JB_A7
value|12
end_define

begin_define
define|#
directive|define
name|JB_PC
value|JB_A1
end_define

begin_comment
comment|/* Setjmp()'s return PC saved in A1 */
end_comment

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

