begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD vget intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|float64_t
name|test_vget_lane_f64
parameter_list|(
name|float64x1_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_f64
comment|// why isn't 1 allowed as second argument?
return|return
name|vget_lane_f64
argument_list|(
name|a1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: extractelement {{.*}} i32 0
comment|// CHECK-NEXT: ret
block|}
end_function

end_unit

