begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -verify -fsyntax-only -std=c11
end_comment

begin_function_decl
name|void
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(xray_always_instrument
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_struct
struct|struct
name|__attribute__
argument_list|(
argument|(xray_always_instrument)
argument_list|)
name|a
block|{
name|int
name|x
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|// expected-warning {{'xray_always_instrument' attribute only applies to functions and methods}}
end_comment

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(xray_always_instrument
parameter_list|(
function_decl|"not-supported"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-error {{'xray_always_instrument' attribute takes no arguments}}
end_comment

end_unit

