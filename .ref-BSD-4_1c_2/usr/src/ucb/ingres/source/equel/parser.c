begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)parser.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_define
define|#
directive|define
name|MAXDEPTH
value|150
end_define

begin_comment
comment|/* **  PARSER FOR YACC OUTPUT ** **  This is the same as the yacc parser found in the UNIX system **  library "/lib/liby.a".  There have been two kinds of **  modifications. 1) The coding style has been altered to conform **  to the INGRES standard.  2) The changes marked by comments. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yyval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in the table file */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yylval
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in the table file */
end_comment

begin_decl_stmt
specifier|extern
name|int
modifier|*
name|yypv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* defined in the table file */
end_comment

begin_comment
comment|/* -------- the next line is an INGRES customization -------- */
end_comment

begin_expr_stmt
name|int
name|yypflag
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* zero for no actions performed */
end_comment

begin_expr_stmt
name|int
name|yydebug
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* 1 for debugging */
end_comment

begin_decl_stmt
name|int
name|yyv
index|[
name|MAXDEPTH
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where the values are stored */
end_comment

begin_expr_stmt
name|int
name|yystate
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* current parser state */
end_comment

begin_expr_stmt
name|int
name|yychar
operator|-
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* current input token number */
end_comment

begin_expr_stmt
name|int
name|yynerrs
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* number of errors */
end_comment

begin_expr_stmt
name|int
name|yyerrflag
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* error recovery flag */
end_comment

begin_macro
name|yyparse
argument_list|()
end_macro

begin_block
block|{
specifier|extern
name|int
name|yygo
index|[]
decl_stmt|,
name|yypgo
index|[]
decl_stmt|,
name|yyr1
index|[]
decl_stmt|,
name|yyr2
index|[]
decl_stmt|,
name|yyact
index|[]
decl_stmt|,
name|yypact
index|[]
decl_stmt|;
comment|/* INGRES customization to make 'ps', 'p', and 'n' register variables */
name|int
name|s
index|[
name|MAXDEPTH
index|]
decl_stmt|;
specifier|register
name|int
modifier|*
name|ps
decl_stmt|,
modifier|*
name|p
decl_stmt|;
specifier|register
name|int
name|n
decl_stmt|;
name|int
name|ac
decl_stmt|;
name|yystate
operator|=
literal|0
expr_stmt|;
name|yychar
operator|=
operator|-
literal|1
expr_stmt|;
name|yynerrs
operator|=
literal|0
expr_stmt|;
name|yyerrflag
operator|=
literal|0
expr_stmt|;
name|ps
operator|=
operator|&
name|s
index|[
literal|0
index|]
operator|-
literal|1
expr_stmt|;
name|yypv
operator|=
operator|&
name|yyv
index|[
literal|0
index|]
operator|-
literal|1
expr_stmt|;
name|stack
label|:
comment|/* put a state and value onto the stack */
if|if
condition|(
name|yydebug
condition|)
name|printf
argument_list|(
literal|"state %d value %d char %d\n"
argument_list|,
name|yystate
argument_list|,
name|yyval
argument_list|,
name|yychar
argument_list|)
expr_stmt|;
operator|*
operator|++
name|ps
operator|=
name|yystate
expr_stmt|;
operator|*
operator|++
name|yypv
operator|=
name|yyval
expr_stmt|;
name|newstate
label|:
comment|/* set ap to point to the parsing actions for the new state */
name|p
operator|=
operator|&
name|yyact
index|[
name|yypact
index|[
name|yystate
operator|+
literal|1
index|]
index|]
expr_stmt|;
name|actn
label|:
comment|/* get the next action, and perform it */
name|n
operator|=
operator|(
name|ac
operator|=
operator|*
name|p
operator|++
operator|)
operator|&
literal|07777
expr_stmt|;
comment|/* n is the "address" of the action */
switch|switch
condition|(
name|ac
operator|>>
literal|12
condition|)
comment|/* switch on operation */
block|{
case|case
literal|1
case|:
comment|/* skip on test */
if|if
condition|(
name|yychar
operator|<
literal|0
condition|)
block|{
name|yychar
operator|=
name|yylex
argument_list|()
expr_stmt|;
if|if
condition|(
name|yydebug
condition|)
name|printf
argument_list|(
literal|"character %d read\n"
argument_list|,
name|yychar
argument_list|)
expr_stmt|;
block|}
comment|/* ---------- the next two lines are an INGRES customization ---------- */
if|if
condition|(
name|yychar
operator|<
literal|0
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|n
operator|!=
name|yychar
condition|)
name|p
operator|++
expr_stmt|;
goto|goto
name|actn
goto|;
comment|/* get next action */
case|case
literal|2
case|:
comment|/* shift */
name|yystate
operator|=
name|n
expr_stmt|;
name|yyval
operator|=
name|yylval
expr_stmt|;
name|yychar
operator|=
operator|-
literal|1
expr_stmt|;
if|if
condition|(
name|yyerrflag
condition|)
name|yyerrflag
operator|--
expr_stmt|;
goto|goto
name|stack
goto|;
comment|/* stack new state */
case|case
literal|3
case|:
comment|/* reduce */
if|if
condition|(
name|yydebug
condition|)
name|printf
argument_list|(
literal|"reduce %d\n"
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|ps
operator|=
operator|-
name|yyr2
index|[
name|n
index|]
expr_stmt|;
name|yypv
operator|=
operator|-
name|yyr2
index|[
name|n
index|]
expr_stmt|;
name|yyval
operator|=
name|yypv
index|[
literal|1
index|]
expr_stmt|;
comment|/* --------  the next 2 lines are an INGRES customization -------- */
if|if
condition|(
name|yypflag
operator|&&
name|yyactr
argument_list|(
name|n
argument_list|)
condition|)
goto|goto
name|abort
goto|;
comment|/* consult goto table to find next state */
for|for
control|(
name|p
operator|=
operator|&
name|yygo
index|[
name|yypgo
index|[
name|yyr1
index|[
name|n
index|]
index|]
index|]
init|;
operator|*
name|p
operator|!=
operator|*
name|ps
operator|&&
operator|*
name|p
operator|>=
literal|0
condition|;
name|p
operator|=
operator|+
literal|2
control|)
empty_stmt|;
name|yystate
operator|=
name|p
index|[
literal|1
index|]
expr_stmt|;
goto|goto
name|stack
goto|;
comment|/* stack new state and value */
case|case
literal|4
case|:
comment|/* accept */
return|return
operator|(
literal|0
operator|)
return|;
case|case
literal|0
case|:
comment|/* error ... attempt to resume parsing */
switch|switch
condition|(
name|yyerrflag
condition|)
block|{
case|case
literal|0
case|:
comment|/* brand new error */
comment|/* ----------the next 2 lines are an INGRES customization ---------- */
comment|/* syntax error */
name|yyerror
argument_list|(
literal|"syntax error"
argument_list|)
expr_stmt|;
name|yynerrs
operator|++
expr_stmt|;
case|case
literal|1
case|:
case|case
literal|2
case|:
comment|/* incompletely recovered error ... try again */
name|yyerrflag
operator|=
literal|3
expr_stmt|;
comment|/* find a state where "error" is a legal shift action */
while|while
condition|(
name|ps
operator|>=
name|s
condition|)
block|{
comment|/* search ps actions */
for|for
control|(
name|p
operator|=
operator|&
name|yyact
index|[
name|yypact
index|[
operator|*
name|ps
operator|+
literal|1
index|]
index|]
init|;
operator|(
operator|*
name|p
operator|>>
literal|12
operator|)
operator|==
literal|1
condition|;
name|p
operator|=
operator|+
literal|2
control|)
if|if
condition|(
operator|*
name|p
operator|==
literal|4352
condition|)
goto|goto
name|found
goto|;
comment|/* the current ps has no shift onn "error", pop stack */
if|if
condition|(
name|yydebug
condition|)
name|printf
argument_list|(
literal|"err recov pops state %d, uncovers %d\n"
argument_list|,
name|ps
index|[
literal|0
index|]
argument_list|,
name|ps
index|[
operator|-
literal|1
index|]
argument_list|)
expr_stmt|;
name|ps
operator|--
expr_stmt|;
name|yypv
operator|--
expr_stmt|;
block|}
comment|/* there is no state on the stack with an error shift ... abort */
name|abort
label|:
return|return
operator|(
literal|1
operator|)
return|;
name|found
label|:
comment|/* we have a state with a shift on "error", resume parsing */
name|yystate
operator|=
name|p
index|[
literal|1
index|]
operator|&
literal|07777
expr_stmt|;
goto|goto
name|stack
goto|;
case|case
literal|3
case|:
comment|/* no shift yet; clobber input char */
if|if
condition|(
name|yydebug
condition|)
name|printf
argument_list|(
literal|"err recov discards char %d\n"
argument_list|,
name|yychar
argument_list|)
expr_stmt|;
comment|/* don't discard EOF; quit */
if|if
condition|(
name|yychar
operator|==
literal|0
condition|)
goto|goto
name|abort
goto|;
name|yychar
operator|=
operator|-
literal|1
expr_stmt|;
goto|goto
name|newstate
goto|;
comment|/* try again in the same state */
block|}
block|}
block|}
end_block

end_unit

