begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-apple-darwin10 -emit-llvm -o - %s -fexceptions -fblocks | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple armv7-apple-unknown -emit-llvm -o - %s -fexceptions -fsjlj-exceptions -fblocks | FileCheck %s -check-prefix=CHECK-ARM
end_comment

begin_comment
comment|// rdar://problem/8621849
end_comment

begin_function
name|void
name|test1
parameter_list|()
block|{
specifier|extern
name|void
name|test1_helper
argument_list|(
name|void
argument_list|(
operator|^
argument_list|)
argument_list|(
name|int
argument_list|)
argument_list|)
decl_stmt|;
comment|// CHECK:     define void @test1()
comment|// CHECK-ARM: define arm_aapcscc void @test1()
specifier|__block
name|int
name|x
init|=
literal|10
decl_stmt|;
comment|// CHECK:     invoke void @test1_helper(
comment|// CHECK-ARM: invoke arm_aapcscc void @test1_helper(
name|test1_helper
argument_list|(
lambda|^
parameter_list|(
name|int
name|v
parameter_list|)
block|{
name|x
operator|=
name|v
expr_stmt|;
block|}
argument_list|)
expr_stmt|;
comment|// CHECK:     call {{.*}} @llvm.eh.selector({{.*}}, i8* bitcast (i32 (...)* @__gcc_personality_v0 to i8*)
comment|// CHECK-ARM: call {{.*}} @llvm.eh.selector({{.*}}, i8* bitcast (i32 (...)* @__gcc_personality_sj0 to i8*)
block|}
end_function

end_unit

