begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GCC for a little endian PowerPC    running System V.4    Copyright (C) 1995, 2000, 2003 Free Software Foundation, Inc.    Contributed by Cygnus Support.     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_POWERPC | MASK_NEW_MNEMONICS | MASK_LITTLE_ENDIAN)
end_define

begin_undef
undef|#
directive|undef
name|CC1_ENDIAN_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_ENDIAN_DEFAULT_SPEC
value|"%(cc1_endian_little)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_TARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_TARGET_SPEC
value|"\ %{mbig: --oformat elf32-powerpc } %{mbig-endian: --oformat elf32-powerpc } \ %{!mlittle: %{!mlittle-endian: %{!mbig: %{!mbig-endian: \     %{mcall-linux: --oformat elf32-powerpc} \   }}}}"
end_define

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "mlittle", "mcall-sysv" }
end_define

end_unit

