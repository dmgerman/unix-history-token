begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	move.c	4.1	83/03/09	*/
end_comment

begin_comment
comment|/*  * move to (x, y).  Both the _pen and cursor are supposed to be moved.  * We really just remember it for later, in case we move again.  */
end_comment

begin_include
include|#
directive|include
file|"2648.h"
end_include

begin_macro
name|move
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
name|fprintf
argument_list|(
name|trace
argument_list|,
literal|"\tmove(%d, %d), "
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
endif|#
directive|endif
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

