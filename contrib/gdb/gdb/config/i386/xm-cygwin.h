begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for hosting on WIN32, for GDB.    Copyright 1995, 1996, 1997, 1998 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_include
include|#
directive|include
file|"fopen-bin.h"
end_include

begin_define
define|#
directive|define
name|GDBINIT_FILENAME
value|"gdb.ini"
end_define

begin_define
define|#
directive|define
name|SLASH_P
parameter_list|(
name|X
parameter_list|)
value|((X)=='\\' || (X) == '/')
end_define

begin_define
define|#
directive|define
name|ROOTED_P
parameter_list|(
name|X
parameter_list|)
value|((SLASH_P((X)[0]))|| ((X)[1] ==':'))
end_define

begin_define
define|#
directive|define
name|SLASH_CHAR
value|'/'
end_define

begin_define
define|#
directive|define
name|SLASH_STRING
value|"/"
end_define

begin_comment
comment|/* Define this if source files use \r\n rather than just \n.  */
end_comment

begin_define
define|#
directive|define
name|CRLF_SOURCE_FILES
end_define

begin_define
define|#
directive|define
name|HAVE_SIGSETMASK
value|0
end_define

end_unit

