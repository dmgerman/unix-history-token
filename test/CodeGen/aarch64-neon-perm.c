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

begin_comment
comment|// Test new aarch64 intrinsics and types
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int8x8_t
name|test_vuzp1_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1_s8
return|return
name|vuzp1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vuzp1q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_s8
return|return
name|vuzp1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vuzp1_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1_s16
return|return
name|vuzp1_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vuzp1q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_s16
return|return
name|vuzp1q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vuzp1_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1_s32
return|return
name|vuzp1_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vuzp1q_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_s32
return|return
name|vuzp1q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vuzp1q_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_s64
return|return
name|vuzp1q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[1\], v[0-9]+.d\[0\]|zip1 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vuzp1_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1_u8
return|return
name|vuzp1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vuzp1q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_u8
return|return
name|vuzp1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vuzp1_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1_u16
return|return
name|vuzp1_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vuzp1q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_u16
return|return
name|vuzp1q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vuzp1_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1_u32
return|return
name|vuzp1_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vuzp1q_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_u32
return|return
name|vuzp1q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vuzp1q_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_u64
return|return
name|vuzp1q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[1\], v[0-9]+.d\[0\]|zip1 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vuzp1_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1_f32
return|return
name|vuzp1_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x4_t
name|test_vuzp1q_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_f32
return|return
name|vuzp1q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vuzp1q_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_f64
return|return
name|vuzp1q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[1\], v[0-9]+.d\[0\]|zip1 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vuzp1_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1_p8
return|return
name|vuzp1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vuzp1q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_p8
return|return
name|vuzp1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x4_t
name|test_vuzp1_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1_p16
return|return
name|vuzp1_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|poly16x8_t
name|test_vuzp1q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_p16
return|return
name|vuzp1q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int8x8_t
name|test_vuzp2_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2_s8
return|return
name|vuzp2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vuzp2q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_s8
return|return
name|vuzp2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vuzp2_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2_s16
return|return
name|vuzp2_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vuzp2q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_s16
return|return
name|vuzp2q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vuzp2_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2_s32
return|return
name|vuzp2_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vuzp2q_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_s32
return|return
name|vuzp2q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vuzp2q_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_s64
return|return
name|vuzp2q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[0\], v[0-9]+.d\[1\]|zip2 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vuzp2_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2_u8
return|return
name|vuzp2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vuzp2q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_u8
return|return
name|vuzp2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vuzp2_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2_u16
return|return
name|vuzp2_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vuzp2q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_u16
return|return
name|vuzp2q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vuzp2_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2_u32
return|return
name|vuzp2_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vuzp2q_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_u32
return|return
name|vuzp2q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vuzp2q_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_u64
return|return
name|vuzp2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[0\], v[0-9]+.d\[1\]|zip2 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vuzp2_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2_f32
return|return
name|vuzp2_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x4_t
name|test_vuzp2q_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_f32
return|return
name|vuzp2q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vuzp2q_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_f64
return|return
name|vuzp2q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[0\], v[0-9]+.d\[1\]|zip2 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vuzp2_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2_p8
return|return
name|vuzp2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vuzp2q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_p8
return|return
name|vuzp2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x4_t
name|test_vuzp2_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2_p16
return|return
name|vuzp2_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|poly16x8_t
name|test_vuzp2q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_p16
return|return
name|vuzp2q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int8x8_t
name|test_vzip1_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1_s8
return|return
name|vzip1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vzip1q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_s8
return|return
name|vzip1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vzip1_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1_s16
return|return
name|vzip1_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vzip1q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_s16
return|return
name|vzip1q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vzip1_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1_s32
return|return
name|vzip1_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vzip1q_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_s32
return|return
name|vzip1q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vzip1q_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_s64
return|return
name|vzip1q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[1\], v[0-9]+.d\[0\]|zip1 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vzip1_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1_u8
return|return
name|vzip1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vzip1q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_u8
return|return
name|vzip1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vzip1_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1_u16
return|return
name|vzip1_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vzip1q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_u16
return|return
name|vzip1q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vzip1_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1_u32
return|return
name|vzip1_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vzip1q_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_u32
return|return
name|vzip1q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vzip1q_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_u64
return|return
name|vzip1q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[1\], v[0-9]+.d\[0\]|zip1 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vzip1_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1_f32
return|return
name|vzip1_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x4_t
name|test_vzip1q_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_f32
return|return
name|vzip1q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vzip1q_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_f64
return|return
name|vzip1q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[1\], v[0-9]+.d\[0\]|zip1 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vzip1_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1_p8
return|return
name|vzip1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vzip1q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_p8
return|return
name|vzip1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x4_t
name|test_vzip1_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1_p16
return|return
name|vzip1_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|poly16x8_t
name|test_vzip1q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_p16
return|return
name|vzip1q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int8x8_t
name|test_vzip2_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2_s8
return|return
name|vzip2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vzip2q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_s8
return|return
name|vzip2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vzip2_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2_s16
return|return
name|vzip2_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vzip2q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_s16
return|return
name|vzip2q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vzip2_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2_s32
return|return
name|vzip2_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vzip2q_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_s32
return|return
name|vzip2q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vzip2q_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_s64
return|return
name|vzip2q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[0\], v[0-9]+.d\[1\]|zip2 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vzip2_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2_u8
return|return
name|vzip2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vzip2q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_u8
return|return
name|vzip2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vzip2_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2_u16
return|return
name|vzip2_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vzip2q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_u16
return|return
name|vzip2q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vzip2_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2_u32
return|return
name|vzip2_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vzip2q_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_u32
return|return
name|vzip2q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vzip2q_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_u64
return|return
name|vzip2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[0\], v[0-9]+.d\[1\]|zip2 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vzip2_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2_f32
return|return
name|vzip2_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x4_t
name|test_vzip2q_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_f32
return|return
name|vzip2q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vzip2q_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_f64
return|return
name|vzip2q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[0\], v[0-9]+.d\[1\]|zip2 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vzip2_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2_p8
return|return
name|vzip2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vzip2q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_p8
return|return
name|vzip2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x4_t
name|test_vzip2_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2_p16
return|return
name|vzip2_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|poly16x8_t
name|test_vzip2q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_p16
return|return
name|vzip2q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int8x8_t
name|test_vtrn1_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1_s8
return|return
name|vtrn1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vtrn1q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_s8
return|return
name|vtrn1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vtrn1_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1_s16
return|return
name|vtrn1_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vtrn1q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_s16
return|return
name|vtrn1q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vtrn1_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1_s32
return|return
name|vtrn1_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vtrn1q_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_s32
return|return
name|vtrn1q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vtrn1q_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_s64
return|return
name|vtrn1q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[1\], v[0-9]+.d\[0\]|zip1 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtrn1_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1_u8
return|return
name|vtrn1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vtrn1q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_u8
return|return
name|vtrn1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vtrn1_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1_u16
return|return
name|vtrn1_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vtrn1q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_u16
return|return
name|vtrn1q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vtrn1_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1_u32
return|return
name|vtrn1_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vtrn1q_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_u32
return|return
name|vtrn1q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vtrn1q_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_u64
return|return
name|vtrn1q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[1\], v[0-9]+.d\[0\]|zip1 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vtrn1_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1_f32
return|return
name|vtrn1_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x4_t
name|test_vtrn1q_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_f32
return|return
name|vtrn1q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vtrn1q_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_f64
return|return
name|vtrn1q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[1\], v[0-9]+.d\[0\]|zip1 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtrn1_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1_p8
return|return
name|vtrn1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vtrn1q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_p8
return|return
name|vtrn1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x4_t
name|test_vtrn1_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1_p16
return|return
name|vtrn1_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|poly16x8_t
name|test_vtrn1q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_p16
return|return
name|vtrn1q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int8x8_t
name|test_vtrn2_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2_s8
return|return
name|vtrn2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vtrn2q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_s8
return|return
name|vtrn2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x4_t
name|test_vtrn2_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2_s16
return|return
name|vtrn2_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16x8_t
name|test_vtrn2q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_s16
return|return
name|vtrn2q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x2_t
name|test_vtrn2_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2_s32
return|return
name|vtrn2_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|int32x4_t
name|test_vtrn2q_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_s32
return|return
name|vtrn2q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vtrn2q_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_s64
return|return
name|vtrn2q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[0\], v[0-9]+.d\[1\]|zip2 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtrn2_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2_u8
return|return
name|vtrn2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vtrn2q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_u8
return|return
name|vtrn2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vtrn2_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2_u16
return|return
name|vtrn2_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vtrn2q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_u16
return|return
name|vtrn2q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vtrn2_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2_u32
return|return
name|vtrn2_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vtrn2q_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_u32
return|return
name|vtrn2q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vtrn2q_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_u64
return|return
name|vtrn2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[0\], v[0-9]+.d\[1\]|zip2 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vtrn2_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2_f32
return|return
name|vtrn2_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v0.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x4_t
name|test_vtrn2q_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_f32
return|return
name|vtrn2q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vtrn2q_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_f64
return|return
name|vtrn2q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.d\[0\], v[0-9]+.d\[1\]|zip2 v0.2d, v0.2d, v1.2d}}
block|}
end_function

