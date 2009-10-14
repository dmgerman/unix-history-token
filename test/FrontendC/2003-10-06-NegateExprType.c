begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_decl_stmt
specifier|extern
name|int
name|A
index|[
literal|10
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|Func
parameter_list|(
name|int
modifier|*
name|B
parameter_list|)
block|{
name|B
operator|-
operator|&
name|A
index|[
literal|5
index|]
expr_stmt|;
block|}
end_function

end_unit

