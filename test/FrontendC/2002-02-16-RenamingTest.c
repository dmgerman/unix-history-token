begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_comment
comment|/* test that locals are renamed with . notation */
end_comment

begin_function_decl
name|void
name|abc
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|Test5
parameter_list|(
name|double
name|X
parameter_list|)
block|{
name|abc
argument_list|(
operator|&
name|X
argument_list|)
expr_stmt|;
block|{
name|int
name|X
decl_stmt|;
name|abc
argument_list|(
operator|&
name|X
argument_list|)
expr_stmt|;
block|{
name|float
name|X
decl_stmt|;
name|abc
argument_list|(
operator|&
name|X
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

