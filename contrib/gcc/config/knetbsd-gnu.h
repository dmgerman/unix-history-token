begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for kNetBSD-based GNU systems with ELF format    Copyright (C) 2004, 2006    Free Software Foundation, Inc.    Contributed by Robert Millan.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINUX_TARGET_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|LINUX_TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\ 	builtin_define ("__NetBSD_kernel__");	\ 	builtin_define ("__GLIBC__");		\ 	builtin_define_std ("unix");		\ 	builtin_assert ("system=unix");		\ 	builtin_assert ("system=posix");	\     }						\   while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|GLIBC_DYNAMIC_LINKER
end_ifdef

begin_undef
undef|#
directive|undef
name|GLIBC_DYNAMIC_LINKER
end_undef

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER
value|"/lib/ld.so.1"
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

