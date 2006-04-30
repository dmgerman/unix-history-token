begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Host-dependent definitions for any CPU running NetBSD.    Copyright 1993, 1994, 1995, 1996, 1999 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Include this to get things like NGROUPS which<limits.h> doesn't    define on some systems. */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* NetBSD has termios facilities. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS
end_define

end_unit

