begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Test of displaying strings compiled into the text segment via -R.  */
end_comment

begin_decl_stmt
name|char
name|str
index|[]
init|=
literal|"this is a test"
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|()
block|{
name|f
argument_list|(
literal|"parameter test"
argument_list|)
expr_stmt|;
block|}
end_function

begin_macro
name|f
argument_list|(
argument|s
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|s
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|abort
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

