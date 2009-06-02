begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S -o - %s | grep nounwind | count 2
end_comment

begin_comment
comment|// RUN: %llvmgcc -S -o - %s | not grep {declare.*nounwind}
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|g
parameter_list|(
name|void
parameter_list|)
block|{
name|f
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

