begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
union|union
block|{
name|long
name|itype
decl_stmt|;
name|tree
name|ttype
decl_stmt|;
name|char
modifier|*
name|strtype
decl_stmt|;
name|enum
name|tree_code
name|code
decl_stmt|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IDENTIFIER
value|258
end_define

begin_define
define|#
directive|define
name|TYPENAME
value|259
end_define

begin_define
define|#
directive|define
name|SCOPED_TYPENAME
value|260
end_define

begin_define
define|#
directive|define
name|SCSPEC
value|261
end_define

begin_define
define|#
directive|define
name|TYPESPEC
value|262
end_define

begin_define
define|#
directive|define
name|TYPE_QUAL
value|263
end_define

begin_define
define|#
directive|define
name|CONSTANT
value|264
end_define

begin_define
define|#
directive|define
name|STRING
value|265
end_define

begin_define
define|#
directive|define
name|ELLIPSIS
value|266
end_define

begin_define
define|#
directive|define
name|SIZEOF
value|267
end_define

begin_define
define|#
directive|define
name|ENUM
value|268
end_define

begin_define
define|#
directive|define
name|IF
value|269
end_define

begin_define
define|#
directive|define
name|ELSE
value|270
end_define

begin_define
define|#
directive|define
name|WHILE
value|271
end_define

begin_define
define|#
directive|define
name|DO
value|272
end_define

begin_define
define|#
directive|define
name|FOR
value|273
end_define

begin_define
define|#
directive|define
name|SWITCH
value|274
end_define

begin_define
define|#
directive|define
name|CASE
value|275
end_define

begin_define
define|#
directive|define
name|DEFAULT
value|276
end_define

begin_define
define|#
directive|define
name|BREAK
value|277
end_define

begin_define
define|#
directive|define
name|CONTINUE
value|278
end_define

begin_define
define|#
directive|define
name|RETURN
value|279
end_define

begin_define
define|#
directive|define
name|GOTO
value|280
end_define

begin_define
define|#
directive|define
name|ASM_KEYWORD
value|281
end_define

begin_define
define|#
directive|define
name|GCC_ASM_KEYWORD
value|282
end_define

begin_define
define|#
directive|define
name|TYPEOF
value|283
end_define

begin_define
define|#
directive|define
name|ALIGNOF
value|284
end_define

begin_define
define|#
directive|define
name|HEADOF
value|285
end_define

begin_define
define|#
directive|define
name|CLASSOF
value|286
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE
value|287
end_define

begin_define
define|#
directive|define
name|EXTENSION
value|288
end_define

begin_define
define|#
directive|define
name|LABEL
value|289
end_define

begin_define
define|#
directive|define
name|AGGR
value|290
end_define

begin_define
define|#
directive|define
name|VISSPEC
value|291
end_define

begin_define
define|#
directive|define
name|DELETE
value|292
end_define

begin_define
define|#
directive|define
name|NEW
value|293
end_define

begin_define
define|#
directive|define
name|OVERLOAD
value|294
end_define

begin_define
define|#
directive|define
name|THIS
value|295
end_define

begin_define
define|#
directive|define
name|OPERATOR
value|296
end_define

begin_define
define|#
directive|define
name|DYNAMIC
value|297
end_define

begin_define
define|#
directive|define
name|POINTSAT_LEFT_RIGHT
value|298
end_define

begin_define
define|#
directive|define
name|LEFT_RIGHT
value|299
end_define

begin_define
define|#
directive|define
name|TEMPLATE
value|300
end_define

begin_define
define|#
directive|define
name|SCOPE
value|301
end_define

begin_define
define|#
directive|define
name|START_DECLARATOR
value|302
end_define

begin_define
define|#
directive|define
name|EMPTY
value|303
end_define

begin_define
define|#
directive|define
name|TYPENAME_COLON
value|304
end_define

begin_define
define|#
directive|define
name|ASSIGN
value|305
end_define

begin_define
define|#
directive|define
name|RANGE
value|306
end_define

begin_define
define|#
directive|define
name|OROR
value|307
end_define

begin_define
define|#
directive|define
name|ANDAND
value|308
end_define

begin_define
define|#
directive|define
name|MIN_MAX
value|309
end_define

begin_define
define|#
directive|define
name|EQCOMPARE
value|310
end_define

begin_define
define|#
directive|define
name|ARITHCOMPARE
value|311
end_define

begin_define
define|#
directive|define
name|LSHIFT
value|312
end_define

begin_define
define|#
directive|define
name|RSHIFT
value|313
end_define

begin_define
define|#
directive|define
name|UNARY
value|314
end_define

begin_define
define|#
directive|define
name|PLUSPLUS
value|315
end_define

begin_define
define|#
directive|define
name|MINUSMINUS
value|316
end_define

begin_define
define|#
directive|define
name|HYPERUNARY
value|317
end_define

begin_define
define|#
directive|define
name|PAREN_STAR_PAREN
value|318
end_define

begin_define
define|#
directive|define
name|POINTSAT
value|319
end_define

begin_define
define|#
directive|define
name|POINTSAT_STAR
value|320
end_define

begin_define
define|#
directive|define
name|DOT_STAR
value|321
end_define

begin_define
define|#
directive|define
name|RAISE
value|322
end_define

begin_define
define|#
directive|define
name|RAISES
value|323
end_define

begin_define
define|#
directive|define
name|RERAISE
value|324
end_define

begin_define
define|#
directive|define
name|TRY
value|325
end_define

begin_define
define|#
directive|define
name|EXCEPT
value|326
end_define

begin_define
define|#
directive|define
name|CATCH
value|327
end_define

begin_define
define|#
directive|define
name|THROW
value|328
end_define

begin_define
define|#
directive|define
name|ANSI_TRY
value|329
end_define

begin_define
define|#
directive|define
name|ANSI_THROW
value|330
end_define

begin_define
define|#
directive|define
name|TYPENAME_ELLIPSIS
value|331
end_define

begin_define
define|#
directive|define
name|PTYPENAME
value|332
end_define

begin_define
define|#
directive|define
name|PRE_PARSED_FUNCTION_DECL
value|333
end_define

begin_define
define|#
directive|define
name|EXTERN_LANG_STRING
value|334
end_define

begin_define
define|#
directive|define
name|ALL
value|335
end_define

begin_define
define|#
directive|define
name|PRE_PARSED_CLASS_DECL
value|336
end_define

begin_define
define|#
directive|define
name|TYPENAME_DEFN
value|337
end_define

begin_define
define|#
directive|define
name|IDENTIFIER_DEFN
value|338
end_define

begin_define
define|#
directive|define
name|PTYPENAME_DEFN
value|339
end_define

begin_define
define|#
directive|define
name|END_OF_SAVED_INPUT
value|340
end_define

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|YYEMPTY
value|-2
end_define

end_unit

