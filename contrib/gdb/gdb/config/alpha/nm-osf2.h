begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native definitions for alpha running OSF/1-2.x, using procfs.    Copyright (C) 1995 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Get generic OSF/1 definitions.  */
end_comment

begin_include
include|#
directive|include
file|"alpha/nm-osf.h"
end_include

begin_comment
comment|/* OSF/1-2.x has optional /proc support, try to use it instead of ptrace.  */
end_comment

begin_define
define|#
directive|define
name|USE_PROC_FS
end_define

begin_define
define|#
directive|define
name|HAVE_OPTIONAL_PROC_FS
end_define

begin_comment
comment|/* OSF/1 doesn't provide the standard fault definitions, so don't use them.  */
end_comment

begin_define
define|#
directive|define
name|FAULTED_USE_SIGINFO
end_define

begin_comment
comment|/* Don't trace faults under OSF/1, rely on the posting of the appropriate    signal if fault tracing is disabled.    Tracing T_IFAULT under Alpha OSF/1 causes a `floating point enable'    fault from which we cannot continue (except by disabling the    tracing).    And as OSF/1 doesn't provide the standard fault definitions, the    mapping of faults to appropriate signals in procfs_wait is difficult.  */
end_comment

begin_define
define|#
directive|define
name|PROCFS_DONT_TRACE_FAULTS
end_define

begin_comment
comment|/* Work around some peculiarities in the OSF/1 procfs implementation.  */
end_comment

begin_define
define|#
directive|define
name|PROCFS_SIGPEND_OFFSET
end_define

begin_define
define|#
directive|define
name|PROCFS_NEED_PIOCSSIG_FOR_KILL
end_define

begin_define
define|#
directive|define
name|PROCFS_DONT_PIOCSSIG_CURSIG
end_define

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
comment|/* poll() doesn't seem to work properly for /proc in this version of the OS.    If we only specify POLLPRI, things hang.  It seems to get better when we set    POLLOUT, but that always returns POLLNVAL!!!  Also, POLLOUT causes problems    on other OSes.  */
end_comment

begin_define
define|#
directive|define
name|LOSING_POLL
end_define

end_unit

