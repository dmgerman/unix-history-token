begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for a little endian PowerPC    running System V.4    Copyright (C) 1995, 2000 Free Software Foundation, Inc.    Contributed by Cygnus Support.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
name|CPP_ENDIAN_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_ENDIAN_DEFAULT_SPEC
value|"%(cpp_endian_little)"
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

begin_comment
comment|/* Define this macro as a C expression for the initializer of an    array of string to tell the driver program which options are    defaults for this target and thus do not need to be handled    specially when using `MULTILIB_OPTIONS'.     Do not define this macro if `MULTILIB_OPTIONS' is not defined in    the target makefile fragment or if none of the options listed in    `MULTILIB_OPTIONS' are set by default.  *Note Target Fragment::.  */
end_comment

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

