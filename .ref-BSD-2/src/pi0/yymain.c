begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (c) 1979 Regents of the University of California */
end_comment

begin_empty
empty|#
end_empty

begin_comment
comment|/*  * pi - Pascal interpreter code translator  *  * Charles Haley, Bill Joy UCB  * Version 1.2 January 1979  */
end_comment

begin_include
include|#
directive|include
file|"0.h"
end_include

begin_include
include|#
directive|include
file|"yy.h"
end_include

begin_expr_stmt
name|int
name|line
literal|1
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Yymain initializes each of the utility  * clusters and then starts the processing  * by calling yyparse.  */
end_comment

begin_macro
name|yymain
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|PI0
name|char
name|strings
index|[
name|STRINC
index|]
decl_stmt|;
name|int
name|trspace
index|[
name|ITREE
index|]
decl_stmt|;
name|int
name|hshtab
index|[
name|HASHINC
index|]
decl_stmt|;
comment|/* 	clear(strings, sizeof strings); 	clear(trspace, sizeof trspace); */
name|clear
argument_list|(
name|hshtab
argument_list|,
sizeof|sizeof
name|hshtab
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Initialize the scanner 	 */
if|if
condition|(
name|getline
argument_list|()
operator|==
operator|-
literal|1
condition|)
block|{
name|Perror
argument_list|(
name|filename
argument_list|,
literal|"No lines in file"
argument_list|)
expr_stmt|;
name|pexit
argument_list|(
name|NOSTART
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Initialize the clusters 	 */
ifdef|#
directive|ifdef
name|PI0
name|initstring
argument_list|(
name|strings
argument_list|)
expr_stmt|;
name|inithash
argument_list|(
name|hshtab
argument_list|)
expr_stmt|;
name|inittree
argument_list|(
name|trspace
argument_list|)
expr_stmt|;
name|send
argument_list|(
name|RINIT
argument_list|)
expr_stmt|;
else|#
directive|else
name|initstring
argument_list|()
expr_stmt|;
name|inithash
argument_list|()
expr_stmt|;
name|inittree
argument_list|()
expr_stmt|;
endif|#
directive|endif
name|initnl
argument_list|()
expr_stmt|;
comment|/* 	 * Process the input 	 */
name|yyparse
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|dumpnl
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|send
argument_list|(
name|RFINISH
argument_list|)
expr_stmt|;
name|pexit
argument_list|(
name|eflg
condition|?
name|ERRS
else|:
name|AOK
argument_list|)
expr_stmt|;
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|PI0
end_ifdef

begin_expr_stmt
name|clear
argument_list|(
name|cp
argument_list|,
name|i
argument_list|)
specifier|register
name|char
operator|*
name|cp
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|register
name|int
name|i
decl_stmt|;
end_decl_stmt

begin_block
block|{
do|do
operator|*
name|cp
operator|++
operator|=
literal|0
expr_stmt|;
do|while
condition|(
operator|--
name|i
condition|)
do|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

