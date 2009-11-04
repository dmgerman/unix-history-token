begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc %s -fsyntax-only -verify
end_comment

begin_comment
comment|//typedef __attribute__(( ext_vector_type(4) ))  float float4;
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

begin_decl_stmt
name|float4
name|foo
init|=
operator|(
name|float4
operator|)
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|,
literal|4.0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float4
name|foo2
init|=
operator|(
name|float4
operator|)
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|,
literal|4.0
block|,
literal|5.0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning{{excess elements in vector initializer}}
end_comment

begin_decl_stmt
name|float4
name|array
index|[]
init|=
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|,
literal|4.0
block|,
literal|5.0
block|,
literal|6.0
block|,
literal|7.0
block|,
literal|8.0
block|,
literal|9.0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|array_sizecheck
index|[
operator|(
sizeof|sizeof
argument_list|(
name|array
argument_list|)
operator|/
sizeof|sizeof
argument_list|(
name|float4
argument_list|)
operator|)
operator|==
literal|3
condition|?
literal|1
else|:
operator|-
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|float4
name|array2
index|[
literal|2
index|]
init|=
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|,
literal|4.0
block|,
literal|5.0
block|,
literal|6.0
block|,
literal|7.0
block|,
literal|8.0
block|,
literal|9.0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{excess elements in array initializer}}
end_comment

begin_decl_stmt
name|float4
name|array3
index|[
literal|2
index|]
init|=
block|{
block|{
literal|1.0
block|,
literal|2.0
block|,
literal|3.0
block|}
block|,
literal|5.0
block|,
literal|6.0
block|,
literal|7.0
block|,
literal|8.0
block|,
literal|9.0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|// expected-warning {{excess elements in array initializer}}
end_comment

begin_comment
comment|// rdar://6881069
end_comment

begin_macro
name|__attribute__
argument_list|(
argument|(vector_size(
literal|16
argument|))
argument_list|)
end_macro

begin_comment
comment|// expected-error {{unsupported type 'float (void)' for vector_size attribute, please use on typedef}}
end_comment

begin_function
name|float
name|f1
parameter_list|(
name|void
parameter_list|)
block|{ }
end_function

begin_comment
comment|// PR5265
end_comment

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|ext_vector_type
argument_list|(
literal|3
argument_list|)
operator|)
argument_list|)
name|float3
typedef|;
end_typedef

begin_decl_stmt
name|int
name|test2
index|[
sizeof|sizeof
argument_list|(
name|float3
argument_list|)
operator|==
sizeof|sizeof
argument_list|(
name|float4
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

