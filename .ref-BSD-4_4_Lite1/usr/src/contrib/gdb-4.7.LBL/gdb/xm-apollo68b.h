begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro defintions for an Apollo 68k in BSD mode    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_define
define|#
directive|define
name|ALIGN_STACK_ON_STARTUP
end_define

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_define
define|#
directive|define
name|PTRACE_IN_WRONG_PLACE
end_define

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

end_unit

