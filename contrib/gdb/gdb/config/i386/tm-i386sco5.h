begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on an Intel i386 running SCO Open Server 5.    Copyright (C) 1998 Free Software Foundation, Inc.    Written by J. Kean Johnston (jkj@sco.com).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386SCO5_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386SCO5_H
value|1
end_define

begin_comment
comment|/* Pick up most of what we need from the generic i386 target include file. */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_comment
comment|/* Pick up more stuff from the generic SYSV and SVR4 host include files. */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386v.h"
end_include

begin_include
include|#
directive|include
file|"tm-sysv4.h"
end_include

begin_define
define|#
directive|define
name|KERNEL_U_SIZE
value|kernel_u_size()
end_define

begin_comment
comment|/*  * SCO is unlike other SVR3 targets in that it has SVR4 style shared  * libs, with a slight twist. We expect 3 traps (2 for the exec and  * one for the dynamic loader).  After the third trap we insert the  * SOLIB breakpoints, then wait for the 4th trap.  */
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
value|3
end_define

begin_comment
comment|/* We can also do hardware watchpoints */
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
comment|/* After a watchpoint trap, the PC points to the instruction which    caused the trap.  But we can continue over it without disabling the    trap. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONTINUABLE_WATCHPOINT
end_define

begin_define
define|#
directive|define
name|HAVE_STEPPABLE_WATCHPOINT
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef TM_I386SCO5_H */
end_comment

end_unit

