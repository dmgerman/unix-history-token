begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon -S -O3 -o - %s | FileCheck %s
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
name|int16x4_t
name|test_vmla_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_lane_s16
return|return
name|vmla_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlaq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_lane_s16
return|return
name|vmlaq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmla_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_lane_s32
return|return
name|vmla_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlaq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_lane_s32
return|return
name|vmlaq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmla_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_laneq_s16
return|return
name|vmla_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlaq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_laneq_s16
return|return
name|vmlaq_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmla_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_laneq_s32
return|return
name|vmla_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlaq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_laneq_s32
return|return
name|vmlaq_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmls_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_lane_s16
return|return
name|vmls_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlsq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_lane_s16
return|return
name|vmlsq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmls_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_lane_s32
return|return
name|vmls_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_lane_s32
return|return
name|vmlsq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmls_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_laneq_s16
return|return
name|vmls_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlsq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_laneq_s16
return|return
name|vmlsq_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmls_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_laneq_s32
return|return
name|vmls_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_laneq_s32
return|return
name|vmlsq_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmul_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_s16
return|return
name|vmul_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmulq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_s16
return|return
name|vmulq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmul_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_s32
return|return
name|vmul_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmulq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_s32
return|return
name|vmulq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmul_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_u16
return|return
name|vmul_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmulq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_u16
return|return
name|vmulq_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmul_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_u32
return|return
name|vmul_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmulq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_u32
return|return
name|vmulq_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmul_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_s16
return|return
name|vmul_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmulq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_s16
return|return
name|vmulq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmul_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_s32
return|return
name|vmul_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmulq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_s32
return|return
name|vmulq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmul_laneq_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_u16
return|return
name|vmul_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmulq_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_u16
return|return
name|vmulq_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmul_laneq_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_u32
return|return
name|vmul_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmulq_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_u32
return|return
name|vmulq_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfma_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfma_lane_f32
return|return
name|vfma_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmaq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_lane_f32
return|return
name|vfmaq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfma_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfma_laneq_f32
return|return
name|vfma_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmaq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_laneq_f32
return|return
name|vfmaq_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfms_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfms_lane_f32
return|return
name|vfms_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmsq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsq_lane_f32
return|return
name|vfmsq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfms_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfms_laneq_f32
return|return
name|vfms_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmsq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsq_laneq_f32
return|return
name|vfmsq_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmaq_lane_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_lane_f64
return|return
name|vfmaq_lane_f64
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
comment|// CHECK: fmla {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmaq_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_laneq_f64
return|return
name|vfmaq_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmsq_lane_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsq_lane_f64
return|return
name|vfmsq_lane_f64
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
comment|// CHECK: fmls {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmsq_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsq_laneq_f64
return|return
name|vfmsq_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|float32_t
name|test_vfmas_laneq_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmas_laneq_f32
return|return
name|vfmas_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmla {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float64_t
name|test_vfmsd_lane_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsd_lane_f64
return|return
name|vfmsd_lane_f64
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
comment|// CHECK: {{fmls d[0-9]+, d[0-9]+, v[0-9]+\.d\[0\]|fmsub d[0-9]+, d[0-9]+, d[0-9]+}}
block|}
end_function

