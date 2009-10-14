begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|long
argument_list|(
operator|*
name|ap
argument_list|)
index|[
literal|4
index|]
expr_stmt|;
block|}
name|ptrs
typedef|;
end_typedef

begin_function
name|void
name|DoAssignIteration
parameter_list|()
block|{
name|ptrs
name|abase
decl_stmt|;
name|abase
operator|.
name|ap
operator|+=
literal|27
expr_stmt|;
name|Assignment
argument_list|(
operator|*
name|abase
operator|.
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

