begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// Test that basic generic vector support works
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o -
end_comment

begin_typedef
typedef|typedef
name|int
name|v4si
name|__attribute__
typedef|((
name|__vector_size__
typedef|(16)));
end_typedef

begin_function
name|void
name|test
parameter_list|(
name|v4si
modifier|*
name|P
parameter_list|,
name|v4si
modifier|*
name|Q
parameter_list|,
name|float
name|X
parameter_list|)
block|{
operator|*
name|P
operator|=
operator|(
name|v4si
operator|)
block|{
name|X
block|,
name|X
block|,
name|X
block|,
name|X
block|}
operator|*
operator|*
name|Q
expr_stmt|;
block|}
end_function

begin_decl_stmt
name|v4si
name|G
init|=
operator|(
name|v4si
operator|)
block|{
literal|0.1
block|,
literal|1.2
block|,
literal|4.2
block|,
literal|17.2
block|}
decl_stmt|;
end_decl_stmt

end_unit

