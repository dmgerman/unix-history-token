begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_union
union|union
name|X
block|{
name|void
modifier|*
name|B
decl_stmt|;
block|}
union|;
end_union

begin_function
name|union
name|X
name|foo
parameter_list|()
block|{
name|union
name|X
name|A
decl_stmt|;
name|A
operator|.
name|B
operator|=
operator|(
name|void
operator|*
operator|)
literal|123
expr_stmt|;
return|return
name|A
return|;
block|}
end_function

end_unit

