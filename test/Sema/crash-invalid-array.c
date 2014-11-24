begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-apple-darwin -fsyntax-only -verify %s
end_comment

begin_comment
comment|// PR6913
end_comment

begin_function
name|int
name|main
parameter_list|()
block|{
name|int
name|x
index|[
literal|10
index|]
index|[
literal|10
index|]
decl_stmt|;
name|int
argument_list|(
operator|*
name|p
argument_list|)
index|[]
operator|=
name|x
expr_stmt|;
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
literal|10
condition|;
operator|++
name|i
control|)
block|{
name|p
index|[
name|i
index|]
index|[
name|i
index|]
operator|=
name|i
expr_stmt|;
comment|// expected-error {{subscript of pointer to incomplete type 'int []'}}
block|}
block|}
end_function

begin_comment
comment|// rdar://13705391
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|a
index|[
operator|*
index|]
index|[
literal|2
index|]
parameter_list|)
block|{
operator|(
name|void
operator|)
name|a
index|[
literal|0
index|]
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{variable length array must be bound in function definition}}
end_comment

begin_function
name|void
name|foo1
parameter_list|(
name|int
name|a
index|[
literal|2
index|]
index|[
operator|*
index|]
parameter_list|)
block|{
operator|(
name|void
operator|)
name|a
index|[
literal|0
index|]
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{variable length array must be bound in function definition}}
end_comment

begin_function
name|void
name|foo2
parameter_list|(
name|int
name|a
index|[
operator|*
index|]
index|[
operator|*
index|]
parameter_list|)
block|{
operator|(
name|void
operator|)
name|a
index|[
literal|0
index|]
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{variable length array must be bound in function definition}}
end_comment

begin_function
name|void
name|foo3
parameter_list|(
name|int
name|a
index|[
literal|2
index|]
index|[
operator|*
index|]
index|[
literal|2
index|]
parameter_list|)
block|{
operator|(
name|void
operator|)
name|a
index|[
literal|0
index|]
index|[
literal|1
index|]
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{variable length array must be bound in function definition}}
end_comment

begin_function
name|void
name|foo4
parameter_list|(
name|int
name|a
index|[
literal|2
index|]
index|[
operator|*
index|]
index|[
operator|*
index|]
parameter_list|)
block|{
operator|(
name|void
operator|)
name|a
index|[
literal|0
index|]
index|[
literal|1
index|]
index|[
literal|1
index|]
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{variable length array must be bound in function definition}}
end_comment

end_unit

