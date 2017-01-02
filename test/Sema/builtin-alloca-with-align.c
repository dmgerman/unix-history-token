begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|__builtin_alloca_with_align
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|__builtin_alloca_with_align
argument_list|(
name|a
argument_list|,
operator|-
literal|32
argument_list|)
expr_stmt|;
comment|// expected-error {{requested alignment is not a power of 2}}
block|}
end_function

begin_function
name|void
name|test3
parameter_list|(
name|unsigned
modifier|*
name|b
parameter_list|)
block|{
name|__builtin_alloca_with_align
argument_list|(
name|b
argument_list|,
literal|32
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible pointer to integer conversion passing 'unsigned int *' to parameter of type}}
block|}
end_function

begin_function
name|void
name|test4
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|__builtin_alloca_with_align
argument_list|(
name|a
argument_list|,
literal|32
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error {{too many arguments to function call, expected 2, have 3}}
block|}
end_function

begin_function
name|void
name|test5
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|__builtin_alloca_with_align
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
expr_stmt|;
comment|// expected-error {{requested alignment is not a power of 2}}
block|}
end_function

begin_function
name|void
name|test6
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|j
parameter_list|)
block|{
name|__builtin_alloca_with_align
argument_list|(
name|a
argument_list|,
name|j
argument_list|)
expr_stmt|;
comment|// expected-error {{must be a constant integer}}
block|}
end_function

begin_function
name|void
name|test7
parameter_list|(
name|int
name|a
parameter_list|)
block|{
name|__builtin_alloca_with_align
argument_list|(
name|a
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// expected-error {{requested alignment must be 8 or greater}}
block|}
end_function

begin_function
name|void
name|test8
parameter_list|()
block|{
name|__builtin_alloca_with_align
argument_list|(
sizeof|sizeof
argument_list|(
name|__INT64_TYPE__
argument_list|)
argument_list|,
name|__alignof__
argument_list|(
name|__INT64_TYPE__
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-warning {{second argument to __builtin_alloca_with_align is supposed to be in bits}}
block|}
end_function

end_unit

