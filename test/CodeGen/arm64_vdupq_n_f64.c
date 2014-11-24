begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O3 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O3 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | \
end_comment

begin_comment
comment|// RUN:   FileCheck -check-prefix=CHECK-IR %s
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|/// Test vdupq_n_f64 and vmovq_nf64 ARM64 intrinsics
end_comment

begin_comment
comment|//<rdar://problem/11778405> ARM64: vdupq_n_f64 and vdupq_lane_f64 intrinsics
end_comment

begin_comment
comment|// missing
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// vdupq_n_f64 -> dup.2d v0, v0[0]
end_comment

begin_comment
comment|//
end_comment

begin_function
name|float64x2_t
name|test_vdupq_n_f64
parameter_list|(
name|float64_t
name|w
parameter_list|)
block|{
return|return
name|vdupq_n_f64
argument_list|(
name|w
argument_list|)
return|;
comment|// CHECK-LABEL: test_vdupq_n_f64:
comment|// CHECK: dup.2d v0, v0[0]
comment|// CHECK-NEXT: ret
block|}
end_function

begin_comment
comment|// might as well test this while we're here
end_comment

begin_comment
comment|// vdupq_n_f32 -> dup.4s v0, v0[0]
end_comment

begin_function
name|float32x4_t
name|test_vdupq_n_f32
parameter_list|(
name|float32_t
name|w
parameter_list|)
block|{
return|return
name|vdupq_n_f32
argument_list|(
name|w
argument_list|)
return|;
comment|// CHECK-LABEL: test_vdupq_n_f32:
comment|// CHECK: dup.4s v0, v0[0]
comment|// CHECK-NEXT: ret
block|}
end_function

begin_comment
comment|// vdupq_lane_f64 -> dup.2d v0, v0[0]
end_comment

begin_comment
comment|// this was in<rdar://problem/11778405>, but had already been implemented,
end_comment

begin_comment
comment|// test anyway
end_comment

begin_function
name|float64x2_t
name|test_vdupq_lane_f64
parameter_list|(
name|float64x1_t
name|V
parameter_list|)
block|{
return|return
name|vdupq_lane_f64
argument_list|(
name|V
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK-LABEL: test_vdupq_lane_f64:
comment|// CHECK: dup.2d v0, v0[0]
comment|// CHECK-NEXT: ret
block|}
end_function

begin_comment
comment|// vmovq_n_f64 -> dup Vd.2d,X0
end_comment

begin_comment
comment|// this wasn't in<rdar://problem/11778405>, but it was between the vdups
end_comment

begin_function
name|float64x2_t
name|test_vmovq_n_f64
parameter_list|(
name|float64_t
name|w
parameter_list|)
block|{
return|return
name|vmovq_n_f64
argument_list|(
name|w
argument_list|)
return|;
comment|// CHECK-LABEL: test_vmovq_n_f64:
comment|// CHECK: dup.2d v0, v0[0]
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float16x4_t
name|test_vmov_n_f16
parameter_list|(
name|float16_t
modifier|*
name|a1
parameter_list|)
block|{
comment|// CHECK-IR-LABEL: test_vmov_n_f16
return|return
name|vmov_n_f16
argument_list|(
operator|*
name|a1
argument_list|)
return|;
comment|// CHECK-IR: insertelement {{.*}} i32 0{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 1{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 2{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 3{{ *$}}
block|}
end_function

begin_comment
comment|// Disable until scalar problem in backend is fixed. Change CHECK-IR@ to
end_comment

begin_comment
comment|// CHECK-IR<colon>
end_comment

begin_comment
comment|/* float64x1_t test_vmov_n_f64(float64_t a1) {   // CHECK-IR@ test_vmov_n_f64   return vmov_n_f64(a1);   // CHECK-IR@ insertelement {{.*}} i32 0{{ *$}} } */
end_comment

begin_function
name|float16x8_t
name|test_vmovq_n_f16
parameter_list|(
name|float16_t
modifier|*
name|a1
parameter_list|)
block|{
comment|// CHECK-IR-LABEL: test_vmovq_n_f16
return|return
name|vmovq_n_f16
argument_list|(
operator|*
name|a1
argument_list|)
return|;
comment|// CHECK-IR: insertelement {{.*}} i32 0{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 1{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 2{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 3{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 4{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 5{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 6{{ *$}}
comment|// CHECK-IR: insertelement {{.*}} i32 7{{ *$}}
block|}
end_function

end_unit

