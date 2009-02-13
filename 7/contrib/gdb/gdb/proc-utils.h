begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Machine independent support for SVR4 /proc (process file system) for GDB.    Copyright 1999, 2000 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation,  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * Pretty-print functions for /proc data   */
end_comment

begin_function_decl
specifier|extern
name|void
name|proc_prettyprint_why
parameter_list|(
name|unsigned
name|long
name|why
parameter_list|,
name|unsigned
name|long
name|what
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyprint_syscalls
parameter_list|(
name|sysset_t
modifier|*
name|sysset
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyprint_syscall
parameter_list|(
name|int
name|num
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyprint_flags
parameter_list|(
name|unsigned
name|long
name|flags
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyfprint_signalset
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|sigset_t
modifier|*
name|sigset
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyfprint_faultset
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|fltset_t
modifier|*
name|fltset
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyfprint_syscall
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|int
name|num
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyfprint_signal
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|int
name|signo
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyfprint_flags
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|unsigned
name|long
name|flags
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyfprint_why
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|unsigned
name|long
name|why
parameter_list|,
name|unsigned
name|long
name|what
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyfprint_fault
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|int
name|faultno
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyfprint_syscalls
parameter_list|(
name|FILE
modifier|*
name|file
parameter_list|,
name|sysset_t
modifier|*
name|sysset
parameter_list|,
name|int
name|verbose
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|proc_prettyfprint_status
parameter_list|(
name|long
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Trace functions for /proc api.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|write_with_trace
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|off_t
name|lseek_with_trace
parameter_list|(
name|int
parameter_list|,
name|off_t
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ioctl_with_trace
parameter_list|(
name|int
parameter_list|,
name|long
parameter_list|,
name|void
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|pid_t
name|wait_with_trace
parameter_list|(
name|int
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|open_with_trace
parameter_list|(
name|char
modifier|*
parameter_list|,
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|close_with_trace
parameter_list|(
name|int
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|procfs_note
parameter_list|(
name|char
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PROCFS_TRACE
end_ifdef

begin_comment
comment|/*  * Debugging code:  *  * These macros allow me to trace the system calls that we make  * to control the child process.  This is quite handy for comparing  * with the older version of procfs.  */
end_comment

begin_define
define|#
directive|define
name|write
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|Z
parameter_list|)
value|write_with_trace (X, Y, Z, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|lseek
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|Z
parameter_list|)
value|lseek_with_trace (X, Y, Z, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|ioctl
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|Z
parameter_list|)
value|ioctl_with_trace (X, Y, Z, __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|open
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|open_with_trace  (X, Y,    __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|close
parameter_list|(
name|X
parameter_list|)
value|close_with_trace (X,       __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|wait
parameter_list|(
name|X
parameter_list|)
value|wait_with_trace  (X,       __FILE__, __LINE__)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|PROCFS_NOTE
parameter_list|(
name|X
parameter_list|)
value|procfs_note      (X,       __FILE__, __LINE__)
end_define

begin_define
define|#
directive|define
name|PROC_PRETTYFPRINT_STATUS
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|,
name|Z
parameter_list|,
name|T
parameter_list|)
define|\
value|proc_prettyfprint_status (X, Y, Z, T)
end_define

begin_comment
comment|/* Define the type (and more importantly the width) of the control    word used to write to the /proc/PID/ctl file. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|PROC_CTL_WORD_TYPE
argument_list|)
end_if

begin_typedef
typedef|typedef
name|PROC_CTL_WORD_TYPE
name|procfs_ctl_t
typedef|;
end_typedef

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|long
name|procfs_ctl_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

