begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on Mach on an Intel 386    Copyright (C) 1986, 1987, 1989, 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_comment
comment|/* Avoid "INT_MIN redefined" warnings -- by defining it here, exactly    the same as in the system<machine/machtypes.h> file.  */
end_comment

begin_undef
undef|#
directive|undef
name|INT_MIN
end_undef

begin_define
define|#
directive|define
name|INT_MIN
value|0x80000000
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
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|(0x80000000 - (UPAGES * NBPG))
end_define

begin_define
define|#
directive|define
name|BROKEN_LARGE_ALLOCA
end_define

begin_define
define|#
directive|define
name|PREPARE_TO_STORE
parameter_list|()
value|read_register_bytes (0, NULL, REGISTER_BYTES)
end_define

begin_comment
comment|/*<errno.h> only defines this if __STDC__!!! */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|strdup
parameter_list|()
function_decl|;
end_function_decl

end_unit

