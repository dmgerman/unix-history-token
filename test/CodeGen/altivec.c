begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -faltivec -triple powerpc-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// Check initialization
end_comment

begin_decl_stmt
name|vector
name|int
name|test0
init|=
call|(
name|vector
name|int
call|)
argument_list|(
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @test0 = global<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_decl_stmt
name|vector
name|float
name|test1
init|=
call|(
name|vector
name|float
call|)
argument_list|(
literal|1.0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// CHECK: @test1 = global<4 x float><float 1.000000e+{{0+}}, float 1.000000e+{{0+}}, float 1.000000e+{{0+}}, float 1.000000e+{{0+}}>
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
name|vector
name|int
name|vi
decl_stmt|;
name|vector
name|float
name|vf
decl_stmt|;
name|vi
operator|=
call|(
name|vector
name|int
call|)
argument_list|(
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK:<i32 1, i32 1, i32 1, i32 1>
name|vf
operator|=
call|(
name|vector
name|float
call|)
argument_list|(
literal|1.0
argument_list|)
expr_stmt|;
comment|// CHECK:<float 1.000000e+{{0+}}, float 1.000000e+{{0+}}, float 1.000000e+{{0+}}, float 1.000000e+{{0+}}>
name|vi
operator|=
call|(
name|vector
name|int
call|)
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK:<i32 1, i32 2, i32 3, i32 4>
name|vi
operator|=
call|(
name|vector
name|int
call|)
argument_list|(
literal|1
argument_list|,
literal|2
argument_list|,
literal|3
argument_list|,
literal|4
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK:<i32 1, i32 2, i32 3, i32 4>
name|vi
operator|=
operator|(
name|vector
name|int
operator|)
block|{
literal|1
block|}
expr_stmt|;
comment|// CHECK:<i32 1, i32 0, i32 0, i32 0>
name|vi
operator|=
operator|(
name|vector
name|int
operator|)
block|{
literal|1
block|,
literal|2
block|}
expr_stmt|;
comment|// CHECK:<i32 1, i32 2, i32 0, i32 0>
name|vi
operator|=
operator|(
name|vector
name|int
operator|)
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|}
expr_stmt|;
comment|// CHECK:<i32 1, i32 2, i32 3, i32 4>
block|}
end_function

begin_comment
comment|// Check pre/post increment/decrement
end_comment

begin_function
name|void
name|test3
parameter_list|()
block|{
name|vector
name|int
name|vi
decl_stmt|;
name|vi
operator|++
expr_stmt|;
comment|// CHECK: add nsw<4 x i32> {{.*}}<i32 1, i32 1, i32 1, i32 1>
name|vector
name|unsigned
name|int
name|vui
decl_stmt|;
operator|--
name|vui
expr_stmt|;
comment|// CHECK: add<4 x i32> {{.*}}<i32 -1, i32 -1, i32 -1, i32 -1>
name|vector
name|float
name|vf
decl_stmt|;
name|vf
operator|++
expr_stmt|;
comment|// CHECK: fadd<4 x float> {{.*}}<float 1.000000e+{{0+}}, float 1.000000e+{{0+}}, float 1.000000e+{{0+}}, float 1.000000e+{{0+}}>
block|}
end_function

end_unit

