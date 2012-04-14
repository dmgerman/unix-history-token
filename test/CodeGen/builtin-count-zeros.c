begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple x86_64-unknown-unknown -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm-unknown-unknown -emit-llvm %s -o - | FileCheck %s --check-prefix=CHECK-ARM
end_comment

begin_function
name|int
name|a
parameter_list|(
name|int
name|a
parameter_list|)
block|{
return|return
name|__builtin_ctz
argument_list|(
name|a
argument_list|)
operator|+
name|__builtin_clz
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: call i32 @llvm.cttz.i32({{.*}}, i1 true)
end_comment

begin_comment
comment|// CHECK: call i32 @llvm.ctlz.i32({{.*}}, i1 true)
end_comment

begin_comment
comment|// CHECK-ARM: call i32 @llvm.cttz.i32({{.*}}, i1 false)
end_comment

begin_comment
comment|// CHECK-ARM: call i32 @llvm.ctlz.i32({{.*}}, i1 false)
end_comment

end_unit

