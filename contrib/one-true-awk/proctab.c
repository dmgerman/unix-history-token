begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"awk.h"
end_include

begin_include
include|#
directive|include
file|"ytab.h"
end_include

begin_decl_stmt
specifier|static
name|char
modifier|*
name|printname
index|[
literal|92
index|]
init|=
block|{
operator|(
name|char
operator|*
operator|)
literal|"FIRSTTOKEN"
block|,
comment|/* 57346 */
operator|(
name|char
operator|*
operator|)
literal|"PROGRAM"
block|,
comment|/* 57347 */
operator|(
name|char
operator|*
operator|)
literal|"PASTAT"
block|,
comment|/* 57348 */
operator|(
name|char
operator|*
operator|)
literal|"PASTAT2"
block|,
comment|/* 57349 */
operator|(
name|char
operator|*
operator|)
literal|"XBEGIN"
block|,
comment|/* 57350 */
operator|(
name|char
operator|*
operator|)
literal|"XEND"
block|,
comment|/* 57351 */
operator|(
name|char
operator|*
operator|)
literal|"NL"
block|,
comment|/* 57352 */
operator|(
name|char
operator|*
operator|)
literal|"ARRAY"
block|,
comment|/* 57353 */
operator|(
name|char
operator|*
operator|)
literal|"MATCH"
block|,
comment|/* 57354 */
operator|(
name|char
operator|*
operator|)
literal|"NOTMATCH"
block|,
comment|/* 57355 */
operator|(
name|char
operator|*
operator|)
literal|"MATCHOP"
block|,
comment|/* 57356 */
operator|(
name|char
operator|*
operator|)
literal|"FINAL"
block|,
comment|/* 57357 */
operator|(
name|char
operator|*
operator|)
literal|"DOT"
block|,
comment|/* 57358 */
operator|(
name|char
operator|*
operator|)
literal|"ALL"
block|,
comment|/* 57359 */
operator|(
name|char
operator|*
operator|)
literal|"CCL"
block|,
comment|/* 57360 */
operator|(
name|char
operator|*
operator|)
literal|"NCCL"
block|,
comment|/* 57361 */
operator|(
name|char
operator|*
operator|)
literal|"CHAR"
block|,
comment|/* 57362 */
operator|(
name|char
operator|*
operator|)
literal|"OR"
block|,
comment|/* 57363 */
operator|(
name|char
operator|*
operator|)
literal|"STAR"
block|,
comment|/* 57364 */
operator|(
name|char
operator|*
operator|)
literal|"QUEST"
block|,
comment|/* 57365 */
operator|(
name|char
operator|*
operator|)
literal|"PLUS"
block|,
comment|/* 57366 */
operator|(
name|char
operator|*
operator|)
literal|"AND"
block|,
comment|/* 57367 */
operator|(
name|char
operator|*
operator|)
literal|"BOR"
block|,
comment|/* 57368 */
operator|(
name|char
operator|*
operator|)
literal|"APPEND"
block|,
comment|/* 57369 */
operator|(
name|char
operator|*
operator|)
literal|"EQ"
block|,
comment|/* 57370 */
operator|(
name|char
operator|*
operator|)
literal|"GE"
block|,
comment|/* 57371 */
operator|(
name|char
operator|*
operator|)
literal|"GT"
block|,
comment|/* 57372 */
operator|(
name|char
operator|*
operator|)
literal|"LE"
block|,
comment|/* 57373 */
operator|(
name|char
operator|*
operator|)
literal|"LT"
block|,
comment|/* 57374 */
operator|(
name|char
operator|*
operator|)
literal|"NE"
block|,
comment|/* 57375 */
operator|(
name|char
operator|*
operator|)
literal|"IN"
block|,
comment|/* 57376 */
operator|(
name|char
operator|*
operator|)
literal|"ARG"
block|,
comment|/* 57377 */
operator|(
name|char
operator|*
operator|)
literal|"BLTIN"
block|,
comment|/* 57378 */
operator|(
name|char
operator|*
operator|)
literal|"BREAK"
block|,
comment|/* 57379 */
operator|(
name|char
operator|*
operator|)
literal|"CLOSE"
block|,
comment|/* 57380 */
operator|(
name|char
operator|*
operator|)
literal|"CONTINUE"
block|,
comment|/* 57381 */
operator|(
name|char
operator|*
operator|)
literal|"DELETE"
block|,
comment|/* 57382 */
operator|(
name|char
operator|*
operator|)
literal|"DO"
block|,
comment|/* 57383 */
operator|(
name|char
operator|*
operator|)
literal|"EXIT"
block|,
comment|/* 57384 */
operator|(
name|char
operator|*
operator|)
literal|"FOR"
block|,
comment|/* 57385 */
operator|(
name|char
operator|*
operator|)
literal|"FUNC"
block|,
comment|/* 57386 */
operator|(
name|char
operator|*
operator|)
literal|"SUB"
block|,
comment|/* 57387 */
operator|(
name|char
operator|*
operator|)
literal|"GSUB"
block|,
comment|/* 57388 */
operator|(
name|char
operator|*
operator|)
literal|"IF"
block|,
comment|/* 57389 */
operator|(
name|char
operator|*
operator|)
literal|"INDEX"
block|,
comment|/* 57390 */
operator|(
name|char
operator|*
operator|)
literal|"LSUBSTR"
block|,
comment|/* 57391 */
operator|(
name|char
operator|*
operator|)
literal|"MATCHFCN"
block|,
comment|/* 57392 */
operator|(
name|char
operator|*
operator|)
literal|"NEXT"
block|,
comment|/* 57393 */
operator|(
name|char
operator|*
operator|)
literal|"NEXTFILE"
block|,
comment|/* 57394 */
operator|(
name|char
operator|*
operator|)
literal|"ADD"
block|,
comment|/* 57395 */
operator|(
name|char
operator|*
operator|)
literal|"MINUS"
block|,
comment|/* 57396 */
operator|(
name|char
operator|*
operator|)
literal|"MULT"
block|,
comment|/* 57397 */
operator|(
name|char
operator|*
operator|)
literal|"DIVIDE"
block|,
comment|/* 57398 */
operator|(
name|char
operator|*
operator|)
literal|"MOD"
block|,
comment|/* 57399 */
operator|(
name|char
operator|*
operator|)
literal|"ASSIGN"
block|,
comment|/* 57400 */
operator|(
name|char
operator|*
operator|)
literal|"ASGNOP"
block|,
comment|/* 57401 */
operator|(
name|char
operator|*
operator|)
literal|"ADDEQ"
block|,
comment|/* 57402 */
operator|(
name|char
operator|*
operator|)
literal|"SUBEQ"
block|,
comment|/* 57403 */
operator|(
name|char
operator|*
operator|)
literal|"MULTEQ"
block|,
comment|/* 57404 */
operator|(
name|char
operator|*
operator|)
literal|"DIVEQ"
block|,
comment|/* 57405 */
operator|(
name|char
operator|*
operator|)
literal|"MODEQ"
block|,
comment|/* 57406 */
operator|(
name|char
operator|*
operator|)
literal|"POWEQ"
block|,
comment|/* 57407 */
operator|(
name|char
operator|*
operator|)
literal|"PRINT"
block|,
comment|/* 57408 */
operator|(
name|char
operator|*
operator|)
literal|"PRINTF"
block|,
comment|/* 57409 */
operator|(
name|char
operator|*
operator|)
literal|"SPRINTF"
block|,
comment|/* 57410 */
operator|(
name|char
operator|*
operator|)
literal|"ELSE"
block|,
comment|/* 57411 */
operator|(
name|char
operator|*
operator|)
literal|"INTEST"
block|,
comment|/* 57412 */
operator|(
name|char
operator|*
operator|)
literal|"CONDEXPR"
block|,
comment|/* 57413 */
operator|(
name|char
operator|*
operator|)
literal|"POSTINCR"
block|,
comment|/* 57414 */
operator|(
name|char
operator|*
operator|)
literal|"PREINCR"
block|,
comment|/* 57415 */
operator|(
name|char
operator|*
operator|)
literal|"POSTDECR"
block|,
comment|/* 57416 */
operator|(
name|char
operator|*
operator|)
literal|"PREDECR"
block|,
comment|/* 57417 */
operator|(
name|char
operator|*
operator|)
literal|"VAR"
block|,
comment|/* 57418 */
operator|(
name|char
operator|*
operator|)
literal|"IVAR"
block|,
comment|/* 57419 */
operator|(
name|char
operator|*
operator|)
literal|"VARNF"
block|,
comment|/* 57420 */
operator|(
name|char
operator|*
operator|)
literal|"CALL"
block|,
comment|/* 57421 */
operator|(
name|char
operator|*
operator|)
literal|"NUMBER"
block|,
comment|/* 57422 */
operator|(
name|char
operator|*
operator|)
literal|"STRING"
block|,
comment|/* 57423 */
operator|(
name|char
operator|*
operator|)
literal|"REGEXPR"
block|,
comment|/* 57424 */
operator|(
name|char
operator|*
operator|)
literal|"GETLINE"
block|,
comment|/* 57425 */
operator|(
name|char
operator|*
operator|)
literal|"RETURN"
block|,
comment|/* 57426 */
operator|(
name|char
operator|*
operator|)
literal|"SPLIT"
block|,
comment|/* 57427 */
operator|(
name|char
operator|*
operator|)
literal|"SUBSTR"
block|,
comment|/* 57428 */
operator|(
name|char
operator|*
operator|)
literal|"WHILE"
block|,
comment|/* 57429 */
operator|(
name|char
operator|*
operator|)
literal|"CAT"
block|,
comment|/* 57430 */
operator|(
name|char
operator|*
operator|)
literal|"NOT"
block|,
comment|/* 57431 */
operator|(
name|char
operator|*
operator|)
literal|"UMINUS"
block|,
comment|/* 57432 */
operator|(
name|char
operator|*
operator|)
literal|"POWER"
block|,
comment|/* 57433 */
operator|(
name|char
operator|*
operator|)
literal|"DECR"
block|,
comment|/* 57434 */
operator|(
name|char
operator|*
operator|)
literal|"INCR"
block|,
comment|/* 57435 */
operator|(
name|char
operator|*
operator|)
literal|"INDIRECT"
block|,
comment|/* 57436 */
operator|(
name|char
operator|*
operator|)
literal|"LASTTOKEN"
block|,
comment|/* 57437 */
block|}
decl_stmt|;
end_decl_stmt

