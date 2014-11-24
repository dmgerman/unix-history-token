begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon -target-cpu cyclone \
end_comment

begin_comment
comment|// RUN:   -ffp-contract=fast -S -O3 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Test new aarch64 intrinsics and types
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|float32_t
name|test_vmuls_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmuls_lane_f32
return|return
name|vmuls_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmul {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float64_t
name|test_vmuld_lane_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmuld_lane_f64
return|return
name|vmuld_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmul {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+.d\[0\]|d[0-9]+}}
block|}
end_function

begin_function
name|float32_t
name|test_vmuls_laneq_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmuls_laneq_f32
return|return
name|vmuls_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmul {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float64_t
name|test_vmuld_laneq_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmuld_laneq_f64
return|return
name|vmuld_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmul {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|float64x1_t
name|test_vmul_n_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_n_f64
return|return
name|vmul_n_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmul {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+.d\[0\]|d[0-9]+}}
block|}
end_function

begin_function
name|float32_t
name|test_vmulxs_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxs_lane_f32
return|return
name|vmulxs_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmulx {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32_t
name|test_vmulxs_laneq_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxs_laneq_f32
return|return
name|vmulxs_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmulx {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float64_t
name|test_vmulxd_lane_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxd_lane_f64
return|return
name|vmulxd_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+.d\[0\]|d[0-9]+}}
block|}
end_function

