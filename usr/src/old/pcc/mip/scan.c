begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|sccsid
init|=
literal|"@(#)scan.c	2.16 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

begin_include
include|#
directive|include
file|"pass1.h"
end_include

begin_include
include|#
directive|include
file|<a.out.h>
end_include

begin_include
include|#
directive|include
file|<stab.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_comment
comment|/* temporarily */
end_comment

begin_decl_stmt
name|int
name|asm_esc
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* asm escaped used in file */
end_comment

begin_comment
comment|/* lexical actions */
end_comment

begin_define
define|#
directive|define
name|A_ERR
value|0
end_define

begin_comment
comment|/* illegal character */
end_comment

begin_define
define|#
directive|define
name|A_LET
value|1
end_define

begin_comment
comment|/* saw a letter */
end_comment

begin_define
define|#
directive|define
name|A_DIG
value|2
end_define

begin_comment
comment|/* saw a digit */
end_comment

begin_define
define|#
directive|define
name|A_1C
value|3
end_define

begin_comment
comment|/* return a single character */
end_comment

begin_define
define|#
directive|define
name|A_STR
value|4
end_define

begin_comment
comment|/* string */
end_comment

begin_define
define|#
directive|define
name|A_CC
value|5
end_define

begin_comment
comment|/* character constant */
end_comment

begin_define
define|#
directive|define
name|A_BCD
value|6
end_define

begin_comment
comment|/* GCOS BCD constant */
end_comment

begin_define
define|#
directive|define
name|A_SL
value|7
end_define

begin_comment
comment|/* saw a / */
end_comment

begin_define
define|#
directive|define
name|A_DOT
value|8
end_define

begin_comment
comment|/* saw a . */
end_comment

begin_define
define|#
directive|define
name|A_PL
value|9
end_define

begin_comment
comment|/* + */
end_comment

begin_define
define|#
directive|define
name|A_MI
value|10
end_define

begin_comment
comment|/* - */
end_comment

begin_define
define|#
directive|define
name|A_EQ
value|11
end_define

begin_comment
comment|/* = */
end_comment

begin_define
define|#
directive|define
name|A_NOT
value|12
end_define

begin_comment
comment|/* ! */
end_comment

begin_define
define|#
directive|define
name|A_LT
value|13
end_define

begin_comment
comment|/*< */
end_comment

begin_define
define|#
directive|define
name|A_GT
value|14
end_define

begin_comment
comment|/*> */
end_comment

begin_define
define|#
directive|define
name|A_AND
value|16
end_define

begin_comment
comment|/*& */
end_comment

begin_define
define|#
directive|define
name|A_OR
value|17
end_define

begin_comment
comment|/* | */
end_comment

begin_define
define|#
directive|define
name|A_WS
value|18
end_define

begin_comment
comment|/* whitespace (not \n) */
end_comment

begin_define
define|#
directive|define
name|A_NL
value|19
end_define

begin_comment
comment|/* \n */
end_comment

begin_comment
comment|/* character classes */
end_comment

begin_define
define|#
directive|define
name|LEXLET
value|01
end_define

begin_define
define|#
directive|define
name|LEXDIG
value|02
end_define

begin_define
define|#
directive|define
name|LEXOCT
value|04
end_define

begin_define
define|#
directive|define
name|LEXHEX
value|010
end_define

begin_define
define|#
directive|define
name|LEXWS
value|020
end_define

begin_define
define|#
directive|define
name|LEXDOT
value|040
end_define

begin_comment
comment|/* reserved word actions */
end_comment

begin_define
define|#
directive|define
name|AR_TY
value|0
end_define

begin_comment
comment|/* type word */
end_comment

begin_define
define|#
directive|define
name|AR_RW
value|1
end_define

begin_comment
comment|/* simple reserved word */
end_comment

begin_define
define|#
directive|define
name|AR_CL
value|2
end_define

begin_comment
comment|/* storage class word */
end_comment

begin_define
define|#
directive|define
name|AR_S
value|3
end_define

begin_comment
comment|/* struct */
end_comment

begin_define
define|#
directive|define
name|AR_U
value|4
end_define

begin_comment
comment|/* union */
end_comment

begin_define
define|#
directive|define
name|AR_E
value|5
end_define

begin_comment
comment|/* enum */
end_comment

begin_define
define|#
directive|define
name|AR_A
value|6
end_define

begin_comment
comment|/* asm */
end_comment

begin_comment
comment|/* text buffer */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLEXNAMES
end_ifndef

