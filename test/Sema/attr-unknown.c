begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -Wattributes %s
end_comment

begin_decl_stmt
name|int
name|x
name|__attribute__
argument_list|(
operator|(
name|foobar
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{unknown attribute 'foobar' ignored}}
end_comment

begin_function_decl
name|void
name|z
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(bogusattr
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{unknown attribute 'bogusattr' ignored}}
end_comment

end_unit

