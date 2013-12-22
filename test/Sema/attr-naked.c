begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only
end_comment

begin_decl_stmt
name|int
name|a
name|__attribute__
argument_list|(
operator|(
name|naked
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{'naked' attribute only applies to functions}}
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(naked)
argument_list|)
end_macro

begin_function
name|int
name|t0
parameter_list|(
name|void
parameter_list|)
block|{
asm|__asm__
specifier|volatile
asm|("mov r0, #0");
block|}
end_function

begin_function_decl
name|void
name|t1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(naked
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|t2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(naked
parameter_list|(
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'naked' attribute takes no arguments}}
end_comment

end_unit

