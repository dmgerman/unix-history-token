begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  * idlok:  *	Turn on and off using insert/deleteln sequences for the given  *	window.  *  * @(#)idlok.c	1.1 (Berkeley) %G%  */
end_comment

begin_expr_stmt
name|idlok
argument_list|(
name|win
argument_list|,
name|bf
argument_list|)
specifier|register
name|WINDOW
operator|*
name|win
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|bool
name|bf
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|bf
condition|)
name|win
operator|->
name|_flags
operator||=
name|_IDLINE
expr_stmt|;
else|else
name|win
operator|->
name|_flags
operator|&=
operator|~
name|_IDLINE
expr_stmt|;
block|}
end_block

end_unit

