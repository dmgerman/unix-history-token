begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler    for Alpha NetBSD systems using ELF.    Copyright (C) 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
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
value|fprintf (stderr, " (Alpha NetBSD/ELF)");
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

begin_define
define|#
directive|define
name|ELF_DYNAMIC_LINKER
value|"/usr/libexec/ld.elf_so"
end_define

end_unit

