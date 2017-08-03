begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* libxo/xo_config.h.  Generated from xo_config.h.in by configure.  */
end_comment

begin_comment
comment|/* libxo/xo_config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP    systems. This function is required for `alloca.c' support on those systems.    */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define to 1 if using `alloca.c'. */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to 1 if you have `alloca', as a function or macro. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define to 1 if you have<alloca.h> and it should be used (not on Ultrix).    */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `asprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ASPRINTF
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `bzero' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BZERO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `ctime' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CTIME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ctype.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CTYPE_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the declaration of `__isthreaded', and to 0 if you    don't. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL___ISTHREADED
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `dlfunc' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFUNC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<errno.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fdopen' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FDOPEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `flock' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FLOCK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getpass' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPASS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getprogname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPROGNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `getrusage' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETRUSAGE
value|1
end_define

begin_comment
comment|/* gettext(3) */
end_comment

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `gettimeofday' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETTIMEOFDAY
value|1
end_define

begin_comment
comment|/* humanize_number(3) */
end_comment

begin_define
define|#
directive|define
name|HAVE_HUMANIZE_NUMBER
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `crypto' library (-lcrypto). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBCRYPTO
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `m' library (-lm). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBM
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<libutil.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBUTIL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if your system has a GNU libc compatible `malloc' function, and    to 0 otherwise. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MALLOC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `memmove' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<monitor.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MONITOR_H */
end_comment

begin_comment
comment|/* Support printflike */
end_comment

begin_comment
comment|/* #undef HAVE_PRINTFLIKE */
end_comment

begin_comment
comment|/* Define to 1 if your system has a GNU libc compatible `realloc' function,    and to 0 otherwise. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REALLOC
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `srand' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SRAND
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sranddev' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SRANDDEV
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdio_ext.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STDIO_EXT_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<stdio.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDIO_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdtime/tzfile.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_STDTIME_TZFILE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `strchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strcspn' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCSPN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strspn' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSPN
value|1
end_define

begin_comment
comment|/* Have struct sockaddr_un.sun_len */
end_comment

begin_define
define|#
directive|define
name|HAVE_SUN_LEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `sysctlbyname' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCTLBYNAME
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/sysctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<threads.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_THREADS_H
value|1
end_define

begin_comment
comment|/* thread-local setting */
end_comment

begin_define
define|#
directive|define
name|HAVE_THREAD_LOCAL
value|THREAD_LOCAL_before
end_define

begin_comment
comment|/* Define to 1 if you have the<tzfile.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TZFILE_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `__flbf' function. */
end_comment

begin_comment
comment|/* #undef HAVE___FLBF */
end_comment

begin_comment
comment|/* Enable debugging */
end_comment

begin_comment
comment|/* #undef LIBXO_DEBUG */
end_comment

begin_comment
comment|/* Enable text-only rendering */
end_comment

begin_comment
comment|/* #undef LIBXO_TEXT_ONLY */
end_comment

begin_comment
comment|/* Version number as dotted value */
end_comment

begin_define
define|#
directive|define
name|LIBXO_VERSION
value|"0.8.4"
end_define

begin_comment
comment|/* Version number extra information */
end_comment

begin_define
define|#
directive|define
name|LIBXO_VERSION_EXTRA
value|""
end_define

begin_comment
comment|/* Version number as a number */
end_comment

begin_define
define|#
directive|define
name|LIBXO_VERSION_NUMBER
value|8004
end_define

begin_comment
comment|/* Version number as string */
end_comment

begin_define
define|#
directive|define
name|LIBXO_VERSION_STRING
value|"8004"
end_define

begin_comment
comment|/* Enable local wcwidth implementation */
end_comment

begin_define
define|#
directive|define
name|LIBXO_WCWIDTH
value|1
end_define

begin_comment
comment|/* Define to the sub-directory where libtool stores uninstalled libraries. */
end_comment

begin_define
define|#
directive|define
name|LT_OBJDIR
value|".libs/"
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"libxo"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"phil@juniper.net"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"libxo"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"libxo 0.8.4"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"libxo"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"0.8.4"
end_define

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at runtime. 	STACK_DIRECTION> 0 => grows toward higher addresses 	STACK_DIRECTION< 0 => grows toward lower addresses 	STACK_DIRECTION = 0 => direction of growth unknown */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Use int return codes */
end_comment

begin_comment
comment|/* #undef USE_INT_RETURN_CODES */
end_comment

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"0.8.4"
end_define

begin_comment
comment|/* Retain hash bucket size */
end_comment

begin_comment
comment|/* #undef XO_RETAIN_SIZE */
end_comment

begin_comment
comment|/* Define to `__inline__' or `__inline' if that's what the C compiler    calls it, or to nothing if 'inline' is not supported under any name.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_comment
comment|/* #undef inline */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define to rpl_malloc if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef malloc */
end_comment

begin_comment
comment|/* Define to rpl_realloc if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef realloc */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

end_unit

