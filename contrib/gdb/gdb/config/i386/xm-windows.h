begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for hosting on WIN32, built with Microsoft Visual C/C++, for GDB.    Copyright 1996, 1998 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/xm-cygwin.h"
end_include

begin_undef
undef|#
directive|undef
name|PRINTF_HAS_LONG_LONG
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_UNISTD_H
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_TERMIO_H
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_TERMIOS_H
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_SGTTY_H
end_undef

begin_undef
undef|#
directive|undef
name|HAVE_SBRK
end_undef

begin_define
define|#
directive|define
name|CANT_FORK
end_define

begin_define
define|#
directive|define
name|MALLOC_INCOMPATIBLE
end_define

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_define
define|#
directive|define
name|SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|SIGTRAP
value|5
end_define

end_unit

