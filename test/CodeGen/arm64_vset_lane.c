begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD set lane intrinsics INCOMPLETE
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|float16x4_t
name|test_vset_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a1
parameter_list|,
name|float16x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_f16
return|return
name|vset_lane_f16
argument_list|(
operator|*
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK insertelement<4 x i16> %a2, i16 %a1, i32 1
block|}
end_function

begin_function
name|float16x8_t
name|test_vsetq_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a1
parameter_list|,
name|float16x8_t
name|a2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_f16
return|return
name|vsetq_lane_f16
argument_list|(
operator|*
name|a1
argument_list|,
name|a2
argument_list|,
literal|4
argument_list|)
return|;
comment|// CHECK insertelement<8 x i16> %a2, i16 %a1, i32 4
block|}
end_function

begin_comment
comment|// problem with scalar_to_vector in backend.  Punt for now
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|float64x1_t test_vset_lane_f64(float64_t a1, float64x1_t a2) {
comment|// CHECK-LABEL@ test_vset_lane_f64
end_comment

begin_comment
unit|return vset_lane_f64(a1, a2, 0);
comment|// CHECK@ @llvm.aarch64.neon.smaxv.i32.v8i8
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_function
name|float64x2_t
name|test_vsetq_lane_f64
parameter_list|(
name|float64_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_f64
return|return
name|vsetq_lane_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK insertelement<2 x double> %a2, double %a1, i32 0
block|}
end_function

end_unit

