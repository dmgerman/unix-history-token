begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for running gdb on a host machine running any flavor of SVR4.    Copyright 1991, 1992 Free Software Foundation, Inc.    Written by Fred Fish at Cygnus Support (fnf@cygnus.com).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Use SVR4 style shared library support */
end_comment

begin_define
define|#
directive|define
name|SVR4_SHARED_LIBS
end_define

begin_comment
comment|/* SVR4 has termio facilities. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_comment
comment|/* SVR4 has mmap facilities */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
end_define

begin_comment
comment|/* TIOCGETC and TIOCGLTC are picked up somewhere, but struct tchars    and struct ltchars are not.  This makes problems for inflow.c.    It is unknown at this time if this is a generic SVR4 problem or    one just limited to the initial SVR4 port host machine. */
end_comment

begin_define
define|#
directive|define
name|TIOCGETC_BROKEN
end_define

begin_define
define|#
directive|define
name|TIOCGLTC_BROKEN
end_define

begin_comment
comment|/* SVR4 is a derivative of System V Release 3 (USG) */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_comment
comment|/* #define SET_STACK_LIMIT_HUGE */
end_comment

begin_comment
comment|/* Use setpgid(0,0) to run inferior in a separate process group */
end_comment

begin_define
define|#
directive|define
name|NEED_POSIX_SETPGID
end_define

begin_comment
comment|/* We have to include these files now, so that GDB will not make    competing definitions in defs.h.  */
end_comment

begin_include
include|#
directive|include
file|<limits.h>
end_include

end_unit

