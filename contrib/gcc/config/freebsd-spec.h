begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Base configuration file for all FreeBSD targets.    Copyright (C) 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Common FreeBSD configuration.     All FreeBSD architectures should include this file, which will specify    their commonalities.    Adapted from gcc/config/freebsd.h by     David O'Brien<obrien@FreeBSD.org>    Loren J. Rittle<ljrittle@acm.org>.  */
end_comment

begin_comment
comment|/* In case we need to know.  */
end_comment

begin_define
define|#
directive|define
name|USING_CONFIG_FREEBSD_SPEC
value|1
end_define

begin_comment
comment|/* This defines which switch letters take arguments.  On FreeBSD, most of    the normal cases (defined in gcc.c) apply, and we also have -h* and    -z* options (for the linker) (coming from SVR4).    We also have -R (alias --rpath), no -z, --soname (-h), --assert etc.  */
end_comment

begin_define
define|#
directive|define
name|FBSD_SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR)					\     || (CHAR) == 'h'							\     || (CHAR) == 'z'
comment|/* ignored by ld */
value|\     || (CHAR) == 'R')
end_define

begin_comment
comment|/* This defines which multi-letter switches take arguments.  */
end_comment

begin_define
define|#
directive|define
name|FBSD_WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\    || !strcmp ((STR), "rpath") || !strcmp ((STR), "rpath-link")		\    || !strcmp ((STR), "soname") || !strcmp ((STR), "defsym") 		\    || !strcmp ((STR), "assert") || !strcmp ((STR), "dynamic-linker"))
end_define

begin_if
if|#
directive|if
name|FBSD_MAJOR
operator|==
literal|6
end_if

begin_define
define|#
directive|define
name|FBSD_CPP_PREDEFINES
define|\
value|"-D__FreeBSD__=6 -Dunix -D__ELF__ -D__KPRINTF_ATTRIBUTE__ -Asystem=unix -Asystem=bsd -Asystem=FreeBSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FBSD_MAJOR
operator|==
literal|5
end_if

begin_define
define|#
directive|define
name|FBSD_CPP_PREDEFINES
define|\
value|"-D__FreeBSD__=5 -Dunix -D__ELF__ -D__KPRINTF_ATTRIBUTE__ -Asystem=unix -Asystem=bsd -Asystem=FreeBSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FBSD_MAJOR
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|FBSD_CPP_PREDEFINES
define|\
value|"-D__FreeBSD__=4 -Dunix -D__ELF__ -D__KPRINTF_ATTRIBUTE__ -Asystem=unix -Asystem=bsd -Asystem=FreeBSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|FBSD_MAJOR
operator|==
literal|3
end_if

begin_define
define|#
directive|define
name|FBSD_CPP_PREDEFINES
define|\
value|"-D__FreeBSD__=3 -Dunix -D__ELF__ -D__KPRINTF_ATTRIBUTE__ -Asystem=unix -Asystem=bsd -Asystem=FreeBSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FBSD_CPP_PREDEFINES
end_ifndef

begin_define
define|#
directive|define
name|FBSD_CPP_PREDEFINES
define|\
value|"-D__FreeBSD__   -Dunix -D__ELF__ -D__KPRINTF_ATTRIBUTE__ -Asystem=unix -Asystem=bsd -Asystem=FreeBSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide a CPP_SPEC appropriate for FreeBSD.  We just deal with the GCC     option `-posix', and PIC issues.  */
end_comment

begin_define
define|#
directive|define
name|FBSD_CPP_SPEC
value|"							\   %(cpp_cpu)								\   %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__}		\   %{posix:-D_POSIX_SOURCE}"
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for FreeBSD.  Here we add    the magical crtbegin.o file (see crtstuff.c) which provides part  	of the support for getting C++ file-scope static object constructed  	before entering `main'. */
end_comment

begin_define
define|#
directive|define
name|FBSD_STARTFILE_SPEC
define|\
value|"%{!shared: \      %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} \ 		       %{!p:%{profile:gcrt1.o%s} \ 			 %{!profile:crt1.o%s}}}} \    crti.o%s %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for FreeBSD.  Here we tack on    the magical crtend.o file (see crtstuff.c) which provides part of  	the support for getting C++ file-scope static object constructed  	before entering `main', followed by a normal "finalizer" file,  	`crtn.o'.  */
end_comment

begin_define
define|#
directive|define
name|FBSD_ENDFILE_SPEC
define|\
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s} crtn.o%s"
end_define

begin_comment
comment|/* Provide a LIB_SPEC appropriate for FreeBSD as configured and as    required by the user-land thread model.  Before __FreeBSD_version    500016, select the appropriate libc, depending on whether we're    doing profiling or need threads support.  At __FreeBSD_version    500016 and later, when threads support is requested include both    -lc and -lc_r instead of only -lc_r.  To make matters interesting,    we can't actually use __FreeBSD_version provided by<osreldate.h>    directly since it breaks cross-compiling.  As a final twist, make    it a hard error if -pthread is provided on the command line and gcc    was configured with --disable-threads (this will help avoid bug    reports from users complaining about threading when they    misconfigured the gcc bootstrap but are later consulting FreeBSD    manual pages that refer to the mythical -pthread option).  */
end_comment

begin_comment
comment|/* Provide a LIB_SPEC appropriate for FreeBSD.  Just select the appropriate    libc, depending on whether we're doing profiling or need threads support.    (simular to the default, except no -lg, and no -p).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FBSD_NO_THREADS
end_ifdef

begin_define
define|#
directive|define
name|FBSD_LIB_SPEC
value|"							\   %{pthread: %eThe -pthread option is only supported on FreeBSD when gcc \ is built with the --enable-threads configure-time option.}		\   %{!shared:								\     %{!pg: -lc}								\     %{pg:  -lc_p}							\   }"
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|FBSD_MAJOR
operator|>=
literal|5
end_if

begin_define
define|#
directive|define
name|FBSD_LIB_SPEC
value|"							\   %{!shared:								\     %{!pg: %{pthread:-lc_r} -lc}					\     %{pg:  %{pthread:-lc_r_p} -lc_p}					\   }"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FBSD_LIB_SPEC
value|"							\   %{!shared:								\     %{!pg:								\       %{!pthread:-lc}							\       %{pthread:-lc_r}}							\     %{pg:								\       %{!pthread:-lc_p}							\       %{pthread:-lc_r_p}}						\   }"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

