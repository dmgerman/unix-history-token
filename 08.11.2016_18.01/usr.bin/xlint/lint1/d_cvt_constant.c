begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* the second assignment assumes failed before */
end_comment

begin_function
name|int
name|main
parameter_list|(
name|void
parameter_list|)
block|{
name|double
name|x
init|=
literal|1
decl_stmt|;
name|int
name|foo
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|foo
condition|)
name|x
operator|=
literal|1
expr_stmt|;
block|}
end_function

end_unit

