begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify %s
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
name|x
comment|// expected-warning {{extra tokens at end of #pragma clang __debug captured directive}}
block|{   }
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
pragma|#
directive|pragma
name|clang
name|__debug
name|captured
name|int
name|x
decl_stmt|;
comment|// expected-error {{expected '{'}}
block|}
end_function

end_unit

