begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %llvmgcc %s -S -emit-llvm -o - | llc
end_comment

begin_function
name|void
name|bork
parameter_list|()
block|{
name|char
name|Qux
index|[
literal|33
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
block|}
end_function

end_unit

