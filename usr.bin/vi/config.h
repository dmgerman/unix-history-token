begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: config.h.in,v 9.5 2013/03/11 01:20:53 zy Exp $ */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Define if you want a debugging version. */
end_comment

begin_comment
comment|/* #undef DEBUG */
end_comment

begin_comment
comment|/* Define when using wide characters */
end_comment

begin_comment
comment|/* #define USE_WIDECHAR set by Makefile */
end_comment

begin_comment
comment|/* Define when iconv can be used */
end_comment

begin_comment
comment|/* #define USE_ICONV set by Makefile */
end_comment

begin_comment
comment|/* Define when the 2nd argument of iconv(3) is not const */
end_comment

begin_comment
comment|/* #undef ICONV_TRADITIONAL */
end_comment

begin_comment
comment|/* Define if you have<libutil.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBUTIL_H
end_define

begin_comment
comment|/* Define if you have<ncurses.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_NCURSES_H
end_define

begin_comment
comment|/* Define if you have<term.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERM_H
end_define

end_unit

