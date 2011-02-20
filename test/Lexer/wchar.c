begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fshort-wchar -verify %s
end_comment

begin_function
name|void
name|f
parameter_list|()
block|{
operator|(
name|void
operator|)
literal|L"\U00010000"
expr_stmt|;
comment|// expected-warning {{character unicode escape sequence too long for its type}}
operator|(
name|void
operator|)
literal|L'
expr|\U00010000'
expr_stmt|;
comment|// expected-warning {{character unicode escape sequence too long for its type}}
operator|(
name|void
operator|)
literal|L'
expr|ab'
expr_stmt|;
comment|// expected-warning {{extraneous characters in wide character constant ignored}}
operator|(
name|void
operator|)
literal|L'
expr|a\u1000'
expr_stmt|;
comment|// expected-warning {{extraneous characters in wide character constant ignored}}
block|}
end_function

end_unit

