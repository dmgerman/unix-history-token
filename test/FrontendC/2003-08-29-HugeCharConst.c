begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc -S %s -o - | llvm-as -o /dev/null
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|unsigned
name|char
name|int_latin1
index|[]
init|=
literal|"f\200\372b\200\343\200\340"
decl_stmt|;
block|}
end_function

end_unit

