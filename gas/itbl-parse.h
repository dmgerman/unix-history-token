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
name|DREG
init|=
literal|258
block|,
name|CREG
init|=
literal|259
block|,
name|GREG
init|=
literal|260
block|,
name|IMMED
init|=
literal|261
block|,
name|ADDR
init|=
literal|262
block|,
name|INSN
init|=
literal|263
block|,
name|NUM
init|=
literal|264
block|,
name|ID
init|=
literal|265
block|,
name|NL
init|=
literal|266
block|,
name|PNUM
init|=
literal|267
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
name|DREG
value|258
end_define

begin_define
define|#
directive|define
name|CREG
value|259
end_define

begin_define
define|#
directive|define
name|GREG
value|260
end_define

begin_define
define|#
directive|define
name|IMMED
value|261
end_define

begin_define
define|#
directive|define
name|ADDR
value|262
end_define

begin_define
define|#
directive|define
name|INSN
value|263
end_define

begin_define
define|#
directive|define
name|NUM
value|264
end_define

begin_define
define|#
directive|define
name|ID
value|265
end_define

begin_define
define|#
directive|define
name|NL
value|266
end_define

begin_define
define|#
directive|define
name|PNUM
value|267
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
number|282
file|"itbl-parse.y"
end_line

begin_typedef
typedef|typedef
union|union
name|YYSTYPE
block|{
name|char
modifier|*
name|str
decl_stmt|;
name|int
name|num
decl_stmt|;
name|int
name|processor
decl_stmt|;
name|unsigned
name|long
name|val
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
number|69
file|"itbl-parse.h"
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

