begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on an encore under umax 4.2    Copyright 1987, 1989, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Do implement the attach and detach commands...  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_comment
comment|/* Offset of registers within u area.  */
end_comment

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|0
end_define

begin_comment
comment|/* called from register_addr() -- blockend not used for now */
end_comment

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
value|{ 									\   switch (regno) {							\   case 0: case 1: case 2: case 3: case 4: case 5: case 6: case 7:	\ 	addr = PU_R0 - (regno * sizeof (int)); break;			\   case SP_REGNUM:							\   	addr = PU_SP; break;						\   case PC_REGNUM:							\   	addr = PU_PC; break;						\   case FP_REGNUM:							\   	addr = PU_FP; break;						\   case PS_REGNUM:							\   	addr = PU_PSL; break;						\   case FPS_REGNUM:							\   	addr = PU_FSR; break;						\   case FP0_REGNUM + 0: case FP0_REGNUM + 1:				\   case FP0_REGNUM + 2: case FP0_REGNUM + 3: 				\   case FP0_REGNUM + 4: case FP0_REGNUM + 5: 				\   case FP0_REGNUM + 6: case FP0_REGNUM + 7: 				\   	addr = PU_F0 + (regno - FP0_REGNUM) * sizeof (float); break;	\   case LP0_REGNUM + 0: case LP0_REGNUM + 1:				\   case LP0_REGNUM + 2: case LP0_REGNUM + 3:				\   	addr = PU_F0 + (regno - LP0_REGNUM) * sizeof (double); break;	\   default:								\   	printf ("bad argument to REGISTER_U_ADDR %d\n", regno);		\ 	abort ();							\   }									\ }
end_define

end_unit

