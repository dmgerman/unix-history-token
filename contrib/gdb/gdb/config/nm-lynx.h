begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native-dependent definitions for LynxOS.     Copyright 1993, 1994, 1995, 1996, 1999, 2000, 2003 Free Software    Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
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

begin_struct_decl
struct_decl|struct
name|target_waitstatus
struct_decl|;
end_struct_decl

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
file|"gdbthread.h"
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

begin_function_decl
specifier|extern
name|ptid_t
name|child_wait
parameter_list|(
name|ptid_t
name|ptid
parameter_list|,
name|struct
name|target_waitstatus
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Lynx needs a special definition of this so that we can    print out the pid and thread number seperately.  */
end_comment

begin_comment
comment|/* override child_pid_to_str in inftarg.c */
end_comment

begin_define
define|#
directive|define
name|CHILD_PID_TO_STR
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|lynx_pid_to_str
parameter_list|(
name|ptid_t
name|ptid
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_LYNX_H */
end_comment

end_unit

