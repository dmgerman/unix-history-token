begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for GNU/Linux, for GDB, the GNU debugger.    Copyright (C) 1986, 1987, 1989, 1992, 1996, 1998    Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"i386/nm-i386v.h"
end_include

begin_comment
comment|/* Return sizeof user struct to callers in less machine dependent routines */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_SIZE
value|kernel_u_size()
end_define

begin_decl_stmt
specifier|extern
name|int
name|kernel_u_size
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Tell gdb that we can attach and detach other processes */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|0
end_define

begin_comment
comment|/* GNU/Linux supports the 386 hardware debugging registers.  */
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
comment|/* After a watchpoint trap, the PC points to the instruction after    the one that caused the trap.  Therefore we don't need to step over it.    But we do need to reset the status register to avoid another trap.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONTINUABLE_WATCHPOINT
end_define

begin_define
define|#
directive|define
name|STOPPED_BY_WATCHPOINT
parameter_list|(
name|W
parameter_list|)
define|\
value|i386_stopped_by_watchpoint (inferior_pid)
end_define

begin_comment
comment|/* Use these macros for watchpoint insertion/removal.  */
end_comment

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
value|i386_insert_watchpoint (inferior_pid, addr, len, type)
end_define

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
value|i386_remove_watchpoint (inferior_pid, addr, len)
end_define

begin_comment
comment|/* We define this if link.h is available, because with ELF we use SVR4 style    shared libraries. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LINK_H
end_ifdef

begin_define
define|#
directive|define
name|SVR4_SHARED_LIBS
end_define

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_comment
comment|/* Support for shared libraries. */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|CORE_ADDR
name|i386_stopped_by_watchpoint
name|PARAMS
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i386_insert_watchpoint
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|,
name|CORE_ADDR
name|addr
operator|,
name|int
name|len
operator|,
name|int
name|rw
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|i386_remove_watchpoint
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|,
name|CORE_ADDR
name|addr
operator|,
name|int
name|len
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef NM_LINUX_H */
end_comment

end_unit

