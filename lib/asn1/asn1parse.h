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
name|kw_ABSENT
init|=
literal|258
block|,
name|kw_ABSTRACT_SYNTAX
init|=
literal|259
block|,
name|kw_ALL
init|=
literal|260
block|,
name|kw_APPLICATION
init|=
literal|261
block|,
name|kw_AUTOMATIC
init|=
literal|262
block|,
name|kw_BEGIN
init|=
literal|263
block|,
name|kw_BIT
init|=
literal|264
block|,
name|kw_BMPString
init|=
literal|265
block|,
name|kw_BOOLEAN
init|=
literal|266
block|,
name|kw_BY
init|=
literal|267
block|,
name|kw_CHARACTER
init|=
literal|268
block|,
name|kw_CHOICE
init|=
literal|269
block|,
name|kw_CLASS
init|=
literal|270
block|,
name|kw_COMPONENT
init|=
literal|271
block|,
name|kw_COMPONENTS
init|=
literal|272
block|,
name|kw_CONSTRAINED
init|=
literal|273
block|,
name|kw_CONTAINING
init|=
literal|274
block|,
name|kw_DEFAULT
init|=
literal|275
block|,
name|kw_DEFINITIONS
init|=
literal|276
block|,
name|kw_EMBEDDED
init|=
literal|277
block|,
name|kw_ENCODED
init|=
literal|278
block|,
name|kw_END
init|=
literal|279
block|,
name|kw_ENUMERATED
init|=
literal|280
block|,
name|kw_EXCEPT
init|=
literal|281
block|,
name|kw_EXPLICIT
init|=
literal|282
block|,
name|kw_EXPORTS
init|=
literal|283
block|,
name|kw_EXTENSIBILITY
init|=
literal|284
block|,
name|kw_EXTERNAL
init|=
literal|285
block|,
name|kw_FALSE
init|=
literal|286
block|,
name|kw_FROM
init|=
literal|287
block|,
name|kw_GeneralString
init|=
literal|288
block|,
name|kw_GeneralizedTime
init|=
literal|289
block|,
name|kw_GraphicString
init|=
literal|290
block|,
name|kw_IA5String
init|=
literal|291
block|,
name|kw_IDENTIFIER
init|=
literal|292
block|,
name|kw_IMPLICIT
init|=
literal|293
block|,
name|kw_IMPLIED
init|=
literal|294
block|,
name|kw_IMPORTS
init|=
literal|295
block|,
name|kw_INCLUDES
init|=
literal|296
block|,
name|kw_INSTANCE
init|=
literal|297
block|,
name|kw_INTEGER
init|=
literal|298
block|,
name|kw_INTERSECTION
init|=
literal|299
block|,
name|kw_ISO646String
init|=
literal|300
block|,
name|kw_MAX
init|=
literal|301
block|,
name|kw_MIN
init|=
literal|302
block|,
name|kw_MINUS_INFINITY
init|=
literal|303
block|,
name|kw_NULL
init|=
literal|304
block|,
name|kw_NumericString
init|=
literal|305
block|,
name|kw_OBJECT
init|=
literal|306
block|,
name|kw_OCTET
init|=
literal|307
block|,
name|kw_OF
init|=
literal|308
block|,
name|kw_OPTIONAL
init|=
literal|309
block|,
name|kw_ObjectDescriptor
init|=
literal|310
block|,
name|kw_PATTERN
init|=
literal|311
block|,
name|kw_PDV
init|=
literal|312
block|,
name|kw_PLUS_INFINITY
init|=
literal|313
block|,
name|kw_PRESENT
init|=
literal|314
block|,
name|kw_PRIVATE
init|=
literal|315
block|,
name|kw_PrintableString
init|=
literal|316
block|,
name|kw_REAL
init|=
literal|317
block|,
name|kw_RELATIVE_OID
init|=
literal|318
block|,
name|kw_SEQUENCE
init|=
literal|319
block|,
name|kw_SET
init|=
literal|320
block|,
name|kw_SIZE
init|=
literal|321
block|,
name|kw_STRING
init|=
literal|322
block|,
name|kw_SYNTAX
init|=
literal|323
block|,
name|kw_T61String
init|=
literal|324
block|,
name|kw_TAGS
init|=
literal|325
block|,
name|kw_TRUE
init|=
literal|326
block|,
name|kw_TYPE_IDENTIFIER
init|=
literal|327
block|,
name|kw_TeletexString
init|=
literal|328
block|,
name|kw_UNION
init|=
literal|329
block|,
name|kw_UNIQUE
init|=
literal|330
block|,
name|kw_UNIVERSAL
init|=
literal|331
block|,
name|kw_UTCTime
init|=
literal|332
block|,
name|kw_UTF8String
init|=
literal|333
block|,
name|kw_UniversalString
init|=
literal|334
block|,
name|kw_VideotexString
init|=
literal|335
block|,
name|kw_VisibleString
init|=
literal|336
block|,
name|kw_WITH
init|=
literal|337
block|,
name|RANGE
init|=
literal|338
block|,
name|EEQUAL
init|=
literal|339
block|,
name|ELLIPSIS
init|=
literal|340
block|,
name|IDENTIFIER
init|=
literal|341
block|,
name|referencename
init|=
literal|342
block|,
name|STRING
init|=
literal|343
block|,
name|NUMBER
init|=
literal|344
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
name|kw_ABSENT
value|258
end_define

