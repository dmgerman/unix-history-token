begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for execution on a Sun 4, for GDB, the GNU debugger.    Copyright 1986, 1987, 1989, 1991, 1992 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@mcc.com).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* Get rid of any system-imposed stack limit if possible.  */
end_comment

begin_define
define|#
directive|define
name|SET_STACK_LIMIT_HUGE
end_define

begin_comment
comment|/* Enable use of alternate code for Sun's format of core dump file.  */
end_comment

begin_define
define|#
directive|define
name|NEW_SUN_CORE
end_define

begin_comment
comment|/* Before storing, we need to read all the registers.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PREPARE_TO_STORE
parameter_list|()
value|read_register_bytes (0, NULL, REGISTER_BYTES)
end_define

begin_comment
comment|/* It does have a wait structure, and it might help things out . . . */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAIT_STRUCT
end_define

end_unit

