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
name|enum
name|tree_code
name|code
decl_stmt|;
name|char
modifier|*
name|filename
decl_stmt|;
name|int
name|lineno
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
name|SCSPEC
value|260
end_define

begin_define
define|#
directive|define
name|TYPESPEC
value|261
end_define

begin_define
define|#
directive|define
name|TYPE_QUAL
value|262
end_define

begin_define
define|#
directive|define
name|CONSTANT
value|263
end_define

begin_define
define|#
directive|define
name|STRING
value|264
end_define

begin_define
define|#
directive|define
name|ELLIPSIS
value|265
end_define

begin_define
define|#
directive|define
name|SIZEOF
value|266
end_define

begin_define
define|#
directive|define
name|ENUM
value|267
end_define

begin_define
define|#
directive|define
name|STRUCT
value|268
end_define

begin_define
define|#
directive|define
name|UNION
value|269
end_define

begin_define
define|#
directive|define
name|IF
value|270
end_define

begin_define
define|#
directive|define
name|ELSE
value|271
end_define

begin_define
define|#
directive|define
name|WHILE
value|272
end_define

begin_define
define|#
directive|define
name|DO
value|273
end_define

begin_define
define|#
directive|define
name|FOR
value|274
end_define

begin_define
define|#
directive|define
name|SWITCH
value|275
end_define

begin_define
define|#
directive|define
name|CASE
value|276
end_define

begin_define
define|#
directive|define
name|DEFAULT
value|277
end_define

begin_define
define|#
directive|define
name|BREAK
value|278
end_define

begin_define
define|#
directive|define
name|CONTINUE
value|279
end_define

begin_define
define|#
directive|define
name|RETURN
value|280
end_define

begin_define
define|#
directive|define
name|GOTO
value|281
end_define

begin_define
define|#
directive|define
name|ASM_KEYWORD
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
name|ALIGN
value|285
end_define

begin_define
define|#
directive|define
name|ATTRIBUTE
value|286
end_define

begin_define
define|#
directive|define
name|EXTENSION
value|287
end_define

begin_define
define|#
directive|define
name|LABEL
value|288
end_define

begin_define
define|#
directive|define
name|ASSIGN
value|289
end_define

begin_define
define|#
directive|define
name|OROR
value|290
end_define

begin_define
define|#
directive|define
name|ANDAND
value|291
end_define

begin_define
define|#
directive|define
name|EQCOMPARE
value|292
end_define

begin_define
define|#
directive|define
name|ARITHCOMPARE
value|293
end_define

begin_define
define|#
directive|define
name|LSHIFT
value|294
end_define

begin_define
define|#
directive|define
name|RSHIFT
value|295
end_define

begin_define
define|#
directive|define
name|UNARY
value|296
end_define

begin_define
define|#
directive|define
name|PLUSPLUS
value|297
end_define

begin_define
define|#
directive|define
name|MINUSMINUS
value|298
end_define

begin_define
define|#
directive|define
name|HYPERUNARY
value|299
end_define

begin_define
define|#
directive|define
name|POINTSAT
value|300
end_define

begin_define
define|#
directive|define
name|INTERFACE
value|301
end_define

begin_define
define|#
directive|define
name|IMPLEMENTATION
value|302
end_define

begin_define
define|#
directive|define
name|END
value|303
end_define

begin_define
define|#
directive|define
name|SELECTOR
value|304
end_define

begin_define
define|#
directive|define
name|DEFS
value|305
end_define

begin_define
define|#
directive|define
name|ENCODE
value|306
end_define

begin_define
define|#
directive|define
name|CLASSNAME
value|307
end_define

begin_define
define|#
directive|define
name|PUBLIC
value|308
end_define

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

