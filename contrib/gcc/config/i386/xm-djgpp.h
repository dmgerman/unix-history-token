begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for Intel 80386 running DJGPP.    Copyright (C) 1988, 1996, 1998, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|__MSDOS__
value|1
end_define

begin_include
include|#
directive|include
file|"i386/xm-i386.h"
end_include

begin_comment
comment|/* Use semicolons to separate elements of a path.  */
end_comment

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|';'
end_define

begin_define
define|#
directive|define
name|EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_comment
comment|/* Even though we support "/", allow "\" since everybody tests both.  */
end_comment

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'/'
end_define

begin_define
define|#
directive|define
name|DIR_SEPARATOR_2
value|'\\'
end_define

begin_comment
comment|/* Allow test for DOS drive names.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DOS_BASED_FILESYSTEM
end_define

begin_define
define|#
directive|define
name|LIBSTDCXX
value|"-lstdcxx"
end_define

begin_comment
comment|/* System dependant initialization for collect2    to tell system() to act like Unix.  */
end_comment

begin_define
define|#
directive|define
name|COLLECT2_HOST_INITIALIZATION
define|\
value|do { __system_flags |= (__system_allow_multiple_cmds			\ 		          | __system_emulate_chdir); } while (0)
end_define

end_unit

