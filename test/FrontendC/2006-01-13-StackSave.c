begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// PR691
end_comment

begin_comment
comment|// RUN: %llvmgcc %s -S -o - | opt -std-compile-opts | \
end_comment

begin_comment
comment|// RUN:    llvm-dis | grep llvm.stacksave
end_comment

begin_function
name|void
name|test
parameter_list|(
name|int
name|N
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|N
condition|;
operator|++
name|i
control|)
block|{
name|int
name|VLA
index|[
name|i
index|]
decl_stmt|;
name|external
argument_list|(
name|VLA
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

