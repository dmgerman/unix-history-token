begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for GDB on mips.    Copyright (C) 1986, 1987, 1989, 1992 Free Software Foundation, Inc.    Contributed by Per Bothner(bothner@cs.wisc.edu) at U.Wisconsin    and by Alessandro Forin(af@cs.cmu.edu) at CMU  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* Figure out where the longjmp will land.  We expect that we have just entered    longjmp and haven't yet setup the stack frame, so the args are still in the    argument regs.  a0 (CALL_ARG0) points at the jmp_buf structure from which we    extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.    This routine returns true on success */
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

