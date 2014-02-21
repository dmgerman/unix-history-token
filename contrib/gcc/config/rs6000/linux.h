begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for PowerPC machines running Linux.    Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003,    2004, 2005, 2006 Free Software Foundation, Inc.    Contributed by Michael Meissner (meissner@cygnus.com).     This file is part of GCC.     GCC is free software; you can redistribute it and/or modify it    under the terms of the GNU General Public License as published    by the Free Software Foundation; either version 2, or (at your    option) any later version.     GCC is distributed in the hope that it will be useful, but WITHOUT    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY    or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public    License for more details.     You should have received a copy of the GNU General Public License    along with GCC; see the file COPYING.  If not, write to the    Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston,    MA 02110-1301, USA.  */
end_comment

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

begin_comment
comment|/* Linux doesn't support saving and restoring 64-bit regs in a 32-bit    process.  */
end_comment

begin_define
define|#
directive|define
name|OS_MISSING_POWERPC64
value|1
end_define

begin_comment
comment|/* We use glibc _mcount for profiling.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
value|1
end_define

begin_comment
comment|/* glibc has float and long double forms of math functions.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_C99_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|TARGET_C99_FUNCTIONS
value|(OPTION_GLIBC)
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
value|do						\     {						\       builtin_define_std ("PPC");		\       builtin_define_std ("powerpc");		\       builtin_assert ("cpu=powerpc");		\       builtin_assert ("machine=powerpc");	\       TARGET_OS_SYSV_CPP_BUILTINS ();		\     }						\   while (0)
end_define

begin_undef
undef|#
directive|undef
name|CPP_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_OS_DEFAULT_SPEC
value|"%(cpp_os_linux)"
end_define

begin_comment
comment|/* The GNU C++ standard library currently requires _GNU_SOURCE being    defined on glibc-based systems. This temporary hack accomplishes this,    it should go away as soon as libstdc++-v3 has a real fix.  */
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
name|LINK_SHLIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SHLIB_SPEC
value|"%{shared:-shared} %{!shared: %{static:-static}}"
end_define

begin_undef
undef|#
directive|undef
name|LIB_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_DEFAULT_SPEC
value|"%(lib_linux)"
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_DEFAULT_SPEC
value|"%(startfile_linux)"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_DEFAULT_SPEC
value|"%(endfile_linux)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_START_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_START_DEFAULT_SPEC
value|"%(link_start_linux)"
end_define

begin_undef
undef|#
directive|undef
name|LINK_OS_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_OS_DEFAULT_SPEC
value|"%(link_os_linux)"
end_define

begin_define
define|#
directive|define
name|LINK_GCC_C_SEQUENCE_SPEC
define|\
value|"%{static:--start-group} %G %L %{static:--end-group}%{!static:%G}"
end_define

begin_comment
comment|/* Use --as-needed -lgcc_s for eh support.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LD_AS_NEEDED
end_ifdef

begin_define
define|#
directive|define
name|USE_LD_AS_NEEDED
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (PowerPC GNU/Linux)");
end_define

begin_comment
comment|/* Override rs6000.h definition.  */
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

begin_comment
comment|/* Override rs6000.h definition.  */
end_comment

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

begin_comment
comment|/* For backward compatibility, we must continue to use the AIX    structure return convention.  */
end_comment

begin_undef
undef|#
directive|undef
name|DRAFT_V4_STRUCT_RET
end_undef

begin_define
define|#
directive|define
name|DRAFT_V4_STRUCT_RET
value|1
end_define

begin_comment
comment|/* We are 32-bit all the time, so optimize a little.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_64BIT
end_undef

begin_define
define|#
directive|define
name|TARGET_64BIT
value|0
end_define

begin_comment
comment|/* We don't need to generate entries in .fixup, except when    -mrelocatable or -mrelocatable-lib is given.  */
end_comment

begin_undef
undef|#
directive|undef
name|RELOCATABLE_NEEDS_FIXUP
end_undef

begin_define
define|#
directive|define
name|RELOCATABLE_NEEDS_FIXUP
define|\
value|(target_flags& target_flags_explicit& MASK_RELOCATABLE)
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
name|TARGET_POSIX_IO
end_define

begin_define
define|#
directive|define
name|MD_UNWIND_SUPPORT
value|"config/rs6000/linux-unwind.h"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_LIBC_PROVIDES_SSP
end_ifdef

begin_comment
comment|/* ppc32 glibc provides __stack_chk_guard in -0x7008(2).  */
end_comment

begin_define
define|#
directive|define
name|TARGET_THREAD_SSP_OFFSET
value|-0x7008
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|POWERPC_LINUX
end_define

begin_comment
comment|/* ppc linux has 128-bit long double support in glibc 2.4 and later.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_DEFAULT_LONG_DOUBLE_128
end_ifdef

begin_define
define|#
directive|define
name|RS6000_DEFAULT_LONG_DOUBLE_SIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

