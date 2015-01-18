begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -fblocks -verify %s
end_comment

begin_function
name|void
name|cat0
parameter_list|(
name|int
name|a
index|[
specifier|static
literal|0
index|]
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-warning {{'static' has no effect on zero-length arrays}}
end_comment

begin_function
name|void
name|cat
parameter_list|(
name|int
name|a
index|[
specifier|static
literal|3
index|]
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note 2 {{callee declares array parameter as static here}}
end_comment

begin_function
name|void
name|vat
parameter_list|(
name|int
name|i
parameter_list|,
name|int
name|a
index|[
specifier|static
name|i
index|]
parameter_list|)
block|{}
end_function

begin_comment
comment|// expected-note {{callee declares array parameter as static here}}
end_comment

begin_function
name|void
name|f
parameter_list|(
name|int
modifier|*
name|p
parameter_list|)
block|{
name|int
name|a
index|[
literal|2
index|]
decl_stmt|,
name|b
index|[
literal|3
index|]
decl_stmt|,
name|c
index|[
literal|4
index|]
decl_stmt|;
name|cat0
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|cat
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee that requires a non-null argument}}
name|cat
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning {{array argument is too small; contains 2 elements, callee requires at least 3}}
name|cat
argument_list|(
name|b
argument_list|)
expr_stmt|;
name|cat
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|cat
argument_list|(
name|p
argument_list|)
expr_stmt|;
name|vat
argument_list|(
literal|1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee that requires a non-null argument}}
name|vat
argument_list|(
literal|3
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_typedef
typedef|typedef
name|int
name|td
index|[
specifier|static
literal|3
index|]
typedef|;
end_typedef

begin_comment
comment|// expected-error {{'static' used in array declarator outside of function prototype}}
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|fp
function_decl|)
parameter_list|(
name|int
index|[
specifier|static
literal|42
index|]
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|// no-warning
end_comment

begin_function
name|void
name|g
parameter_list|(
name|void
parameter_list|)
block|{
name|int
name|a
index|[
specifier|static
literal|42
index|]
decl_stmt|;
comment|// expected-error {{'static' used in array declarator outside of function prototype}}
name|int
name|b
index|[
specifier|const
literal|10
index|]
decl_stmt|;
comment|// expected-error {{type qualifier used in array declarator outside of function prototype}}
name|int
name|c
index|[
specifier|volatile
literal|10
index|]
decl_stmt|;
comment|// expected-error {{type qualifier used in array declarator outside of function prototype}}
name|int
name|d
index|[
specifier|restrict
literal|10
index|]
decl_stmt|;
comment|// expected-error {{type qualifier used in array declarator outside of function prototype}}
name|int
name|e
index|[
specifier|static
specifier|restrict
literal|1
index|]
decl_stmt|;
comment|// expected-error {{'static' used in array declarator outside of function prototype}}
block|}
end_function

begin_function_decl
name|void
name|h
parameter_list|(
name|int
index|[
specifier|static
specifier|const
literal|10
index|]
index|[
literal|42
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// no-warning
end_comment

begin_function_decl
name|void
name|i
parameter_list|(
name|int
index|[
literal|10
index|]
index|[
specifier|static
literal|42
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{'static' used in non-outermost array type derivation}}
end_comment

begin_function_decl
name|void
name|j
parameter_list|(
name|int
index|[
literal|10
index|]
index|[
specifier|const
literal|42
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// expected-error {{type qualifier used in non-outermost array type derivation}}
end_comment

begin_decl_stmt
name|void
name|k
argument_list|(
name|int
argument_list|(
operator|*
name|x
argument_list|)
index|[
specifier|static
literal|10
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error {{'static' used in non-outermost array type derivation}}
end_comment

begin_decl_stmt
name|void
name|l
argument_list|(
name|int
argument_list|(
name|x
argument_list|)
index|[
specifier|static
literal|10
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no-warning
end_comment

begin_function_decl
name|void
name|m
parameter_list|(
name|int
modifier|*
name|x
index|[
specifier|static
literal|10
index|]
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// no-warning
end_comment

begin_decl_stmt
name|void
name|n
argument_list|(
name|int
operator|*
operator|(
name|x
operator|)
index|[
specifier|static
literal|10
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// no-warning
end_comment

begin_decl_stmt
name|void
name|o
argument_list|(
name|int
argument_list|(
name|x
index|[
specifier|static
literal|10
index|]
argument_list|)
argument_list|(
name|void
argument_list|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{'x' declared as array of functions of type 'int (void)'}}
end_comment

begin_decl_stmt
name|void
name|p
argument_list|(
name|int
argument_list|(
operator|^
name|x
argument_list|)
index|[
specifier|static
literal|10
index|]
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-error{{block pointer to non-function type is invalid}}
end_comment

begin_function_decl
name|void
name|q
parameter_list|(
name|int
function_decl|(
modifier|^
name|x
index|[
specifier|static
literal|10
index|]
function_decl|)
parameter_list|()
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// no-warning
end_comment

begin_function
name|void
name|r
parameter_list|(
name|x
parameter_list|)
name|int
name|x
index|[
specifier|restrict
index|]
decl_stmt|;
comment|// no-warning
block|{}
end_function

end_unit

