begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/*  The definition of yysccsid in the banner should be replaced with	*/
end_comment

begin_comment
comment|/*  a #pragma ident directive if the target C compiler supports		*/
end_comment

begin_comment
comment|/*  #pragma ident directives.						*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*  If the skeleton is changed, the banner should be changed so that	*/
end_comment

begin_comment
comment|/*  the altered version can be easily distinguished from the original.	*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*  The #defines included with the banner are there because they are	*/
end_comment

begin_comment
comment|/*  useful in subsequent code.  The macros #defined in the header or	*/
end_comment

begin_comment
comment|/*  the body either are not useful outside of semantic actions or	*/
end_comment

begin_comment
comment|/*  are conditional.							*/
end_comment

begin_decl_stmt
name|char
modifier|*
name|banner
index|[]
init|=
block|{
literal|"#ifndef lint"
block|,
literal|"static char yysccsid[] = \"@(#)yaccpar	1.9 (Berkeley) 02/21/93\";"
block|,
literal|"#endif"
block|,
literal|"#define YYBYACC 1"
block|,
literal|"#define YYMAJOR 1"
block|,
literal|"#define YYMINOR 9"
block|,
literal|"#define yyclearin (yychar=(-1))"
block|,
literal|"#define yyerrok (yyerrflag=0)"
block|,
literal|"#define YYRECOVERING (yyerrflag!=0)"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|tables
index|[]
init|=
block|{
literal|"extern short yylhs[];"
block|,
literal|"extern short yylen[];"
block|,
literal|"extern short yydefred[];"
block|,
literal|"extern short yydgoto[];"
block|,
literal|"extern short yysindex[];"
block|,
literal|"extern short yyrindex[];"
block|,
literal|"extern short yygindex[];"
block|,
literal|"extern short yytable[];"
block|,
literal|"extern short yycheck[];"
block|,
literal|"#if YYDEBUG"
block|,
literal|"extern char *yyname[];"
block|,
literal|"extern char *yyrule[];"
block|,
literal|"#endif"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|header
index|[]
init|=
block|{
literal|"#ifdef YYSTACKSIZE"
block|,
literal|"#undef YYMAXDEPTH"
block|,
literal|"#define YYMAXDEPTH YYSTACKSIZE"
block|,
literal|"#else"
block|,
literal|"#ifdef YYMAXDEPTH"
block|,
literal|"#define YYSTACKSIZE YYMAXDEPTH"
block|,
literal|"#else"
block|,
literal|"#define YYSTACKSIZE 500"
block|,
literal|"#define YYMAXDEPTH 500"
block|,
literal|"#endif"
block|,
literal|"#endif"
block|,
literal|"int yydebug;"
block|,
literal|"int yynerrs;"
block|,
literal|"int yyerrflag;"
block|,
literal|"int yychar;"
block|,
literal|"short *yyssp;"
block|,
literal|"YYSTYPE *yyvsp;"
block|,
literal|"YYSTYPE yyval;"
block|,
literal|"YYSTYPE yylval;"
block|,
literal|"short yyss[YYSTACKSIZE];"
block|,
literal|"YYSTYPE yyvs[YYSTACKSIZE];"
block|,
literal|"#define yystacksize YYSTACKSIZE"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|body
index|[]
init|=
block|{
literal|"#define YYABORT goto yyabort"
block|,
literal|"#define YYREJECT goto yyabort"
block|,
literal|"#define YYACCEPT goto yyaccept"
block|,
literal|"#define YYERROR goto yyerrlab"
block|,
literal|"int"
block|,
literal|"yyparse()"
block|,
literal|"{"
block|,
literal|"    register int yym, yyn, yystate;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"    register char *yys;"
block|,
literal|"    extern char *getenv();"
block|,
literal|""
block|,
literal|"    if (yys = getenv(\"YYDEBUG\"))"
block|,
literal|"    {"
block|,
literal|"        yyn = *yys;"
block|,
literal|"        if (yyn>= '0'&& yyn<= '9')"
block|,
literal|"            yydebug = yyn - '0';"
block|,
literal|"    }"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"    yynerrs = 0;"
block|,
literal|"    yyerrflag = 0;"
block|,
literal|"    yychar = (-1);"
block|,
literal|""
block|,
literal|"    yyssp = yyss;"
block|,
literal|"    yyvsp = yyvs;"
block|,
literal|"    *yyssp = yystate = 0;"
block|,
literal|""
block|,
literal|"yyloop:"
block|,
literal|"    if (yyn = yydefred[yystate]) goto yyreduce;"
block|,
literal|"    if (yychar< 0)"
block|,
literal|"    {"
block|,
literal|"        if ((yychar = yylex())< 0) yychar = 0;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"        if (yydebug)"
block|,
literal|"        {"
block|,
literal|"            yys = 0;"
block|,
literal|"            if (yychar<= YYMAXTOKEN) yys = yyname[yychar];"
block|,
literal|"            if (!yys) yys = \"illegal-symbol\";"
block|,
literal|"            printf(\"%sdebug: state %d, reading %d (%s)\\n\","
block|,
literal|"                    YYPREFIX, yystate, yychar, yys);"
block|,
literal|"        }"
block|,
literal|"#endif"
block|,
literal|"    }"
block|,
literal|"    if ((yyn = yysindex[yystate])&& (yyn += yychar)>= 0&&"
block|,
literal|"            yyn<= YYTABLESIZE&& yycheck[yyn] == yychar)"
block|,
literal|"    {"
block|,
literal|"#if YYDEBUG"
block|,
literal|"        if (yydebug)"
block|,
literal|"            printf(\"%sdebug: state %d, shifting to state %d\\n\","
block|,
literal|"                    YYPREFIX, yystate, yytable[yyn]);"
block|,
literal|"#endif"
block|,
literal|"        if (yyssp>= yyss + yystacksize - 1)"
block|,
literal|"        {"
block|,
literal|"            goto yyoverflow;"
block|,
literal|"        }"
block|,
literal|"        *++yyssp = yystate = yytable[yyn];"
block|,
literal|"        *++yyvsp = yylval;"
block|,
literal|"        yychar = (-1);"
block|,
literal|"        if (yyerrflag> 0)  --yyerrflag;"
block|,
literal|"        goto yyloop;"
block|,
literal|"    }"
block|,
literal|"    if ((yyn = yyrindex[yystate])&& (yyn += yychar)>= 0&&"
block|,
literal|"            yyn<= YYTABLESIZE&& yycheck[yyn] == yychar)"
block|,
literal|"    {"
block|,
literal|"        yyn = yytable[yyn];"
block|,
literal|"        goto yyreduce;"
block|,
literal|"    }"
block|,
literal|"    if (yyerrflag) goto yyinrecovery;"
block|,
literal|"#ifdef lint"
block|,
literal|"    goto yynewerror;"
block|,
literal|"#endif"
block|,
literal|"yynewerror:"
block|,
literal|"    yyerror(\"syntax error\");"
block|,
literal|"#ifdef lint"
block|,
literal|"    goto yyerrlab;"
block|,
literal|"#endif"
block|,
literal|"yyerrlab:"
block|,
literal|"    ++yynerrs;"
block|,
literal|"yyinrecovery:"
block|,
literal|"    if (yyerrflag< 3)"
block|,
literal|"    {"
block|,
literal|"        yyerrflag = 3;"
block|,
literal|"        for (;;)"
block|,
literal|"        {"
block|,
literal|"            if ((yyn = yysindex[*yyssp])&& (yyn += YYERRCODE)>= 0&&"
block|,
literal|"                    yyn<= YYTABLESIZE&& yycheck[yyn] == YYERRCODE)"
block|,
literal|"            {"
block|,
literal|"#if YYDEBUG"
block|,
literal|"                if (yydebug)"
block|,
literal|"                    printf(\"%sdebug: state %d, error recovery shifting\\"
block|,
literal|" to state %d\\n\", YYPREFIX, *yyssp, yytable[yyn]);"
block|,
literal|"#endif"
block|,
literal|"                if (yyssp>= yyss + yystacksize - 1)"
block|,
literal|"                {"
block|,
literal|"                    goto yyoverflow;"
block|,
literal|"                }"
block|,
literal|"                *++yyssp = yystate = yytable[yyn];"
block|,
literal|"                *++yyvsp = yylval;"
block|,
literal|"                goto yyloop;"
block|,
literal|"            }"
block|,
literal|"            else"
block|,
literal|"            {"
block|,
literal|"#if YYDEBUG"
block|,
literal|"                if (yydebug)"
block|,
literal|"                    printf(\"%sdebug: error recovery discarding state %d\ \\n\","
block|,
literal|"                            YYPREFIX, *yyssp);"
block|,
literal|"#endif"
block|,
literal|"                if (yyssp<= yyss) goto yyabort;"
block|,
literal|"                --yyssp;"
block|,
literal|"                --yyvsp;"
block|,
literal|"            }"
block|,
literal|"        }"
block|,
literal|"    }"
block|,
literal|"    else"
block|,
literal|"    {"
block|,
literal|"        if (yychar == 0) goto yyabort;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"        if (yydebug)"
block|,
literal|"        {"
block|,
literal|"            yys = 0;"
block|,
literal|"            if (yychar<= YYMAXTOKEN) yys = yyname[yychar];"
block|,
literal|"            if (!yys) yys = \"illegal-symbol\";"
block|,
literal|"            printf(\"%sdebug: state %d, error recovery discards token %d\  (%s)\\n\","
block|,
literal|"                    YYPREFIX, yystate, yychar, yys);"
block|,
literal|"        }"
block|,
literal|"#endif"
block|,
literal|"        yychar = (-1);"
block|,
literal|"        goto yyloop;"
block|,
literal|"    }"
block|,
literal|"yyreduce:"
block|,
literal|"#if YYDEBUG"
block|,
literal|"    if (yydebug)"
block|,
literal|"        printf(\"%sdebug: state %d, reducing by rule %d (%s)\\n\","
block|,
literal|"                YYPREFIX, yystate, yyn, yyrule[yyn]);"
block|,
literal|"#endif"
block|,
literal|"    yym = yylen[yyn];"
block|,
literal|"    yyval = yyvsp[1-yym];"
block|,
literal|"    switch (yyn)"
block|,
literal|"    {"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|trailer
index|[]
init|=
block|{
literal|"    }"
block|,
literal|"    yyssp -= yym;"
block|,
literal|"    yystate = *yyssp;"
block|,
literal|"    yyvsp -= yym;"
block|,
literal|"    yym = yylhs[yyn];"
block|,
literal|"    if (yystate == 0&& yym == 0)"
block|,
literal|"    {"
block|,
literal|"#if YYDEBUG"
block|,
literal|"        if (yydebug)"
block|,
literal|"            printf(\"%sdebug: after reduction, shifting from state 0 to\\"
block|,
literal|" state %d\\n\", YYPREFIX, YYFINAL);"
block|,
literal|"#endif"
block|,
literal|"        yystate = YYFINAL;"
block|,
literal|"        *++yyssp = YYFINAL;"
block|,
literal|"        *++yyvsp = yyval;"
block|,
literal|"        if (yychar< 0)"
block|,
literal|"        {"
block|,
literal|"            if ((yychar = yylex())< 0) yychar = 0;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"            if (yydebug)"
block|,
literal|"            {"
block|,
literal|"                yys = 0;"
block|,
literal|"                if (yychar<= YYMAXTOKEN) yys = yyname[yychar];"
block|,
literal|"                if (!yys) yys = \"illegal-symbol\";"
block|,
literal|"                printf(\"%sdebug: state %d, reading %d (%s)\\n\","
block|,
literal|"                        YYPREFIX, YYFINAL, yychar, yys);"
block|,
literal|"            }"
block|,
literal|"#endif"
block|,
literal|"        }"
block|,
literal|"        if (yychar == 0) goto yyaccept;"
block|,
literal|"        goto yyloop;"
block|,
literal|"    }"
block|,
literal|"    if ((yyn = yygindex[yym])&& (yyn += yystate)>= 0&&"
block|,
literal|"            yyn<= YYTABLESIZE&& yycheck[yyn] == yystate)"
block|,
literal|"        yystate = yytable[yyn];"
block|,
literal|"    else"
block|,
literal|"        yystate = yydgoto[yym];"
block|,
literal|"#if YYDEBUG"
block|,
literal|"    if (yydebug)"
block|,
literal|"        printf(\"%sdebug: after reduction, shifting from state %d \\"
block|,
literal|"to state %d\\n\", YYPREFIX, *yyssp, yystate);"
block|,
literal|"#endif"
block|,
literal|"    if (yyssp>= yyss + yystacksize - 1)"
block|,
literal|"    {"
block|,
literal|"        goto yyoverflow;"
block|,
literal|"    }"
block|,
literal|"    *++yyssp = yystate;"
block|,
literal|"    *++yyvsp = yyval;"
block|,
literal|"    goto yyloop;"
block|,
literal|"yyoverflow:"
block|,
literal|"    yyerror(\"yacc stack overflow\");"
block|,
literal|"yyabort:"
block|,
literal|"    return (1);"
block|,
literal|"yyaccept:"
block|,
literal|"    return (0);"
block|,
literal|"}"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_macro
name|write_section
argument_list|(
argument|section
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|section
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|c
decl_stmt|;
specifier|register
name|int
name|i
decl_stmt|;
specifier|register
name|char
modifier|*
name|s
decl_stmt|;
specifier|register
name|FILE
modifier|*
name|f
decl_stmt|;
name|f
operator|=
name|code_file
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|s
operator|=
name|section
index|[
name|i
index|]
condition|;
operator|++
name|i
control|)
block|{
operator|++
name|outline
expr_stmt|;
while|while
condition|(
name|c
operator|=
operator|*
name|s
condition|)
block|{
name|putc
argument_list|(
name|c
argument_list|,
name|f
argument_list|)
expr_stmt|;
operator|++
name|s
expr_stmt|;
block|}
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|f
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

