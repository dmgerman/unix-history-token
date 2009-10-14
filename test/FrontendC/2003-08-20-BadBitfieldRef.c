begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|char
modifier|*
name|ap
decl_stmt|;
name|ap
index|[
literal|1
index|]
operator|==
literal|'-'
operator|&&
name|ap
index|[
literal|2
index|]
operator|==
literal|0
expr_stmt|;
block|}
end_function

end_unit

