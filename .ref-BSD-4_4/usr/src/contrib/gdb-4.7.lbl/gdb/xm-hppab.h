begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parameters for hosting on an HPPA PA-RISC machine, running BSD, for GDB.    Copyright 1991, 1992 Free Software Foundation, Inc.      Contributed by the Center for Software Science at the    University of Utah (pa-gdb-bugs@cs.utah.edu).  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This is a big-endian host.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
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

begin_ifndef
ifndef|#
directive|ifndef
name|hp800
end_ifndef

begin_define
define|#
directive|define
name|USG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|SEEK_SET
end_ifndef

begin_define
define|#
directive|define
name|SEEK_SET
value|0
end_define

begin_comment
comment|/* Set file pointer to "offset" */
end_comment

begin_define
define|#
directive|define
name|SEEK_CUR
value|1
end_define

begin_comment
comment|/* Set file pointer to current plus "offset" */
end_comment

begin_define
define|#
directive|define
name|SEEK_END
value|2
end_define

begin_comment
comment|/* Set file pointer to EOF plus "offset" */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SEEK_SET */
end_comment

end_unit

