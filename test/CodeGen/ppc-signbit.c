begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple powerpc64-linux-gnu | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 %s -emit-llvm -o - -triple powerpc64le-linux-gnu | FileCheck %s
end_comment

begin_function
name|int
name|test
parameter_list|(
name|long
name|double
name|x
parameter_list|)
block|{
return|return
name|__builtin_signbitl
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define signext i32 @test(ppc_fp128 %x)
end_comment

begin_comment
comment|// CHECK: bitcast ppc_fp128 %{{.*}} to i128
end_comment

begin_comment
comment|// CHECK: trunc i128 %{{.*}} to i64
end_comment

begin_comment
comment|// CHECK: icmp slt i64 %{{.*}}, 0
end_comment

begin_comment
comment|// CHECK: zext i1 %{{.*}} to i32
end_comment

end_unit

