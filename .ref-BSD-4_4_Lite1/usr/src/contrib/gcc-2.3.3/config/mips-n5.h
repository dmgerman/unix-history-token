begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.  Sony RISC NEWS (mips) System V version.    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|MIPS_SYSV
end_define

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dmips -Dunix -Dhost_mips -Dsony -Dsonyrisc -DMIPSEB -DSYSTYPE_SYSV"
end_define

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/ccs/lib/"
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
value|"\ %{G*} \ %{!mgas: %{mips1} %{mips2} %{mips3} \ 	 %{EB} %{!EB:-EB} %{EL: %e-EL not supported} \ 	 %{bestGnum} %{shared} %{non_shared}}"
end_define

begin_define
define|#
directive|define
name|LIB_SPEC
value|"\ %{ZBSD43: -L/usr/ucblib -lucb -lresolv -lsocket -lnsl} \ -nocount %{p:-lprof1} %{pg:-lprof1} -lc crtn.o%s values-Xt.o%s"
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{pg:gcrt0.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:-nocount crt1.o%s -count}}"
end_define

begin_define
define|#
directive|define
name|MACHINE_TYPE
value|"Sony RISC NEWS (SVR4 mips)"
end_define

begin_define
define|#
directive|define
name|NO_LIB_PROTOTYPE
end_define

begin_define
define|#
directive|define
name|NO_DOLLAR_IN_LABEL
end_define

begin_define
define|#
directive|define
name|NM_FLAGS
value|"-Bp"
end_define

begin_comment
comment|/* Generate calls to memcpy, etc., not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Mips System V.4 doesn't have a getpagesize() function needed by the    trampoline code, so use the POSIX sysconf function to get it.    This is only done when compiling the trampoline code.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|L_trampoline
end_ifdef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|_SC_PAGE_SIZE
end_ifdef

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|sysconf(_SC_PAGE_SIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* older rev of OS */
end_comment

begin_define
define|#
directive|define
name|getpagesize
parameter_list|()
value|(NBPC)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SC_PAGE_SIZE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  L_trampoline */
end_comment

begin_include
include|#
directive|include
file|"mips.h"
end_include

end_unit