begin_function
name|poly8x8_t
name|test_vtrn2_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2_p8
return|return
name|vtrn2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vtrn2q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_p8
return|return
name|vtrn2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x4_t
name|test_vtrn2_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2_p16
return|return
name|vtrn2_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|poly16x8_t
name|test_vtrn2q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_p16
return|return
name|vtrn2q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int8x8x2_t
name|test_vuzp_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp_s8
return|return
name|vuzp_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: uzp2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4x2_t
name|test_vuzp_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp_s16
return|return
name|vuzp_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
comment|// CHECK: uzp2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2x2_t
name|test_vuzp_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp_s32
return|return
name|vuzp_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v2.2s, v0.2s, v1.2s}}
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v1.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|uint8x8x2_t
name|test_vuzp_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp_u8
return|return
name|vuzp_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: uzp2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4x2_t
name|test_vuzp_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp_u16
return|return
name|vuzp_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
comment|// CHECK: uzp2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2x2_t
name|test_vuzp_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp_u32
return|return
name|vuzp_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v2.2s, v0.2s, v1.2s}}
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v1.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x2x2_t
name|test_vuzp_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp_f32
return|return
name|vuzp_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v2.2s, v0.2s, v1.2s}}
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v1.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|poly8x8x2_t
name|test_vuzp_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp_p8
return|return
name|vuzp_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: uzp2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly16x4x2_t
name|test_vuzp_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp_p16
return|return
name|vuzp_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
comment|// CHECK: uzp2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int8x16x2_t
name|test_vuzpq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzpq_s8
return|return
name|vuzpq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
comment|// CHECK: uzp2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8x2_t
name|test_vuzpq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzpq_s16
return|return
name|vuzpq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
comment|// CHECK: uzp2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4x2_t
name|test_vuzpq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzpq_s32
return|return
name|vuzpq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: uzp2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16x2_t
name|test_vuzpq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzpq_u8
return|return
name|vuzpq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
comment|// CHECK: uzp2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8x2_t
name|test_vuzpq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzpq_u16
return|return
name|vuzpq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
comment|// CHECK: uzp2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4x2_t
name|test_vuzpq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzpq_u32
return|return
name|vuzpq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: uzp2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4x2_t
name|test_vuzpq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzpq_f32
return|return
name|vuzpq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: uzp2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|poly8x16x2_t
name|test_vuzpq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzpq_p8
return|return
name|vuzpq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
comment|// CHECK: uzp2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x8x2_t
name|test_vuzpq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzpq_p16
return|return
name|vuzpq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uzp1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
comment|// CHECK: uzp2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int8x8x2_t
name|test_vzip_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip_s8
return|return
name|vzip_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: zip2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4x2_t
name|test_vzip_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip_s16
return|return
name|vzip_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
comment|// CHECK: zip2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2x2_t
name|test_vzip_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip_s32
return|return
name|vzip_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v2.2s, v0.2s, v1.2s}}
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v1.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|uint8x8x2_t
name|test_vzip_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip_u8
return|return
name|vzip_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: zip2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4x2_t
name|test_vzip_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip_u16
return|return
name|vzip_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
comment|// CHECK: zip2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2x2_t
name|test_vzip_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip_u32
return|return
name|vzip_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v2.2s, v0.2s, v1.2s}}
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v1.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x2x2_t
name|test_vzip_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip_f32
return|return
name|vzip_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v2.2s, v0.2s, v1.2s}}
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v1.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|poly8x8x2_t
name|test_vzip_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip_p8
return|return
name|vzip_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: zip2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly16x4x2_t
name|test_vzip_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip_p16
return|return
name|vzip_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
comment|// CHECK: zip2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int8x16x2_t
name|test_vzipq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzipq_s8
return|return
name|vzipq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
comment|// CHECK: zip2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8x2_t
name|test_vzipq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzipq_s16
return|return
name|vzipq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
comment|// CHECK: zip2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4x2_t
name|test_vzipq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzipq_s32
return|return
name|vzipq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: zip2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16x2_t
name|test_vzipq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzipq_u8
return|return
name|vzipq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
comment|// CHECK: zip2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8x2_t
name|test_vzipq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzipq_u16
return|return
name|vzipq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
comment|// CHECK: zip2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4x2_t
name|test_vzipq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzipq_u32
return|return
name|vzipq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: zip2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4x2_t
name|test_vzipq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzipq_f32
return|return
name|vzipq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: zip2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|poly8x16x2_t
name|test_vzipq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzipq_p8
return|return
name|vzipq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
comment|// CHECK: zip2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x8x2_t
name|test_vzipq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzipq_p16
return|return
name|vzipq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: zip1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
comment|// CHECK: zip2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int8x8x2_t
name|test_vtrn_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn_s8
return|return
name|vtrn_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: trn2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4x2_t
name|test_vtrn_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn_s16
return|return
name|vtrn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
comment|// CHECK: trn2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2x2_t
name|test_vtrn_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn_s32
return|return
name|vtrn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v2.2s, v0.2s, v1.2s}}
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v1.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|uint8x8x2_t
name|test_vtrn_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn_u8
return|return
name|vtrn_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: trn2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4x2_t
name|test_vtrn_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn_u16
return|return
name|vtrn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
comment|// CHECK: trn2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2x2_t
name|test_vtrn_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn_u32
return|return
name|vtrn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v2.2s, v0.2s, v1.2s}}
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v1.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x2x2_t
name|test_vtrn_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn_f32
return|return
name|vtrn_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: {{ins v[0-9]+.s\[1\], v[0-9]+.s\[0\]|zip1 v2.2s, v0.2s, v1.2s}}
comment|// CHECK: {{ins v[0-9]+.s\[0\], v[0-9]+.s\[1\]|zip2 v1.2s, v0.2s, v1.2s}}
block|}
end_function

