begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	draw.c	4.1	83/03/09	*/
end_comment

begin_comment
comment|/*  * draw a line from the current place to (x,y).  Such lines are  * supposed to be horizontal, and are affected by the current mode.  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|draw
argument_list|(
argument|x
argument_list|,
argument|y
argument_list|)
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|TRACE
if|if
condition|(
name|trace
condition|)
block|{
name|fprintf
argument_list|(
name|trace
argument_list|,
literal|"draw(%d,%d)\n"
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|sync
argument_list|()
expr_stmt|;
name|escseq
argument_list|(
name|ESCP
argument_list|)
expr_stmt|;
name|motion
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
name|_supx
operator|=
name|x
expr_stmt|;
name|_supy
operator|=
name|y
expr_stmt|;
block|}
end_block

end_unit

