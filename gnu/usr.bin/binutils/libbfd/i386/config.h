begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if using alloca.c.  */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

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
comment|/* Define if you have a working `mmap' system call.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

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
comment|/* Define if you have the __argz_count function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_COUNT */
end_comment

begin_comment
comment|/* Define if you have the __argz_next function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_NEXT */
end_comment

begin_comment
comment|/* Define if you have the __argz_stringify function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_STRINGIFY */
end_comment

begin_comment
comment|/* Define if you have the dcgettext function.  */
end_comment

begin_comment
comment|/* #undef HAVE_DCGETTEXT */
end_comment

begin_comment
comment|/* Define if you have the fcntl function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL
value|1
end_define

begin_comment
comment|/* Define if you have the fdopen function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FDOPEN
value|1
end_define

begin_comment
comment|/* Define if you have the getcwd function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define if you have the getgid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGID
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
comment|/* Define if you have the getuid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
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
comment|/* Define if you have the mprotect function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MPROTECT
value|1
end_define

begin_comment
comment|/* Define if you have the munmap function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MUNMAP
value|1
end_define

begin_comment
comment|/* Define if you have the putenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define if you have the setenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if you have the setitimer function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETITIMER
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
comment|/* Define if you have the stpcpy function.  */
end_comment

begin_comment
comment|/* #undef HAVE_STPCPY */
end_comment

begin_comment
comment|/* Define if you have the strcasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
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
comment|/* Define if you have the sysconf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define if you have the<argz.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_H */
end_comment

begin_comment
comment|/* Define if you have the<dirent.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
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
comment|/* Define if you have the<malloc.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define if you have the<ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<nl_types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stddef.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
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

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/dir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
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
comment|/* Define if you have the<sys/procfs.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PROCFS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
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
comment|/* Define if you have the<values.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_VALUES_H */
end_comment

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"bfd"
end_define

begin_comment
comment|/* Version number of package */
end_comment

begin_comment
comment|/* #define VERSION "2.11" */
end_comment

begin_comment
comment|/* Define if you have the stpcpy function */
end_comment

begin_comment
comment|/* #undef HAVE_STPCPY */
end_comment

begin_comment
comment|/* Define if your locale.h file contains LC_MESSAGES. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LC_MESSAGES
value|1
end_define

begin_comment
comment|/* Define to 1 if NLS is requested */
end_comment

begin_comment
comment|/* #define ENABLE_NLS 1 */
end_comment

begin_comment
comment|/* Define as 1 if you have gettext and don't want to use GNU gettext. */
end_comment

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Use b modifier when opening binary files? */
end_comment

begin_comment
comment|/* #undef USE_BINARY_FOPEN */
end_comment

begin_comment
comment|/* Define if strstr is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRSTR */
end_comment

begin_comment
comment|/* Define if malloc is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_MALLOC */
end_comment

begin_comment
comment|/* Define if realloc is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_REALLOC */
end_comment

begin_comment
comment|/* Define if free is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_FREE */
end_comment

begin_comment
comment|/* Define if getenv is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_GETENV */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has prstatus_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRSTATUS_T
value|1
end_define

begin_comment
comment|/* Define if<sys/procfs.h> has prstatus32_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PRSTATUS32_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has prstatus_t.pr_who. */
end_comment

begin_comment
comment|/* #undef HAVE_PRSTATUS_T_PR_WHO */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has prstatus32_t.pr_who. */
end_comment

begin_comment
comment|/* #undef HAVE_PRSTATUS32_T_PR_WHO */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has pstatus_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PSTATUS_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has pxstatus_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PXSTATUS_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has pstatus32_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PSTATUS32_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has prpsinfo_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRPSINFO_T
value|1
end_define

begin_comment
comment|/* Define if<sys/procfs.h> has prpsinfo32_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PRPSINFO32_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has psinfo_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PSINFO_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has psinfo32_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PSINFO32_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has lwpstatus_t. */
end_comment

begin_comment
comment|/* #undef HAVE_LWPSTATUS_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has lwpxstatus_t. */
end_comment

begin_comment
comment|/* #undef HAVE_LWPXSTATUS_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has lwpstatus_t.pr_context. */
end_comment

begin_comment
comment|/* #undef HAVE_LWPSTATUS_T_PR_CONTEXT */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has lwpstatus_t.pr_reg. */
end_comment

begin_comment
comment|/* #undef HAVE_LWPSTATUS_T_PR_REG */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has win32_pstatus_t. */
end_comment

begin_comment
comment|/* #undef HAVE_WIN32_PSTATUS_T */
end_comment

begin_comment
comment|/* Name of host specific header file to include in trad-core.c. */
end_comment

begin_define
define|#
directive|define
name|TRAD_HEADER
value|"hosts/i386bsd.h"
end_define

begin_comment
comment|/* Use mmap if it's available? */
end_comment

begin_comment
comment|/* #undef USE_MMAP */
end_comment

end_unit

