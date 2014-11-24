begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD duplicate lane and n intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|void
name|test_vdup_lane_s64
parameter_list|(
name|int64x1_t
name|a1
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdup_lane_s64
name|vdup_lane_s64
argument_list|(
name|a1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
block|}
end_function

begin_function
name|void
name|test_vdup_lane_u64
parameter_list|(
name|uint64x1_t
name|a1
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdup_lane_u64
name|vdup_lane_u64
argument_list|(
name|a1
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
block|}
end_function

begin_comment
comment|// uncomment out the following code once scalar_to_vector in the backend
end_comment

begin_comment
comment|// works (for 64 bit?).  Change the "CHECK@" to "CHECK<colon>"
end_comment

begin_comment
comment|/* float64x1_t test_vdup_n_f64(float64_t a1) {   // CHECK-LABEL@ test_vdup_n_f64   return vdup_n_f64(a1);   // match that an element is inserted into part 0   // CHECK@ insertelement {{.*, i32 0 *$}} } */
end_comment

begin_function
name|float16x8_t
name|test_vdupq_n_f16
parameter_list|(
name|float16_t
modifier|*
name|a1
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdupq_n_f16
return|return
name|vdupq_n_f16
argument_list|(
operator|*
name|a1
argument_list|)
return|;
comment|// match that an element is inserted into parts 0-7.  The backend better
comment|// turn that into a single dup intruction
comment|// CHECK: insertelement {{.*, i32 0 *$}}
comment|// CHECK: insertelement {{.*, i32 1 *$}}
comment|// CHECK: insertelement {{.*, i32 2 *$}}
comment|// CHECK: insertelement {{.*, i32 3 *$}}
comment|// CHECK: insertelement {{.*, i32 4 *$}}
comment|// CHECK: insertelement {{.*, i32 5 *$}}
comment|// CHECK: insertelement {{.*, i32 6 *$}}
comment|// CHECK: insertelement {{.*, i32 7 *$}}
block|}
end_function

end_unit

