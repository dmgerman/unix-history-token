begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"aw.c @(#)aw.c	1.1	10/1/82 Berkeley "
decl_stmt|;
end_decl_stmt

begin_include
include|#
directive|include
file|"apl.h"
end_include

begin_decl_stmt
name|char
modifier|*
name|opname
index|[]
init|=
block|{
literal|"eol"
block|,
comment|/* 0 */
literal|"add"
block|,
comment|/* 1 */
literal|"plus"
block|,
comment|/* 2 */
literal|"sub"
block|,
comment|/* 3 */
literal|"minus"
block|,
comment|/* 4 */
literal|"mul"
block|,
comment|/* 5 */
literal|"sgn"
block|,
comment|/* 6 */
literal|"div"
block|,
comment|/* 7 */
literal|"recip"
block|,
comment|/* 8 */
literal|"mod"
block|,
comment|/* 9 */
literal|"abs"
block|,
comment|/* 10 */
literal|"min"
block|,
comment|/* 11 */
literal|"floor"
block|,
comment|/* 12 */
literal|"max"
block|,
comment|/* 13 */
literal|"ceil"
block|,
comment|/* 14 */
literal|"pwr"
block|,
comment|/* 15 */
literal|"exp"
block|,
comment|/* 16 */
literal|"log"
block|,
comment|/* 17 */
literal|"loge"
block|,
comment|/* 18 */
literal|"cir"
block|,
comment|/* 19 */
literal|"pi"
block|,
comment|/* 20 */
literal|"comb"
block|,
comment|/* 21 */
literal|"fac"
block|,
comment|/* 22 */
literal|"deal"
block|,
comment|/* 23 */
literal|"rand"
block|,
comment|/* 24 */
literal|"drho"
block|,
comment|/* 25 */
literal|"mrho"
block|,
comment|/* 26 */
literal|"diot"
block|,
comment|/* 27 */
literal|"miot"
block|,
comment|/* 28 */
literal|"rot0"
block|,
comment|/* 29 */
literal|"rev0"
block|,
comment|/* 30 */
literal|"dtrn"
block|,
comment|/* 31 */
literal|"mtrn"
block|,
comment|/* 32 */
literal|"dibm"
block|,
comment|/* 33 */
literal|"mibm"
block|,
comment|/* 34 */
literal|"gdu"
block|,
comment|/* 35 */
literal|"gduk"
block|,
comment|/* 36 */
literal|"gdd"
block|,
comment|/* 37 */
literal|"gddk"
block|,
comment|/* 38 */
literal|"exd"
block|,
comment|/* 39 */
literal|"scan"
block|,
comment|/* 40 */
literal|"exdk"
block|,
comment|/* 41 */
literal|"scank"
block|,
comment|/* 42 */
literal|"iprod"
block|,
comment|/* 43 */
literal|"oprod"
block|,
comment|/* 44 */
literal|"quad"
block|,
comment|/* 45 */
literal|"qquad"
block|,
comment|/* 46 */
literal|"br0"
block|,
comment|/* 47 */
literal|"br"
block|,
comment|/* 48 */
literal|"ddom"
block|,
comment|/* 49 */
literal|"mdom"
block|,
comment|/* 50 */
literal|"com"
block|,
comment|/* 51 */
literal|"red"
block|,
comment|/* 52 */
literal|"comk"
block|,
comment|/* 53 */
literal|"redk"
block|,
comment|/* 54 */
literal|"rot"
block|,
comment|/* 55 */
literal|"rev"
block|,
comment|/* 56 */
literal|"rotk"
block|,
comment|/* 57 */
literal|"revk"
block|,
comment|/* 58 */
literal|"cat"
block|,
comment|/* 59 */
literal|"rav"
block|,
comment|/* 60 */
literal|"catk"
block|,
comment|/* 61 */
literal|"ravk"
block|,
comment|/* 62 */
literal|"print"
block|,
comment|/* 63 */
literal|"quot"
block|,
comment|/* 64 */
literal|"elid"
block|,
comment|/* 65 */
literal|"cquad"
block|,
comment|/* 66 */
literal|"comnt"
block|,
comment|/* 67 */
literal|"index"
block|,
comment|/* 68 */
literal|"hprint"
block|,
comment|/* 69 */
literal|0
block|,
comment|/* 70 */
literal|"lt"
block|,
comment|/* 71 */
literal|"le"
block|,
comment|/* 72 */
literal|"gt"
block|,
comment|/* 73 */
literal|"ge"
block|,
comment|/* 74 */
literal|"eq"
block|,
comment|/* 75 */
literal|"ne"
block|,
comment|/* 76 */
literal|"and"
block|,
comment|/* 77 */
literal|"or"
block|,
comment|/* 78 */
literal|"nand"
block|,
comment|/* 79 */
literal|"nor"
block|,
comment|/* 80 */
literal|"not"
block|,
comment|/* 81 */
literal|"eps"
block|,
comment|/* 82 */
literal|"meps"
block|,
comment|/* 83 */
literal|"rep"
block|,
comment|/* 84 */
literal|"take"
block|,
comment|/* 85 */
literal|"drop"
block|,
comment|/* 86 */
literal|"exd0"
block|,
comment|/* 87 */
literal|"asgn"
block|,
comment|/* 88 */
literal|"immed"
block|,
comment|/* 89 */
literal|"name"
block|,
comment|/* 90 */
literal|"const"
block|,
comment|/* 91 */
literal|"fun"
block|,
comment|/* 92 */
literal|"arg1"
block|,
comment|/* 93 */
literal|"arg2"
block|,
comment|/* 94 */
literal|"auto"
block|,
comment|/* 95 */
literal|"rest"
block|,
comment|/* 96 */
literal|"com0"
block|,
comment|/* 97 */
literal|"red0"
block|,
comment|/* 98 */
literal|"exd0"
block|,
comment|/* 99 */
literal|"scan0"
block|,
comment|/*100 */
literal|"base"
block|,
comment|/*101 */
literal|"format"
block|,
comment|/*102 */
comment|/*	format		*/
literal|"label"
block|,
comment|/*103 */
literal|"psi"
block|,
comment|/*104 */
literal|"psi1"
block|,
comment|/*105 */
literal|"psi2"
block|,
comment|/*106 */
literal|"isp"
block|,
comment|/*107 */
literal|"isp1"
block|,
comment|/*108 */
literal|"isp2"
block|,
comment|/*109 */
literal|"Lwidth"
block|,
comment|/*110 */
literal|"Lfuzz"
block|,
comment|/*111 */
literal|"Lrun"
block|,
comment|/*112 */
literal|"Lfork"
block|,
comment|/*113 */
literal|"Lwait"
block|,
comment|/*114 */
literal|"Lexec"
block|,
comment|/*115 */
literal|"Lfx"
block|,
comment|/*116 */
literal|"Lexit"
block|,
comment|/*117 */
literal|"Lpipe"
block|,
comment|/*118 */
literal|"Lchdir"
block|,
comment|/*119 */
literal|"Lopen"
block|,
comment|/*120 */
literal|"Lclose"
block|,
comment|/*121 */
literal|"Lread"
block|,
comment|/*122 */
literal|"Lwrite"
block|,
comment|/*123 */
literal|"Lcreat"
block|,
comment|/*124 */
literal|"Lseek"
block|,
comment|/*125 */
literal|"Lrm"
block|,
comment|/*126 */
literal|"Lrd"
block|,
comment|/*127 */
literal|"Ldup"
block|,
comment|/*128 */
literal|"Lap"
block|,
comment|/*129 */
literal|"Lkill"
block|,
comment|/*130 */
literal|"Lcr"
block|,
comment|/*131 */
literal|"dfmt"
block|,
comment|/*132 */
literal|"mfmt"
block|,
comment|/*133 */
literal|"Lnc"
block|,
comment|/*134 */
literal|"nilret"
block|,
comment|/*135 */
literal|"Llx"
block|,
comment|/*136 */
literal|"ibr"
block|,
comment|/*137 */
literal|"ibr0"
block|,
comment|/*138 */
literal|"rval"
block|,
comment|/*139 */
literal|"Lsig"
block|,
comment|/*140 */
literal|"Lfloat"
block|,
comment|/*141 */
literal|"Lnl"
block|,
comment|/*142 */
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|dump
argument_list|(
argument|cp
argument_list|,
argument|flag
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
if|if
condition|(
name|flag
condition|)
name|printf
argument_list|(
literal|"[ "
argument_list|)
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
if|if
condition|(
name|flag
condition|)
name|printf
argument_list|(
literal|" ]\n[ "
argument_list|)
expr_stmt|;
else|else
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
if|if
condition|(
name|i
operator|!=
name|EOF
condition|)
name|i
operator|&=
literal|0377
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
operator|&&
name|i
operator|<=
literal|140
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
elseif|else
if|if
condition|(
name|i
operator|!=
name|EOF
condition|)
name|printf
argument_list|(
literal|"%d "
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
name|printf
argument_list|(
literal|"."
argument_list|)
expr_stmt|;
if|if
condition|(
name|flag
condition|)
name|printf
argument_list|(
literal|" ]."
argument_list|)
expr_stmt|;
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
operator|+=
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
operator|+=
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
case|case
name|RVAL
case|:
name|s
operator|+=
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
operator|(
operator|(
expr|struct
name|nlist
operator|*
operator|)
name|cp
operator|)
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

end_unit

