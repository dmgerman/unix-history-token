begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for native support of irix4.  Copyright (C) 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Let's use /debug instead of all this dangerous mucking about  * with ptrace(), which seems *extremely* fragile, anyway.  */
end_comment

begin_define
define|#
directive|define
name|USE_PROC_FS
end_define

begin_define
define|#
directive|define
name|PROC_NAME_FMT
value|"/debug/%d"
end_define

begin_comment
comment|/* Don't need special routines for the SGI -- we can use infptrace.c */
end_comment

begin_undef
undef|#
directive|undef
name|FETCH_INFERIOR_REGISTERS
end_undef

begin_define
define|#
directive|define
name|U_REGS_OFFSET
value|0
end_define

end_unit

