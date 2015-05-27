begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple=x86_64-apple-darwin -fsyntax-only -verify %s
end_comment

begin_comment
comment|// PR23086
end_comment

begin_expr_stmt
name|__builtin_isinf
argument_list|(
operator|...
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}} expected-error {{ISO C requires a named parameter before '...'}} // expected-error {{conflicting types for '__builtin_isinf'}} // expected-note {{'__builtin_isinf' is a builtin with type 'int ()'}}
end_comment

end_unit

