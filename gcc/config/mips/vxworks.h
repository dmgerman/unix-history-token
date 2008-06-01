begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1999, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
value|fprintf (stderr, " (MIPS, VxWorks syntax)");
end_define

begin_comment
comment|/* Combination of mips.h and svr4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR)      \    || (CHAR) == 'G'                     \    || (CHAR) == 'h'                     \    || (CHAR) == 'x'                     \    || (CHAR) == 'z')
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{!G:-G 0} %{G*} %(endian_spec) %{mips1} %{mips2} %{mips3} %{mips4} \ %{mips32} %{mips32r2} %{mips64} \ %{mips16:%{!mno-mips16:-mips16}} %{mno-mips16:-no-mips16} \ %(subtarget_asm_optimizing_spec) \ %(subtarget_asm_debugging_spec) \ %{mabi=*} %{!mabi*: %(asm_abi_default_spec)} \ %{mgp32} %{mgp64} %{march=*} %{mxgot:-xgot} \ %{mtune=*} %{v} \ %(subtarget_asm_spec)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_comment
comment|/* LINK_SPEC is clobbered in svr4.h. ugh!  */
end_comment

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\ %(endian_spec) \ %{!G:-G 0} %{G*} %{mips1} %{mips2} %{mips3} %{mips4} %{mips32} %{mips64} \ %{bestGnum}"
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do                                                    \     {                                                   \       builtin_define ("__vxworks");                     \       builtin_assert ("system=unix");                   \     }                                                   \   while (0)
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
define|\
value|"%{!DCPU=*: %{mips3|mips4|mips64:-DCPU=MIPS64;:-DCPU=MIPS32}} \   %{EL|mel:-DMIPSEL;:-DMIPSEB} \   %{msoft-float:-DSOFT_FLOAT} \   %{mips1:-D_WRS_R3K_EXC_SUPPORT}"
end_define

begin_comment
comment|/* No sdata.  */
end_comment

begin_undef
undef|#
directive|undef
name|MIPS_DEFAULT_GVALUE
end_undef

begin_define
define|#
directive|define
name|MIPS_DEFAULT_GVALUE
value|0
end_define

end_unit

