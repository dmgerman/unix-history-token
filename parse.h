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
name|CHAR
init|=
literal|258
block|,
name|NUMBER
init|=
literal|259
block|,
name|SECTEND
init|=
literal|260
block|,
name|SCDECL
init|=
literal|261
block|,
name|XSCDECL
init|=
literal|262
block|,
name|NAME
init|=
literal|263
block|,
name|PREVCCL
init|=
literal|264
block|,
name|EOF_OP
init|=
literal|265
block|,
name|OPTION_OP
init|=
literal|266
block|,
name|OPT_OUTFILE
init|=
literal|267
block|,
name|OPT_PREFIX
init|=
literal|268
block|,
name|OPT_YYCLASS
init|=
literal|269
block|,
name|OPT_HEADER
init|=
literal|270
block|,
name|OPT_EXTRA_TYPE
init|=
literal|271
block|,
name|OPT_TABLES
init|=
literal|272
block|,
name|CCE_ALNUM
init|=
literal|273
block|,
name|CCE_ALPHA
init|=
literal|274
block|,
name|CCE_BLANK
init|=
literal|275
block|,
name|CCE_CNTRL
init|=
literal|276
block|,
name|CCE_DIGIT
init|=
literal|277
block|,
name|CCE_GRAPH
init|=
literal|278
block|,
name|CCE_LOWER
init|=
literal|279
block|,
name|CCE_PRINT
init|=
literal|280
block|,
name|CCE_PUNCT
init|=
literal|281
block|,
name|CCE_SPACE
init|=
literal|282
block|,
name|CCE_UPPER
init|=
literal|283
block|,
name|CCE_XDIGIT
init|=
literal|284
block|,
name|CCE_NEG_ALNUM
init|=
literal|285
block|,
name|CCE_NEG_ALPHA
init|=
literal|286
block|,
name|CCE_NEG_BLANK
init|=
literal|287
block|,
name|CCE_NEG_CNTRL
init|=
literal|288
block|,
name|CCE_NEG_DIGIT
init|=
literal|289
block|,
name|CCE_NEG_GRAPH
init|=
literal|290
block|,
name|CCE_NEG_LOWER
init|=
literal|291
block|,
name|CCE_NEG_PRINT
init|=
literal|292
block|,
name|CCE_NEG_PUNCT
init|=
literal|293
block|,
name|CCE_NEG_SPACE
init|=
literal|294
block|,
name|CCE_NEG_UPPER
init|=
literal|295
block|,
name|CCE_NEG_XDIGIT
init|=
literal|296
block|,
name|CCL_OP_UNION
init|=
literal|297
block|,
name|CCL_OP_DIFF
init|=
literal|298
block|,
name|BEGIN_REPEAT_POSIX
init|=
literal|299
block|,
name|END_REPEAT_POSIX
init|=
literal|300
block|,
name|BEGIN_REPEAT_FLEX
init|=
literal|301
block|,
name|END_REPEAT_FLEX
init|=
literal|302
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
name|CHAR
value|258
end_define

begin_define
define|#
directive|define
name|NUMBER
value|259
end_define

begin_define
define|#
directive|define
name|SECTEND
value|260
end_define

begin_define
define|#
directive|define
name|SCDECL
value|261
end_define

begin_define
define|#
directive|define
name|XSCDECL
value|262
end_define

begin_define
define|#
directive|define
name|NAME
value|263
end_define

begin_define
define|#
directive|define
name|PREVCCL
value|264
end_define

begin_define
define|#
directive|define
name|EOF_OP
value|265
end_define

begin_define
define|#
directive|define
name|OPTION_OP
value|266
end_define

begin_define
define|#
directive|define
name|OPT_OUTFILE
value|267
end_define

begin_define
define|#
directive|define
name|OPT_PREFIX
value|268
end_define

begin_define
define|#
directive|define
name|OPT_YYCLASS
value|269
end_define

begin_define
define|#
directive|define
name|OPT_HEADER
value|270
end_define

begin_define
define|#
directive|define
name|OPT_EXTRA_TYPE
value|271
end_define

begin_define
define|#
directive|define
name|OPT_TABLES
value|272
end_define

begin_define
define|#
directive|define
name|CCE_ALNUM
value|273
end_define

begin_define
define|#
directive|define
name|CCE_ALPHA
value|274
end_define

begin_define
define|#
directive|define
name|CCE_BLANK
value|275
end_define

begin_define
define|#
directive|define
name|CCE_CNTRL
value|276
end_define

begin_define
define|#
directive|define
name|CCE_DIGIT
value|277
end_define

begin_define
define|#
directive|define
name|CCE_GRAPH
value|278
end_define

begin_define
define|#
directive|define
name|CCE_LOWER
value|279
end_define

begin_define
define|#
directive|define
name|CCE_PRINT
value|280
end_define

begin_define
define|#
directive|define
name|CCE_PUNCT
value|281
end_define

begin_define
define|#
directive|define
name|CCE_SPACE
value|282
end_define

begin_define
define|#
directive|define
name|CCE_UPPER
value|283
end_define

begin_define
define|#
directive|define
name|CCE_XDIGIT
value|284
end_define

begin_define
define|#
directive|define
name|CCE_NEG_ALNUM
value|285
end_define

begin_define
define|#
directive|define
name|CCE_NEG_ALPHA
value|286
end_define

begin_define
define|#
directive|define
name|CCE_NEG_BLANK
value|287
end_define

begin_define
define|#
directive|define
name|CCE_NEG_CNTRL
value|288
end_define

begin_define
define|#
directive|define
name|CCE_NEG_DIGIT
value|289
end_define

begin_define
define|#
directive|define
name|CCE_NEG_GRAPH
value|290
end_define

begin_define
define|#
directive|define
name|CCE_NEG_LOWER
value|291
end_define

begin_define
define|#
directive|define
name|CCE_NEG_PRINT
value|292
end_define

begin_define
define|#
directive|define
name|CCE_NEG_PUNCT
value|293
end_define

begin_define
define|#
directive|define
name|CCE_NEG_SPACE
value|294
end_define

begin_define
define|#
directive|define
name|CCE_NEG_UPPER
value|295
end_define

begin_define
define|#
directive|define
name|CCE_NEG_XDIGIT
value|296
end_define

begin_define
define|#
directive|define
name|CCL_OP_UNION
value|297
end_define

begin_define
define|#
directive|define
name|CCL_OP_DIFF
value|298
end_define

begin_define
define|#
directive|define
name|BEGIN_REPEAT_POSIX
value|299
end_define

begin_define
define|#
directive|define
name|END_REPEAT_POSIX
value|300
end_define

begin_define
define|#
directive|define
name|BEGIN_REPEAT_FLEX
value|301
end_define

begin_define
define|#
directive|define
name|END_REPEAT_FLEX
value|302
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

begin_typedef
typedef|typedef
name|int
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
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

