begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  * relocate the starting position of a window  */
end_comment

begin_macro
name|mvwin
argument_list|(
argument|win
argument_list|,
argument|by
argument_list|,
argument|bx
argument_list|)
end_macro

begin_decl_stmt
name|reg
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|reg
name|int
name|by
decl_stmt|,
name|bx
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|by
operator|+
name|win
operator|->
name|_maxy
operator|>
name|LINES
operator|||
name|bx
operator|+
name|win
operator|->
name|_maxx
operator|>
name|COLS
condition|)
return|return
name|ERR
return|;
name|win
operator|->
name|_begy
operator|=
name|by
expr_stmt|;
name|win
operator|->
name|_begx
operator|=
name|bx
expr_stmt|;
name|touchwin
argument_list|(
name|win
argument_list|)
expr_stmt|;
return|return
name|OK
return|;
block|}
end_block

end_unit

