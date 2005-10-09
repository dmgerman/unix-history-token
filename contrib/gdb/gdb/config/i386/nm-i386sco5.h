begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for SCO OpenServer 5.    Copyright 1996, 1998, 2002 Free Software Foundation, Inc.    Re-written by J. Kean Johnston<jkj@sco.com>.    Originally written by Robert Lipe<robertl@dgii.com>, based on     work by Ian Lance Taylor<ian@cygnus.com> and     Martin Walker<maw@netcom.com>.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_I386SCO5_H
end_ifndef

begin_define
define|#
directive|define
name|NM_I386SCO5_H
end_define

begin_comment
comment|/* Basically, its a lot like the older versions ... */
end_comment

begin_include
include|#
directive|include
file|"i386/nm-i386sco.h"
end_include

begin_comment
comment|/* ... but it can do a lot of SVR4 type stuff too.  */
end_comment

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
comment|/* Pick up shared library support.  */
end_comment

begin_comment
comment|/* SCO is unlike other SVR4 systems in that it has SVR4 style shared    libs, with a slight twist.  We expect 3 traps (2 for the exec and    one for the dynamic loader).  After the third trap we insert the    shared library breakpoints, then wait for the 4th trap.  */
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
comment|/* SCO does not provide<sys/ptrace.h>.  However, infptrace.c does not    have defaults for these values.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ATTACH
value|10
end_define

begin_define
define|#
directive|define
name|PTRACE_DETACH
value|11
end_define

begin_comment
comment|/* Return the size of the user struct.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_SIZE
value|kernel_u_size ()
end_define

begin_function_decl
specifier|extern
name|int
name|kernel_u_size
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* We can attach and detach.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_comment
comment|/* Hardware-assisted breakpoints and watchpoints.  */
end_comment

begin_comment
comment|/* We can also do hardware watchpoints.  */
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
comment|/* After a watchpoint trap, the PC points to the instruction which    caused the trap.  But we can continue over it without disabling the    trap.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CONTINUABLE_WATCHPOINT
value|1
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
value|i386_stopped_by_watchpoint (PIDGET (inferior_ptid))
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
value|i386_insert_watchpoint (PIDGET (inferior_ptid), addr, len, type)
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
value|i386_remove_watchpoint (PIDGET (inferior_ptid), addr, len)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nm-i386sco5.h */
end_comment

end_unit

