begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Clean things up before exiting  *  * %G% (Berkeley) %W  */
end_comment

begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_macro
name|endwin
argument_list|()
end_macro

begin_block
block|{
name|resetty
argument_list|()
expr_stmt|;
name|_puts
argument_list|(
name|VE
argument_list|)
expr_stmt|;
name|_puts
argument_list|(
name|TE
argument_list|)
expr_stmt|;
if|if
condition|(
name|curscr
condition|)
block|{
if|if
condition|(
name|curscr
operator|->
name|_flags
operator|&
name|_STANDOUT
condition|)
block|{
name|_puts
argument_list|(
name|SE
argument_list|)
expr_stmt|;
name|curscr
operator|->
name|_flags
operator|&=
operator|~
name|_STANDOUT
expr_stmt|;
block|}
name|_endwin
operator|=
name|TRUE
expr_stmt|;
block|}
block|}
end_block

end_unit

