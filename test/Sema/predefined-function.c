begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic %s
end_comment

begin_function_decl
name|char
modifier|*
name|funk
parameter_list|(
name|int
name|format
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|Test
block|{
name|A
init|=
operator|-
literal|1
block|}
enum|;
end_enum

begin_function_decl
name|char
modifier|*
name|funk
parameter_list|(
name|enum
name|Test
name|x
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|eli
parameter_list|(
name|float
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_function
name|int
name|b
parameter_list|(
name|int
name|c
parameter_list|)
block|{
return|return
literal|1
return|;
block|}
end_function

begin_function_decl
name|int
name|foo
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|foo
parameter_list|()
block|{
name|int
name|eli
argument_list|(
name|int
argument_list|(
name|int
argument_list|)
argument_list|)
decl_stmt|;
comment|// expected-error {{conflicting types for 'eli'}}
name|eli
argument_list|(
name|b
argument_list|)
expr_stmt|;
comment|// expected-error{{incompatible type passing}}
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
name|bar
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|int
name|bar
parameter_list|(
name|int
name|i
parameter_list|)
comment|// expected-note {{previous definition is here}}
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|bar
parameter_list|()
comment|// expected-error {{redefinition of 'bar'}}
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
name|foobar
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// note {{previous declaration is here}}
end_comment

begin_function
name|int
name|foobar
parameter_list|()
comment|// error {{conflicting types for 'foobar'}}
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function_decl
name|int
name|wibble
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{previous declaration is here}}
end_comment

begin_function
name|float
name|wibble
parameter_list|()
comment|// expected-error {{conflicting types for 'wibble'}}
block|{
return|return
literal|0.0f
return|;
block|}
end_function

end_unit

