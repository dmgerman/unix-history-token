begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for i386 running System V (pre-SVR4).     Copyright 1986, 1987, 1989, 1992, 1993, 1998, 2000, 2002    Free Software Foundation, Inc.    Changes for 80386 by Pace Willisson (pace@prep.ai.mit.edu), July 1988.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_I386V_H
end_ifndef

begin_define
define|#
directive|define
name|NM_I386V_H
end_define

begin_comment
comment|/* Support for the user struct.  */
end_comment

begin_comment
comment|/* This is the amount to subtract from u.u_ar0    to get the offset in the core file of the register values.  */
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
name|regnum
parameter_list|)
define|\
value|(addr) = register_u_addr ((blockend), (regnum))
end_define

begin_function_decl
specifier|extern
name|CORE_ADDR
name|register_u_addr
parameter_list|(
name|CORE_ADDR
name|blockend
parameter_list|,
name|int
name|regnum
parameter_list|)
function_decl|;
end_function_decl

begin_escape
end_escape

begin_comment
comment|/* Number of traps that happen between exec'ing the shell to run an    inferior, and when we finally get to the inferior code.  This is 2    on most implementations.  Override here to 4.  */
end_comment

begin_undef
undef|#
directive|undef
name|START_INFERIOR_TRAPS_EXPECTED
end_undef

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nm-i386v.h */
end_comment

end_unit

