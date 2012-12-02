begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__minsize__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|int
name|var1
name|__attribute__
argument_list|(
operator|(
name|__minsize__
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'__minsize__' attribute only applies to functions and methods}}
end_comment

end_unit

