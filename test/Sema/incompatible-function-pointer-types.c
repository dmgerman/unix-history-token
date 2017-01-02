begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -Wincompatible-pointer-types -verify
end_comment

begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only %s -Wincompatible-function-pointer-types -verify
end_comment

begin_comment
comment|// This test ensures that the subgroup of -Wincompatible-pointer-types warnings
end_comment

begin_comment
comment|// that concern function pointers can be promoted (or not promoted) to an error
end_comment

begin_comment
comment|// *separately* from the other -Wincompatible-pointer-type warnings.
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|MyFnTyA
function_decl|)
parameter_list|(
name|int
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_function
name|int
name|bar
parameter_list|(
name|char
modifier|*
name|a
parameter_list|,
name|int
modifier|*
name|b
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_function
name|int
name|foo
parameter_list|(
name|MyFnTyA
name|x
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|// expected-note {{passing argument to parameter 'x' here}}
end_comment

begin_function
name|void
name|baz
parameter_list|()
block|{
name|foo
argument_list|(
operator|&
name|bar
argument_list|)
expr_stmt|;
comment|// expected-warning {{incompatible function pointer types passing 'int (*)(char *, int *)' to parameter of type 'MyFnTyA' (aka 'int (*)(int *, char *)')}}
block|}
end_function

end_unit

