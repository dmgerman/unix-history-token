begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for FreeBSD for S/390.    Copyright (C) 1999, 2000, 2001, 2002, 2004, 2005, 2006    Free Software Foundation, Inc.    Contributed by Hartmut Penner (hpenner@de.ibm.com) and                   Ulrich Weigand (uweigand@de.ibm.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CONFIG_S390_FREEBSD_H
end_ifndef

begin_define
define|#
directive|define
name|_CONFIG_S390_FREEBSD_H
end_define

begin_comment
comment|/* Target specific version string.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (FreeBSD for zSeries)");
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (FreeBSD for S/390)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target specific type definitions.  */
end_comment

begin_comment
comment|/* ??? Do we really want long as size_t on 31-bit?  */
end_comment

begin_comment
comment|/* Answer is yes for FreeBSD. */
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
value|(TARGET_64BIT ? "long unsigned int" : "unsigned int")
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
value|(TARGET_64BIT ? "long int" : "int")
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

begin_undef
undef|#
directive|undef
name|DEFAULT_SIGNED_CHAR
end_undef

begin_define
define|#
directive|define
name|DEFAULT_SIGNED_CHAR
value|1
end_define

begin_comment
comment|/* Target specific assembler settings.  */
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
value|"%{m31&m64}%{mesa&mzarch}%{march=*}"
end_define

begin_comment
comment|/* Target specific linker settings.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m64" }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "m31" }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER32
value|"/lib/ld.so.1"
end_define

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER64
value|"/lib/ld64.so.1"
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
value|"%{m31:-m elf_s390}%{m64:-m elf64_s390} \    %{shared:-shared} \    %{!shared: \       %{static:-static} \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker: \           %{m31:-dynamic-linker " LINUX_DYNAMIC_LINKER32 "} \           %{m64:-dynamic-linker " LINUX_DYNAMIC_LINKER64 "}}}}"
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_END
value|file_end_indicate_exec_stack
end_define

begin_define
define|#
directive|define
name|MD_UNWIND_SUPPORT
value|"config/s390/freebsd-unwind.h"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_LIBC_PROVIDES_SSP
end_ifdef

begin_comment
comment|/* s390 glibc provides __stack_chk_guard in 0x14(tp),    s390x glibc provides it at 0x28(tp).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_THREAD_SSP_OFFSET
value|(TARGET_64BIT ? 0x28 : 0x14)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if long doubles should be mangled as 'g'.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ALTERNATE_LONG_DOUBLE_MANGLING
end_define

begin_comment
comment|/* Override the default comment-starter of "/APP" from unix.h.  */
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

