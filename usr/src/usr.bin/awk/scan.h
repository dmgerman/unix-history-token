begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************** scan.h copyright 1991, Michael D. Brennan  This is a source file for mawk, an implementation of the AWK programming language.  Mawk is distributed without warranty under the terms of the GNU General Public License, version 2, 1991. ********************************************/
end_comment

begin_comment
comment|/* $Log:	scan.h,v $  * Revision 5.1  91/12/05  07:59:33  brennan  * 1.1 pre-release  *  */
end_comment

begin_comment
comment|/* scan.h  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SCAN_H_INCLUDED
end_ifndef

begin_define
define|#
directive|define
name|SCAN_H_INCLUDED
value|1
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|MAKESCAN
end_ifndef

begin_include
include|#
directive|include
file|"symtype.h"
end_include

begin_include
include|#
directive|include
file|"parse.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|char
name|scan_code
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  the scan codes to compactify the main switch */
end_comment

begin_define
define|#
directive|define
name|SC_SPACE
value|1
end_define

begin_define
define|#
directive|define
name|SC_NL
value|2
end_define

begin_define
define|#
directive|define
name|SC_SEMI_COLON
value|3
end_define

begin_define
define|#
directive|define
name|SC_FAKE_SEMI_COLON
value|4
end_define

begin_define
define|#
directive|define
name|SC_LBRACE
value|5
end_define

begin_define
define|#
directive|define
name|SC_RBRACE
value|6
end_define

begin_define
define|#
directive|define
name|SC_QMARK
value|7
end_define

begin_define
define|#
directive|define
name|SC_COLON
value|8
end_define

begin_define
define|#
directive|define
name|SC_OR
value|9
end_define

begin_define
define|#
directive|define
name|SC_AND
value|10
end_define

begin_define
define|#
directive|define
name|SC_PLUS
value|11
end_define

begin_define
define|#
directive|define
name|SC_MINUS
value|12
end_define

begin_define
define|#
directive|define
name|SC_MUL
value|13
end_define

begin_define
define|#
directive|define
name|SC_DIV
value|14
end_define

begin_define
define|#
directive|define
name|SC_MOD
value|15
end_define

begin_define
define|#
directive|define
name|SC_POW
value|16
end_define

begin_define
define|#
directive|define
name|SC_LPAREN
value|17
end_define

begin_define
define|#
directive|define
name|SC_RPAREN
value|18
end_define

begin_define
define|#
directive|define
name|SC_LBOX
value|19
end_define

begin_define
define|#
directive|define
name|SC_RBOX
value|20
end_define

begin_define
define|#
directive|define
name|SC_IDCHAR
value|21
end_define

begin_define
define|#
directive|define
name|SC_DIGIT
value|22
end_define

begin_define
define|#
directive|define
name|SC_DQUOTE
value|23
end_define

begin_define
define|#
directive|define
name|SC_ESCAPE
value|24
end_define

begin_define
define|#
directive|define
name|SC_COMMENT
value|25
end_define

begin_define
define|#
directive|define
name|SC_EQUAL
value|26
end_define

begin_define
define|#
directive|define
name|SC_NOT
value|27
end_define

begin_define
define|#
directive|define
name|SC_LT
value|28
end_define

begin_define
define|#
directive|define
name|SC_GT
value|29
end_define

begin_define
define|#
directive|define
name|SC_COMMA
value|30
end_define

begin_define
define|#
directive|define
name|SC_DOT
value|31
end_define

begin_define
define|#
directive|define
name|SC_MATCH
value|32
end_define

begin_define
define|#
directive|define
name|SC_DOLLAR
value|33
end_define

begin_define
define|#
directive|define
name|SC_UNEXPECTED
value|34
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|MAKESCAN
end_ifndef

begin_comment
comment|/* global functions in scan.c */
end_comment

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|scan_init
argument_list|,
operator|(
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|scan_cleanup
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|PROTO
argument_list|(
name|eat_nl
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|PROTO
argument_list|(
name|yylex
argument_list|,
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|YYSTYPE
name|yylval
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ct_ret
parameter_list|(
name|x
parameter_list|)
value|return current_token = (x)
end_define

begin_define
define|#
directive|define
name|next
parameter_list|()
value|(*buffp ? *buffp++ : slow_next())
end_define

begin_define
define|#
directive|define
name|un_next
parameter_list|()
value|buffp--
end_define

begin_define
define|#
directive|define
name|test1_ret
parameter_list|(
name|c
parameter_list|,
name|x
parameter_list|,
name|d
parameter_list|)
value|if ( next() == (c) ) ct_ret(x) ;\                            else { un_next() ; ct_ret(d) ; }
end_define

begin_define
define|#
directive|define
name|test2_ret
parameter_list|(
name|c1
parameter_list|,
name|x1
parameter_list|,
name|c2
parameter_list|,
name|x2
parameter_list|,
name|d
parameter_list|)
value|switch( next() )\                                    { case c1: ct_ret(x1) ;\                                      case c2: ct_ret(x2) ;\                                      default: un_next() ;\                                               ct_ret(d) ; }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! MAKESCAN  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

