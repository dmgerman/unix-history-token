begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1994 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TOKEN_H
end_ifndef

begin_define
define|#
directive|define
name|TOKEN_H
end_define

begin_include
include|#
directive|include
file|"zmath.h"
end_include

begin_comment
comment|/*  * Token types  */
end_comment

begin_define
define|#
directive|define
name|T_NULL
value|0
end_define

begin_comment
comment|/* null token */
end_comment

begin_define
define|#
directive|define
name|T_LEFTPAREN
value|1
end_define

begin_comment
comment|/* left parenthesis "(" */
end_comment

begin_define
define|#
directive|define
name|T_RIGHTPAREN
value|2
end_define

begin_comment
comment|/* right parenthesis ")" */
end_comment

begin_define
define|#
directive|define
name|T_LEFTBRACE
value|3
end_define

begin_comment
comment|/* left brace "{" */
end_comment

begin_define
define|#
directive|define
name|T_RIGHTBRACE
value|4
end_define

begin_comment
comment|/* right brace "}" */
end_comment

begin_define
define|#
directive|define
name|T_SEMICOLON
value|5
end_define

begin_comment
comment|/* end of statement ";" */
end_comment

begin_define
define|#
directive|define
name|T_EOF
value|6
end_define

begin_comment
comment|/* end of file */
end_comment

begin_define
define|#
directive|define
name|T_COLON
value|7
end_define

begin_comment
comment|/* label character ":" */
end_comment

begin_define
define|#
directive|define
name|T_ASSIGN
value|8
end_define

begin_comment
comment|/* assignment "=" */
end_comment

begin_define
define|#
directive|define
name|T_PLUS
value|9
end_define

begin_comment
comment|/* plus sign "+" */
end_comment

begin_define
define|#
directive|define
name|T_MINUS
value|10
end_define

begin_comment
comment|/* minus sign "-" */
end_comment

begin_define
define|#
directive|define
name|T_MULT
value|11
end_define

begin_comment
comment|/* multiply sign "*" */
end_comment

begin_define
define|#
directive|define
name|T_DIV
value|12
end_define

begin_comment
comment|/* divide sign "/" */
end_comment

begin_define
define|#
directive|define
name|T_MOD
value|13
end_define

begin_comment
comment|/* modulo sign "%" */
end_comment

begin_define
define|#
directive|define
name|T_POWER
value|14
end_define

begin_comment
comment|/* power sign "^" or "**" */
end_comment

begin_define
define|#
directive|define
name|T_EQ
value|15
end_define

begin_comment
comment|/* equality "==" */
end_comment

begin_define
define|#
directive|define
name|T_NE
value|16
end_define

begin_comment
comment|/* notequal "!=" */
end_comment

begin_define
define|#
directive|define
name|T_LT
value|17
end_define

begin_comment
comment|/* less than "<" */
end_comment

begin_define
define|#
directive|define
name|T_GT
value|18
end_define

begin_comment
comment|/* greater than ">" */
end_comment

begin_define
define|#
directive|define
name|T_LE
value|19
end_define

begin_comment
comment|/* less than or equals "<=" */
end_comment

begin_define
define|#
directive|define
name|T_GE
value|20
end_define

begin_comment
comment|/* greater than or equals ">=" */
end_comment

begin_define
define|#
directive|define
name|T_LEFTBRACKET
value|21
end_define

begin_comment
comment|/* left bracket "[" */
end_comment

begin_define
define|#
directive|define
name|T_RIGHTBRACKET
value|22
end_define

begin_comment
comment|/* right bracket "]" */
end_comment

begin_define
define|#
directive|define
name|T_SYMBOL
value|23
end_define

begin_comment
comment|/* symbol name */
end_comment

begin_define
define|#
directive|define
name|T_STRING
value|24
end_define

begin_comment
comment|/* string value (double quotes) */
end_comment

begin_define
define|#
directive|define
name|T_NUMBER
value|25
end_define

begin_comment
comment|/* numeric real constant */
end_comment

begin_define
define|#
directive|define
name|T_PLUSEQUALS
value|26
end_define

begin_comment
comment|/* plus equals "+=" */
end_comment

begin_define
define|#
directive|define
name|T_MINUSEQUALS
value|27
end_define

begin_comment
comment|/* minus equals "-=" */
end_comment

begin_define
define|#
directive|define
name|T_MULTEQUALS
value|28
end_define

begin_comment
comment|/* multiply equals "*=" */
end_comment

begin_define
define|#
directive|define
name|T_DIVEQUALS
value|29
end_define

begin_comment
comment|/* divide equals "/=" */
end_comment

begin_define
define|#
directive|define
name|T_MODEQUALS
value|30
end_define

begin_comment
comment|/* modulo equals "%=" */
end_comment

begin_define
define|#
directive|define
name|T_PLUSPLUS
value|31
end_define

