begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for hosting on Windows32.    using GNU tools and the Windows32 API Library.    Copyright (C) 1997, 1998, 1999, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Even though we support "/", allow "\" since everybody tests both.  */
end_comment

begin_define
define|#
directive|define
name|DIR_SEPARATOR
value|'\\'
end_define

begin_define
define|#
directive|define
name|DIR_SEPARATOR_2
value|'/'
end_define

begin_comment
comment|/* Mingw32 does not try to hide the underlying DOS-based file system    like Cygwin does.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DOS_BASED_FILE_SYSTEM
end_define

begin_define
define|#
directive|define
name|HOST_EXECUTABLE_SUFFIX
value|".exe"
end_define

begin_undef
undef|#
directive|undef
name|PATH_SEPARATOR
end_undef

begin_define
define|#
directive|define
name|PATH_SEPARATOR
value|';'
end_define

end_unit

