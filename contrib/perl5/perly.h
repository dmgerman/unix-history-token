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
name|METHOD
value|258
end_define

begin_define
define|#
directive|define
name|FUNCMETH
value|259
end_define

begin_define
define|#
directive|define
name|THING
value|260
end_define

begin_define
define|#
directive|define
name|PMFUNC
value|261
end_define

begin_define
define|#
directive|define
name|PRIVATEREF
value|262
end_define

begin_define
define|#
directive|define
name|FUNC0SUB
value|263
end_define

begin_define
define|#
directive|define
name|UNIOPSUB
value|264
end_define

begin_define
define|#
directive|define
name|LSTOPSUB
value|265
end_define

begin_define
define|#
directive|define
name|LABEL
value|266
end_define

begin_define
define|#
directive|define
name|FORMAT
value|267
end_define

begin_define
define|#
directive|define
name|SUB
value|268
end_define

begin_define
define|#
directive|define
name|ANONSUB
value|269
end_define

begin_define
define|#
directive|define
name|PACKAGE
value|270
end_define

begin_define
define|#
directive|define
name|USE
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
name|UNTIL
value|273
end_define

begin_define
define|#
directive|define
name|IF
value|274
end_define

begin_define
define|#
directive|define
name|UNLESS
value|275
end_define

begin_define
define|#
directive|define
name|ELSE
value|276
end_define

begin_define
define|#
directive|define
name|ELSIF
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
name|FOR
value|279
end_define

begin_define
define|#
directive|define
name|LOOPEX
value|280
end_define

begin_define
define|#
directive|define
name|DOTDOT
value|281
end_define

begin_define
define|#
directive|define
name|FUNC0
value|282
end_define

begin_define
define|#
directive|define
name|FUNC1
value|283
end_define

begin_define
define|#
directive|define
name|FUNC
value|284
end_define

begin_define
define|#
directive|define
name|UNIOP
value|285
end_define

begin_define
define|#
directive|define
name|LSTOP
value|286
end_define

begin_define
define|#
directive|define
name|RELOP
value|287
end_define

begin_define
define|#
directive|define
name|EQOP
value|288
end_define

begin_define
define|#
directive|define
name|MULOP
value|289
end_define

begin_define
define|#
directive|define
name|ADDOP
value|290
end_define

begin_define
define|#
directive|define
name|DOLSHARP
value|291
end_define

begin_define
define|#
directive|define
name|DO
value|292
end_define

begin_define
define|#
directive|define
name|HASHBRACK
value|293
end_define

begin_define
define|#
directive|define
name|NOAMP
value|294
end_define

begin_define
define|#
directive|define
name|LOCAL
value|295
end_define

begin_define
define|#
directive|define
name|MY
value|296
end_define

begin_define
define|#
directive|define
name|OROP
value|297
end_define

begin_define
define|#
directive|define
name|ANDOP
value|298
end_define

begin_define
define|#
directive|define
name|NOTOP
value|299
end_define

begin_define
define|#
directive|define
name|ASSIGNOP
value|300
end_define

begin_define
define|#
directive|define
name|OROR
value|301
end_define

begin_define
define|#
directive|define
name|ANDAND
value|302
end_define

begin_define
define|#
directive|define
name|BITOROP
value|303
end_define

begin_define
define|#
directive|define
name|BITANDOP
value|304
end_define

begin_define
define|#
directive|define
name|SHIFTOP
value|305
end_define

begin_define
define|#
directive|define
name|MATCHOP
value|306
end_define

begin_define
define|#
directive|define
name|UMINUS
value|307
end_define

begin_define
define|#
directive|define
name|REFGEN
value|308
end_define

begin_define
define|#
directive|define
name|POWOP
value|309
end_define

begin_define
define|#
directive|define
name|PREINC
value|310
end_define

begin_define
define|#
directive|define
name|PREDEC
value|311
end_define

begin_define
define|#
directive|define
name|POSTINC
value|312
end_define

begin_define
define|#
directive|define
name|POSTDEC
value|313
end_define

begin_define
define|#
directive|define
name|ARROW
value|314
end_define

begin_typedef
typedef|typedef
union|union
block|{
name|I32
name|ival
decl_stmt|;
name|char
modifier|*
name|pval
decl_stmt|;
name|OP
modifier|*
name|opval
decl_stmt|;
name|GV
modifier|*
name|gvval
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

