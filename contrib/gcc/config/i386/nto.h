begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running QNX/Neutrino.    Copyright (C) 2002, 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PCC_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|1
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (QNX/Neutrino/i386 ELF)");
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
value|do						\     {						\         builtin_define_std ("__X86__");		\         builtin_define_std ("__QNXNTO__");	\         builtin_define_std ("__QNX__");		\         builtin_define_std ("__ELF__");		\         builtin_define_std ("__LITTLEENDIAN__");\         builtin_assert ("system=qnx");		\         builtin_assert ("system=qnxnto");	\         builtin_assert ("system=nto");		\         builtin_assert ("system=unix");		\     }						\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|THREAD_MODEL_SPEC
end_undef

begin_define
define|#
directive|define
name|THREAD_MODEL_SPEC
value|"posix"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_DIRECTORY_STRUCTURE
end_ifdef

begin_define
define|#
directive|define
name|SYSROOT_SUFFIX_SPEC
value|"x86"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: \   %{!symbolic: \     %{pg:mcrt1.o%s} \     %{!pg:%{p:mcrt1.o%s} \     %{!p:crt1.o%s}}}} \ crti.o%s \ %{fexceptions: crtbegin.o%s} \ %{!fexceptions: %R/lib/crtbegin.o}"
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
define|\
value|"crtend.o%s crtn.o%s"
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
value|"%{h*} %{v:-V} \    %{b} \    %{static:-dn -Bstatic} \    %{shared:-G -dy -z text} \    %{symbolic:-Bsymbolic -G -dy -z text} \    %{G:-G} \    %{YP,*} \    %{!YP,*:%{p:-Y P,%R/lib} \     %{!p:-Y P,%R/lib}} \    %{Qy:} %{!Qn:-Qy} \    -m i386nto \    %{!shared: --dynamic-linker /usr/lib/ldqnx.so.2}"
end_define

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
value|"long unsigned int"
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
value|BITS_PER_WORD
end_define

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
value|1
end_define

end_unit

