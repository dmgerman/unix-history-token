begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on an Alpha box under Linux.  The    definitions here are used when the _target_ system is running Linux.    Copyright 1996 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_LINUXALPHA_H
end_ifndef

begin_define
define|#
directive|define
name|TM_LINUXALPHA_H
end_define

begin_include
include|#
directive|include
file|"alpha/tm-alpha.h"
end_include

begin_comment
comment|/* Are we currently handling a signal ?  */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|alpha_linux_sigtramp_offset
name|PARAMS
argument_list|(
operator|(
name|CORE_ADDR
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_undef
undef|#
directive|undef
name|IN_SIGTRAMP
end_undef

begin_define
define|#
directive|define
name|IN_SIGTRAMP
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|(alpha_linux_sigtramp_offset (pc)>= 0)
end_define

begin_comment
comment|/* Get start and end address of sigtramp handler.  */
end_comment

begin_define
define|#
directive|define
name|SIGTRAMP_START
parameter_list|(
name|pc
parameter_list|)
value|(pc - alpha_linux_sigtramp_offset (pc))
end_define

begin_define
define|#
directive|define
name|SIGTRAMP_END
parameter_list|(
name|pc
parameter_list|)
value|(SIGTRAMP_START(pc) + 3*4)
end_define

begin_comment
comment|/* Number of traps that happen between exec'ing the shell to run an    inferior, and when we finally get to the inferior code.  This is 2    on Linux and most implementations.  */
end_comment

begin_undef
undef|#
directive|undef
name|START_INFERIOR_TRAPS_EXPECTED
end_undef

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|2
end_define

begin_comment
comment|/* Return TRUE if procedure descriptor PROC is a procedure descriptor    that refers to a dynamically generated sigtramp function.  */
end_comment

begin_undef
undef|#
directive|undef
name|PROC_DESC_IS_DYN_SIGTRAMP
end_undef

begin_define
define|#
directive|define
name|PROC_SIGTRAMP_MAGIC
value|0x0e0f0f0f
end_define

begin_define
define|#
directive|define
name|PROC_DESC_IS_DYN_SIGTRAMP
parameter_list|(
name|proc
parameter_list|)
value|((proc)->pdr.isym		\ 					 == PROC_SIGTRAMP_MAGIC)
end_define

begin_undef
undef|#
directive|undef
name|SET_PROC_DESC_IS_DYN_SIGTRAMP
end_undef

begin_define
define|#
directive|define
name|SET_PROC_DESC_IS_DYN_SIGTRAMP
parameter_list|(
name|proc
parameter_list|)
value|((proc)->pdr.isym		\ 					     = PROC_SIGTRAMP_MAGIC)
end_define

begin_comment
comment|/* If PC is inside a dynamically generated sigtramp function, return    how many bytes the program counter is beyond the start of that    function.  Otherwise, return a negative value.  */
end_comment

begin_undef
undef|#
directive|undef
name|DYNAMIC_SIGTRAMP_OFFSET
end_undef

begin_define
define|#
directive|define
name|DYNAMIC_SIGTRAMP_OFFSET
parameter_list|(
name|pc
parameter_list|)
value|(alpha_linux_sigtramp_offset (pc))
end_define

begin_comment
comment|/* Translate a signal handler frame into the address of the sigcontext    structure.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIGCONTEXT_ADDR
end_undef

begin_define
define|#
directive|define
name|SIGCONTEXT_ADDR
parameter_list|(
name|frame
parameter_list|)
value|((frame)->frame - 0x298)
end_define

begin_comment
comment|/* If FRAME refers to a sigtramp frame, return the address of the next frame.     Under Linux, sigtramp handlers have dynamically generated procedure    descriptors that make this hack unnecessary.  */
end_comment

begin_undef
undef|#
directive|undef
name|FRAME_PAST_SIGTRAMP_FRAME
end_undef

begin_define
define|#
directive|define
name|FRAME_PAST_SIGTRAMP_FRAME
parameter_list|(
name|frame
parameter_list|,
name|pc
parameter_list|)
value|(0)
end_define

begin_comment
comment|/* We need this for the SOLIB_TRAMPOLINE stuff.  */
end_comment

begin_include
include|#
directive|include
file|"tm-sysv4.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_LINUXALPHA_H */
end_comment

end_unit

