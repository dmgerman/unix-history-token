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
name|CHECK
init|=
literal|258
block|,
name|CODESTART
init|=
literal|259
block|,
name|COPYRIGHT
init|=
literal|260
block|,
name|CUSTOM
init|=
literal|261
block|,
name|DATE
init|=
literal|262
block|,
name|DEBUG
init|=
literal|263
block|,
name|DESCRIPTION
init|=
literal|264
block|,
name|EXIT
init|=
literal|265
block|,
name|EXPORT
init|=
literal|266
block|,
name|FLAG_ON
init|=
literal|267
block|,
name|FLAG_OFF
init|=
literal|268
block|,
name|FULLMAP
init|=
literal|269
block|,
name|HELP
init|=
literal|270
block|,
name|IMPORT
init|=
literal|271
block|,
name|INPUT
init|=
literal|272
block|,
name|MAP
init|=
literal|273
block|,
name|MESSAGES
init|=
literal|274
block|,
name|MODULE
init|=
literal|275
block|,
name|MULTIPLE
init|=
literal|276
block|,
name|OS_DOMAIN
init|=
literal|277
block|,
name|OUTPUT
init|=
literal|278
block|,
name|PSEUDOPREEMPTION
init|=
literal|279
block|,
name|REENTRANT
init|=
literal|280
block|,
name|SCREENNAME
init|=
literal|281
block|,
name|SHARELIB
init|=
literal|282
block|,
name|STACK
init|=
literal|283
block|,
name|START
init|=
literal|284
block|,
name|SYNCHRONIZE
init|=
literal|285
block|,
name|THREADNAME
init|=
literal|286
block|,
name|TYPE
init|=
literal|287
block|,
name|VERBOSE
init|=
literal|288
block|,
name|VERSIONK
init|=
literal|289
block|,
name|XDCDATA
init|=
literal|290
block|,
name|STRING
init|=
literal|291
block|,
name|QUOTED_STRING
init|=
literal|292
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
name|CHECK
value|258
end_define

begin_define
define|#
directive|define
name|CODESTART
value|259
end_define

begin_define
define|#
directive|define
name|COPYRIGHT
value|260
end_define

begin_define
define|#
directive|define
name|CUSTOM
value|261
end_define

begin_define
define|#
directive|define
name|DATE
value|262
end_define

begin_define
define|#
directive|define
name|DEBUG
value|263
end_define

begin_define
define|#
directive|define
name|DESCRIPTION
value|264
end_define

begin_define
define|#
directive|define
name|EXIT
value|265
end_define

begin_define
define|#
directive|define
name|EXPORT
value|266
end_define

begin_define
define|#
directive|define
name|FLAG_ON
value|267
end_define

begin_define
define|#
directive|define
name|FLAG_OFF
value|268
end_define

begin_define
define|#
directive|define
name|FULLMAP
value|269
end_define

begin_define
define|#
directive|define
name|HELP
value|270
end_define

begin_define
define|#
directive|define
name|IMPORT
value|271
end_define

begin_define
define|#
directive|define
name|INPUT
value|272
end_define

begin_define
define|#
directive|define
name|MAP
value|273
end_define

begin_define
define|#
directive|define
name|MESSAGES
value|274
end_define

begin_define
define|#
directive|define
name|MODULE
value|275
end_define

begin_define
define|#
directive|define
name|MULTIPLE
value|276
end_define

begin_define
define|#
directive|define
name|OS_DOMAIN
value|277
end_define

begin_define
define|#
directive|define
name|OUTPUT
value|278
end_define

begin_define
define|#
directive|define
name|PSEUDOPREEMPTION
value|279
end_define

begin_define
define|#
directive|define
name|REENTRANT
value|280
end_define

begin_define
define|#
directive|define
name|SCREENNAME
value|281
end_define

begin_define
define|#
directive|define
name|SHARELIB
value|282
end_define

begin_define
define|#
directive|define
name|STACK
value|283
end_define

begin_define
define|#
directive|define
name|START
value|284
end_define

begin_define
define|#
directive|define
name|SYNCHRONIZE
value|285
end_define

begin_define
define|#
directive|define
name|THREADNAME
value|286
end_define

begin_define
define|#
directive|define
name|TYPE
value|287
end_define

begin_define
define|#
directive|define
name|VERBOSE
value|288
end_define

begin_define
define|#
directive|define
name|VERSIONK
value|289
end_define

begin_define
define|#
directive|define
name|XDCDATA
value|290
end_define

begin_define
define|#
directive|define
name|STRING
value|291
end_define

begin_define
define|#
directive|define
name|QUOTED_STRING
value|292
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
number|113
file|"nlmheader.y"
end_line

begin_typedef
typedef|typedef
union|union
name|YYSTYPE
block|{
name|char
modifier|*
name|string
decl_stmt|;
name|struct
name|string_list
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
number|117
file|"nlmheader.h"
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

