begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_struct_decl
struct_decl|struct
name|foo
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note 3 {{forward declaration of 'struct foo'}}
end_comment

begin_function_decl
name|struct
name|foo
name|a
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{'a' declared here}}
end_comment

begin_function_decl
name|void
name|b
parameter_list|(
name|struct
name|foo
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|c
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|func
parameter_list|()
block|{
name|a
argument_list|()
expr_stmt|;
comment|// expected-error{{calling 'a' with incomplete return type 'struct foo'}}
name|b
argument_list|(
operator|*
operator|(
expr|struct
name|foo
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error{{argument type 'struct foo' is incomplete}}
name|c
argument_list|(
operator|*
operator|(
expr|struct
name|foo
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error{{argument type 'struct foo' is incomplete}}
block|}
end_function

end_unit

