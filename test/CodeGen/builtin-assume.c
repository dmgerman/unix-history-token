begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple i386-mingw32 -fms-extensions -emit-llvm -o - %s | FileCheck %s
end_comment

begin_comment
comment|// CHECK-LABEL: @test1
end_comment

begin_function
name|int
name|test1
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|int
name|i
parameter_list|)
block|{
comment|// CHECK: store i32* %a, i32** [[A_ADDR:%.+]], align
comment|// CHECK: [[A:%.+]] = load i32** [[A_ADDR]]
comment|// CHECK: [[CMP:%.+]] = icmp ne i32* [[A]], null
comment|// CHECK: call void @llvm.assume(i1 [[CMP]])
ifdef|#
directive|ifdef
name|_MSC_VER
name|__assume
argument_list|(
argument|a !=
literal|0
argument_list|)
else|#
directive|else
name|__builtin_assume
argument_list|(
name|a
operator|!=
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Nothing is generated for an assume with side effects...
comment|// CHECK-NOT: load i32** %i.addr
comment|// CHECK-NOT: call void @llvm.assume
ifdef|#
directive|ifdef
name|_MSC_VER
name|__assume
argument_list|(
argument|++i !=
literal|0
argument_list|)
else|#
directive|else
name|__builtin_assume
argument_list|(
operator|++
name|i
operator|!=
literal|0
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
name|a
index|[
literal|0
index|]
return|;
block|}
end_function

end_unit

