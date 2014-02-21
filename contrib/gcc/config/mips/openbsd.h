begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration for  a MIPS ABI32 OpenBSD target.    Copyright (C) 1999, 2003, 2004 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Definitions needed for OpenBSD, to avoid picking mips 'defaults'.  */
end_comment

begin_comment
comment|/* GAS must know this.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_ASM_SPEC
value|"%{fPIC|fPIE:-KPIC}"
end_define

begin_define
define|#
directive|define
name|AS_NEEDS_DASH_FOR_PIPED_INPUT
end_define

begin_comment
comment|/* CPP specific OpenBSD specs.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_CPP_SPEC
value|OBSD_CPP_SPEC
end_define

begin_comment
comment|/* Needed for ELF (inspired by netbsd-elf).  */
end_comment

begin_undef
undef|#
directive|undef
name|LOCAL_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* The profiling lib spec here is not really correct but we leave    it as it is until we have some kind of profiling working.  */
end_comment

begin_define
define|#
directive|define
name|LIB_SPEC
value|OBSD_LIB_SPEC
end_define

begin_comment
comment|/* mips assembler uses .set for arcane purposes.  __attribute__((alias))    and friends won't work until we get recent binutils with .weakext 	support.  */
end_comment

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {						\ 	builtin_define ("__unix__");			\ 	builtin_define ("__SYSTYPE_BSD__");		\ 	builtin_define ("__NO_LEADING_UNDERSCORES__");	\ 	builtin_define ("__GP_SUPPORT__");		\ 	builtin_define ("__OpenBSD__");			\ 	builtin_assert ("system=unix");			\ 	builtin_assert ("system=OpenBSD");		\ } while (0)
end_define

begin_comment
comment|/* Layout of source language data types.  */
end_comment

begin_comment
comment|/* This must agree with<machine/ansi.h>.  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

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
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* Controlling the compilation driver.  */
end_comment

begin_comment
comment|/* LINK_SPEC appropriate for OpenBSD:  support for GCC options    -static, -assert, and -nostdlib. Dynamic loader control.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{G*} %{EB} %{EL} %{mips1} %{mips2} %{mips3} \    %{bestGnum} %{shared} %{non_shared} \    %{call_shared} %{no_archive} %{exact_version} \    %{!shared: %{!non_shared: %{!call_shared: -non_shared}}} \    %{!dynamic-linker:-dynamic-linker /usr/libexec/ld.so} \    %{!nostdlib:%{!r*:%{!e*:-e __start}}} -dc -dp \    %{static:-Bstatic} %{!static:-Bdynamic} %{assert*}"
end_define

begin_comment
comment|/* -G is incompatible with -KPIC which is the default, so only allow objects    in the small data section if the user explicitly asks for it.  */
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

begin_comment
comment|/* Since gas and gld are standard on OpenBSD, we don't need these.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ASM_NAMED_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|default_elf_asm_named_section
end_define

end_unit