begin_function
name|float64_t
name|test_vmulxd_laneq_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxd_laneq_f64
return|return
name|vmulxd_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmulx {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulx_lane_f64
end_comment

begin_function
name|float64x1_t
name|test_vmulx_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
return|return
name|vmulx_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+.d\[0\]|d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulx_laneq_f64_0
end_comment

begin_function
name|float64x1_t
name|test_vmulx_laneq_f64_0
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
return|return
name|vmulx_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[0]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulx_laneq_f64_1
end_comment

begin_function
name|float64x1_t
name|test_vmulx_laneq_f64_1
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
return|return
name|vmulx_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmulx {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfmas_lane_f32
end_comment

begin_function
name|float32_t
name|test_vfmas_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vfmas_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmla {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfmad_lane_f64
end_comment

begin_function
name|float64_t
name|test_vfmad_lane_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|,
name|float64x1_t
name|c
parameter_list|)
block|{
return|return
name|vfmad_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: {{fmla|fmadd}} {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+.d\[0\]|d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfmad_laneq_f64
end_comment

begin_function
name|float64_t
name|test_vfmad_laneq_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|,
name|float64x2_t
name|c
parameter_list|)
block|{
return|return
name|vfmad_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmla {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfmss_lane_f32
end_comment

begin_function
name|float32_t
name|test_vfmss_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vfmss_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmls {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfma_lane_f64
end_comment

begin_function
name|float64x1_t
name|test_vfma_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vfma_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: {{fmla|fmadd}} {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+.d\[0\]|d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfms_lane_f64
end_comment

begin_function
name|float64x1_t
name|test_vfms_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vfms_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: {{fmls|fmsub}} {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+.d\[0\]|d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfma_laneq_f64
end_comment

begin_function
name|float64x1_t
name|test_vfma_laneq_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vfma_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmla {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[0]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vfms_laneq_f64
end_comment

begin_function
name|float64x1_t
name|test_vfms_laneq_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vfms_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmls {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[0]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmullh_lane_s16
end_comment

begin_function
name|int32_t
name|test_vqdmullh_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmullh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmull {{s[0-9]+|v[0-9]+.4s}}, {{h[0-9]+|v[0-9].4h}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulls_lane_s32
end_comment

begin_function
name|int64_t
name|test_vqdmulls_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulls_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmull {{d[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmullh_laneq_s16
end_comment

begin_function
name|int32_t
name|test_vqdmullh_laneq_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqdmullh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmull {{s[0-9]+|v[0-9]+.4s}}, {{h[0-9]+|v[0-9]+.4h}}, {{v[0-9]+}}.h[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulls_laneq_s32
end_comment

begin_function
name|int64_t
name|test_vqdmulls_laneq_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulls_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmull {{d[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhh_lane_s16
end_comment

begin_function
name|int16_t
name|test_vqdmulhh_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmulh {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhs_lane_s32
end_comment

begin_function
name|int32_t
name|test_vqdmulhs_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhs_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmulh {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhh_laneq_s16
end_comment

begin_function
name|int16_t
name|test_vqdmulhh_laneq_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmulh {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{v[0-9]+}}.h[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmulhs_laneq_s32
end_comment

begin_function
name|int32_t
name|test_vqdmulhs_laneq_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhs_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmulh {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhh_lane_s16
end_comment

begin_function
name|int16_t
name|test_vqrdmulhh_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhs_lane_s32
end_comment

begin_function
name|int32_t
name|test_vqrdmulhs_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhs_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhh_laneq_s16
end_comment

begin_function
name|int16_t
name|test_vqrdmulhh_laneq_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{v[0-9]+}}.h[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrdmulhs_laneq_s32
end_comment

begin_function
name|int32_t
name|test_vqrdmulhs_laneq_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhs_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlalh_lane_s16
end_comment

begin_function
name|int32_t
name|test_vqdmlalh_lane_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlalh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlal {{s[0-9]+|v[0-9]+.4s}}, {{h[0-9]+|v[0-9]+.4h}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlals_lane_s32
end_comment

begin_function
name|int64_t
name|test_vqdmlals_lane_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlals_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmlal {{d[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlalh_laneq_s16
end_comment

begin_function
name|int32_t
name|test_vqdmlalh_laneq_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlalh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmlal {{s[0-9]+|v[0-9]+.4s}}, {{h[0-9]+|v[0-9]+.4h}}, {{v[0-9]+}}.h[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlals_laneq_s32
end_comment

begin_function
name|int64_t
name|test_vqdmlals_laneq_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlals_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlal {{d[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlslh_lane_s16
end_comment

begin_function
name|int32_t
name|test_vqdmlslh_lane_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlslh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{s[0-9]+|v[0-9]+.4s}}, {{h[0-9]+|v[0-9]+.4h}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlsls_lane_s32
end_comment

begin_function
name|int64_t
name|test_vqdmlsls_lane_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsls_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{d[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlslh_laneq_s16
end_comment

begin_function
name|int32_t
name|test_vqdmlslh_laneq_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlslh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{s[0-9]+|v[0-9]+.4s}}, {{h[0-9]+|v[0-9]+.4h}}, {{v[0-9]+}}.h[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqdmlsls_laneq_s32
end_comment

begin_function
name|int64_t
name|test_vqdmlsls_laneq_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsls_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{d[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulx_lane_f64_0:
end_comment

begin_function
name|float64x1_t
name|test_vmulx_lane_f64_0
parameter_list|()
block|{
name|float64x1_t
name|arg1
decl_stmt|;
name|float64x1_t
name|arg2
decl_stmt|;
name|float64x1_t
name|result
decl_stmt|;
name|float64_t
name|sarg1
decl_stmt|,
name|sarg2
decl_stmt|,
name|sres
decl_stmt|;
name|arg1
operator|=
name|vcreate_f64
argument_list|(
name|UINT64_C
argument_list|(
literal|0x3fd6304bc43ab5c2
argument_list|)
argument_list|)
expr_stmt|;
name|arg2
operator|=
name|vcreate_f64
argument_list|(
name|UINT64_C
argument_list|(
literal|0x3fee211e215aeef3
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|=
name|vmulx_lane_f64
argument_list|(
name|arg1
argument_list|,
name|arg2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: adrp x[[ADDRLO:[0-9]+]]
comment|// CHECK: ldr d0, [x[[ADDRLO]],
comment|// CHECK: adrp x[[ADDRLO:[0-9]+]]
comment|// CHECK: ldr d1, [x[[ADDRLO]],
comment|// CHECK: fmulx d0, d1, d0
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vmulx_laneq_f64_2:
end_comment

begin_function
name|float64x1_t
name|test_vmulx_laneq_f64_2
parameter_list|()
block|{
name|float64x1_t
name|arg1
decl_stmt|;
name|float64x1_t
name|arg2
decl_stmt|;
name|float64x2_t
name|arg3
decl_stmt|;
name|float64x1_t
name|result
decl_stmt|;
name|float64_t
name|sarg1
decl_stmt|,
name|sarg2
decl_stmt|,
name|sres
decl_stmt|;
name|arg1
operator|=
name|vcreate_f64
argument_list|(
name|UINT64_C
argument_list|(
literal|0x3fd6304bc43ab5c2
argument_list|)
argument_list|)
expr_stmt|;
name|arg2
operator|=
name|vcreate_f64
argument_list|(
name|UINT64_C
argument_list|(
literal|0x3fee211e215aeef3
argument_list|)
argument_list|)
expr_stmt|;
name|arg3
operator|=
name|vcombine_f64
argument_list|(
name|arg1
argument_list|,
name|arg2
argument_list|)
expr_stmt|;
name|result
operator|=
name|vmulx_laneq_f64
argument_list|(
name|arg1
argument_list|,
name|arg3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: adrp x[[ADDRLO:[0-9]+]]
comment|// CHECK: ldr d0, [x[[ADDRLO]],
comment|// CHECK: adrp x[[ADDRLO:[0-9]+]]
comment|// CHECK: ldr d1, [x[[ADDRLO]],
comment|// CHECK: fmulx d0, d1, d0
return|return
name|result
return|;
block|}
end_function

end_unit

