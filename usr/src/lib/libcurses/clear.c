begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  *	This routine clears the window.  *  * @(#)clear.c	1.2 (Berkeley) %G%  */
end_comment

begin_macro
name|wclear
argument_list|(
argument|win
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|werase
argument_list|(
name|win
argument_list|)
expr_stmt|;
name|win
operator|->
name|_clear
operator|=
name|TRUE
expr_stmt|;
return|return
name|OK
return|;
block|}
end_block

end_unit

