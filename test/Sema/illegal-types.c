begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -std=c++98 %s
end_comment

begin_decl_stmt
name|void
name|a
argument_list|(
name|void
index|[]
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'type name' declared as array of functions}}
end_comment

begin_decl_stmt
name|void
name|b
argument_list|(
name|void
name|p
index|[]
operator|(
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'p' declared as array of functions}}
end_comment

begin_function_decl
name|void
name|c
parameter_list|(
name|int
modifier|&
type|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'type name' declared as array of references}}
end_comment

begin_function_decl
name|void
name|d
parameter_list|(
name|int
modifier|&
name|p
index|[]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error{{'p' declared as array of references}}
end_comment

end_unit