begin_define
define|#
directive|define
name|kw_ABSTRACT_SYNTAX
value|259
end_define

begin_define
define|#
directive|define
name|kw_ALL
value|260
end_define

begin_define
define|#
directive|define
name|kw_APPLICATION
value|261
end_define

begin_define
define|#
directive|define
name|kw_AUTOMATIC
value|262
end_define

begin_define
define|#
directive|define
name|kw_BEGIN
value|263
end_define

begin_define
define|#
directive|define
name|kw_BIT
value|264
end_define

begin_define
define|#
directive|define
name|kw_BMPString
value|265
end_define

begin_define
define|#
directive|define
name|kw_BOOLEAN
value|266
end_define

begin_define
define|#
directive|define
name|kw_BY
value|267
end_define

begin_define
define|#
directive|define
name|kw_CHARACTER
value|268
end_define

begin_define
define|#
directive|define
name|kw_CHOICE
value|269
end_define

begin_define
define|#
directive|define
name|kw_CLASS
value|270
end_define

begin_define
define|#
directive|define
name|kw_COMPONENT
value|271
end_define

begin_define
define|#
directive|define
name|kw_COMPONENTS
value|272
end_define

begin_define
define|#
directive|define
name|kw_CONSTRAINED
value|273
end_define

begin_define
define|#
directive|define
name|kw_CONTAINING
value|274
end_define

begin_define
define|#
directive|define
name|kw_DEFAULT
value|275
end_define

begin_define
define|#
directive|define
name|kw_DEFINITIONS
value|276
end_define

begin_define
define|#
directive|define
name|kw_EMBEDDED
value|277
end_define

begin_define
define|#
directive|define
name|kw_ENCODED
value|278
end_define

begin_define
define|#
directive|define
name|kw_END
value|279
end_define

begin_define
define|#
directive|define
name|kw_ENUMERATED
value|280
end_define

begin_define
define|#
directive|define
name|kw_EXCEPT
value|281
end_define

begin_define
define|#
directive|define
name|kw_EXPLICIT
value|282
end_define

begin_define
define|#
directive|define
name|kw_EXPORTS
value|283
end_define

begin_define
define|#
directive|define
name|kw_EXTENSIBILITY
value|284
end_define

begin_define
define|#
directive|define
name|kw_EXTERNAL
value|285
end_define

begin_define
define|#
directive|define
name|kw_FALSE
value|286
end_define

begin_define
define|#
directive|define
name|kw_FROM
value|287
end_define

begin_define
define|#
directive|define
name|kw_GeneralString
value|288
end_define

begin_define
define|#
directive|define
name|kw_GeneralizedTime
value|289
end_define

begin_define
define|#
directive|define
name|kw_GraphicString
value|290
end_define

begin_define
define|#
directive|define
name|kw_IA5String
value|291
end_define

begin_define
define|#
directive|define
name|kw_IDENTIFIER
value|292
end_define

begin_define
define|#
directive|define
name|kw_IMPLICIT
value|293
end_define

begin_define
define|#
directive|define
name|kw_IMPLIED
value|294
end_define

begin_define
define|#
directive|define
name|kw_IMPORTS
value|295
end_define

begin_define
define|#
directive|define
name|kw_INCLUDES
value|296
end_define

begin_define
define|#
directive|define
name|kw_INSTANCE
value|297
end_define

begin_define
define|#
directive|define
name|kw_INTEGER
value|298
end_define

begin_define
define|#
directive|define
name|kw_INTERSECTION
value|299
end_define

begin_define
define|#
directive|define
name|kw_ISO646String
value|300
end_define

