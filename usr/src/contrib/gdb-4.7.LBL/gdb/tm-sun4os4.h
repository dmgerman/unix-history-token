begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB for a Sun 4 running sunos 4.    Copyright 1989, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"tm-sparc.h"
end_include

begin_include
include|#
directive|include
file|"tm-sunos.h"
end_include

begin_comment
comment|/* Offsets into jmp_buf.  Not defined by Sun, but at least documented in a    comment in<machine/setjmp.h>! */
end_comment

begin_define
define|#
directive|define
name|JB_ELEMENT_SIZE
value|4
end_define

begin_comment
comment|/* Size of each element in jmp_buf */
end_comment

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
name|JB_NPC
value|4
end_define

begin_define
define|#
directive|define
name|JB_PSR
value|5
end_define

begin_define
define|#
directive|define
name|JB_G1
value|6
end_define

begin_define
define|#
directive|define
name|JB_O0
value|7
end_define

begin_define
define|#
directive|define
name|JB_WBCNT
value|8
end_define

begin_comment
comment|/* Figure out where the longjmp will land.  We expect that we have just entered    longjmp and haven't yet setup the stack frame, so the args are still in the    output regs.  %o0 (O0_REGNUM) points at the jmp_buf structure from which we    extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.    This routine returns true on success */
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