begin_define
define|#
directive|define
name|LXTSZ
value|100
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LXTSZ
value|BUFSIZ
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
name|yytext
index|[
name|LXTSZ
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lxgcp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|proflg
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|gdebug
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|fpe
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|sigvec
name|fpe_sigvec
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|oldway
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* allocate storage so lint will compile as well */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINT
end_ifndef

begin_decl_stmt
specifier|extern
name|int
name|lastloc
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|unsigned
name|caloff
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|mainp1
argument_list|(
argument|argc
argument_list|,
argument|argv
argument_list|)
end_macro

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* control multiple files */
specifier|register
name|i
expr_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
specifier|extern
name|int
name|idebug
decl_stmt|,
name|bdebug
decl_stmt|,
name|tdebug
decl_stmt|,
name|edebug
decl_stmt|;
specifier|extern
name|int
name|ddebug
decl_stmt|,
name|xdebug
decl_stmt|,
name|gdebug
decl_stmt|,
name|adebug
decl_stmt|;
specifier|extern
name|unsigned
name|int
name|offsz
decl_stmt|;
name|int
name|fdef
init|=
literal|0
decl_stmt|;
specifier|extern
name|char
modifier|*
name|release
decl_stmt|;
name|offsz
operator|=
name|caloff
argument_list|()
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|1
init|;
name|i
operator|<
name|argc
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
operator|*
operator|(
name|cp
operator|=
name|argv
index|[
name|i
index|]
operator|)
operator|==
literal|'-'
operator|&&
operator|*
operator|++
name|cp
operator|==
literal|'X'
condition|)
block|{
while|while
condition|(
operator|*
operator|++
name|cp
condition|)
block|{
switch|switch
condition|(
operator|*
name|cp
condition|)
block|{
case|case
literal|'r'
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"Release: %s\n"
argument_list|,
name|release
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'d'
case|:
operator|++
name|ddebug
expr_stmt|;
break|break;
case|case
literal|'i'
case|:
operator|++
name|idebug
expr_stmt|;
break|break;
case|case
literal|'b'
case|:
operator|++
name|bdebug
expr_stmt|;
break|break;
case|case
literal|'t'
case|:
operator|++
name|tdebug
expr_stmt|;
break|break;
case|case
literal|'e'
case|:
operator|++
name|edebug
expr_stmt|;
break|break;
case|case
literal|'x'
case|:
operator|++
name|xdebug
expr_stmt|;
break|break;
case|case
literal|'P'
case|:
comment|/* profiling */
operator|++
name|proflg
expr_stmt|;
break|break;
case|case
literal|'g'
case|:
operator|++
name|gdebug
expr_stmt|;
break|break;
case|case
literal|'a'
case|:
operator|++
name|adebug
expr_stmt|;
break|break;
case|case
literal|'G'
case|:
operator|++
name|gdebug
expr_stmt|;
name|oldway
operator|=
literal|1
expr_stmt|;
break|break;
block|}
block|}
block|}
else|else
block|{
if|if
condition|(
operator|*
operator|(
name|argv
index|[
name|i
index|]
operator|)
operator|!=
literal|'-'
condition|)
switch|switch
condition|(
name|fdef
operator|++
condition|)
block|{
case|case
literal|0
case|:
case|case
literal|1
case|:
if|if
condition|(
name|freopen
argument_list|(
name|argv
index|[
name|i
index|]
argument_list|,
name|fdef
operator|==
literal|1
condition|?
literal|"r"
else|:
literal|"w"
argument_list|,
name|fdef
operator|==
literal|1
condition|?
name|stdin
else|:
name|stdout
argument_list|)
operator|==
name|NULL
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ccom:can't open %s\n"
argument_list|,
name|argv
index|[
name|i
index|]
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
break|break;
default|default:
empty_stmt|;
block|}
block|}
block|}
ifdef|#
directive|ifdef
name|ONEPASS
operator|(
name|void
operator|)
name|p2init
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
endif|#
directive|endif
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|SYMTSZ
condition|;
operator|++
name|i
control|)
name|stab
index|[
name|i
index|]
operator|.
name|stype
operator|=
name|TNULL
expr_stmt|;
name|lineno
operator|=
literal|1
expr_stmt|;
name|lxinit
argument_list|()
expr_stmt|;
name|tinit
argument_list|()
expr_stmt|;
name|mkdope
argument_list|()
expr_stmt|;
comment|/* dimension table initialization */
name|dimtab
index|[
name|NULL
index|]
operator|=
literal|0
expr_stmt|;
name|dimtab
index|[
name|CHAR
index|]
operator|=
name|SZCHAR
expr_stmt|;
name|dimtab
index|[
name|INT
index|]
operator|=
name|SZINT
expr_stmt|;
name|dimtab
index|[
name|FLOAT
index|]
operator|=
name|SZFLOAT
expr_stmt|;
name|dimtab
index|[
name|DOUBLE
index|]
operator|=
name|SZDOUBLE
expr_stmt|;
name|dimtab
index|[
name|LONG
index|]
operator|=
name|SZLONG
expr_stmt|;
name|dimtab
index|[
name|SHORT
index|]
operator|=
name|SZSHORT
expr_stmt|;
name|dimtab
index|[
name|UCHAR
index|]
operator|=
name|SZCHAR
expr_stmt|;
name|dimtab
index|[
name|USHORT
index|]
operator|=
name|SZSHORT
expr_stmt|;
name|dimtab
index|[
name|UNSIGNED
index|]
operator|=
name|SZINT
expr_stmt|;
name|dimtab
index|[
name|ULONG
index|]
operator|=
name|SZLONG
expr_stmt|;
comment|/* starts past any of the above */
name|curdim
operator|=
literal|16
expr_stmt|;
name|reached
operator|=
literal|1
expr_stmt|;
name|fpe_sigvec
operator|.
name|sv_handler
operator|=
name|fpe
expr_stmt|;
operator|(
name|void
operator|)
name|sigvec
argument_list|(
name|SIGFPE
argument_list|,
operator|&
name|fpe_sigvec
argument_list|,
operator|(
expr|struct
name|sigvec
operator|*
operator|)
name|NULL
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|yyparse
argument_list|()
expr_stmt|;
name|yyaccpt
argument_list|()
expr_stmt|;
name|ejobcode
argument_list|(
name|nerrors
condition|?
literal|1
else|:
literal|0
argument_list|)
expr_stmt|;
return|return
operator|(
name|nerrors
condition|?
literal|1
else|:
literal|0
operator|)
return|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|ibm
end_ifdef

begin_define
define|#
directive|define
name|CSMASK
value|0377
end_define

begin_define
define|#
directive|define
name|CSSZ
value|256
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CSMASK
value|0177
end_define

begin_define
define|#
directive|define
name|CSSZ
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|short
name|lxmask
index|[
name|CSSZ
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|lxenter
argument_list|(
name|s
argument_list|,
name|m
argument_list|)
specifier|register
name|char
operator|*
name|s
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|short
name|m
decl_stmt|;
end_decl_stmt

begin_block
block|{
comment|/* enter a mask into lxmask */
specifier|register
name|c
expr_stmt|;
while|while
condition|(
name|c
operator|=
operator|*
name|s
operator|++
condition|)
name|lxmask
index|[
name|c
operator|+
literal|1
index|]
operator||=
name|m
expr_stmt|;
block|}
end_block

begin_define
define|#
directive|define
name|lxget
parameter_list|(
name|c
parameter_list|,
name|m
parameter_list|)
value|(lxgcp=yytext,lxmore(c,m))
end_define

begin_expr_stmt
name|lxmore
argument_list|(
name|c
argument_list|,
name|m
argument_list|)
specifier|register
name|c
operator|,
name|m
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
operator|*
operator|(
name|cp
operator|=
name|lxgcp
operator|)
operator|=
name|c
expr_stmt|;
while|while
condition|(
name|c
operator|=
name|getchar
argument_list|()
operator|,
name|lxmask
index|[
name|c
operator|+
literal|1
index|]
operator|&
name|m
condition|)
block|{
if|if
condition|(
name|cp
operator|<
operator|&
name|yytext
index|[
name|LXTSZ
operator|-
literal|1
index|]
condition|)
block|{
operator|*
operator|++
name|cp
operator|=
name|c
expr_stmt|;
block|}
block|}
name|ungetc
argument_list|(
name|c
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
operator|*
operator|(
name|lxgcp
operator|=
name|cp
operator|+
literal|1
operator|)
operator|=
literal|'\0'
expr_stmt|;
block|}
end_block

begin_struct
struct|struct
name|lxdope
block|{
name|short
name|lxch
decl_stmt|;
comment|/* the character */
name|short
name|lxact
decl_stmt|;
comment|/* the action to be performed */
name|short
name|lxtok
decl_stmt|;
comment|/* the token number to be returned */
name|short
name|lxval
decl_stmt|;
comment|/* the value to be returned */
block|}
name|lxdope
index|[]
init|=
block|{
literal|'@'
block|,
name|A_ERR
block|,
literal|0
block|,
literal|0
block|,
comment|/* illegal characters go here... */
literal|'_'
block|,
name|A_LET
block|,
literal|0
block|,
literal|0
block|,
comment|/* letters point here */
literal|'0'
block|,
name|A_DIG
block|,
literal|0
block|,
literal|0
block|,
comment|/* digits point here */
literal|' '
block|,
name|A_WS
block|,
literal|0
block|,
literal|0
block|,
comment|/* whitespace goes here */
literal|'\n'
block|,
name|A_NL
block|,
literal|0
block|,
literal|0
block|,
literal|'"'
block|,
name|A_STR
block|,
literal|0
block|,
literal|0
block|,
comment|/* character string */
literal|'\''
block|,
name|A_CC
block|,
literal|0
block|,
literal|0
block|,
comment|/* character constant */
ifdef|#
directive|ifdef
name|gcos
literal|'`'
block|,
name|A_BCD
block|,
literal|0
block|,
literal|0
block|,
comment|/* GCOS BCD constant */
endif|#
directive|endif
literal|'('
block|,
name|A_1C
block|,
name|LP
block|,
literal|0
block|,
literal|')'
block|,
name|A_1C
block|,
name|RP
block|,
literal|0
block|,
literal|'{'
block|,
name|A_1C
block|,
name|LC
block|,
literal|0
block|,
literal|'}'
block|,
name|A_1C
block|,
name|RC
block|,
literal|0
block|,
literal|'['
block|,
name|A_1C
block|,
name|LB
block|,
literal|0
block|,
literal|']'
block|,
name|A_1C
block|,
name|RB
block|,
literal|0
block|,
literal|'*'
block|,
name|A_1C
block|,
name|MUL
block|,
name|MUL
block|,
literal|'?'
block|,
name|A_1C
block|,
name|QUEST
block|,
literal|0
block|,
literal|':'
block|,
name|A_1C
block|,
name|COLON
block|,
literal|0
block|,
literal|'+'
block|,
name|A_PL
block|,
name|PLUS
block|,
name|PLUS
block|,
literal|'-'
block|,
name|A_MI
block|,
name|MINUS
block|,
name|MINUS
block|,
literal|'/'
block|,
name|A_SL
block|,
name|DIVOP
block|,
name|DIV
block|,
literal|'%'
block|,
name|A_1C
block|,
name|DIVOP
block|,
name|MOD
block|,
literal|'&'
block|,
name|A_AND
block|,
name|AND
block|,
name|AND
block|,
literal|'|'
block|,
name|A_OR
block|,
name|OR
block|,
name|OR
block|,
literal|'^'
block|,
name|A_1C
block|,
name|ER
block|,
name|ER
block|,
literal|'!'
block|,
name|A_NOT
block|,
name|UNOP
block|,
name|NOT
block|,
literal|'~'
block|,
name|A_1C
block|,
name|UNOP
block|,
name|COMPL
block|,
literal|','
block|,
name|A_1C
block|,
name|CM
block|,
name|CM
block|,
literal|';'
block|,
name|A_1C
block|,
name|SM
block|,
literal|0
block|,
literal|'.'
block|,
name|A_DOT
block|,
name|STROP
block|,
name|DOT
block|,
literal|'<'
block|,
name|A_LT
block|,
name|RELOP
block|,
name|LT
block|,
literal|'>'
block|,
name|A_GT
block|,
name|RELOP
block|,
name|GT
block|,
literal|'='
block|,
name|A_EQ
block|,
name|ASSIGN
block|,
name|ASSIGN
block|,
operator|-
literal|1
block|,
name|A_1C
block|,
literal|0
block|,
literal|0
block|, 	}
struct|;
end_struct

begin_decl_stmt
name|struct
name|lxdope
modifier|*
name|lxcp
index|[
name|CSSZ
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_macro
name|lxinit
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|lxdope
modifier|*
name|p
decl_stmt|;
specifier|register
name|i
expr_stmt|;
specifier|register
name|char
modifier|*
name|cp
decl_stmt|;
comment|/* set up character classes */
name|lxenter
argument_list|(
literal|"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_"
argument_list|,
name|LEXLET
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|VMS
name|lxmask
index|[
literal|'$'
operator|+
literal|1
index|]
operator||=
name|LEXLET
expr_stmt|;
endif|#
directive|endif
name|lxenter
argument_list|(
literal|"0123456789"
argument_list|,
name|LEXDIG
argument_list|)
expr_stmt|;
name|lxenter
argument_list|(
literal|"0123456789abcdefABCDEF"
argument_list|,
name|LEXHEX
argument_list|)
expr_stmt|;
name|lxenter
argument_list|(
literal|" \t\r\b\f\v"
argument_list|,
name|LEXWS
argument_list|)
expr_stmt|;
name|lxenter
argument_list|(
literal|"01234567"
argument_list|,
name|LEXOCT
argument_list|)
expr_stmt|;
name|lxmask
index|[
literal|'.'
operator|+
literal|1
index|]
operator||=
name|LEXDOT
expr_stmt|;
comment|/* make lxcp point to appropriate lxdope entry for each character */
comment|/* initialize error entries */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|CSSZ
condition|;
operator|++
name|i
control|)
name|lxcp
index|[
name|i
index|]
operator|=
name|lxdope
expr_stmt|;
comment|/* make unique entries */
for|for
control|(
name|p
operator|=
name|lxdope
init|;
condition|;
operator|++
name|p
control|)
block|{
name|lxcp
index|[
name|p
operator|->
name|lxch
operator|+
literal|1
index|]
operator|=
name|p
expr_stmt|;
if|if
condition|(
name|p
operator|->
name|lxch
operator|<
literal|0
condition|)
break|break;
block|}
comment|/* handle letters, digits, and whitespace */
comment|/* by convention, first, second, and third places */
name|cp
operator|=
literal|"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
expr_stmt|;
while|while
condition|(
operator|*
name|cp
condition|)
name|lxcp
index|[
operator|*
name|cp
operator|++
operator|+
literal|1
index|]
operator|=
operator|&
name|lxdope
index|[
literal|1
index|]
expr_stmt|;
ifdef|#
directive|ifdef
name|VMS
name|lxcp
index|[
literal|'$'
operator|+
literal|1
index|]
operator|=
operator|&
name|lxdope
index|[
literal|1
index|]
expr_stmt|;
endif|#
directive|endif
name|cp
operator|=
literal|"123456789"
expr_stmt|;
while|while
condition|(
operator|*
name|cp
condition|)
name|lxcp
index|[
operator|*
name|cp
operator|++
operator|+
literal|1
index|]
operator|=
operator|&
name|lxdope
index|[
literal|2
index|]
expr_stmt|;
name|cp
operator|=
literal|"\t\b\r\f\v"
expr_stmt|;
while|while
condition|(
operator|*
name|cp
condition|)
name|lxcp
index|[
operator|*
name|cp
operator|++
operator|+
literal|1
index|]
operator|=
operator|&
name|lxdope
index|[
literal|3
index|]
expr_stmt|;
comment|/* first line might have title */
name|lxtitle
argument_list|()
expr_stmt|;
block|}
end_block

begin_decl_stmt
name|int
name|lxmatch
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* character to be matched in char or string constant */
end_comment

begin_macro
name|lxstr
argument_list|(
argument|ct
argument_list|)
end_macro

begin_block
block|{
comment|/* match a string or character constant, up to lxmatch */
specifier|register
name|c
expr_stmt|;
specifier|register
name|val
expr_stmt|;
specifier|register
name|i
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
operator|(
name|c
operator|=
name|getchar
argument_list|()
operator|)
operator|!=
name|lxmatch
condition|)
block|{
switch|switch
condition|(
name|c
condition|)
block|{
case|case
name|EOF
case|:
name|uerror
argument_list|(
literal|"unexpected EOF"
argument_list|)
expr_stmt|;
break|break;
case|case
literal|'\n'
case|:
name|uerror
argument_list|(
literal|"newline in string or char constant"
argument_list|)
expr_stmt|;
operator|++
name|lineno
expr_stmt|;
break|break;
case|case
literal|'\\'
case|:
switch|switch
condition|(
name|c
operator|=
name|getchar
argument_list|()
condition|)
block|{
case|case
literal|'\n'
case|:
operator|++
name|lineno
expr_stmt|;
continue|continue;
default|default:
ifdef|#
directive|ifdef
name|LINT
if|if
condition|(
name|hflag
condition|)
name|uerror
argument_list|(
literal|"superfluous backslash in %s constant"
argument_list|,
name|lxmatch
operator|==
literal|'\''
condition|?
literal|"char"
else|:
literal|"string"
argument_list|)
expr_stmt|;
comment|/*FALLTHROUGH*/
endif|#
directive|endif
case|case
literal|'\\'
case|:
case|case
literal|'\"'
case|:
case|case
literal|'\''
case|:
name|val
operator|=
name|c
expr_stmt|;
goto|goto
name|mkcc
goto|;
case|case
literal|'n'
case|:
name|val
operator|=
literal|'\n'
expr_stmt|;
goto|goto
name|mkcc
goto|;
case|case
literal|'r'
case|:
name|val
operator|=
literal|'\r'
expr_stmt|;
goto|goto
name|mkcc
goto|;
case|case
literal|'b'
case|:
name|val
operator|=
literal|'\b'
expr_stmt|;
goto|goto
name|mkcc
goto|;
case|case
literal|'t'
case|:
name|val
operator|=
literal|'\t'
expr_stmt|;
goto|goto
name|mkcc
goto|;
case|case
literal|'f'
case|:
name|val
operator|=
literal|'\f'
expr_stmt|;
goto|goto
name|mkcc
goto|;
case|case
literal|'v'
case|:
name|val
operator|=
literal|'\v'
expr_stmt|;
goto|goto
name|mkcc
goto|;
case|case
literal|'0'
case|:
case|case
literal|'1'
case|:
case|case
literal|'2'
case|:
case|case
literal|'3'
case|:
case|case
literal|'4'
case|:
case|case
literal|'5'
case|:
case|case
literal|'6'
case|:
case|case
literal|'7'
case|:
name|val
operator|=
name|c
operator|-
literal|'0'
expr_stmt|;
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
comment|/* try for 2 */
if|if
condition|(
name|lxmask
index|[
name|c
operator|+
literal|1
index|]
operator|&
name|LEXOCT
condition|)
block|{
name|val
operator|=
operator|(
name|val
operator|<<
literal|3
operator|)
operator||
operator|(
name|c
operator|-
literal|'0'
operator|)
expr_stmt|;
name|c
operator|=
name|getchar
argument_list|()
expr_stmt|;
comment|/* try for 3 */
if|if
condition|(
name|lxmask
index|[
name|c
operator|+
literal|1
index|]
operator|&
name|LEXOCT
condition|)
block|{
name|val
operator|=
operator|(
name|val
operator|<<
literal|3
operator|)
operator||
operator|(
name|c
operator|-
literal|'0'
operator|)
expr_stmt|;
block|}
else|else
name|ungetc
argument_list|(
name|c
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
block|}
else|else
name|ungetc
argument_list|(
name|c
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
goto|goto
name|mkcc1
goto|;
block|}
default|default:
name|val
operator|=
name|c
expr_stmt|;
name|mkcc
label|:
name|val
operator|=
name|CCTRANS
argument_list|(
name|val
argument_list|)
expr_stmt|;
name|mkcc1
label|:
if|if
condition|(
name|lxmatch
operator|==
literal|'\''
condition|)
block|{
name|val
operator|=
name|CHARCAST
argument_list|(
name|val
argument_list|)
expr_stmt|;
comment|/* it is, after all, a "character" constant */
name|makecc
argument_list|(
name|val
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|/* stash the byte into the string */
if|if
condition|(
name|strflg
condition|)
block|{
if|if
condition|(
name|ct
operator|==
literal|0
operator|||
name|i
operator|<
name|ct
condition|)
name|putbyte
argument_list|(
name|val
argument_list|)
expr_stmt|;
elseif|else
if|if
condition|(
name|i
operator|==
name|ct
condition|)
name|werror
argument_list|(
literal|"non-null byte ignored in string initializer"
argument_list|)
expr_stmt|;
block|}
else|else
name|bycode
argument_list|(
name|val
argument_list|,
name|i
argument_list|)
expr_stmt|;
block|}
operator|++
name|i
expr_stmt|;
continue|continue;
block|}
break|break;
block|}
comment|/* end of string or  char constant */
if|if
condition|(
name|lxmatch
operator|==
literal|'"'
condition|)
block|{
if|if
condition|(
name|strflg
condition|)
block|{
comment|/* end the string */
if|if
condition|(
name|ct
operator|==
literal|0
operator|||
name|i
operator|<
name|ct
condition|)
name|putbyte
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|/* the null at the end */
block|}
else|else
block|{
comment|/* the initializer gets a null byte */
name|bycode
argument_list|(
literal|0
argument_list|,
name|i
operator|++
argument_list|)
expr_stmt|;
name|bycode
argument_list|(
operator|-
literal|1
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|dimtab
index|[
name|curdim
index|]
operator|=
name|i
expr_stmt|;
comment|/* in case of later sizeof ... */
block|}
block|}
else|else
block|{
comment|/* end the character constant */
if|if
condition|(
name|i
operator|==
literal|0
condition|)
name|uerror
argument_list|(
literal|"empty character constant"
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>
operator|(
name|SZINT
operator|/
name|SZCHAR
operator|)
operator|||
operator|(
operator|(
name|pflag
operator|||
name|hflag
operator|)
operator|&&
name|i
operator|>
literal|1
operator|)
condition|)
name|uerror
argument_list|(
literal|"too many characters in character constant"
argument_list|)
expr_stmt|;
block|}
name|lxmatch
operator|=
literal|0
expr_stmt|;
comment|/* handshake with yylex() */
block|}
end_block

begin_macro
name|lxcom
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|c
expr_stmt|;
comment|/* saw a /*: process a comment */
for|for
control|(
init|;
condition|;
control|)
block|{
switch|switch
condition|(
name|c
operator|=
name|getchar
argument_list|()
condition|)
block|{
case|case
name|EOF
case|:
name|uerror
argument_list|(
literal|"unexpected EOF"
argument_list|)
expr_stmt|;
return|return;
case|case
literal|'\n'
case|:
operator|++
name|lineno
expr_stmt|;
default|default:
continue|continue;
case|case
literal|'*'
case|:
if|if
condition|(
operator|(
name|c
operator|=
name|getchar
argument_list|()
operator|)
operator|==
literal|'/'
condition|)
return|return;
else|else
name|ungetc
argument_list|(
name|c
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
continue|continue;
ifdef|#
directive|ifdef
name|LINT
case|case
literal|'V'
case|:
name|lxget
argument_list|(
name|c
argument_list|,
name|LEXLET
operator||
name|LEXDIG
argument_list|)
expr_stmt|;
block|{
specifier|extern
name|int
name|vaflag
decl_stmt|;
name|int
name|i
decl_stmt|;
name|i
operator|=
name|yytext
index|[
literal|7
index|]
condition|?
name|yytext
index|[
literal|7
index|]
operator|-
literal|'0'
else|:
literal|0
expr_stmt|;
name|yytext
index|[
literal|7
index|]
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|yytext
argument_list|,
literal|"VARARGS"
argument_list|)
condition|)
continue|continue;
name|vaflag
operator|=
name|i
expr_stmt|;
continue|continue;
block|}
case|case
literal|'L'
case|:
name|lxget
argument_list|(
name|c
argument_list|,
name|LEXLET
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|yytext
argument_list|,
literal|"LINTLIBRARY"
argument_list|)
condition|)
continue|continue;
block|{
specifier|extern
name|int
name|libflag
decl_stmt|;
name|libflag
operator|=
literal|1
expr_stmt|;
block|}
continue|continue;
case|case
literal|'A'
case|:
name|lxget
argument_list|(
name|c
argument_list|,
name|LEXLET
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|yytext
argument_list|,
literal|"ARGSUSED"
argument_list|)
condition|)
continue|continue;
block|{
specifier|extern
name|int
name|argflag
decl_stmt|,
name|vflag
decl_stmt|;
name|argflag
operator|=
literal|1
expr_stmt|;
name|vflag
operator|=
literal|0
expr_stmt|;
block|}
continue|continue;
case|case
literal|'N'
case|:
name|lxget
argument_list|(
name|c
argument_list|,
name|LEXLET
argument_list|)
expr_stmt|;
if|if
condition|(
name|strcmp
argument_list|(
name|yytext
argument_list|,
literal|"NOTREACHED"
argument_list|)
condition|)
continue|continue;
name|reached
operator|=
literal|0
expr_stmt|;
continue|continue;
endif|#
directive|endif
block|}
block|}
block|}
end_block

begin_macro
name|yylex
argument_list|()
end_macro

begin_block
block|{
name|double
name|atof
parameter_list|()
function_decl|;
if|if
condition|(
name|lxmatch
operator|!=
literal|0
condition|)
block|{
comment|/* recover from a syntax error that consumes a STRING token */
name|strflg
operator|=
literal|1
expr_stmt|;
name|lxstr
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
for|for
control|(
init|;
condition|;
control|)
block|{
specifier|register
name|lxchar
expr_stmt|;
specifier|register
name|struct
name|lxdope
modifier|*
name|p
decl_stmt|;
specifier|register
name|struct
name|symtab
modifier|*
name|sp
decl_stmt|;
name|int
name|id
decl_stmt|;
name|char
modifier|*
name|s
decl_stmt|;
specifier|static
name|char
name|sc
index|[
literal|5
index|]
decl_stmt|;
switch|switch
condition|(
operator|(
name|p
operator|=
name|lxcp
index|[
operator|(
name|lxchar
operator|=
name|getchar
argument_list|()
operator|)
operator|+
literal|1
index|]
operator|)
operator|->
name|lxact
condition|)
block|{
name|onechar
label|:
name|ungetc
argument_list|(
name|lxchar
argument_list|,
name|stdin
argument_list|)
expr_stmt|;
case|case
name|A_1C
case|:
comment|/* eat up a single character, and return an opcode */
name|yylval
operator|.
name|intval
operator|=
name|p
operator|->
name|lxval
expr_stmt|;
return|return
operator|(
name|p
operator|->
name|lxtok
operator|)
return|;
case|case
name|A_ERR
case|:
switch|switch
condition|(
name|lxchar
condition|)
block|{
case|case
literal|'\\'
case|:
name|s
operator|=
literal|"\\\\"
expr_stmt|;
break|break;
case|case
literal|'\0'
case|:
name|s
operator|=
literal|"\\0"
expr_stmt|;
break|break;
default|default:
if|if
condition|(
name|isgraph
argument_list|(
name|lxchar
argument_list|)
condition|)
block|{
name|sc
index|[
literal|0
index|]
operator|=
name|lxchar
expr_stmt|;
name|sc
index|[
literal|1
index|]
operator|=
literal|'\0'
expr_stmt|;
block|}
else|else
name|sprintf
argument_list|(
name|sc
argument_list|,
literal|"\\%03.3o"
argument_list|,
operator|(
name|unsigned
name|char
operator|)
name|lxchar
argument_list|)
expr_stmt|;
name|s
operator|=
name|sc
expr_stmt|;
break|break;
block|}
name|uerror
argument_list|(
literal|"illegal character: '%s'"
argument_list|,
name|s
argument_list|)
expr_stmt|;
continue|continue;
comment|/* ignore it and see if we find more */
case|case
name|A_LET
case|:
comment|/* collect an identifier, check for reserved word, and return */
name|lxget
argument_list|(
name|lxchar
argument_list|,
name|LEXLET
operator||
name|LEXDIG
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|lxchar
operator|=
name|lxres
argument_list|()
operator|)
operator|>
literal|0
condition|)
return|return
operator|(
name|lxchar
operator|)
return|;
comment|/* reserved word */
if|if
condition|(
name|lxchar
operator|==
literal|0
condition|)
continue|continue;
ifdef|#
directive|ifdef
name|FLEXNAMES
name|id
operator|=
name|lookup
argument_list|(
argument|hash(yytext)
argument_list|,
else|#
directive|else
argument|id = lookup( yytext,
endif|#
directive|endif
comment|/* tag name for struct/union/enum */
argument|(stwart&TAGNAME)? STAG:
comment|/* member name for struct/union */
argument|(stwart&(INSTRUCT|INUNION|FUNNYNAME))?SMOS:
literal|0
argument|); 			sp =&stab[id]; 			if( sp->sclass == TYPEDEF&& !stwart ){ 				stwart = instruct; 				yylval.nodep = mkty( sp->stype, sp->dimoff, sp->sizoff ); 				return( TYPE ); 				} 			stwart = (stwart&SEENAME) ? instruct :
literal|0
argument|; 			yylval.intval = id; 			return( NAME );  		case A_DIG:
comment|/* collect a digit string, then look at last one... */
argument|lastcon =
literal|0
argument|; 			lxget( lxchar, LEXDIG ); 			switch( lxchar=getchar() ){  			case
literal|'x'
argument|: 			case
literal|'X'
argument|: 				if( yytext[
literal|0
argument|] !=
literal|'0'
argument|&& !yytext[
literal|1
argument|] ) uerror(
literal|"illegal hex constant"
argument|); 				lxmore( lxchar, LEXHEX );
comment|/* convert the value */
argument|{ 					register char *cp; 					for( cp = yytext+
literal|2
argument|; *cp; ++cp ){
comment|/* this code won't work for all wild character sets, 						   but seems ok for ascii and ebcdic */
argument|lastcon<<=
literal|4
argument|; 						if( isdigit( *cp ) ) lastcon += *cp-
literal|'0'
argument|; 						else if( isupper( *cp ) ) lastcon += *cp -
literal|'A'
argument|+
literal|10
argument|; 						else lastcon += *cp -
literal|'a'
argument|+
literal|10
argument|; 						} 					}  			hexlong:
comment|/* criterion for longness for hex and octal constants is that it 				   fit within 0177777 */
argument|if( lastcon& ~
literal|0177777L
argument|) yylval.intval =
literal|1
argument|; 				else yylval.intval =
literal|0
argument|;  				goto islong;  			case
literal|'.'
argument|: 				lxmore( lxchar, LEXDIG );  			getfp: 				if( (lxchar=getchar()) ==
literal|'e'
argument||| lxchar ==
literal|'E'
argument|){
comment|/* exponent */
argument|case
literal|'e'
argument|: 			case
literal|'E'
argument|: 					if( (lxchar=getchar()) ==
literal|'+'
argument||| lxchar ==
literal|'-'
argument|){ 						*lxgcp++ =
literal|'e'
argument|; 						} 					else { 						ungetc(lxchar,stdin); 						lxchar =
literal|'e'
argument|; 						} 					lxmore( lxchar, LEXDIG );
comment|/* now have the whole thing... */
argument|} 				else {
comment|/* no exponent */
argument|ungetc( lxchar ,stdin); 					} 				dcon = atof( yytext ); 				if( (lxchar = getchar()) ==
literal|'F'
argument||| lxchar ==
literal|'f'
argument|){ 					fcon = dcon; 					return( FCON ); 					} 				else ungetc( lxchar ,stdin); 				return( DCON );  			default: 				ungetc( lxchar ,stdin); 				if( yytext[
literal|0
argument|] ==
literal|'0'
argument|){
comment|/* convert in octal */
argument|register char *cp; 					for( cp = yytext+
literal|1
argument|; *cp; ++cp ){ 						lastcon<<=
literal|3
argument|; 						lastcon += *cp -
literal|'0'
argument|; 						} 					goto hexlong; 					} 				else {
comment|/* convert in decimal */
argument|register char *cp; 					for( cp = yytext; *cp; ++cp ){ 						lastcon = lastcon *
literal|10
argument|+ *cp -
literal|'0'
argument|; 						} 					}
comment|/* decide if it is long or not (decimal case) */
comment|/* if it is positive and fits in 15 bits, or negative and 				   and fits in 15 bits plus an extended sign, it is int; otherwise long */
comment|/* if there is an l or L following, all bets are off... */
argument|{	CONSZ v; 					v = lastcon& ~
literal|077777L
argument|; 					if( v ==
literal|0
argument||| v == ~
literal|077777L
argument|) yylval.intval =
literal|0
argument|; 					else yylval.intval =
literal|1
argument|; 					}  			islong:
comment|/* finally, look for trailing L or l */
argument|if( (lxchar = getchar()) ==
literal|'L'
argument||| lxchar ==
literal|'l'
argument|) yylval.intval =
literal|1
argument|; 				else ungetc( lxchar ,stdin); 				return( ICON ); 				}  		case A_DOT:
comment|/* look for a dot: if followed by a digit, floating point */
argument|lxchar = getchar(); 			if( lxmask[lxchar+
literal|1
argument|]& LEXDIG ){ 				ungetc(lxchar,stdin); 				lxget(
literal|'.'
argument|, LEXDIG ); 				goto getfp; 				} 			stwart = FUNNYNAME; 			goto onechar;  		case A_STR:
comment|/* string constant */
argument|lxmatch =
literal|'"'
argument|; 			return( STRING );  		case A_CC:
comment|/* character constant */
argument|lxmatch =
literal|'\''
argument|; 			lastcon =
literal|0
argument|; 			lxstr(
literal|0
argument|); 			yylval.intval =
literal|0
argument|; 			return( ICON );
ifdef|#
directive|ifdef
name|gcos
argument|case A_BCD: 			{ 				register i; 				int j; 				for( i=
literal|0
argument|; i<LXTSZ; ++i ){ 					if( ( j = getchar() ) ==
literal|'`'
argument|) break; 					if( j ==
literal|'\n'
argument|){ 						uerror(
literal|"newline in BCD constant"
argument|); 						break; 						} 					yytext[i] = j; 					} 				yytext[i] =
literal|'\0'
argument|; 				if( i>
literal|6
argument|) uerror(
literal|"BCD constant exceeds 6 characters"
argument|);
ifndef|#
directive|ifndef
name|unix
argument|else strtob( yytext,&lastcon, i ); 				lastcon>>=
literal|6
argument|*(
literal|6
argument|-i);
else|#
directive|else
argument|uerror(
literal|"gcos BCD constant illegal"
argument|);
endif|#
directive|endif
argument|yylval.intval =
literal|0
argument|;
comment|/* not long */
argument|return( ICON ); 				}
endif|#
directive|endif
argument|case A_SL:
comment|/* / */
argument|if( (lxchar=getchar()) !=
literal|'*'
argument|) goto onechar; 			lxcom(); 		case A_WS: 			continue;  		case A_NL: 			++lineno; 			lxtitle(); 			continue;  		case A_NOT:
comment|/* ! */
argument|if( (lxchar=getchar()) !=
literal|'='
argument|) goto onechar; 			yylval.intval = NE; 			return( EQUOP );  		case A_MI:
comment|/* - */
argument|if( (lxchar=getchar()) ==
literal|'-'
argument|){ 				yylval.intval = DECR; 				return( INCOP ); 				} 			if( lxchar !=
literal|'>'
argument|) goto onechar; 			stwart = FUNNYNAME; 			yylval.intval=STREF; 			return( STROP );  		case A_PL:
comment|/* + */
argument|if( (lxchar=getchar()) !=
literal|'+'
argument|) goto onechar; 			yylval.intval = INCR; 			return( INCOP );  		case A_AND:
comment|/*& */
argument|if( (lxchar=getchar()) !=
literal|'&'
argument|) goto onechar; 			return( yylval.intval = ANDAND );  		case A_OR:
comment|/* | */
argument|if( (lxchar=getchar()) !=
literal|'|'
argument|) goto onechar; 			return( yylval.intval = OROR );  		case A_LT:
comment|/*< */
argument|if( (lxchar=getchar()) ==
literal|'<'
argument|){ 				yylval.intval = LS; 				return( SHIFTOP ); 				} 			if( lxchar !=
literal|'='
argument|) goto onechar; 			yylval.intval = LE; 			return( RELOP );  		case A_GT:
comment|/*> */
argument|if( (lxchar=getchar()) ==
literal|'>'
argument|){ 				yylval.intval = RS; 				return(SHIFTOP ); 				} 			if( lxchar !=
literal|'='
argument|) goto onechar; 			yylval.intval = GE; 			return( RELOP );  		case A_EQ:
comment|/* = */
argument|switch( lxchar = getchar() ){  			case
literal|'='
argument|: 				yylval.intval = EQ; 				return( EQUOP );
ifdef|#
directive|ifdef
name|old_assignment_ops
argument|case
literal|'+'
argument|: 				yylval.intval = ASG PLUS; 				break;  			case
literal|'-'
argument|: 				yylval.intval = ASG MINUS;  			warn: 				if( lxmask[ (lxchar=getchar())+
literal|1
argument|]& (LEXLET|LEXDIG|LEXDOT) ){ 					werror(
literal|"ambiguous assignment: assignment op taken"
argument|); 					} 				ungetc( lxchar ,stdin); 				break;  			case
literal|'*'
argument|: 				yylval.intval = ASG MUL; 				goto warn;  			case
literal|'/'
argument|: 				yylval.intval = ASG DIV; 				break;  			case
literal|'%'
argument|: 				yylval.intval = ASG MOD; 				break;  			case
literal|'&'
argument|: 				yylval.intval = ASG AND; 				break;  			case
literal|'|'
argument|: 				yylval.intval = ASG OR; 				break;  			case
literal|'^'
argument|: 				yylval.intval = ASG ER; 				break;  			case
literal|'<'
argument|: 				if( (lxchar=getchar()) !=
literal|'<'
argument|){ 					uerror(
literal|"=<%c illegal"
argument|, lxchar ); 					} 				yylval.intval = ASG LS; 				break;  			case
literal|'>'
argument|: 				if( (lxchar=getchar()) !=
literal|'>'
argument|){ 					uerror(
literal|"=>%c illegal"
argument|, lxchar ); 					} 				yylval.intval = ASG RS; 				break;
endif|#
directive|endif
endif|old_assignment_ops
argument|default: 				goto onechar;  				}
ifdef|#
directive|ifdef
name|old_assignment_ops
comment|/* defeat 'unreachable code' warning */
argument|return( ASOP );
endif|#
directive|endif
endif|old_assignment_ops
argument|default: 			cerror(
literal|"yylex error, character %03o (octal)"
argument|, lxchar );  			}
comment|/* ordinarily, repeat here... */
argument|cerror(
literal|"out of switch in yylex"
argument|);  		}  	}  struct lxrdope {
comment|/* dope for reserved, in alphabetical order */
argument|char *lxrch;
comment|/* name of reserved word */
argument|short lxract;
comment|/* reserved word action */
argument|short lxrval;
comment|/* value to be returned */
argument|} lxrdope[] = {
literal|"asm"
argument_list|,
argument|AR_A
argument_list|,
literal|0
argument_list|,
literal|"auto"
argument_list|,
argument|AR_CL
argument_list|,
argument|AUTO
argument_list|,
literal|"break"
argument_list|,
argument|AR_RW
argument_list|,
argument|BREAK
argument_list|,
literal|"char"
argument_list|,
argument|AR_TY
argument_list|,
argument|CHAR
argument_list|,
literal|"case"
argument_list|,
argument|AR_RW
argument_list|,
argument|CASE
argument_list|,
literal|"continue"
argument_list|,
argument|AR_RW
argument_list|,
argument|CONTINUE
argument_list|,
literal|"double"
argument_list|,
argument|AR_TY
argument_list|,
argument|DOUBLE
argument_list|,
literal|"default"
argument_list|,
argument|AR_RW
argument_list|,
argument|DEFAULT
argument_list|,
literal|"do"
argument_list|,
argument|AR_RW
argument_list|,
argument|DO
argument_list|,
literal|"extern"
argument_list|,
argument|AR_CL
argument_list|,
argument|EXTERN
argument_list|,
literal|"else"
argument_list|,
argument|AR_RW
argument_list|,
argument|ELSE
argument_list|,
literal|"enum"
argument_list|,
argument|AR_E
argument_list|,
argument|ENUM
argument_list|,
literal|"for"
argument_list|,
argument|AR_RW
argument_list|,
argument|FOR
argument_list|,
literal|"float"
argument_list|,
argument|AR_TY
argument_list|,
argument|FLOAT
argument_list|,
literal|"fortran"
argument_list|,
argument|AR_CL
argument_list|,
argument|FORTRAN
argument_list|,
literal|"goto"
argument_list|,
argument|AR_RW
argument_list|,
argument|GOTO
argument_list|,
literal|"if"
argument_list|,
argument|AR_RW
argument_list|,
argument|IF
argument_list|,
literal|"int"
argument_list|,
argument|AR_TY
argument_list|,
argument|INT
argument_list|,
literal|"long"
argument_list|,
argument|AR_TY
argument_list|,
argument|LONG
argument_list|,
literal|"return"
argument_list|,
argument|AR_RW
argument_list|,
argument|RETURN
argument_list|,
literal|"register"
argument_list|,
argument|AR_CL
argument_list|,
argument|REGISTER
argument_list|,
literal|"switch"
argument_list|,
argument|AR_RW
argument_list|,
argument|SWITCH
argument_list|,
literal|"struct"
argument_list|,
argument|AR_S
argument_list|,
literal|0
argument_list|,
literal|"sizeof"
argument_list|,
argument|AR_RW
argument_list|,
argument|SIZEOF
argument_list|,
literal|"short"
argument_list|,
argument|AR_TY
argument_list|,
argument|SHORT
argument_list|,
literal|"static"
argument_list|,
argument|AR_CL
argument_list|,
argument|STATIC
argument_list|,
literal|"typedef"
argument_list|,
argument|AR_CL
argument_list|,
argument|TYPEDEF
argument_list|,
literal|"unsigned"
argument_list|,
argument|AR_TY
argument_list|,
argument|UNSIGNED
argument_list|,
literal|"union"
argument_list|,
argument|AR_U
argument_list|,
literal|0
argument_list|,
literal|"void"
argument_list|,
argument|AR_TY
argument_list|,
argument|UNDEF
argument_list|,
comment|/* tymerge adds FTN */
literal|"while"
argument_list|,
argument|AR_RW
argument_list|,
argument|WHILE
argument_list|,
literal|""
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|,
comment|/* to stop the search */
argument|};  lxres() {
comment|/* check to see of yytext is reserved; if so, 	/* do the appropriate action and return */
comment|/* otherwise, return -1 */
argument|register c
argument_list|,
argument|ch; 	register struct lxrdope *p;  	ch = yytext[
literal|0
argument|];  	if( !islower(ch) ) return( -
literal|1
argument|);  	switch( ch ){  	case
literal|'a'
argument|: 		c=
literal|0
argument|; break; 	case
literal|'b'
argument|: 		c=
literal|2
argument|; break; 	case
literal|'c'
argument|: 		c=
literal|3
argument|; break; 	case
literal|'d'
argument|: 		c=
literal|6
argument|; break; 	case
literal|'e'
argument|: 		c=
literal|9
argument|; break; 	case
literal|'f'
argument|: 		c=
literal|12
argument|; break; 	case
literal|'g'
argument|: 		c=
literal|15
argument|; break; 	case
literal|'i'
argument|: 		c=
literal|16
argument|; break; 	case
literal|'l'
argument|: 		c=
literal|18
argument|; break; 	case
literal|'r'
argument|: 		c=
literal|19
argument|; break; 	case
literal|'s'
argument|: 		c=
literal|21
argument|; break; 	case
literal|'t'
argument|: 		c=
literal|26
argument|; break; 	case
literal|'u'
argument|: 		c=
literal|27
argument|; break; 	case
literal|'v'
argument|: 		c=
literal|29
argument|; break; 	case
literal|'w'
argument|: 		c=
literal|30
argument|; break;  	default: 		return( -
literal|1
argument|); 		}  	for( p= lxrdope+c; p->lxrch[
literal|0
argument|] == ch; ++p ){ 		if( !strcmp( yytext, p->lxrch ) ){
comment|/* match */
argument|switch( p->lxract ){  			case AR_TY:
comment|/* type word */
argument|stwart = instruct; 				yylval.nodep = mkty( (TWORD)p->lxrval,
literal|0
argument|, p->lxrval ); 				return( TYPE );  			case AR_RW:
comment|/* ordinary reserved word */
argument|return( yylval.intval = p->lxrval );  			case AR_CL:
comment|/* class word */
argument|yylval.intval = p->lxrval; 				return( CLASS );  			case AR_S:
comment|/* struct */
argument|stwart = INSTRUCT|SEENAME|TAGNAME; 				yylval.intval = INSTRUCT; 				return( STRUCT );  			case AR_U:
comment|/* union */
argument|stwart = INUNION|SEENAME|TAGNAME; 				yylval.intval = INUNION; 				return( STRUCT );  			case AR_E:
comment|/* enums */
argument|stwart = SEENAME|TAGNAME; 				return( yylval.intval = ENUM );  			case AR_A:
comment|/* asm */
argument|asm_esc =
literal|1
argument|;
comment|/* warn the world! */
argument|lxget(
literal|' '
argument|, LEXWS ); 				if( getchar() !=
literal|'('
argument|) goto badasm; 				lxget(
literal|' '
argument|, LEXWS ); 				if( getchar() !=
literal|'"'
argument|) goto badasm;
ifndef|#
directive|ifndef
name|ONEPASS
ifndef|#
directive|ifndef
name|LINT
argument|putchar(
literal|')'
argument|);
endif|#
directive|endif
endif|#
directive|endif
argument|while( (c=getchar()) !=
literal|'"'
argument|){ 					if( c==
literal|'\n'
argument||| c==EOF ) goto badasm;
ifndef|#
directive|ifndef
name|LINT
argument|putchar(c);
endif|#
directive|endif
argument|} 				lxget(
literal|' '
argument|, LEXWS ); 				if( getchar() !=
literal|')'
argument|) goto badasm;
ifndef|#
directive|ifndef
name|LINT
argument|putchar(
literal|'\n'
argument|);
endif|#
directive|endif
argument|return(
literal|0
argument|);  			badasm: 				uerror(
literal|"bad asm construction"
argument|); 				return(
literal|0
argument|);  			default: 				cerror(
literal|"bad AR_?? action"
argument|); 				} 			} 		} 	return( -
literal|1
argument|); 	}  extern int	labelno;  lxtitle(){
comment|/* called after a newline; set linenumber and file name */
argument|register c
argument_list|,
argument|val; 	register char *cp
argument_list|,
argument|*cq;  	for(;;){
comment|/* might be several such lines in a row */
argument|if( (c=getchar()) !=
literal|'#'
argument|){ 			if( c != EOF ) ungetc(c,stdin);
ifndef|#
directive|ifndef
name|LINT
argument|if ( lastloc != PROG) return; 			cp = ftitle; 			cq = ititle; 			while ( *cp ) if (*cp++ != *cq++) return; 			if ( *cq ) return; 			if( nerrors ==
literal|0
argument|) psline();
endif|#
directive|endif
argument|return; 			}  		lxget(
literal|' '
argument|, LEXWS ); 		c = getchar(); 		if( c ==
literal|'i'
argument|){
comment|/* #ident -- currently a no-op */
argument|lxget( c, LEXLET ); 			if( strcmp( yytext,
literal|"ident"
argument|) ) 				werror(
literal|"%s: undefined control"
argument|, yytext ); 			while( (c = getchar()) !=
literal|'\n'
argument|&& c != EOF ) 				; 			continue; 			} 		if( c ==
literal|'p'
argument|){
comment|/* #pragma -- special instructions */
argument|lxget( c, LEXLET ); 			if( strcmp( yytext,
literal|"pragma"
argument|) ) { 				werror(
literal|"%s: undefined control"
argument|, yytext ); 				while( (c = getchar()) !=
literal|'\n'
argument|&& c != EOF ) 					; 				continue; 				} 			lxget(
literal|' '
argument|, LEXWS ); 			switch( c = getchar() ){
ifdef|#
directive|ifdef
name|LINT
argument|case
literal|'V'
argument|: 				lxget( c, LEXLET|LEXDIG ); 				{ 					extern int vaflag; 					int i; 					i = yytext[
literal|7
argument|]?yytext[
literal|7
argument|]-
literal|'0'
argument|:
literal|0
argument|; 					yytext[
literal|7
argument|] =
literal|'\0'
argument|; 					if( strcmp( yytext,
literal|"VARARGS"
argument|) ) break; 					vaflag = i; 					break; 					} 			case
literal|'L'
argument|: 				lxget( c, LEXLET ); 				if( strcmp( yytext,
literal|"LINTLIBRARY"
argument|) ) break; 				{ 					extern int libflag; 					libflag =
literal|1
argument|; 					} 				break;  			case
literal|'A'
argument|: 				lxget( c, LEXLET ); 				if( strcmp( yytext,
literal|"ARGSUSED"
argument|) ) break; 				{ 					extern int argflag
argument_list|,
argument|vflag; 					argflag =
literal|1
argument|; 					vflag =
literal|0
argument|; 					} 				break;  			case
literal|'N'
argument|: 				lxget( c, LEXLET ); 				if( strcmp( yytext,
literal|"NOTREACHED"
argument|) ) break; 				reached =
literal|0
argument|; 				break;
endif|#
directive|endif
argument|case
literal|'\n'
argument|: 			case EOF: 				continue; 				} 			while( (c = getchar()) !=
literal|'\n'
argument|&& c != EOF ) 				; 			continue; 			} 		if( c ==
literal|'l'
argument|){
comment|/* #line -- just like # */
argument|lxget( c, LEXLET ); 			if( strcmp( yytext,
literal|"line"
argument|) ){ 				werror(
literal|"%s: undefined control"
argument|, yytext ); 				while( (c = getchar()) !=
literal|'\n'
argument|&& c != EOF ) 					; 				continue; 				} 			lxget(
literal|' '
argument|, LEXWS ); 			c = getchar(); 			} 		if( !isdigit(c) ){ 			if( isalpha(c) ){ 				lxget( c, LEXLET ); 				werror(
literal|"%s: undefined control"
argument|, yytext ); 				} 			while( c !=
literal|'\n'
argument|&& c != EOF ) 				c = getchar(); 			continue; 			} 			 		val =
literal|0
argument|; 		do { 			val = val*
literal|10
argument|+ c -
literal|'0'
argument|; 			} 		while( isdigit( c = getchar() ) );  		if( c == EOF ) 			continue; 		ungetc( c, stdin ); 		lineno = val; 		lxget(
literal|' '
argument|, LEXWS ); 		if( (c=getchar()) !=
literal|'\n'
argument|&& c != EOF ){ 			for( cp=ftitle; c!=EOF&& c!=
literal|'\n'
argument|; c=getchar(),++cp ){ 				*cp = c; 				} 			*cp =
literal|'\0'
argument|;
ifndef|#
directive|ifndef
name|LINT
argument|if (ititle[
literal|0
argument|] ==
literal|'\0'
argument|) { 				cp = ftitle; 				cq = ititle; 				while ( *cp )   					*cq++ = *cp++; 				*cq =
literal|'\0'
argument|; 				*--cq =
literal|'\0'
argument|;
ifndef|#
directive|ifndef
name|FLEXNAMES
argument|for ( cp = ititle+
literal|1
argument|; *(cp-
literal|1
argument|); cp +=
literal|8
argument|) { 					pstab(cp, N_SO); 					if (gdebug) printf(
literal|"0,0,LL%d\n"
argument|, labelno); 					}
else|#
directive|else
argument|pstab(ititle+
literal|1
argument|, N_SO); 				if (gdebug) printf(
literal|"0,0,LL%d\n"
argument|, labelno);
endif|#
directive|endif
argument|*cq =
literal|'"'
argument|; 				printf(
literal|"LL%d:\n"
argument|, labelno++); 				}
endif|#
directive|endif
argument|} 		} 	}
ifdef|#
directive|ifdef
name|FLEXNAMES
define|#
directive|define
name|NSAVETAB
value|4096
argument|char	*savetab; unsigned saveleft; char	*malloc(); char	*calloc(); char	*strncpy();  char * savestr(cp) 	register char *cp; { 	register int len;  	len = strlen(cp) +
literal|1
argument|; 	if (len> saveleft) { 		saveleft = NSAVETAB; 		if (len> saveleft) 			saveleft = len; 		savetab = malloc(saveleft); 		if (savetab ==
literal|0
argument|) 			cerror(
literal|"Ran out of memory (savestr)"
argument|); 	} 	(void) strncpy(savetab, cp, len); 	cp = savetab; 	savetab += len; 	saveleft -= len; 	return (cp); }
comment|/*  * The definition for the segmented hash tables.  */
define|#
directive|define
name|MAXHASH
value|20
define|#
directive|define
name|HASHINC
value|1013
argument|struct ht { 	char	**ht_low; 	char	**ht_high; 	int	ht_used; } htab[MAXHASH];  char * hash(s) 	char *s; { 	register char **h; 	register i; 	register char *cp; 	struct ht *htp; 	int sh;
comment|/* 	 * The hash function is a modular hash of 	 * the sum of the characters with the sum 	 * doubled before each successive character 	 * is added. 	 */
argument|cp = s; 	i =
literal|0
argument|; 	while (*cp) 		i = i*
literal|2
argument|+ *cp++; 	sh = (i&
literal|077777
argument|) % HASHINC; 	cp = s;
comment|/* 	 * There are as many as MAXHASH active 	 * hash tables at any given point in time. 	 * The search starts with the first table 	 * and continues through the active tables 	 * as necessary. 	 */
argument|for (htp = htab; htp<&htab[MAXHASH]; htp++) { 		if (htp->ht_low ==
literal|0
argument|) { 			register char **hp = 			    (char **) calloc(sizeof (char **), HASHINC); 			if (hp ==
literal|0
argument|) 				cerror(
literal|"ran out of memory (hash)"
argument|); 			htp->ht_low = hp; 			htp->ht_high = htp->ht_low + HASHINC; 		} 		h = htp->ht_low + sh;
comment|/* 		 * quadratic rehash increment 		 * starts at 1 and incremented 		 * by two each rehash. 		 */
argument|i =
literal|1
argument|; 		do { 			if (*h ==
literal|0
argument|) { 				if (htp->ht_used> (HASHINC *
literal|3
argument|)/
literal|4
argument|) 					break; 				htp->ht_used++; 				*h = savestr(cp); 				return (*h); 			} 			if (**h == *cp&& strcmp(*h, cp) ==
literal|0
argument|) 				return (*h); 			h += i; 			i +=
literal|2
argument|; 			if (h>= htp->ht_high) 				h -= HASHINC; 		} while (i< HASHINC); 	} 	cerror(
literal|"ran out of hash tables"
argument|);
comment|/*NOTREACHED*/
argument|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

