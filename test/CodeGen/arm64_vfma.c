begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD fused multiply add intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|float32x2_t
name|test_vfma_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|,
name|float32x2_t
name|a2
parameter_list|,
name|float32x2_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfma_f32
return|return
name|vfma_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
return|;
comment|// CHECK: llvm.fma.v2f32({{.*a2, .*a3, .*a1}})
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmaq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|,
name|float32x4_t
name|a2
parameter_list|,
name|float32x4_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmaq_f32
return|return
name|vfmaq_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
return|;
comment|// CHECK: llvm.fma.v4f32({{.*a2, .*a3, .*a1}})
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmaq_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|,
name|float64x2_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmaq_f64
return|return
name|vfmaq_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
return|;
comment|// CHECK: llvm.fma.v2f64({{.*a2, .*a3, .*a1}})
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x2_t
name|test_vfma_lane_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|,
name|float32x2_t
name|a2
parameter_list|,
name|float32x2_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfma_lane_f32
return|return
name|vfma_lane_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
literal|1
argument_list|)
return|;
comment|// NB: the test below is deliberately lose, so that we don't depend too much
comment|// upon the exact IR used to select lane 1 (usually a shufflevector)
comment|// CHECK: llvm.fma.v2f32(<2 x float> %a2,<2 x float> {{.*}},<2 x float> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmaq_lane_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|,
name|float32x4_t
name|a2
parameter_list|,
name|float32x2_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmaq_lane_f32
return|return
name|vfmaq_lane_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
literal|1
argument_list|)
return|;
comment|// NB: the test below is deliberately lose, so that we don't depend too much
comment|// upon the exact IR used to select lane 1 (usually a shufflevector)
comment|// CHECK: llvm.fma.v4f32(<4 x float> %a2,<4 x float> {{.*}},<4 x float> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmaq_lane_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|,
name|float64x1_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmaq_lane_f64
return|return
name|vfmaq_lane_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
literal|0
argument_list|)
return|;
comment|// NB: the test below is deliberately lose, so that we don't depend too much
comment|// upon the exact IR used to select lane 1 (usually a shufflevector)
comment|// CHECK: llvm.fma.v2f64(<2 x double> %a2,<2 x double> {{.*}},<2 x double> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x2_t
name|test_vfma_n_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|,
name|float32x2_t
name|a2
parameter_list|,
name|float32_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfma_n_f32
return|return
name|vfma_n_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
return|;
comment|// NB: the test below is deliberately lose, so that we don't depend too much
comment|// upon the exact IR used to select lane 0 (usually two insertelements)
comment|// CHECK: llvm.fma.v2f32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmaq_n_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|,
name|float32x4_t
name|a2
parameter_list|,
name|float32_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmaq_n_f32
return|return
name|vfmaq_n_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
return|;
comment|// NB: the test below is deliberately lose, so that we don't depend too much
comment|// upon the exact IR used to select lane 0 (usually four insertelements)
comment|// CHECK: llvm.fma.v4f32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmaq_n_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|,
name|float64_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmaq_n_f64
return|return
name|vfmaq_n_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
return|;
comment|// NB: the test below is deliberately lose, so that we don't depend too much
comment|// upon the exact IR used to select lane 0 (usually two insertelements)
comment|// CHECK: llvm.fma.v2f64
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x2_t
name|test_vfms_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|,
name|float32x2_t
name|a2
parameter_list|,
name|float32x2_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfms_f32
return|return
name|vfms_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
return|;
comment|// CHECK: [[NEG:%.*]] = fsub<2 x float> {{.*}}, %a2
comment|// CHECK: llvm.fma.v2f32(<2 x float> %a3,<2 x float> [[NEG]],<2 x float> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmsq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|,
name|float32x4_t
name|a2
parameter_list|,
name|float32x4_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmsq_f32
return|return
name|vfmsq_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
return|;
comment|// CHECK: [[NEG:%.*]] = fsub<4 x float> {{.*}}, %a2
comment|// CHECK: llvm.fma.v4f32(<4 x float> %a3,<4 x float> [[NEG]],<4 x float> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmsq_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|,
name|float64x2_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmsq_f64
return|return
name|vfmsq_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|)
return|;
comment|// CHECK: [[NEG:%.*]] = fsub<2 x double> {{.*}}, %a2
comment|// CHECK: llvm.fma.v2f64(<2 x double> %a3,<2 x double> [[NEG]],<2 x double> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x2_t
name|test_vfms_lane_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|,
name|float32x2_t
name|a2
parameter_list|,
name|float32x2_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfms_lane_f32
return|return
name|vfms_lane_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
literal|1
argument_list|)
return|;
comment|// NB: the test below is deliberately lose, so that we don't depend too much
comment|// upon the exact IR used to select lane 1 (usually a shufflevector)
comment|// CHECK: [[NEG:%.*]] = fsub<2 x float> {{.*}}, %a3
comment|// CHECK: [[LANE:%.*]] = shufflevector<2 x float> [[NEG]]
comment|// CHECK: llvm.fma.v2f32(<2 x float> {{.*}},<2 x float> [[LANE]],<2 x float> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmsq_lane_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|,
name|float32x4_t
name|a2
parameter_list|,
name|float32x2_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmsq_lane_f32
return|return
name|vfmsq_lane_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
literal|1
argument_list|)
return|;
comment|// NB: the test below is deliberately lose, so that we don't depend too much
comment|// upon the exact IR used to select lane 1 (usually a shufflevector)
comment|// CHECK: [[NEG:%.*]] = fsub<2 x float> {{.*}}, %a3
comment|// CHECK: [[LANE:%.*]] = shufflevector<2 x float> [[NEG]]
comment|// CHECK: llvm.fma.v4f32(<4 x float> {{.*}},<4 x float> [[LANE]],<4 x float> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmsq_lane_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|,
name|float64x1_t
name|a3
parameter_list|)
block|{
comment|// CHECK: test_vfmsq_lane_f64
return|return
name|vfmsq_lane_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
name|a3
argument_list|,
literal|0
argument_list|)
return|;
comment|// NB: the test below is deliberately lose, so that we don't depend too much
comment|// upon the exact IR used to select lane 1 (usually a shufflevector)
comment|// CHECK: [[NEG:%.*]] = fsub<1 x double> {{.*}}, %a3
comment|// CHECK: [[LANE:%.*]] = shufflevector<1 x double> [[NEG]]
comment|// CHECK: llvm.fma.v2f64(<2 x double> {{.*}},<2 x double> [[LANE]],<2 x double> %a1)
comment|// CHECK-NEXT: ret
block|}
end_function

end_unit

