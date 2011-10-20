begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Check that -w has lower priority than -pedantic-errors.
end_comment

begin_comment
comment|// RUN: %clang_cc1 -verify -pedantic-errors -w %s
end_comment

begin_function
name|void
name|f0
parameter_list|()
block|{
name|f1
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error {{implicit declaration of function}}
end_comment

end_unit

