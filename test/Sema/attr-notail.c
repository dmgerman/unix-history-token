begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|int
name|callee0
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(not_tail_called
operator|,
function_decl|always_inline
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'not_tail_called' and 'always_inline' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note{{conflicting attribute is here}}
end_comment

begin_function_decl
name|int
name|callee1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(always_inline
operator|,
function_decl|not_tail_called
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error{{'always_inline' and 'not_tail_called' attributes are not compatible}} \
end_comment

begin_comment
comment|// expected-note{{conflicting attribute is here}}
end_comment

begin_function
name|int
name|foo
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|a
condition|?
name|callee0
argument_list|()
else|:
name|callee1
argument_list|()
return|;
block|}
end_function

begin_decl_stmt
name|int
name|g0
name|__attribute__
argument_list|(
operator|(
name|not_tail_called
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'not_tail_called' attribute only applies to functions}}
end_comment

begin_function_decl
name|int
name|foo2
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(not_tail_called
parameter_list|(
function_decl|"abc"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'not_tail_called' attribute takes no arguments}}
end_comment

end_unit