begin_function
name|poly8x8x2_t
name|test_vtrn_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn_p8
return|return
name|vtrn_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
comment|// CHECK: trn2 {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly16x4x2_t
name|test_vtrn_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn_p16
return|return
name|vtrn_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
comment|// CHECK: trn2 {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int8x16x2_t
name|test_vtrnq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrnq_s8
return|return
name|vtrnq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
comment|// CHECK: trn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8x2_t
name|test_vtrnq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrnq_s16
return|return
name|vtrnq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
comment|// CHECK: trn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4x2_t
name|test_vtrnq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrnq_s32
return|return
name|vtrnq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: trn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16x2_t
name|test_vtrnq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrnq_u8
return|return
name|vtrnq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
comment|// CHECK: trn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8x2_t
name|test_vtrnq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrnq_u16
return|return
name|vtrnq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
comment|// CHECK: trn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4x2_t
name|test_vtrnq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrnq_u32
return|return
name|vtrnq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: trn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4x2_t
name|test_vtrnq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrnq_f32
return|return
name|vtrnq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: trn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|poly8x16x2_t
name|test_vtrnq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrnq_p8
return|return
name|vtrnq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
comment|// CHECK: trn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x8x2_t
name|test_vtrnq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrnq_p16
return|return
name|vtrnq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: trn1 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
comment|// CHECK: trn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

end_unit

