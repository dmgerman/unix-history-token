begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -fsyntax-only -verify %s -fno-lax-vector-conversions
end_comment

begin_typedef
typedef|typedef
name|float
name|float4
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|int
name|int4
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
name|int4
modifier|*
name|int4p
typedef|;
end_typedef

begin_function
name|void
name|test1
parameter_list|(
name|float4
name|a
parameter_list|,
name|int4
modifier|*
name|result
parameter_list|,
name|int
name|i
parameter_list|)
block|{
name|result
index|[
name|i
index|]
operator|=
name|a
expr_stmt|;
comment|// expected-error {{assigning 'float4', expected 'int4'}}
block|}
end_function

begin_function
name|void
name|test2
parameter_list|(
name|float4
name|a
parameter_list|,
name|int4p
name|result
parameter_list|,
name|int
name|i
parameter_list|)
block|{
name|result
index|[
name|i
index|]
operator|=
name|a
expr_stmt|;
comment|// expected-error {{assigning 'float4', expected 'int4'}}
block|}
end_function

begin_comment
comment|// PR2039
end_comment

begin_typedef
typedef|typedef
name|int
name|a
index|[
literal|5
index|]
typedef|;
end_typedef

begin_function
name|void
name|test3
parameter_list|()
block|{
typedef|typedef
specifier|const
name|a
name|b
typedef|;
name|b
name|r
decl_stmt|;
name|r
index|[
literal|0
index|]
operator|=
literal|10
expr_stmt|;
comment|// expected-error {{read-only variable is not assignable}}
block|}
end_function

begin_function
name|int
name|test4
parameter_list|(
specifier|const
name|a
name|y
parameter_list|)
block|{
name|y
index|[
literal|0
index|]
operator|=
literal|10
expr_stmt|;
comment|// expected-error {{read-only variable is not assignable}}
block|}
end_function

begin_comment
comment|// PR2189
end_comment

begin_function
name|int
name|test5
parameter_list|()
block|{
specifier|const
name|int
name|s
index|[
literal|5
index|]
decl_stmt|;
name|int
name|t
index|[
literal|5
index|]
decl_stmt|;
return|return
operator|&
name|s
operator|==
operator|&
name|t
return|;
comment|// expected-warning {{comparison of distinct pointer types}}
block|}
end_function

begin_function
name|int
name|test6
parameter_list|()
block|{
specifier|const
name|a
name|s
decl_stmt|;
name|a
name|t
decl_stmt|;
return|return
operator|&
name|s
operator|==
operator|&
name|t
return|;
comment|// expected-warning {{comparison of distinct pointer types}}
block|}
end_function

end_unit

