begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Benchmark "null big job" program.  */
end_comment

begin_comment
comment|/* 250 here is intended to approximate vi's text+data size */
end_comment

begin_decl_stmt
name|char
name|space
index|[
literal|1024
operator|*
literal|250
index|]
init|=
literal|"force into data segment"
decl_stmt|;
end_decl_stmt

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|char
modifier|*
name|argv
index|[]
decl_stmt|;
block|{
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

