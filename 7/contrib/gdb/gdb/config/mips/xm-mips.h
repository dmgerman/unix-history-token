begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// OBSOLETE /* Definitions to make GDB run on a mips box under 4.3bsd.
end_comment

begin_comment
comment|// OBSOLETE    Copyright 1986, 1987, 1989, 1993, 1994, 1995, 1996, 1998
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
comment|// OBSOLETE #ifdef ultrix
end_comment

begin_comment
comment|// OBSOLETE /* Needed for DECstation core files.  */
end_comment

begin_comment
comment|// OBSOLETE #include<machine/param.h>
end_comment

begin_comment
comment|// OBSOLETE #define KERNEL_U_ADDR UADDR
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Native Ultrix cc has broken long long support.  */
end_comment

begin_comment
comment|// OBSOLETE #ifndef __GNUC__
end_comment

begin_comment
comment|// OBSOLETE #undef CC_HAS_LONG_LONG
end_comment

begin_comment
comment|// OBSOLETE #endif
end_comment

begin_comment
comment|// OBSOLETE #endif
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE #if ! defined (__GNUC__)&& ! defined (offsetof)
end_comment

begin_comment
comment|// OBSOLETE #define offsetof(TYPE, MEMBER) ((unsigned long)&((TYPE *)0)->MEMBER)
end_comment

begin_comment
comment|// OBSOLETE #endif
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Only used for core files on DECstations.
end_comment

begin_comment
comment|// OBSOLETE    First four registers at u.u_ar0 are saved arguments, and
end_comment

begin_comment
comment|// OBSOLETE    there is no r0 saved.   Float registers are saved
end_comment

begin_comment
comment|// OBSOLETE    in u_pcb.pcb_fpregs, not relative to u.u_ar0.  */
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE #define REGISTER_U_ADDR(addr, blockend, regno) 		\
end_comment

begin_comment
comment|// OBSOLETE 	{ \
end_comment

begin_comment
comment|// OBSOLETE 	  if (regno< FP0_REGNUM) \
end_comment

begin_comment
comment|// OBSOLETE 	    addr = blockend + sizeof(int) * (4 + regno - 1); \
end_comment

begin_comment
comment|// OBSOLETE 	  else \
end_comment

begin_comment
comment|// OBSOLETE 	    addr = offsetof (struct user, u_pcb.pcb_fpregs[0]) + \
end_comment

begin_comment
comment|// OBSOLETE 		   sizeof (int) * (regno - FP0_REGNUM); \
end_comment

begin_comment
comment|// OBSOLETE 	}
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Kernel is a bit tenacious about sharing text segments, disallowing bpts.  */
end_comment

begin_comment
comment|// OBSOLETE #define	ONE_PROCESS_WRITETEXT
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* HAVE_SGTTY also works, last we tried.
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE    But we have termios, at least as of Ultrix 4.2A, so use it.  */
end_comment

begin_comment
comment|// OBSOLETE #define HAVE_TERMIOS
end_comment

end_unit

