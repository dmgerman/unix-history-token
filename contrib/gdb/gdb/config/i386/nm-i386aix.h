begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for i386 aix ps/2.    Copyright 1986, 1987, 1989, 1992, 1993 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  * Changes for IBM AIX PS/2 by Minh Tran-Le (tranle@intellicorp.com)  * Revision:	 5-May-93 00:11:35  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_I386AIX_H
end_ifndef

begin_define
define|#
directive|define
name|NM_I386AIX_H
value|1
end_define

begin_comment
comment|/* code to execute to print interesting information about the  * floating point processor (if any)  * No need to define if there is nothing to do.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_INFO
value|{ i386_float_info (); }
end_define

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
end_comment

begin_undef
undef|#
directive|undef
name|KERNEL_U_ADDR
end_undef

begin_define
define|#
directive|define
name|KERNEL_U_ADDR
value|0xf03fd000
end_define

begin_comment
comment|/* Override copies of {fetch,store}_inferior_registers in infptrace.c.  */
end_comment

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NM_I386AIX_H */
end_comment

end_unit

