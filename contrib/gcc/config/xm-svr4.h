begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for hosts running System V Release 4    Copyright (C) 1988, 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_define
define|#
directive|define
name|POSIX
end_define

begin_comment
comment|/* SVR4 provides no sys_siglist,    but does offer the same data under another name.  */
end_comment

begin_define
define|#
directive|define
name|sys_siglist
value|_sys_siglist
end_define

begin_undef
undef|#
directive|undef
name|SYS_SIGLIST_DECLARED
end_undef

begin_define
define|#
directive|define
name|SYS_SIGLIST_DECLARED
end_define

end_unit

