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
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
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
comment|/* Define if lex declares yytext as a char * by default, not a char[].  */
end_comment

begin_define
define|#
directive|define
name|YYTEXT_POINTER
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
comment|/* Define if you have the remove function.  */
end_comment

begin_comment
comment|/* #undef HAVE_REMOVE */
end_comment

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
comment|/* Define if you have the unlink function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNLINK
value|1
end_define

begin_comment
comment|/* Define if you have the<argz.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_H */
end_comment

begin_comment
comment|/* Define if you have the<errno.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
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
comment|/* Define if you have the<memory.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

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
comment|/* Define if you have the<stdarg.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
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
comment|/* Define if you have the<sys/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
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
comment|/* Define if you have the<varargs.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VARARGS_H
value|1
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"gas"
end_define

begin_comment
comment|/* Version number of package */
end_comment

begin_comment
comment|/* #define VERSION "2.12" */
end_comment

begin_comment
comment|/* Define if defaulting to ELF on SCO 5. */
end_comment

begin_comment
comment|/* #undef SCO_ELF */
end_comment

begin_comment
comment|/* Using strict COFF? */
end_comment

begin_comment
comment|/* #undef STRICTCOFF */
end_comment

begin_comment
comment|/* Define if default target is PowerPC Solaris. */
end_comment

begin_comment
comment|/* #undef TARGET_SOLARIS_COMMENT */
end_comment

begin_comment
comment|/* Define as 1 if big endian. */
end_comment

begin_comment
comment|/* #undef TARGET_BYTES_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Use ELF stabs for MIPS, not ECOFF stabs */
end_comment

begin_comment
comment|/* #undef MIPS_STABS_ELF */
end_comment

begin_comment
comment|/* Default architecture. */
end_comment

begin_comment
comment|/* #undef DEFAULT_ARCH */
end_comment

begin_comment
comment|/* Using cgen code? */
end_comment

begin_comment
comment|/* #undef USING_CGEN */
end_comment

begin_comment
comment|/* Using i386 COFF? */
end_comment

begin_comment
comment|/* #undef I386COFF */
end_comment

begin_comment
comment|/* Using m68k COFF? */
end_comment

begin_comment
comment|/* #undef M68KCOFF */
end_comment

begin_comment
comment|/* Using m88k COFF? */
end_comment

begin_comment
comment|/* #undef M88KCOFF */
end_comment

begin_comment
comment|/* a.out support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_AOUT */
end_comment

begin_comment
comment|/* b.out support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_BOUT */
end_comment

begin_comment
comment|/* COFF support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_COFF */
end_comment

begin_comment
comment|/* ECOFF support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_ECOFF */
end_comment

begin_comment
comment|/* ELF support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_ELF */
end_comment

begin_comment
comment|/* generic support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_GENERIC */
end_comment

begin_comment
comment|/* HP300 support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_HP300 */
end_comment

begin_comment
comment|/* IEEE support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_IEEE */
end_comment

begin_comment
comment|/* SOM support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_SOM */
end_comment

begin_comment
comment|/* VMS support? */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_VMS */
end_comment

begin_comment
comment|/* Use emulation support? */
end_comment

begin_comment
comment|/* #undef USE_EMULATIONS */
end_comment

begin_comment
comment|/* Supported emulations. */
end_comment

begin_define
define|#
directive|define
name|EMULATIONS
end_define

begin_comment
comment|/* Default emulation. */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_EMULATION
value|""
end_define

begin_comment
comment|/* old COFF support? */
end_comment

begin_comment
comment|/* #undef MANY_SEGMENTS */
end_comment

begin_comment
comment|/* Use BFD interface? */
end_comment

begin_define
define|#
directive|define
name|BFD_ASSEMBLER
value|1
end_define

begin_comment
comment|/* Target alias. */
end_comment

begin_define
define|#
directive|define
name|TARGET_ALIAS
value|"alpha-obrien-freebsd5.0"
end_define

begin_comment
comment|/* Canonical target. */
end_comment

begin_define
define|#
directive|define
name|TARGET_CANONICAL
value|"alpha-obrien-freebsd5.0"
end_define

begin_comment
comment|/* Target CPU. */
end_comment

begin_define
define|#
directive|define
name|TARGET_CPU
value|"alpha"
end_define

begin_comment
comment|/* Target vendor. */
end_comment

begin_define
define|#
directive|define
name|TARGET_VENDOR
value|"obrien"
end_define

begin_comment
comment|/* Target OS. */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS
value|"freebsd5.0"
end_define

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
comment|/* Compiling cross-assembler? */
end_comment

begin_comment
comment|/* #undef CROSS_COMPILE */
end_comment

begin_comment
comment|/* assert broken? */
end_comment

begin_comment
comment|/* #undef BROKEN_ASSERT */
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
comment|/* Define if free is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_FREE */
end_comment

begin_comment
comment|/* Define if sbrk is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_SBRK */
end_comment

begin_comment
comment|/* Define if environ is not declared in system header files. */
end_comment

begin_define
define|#
directive|define
name|NEED_DECLARATION_ENVIRON
value|1
end_define

begin_comment
comment|/* Define if errno is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_ERRNO */
end_comment

end_unit

