begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Robert Paul Corbett.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
specifier|const
name|sccsid
index|[]
init|=
literal|"@(#)skeleton.c	5.8 (Berkeley) 4/29/95"
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
literal|"static char const "
block|,
literal|"yyrcsid[] = \"$FreeBSD$\";"
block|,
literal|"#endif"
block|,
literal|"#include<stdlib.h>"
block|,
literal|"#define YYBYACC 1"
block|,
literal|"#define YYMAJOR 1"
block|,
literal|"#define YYMINOR 9"
block|,
literal|"#define YYLEX yylex()"
block|,
literal|"#define YYEMPTY -1"
block|,
literal|"#define yyclearin (yychar=(YYEMPTY))"
block|,
literal|"#define yyerrok (yyerrflag=0)"
block|,
literal|"#define YYRECOVERING() (yyerrflag!=0)"
block|,
literal|"#if defined(__cplusplus) || __STDC__"
block|,
literal|"static int yygrowstack(void);"
block|,
literal|"#else"
block|,
literal|"static int yygrowstack();"
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
name|tables
index|[]
init|=
block|{
literal|"extern const short yylhs[];"
block|,
literal|"extern const short yylen[];"
block|,
literal|"extern const short yydefred[];"
block|,
literal|"extern const short yydgoto[];"
block|,
literal|"extern const short yysindex[];"
block|,
literal|"extern const short yyrindex[];"
block|,
literal|"extern const short yygindex[];"
block|,
literal|"extern const short yytable[];"
block|,
literal|"extern const short yycheck[];"
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
literal|"#if YYDEBUG"
block|,
literal|"#include<stdio.h>"
block|,
literal|"#endif"
block|,
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
literal|"#define YYSTACKSIZE 10000"
block|,
literal|"#define YYMAXDEPTH 10000"
block|,
literal|"#endif"
block|,
literal|"#endif"
block|,
literal|"#define YYINITSTACKSIZE 200"
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
literal|"short *yyss;"
block|,
literal|"short *yysslim;"
block|,
literal|"YYSTYPE *yyvs;"
block|,
literal|"int yystacksize;"
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
literal|"/* allocate initial stack or double stack size, up to YYMAXDEPTH */"
block|,
literal|"static int yygrowstack()"
block|,
literal|"{"
block|,
literal|"    int newsize, i;"
block|,
literal|"    short *newss;"
block|,
literal|"    YYSTYPE *newvs;"
block|,
literal|""
block|,
literal|"    if ((newsize = yystacksize) == 0)"
block|,
literal|"        newsize = YYINITSTACKSIZE;"
block|,
literal|"    else if (newsize>= YYMAXDEPTH)"
block|,
literal|"        return -1;"
block|,
literal|"    else if ((newsize *= 2)> YYMAXDEPTH)"
block|,
literal|"        newsize = YYMAXDEPTH;"
block|,
literal|"    i = yyssp - yyss;"
block|,
literal|"    newss = yyss ? (short *)realloc(yyss, newsize * sizeof *newss) :"
block|,
literal|"      (short *)malloc(newsize * sizeof *newss);"
block|,
literal|"    if (newss == NULL)"
block|,
literal|"        return -1;"
block|,
literal|"    yyss = newss;"
block|,
literal|"    yyssp = newss + i;"
block|,
literal|"    newvs = yyvs ? (YYSTYPE *)realloc(yyvs, newsize * sizeof *newvs) :"
block|,
literal|"      (YYSTYPE *)malloc(newsize * sizeof *newvs);"
block|,
literal|"    if (newvs == NULL)"
block|,
literal|"        return -1;"
block|,
literal|"    yyvs = newvs;"
block|,
literal|"    yyvsp = newvs + i;"
block|,
literal|"    yystacksize = newsize;"
block|,
literal|"    yysslim = yyss + newsize - 1;"
block|,
literal|"    return 0;"
block|,
literal|"}"
block|,
literal|""
block|,
literal|"#define YYABORT goto yyabort"
block|,
literal|"#define YYREJECT goto yyabort"
block|,
literal|"#define YYACCEPT goto yyaccept"
block|,
literal|"#define YYERROR goto yyerrlab"
block|,
literal|""
block|,
literal|"#ifndef YYPARSE_PARAM"
block|,
literal|"#if defined(__cplusplus) || __STDC__"
block|,
literal|"#define YYPARSE_PARAM_ARG void"
block|,
literal|"#define YYPARSE_PARAM_DECL"
block|,
literal|"#else	/* ! ANSI-C/C++ */"
block|,
literal|"#define YYPARSE_PARAM_ARG"
block|,
literal|"#define YYPARSE_PARAM_DECL"
block|,
literal|"#endif	/* ANSI-C/C++ */"
block|,
literal|"#else	/* YYPARSE_PARAM */"
block|,
literal|"#ifndef YYPARSE_PARAM_TYPE"
block|,
literal|"#define YYPARSE_PARAM_TYPE void *"
block|,
literal|"#endif"
block|,
literal|"#if defined(__cplusplus) || __STDC__"
block|,
literal|"#define YYPARSE_PARAM_ARG YYPARSE_PARAM_TYPE YYPARSE_PARAM"
block|,
literal|"#define YYPARSE_PARAM_DECL"
block|,
literal|"#else	/* ! ANSI-C/C++ */"
block|,
literal|"#define YYPARSE_PARAM_ARG YYPARSE_PARAM"
block|,
literal|"#define YYPARSE_PARAM_DECL YYPARSE_PARAM_TYPE YYPARSE_PARAM;"
block|,
literal|"#endif	/* ANSI-C/C++ */"
block|,
literal|"#endif	/* ! YYPARSE_PARAM */"
block|,
literal|""
block|,
literal|"int"
block|,
literal|"yyparse (YYPARSE_PARAM_ARG)"
block|,
literal|"    YYPARSE_PARAM_DECL"
block|,
literal|"{"
block|,
literal|"    register int yym, yyn, yystate;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"    register const char *yys;"
block|,
literal|""
block|,
literal|"    if ((yys = getenv(\"YYDEBUG\")))"
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
literal|"    if (yyss == NULL&& yygrowstack()) goto yyoverflow;"
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
literal|"    if ((yyn = yydefred[yystate])) goto yyreduce;"
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
literal|"        if (yyssp>= yysslim&& yygrowstack())"
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
literal|"#if defined(lint) || defined(__GNUC__)"
block|,
literal|"    goto yynewerror;"
block|,
literal|"#endif"
block|,
literal|"yynewerror:"
block|,
literal|"    yyerror(\"syntax error\");"
block|,
literal|"#if defined(lint) || defined(__GNUC__)"
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
literal|"                if (yyssp>= yysslim&& yygrowstack())"
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
literal|"    if (yyssp>= yysslim&& yygrowstack())"
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

begin_function
name|void
name|write_section
parameter_list|(
name|section
parameter_list|)
name|char
modifier|*
name|section
index|[]
decl_stmt|;
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
operator|(
name|s
operator|=
name|section
index|[
name|i
index|]
operator|)
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
operator|(
name|c
operator|=
operator|*
name|s
operator|)
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
end_function

end_unit

