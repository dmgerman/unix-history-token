begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for target OS TPF for GNU compiler, for IBM S/390 hardware    Copyright (C) 2003 Free Software Foundation, Inc.    Contributed by P.J. Darcy (darcypj@us.ibm.com),                   Hartmut Penner (hpenner@de.ibm.com), and                   Ulrich Weigand (uweigand@de.ibm.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TPF_H
end_ifndef

begin_define
define|#
directive|define
name|_TPF_H
end_define

begin_comment
comment|/* TPF wants the following macros defined/undefined as follows.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_define
define|#
directive|define
name|TARGET_HAS_F_SETLKW
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
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|("long unsigned int")
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
value|("long int")
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
comment|/* Basic record keeping for the TPF OS name.  */
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
value|fprintf (stderr, " (TPF: zSeries)");
end_define

begin_comment
comment|/* TPF OS specific stack-pointer offset.  */
end_comment

begin_undef
undef|#
directive|undef
name|STACK_POINTER_OFFSET
end_undef

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|280
end_define

begin_comment
comment|/* When building for TPF, set a generic default target that is 64 bits.  */
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
value|0x33
end_define

begin_comment
comment|/* TPF OS specific compiler settings.  */
end_comment

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
value|do                                            \     {                                           \       builtin_define_std ("tpf");               \       builtin_assert ("system=tpf");            \       builtin_define ("__ELF__");               \       if (flag_pic)                             \         {                                       \           builtin_define ("__PIC__");           \           builtin_define ("__pic__");           \         }                                       \     }                                           \   while (0)
end_define

begin_comment
comment|/* Make TPF specific spec file settings here.  */
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
define|\
value|"%{!shared: \      %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} \                        %{!p:%{profile:gcrt1.o%s} \                          %{!profile:crt1.o%s}}}} \    crti.o%s %{static:crtbeginT.o%s} \    %{!static:%{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}}"
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
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
end_define

begin_comment
comment|/* The GNU C++ standard library requires that these macros be defined.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPLUSPLUS_CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPLUSPLUS_CPP_SPEC
value|"-D_GNU_SOURCE %(cpp)"
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
value|"%{m31&m64}%{mesa&mzarch}%{march=*}"
end_define

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{pthread:-lpthread} -lc"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_C99_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|TARGET_C99_FUNCTIONS
value|1
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
value|"-m elf64_s390 \    %{shared:-shared} \    %{!shared: \       %{static:-static} \       %{!static: \         %{rdynamic:-export-dynamic} \         %{!dynamic-linker:-dynamic-linker /lib/ld64.so}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _TPF_H */
end_comment

end_unit

