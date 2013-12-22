begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple i386-unknown-linux-gnu -emit-llvm %s -o - | FileCheck %s
end_comment

begin_macro
name|__attribute
argument_list|(
argument|(aligned(
literal|16
argument|))
argument_list|)
end_macro

begin_decl_stmt
name|float
name|a
index|[
literal|128
index|]
decl_stmt|;
end_decl_stmt

begin_union
union|union
block|{
name|int
name|a
index|[
literal|4
index|]
decl_stmt|;
name|__attribute
argument_list|(
argument|(aligned(
literal|16
argument|))
argument_list|)
name|float
name|b
index|[
literal|4
index|]
decl_stmt|;
block|}
name|b
union|;
end_union

begin_comment
comment|// CHECK: @a = {{.*}}zeroinitializer, align 16
end_comment

begin_comment
comment|// CHECK: @b = {{.*}}zeroinitializer, align 16
end_comment

begin_decl_stmt
name|long
name|long
name|int
name|test5
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK-DAG: @test5 = common global [1024 x i64] zeroinitializer, align 8
end_comment

begin_comment
comment|// PR5279 - Reduced alignment on typedef.
end_comment

begin_typedef
typedef|typedef
name|int
name|myint
name|__attribute__
typedef|((
name|aligned
typedef|(1)));
end_typedef

begin_function
name|void
name|test1
parameter_list|(
name|myint
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
literal|0
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test1(
end_comment

begin_comment
comment|// CHECK: store i32 0, i32* {{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_function
name|int
name|test1a
parameter_list|(
name|myint
modifier|*
name|p
parameter_list|)
block|{
return|return
operator|*
name|p
return|;
block|}
end_function

begin_comment
comment|// CHECK: @test1a(
end_comment

begin_comment
comment|// CHECK: load i32* {{.*}}, align 1
end_comment

begin_comment
comment|// CHECK: ret i32
end_comment

begin_comment
comment|// PR5279 - Reduced alignment on typedef.
end_comment

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|,
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
name|packedfloat4
typedef|;
end_typedef

begin_function
name|void
name|test2
parameter_list|(
name|packedfloat4
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|(
name|packedfloat4
operator|)
block|{
literal|3.2f
block|,
literal|2.3f
block|,
literal|0.1f
block|,
literal|0.0f
block|}
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test2(
end_comment

begin_comment
comment|// CHECK: store<4 x float> {{.*}}, align 4
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_comment
comment|// PR5279 - Reduced alignment on typedef.
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
operator|,
name|aligned
argument_list|(
literal|4
argument_list|)
operator|)
argument_list|)
name|packedfloat3
typedef|;
end_typedef

begin_function
name|void
name|test3
parameter_list|(
name|packedfloat3
modifier|*
name|p
parameter_list|)
block|{
operator|*
name|p
operator|=
operator|(
name|packedfloat3
operator|)
block|{
literal|3.2f
block|,
literal|2.3f
block|,
literal|0.1f
block|}
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test3(
end_comment

begin_comment
comment|// CHECK: %{{.*}} = bitcast<3 x float>* %{{.*}} to<4 x float>*
end_comment

begin_comment
comment|// CHECK: store<4 x float> {{.*}}, align 4
end_comment

begin_comment
comment|// CHECK: ret void
end_comment

begin_typedef
typedef|typedef
name|float
name|__attribute__
argument_list|(
operator|(
name|vector_size
argument_list|(
literal|16
argument_list|)
operator|,
name|aligned
argument_list|(
literal|64
argument_list|)
operator|)
argument_list|)
name|float4align64
typedef|;
end_typedef

begin_comment
comment|// rdar://10639962 - Typedef alignment lost in p[]-style dereferencing
end_comment

begin_function
name|void
name|test4
parameter_list|(
name|float4align64
modifier|*
name|p
parameter_list|)
block|{
name|p
index|[
literal|0
index|]
operator|=
operator|(
name|float4align64
operator|)
block|{
literal|3.2f
block|,
literal|2.3f
block|,
literal|0.1f
block|,
literal|0.0f
block|}
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK: @test4(
end_comment

begin_comment
comment|// CHECK: store<4 x float> {{.*}},<4 x float>* {{.*}}, align 64
end_comment

end_unit

