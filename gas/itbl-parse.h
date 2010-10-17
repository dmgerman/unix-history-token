begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|BISON_Y_TAB_H
end_ifndef

begin_define
define|#
directive|define
name|BISON_Y_TAB_H
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|YYSTYPE
end_ifndef

begin_typedef
typedef|typedef
union|union
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
name|yystype
typedef|;
end_typedef

begin_define
define|#
directive|define
name|YYSTYPE
value|yystype
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

begin_define
define|#
directive|define
name|DREG
value|257
end_define

begin_define
define|#
directive|define
name|CREG
value|258
end_define

begin_define
define|#
directive|define
name|GREG
value|259
end_define

begin_define
define|#
directive|define
name|IMMED
value|260
end_define

begin_define
define|#
directive|define
name|ADDR
value|261
end_define

begin_define
define|#
directive|define
name|INSN
value|262
end_define

begin_define
define|#
directive|define
name|NUM
value|263
end_define

begin_define
define|#
directive|define
name|ID
value|264
end_define

begin_define
define|#
directive|define
name|NL
value|265
end_define

begin_define
define|#
directive|define
name|PNUM
value|266
end_define

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not BISON_Y_TAB_H */
end_comment

end_unit

