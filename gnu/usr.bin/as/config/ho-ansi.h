begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ho-ansi.h  Host-specific header file for generic ansi environments.    Copyright (C) 1987, 1991, 1992 Free Software Foundation, Inc.     This file is part of GAS, the GNU Assembler.     GAS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GAS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GAS; see the file COPYING.  If not, write to    the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|M_ANSI
value|1
end_define

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<memory.h>
end_include

begin_define
define|#
directive|define
name|sys_nerr
value|_sys_nerr
end_define

begin_define
define|#
directive|define
name|sys_errlist
value|_sys_errlist
end_define

begin_comment
comment|/* end of ho-ansi.h */
end_comment

end_unit

