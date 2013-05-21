begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated from conf.in by configure.  */
end_comment

begin_comment
comment|/* conf.in.  Generated from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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
comment|/* Define to 1 if translation of program messages to the user's native    language is requested. */
end_comment

begin_comment
comment|/* #undef ENABLE_NLS */
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
comment|/* Define if the GNU dcgettext() function is already present or preinstalled.    */
end_comment

begin_comment
comment|/* #undef HAVE_DCGETTEXT */
end_comment

begin_comment
comment|/* Define to 1 if you have the `dup2' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DUP2
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FORK
value|1
end_define

begin_comment
comment|/* Define if the GNU gettext() function is already present or preinstalled. */
end_comment

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Define if you have the iconv() function. */
end_comment

begin_comment
comment|/* #undef HAVE_ICONV */
end_comment

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
comment|/* Define to 1 if you have the `isascii' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISASCII
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<libintl.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_LIBINTL_H */
end_comment

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
comment|/* pthread library */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBPTHREAD
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<locale.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
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
comment|/* Define to 1 if you have the<malloc.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

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
comment|/* Define to 1 if you have the `memset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<netinet/in.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NETINET_IN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `pow' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_POW
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<pthread.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PTHREAD_H
value|1
end_define

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
comment|/* Define to 1 if you have the `regcomp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGCOMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<regex.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGEX_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `setlocale' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define to 1 if stdbool.h conforms to C99. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDBOOL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stddef.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
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
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

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
comment|/* Define to 1 if you have the `strtol' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOL
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
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have<sys/wait.h> that is POSIX.1 compatible. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

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
comment|/* Define to 1 if you have the `vfork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFORK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<vfork.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define to 1 if `fork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if `vfork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_VFORK
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `_Bool'. */
end_comment

begin_define
define|#
directive|define
name|HAVE__BOOL
value|1
end_define

begin_comment
comment|/* Define to the m4 executable name. */
end_comment

begin_define
define|#
directive|define
name|M4
value|"m4"
end_define

begin_comment
comment|/* Define to 1 if your C compiler doesn't accept -c and -o together. */
end_comment

begin_comment
comment|/* #undef NO_MINUS_C_MINUS_O */
end_comment

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"flex"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|"flex-help@lists.sourceforge.net"
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"the fast lexical analyser generator"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"the fast lexical analyser generator 2.5.37"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"flex"
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
value|"2.5.37"
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
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"2.5.37"
end_define

begin_comment
comment|/* Define to 1 if `lex' declares `yytext' as a `char *' by default, not a    `char[]'. */
end_comment

begin_define
define|#
directive|define
name|YYTEXT_POINTER
value|1
end_define

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to rpl_malloc if the replacement function should be used. */
end_comment

begin_comment
comment|/* #undef malloc */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
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

begin_comment
comment|/* Define as `fork' if `vfork' does not work. */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

end_unit

