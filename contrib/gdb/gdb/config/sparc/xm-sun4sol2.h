begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for running gdb on a Sun 4 running Solaris 2.    Copyright 1989, 1992, 1993, 1994, 1995, 1996, 1998, 2000    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Pick up more stuff from the generic SVR4 host include file. */
end_comment

begin_include
include|#
directive|include
file|"xm-sysv4.h"
end_include

begin_comment
comment|/* These are not currently used in SVR4 (but should be, FIXME!).  */
end_comment

begin_undef
undef|#
directive|undef
name|DO_DEFERRED_STORES
end_undef

begin_undef
undef|#
directive|undef
name|CLEAR_DEFERRED_STORES
end_undef

begin_comment
comment|/* solaris doesn't have siginterrupt, though it has sigaction; however,    in this case siginterrupt would just be setting the default. */
end_comment

begin_define
define|#
directive|define
name|NO_SIGINTERRUPT
end_define

begin_comment
comment|/* On sol2.7,<curses.h> emits a bunch of 'macro redefined'    warnings, which makes autoconf think curses.h doesn't    exist.  Compensate for that here. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CURSES_H
value|1
end_define

end_unit

