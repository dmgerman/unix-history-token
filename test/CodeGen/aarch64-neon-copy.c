begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64-none-linux-gnu -target-feature +neon \
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
name|uint8x8_t
name|test_vset_lane_u8
parameter_list|(
name|uint8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_u8
return|return
name|vset_lane_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|6
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[6], {{w[0-9]+}}
block|}
end_function

begin_function
name|uint16x4_t
name|test_vset_lane_u16
parameter_list|(
name|uint16_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_u16
return|return
name|vset_lane_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{w[0-9]+}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vset_lane_u32
parameter_list|(
name|uint32_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_u32
return|return
name|vset_lane_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[1], {{w[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vset_lane_u64
parameter_list|(
name|uint64_t
name|v1
parameter_list|,
name|uint64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_u64
return|return
name|vset_lane_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|int8x8_t
name|test_vset_lane_s8
parameter_list|(
name|int8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_s8
return|return
name|vset_lane_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|6
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[6], {{w[0-9]+}}
block|}
end_function

begin_function
name|int16x4_t
name|test_vset_lane_s16
parameter_list|(
name|int16_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_s16
return|return
name|vset_lane_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{w[0-9]+}}
block|}
end_function

begin_function
name|int32x2_t
name|test_vset_lane_s32
parameter_list|(
name|int32_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_s32
return|return
name|vset_lane_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[1], {{w[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vset_lane_s64
parameter_list|(
name|int64_t
name|v1
parameter_list|,
name|int64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_s64
return|return
name|vset_lane_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|uint8x16_t
name|test_vsetq_lane_u8
parameter_list|(
name|uint8_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_u8
return|return
name|vsetq_lane_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|6
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[6], {{w[0-9]+}}
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsetq_lane_u16
parameter_list|(
name|uint16_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_u16
return|return
name|vsetq_lane_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{w[0-9]+}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsetq_lane_u32
parameter_list|(
name|uint32_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_u32
return|return
name|vsetq_lane_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[1], {{w[0-9]+}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vsetq_lane_u64
parameter_list|(
name|uint64_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_u64
return|return
name|vsetq_lane_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{x[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vsetq_lane_s8
parameter_list|(
name|int8_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_s8
return|return
name|vsetq_lane_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|6
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[6], {{w[0-9]+}}
block|}
end_function

begin_function
name|int16x8_t
name|test_vsetq_lane_s16
parameter_list|(
name|int16_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_s16
return|return
name|vsetq_lane_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{w[0-9]+}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vsetq_lane_s32
parameter_list|(
name|int32_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_s32
return|return
name|vsetq_lane_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[1], {{w[0-9]+}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vsetq_lane_s64
parameter_list|(
name|int64_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_s64
return|return
name|vsetq_lane_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.d[0], {{x[0-9]+}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vset_lane_p8
parameter_list|(
name|poly8_t
name|v1
parameter_list|,
name|poly8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_p8
return|return
name|vset_lane_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|6
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[6], {{w[0-9]+}}
block|}
end_function

begin_function
name|poly16x4_t
name|test_vset_lane_p16
parameter_list|(
name|poly16_t
name|v1
parameter_list|,
name|poly16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_p16
return|return
name|vset_lane_p16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{w[0-9]+}}
block|}
end_function

begin_function
name|poly8x16_t
name|test_vsetq_lane_p8
parameter_list|(
name|poly8_t
name|v1
parameter_list|,
name|poly8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_p8
return|return
name|vsetq_lane_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|6
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[6], {{w[0-9]+}}
block|}
end_function

begin_function
name|poly16x8_t
name|test_vsetq_lane_p16
parameter_list|(
name|poly16_t
name|v1
parameter_list|,
name|poly16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_p16
return|return
name|vsetq_lane_p16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{w[0-9]+}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vset_lane_f32
parameter_list|(
name|float32_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_f32
return|return
name|vset_lane_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[1], {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vsetq_lane_f32
parameter_list|(
name|float32_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_f32
return|return
name|vsetq_lane_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[1], {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x1_t
name|test_vset_lane_f64
parameter_list|(
name|float64_t
name|v1
parameter_list|,
name|float64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vset_lane_f64
return|return
name|vset_lane_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|float64x2_t
name|test_vsetq_lane_f64
parameter_list|(
name|float64_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vsetq_lane_f64
return|return
name|vsetq_lane_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.d[0], {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|uint8_t
name|test_vget_lane_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_u8
return|return
name|vget_lane_u8
argument_list|(
name|v1
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.b[7]
block|}
end_function

begin_function
name|uint16_t
name|test_vget_lane_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_u16
return|return
name|vget_lane_u16
argument_list|(
name|v1
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint32_t
name|test_vget_lane_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_u32
return|return
name|vget_lane_u32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint64_t
name|test_vget_lane_u64
parameter_list|(
name|uint64x1_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_u64
return|return
name|vget_lane_u64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8_t
name|test_vgetq_lane_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_u8
return|return
name|vgetq_lane_u8
argument_list|(
name|v1
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.b[15]
block|}
end_function

begin_function
name|uint16_t
name|test_vgetq_lane_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_u16
return|return
name|vgetq_lane_u16
argument_list|(
name|v1
argument_list|,
literal|6
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.h[6]
block|}
end_function

begin_function
name|uint32_t
name|test_vgetq_lane_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_u32
return|return
name|vgetq_lane_u32
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.s[2]
block|}
end_function

begin_function
name|uint64_t
name|test_vgetq_lane_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_u64
return|return
name|vgetq_lane_u64
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: umov {{x[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|poly8_t
name|test_vget_lane_p8
parameter_list|(
name|poly8x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_p8
return|return
name|vget_lane_p8
argument_list|(
name|v1
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.b[7]
block|}
end_function

begin_function
name|poly16_t
name|test_vget_lane_p16
parameter_list|(
name|poly16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_p16
return|return
name|vget_lane_p16
argument_list|(
name|v1
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|poly8_t
name|test_vgetq_lane_p8
parameter_list|(
name|poly8x16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_p8
return|return
name|vgetq_lane_p8
argument_list|(
name|v1
argument_list|,
literal|14
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.b[14]
block|}
end_function

begin_function
name|poly16_t
name|test_vgetq_lane_p16
parameter_list|(
name|poly16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_p16
return|return
name|vgetq_lane_p16
argument_list|(
name|v1
argument_list|,
literal|6
argument_list|)
return|;
comment|// CHECK: umov {{w[0-9]+}}, {{v[0-9]+}}.h[6]
block|}
end_function

begin_function
name|int32_t
name|test_vget_lane_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_s8
return|return
name|vget_lane_s8
argument_list|(
name|v1
argument_list|,
literal|7
argument_list|)
operator|+
literal|1
return|;
comment|// CHECK: smov {{w[0-9]+}}, {{v[0-9]+}}.b[7]
block|}
end_function

begin_function
name|int32_t
name|test_vget_lane_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_s16
return|return
name|vget_lane_s16
argument_list|(
name|v1
argument_list|,
literal|3
argument_list|)
operator|+
literal|1
return|;
comment|// CHECK: smov {{w[0-9]+}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int64_t
name|test_vget_lane_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_s32
return|return
name|vget_lane_s32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: smov {{x[0-9]+}}, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int64_t
name|test_vget_lane_s64
parameter_list|(
name|int64x1_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vget_lane_s64
return|return
name|vget_lane_s64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int32_t
name|test_vgetq_lane_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_s8
return|return
name|vgetq_lane_s8
argument_list|(
name|v1
argument_list|,
literal|15
argument_list|)
operator|+
literal|1
return|;
comment|// CHECK: smov {{w[0-9]+}}, {{v[0-9]+}}.b[15]
block|}
end_function

begin_function
name|int32_t
name|test_vgetq_lane_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_s16
return|return
name|vgetq_lane_s16
argument_list|(
name|v1
argument_list|,
literal|6
argument_list|)
operator|+
literal|1
return|;
comment|// CHECK: smov {{w[0-9]+}}, {{v[0-9]+}}.h[6]
block|}
end_function

begin_function
name|int64_t
name|test_vgetq_lane_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_s32
return|return
name|vgetq_lane_s32
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: smov {{x[0-9]+}}, {{v[0-9]+}}.s[2]
block|}
end_function

begin_function
name|int64_t
name|test_vgetq_lane_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vgetq_lane_s64
return|return
name|vgetq_lane_s64
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: umov {{x[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|int8x8_t
name|test_vcopy_lane_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_lane_s8
return|return
name|vcopy_lane_s8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|int16x4_t
name|test_vcopy_lane_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_lane_s16
return|return
name|vcopy_lane_s16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|poly8x8_t
name|test_vcopy_lane_p8
parameter_list|(
name|poly8x8_t
name|v1
parameter_list|,
name|poly8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_lane_p8
return|return
name|vcopy_lane_p8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|poly16x4_t
name|test_vcopy_lane_p16
parameter_list|(
name|poly16x4_t
name|v1
parameter_list|,
name|poly16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_lane_p16
return|return
name|vcopy_lane_p16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int32x2_t
name|test_vcopy_lane_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_lane_s32
return|return
name|vcopy_lane_s32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32x2_t
name|test_vcopy_lane_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_lane_f32
return|return
name|vcopy_lane_f32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint8x8_t
name|test_vcopy_lane_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_lane_u8
return|return
name|vcopy_lane_u8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vcopy_lane_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_lane_u16
return|return
name|vcopy_lane_u16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcopy_lane_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_lane_u32
return|return
name|vcopy_lane_u32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int8x8_t
name|test_vcopy_laneq_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_laneq_s8
return|return
name|vcopy_laneq_s8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|int16x4_t
name|test_vcopy_laneq_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_laneq_s16
return|return
name|vcopy_laneq_s16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|poly8x8_t
name|test_vcopy_laneq_p8
parameter_list|(
name|poly8x8_t
name|v1
parameter_list|,
name|poly8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_laneq_p8
return|return
name|vcopy_laneq_p8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|poly16x4_t
name|test_vcopy_laneq_p16
parameter_list|(
name|poly16x4_t
name|v1
parameter_list|,
name|poly16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_laneq_p16
return|return
name|vcopy_laneq_p16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int32x2_t
name|test_vcopy_laneq_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_laneq_s32
return|return
name|vcopy_laneq_s32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32x2_t
name|test_vcopy_laneq_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_laneq_f32
return|return
name|vcopy_laneq_f32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint8x8_t
name|test_vcopy_laneq_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_laneq_u8
return|return
name|vcopy_laneq_u8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vcopy_laneq_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_laneq_u16
return|return
name|vcopy_laneq_u16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcopy_laneq_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopy_laneq_u32
return|return
name|vcopy_laneq_u32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int8x16_t
name|test_vcopyq_lane_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_s8
return|return
name|vcopyq_lane_s8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|int16x8_t
name|test_vcopyq_lane_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_s16
return|return
name|vcopyq_lane_s16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|poly8x16_t
name|test_vcopyq_lane_p8
parameter_list|(
name|poly8x16_t
name|v1
parameter_list|,
name|poly8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_p8
return|return
name|vcopyq_lane_p8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|poly16x8_t
name|test_vcopyq_lane_p16
parameter_list|(
name|poly16x8_t
name|v1
parameter_list|,
name|poly16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_p16
return|return
name|vcopyq_lane_p16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vcopyq_lane_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_s32
return|return
name|vcopyq_lane_s32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int64x2_t
name|test_vcopyq_lane_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_s64
return|return
name|vcopyq_lane_s64
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|,
name|v2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vcopyq_lane_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_f32
return|return
name|vcopyq_lane_f32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float64x2_t
name|test_vcopyq_lane_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_f64
return|return
name|vcopyq_lane_f64
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|,
name|v2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcopyq_lane_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_u8
return|return
name|vcopyq_lane_u8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcopyq_lane_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_u16
return|return
name|vcopyq_lane_u16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcopyq_lane_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_u32
return|return
name|vcopyq_lane_u32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcopyq_lane_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_lane_u64
return|return
name|vcopyq_lane_u64
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|,
name|v2
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|int8x16_t
name|test_vcopyq_laneq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_s8
return|return
name|vcopyq_laneq_s8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|int16x8_t
name|test_vcopyq_laneq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_s16
return|return
name|vcopyq_laneq_s16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|poly8x16_t
name|test_vcopyq_laneq_p8
parameter_list|(
name|poly8x16_t
name|v1
parameter_list|,
name|poly8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_p8
return|return
name|vcopyq_laneq_p8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|poly16x8_t
name|test_vcopyq_laneq_p16
parameter_list|(
name|poly16x8_t
name|v1
parameter_list|,
name|poly16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_p16
return|return
name|vcopyq_laneq_p16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|int32x4_t
name|test_vcopyq_laneq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_s32
return|return
name|vcopyq_laneq_s32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float32x4_t
name|test_vcopyq_laneq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_f32
return|return
name|vcopyq_laneq_f32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int64x2_t
name|test_vcopyq_laneq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_s64
return|return
name|vcopyq_laneq_s64
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcopyq_laneq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_u8
return|return
name|vcopyq_laneq_u8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.b[5], {{v[0-9]+}}.b[3]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcopyq_laneq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_u16
return|return
name|vcopyq_laneq_u16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|,
name|v2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[2], {{v[0-9]+}}.h[3]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcopyq_laneq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_u32
return|return
name|vcopyq_laneq_u32
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.s[0], {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcopyq_laneq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK: test_vcopyq_laneq_u64
return|return
name|vcopyq_laneq_u64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|,
name|v2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.d[0], {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|int8x8_t
name|test_vcreate_s8
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_s8
return|return
name|vcreate_s8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|int16x4_t
name|test_vcreate_s16
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_s16
return|return
name|vcreate_s16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|int32x2_t
name|test_vcreate_s32
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_s32
return|return
name|vcreate_s32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vcreate_s64
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_s64
return|return
name|vcreate_s64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vcreate_u8
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_u8
return|return
name|vcreate_u8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|uint16x4_t
name|test_vcreate_u16
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_u16
return|return
name|vcreate_u16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcreate_u32
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_u32
return|return
name|vcreate_u32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcreate_u64
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_u64
return|return
name|vcreate_u64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vcreate_p8
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_p8
return|return
name|vcreate_p8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly16x4_t
name|test_vcreate_p16
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_p16
return|return
name|vcreate_p16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|float16x4_t
name|test_vcreate_f16
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_f16
return|return
name|vcreate_f16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vcreate_f32
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_f32
return|return
name|vcreate_f32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vcreate_f64
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vcreate_f64
return|return
name|vcreate_f64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vdup_n_u8
parameter_list|(
name|uint8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_u8
return|return
name|vdup_n_u8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint16x4_t
name|test_vdup_n_u16
parameter_list|(
name|uint16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_u16
return|return
name|vdup_n_u16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vdup_n_u32
parameter_list|(
name|uint32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_u32
return|return
name|vdup_n_u32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vdup_n_u64
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_u64
return|return
name|vdup_n_u64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|uint8x16_t
name|test_vdupq_n_u8
parameter_list|(
name|uint8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_u8
return|return
name|vdupq_n_u8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint16x8_t
name|test_vdupq_n_u16
parameter_list|(
name|uint16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_u16
return|return
name|vdupq_n_u16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vdupq_n_u32
parameter_list|(
name|uint32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_u32
return|return
name|vdupq_n_u32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vdupq_n_u64
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_u64
return|return
name|vdupq_n_u64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{x[0-9]+}}
block|}
end_function

begin_function
name|int8x8_t
name|test_vdup_n_s8
parameter_list|(
name|int8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_s8
return|return
name|vdup_n_s8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{w[0-9]+}}
block|}
end_function

begin_function
name|int16x4_t
name|test_vdup_n_s16
parameter_list|(
name|int16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_s16
return|return
name|vdup_n_s16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{w[0-9]+}}
block|}
end_function

begin_function
name|int32x2_t
name|test_vdup_n_s32
parameter_list|(
name|int32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_s32
return|return
name|vdup_n_s32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{w[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vdup_n_s64
parameter_list|(
name|int64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_s64
return|return
name|vdup_n_s64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vdupq_n_s8
parameter_list|(
name|int8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_s8
return|return
name|vdupq_n_s8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{w[0-9]+}}
block|}
end_function

begin_function
name|int16x8_t
name|test_vdupq_n_s16
parameter_list|(
name|int16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_s16
return|return
name|vdupq_n_s16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{w[0-9]+}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vdupq_n_s32
parameter_list|(
name|int32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_s32
return|return
name|vdupq_n_s32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{w[0-9]+}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vdupq_n_s64
parameter_list|(
name|int64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_s64
return|return
name|vdupq_n_s64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vdup_n_p8
parameter_list|(
name|poly8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_p8
return|return
name|vdup_n_p8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{w[0-9]+}}
block|}
end_function

begin_function
name|poly16x4_t
name|test_vdup_n_p16
parameter_list|(
name|poly16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_p16
return|return
name|vdup_n_p16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{w[0-9]+}}
block|}
end_function

begin_function
name|poly8x16_t
name|test_vdupq_n_p8
parameter_list|(
name|poly8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_p8
return|return
name|vdupq_n_p8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{w[0-9]+}}
block|}
end_function

begin_function
name|poly16x8_t
name|test_vdupq_n_p16
parameter_list|(
name|poly16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_p16
return|return
name|vdupq_n_p16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{w[0-9]+}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vdup_n_f32
parameter_list|(
name|float32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_f32
return|return
name|vdup_n_f32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x1_t
name|test_vdup_n_f64
parameter_list|(
name|float64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_n_f64
return|return
name|vdup_n_f64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|float32x4_t
name|test_vdupq_n_f32
parameter_list|(
name|float32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_f32
return|return
name|vdupq_n_f32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vdupq_n_f64
parameter_list|(
name|float64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_n_f64
return|return
name|vdupq_n_f64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|int8x8_t
name|test_vdup_lane_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_s8
return|return
name|vdup_lane_s8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|int16x4_t
name|test_vdup_lane_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_s16
return|return
name|vdup_lane_s16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|int32x2_t
name|test_vdup_lane_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_s32
return|return
name|vdup_lane_s32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int64x1_t
name|test_vdup_lane_s64
parameter_list|(
name|int64x1_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_s64
return|return
name|vdup_lane_s64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|int8x16_t
name|test_vdupq_lane_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_s8
return|return
name|vdupq_lane_s8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|int16x8_t
name|test_vdupq_lane_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_s16
return|return
name|vdupq_lane_s16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|int32x4_t
name|test_vdupq_lane_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_s32
return|return
name|vdupq_lane_s32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int64x2_t
name|test_vdupq_lane_s64
parameter_list|(
name|int64x1_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_s64
return|return
name|vdupq_lane_s64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|uint8x8_t
name|test_vdup_lane_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_u8
return|return
name|vdup_lane_u8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vdup_lane_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_u16
return|return
name|vdup_lane_u16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vdup_lane_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_u32
return|return
name|vdup_lane_u32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint64x1_t
name|test_vdup_lane_u64
parameter_list|(
name|uint64x1_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_u64
return|return
name|vdup_lane_u64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|uint8x16_t
name|test_vdupq_lane_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_u8
return|return
name|vdupq_lane_u8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vdupq_lane_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_u16
return|return
name|vdupq_lane_u16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vdupq_lane_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_u32
return|return
name|vdupq_lane_u32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vdupq_lane_u64
parameter_list|(
name|uint64x1_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_u64
return|return
name|vdupq_lane_u64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|int8x8_t
name|test_vdup_laneq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_s8
return|return
name|vdup_laneq_s8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|int16x4_t
name|test_vdup_laneq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_s16
return|return
name|vdup_laneq_s16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|int32x2_t
name|test_vdup_laneq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_s32
return|return
name|vdup_laneq_s32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int64x1_t
name|test_vdup_laneq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_s64
return|return
name|vdup_laneq_s64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|int8x16_t
name|test_vdupq_laneq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_s8
return|return
name|vdupq_laneq_s8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|int16x8_t
name|test_vdupq_laneq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_s16
return|return
name|vdupq_laneq_s16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|int32x4_t
name|test_vdupq_laneq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_s32
return|return
name|vdupq_laneq_s32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|int64x2_t
name|test_vdupq_laneq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_s64
return|return
name|vdupq_laneq_s64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|uint8x8_t
name|test_vdup_laneq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_u8
return|return
name|vdup_laneq_u8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vdup_laneq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_u16
return|return
name|vdup_laneq_u16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vdup_laneq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_u32
return|return
name|vdup_laneq_u32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint64x1_t
name|test_vdup_laneq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_u64
return|return
name|vdup_laneq_u64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|uint8x16_t
name|test_vdupq_laneq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_u8
return|return
name|vdupq_laneq_u8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vdupq_laneq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_u16
return|return
name|vdupq_laneq_u16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vdupq_laneq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_u32
return|return
name|vdupq_laneq_u32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vdupq_laneq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_u64
return|return
name|vdupq_laneq_u64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|poly8x8_t
name|test_vdup_lane_p8
parameter_list|(
name|poly8x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_p8
return|return
name|vdup_lane_p8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|poly16x4_t
name|test_vdup_lane_p16
parameter_list|(
name|poly16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_p16
return|return
name|vdup_lane_p16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|poly8x16_t
name|test_vdupq_lane_p8
parameter_list|(
name|poly8x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_p8
return|return
name|vdupq_lane_p8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|poly16x8_t
name|test_vdupq_lane_p16
parameter_list|(
name|poly16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_p16
return|return
name|vdupq_lane_p16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|poly8x8_t
name|test_vdup_laneq_p8
parameter_list|(
name|poly8x16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_p8
return|return
name|vdup_laneq_p8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|poly16x4_t
name|test_vdup_laneq_p16
parameter_list|(
name|poly16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_p16
return|return
name|vdup_laneq_p16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|poly8x16_t
name|test_vdupq_laneq_p8
parameter_list|(
name|poly8x16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_p8
return|return
name|vdupq_laneq_p8
argument_list|(
name|v1
argument_list|,
literal|5
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{v[0-9]+}}.b[5]
block|}
end_function

begin_function
name|poly16x8_t
name|test_vdupq_laneq_p16
parameter_list|(
name|poly16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_p16
return|return
name|vdupq_laneq_p16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|float16x4_t
name|test_vdup_lane_f16
parameter_list|(
name|float16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_f16
return|return
name|vdup_lane_f16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|float32x2_t
name|test_vdup_lane_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_f32
return|return
name|vdup_lane_f32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float64x1_t
name|test_vdup_lane_f64
parameter_list|(
name|float64x1_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_lane_f64
return|return
name|vdup_lane_f64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|float16x4_t
name|test_vdup_laneq_f16
parameter_list|(
name|float16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_f16
return|return
name|vdup_laneq_f16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|float32x2_t
name|test_vdup_laneq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_f32
return|return
name|vdup_laneq_f32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float64x1_t
name|test_vdup_laneq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdup_laneq_f64
return|return
name|vdup_laneq_f64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|float16x8_t
name|test_vdupq_lane_f16
parameter_list|(
name|float16x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_f16
return|return
name|vdupq_lane_f16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|float32x4_t
name|test_vdupq_lane_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_f32
return|return
name|vdupq_lane_f32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float64x2_t
name|test_vdupq_lane_f64
parameter_list|(
name|float64x1_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_lane_f64
return|return
name|vdupq_lane_f64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|float16x8_t
name|test_vdupq_laneq_f16
parameter_list|(
name|float16x8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_f16
return|return
name|vdupq_laneq_f16
argument_list|(
name|v1
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{v[0-9]+}}.h[2]
block|}
end_function

begin_function
name|float32x4_t
name|test_vdupq_laneq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_f32
return|return
name|vdupq_laneq_f32
argument_list|(
name|v1
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

begin_function
name|float64x2_t
name|test_vdupq_laneq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vdupq_laneq_f64
return|return
name|vdupq_laneq_f64
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|int8x8_t
name|test_vmov_n_s8
parameter_list|(
name|int8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_s8
return|return
name|vmov_n_s8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{w[0-9]+}}
block|}
end_function

begin_function
name|int16x4_t
name|test_vmov_n_s16
parameter_list|(
name|int16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_s16
return|return
name|vmov_n_s16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{w[0-9]+}}
block|}
end_function

begin_function
name|int32x2_t
name|test_vmov_n_s32
parameter_list|(
name|int32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_s32
return|return
name|vmov_n_s32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{w[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vmov_n_s64
parameter_list|(
name|int64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_s64
return|return
name|vmov_n_s64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vmovq_n_s8
parameter_list|(
name|int8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_s8
return|return
name|vmovq_n_s8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{w[0-9]+}}
block|}
end_function

begin_function
name|int16x8_t
name|test_vmovq_n_s16
parameter_list|(
name|int16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_s16
return|return
name|vmovq_n_s16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{w[0-9]+}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vmovq_n_s32
parameter_list|(
name|int32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_s32
return|return
name|vmovq_n_s32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{w[0-9]+}}
block|}
end_function

begin_function
name|int64x2_t
name|test_vmovq_n_s64
parameter_list|(
name|int64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_s64
return|return
name|vmovq_n_s64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{x[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vmov_n_u8
parameter_list|(
name|uint8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_u8
return|return
name|vmov_n_u8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmov_n_u16
parameter_list|(
name|uint16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_u16
return|return
name|vmov_n_u16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmov_n_u32
parameter_list|(
name|uint32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_u32
return|return
name|vmov_n_u32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vmov_n_u64
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_u64
return|return
name|vmov_n_u64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|uint8x16_t
name|test_vmovq_n_u8
parameter_list|(
name|uint8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_u8
return|return
name|vmovq_n_u8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmovq_n_u16
parameter_list|(
name|uint16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_u16
return|return
name|vmovq_n_u16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmovq_n_u32
parameter_list|(
name|uint32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_u32
return|return
name|vmovq_n_u32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{w[0-9]+}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmovq_n_u64
parameter_list|(
name|uint64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_u64
return|return
name|vmovq_n_u64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vmov_n_p8
parameter_list|(
name|poly8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_p8
return|return
name|vmov_n_p8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8b, {{w[0-9]+}}
block|}
end_function

begin_function
name|poly16x4_t
name|test_vmov_n_p16
parameter_list|(
name|poly16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_p16
return|return
name|vmov_n_p16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4h, {{w[0-9]+}}
block|}
end_function

begin_function
name|poly8x16_t
name|test_vmovq_n_p8
parameter_list|(
name|poly8_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_p8
return|return
name|vmovq_n_p8
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.16b, {{w[0-9]+}}
block|}
end_function

begin_function
name|poly16x8_t
name|test_vmovq_n_p16
parameter_list|(
name|poly16_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_p16
return|return
name|vmovq_n_p16
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.8h, {{w[0-9]+}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vmov_n_f32
parameter_list|(
name|float32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_f32
return|return
name|vmov_n_f32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x1_t
name|test_vmov_n_f64
parameter_list|(
name|float64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmov_n_f64
return|return
name|vmov_n_f64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|float32x4_t
name|test_vmovq_n_f32
parameter_list|(
name|float32_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_f32
return|return
name|vmovq_n_f32
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vmovq_n_f64
parameter_list|(
name|float64_t
name|v1
parameter_list|)
block|{
comment|// CHECK: test_vmovq_n_f64
return|return
name|vmovq_n_f64
argument_list|(
name|v1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_comment
comment|// CHECK: test_vcopy_lane_s64
end_comment

begin_function
name|int64x1_t
name|test_vcopy_lane_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|c
parameter_list|)
block|{
return|return
name|vcopy_lane_s64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
name|c
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{d[0-9]+}}
comment|// CHECK-NOT: dup {{d[0-9]+}}, {{v[0-9]+}}.d[0]
block|}
end_function

begin_comment
comment|// CHECK: test_vcopy_lane_u64
end_comment

begin_function
name|uint64x1_t
name|test_vcopy_lane_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|c
parameter_list|)
block|{
return|return
name|vcopy_lane_u64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
name|c
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{d[0-9]+}}
comment|// CHECK-NOT: dup {{d[0-9]+}}, {{v[0-9]+}}.d[0]
block|}
end_function

begin_comment
comment|// CHECK: test_vcopy_lane_f64
end_comment

begin_function
name|float64x1_t
name|test_vcopy_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|c
parameter_list|)
block|{
return|return
name|vcopy_lane_f64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
name|c
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{d[0-9]+}}
comment|// CHECK-NOT: dup {{d[0-9]+}}, {{v[0-9]+}}.d[0]
block|}
end_function

begin_comment
comment|// CHECK: test_vcopy_laneq_s64
end_comment

begin_function
name|int64x1_t
name|test_vcopy_laneq_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x2_t
name|c
parameter_list|)
block|{
return|return
name|vcopy_laneq_s64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK: test_vcopy_laneq_u64
end_comment

begin_function
name|uint64x1_t
name|test_vcopy_laneq_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x2_t
name|c
parameter_list|)
block|{
return|return
name|vcopy_laneq_u64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK: test_vcopy_laneq_f64
end_comment

begin_function
name|float64x1_t
name|test_vcopy_laneq_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x2_t
name|c
parameter_list|)
block|{
return|return
name|vcopy_laneq_f64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK: test_vcopy_laneq_p64
end_comment

begin_function
name|poly64x1_t
name|test_vcopy_laneq_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x2_t
name|c
parameter_list|)
block|{
return|return
name|vcopy_laneq_p64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{d[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_comment
comment|// CHECK: test_vcopyq_laneq_f64
end_comment

begin_function
name|float64x2_t
name|test_vcopyq_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|c
parameter_list|)
block|{
comment|// CHECK: ins  {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[1]
return|return
name|vcopyq_laneq_f64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK: test_vget_lane_f16
end_comment

begin_function
name|int
name|test_vget_lane_f16
parameter_list|(
name|float16x4_t
name|v1
parameter_list|)
block|{
name|float16_t
name|a
init|=
name|vget_lane_f16
argument_list|(
name|v1
argument_list|,
literal|3
argument_list|)
decl_stmt|;
return|return
operator|(
name|int
operator|)
name|a
return|;
comment|// CHECK: dup {{h[0-9]+}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK: test_vgetq_lane_f16
end_comment

begin_function
name|int
name|test_vgetq_lane_f16
parameter_list|(
name|float16x8_t
name|v1
parameter_list|)
block|{
name|float16_t
name|a
init|=
name|vgetq_lane_f16
argument_list|(
name|v1
argument_list|,
literal|7
argument_list|)
decl_stmt|;
return|return
operator|(
name|int
operator|)
name|a
return|;
comment|// CHECK: dup {{h[0-9]+}}, {{v[0-9]+}}.h[7]
block|}
end_function

begin_comment
comment|// CHECK: test_vget_lane_f16_2
end_comment

begin_function
name|float
name|test_vget_lane_f16_2
parameter_list|(
name|float16x4_t
name|v1
parameter_list|)
block|{
name|float16_t
name|a
init|=
name|vget_lane_f16
argument_list|(
name|v1
argument_list|,
literal|3
argument_list|)
decl_stmt|;
return|return
operator|(
name|float
operator|)
name|a
return|;
comment|// CHECK: dup {{h[0-9]+}}, {{v[0-9]+}}.h[3]
block|}
end_function

begin_comment
comment|// CHECK: test_vgetq_lane_f16_2
end_comment

begin_function
name|float
name|test_vgetq_lane_f16_2
parameter_list|(
name|float16x8_t
name|v1
parameter_list|)
block|{
name|float16_t
name|a
init|=
name|vgetq_lane_f16
argument_list|(
name|v1
argument_list|,
literal|7
argument_list|)
decl_stmt|;
return|return
operator|(
name|float
operator|)
name|a
return|;
comment|// CHECK: dup {{h[0-9]+}}, {{v[0-9]+}}.h[7]
block|}
end_function

begin_comment
comment|// CHECK: test_vset_lane_f16
end_comment

begin_function
name|float16x4_t
name|test_vset_lane_f16
parameter_list|(
name|float16x4_t
name|v1
parameter_list|)
block|{
name|float16_t
name|a
decl_stmt|;
return|return
name|vset_lane_f16
argument_list|(
name|a
argument_list|,
name|v1
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: fmov  {{s[0-9]+}}, wzr
comment|// CHECK-NEXT: ins {{v[0-9]+}}.h[3],  {{v[0-9]+}}.h[0]
block|}
end_function

begin_comment
comment|// CHECK: test_vsetq_lane_f16
end_comment

begin_function
name|float16x8_t
name|test_vsetq_lane_f16
parameter_list|(
name|float16x8_t
name|v1
parameter_list|)
block|{
name|float16_t
name|a
decl_stmt|;
return|return
name|vsetq_lane_f16
argument_list|(
name|a
argument_list|,
name|v1
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: fmov  {{s[0-9]+}}, wzr
comment|// CHECK-NEXT: ins {{v[0-9]+}}.h[7],  {{v[0-9]+}}.h[0]
block|}
end_function

begin_comment
comment|// CHECK: test_vset_lane_f16_2
end_comment

begin_function
name|float16x4_t
name|test_vset_lane_f16_2
parameter_list|(
name|float16x4_t
name|v1
parameter_list|)
block|{
name|float16_t
name|a
init|=
name|vget_lane_f16
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
return|return
name|vset_lane_f16
argument_list|(
name|a
argument_list|,
name|v1
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[3],  {{v[0-9]+}}.h[0]
block|}
end_function

begin_comment
comment|// CHECK: test_vsetq_lane_f16_2
end_comment

begin_function
name|float16x8_t
name|test_vsetq_lane_f16_2
parameter_list|(
name|float16x8_t
name|v1
parameter_list|)
block|{
name|float16_t
name|a
init|=
name|vgetq_lane_f16
argument_list|(
name|v1
argument_list|,
literal|0
argument_list|)
decl_stmt|;
return|return
name|vsetq_lane_f16
argument_list|(
name|a
argument_list|,
name|v1
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[7],  {{v[0-9]+}}.h[0]
block|}
end_function

begin_comment
comment|// CHECK: test_vsetq_lane_f16_3
end_comment

begin_function
name|float16x8_t
name|test_vsetq_lane_f16_3
parameter_list|(
name|float16x8_t
name|v1
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|)
block|{
name|float16_t
name|a
init|=
operator|(
name|float16_t
operator|)
name|b
decl_stmt|;
return|return
name|vsetq_lane_f16
argument_list|(
name|a
argument_list|,
name|v1
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[7],  {{w[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK: test_vsetq_lane_f16_4
end_comment

begin_function
name|float16x8_t
name|test_vsetq_lane_f16_4
parameter_list|(
name|float16x8_t
name|v1
parameter_list|,
name|float
name|b
parameter_list|,
name|float
name|c
parameter_list|)
block|{
name|float16_t
name|a
init|=
operator|(
name|float16_t
operator|)
name|b
operator|+
literal|1.0
decl_stmt|;
return|return
name|vsetq_lane_f16
argument_list|(
name|a
argument_list|,
name|v1
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.h[7],  {{w[0-9]+}}
block|}
end_function

end_unit

