begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple x86_64-apple-darwin9
end_comment

begin_comment
comment|// rdar://6726818
end_comment

begin_function
name|void
name|f1
parameter_list|()
block|{
specifier|const
name|__builtin_va_list
name|args2
decl_stmt|;
operator|(
name|void
operator|)
name|__builtin_va_arg
argument_list|(
name|args2
argument_list|,
name|int
argument_list|)
expr_stmt|;
comment|// expected-error {{first argument to 'va_arg' is of type '__builtin_va_list const' and not 'va_list'}}
block|}
end_function

end_unit

