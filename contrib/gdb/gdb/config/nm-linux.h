begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for GNU/Linux.     Copyright 1999, 2000, 2001, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* GNU/Linux is SVR4-ish but its /proc file system isn't.  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_PROC_FS
end_undef

begin_comment
comment|/* Tell GDB that we can attach and detach other processes.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_comment
comment|/* Since we're building a native debugger, we can include<signal.h>    to find the range of real-time signals.  */
end_comment

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__SIGRTMIN
end_ifdef

begin_define
define|#
directive|define
name|REALTIME_LO
value|__SIGRTMIN
end_define

begin_define
define|#
directive|define
name|REALTIME_HI
value|(__SIGRTMAX + 1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* We define this if link.h is available, because with ELF we use SVR4    style shared libraries.  */
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
comment|/* Support for shared libraries.  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Override child_wait in `inftarg.c'.  */
end_comment

begin_struct_decl
struct_decl|struct
name|target_waitstatus
struct_decl|;
end_struct_decl

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
name|ourstatus
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CHILD_WAIT
end_define

begin_function_decl
specifier|extern
name|int
name|lin_lwp_prepare_to_proceed
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|PREPARE_TO_PROCEED
parameter_list|(
name|select_it
parameter_list|)
value|lin_lwp_prepare_to_proceed ()
end_define

begin_function_decl
specifier|extern
name|void
name|lin_lwp_attach_lwp
parameter_list|(
name|ptid_t
name|ptid
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|ATTACH_LWP
parameter_list|(
name|ptid
parameter_list|,
name|verbose
parameter_list|)
value|lin_lwp_attach_lwp ((ptid), (verbose))
end_define

begin_function_decl
specifier|extern
name|void
name|lin_thread_get_thread_signals
parameter_list|(
name|sigset_t
modifier|*
name|mask
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|GET_THREAD_SIGNALS
parameter_list|(
name|mask
parameter_list|)
value|lin_thread_get_thread_signals (mask)
end_define

begin_comment
comment|/* Defined to make stepping-over-breakpoints be thread-atomic.  */
end_comment

begin_define
define|#
directive|define
name|USE_THREAD_STEP_NEEDED
value|1
end_define

begin_escape
end_escape

begin_comment
comment|/* Use elf_gregset_t and elf_fpregset_t, rather than    gregset_t and fpregset_t.  */
end_comment

begin_define
define|#
directive|define
name|GDB_GREGSET_T
value|elf_gregset_t
end_define

begin_define
define|#
directive|define
name|GDB_FPREGSET_T
value|elf_fpregset_t
end_define

begin_comment
comment|/* Override child_pid_to_exec_file in 'inftarg.c'.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PID_TO_EXEC_FILE
end_define

end_unit

