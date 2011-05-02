begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -verify
end_comment

begin_function_decl
name|char
name|memset
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{incompatible redeclaration of library function 'memset'}} expected-note{{'memset' is a builtin with type}}
end_comment

begin_function
name|char
name|test
parameter_list|()
block|{
return|return
name|memset
argument_list|()
return|;
block|}
end_function

end_unit

