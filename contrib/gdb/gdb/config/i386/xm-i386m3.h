begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on Mach 3 on an Intel 386    Copyright (C) 1986, 1987, 1989, 1991 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* Do implement the attach and detach commands.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_DETACH
value|1
end_define

begin_comment
comment|/* Not needeed */
end_comment

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|EMULATOR_BASE
end_ifndef

begin_comment
comment|/* For EMULATOR_BASE and EMULATOR_END.  * OSF 1/MK has different values in some other place.  */
end_comment

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EMULATOR_BASE */
end_comment

end_unit

