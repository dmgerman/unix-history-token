begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* configh.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/*  * acconfig.h -- configuration definitions for gawk.  */
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_comment
comment|/*   * Copyright (C) 1995-2000 the Free Software Foundation, Inc.  *   * This file is part of GAWK, the GNU implementation of the  * AWK Programming Language.  *   * GAWK is free software; you can redistribute it and/or modify  * it under the terms of the GNU General Public License as published by  * the Free Software Foundation; either version 2 of the License, or  * (at your option) any later version.  *   * GAWK is distributed in the hope that it will be useful,  * but WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the  * GNU General Public License for more details.  *   * You should have received a copy of the GNU General Public License  * along with this program; if not, write to the Free Software  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA  */
end_comment

begin_comment
comment|/* Define if on AIX 3.    System headers sometimes define this.    We just want to avoid a redefinition error message.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_comment
comment|/* #undef _ALL_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if using alloca.c.  */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define if type char is unsigned and you are not using gcc.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__CHAR_UNSIGNED__
end_ifndef

begin_comment
comment|/* #undef __CHAR_UNSIGNED__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.    This function is required for alloca.c support on those systems.  */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define to the type of elements in the array set by `getgroups'.    Usually this is either `int' or `gid_t'.  */
end_comment

begin_define
define|#
directive|define
name|GETGROUPS_T
value|gid_t
end_define

begin_comment
comment|/* Define if the `getpgrp' function takes no argument.  */
end_comment

begin_define
define|#
directive|define
name|GETPGRP_VOID
value|1
end_define

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef gid_t */
end_comment

begin_comment
comment|/* Define if you have alloca, as a function or macro.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix).  */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define if you don't have vprintf but do have _doprnt.  */
end_comment

begin_comment
comment|/* #undef HAVE_DOPRNT */
end_comment

begin_comment
comment|/* Define if you have a working `mmap' system call.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define if your struct stat has st_blksize.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define if you have the ANSI # stringizing operator in cpp. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGIZE
value|1
end_define

begin_comment
comment|/* Define if you have<sys/wait.h> that is POSIX.1 compatible.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if your struct tm has tm_zone.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TM_ZONE
value|1
end_define

begin_comment
comment|/* Define if you don't have tm_zone but do have the external array    tzname.  */
end_comment

begin_comment
comment|/* #undef HAVE_TZNAME */
end_comment

begin_comment
comment|/* Define if you have the vprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* Define if on MINIX.  */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define if the system does not provide POSIX.1 features except    with this defined.  */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (int or void).  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.  STACK_DIRECTION> 0 => grows toward higher addresses  STACK_DIRECTION< 0 => grows toward lower addresses  STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Define if your<sys/time.h> declares struct tm.  */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef uid_t */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGIZE
value|1
end_define

begin_comment
comment|/* can use ANSI # operator in cpp */
end_comment

begin_define
define|#
directive|define
name|REGEX_MALLOC
value|1
end_define

begin_comment
comment|/* use malloc instead of alloca in regex.c */
end_comment

begin_define
define|#
directive|define
name|SPRINTF_RET
value|int
end_define

begin_comment
comment|/* return type of sprintf */
end_comment

begin_comment
comment|/* #undef BITOPS */
end_comment

begin_comment
comment|/* bitwise ops (undocumented feature) */
end_comment

begin_comment
comment|/* #undef NONDECDATA */
end_comment

begin_comment
comment|/* non-decimal input data (undocumented feature) */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* bits in a file offset, where this matters */
end_comment

begin_comment
comment|/* #undef _LARGEFILE_SOURCE */
end_comment

begin_comment
comment|/* makes fseeko etc. visible on some hosts */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* emables large files on AIX-style hosts */
end_comment

begin_comment
comment|/* Define if you have the fmod function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FMOD
value|1
end_define

begin_comment
comment|/* Define if you have the getpagesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the madvise function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MADVISE
value|1
end_define

begin_comment
comment|/* Define if you have the memcmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCMP
value|1
end_define

begin_comment
comment|/* Define if you have the memcpy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCPY
value|1
end_define

begin_comment
comment|/* Define if you have the memset function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define if you have the setlocale function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define if you have the strchr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define if you have the strerror function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the strftime function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRFTIME
value|1
end_define

begin_comment
comment|/* Define if you have the strncasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the strtod function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOD
value|1
end_define

begin_comment
comment|/* Define if you have the system function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSTEM
value|1
end_define

begin_comment
comment|/* Define if you have the tzset function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TZSET
value|1
end_define

begin_comment
comment|/* Define if you have the<limits.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<locale.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<memory.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<signum.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SIGNUM_H */
end_comment

begin_comment
comment|/* Define if you have the<stdarg.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<strings.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_STRINGS_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the m library (-lm).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBM
value|1
end_define

begin_comment
comment|/* Number of bits in a file offset, on hosts where this is settable. */
end_comment

begin_comment
comment|/* #undef _FILE_OFFSET_BITS */
end_comment

begin_comment
comment|/* Define to make ftello visible on some hosts (e.g. HP-UX 10.20). */
end_comment

begin_comment
comment|/* #undef _LARGEFILE_SOURCE */
end_comment

begin_comment
comment|/* Define for large files, on AIX-style hosts. */
end_comment

begin_comment
comment|/* #undef _LARGE_FILES */
end_comment

begin_comment
comment|/* Define to make ftello visible on some hosts (e.g. glibc 2.1.3). */
end_comment

begin_comment
comment|/* #undef _XOPEN_SOURCE */
end_comment

begin_include
include|#
directive|include
file|<custom.h>
end_include

begin_comment
comment|/* overrides for stuff autoconf can't deal with */
end_comment

end_unit

