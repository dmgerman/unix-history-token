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
name|NEWLINE
init|=
literal|258
block|,
name|VERBOSE
init|=
literal|259
block|,
name|FILENAME
init|=
literal|260
block|,
name|ADDLIB
init|=
literal|261
block|,
name|LIST
init|=
literal|262
block|,
name|ADDMOD
init|=
literal|263
block|,
name|CLEAR
init|=
literal|264
block|,
name|CREATE
init|=
literal|265
block|,
name|DELETE
init|=
literal|266
block|,
name|DIRECTORY
init|=
literal|267
block|,
name|END
init|=
literal|268
block|,
name|EXTRACT
init|=
literal|269
block|,
name|FULLDIR
init|=
literal|270
block|,
name|HELP
init|=
literal|271
block|,
name|QUIT
init|=
literal|272
block|,
name|REPLACE
init|=
literal|273
block|,
name|SAVE
init|=
literal|274
block|,
name|OPEN
init|=
literal|275
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
name|NEWLINE
value|258
end_define

begin_define
define|#
directive|define
name|VERBOSE
value|259
end_define

begin_define
define|#
directive|define
name|FILENAME
value|260
end_define

begin_define
define|#
directive|define
name|ADDLIB
value|261
end_define

begin_define
define|#
directive|define
name|LIST
value|262
end_define

begin_define
define|#
directive|define
name|ADDMOD
value|263
end_define

begin_define
define|#
directive|define
name|CLEAR
value|264
end_define

begin_define
define|#
directive|define
name|CREATE
value|265
end_define

begin_define
define|#
directive|define
name|DELETE
value|266
end_define

begin_define
define|#
directive|define
name|DIRECTORY
value|267
end_define

begin_define
define|#
directive|define
name|END
value|268
end_define

begin_define
define|#
directive|define
name|EXTRACT
value|269
end_define

begin_define
define|#
directive|define
name|FULLDIR
value|270
end_define

begin_define
define|#
directive|define
name|HELP
value|271
end_define

begin_define
define|#
directive|define
name|QUIT
value|272
end_define

begin_define
define|#
directive|define
name|REPLACE
value|273
end_define

begin_define
define|#
directive|define
name|SAVE
value|274
end_define

begin_define
define|#
directive|define
name|OPEN
value|275
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
number|37
file|"arparse.y"
end_line

begin_typedef
typedef|typedef
union|union
name|YYSTYPE
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|struct
name|list
modifier|*
name|list
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
number|84
file|"arparse.h"
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

