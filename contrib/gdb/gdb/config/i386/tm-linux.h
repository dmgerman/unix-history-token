begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to target GDB to GNU/Linux on 386.    Copyright 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|TM_LINUX_H
end_define

begin_comment
comment|/* FIXME:  If nothing else gets added to this file, it could be removed    and configure could just use tm-i386.h instead. -fnf */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_comment
comment|/* Offset to saved PC in sigcontext, from<linux/signal.h>.  */
end_comment

begin_define
define|#
directive|define
name|SIGCONTEXT_PC_OFFSET
value|38
end_define

begin_comment
comment|/* We need this file for the SOLIB_TRAMPOLINE stuff. */
end_comment

begin_include
include|#
directive|include
file|"tm-sysv4.h"
end_include

begin_comment
comment|/* The following works around a problem with /usr/include/sys/procfs.h  */
end_comment

begin_define
define|#
directive|define
name|sys_quotactl
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef TM_LINUX_H */
end_comment

end_unit

