begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$FreeBSD$	*/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|wordtab
block|{
name|char
modifier|*
name|w_word
decl_stmt|;
name|int
name|w_value
decl_stmt|;
block|}
name|wordtab_t
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|NO_YACC
end_ifdef

begin_define
define|#
directive|define
name|YY_COMMENT
value|1000
end_define

begin_define
define|#
directive|define
name|YY_CMP_NE
value|1001
end_define

begin_define
define|#
directive|define
name|YY_CMP_LE
value|1002
end_define

begin_define
define|#
directive|define
name|YY_RANGE_OUT
value|1003
end_define

begin_define
define|#
directive|define
name|YY_CMP_GE
value|1004
end_define

begin_define
define|#
directive|define
name|YY_RANGE_IN
value|1005
end_define

begin_define
define|#
directive|define
name|YY_HEX
value|1006
end_define

begin_define
define|#
directive|define
name|YY_NUMBER
value|1007
end_define

begin_define
define|#
directive|define
name|YY_IPV6
value|1008
end_define

begin_define
define|#
directive|define
name|YY_STR
value|1009
end_define

begin_define
define|#
directive|define
name|YY_IPADDR
value|1010
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|YYBUFSIZ
value|8192
end_define

begin_decl_stmt
specifier|extern
name|wordtab_t
modifier|*
name|yysettab
name|__P
argument_list|(
operator|(
name|wordtab_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|yysetdict
name|__P
argument_list|(
operator|(
name|wordtab_t
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yylex
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|yyerror
name|__P
argument_list|(
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|yykeytostr
name|__P
argument_list|(
operator|(
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|yyresetdict
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|yyin
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yylineNum
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyexpectaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yybreakondot
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|yyvarnext
decl_stmt|;
end_decl_stmt

end_unit

