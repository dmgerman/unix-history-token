begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for GNU C-compiler for standard 32-bit host machine.    Copyright (C) 1997 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* #defines that need visibility everywhere.  */
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_comment
comment|/* This describes the machine the compiler is hosted on.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BITS_PER_CHAR
value|8
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_SHORT
value|16
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_INT
value|32
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|32
end_define

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONGLONG
value|64
end_define

begin_comment
comment|/* Arguments to use with `exit'.  */
end_comment

begin_define
define|#
directive|define
name|SUCCESS_EXIT_CODE
value|0
end_define

begin_define
define|#
directive|define
name|FATAL_EXIT_CODE
value|33
end_define

end_unit

