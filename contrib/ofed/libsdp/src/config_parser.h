begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* A Bison parser, made by GNU Bison 2.3.  */
end_comment

begin_comment
comment|/* Skeleton interface for Bison's Yacc-like parsers in C     Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006    Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 51 Franklin Street, Fifth Floor,    Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* As a special exception, you may create a larger work that contains    part or all of the Bison parser skeleton and distribute that work    under terms of your choice, so long as that work isn't itself a    parser generator using the skeleton or a modified version thereof    as a parser skeleton.  Alternatively, if you modify or redistribute    the parser skeleton itself, you may (at your option) remove this    special exception, which will cause the skeleton and the resulting    Bison output files to be licensed under the GNU General Public    License without this special exception.     This special exception was added by the Free Software Foundation in    version 2.2 of Bison.  */
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
name|USE
init|=
literal|258
block|,
name|CLIENT
init|=
literal|259
block|,
name|SERVER
init|=
literal|260
block|,
name|TCP
init|=
literal|261
block|,
name|SDP
init|=
literal|262
block|,
name|BOTH
init|=
literal|263
block|,
name|INT
init|=
literal|264
block|,
name|LOG
init|=
literal|265
block|,
name|DEST
init|=
literal|266
block|,
name|STDERR
init|=
literal|267
block|,
name|SYSLOG
init|=
literal|268
block|,
name|FILENAME
init|=
literal|269
block|,
name|NAME
init|=
literal|270
block|,
name|LEVEL
init|=
literal|271
block|,
name|LINE
init|=
literal|272
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
name|USE
value|258
end_define

begin_define
define|#
directive|define
name|CLIENT
value|259
end_define

begin_define
define|#
directive|define
name|SERVER
value|260
end_define

begin_define
define|#
directive|define
name|TCP
value|261
end_define

begin_define
define|#
directive|define
name|SDP
value|262
end_define

begin_define
define|#
directive|define
name|BOTH
value|263
end_define

begin_define
define|#
directive|define
name|INT
value|264
end_define

begin_define
define|#
directive|define
name|LOG
value|265
end_define

begin_define
define|#
directive|define
name|DEST
value|266
end_define

begin_define
define|#
directive|define
name|STDERR
value|267
end_define

begin_define
define|#
directive|define
name|SYSLOG
value|268
end_define

begin_define
define|#
directive|define
name|FILENAME
value|269
end_define

begin_define
define|#
directive|define
name|NAME
value|270
end_define

begin_define
define|#
directive|define
name|LEVEL
value|271
end_define

begin_define
define|#
directive|define
name|LINE
value|272
end_define

begin_if
if|#
directive|if
operator|!
name|defined
name|YYSTYPE
operator|&&
operator|!
name|defined
name|YYSTYPE_IS_DECLARED
end_if

begin_typedef
typedef|typedef
union|union
name|YYSTYPE
line|#
directive|line
number|167
file|"./config_parser.y"
block|{
name|int
name|ival
decl_stmt|;
name|char
modifier|*
name|sval
decl_stmt|;
block|}
comment|/* Line 1529 of yacc.c.  */
line|#
directive|line
number|88
file|"y.tab.h"
name|YYSTYPE
typedef|;
end_typedef

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
name|libsdp_yylval
decl_stmt|;
end_decl_stmt

end_unit

