begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Configuration file for sparc64 OpenBSD target.    Copyright (C) 1999 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|fprintf (stderr, " (sparc64 OpenBSD ELF)")
end_define

begin_comment
comment|/* XXX - do we really want HARD_QUAD? */
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
define|\
value|(MASK_V9 + MASK_PTR64 + MASK_64BIT + MASK_HARD_QUAD \  + MASK_APP_REGS + MASK_FPU + MASK_STACK_BIAS + MASK_LONG_DOUBLE_128)
end_define

begin_undef
undef|#
directive|undef
name|SPARC_DEFAULT_CMODEL
end_undef

begin_define
define|#
directive|define
name|SPARC_DEFAULT_CMODEL
value|CM_MEDMID
end_define

begin_comment
comment|/* Target OS builtins.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\ 	builtin_define ("__unix__");		\ 	builtin_define ("__OpenBSD__");		\ 	builtin_assert ("system=unix");		\ 	builtin_assert ("system=OpenBSD");	\ 	builtin_define ("__sparc64__");		\ 	builtin_define ("__sparcv9__");		\ 	builtin_define ("__sparc_v9__");	\ 	builtin_define ("__arch64__");		\     }						\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|CPP_SUBTARGET_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SUBTARGET_SPEC
value|""
end_define

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"\ %{v:-V} -s %{fpic|fPIC|fpie|fPIE:-K PIC} \ %{mlittle-endian:-EL} \ %(asm_cpu) %(asm_arch) \ "
end_define

begin_comment
comment|/* Layout of source language data types.  */
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
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|128
end_define

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
value|"%{!shared:%{!nostdlib:%{!r*:%{!e*:-e __start}}}} \    %{shared:-shared} %{R*} \    %{static:-Bstatic} \    %{!static:-Bdynamic} \    %{assert*} \    %{!dynamic-linker:-dynamic-linker /usr/libexec/ld.so}"
end_define

begin_comment
comment|/* As an elf system, we need crtbegin/crtend stuff.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"\         %{!shared: %{pg:gcrt0%O%s} %{!pg:%{p:gcrt0%O%s} %{!p:crt0%O%s}} \         crtbegin%O%s} %{shared:crtbeginS%O%s}"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"%{!shared:crtend%O%s} %{shared:crtendS%O%s}"
end_define

end_unit

