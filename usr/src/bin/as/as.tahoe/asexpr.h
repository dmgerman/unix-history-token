begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	Copyright (c) 1982 Regents of the University of California  *	@(#)asexpr.h 4.4 6/9/83  */
end_comment

begin_comment
comment|/*  *	Definitions to parse tokens  */
end_comment

begin_define
define|#
directive|define
name|ERROR
parameter_list|(
name|string
parameter_list|)
value|yyerror(string); goto errorfix
end_define

begin_define
define|#
directive|define
name|peekahead
value|(*tokptr)
end_define

begin_define
define|#
directive|define
name|shift
value|val = yylex()
end_define

begin_define
define|#
directive|define
name|advance
value|shift
end_define

begin_define
define|#
directive|define
name|shiftover
parameter_list|(
name|token
parameter_list|)
value|if (val != token) { \ 					shiftoerror(token); \ 					goto errorfix; \ 				} \ 				shift
end_define

begin_define
define|#
directive|define
name|advanceover
value|shiftover
end_define

begin_comment
comment|/*  *	To speed up the expression processing, we class the input tokens  *	into various sets.  *  *	We don't call the recursive descent expression analyzer if we can  *	determine by looking at the next token after the first token in  *	an expression that the expression is simple (name, integer or floating  *	point value).  Expressions with operators are parsed using the recursive  *	descent method.  */
end_comment

begin_comment
comment|/*  *	Functional forwards for expression utility routines  */
end_comment

begin_function_decl
name|struct
name|exp
modifier|*
name|combine
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|exp
modifier|*
name|boolterm
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|exp
modifier|*
name|term
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|exp
modifier|*
name|factor
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|exp
modifier|*
name|yukkyexpr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  *	The set definitions  */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|tokensets
index|[
operator|(
name|LASTTOKEN
operator|)
operator|-
operator|(
name|FIRSTTOKEN
operator|)
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|LINSTBEGIN
value|01
end_define

begin_comment
comment|/*SEMI, NL, NAME*/
end_comment

begin_define
define|#
directive|define
name|EBEGOPS
value|02
end_define

begin_comment
comment|/*LP, MINUS, TILDE*/
end_comment

begin_define
define|#
directive|define
name|YUKKYEXPRBEG
value|04
end_define

begin_comment
comment|/*NAME, INSTn, INST0, REG, BFINT*/
end_comment

begin_define
define|#
directive|define
name|SAFEEXPRBEG
value|010
end_define

begin_comment
comment|/*INT, FLTNUM*/
end_comment

begin_define
define|#
directive|define
name|ADDOPS
value|020
end_define

begin_comment
comment|/*PLUS, MINUS*/
end_comment

begin_define
define|#
directive|define
name|BOOLOPS
value|040
end_define

begin_comment
comment|/*IOR, XOR, AND*/
end_comment

begin_define
define|#
directive|define
name|MULOPS
value|0100
end_define

begin_comment
comment|/*LSH, RSH, MUL, DIV, TILDE*/
end_comment

begin_define
define|#
directive|define
name|INTOKSET
parameter_list|(
name|val
parameter_list|,
name|set
parameter_list|)
value|(tokensets[(val)]& (set) )
end_define

begin_function_decl
name|inttoktype
name|exprparse
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|inttoktype
name|funnyreg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|inttoktype
name|yylex
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|expr
parameter_list|(
name|xp
parameter_list|,
name|val
parameter_list|)
value|{ \ 	if ( (!INTOKSET(val, EBEGOPS))&& (!INTOKSET(peekahead, ADDOPS+BOOLOPS+MULOPS))) { \ 		if (INTOKSET(val, YUKKYEXPRBEG)) xp = yukkyexpr(val, yylval); \ 		else xp = (struct exp *) yylval; \ 		shift; \ 	} else { \ 		val = exprparse(val, ptrloc1xp); \ 		xp = loc1xp; \ 	} \     }
end_define

begin_comment
comment|/*  *	Registers can be either of the form r0...pc, or  *	of the form %<expression>  *	NOTE:	Reizers documentation on the assembler says that it  *	can be of the form r0 +<expression>.. That's not true.  *  *	NOTE:	Reizer's yacc grammar would seem to allow an expression  *	to be: (This is undocumented)  *		a)	a register  *		b)	an Instruction (INSTn or INST0)  */
end_comment

begin_define
define|#
directive|define
name|findreg
parameter_list|(
name|regno
parameter_list|)
define|\
value|if (val == REG) { \ 		regno = yylval; \ 		shift; \ 	} else \ 	if (val == REGOP) { \ 		shift;
comment|/*over the REGOP*/
value|\ 		val = funnyreg(val, ptrregno); \ 	} \ 	else { ERROR ("register expected"); }
end_define

end_unit

