begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|UNEXPECTED
value|257
end_define

begin_define
define|#
directive|define
name|BAD_DECIMAL
value|258
end_define

begin_define
define|#
directive|define
name|NL
value|259
end_define

begin_define
define|#
directive|define
name|SEMI_COLON
value|260
end_define

begin_define
define|#
directive|define
name|LBRACE
value|261
end_define

begin_define
define|#
directive|define
name|RBRACE
value|262
end_define

begin_define
define|#
directive|define
name|LBOX
value|263
end_define

begin_define
define|#
directive|define
name|RBOX
value|264
end_define

begin_define
define|#
directive|define
name|COMMA
value|265
end_define

begin_define
define|#
directive|define
name|IO_OUT
value|266
end_define

begin_define
define|#
directive|define
name|ASSIGN
value|267
end_define

begin_define
define|#
directive|define
name|ADD_ASG
value|268
end_define

begin_define
define|#
directive|define
name|SUB_ASG
value|269
end_define

begin_define
define|#
directive|define
name|MUL_ASG
value|270
end_define

begin_define
define|#
directive|define
name|DIV_ASG
value|271
end_define

begin_define
define|#
directive|define
name|MOD_ASG
value|272
end_define

begin_define
define|#
directive|define
name|POW_ASG
value|273
end_define

begin_define
define|#
directive|define
name|QMARK
value|274
end_define

begin_define
define|#
directive|define
name|COLON
value|275
end_define

begin_define
define|#
directive|define
name|OR
value|276
end_define

begin_define
define|#
directive|define
name|AND
value|277
end_define

begin_define
define|#
directive|define
name|IN
value|278
end_define

begin_define
define|#
directive|define
name|MATCH
value|279
end_define

begin_define
define|#
directive|define
name|EQ
value|280
end_define

begin_define
define|#
directive|define
name|NEQ
value|281
end_define

begin_define
define|#
directive|define
name|LT
value|282
end_define

begin_define
define|#
directive|define
name|LTE
value|283
end_define

begin_define
define|#
directive|define
name|GT
value|284
end_define

begin_define
define|#
directive|define
name|GTE
value|285
end_define

begin_define
define|#
directive|define
name|CAT
value|286
end_define

begin_define
define|#
directive|define
name|GETLINE
value|287
end_define

begin_define
define|#
directive|define
name|PLUS
value|288
end_define

begin_define
define|#
directive|define
name|MINUS
value|289
end_define

begin_define
define|#
directive|define
name|MUL
value|290
end_define

begin_define
define|#
directive|define
name|DIV
value|291
end_define

begin_define
define|#
directive|define
name|MOD
value|292
end_define

begin_define
define|#
directive|define
name|NOT
value|293
end_define

begin_define
define|#
directive|define
name|UMINUS
value|294
end_define

begin_define
define|#
directive|define
name|IO_IN
value|295
end_define

begin_define
define|#
directive|define
name|PIPE
value|296
end_define

begin_define
define|#
directive|define
name|POW
value|297
end_define

begin_define
define|#
directive|define
name|INC_or_DEC
value|298
end_define

begin_define
define|#
directive|define
name|DOLLAR
value|299
end_define

begin_define
define|#
directive|define
name|FIELD
value|300
end_define

begin_define
define|#
directive|define
name|LPAREN
value|301
end_define

begin_define
define|#
directive|define
name|RPAREN
value|302
end_define

begin_define
define|#
directive|define
name|DOUBLE
value|303
end_define

begin_define
define|#
directive|define
name|STRING_
value|304
end_define

begin_define
define|#
directive|define
name|RE
value|305
end_define

begin_define
define|#
directive|define
name|ID
value|306
end_define

begin_define
define|#
directive|define
name|D_ID
value|307
end_define

begin_define
define|#
directive|define
name|FUNCT_ID
value|308
end_define

begin_define
define|#
directive|define
name|BUILTIN
value|309
end_define

begin_define
define|#
directive|define
name|PRINT
value|310
end_define

begin_define
define|#
directive|define
name|PRINTF
value|311
end_define

begin_define
define|#
directive|define
name|SPLIT
value|312
end_define

begin_define
define|#
directive|define
name|MATCH_FUNC
value|313
end_define

begin_define
define|#
directive|define
name|SUB
value|314
end_define

begin_define
define|#
directive|define
name|GSUB
value|315
end_define

begin_define
define|#
directive|define
name|DO
value|316
end_define

begin_define
define|#
directive|define
name|WHILE
value|317
end_define

begin_define
define|#
directive|define
name|FOR
value|318
end_define

begin_define
define|#
directive|define
name|BREAK
value|319
end_define

begin_define
define|#
directive|define
name|CONTINUE
value|320
end_define

begin_define
define|#
directive|define
name|IF
value|321
end_define

begin_define
define|#
directive|define
name|ELSE
value|322
end_define

begin_define
define|#
directive|define
name|DELETE
value|323
end_define

begin_define
define|#
directive|define
name|BEGIN
value|324
end_define

begin_define
define|#
directive|define
name|END
value|325
end_define

begin_define
define|#
directive|define
name|EXIT
value|326
end_define

begin_define
define|#
directive|define
name|NEXT
value|327
end_define

begin_define
define|#
directive|define
name|RETURN
value|328
end_define

begin_define
define|#
directive|define
name|FUNCTION
value|329
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|CELL
modifier|*
name|cp
decl_stmt|;
name|SYMTAB
modifier|*
name|stp
decl_stmt|;
name|INST
modifier|*
name|start
decl_stmt|;
comment|/* code starting address */
name|PF_CP
name|fp
decl_stmt|;
comment|/* ptr to a (print/printf) or (sub/gsub) function */
name|BI_REC
modifier|*
name|bip
decl_stmt|;
comment|/* ptr to info about a builtin */
name|FBLOCK
modifier|*
name|fbp
decl_stmt|;
comment|/* ptr to a function block */
name|ARG2_REC
modifier|*
name|arg2p
decl_stmt|;
name|CA_REC
modifier|*
name|ca_p
decl_stmt|;
name|int
name|ival
decl_stmt|;
name|PTR
name|ptr
decl_stmt|;
block|}
name|YYSTYPE
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

