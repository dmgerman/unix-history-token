begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|disable_tail_calls
operator|,
name|naked
operator|)
argument_list|)
name|foo1
argument_list|(
name|int
name|a
argument_list|)
block|{
comment|// expected-error {{'disable_tail_calls' and 'naked' attributes are not compatible}} expected-note {{conflicting attribute is here}}
asm|__asm__("");
block|}
end_decl_stmt

begin_decl_stmt
name|void
name|__attribute__
argument_list|(
operator|(
name|naked
operator|,
name|disable_tail_calls
operator|)
argument_list|)
name|foo2
argument_list|(
name|int
name|a
argument_list|)
block|{
comment|// expected-error {{'naked' and 'disable_tail_calls' attributes are not compatible}} expected-note {{conflicting attribute is here}}
asm|__asm__("");
block|}
end_decl_stmt

begin_decl_stmt
name|int
name|g0
name|__attribute__
argument_list|(
operator|(
name|disable_tail_calls
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'disable_tail_calls' attribute only applies to functions and methods}}
end_comment

begin_function_decl
name|int
name|foo3
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(disable_tail_calls
parameter_list|(
function_decl|"abc"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'disable_tail_calls' attribute takes no arguments}}
end_comment

end_unit

