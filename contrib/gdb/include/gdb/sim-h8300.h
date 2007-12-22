begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file defines the interface between the h8300 simulator and gdb.    Copyright (C) 2002 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SIM_H8300_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|SIM_H8300_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__cplusplus
end_ifdef

begin_extern
extern|extern
literal|"C"
block|{
comment|//}
endif|#
directive|endif
comment|/* The simulator makes use of the following register information. */
enum|enum
name|sim_h8300_regs
block|{
comment|/* Registers common to all the H8 variants. */
comment|/* Start here: */
name|SIM_H8300_R0_REGNUM
block|,
name|SIM_H8300_R1_REGNUM
block|,
name|SIM_H8300_R2_REGNUM
block|,
name|SIM_H8300_R3_REGNUM
block|,
name|SIM_H8300_R4_REGNUM
block|,
name|SIM_H8300_R5_REGNUM
block|,
name|SIM_H8300_R6_REGNUM
block|,
name|SIM_H8300_R7_REGNUM
block|,
name|SIM_H8300_CCR_REGNUM
block|,
comment|/* Contains processor status */
name|SIM_H8300_PC_REGNUM
block|,
comment|/* Contains program counter */
comment|/* End here */
name|SIM_H8300_EXR_REGNUM
block|,
comment|/* Contains extended processor status                               H8S and higher */
name|SIM_H8300_MACL_REGNUM
block|,
comment|/* Lower part of MAC register (26xx only)*/
name|SIM_H8300_MACH_REGNUM
block|,
comment|/* High part of MAC register (26xx only) */
name|SIM_H8300_CYCLE_REGNUM
block|,
name|SIM_H8300_INST_REGNUM
block|,
name|SIM_H8300_TICK_REGNUM
block|}
enum|;
enum|enum
block|{
name|SIM_H8300_ARG_FIRST_REGNUM
init|=
name|SIM_H8300_R0_REGNUM
block|,
comment|/* first reg in which an arg                                                          may be passed */
name|SIM_H8300_ARG_LAST_REGNUM
init|=
name|SIM_H8300_R3_REGNUM
block|,
comment|/* last  reg in which an arg                                                          may be passed */
name|SIM_H8300_FP_REGNUM
init|=
name|SIM_H8300_R6_REGNUM
block|,
comment|/* Contain address of executing                                                   stack frame */
name|SIM_H8300_SP_REGNUM
init|=
name|SIM_H8300_R7_REGNUM
comment|/* Contains address of top of stack */
block|}
enum|;
enum|enum
block|{
name|SIM_H8300_NUM_COMMON_REGS
init|=
literal|10
block|,
name|SIM_H8300_S_NUM_REGS
init|=
literal|13
block|,
name|SIM_H8300_NUM_REGS
init|=
literal|16
block|}
enum|;
ifdef|#
directive|ifdef
name|__cplusplus
block|}
end_extern

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SIM_H8300_H */
end_comment

end_unit

