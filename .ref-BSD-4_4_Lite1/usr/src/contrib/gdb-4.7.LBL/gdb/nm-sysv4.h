begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for running gdb on a host machine running any flavor of SVR4.    Copyright 1991, 1992 Free Software Foundation, Inc.    Written by Fred Fish at Cygnus Support (fnf@cygnus.com).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* SVR4 has /proc support, so use it instead of ptrace. */
end_comment

begin_define
define|#
directive|define
name|USE_PROC_FS
end_define

begin_comment
comment|/* SVR4 machines can easily do attach and detach via /proc (procfs.c)    support */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

end_unit

