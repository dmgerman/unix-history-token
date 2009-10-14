begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -S -g -o %t.s %s
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|i
init|=
literal|0
decl_stmt|;
name|i
operator|=
literal|42
expr_stmt|;
block|}
end_function

end_unit

