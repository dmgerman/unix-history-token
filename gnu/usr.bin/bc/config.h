begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define if you don't have vprintf but do have _doprnt.  */
end_comment

begin_comment
comment|/* #undef HAVE_DOPRNT */
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
comment|/* Define to `unsigned' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef size_t */
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
comment|/* VERSION number for DC target*/
end_comment

begin_define
define|#
directive|define
name|DC_VERSION
value|"1.3"
end_define

begin_comment
comment|/* COPYRIGHT notice for DC target */
end_comment

begin_define
define|#
directive|define
name|DC_COPYRIGHT
value|"Copyright 1994, 1997, 1998, 2000 Free Software Foundation, Inc."
end_define

begin_comment
comment|/* COPYRIGHT notice for BC target */
end_comment

begin_define
define|#
directive|define
name|BC_COPYRIGHT
value|"Copyright 1991-1994, 1997, 1998, 2000 Free Software Foundation, Inc."
end_define

begin_comment
comment|/* Define to use the readline library. */
end_comment

begin_define
define|#
directive|define
name|READLINE
value|1
end_define

begin_comment
comment|/* Define to use the BSD libedit library. */
end_comment

begin_comment
comment|/* #undef LIBEDIT */
end_comment

begin_comment
comment|/* Define to `size_t' if<sys/types.h> and<stddef.h> don't define.  */
end_comment

begin_comment
comment|/* #undef ptrdiff_t */
end_comment

begin_comment
comment|/* Define if you have the isgraph function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISGRAPH
value|1
end_define

begin_comment
comment|/* Define if you have the setvbuf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETVBUF
value|1
end_define

begin_comment
comment|/* Define if you have the<lib.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_LIB_H */
end_comment

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
comment|/* Define if you have the<stdarg.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
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
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"bc"
end_define

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"1.06"
end_define

end_unit

