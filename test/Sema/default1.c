begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_function_decl
name|void
name|f
parameter_list|(
name|int
name|i
init|=
literal|0
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{C does not support default arguments}}
end_comment

end_unit

