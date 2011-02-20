begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|// rdar: //6734520
end_comment

begin_function_decl
name|int
name|foo
parameter_list|(
name|int
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__unavailable__
parameter_list|(
function_decl|"USE IFOO INSTEAD"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{function has been explicitly marked unavailable here}}
end_comment

begin_function_decl
name|double
name|dfoo
parameter_list|(
name|double
parameter_list|)
function_decl|__attribute__
parameter_list|(
function_decl|(__unavailable__
parameter_list|(
function_decl|"NO LONGER"
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note 2 {{function has been explicitly marked unavailable here}}
end_comment

begin_function_decl
name|void
name|bar
parameter_list|()
function_decl|__attribute__
parameter_list|(
function_decl|(__unavailable__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-note {{explicitly marked unavailable}}
end_comment

begin_function
name|void
name|test_foo
parameter_list|()
block|{
name|int
name|ir
init|=
name|foo
argument_list|(
literal|1
argument_list|)
decl_stmt|;
comment|// expected-error {{'foo' is unavailable: USE IFOO INSTEAD}}
name|double
name|dr
init|=
name|dfoo
argument_list|(
literal|1.0
argument_list|)
decl_stmt|;
comment|// expected-error {{'dfoo' is unavailable: NO LONGER}}
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|()
init|=
operator|&
name|bar
function_decl|;
comment|// expected-error {{'bar' is unavailable}}
name|double
function_decl|(
modifier|*
name|fp4
function_decl|)
parameter_list|(
name|double
parameter_list|)
init|=
name|dfoo
function_decl|;
comment|// expected-error {{'dfoo' is unavailable: NO LONGER}}
block|}
end_function

begin_decl_stmt
name|char
name|test2
index|[
name|__has_feature
argument_list|(
name|attribute_unavailable_with_message
argument_list|)
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

end_unit

