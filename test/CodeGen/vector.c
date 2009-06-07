begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm %s -o -
end_comment

begin_typedef
typedef|typedef
name|short
name|__v4hi
name|__attribute__
typedef|((
name|__vector_size__
typedef|(8)));
end_typedef

begin_function
name|void
name|f
parameter_list|()
block|{
name|__v4hi
name|A
init|=
operator|(
name|__v4hi
operator|)
literal|0LL
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|__v4hi
name|x
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|__v4hi
name|y
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|int
name|vty
name|__attribute
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
name|int
name|a
parameter_list|()
block|{
name|vty
name|b
decl_stmt|;
return|return
name|b
index|[
literal|2LL
index|]
return|;
block|}
end_function

begin_comment
comment|// PR4339
end_comment

begin_typedef
typedef|typedef
name|float
name|vec4
name|__attribute__
typedef|((
name|vector_size
typedef|(16)));
end_typedef

begin_function
name|void
name|vac
parameter_list|(
name|vec4
modifier|*
name|a
parameter_list|,
name|char
name|b
parameter_list|,
name|float
name|c
parameter_list|)
block|{
operator|(
operator|*
name|a
operator|)
index|[
name|b
index|]
operator|=
name|c
expr_stmt|;
block|}
end_function

end_unit

