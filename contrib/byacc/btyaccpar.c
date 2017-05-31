begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file generated automatically using  * @Id: skel2c,v 1.4 2016/06/07 00:26:09 tom Exp @  */
end_comment

begin_comment
comment|/* @Id: btyaccpar.skel,v 1.6 2017/04/30 23:40:34 tom Exp @ */
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
literal|"extern const YYINT yylhs[];"
block|,
literal|"extern const YYINT yylen[];"
block|,
literal|"extern const YYINT yydefred[];"
block|,
literal|"extern const YYINT yystos[];"
block|,
literal|"extern const YYINT yydgoto[];"
block|,
literal|"extern const YYINT yysindex[];"
block|,
literal|"extern const YYINT yyrindex[];"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"extern const YYINT yycindex[];"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"extern const YYINT yygindex[];"
block|,
literal|"extern const YYINT yytable[];"
block|,
literal|"extern const YYINT yycheck[];"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"extern const YYINT yyctable[];"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|""
block|,
literal|"#if YYDEBUG || defined(yytname)"
block|,
literal|"extern const char *const yyname[];"
block|,
literal|"#endif"
block|,
literal|"#if YYDEBUG"
block|,
literal|"extern const char *const yyrule[];"
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
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"YYLTYPE  yyloc; /* position returned by actions */"
block|,
literal|"YYLTYPE  yylloc; /* position from the lexer */"
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
name|hdr_defs
index|[]
init|=
block|{
literal|""
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"#ifndef YYLLOC_DEFAULT"
block|,
literal|"#define YYLLOC_DEFAULT(loc, rhs, n) \\"
block|,
literal|"do \\"
block|,
literal|"{ \\"
block|,
literal|"    if (n == 0) \\"
block|,
literal|"    { \\"
block|,
literal|"        (loc).first_line   = ((rhs)[-1]).last_line; \\"
block|,
literal|"        (loc).first_column = ((rhs)[-1]).last_column; \\"
block|,
literal|"        (loc).last_line    = ((rhs)[-1]).last_line; \\"
block|,
literal|"        (loc).last_column  = ((rhs)[-1]).last_column; \\"
block|,
literal|"    } \\"
block|,
literal|"    else \\"
block|,
literal|"    { \\"
block|,
literal|"        (loc).first_line   = ((rhs)[ 0 ]).first_line; \\"
block|,
literal|"        (loc).first_column = ((rhs)[ 0 ]).first_column; \\"
block|,
literal|"        (loc).last_line    = ((rhs)[n-1]).last_line; \\"
block|,
literal|"        (loc).last_column  = ((rhs)[n-1]).last_column; \\"
block|,
literal|"    } \\"
block|,
literal|"} while (0)"
block|,
literal|"#endif /* YYLLOC_DEFAULT */"
block|,
literal|"#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|""
block|,
literal|"#ifndef YYLVQUEUEGROWTH"
block|,
literal|"#define YYLVQUEUEGROWTH 32"
block|,
literal|"#endif"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
literal|"#ifndef YYINITSTACKSIZE"
block|,
literal|"#define YYINITSTACKSIZE 200"
block|,
literal|"#endif"
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
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    YYLTYPE  *p_base;"
block|,
literal|"    YYLTYPE  *p_mark;"
block|,
literal|"#endif"
block|,
literal|"} YYSTACKDATA;"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|""
block|,
literal|"struct YYParseState_s"
block|,
literal|"{"
block|,
literal|"    struct YYParseState_s *save;    /* Previously saved parser state */"
block|,
literal|"    YYSTACKDATA            yystack; /* saved parser stack */"
block|,
literal|"    int                    state;   /* saved parser state */"
block|,
literal|"    int                    errflag; /* saved error recovery status */"
block|,
literal|"    int                    lexeme;  /* saved index of the conflict lexeme in the lexical queue */"
block|,
literal|"    YYINT                  ctry;    /* saved index in yyctable[] for this conflict */"
block|,
literal|"};"
block|,
literal|"typedef struct YYParseState_s YYParseState;"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|""
block|,
literal|"/* Current parser state */"
block|,
literal|"static YYParseState *yyps = 0;"
block|,
literal|""
block|,
literal|"/* yypath != NULL: do the full parse, starting at *yypath parser state. */"
block|,
literal|"static YYParseState *yypath = 0;"
block|,
literal|""
block|,
literal|"/* Base of the lexical value queue */"
block|,
literal|"static YYSTYPE *yylvals = 0;"
block|,
literal|""
block|,
literal|"/* Current position at lexical value queue */"
block|,
literal|"static YYSTYPE *yylvp = 0;"
block|,
literal|""
block|,
literal|"/* End position of lexical value queue */"
block|,
literal|"static YYSTYPE *yylve = 0;"
block|,
literal|""
block|,
literal|"/* The last allocated position at the lexical value queue */"
block|,
literal|"static YYSTYPE *yylvlim = 0;"
block|,
literal|""
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"/* Base of the lexical position queue */"
block|,
literal|"static YYLTYPE *yylpsns = 0;"
block|,
literal|""
block|,
literal|"/* Current position at lexical position queue */"
block|,
literal|"static YYLTYPE *yylpp = 0;"
block|,
literal|""
block|,
literal|"/* End position of lexical position queue */"
block|,
literal|"static YYLTYPE *yylpe = 0;"
block|,
literal|""
block|,
literal|"/* The last allocated position at the lexical position queue */"
block|,
literal|"static YYLTYPE *yylplim = 0;"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"/* Current position at lexical token queue */"
block|,
literal|"static YYINT  *yylexp = 0;"
block|,
literal|""
block|,
literal|"static YYINT  *yylexemes = 0;"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    YYLTYPE  yyloc; /* position returned by actions */"
block|,
literal|"    YYLTYPE  yylloc; /* position from the lexer */"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"    /* variables for the parser stack */"
block|,
literal|"    YYSTACKDATA yystack;"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|""
block|,
literal|"    /* Current parser state */"
block|,
literal|"    static YYParseState *yyps = 0;"
block|,
literal|""
block|,
literal|"    /* yypath != NULL: do the full parse, starting at *yypath parser state. */"
block|,
literal|"    static YYParseState *yypath = 0;"
block|,
literal|""
block|,
literal|"    /* Base of the lexical value queue */"
block|,
literal|"    static YYSTYPE *yylvals = 0;"
block|,
literal|""
block|,
literal|"    /* Current position at lexical value queue */"
block|,
literal|"    static YYSTYPE *yylvp = 0;"
block|,
literal|""
block|,
literal|"    /* End position of lexical value queue */"
block|,
literal|"    static YYSTYPE *yylve = 0;"
block|,
literal|""
block|,
literal|"    /* The last allocated position at the lexical value queue */"
block|,
literal|"    static YYSTYPE *yylvlim = 0;"
block|,
literal|""
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    /* Base of the lexical position queue */"
block|,
literal|"    static YYLTYPE *yylpsns = 0;"
block|,
literal|""
block|,
literal|"    /* Current position at lexical position queue */"
block|,
literal|"    static YYLTYPE *yylpp = 0;"
block|,
literal|""
block|,
literal|"    /* End position of lexical position queue */"
block|,
literal|"    static YYLTYPE *yylpe = 0;"
block|,
literal|""
block|,
literal|"    /* The last allocated position at the lexical position queue */"
block|,
literal|"    static YYLTYPE *yylplim = 0;"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"    /* Current position at lexical token queue */"
block|,
literal|"    static YYINT  *yylexp = 0;"
block|,
literal|""
block|,
literal|"    static YYINT  *yylexemes = 0;"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
literal|"/* For use in generated program */"
block|,
literal|"#define yydepth (int)(yystack.s_mark - yystack.s_base)"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"#define yytrial (yyps->save)"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    YYLTYPE *newps;"
block|,
literal|"#endif"
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
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    newps = (YYLTYPE *)realloc(data->p_base, newsize * sizeof(*newps));"
block|,
literal|"    if (newps == 0)"
block|,
literal|"        return YYENOMEM;"
block|,
literal|""
block|,
literal|"    data->p_base = newps;"
block|,
literal|"    data->p_mark = newps + i;"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"    data->stacksize = newsize;"
block|,
literal|"    data->s_last = data->s_base + newsize - 1;"
block|,
literal|""
block|,
literal|"#if YYDEBUG"
block|,
literal|"    if (yydebug)"
block|,
literal|"        fprintf(stderr, \"%sdebug: stack size increased to %d\\n\", YYPREFIX, newsize);"
block|,
literal|"#endif"
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
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    free(data->p_base);"
block|,
literal|"#endif"
block|,
literal|"    memset(data, 0, sizeof(*data));"
block|,
literal|"}"
block|,
literal|"#else"
block|,
literal|"#define yyfreestack(data) /* nothing */"
block|,
literal|"#endif /* YYPURE || defined(YY_NO_LEAKS) */"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|""
block|,
literal|"static YYParseState *"
block|,
literal|"yyNewState(unsigned size)"
block|,
literal|"{"
block|,
literal|"    YYParseState *p = (YYParseState *) malloc(sizeof(YYParseState));"
block|,
literal|"    if (p == NULL) return NULL;"
block|,
literal|""
block|,
literal|"    p->yystack.stacksize = size;"
block|,
literal|"    if (size == 0)"
block|,
literal|"    {"
block|,
literal|"        p->yystack.s_base = NULL;"
block|,
literal|"        p->yystack.l_base = NULL;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"        p->yystack.p_base = NULL;"
block|,
literal|"#endif"
block|,
literal|"        return p;"
block|,
literal|"    }"
block|,
literal|"    p->yystack.s_base    = (YYINT *) malloc(size * sizeof(YYINT));"
block|,
literal|"    if (p->yystack.s_base == NULL) return NULL;"
block|,
literal|"    p->yystack.l_base    = (YYSTYPE *) malloc(size * sizeof(YYSTYPE));"
block|,
literal|"    if (p->yystack.l_base == NULL) return NULL;"
block|,
literal|"    memset(p->yystack.l_base, 0, size * sizeof(YYSTYPE));"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    p->yystack.p_base    = (YYLTYPE *) malloc(size * sizeof(YYLTYPE));"
block|,
literal|"    if (p->yystack.p_base == NULL) return NULL;"
block|,
literal|"    memset(p->yystack.p_base, 0, size * sizeof(YYLTYPE));"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"    return p;"
block|,
literal|"}"
block|,
literal|""
block|,
literal|"static void"
block|,
literal|"yyFreeState(YYParseState *p)"
block|,
literal|"{"
block|,
literal|"    yyfreestack(&p->yystack);"
block|,
literal|"    free(p);"
block|,
literal|"}"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"#define YYVALID        do { if (yyps->save)            goto yyvalid; } while(0)"
block|,
literal|"#define YYVALID_NESTED do { if (yyps->save&& \\"
block|,
literal|"                                yyps->save->save == 0) goto yyvalid; } while(0)"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
literal|"    int yym, yyn, yystate, yyresult;"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"    int yynewerrflag;"
block|,
literal|"    YYParseState *yyerrctx = NULL;"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    YYLTYPE  yyerror_loc_range[2]; /* position of error start& end */"
block|,
literal|"#endif"
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
literal|"    if (yydebug)"
block|,
literal|"        fprintf(stderr, \"%sdebug[<# of symbols on state stack>]\\n\", YYPREFIX);"
block|,
literal|"#endif"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    memset(yyerror_loc_range, 0, sizeof(yyerror_loc_range));"
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
name|init_vars
index|[]
init|=
block|{
literal|"    yyerrflag = 0;"
block|,
literal|"    yychar = 0;"
block|,
literal|"    memset(&yyval,  0, sizeof(yyval));"
block|,
literal|"    memset(&yylval, 0, sizeof(yylval));"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    memset(&yyloc,  0, sizeof(yyloc));"
block|,
literal|"    memset(&yylloc, 0, sizeof(yylloc));"
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
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"    yyps = yyNewState(0); if (yyps == 0) goto yyenomem;"
block|,
literal|"    yyps->save = 0;"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    yystack.p_mark = yystack.p_base;"
block|,
literal|"#endif"
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
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"        do {"
block|,
literal|"        if (yylvp< yylve)"
block|,
literal|"        {"
block|,
literal|"            /* we're currently re-reading tokens */"
block|,
literal|"            yylval = *yylvp++;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"            yylloc = *yylpp++;"
block|,
literal|"#endif"
block|,
literal|"            yychar = *yylexp++;"
block|,
literal|"            break;"
block|,
literal|"        }"
block|,
literal|"        if (yyps->save)"
block|,
literal|"        {"
block|,
literal|"            /* in trial mode; save scanner results for future parse attempts */"
block|,
literal|"            if (yylvp == yylvlim)"
block|,
literal|"            {   /* Enlarge lexical value queue */"
block|,
literal|"                size_t p = (size_t) (yylvp - yylvals);"
block|,
literal|"                size_t s = (size_t) (yylvlim - yylvals);"
block|,
literal|""
block|,
literal|"                s += YYLVQUEUEGROWTH;"
block|,
literal|"                if ((yylexemes = realloc(yylexemes, s * sizeof(YYINT))) == NULL) goto yyenomem;"
block|,
literal|"                if ((yylvals   = realloc(yylvals, s * sizeof(YYSTYPE))) == NULL) goto yyenomem;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                if ((yylpsns   = realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL) goto yyenomem;"
block|,
literal|"#endif"
block|,
literal|"                yylvp   = yylve = yylvals + p;"
block|,
literal|"                yylvlim = yylvals + s;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                yylpp   = yylpe = yylpsns + p;"
block|,
literal|"                yylplim = yylpsns + s;"
block|,
literal|"#endif"
block|,
literal|"                yylexp  = yylexemes + p;"
block|,
literal|"            }"
block|,
literal|"            *yylexp = (YYINT) YYLEX;"
block|,
literal|"            *yylvp++ = yylval;"
block|,
literal|"            yylve++;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"            *yylpp++ = yylloc;"
block|,
literal|"            yylpe++;"
block|,
literal|"#endif"
block|,
literal|"            yychar = *yylexp++;"
block|,
literal|"            break;"
block|,
literal|"        }"
block|,
literal|"        /* normal operation, no conflict encountered */"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"        yychar = YYLEX;"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"        } while (0);"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
literal|"            fprintf(stderr, \"%s[%d]: state %d, reading token %d (%s)\","
block|,
literal|"                            YYDEBUGSTR, yydepth, yystate, yychar, yys);"
block|,
literal|"#ifdef YYSTYPE_TOSTRING"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"            if (!yytrial)"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"                fprintf(stderr, \"<%s>\", YYSTYPE_TOSTRING(yychar, yylval));"
block|,
literal|"#endif"
block|,
literal|"            fputc('\\n', stderr);"
block|,
literal|"        }"
block|,
literal|"#endif"
block|,
literal|"    }"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|""
block|,
literal|"    /* Do we have a conflict? */"
block|,
literal|"    if (((yyn = yycindex[yystate]) != 0)&& (yyn += yychar)>= 0&&"
block|,
literal|"        yyn<= YYTABLESIZE&& yycheck[yyn] == (YYINT) yychar)"
block|,
literal|"    {"
block|,
literal|"        YYINT ctry;"
block|,
literal|""
block|,
literal|"        if (yypath)"
block|,
literal|"        {"
block|,
literal|"            YYParseState *save;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"            if (yydebug)"
block|,
literal|"                fprintf(stderr, \"%s[%d]: CONFLICT in state %d: following successful trial parse\\n\","
block|,
literal|"                                YYDEBUGSTR, yydepth, yystate);"
block|,
literal|"#endif"
block|,
literal|"            /* Switch to the next conflict context */"
block|,
literal|"            save = yypath;"
block|,
literal|"            yypath = save->save;"
block|,
literal|"            save->save = NULL;"
block|,
literal|"            ctry = save->ctry;"
block|,
literal|"            if (save->state != yystate) YYABORT;"
block|,
literal|"            yyFreeState(save);"
block|,
literal|""
block|,
literal|"        }"
block|,
literal|"        else"
block|,
literal|"        {"
block|,
literal|""
block|,
literal|"            /* Unresolved conflict - start/continue trial parse */"
block|,
literal|"            YYParseState *save;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"            if (yydebug)"
block|,
literal|"            {"
block|,
literal|"                fprintf(stderr, \"%s[%d]: CONFLICT in state %d. \", YYDEBUGSTR, yydepth, yystate);"
block|,
literal|"                if (yyps->save)"
block|,
literal|"                    fputs(\"ALREADY in conflict, continuing trial parse.\\n\", stderr);"
block|,
literal|"                else"
block|,
literal|"                    fputs(\"Starting trial parse.\\n\", stderr);"
block|,
literal|"            }"
block|,
literal|"#endif"
block|,
literal|"            save                  = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));"
block|,
literal|"            if (save == NULL) goto yyenomem;"
block|,
literal|"            save->save            = yyps->save;"
block|,
literal|"            save->state           = yystate;"
block|,
literal|"            save->errflag         = yyerrflag;"
block|,
literal|"            save->yystack.s_mark  = save->yystack.s_base + (yystack.s_mark - yystack.s_base);"
block|,
literal|"            memcpy (save->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));"
block|,
literal|"            save->yystack.l_mark  = save->yystack.l_base + (yystack.l_mark - yystack.l_base);"
block|,
literal|"            memcpy (save->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"            save->yystack.p_mark  = save->yystack.p_base + (yystack.p_mark - yystack.p_base);"
block|,
literal|"            memcpy (save->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));"
block|,
literal|"#endif"
block|,
literal|"            ctry                  = yytable[yyn];"
block|,
literal|"            if (yyctable[ctry] == -1)"
block|,
literal|"            {"
block|,
literal|"#if YYDEBUG"
block|,
literal|"                if (yydebug&& yychar>= YYEOF)"
block|,
literal|"                    fprintf(stderr, \"%s[%d]: backtracking 1 token\\n\", YYDEBUGSTR, yydepth);"
block|,
literal|"#endif"
block|,
literal|"                ctry++;"
block|,
literal|"            }"
block|,
literal|"            save->ctry = ctry;"
block|,
literal|"            if (yyps->save == NULL)"
block|,
literal|"            {"
block|,
literal|"                /* If this is a first conflict in the stack, start saving lexemes */"
block|,
literal|"                if (!yylexemes)"
block|,
literal|"                {"
block|,
literal|"                    yylexemes = malloc((YYLVQUEUEGROWTH) * sizeof(YYINT));"
block|,
literal|"                    if (yylexemes == NULL) goto yyenomem;"
block|,
literal|"                    yylvals   = (YYSTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYSTYPE));"
block|,
literal|"                    if (yylvals == NULL) goto yyenomem;"
block|,
literal|"                    yylvlim   = yylvals + YYLVQUEUEGROWTH;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                    yylpsns   = (YYLTYPE *) malloc((YYLVQUEUEGROWTH) * sizeof(YYLTYPE));"
block|,
literal|"                    if (yylpsns == NULL) goto yyenomem;"
block|,
literal|"                    yylplim   = yylpsns + YYLVQUEUEGROWTH;"
block|,
literal|"#endif"
block|,
literal|"                }"
block|,
literal|"                if (yylvp == yylve)"
block|,
literal|"                {"
block|,
literal|"                    yylvp  = yylve = yylvals;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                    yylpp  = yylpe = yylpsns;"
block|,
literal|"#endif"
block|,
literal|"                    yylexp = yylexemes;"
block|,
literal|"                    if (yychar>= YYEOF)"
block|,
literal|"                    {"
block|,
literal|"                        *yylve++ = yylval;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                        *yylpe++ = yylloc;"
block|,
literal|"#endif"
block|,
literal|"                        *yylexp  = (YYINT) yychar;"
block|,
literal|"                        yychar   = YYEMPTY;"
block|,
literal|"                    }"
block|,
literal|"                }"
block|,
literal|"            }"
block|,
literal|"            if (yychar>= YYEOF)"
block|,
literal|"            {"
block|,
literal|"                yylvp--;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                yylpp--;"
block|,
literal|"#endif"
block|,
literal|"                yylexp--;"
block|,
literal|"                yychar = YYEMPTY;"
block|,
literal|"            }"
block|,
literal|"            save->lexeme = (int) (yylvp - yylvals);"
block|,
literal|"            yyps->save   = save;"
block|,
literal|"        }"
block|,
literal|"        if (yytable[yyn] == ctry)"
block|,
literal|"        {"
block|,
literal|"#if YYDEBUG"
block|,
literal|"            if (yydebug)"
block|,
literal|"                fprintf(stderr, \"%s[%d]: state %d, shifting to state %d\\n\","
block|,
literal|"                                YYDEBUGSTR, yydepth, yystate, yyctable[ctry]);"
block|,
literal|"#endif"
block|,
literal|"            if (yychar< 0)"
block|,
literal|"            {"
block|,
literal|"                yylvp++;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                yylpp++;"
block|,
literal|"#endif"
block|,
literal|"                yylexp++;"
block|,
literal|"            }"
block|,
literal|"            if (yystack.s_mark>= yystack.s_last&& yygrowstack(&yystack) == YYENOMEM)"
block|,
literal|"                goto yyoverflow;"
block|,
literal|"            yystate = yyctable[ctry];"
block|,
literal|"            *++yystack.s_mark = (YYINT) yystate;"
block|,
literal|"            *++yystack.l_mark = yylval;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"            *++yystack.p_mark = yylloc;"
block|,
literal|"#endif"
block|,
literal|"            yychar  = YYEMPTY;"
block|,
literal|"            if (yyerrflag> 0) --yyerrflag;"
block|,
literal|"            goto yyloop;"
block|,
literal|"        }"
block|,
literal|"        else"
block|,
literal|"        {"
block|,
literal|"            yyn = yyctable[ctry];"
block|,
literal|"            goto yyreduce;"
block|,
literal|"        }"
block|,
literal|"    } /* End of code dealing with conflicts */"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
literal|"            fprintf(stderr, \"%s[%d]: state %d, shifting to state %d\\n\","
block|,
literal|"                            YYDEBUGSTR, yydepth, yystate, yytable[yyn]);"
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
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"        *++yystack.p_mark = yylloc;"
block|,
literal|"#endif"
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
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|""
block|,
literal|"    yynewerrflag = 1;"
block|,
literal|"    goto yyerrhandler;"
block|,
literal|"    goto yyerrlab; /* redundant goto avoids 'unused label' warning */"
block|,
literal|""
block|,
literal|"yyerrlab:"
block|,
literal|"    /* explicit YYERROR from an action -- pop the rhs of the rule reduced"
block|,
literal|"     * before looking for error recovery */"
block|,
literal|"    yystack.s_mark -= yym;"
block|,
literal|"    yystate = *yystack.s_mark;"
block|,
literal|"    yystack.l_mark -= yym;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    yystack.p_mark -= yym;"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"    yynewerrflag = 0;"
block|,
literal|"yyerrhandler:"
block|,
literal|"    while (yyps->save)"
block|,
literal|"    {"
block|,
literal|"        int ctry;"
block|,
literal|"        YYParseState *save = yyps->save;"
block|,
literal|"#if YYDEBUG"
block|,
literal|"        if (yydebug)"
block|,
literal|"            fprintf(stderr, \"%s[%d]: ERROR in state %d, CONFLICT BACKTRACKING to state %d, %d tokens\\n\","
block|,
literal|"                            YYDEBUGSTR, yydepth, yystate, yyps->save->state,"
block|,
literal|"                    (int)(yylvp - yylvals - yyps->save->lexeme));"
block|,
literal|"#endif"
block|,
literal|"        /* Memorize most forward-looking error state in case it's really an error. */"
block|,
literal|"        if (yyerrctx == NULL || yyerrctx->lexeme< yylvp - yylvals)"
block|,
literal|"        {"
block|,
literal|"            /* Free old saved error context state */"
block|,
literal|"            if (yyerrctx) yyFreeState(yyerrctx);"
block|,
literal|"            /* Create and fill out new saved error context state */"
block|,
literal|"            yyerrctx                 = yyNewState((unsigned)(yystack.s_mark - yystack.s_base + 1));"
block|,
literal|"            if (yyerrctx == NULL) goto yyenomem;"
block|,
literal|"            yyerrctx->save           = yyps->save;"
block|,
literal|"            yyerrctx->state          = yystate;"
block|,
literal|"            yyerrctx->errflag        = yyerrflag;"
block|,
literal|"            yyerrctx->yystack.s_mark = yyerrctx->yystack.s_base + (yystack.s_mark - yystack.s_base);"
block|,
literal|"            memcpy (yyerrctx->yystack.s_base, yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));"
block|,
literal|"            yyerrctx->yystack.l_mark = yyerrctx->yystack.l_base + (yystack.l_mark - yystack.l_base);"
block|,
literal|"            memcpy (yyerrctx->yystack.l_base, yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"            yyerrctx->yystack.p_mark = yyerrctx->yystack.p_base + (yystack.p_mark - yystack.p_base);"
block|,
literal|"            memcpy (yyerrctx->yystack.p_base, yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));"
block|,
literal|"#endif"
block|,
literal|"            yyerrctx->lexeme         = (int) (yylvp - yylvals);"
block|,
literal|"        }"
block|,
literal|"        yylvp          = yylvals   + save->lexeme;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"        yylpp          = yylpsns   + save->lexeme;"
block|,
literal|"#endif"
block|,
literal|"        yylexp         = yylexemes + save->lexeme;"
block|,
literal|"        yychar         = YYEMPTY;"
block|,
literal|"        yystack.s_mark = yystack.s_base + (save->yystack.s_mark - save->yystack.s_base);"
block|,
literal|"        memcpy (yystack.s_base, save->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));"
block|,
literal|"        yystack.l_mark = yystack.l_base + (save->yystack.l_mark - save->yystack.l_base);"
block|,
literal|"        memcpy (yystack.l_base, save->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"        yystack.p_mark = yystack.p_base + (save->yystack.p_mark - save->yystack.p_base);"
block|,
literal|"        memcpy (yystack.p_base, save->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));"
block|,
literal|"#endif"
block|,
literal|"        ctry           = ++save->ctry;"
block|,
literal|"        yystate        = save->state;"
block|,
literal|"        /* We tried shift, try reduce now */"
block|,
literal|"        if ((yyn = yyctable[ctry])>= 0) goto yyreduce;"
block|,
literal|"        yyps->save     = save->save;"
block|,
literal|"        save->save     = NULL;"
block|,
literal|"        yyFreeState(save);"
block|,
literal|""
block|,
literal|"        /* Nothing left on the stack -- error */"
block|,
literal|"        if (!yyps->save)"
block|,
literal|"        {"
block|,
literal|"#if YYDEBUG"
block|,
literal|"            if (yydebug)"
block|,
literal|"                fprintf(stderr, \"%sdebug[%d,trial]: trial parse FAILED, entering ERROR mode\\n\","
block|,
literal|"                                YYPREFIX, yydepth);"
block|,
literal|"#endif"
block|,
literal|"            /* Restore state as it was in the most forward-advanced error */"
block|,
literal|"            yylvp          = yylvals   + yyerrctx->lexeme;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"            yylpp          = yylpsns   + yyerrctx->lexeme;"
block|,
literal|"#endif"
block|,
literal|"            yylexp         = yylexemes + yyerrctx->lexeme;"
block|,
literal|"            yychar         = yylexp[-1];"
block|,
literal|"            yylval         = yylvp[-1];"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"            yylloc         = yylpp[-1];"
block|,
literal|"#endif"
block|,
literal|"            yystack.s_mark = yystack.s_base + (yyerrctx->yystack.s_mark - yyerrctx->yystack.s_base);"
block|,
literal|"            memcpy (yystack.s_base, yyerrctx->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));"
block|,
literal|"            yystack.l_mark = yystack.l_base + (yyerrctx->yystack.l_mark - yyerrctx->yystack.l_base);"
block|,
literal|"            memcpy (yystack.l_base, yyerrctx->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"            yystack.p_mark = yystack.p_base + (yyerrctx->yystack.p_mark - yyerrctx->yystack.p_base);"
block|,
literal|"            memcpy (yystack.p_base, yyerrctx->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));"
block|,
literal|"#endif"
block|,
literal|"            yystate        = yyerrctx->state;"
block|,
literal|"            yyFreeState(yyerrctx);"
block|,
literal|"            yyerrctx       = NULL;"
block|,
literal|"        }"
block|,
literal|"        yynewerrflag = 1;"
block|,
literal|"    }"
block|,
literal|"    if (yynewerrflag == 0) goto yyinrecovery;"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|""
block|,
literal|"    YYERROR_CALL(\"syntax error\");"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    yyerror_loc_range[0] = yylloc; /* lookahead position is error start position */"
block|,
literal|"#endif"
block|,
literal|""
block|,
literal|"#if !YYBTYACC"
block|,
literal|"    goto yyerrlab; /* redundant goto avoids 'unused label' warning */"
block|,
literal|"yyerrlab:"
block|,
literal|"#endif"
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
literal|"                    fprintf(stderr, \"%s[%d]: state %d, error recovery shifting to state %d\\n\","
block|,
literal|"                                    YYDEBUGSTR, yydepth, *yystack.s_mark, yytable[yyn]);"
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
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                /* lookahead position is error end position */"
block|,
literal|"                yyerror_loc_range[1] = yylloc;"
block|,
literal|"                YYLLOC_DEFAULT(yyloc, yyerror_loc_range, 2); /* position of error span */"
block|,
literal|"                *++yystack.p_mark = yyloc;"
block|,
literal|"#endif"
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
literal|"                    fprintf(stderr, \"%s[%d]: error recovery discarding state %d\\n\","
block|,
literal|"                                    YYDEBUGSTR, yydepth, *yystack.s_mark);"
block|,
literal|"#endif"
block|,
literal|"                if (yystack.s_mark<= yystack.s_base) goto yyabort;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                /* the current TOS position is the error start position */"
block|,
literal|"                yyerror_loc_range[0] = *yystack.p_mark;"
block|,
literal|"#endif"
block|,
literal|"#if defined(YYDESTRUCT_CALL)"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"                if (!yytrial)"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                    YYDESTRUCT_CALL(\"error: discarding state\","
block|,
literal|"                                    yystos[*yystack.s_mark], yystack.l_mark, yystack.p_mark);"
block|,
literal|"#else"
block|,
literal|"                    YYDESTRUCT_CALL(\"error: discarding state\","
block|,
literal|"                                    yystos[*yystack.s_mark], yystack.l_mark);"
block|,
literal|"#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */"
block|,
literal|"#endif /* defined(YYDESTRUCT_CALL) */"
block|,
literal|"                --yystack.s_mark;"
block|,
literal|"                --yystack.l_mark;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                --yystack.p_mark;"
block|,
literal|"#endif"
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
literal|"            fprintf(stderr, \"%s[%d]: state %d, error recovery discarding token %d (%s)\\n\","
block|,
literal|"                            YYDEBUGSTR, yydepth, yystate, yychar, yys);"
block|,
literal|"        }"
block|,
literal|"#endif"
block|,
literal|"#if defined(YYDESTRUCT_CALL)"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"        if (!yytrial)"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"            YYDESTRUCT_CALL(\"error: discarding token\", yychar,&yylval,&yylloc);"
block|,
literal|"#else"
block|,
literal|"            YYDESTRUCT_CALL(\"error: discarding token\", yychar,&yylval);"
block|,
literal|"#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */"
block|,
literal|"#endif /* defined(YYDESTRUCT_CALL) */"
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
literal|"    yym = yylen[yyn];"
block|,
literal|"#if YYDEBUG"
block|,
literal|"    if (yydebug)"
block|,
literal|"    {"
block|,
literal|"        fprintf(stderr, \"%s[%d]: state %d, reducing by rule %d (%s)\","
block|,
literal|"                        YYDEBUGSTR, yydepth, yystate, yyn, yyrule[yyn]);"
block|,
literal|"#ifdef YYSTYPE_TOSTRING"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"        if (!yytrial)"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"            if (yym> 0)"
block|,
literal|"            {"
block|,
literal|"                int i;"
block|,
literal|"                fputc('<', stderr);"
block|,
literal|"                for (i = yym; i> 0; i--)"
block|,
literal|"                {"
block|,
literal|"                    if (i != yym) fputs(\", \", stderr);"
block|,
literal|"                    fputs(YYSTYPE_TOSTRING(yystos[yystack.s_mark[1-i]],"
block|,
literal|"                                           yystack.l_mark[1-i]), stderr);"
block|,
literal|"                }"
block|,
literal|"                fputc('>', stderr);"
block|,
literal|"            }"
block|,
literal|"#endif"
block|,
literal|"        fputc('\\n', stderr);"
block|,
literal|"    }"
block|,
literal|"#endif"
block|,
literal|"    if (yym> 0)"
block|,
literal|"        yyval = yystack.l_mark[1-yym];"
block|,
literal|"    else"
block|,
literal|"        memset(&yyval, 0, sizeof yyval);"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|""
block|,
literal|"    /* Perform position reduction */"
block|,
literal|"    memset(&yyloc, 0, sizeof(yyloc));"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"    if (!yytrial)"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"    {"
block|,
literal|"        YYLLOC_DEFAULT(yyloc,&yystack.p_mark[1-yym], yym);"
block|,
literal|"        /* just in case YYERROR is invoked within the action, save"
block|,
literal|"           the start of the rhs as the error start position */"
block|,
literal|"        yyerror_loc_range[0] = yystack.p_mark[1-yym];"
block|,
literal|"    }"
block|,
literal|"#endif"
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
literal|"    default:"
block|,
literal|"        break;"
block|,
literal|"    }"
block|,
literal|"    yystack.s_mark -= yym;"
block|,
literal|"    yystate = *yystack.s_mark;"
block|,
literal|"    yystack.l_mark -= yym;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    yystack.p_mark -= yym;"
block|,
literal|"#endif"
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
literal|"        {"
block|,
literal|"            fprintf(stderr, \"%s[%d]: after reduction, \", YYDEBUGSTR, yydepth);"
block|,
literal|"#ifdef YYSTYPE_TOSTRING"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"            if (!yytrial)"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"                fprintf(stderr, \"result is<%s>, \", YYSTYPE_TOSTRING(yystos[YYFINAL], yyval));"
block|,
literal|"#endif"
block|,
literal|"            fprintf(stderr, \"shifting from state 0 to final state %d\\n\", YYFINAL);"
block|,
literal|"        }"
block|,
literal|"#endif"
block|,
literal|"        yystate = YYFINAL;"
block|,
literal|"        *++yystack.s_mark = YYFINAL;"
block|,
literal|"        *++yystack.l_mark = yyval;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"        *++yystack.p_mark = yyloc;"
block|,
literal|"#endif"
block|,
literal|"        if (yychar< 0)"
block|,
literal|"        {"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"            do {"
block|,
literal|"            if (yylvp< yylve)"
block|,
literal|"            {"
block|,
literal|"                /* we're currently re-reading tokens */"
block|,
literal|"                yylval = *yylvp++;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                yylloc = *yylpp++;"
block|,
literal|"#endif"
block|,
literal|"                yychar = *yylexp++;"
block|,
literal|"                break;"
block|,
literal|"            }"
block|,
literal|"            if (yyps->save)"
block|,
literal|"            {"
block|,
literal|"                /* in trial mode; save scanner results for future parse attempts */"
block|,
literal|"                if (yylvp == yylvlim)"
block|,
literal|"                {   /* Enlarge lexical value queue */"
block|,
literal|"                    size_t p = (size_t) (yylvp - yylvals);"
block|,
literal|"                    size_t s = (size_t) (yylvlim - yylvals);"
block|,
literal|""
block|,
literal|"                    s += YYLVQUEUEGROWTH;"
block|,
literal|"                    if ((yylexemes = realloc(yylexemes, s * sizeof(YYINT))) == NULL)"
block|,
literal|"                        goto yyenomem;"
block|,
literal|"                    if ((yylvals   = realloc(yylvals, s * sizeof(YYSTYPE))) == NULL)"
block|,
literal|"                        goto yyenomem;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                    if ((yylpsns   = realloc(yylpsns, s * sizeof(YYLTYPE))) == NULL)"
block|,
literal|"                        goto yyenomem;"
block|,
literal|"#endif"
block|,
literal|"                    yylvp   = yylve = yylvals + p;"
block|,
literal|"                    yylvlim = yylvals + s;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                    yylpp   = yylpe = yylpsns + p;"
block|,
literal|"                    yylplim = yylpsns + s;"
block|,
literal|"#endif"
block|,
literal|"                    yylexp  = yylexemes + p;"
block|,
literal|"                }"
block|,
literal|"                *yylexp = (YYINT) YYLEX;"
block|,
literal|"                *yylvp++ = yylval;"
block|,
literal|"                yylve++;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"                *yylpp++ = yylloc;"
block|,
literal|"                yylpe++;"
block|,
literal|"#endif"
block|,
literal|"                yychar = *yylexp++;"
block|,
literal|"                break;"
block|,
literal|"            }"
block|,
literal|"            /* normal operation, no conflict encountered */"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"            yychar = YYLEX;"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"            } while (0);"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
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
literal|"                fprintf(stderr, \"%s[%d]: state %d, reading token %d (%s)\\n\","
block|,
literal|"                                YYDEBUGSTR, yydepth, YYFINAL, yychar, yys);"
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
literal|"    {"
block|,
literal|"        fprintf(stderr, \"%s[%d]: after reduction, \", YYDEBUGSTR, yydepth);"
block|,
literal|"#ifdef YYSTYPE_TOSTRING"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"        if (!yytrial)"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"            fprintf(stderr, \"result is<%s>, \", YYSTYPE_TOSTRING(yystos[yystate], yyval));"
block|,
literal|"#endif"
block|,
literal|"        fprintf(stderr, \"shifting from state %d to state %d\\n\", *yystack.s_mark, yystate);"
block|,
literal|"    }"
block|,
literal|"#endif"
block|,
literal|"    if (yystack.s_mark>= yystack.s_last&& yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;"
block|,
literal|"    *++yystack.s_mark = (YYINT) yystate;"
block|,
literal|"    *++yystack.l_mark = yyval;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    *++yystack.p_mark = yyloc;"
block|,
literal|"#endif"
block|,
literal|"    goto yyloop;"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|""
block|,
literal|"    /* Reduction declares that this path is valid. Set yypath and do a full parse */"
block|,
literal|"yyvalid:"
block|,
literal|"    if (yypath) YYABORT;"
block|,
literal|"    while (yyps->save)"
block|,
literal|"    {"
block|,
literal|"        YYParseState *save = yyps->save;"
block|,
literal|"        yyps->save = save->save;"
block|,
literal|"        save->save = yypath;"
block|,
literal|"        yypath = save;"
block|,
literal|"    }"
block|,
literal|"#if YYDEBUG"
block|,
literal|"    if (yydebug)"
block|,
literal|"        fprintf(stderr, \"%s[%d]: state %d, CONFLICT trial successful, backtracking to state %d, %d tokens\\n\","
block|,
literal|"                        YYDEBUGSTR, yydepth, yystate, yypath->state, (int)(yylvp - yylvals - yypath->lexeme));"
block|,
literal|"#endif"
block|,
literal|"    if (yyerrctx)"
block|,
literal|"    {"
block|,
literal|"        yyFreeState(yyerrctx);"
block|,
literal|"        yyerrctx = NULL;"
block|,
literal|"    }"
block|,
literal|"    yylvp          = yylvals + yypath->lexeme;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    yylpp          = yylpsns + yypath->lexeme;"
block|,
literal|"#endif"
block|,
literal|"    yylexp         = yylexemes + yypath->lexeme;"
block|,
literal|"    yychar         = YYEMPTY;"
block|,
literal|"    yystack.s_mark = yystack.s_base + (yypath->yystack.s_mark - yypath->yystack.s_base);"
block|,
literal|"    memcpy (yystack.s_base, yypath->yystack.s_base, (size_t) (yystack.s_mark - yystack.s_base + 1) * sizeof(YYINT));"
block|,
literal|"    yystack.l_mark = yystack.l_base + (yypath->yystack.l_mark - yypath->yystack.l_base);"
block|,
literal|"    memcpy (yystack.l_base, yypath->yystack.l_base, (size_t) (yystack.l_mark - yystack.l_base + 1) * sizeof(YYSTYPE));"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"    yystack.p_mark = yystack.p_base + (yypath->yystack.p_mark - yypath->yystack.p_base);"
block|,
literal|"    memcpy (yystack.p_base, yypath->yystack.p_base, (size_t) (yystack.p_mark - yystack.p_base + 1) * sizeof(YYLTYPE));"
block|,
literal|"#endif"
block|,
literal|"    yystate        = yypath->state;"
block|,
literal|"    goto yyloop;"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|""
block|,
literal|"yyoverflow:"
block|,
literal|"    YYERROR_CALL(\"yacc stack overflow\");"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"    goto yyabort_nomem;"
block|,
literal|"yyenomem:"
block|,
literal|"    YYERROR_CALL(\"memory exhausted\");"
block|,
literal|"yyabort_nomem:"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"    yyresult = 2;"
block|,
literal|"    goto yyreturn;"
block|,
literal|""
block|,
literal|"yyabort:"
block|,
literal|"    yyresult = 1;"
block|,
literal|"    goto yyreturn;"
block|,
literal|""
block|,
literal|"yyaccept:"
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"    if (yyps->save) goto yyvalid;"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"    yyresult = 0;"
block|,
literal|""
block|,
literal|"yyreturn:"
block|,
literal|"#if defined(YYDESTRUCT_CALL)"
block|,
literal|"    if (yychar != YYEOF&& yychar != YYEMPTY)"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"        YYDESTRUCT_CALL(\"cleanup: discarding token\", yychar,&yylval,&yylloc);"
block|,
literal|"#else"
block|,
literal|"        YYDESTRUCT_CALL(\"cleanup: discarding token\", yychar,&yylval);"
block|,
literal|"#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */"
block|,
literal|""
block|,
literal|"    {"
block|,
literal|"        YYSTYPE *pv;"
block|,
literal|"#if defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED)"
block|,
literal|"        YYLTYPE *pp;"
block|,
literal|""
block|,
literal|"        for (pv = yystack.l_base, pp = yystack.p_base; pv<= yystack.l_mark; ++pv, ++pp)"
block|,
literal|"             YYDESTRUCT_CALL(\"cleanup: discarding state\","
block|,
literal|"                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv, pp);"
block|,
literal|"#else"
block|,
literal|"        for (pv = yystack.l_base; pv<= yystack.l_mark; ++pv)"
block|,
literal|"             YYDESTRUCT_CALL(\"cleanup: discarding state\","
block|,
literal|"                             yystos[*(yystack.s_base + (pv - yystack.l_base))], pv);"
block|,
literal|"#endif /* defined(YYLTYPE) || defined(YYLTYPE_IS_DECLARED) */"
block|,
literal|"    }"
block|,
literal|"#endif /* defined(YYDESTRUCT_CALL) */"
block|,
literal|""
block|,
if|#
directive|if
name|defined
argument_list|(
name|YYBTYACC
argument_list|)
literal|"#if YYBTYACC"
block|,
literal|"    if (yyerrctx)"
block|,
literal|"    {"
block|,
literal|"        yyFreeState(yyerrctx);"
block|,
literal|"        yyerrctx = NULL;"
block|,
literal|"    }"
block|,
literal|"    while (yyps)"
block|,
literal|"    {"
block|,
literal|"        YYParseState *save = yyps;"
block|,
literal|"        yyps = save->save;"
block|,
literal|"        save->save = NULL;"
block|,
literal|"        yyFreeState(save);"
block|,
literal|"    }"
block|,
literal|"    while (yypath)"
block|,
literal|"    {"
block|,
literal|"        YYParseState *save = yypath;"
block|,
literal|"        yypath = save->save;"
block|,
literal|"        save->save = NULL;"
block|,
literal|"        yyFreeState(save);"
block|,
literal|"    }"
block|,
literal|"#endif /* YYBTYACC */"
block|,
endif|#
directive|endif
comment|/* defined(YYBTYACC) */
literal|"    yyfreestack(&yystack);"
block|,
literal|"    return (yyresult);"
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

