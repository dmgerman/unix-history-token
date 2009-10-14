begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_decl_stmt
name|int
name|tcount
decl_stmt|;
end_decl_stmt

begin_function_decl
name|void
name|test
parameter_list|(
name|char
modifier|*
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|foo
parameter_list|()
block|{
name|char
name|Buf
index|[
literal|10
index|]
decl_stmt|;
name|test
argument_list|(
name|Buf
argument_list|,
literal|"n%%%d"
argument_list|,
name|tcount
operator|++
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

