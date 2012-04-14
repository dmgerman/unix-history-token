begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
name|test0
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"default"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|test1
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"hidden"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_function_decl
name|void
name|test2
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"internal"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// rdar://problem/10753392
end_comment

begin_function_decl
name|void
name|test3
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(visibility
parameter_list|(
function_decl|"protected"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{target does not support 'protected' visibility; using 'default'}}
end_comment

end_unit

