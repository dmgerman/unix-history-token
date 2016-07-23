begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD vcreate intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|float32x2_t
name|test_vcreate_f32
parameter_list|(
name|uint64_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_f32
return|return
name|vcreate_f32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: bitcast {{.*}} to<2 x float>
comment|// CHECK-NEXT: ret
block|}
end_function

end_unit

