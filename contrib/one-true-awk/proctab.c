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
literal|93
index|]
init|=
block|{
operator|(
name|char
operator|*
operator|)
literal|"FIRSTTOKEN"
block|,
comment|/* 258 */
operator|(
name|char
operator|*
operator|)
literal|"PROGRAM"
block|,
comment|/* 259 */
operator|(
name|char
operator|*
operator|)
literal|"PASTAT"
block|,
comment|/* 260 */
operator|(
name|char
operator|*
operator|)
literal|"PASTAT2"
block|,
comment|/* 261 */
operator|(
name|char
operator|*
operator|)
literal|"XBEGIN"
block|,
comment|/* 262 */
operator|(
name|char
operator|*
operator|)
literal|"XEND"
block|,
comment|/* 263 */
operator|(
name|char
operator|*
operator|)
literal|"NL"
block|,
comment|/* 264 */
operator|(
name|char
operator|*
operator|)
literal|"ARRAY"
block|,
comment|/* 265 */
operator|(
name|char
operator|*
operator|)
literal|"MATCH"
block|,
comment|/* 266 */
operator|(
name|char
operator|*
operator|)
literal|"NOTMATCH"
block|,
comment|/* 267 */
operator|(
name|char
operator|*
operator|)
literal|"MATCHOP"
block|,
comment|/* 268 */
operator|(
name|char
operator|*
operator|)
literal|"FINAL"
block|,
comment|/* 269 */
operator|(
name|char
operator|*
operator|)
literal|"DOT"
block|,
comment|/* 270 */
operator|(
name|char
operator|*
operator|)
literal|"ALL"
block|,
comment|/* 271 */
operator|(
name|char
operator|*
operator|)
literal|"CCL"
block|,
comment|/* 272 */
operator|(
name|char
operator|*
operator|)
literal|"NCCL"
block|,
comment|/* 273 */
operator|(
name|char
operator|*
operator|)
literal|"CHAR"
block|,
comment|/* 274 */
operator|(
name|char
operator|*
operator|)
literal|"OR"
block|,
comment|/* 275 */
operator|(
name|char
operator|*
operator|)
literal|"STAR"
block|,
comment|/* 276 */
operator|(
name|char
operator|*
operator|)
literal|"QUEST"
block|,
comment|/* 277 */
operator|(
name|char
operator|*
operator|)
literal|"PLUS"
block|,
comment|/* 278 */
operator|(
name|char
operator|*
operator|)
literal|"EMPTYRE"
block|,
comment|/* 279 */
operator|(
name|char
operator|*
operator|)
literal|"AND"
block|,
comment|/* 280 */
operator|(
name|char
operator|*
operator|)
literal|"BOR"
block|,
comment|/* 281 */
operator|(
name|char
operator|*
operator|)
literal|"APPEND"
block|,
comment|/* 282 */
operator|(
name|char
operator|*
operator|)
literal|"EQ"
block|,
comment|/* 283 */
operator|(
name|char
operator|*
operator|)
literal|"GE"
block|,
comment|/* 284 */
operator|(
name|char
operator|*
operator|)
literal|"GT"
block|,
comment|/* 285 */
operator|(
name|char
operator|*
operator|)
literal|"LE"
block|,
comment|/* 286 */
operator|(
name|char
operator|*
operator|)
literal|"LT"
block|,
comment|/* 287 */
operator|(
name|char
operator|*
operator|)
literal|"NE"
block|,
comment|/* 288 */
operator|(
name|char
operator|*
operator|)
literal|"IN"
block|,
comment|/* 289 */
operator|(
name|char
operator|*
operator|)
literal|"ARG"
block|,
comment|/* 290 */
operator|(
name|char
operator|*
operator|)
literal|"BLTIN"
block|,
comment|/* 291 */
operator|(
name|char
operator|*
operator|)
literal|"BREAK"
block|,
comment|/* 292 */
operator|(
name|char
operator|*
operator|)
literal|"CLOSE"
block|,
comment|/* 293 */
operator|(
name|char
operator|*
operator|)
literal|"CONTINUE"
block|,
comment|/* 294 */
operator|(
name|char
operator|*
operator|)
literal|"DELETE"
block|,
comment|/* 295 */
operator|(
name|char
operator|*
operator|)
literal|"DO"
block|,
comment|/* 296 */
operator|(
name|char
operator|*
operator|)
literal|"EXIT"
block|,
comment|/* 297 */
operator|(
name|char
operator|*
operator|)
literal|"FOR"
block|,
comment|/* 298 */
operator|(
name|char
operator|*
operator|)
literal|"FUNC"
block|,
comment|/* 299 */
operator|(
name|char
operator|*
operator|)
literal|"SUB"
block|,
comment|/* 300 */
operator|(
name|char
operator|*
operator|)
literal|"GSUB"
block|,
comment|/* 301 */
operator|(
name|char
operator|*
operator|)
literal|"IF"
block|,
comment|/* 302 */
operator|(
name|char
operator|*
operator|)
literal|"INDEX"
block|,
comment|/* 303 */
operator|(
name|char
operator|*
operator|)
literal|"LSUBSTR"
block|,
comment|/* 304 */
operator|(
name|char
operator|*
operator|)
literal|"MATCHFCN"
block|,
comment|/* 305 */
operator|(
name|char
operator|*
operator|)
literal|"NEXT"
block|,
comment|/* 306 */
operator|(
name|char
operator|*
operator|)
literal|"NEXTFILE"
block|,
comment|/* 307 */
operator|(
name|char
operator|*
operator|)
literal|"ADD"
block|,
comment|/* 308 */
operator|(
name|char
operator|*
operator|)
literal|"MINUS"
block|,
comment|/* 309 */
operator|(
name|char
operator|*
operator|)
literal|"MULT"
block|,
comment|/* 310 */
operator|(
name|char
operator|*
operator|)
literal|"DIVIDE"
block|,
comment|/* 311 */
operator|(
name|char
operator|*
operator|)
literal|"MOD"
block|,
comment|/* 312 */
operator|(
name|char
operator|*
operator|)
literal|"ASSIGN"
block|,
comment|/* 313 */
operator|(
name|char
operator|*
operator|)
literal|"ASGNOP"
block|,
comment|/* 314 */
operator|(
name|char
operator|*
operator|)
literal|"ADDEQ"
block|,
comment|/* 315 */
operator|(
name|char
operator|*
operator|)
literal|"SUBEQ"
block|,
comment|/* 316 */
operator|(
name|char
operator|*
operator|)
literal|"MULTEQ"
block|,
comment|/* 317 */
operator|(
name|char
operator|*
operator|)
literal|"DIVEQ"
block|,
comment|/* 318 */
operator|(
name|char
operator|*
operator|)
literal|"MODEQ"
block|,
comment|/* 319 */
operator|(
name|char
operator|*
operator|)
literal|"POWEQ"
block|,
comment|/* 320 */
operator|(
name|char
operator|*
operator|)
literal|"PRINT"
block|,
comment|/* 321 */
operator|(
name|char
operator|*
operator|)
literal|"PRINTF"
block|,
comment|/* 322 */
operator|(
name|char
operator|*
operator|)
literal|"SPRINTF"
block|,
comment|/* 323 */
operator|(
name|char
operator|*
operator|)
literal|"ELSE"
block|,
comment|/* 324 */
operator|(
name|char
operator|*
operator|)
literal|"INTEST"
block|,
comment|/* 325 */
operator|(
name|char
operator|*
operator|)
literal|"CONDEXPR"
block|,
comment|/* 326 */
operator|(
name|char
operator|*
operator|)
literal|"POSTINCR"
block|,
comment|/* 327 */
operator|(
name|char
operator|*
operator|)
literal|"PREINCR"
block|,
comment|/* 328 */
operator|(
name|char
operator|*
operator|)
literal|"POSTDECR"
block|,
comment|/* 329 */
operator|(
name|char
operator|*
operator|)
literal|"PREDECR"
block|,
comment|/* 330 */
operator|(
name|char
operator|*
operator|)
literal|"VAR"
block|,
comment|/* 331 */
operator|(
name|char
operator|*
operator|)
literal|"IVAR"
block|,
comment|/* 332 */
operator|(
name|char
operator|*
operator|)
literal|"VARNF"
block|,
comment|/* 333 */
operator|(
name|char
operator|*
operator|)
literal|"CALL"
block|,
comment|/* 334 */
operator|(
name|char
operator|*
operator|)
literal|"NUMBER"
block|,
comment|/* 335 */
operator|(
name|char
operator|*
operator|)
literal|"STRING"
block|,
comment|/* 336 */
operator|(
name|char
operator|*
operator|)
literal|"REGEXPR"
block|,
comment|/* 337 */
operator|(
name|char
operator|*
operator|)
literal|"GETLINE"
block|,
comment|/* 338 */
operator|(
name|char
operator|*
operator|)
literal|"SUBSTR"
block|,
comment|/* 339 */
operator|(
name|char
operator|*
operator|)
literal|"SPLIT"
block|,
comment|/* 340 */
operator|(
name|char
operator|*
operator|)
literal|"RETURN"
block|,
comment|/* 341 */
operator|(
name|char
operator|*
operator|)
literal|"WHILE"
block|,
comment|/* 342 */
operator|(
name|char
operator|*
operator|)
literal|"CAT"
block|,
comment|/* 343 */
operator|(
name|char
operator|*
operator|)
literal|"UMINUS"
block|,
comment|/* 344 */
operator|(
name|char
operator|*
operator|)
literal|"NOT"
block|,
comment|/* 345 */
operator|(
name|char
operator|*
operator|)
literal|"POWER"
block|,
comment|/* 346 */
operator|(
name|char
operator|*
operator|)
literal|"INCR"
block|,
comment|/* 347 */
operator|(
name|char
operator|*
operator|)
literal|"DECR"
block|,
comment|/* 348 */
operator|(
name|char
operator|*
operator|)
literal|"INDIRECT"
block|,
comment|/* 349 */
operator|(
name|char
operator|*
operator|)
literal|"LASTTOKEN"
block|,
comment|/* 350 */
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
literal|93
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
function_decl|nullproc
operator|,
comment|/* EMPTYRE */
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
function_decl|awkgetline
operator|,
comment|/* GETLINE */
function_decl|substr
operator|,
comment|/* SUBSTR */
function_decl|split
operator|,
comment|/* SPLIT */
function_decl|jump
operator|,
comment|/* RETURN */
function_decl|whilestat
operator|,
comment|/* WHILE */
function_decl|cat
operator|,
comment|/* CAT */
function_decl|arith
operator|,
comment|/* UMINUS */
function_decl|boolop
operator|,
comment|/* NOT */
function_decl|arith
operator|,
comment|/* POWER */
function_decl|nullproc
operator|,
comment|/* INCR */
function_decl|nullproc
operator|,
comment|/* DECR */
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

