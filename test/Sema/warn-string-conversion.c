begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -verify -fsyntax-only -Wstring-conversion %s
end_comment

begin_define
define|#
directive|define
name|assert
parameter_list|(
name|EXPR
parameter_list|)
value|(void)(EXPR);
end_define

begin_comment
comment|// Expection for common assert form.
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
name|assert
argument_list|(
literal|0
operator|&&
literal|"foo"
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|"foo"
operator|&&
literal|0
argument_list|)
expr_stmt|;
name|assert
argument_list|(
literal|0
operator|||
literal|"foo"
argument_list|)
expr_stmt|;
comment|// expected-warning {{string literal}}
block|}
end_function

begin_function
name|void
name|test2
parameter_list|()
block|{
if|if
condition|(
literal|"hi"
condition|)
block|{}
comment|// expected-warning {{string literal}}
while|while
condition|(
literal|"hello"
condition|)
block|{}
comment|// expected-warning {{string literal}}
for|for
control|(
init|;
literal|"howdy"
condition|;
control|)
block|{}
comment|// expected-warning {{string literal}}
do|do
block|{ }
do|while
condition|(
literal|"hey"
condition|)
do|;
comment|// expected-warning {{string literal}}
block|}
end_function

end_unit

