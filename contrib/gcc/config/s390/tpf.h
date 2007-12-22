begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for target OS TPF for GNU compiler, for IBM S/390 hardware    Copyright (C) 2003, 2004, 2005 Free Software Foundation, Inc.    Contributed by P.J. Darcy (darcypj@us.ibm.com),                   Hartmut Penner (hpenner@de.ibm.com), and                   Ulrich Weigand (uweigand@de.ibm.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
name|TARGET_TPF
end_undef

begin_define
define|#
directive|define
name|TARGET_TPF
value|1
end_define

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
name|TARGET_POSIX_IO
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
value|448
end_define

begin_comment
comment|/* When building for TPF, set a generic default target that is 64 bits. Also    enable TPF profiling support and the standard backchain by default.  */
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
value|(MASK_TPF_PROFILING | MASK_64BIT | MASK_ZARCH \ 			| MASK_HARD_FLOAT | MASK_BACKCHAIN)
end_define

begin_comment
comment|/* Exception handling.  */
end_comment

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_PREFERRED_EH_DATA_FORMAT
end_undef

begin_define
define|#
directive|define
name|ASM_PREFERRED_EH_DATA_FORMAT
parameter_list|(
name|CODE
parameter_list|,
name|GLOBAL
parameter_list|)
value|DW_EH_PE_absptr
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
value|do                                            \     {                                           \       builtin_define_std ("tpf");               \       builtin_assert ("system=tpf");            \       builtin_define ("__ELF__");               \     }                                           \   while (0)
end_define

begin_define
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "entry_spec", ENTRY_SPEC }
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
value|"%{mmain:crt0%O%s} crtbeginS%O%s crt3%O%s"
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
value|"crtendS%O%s"
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{!fverbose-asm: -fverbose-asm}"
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
value|"%{m31&m64}%{mesa&mzarch}%{march=*} \                   -alshd=%b.lst"
end_define

begin_comment
comment|/* It would be nice to get the system linker script define the ones that it    needed.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"-lCTIS -lCISO -lCLBM -lCTAL -lCFVS -lCTBX -lCTXO \                   -lCJ00 -lCTDF -lCOMX -lCOMS -lCTHD -lCTAD -lTPFSTUB"
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

begin_define
define|#
directive|define
name|ENTRY_SPEC
value|"%{mmain:-entry=_start} \                     %{!mmain:-entry=0}"
end_define

begin_comment
comment|/* All linking is done shared on TPF-OS.  */
end_comment

begin_comment
comment|/* FIXME: When binutils patch for new emulation is committed    then change emulation to elf64_s390_tpf.  */
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
value|"-m elf64_s390 \    %{static:%estatic is not supported on TPF-OS} \    %{shared: -shared} \    %{!shared:-shared} \    %(entry_spec)"
end_define

begin_define
define|#
directive|define
name|MD_UNWIND_SUPPORT
value|"config/s390/tpf-unwind.h"
end_define

begin_comment
comment|/* IBM copies these libraries over with these names.  */
end_comment

begin_define
define|#
directive|define
name|MATH_LIBRARY
value|"-lCLBM"
end_define

begin_define
define|#
directive|define
name|LIBSTDCXX
value|"-lCPP1"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! _TPF_H */
end_comment

end_unit

