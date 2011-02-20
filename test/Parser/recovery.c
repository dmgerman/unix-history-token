begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify -pedantic -fblocks %s
end_comment

begin_comment
comment|// PR2241
end_comment

begin_decl_stmt
name|float
name|test2241
index|[
literal|2
index|]
init|=
block|{
literal|1e
block|,
comment|// expected-error {{exponent}}
literal|1ee0
comment|// expected-error {{exponent}}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Testcase derived from PR2692
end_comment

begin_function
specifier|static
name|void
name|f
parameter_list|(
name|char
modifier|*
function_decl|(
modifier|*
name|g
function_decl|)
parameter_list|(
name|char
modifier|*
modifier|*
parameter_list|,
name|int
parameter_list|)
parameter_list|,
name|char
modifier|*
modifier|*
name|p
parameter_list|,
modifier|...
parameter_list|)
block|{
name|char
modifier|*
name|s
decl_stmt|;
name|va_list
name|v
decl_stmt|;
comment|// expected-error {{identifier}}
name|s
operator|=
name|g
argument_list|(
name|p
argument_list|,
name|__builtin_va_arg
argument_list|(
name|v
argument_list|,
name|int
argument_list|)
argument_list|)
expr_stmt|;
comment|// expected-error {{identifier}}
block|}
end_function

begin_comment
comment|// PR3172
end_comment

begin_comment
unit|}
comment|// expected-error {{expected external declaration}}
end_comment

begin_comment
comment|// rdar://6094870
end_comment

begin_macro
unit|void
name|test
argument_list|(
argument|int a
argument_list|)
end_macro

begin_block
block|{
struct|struct
block|{
name|int
name|i
decl_stmt|;
block|}
name|x
struct|;
if|if
condition|(
name|x
operator|.
name|hello
condition|)
comment|// expected-error {{no member named 'hello'}}
name|test
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|else
empty_stmt|;
if|if
condition|(
name|x
operator|.
name|hello
operator|==
literal|0
condition|)
comment|// expected-error {{no member named 'hello'}}
name|test
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|else
empty_stmt|;
if|if
condition|(
operator|(
name|x
operator|.
name|hello
operator|==
literal|0
operator|)
condition|)
comment|// expected-error {{no member named 'hello'}}
name|test
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|else
empty_stmt|;
if|if
condition|(
name|x
operator|.
name|i
operator|==
literal|0
condition|)
block|)
end_block

begin_comment
comment|// expected-error {{expected expression}}
end_comment

begin_expr_stmt
name|test
argument_list|(
literal|0
argument_list|)
expr_stmt|;
end_expr_stmt

begin_else
else|else
empty_stmt|;
end_else

begin_expr_stmt
unit|}    char
operator|(
operator|(
operator|(
operator|(
comment|/* expected-note {{to match this '('}} */
operator|*
name|X
name|x
expr|]
operator|)
operator|)
operator|)
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* expected-error {{expected ')'}} */
end_comment

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// expected-warning {{ISO C does not allow an extra ';' outside of a function}}
end_comment

begin_struct
struct|struct
name|S
block|{
name|void
modifier|*
name|X
decl_stmt|,
modifier|*
name|Y
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|S
name|A
init|=
block|{
operator|&
name|BADIDENT
block|,
literal|0
comment|/* expected-error {{use of undeclared identifier}} */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// rdar://6248081
end_comment

begin_function
name|void
name|test6248081
parameter_list|()
block|{
index|[
literal|10
index|]
comment|// expected-error {{expected expression}}
block|}
end_function

begin_struct_decl
struct_decl|struct
name|forward
struct_decl|;
end_struct_decl

begin_comment
comment|// expected-note{{forward declaration of 'struct forward'}}
end_comment

begin_function
name|void
name|x
parameter_list|(
name|struct
name|forward
modifier|*
name|x
parameter_list|)
block|{
switch|switch
condition|(
name|x
operator|->
name|a
condition|)
block|{}
block|}
end_function

begin_comment
comment|// expected-error {{incomplete definition of type}}
end_comment

begin_comment
comment|// PR3410
end_comment

begin_function
name|void
name|foo
parameter_list|()
block|{
name|int
name|X
decl_stmt|;
name|X
operator|=
literal|4
comment|// expected-error{{expected ';' after expression}}
block|}
end_function

begin_comment
comment|// rdar://7980651
end_comment

begin_typedef
typedef|typedef
name|int
name|intptr_t
typedef|;
end_typedef

begin_comment
comment|// expected-note {{'intptr_t' declared here}}
end_comment

begin_function_decl
name|void
name|bar
parameter_list|(
name|intptr
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{unknown type name 'intptr'; did you mean 'intptr_t'?}}
end_comment

begin_function
name|void
name|test1
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|x
init|=
literal|2
operator|:
comment|// expected-error {{expected ';' at end of declaration}}
name|int
name|y
operator|=
name|x
decl_stmt|;
name|int
name|z
init|=
name|y
decl_stmt|;
block|}
end_function

end_unit