begin_comment
comment|/* plusplus "++" */
end_comment

begin_define
define|#
directive|define
name|T_MINUSMINUS
value|32
end_define

begin_comment
comment|/* minusminus "--" */
end_comment

begin_define
define|#
directive|define
name|T_COMMA
value|33
end_define

begin_comment
comment|/* comma "," */
end_comment

begin_define
define|#
directive|define
name|T_ANDAND
value|34
end_define

begin_comment
comment|/* logical and "&&" */
end_comment

begin_define
define|#
directive|define
name|T_OROR
value|35
end_define

begin_comment
comment|/* logical or "||" */
end_comment

begin_define
define|#
directive|define
name|T_OLDVALUE
value|36
end_define

begin_comment
comment|/* old value from previous calculation */
end_comment

begin_define
define|#
directive|define
name|T_SLASHSLASH
value|37
end_define

begin_comment
comment|/* integer divide "//" */
end_comment

begin_define
define|#
directive|define
name|T_NEWLINE
value|38
end_define

begin_comment
comment|/* newline character */
end_comment

begin_define
define|#
directive|define
name|T_SLASHSLASHEQUALS
value|39
end_define

begin_comment
comment|/* integer divide equals "//=" */
end_comment

begin_define
define|#
directive|define
name|T_AND
value|40
end_define

begin_comment
comment|/* arithmetic and "&" */
end_comment

begin_define
define|#
directive|define
name|T_OR
value|41
end_define

begin_comment
comment|/* arithmetic or "|" */
end_comment

begin_define
define|#
directive|define
name|T_NOT
value|42
end_define

begin_comment
comment|/* logical not "!" */
end_comment

begin_define
define|#
directive|define
name|T_LEFTSHIFT
value|43
end_define

begin_comment
comment|/* left shift "<<" */
end_comment

begin_define
define|#
directive|define
name|T_RIGHTSHIFT
value|44
end_define

begin_comment
comment|/* right shift ">>" */
end_comment

begin_define
define|#
directive|define
name|T_ANDEQUALS
value|45
end_define

begin_comment
comment|/* and equals "&=" */
end_comment

begin_define
define|#
directive|define
name|T_OREQUALS
value|46
end_define

begin_comment
comment|/* or equals "|= */
end_comment

begin_define
define|#
directive|define
name|T_LSHIFTEQUALS
value|47
end_define

begin_comment
comment|/* left shift equals "<<=" */
end_comment

begin_define
define|#
directive|define
name|T_RSHIFTEQUALS
value|48
end_define

begin_comment
comment|/* right shift equals ">>= */
end_comment

begin_define
define|#
directive|define
name|T_POWEREQUALS
value|49
end_define

begin_comment
comment|/* power equals "^=" or "**=" */
end_comment

begin_define
define|#
directive|define
name|T_PERIOD
value|50
end_define

begin_comment
comment|/* period "." */
end_comment

begin_define
define|#
directive|define
name|T_IMAGINARY
value|51
end_define

begin_comment
comment|/* numeric imaginary constant */
end_comment

begin_define
define|#
directive|define
name|T_AMPERSAND
value|52
end_define

begin_comment
comment|/* ampersand "&" */
end_comment

begin_define
define|#
directive|define
name|T_QUESTIONMARK
value|53
end_define

begin_comment
comment|/* question mark "?" */
end_comment

begin_comment
comment|/*  * Keyword tokens  */
end_comment

begin_define
define|#
directive|define
name|T_IF
value|101
end_define

begin_comment
comment|/* if keyword */
end_comment

begin_define
define|#
directive|define
name|T_ELSE
value|102
end_define

begin_comment
comment|/* else keyword */
end_comment

begin_define
define|#
directive|define
name|T_WHILE
value|103
end_define

begin_comment
comment|/* while keyword */
end_comment

begin_define
define|#
directive|define
name|T_CONTINUE
value|104
end_define

begin_comment
comment|/* continue keyword */
end_comment

begin_define
define|#
directive|define
name|T_BREAK
value|105
end_define

begin_comment
comment|/* break keyword */
end_comment

begin_define
define|#
directive|define
name|T_GOTO
value|106
end_define

begin_comment
comment|/* goto keyword */
end_comment

begin_define
define|#
directive|define
name|T_RETURN
value|107
end_define

begin_comment
comment|/* return keyword */
end_comment

begin_define
define|#
directive|define
name|T_LOCAL
value|108
end_define

begin_comment
comment|/* local keyword */
end_comment

begin_define
define|#
directive|define
name|T_GLOBAL
value|109
end_define

begin_comment
comment|/* global keyword */
end_comment

begin_define
define|#
directive|define
name|T_STATIC
value|110
end_define

begin_comment
comment|/* static keyword */
end_comment

begin_define
define|#
directive|define
name|T_DO
value|111
end_define

begin_comment
comment|/* do keyword */
end_comment

