begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o -  -fnested-functions
end_comment

begin_comment
comment|// PR1274
end_comment

begin_function
name|void
name|Bork
parameter_list|()
block|{
name|void
name|Fork
parameter_list|(
specifier|const
name|int
modifier|*
name|src
parameter_list|,
name|int
name|size
parameter_list|)
block|{
name|int
name|i
init|=
literal|1
decl_stmt|;
name|int
name|x
decl_stmt|;
while|while
condition|(
name|i
operator|<
name|size
condition|)
name|x
operator|=
name|src
index|[
name|i
index|]
expr_stmt|;
block|}
block|}
end_function

begin_function
name|void
name|foo
parameter_list|(
name|void
modifier|*
name|a
parameter_list|)
block|{
specifier|inline
name|void
name|foo_bar
parameter_list|()
block|{
name|a
operator|+=
literal|1
expr_stmt|;
block|}
block|}
end_function

end_unit

