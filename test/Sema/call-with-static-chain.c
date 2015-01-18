begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fblocks -verify %s
end_comment

begin_function_decl
name|void
name|f
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|g
parameter_list|()
block|{
name|__builtin_call_with_static_chain
argument_list|(
name|f
argument_list|()
argument_list|,
name|f
argument_list|)
expr_stmt|;
name|__builtin_call_with_static_chain
argument_list|(
name|f
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// expected-error {{first argument to __builtin_call_with_static_chain must be a non-member call expression}}
name|__builtin_call_with_static_chain
argument_list|(
lambda|^
block|{}
argument_list|()
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// expected-error {{first argument to __builtin_call_with_static_chain must not be a block call}}
name|__builtin_call_with_static_chain
argument_list|(
name|__builtin_unreachable
argument_list|()
argument_list|,
name|f
argument_list|)
expr_stmt|;
comment|// expected-error {{first argument to __builtin_call_with_static_chain must not be a builtin call}}
name|__builtin_call_with_static_chain
argument_list|(
name|f
argument_list|()
argument_list|,
literal|42
argument_list|)
expr_stmt|;
comment|// expected-error {{second argument to __builtin_call_with_static_chain must be of pointer type}}
block|}
end_function

end_unit

