begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_empty
empty|#
end_empty

begin_comment
comment|/*  * pi - Pascal interpreter code translator  *  * Charles Haley, Bill Joy UCB  * Version 1.0 August 1977  *  *  * pxp - Pascal execution profiler  *  * Bill Joy UCB  * Version 1.0 August 1977  */
end_comment

begin_include
include|#
directive|include
file|"whoami"
end_include

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
comment|/* 	 * Initialize the scanner 	 */
ifdef|#
directive|ifdef
name|PXP
if|if
condition|(
name|bracket
operator|==
literal|0
condition|)
block|{
endif|#
directive|endif
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
ifdef|#
directive|ifdef
name|PXP
block|}
else|else
name|yyline
operator|=
literal|0
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PI
comment|/* 	 * Magic number for Pascal 	 */
name|word
argument_list|(
literal|0404
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Initialize the clusters 	 * 	initstring(); 	 */
name|inithash
argument_list|()
expr_stmt|;
name|inittree
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|PI
name|initnl
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Process the input 	 */
name|yyparse
argument_list|()
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
ifdef|#
directive|ifdef
name|PI
name|dumpnl
argument_list|(
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|PXP
name|prttab
argument_list|()
expr_stmt|;
endif|#
directive|endif
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

end_unit

