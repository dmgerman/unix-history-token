begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -emit-llvm %s -o - -fnested-functions | not grep nest
end_comment

begin_function
name|void
name|n1
parameter_list|(
name|void
parameter_list|)
block|{
name|void
name|a
parameter_list|(
name|void
parameter_list|)
block|{
name|a
argument_list|()
expr_stmt|;
block|}
name|a
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

