begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for running gdb on a Sun 4 running sunos 4.    Copyright (C) 1989, Free Software Foundation, Inc.  This file is part of GDB.  GDB is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 1, or (at your option) any later version.  GDB is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GDB; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"m-sparc.h"
end_include

begin_undef
undef|#
directive|undef
name|STACK_END_ADDRESS
end_undef

begin_define
define|#
directive|define
name|STACK_END_ADDRESS
value|0xf8000000
end_define

begin_define
define|#
directive|define
name|SUNOS4
end_define

begin_define
define|#
directive|define
name|FPU
end_define

end_unit

