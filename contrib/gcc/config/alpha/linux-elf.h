begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler    for Alpha Linux-based GNU systems using ELF.    Copyright (C) 1996, 1997 Free Software Foundation, Inc.    Contributed by Richard Henderson.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (Alpha GNU/Linux for ELF)");
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "elf_dynamic_linker", ELF_DYNAMIC_LINKER },
end_define

begin_undef
undef|#
directive|undef
name|SUB_CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|SUB_CPP_PREDEFINES
value|"-D__ELF__"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_define
define|#
directive|define
name|ELF_DYNAMIC_LINKER
value|"/lib/ld.so.1"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ELF_DYNAMIC_LINKER
value|"/lib/ld-linux.so.2"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_GNULIBC_1
end_ifndef

begin_undef
undef|#
directive|undef
name|DEFAULT_VTABLE_THUNKS
end_undef

begin_define
define|#
directive|define
name|DEFAULT_VTABLE_THUNKS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|USE_GNULIBC_1
end_ifndef

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{shared:-lc}%{!shared:%{pthread:-lpthread }%{profile:-lc_p}%{!profile:-lc}} "
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

