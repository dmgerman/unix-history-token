begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target independent definitions for LynxOS, using Lynx's old as and ld.    Copyright (C) 1993 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* This is for backwards compatibility with older Lynx tools, which use    a version of a.out format. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{mcoff:-C}"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{mthreads:-D_MULTITHREADED}  \   %{mposix:-D_POSIX_SOURCE}  \   %{msystem-v:-I/usr/include_v}"
end_define

begin_comment
comment|/* Provide required defaults for linker switches.  */
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
value|"%{msystem-v:-V} %{mcoff:-k}"
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
value|"%{mthreads:-L/lib/thread/}%{msystem-v:-lc_v}%{!msystem-v:%{mposix:-lc_p} -lc}"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{p:%{mcoff:pinit1.o%s}%{!mcoff:pinit.o%s}}%{!p:%{msystem-v:%{mcoff:vinit1.o%s}%{!mcoff:vinit.o%s}}%{!msystem-v:%{mcoff:init1.o%s}%{!mcoff:init.o%s}}}"
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
value|"%{mcoff:initn.o%s} %{p:_etext.o%s}"
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
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"long int"
end_define

begin_comment
comment|/* We want to output DBX debugging information.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

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
comment|/* We optionally want to be able to produce SDB debugging output so that    we can create debuggable SDB/coff files.  This won't be needed when    stabs-in-coff works.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_comment
comment|/* Generate calls to memcpy, memcmp and memset.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Handle #pragma pack and sometimes #pragma weak.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_define
define|#
directive|define
name|TARGET_THREADS
value|(target_flags& MASK_THREADS)
end_define

begin_define
define|#
directive|define
name|MASK_THREADS
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TARGET_POSIX
value|(target_flags& MASK_POSIX)
end_define

begin_define
define|#
directive|define
name|MASK_POSIX
value|0x20000000
end_define

begin_define
define|#
directive|define
name|TARGET_SYSTEM_V
value|(target_flags& MASK_SYSTEM_V)
end_define

begin_define
define|#
directive|define
name|MASK_SYSTEM_V
value|0x10000000
end_define

begin_define
define|#
directive|define
name|TARGET_COFF
value|(target_flags& MASK_COFF)
end_define

begin_define
define|#
directive|define
name|MASK_COFF
value|0x08000000
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{"threads",		MASK_THREADS},		\     {"posix",		MASK_POSIX},		\     {"system-v",	MASK_SYSTEM_V},		\     {"coff",		MASK_COFF},
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_OVERRIDE_OPTIONS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_OVERRIDE_OPTIONS
define|\
value|{ if (TARGET_SYSTEM_V&& profile_flag)			\     warning ("-msystem-v and -p are incompatible");		\   if (TARGET_SYSTEM_V&& TARGET_THREADS)			\     warning ("-msystem-v and -mthreads are incompatible"); }
end_define

begin_comment
comment|/* Define this so that C++ destructors will use atexit.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* This is defined only so that we can find the assembler.  Everything else    is in /bin.  */
end_comment

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/local/lib/gcc-"
end_define

begin_comment
comment|/* This is needed because /bin/ld does not handle -L options correctly. */
end_comment

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL_1
end_define

begin_comment
comment|/* The Lynx linker considers __main to be a possible entry point, so we    must use a different name.  */
end_comment

begin_define
define|#
directive|define
name|NAME__MAIN
value|"____main"
end_define

begin_define
define|#
directive|define
name|SYMBOL__MAIN
value|____main
end_define

end_unit

