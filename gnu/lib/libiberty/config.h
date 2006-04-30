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
comment|/* Define if you have<sys/wait.h> that is POSIX.1 compatible.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have<vfork.h>.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
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
comment|/* Define vfork as fork if vfork does not work.  */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Define if you have the asprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ASPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the atexit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
value|1
end_define

begin_comment
comment|/* Define if you have the basename function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BASENAME
value|1
end_define

begin_comment
comment|/* Define if you have the bcmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BCMP
value|1
end_define

begin_comment
comment|/* Define if you have the bcopy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BCOPY
value|1
end_define

begin_comment
comment|/* Define if you have the bsearch function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BSEARCH
value|1
end_define

begin_comment
comment|/* Define if you have the bzero function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BZERO
value|1
end_define

begin_comment
comment|/* Define if you have the calloc function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CALLOC
value|1
end_define

begin_comment
comment|/* Define if you have the clock function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CLOCK
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
comment|/* Define if you have the getpagesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the getrusage function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
value|1
end_define

begin_comment
comment|/* Define if you have the gettimeofday function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* Define if you have the index function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_INDEX
value|1
end_define

begin_comment
comment|/* Define if you have the insque function.  */
end_comment

begin_comment
comment|/* #undef HAVE_INSQUE */
end_comment

begin_comment
comment|/* Define if you have the memchr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
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
comment|/* Define if you have the memmove function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
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
comment|/* Define if you have the mkstemps function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMPS
value|1
end_define

begin_comment
comment|/* Define if you have the on_exit function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ON_EXIT */
end_comment

begin_comment
comment|/* Define if you have the psignal function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PSIGNAL
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
comment|/* Define if you have the random function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RANDOM
value|1
end_define

begin_comment
comment|/* Define if you have the rename function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RENAME
value|1
end_define

begin_comment
comment|/* Define if you have the rindex function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RINDEX
value|1
end_define

begin_comment
comment|/* Define if you have the sbrk function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SBRK
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
comment|/* Define if you have the sigsetmask function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSETMASK
value|1
end_define

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
comment|/* Define if you have the strdup function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
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
comment|/* Define if you have the strncasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the strrchr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRRCHR
value|1
end_define

begin_comment
comment|/* Define if you have the strsignal function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSIGNAL
value|1
end_define

begin_comment
comment|/* Define if you have the strstr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
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
comment|/* Define if you have the strtol function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOL
value|1
end_define

begin_comment
comment|/* Define if you have the strtoul function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
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
comment|/* Define if you have the times function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIMES
value|1
end_define

begin_comment
comment|/* Define if you have the tmpnam function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TMPNAM
value|1
end_define

begin_comment
comment|/* Define if you have the vasprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VASPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the vfprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFPRINTF
value|1
end_define

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
comment|/* Define if you have the vsprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the waitpid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WAITPID
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
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/mman.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

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
comment|/* Define if you have the<sys/resource.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_RESOURCE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stat.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
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
comment|/* Define if errno must be declared even when<errno.h> is included. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_ERRNO */
end_comment

begin_comment
comment|/* Define if you have the sys_errlist variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_ERRLIST
value|1
end_define

begin_comment
comment|/* Define if you have the sys_nerr variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_NERR
value|1
end_define

begin_comment
comment|/* Define if you have the sys_siglist variable. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SIGLIST
value|1
end_define

end_unit