begin_define
define|#
directive|define
name|kw_MAX
value|301
end_define

begin_define
define|#
directive|define
name|kw_MIN
value|302
end_define

begin_define
define|#
directive|define
name|kw_MINUS_INFINITY
value|303
end_define

begin_define
define|#
directive|define
name|kw_NULL
value|304
end_define

begin_define
define|#
directive|define
name|kw_NumericString
value|305
end_define

begin_define
define|#
directive|define
name|kw_OBJECT
value|306
end_define

begin_define
define|#
directive|define
name|kw_OCTET
value|307
end_define

begin_define
define|#
directive|define
name|kw_OF
value|308
end_define

begin_define
define|#
directive|define
name|kw_OPTIONAL
value|309
end_define

begin_define
define|#
directive|define
name|kw_ObjectDescriptor
value|310
end_define

begin_define
define|#
directive|define
name|kw_PATTERN
value|311
end_define

begin_define
define|#
directive|define
name|kw_PDV
value|312
end_define

begin_define
define|#
directive|define
name|kw_PLUS_INFINITY
value|313
end_define

begin_define
define|#
directive|define
name|kw_PRESENT
value|314
end_define

begin_define
define|#
directive|define
name|kw_PRIVATE
value|315
end_define

begin_define
define|#
directive|define
name|kw_PrintableString
value|316
end_define

begin_define
define|#
directive|define
name|kw_REAL
value|317
end_define

begin_define
define|#
directive|define
name|kw_RELATIVE_OID
value|318
end_define

begin_define
define|#
directive|define
name|kw_SEQUENCE
value|319
end_define

begin_define
define|#
directive|define
name|kw_SET
value|320
end_define

begin_define
define|#
directive|define
name|kw_SIZE
value|321
end_define

begin_define
define|#
directive|define
name|kw_STRING
value|322
end_define

begin_define
define|#
directive|define
name|kw_SYNTAX
value|323
end_define

begin_define
define|#
directive|define
name|kw_T61String
value|324
end_define

begin_define
define|#
directive|define
name|kw_TAGS
value|325
end_define

begin_define
define|#
directive|define
name|kw_TRUE
value|326
end_define

begin_define
define|#
directive|define
name|kw_TYPE_IDENTIFIER
value|327
end_define

begin_define
define|#
directive|define
name|kw_TeletexString
value|328
end_define

begin_define
define|#
directive|define
name|kw_UNION
value|329
end_define

begin_define
define|#
directive|define
name|kw_UNIQUE
value|330
end_define

begin_define
define|#
directive|define
name|kw_UNIVERSAL
value|331
end_define

begin_define
define|#
directive|define
name|kw_UTCTime
value|332
end_define

begin_define
define|#
directive|define
name|kw_UTF8String
value|333
end_define

begin_define
define|#
directive|define
name|kw_UniversalString
value|334
end_define

begin_define
define|#
directive|define
name|kw_VideotexString
value|335
end_define

begin_define
define|#
directive|define
name|kw_VisibleString
value|336
end_define

begin_define
define|#
directive|define
name|kw_WITH
value|337
end_define

begin_define
define|#
directive|define
name|RANGE
value|338
end_define

begin_define
define|#
directive|define
name|EEQUAL
value|339
end_define

begin_define
define|#
directive|define
name|ELLIPSIS
value|340
end_define

begin_define
define|#
directive|define
name|IDENTIFIER
value|341
end_define

begin_define
define|#
directive|define
name|referencename
value|342
end_define

begin_define
define|#
directive|define
name|STRING
value|343
end_define

begin_define
define|#
directive|define
name|NUMBER
value|344
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
number|71
file|"asn1parse.y"
block|{
name|int
name|constant
decl_stmt|;
name|struct
name|value
modifier|*
name|value
decl_stmt|;
name|struct
name|range
modifier|*
name|range
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
name|Type
modifier|*
name|type
decl_stmt|;
name|Member
modifier|*
name|member
decl_stmt|;
name|struct
name|objid
modifier|*
name|objid
decl_stmt|;
name|char
modifier|*
name|defval
decl_stmt|;
name|struct
name|string_list
modifier|*
name|sl
decl_stmt|;
name|struct
name|tagtype
name|tag
decl_stmt|;
name|struct
name|memhead
modifier|*
name|members
decl_stmt|;
name|struct
name|constraint_spec
modifier|*
name|constraint_spec
decl_stmt|;
block|}
comment|/* Line 1529 of yacc.c.  */
line|#
directive|line
number|242
file|"asn1parse.h"
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

