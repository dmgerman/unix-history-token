begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  *	This routine implements a printf on the standard screen.  */
end_comment

begin_macro
name|printw
argument_list|(
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|_sprintw
argument_list|(
name|stdscr
argument_list|,
name|fmt
argument_list|,
operator|&
name|args
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine implements a printf on the given window.  */
end_comment

begin_macro
name|wprintw
argument_list|(
argument|win
argument_list|,
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
name|_sprintw
argument_list|(
name|win
argument_list|,
name|fmt
argument_list|,
operator|&
name|args
argument_list|)
return|;
block|}
end_block

begin_comment
comment|/*  *	This routine actually executes the printf and adds it to the window  */
end_comment

begin_macro
name|_sprintw
argument_list|(
argument|win
argument_list|,
argument|fmt
argument_list|,
argument|args
argument_list|)
end_macro

begin_decl_stmt
name|WINDOW
modifier|*
name|win
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|fmt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|args
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|FILE
name|junk
decl_stmt|;
name|char
name|buf
index|[
literal|512
index|]
decl_stmt|;
name|junk
operator|.
name|_flag
operator|=
name|_IOWRT
operator|+
name|_IOSTRG
expr_stmt|;
name|junk
operator|.
name|_ptr
operator|=
name|buf
expr_stmt|;
name|junk
operator|.
name|_cnt
operator|=
literal|32767
expr_stmt|;
name|_doprnt
argument_list|(
name|fmt
argument_list|,
name|args
argument_list|,
operator|&
name|junk
argument_list|)
expr_stmt|;
name|putc
argument_list|(
literal|'\0'
argument_list|,
operator|&
name|junk
argument_list|)
expr_stmt|;
return|return
name|waddstr
argument_list|(
name|win
argument_list|,
name|buf
argument_list|)
return|;
block|}
end_block

end_unit

