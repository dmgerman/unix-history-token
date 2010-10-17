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
name|int
name|i
decl_stmt|;
name|char
modifier|*
name|s
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
name|COND
value|257
end_define

begin_define
define|#
directive|define
name|REPEAT
value|258
end_define

begin_define
define|#
directive|define
name|TYPE
value|259
end_define

begin_define
define|#
directive|define
name|NAME
value|260
end_define

begin_define
define|#
directive|define
name|NUMBER
value|261
end_define

begin_define
define|#
directive|define
name|UNIT
value|262
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

