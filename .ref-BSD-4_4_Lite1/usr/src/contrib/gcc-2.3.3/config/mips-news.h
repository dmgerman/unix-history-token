begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Sony RISC NEWS (mips)    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_NEWS
end_define

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dr3000 -Dnews3700 -DLANGUAGE_C -DMIPSEB -DSYSTYPE_BSD \ -Dsony_news -Dsony -Dunix -Dmips -Dhost_mips"
end_define

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{!mgas: \ 	%{!mrnames: %{!.s:-nocpp} %{.s: %{cpp} %{nocpp}}} \ 	%{pipe:%e:-pipe not supported} \ 	%{EB} %{!EB:-EB} \ 	%{EL: %e-EL not supported} \ 	%{mips1} %{mips2} %{mips3} \ 	%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3} \ 	%{g} %{g1} %{g2} %{g3} %{g0} %{v} %{K}} \ %{G*}"
end_define

begin_define
define|#
directive|define
name|SYSTEM_INCLUDE_DIR
value|"/usr/include2.0"
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{.cc:	-D__LANGUAGE_C_PLUS_PLUS -D_LANGUAGE_C_PLUS_PLUS} \ %{.cxx:	-D__LANGUAGE_C_PLUS_PLUS -D_LANGUAGE_C_PLUS_PLUS} \ %{.C:	-D__LANGUAGE_C_PLUS_PLUS -D_LANGUAGE_C_PLUS_PLUS} \ %{.m:	-D__LANGUAGE_OBJECTIVE_C -D_LANGUAGE_OBJECTIVE_C} \ %{.S:	-D__LANGUAGE_ASSEMBLY -D_LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY}} \ %{!.S:	-D__LANGUAGE_C -D_LANGUAGE_C %{!ansi:-DLANGUAGE_C}}"
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %{G*} \ %{!mgas: \ 	%{EB} %{!EB:-EB} \ 	%{EL: %e-EL not supported} \ 	%{mips1} %{mips2} %{mips3} \ 	%{bestGnum}}"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-lprof1} %{pg:-lprof1} -lc"
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"RISC NEWS-OS"
end_define

begin_include
include|#
directive|include
file|"mips.h"
end_include

end_unit

