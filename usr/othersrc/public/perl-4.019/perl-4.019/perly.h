begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|WORD
value|257
end_define

begin_define
define|#
directive|define
name|APPEND
value|258
end_define

begin_define
define|#
directive|define
name|OPEN
value|259
end_define

begin_define
define|#
directive|define
name|SSELECT
value|260
end_define

begin_define
define|#
directive|define
name|LOOPEX
value|261
end_define

begin_define
define|#
directive|define
name|USING
value|262
end_define

begin_define
define|#
directive|define
name|FORMAT
value|263
end_define

begin_define
define|#
directive|define
name|DO
value|264
end_define

begin_define
define|#
directive|define
name|SHIFT
value|265
end_define

begin_define
define|#
directive|define
name|PUSH
value|266
end_define

begin_define
define|#
directive|define
name|POP
value|267
end_define

begin_define
define|#
directive|define
name|LVALFUN
value|268
end_define

begin_define
define|#
directive|define
name|WHILE
value|269
end_define

begin_define
define|#
directive|define
name|UNTIL
value|270
end_define

begin_define
define|#
directive|define
name|IF
value|271
end_define

begin_define
define|#
directive|define
name|UNLESS
value|272
end_define

begin_define
define|#
directive|define
name|ELSE
value|273
end_define

begin_define
define|#
directive|define
name|ELSIF
value|274
end_define

begin_define
define|#
directive|define
name|CONTINUE
value|275
end_define

begin_define
define|#
directive|define
name|SPLIT
value|276
end_define

begin_define
define|#
directive|define
name|FLIST
value|277
end_define

begin_define
define|#
directive|define
name|FOR
value|278
end_define

begin_define
define|#
directive|define
name|FILOP
value|279
end_define

begin_define
define|#
directive|define
name|FILOP2
value|280
end_define

begin_define
define|#
directive|define
name|FILOP3
value|281
end_define

begin_define
define|#
directive|define
name|FILOP4
value|282
end_define

begin_define
define|#
directive|define
name|FILOP22
value|283
end_define

begin_define
define|#
directive|define
name|FILOP25
value|284
end_define

begin_define
define|#
directive|define
name|FUNC0
value|285
end_define

begin_define
define|#
directive|define
name|FUNC1
value|286
end_define

begin_define
define|#
directive|define
name|FUNC2
value|287
end_define

begin_define
define|#
directive|define
name|FUNC2x
value|288
end_define

begin_define
define|#
directive|define
name|FUNC3
value|289
end_define

begin_define
define|#
directive|define
name|FUNC4
value|290
end_define

begin_define
define|#
directive|define
name|FUNC5
value|291
end_define

begin_define
define|#
directive|define
name|HSHFUN
value|292
end_define

begin_define
define|#
directive|define
name|HSHFUN3
value|293
end_define

begin_define
define|#
directive|define
name|FLIST2
value|294
end_define

begin_define
define|#
directive|define
name|SUB
value|295
end_define

begin_define
define|#
directive|define
name|FILETEST
value|296
end_define

begin_define
define|#
directive|define
name|LOCAL
value|297
end_define

begin_define
define|#
directive|define
name|DELETE
value|298
end_define

begin_define
define|#
directive|define
name|RELOP
value|299
end_define

begin_define
define|#
directive|define
name|EQOP
value|300
end_define

begin_define
define|#
directive|define
name|MULOP
value|301
end_define

begin_define
define|#
directive|define
name|ADDOP
value|302
end_define

begin_define
define|#
directive|define
name|PACKAGE
value|303
end_define

begin_define
define|#
directive|define
name|AMPER
value|304
end_define

begin_define
define|#
directive|define
name|FORMLIST
value|305
end_define

begin_define
define|#
directive|define
name|REG
value|306
end_define

begin_define
define|#
directive|define
name|ARYLEN
value|307
end_define

begin_define
define|#
directive|define
name|ARY
value|308
end_define

begin_define
define|#
directive|define
name|HSH
value|309
end_define

begin_define
define|#
directive|define
name|STAR
value|310
end_define

begin_define
define|#
directive|define
name|SUBST
value|311
end_define

begin_define
define|#
directive|define
name|PATTERN
value|312
end_define

begin_define
define|#
directive|define
name|RSTRING
value|313
end_define

begin_define
define|#
directive|define
name|TRANS
value|314
end_define

begin_define
define|#
directive|define
name|LISTOP
value|315
end_define

begin_define
define|#
directive|define
name|DOTDOT
value|316
end_define

begin_define
define|#
directive|define
name|OROR
value|317
end_define

begin_define
define|#
directive|define
name|ANDAND
value|318
end_define

begin_define
define|#
directive|define
name|UNIOP
value|319
end_define

begin_define
define|#
directive|define
name|LS
value|320
end_define

begin_define
define|#
directive|define
name|RS
value|321
end_define

begin_define
define|#
directive|define
name|MATCH
value|322
end_define

begin_define
define|#
directive|define
name|NMATCH
value|323
end_define

begin_define
define|#
directive|define
name|UMINUS
value|324
end_define

begin_define
define|#
directive|define
name|POW
value|325
end_define

begin_define
define|#
directive|define
name|INC
value|326
end_define

begin_define
define|#
directive|define
name|DEC
value|327
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|ival
decl_stmt|;
name|char
modifier|*
name|cval
decl_stmt|;
name|ARG
modifier|*
name|arg
decl_stmt|;
name|CMD
modifier|*
name|cmdval
decl_stmt|;
name|struct
name|compcmd
name|compval
decl_stmt|;
name|STAB
modifier|*
name|stabval
decl_stmt|;
name|FCMD
modifier|*
name|formval
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

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

end_unit

