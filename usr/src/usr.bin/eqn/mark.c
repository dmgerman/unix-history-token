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
literal|"@(#)mark.c	4.2 8/11/83"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"e.h"
end_include

begin_macro
name|mark
argument_list|(
argument|p1
argument_list|)
end_macro

begin_decl_stmt
name|int
name|p1
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|markline
operator|=
literal|1
expr_stmt|;
name|printf
argument_list|(
literal|".ds %d \\k(97\\*(%d\n"
argument_list|,
name|p1
argument_list|,
name|p1
argument_list|)
expr_stmt|;
name|yyval
operator|=
name|p1
expr_stmt|;
if|if
condition|(
name|dbg
condition|)
name|printf
argument_list|(
literal|".\tmark %d\n"
argument_list|,
name|p1
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|lineup
argument_list|(
argument|p1
argument_list|)
end_macro

begin_block
block|{
name|markline
operator|=
literal|1
expr_stmt|;
if|if
condition|(
name|p1
operator|==
literal|0
condition|)
block|{
name|yyval
operator|=
name|oalloc
argument_list|()
expr_stmt|;
name|printf
argument_list|(
literal|".ds %d \\h'|\\n(97u'\n"
argument_list|,
name|yyval
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|dbg
condition|)
name|printf
argument_list|(
literal|".\tlineup %d\n"
argument_list|,
name|p1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

