begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    64-bit VxWorks Sparc version.    Copyright (C) 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Specify what to link with.  */
end_comment

begin_comment
comment|/* VxWorks does all the library stuff itself.  */
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
value|"-r"
end_define

begin_comment
comment|/* VxWorks provides the functionality of crt0.o and friends itself.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|""
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
value|""
end_define

begin_comment
comment|/* We need to prohibit dots in constructor labels so that we can build a    table of { string, address } entries for each non-static name in a    program.  The address, being of the form&name, it cannot contain a dot or    C will try to parse it as a&struct.field phrase.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|DOLLARS_IN_IDENTIFIERS
end_undef

begin_define
define|#
directive|define
name|DOLLARS_IN_IDENTIFIERS
value|1
end_define

begin_define
define|#
directive|define
name|NO_DOT_IN_LABEL
end_define

begin_comment
comment|/* Enable #pragma pack(n) */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_comment
comment|/* We use stabs for debugging */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_comment
comment|/* Longs are still only 32bits for vxWorks, even for UltraSPARC */
end_comment

begin_undef
undef|#
directive|undef
name|LONG_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|32
end_define

begin_undef
undef|#
directive|undef
name|CPP_ARCH32_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_ARCH32_SPEC
value|"-Acpu(sparc) -Amachine(sparc)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_ARCH64_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_ARCH64_SPEC
define|\
value|"-Dsparc64 -D__arch64__ -Acpu(sparc64) -Amachine(sparc64)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__vxworks -D__sparc__ -Dsparc -D__GCC_NEW_VARARGS__"
end_define

begin_comment
comment|/* Note that we define CPU here even if the user has specified -ansi.    This violates user namespace, but the VxWorks headers, and potentially    user code, all explicitly rely upon the definition of CPU in order to get    the proper processor information.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %(cpp_arch) -DCPU=ULTRASPARC -D__CPU__=CPU"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_APP_REGS | MASK_EPILOGUE | MASK_FPU \ 			| MASK_LONG_DOUBLE_128 | MASK_64BIT)
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
value|CM_MEDLOW
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"long int"
end_define

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"char"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|8
end_define

begin_comment
comment|/* US Software GOFAST library support.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SUBTARGET_OPTABS
end_undef

begin_define
define|#
directive|define
name|INIT_SUBTARGET_OPTABS
value|INIT_GOFAST_OPTABS
end_define

end_unit

