begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -triple=i686-pc-linux-gnu %s
end_comment

begin_function
name|int
name|a
parameter_list|()
block|{
name|__builtin_va_arg
argument_list|(
operator|(
name|char
operator|*
operator|)
literal|0
argument_list|,
name|int
argument_list|)
expr_stmt|;
comment|// expected-error {{expression is not assignable}}
name|__builtin_va_arg
argument_list|(
operator|(
name|void
operator|*
operator|)
block|{
literal|0
block|}
argument_list|,
name|int
argument_list|)
expr_stmt|;
comment|// expected-error {{first argument to 'va_arg' is of type 'void *'}}
block|}
end_function

end_unit

