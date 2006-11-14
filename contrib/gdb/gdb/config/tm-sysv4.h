begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for GDB on all SVR4 target systems.    Copyright 1991, 1992, 1993, 1994, 1996, 1997, 2000    Free Software Foundation, Inc.    Written by Fred Fish at Cygnus Support (fnf@cygnus.com).     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* For SVR4 shared libraries, each call to a library routine goes through    a small piece of trampoline code in the ".plt" section.    The horribly ugly wait_for_inferior() routine uses this macro to detect    when we have stepped into one of these fragments.    We do not use lookup_solib_trampoline_symbol_by_pc, because    we cannot always find the shared library trampoline symbols    (e.g. on Irix5).  */
end_comment

begin_define
define|#
directive|define
name|IN_SOLIB_CALL_TRAMPOLINE
parameter_list|(
name|pc
parameter_list|,
name|name
parameter_list|)
value|in_plt_section((pc), (name))
end_define

begin_function_decl
specifier|extern
name|int
name|in_plt_section
parameter_list|(
name|CORE_ADDR
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* If PC is in a shared library trampoline code, return the PC    where the function itself actually starts.  If not, return 0.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_TRAMPOLINE_CODE
parameter_list|(
name|pc
parameter_list|)
value|find_solib_trampoline_target (pc)
end_define

end_unit

