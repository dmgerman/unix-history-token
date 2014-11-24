begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -ffp-contract=fast -S -O3 -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: test_vdups_lane_f32
end_comment

begin_function
name|float32_t
name|test_vdups_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdups_lane_f32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ret
comment|// CHECK-NOT: dup {{s[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupd_lane_f64
end_comment

begin_function
name|float64_t
name|test_vdupd_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_lane_f64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ret
comment|// CHECK-NOT: dup {{d[0-9]+}}, {{v[0-9]+}}.d[0]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdups_laneq_f32
end_comment

begin_function
name|float32_t
name|test_vdups_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vdups_laneq_f32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ret
comment|// CHECK-NOT: dup {{s[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupd_laneq_f64
end_comment

begin_function
name|float64_t
name|test_vdupd_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_laneq_f64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ret
comment|// CHECK-NOT: dup {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupb_lane_s8
end_comment

begin_function
name|int8_t
name|test_vdupb_lane_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_lane_s8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: {{umov|smov}} {{w[0-9]+}}, {{v[0-9]+}}.b[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vduph_lane_s16
end_comment

begin_function
name|int16_t
name|test_vduph_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vduph_lane_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: {{umov|smov}} {{w[0-9]+}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdups_lane_s32
end_comment

begin_function
name|int32_t
name|test_vdups_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdups_lane_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupd_lane_s64
end_comment

begin_function
name|int64_t
name|test_vdupd_lane_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_lane_s64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupb_lane_u8
end_comment

begin_function
name|uint8_t
name|test_vdupb_lane_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_lane_u8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.b[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vduph_lane_u16
end_comment

begin_function
name|uint16_t
name|test_vduph_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vduph_lane_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdups_lane_u32
end_comment

begin_function
name|uint32_t
name|test_vdups_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdups_lane_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupd_lane_u64
end_comment

begin_function
name|uint64_t
name|test_vdupd_lane_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_lane_u64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupb_laneq_s8
end_comment

begin_function
name|int8_t
name|test_vdupb_laneq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_laneq_s8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: {{umov|smov}} {{w[0-9]+}}, {{v[0-9]+}}.b[15]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vduph_laneq_s16
end_comment

begin_function
name|int16_t
name|test_vduph_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vduph_laneq_s16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: {{umov|smov}} {{w[0-9]+}}, {{v[0-9]+}}.h[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdups_laneq_s32
end_comment

begin_function
name|int32_t
name|test_vdups_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vdups_laneq_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupd_laneq_s64
end_comment

begin_function
name|int64_t
name|test_vdupd_laneq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_laneq_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{x[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupb_laneq_u8
end_comment

begin_function
name|uint8_t
name|test_vdupb_laneq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_laneq_u8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.b[15]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vduph_laneq_u16
end_comment

begin_function
name|uint16_t
name|test_vduph_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vduph_laneq_u16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.h[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdups_laneq_u32
end_comment

begin_function
name|uint32_t
name|test_vdups_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vdups_laneq_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.s[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupd_laneq_u64
end_comment

begin_function
name|uint64_t
name|test_vdupd_laneq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_laneq_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{x[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupb_lane_p8
end_comment

begin_function
name|poly8_t
name|test_vdupb_lane_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_lane_p8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.b[7]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vduph_lane_p16
end_comment

begin_function
name|poly16_t
name|test_vduph_lane_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vduph_lane_p16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vdupb_laneq_p8
end_comment

begin_function
name|poly8_t
name|test_vdupb_laneq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_laneq_p8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.b[15]
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vduph_laneq_p16
end_comment

begin_function
name|poly16_t
name|test_vduph_laneq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vduph_laneq_p16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: {{mov|umov}} {{w[0-9]+}}, {{v[0-9]+}}.h[7]
block|}
end_function

end_unit

