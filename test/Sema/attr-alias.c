begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin  -fsyntax-only -verify %s
end_comment

begin_function
name|void
name|g
parameter_list|()
block|{}
end_function

begin_comment
comment|// It is important that the following string be in the error message. The gcc
end_comment

begin_comment
comment|// testsuite looks for it to decide if a target supports aliases.
end_comment

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(alias
parameter_list|(
function_decl|"g"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|//expected-error {{only weak aliases are supported}}
end_comment

end_unit

