begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"sendmail.h"
end_include

begin_expr_stmt
name|SCCSID
argument_list|(
argument|@
operator|(
operator|#
operator|)
name|clock
operator|.
name|c
literal|3.2
operator|%
name|G
operator|%
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* **  TICK -- take a clock tick ** **	Someday this will have to do more complex event scheduling. ** **	Parameters: **		none. ** **	Returns: **		non-local through TickFrame. ** **	Side Effects: **		none. */
end_comment

begin_macro
name|tick
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|tTd
argument_list|(
literal|5
argument_list|,
literal|1
argument_list|)
condition|)
name|printf
argument_list|(
literal|"tick\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
endif|DEBUG
name|longjmp
argument_list|(
name|TickFrame
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

