begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* auto-host.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if you can safely include both<string.h> and<strings.h>.  */
end_comment

begin_define
define|#
directive|define
name|STRING_WITH_STRINGS
value|1
end_define

begin_comment
comment|/* Define if printf supports "%p".  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRINTF_PTR
value|1
end_define

begin_comment
comment|/* Define if you want expensive run-time checks. */
end_comment

begin_comment
comment|/* #undef ENABLE_CHECKING */
end_comment

begin_comment
comment|/* Define to 1 if NLS is requested.  */
end_comment

begin_comment
comment|/* #undef ENABLE_NLS */
end_comment

begin_comment
comment|/* Define as 1 if you have catgets and don't want to use GNU gettext.  */
end_comment

begin_comment
comment|/* #undef HAVE_CATGETS */
end_comment

begin_comment
comment|/* Define as 1 if you have gettext and don't want to use GNU gettext.  */
end_comment

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Define if your cpp understands the stringify operator.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CPP_STRINGIFY
value|1
end_define

begin_comment
comment|/* Define if your compiler understands volatile.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VOLATILE
value|1
end_define

begin_comment
comment|/* Define if your assembler supports specifying the maximum number    of bytes to skip when using the GAS .p2align command. */
end_comment

begin_comment
comment|/* #undef HAVE_GAS_MAX_SKIP_P2ALIGN */
end_comment

begin_comment
comment|/* Define if your assembler supports .balign and .p2align.  */
end_comment

begin_comment
comment|/* #undef HAVE_GAS_BALIGN_AND_P2ALIGN */
end_comment

begin_comment
comment|/* Define if your assembler supports .subsection and .subsection -1 starts    emitting at the beginning of your section */
end_comment

begin_comment
comment|/* #undef HAVE_GAS_SUBSECTION_ORDERING */
end_comment

begin_comment
comment|/* Define if your assembler uses the old HImode fild and fist notation.  */
end_comment

begin_comment
comment|/* #undef HAVE_GAS_FILDS_FISTS */
end_comment

begin_comment
comment|/* Define if you have a working<inttypes.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_INTTYPES_H */
end_comment

begin_comment
comment|/* Define if your locale.h file contains LC_MESSAGES.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LC_MESSAGES
value|1
end_define

begin_comment
comment|/* Whether malloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_MALLOC */
end_comment

begin_comment
comment|/* Whether realloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_REALLOC */
end_comment

begin_comment
comment|/* Whether calloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_CALLOC */
end_comment

begin_comment
comment|/* Whether free must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_FREE */
end_comment

begin_comment
comment|/* Whether bcopy must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_BCOPY */
end_comment

begin_comment
comment|/* Whether bcmp must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_BCMP */
end_comment

begin_comment
comment|/* Whether bzero must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_BZERO */
end_comment

begin_comment
comment|/* Whether index must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_INDEX */
end_comment

begin_comment
comment|/* Whether rindex must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_RINDEX */
end_comment

begin_comment
comment|/* Whether getenv must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_GETENV */
end_comment

begin_comment
comment|/* Whether atol must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_ATOL */
end_comment

begin_comment
comment|/* Whether atof must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_ATOF */
end_comment

begin_comment
comment|/* Whether sbrk must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_SBRK */
end_comment

begin_comment
comment|/* Whether abort must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_ABORT */
end_comment

begin_comment
comment|/* Whether strerror must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRERROR */
end_comment

begin_comment
comment|/* Whether strsignal must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRSIGNAL */
end_comment

begin_comment
comment|/* Whether strstr must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRSTR */
end_comment

begin_comment
comment|/* Whether getcwd must be declared even if<unistd.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_GETCWD */
end_comment

begin_comment
comment|/* Whether getwd must be declared even if<unistd.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_GETWD */
end_comment

begin_comment
comment|/* Whether getrlimit must be declared even if<sys/resource.h> is included.  */
end_comment

begin_define
define|#
directive|define
name|NEED_DECLARATION_GETRLIMIT
value|1
end_define

begin_comment
comment|/* Whether setrlimit must be declared even if<sys/resource.h> is included.  */
end_comment

begin_define
define|#
directive|define
name|NEED_DECLARATION_SETRLIMIT
value|1
end_define

begin_comment
comment|/* Whether putc_unlocked must be declared even if<stdio.h> is included.  */
end_comment

begin_define
define|#
directive|define
name|NEED_DECLARATION_PUTC_UNLOCKED
value|1
end_define

begin_comment
comment|/* Whether fputs_unlocked must be declared even if<stdio.h> is included.  */
end_comment

begin_define
define|#
directive|define
name|NEED_DECLARATION_FPUTS_UNLOCKED
value|1
end_define

begin_comment
comment|/* Define to enable the use of a default assembler. */
end_comment

begin_comment
comment|/* #undef DEFAULT_ASSEMBLER */
end_comment

begin_comment
comment|/* Define to enable the use of a default linker. */
end_comment

begin_comment
comment|/* #undef DEFAULT_LINKER */
end_comment

begin_comment
comment|/* Define if host mkdir takes a single argument. */
end_comment

begin_comment
comment|/* #undef MKDIR_TAKES_ONE_ARG */
end_comment

begin_comment
comment|/* Define to the name of the distribution.  */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"gcc"
end_define

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
comment|/* Define if you have the vprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
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
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
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
comment|/* Define if `sys_siglist' is declared by<signal.h>.  */
end_comment

begin_define
define|#
directive|define
name|SYS_SIGLIST_DECLARED
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
comment|/* Define if you have the atoll function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ATOLL */
end_comment

begin_comment
comment|/* Define if you have the atoq function.  */
end_comment

begin_comment
comment|/* #undef HAVE_ATOQ */
end_comment

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
comment|/* Define if you have the dcgettext function.  */
end_comment

begin_comment
comment|/* #undef HAVE_DCGETTEXT */
end_comment

begin_comment
comment|/* Define if you have the fputc_unlocked function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FPUTC_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the fputs_unlocked function.  */
end_comment

begin_comment
comment|/* #undef HAVE_FPUTS_UNLOCKED */
end_comment

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
comment|/* Define if you have the getrlimit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRLIMIT
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
comment|/* Define if you have the isascii function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISASCII
value|1
end_define

begin_comment
comment|/* Define if you have the kill function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_KILL
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
comment|/* Define if you have the popen function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_POPEN
value|1
end_define

begin_comment
comment|/* Define if you have the putc_unlocked function.  */
end_comment

begin_comment
comment|/* #undef HAVE_PUTC_UNLOCKED */
end_comment

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
comment|/* Define if you have the rindex function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RINDEX
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
comment|/* Define if you have the setlocale function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define if you have the setrlimit function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETRLIMIT
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
comment|/* Define if you have the<argz.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_H */
end_comment

begin_comment
comment|/* Define if you have the<direct.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_DIRECT_H */
end_comment

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
comment|/* Define if you have the<nl_types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stab.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STAB_H
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
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
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
comment|/* Define if you have the<sys/times.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIMES_H
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
comment|/* Define if you have the i library (-li).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBI */
end_comment

end_unit

