begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file generated automatically using  * @Id: skel2c,v 1.4 2016/06/07 00:26:09 tom Exp @  */
end_comment

begin_comment
comment|/* @Id: yaccpar.skel,v 1.7 2016/06/06 23:35:55 Tom.Shields Exp @ */
end_comment

begin_include
include|#
directive|include
file|"defs.h"
end_include

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
specifier|const
name|char
modifier|*
specifier|const
name|banner
index|[]
init|=
block|{
literal|"/* original parser id follows */"
block|,
literal|"/* yysccsid[] = \"@(#)yaccpar	1.9 (Berkeley) 02/21/93\" */"
block|,
literal|"/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */"
block|,
literal|""
block|,
literal|"#define YYBYACC 1"
block|,
name|CONCAT1
argument_list|(
literal|"#define YYMAJOR "
argument_list|,
name|YYMAJOR
argument_list|)
block|,
name|CONCAT1
argument_list|(
literal|"#define YYMINOR "
argument_list|,
name|YYMINOR
argument_list|)
block|,
ifdef|#
directive|ifdef
name|YYPATCH
name|CONCAT1
argument_list|(
literal|"#define YYPATCH "
argument_list|,
name|YYPATCH
argument_list|)
block|,
endif|#
directive|endif
literal|""
block|,
literal|"#define YYEMPTY        (-1)"
block|,
literal|"#define yyclearin      (yychar = YYEMPTY)"
block|,
literal|"#define yyerrok        (yyerrflag = 0)"
block|,
literal|"#define YYRECOVERING() (yyerrflag != 0)"
block|,
literal|"#define YYENOMEM       (-2)"
block|,
literal|"#define YYEOF          0"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|xdecls
index|[]
init|=
block|{
literal|""
block|,
literal|"extern int YYPARSE_DECL();"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|tables
index|[]
init|=
block|{
literal|"extern YYINT yylhs[];"
block|,
literal|"extern YYINT yylen[];"
block|,
literal|"extern YYINT yydefred[];"
block|,
literal|"extern YYINT yydgoto[];"
block|,
literal|"extern YYINT yysindex[];"
block|,
literal|"extern YYINT yyrindex[];"
block|,
literal|"extern YYINT yygindex[];"
block|,
literal|"extern YYINT yytable[];"
block|,
literal|"extern YYINT yycheck[];"
block|,
literal|""
block|,
literal|"#if YYDEBUG || defined(yytname)"
block|,
literal|"extern char *yyname[];"
block|,
literal|"#endif"
block|,
literal|"#if YYDEBUG"
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
specifier|const
name|char
modifier|*
specifier|const
name|global_vars
index|[]
init|=
block|{
literal|""
block|,
literal|"int      yydebug;"
block|,
literal|"int      yynerrs;"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|impure_vars
index|[]
init|=
block|{
literal|""
block|,
literal|"int      yyerrflag;"
block|,
literal|"int      yychar;"
block|,
literal|"YYSTYPE  yyval;"
block|,
literal|"YYSTYPE  yylval;"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|hdr_defs
index|[]
init|=
block|{
literal|""
block|,
literal|"/* define the initial stack-sizes */"
block|,
literal|"#ifdef YYSTACKSIZE"
block|,
literal|"#undef YYMAXDEPTH"
block|,
literal|"#define YYMAXDEPTH  YYSTACKSIZE"
block|,
literal|"#else"
block|,
literal|"#ifdef YYMAXDEPTH"
block|,
literal|"#define YYSTACKSIZE YYMAXDEPTH"
block|,
literal|"#else"
block|,
literal|"#define YYSTACKSIZE 10000"
block|,
literal|"#define YYMAXDEPTH  10000"
block|,
literal|"#endif"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"#define YYINITSTACKSIZE 200"
block|,
literal|""
block|,
literal|"typedef struct {"
block|,
literal|"    unsigned stacksize;"
block|,
literal|"    YYINT    *s_base;"
block|,
literal|"    YYINT    *s_mark;"
block|,
literal|"    YYINT    *s_last;"
block|,
literal|"    YYSTYPE  *l_base;"
block|,
literal|"    YYSTYPE  *l_mark;"
block|,
literal|"} YYSTACKDATA;"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|hdr_vars
index|[]
init|=
block|{
literal|"/* variables for the parser stack */"
block|,
literal|"static YYSTACKDATA yystack;"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|body_vars
index|[]
init|=
block|{
literal|"    int      yyerrflag;"
block|,
literal|"    int      yychar;"
block|,
literal|"    YYSTYPE  yyval;"
block|,
literal|"    YYSTYPE  yylval;"
block|,
literal|""
block|,
literal|"    /* variables for the parser stack */"
block|,
literal|"    YYSTACKDATA yystack;"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|body_1
index|[]
init|=
block|{
literal|""
block|,
literal|"#if YYDEBUG"
block|,
literal|"#include<stdio.h>	/* needed for printf */"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"#include<stdlib.h>	/* needed for malloc, etc */"
block|,
literal|"#include<string.h>	/* needed for memset */"
block|,
literal|""
block|,
literal|"/* allocate initial stack or double stack size, up to YYMAXDEPTH */"
block|,
literal|"static int yygrowstack(YYSTACKDATA *data)"
block|,
literal|"{"
block|,
literal|"    int i;"
block|,
literal|"    unsigned newsize;"
block|,
literal|"    YYINT *newss;"
block|,
literal|"    YYSTYPE *newvs;"
block|,
literal|""
block|,
literal|"    if ((newsize = data->stacksize) == 0)"
block|,
literal|"        newsize = YYINITSTACKSIZE;"
block|,
literal|"    else if (newsize>= YYMAXDEPTH)"
block|,
literal|"        return YYENOMEM;"
block|,
literal|"    else if ((newsize *= 2)> YYMAXDEPTH)"
block|,
literal|"        newsize = YYMAXDEPTH;"
block|,
literal|""
block|,
literal|"    i = (int) (data->s_mark - data->s_base);"
block|,
literal|"    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));"
block|,
literal|"    if (newss == 0)"
block|,
literal|"        return YYENOMEM;"
block|,
literal|""
block|,
literal|"    data->s_base = newss;"
block|,
literal|"    data->s_mark = newss + i;"
block|,
literal|""
block|,
literal|"    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));"
block|,
literal|"    if (newvs == 0)"
block|,
literal|"        return YYENOMEM;"
block|,
literal|""
block|,
literal|"    data->l_base = newvs;"
block|,
literal|"    data->l_mark = newvs + i;"
block|,
literal|""
block|,
literal|"    data->stacksize = newsize;"
block|,
literal|"    data->s_last = data->s_base + newsize - 1;"
block|,
literal|"    return 0;"
block|,
literal|"}"
block|,
literal|""
block|,
literal|"#if YYPURE || defined(YY_NO_LEAKS)"
block|,
literal|"static void yyfreestack(YYSTACKDATA *data)"
block|,
literal|"{"
block|,
literal|"    free(data->s_base);"
block|,
literal|"    free(data->l_base);"
block|,
literal|"    memset(data, 0, sizeof(*data));"
block|,
literal|"}"
block|,
literal|"#else"
block|,
literal|"#define yyfreestack(data) /* nothing */"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"#define YYABORT  goto yyabort"
block|,
literal|"#define YYREJECT goto yyabort"
block|,
literal|"#define YYACCEPT goto yyaccept"
block|,
literal|"#define YYERROR  goto yyerrlab"
block|,
literal|""
block|,
literal|"int"
block|,
literal|"YYPARSE_DECL()"
block|,
literal|"{"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|body_2
index|[]
init|=
block|{
literal|"    int yym, yyn, yystate;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"    const char *yys;"
block|,
literal|""
block|,
literal|"    if ((yys = getenv(\"YYDEBUG\")) != 0)"
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
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|char
modifier|*
specifier|const
name|body_3
index|[]
init|=
block|{
literal|"    yym = 0;"
block|,
literal|"    yyn = 0;"
block|,
literal|"    yynerrs = 0;"
block|,
literal|"    yyerrflag = 0;"
block|,
literal|"    yychar = YYEMPTY;"
block|,
literal|"    yystate = 0;"
block|,
literal|""
block|,
literal|"#if YYPURE"
block|,
literal|"    memset(&yystack, 0, sizeof(yystack));"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"    if (yystack.s_base == NULL&& yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;"
block|,
literal|"    yystack.s_mark = yystack.s_base;"
block|,
literal|"    yystack.l_mark = yystack.l_base;"
block|,
literal|"    yystate = 0;"
block|,
literal|"    *yystack.s_mark = 0;"
block|,
literal|""
block|,
literal|"yyloop:"
block|,
literal|"    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;"
block|,
literal|"    if (yychar< 0)"
block|,
literal|"    {"
block|,
literal|"        yychar = YYLEX;"
block|,
literal|"        if (yychar< 0) yychar = YYEOF;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"        if (yydebug)"
block|,
literal|"        {"
block|,
literal|"            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];"
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
literal|"    if (((yyn = yysindex[yystate]) != 0)&& (yyn += yychar)>= 0&&"
block|,
literal|"            yyn<= YYTABLESIZE&& yycheck[yyn] == (YYINT) yychar)"
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
literal|"        if (yystack.s_mark>= yystack.s_last&& yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;"
block|,
literal|"        yystate = yytable[yyn];"
block|,
literal|"        *++yystack.s_mark = yytable[yyn];"
block|,
literal|"        *++yystack.l_mark = yylval;"
block|,
literal|"        yychar = YYEMPTY;"
block|,
literal|"        if (yyerrflag> 0)  --yyerrflag;"
block|,
literal|"        goto yyloop;"
block|,
literal|"    }"
block|,
literal|"    if (((yyn = yyrindex[yystate]) != 0)&& (yyn += yychar)>= 0&&"
block|,
literal|"            yyn<= YYTABLESIZE&& yycheck[yyn] == (YYINT) yychar)"
block|,
literal|"    {"
block|,
literal|"        yyn = yytable[yyn];"
block|,
literal|"        goto yyreduce;"
block|,
literal|"    }"
block|,
literal|"    if (yyerrflag != 0) goto yyinrecovery;"
block|,
literal|""
block|,
literal|"    YYERROR_CALL(\"syntax error\");"
block|,
literal|""
block|,
literal|"    goto yyerrlab; /* redundant goto avoids 'unused label' warning */"
block|,
literal|"yyerrlab:"
block|,
literal|"    ++yynerrs;"
block|,
literal|""
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
literal|"            if (((yyn = yysindex[*yystack.s_mark]) != 0)&& (yyn += YYERRCODE)>= 0&&"
block|,
literal|"                    yyn<= YYTABLESIZE&& yycheck[yyn] == (YYINT) YYERRCODE)"
block|,
literal|"            {"
block|,
literal|"#if YYDEBUG"
block|,
literal|"                if (yydebug)"
block|,
literal|"                    printf(\"%sdebug: state %d, error recovery shifting\\"
block|,
literal|" to state %d\\n\", YYPREFIX, *yystack.s_mark, yytable[yyn]);"
block|,
literal|"#endif"
block|,
literal|"                if (yystack.s_mark>= yystack.s_last&& yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;"
block|,
literal|"                yystate = yytable[yyn];"
block|,
literal|"                *++yystack.s_mark = yytable[yyn];"
block|,
literal|"                *++yystack.l_mark = yylval;"
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
literal|"                    printf(\"%sdebug: error recovery discarding state %d\\n\","
block|,
literal|"                            YYPREFIX, *yystack.s_mark);"
block|,
literal|"#endif"
block|,
literal|"                if (yystack.s_mark<= yystack.s_base) goto yyabort;"
block|,
literal|"                --yystack.s_mark;"
block|,
literal|"                --yystack.l_mark;"
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
literal|"        if (yychar == YYEOF) goto yyabort;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"        if (yydebug)"
block|,
literal|"        {"
block|,
literal|"            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];"
block|,
literal|"            printf(\"%sdebug: state %d, error recovery discards token %d (%s)\\n\","
block|,
literal|"                    YYPREFIX, yystate, yychar, yys);"
block|,
literal|"        }"
block|,
literal|"#endif"
block|,
literal|"        yychar = YYEMPTY;"
block|,
literal|"        goto yyloop;"
block|,
literal|"    }"
block|,
literal|""
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
literal|"    if (yym> 0)"
block|,
literal|"        yyval = yystack.l_mark[1-yym];"
block|,
literal|"    else"
block|,
literal|"        memset(&yyval, 0, sizeof yyval);"
block|,
literal|""
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
specifier|const
name|char
modifier|*
specifier|const
name|trailer
index|[]
init|=
block|{
literal|"    }"
block|,
literal|"    yystack.s_mark -= yym;"
block|,
literal|"    yystate = *yystack.s_mark;"
block|,
literal|"    yystack.l_mark -= yym;"
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
literal|"        *++yystack.s_mark = YYFINAL;"
block|,
literal|"        *++yystack.l_mark = yyval;"
block|,
literal|"        if (yychar< 0)"
block|,
literal|"        {"
block|,
literal|"            yychar = YYLEX;"
block|,
literal|"            if (yychar< 0) yychar = YYEOF;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"            if (yydebug)"
block|,
literal|"            {"
block|,
literal|"                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];"
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
literal|"        if (yychar == YYEOF) goto yyaccept;"
block|,
literal|"        goto yyloop;"
block|,
literal|"    }"
block|,
literal|"    if (((yyn = yygindex[yym]) != 0)&& (yyn += yystate)>= 0&&"
block|,
literal|"            yyn<= YYTABLESIZE&& yycheck[yyn] == (YYINT) yystate)"
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
literal|"to state %d\\n\", YYPREFIX, *yystack.s_mark, yystate);"
block|,
literal|"#endif"
block|,
literal|"    if (yystack.s_mark>= yystack.s_last&& yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;"
block|,
literal|"    *++yystack.s_mark = (YYINT) yystate;"
block|,
literal|"    *++yystack.l_mark = yyval;"
block|,
literal|"    goto yyloop;"
block|,
literal|""
block|,
literal|"yyoverflow:"
block|,
literal|"    YYERROR_CALL(\"yacc stack overflow\");"
block|,
literal|""
block|,
literal|"yyabort:"
block|,
literal|"    yyfreestack(&yystack);"
block|,
literal|"    return (1);"
block|,
literal|""
block|,
literal|"yyaccept:"
block|,
literal|"    yyfreestack(&yystack);"
block|,
literal|"    return (0);"
block|,
literal|"}"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|write_section
parameter_list|(
name|FILE
modifier|*
name|fp
parameter_list|,
specifier|const
name|char
modifier|*
specifier|const
name|section
index|[]
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
specifier|const
name|char
modifier|*
name|s
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
operator|(
name|s
operator|=
name|section
index|[
name|i
index|]
operator|)
operator|!=
literal|0
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|fp
operator|==
name|code_file
condition|)
operator|++
name|outline
expr_stmt|;
name|fprintf
argument_list|(
name|fp
argument_list|,
literal|"%s\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

