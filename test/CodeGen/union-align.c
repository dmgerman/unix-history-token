begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm %s -o - | grep load | grep "4 x float" | not grep "align 4"
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-linux-gnu -emit-llvm %s -o - | grep load | grep "4 x float" | grep "align 16"
end_comment

begin_comment
comment|// PR3432
end_comment

begin_comment
comment|// rdar://6536377
end_comment

begin_typedef
typedef|typedef
name|float
name|__m128
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|int
name|i
index|[
literal|4
index|]
decl_stmt|;
name|float
name|f
index|[
literal|4
index|]
decl_stmt|;
name|__m128
name|v
decl_stmt|;
block|}
name|u_t
typedef|;
end_typedef

begin_function
name|__m128
name|t
parameter_list|(
name|u_t
modifier|*
name|a
parameter_list|)
block|{
return|return
name|a
operator|->
name|v
return|;
block|}
end_function

end_unit

