begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GCC for hosting on Windows32.    using GNU tools and the Windows32 API Library.    Copyright (C) 1997, 1998, 1999, 2001, 2002, 2003, 2004 Free Software    Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

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

begin_comment
comment|/* This is the name of the null device on windows.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BIT_BUCKET
value|"nul"
end_define

begin_comment
comment|/*  The st_ino field of struct stat is always 0.  */
end_comment

begin_define
define|#
directive|define
name|HOST_LACKS_INODE_NUMBERS
end_define

begin_comment
comment|/* MSVCRT does not support the "ll" format specifier for printing    "long long" values.  Instead, we use "I64".  */
end_comment

begin_define
define|#
directive|define
name|HOST_LONG_LONG_FORMAT
value|"I64"
end_define

end_unit