begin_define
define|#
directive|define
name|T_FOR
value|112
end_define

begin_comment
comment|/* for keyword */
end_comment

begin_define
define|#
directive|define
name|T_SWITCH
value|113
end_define

begin_comment
comment|/* switch keyword */
end_comment

begin_define
define|#
directive|define
name|T_CASE
value|114
end_define

begin_comment
comment|/* case keyword */
end_comment

begin_define
define|#
directive|define
name|T_DEFAULT
value|115
end_define

begin_comment
comment|/* default keyword */
end_comment

begin_define
define|#
directive|define
name|T_QUIT
value|116
end_define

begin_comment
comment|/* quit keyword */
end_comment

begin_define
define|#
directive|define
name|T_DEFINE
value|117
end_define

begin_comment
comment|/* define keyword */
end_comment

begin_define
define|#
directive|define
name|T_READ
value|118
end_define

begin_comment
comment|/* read keyword */
end_comment

begin_define
define|#
directive|define
name|T_SHOW
value|119
end_define

begin_comment
comment|/* show keyword */
end_comment

begin_define
define|#
directive|define
name|T_HELP
value|120
end_define

begin_comment
comment|/* help keyword */
end_comment

begin_define
define|#
directive|define
name|T_WRITE
value|121
end_define

begin_comment
comment|/* write keyword */
end_comment

begin_define
define|#
directive|define
name|T_MAT
value|122
end_define

begin_comment
comment|/* mat keyword */
end_comment

begin_define
define|#
directive|define
name|T_OBJ
value|123
end_define

begin_comment
comment|/* obj keyword */
end_comment

begin_define
define|#
directive|define
name|T_PRINT
value|124
end_define

begin_comment
comment|/* print keyword */
end_comment

begin_define
define|#
directive|define
name|T_USE
value|125
end_define

begin_comment
comment|/* use keyword */
end_comment

begin_define
define|#
directive|define
name|iskeyword
parameter_list|(
name|n
parameter_list|)
value|((n)> 100)
end_define

begin_comment
comment|/* TRUE if token is a keyword */
end_comment

begin_comment
comment|/*  * Flags returned describing results of expression parsing.  */
end_comment

begin_define
define|#
directive|define
name|EXPR_RVALUE
value|0x0001
end_define

begin_comment
comment|/* result is an rvalue */
end_comment

begin_define
define|#
directive|define
name|EXPR_CONST
value|0x0002
end_define

begin_comment
comment|/* result is constant */
end_comment

begin_define
define|#
directive|define
name|EXPR_ASSIGN
value|0x0004
end_define

begin_comment
comment|/* result is an assignment */
end_comment

begin_define
define|#
directive|define
name|isrvalue
parameter_list|(
name|n
parameter_list|)
value|((n)& EXPR_RVALUE)
end_define

begin_comment
comment|/* TRUE if expression is rvalue */
end_comment

begin_define
define|#
directive|define
name|islvalue
parameter_list|(
name|n
parameter_list|)
value|(((n)& EXPR_RVALUE) == 0)
end_define

begin_comment
comment|/* TRUE if expr is lvalue */
end_comment

begin_define
define|#
directive|define
name|isconst
parameter_list|(
name|n
parameter_list|)
value|((n)& EXPR_CONST)
end_define

begin_comment
comment|/* TRUE if expr is constant */
end_comment

begin_define
define|#
directive|define
name|isassign
parameter_list|(
name|n
parameter_list|)
value|((n)& EXPR_ASSIGN)
end_define

begin_comment
comment|/* TRUE if expr is an assignment */
end_comment

begin_comment
comment|/*  * Flags for modes for tokenizing.  */
end_comment

begin_define
define|#
directive|define
name|TM_DEFAULT
value|0x0
end_define

begin_comment
comment|/* normal mode */
end_comment

begin_define
define|#
directive|define
name|TM_NEWLINES
value|0x1
end_define

begin_comment
comment|/* treat any newline as a token */
end_comment

begin_define
define|#
directive|define
name|TM_ALLSYMS
value|0x2
end_define

begin_comment
comment|/* treat almost everything as a symbol */
end_comment

begin_decl_stmt
specifier|extern
name|long
name|errorcount
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of errors found */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|tokenstring
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|long
name|tokennumber
name|MATH_PROTO
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
name|inittokens
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|tokenmode
name|MATH_PROTO
argument_list|(
operator|(
name|int
name|flag
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gettoken
name|MATH_PROTO
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
name|rescantoken
name|MATH_PROTO
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_ifdef
ifdef|#
directive|ifdef
name|VARARGS
end_ifdef

begin_function_decl
specifier|extern
name|void
name|scanerror
parameter_list|()
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|void
name|scanerror
name|MATH_PROTO
argument_list|(
operator|(
name|int
operator|,
name|char
operator|*
operator|,
operator|...
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* END CODE */
end_comment

end_unit

