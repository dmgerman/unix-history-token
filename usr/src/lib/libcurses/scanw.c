begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"curses.ext"
end_include

begin_comment
comment|/*  *	This routine implements a scanf on the standard screen.  */
end_comment

begin_macro
name|scanw
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
name|_sscans
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
comment|/*  *	This routine implements a scanf on the given window.  */
end_comment

begin_macro
name|wscanw
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
name|_sscans
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
comment|/*  *	This routine actually executes the scanf from the window.  */
end_comment

begin_macro
name|_sscans
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
name|char
name|buf
index|[
literal|100
index|]
decl_stmt|;
name|FILE
name|junk
decl_stmt|;
name|junk
operator|.
name|_flag
operator|=
name|_IOREAD
operator||
name|_IOSTRG
expr_stmt|;
name|junk
operator|.
name|_base
operator|=
name|junk
operator|.
name|_ptr
operator|=
name|buf
expr_stmt|;
if|if
condition|(
name|wgetstr
argument_list|(
name|win
argument_list|,
name|buf
argument_list|)
operator|==
name|ERR
condition|)
return|return
name|ERR
return|;
name|junk
operator|.
name|_cnt
operator|=
name|strlen
argument_list|(
name|buf
argument_list|)
expr_stmt|;
return|return
name|_doscan
argument_list|(
operator|&
name|junk
argument_list|,
name|fmt
argument_list|,
name|args
argument_list|)
return|;
block|}
end_block

end_unit

