begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// OBSOLETE /* Native definitions for GDB on DECstations, Sony News. and MIPS Riscos systems
end_comment

begin_comment
comment|// OBSOLETE    Copyright 1986, 1987, 1989, 1992, 1995, 1996, 2000
end_comment

begin_comment
comment|// OBSOLETE    Free Software Foundation, Inc.
end_comment

begin_comment
comment|// OBSOLETE    Contributed by Per Bothner(bothner@cs.wisc.edu) at U.Wisconsin
end_comment

begin_comment
comment|// OBSOLETE    and by Alessandro Forin(af@cs.cmu.edu) at CMU
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    This file is part of GDB.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    This program is free software; you can redistribute it and/or modify
end_comment

begin_comment
comment|// OBSOLETE    it under the terms of the GNU General Public License as published by
end_comment

begin_comment
comment|// OBSOLETE    the Free Software Foundation; either version 2 of the License, or
end_comment

begin_comment
comment|// OBSOLETE    (at your option) any later version.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    This program is distributed in the hope that it will be useful,
end_comment

begin_comment
comment|// OBSOLETE    but WITHOUT ANY WARRANTY; without even the implied warranty of
end_comment

begin_comment
comment|// OBSOLETE    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
end_comment

begin_comment
comment|// OBSOLETE    GNU General Public License for more details.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    You should have received a copy of the GNU General Public License
end_comment

begin_comment
comment|// OBSOLETE    along with this program; if not, write to the Free Software
end_comment

begin_comment
comment|// OBSOLETE    Foundation, Inc., 59 Temple Place - Suite 330,
end_comment

begin_comment
comment|// OBSOLETE    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_comment
comment|// OBSOLETE #define FETCH_INFERIOR_REGISTERS
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Figure out where the longjmp will land.  We expect that we have just entered
end_comment

begin_comment
comment|// OBSOLETE    longjmp and haven't yet setup the stack frame, so the args are still in the
end_comment

begin_comment
comment|// OBSOLETE    argument regs.  a0 (CALL_ARG0) points at the jmp_buf structure from which we
end_comment

begin_comment
comment|// OBSOLETE    extract the pc (JB_PC) that we will land at.  The pc is copied into ADDR.
end_comment

begin_comment
comment|// OBSOLETE    This routine returns true on success */
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE #define GET_LONGJMP_TARGET(ADDR) get_longjmp_target(ADDR)
end_comment

begin_comment
comment|// OBSOLETE extern int get_longjmp_target (CORE_ADDR *);
end_comment

end_unit

