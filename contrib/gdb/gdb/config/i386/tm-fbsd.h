begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target macro definitions for i386 running FreeBSD    Copyright (C) 1997 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386bsd.h"
end_include

begin_undef
undef|#
directive|undef
name|NUM_REGS
end_undef

begin_define
define|#
directive|define
name|NUM_REGS
value|14
end_define

begin_undef
undef|#
directive|undef
name|IN_SOLIB_CALL_TRAMPOLINE
end_undef

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|STREQ (name, "_DYNAMIC")
end_define

begin_extern
extern|extern i386_float_info (
end_extern

begin_empty_stmt
unit|)
empty_stmt|;
end_empty_stmt

begin_define
define|#
directive|define
name|FLOAT_INFO
value|i386_float_info ()
end_define

end_unit

