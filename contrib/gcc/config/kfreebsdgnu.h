begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for GNU/KFreeBSD systems with ELF format.    Copyright (C) 2002 Free Software Foundation, Inc.    Contributed by Bruno Haible.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_OS_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|builtin_define ("__GNU_KFreeBSD__=0");		\   builtin_define ("__gnu_kfreebsd__=0");		\   builtin_define ("__FreeBSD_kernel__=5");		\   builtin_define ("__ELF__");				\   builtin_define_std ("unix");				\   builtin_assert ("system=posix");
end_define

begin_undef
undef|#
directive|undef
name|TARGET_CPU_CPP_BUILTINS
end_undef

begin_define
define|#
directive|define
name|TARGET_CPU_CPP_BUILTINS
parameter_list|()
define|\
value|builtin_define ("__i386__");				\   builtin_define_std ("i386");				\   builtin_assert ("cpu=i386");				\   builtin_assert ("machine=i386");
end_define

begin_comment
comment|/* do {} while (0) */
end_comment

end_unit

