begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on an Intel i386 running SVR4.2MP    Copyright (C) 1991, 1994 Free Software Foundation, Inc.    Written by Fred Fish at Cygnus Support (fnf@cygnus.com)  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386V42MP_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386V42MP_H
value|1
end_define

begin_comment
comment|/* pick up more generic x86 sysv4 stuff */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386v4.h"
end_include

begin_comment
comment|/* procfs on this architecture has multiple fds (ctl, as, map, status) 	including a control fd */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_MULTIPLE_PROC_FDS
end_ifndef

begin_define
define|#
directive|define
name|HAVE_MULTIPLE_PROC_FDS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* procfs on this architecture communicates with read/write instead 	of ioctl */
end_comment

begin_define
define|#
directive|define
name|PROCFS_USE_READ_WRITE
end_define

begin_comment
comment|/* define to select for other sysv4.2mp weirdness */
end_comment

begin_define
define|#
directive|define
name|UNIXWARE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ifndef TM_I386V42MP_H */
end_comment

end_unit

