begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on a Sequent Symmetry under dynix 3.0,    with Weitek 1167 and i387 support.    Copyright 1986, 1987, 1989, 1992  Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* We must fetch all the regs before storing, since we store all at once.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PREPARE_TO_STORE
parameter_list|()
value|read_register_bytes (0, NULL, REGISTER_BYTES)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_define
define|#
directive|define
name|CHILD_WAIT
end_define

begin_decl_stmt
specifier|extern
name|int
name|child_wait
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|target_waitstatus
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_SEQUENT_
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/user.h>
end_include

begin_include
include|#
directive|include
file|<sys/mc_vmparam.h>
end_include

begin_comment
comment|/* VA_UAREA is defined in<sys/mc_vmparam.h>, and is dependant upon     sizeof(struct user) */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|(VA_UAREA)
end_define

begin_comment
comment|/* ptx */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|(0x80000000 - (UPAGES * NBPG))
end_define

begin_comment
comment|/* dynix */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

