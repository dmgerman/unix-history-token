begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc< %s -emit-llvm
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|int
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
condition|)
block|{
case|case
literal|111111111111111111111111111111111111111
case|:
name|bar
argument_list|()
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|// Mismatched type between return and function result.
end_comment

begin_function
name|int
name|test2
parameter_list|()
block|{
return|return;
block|}
end_function

begin_function
name|void
name|test3
parameter_list|()
block|{
return|return
literal|4
return|;
block|}
end_function

end_unit

