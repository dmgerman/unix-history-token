begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  *	This routine adds a string starting at (_cury,_curx)  */
end_comment

begin_macro
name|waddstr
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
ifdef|#
directive|ifdef
name|DEBUG
name|fprintf
argument_list|(
name|outf
argument_list|,
literal|"WADDSTR(\"%s\")\n"
argument_list|,
name|str
argument_list|)
expr_stmt|;
endif|#
directive|endif
while|while
condition|(
operator|*
name|str
condition|)
if|if
condition|(
name|waddch
argument_list|(
name|win
argument_list|,
operator|*
name|str
operator|++
argument_list|)
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

