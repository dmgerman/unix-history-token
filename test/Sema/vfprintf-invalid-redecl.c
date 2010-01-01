begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -fsyntax-only -verify
end_comment

begin_comment
comment|// PR4290
end_comment

begin_comment
comment|// The following declaration is not compatible with vfprintf(), but make
end_comment

begin_comment
comment|// sure this isn't an error: autoconf expects this to build.
end_comment

begin_function_decl
name|char
name|vfprintf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-warning {{incompatible redeclaration of library function 'vfprintf'}} expected-note {{'vfprintf' is a builtin}}
end_comment

end_unit

