begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Rs6000 running LynxOS.    Copyright (C) 1995, 1996, 2000 Free Software Foundation, Inc.    Contributed by David Henkel-Wallace, Cygnus Support (gumby@cygnus.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Definitions we want to override with those from rs6000.h: */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
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

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_COMMON
end_undef

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LOCAL
end_undef

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_include
include|#
directive|include
file|<rs6000/rs6000.h>
end_include

begin_comment
comment|/* Print subsidiary information on the compiler version in use.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (LynxOS-RS/6000)");
end_define

begin_comment
comment|/* LynxOS has signed chars, regardless of what most R/S 6000 systems do */
end_comment

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

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Acpu=rs6000 -Amachine=rs6000 -Asystem=lynx -Asystem=unix -DLynx -D_IBMR2 -Dunix -Drs6000 -Dlynx -DLYNX"
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
value|"-T0x10001000 -H0x1000 -D0x20000000 -btextro -bhalt:4 -bnodelcsect -bnso -bro -bnoglink %{v} %{b*}"
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
value|"%{mthreads:-L/lib/thread/}  \   %{msystem-v:-lc_v -lm.v}  \   %{!msystem-v:%{mposix:-lc_p} -lc -lm}"
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
value|"%{p:%{mthreads:thread/pinit.o%s}%{!mthreads:pinit.o%s}}%{!p:%{msystem-v:vinit.o%s -e_start}%{!msystem-v:%{mthreads:thread/init.o%s}%{!mthreads:init.o%s}}}"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_comment
comment|/* This can become more refined as we have more powerpc options.  */
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
value|"-u %(asm_cpu)"
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
value|{"threads",		MASK_THREADS},		\     {"posix",		MASK_POSIX},		\     {"system-v",	MASK_SYSTEM_V},
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
value|do {								\   if (TARGET_SYSTEM_V&& profile_flag)				\     warning ("-msystem-v and -p are incompatible");		\   if (TARGET_SYSTEM_V&& TARGET_THREADS)			\     warning ("-msystem-v and -mthreads are incompatible");	\ } while (0)
end_define

begin_comment
comment|/* For collect2 */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_NONE
end_define

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_COFF
end_undef

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_ROSE
end_undef

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|REAL_LD_FILE_NAME
end_undef

begin_undef
undef|#
directive|undef
name|REAL_STRIP_FILE_NAME
end_undef

begin_comment
comment|/* LynxOS doesn't have mcount.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|file
parameter_list|,
name|profile_label_no
parameter_list|)
end_define

end_unit

