begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * The purpose of this test case is to make sure that dbx interprets  * the command "stop in same" at the top level to mean stop in the  * routine same.  Originally, dbx complained since "same" in the initial  * context refers to the module named "same" (since this file is "same.c").  */
end_comment

begin_macro
name|same
argument_list|()
end_macro

begin_block
block|{
name|printf
argument_list|(
literal|"same function and module names\n"
argument_list|)
expr_stmt|;
block|}
end_block

begin_function
name|main
parameter_list|()
block|{
name|same
argument_list|()
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

