begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  *	This routine gets a string starting at (_cury,_curx)  */
end_comment

begin_macro
name|wgetstr
argument_list|(
argument|win
argument_list|,
argument|str
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
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_block
block|{
while|while
condition|(
operator|(
operator|*
name|str
operator|=
name|wgetch
argument_list|(
name|win
argument_list|)
operator|)
operator|!=
name|ERR
operator|&&
operator|*
name|str
operator|!=
literal|'\n'
condition|)
empty_stmt|;
name|str
operator|++
expr_stmt|;
operator|*
name|str
operator|=
literal|'\0'
expr_stmt|;
if|if
condition|(
operator|*
name|str
operator|==
name|ERR
condition|)
return|return
name|ERR
return|;
return|return
name|OK
return|;
block|}
end_block

end_unit

