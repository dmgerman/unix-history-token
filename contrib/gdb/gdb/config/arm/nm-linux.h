begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on an ARM based machine under GNU/Linux.    Copyright 1999, 2000, 2001 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_ARMLINUX_H
end_ifndef

begin_define
define|#
directive|define
name|NM_ARMLINUX_H
end_define

begin_include
include|#
directive|include
file|"nm-linux.h"
end_include

begin_comment
comment|/* ptrace register ``addresses'' are absolute.  */
end_comment

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|0
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GDBSERVER
end_ifdef

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
value|(addr) = arm_register_u_addr ((blockend),(regno))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDBSERVER */
end_comment

begin_comment
comment|/* Return sizeof user struct to callers in less machine dependent routines */
end_comment

begin_function_decl
specifier|extern
name|int
name|kernel_u_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|KERNEL_U_SIZE
value|arm_linux_kernel_u_size()
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_ARMLINUX_H */
end_comment

end_unit

