begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a merlin under utek 2.1    Copyright 1986, 1987, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<machine/reg.h>
end_include

begin_comment
comment|/* This machine doesn't have the siginterrupt call.  */
end_comment

begin_define
define|#
directive|define
name|NO_SIGINTERRUPT
end_define

begin_comment
comment|/* Under Utek, a ptrace'd process can be the only active process for    an executable.  Therefore instead of /bin/sh use gdb-sh (which should    just be a copy of /bin/sh which is world readable and writeable).  */
end_comment

begin_define
define|#
directive|define
name|SHELL_FILE
value|"/usr/gnu/lib/gdb-sh"
end_define

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|(0xfef000)
end_define

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|{ 									\   switch (regno) {							\   case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:	\ 	addr = blockend + (R0 - regno) * sizeof (int); break;		\   case PC_REGNUM:							\   	addr = blockend + PC * sizeof (int); break;			\   case SP_REGNUM:							\   	addr = blockend + SP * sizeof (int); break;			\   case FP_REGNUM:							\   	addr = blockend + FP * sizeof (int); break;			\   case PS_REGNUM:							\   	addr = blockend + 12 * sizeof (int); break;			\   case FPS_REGNUM:							\   	addr = 108; break;						\   case FP0_REGNUM + 0: case FP0_REGNUM + 1:				\   case FP0_REGNUM + 2: case FP0_REGNUM + 3: 				\   case FP0_REGNUM + 4: case FP0_REGNUM + 5: 				\   case FP0_REGNUM + 6: case FP0_REGNUM + 7: 				\   	addr = 76 + (regno - FP0_REGNUM) * sizeof (float); break;	\   case LP0_REGNUM + 0: case LP0_REGNUM + 1:				\   case LP0_REGNUM + 2: case LP0_REGNUM + 3:				\   	addr = 76 + (regno - LP0_REGNUM) * sizeof (double); break;	\   default:								\   	printf ("bad argument to REGISTER_U_ADDR %d\n", regno);		\ 	abort ();							\   }									\ }
end_define

end_unit

