begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for SunOS 4.x    Copyright (C) 1994, 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUNOS4_SHARED_LIBRARIES
end_undef

begin_define
define|#
directive|define
name|SUNOS4_SHARED_LIBRARIES
value|1
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dsparc -Dsun -Dunix -Asystem=unix -Asystem=bsd"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!shared:%{!p:%{!pg:-lc}}%{p:-lc_p}%{pg:-lc_p} %{g:-lg}}"
end_define

begin_comment
comment|/* Provide required defaults for linker -e and -d switches.  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{!shared:%{!nostdlib:%{!r*:%{!e*:-e start}}} -dc -dp} %{static:-Bstatic} \   %{assert*} %{shared:%{!mimpure-text:-assert pure-text}}"
end_define

begin_comment
comment|/* Use N_BINCL stabs.  */
end_comment

begin_define
define|#
directive|define
name|DBX_USE_BINCL
end_define

begin_comment
comment|/* The Sun as doesn't like unaligned data.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_comment
comment|/* SunOS has on_exit instead of atexit.  */
end_comment

begin_comment
comment|/* The man page says it returns int.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|on_exit
name|PARAMS
argument_list|(
operator|(
name|void
operator|*
operator|,
name|void
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ON_EXIT
parameter_list|(
name|FUNC
parameter_list|)
value|on_exit ((FUNC), 0)
end_define

begin_define
define|#
directive|define
name|NEED_ATEXIT
end_define

end_unit

