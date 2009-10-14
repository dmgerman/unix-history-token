begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -fsyntax-only %s -verify -fblocks
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
operator|^
operator|(
name|void
operator|)
name|__attribute__
argument_list|(
argument|(noreturn)
argument_list|)
block|{ }
operator|(
operator|)
expr_stmt|;
comment|// expected-error {{block declared 'noreturn' should not return}}
block|}
end_function

end_unit

