begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for LynxOS.    Copyright 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_LYNX_H
end_ifndef

begin_define
define|#
directive|define
name|NM_LYNX_H
end_define

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_comment
comment|/* sys/kernel.h should define this, but doesn't always, sigh. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__LYNXOS
end_ifndef

begin_define
define|#
directive|define
name|__LYNXOS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/mem.h>
end_include

begin_include
include|#
directive|include
file|<sys/signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/itimer.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|"thread.h"
end_include

begin_comment
comment|/* This is the amount to subtract from u.u_ar0 to get the offset in    the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|USRSTACK
end_define

begin_undef
undef|#
directive|undef
name|FLOAT_INFO
end_undef

begin_comment
comment|/* No float info yet */
end_comment

begin_comment
comment|/* As of LynxOS 2.2.2 (beta 8/15/94), this is int.  Previous versions seem to    have had no prototype, so I'm not sure why GDB used to define this to    char *.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ARG3_TYPE
value|int
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_comment
comment|/* Thread ID of stopped thread.  */
end_comment

begin_define
define|#
directive|define
name|WIFTID
parameter_list|(
name|x
parameter_list|)
value|(((union wait *)&x)->w_tid)
end_define

begin_comment
comment|/* Override child_wait in inftarg.c */
end_comment

begin_define
define|#
directive|define
name|CHILD_WAIT
end_define

begin_comment
comment|/* Override child_resume in infptrace.c */
end_comment

begin_define
define|#
directive|define
name|CHILD_RESUME
end_define

begin_comment
comment|/* Override child_thread_alive in intarg.c */
end_comment

begin_define
define|#
directive|define
name|CHILD_THREAD_ALIVE
end_define

begin_include
include|#
directive|include
file|"target.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|child_wait
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|,
expr|struct
name|target_waitstatus
operator|*
name|status
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Lynx needs a special definition of this so that we can    print out the pid and thread number seperatly.  */
end_comment

begin_undef
undef|#
directive|undef
name|target_pid_to_str
end_undef

begin_define
define|#
directive|define
name|target_pid_to_str
parameter_list|(
name|PID
parameter_list|)
value|lynx_pid_to_str (PID)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|lynx_pid_to_str
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_LYNX_H */
end_comment

end_unit

