begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Test program for dbx call command.  */
end_comment

begin_decl_stmt
name|int
name|global
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|int
name|main_local
decl_stmt|;
name|global
operator|=
literal|2
expr_stmt|;
name|main_local
operator|=
literal|19
expr_stmt|;
name|p1
argument_list|()
expr_stmt|;
name|p2
argument_list|(
name|main_local
argument_list|)
expr_stmt|;
name|p3
argument_list|(
literal|"test"
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|p1
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"in p1\n"
argument_list|)
expr_stmt|;
name|global
operator|=
literal|4
expr_stmt|;
block|}
end_block

begin_macro
name|p2
argument_list|(
argument|from_main
argument_list|)
end_macro

begin_decl_stmt
name|int
name|from_main
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"in p2(%d)\n"
argument_list|,
name|from_main
argument_list|)
expr_stmt|;
name|global
operator|=
literal|9
expr_stmt|;
block|}
end_block

begin_macro
name|p3
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
name|s
index|[]
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|printf
argument_list|(
literal|"in p3(%s)\n"
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|global
operator|=
literal|10
expr_stmt|;
block|}
end_block

end_unit