begin_function
name|float32_t
name|test_vfmss_laneq_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmss_laneq_f32
return|return
name|vfmss_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmls {{s[0-9]+}}, {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float64_t
name|test_vfmsd_laneq_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsd_laneq_f64
return|return
name|vfmsd_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmls {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_lane_s16
return|return
name|vmlal_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_lane_s32
return|return
name|vmlal_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: smlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_laneq_s16
return|return
name|vmlal_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: smlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_laneq_s32
return|return
name|vmlal_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_lane_s16
return|return
name|vmlal_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_lane_s32
return|return
name|vmlal_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: smlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_laneq_s16
return|return
name|vmlal_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: smlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_laneq_s32
return|return
name|vmlal_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_lane_s16
return|return
name|vmlsl_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_lane_s32
return|return
name|vmlsl_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: smlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_laneq_s16
return|return
name|vmlsl_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: smlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_laneq_s32
return|return
name|vmlsl_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_lane_s16
return|return
name|vmlsl_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_lane_s32
return|return
name|vmlsl_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: smlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_laneq_s16
return|return
name|vmlsl_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: smlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_laneq_s32
return|return
name|vmlsl_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_lane_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_lane_u16
return|return
name|vmlal_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_lane_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_lane_u32
return|return
name|vmlal_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: umlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_laneq_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_laneq_u16
return|return
name|vmlal_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: umlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_laneq_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_laneq_u32
return|return
name|vmlal_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_lane_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_lane_u16
return|return
name|vmlal_high_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_lane_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_lane_u32
return|return
name|vmlal_high_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: umlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_laneq_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_laneq_u16
return|return
name|vmlal_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: umlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_laneq_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_laneq_u32
return|return
name|vmlal_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_lane_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_lane_u16
return|return
name|vmlsl_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_lane_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_lane_u32
return|return
name|vmlsl_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: umlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_laneq_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_laneq_u16
return|return
name|vmlsl_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: umlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_laneq_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_laneq_u32
return|return
name|vmlsl_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_lane_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_lane_u16
return|return
name|vmlsl_high_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_lane_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_lane_u32
return|return
name|vmlsl_high_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: umlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_laneq_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_laneq_u16
return|return
name|vmlsl_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: umlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_laneq_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_laneq_u32
return|return
name|vmlsl_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_lane_s16
return|return
name|vmull_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_lane_s32
return|return
name|vmull_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_lane_u16
return|return
name|vmull_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_lane_u32
return|return
name|vmull_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_high_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_lane_s16
return|return
name|vmull_high_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_high_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_lane_s32
return|return
name|vmull_high_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_high_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_lane_u16
return|return
name|vmull_high_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_high_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_lane_u32
return|return
name|vmull_high_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_laneq_s16
return|return
name|vmull_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_laneq_s32
return|return
name|vmull_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_laneq_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_laneq_u16
return|return
name|vmull_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_laneq_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_laneq_u32
return|return
name|vmull_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_high_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_laneq_s16
return|return
name|vmull_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_high_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_laneq_s32
return|return
name|vmull_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_high_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_laneq_u16
return|return
name|vmull_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_high_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_laneq_u32
return|return
name|vmull_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_lane_s16
return|return
name|vqdmlal_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_lane_s32
return|return
name|vqdmlal_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_high_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_lane_s16
return|return
name|vqdmlal_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_high_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_lane_s32
return|return
name|vqdmlal_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_lane_s16
return|return
name|vqdmlsl_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_lane_s32
return|return
name|vqdmlsl_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_high_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_lane_s16
return|return
name|vqdmlsl_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_high_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_lane_s32
return|return
name|vqdmlsl_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_lane_s16
return|return
name|vqdmull_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_lane_s32
return|return
name|vqdmull_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_laneq_s16
return|return
name|vqdmull_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_laneq_s32
return|return
name|vqdmull_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_high_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_lane_s16
return|return
name|vqdmull_high_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_high_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_lane_s32
return|return
name|vqdmull_high_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_high_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_laneq_s16
return|return
name|vqdmull_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_high_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_laneq_s32
return|return
name|vqdmull_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int16x4_t
name|test_vqdmulh_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_lane_s16
return|return
name|vqdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int16x8_t
name|test_vqdmulhq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_lane_s16
return|return
name|vqdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int32x2_t
name|test_vqdmulh_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_lane_s32
return|return
name|vqdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmulhq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_lane_s32
return|return
name|vqdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int16x4_t
name|test_vqrdmulh_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_lane_s16
return|return
name|vqrdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int16x8_t
name|test_vqrdmulhq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_lane_s16
return|return
name|vqrdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int32x2_t
name|test_vqrdmulh_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_lane_s32
return|return
name|vqrdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqrdmulhq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_lane_s32
return|return
name|vqrdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32x2_t
name|test_vmul_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_f32
return|return
name|vmul_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float64x1_t
name|test_vmul_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_f64
return|return
name|vmul_lane_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmul {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+\.d\[0\]|d[0-9]+}}
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_f32
return|return
name|vmulq_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulq_lane_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_f64
return|return
name|vmulq_lane_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vmul_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_f32
return|return
name|vmul_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float64x1_t
name|test_vmul_laneq_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_f64
return|return
name|vmul_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmul {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_f32
return|return
name|vmulq_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulq_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_f64
return|return
name|vmulq_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|float32x2_t
name|test_vmulx_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulx_lane_f32
return|return
name|vmulx_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulxq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_lane_f32
return|return
name|vmulxq_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulxq_lane_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_lane_f64
return|return
name|vmulxq_lane_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vmulx_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulx_laneq_f32
return|return
name|vmulx_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulxq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_laneq_f32
return|return
name|vmulxq_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulxq_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_laneq_f64
return|return
name|vmulxq_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmla_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_lane_s16_0
return|return
name|vmla_lane_s16
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
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlaq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_lane_s16_0
return|return
name|vmlaq_lane_s16
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
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmla_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_lane_s32_0
return|return
name|vmla_lane_s32
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
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlaq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_lane_s32_0
return|return
name|vmlaq_lane_s32
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
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmla_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_laneq_s16_0
return|return
name|vmla_laneq_s16
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
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlaq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_laneq_s16_0
return|return
name|vmlaq_laneq_s16
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
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmla_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_laneq_s32_0
return|return
name|vmla_laneq_s32
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
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlaq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_laneq_s32_0
return|return
name|vmlaq_laneq_s32
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
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmls_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_lane_s16_0
return|return
name|vmls_lane_s16
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
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlsq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_lane_s16_0
return|return
name|vmlsq_lane_s16
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
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmls_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_lane_s32_0
return|return
name|vmls_lane_s32
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
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_lane_s32_0
return|return
name|vmlsq_lane_s32
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
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmls_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_laneq_s16_0
return|return
name|vmls_laneq_s16
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
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlsq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_laneq_s16_0
return|return
name|vmlsq_laneq_s16
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
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmls_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_laneq_s32_0
return|return
name|vmls_laneq_s32
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
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_laneq_s32_0
return|return
name|vmlsq_laneq_s32
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
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmul_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_s16_0
return|return
name|vmul_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmulq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_s16_0
return|return
name|vmulq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmul_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_s32_0
return|return
name|vmul_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmulq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_s32_0
return|return
name|vmulq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmul_lane_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_u16_0
return|return
name|vmul_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmulq_lane_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_u16_0
return|return
name|vmulq_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmul_lane_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_u32_0
return|return
name|vmul_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmulq_lane_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_u32_0
return|return
name|vmulq_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmul_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_s16_0
return|return
name|vmul_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vmulq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_s16_0
return|return
name|vmulq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vmul_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_s32_0
return|return
name|vmul_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmulq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_s32_0
return|return
name|vmulq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmul_laneq_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_u16_0
return|return
name|vmul_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmulq_laneq_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_u16_0
return|return
name|vmulq_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmul_laneq_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_u32_0
return|return
name|vmul_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmulq_laneq_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_u32_0
return|return
name|vmulq_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfma_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfma_lane_f32_0
return|return
name|vfma_lane_f32
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
comment|// CHECK: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmaq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_lane_f32_0
return|return
name|vfmaq_lane_f32
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
comment|// CHECK: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfma_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfma_laneq_f32_0
return|return
name|vfma_laneq_f32
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
comment|// CHECK: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmaq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_laneq_f32_0
return|return
name|vfmaq_laneq_f32
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
comment|// CHECK: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfms_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfms_lane_f32_0
return|return
name|vfms_lane_f32
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
comment|// CHECK: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmsq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsq_lane_f32_0
return|return
name|vfmsq_lane_f32
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
comment|// CHECK: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfms_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfms_laneq_f32_0
return|return
name|vfms_laneq_f32
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
comment|// CHECK: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmsq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsq_laneq_f32_0
return|return
name|vfmsq_laneq_f32
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
comment|// CHECK: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmaq_laneq_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_laneq_f64_0
return|return
name|vfmaq_laneq_f64
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
comment|// CHECK: fmla {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmsq_laneq_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsq_laneq_f64_0
return|return
name|vfmsq_laneq_f64
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
comment|// CHECK: fmls {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_lane_s16_0
return|return
name|vmlal_lane_s16
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
comment|// CHECK: smlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_lane_s32_0
return|return
name|vmlal_lane_s32
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
comment|// CHECK: smlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_laneq_s16_0
return|return
name|vmlal_laneq_s16
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
comment|// CHECK: smlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_laneq_s32_0
return|return
name|vmlal_laneq_s32
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
comment|// CHECK: smlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_lane_s16_0
return|return
name|vmlal_high_lane_s16
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
comment|// CHECK: smlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_lane_s32_0
return|return
name|vmlal_high_lane_s32
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
comment|// CHECK: smlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_laneq_s16_0
return|return
name|vmlal_high_laneq_s16
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
comment|// CHECK: smlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_laneq_s32_0
return|return
name|vmlal_high_laneq_s32
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
comment|// CHECK: smlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_lane_s16_0
return|return
name|vmlsl_lane_s16
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
comment|// CHECK: smlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_lane_s32_0
return|return
name|vmlsl_lane_s32
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
comment|// CHECK: smlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_laneq_s16_0
return|return
name|vmlsl_laneq_s16
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
comment|// CHECK: smlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_laneq_s32_0
return|return
name|vmlsl_laneq_s32
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
comment|// CHECK: smlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_lane_s16_0
return|return
name|vmlsl_high_lane_s16
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
comment|// CHECK: smlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_lane_s32_0
return|return
name|vmlsl_high_lane_s32
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
comment|// CHECK: smlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_laneq_s16_0
return|return
name|vmlsl_high_laneq_s16
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
comment|// CHECK: smlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_laneq_s32_0
return|return
name|vmlsl_high_laneq_s32
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
comment|// CHECK: smlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_lane_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_lane_u16_0
return|return
name|vmlal_lane_u16
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
comment|// CHECK: umlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_lane_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_lane_u32_0
return|return
name|vmlal_lane_u32
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
comment|// CHECK: umlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_laneq_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_laneq_u16_0
return|return
name|vmlal_laneq_u16
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
comment|// CHECK: umlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_laneq_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_laneq_u32_0
return|return
name|vmlal_laneq_u32
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
comment|// CHECK: umlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_lane_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_lane_u16_0
return|return
name|vmlal_high_lane_u16
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
comment|// CHECK: umlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_lane_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_lane_u32_0
return|return
name|vmlal_high_lane_u32
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
comment|// CHECK: umlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_laneq_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_laneq_u16_0
return|return
name|vmlal_high_laneq_u16
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
comment|// CHECK: umlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_laneq_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_laneq_u32_0
return|return
name|vmlal_high_laneq_u32
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
comment|// CHECK: umlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_lane_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_lane_u16_0
return|return
name|vmlsl_lane_u16
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
comment|// CHECK: umlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_lane_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_lane_u32_0
return|return
name|vmlsl_lane_u32
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
comment|// CHECK: umlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_laneq_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_laneq_u16_0
return|return
name|vmlsl_laneq_u16
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
comment|// CHECK: umlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_laneq_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_laneq_u32_0
return|return
name|vmlsl_laneq_u32
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
comment|// CHECK: umlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_lane_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_lane_u16_0
return|return
name|vmlsl_high_lane_u16
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
comment|// CHECK: umlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_lane_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_lane_u32_0
return|return
name|vmlsl_high_lane_u32
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
comment|// CHECK: umlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_laneq_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_laneq_u16_0
return|return
name|vmlsl_high_laneq_u16
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
comment|// CHECK: umlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_laneq_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_laneq_u32_0
return|return
name|vmlsl_high_laneq_u32
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
comment|// CHECK: umlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_lane_s16_0
return|return
name|vmull_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_lane_s32_0
return|return
name|vmull_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_lane_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_lane_u16_0
return|return
name|vmull_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_lane_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_lane_u32_0
return|return
name|vmull_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_high_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_lane_s16_0
return|return
name|vmull_high_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_high_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_lane_s32_0
return|return
name|vmull_high_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_high_lane_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_lane_u16_0
return|return
name|vmull_high_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_high_lane_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_lane_u32_0
return|return
name|vmull_high_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_laneq_s16_0
return|return
name|vmull_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_laneq_s32_0
return|return
name|vmull_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_laneq_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_laneq_u16_0
return|return
name|vmull_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_laneq_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_laneq_u32_0
return|return
name|vmull_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_high_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_laneq_s16_0
return|return
name|vmull_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_high_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_laneq_s32_0
return|return
name|vmull_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_high_laneq_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_laneq_u16_0
return|return
name|vmull_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_high_laneq_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_laneq_u32_0
return|return
name|vmull_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_lane_s16_0
return|return
name|vqdmlal_lane_s16
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
comment|// CHECK: sqdmlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_lane_s32_0
return|return
name|vqdmlal_lane_s32
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
comment|// CHECK: sqdmlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_high_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_lane_s16_0
return|return
name|vqdmlal_high_lane_s16
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
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_high_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_lane_s32_0
return|return
name|vqdmlal_high_lane_s32
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
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_lane_s16_0
return|return
name|vqdmlsl_lane_s16
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
comment|// CHECK: sqdmlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_lane_s32_0
return|return
name|vqdmlsl_lane_s32
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
comment|// CHECK: sqdmlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_high_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_lane_s16_0
return|return
name|vqdmlsl_high_lane_s16
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
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_high_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_lane_s32_0
return|return
name|vqdmlsl_high_lane_s32
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
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_lane_s16_0
return|return
name|vqdmull_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_lane_s32_0
return|return
name|vqdmull_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_laneq_s16_0
return|return
name|vqdmull_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_laneq_s32_0
return|return
name|vqdmull_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_high_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_lane_s16_0
return|return
name|vqdmull_high_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_high_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_lane_s32_0
return|return
name|vqdmull_high_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_high_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_laneq_s16_0
return|return
name|vqdmull_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_high_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_laneq_s32_0
return|return
name|vqdmull_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vqdmulh_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_lane_s16_0
return|return
name|vqdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vqdmulhq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_lane_s16_0
return|return
name|vqdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vqdmulh_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_lane_s32_0
return|return
name|vqdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmulhq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_lane_s32_0
return|return
name|vqdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vqrdmulh_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_lane_s16_0
return|return
name|vqrdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vqrdmulhq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_lane_s16_0
return|return
name|vqrdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vqrdmulh_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_lane_s32_0
return|return
name|vqrdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqrdmulhq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_lane_s32_0
return|return
name|vqrdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vmul_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_lane_f32_0
return|return
name|vmul_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_lane_f32_0
return|return
name|vmulq_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vmul_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_f32_0
return|return
name|vmul_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x1_t
name|test_vmul_laneq_f64_0
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_laneq_f64_0
return|return
name|vmul_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmul {{d[0-9]+}}, {{d[0-9]+}}, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_f32_0
return|return
name|vmulq_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulq_laneq_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_laneq_f64_0
return|return
name|vmulq_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vmulx_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulx_lane_f32_0
return|return
name|vmulx_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulxq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_lane_f32_0
return|return
name|vmulxq_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulxq_lane_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_lane_f64_0
return|return
name|vmulxq_lane_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vmulx_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulx_laneq_f32_0
return|return
name|vmulx_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulxq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_laneq_f32_0
return|return
name|vmulxq_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulxq_laneq_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_laneq_f64_0
return|return
name|vmulxq_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_high_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_n_s16
return|return
name|vmull_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+\.h\[0\]|v[0-9]+\.8h}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_high_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_n_s32
return|return
name|vmull_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+\.s\[0\]|v[0-9]+\.4s}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_high_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_n_u16
return|return
name|vmull_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+\.h\[0\]|v[0-9]+\.8h}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_high_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_n_u32
return|return
name|vmull_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+\.s\[0\]|v[0-9]+\.4s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_high_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_n_s16
return|return
name|vqdmull_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+\.h\[0\]|v[0-9]+\.8h}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_high_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_n_s32
return|return
name|vqdmull_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+\.s\[0\]|v[0-9]+\.4s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_n_s16
return|return
name|vmlal_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+\.h\[0\]|v[0-9]+\.8h}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_n_s32
return|return
name|vmlal_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+\.s\[0\]|v[0-9]+\.4s}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlal_high_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_n_u16
return|return
name|vmlal_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+\.h\[0\]|v[0-9]+\.8h}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmlal_high_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_n_u32
return|return
name|vmlal_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+\.s\[0\]|v[0-9]+\.4s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_high_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_n_s16
return|return
name|vqdmlal_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+\.h\[0\]|v[0-9]+\.8h}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_high_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_n_s32
return|return
name|vqdmlal_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+\.s\[0\]|v[0-9]+\.4s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_n_s16
return|return
name|vmlsl_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+\.h\[0\]|v[0-9]+\.8h}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_n_s32
return|return
name|vmlsl_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+\.s\[0\]|v[0-9]+\.4s}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsl_high_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_n_u16
return|return
name|vmlsl_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+\.h\[0\]|v[0-9]+\.8h}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmlsl_high_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_n_u32
return|return
name|vmlsl_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+\.s\[0\]|v[0-9]+\.4s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_high_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_n_s16
return|return
name|vqdmlsl_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+\.h\[0\]|v[0-9]+\.8h}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_high_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_n_s32
return|return
name|vqdmlsl_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+\.s\[0\]|v[0-9]+\.4s}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vmul_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_n_f32
return|return
name|vmul_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_n_f32
return|return
name|vmulq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulq_n_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_n_f64
return|return
name|vmulq_n_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfma_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32_t
name|n
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfma_n_f32
return|return
name|vfma_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|n
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmaq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32_t
name|n
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_n_f32
return|return
name|vfmaq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|n
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x2_t
name|test_vfms_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32_t
name|n
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfms_n_f32
return|return
name|vfms_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|n
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmsq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32_t
name|n
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsq_n_f32
return|return
name|vfmsq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|n
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vmul_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_n_s16
return|return
name|vmul_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vmulq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_n_s16
return|return
name|vmulq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, w0
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vmul_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_n_s32
return|return
name|vmul_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vmulq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_n_s32
return|return
name|vmulq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, w0
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmul_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_n_u16
return|return
name|vmul_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmulq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_n_u16
return|return
name|vmulq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, w0
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmul_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_n_u32
return|return
name|vmul_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmulq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_n_u32
return|return
name|vmulq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, w0
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_n_s16
return|return
name|vmull_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: smull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_n_s32
return|return
name|vmull_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: smull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_n_u16
return|return
name|vmull_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: umull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_n_u32
return|return
name|vmull_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: umull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_n_s16
return|return
name|vqdmull_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: sqdmull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_n_s32
return|return
name|vqdmull_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: sqdmull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x4_t
name|test_vqdmulh_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_n_s16
return|return
name|vqdmulh_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: sqdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vqdmulhq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_n_s16
return|return
name|vqdmulhq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, w0
comment|// CHECK: sqdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqdmulh_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_n_s32
return|return
name|vqdmulh_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: sqdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmulhq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_n_s32
return|return
name|vqdmulhq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, w0
comment|// CHECK: sqdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x4_t
name|test_vqrdmulh_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_n_s16
return|return
name|vqrdmulh_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vqrdmulhq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_n_s16
return|return
name|vqrdmulhq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, w0
comment|// CHECK: sqrdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqrdmulh_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_n_s32
return|return
name|vqrdmulh_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: sqrdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqrdmulhq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_n_s32
return|return
name|vqrdmulhq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, w0
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x4_t
name|test_vmla_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_n_s16
return|return
name|vmla_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlaq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_n_s16
return|return
name|vmlaq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, w0
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vmla_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_n_s32
return|return
name|vmla_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlaq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_n_s32
return|return
name|vmlaq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, w0
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmla_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_n_u16
return|return
name|vmla_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlaq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_n_u16
return|return
name|vmlaq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, w0
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmla_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_n_u32
return|return
name|vmla_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlaq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_n_u32
return|return
name|vmlaq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, w0
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_n_s16
return|return
name|vmlal_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: smlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_n_s32
return|return
name|vmlal_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: smlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlal_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_n_u16
return|return
name|vmlal_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: umlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmlal_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_n_u32
return|return
name|vmlal_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: umlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_n_s16
return|return
name|vqdmlal_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: sqdmlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_n_s32
return|return
name|vqdmlal_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: sqdmlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x4_t
name|test_vmls_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_n_s16
return|return
name|vmls_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlsq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_n_s16
return|return
name|vmlsq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, w0
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vmls_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_n_s32
return|return
name|vmls_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_n_s32
return|return
name|vmlsq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmls_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_n_u16
return|return
name|vmls_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlsq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_n_u16
return|return
name|vmlsq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, w0
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmls_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_n_u32
return|return
name|vmls_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_n_u32
return|return
name|vmlsq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_n_s16
return|return
name|vmlsl_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: smlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_n_s32
return|return
name|vmlsl_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: smlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsl_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_n_u16
return|return
name|vmlsl_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: umlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmlsl_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_n_u32
return|return
name|vmlsl_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: umlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_n_s16
return|return
name|vqdmlsl_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, w0
comment|// CHECK: sqdmlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_n_s32
return|return
name|vqdmlsl_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, w0
comment|// CHECK: sqdmlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmla_lane_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_lane_u16_0
return|return
name|vmla_lane_u16
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
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlaq_lane_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_lane_u16_0
return|return
name|vmlaq_lane_u16
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
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmla_lane_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_lane_u32_0
return|return
name|vmla_lane_u32
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
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlaq_lane_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_lane_u32_0
return|return
name|vmlaq_lane_u32
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
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmla_laneq_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_laneq_u16_0
return|return
name|vmla_laneq_u16
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
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlaq_laneq_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_laneq_u16_0
return|return
name|vmlaq_laneq_u16
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
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmla_laneq_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_laneq_u32_0
return|return
name|vmla_laneq_u32
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
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlaq_laneq_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_laneq_u32_0
return|return
name|vmlaq_laneq_u32
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
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_laneq_s16_0
return|return
name|vqdmlal_laneq_s16
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
comment|// CHECK: sqdmlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_laneq_s32_0
return|return
name|vqdmlal_laneq_s32
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
comment|// CHECK: sqdmlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_high_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_laneq_s16_0
return|return
name|vqdmlal_high_laneq_s16
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
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_high_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_laneq_s32_0
return|return
name|vqdmlal_high_laneq_s32
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
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmls_lane_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_lane_u16_0
return|return
name|vmls_lane_u16
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
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlsq_lane_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_lane_u16_0
return|return
name|vmlsq_lane_u16
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
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmls_lane_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_lane_u32_0
return|return
name|vmls_lane_u32
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
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsq_lane_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_lane_u32_0
return|return
name|vmlsq_lane_u32
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
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmls_laneq_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_laneq_u16_0
return|return
name|vmls_laneq_u16
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
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlsq_laneq_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_laneq_u16_0
return|return
name|vmlsq_laneq_u16
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
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmls_laneq_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_laneq_u32_0
return|return
name|vmls_laneq_u32
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
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsq_laneq_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_laneq_u32_0
return|return
name|vmlsq_laneq_u32
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
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_laneq_s16_0
return|return
name|vqdmlsl_laneq_s16
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
comment|// CHECK: sqdmlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_laneq_s32_0
return|return
name|vqdmlsl_laneq_s32
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
comment|// CHECK: sqdmlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_high_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_laneq_s16_0
return|return
name|vqdmlsl_high_laneq_s16
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
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_high_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_laneq_s32_0
return|return
name|vqdmlsl_high_laneq_s32
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
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vqdmulh_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_laneq_s16_0
return|return
name|vqdmulh_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vqdmulhq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_laneq_s16_0
return|return
name|vqdmulhq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vqdmulh_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_laneq_s32_0
return|return
name|vqdmulh_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmulhq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_laneq_s32_0
return|return
name|vqdmulhq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int16x4_t
name|test_vqrdmulh_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_laneq_s16_0
return|return
name|vqrdmulh_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vqrdmulhq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_laneq_s16_0
return|return
name|vqrdmulhq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[0]
block|}
end_function

