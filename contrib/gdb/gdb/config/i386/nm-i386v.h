begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for i386.    Copyright 1986, 1987, 1989, 1992 Free Software Foundation, Inc.    Changes for 80386 by Pace Willisson (pace@prep.ai.mit.edu), July 1988.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* code to execute to print interesting information about the    floating point processor (if any)    No need to define if there is nothing to do.    On the 386, unfortunately this code is host-dependent (and lives    in the i386-xdep.c file), so we can't    do this unless we *know* we aren't cross-debugging.  FIXME.  */
end_comment

begin_define
define|#
directive|define
name|FLOAT_INFO
value|{ i386_float_info (); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*0*/
end_comment

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|(addr) = i386_register_u_addr ((blockend),(regno));
end_define

begin_decl_stmt
specifier|extern
name|int
name|i386_register_u_addr
name|PARAMS
argument_list|(
operator|(
name|int
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

