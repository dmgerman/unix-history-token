begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Robert Paul Corbett.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Berkeley.  The name of the  * University may not be used to endorse or promote products derived  * from this software without specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)skeleton.c	5.1 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_comment
comment|/*  The three line banner used here should be replaced with a one line	*/
end_comment

begin_comment
comment|/*  #ident directive if the target C compiler supports #ident		*/
end_comment

begin_comment
comment|/*  directives.								*/
end_comment

begin_comment
comment|/*									*/
end_comment

begin_comment
comment|/*  If the skeleton is changed, the banner should be changed so that	*/
end_comment

begin_comment
comment|/*  the altered version can easily be distinguished from the original.	*/
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
literal|"char yysccsid[] = \"@(#)yaccpar	1.1 (Berkeley) 12/10/89\";"
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
literal|"#define yyclearin (yychar=(-1))"
block|,
literal|"#define yyerrok (yyerrflag=0)"
block|,
literal|"#ifndef YYSTACKSIZE"
block|,
literal|"#ifdef YYMAXDEPTH"
block|,
literal|"#define YYSTACKSIZE YYMAXDEPTH"
block|,
literal|"#else"
block|,
literal|"#define YYSTACKSIZE 300"
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
literal|"#define yystacksize YYSTACKSIZE"
block|,
literal|"short yyss[YYSTACKSIZE];"
block|,
literal|"YYSTYPE yyvs[YYSTACKSIZE];"
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
literal|"        if (yyn == '0')"
block|,
literal|"            yydebug = 0;"
block|,
literal|"        else if (yyn>= '1'&& yyn<= '9')"
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
literal|"            printf(\"yydebug: state %d, reading %d (%s)\\n\", yystate,"
block|,
literal|"                    yychar, yys);"
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
literal|"            printf(\"yydebug: state %d, shifting to state %d\\n\","
block|,
literal|"                    yystate, yytable[yyn]);"
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
literal|"yynewerror:"
block|,
literal|"    yyerror(\"syntax error\");"
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
literal|"                    printf(\"yydebug: state %d, error recovery shifting\\"
block|,
literal|" to state %d\\n\", *yyssp, yytable[yyn]);"
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
literal|"                    printf(\"yydebug: error recovery discarding state %d\ \\n\","
block|,
literal|"                            *yyssp);"
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
literal|"            printf(\"yydebug: state %d, error recovery discards token %d\  (%s)\\n\","
block|,
literal|"                    yystate, yychar, yys);"
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
literal|"        printf(\"yydebug: state %d, reducing by rule %d (%s)\\n\","
block|,
literal|"                yystate, yyn, yyrule[yyn]);"
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
literal|"#ifdef YYDEBUG"
block|,
literal|"        if (yydebug)"
block|,
literal|"            printf(\"yydebug: after reduction, shifting from state 0 to\\"
block|,
literal|" state %d\\n\", YYFINAL);"
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
literal|"                printf(\"yydebug: state %d, reading %d (%s)\\n\","
block|,
literal|"                        YYFINAL, yychar, yys);"
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
literal|"#ifdef YYDEBUG"
block|,
literal|"    if (yydebug)"
block|,
literal|"        printf(\"yydebug: after reduction, shifting from state %d \\"
block|,
literal|"to state %d\\n\", *yyssp, yystate);"
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
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
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
name|fprintf
argument_list|(
name|output_file
argument_list|,
literal|"%s\n"
argument_list|,
name|section
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
block|}
end_block

end_unit

