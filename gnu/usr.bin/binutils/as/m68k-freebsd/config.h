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
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.  STACK_DIRECTION> 0 => grows toward higher addresses  STACK_DIRECTION< 0 => grows toward lower addresses  STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

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
comment|/* Name of package.  */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"gas"
end_define

begin_comment
comment|/* Version of package.  */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"2.9.1"
end_define

begin_comment
comment|/* Should gas use high-level BFD interfaces?  */
end_comment

begin_define
define|#
directive|define
name|BFD_ASSEMBLER
value|1
end_define

begin_comment
comment|/* Some assert/preprocessor combinations are incapable of handling    certain kinds of constructs in the argument of assert.  For example,    quoted strings (if requoting isn't done right) or newlines.  */
end_comment

begin_comment
comment|/* #undef BROKEN_ASSERT */
end_comment

begin_comment
comment|/* If we aren't doing cross-assembling, some operations can be optimized,    since byte orders and value sizes don't need to be adjusted.  */
end_comment

begin_define
define|#
directive|define
name|CROSS_COMPILE
value|1
end_define

begin_comment
comment|/* Some gas code wants to know these parameters.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ALIAS
value|"m68k-unknown-freebsd"
end_define

begin_define
define|#
directive|define
name|TARGET_CPU
value|"m68k"
end_define

begin_define
define|#
directive|define
name|TARGET_CANONICAL
value|"m68k-unknown-freebsd"
end_define

begin_define
define|#
directive|define
name|TARGET_OS
value|"freebsd"
end_define

begin_define
define|#
directive|define
name|TARGET_VENDOR
value|"unknown"
end_define

begin_comment
comment|/* Sometimes the system header files don't declare strstr.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRSTR */
end_comment

begin_comment
comment|/* Sometimes the system header files don't declare malloc and realloc.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_MALLOC */
end_comment

begin_comment
comment|/* Sometimes the system header files don't declare free.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_FREE */
end_comment

begin_comment
comment|/* Sometimes the system header files don't declare sbrk.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_SBRK */
end_comment

begin_comment
comment|/* Sometimes errno.h doesn't declare errno itself.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_ERRNO */
end_comment

begin_define
define|#
directive|define
name|MANY_SEGMENTS
value|1
end_define

begin_comment
comment|/* The configure script defines this for some targets based on the    target name used.  It is not always defined.  */
end_comment

begin_comment
comment|/* #undef TARGET_BYTES_BIG_ENDIAN */
end_comment

begin_comment
comment|/* Needed only for some configurations that can produce multiple output    formats.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_EMULATION
value|""
end_define

begin_define
define|#
directive|define
name|EMULATIONS
end_define

begin_comment
comment|/* #undef USE_EMULATIONS */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_AOUT */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_BOUT */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_COFF */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_ECOFF */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_ELF */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_GENERIC */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_HP300 */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_IEEE */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_SOM */
end_comment

begin_comment
comment|/* #undef OBJ_MAYBE_VMS */
end_comment

begin_comment
comment|/* Used for some of the COFF configurations, when the COFF code needs    to select something based on the CPU type before it knows it... */
end_comment

begin_comment
comment|/* #undef I386COFF */
end_comment

begin_comment
comment|/* #undef M68KCOFF */
end_comment

begin_comment
comment|/* #undef M88KCOFF */
end_comment

begin_comment
comment|/* Using cgen code?  */
end_comment

begin_comment
comment|/* #undef USING_CGEN */
end_comment

begin_comment
comment|/* Needed only for sparc configuration.  */
end_comment

begin_comment
comment|/* #undef DEFAULT_ARCH */
end_comment

begin_comment
comment|/* Needed only for PowerPC Solaris.  */
end_comment

begin_comment
comment|/* #undef TARGET_SOLARIS_COMMENT */
end_comment

begin_comment
comment|/* Needed only for SCO 5.  */
end_comment

begin_comment
comment|/* #undef SCO_ELF */
end_comment

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
comment|/* Define if you have the unlink function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNLINK
value|1
end_define

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
comment|/* Define if you have the<memory.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
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
comment|/* Define if you have the<varargs.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VARARGS_H
value|1
end_define

end_unit

