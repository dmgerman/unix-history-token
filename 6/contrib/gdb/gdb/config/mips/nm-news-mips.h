begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// OBSOLETE /* Definitions to make GDB run on a mips box under 4.3bsd.
end_comment

begin_comment
comment|// OBSOLETE    Copyright 1986, 1987, 1989, 1993, 1996 Free Software Foundation, Inc.
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
comment|// OBSOLETE #ifndef NM_NEWS_MIPS_H
end_comment

begin_comment
comment|// OBSOLETE #define NM_NEWS_MIPS_H 1
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Needed for RISC NEWS core files.  */
end_comment

begin_comment
comment|// OBSOLETE #include<machine/machparam.h>
end_comment

begin_comment
comment|// OBSOLETE #include<sys/types.h>
end_comment

begin_comment
comment|// OBSOLETE #define KERNEL_U_ADDR UADDR
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE #define REGISTER_U_ADDR(addr, blockend, regno) 		\
end_comment

begin_comment
comment|// OBSOLETE 	if (regno< 38) addr = (NBPG*UPAGES) + (regno - 38)*sizeof(int);\
end_comment

begin_comment
comment|// OBSOLETE 	else addr = 0;		/* ..somewhere in the pcb */
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
comment|// OBSOLETE #include "mips/nm-mips.h"
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE /* Apparently not in<sys/types.h> */
end_comment

begin_comment
comment|// OBSOLETE typedef int pid_t;
end_comment

begin_comment
comment|// OBSOLETE
end_comment

begin_comment
comment|// OBSOLETE #endif /* NM_NEWS_MIPS_H */
end_comment

end_unit

