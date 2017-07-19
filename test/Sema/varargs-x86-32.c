begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -triple i386-apple-darwin9
end_comment

begin_function
name|void
name|foo
parameter_list|(
name|int
name|a
parameter_list|,
modifier|...
parameter_list|)
block|{
name|__builtin_ms_va_start
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|0
argument_list|,
name|a
argument_list|)
expr_stmt|;
comment|// expected-error {{this builtin is only available on x86-64 and aarch64 targets}}
block|}
end_function

end_unit

