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

begin_function
name|void
name|f
parameter_list|(
name|long
modifier|*
name|a
parameter_list|,
name|long
name|b
parameter_list|)
block|{
name|__atomic_or_fetch
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|// expected-error {{use of undeclared identifier 'c'}}
block|}
end_function

begin_function_decl
specifier|extern
name|double
name|cabs
parameter_list|(
specifier|_Complex
name|double
name|z
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|fn1
parameter_list|()
block|{
name|cabs
argument_list|(
name|errij
argument_list|)
expr_stmt|;
comment|// expected-error {{use of undeclared identifier 'errij'}}
block|}
end_function

begin_function_decl
specifier|extern
name|long
name|afunction
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-note {{'afunction' declared here}}
end_comment

begin_function
name|void
name|fn2
parameter_list|()
block|{
name|f
argument_list|(
name|THIS_IS_AN_ERROR
argument_list|,
comment|// expected-error {{use of undeclared identifier 'THIS_IS_AN_ERROR'}}
name|afunction
argument_list|(
name|afunction_
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-error {{use of undeclared identifier 'afunction_'; did you mean 'afunction'?}}
block|}
end_function

begin_decl_stmt
name|int
name|d
init|=
name|X
condition|?
name|d
else|:
name|L
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error 2 {{use of undeclared identifier}}
end_comment

begin_function
name|int
name|fn_with_ids
parameter_list|()
block|{
name|ID
operator|=
name|ID
operator|==
name|ID
operator|>=
name|ID
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error 4 {{use of undeclared identifier}}
end_comment

begin_function
name|int
name|fn_with_rs
parameter_list|(
name|int
name|r
parameter_list|)
block|{
name|r
operator|=
name|TYPO
operator|+
name|r
operator|*
name|TYPO
expr_stmt|;
block|}
end_function

begin_comment
comment|// expected-error 2 {{use of undeclared identifier}}
end_comment

begin_function
name|void
name|fn_with_unknown
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
name|fn_with_unknown
argument_list|(
name|unknown
argument_list|,
name|unknown
operator||
name|unknown
argument_list|)
expr_stmt|;
comment|// expected-error 3 {{use of undeclared identifier}}
block|}
end_function

begin_comment
comment|// Two typos in a parenthesized expression or argument list with a conditional
end_comment

begin_comment
comment|// expression caused a crash in C mode.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// r272587 fixed a similar bug for binary operations. The same fix was needed for
end_comment

begin_comment
comment|// conditional expressions.
end_comment

begin_function
name|int
name|g
parameter_list|(
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
block|{
return|return
name|x
operator|+
name|y
return|;
block|}
end_function

begin_function
name|int
name|h
parameter_list|()
block|{
name|g
argument_list|(
name|x
argument_list|,
literal|5
condition|?
name|z
else|:
literal|0
argument_list|)
expr_stmt|;
comment|// expected-error 2 {{use of undeclared identifier}}
operator|(
name|x
operator|,
literal|5
condition|?
name|z
else|:
literal|0
operator|)
expr_stmt|;
comment|// expected-error 2 {{use of undeclared identifier}}
block|}
end_function

begin_macro
name|__attribute__
argument_list|(
argument|(overloadable)
argument_list|)
end_macro

begin_function_decl
name|void
name|func_overloadable
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_macro
name|__attribute__
argument_list|(
argument|(overloadable)
argument_list|)
end_macro

begin_function_decl
name|void
name|func_overloadable
parameter_list|(
name|float
parameter_list|)
function_decl|;
end_function_decl

begin_function
name|void
name|overloadable_callexpr
parameter_list|(
name|int
name|arg
parameter_list|)
block|{
name|func_overloadable
argument_list|(
name|ar
argument_list|)
expr_stmt|;
comment|//expected-error{{use of undeclared identifier}}
block|}
end_function

end_unit

