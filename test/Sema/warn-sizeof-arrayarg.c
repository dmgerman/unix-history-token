begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s
end_comment

begin_typedef
typedef|typedef
name|int
name|Arr
index|[
literal|10
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|trungl_int
typedef|;
end_typedef

begin_function
name|void
name|f
parameter_list|(
name|int
name|a
index|[
literal|10
index|]
parameter_list|,
name|Arr
name|arr
parameter_list|)
block|{
comment|// \
comment|// expected-note {{declared here}} \
comment|// expected-note {{declared here}} \
comment|// expected-note {{declared here}} \
comment|// expected-note {{declared here}}
comment|/* Should warn. */
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|a
argument_list|)
expr_stmt|;
comment|// \
comment|// expected-warning{{sizeof on array function parameter will return size of 'int *' instead of 'int [10]'}}
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
operator|(
operator|(
operator|(
name|a
operator|)
operator|)
operator|)
argument_list|)
expr_stmt|;
comment|// \
comment|// expected-warning{{sizeof on array function parameter will return size of 'int *' instead of 'int [10]'}}
operator|(
name|void
operator|)
sizeof|sizeof
name|a
expr_stmt|;
comment|// \
comment|// expected-warning{{sizeof on array function parameter will return size of 'int *' instead of 'int [10]'}}
operator|(
name|void
operator|)
sizeof|sizeof
name|arr
expr_stmt|;
comment|// \
comment|// expected-warning{{sizeof on array function parameter will return size of 'int *' instead of 'Arr' (aka 'int [10]')}}
comment|/* Shouldn't warn. */
name|int
name|b
index|[
literal|10
index|]
decl_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
name|b
expr_stmt|;
name|Arr
name|brr
decl_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
name|brr
expr_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|Arr
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
sizeof|sizeof
argument_list|(
name|int
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

