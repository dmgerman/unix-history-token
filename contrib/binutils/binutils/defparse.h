begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A Bison parser, made by GNU Bison 2.1.  */
end_comment

begin_comment
comment|/* Skeleton parser for Yacc-like parsing with Bison,    Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, when this file is copied by Bison into a    Bison output file, you may use that output file without restriction.    This special exception was added by the Free Software Foundation    in version 1.24 of Bison.  */
end_comment

begin_comment
comment|/* Tokens.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|YYTOKENTYPE
end_ifndef

begin_define
define|#
directive|define
name|YYTOKENTYPE
end_define

begin_comment
comment|/* Put the tokens into the symbol table, so that GDB and other debuggers       know about them.  */
end_comment

begin_enum
enum|enum
name|yytokentype
block|{
name|NAME
init|=
literal|258
block|,
name|LIBRARY
init|=
literal|259
block|,
name|DESCRIPTION
init|=
literal|260
block|,
name|STACKSIZE
init|=
literal|261
block|,
name|HEAPSIZE
init|=
literal|262
block|,
name|CODE
init|=
literal|263
block|,
name|DATA
init|=
literal|264
block|,
name|SECTIONS
init|=
literal|265
block|,
name|EXPORTS
init|=
literal|266
block|,
name|IMPORTS
init|=
literal|267
block|,
name|VERSIONK
init|=
literal|268
block|,
name|BASE
init|=
literal|269
block|,
name|CONSTANT
init|=
literal|270
block|,
name|READ
init|=
literal|271
block|,
name|WRITE
init|=
literal|272
block|,
name|EXECUTE
init|=
literal|273
block|,
name|SHARED
init|=
literal|274
block|,
name|NONSHARED
init|=
literal|275
block|,
name|NONAME
init|=
literal|276
block|,
name|PRIVATE
init|=
literal|277
block|,
name|SINGLE
init|=
literal|278
block|,
name|MULTIPLE
init|=
literal|279
block|,
name|INITINSTANCE
init|=
literal|280
block|,
name|INITGLOBAL
init|=
literal|281
block|,
name|TERMINSTANCE
init|=
literal|282
block|,
name|TERMGLOBAL
init|=
literal|283
block|,
name|ID
init|=
literal|284
block|,
name|NUMBER
init|=
literal|285
block|}
enum|;
end_enum

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Tokens.  */
end_comment

begin_define
define|#
directive|define
name|NAME
value|258
end_define

begin_define
define|#
directive|define
name|LIBRARY
value|259
end_define

begin_define
define|#
directive|define
name|DESCRIPTION
value|260
end_define

begin_define
define|#
directive|define
name|STACKSIZE
value|261
end_define

begin_define
define|#
directive|define
name|HEAPSIZE
value|262
end_define

begin_define
define|#
directive|define
name|CODE
value|263
end_define

begin_define
define|#
directive|define
name|DATA
value|264
end_define

begin_define
define|#
directive|define
name|SECTIONS
value|265
end_define

begin_define
define|#
directive|define
name|EXPORTS
value|266
end_define

begin_define
define|#
directive|define
name|IMPORTS
value|267
end_define

begin_define
define|#
directive|define
name|VERSIONK
value|268
end_define

begin_define
define|#
directive|define
name|BASE
value|269
end_define

begin_define
define|#
directive|define
name|CONSTANT
value|270
end_define

begin_define
define|#
directive|define
name|READ
value|271
end_define

begin_define
define|#
directive|define
name|WRITE
value|272
end_define

begin_define
define|#
directive|define
name|EXECUTE
value|273
end_define

begin_define
define|#
directive|define
name|SHARED
value|274
end_define

begin_define
define|#
directive|define
name|NONSHARED
value|275
end_define

begin_define
define|#
directive|define
name|NONAME
value|276
end_define

begin_define
define|#
directive|define
name|PRIVATE
value|277
end_define

begin_define
define|#
directive|define
name|SINGLE
value|278
end_define

begin_define
define|#
directive|define
name|MULTIPLE
value|279
end_define

begin_define
define|#
directive|define
name|INITINSTANCE
value|280
end_define

begin_define
define|#
directive|define
name|INITGLOBAL
value|281
end_define

begin_define
define|#
directive|define
name|TERMINSTANCE
value|282
end_define

begin_define
define|#
directive|define
name|TERMGLOBAL
value|283
end_define

begin_define
define|#
directive|define
name|ID
value|284
end_define

begin_define
define|#
directive|define
name|NUMBER
value|285
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|YYSTYPE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|YYSTYPE_IS_DECLARED
argument_list|)
end_if

begin_line
line|#
directive|line
number|27
file|"defparse.y"
end_line

begin_typedef
typedef|typedef
union|union
name|YYSTYPE
block|{
name|char
modifier|*
name|id
decl_stmt|;
name|int
name|number
decl_stmt|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_comment
comment|/* Line 1447 of yacc.c.  */
end_comment

begin_line
line|#
directive|line
number|103
file|"defparse.h"
end_line

begin_define
define|#
directive|define
name|yystype
value|YYSTYPE
end_define

begin_comment
comment|/* obsolescent; will be withdrawn */
end_comment

begin_define
define|#
directive|define
name|YYSTYPE_IS_DECLARED
value|1
end_define

begin_define
define|#
directive|define
name|YYSTYPE_IS_TRIVIAL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

