begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file contains typo correction tests which hit different code paths in C
end_comment

begin_comment
comment|// than in C++ and may exhibit different behavior as a result.
end_comment

begin_macro
name|__typeof__
argument_list|(
argument|struct F*
argument_list|)
end_macro

begin_expr_stmt
name|var
index|[
name|invalid
index|]
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-error-re {{use of undeclared identifier 'invalid'{{$}}}}
end_comment

begin_function
name|void
name|PR21656
parameter_list|()
block|{
name|float
name|x
decl_stmt|;
name|x
operator|=
operator|(
name|float
operator|)
name|arst
expr_stmt|;
comment|// expected-error-re {{use of undeclared identifier 'arst'{{$}}}}
block|}
end_function

begin_expr_stmt
name|a
operator|=
name|b
condition|?
else|:
literal|0
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}} \
end_comment

begin_comment
comment|// expected-error {{use of undeclared identifier 'b'}}
end_comment

begin_decl_stmt
name|int
name|foobar
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-note {{'foobar' declared here}}
end_comment

begin_expr_stmt
name|a
operator|=
name|goobar
condition|?
else|:
literal|4
expr_stmt|;
end_expr_stmt

begin_comment
comment|// expected-warning {{type specifier missing, defaults to 'int'}} \
end_comment

begin_comment
comment|// expected-error {{use of undeclared identifier 'goobar'; did you mean 'foobar'?}} \
end_comment

begin_comment
comment|// expected-error {{initializer element is not a compile-time constant}}
end_comment

begin_struct
struct|struct
name|ContainerStuct
block|{
enum|enum
block|{
name|SOME_ENUM
block|}
enum|;
comment|// expected-note {{'SOME_ENUM' declared here}}
block|}
struct|;
end_struct

begin_function
name|void
name|func
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
switch|switch
condition|(
name|arg
condition|)
block|{
case|case
name|SOME_ENUM_
case|:
comment|// expected-error {{use of undeclared identifier 'SOME_ENUM_'; did you mean 'SOME_ENUM'}}
empty_stmt|;
block|}
block|}
end_function

begin_function_decl
name|void
name|banana
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{'banana' declared here}}
end_comment

begin_function
name|int
name|c11Generic
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
generic_selection|_Generic(
name|hello
generic_selection|,
name|int
association|:
name|banana
generic_selection|)
argument_list|()
expr_stmt|;
comment|// expected-error-re {{use of undeclared identifier 'hello'{{$}}}}
generic_selection|_Generic(
name|arg
generic_selection|,
name|int
association|:
name|bandana
generic_selection|)
argument_list|()
expr_stmt|;
comment|// expected-error {{use of undeclared identifier 'bandana'; did you mean 'banana'?}}
block|}
end_function

begin_typedef
typedef|typedef
name|long
name|long
name|__m128i
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function
name|int
name|PR23101
parameter_list|(
name|__m128i
name|__x
parameter_list|)
block|{
return|return
name|foo
argument_list|(
operator|(
name|__v2di
operator|)
name|__x
argument_list|)
return|;
comment|// expected-warning {{implicit declaration of function 'foo'}} \
comment|// expected-error {{use of undeclared identifier '__v2di'}}
block|}
end_function

end_unit

