begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
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

begin_typedef
typedef|typedef
name|int
name|i3
index|[
specifier|static
literal|3
index|]
typedef|;
end_typedef

begin_function
name|void
name|tcat
parameter_list|(
name|i3
name|a
parameter_list|)
block|{}
end_function

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
comment|// expected-warning {{null passed to a callee which requires a non-null argument}}
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
name|tcat
argument_list|(
literal|0
argument_list|)
expr_stmt|;
comment|// expected-warning {{null passed to a callee which requires a non-null argument}}
name|tcat
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// expected-warning {{array argument is too small; contains 2 elements, callee requires at least 3}}
name|tcat
argument_list|(
name|b
argument_list|)
expr_stmt|;
name|tcat
argument_list|(
name|c
argument_list|)
expr_stmt|;
name|tcat
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
comment|// expected-warning {{null passed to a callee which requires a non-null argument}}
name|vat
argument_list|(
literal|3
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