begin_function
name|int32x2_t
name|test_vqrdmulh_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_laneq_s32_0
return|return
name|vqrdmulh_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqrdmulhq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_laneq_s32_0
return|return
name|vqrdmulhq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmla_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_lane_u16
return|return
name|vmla_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlaq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_lane_u16
return|return
name|vmlaq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmla_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_lane_u32
return|return
name|vmla_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlaq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_lane_u32
return|return
name|vmlaq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmla_laneq_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_laneq_u16
return|return
name|vmla_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlaq_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_laneq_u16
return|return
name|vmlaq_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmla_laneq_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_laneq_u32
return|return
name|vmla_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlaq_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_laneq_u32
return|return
name|vmlaq_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_laneq_s16
return|return
name|vqdmlal_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_laneq_s32
return|return
name|vqdmlal_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_high_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_laneq_s16
return|return
name|vqdmlal_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_high_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_laneq_s32
return|return
name|vqdmlal_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmls_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_lane_u16
return|return
name|vmls_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlsq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_lane_u16
return|return
name|vmlsq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmls_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_lane_u32
return|return
name|vmls_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_lane_u32
return|return
name|vmlsq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmls_laneq_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_laneq_u16
return|return
name|vmls_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlsq_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_laneq_u16
return|return
name|vmlsq_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmls_laneq_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_laneq_u32
return|return
name|vmls_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsq_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_laneq_u32
return|return
name|vmlsq_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_laneq_s16
return|return
name|vqdmlsl_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_laneq_s32
return|return
name|vqdmlsl_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_high_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_laneq_s16
return|return
name|vqdmlsl_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_high_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_laneq_s32
return|return
name|vqdmlsl_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int16x4_t
name|test_vqdmulh_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_laneq_s16
return|return
name|vqdmulh_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int16x8_t
name|test_vqdmulhq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_laneq_s16
return|return
name|vqdmulhq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int32x2_t
name|test_vqdmulh_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_laneq_s32
return|return
name|vqdmulh_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmulhq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_laneq_s32
return|return
name|vqdmulhq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int16x4_t
name|test_vqrdmulh_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_laneq_s16
return|return
name|vqrdmulh_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int16x8_t
name|test_vqrdmulhq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_laneq_s16
return|return
name|vqrdmulhq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.h[7]
block|}
end_function

begin_function
name|int32x2_t
name|test_vqrdmulh_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_laneq_s32
return|return
name|vqrdmulh_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vqrdmulhq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_laneq_s32
return|return
name|vqrdmulhq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

end_unit

