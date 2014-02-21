begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*********************************************************************** Copyright 2003-2006 Raza Microelectronics, Inc.(RMI). This is a derived work from software originally provided by the external entity identified below. The licensing terms and warranties specified in the header of the original work apply to this derived work. Contribution by RMI:  *****************************#RMI_1#**********************************/
end_comment

begin_comment
comment|/* Native-dependent definitions for NetBSD/mips.    Copyright 2002 Free Software Foundation, Inc.    Contributed by Wasabi Systems, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_FBSD_H
end_ifndef

begin_define
define|#
directive|define
name|NM_FBSD_H
end_define

begin_comment
comment|/* Override child_pid_to_exec_file in 'inftarg.c'.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PID_TO_EXEC_FILE
end_define

begin_comment
comment|/* Type of the third argument to the `ptrace' system call.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|caddr_t
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in `infptrace.c'.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* We can attach and detach.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_comment
comment|/* Shared library support.  */
end_comment

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_FBSD_H */
end_comment

end_unit

