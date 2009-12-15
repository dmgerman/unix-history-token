begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: clang-cc -emit-llvm< %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK: @test1.x = internal constant [12 x i32] [i32 1
end_comment

begin_comment
comment|// CHECK: @test2.x = internal constant [13 x i32] [i32 1,
end_comment

begin_comment
comment|// CHECK: @test5w = global %0 { i32 2, [4 x i8] undef }
end_comment

begin_comment
comment|// CHECK: @test5y = global %union.test5u { double 7.300000e+0{{[0]*}}1 }
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
comment|// This should codegen as a "@test1.x" global.
specifier|const
name|int
name|x
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|6
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|123
block|,
literal|231
block|,
literal|123
block|,
literal|23
block|}
decl_stmt|;
name|foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: @test1()
comment|// CHECK: {{call.*@foo.*@test1.x}}
block|}
end_function

begin_comment
comment|// rdar://7346691
end_comment

begin_function
name|void
name|test2
parameter_list|()
block|{
comment|// This should codegen as a "@test2.x" global + memcpy.
name|int
name|x
index|[]
init|=
block|{
literal|1
block|,
literal|2
block|,
literal|3
block|,
literal|4
block|,
literal|6
block|,
literal|8
block|,
literal|9
block|,
literal|10
block|,
literal|123
block|,
literal|231
block|,
literal|123
block|,
literal|23
block|,
literal|24
block|}
decl_stmt|;
name|foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: @test2()
comment|// CHECK: %x = alloca [13 x i32]
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK: call{{.*}}@foo{{.*}}i32* %
block|}
end_function

begin_function
name|void
name|test3
parameter_list|()
block|{
comment|// This should codegen as a memset.
name|int
name|x
index|[
literal|100
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|foo
argument_list|(
name|x
argument_list|)
expr_stmt|;
comment|// CHECK: @test3()
comment|// CHECK: %x = alloca [100 x i32]
comment|// CHECK: call void @llvm.memset
block|}
end_function

begin_function
name|void
name|test4
parameter_list|(
name|void
parameter_list|)
block|{
name|char
name|a
index|[
literal|10
index|]
init|=
literal|"asdf"
decl_stmt|;
name|char
name|b
index|[
literal|10
index|]
init|=
block|{
literal|"asdf"
block|}
decl_stmt|;
comment|// CHECK: @test4()
comment|// CHECK: %a = alloca [10 x i8]
comment|// CHECK: %b = alloca [10 x i8]
comment|// CHECK: call void @llvm.memcpy
comment|// CHECK: call void @llvm.memcpy
block|}
end_function

begin_union
union|union
name|test5u
block|{
name|int
name|i
decl_stmt|;
name|double
name|d
decl_stmt|;
block|}
union|;
end_union

begin_function
name|void
name|test5
parameter_list|()
block|{
name|union
name|test5u
name|ola
init|=
operator|(
expr|union
name|test5u
operator|)
literal|351
decl_stmt|;
name|union
name|test5u
name|olb
init|=
operator|(
expr|union
name|test5u
operator|)
literal|1.0
decl_stmt|;
block|}
end_function

begin_decl_stmt
name|union
name|test5u
name|test5w
init|=
operator|(
expr|union
name|test5u
operator|)
literal|2
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|union
name|test5u
name|test5y
init|=
operator|(
expr|union
name|test5u
operator|)
literal|73.0
decl_stmt|;
end_decl_stmt

end_unit

