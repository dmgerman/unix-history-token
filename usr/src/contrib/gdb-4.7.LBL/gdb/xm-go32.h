begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for hosting on GO32, for GDB.    Copyright 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|EIO
end_undef

begin_define
define|#
directive|define
name|EIO
value|0
end_define

begin_define
define|#
directive|define
name|SYS_SIGLIST_MISSING
value|1
end_define

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

begin_comment
comment|/* Define this lseek(n) != nth byte of file */
end_comment

begin_define
define|#
directive|define
name|LSEEK_NOT_LINEAR
end_define

end_unit

