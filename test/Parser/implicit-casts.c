begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only -verify -pedantic %s
end_comment

begin_decl_stmt
specifier|_Complex
name|double
name|X
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test1
parameter_list|(
name|int
name|c
parameter_list|)
block|{
name|X
operator|=
literal|5
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
name|int
name|i
decl_stmt|;
name|double
name|d
init|=
name|i
decl_stmt|;
name|double
specifier|_Complex
name|a
init|=
literal|5
decl_stmt|;
name|test1
argument_list|(
name|a
argument_list|)
expr_stmt|;
name|a
operator|=
literal|5
expr_stmt|;
name|d
operator|=
name|i
expr_stmt|;
block|}
end_function

begin_function
name|int
name|test3
parameter_list|()
block|{
name|int
name|a
index|[
literal|2
index|]
decl_stmt|;
name|a
index|[
literal|0
index|]
operator|=
name|test3
expr_stmt|;
comment|// expected-warning{{incompatible pointer to integer conversion assigning 'int ()', expected 'int'}}
block|}
end_function

begin_decl_stmt
name|short
name|x
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test4
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|x
operator|+=
name|c
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|int
name|y
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|test5
parameter_list|(
name|char
name|c
parameter_list|)
block|{
name|y
operator|+=
name|c
expr_stmt|;
block|}
end_function

end_unit

