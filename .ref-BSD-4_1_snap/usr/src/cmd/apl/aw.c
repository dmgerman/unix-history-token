begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"apl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|FULLD
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|opname
index|[]
block|{
literal|"eol"
operator|,
comment|/* 0 */
literal|"add"
operator|,
comment|/* 1 */
literal|"plus"
operator|,
comment|/* 2 */
literal|"sub"
operator|,
comment|/* 3 */
literal|"minus"
operator|,
comment|/* 4 */
literal|"mul"
operator|,
comment|/* 5 */
literal|"sgn"
operator|,
comment|/* 6 */
literal|"div"
operator|,
comment|/* 7 */
literal|"recip"
operator|,
comment|/* 8 */
literal|"mod"
operator|,
comment|/* 9 */
literal|"abs"
operator|,
comment|/* 10 */
literal|"min"
operator|,
comment|/* 11 */
literal|"floor"
operator|,
comment|/* 12 */
literal|"max"
operator|,
comment|/* 13 */
literal|"ceil"
operator|,
comment|/* 14 */
literal|"pwr"
operator|,
comment|/* 15 */
literal|"exp"
operator|,
comment|/* 16 */
literal|"log"
operator|,
comment|/* 17 */
literal|"loge"
operator|,
comment|/* 18 */
literal|"cir"
operator|,
comment|/* 19 */
literal|"pi"
operator|,
comment|/* 20 */
literal|"comb"
operator|,
comment|/* 21 */
literal|"fac"
operator|,
comment|/* 22 */
literal|"deal"
operator|,
comment|/* 23 */
literal|"rand"
operator|,
comment|/* 24 */
literal|"drho"
operator|,
comment|/* 25 */
literal|"mrho"
operator|,
comment|/* 26 */
literal|"diot"
operator|,
comment|/* 27 */
literal|"miot"
operator|,
comment|/* 28 */
literal|"rot0"
operator|,
comment|/* 29 */
literal|"rev0"
operator|,
comment|/* 30 */
literal|"dtrn"
operator|,
comment|/* 31 */
literal|"mtrn"
operator|,
comment|/* 32 */
literal|"dibm"
operator|,
comment|/* 33 */
literal|"mibm"
operator|,
comment|/* 34 */
literal|"gdu"
operator|,
comment|/* 35 */
literal|"gduk"
operator|,
comment|/* 36 */
literal|"gdd"
operator|,
comment|/* 37 */
literal|"gddk"
operator|,
comment|/* 38 */
literal|"exd"
operator|,
comment|/* 39 */
literal|"scan"
operator|,
comment|/* 40 */
literal|"exdk"
operator|,
comment|/* 41 */
literal|"scank"
operator|,
comment|/* 42 */
literal|"iprod"
operator|,
comment|/* 43 */
literal|"oprod"
operator|,
comment|/* 44 */
literal|"quad"
operator|,
comment|/* 45 */
literal|"qquad"
operator|,
comment|/* 46 */
literal|"br0"
operator|,
comment|/* 47 */
literal|"br"
operator|,
comment|/* 48 */
literal|"ddom"
operator|,
comment|/* 49 */
literal|"mdom"
operator|,
comment|/* 50 */
literal|"com"
operator|,
comment|/* 51 */
literal|"red"
operator|,
comment|/* 52 */
literal|"comk"
operator|,
comment|/* 53 */
literal|"redk"
operator|,
comment|/* 54 */
literal|"rot"
operator|,
comment|/* 55 */
literal|"rev"
operator|,
comment|/* 56 */
literal|"rotk"
operator|,
comment|/* 57 */
literal|"revk"
operator|,
comment|/* 58 */
literal|"cat"
operator|,
comment|/* 59 */
literal|"rav"
operator|,
comment|/* 60 */
literal|"catk"
operator|,
comment|/* 61 */
literal|"ravk"
operator|,
comment|/* 62 */
literal|"print"
operator|,
comment|/* 63 */
literal|"quot"
operator|,
comment|/* 64 */
literal|"elid"
operator|,
comment|/* 65 */
literal|"cquad"
operator|,
comment|/* 66 */
literal|"comnt"
operator|,
comment|/* 67 */
literal|"index"
operator|,
comment|/* 68 */
literal|"hprint"
operator|,
comment|/* 69 */
literal|0
operator|,
comment|/* 70 */
literal|"lt"
operator|,
comment|/* 71 */
literal|"le"
operator|,
comment|/* 72 */
literal|"gt"
operator|,
comment|/* 73 */
literal|"ge"
operator|,
comment|/* 74 */
literal|"eq"
operator|,
comment|/* 75 */
literal|"ne"
operator|,
comment|/* 76 */
literal|"and"
operator|,
comment|/* 77 */
literal|"or"
operator|,
comment|/* 78 */
literal|"nand"
operator|,
comment|/* 79 */
literal|"nor"
operator|,
comment|/* 80 */
literal|"not"
operator|,
comment|/* 81 */
literal|"eps"
operator|,
comment|/* 82 */
literal|"meps"
operator|,
comment|/* 83 */
literal|"rep"
operator|,
comment|/* 84 */
literal|"take"
operator|,
comment|/* 85 */
literal|"drop"
operator|,
comment|/* 86 */
literal|"exd0"
operator|,
comment|/* 87 */
literal|"asgn"
operator|,
comment|/* 88 */
literal|"immed"
operator|,
comment|/* 89 */
literal|"name"
operator|,
comment|/* 90 */
literal|"const"
operator|,
comment|/* 91 */
literal|"fun"
operator|,
comment|/* 92 */
literal|"arg1"
operator|,
comment|/* 93 */
literal|"arg2"
operator|,
comment|/* 94 */
literal|"auto"
operator|,
comment|/* 95 */
literal|"rest"
operator|,
comment|/* 96 */
literal|"com0"
operator|,
comment|/* 97 */
literal|"red0"
operator|,
comment|/* 98 */
literal|"exd0"
operator|,
comment|/* 99 */
literal|"scan0"
operator|,
comment|/*100 */
literal|"base"
operator|,
comment|/*101 */
literal|"menc"
operator|,
comment|/*102 */
comment|/*      monadic encode  */
literal|"label"
operator|,
comment|/*103 */
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|SOMED
end_ifdef

begin_macro
name|dump
argument_list|(
argument|cp
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|cp
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|t
decl_stmt|;
specifier|register
name|i
expr_stmt|;
name|s
operator|=
name|cp
expr_stmt|;
name|loop
label|:
name|putchar
argument_list|(
literal|' '
argument_list|)
expr_stmt|;
if|if
condition|(
name|column
operator|>
literal|50
condition|)
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
name|i
operator|=
operator|*
name|s
operator|++
expr_stmt|;
ifdef|#
directive|ifdef
name|FULLD
if|if
condition|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<=
literal|103
operator|&&
name|opname
index|[
name|i
index|]
condition|)
block|{
name|t
operator|=
name|opname
index|[
name|i
index|]
expr_stmt|;
while|while
condition|(
operator|*
name|t
condition|)
name|putchar
argument_list|(
operator|*
name|t
operator|++
argument_list|)
expr_stmt|;
block|}
else|else
endif|#
directive|endif
name|printf
argument_list|(
literal|"%d"
argument_list|,
name|i
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|i
condition|)
block|{
case|case
name|EOL
case|:
if|if
condition|(
operator|*
name|s
operator|!=
name|EOL
condition|)
break|break;
case|case
name|EOF
case|:
name|putchar
argument_list|(
literal|'\n'
argument_list|)
expr_stmt|;
return|return;
case|case
name|QUOT
case|:
name|i
operator|=
operator|*
name|s
operator|++
expr_stmt|;
name|s
operator|=
operator|+
name|i
expr_stmt|;
break|break;
case|case
name|CONST
case|:
name|i
operator|=
operator|*
name|s
operator|++
expr_stmt|;
name|s
operator|=
operator|+
name|i
operator|*
name|SDAT
expr_stmt|;
break|break;
case|case
name|NAME
case|:
case|case
name|FUN
case|:
case|case
name|ARG1
case|:
case|case
name|ARG2
case|:
case|case
name|AUTO
case|:
case|case
name|REST
case|:
name|s
operator|=
operator|+
name|copy
argument_list|(
name|IN
argument_list|,
name|s
argument_list|,
operator|&
name|cp
argument_list|,
literal|1
argument_list|)
expr_stmt|;
name|putchar
argument_list|(
literal|'-'
argument_list|)
expr_stmt|;
name|t
operator|=
name|cp
operator|->
name|namep
expr_stmt|;
while|while
condition|(
operator|*
name|t
condition|)
name|putchar
argument_list|(
operator|*
name|t
operator|++
argument_list|)
expr_stmt|;
break|break;
case|case
name|INDEX
case|:
case|case
name|IMMED
case|:
name|s
operator|++
expr_stmt|;
break|break;
block|}
goto|goto
name|loop
goto|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

