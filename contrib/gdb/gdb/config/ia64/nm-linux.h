begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for GNU/Linux, for GDB, the GNU debugger.    Copyright 1999, 2000, 2001    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|NM_LINUX_H
end_define

begin_include
include|#
directive|include
file|"nm-linux.h"
end_include

begin_comment
comment|/* Note:  It seems likely that we'll have to eventually define    FETCH_INFERIOR_REGISTERS.  But until that time, we'll make do    with the following. */
end_comment

begin_define
define|#
directive|define
name|CANNOT_FETCH_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|ia64_cannot_fetch_register(regno)
end_define

begin_function_decl
specifier|extern
name|int
name|ia64_cannot_fetch_register
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|ia64_cannot_store_register(regno)
end_define

begin_function_decl
specifier|extern
name|int
name|ia64_cannot_store_register
parameter_list|(
name|int
name|regno
parameter_list|)
function_decl|;
end_function_decl

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
value|(addr) = ia64_register_u_addr ((blockend),(regno));
end_define

begin_function_decl
specifier|extern
name|int
name|ia64_register_u_addr
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GDBSERVER */
end_comment

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|0
end_define

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|long
end_define

begin_define
define|#
directive|define
name|PTRACE_XFER_TYPE
value|long
end_define

begin_comment
comment|/* Hardware watchpoints */
end_comment

begin_define
define|#
directive|define
name|TARGET_HAS_HARDWARE_WATCHPOINTS
end_define

begin_define
define|#
directive|define
name|TARGET_CAN_USE_HARDWARE_WATCHPOINT
parameter_list|(
name|type
parameter_list|,
name|cnt
parameter_list|,
name|ot
parameter_list|)
value|1
end_define

begin_comment
comment|/* The IA-64 architecture can step over a watch point (without triggering    it again) if the "dd" (data debug fault disable) bit in the processor    status word is set.        This PSR bit is set in ia64_linux_stopped_by_watchpoint when the    code there has determined that a hardware watchpoint has indeed    been hit.  The CPU will then be able to execute one instruction     without triggering a watchpoint. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STEPPABLE_WATCHPOINT
value|1
end_define

begin_define
define|#
directive|define
name|STOPPED_BY_WATCHPOINT
parameter_list|(
name|W
parameter_list|)
define|\
value|ia64_linux_stopped_by_watchpoint (inferior_ptid)
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|ia64_linux_stopped_by_watchpoint
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|target_insert_watchpoint
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|type
parameter_list|)
define|\
value|ia64_linux_insert_watchpoint (inferior_ptid, addr, len, type)
end_define

begin_function_decl
specifier|extern
name|int
name|ia64_linux_insert_watchpoint
parameter_list|(
name|ptid_t
name|ptid
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|,
name|int
name|rw
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|target_remove_watchpoint
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|type
parameter_list|)
define|\
value|ia64_linux_remove_watchpoint (inferior_ptid, addr, len)
end_define

begin_function_decl
specifier|extern
name|int
name|ia64_linux_remove_watchpoint
parameter_list|(
name|ptid_t
name|ptid
parameter_list|,
name|CORE_ADDR
name|addr
parameter_list|,
name|int
name|len
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef NM_LINUX_H */
end_comment

end_unit

