begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
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
literal|"@(#)header.c	4.1 (Berkeley) 8/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ldefs.c"
end_include

begin_macro
name|phead1
argument_list|()
end_macro

begin_block
block|{
name|ratfor
condition|?
name|rhd1
argument_list|()
else|:
name|chd1
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|chd1
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# include \"stdio.h\"\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|ZCH
operator|>
name|NCH
condition|)
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define U(x) ((x)&0377)\n"
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define U(x) x\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define NLSTATE yyprevious=YYNEWLINE\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define BEGIN yybgin = yysvec + 1 +\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define INITIAL 0\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define YYLERR yysvec\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define YYSTATE (yyestate-yysvec-1)\n"
argument_list|)
expr_stmt|;
if|if
condition|(
name|optim
condition|)
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define YYOPTIM 1\n"
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define LEXDEBUG 1\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define YYLMAX 200\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define output(c) putc(c,yyout)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"%s%d%s\n"
argument_list|,
literal|"# define input() (((yytchar=yysptr>yysbuf?U(*--yysptr):getc(yyin))=="
argument_list|,
name|ctable
index|[
literal|'\n'
index|]
argument_list|,
literal|"?(yylineno++,yytchar):yytchar)==EOF?0:yytchar)"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define unput(c) {yytchar= (c);if(yytchar=='\\n')yylineno--;*yysptr++=yytchar;}\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define yymore() (yymorfg=1)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define ECHO fprintf(yyout, \"%%s\",yytext)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"# define REJECT { nstr = yyreject(); goto yyfussy;}\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"int yyleng; extern char yytext[];\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"int yymorfg;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"extern char *yysptr, yysbuf[];\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"int yytchar;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"FILE *yyin ={stdin}, *yyout ={stdout};\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"extern int yylineno;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"struct yysvf { \n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\tstruct yywork *yystoff;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\tstruct yysvf *yyother;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\tint *yystops;};\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"struct yysvf *yyestate;\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"extern struct yysvf yysvec[], *yybgin;\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|rhd1
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"integer function yylex(dummy)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"define YYLMAX 200\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"define ECHO call yyecho(yytext,yyleng)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"define REJECT nstr = yyrjct(yytext,yyleng);goto 30998\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"integer nstr,yylook,yywrap\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"integer yyleng, yytext(YYLMAX)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"common /yyxel/ yyleng, yytext\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"common /yyldat/ yyfnd, yymorf, yyprev, yybgin, yylsp, yylsta\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"integer yyfnd, yymorf, yyprev, yybgin, yylsp, yylsta(YYLMAX)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"for(;;){\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\t30999 nstr = yylook(dummy)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\tgoto 30998\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\t30000 k = yywrap(dummy)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\tif(k .ne. 0){\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\tyylex=0; return; }\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\t\telse goto 30998\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|phead2
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|ratfor
condition|)
name|chd2
argument_list|()
expr_stmt|;
block|}
end_block

begin_macro
name|chd2
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"while((nstr = yylook())>= 0)\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"yyfussy: switch(nstr){\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"case 0:\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"if(yywrap()) return(0); break;\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|ptail
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|pflag
condition|)
name|ratfor
condition|?
name|rtail
argument_list|()
else|:
name|ctail
argument_list|()
expr_stmt|;
name|pflag
operator|=
literal|1
expr_stmt|;
block|}
end_block

begin_macro
name|ctail
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"case -1:\nbreak;\n"
argument_list|)
expr_stmt|;
comment|/* for reject */
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"default:\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"fprintf(yyout,\"bad switch yylook %%d\",nstr);\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"} return(0); }\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"/* end of yylex */\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|rtail
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"\n30998 if(nstr .lt. 0 .or. nstr .gt. %d)goto 30999\n"
argument_list|,
name|casecount
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"nstr = nstr + 1\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"goto(\n"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|casecount
condition|;
name|i
operator|++
control|)
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"%d,\n"
argument_list|,
literal|30000
operator|+
name|i
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"30999),nstr\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"30997 continue\n"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|fout
argument_list|,
literal|"}\nend\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|statistics
argument_list|()
end_macro

begin_block
block|{
name|fprintf
argument_list|(
name|errorf
argument_list|,
literal|"%d/%d nodes(%%e), %d/%d positions(%%p), %d/%d (%%n), %ld transitions\n"
argument_list|,
name|tptr
argument_list|,
name|treesize
argument_list|,
name|nxtpos
operator|-
name|positions
argument_list|,
name|maxpos
argument_list|,
name|stnum
operator|+
literal|1
argument_list|,
name|nstates
argument_list|,
name|rcount
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|errorf
argument_list|,
literal|", %d/%d packed char classes(%%k)"
argument_list|,
name|pcptr
operator|-
name|pchar
argument_list|,
name|pchlen
argument_list|)
expr_stmt|;
if|if
condition|(
name|optim
condition|)
name|fprintf
argument_list|(
name|errorf
argument_list|,
literal|", %d/%d packed transitions(%%a)"
argument_list|,
name|nptr
argument_list|,
name|ntrans
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|errorf
argument_list|,
literal|", %d/%d output slots(%%o)"
argument_list|,
name|yytop
argument_list|,
name|outsize
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\n'
argument_list|,
name|errorf
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

