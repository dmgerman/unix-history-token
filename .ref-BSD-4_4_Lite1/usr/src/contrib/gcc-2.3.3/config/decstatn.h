begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  DECstation (ultrix) version.    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|DECSTATION
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_PREDEFINES
end_ifndef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__ANSI_COMPAT \ -DMIPSEL -DR3000 -DSYSTYPE_BSD -D_SYSTYPE_BSD -Dbsd4_2 -Dhost_mips -Dmips -Dultrix -Dunix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_SPEC
end_ifndef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{!mgas: \ 	%{!mrnames: %{!.s:-nocpp} %{.s: %{cpp} %{nocpp}}} \ 	%{pipe:%e:-pipe not supported} \ 	%{EL} %{!EL:-EL} \ 	%{EB: %e-EB not supported} \ 	%{mips1} %{mips2} %{mips3} \ 	%{O:-O2} %{O1:-O2} %{O2:-O2} %{O3:-O3} \ 	%{g} %{g0} %{g1} %{g2} %{g3} %{v} %{K}} \ %{G*}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CPP_SPEC
end_ifndef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{.S:	-D__LANGUAGE_ASSEMBLY__ -D__LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY}} \ %{.cc:	-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS} \ %{.cxx:	-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS} \ %{.C:	-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS} \ %{.m:	-D__LANGUAGE_OBJECTIVE_C__ -D__LANGUAGE_OBJECTIVE_C} \ %{!.S:	-D__LANGUAGE_C__  -D__LANGUAGE_C %{!ansi:-DLANGUAGE_C}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %{G*} \ %{!mgas: \ 	%{EL} %{!EL: -EL} \ 	%{EB: %e-EB not supported} \ 	%{mips1} %{mips2} %{mips3} \ 	%{bestGnum}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{p:-lprof1} %{pg:-lprof1} -lc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STARTFILE_SPEC
end_ifndef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For compatibility with types.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIZE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MACHINE_TYPE
end_ifndef

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"DECstation running ultrix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use atexit for static constructors/destructors, instead of defining    our own exit function.  Ultrix 4.x has this, 3.x probably does not.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Generate calls to memcpy, etc., not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_include
include|#
directive|include
file|"mips.h"
end_include

end_unit