begin_function_decl
name|Cell
modifier|*
function_decl|(
modifier|*
name|proctab
index|[
literal|92
index|]
function_decl|)
parameter_list|(
name|Node
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
init|=
block|{
name|nullproc
operator|,
comment|/* FIRSTTOKEN */
function_decl|program
operator|,
comment|/* PROGRAM */
function_decl|pastat
operator|,
comment|/* PASTAT */
function_decl|dopa2
operator|,
comment|/* PASTAT2 */
function_decl|nullproc
operator|,
comment|/* XBEGIN */
function_decl|nullproc
operator|,
comment|/* XEND */
function_decl|nullproc
operator|,
comment|/* NL */
function_decl|array
operator|,
comment|/* ARRAY */
function_decl|matchop
operator|,
comment|/* MATCH */
function_decl|matchop
operator|,
comment|/* NOTMATCH */
function_decl|nullproc
operator|,
comment|/* MATCHOP */
function_decl|nullproc
operator|,
comment|/* FINAL */
function_decl|nullproc
operator|,
comment|/* DOT */
function_decl|nullproc
operator|,
comment|/* ALL */
function_decl|nullproc
operator|,
comment|/* CCL */
function_decl|nullproc
operator|,
comment|/* NCCL */
function_decl|nullproc
operator|,
comment|/* CHAR */
function_decl|nullproc
operator|,
comment|/* OR */
function_decl|nullproc
operator|,
comment|/* STAR */
function_decl|nullproc
operator|,
comment|/* QUEST */
function_decl|nullproc
operator|,
comment|/* PLUS */
function_decl|boolop
operator|,
comment|/* AND */
function_decl|boolop
operator|,
comment|/* BOR */
function_decl|nullproc
operator|,
comment|/* APPEND */
function_decl|relop
operator|,
comment|/* EQ */
function_decl|relop
operator|,
comment|/* GE */
function_decl|relop
operator|,
comment|/* GT */
function_decl|relop
operator|,
comment|/* LE */
function_decl|relop
operator|,
comment|/* LT */
function_decl|relop
operator|,
comment|/* NE */
function_decl|instat
operator|,
comment|/* IN */
function_decl|arg
operator|,
comment|/* ARG */
function_decl|bltin
operator|,
comment|/* BLTIN */
function_decl|jump
operator|,
comment|/* BREAK */
function_decl|closefile
operator|,
comment|/* CLOSE */
function_decl|jump
operator|,
comment|/* CONTINUE */
function_decl|awkdelete
operator|,
comment|/* DELETE */
function_decl|dostat
operator|,
comment|/* DO */
function_decl|jump
operator|,
comment|/* EXIT */
function_decl|forstat
operator|,
comment|/* FOR */
function_decl|nullproc
operator|,
comment|/* FUNC */
function_decl|sub
operator|,
comment|/* SUB */
function_decl|gsub
operator|,
comment|/* GSUB */
function_decl|ifstat
operator|,
comment|/* IF */
function_decl|sindex
operator|,
comment|/* INDEX */
function_decl|nullproc
operator|,
comment|/* LSUBSTR */
function_decl|matchop
operator|,
comment|/* MATCHFCN */
function_decl|jump
operator|,
comment|/* NEXT */
function_decl|jump
operator|,
comment|/* NEXTFILE */
function_decl|arith
operator|,
comment|/* ADD */
function_decl|arith
operator|,
comment|/* MINUS */
function_decl|arith
operator|,
comment|/* MULT */
function_decl|arith
operator|,
comment|/* DIVIDE */
function_decl|arith
operator|,
comment|/* MOD */
function_decl|assign
operator|,
comment|/* ASSIGN */
function_decl|nullproc
operator|,
comment|/* ASGNOP */
function_decl|assign
operator|,
comment|/* ADDEQ */
function_decl|assign
operator|,
comment|/* SUBEQ */
function_decl|assign
operator|,
comment|/* MULTEQ */
function_decl|assign
operator|,
comment|/* DIVEQ */
function_decl|assign
operator|,
comment|/* MODEQ */
function_decl|assign
operator|,
comment|/* POWEQ */
function_decl|printstat
operator|,
comment|/* PRINT */
function_decl|awkprintf
operator|,
comment|/* PRINTF */
function_decl|awksprintf
operator|,
comment|/* SPRINTF */
function_decl|nullproc
operator|,
comment|/* ELSE */
function_decl|intest
operator|,
comment|/* INTEST */
function_decl|condexpr
operator|,
comment|/* CONDEXPR */
function_decl|incrdecr
operator|,
comment|/* POSTINCR */
function_decl|incrdecr
operator|,
comment|/* PREINCR */
function_decl|incrdecr
operator|,
comment|/* POSTDECR */
function_decl|incrdecr
operator|,
comment|/* PREDECR */
function_decl|nullproc
operator|,
comment|/* VAR */
function_decl|nullproc
operator|,
comment|/* IVAR */
function_decl|getnf
operator|,
comment|/* VARNF */
function_decl|call
operator|,
comment|/* CALL */
function_decl|nullproc
operator|,
comment|/* NUMBER */
function_decl|nullproc
operator|,
comment|/* STRING */
function_decl|nullproc
operator|,
comment|/* REGEXPR */
function_decl|getline
operator|,
comment|/* GETLINE */
function_decl|jump
operator|,
comment|/* RETURN */
function_decl|split
operator|,
comment|/* SPLIT */
function_decl|substr
operator|,
comment|/* SUBSTR */
function_decl|whilestat
operator|,
comment|/* WHILE */
function_decl|cat
operator|,
comment|/* CAT */
function_decl|boolop
operator|,
comment|/* NOT */
function_decl|arith
operator|,
comment|/* UMINUS */
function_decl|arith
operator|,
comment|/* POWER */
function_decl|nullproc
operator|,
comment|/* DECR */
function_decl|nullproc
operator|,
comment|/* INCR */
function_decl|indirect
operator|,
comment|/* INDIRECT */
function_decl|nullproc
operator|,
end_function_decl

begin_comment
comment|/* LASTTOKEN */
end_comment

begin_function
unit|};
name|char
modifier|*
name|tokname
parameter_list|(
name|int
name|n
parameter_list|)
block|{
specifier|static
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
if|if
condition|(
name|n
operator|<
name|FIRSTTOKEN
operator|||
name|n
operator|>
name|LASTTOKEN
condition|)
block|{
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"token %d"
argument_list|,
name|n
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
return|return
name|printname
index|[
name|n
operator|-
name|FIRSTTOKEN
index|]
return|;
block|}
end_function

end_unit

