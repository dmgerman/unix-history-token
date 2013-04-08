begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -std=gnu89 -pedantic -fsyntax-only -verify
end_comment

begin_function_decl
name|int
name|f
parameter_list|(
name|int
specifier|restrict
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|main
parameter_list|()
block|{}
end_function

begin_comment
comment|// expected-warning {{return type of 'main' is not 'int'}} expected-note {{change return type to 'int'}}
end_comment

end_unit

