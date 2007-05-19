begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for RTEMS based ARM systems using ELF    Copyright (C) 2000, 2002, 2005 Free Software Foundation, Inc.      This file is part of GCC.      GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.      GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.      You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.  If not, write to    the Free Software Foundation, 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Run-time Target Specification.  */
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
value|fputs (" (ARM/ELF RTEMS)", stderr);
end_define

begin_define
define|#
directive|define
name|HAS_INIT_SECTION
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {					\ 	builtin_define ("__rtems__");		\ 	builtin_assert ("system=rtems");	\     } while (0)
end_define

begin_comment
comment|/*  * The default in gcc now is soft-float, but gcc misses it to   * pass it to the assembler.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_ASM_SPEC
value|"\   %{!mhard-float: %{!msoft-float:-mfpu=softfpa}}"
end_define

begin_comment
comment|/*  *  The default includes --start-group and --end-group which conflicts  *  with how this used to be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_GCC_C_SEQUENCE_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_GCC_C_SEQUENCE_SPEC
value|"%G %L"
end_define

end_unit

