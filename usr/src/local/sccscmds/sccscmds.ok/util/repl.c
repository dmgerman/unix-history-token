begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
specifier|static
name|char
name|Sccsid
index|[]
init|=
literal|"@(#)repl.c	1.2	%G%"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* 	Replace each occurrence of `old' with `new' in `str'. 	Return `str'. */
end_comment

begin_macro
name|repl
argument_list|(
argument|str
argument_list|,
argument|old
argument_list|,
argument|new
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|str
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|old
decl_stmt|,
name|new
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return
operator|(
name|trnslat
argument_list|(
name|str
argument_list|,
operator|&
name|old
argument_list|,
operator|&
name|new
argument_list|,
name|str
argument_list|)
operator|)
return|;
block|}
end_block

end_unit

