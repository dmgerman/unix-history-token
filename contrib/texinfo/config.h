begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.in.  Generated automatically from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* acconfig.h    This file is in the public domain.    $Id: acconfig.h,v 1.3 1998/12/06 22:04:03 karl Exp $     Descriptive text for the C preprocessor macros that    the distributed Autoconf macros can define.    No software package will use all of them; autoheader copies the ones    your configure.in uses into your configuration header file templates.     The entries are in sort -df order: alphabetical, case insensitive,    ignoring punctuation (such as underscores).  Although this order    can split up related entries, it makes it easier to check whether    a given entry is in the file.     Leave the following blank line there!!  Autoheader needs it.  */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Define to 1 if including sys/ioctl.h is needed to get TIOCGWINSZ. */
end_comment

begin_comment
comment|/* #undef GWINSZ_IN_SYS_IOCTL */
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
comment|/* Define if your locale.h file contains LC_MESSAGES.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LC_MESSAGES
value|1
end_define

begin_comment
comment|/* Define as 1 if you have the stpcpy function.  */
end_comment

begin_comment
comment|/* #undef HAVE_STPCPY */
end_comment

begin_comment
comment|/* Define to the name of the distribution.  */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"texinfo"
end_define

begin_comment
comment|/* Define to the version of the distribution.  */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"4.1"
end_define

begin_comment
comment|/* Define to one of `_getb67', `GETB67', `getb67' for Cray-2 and Cray-YMP    systems. This function is required for `alloca.c' support on those systems.    */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define if using `alloca.c'. */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to 1 if translation of program messages to the user's native    language is requested. */
end_comment

begin_comment
comment|/* #undef ENABLE_NLS */
end_comment

begin_comment
comment|/* Define if `TIOCGWINSZ' requires<sys/ioctl.h> */
end_comment

begin_comment
comment|/* #undef GWINSZ_IN_SYS_IOCTL */
end_comment

begin_comment
comment|/* Define if you have `alloca', as a function or macro. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix). */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define if you have the<argz.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_H */
end_comment

begin_comment
comment|/* Define if you have the `bzero' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_BZERO
value|1
end_define

begin_comment
comment|/* Define if the GNU dcgettext() function is already present or preinstalled.    */
end_comment

begin_comment
comment|/* #undef HAVE_DCGETTEXT */
end_comment

begin_comment
comment|/* Define if this function is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if this function is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRCOLL
value|1
end_define

begin_comment
comment|/* Define if this function is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRERROR
value|1
end_define

begin_comment
comment|/* Define if this function is declared. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DECL_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you don't have `vprintf' but do have `_doprnt.' */
end_comment

begin_comment
comment|/* #undef HAVE_DOPRNT */
end_comment

begin_comment
comment|/* Define if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the `feof_unlocked' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FEOF_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the `fgets_unlocked' function. */
end_comment

begin_comment
comment|/* #undef HAVE_FGETS_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the `getcwd' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
value|1
end_define

begin_comment
comment|/* Define if you have the `getc_unlocked' function. */
end_comment

begin_comment
comment|/* #undef HAVE_GETC_UNLOCKED */
end_comment

begin_comment
comment|/* Define if you have the `getegid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEGID
value|1
end_define

begin_comment
comment|/* Define if you have the `geteuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETEUID
value|1
end_define

begin_comment
comment|/* Define if you have the `getgid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETGID
value|1
end_define

begin_comment
comment|/* Define if you have the `getpagesize' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if the GNU gettext() function is already present or preinstalled. */
end_comment

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Define if you have the `getuid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETUID
value|1
end_define

begin_comment
comment|/* Define if you have the iconv() function. */
end_comment

begin_comment
comment|/* #undef HAVE_ICONV */
end_comment

begin_comment
comment|/* Define if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<io.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_IO_H */
end_comment

begin_comment
comment|/* Define if you have<langinfo.h> and nl_langinfo(CODESET). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LANGINFO_CODESET
value|1
end_define

begin_comment
comment|/* Define if your<locale.h> file defines LC_MESSAGES. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LC_MESSAGES
value|1
end_define

begin_comment
comment|/* Define if you have the `bsd' library (-lbsd). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBBSD */
end_comment

begin_comment
comment|/* Define if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<locale.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<malloc.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define if you have the `memcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCPY
value|1
end_define

begin_comment
comment|/* Define if you have the `memmove' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the `mempcpy' function. */
end_comment

begin_comment
comment|/* #undef HAVE_MEMPCPY */
end_comment

begin_comment
comment|/* Define if you have the `memset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define if you have a working `mmap' system call. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define if you have the `munmap' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MUNMAP
value|1
end_define

begin_comment
comment|/* Define if you have the<ncurses/termcap.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_NCURSES_TERMCAP_H */
end_comment

begin_comment
comment|/* Define if you have the<nl_types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the `putenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define if you have the<pwd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PWD_H
value|1
end_define

begin_comment
comment|/* Define if you have the `setenv' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if you have the `setlocale' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define if you have the `setvbuf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETVBUF
value|1
end_define

begin_comment
comment|/* Define if you have the `sigprocmask' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGPROCMASK
value|1
end_define

begin_comment
comment|/* Define if you have the `sigsetmask' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSETMASK
value|1
end_define

begin_comment
comment|/* Define if you have the<stddef.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the `stpcpy' function. */
end_comment

begin_comment
comment|/* #undef HAVE_STPCPY */
end_comment

begin_comment
comment|/* Define if you have the `strcasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the `strchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define if you have the `strcoll' function and it is properly defined. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCOLL
value|1
end_define

begin_comment
comment|/* Define if you have the `strdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the `strncasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRNCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the `strtoul' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/file.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ptem.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTEM_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ttold.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_TTOLD_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/wait.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<termcap.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMCAP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<termios.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<termio.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_TERMIO_H */
end_comment

begin_comment
comment|/* Define if you have the `tsearch' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TSEARCH
value|1
end_define

begin_comment
comment|/* Define if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the `vprintf' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the `__argz_count' function. */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_COUNT */
end_comment

begin_comment
comment|/* Define if you have the `__argz_next' function. */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_NEXT */
end_comment

begin_comment
comment|/* Define if you have the `__argz_stringify' function. */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_STRINGIFY */
end_comment

begin_comment
comment|/* Define as const if the declaration of iconv() needs const. */
end_comment

begin_comment
comment|/* #undef ICONV_CONST */
end_comment

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"texinfo"
end_define

begin_comment
comment|/* Define as the return type of signal handlers (`int' or `void'). */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.         STACK_DIRECTION> 0 => grows toward higher addresses         STACK_DIRECTION< 0 => grows toward lower addresses         STACK_DIRECTION = 0 => direction of growth unknown */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define if the `S_IS*' macros in<sys/stat.h> do not work properly. */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if your<sys/time.h> declares `struct tm'. */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"4.1"
end_define

begin_comment
comment|/* Define if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define if the system does not provide POSIX.1 features except with this    defined. */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define if you need to in order for `stat' and other things to work. */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define as `__inline' if that's what the C compiler calls it, or to nothing    if it is not supported. */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_escape
end_escape

begin_comment
comment|/* Leave that blank line there!!  Autoheader needs it.    If you're adding to this file, keep in mind:    The entries are in sort -df order: alphabetical, case insensitive,    ignoring punctuation (such as underscores).  */
end_comment

end_unit

