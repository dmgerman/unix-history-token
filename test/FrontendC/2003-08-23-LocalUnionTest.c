begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_union
union|union
name|foo
block|{
name|int
name|X
decl_stmt|;
block|}
union|;
end_union

begin_function
name|int
name|test
parameter_list|(
name|union
name|foo
modifier|*
name|F
parameter_list|)
block|{
block|{
union|union
name|foo
block|{
name|float
name|X
decl_stmt|;
block|}
name|A
union|;
block|}
block|}
end_function

end_unit

