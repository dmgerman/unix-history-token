begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -ffp-contract=fast -S -O3 -o - %s | FileCheck %s --check-prefix=CHECK --check-prefix=CHECK-ARM64
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
name|test_vadd_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_s8
return|return
name|vadd_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vadd_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_s16
return|return
name|vadd_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vadd_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_s32
return|return
name|vadd_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64x1_t
name|test_vadd_s64
parameter_list|(
name|int64x1_t
name|v1
parameter_list|,
name|int64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_s64
return|return
name|vadd_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vadd_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_f32
return|return
name|vadd_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vadd_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_u8
return|return
name|vadd_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vadd_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_u16
return|return
name|vadd_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vadd_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_u32
return|return
name|vadd_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vadd_u64
parameter_list|(
name|uint64x1_t
name|v1
parameter_list|,
name|uint64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_u64
return|return
name|vadd_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vaddq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddq_s8
return|return
name|vaddq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vaddq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddq_s16
return|return
name|vaddq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vaddq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddq_s32
return|return
name|vaddq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vaddq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddq_s64
return|return
name|vaddq_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x4_t
name|test_vaddq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddq_f32
return|return
name|vaddq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vaddq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddq_f64
return|return
name|vaddq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fadd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vaddq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddq_u8
return|return
name|vaddq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vaddq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddq_u16
return|return
name|vaddq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vaddq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: vaddq_u32
return|return
name|vaddq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vaddq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddq_u64
return|return
name|vaddq_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: add {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vsub_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_s8
return|return
name|vsub_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vsub_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_s16
return|return
name|vsub_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vsub_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_s32
return|return
name|vsub_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64x1_t
name|test_vsub_s64
parameter_list|(
name|int64x1_t
name|v1
parameter_list|,
name|int64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_s64
return|return
name|vsub_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|float32x2_t
name|test_vsub_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_f32
return|return
name|vsub_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vsub_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_u8
return|return
name|vsub_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vsub_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_u16
return|return
name|vsub_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vsub_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_u32
return|return
name|vsub_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vsub_u64
parameter_list|(
name|uint64x1_t
name|v1
parameter_list|,
name|uint64x1_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_u64
return|return
name|vsub_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vsubq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubq_s8
return|return
name|vsubq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vsubq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubq_s16
return|return
name|vsubq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vsubq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubq_s32
return|return
name|vsubq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vsubq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubq_s64
return|return
name|vsubq_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x4_t
name|test_vsubq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubq_f32
return|return
name|vsubq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vsubq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubq_f64
return|return
name|vsubq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fsub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vsubq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubq_u8
return|return
name|vsubq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsubq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubq_u16
return|return
name|vsubq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsubq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK: vsubq_u32
return|return
name|vsubq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vsubq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubq_u64
return|return
name|vsubq_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vmul_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_s8
return|return
name|vmul_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vmul_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_s16
return|return
name|vmul_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vmul_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_s32
return|return
name|vmul_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vmul_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_f32
return|return
name|vmul_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vmul_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_u8
return|return
name|vmul_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmul_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_u16
return|return
name|vmul_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmul_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_u32
return|return
name|vmul_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vmulq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_s8
return|return
name|vmulq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vmulq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_s16
return|return
name|vmulq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vmulq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_s32
return|return
name|vmulq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vmulq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_u8
return|return
name|vmulq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmulq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_u16
return|return
name|vmulq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmulq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_u32
return|return
name|vmulq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: mul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_f32
return|return
name|vmulq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulq_f64
return|return
name|vmulq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fmul {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|poly8x8_t
name|test_vmul_p8
parameter_list|(
name|poly8x8_t
name|v1
parameter_list|,
name|poly8x8_t
name|v2
parameter_list|)
block|{
comment|//  test_vmul_p8
return|return
name|vmul_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|//  pmul {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vmulq_p8
parameter_list|(
name|poly8x16_t
name|v1
parameter_list|,
name|poly8x16_t
name|v2
parameter_list|)
block|{
comment|// test_vmulq_p8
return|return
name|vmulq_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// pmul {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int8x8_t
name|test_vmla_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|,
name|int8x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_s8
return|return
name|vmla_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vmla_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|,
name|int16x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_s16
return|return
name|vmla_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vmla_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|,
name|int32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_s32
return|return
name|vmla_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vmla_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|,
name|float32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_f32
return|return
name|vmla_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vmla_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|,
name|uint8x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_u8
return|return
name|vmla_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmla_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|,
name|uint16x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_u16
return|return
name|vmla_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmla_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|,
name|uint32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_u32
return|return
name|vmla_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vmlaq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|,
name|int8x16_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_s8
return|return
name|vmlaq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlaq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|,
name|int16x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_s16
return|return
name|vmlaq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlaq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|,
name|int32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_s32
return|return
name|vmlaq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vmlaq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|,
name|float32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_f32
return|return
name|vmlaq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vmlaq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|,
name|uint8x16_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_u8
return|return
name|vmlaq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlaq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|,
name|uint16x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_u16
return|return
name|vmlaq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlaq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|,
name|uint32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_u32
return|return
name|vmlaq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vmlaq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|,
name|float64x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlaq_f64
return|return
name|vmlaq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vmls_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|,
name|int8x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_s8
return|return
name|vmls_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vmls_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|,
name|int16x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_s16
return|return
name|vmls_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vmls_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|,
name|int32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_s32
return|return
name|vmls_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vmls_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|,
name|float32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_f32
return|return
name|vmls_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vmls_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|,
name|uint8x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_u8
return|return
name|vmls_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmls_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|,
name|uint16x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_u16
return|return
name|vmls_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmls_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|,
name|uint32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_u32
return|return
name|vmls_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vmlsq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|,
name|int8x16_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_s8
return|return
name|vmlsq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlsq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|,
name|int16x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_s16
return|return
name|vmlsq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|,
name|int32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_s32
return|return
name|vmlsq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vmlsq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|,
name|float32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_f32
return|return
name|vmlsq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vmlsq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|,
name|uint8x16_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_u8
return|return
name|vmlsq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlsq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|,
name|uint16x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_u16
return|return
name|vmlsq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|,
name|uint32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_u32
return|return
name|vmlsq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: mls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vmlsq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|,
name|float64x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsq_f64
return|return
name|vmlsq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmls {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vfma_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|,
name|float32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfma_f32
return|return
name|vfma_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmaq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|,
name|float32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_f32
return|return
name|vfmaq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmaq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|,
name|float64x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmaq_f64
return|return
name|vfmaq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmla {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vfms_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|,
name|float32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfms_f32
return|return
name|vfms_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmls v0.2s, {{v1.2s, v2.2s|v2.2s, v1.2s}}
block|}
end_function

begin_function
name|float32x4_t
name|test_vfmsq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|,
name|float32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfmsq_f32
return|return
name|vfmsq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmls v0.4s, {{v1.4s, v2.4s|v2.4s, v1.4s}}
block|}
end_function

begin_function
name|float64x2_t
name|test_vfmsq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|,
name|float64x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK: vfmsq_f64
return|return
name|vfmsq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: fmls v0.2d, {{v1.2d, v2.2d|v2.2d, v1.2d}}
block|}
end_function

begin_function
name|float64x2_t
name|test_vdivq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdivq_f64
return|return
name|vdivq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fdiv {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x4_t
name|test_vdivq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdivq_f32
return|return
name|vdivq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fdiv {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x2_t
name|test_vdiv_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdiv_f32
return|return
name|vdiv_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fdiv {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x8_t
name|test_vaba_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|,
name|int8x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaba_s8
return|return
name|vaba_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: saba {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vaba_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|,
name|int16x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaba_s16
return|return
name|vaba_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: saba {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vaba_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|,
name|int32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaba_s32
return|return
name|vaba_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: saba {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vaba_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|,
name|uint8x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaba_u8
return|return
name|vaba_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: uaba {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vaba_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|,
name|uint16x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaba_u16
return|return
name|vaba_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: uaba {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vaba_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|,
name|uint32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaba_u32
return|return
name|vaba_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: uaba {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vabaq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|,
name|int8x16_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabaq_s8
return|return
name|vabaq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: saba {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vabaq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|,
name|int16x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabaq_s16
return|return
name|vabaq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: saba {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vabaq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|,
name|int32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabaq_s32
return|return
name|vabaq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: saba {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vabaq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|,
name|uint8x16_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabaq_u8
return|return
name|vabaq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: uaba {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vabaq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|,
name|uint16x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabaq_u16
return|return
name|vabaq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: uaba {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vabaq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|,
name|uint32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabaq_u32
return|return
name|vabaq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: uaba {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int8x8_t
name|test_vabd_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabd_s8
return|return
name|vabd_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sabd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vabd_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabd_s16
return|return
name|vabd_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sabd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vabd_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabd_s32
return|return
name|vabd_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sabd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vabd_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabd_u8
return|return
name|vabd_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uabd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vabd_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabd_u16
return|return
name|vabd_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uabd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vabd_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabd_u32
return|return
name|vabd_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uabd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vabd_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabd_f32
return|return
name|vabd_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fabd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vabdq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdq_s8
return|return
name|vabdq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sabd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vabdq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdq_s16
return|return
name|vabdq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sabd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vabdq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdq_s32
return|return
name|vabdq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: sabd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vabdq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdq_u8
return|return
name|vabdq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uabd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vabdq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdq_u16
return|return
name|vabdq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uabd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vabdq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdq_u32
return|return
name|vabdq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uabd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vabdq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdq_f32
return|return
name|vabdq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fabd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vabdq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdq_f64
return|return
name|vabdq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fabd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vbsl_s8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|,
name|int8x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_s8
return|return
name|vbsl_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x8_t
name|test_vbsl_s16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|,
name|int16x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_s16
return|return
name|vbsl_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x2_t
name|test_vbsl_s32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|,
name|int32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_s32
return|return
name|vbsl_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint64x1_t
name|test_vbsl_s64
parameter_list|(
name|uint64x1_t
name|v1
parameter_list|,
name|uint64x1_t
name|v2
parameter_list|,
name|uint64x1_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_s64
return|return
name|vbsl_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x8_t
name|test_vbsl_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|,
name|uint8x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_u8
return|return
name|vbsl_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vbsl_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|,
name|uint16x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_u16
return|return
name|vbsl_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x2_t
name|test_vbsl_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|,
name|uint32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_u32
return|return
name|vbsl_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint64x1_t
name|test_vbsl_u64
parameter_list|(
name|uint64x1_t
name|v1
parameter_list|,
name|uint64x1_t
name|v2
parameter_list|,
name|uint64x1_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_u64
return|return
name|vbsl_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|float32x2_t
name|test_vbsl_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|,
name|float32x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_f32
return|return
name|vbsl_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|float64x1_t
name|test_vbsl_f64
parameter_list|(
name|uint64x1_t
name|v1
parameter_list|,
name|float64x1_t
name|v2
parameter_list|,
name|float64x1_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_f64
return|return
name|vbsl_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly8x8_t
name|test_vbsl_p8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|poly8x8_t
name|v2
parameter_list|,
name|poly8x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_p8
return|return
name|vbsl_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly16x4_t
name|test_vbsl_p16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|poly16x4_t
name|v2
parameter_list|,
name|poly16x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_p16
return|return
name|vbsl_p16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int8x16_t
name|test_vbslq_s8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|,
name|int8x16_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_s8
return|return
name|vbslq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vbslq_s16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|,
name|int16x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_s16
return|return
name|vbslq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vbslq_s32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|,
name|int32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_s32
return|return
name|vbslq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int64x2_t
name|test_vbslq_s64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|,
name|int64x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_s64
return|return
name|vbslq_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vbslq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|,
name|uint8x16_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_u8
return|return
name|vbslq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vbslq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|,
name|uint16x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_u16
return|return
name|vbslq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vbslq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|,
name|int32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_u32
return|return
name|vbslq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint64x2_t
name|test_vbslq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|,
name|uint64x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_u64
return|return
name|vbslq_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|float32x4_t
name|test_vbslq_f32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|,
name|float32x4_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_f32
return|return
name|vbslq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly8x16_t
name|test_vbslq_p8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|poly8x16_t
name|v2
parameter_list|,
name|poly8x16_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_p8
return|return
name|vbslq_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly16x8_t
name|test_vbslq_p16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|poly16x8_t
name|v2
parameter_list|,
name|poly16x8_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_p16
return|return
name|vbslq_p16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|float64x2_t
name|test_vbslq_f64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|,
name|float64x2_t
name|v3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_f64
return|return
name|vbslq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|,
name|v3
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|float32x2_t
name|test_vrecps_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecps_f32
return|return
name|vrecps_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: frecps {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrecpsq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecpsq_f32
return|return
name|vrecpsq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: frecps {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrecpsq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecpsq_f64
return|return
name|vrecpsq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: frecps {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vrsqrts_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsqrts_f32
return|return
name|vrsqrts_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: frsqrts {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vrsqrtsq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsqrtsq_f32
return|return
name|vrsqrtsq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: frsqrts {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vrsqrtsq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsqrtsq_f64
return|return
name|vrsqrtsq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: frsqrts {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcage_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcage_f32
return|return
name|vcage_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: facge {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcage_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcage_f64
return|return
name|vcage_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: facge {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcageq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcageq_f32
return|return
name|vcageq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: facge {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcageq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcageq_f64
return|return
name|vcageq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: facge {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcagt_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcagt_f32
return|return
name|vcagt_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: facgt {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcagt_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcagt_f64
return|return
name|vcagt_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: facgt {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcagtq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcagtq_f32
return|return
name|vcagtq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: facgt {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcagtq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcagtq_f64
return|return
name|vcagtq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: facgt {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcale_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcale_f32
return|return
name|vcale_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// Using registers other than v0, v1 are possible, but would be odd.
comment|// CHECK: facge {{v[0-9]+}}.2s, v1.2s, v0.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcale_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcale_f64
return|return
name|vcale_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: facge {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcaleq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcaleq_f32
return|return
name|vcaleq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// Using registers other than v0, v1 are possible, but would be odd.
comment|// CHECK: facge {{v[0-9]+}}.4s, v1.4s, v0.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcaleq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcaleq_f64
return|return
name|vcaleq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// Using registers other than v0, v1 are possible, but would be odd.
comment|// CHECK: facge {{v[0-9]+}}.2d, v1.2d, v0.2d
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcalt_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcalt_f32
return|return
name|vcalt_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// Using registers other than v0, v1 are possible, but would be odd.
comment|// CHECK: facgt {{v[0-9]+}}.2s, v1.2s, v0.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcalt_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcalt_f64
return|return
name|vcalt_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: facgt {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcaltq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcaltq_f32
return|return
name|vcaltq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// Using registers other than v0, v1 are possible, but would be odd.
comment|// CHECK: facgt {{v[0-9]+}}.4s, v1.4s, v0.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcaltq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcaltq_f64
return|return
name|vcaltq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// Using registers other than v0, v1 are possible, but would be odd.
comment|// CHECK: facgt {{v[0-9]+}}.2d, v1.2d, v0.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtst_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_s8
return|return
name|vtst_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vtst_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_s16
return|return
name|vtst_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vtst_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_s32
return|return
name|vtst_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtst_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_u8
return|return
name|vtst_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vtst_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_u16
return|return
name|vtst_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vtst_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_u32
return|return
name|vtst_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vtstq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_s8
return|return
name|vtstq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vtstq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_s16
return|return
name|vtstq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vtstq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_s32
return|return
name|vtstq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vtstq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_u8
return|return
name|vtstq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vtstq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_u16
return|return
name|vtstq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vtstq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_u32
return|return
name|vtstq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vtstq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_s64
return|return
name|vtstq_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vtstq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_u64
return|return
name|vtstq_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vtst_p8
parameter_list|(
name|poly8x8_t
name|v1
parameter_list|,
name|poly8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_p8
return|return
name|vtst_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vtst_p16
parameter_list|(
name|poly16x4_t
name|v1
parameter_list|,
name|poly16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_p16
return|return
name|vtst_p16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint8x16_t
name|test_vtstq_p8
parameter_list|(
name|poly8x16_t
name|v1
parameter_list|,
name|poly8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_p8
return|return
name|vtstq_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vtstq_p16
parameter_list|(
name|poly16x8_t
name|v1
parameter_list|,
name|poly16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_p16
return|return
name|vtstq_p16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x1_t
name|test_vtst_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_s64
return|return
name|vtst_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmtst {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vtst_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_u64
return|return
name|vtst_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmtst {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vceq_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_s8
return|return
name|vceq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vceq_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_s16
return|return
name|vceq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vceq_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_s32
return|return
name|vceq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vceq_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_s64
return|return
name|vceq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vceq_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_u64
return|return
name|vceq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vceq_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_f32
return|return
name|vceq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmeq {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vceq_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_f64
return|return
name|vceq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fcmeq {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vceq_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_u8
return|return
name|vceq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vceq_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_u16
return|return
name|vceq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vceq_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_u32
return|return
name|vceq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vceq_p8
parameter_list|(
name|poly8x8_t
name|v1
parameter_list|,
name|poly8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_p8
return|return
name|vceq_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vceqq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_s8
return|return
name|vceqq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vceqq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_s16
return|return
name|vceqq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vceqq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_s32
return|return
name|vceqq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vceqq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_f32
return|return
name|vceqq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmeq {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vceqq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_u8
return|return
name|vceqq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vceqq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_u16
return|return
name|vceqq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vceqq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_u32
return|return
name|vceqq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vceqq_p8
parameter_list|(
name|poly8x16_t
name|v1
parameter_list|,
name|poly8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_p8
return|return
name|vceqq_p8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint64x2_t
name|test_vceqq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_s64
return|return
name|vceqq_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vceqq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_u64
return|return
name|vceqq_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vceqq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_f64
return|return
name|vceqq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmeq {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vcge_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_s8
return|return
name|vcge_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vcge_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_s16
return|return
name|vcge_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcge_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_s32
return|return
name|vcge_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcge_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_s64
return|return
name|vcge_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmge {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcge_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_u64
return|return
name|vcge_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmhs {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcge_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_f32
return|return
name|vcge_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmge {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcge_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_f64
return|return
name|vcge_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fcmge {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vcge_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_u8
return|return
name|vcge_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vcge_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_u16
return|return
name|vcge_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcge_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcge_u32
return|return
name|vcge_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcgeq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_s8
return|return
name|vcgeq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcgeq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_s16
return|return
name|vcgeq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcgeq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_s32
return|return
name|vcgeq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcgeq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_f32
return|return
name|vcgeq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmge {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcgeq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_u8
return|return
name|vcgeq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcgeq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_u16
return|return
name|vcgeq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcgeq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_u32
return|return
name|vcgeq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgeq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_s64
return|return
name|vcgeq_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgeq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_u64
return|return
name|vcgeq_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgeq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgeq_f64
return|return
name|vcgeq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmge {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_comment
comment|// Notes about vcle:
end_comment

begin_comment
comment|// LE condition predicate implemented as GE, so check reversed operands.
end_comment

begin_comment
comment|// Using registers other than v0, v1 are possible, but would be odd.
end_comment

begin_function
name|uint8x8_t
name|test_vcle_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_s8
return|return
name|vcle_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.8b, v1.8b, v0.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vcle_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_s16
return|return
name|vcle_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.4h, v1.4h, v0.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcle_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_s32
return|return
name|vcle_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.2s, v1.2s, v0.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcle_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_s64
return|return
name|vcle_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmge {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcle_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_u64
return|return
name|vcle_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmhs {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcle_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_f32
return|return
name|vcle_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmge {{v[0-9]+}}.2s, v1.2s, v0.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcle_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_f64
return|return
name|vcle_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fcmge {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vcle_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_u8
return|return
name|vcle_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.8b, v1.8b, v0.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vcle_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_u16
return|return
name|vcle_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.4h, v1.4h, v0.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcle_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcle_u32
return|return
name|vcle_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.2s, v1.2s, v0.2s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcleq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_s8
return|return
name|vcleq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.16b, v1.16b, v0.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcleq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_s16
return|return
name|vcleq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.8h, v1.8h, v0.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcleq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_s32
return|return
name|vcleq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.4s, v1.4s, v0.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcleq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_f32
return|return
name|vcleq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmge {{v[0-9]+}}.4s, v1.4s, v0.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcleq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_u8
return|return
name|vcleq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.16b, v1.16b, v0.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcleq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_u16
return|return
name|vcleq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.8h, v1.8h, v0.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcleq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_u32
return|return
name|vcleq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.4s, v1.4s, v0.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcleq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_s64
return|return
name|vcleq_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmge {{v[0-9]+}}.2d, v1.2d, v0.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcleq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_u64
return|return
name|vcleq_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhs {{v[0-9]+}}.2d, v1.2d, v0.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcleq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcleq_f64
return|return
name|vcleq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmge {{v[0-9]+}}.2d, v1.2d, v0.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vcgt_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_s8
return|return
name|vcgt_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vcgt_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_s16
return|return
name|vcgt_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcgt_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_s32
return|return
name|vcgt_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcgt_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_s64
return|return
name|vcgt_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmgt {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcgt_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_u64
return|return
name|vcgt_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmhi {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcgt_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_f32
return|return
name|vcgt_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmgt {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcgt_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_f64
return|return
name|vcgt_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fcmgt {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vcgt_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_u8
return|return
name|vcgt_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vcgt_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_u16
return|return
name|vcgt_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcgt_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgt_u32
return|return
name|vcgt_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcgtq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_s8
return|return
name|vcgtq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcgtq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_s16
return|return
name|vcgtq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcgtq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_s32
return|return
name|vcgtq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcgtq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_f32
return|return
name|vcgtq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmgt {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcgtq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_u8
return|return
name|vcgtq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcgtq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_u16
return|return
name|vcgtq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcgtq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_u32
return|return
name|vcgtq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgtq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_s64
return|return
name|vcgtq_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgtq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_u64
return|return
name|vcgtq_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcgtq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtq_f64
return|return
name|vcgtq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmgt {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_comment
comment|// Notes about vclt:
end_comment

begin_comment
comment|// LT condition predicate implemented as GT, so check reversed operands.
end_comment

begin_comment
comment|// Using registers other than v0, v1 are possible, but would be odd.
end_comment

begin_function
name|uint8x8_t
name|test_vclt_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_s8
return|return
name|vclt_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.8b, v1.8b, v0.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vclt_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_s16
return|return
name|vclt_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.4h, v1.4h, v0.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vclt_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_s32
return|return
name|vclt_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.2s, v1.2s, v0.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vclt_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_s64
return|return
name|vclt_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmgt {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vclt_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_u64
return|return
name|vclt_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmhi {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint32x2_t
name|test_vclt_f32
parameter_list|(
name|float32x2_t
name|v1
parameter_list|,
name|float32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_f32
return|return
name|vclt_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmgt {{v[0-9]+}}.2s, v1.2s, v0.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vclt_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_f64
return|return
name|vclt_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fcmgt {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vclt_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_u8
return|return
name|vclt_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.8b, v1.8b, v0.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vclt_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_u16
return|return
name|vclt_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.4h, v1.4h, v0.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vclt_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclt_u32
return|return
name|vclt_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.2s, v1.2s, v0.2s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcltq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_s8
return|return
name|vcltq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.16b, v1.16b, v0.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcltq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_s16
return|return
name|vcltq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.8h, v1.8h, v0.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcltq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_s32
return|return
name|vcltq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.4s, v1.4s, v0.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcltq_f32
parameter_list|(
name|float32x4_t
name|v1
parameter_list|,
name|float32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_f32
return|return
name|vcltq_f32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmgt {{v[0-9]+}}.4s, v1.4s, v0.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcltq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_u8
return|return
name|vcltq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.16b, v1.16b, v0.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcltq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_u16
return|return
name|vcltq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.8h, v1.8h, v0.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcltq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_u32
return|return
name|vcltq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.4s, v1.4s, v0.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcltq_s64
parameter_list|(
name|int64x2_t
name|v1
parameter_list|,
name|int64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_s64
return|return
name|vcltq_s64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmgt {{v[0-9]+}}.2d, v1.2d, v0.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcltq_u64
parameter_list|(
name|uint64x2_t
name|v1
parameter_list|,
name|uint64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_u64
return|return
name|vcltq_u64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: cmhi {{v[0-9]+}}.2d, v1.2d, v0.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcltq_f64
parameter_list|(
name|float64x2_t
name|v1
parameter_list|,
name|float64x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltq_f64
return|return
name|vcltq_f64
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: fcmgt {{v[0-9]+}}.2d, v1.2d, v0.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vhadd_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhadd_s8
return|return
name|vhadd_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vhadd_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhadd_s16
return|return
name|vhadd_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vhadd_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhadd_s32
return|return
name|vhadd_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vhadd_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhadd_u8
return|return
name|vhadd_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vhadd_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhadd_u16
return|return
name|vhadd_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vhadd_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhadd_u32
return|return
name|vhadd_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vhaddq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhaddq_s8
return|return
name|vhaddq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vhaddq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhaddq_s16
return|return
name|vhaddq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vhaddq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhaddq_s32
return|return
name|vhaddq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vhaddq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhaddq_u8
return|return
name|vhaddq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vhaddq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhaddq_u16
return|return
name|vhaddq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vhaddq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhaddq_u32
return|return
name|vhaddq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int8x8_t
name|test_vhsub_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsub_s8
return|return
name|vhsub_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shsub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vhsub_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsub_s16
return|return
name|vhsub_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shsub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vhsub_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsub_s32
return|return
name|vhsub_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vhsub_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsub_u8
return|return
name|vhsub_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhsub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vhsub_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsub_u16
return|return
name|vhsub_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhsub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vhsub_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsub_u32
return|return
name|vhsub_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vhsubq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsubq_s8
return|return
name|vhsubq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shsub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vhsubq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsubq_s16
return|return
name|vhsubq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shsub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vhsubq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsubq_s32
return|return
name|vhsubq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: shsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vhsubq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsubq_u8
return|return
name|vhsubq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhsub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vhsubq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsubq_u16
return|return
name|vhsubq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhsub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vhsubq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vhsubq_u32
return|return
name|vhsubq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: uhsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int8x8_t
name|test_vrhadd_s8
parameter_list|(
name|int8x8_t
name|v1
parameter_list|,
name|int8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhadd_s8
return|return
name|vrhadd_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: srhadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vrhadd_s16
parameter_list|(
name|int16x4_t
name|v1
parameter_list|,
name|int16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhadd_s16
return|return
name|vrhadd_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: srhadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vrhadd_s32
parameter_list|(
name|int32x2_t
name|v1
parameter_list|,
name|int32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhadd_s32
return|return
name|vrhadd_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: srhadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vrhadd_u8
parameter_list|(
name|uint8x8_t
name|v1
parameter_list|,
name|uint8x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhadd_u8
return|return
name|vrhadd_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: urhadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vrhadd_u16
parameter_list|(
name|uint16x4_t
name|v1
parameter_list|,
name|uint16x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhadd_u16
return|return
name|vrhadd_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: urhadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vrhadd_u32
parameter_list|(
name|uint32x2_t
name|v1
parameter_list|,
name|uint32x2_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhadd_u32
return|return
name|vrhadd_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: urhadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vrhaddq_s8
parameter_list|(
name|int8x16_t
name|v1
parameter_list|,
name|int8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhaddq_s8
return|return
name|vrhaddq_s8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: srhadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vrhaddq_s16
parameter_list|(
name|int16x8_t
name|v1
parameter_list|,
name|int16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhaddq_s16
return|return
name|vrhaddq_s16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: srhadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vrhaddq_s32
parameter_list|(
name|int32x4_t
name|v1
parameter_list|,
name|int32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhaddq_s32
return|return
name|vrhaddq_s32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: srhadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vrhaddq_u8
parameter_list|(
name|uint8x16_t
name|v1
parameter_list|,
name|uint8x16_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhaddq_u8
return|return
name|vrhaddq_u8
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: urhadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vrhaddq_u16
parameter_list|(
name|uint16x8_t
name|v1
parameter_list|,
name|uint16x8_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhaddq_u16
return|return
name|vrhaddq_u16
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: urhadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vrhaddq_u32
parameter_list|(
name|uint32x4_t
name|v1
parameter_list|,
name|uint32x4_t
name|v2
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrhaddq_u32
return|return
name|vrhaddq_u32
argument_list|(
name|v1
argument_list|,
name|v2
argument_list|)
return|;
comment|// CHECK: urhadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int8x8_t
name|test_vqadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqadd_s8
return|return
name|vqadd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vqadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqadd_s16
return|return
name|vqadd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqadd_s32
return|return
name|vqadd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64x1_t
name|test_vqadd_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqadd_s64
return|return
name|vqadd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK:  sqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqadd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqadd_u8
return|return
name|vqadd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vqadd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqadd_u16
return|return
name|vqadd_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vqadd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqadd_u32
return|return
name|vqadd_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vqadd_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK:  test_vqadd_u64
return|return
name|vqadd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK:  uqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vqaddq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddq_s8
return|return
name|vqaddq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vqaddq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddq_s16
return|return
name|vqaddq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vqaddq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddq_s32
return|return
name|vqaddq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vqaddq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddq_s64
return|return
name|vqaddq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqaddq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddq_u8
return|return
name|vqaddq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vqaddq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddq_u16
return|return
name|vqaddq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vqaddq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddq_u32
return|return
name|vqaddq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vqaddq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddq_u64
return|return
name|vqaddq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vqsub_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsub_s8
return|return
name|vqsub_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vqsub_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsub_s16
return|return
name|vqsub_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqsub_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsub_s32
return|return
name|vqsub_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64x1_t
name|test_vqsub_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsub_s64
return|return
name|vqsub_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqsub_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsub_u8
return|return
name|vqsub_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vqsub_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsub_u16
return|return
name|vqsub_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vqsub_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsub_u32
return|return
name|vqsub_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vqsub_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsub_u64
return|return
name|vqsub_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK:  uqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vqsubq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubq_s8
return|return
name|vqsubq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vqsubq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubq_s16
return|return
name|vqsubq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vqsubq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubq_s32
return|return
name|vqsubq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vqsubq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubq_s64
return|return
name|vqsubq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqsubq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubq_u8
return|return
name|vqsubq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vqsubq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubq_u16
return|return
name|vqsubq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vqsubq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubq_u32
return|return
name|vqsubq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vqsubq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubq_u64
return|return
name|vqsubq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vshl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_s8
return|return
name|vshl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vshl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_s16
return|return
name|vshl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vshl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_s32
return|return
name|vshl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64x1_t
name|test_vshl_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_s64
return|return
name|vshl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vshl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_u8
return|return
name|vshl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vshl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_u16
return|return
name|vshl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vshl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_u32
return|return
name|vshl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vshl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_u64
return|return
name|vshl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vshlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_s8
return|return
name|vshlq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vshlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_s16
return|return
name|vshlq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vshlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_s32
return|return
name|vshlq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vshlq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_s64
return|return
name|vshlq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vshlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_u8
return|return
name|vshlq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vshlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_u16
return|return
name|vshlq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vshlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_u32
return|return
name|vshlq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vshlq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_u64
return|return
name|vshlq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vqshl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_s8
return|return
name|vqshl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vqshl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_s16
return|return
name|vqshl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqshl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_s32
return|return
name|vqshl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64x1_t
name|test_vqshl_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_s64
return|return
name|vqshl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqshl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_u8
return|return
name|vqshl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vqshl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_u16
return|return
name|vqshl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vqshl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_u32
return|return
name|vqshl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vqshl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_u64
return|return
name|vqshl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vqshlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_s8
return|return
name|vqshlq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vqshlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_s16
return|return
name|vqshlq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vqshlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_s32
return|return
name|vqshlq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vqshlq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_s64
return|return
name|vqshlq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqshlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_u8
return|return
name|vqshlq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vqshlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_u16
return|return
name|vqshlq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vqshlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_u32
return|return
name|vqshlq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vqshlq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_u64
return|return
name|vqshlq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vrshl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshl_s8
return|return
name|vrshl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vrshl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshl_s16
return|return
name|vrshl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vrshl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshl_s32
return|return
name|vrshl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64x1_t
name|test_vrshl_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshl_s64
return|return
name|vrshl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vrshl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshl_u8
return|return
name|vrshl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vrshl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshl_u16
return|return
name|vrshl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vrshl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshl_u32
return|return
name|vrshl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vrshl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshl_u64
return|return
name|vrshl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vrshlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshlq_s8
return|return
name|vrshlq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vrshlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshlq_s16
return|return
name|vrshlq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vrshlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshlq_s32
return|return
name|vrshlq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vrshlq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshlq_s64
return|return
name|vrshlq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vrshlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshlq_u8
return|return
name|vrshlq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vrshlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshlq_u16
return|return
name|vrshlq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vrshlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshlq_u32
return|return
name|vrshlq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vrshlq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshlq_u64
return|return
name|vrshlq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vqrshl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshl_s8
return|return
name|vqrshl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vqrshl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshl_s16
return|return
name|vqrshl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqrshl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshl_s32
return|return
name|vqrshl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64x1_t
name|test_vqrshl_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshl_s64
return|return
name|vqrshl_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqrshl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshl_u8
return|return
name|vqrshl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vqrshl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshl_u16
return|return
name|vqrshl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vqrshl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshl_u32
return|return
name|vqrshl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64x1_t
name|test_vqrshl_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshl_u64
return|return
name|vqrshl_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int8x16_t
name|test_vqrshlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshlq_s8
return|return
name|vqrshlq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vqrshlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshlq_s16
return|return
name|vqrshlq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vqrshlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshlq_s32
return|return
name|vqrshlq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int64x2_t
name|test_vqrshlq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshlq_s64
return|return
name|vqrshlq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlq_u8
end_comment

begin_function
name|uint8x16_t
name|test_vqrshlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vqrshlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshlq_u16
return|return
name|vqrshlq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vqrshlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshlq_u32
return|return
name|vqrshlq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vqrshlq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshlq_u64
return|return
name|vqrshlq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|poly64x1_t
name|test_vsli_n_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_p64
return|return
name|vsli_n_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sli {{d[0-9]+}}, {{d[0-9]+}}, #0
block|}
end_function

begin_function
name|poly64x2_t
name|test_vsliq_n_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_p64
return|return
name|vsliq_n_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #0
block|}
end_function

begin_function
name|int8x8_t
name|test_vmax_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmax_s8
return|return
name|vmax_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smax {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vmax_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmax_s16
return|return
name|vmax_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smax {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vmax_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmax_s32
return|return
name|vmax_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smax {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vmax_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmax_u8
return|return
name|vmax_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umax {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmax_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmax_u16
return|return
name|vmax_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umax {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmax_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmax_u32
return|return
name|vmax_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umax {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vmax_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmax_f32
return|return
name|vmax_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmax {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vmaxq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxq_s8
return|return
name|vmaxq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smax {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vmaxq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxq_s16
return|return
name|vmaxq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smax {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vmaxq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxq_s32
return|return
name|vmaxq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smax {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vmaxq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxq_u8
return|return
name|vmaxq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umax {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmaxq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxq_u16
return|return
name|vmaxq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umax {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmaxq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxq_u32
return|return
name|vmaxq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umax {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vmaxq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxq_f32
return|return
name|vmaxq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmax {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vmaxq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxq_f64
return|return
name|vmaxq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmax {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vmin_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmin_s8
return|return
name|vmin_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smin {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vmin_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmin_s16
return|return
name|vmin_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smin {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vmin_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmin_s32
return|return
name|vmin_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smin {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vmin_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmin_u8
return|return
name|vmin_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umin {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vmin_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmin_u16
return|return
name|vmin_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umin {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmin_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmin_u32
return|return
name|vmin_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umin {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vmin_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmin_f32
return|return
name|vmin_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmin {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vminq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminq_s8
return|return
name|vminq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smin {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vminq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminq_s16
return|return
name|vminq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smin {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vminq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminq_s32
return|return
name|vminq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smin {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vminq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminq_u8
return|return
name|vminq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umin {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vminq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminq_u16
return|return
name|vminq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umin {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vminq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminq_u32
return|return
name|vminq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umin {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vminq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminq_f32
return|return
name|vminq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmin {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vminq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminq_f64
return|return
name|vminq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmin {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vmaxnm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxnm_f32
return|return
name|vmaxnm_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxnm {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vmaxnmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxnmq_f32
return|return
name|vmaxnmq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxnm {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vmaxnmq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxnmq_f64
return|return
name|vmaxnmq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxnm {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vminnm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminnm_f32
return|return
name|vminnm_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminnm {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vminnmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminnmq_f32
return|return
name|vminnmq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminnm {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vminnmq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminnmq_f64
return|return
name|vminnmq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminnm {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vpmax_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmax_s8
return|return
name|vpmax_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smaxp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vpmax_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmax_s16
return|return
name|vpmax_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smaxp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vpmax_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmax_s32
return|return
name|vpmax_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smaxp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vpmax_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmax_u8
return|return
name|vpmax_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umaxp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vpmax_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmax_u16
return|return
name|vpmax_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umaxp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vpmax_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmax_u32
return|return
name|vpmax_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umaxp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vpmax_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmax_f32
return|return
name|vpmax_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vpmaxq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxq_s8
return|return
name|vpmaxq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smaxp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vpmaxq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxq_s16
return|return
name|vpmaxq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smaxp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vpmaxq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxq_s32
return|return
name|vpmaxq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smaxp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vpmaxq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxq_u8
return|return
name|vpmaxq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umaxp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vpmaxq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxq_u16
return|return
name|vpmaxq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umaxp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vpmaxq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxq_u32
return|return
name|vpmaxq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umaxp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vpmaxq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxq_f32
return|return
name|vpmaxq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vpmaxq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxq_f64
return|return
name|vpmaxq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vpmin_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmin_s8
return|return
name|vpmin_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sminp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vpmin_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmin_s16
return|return
name|vpmin_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sminp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vpmin_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmin_s32
return|return
name|vpmin_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sminp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vpmin_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmin_u8
return|return
name|vpmin_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uminp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vpmin_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmin_u16
return|return
name|vpmin_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uminp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vpmin_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmin_u32
return|return
name|vpmin_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uminp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vpmin_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmin_f32
return|return
name|vpmin_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vpminq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminq_s8
return|return
name|vpminq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sminp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vpminq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminq_s16
return|return
name|vpminq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sminp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vpminq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminq_s32
return|return
name|vpminq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sminp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vpminq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminq_u8
return|return
name|vpminq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uminp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vpminq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminq_u16
return|return
name|vpminq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uminp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vpminq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminq_u32
return|return
name|vpminq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uminp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vpminq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminq_f32
return|return
name|vpminq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vpminq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminq_f64
return|return
name|vpminq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vpmaxnm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxnm_f32
return|return
name|vpmaxnm_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxnmp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vpmaxnmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxnmq_f32
return|return
name|vpmaxnmq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxnmp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vpmaxnmq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpmaxnmq_f64
return|return
name|vpmaxnmq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxnmp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32x2_t
name|test_vpminnm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminnm_f32
return|return
name|vpminnm_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminnmp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vpminnmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminnmq_f32
return|return
name|vpminnmq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminnmp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vpminnmq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpminnmq_f64
return|return
name|vpminnmq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminnmp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vpadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadd_s8
return|return
name|vpadd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16x4_t
name|test_vpadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadd_s16
return|return
name|vpadd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vpadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadd_s32
return|return
name|vpadd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint8x8_t
name|test_vpadd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadd_u8
return|return
name|vpadd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vpadd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadd_u16
return|return
name|vpadd_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vpadd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadd_u32
return|return
name|vpadd_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x2_t
name|test_vpadd_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpadd_f32
return|return
name|vpadd_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: faddp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int8x16_t
name|test_vpaddq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_s8
return|return
name|vpaddq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16x8_t
name|test_vpaddq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_s16
return|return
name|vpaddq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vpaddq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_s32
return|return
name|vpaddq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8x16_t
name|test_vpaddq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_u8
return|return
name|vpaddq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x8_t
name|test_vpaddq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_u16
return|return
name|vpaddq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x4_t
name|test_vpaddq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_u32
return|return
name|vpaddq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x4_t
name|test_vpaddq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_f32
return|return
name|vpaddq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: faddp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vpaddq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_f64
return|return
name|vpaddq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: faddp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int16x4_t
name|test_vqdmulh_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_s16
return|return
name|vqdmulh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqdmulh_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulh_s32
return|return
name|vqdmulh_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vqdmulhq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_s16
return|return
name|vqdmulhq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmulhq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhq_s32
return|return
name|vqdmulhq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x4_t
name|test_vqrdmulh_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_s16
return|return
name|vqrdmulh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int32x2_t
name|test_vqrdmulh_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulh_s32
return|return
name|vqrdmulh_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vqrdmulhq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_s16
return|return
name|vqrdmulhq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32x4_t
name|test_vqrdmulhq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhq_s32
return|return
name|vqrdmulhq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32x2_t
name|test_vmulx_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulx_f32
return|return
name|vmulx_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32x4_t
name|test_vmulxq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_f32
return|return
name|vmulxq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float64x2_t
name|test_vmulxq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxq_f64
return|return
name|vmulxq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmulx {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vshl_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_n_s8
return|return
name|vshl_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vshl_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_n_s16
return|return
name|vshl_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vshl_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_n_s32
return|return
name|vshl_n_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vshlq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_n_s8
return|return
name|vshlq_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vshlq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_n_s16
return|return
name|vshlq_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vshlq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_n_s32
return|return
name|vshlq_n_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vshlq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_n_s64
return|return
name|vshlq_n_s64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vshl_n_u8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_n_u8
return|return
name|vshl_n_u8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vshl_n_u16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_n_u16
return|return
name|vshl_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vshl_n_u32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_n_u32
return|return
name|vshl_n_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vshlq_n_u8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_n_u8
return|return
name|vshlq_n_u8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vshlq_n_u16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_n_u16
return|return
name|vshlq_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vshlq_n_u32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_n_u32
return|return
name|vshlq_n_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vshlq_n_u64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshlq_n_u64
return|return
name|vshlq_n_u64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vshr_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshr_n_s8
return|return
name|vshr_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sshr {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vshr_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshr_n_s16
return|return
name|vshr_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sshr {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vshr_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshr_n_s32
return|return
name|vshr_n_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sshr {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vshrq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrq_n_s8
return|return
name|vshrq_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sshr {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vshrq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrq_n_s16
return|return
name|vshrq_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sshr {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vshrq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrq_n_s32
return|return
name|vshrq_n_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sshr {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vshrq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrq_n_s64
return|return
name|vshrq_n_s64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sshr {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vshr_n_u8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshr_n_u8
return|return
name|vshr_n_u8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ushr {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vshr_n_u16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshr_n_u16
return|return
name|vshr_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ushr {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vshr_n_u32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshr_n_u32
return|return
name|vshr_n_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ushr {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vshrq_n_u8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrq_n_u8
return|return
name|vshrq_n_u8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ushr {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vshrq_n_u16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrq_n_u16
return|return
name|vshrq_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ushr {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vshrq_n_u32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrq_n_u32
return|return
name|vshrq_n_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ushr {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vshrq_n_u64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrq_n_u64
return|return
name|vshrq_n_u64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ushr {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vsra_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsra_n_s8
return|return
name|vsra_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ssra {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vsra_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsra_n_s16
return|return
name|vsra_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ssra {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vsra_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsra_n_s32
return|return
name|vsra_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ssra {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vsraq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsraq_n_s8
return|return
name|vsraq_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ssra {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vsraq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsraq_n_s16
return|return
name|vsraq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ssra {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vsraq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsraq_n_s32
return|return
name|vsraq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ssra {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vsraq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsraq_n_s64
return|return
name|vsraq_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ssra {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vsra_n_u8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsra_n_u8
return|return
name|vsra_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: usra {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vsra_n_u16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsra_n_u16
return|return
name|vsra_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: usra {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vsra_n_u32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsra_n_u32
return|return
name|vsra_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: usra {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vsraq_n_u8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsraq_n_u8
return|return
name|vsraq_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: usra {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vsraq_n_u16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsraq_n_u16
return|return
name|vsraq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: usra {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vsraq_n_u32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsraq_n_u32
return|return
name|vsraq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: usra {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vsraq_n_u64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsraq_n_u64
return|return
name|vsraq_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: usra {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vrshr_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshr_n_s8
return|return
name|vrshr_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srshr {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vrshr_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshr_n_s16
return|return
name|vrshr_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srshr {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vrshr_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshr_n_s32
return|return
name|vrshr_n_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srshr {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vrshrq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrq_n_s8
return|return
name|vrshrq_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srshr {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vrshrq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrq_n_s16
return|return
name|vrshrq_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srshr {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vrshrq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrq_n_s32
return|return
name|vrshrq_n_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srshr {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vrshrq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrq_n_s64
return|return
name|vrshrq_n_s64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srshr {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vrshr_n_u8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshr_n_u8
return|return
name|vrshr_n_u8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: urshr {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vrshr_n_u16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshr_n_u16
return|return
name|vrshr_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: urshr {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vrshr_n_u32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshr_n_u32
return|return
name|vrshr_n_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: urshr {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vrshrq_n_u8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrq_n_u8
return|return
name|vrshrq_n_u8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: urshr {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vrshrq_n_u16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrq_n_u16
return|return
name|vrshrq_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: urshr {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vrshrq_n_u32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrq_n_u32
return|return
name|vrshrq_n_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: urshr {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vrshrq_n_u64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrq_n_u64
return|return
name|vrshrq_n_u64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: urshr {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vrsra_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsra_n_s8
return|return
name|vrsra_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srsra {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vrsra_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsra_n_s16
return|return
name|vrsra_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srsra {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vrsra_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsra_n_s32
return|return
name|vrsra_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srsra {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vrsraq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsraq_n_s8
return|return
name|vrsraq_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srsra {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vrsraq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsraq_n_s16
return|return
name|vrsraq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srsra {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vrsraq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsraq_n_s32
return|return
name|vrsraq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srsra {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vrsraq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsraq_n_s64
return|return
name|vrsraq_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: srsra {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vrsra_n_u8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsra_n_u8
return|return
name|vrsra_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ursra {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vrsra_n_u16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsra_n_u16
return|return
name|vrsra_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ursra {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vrsra_n_u32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsra_n_u32
return|return
name|vrsra_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ursra {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vrsraq_n_u8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsraq_n_u8
return|return
name|vrsraq_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ursra {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vrsraq_n_u16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsraq_n_u16
return|return
name|vrsraq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ursra {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vrsraq_n_u32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsraq_n_u32
return|return
name|vrsraq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ursra {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vrsraq_n_u64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsraq_n_u64
return|return
name|vrsraq_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ursra {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vsri_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_s8
return|return
name|vsri_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vsri_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_s16
return|return
name|vsri_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vsri_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_s32
return|return
name|vsri_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vsriq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_s8
return|return
name|vsriq_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vsriq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_s16
return|return
name|vsriq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vsriq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_s32
return|return
name|vsriq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vsriq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_s64
return|return
name|vsriq_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vsri_n_u8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_u8
return|return
name|vsri_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vsri_n_u16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_u16
return|return
name|vsri_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vsri_n_u32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_u32
return|return
name|vsri_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vsriq_n_u8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_u8
return|return
name|vsriq_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vsriq_n_u16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_u16
return|return
name|vsriq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vsriq_n_u32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_u32
return|return
name|vsriq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vsriq_n_u64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_u64
return|return
name|vsriq_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|poly8x8_t
name|test_vsri_n_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_p8
return|return
name|vsri_n_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|poly16x4_t
name|test_vsri_n_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_p16
return|return
name|vsri_n_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #15
block|}
end_function

begin_function
name|poly8x16_t
name|test_vsriq_n_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_p8
return|return
name|vsriq_n_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|poly16x8_t
name|test_vsriq_n_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_p16
return|return
name|vsriq_n_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #15
block|}
end_function

begin_function
name|int8x8_t
name|test_vsli_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_s8
return|return
name|vsli_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vsli_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_s16
return|return
name|vsli_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vsli_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_s32
return|return
name|vsli_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vsliq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_s8
return|return
name|vsliq_n_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vsliq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_s16
return|return
name|vsliq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vsliq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_s32
return|return
name|vsliq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vsliq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_s64
return|return
name|vsliq_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|uint8x8_t
name|test_vsli_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_u8
return|return
name|vsli_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|uint16x4_t
name|test_vsli_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_u16
return|return
name|vsli_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|uint32x2_t
name|test_vsli_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_u32
return|return
name|vsli_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|uint8x16_t
name|test_vsliq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_u8
return|return
name|vsliq_n_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsliq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_u16
return|return
name|vsliq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsliq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_u32
return|return
name|vsliq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|uint64x2_t
name|test_vsliq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_u64
return|return
name|vsliq_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|poly8x8_t
name|test_vsli_n_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_p8
return|return
name|vsli_n_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|poly16x4_t
name|test_vsli_n_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_p16
return|return
name|vsli_n_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #15
block|}
end_function

begin_function
name|poly8x16_t
name|test_vsliq_n_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_p8
return|return
name|vsliq_n_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|poly16x8_t
name|test_vsliq_n_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsliq_n_p16
return|return
name|vsliq_n_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: sli {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #15
block|}
end_function

begin_function
name|int8x8_t
name|test_vqshlu_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlu_n_s8
return|return
name|vqshlu_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshlu {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vqshlu_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlu_n_s16
return|return
name|vqshlu_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshlu {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vqshlu_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlu_n_s32
return|return
name|vqshlu_n_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshlu {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #3
block|}
end_function

begin_function
name|int8x16_t
name|test_vqshluq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshluq_n_s8
return|return
name|vqshluq_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshlu {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vqshluq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshluq_n_s16
return|return
name|vqshluq_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshlu {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vqshluq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshluq_n_s32
return|return
name|vqshluq_n_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshlu {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #3
block|}
end_function

begin_function
name|int64x2_t
name|test_vqshluq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshluq_n_s64
return|return
name|vqshluq_n_s64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshlu {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #3
block|}
end_function

begin_function
name|int8x8_t
name|test_vshrn_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_n_s16
return|return
name|vshrn_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vshrn_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_n_s32
return|return
name|vshrn_n_s32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: shrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x2_t
name|test_vshrn_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_n_s64
return|return
name|vshrn_n_s64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: shrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|uint8x8_t
name|test_vshrn_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_n_u16
return|return
name|vshrn_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|uint16x4_t
name|test_vshrn_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_n_u32
return|return
name|vshrn_n_u32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: shrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|uint32x2_t
name|test_vshrn_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_n_u64
return|return
name|vshrn_n_u64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: shrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x16_t
name|test_vshrn_high_n_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_high_n_s16
return|return
name|vshrn_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vshrn_high_n_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_high_n_s32
return|return
name|vshrn_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: shrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x4_t
name|test_vshrn_high_n_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_high_n_s64
return|return
name|vshrn_high_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: shrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|uint8x16_t
name|test_vshrn_high_n_u16
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_high_n_u16
return|return
name|vshrn_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: shrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|uint16x8_t
name|test_vshrn_high_n_u32
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_high_n_u32
return|return
name|vshrn_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: shrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|uint32x4_t
name|test_vshrn_high_n_u64
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrn_high_n_u64
return|return
name|vshrn_high_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: shrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x8_t
name|test_vqshrun_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrun_n_s16
return|return
name|vqshrun_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshrun {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vqshrun_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrun_n_s32
return|return
name|vqshrun_n_s32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sqshrun {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x2_t
name|test_vqshrun_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrun_n_s64
return|return
name|vqshrun_n_s64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sqshrun {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x16_t
name|test_vqshrun_high_n_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrun_high_n_s16
return|return
name|vqshrun_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshrun2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vqshrun_high_n_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrun_high_n_s32
return|return
name|vqshrun_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sqshrun2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x4_t
name|test_vqshrun_high_n_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrun_high_n_s64
return|return
name|vqshrun_high_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sqshrun2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x8_t
name|test_vrshrn_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_n_s16
return|return
name|vrshrn_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: rshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vrshrn_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_n_s32
return|return
name|vrshrn_n_s32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: rshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x2_t
name|test_vrshrn_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_n_s64
return|return
name|vrshrn_n_s64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: rshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|uint8x8_t
name|test_vrshrn_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_n_u16
return|return
name|vrshrn_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: rshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|uint16x4_t
name|test_vrshrn_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_n_u32
return|return
name|vrshrn_n_u32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: rshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|uint32x2_t
name|test_vrshrn_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_n_u64
return|return
name|vrshrn_n_u64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: rshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x16_t
name|test_vrshrn_high_n_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_high_n_s16
return|return
name|vrshrn_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: rshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vrshrn_high_n_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_high_n_s32
return|return
name|vrshrn_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: rshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x4_t
name|test_vrshrn_high_n_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_high_n_s64
return|return
name|vrshrn_high_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: rshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|uint8x16_t
name|test_vrshrn_high_n_u16
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_high_n_u16
return|return
name|vrshrn_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: rshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|uint16x8_t
name|test_vrshrn_high_n_u32
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_high_n_u32
return|return
name|vrshrn_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: rshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|uint32x4_t
name|test_vrshrn_high_n_u64
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrn_high_n_u64
return|return
name|vrshrn_high_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: rshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x8_t
name|test_vqrshrun_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrun_n_s16
return|return
name|vqrshrun_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrshrun {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vqrshrun_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrun_n_s32
return|return
name|vqrshrun_n_s32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sqrshrun {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x2_t
name|test_vqrshrun_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrun_n_s64
return|return
name|vqrshrun_n_s64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sqrshrun {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x16_t
name|test_vqrshrun_high_n_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrun_high_n_s16
return|return
name|vqrshrun_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrshrun2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vqrshrun_high_n_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrun_high_n_s32
return|return
name|vqrshrun_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sqrshrun2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x4_t
name|test_vqrshrun_high_n_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrun_high_n_s64
return|return
name|vqrshrun_high_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sqrshrun2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x8_t
name|test_vqshrn_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_n_s16
return|return
name|vqshrn_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vqshrn_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_n_s32
return|return
name|vqshrn_n_s32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sqshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x2_t
name|test_vqshrn_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_n_s64
return|return
name|vqshrn_n_s64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sqshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqshrn_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_n_u16
return|return
name|vqshrn_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: uqshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|uint16x4_t
name|test_vqshrn_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_n_u32
return|return
name|vqshrn_n_u32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: uqshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|uint32x2_t
name|test_vqshrn_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_n_u64
return|return
name|vqshrn_n_u64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: uqshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x16_t
name|test_vqshrn_high_n_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_high_n_s16
return|return
name|vqshrn_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vqshrn_high_n_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_high_n_s32
return|return
name|vqshrn_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sqshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x4_t
name|test_vqshrn_high_n_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_high_n_s64
return|return
name|vqshrn_high_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sqshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqshrn_high_n_u16
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_high_n_u16
return|return
name|vqshrn_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: uqshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|uint16x8_t
name|test_vqshrn_high_n_u32
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_high_n_u32
return|return
name|vqshrn_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: uqshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|uint32x4_t
name|test_vqshrn_high_n_u64
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrn_high_n_u64
return|return
name|vqshrn_high_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: uqshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x8_t
name|test_vqrshrn_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_n_s16
return|return
name|vqrshrn_n_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vqrshrn_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_n_s32
return|return
name|vqrshrn_n_s32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sqrshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x2_t
name|test_vqrshrn_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_n_s64
return|return
name|vqrshrn_n_s64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sqrshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqrshrn_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_n_u16
return|return
name|vqrshrn_n_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: uqrshrn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|uint16x4_t
name|test_vqrshrn_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_n_u32
return|return
name|vqrshrn_n_u32
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: uqrshrn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|uint32x2_t
name|test_vqrshrn_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_n_u64
return|return
name|vqrshrn_n_u64
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: uqrshrn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int8x16_t
name|test_vqrshrn_high_n_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_high_n_s16
return|return
name|vqrshrn_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sqrshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vqrshrn_high_n_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_high_n_s32
return|return
name|vqrshrn_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sqrshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|int32x4_t
name|test_vqrshrn_high_n_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_high_n_s64
return|return
name|vqrshrn_high_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sqrshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqrshrn_high_n_u16
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_high_n_u16
return|return
name|vqrshrn_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: uqrshrn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, #3
block|}
end_function

begin_function
name|uint16x8_t
name|test_vqrshrn_high_n_u32
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_high_n_u32
return|return
name|vqrshrn_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: uqrshrn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, #9
block|}
end_function

begin_function
name|uint32x4_t
name|test_vqrshrn_high_n_u64
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrn_high_n_u64
return|return
name|vqrshrn_high_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: uqrshrn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, #19
block|}
end_function

begin_function
name|int16x8_t
name|test_vshll_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_s8
return|return
name|vshll_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sshll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vshll_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_s16
return|return
name|vshll_n_s16
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sshll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #9
block|}
end_function

begin_function
name|int64x2_t
name|test_vshll_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_s32
return|return
name|vshll_n_s32
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sshll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #19
block|}
end_function

begin_function
name|uint16x8_t
name|test_vshll_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_u8
return|return
name|vshll_n_u8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ushll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #3
block|}
end_function

begin_function
name|uint32x4_t
name|test_vshll_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_u16
return|return
name|vshll_n_u16
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: ushll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #9
block|}
end_function

begin_function
name|uint64x2_t
name|test_vshll_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_n_u32
return|return
name|vshll_n_u32
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: ushll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #19
block|}
end_function

begin_function
name|int16x8_t
name|test_vshll_high_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_s8
return|return
name|vshll_high_n_s8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: sshll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vshll_high_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_s16
return|return
name|vshll_high_n_s16
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: sshll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #9
block|}
end_function

begin_function
name|int64x2_t
name|test_vshll_high_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_s32
return|return
name|vshll_high_n_s32
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: sshll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #19
block|}
end_function

begin_function
name|uint16x8_t
name|test_vshll_high_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_u8
return|return
name|vshll_high_n_u8
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ushll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #3
block|}
end_function

begin_function
name|uint32x4_t
name|test_vshll_high_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_u16
return|return
name|vshll_high_n_u16
argument_list|(
name|a
argument_list|,
literal|9
argument_list|)
return|;
comment|// CHECK: ushll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #9
block|}
end_function

begin_function
name|uint64x2_t
name|test_vshll_high_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshll_high_n_u32
return|return
name|vshll_high_n_u32
argument_list|(
name|a
argument_list|,
literal|19
argument_list|)
return|;
comment|// CHECK: ushll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #19
block|}
end_function

begin_function
name|int16x8_t
name|test_vmovl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_s8
return|return
name|vmovl_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sshll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #0
block|}
end_function

begin_function
name|int32x4_t
name|test_vmovl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_s16
return|return
name|vmovl_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sshll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #0
block|}
end_function

begin_function
name|int64x2_t
name|test_vmovl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_s32
return|return
name|vmovl_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sshll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #0
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmovl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_u8
return|return
name|vmovl_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ushll {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, #0
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmovl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_u16
return|return
name|vmovl_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ushll {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, #0
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmovl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_u32
return|return
name|vmovl_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ushll {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, #0
block|}
end_function

begin_function
name|int16x8_t
name|test_vmovl_high_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_high_s8
return|return
name|vmovl_high_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sshll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #0
block|}
end_function

begin_function
name|int32x4_t
name|test_vmovl_high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_high_s16
return|return
name|vmovl_high_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sshll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #0
block|}
end_function

begin_function
name|int64x2_t
name|test_vmovl_high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_high_s32
return|return
name|vmovl_high_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sshll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #0
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmovl_high_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_high_u8
return|return
name|vmovl_high_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ushll2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, #0
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmovl_high_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_high_u16
return|return
name|vmovl_high_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ushll2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, #0
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmovl_high_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovl_high_u32
return|return
name|vmovl_high_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ushll2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, #0
block|}
end_function

begin_function
name|float32x2_t
name|test_vcvt_n_f32_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_n_f32_s32
return|return
name|vcvt_n_f32_s32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
comment|// CHECK: scvtf {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #31
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvtq_n_f32_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtq_n_f32_s32
return|return
name|vcvtq_n_f32_s32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
comment|// CHECK: scvtf {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #31
block|}
end_function

begin_function
name|float64x2_t
name|test_vcvtq_n_f64_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtq_n_f64_s64
return|return
name|vcvtq_n_f64_s64
argument_list|(
name|a
argument_list|,
literal|50
argument_list|)
return|;
comment|// CHECK: scvtf {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #50
block|}
end_function

begin_function
name|float32x2_t
name|test_vcvt_n_f32_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_n_f32_u32
return|return
name|vcvt_n_f32_u32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
comment|// CHECK: ucvtf {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #31
block|}
end_function

begin_function
name|float32x4_t
name|test_vcvtq_n_f32_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtq_n_f32_u32
return|return
name|vcvtq_n_f32_u32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
comment|// CHECK: ucvtf {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #31
block|}
end_function

begin_function
name|float64x2_t
name|test_vcvtq_n_f64_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtq_n_f64_u64
return|return
name|vcvtq_n_f64_u64
argument_list|(
name|a
argument_list|,
literal|50
argument_list|)
return|;
comment|// CHECK: ucvtf {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #50
block|}
end_function

begin_function
name|int32x2_t
name|test_vcvt_n_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_n_s32_f32
return|return
name|vcvt_n_s32_f32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
comment|// CHECK: fcvtzs {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #31
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtq_n_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtq_n_s32_f32
return|return
name|vcvtq_n_s32_f32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
comment|// CHECK: fcvtzs {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #31
block|}
end_function

begin_function
name|int64x2_t
name|test_vcvtq_n_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtq_n_s64_f64
return|return
name|vcvtq_n_s64_f64
argument_list|(
name|a
argument_list|,
literal|50
argument_list|)
return|;
comment|// CHECK: fcvtzs {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #50
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvt_n_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_n_u32_f32
return|return
name|vcvt_n_u32_f32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
comment|// CHECK: fcvtzu {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #31
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtq_n_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtq_n_u32_f32
return|return
name|vcvtq_n_u32_f32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
comment|// CHECK: fcvtzu {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #31
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcvtq_n_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtq_n_u64_f64
return|return
name|vcvtq_n_u64_f64
argument_list|(
name|a
argument_list|,
literal|50
argument_list|)
return|;
comment|// CHECK: fcvtzu {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #50
block|}
end_function

begin_function
name|int16x8_t
name|test_vaddl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_s8
return|return
name|vaddl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddl {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vaddl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_s16
return|return
name|vaddl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vaddl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_s32
return|return
name|vaddl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vaddl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_u8
return|return
name|vaddl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddl {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vaddl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_u16
return|return
name|vaddl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vaddl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_u32
return|return
name|vaddl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vaddl_high_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_high_s8
return|return
name|vaddl_high_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddl2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vaddl_high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_high_s16
return|return
name|vaddl_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vaddl_high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_high_s32
return|return
name|vaddl_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vaddl_high_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_high_u8
return|return
name|vaddl_high_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddl2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vaddl_high_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_high_u16
return|return
name|vaddl_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vaddl_high_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddl_high_u32
return|return
name|vaddl_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x8_t
name|test_vaddw_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_s8
return|return
name|vaddw_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddw {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vaddw_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_s16
return|return
name|vaddw_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddw {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vaddw_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_s32
return|return
name|vaddw_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddw {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vaddw_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_u8
return|return
name|vaddw_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddw {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vaddw_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_u16
return|return
name|vaddw_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddw {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vaddw_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_u32
return|return
name|vaddw_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddw {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vaddw_high_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_high_s8
return|return
name|vaddw_high_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddw2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vaddw_high_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_high_s16
return|return
name|vaddw_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddw2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vaddw_high_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_high_s32
return|return
name|vaddw_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: saddw2 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vaddw_high_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_high_u8
return|return
name|vaddw_high_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddw2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vaddw_high_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_high_u16
return|return
name|vaddw_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddw2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vaddw_high_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddw_high_u32
return|return
name|vaddw_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uaddw2 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x8_t
name|test_vsubl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_s8
return|return
name|vsubl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubl {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vsubl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_s16
return|return
name|vsubl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vsubl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_s32
return|return
name|vsubl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsubl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_u8
return|return
name|vsubl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubl {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsubl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_u16
return|return
name|vsubl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vsubl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_u32
return|return
name|vsubl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vsubl_high_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_high_s8
return|return
name|vsubl_high_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubl2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vsubl_high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_high_s16
return|return
name|vsubl_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vsubl_high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_high_s32
return|return
name|vsubl_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsubl_high_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_high_u8
return|return
name|vsubl_high_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubl2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsubl_high_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_high_u16
return|return
name|vsubl_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vsubl_high_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubl_high_u32
return|return
name|vsubl_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x8_t
name|test_vsubw_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_s8
return|return
name|vsubw_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubw {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vsubw_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_s16
return|return
name|vsubw_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubw {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vsubw_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_s32
return|return
name|vsubw_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubw {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsubw_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_u8
return|return
name|vsubw_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubw {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsubw_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_u16
return|return
name|vsubw_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubw {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vsubw_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_u32
return|return
name|vsubw_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubw {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vsubw_high_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_high_s8
return|return
name|vsubw_high_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubw2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vsubw_high_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_high_s16
return|return
name|vsubw_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubw2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vsubw_high_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_high_s32
return|return
name|vsubw_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ssubw2 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsubw_high_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_high_u8
return|return
name|vsubw_high_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubw2 {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsubw_high_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_high_u16
return|return
name|vsubw_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubw2 {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vsubw_high_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubw_high_u32
return|return
name|vsubw_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usubw2 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int8x8_t
name|test_vaddhn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_s16
return|return
name|vaddhn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x4_t
name|test_vaddhn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_s32
return|return
name|vaddhn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x2_t
name|test_vaddhn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_s64
return|return
name|vaddhn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vaddhn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_u16
return|return
name|vaddhn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x4_t
name|test_vaddhn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_u32
return|return
name|vaddhn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x2_t
name|test_vaddhn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_u64
return|return
name|vaddhn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x16_t
name|test_vaddhn_high_s16
parameter_list|(
name|int8x8_t
name|r
parameter_list|,
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_high_s16
return|return
name|vaddhn_high_s16
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x8_t
name|test_vaddhn_high_s32
parameter_list|(
name|int16x4_t
name|r
parameter_list|,
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_high_s32
return|return
name|vaddhn_high_s32
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vaddhn_high_s64
parameter_list|(
name|int32x2_t
name|r
parameter_list|,
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_high_s64
return|return
name|vaddhn_high_s64
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vaddhn_high_u16
parameter_list|(
name|uint8x8_t
name|r
parameter_list|,
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_high_u16
return|return
name|vaddhn_high_u16
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vaddhn_high_u32
parameter_list|(
name|uint16x4_t
name|r
parameter_list|,
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_high_u32
return|return
name|vaddhn_high_u32
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vaddhn_high_u64
parameter_list|(
name|uint32x2_t
name|r
parameter_list|,
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddhn_high_u64
return|return
name|vaddhn_high_u64
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addhn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vraddhn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_s16
return|return
name|vraddhn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x4_t
name|test_vraddhn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_s32
return|return
name|vraddhn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x2_t
name|test_vraddhn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_s64
return|return
name|vraddhn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vraddhn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_u16
return|return
name|vraddhn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x4_t
name|test_vraddhn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_u32
return|return
name|vraddhn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x2_t
name|test_vraddhn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_u64
return|return
name|vraddhn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x16_t
name|test_vraddhn_high_s16
parameter_list|(
name|int8x8_t
name|r
parameter_list|,
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_high_s16
return|return
name|vraddhn_high_s16
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x8_t
name|test_vraddhn_high_s32
parameter_list|(
name|int16x4_t
name|r
parameter_list|,
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_high_s32
return|return
name|vraddhn_high_s32
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vraddhn_high_s64
parameter_list|(
name|int32x2_t
name|r
parameter_list|,
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_high_s64
return|return
name|vraddhn_high_s64
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vraddhn_high_u16
parameter_list|(
name|uint8x8_t
name|r
parameter_list|,
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_high_u16
return|return
name|vraddhn_high_u16
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vraddhn_high_u32
parameter_list|(
name|uint16x4_t
name|r
parameter_list|,
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_high_u32
return|return
name|vraddhn_high_u32
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vraddhn_high_u64
parameter_list|(
name|uint32x2_t
name|r
parameter_list|,
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vraddhn_high_u64
return|return
name|vraddhn_high_u64
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: raddhn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vsubhn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_s16
return|return
name|vsubhn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x4_t
name|test_vsubhn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_s32
return|return
name|vsubhn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x2_t
name|test_vsubhn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_s64
return|return
name|vsubhn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vsubhn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_u16
return|return
name|vsubhn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x4_t
name|test_vsubhn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_u32
return|return
name|vsubhn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x2_t
name|test_vsubhn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_u64
return|return
name|vsubhn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x16_t
name|test_vsubhn_high_s16
parameter_list|(
name|int8x8_t
name|r
parameter_list|,
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_high_s16
return|return
name|vsubhn_high_s16
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x8_t
name|test_vsubhn_high_s32
parameter_list|(
name|int16x4_t
name|r
parameter_list|,
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_high_s32
return|return
name|vsubhn_high_s32
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vsubhn_high_s64
parameter_list|(
name|int32x2_t
name|r
parameter_list|,
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_high_s64
return|return
name|vsubhn_high_s64
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vsubhn_high_u16
parameter_list|(
name|uint8x8_t
name|r
parameter_list|,
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_high_u16
return|return
name|vsubhn_high_u16
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsubhn_high_u32
parameter_list|(
name|uint16x4_t
name|r
parameter_list|,
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_high_u32
return|return
name|vsubhn_high_u32
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsubhn_high_u64
parameter_list|(
name|uint32x2_t
name|r
parameter_list|,
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubhn_high_u64
return|return
name|vsubhn_high_u64
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: subhn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x8_t
name|test_vrsubhn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_s16
return|return
name|vrsubhn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x4_t
name|test_vrsubhn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_s32
return|return
name|vrsubhn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x2_t
name|test_vrsubhn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_s64
return|return
name|vrsubhn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x8_t
name|test_vrsubhn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_u16
return|return
name|vrsubhn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn {{v[0-9]+}}.8b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x4_t
name|test_vrsubhn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_u32
return|return
name|vrsubhn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn {{v[0-9]+}}.4h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x2_t
name|test_vrsubhn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_u64
return|return
name|vrsubhn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn {{v[0-9]+}}.2s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int8x16_t
name|test_vrsubhn_high_s16
parameter_list|(
name|int8x8_t
name|r
parameter_list|,
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_high_s16
return|return
name|vrsubhn_high_s16
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int16x8_t
name|test_vrsubhn_high_s32
parameter_list|(
name|int16x4_t
name|r
parameter_list|,
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_high_s32
return|return
name|vrsubhn_high_s32
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vrsubhn_high_s64
parameter_list|(
name|int32x2_t
name|r
parameter_list|,
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_high_s64
return|return
name|vrsubhn_high_s64
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint8x16_t
name|test_vrsubhn_high_u16
parameter_list|(
name|uint8x8_t
name|r
parameter_list|,
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_high_u16
return|return
name|vrsubhn_high_u16
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn2 {{v[0-9]+}}.16b, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vrsubhn_high_u32
parameter_list|(
name|uint16x4_t
name|r
parameter_list|,
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_high_u32
return|return
name|vrsubhn_high_u32
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn2 {{v[0-9]+}}.8h, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vrsubhn_high_u64
parameter_list|(
name|uint32x2_t
name|r
parameter_list|,
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsubhn_high_u64
return|return
name|vrsubhn_high_u64
argument_list|(
name|r
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: rsubhn2 {{v[0-9]+}}.4s, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int16x8_t
name|test_vabdl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_s8
return|return
name|vabdl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sabdl {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vabdl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_s16
return|return
name|vabdl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sabdl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vabdl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_s32
return|return
name|vabdl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sabdl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vabdl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_u8
return|return
name|vabdl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uabdl {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vabdl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_u16
return|return
name|vabdl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uabdl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vabdl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_u32
return|return
name|vabdl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uabdl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vabal_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_s8
return|return
name|vabal_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sabal {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vabal_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_s16
return|return
name|vabal_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sabal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vabal_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_s32
return|return
name|vabal_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sabal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vabal_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_u8
return|return
name|vabal_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: uabal {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vabal_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_u16
return|return
name|vabal_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: uabal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vabal_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_u32
return|return
name|vabal_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: uabal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vabdl_high_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_high_s8
return|return
name|vabdl_high_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sabdl2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vabdl_high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_high_s16
return|return
name|vabdl_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sabdl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vabdl_high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_high_s32
return|return
name|vabdl_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sabdl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vabdl_high_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_high_u8
return|return
name|vabdl_high_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uabdl2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vabdl_high_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_high_u16
return|return
name|vabdl_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uabdl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vabdl_high_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdl_high_u32
return|return
name|vabdl_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uabdl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x8_t
name|test_vabal_high_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|,
name|int8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_high_s8
return|return
name|vabal_high_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sabal2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vabal_high_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_high_s16
return|return
name|vabal_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sabal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vabal_high_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_high_s32
return|return
name|vabal_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sabal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vabal_high_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_high_u8
return|return
name|vabal_high_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: uabal2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vabal_high_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_high_u16
return|return
name|vabal_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: uabal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vabal_high_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabal_high_u32
return|return
name|vabal_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: uabal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x8_t
name|test_vmull_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_s8
return|return
name|vmull_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_s16
return|return
name|vmull_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_s32
return|return
name|vmull_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmull_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_u8
return|return
name|vmull_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_u16
return|return
name|vmull_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_u32
return|return
name|vmull_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vmull_high_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_s8
return|return
name|vmull_high_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vmull_high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_s16
return|return
name|vmull_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vmull_high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_s32
return|return
name|vmull_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: smull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmull_high_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_u8
return|return
name|vmull_high_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmull_high_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_u16
return|return
name|vmull_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmull_high_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_u32
return|return
name|vmull_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: umull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlal_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_s8
return|return
name|vmlal_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlal {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_s16
return|return
name|vmlal_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_s32
return|return
name|vmlal_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlal_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_u8
return|return
name|vmlal_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlal {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlal_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_u16
return|return
name|vmlal_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmlal_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_u32
return|return
name|vmlal_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlal_high_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|,
name|int8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_s8
return|return
name|vmlal_high_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlal2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlal_high_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_s16
return|return
name|vmlal_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlal_high_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_s32
return|return
name|vmlal_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlal_high_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_u8
return|return
name|vmlal_high_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlal2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlal_high_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_u16
return|return
name|vmlal_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmlal_high_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlal_high_u32
return|return
name|vmlal_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlsl_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|,
name|int8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_s8
return|return
name|vmlsl_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlsl {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_s16
return|return
name|vmlsl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_s32
return|return
name|vmlsl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlsl_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|,
name|uint8x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_u8
return|return
name|vmlsl_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlsl {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsl_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_u16
return|return
name|vmlsl_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmlsl_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_u32
return|return
name|vmlsl_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int16x8_t
name|test_vmlsl_high_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|,
name|int8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_s8
return|return
name|vmlsl_high_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlsl2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32x4_t
name|test_vmlsl_high_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_s16
return|return
name|vmlsl_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vmlsl_high_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_s32
return|return
name|vmlsl_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: smlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16x8_t
name|test_vmlsl_high_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|,
name|uint8x16_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_u8
return|return
name|vmlsl_high_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlsl2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32x4_t
name|test_vmlsl_high_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_u16
return|return
name|vmlsl_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64x2_t
name|test_vmlsl_high_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmlsl_high_u32
return|return
name|vmlsl_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: umlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_s16
return|return
name|vqdmull_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_s32
return|return
name|vqdmull_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmull {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_s16
return|return
name|vqdmlal_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlal {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_s32
return|return
name|vqdmlal_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlal {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_s16
return|return
name|vqdmlsl_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{v[0-9]+}}.4s, {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_s32
return|return
name|vqdmlsl_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlsl {{v[0-9]+}}.2d, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmull_high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_s16
return|return
name|vqdmull_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmull_high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmull_high_s32
return|return
name|vqdmull_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmull2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlal_high_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_s16
return|return
name|vqdmlal_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlal_high_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlal_high_s32
return|return
name|vqdmlal_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlal2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int32x4_t
name|test_vqdmlsl_high_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_s16
return|return
name|vqdmlsl_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.4s, {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64x2_t
name|test_vqdmlsl_high_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsl_high_s32
return|return
name|vqdmlsl_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: sqdmlsl2 {{v[0-9]+}}.2d, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|poly16x8_t
name|test_vmull_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_p8
return|return
name|vmull_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: pmull {{v[0-9]+}}.8h, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly16x8_t
name|test_vmull_high_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_p8
return|return
name|vmull_high_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: pmull2 {{v[0-9]+}}.8h, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int64_t
name|test_vaddd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddd_s64
return|return
name|vaddd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: add {{[xd][0-9]+}}, {{[xd][0-9]+}}, {{[xd][0-9]+}}
block|}
end_function

begin_function
name|uint64_t
name|test_vaddd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddd_u64
return|return
name|vaddd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: add {{[xd][0-9]+}}, {{[xd][0-9]+}}, {{[xd][0-9]+}}
block|}
end_function

begin_function
name|int64_t
name|test_vsubd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubd_s64
return|return
name|vsubd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sub {{[xd][0-9]+}}, {{[xd][0-9]+}}, {{[xd][0-9]+}}
block|}
end_function

begin_function
name|uint64_t
name|test_vsubd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsubd_u64
return|return
name|vsubd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sub {{[xd][0-9]+}}, {{[xd][0-9]+}}, {{[xd][0-9]+}}
block|}
end_function

begin_function
name|int8_t
name|test_vqaddb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddb_s8
return|return
name|vqaddb_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
block|}
end_function

begin_function
name|int16_t
name|test_vqaddh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddh_s16
return|return
name|vqaddh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_function
name|int32_t
name|test_vqadds_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqadds_s32
return|return
name|vqadds_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|int64_t
name|test_vqaddd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddd_s64
return|return
name|vqaddd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8_t
name|test_vqaddb_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddb_u8
return|return
name|vqaddb_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
block|}
end_function

begin_function
name|uint16_t
name|test_vqaddh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddh_u16
return|return
name|vqaddh_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_function
name|uint32_t
name|test_vqadds_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqadds_u32
return|return
name|vqadds_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|uint64_t
name|test_vqaddd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqaddd_u64
return|return
name|vqaddd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqadd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int8_t
name|test_vqsubb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubb_s8
return|return
name|vqsubb_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
block|}
end_function

begin_function
name|int16_t
name|test_vqsubh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubh_s16
return|return
name|vqsubh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_function
name|int32_t
name|test_vqsubs_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubs_s32
return|return
name|vqsubs_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|int64_t
name|test_vqsubd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubd_s64
return|return
name|vqsubd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint8_t
name|test_vqsubb_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubb_u8
return|return
name|vqsubb_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
block|}
end_function

begin_function
name|uint16_t
name|test_vqsubh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubh_u16
return|return
name|vqsubh_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_function
name|uint32_t
name|test_vqsubs_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubs_u32
return|return
name|vqsubs_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|uint64_t
name|test_vqsubd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqsubd_u64
return|return
name|vqsubd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqsub {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|int64_t
name|test_vshld_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshld_s64
return|return
name|vshld_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64_t
name|test_vshld_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshld_u64
return|return
name|vshld_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: ushl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlb_s8
end_comment

begin_function
name|int8_t
name|test_vqshlb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8_t
name|b
parameter_list|)
block|{
return|return
name|vqshlb_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlh_s16
end_comment

begin_function
name|int16_t
name|test_vqshlh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqshlh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshls_s32
end_comment

begin_function
name|int32_t
name|test_vqshls_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqshls_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshld_s64
end_comment

begin_function
name|int64_t
name|test_vqshld_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
return|return
name|vqshld_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlb_u8
end_comment

begin_function
name|uint8_t
name|test_vqshlb_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
return|return
name|vqshlb_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshlh_u16
end_comment

begin_function
name|uint16_t
name|test_vqshlh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vqshlh_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshls_u32
end_comment

begin_function
name|uint32_t
name|test_vqshls_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vqshls_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqshld_u64
end_comment

begin_function
name|uint64_t
name|test_vqshld_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|vqshld_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshld_s64
end_comment

begin_function
name|int64_t
name|test_vrshld_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
return|return
name|vrshld_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: srshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vrshld_u64
end_comment

begin_function
name|uint64_t
name|test_vrshld_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|vrshld_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: urshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlb_s8
end_comment

begin_function
name|int8_t
name|test_vqrshlb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlb_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlh_s16
end_comment

begin_function
name|int16_t
name|test_vqrshlh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshls_s32
end_comment

begin_function
name|int32_t
name|test_vqrshls_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqrshls_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshld_s64
end_comment

begin_function
name|int64_t
name|test_vqrshld_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
return|return
name|vqrshld_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlb_u8
end_comment

begin_function
name|uint8_t
name|test_vqrshlb_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlb_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshlh_u16
end_comment

begin_function
name|uint16_t
name|test_vqrshlh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vqrshlh_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshls_u32
end_comment

begin_function
name|uint32_t
name|test_vqrshls_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vqrshls_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vqrshld_u64
end_comment

begin_function
name|uint64_t
name|test_vqrshld_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
return|return
name|vqrshld_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: uqrshl {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddd_s64
end_comment

begin_function
name|int64_t
name|test_vpaddd_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vpaddd_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpadds_f32
end_comment

begin_function
name|float32_t
name|test_vpadds_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vpadds_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: faddp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpaddd_f64
end_comment

begin_function
name|float64_t
name|test_vpaddd_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vpaddd_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: faddp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmaxnms_f32
end_comment

begin_function
name|float32_t
name|test_vpmaxnms_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vpmaxnms_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxnmp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmaxnmqd_f64
end_comment

begin_function
name|float64_t
name|test_vpmaxnmqd_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vpmaxnmqd_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxnmp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmaxs_f32
end_comment

begin_function
name|float32_t
name|test_vpmaxs_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vpmaxs_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmaxqd_f64
end_comment

begin_function
name|float64_t
name|test_vpmaxqd_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vpmaxqd_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpminnms_f32
end_comment

begin_function
name|float32_t
name|test_vpminnms_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vpminnms_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminnmp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpminnmqd_f64
end_comment

begin_function
name|float64_t
name|test_vpminnmqd_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vpminnmqd_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminnmp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpmins_f32
end_comment

begin_function
name|float32_t
name|test_vpmins_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vpmins_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vpminqd_f64
end_comment

begin_function
name|float64_t
name|test_vpminqd_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vpminqd_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int16_t
name|test_vqdmulhh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhh_s16
return|return
name|vqdmulhh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmulh {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_function
name|int32_t
name|test_vqdmulhs_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulhs_s32
return|return
name|vqdmulhs_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqdmulh {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|int16_t
name|test_vqrdmulhh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhh_s16
return|return
name|vqrdmulhh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
block|}
end_function

begin_function
name|int32_t
name|test_vqrdmulhs_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrdmulhs_s32
return|return
name|vqrdmulhs_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: sqrdmulh {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|float32_t
name|test_vmulxs_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxs_f32
return|return
name|vmulxs_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmulx {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|float64_t
name|test_vmulxd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulxd_f64
return|return
name|vmulxd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmulx {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vmulx_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmulx_f64
return|return
name|vmulx_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmulx {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|float32_t
name|test_vrecpss_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecpss_f32
return|return
name|vrecpss_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: frecps {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|float64_t
name|test_vrecpsd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecpsd_f64
return|return
name|vrecpsd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: frecps {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|float32_t
name|test_vrsqrtss_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsqrtss_f32
return|return
name|vrsqrtss_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: frsqrts {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
block|}
end_function

begin_function
name|float64_t
name|test_vrsqrtsd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsqrtsd_f64
return|return
name|vrsqrtsd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: frsqrts {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|float32_t
name|test_vcvts_f32_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvts_f32_s32
comment|// CHECK: scvtf {{s[0-9]+}}, {{[ws][0-9]+}}
return|return
name|vcvts_f32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float64_t
name|test_vcvtd_f64_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtd_f64_s64
comment|// CHECK: scvtf {{d[0-9]+}}, {{[dx][0-9]+}}
return|return
name|vcvtd_f64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vcvts_f32_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvts_f32_u32
comment|// CHECK: ucvtf {{s[0-9]+}}, {{[ws][0-9]+}}
return|return
name|vcvts_f32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float64_t
name|test_vcvtd_f64_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtd_f64_u64
comment|// CHECK: ucvtf {{d[0-9]+}}, {{[xd][0-9]+}}
return|return
name|vcvtd_f64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vrecpes_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecpes_f32
comment|// CHECK: frecpe {{s[0-9]+}}, {{s[0-9]+}}
return|return
name|vrecpes_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float64_t
name|test_vrecped_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecped_f64
comment|// CHECK: frecpe {{d[0-9]+}}, {{d[0-9]+}}
return|return
name|vrecped_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vrecpxs_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecpxs_f32
comment|// CHECK: frecpx {{s[0-9]+}}, {{s[0-9]+}}
return|return
name|vrecpxs_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float64_t
name|test_vrecpxd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecpxd_f64
comment|// CHECK: frecpx {{d[0-9]+}}, {{d[0-9]+}}
return|return
name|vrecpxd_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|test_vrsqrte_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsqrte_u32
comment|// CHECK: ursqrte {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
return|return
name|vrsqrte_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vrsqrteq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsqrteq_u32
comment|// CHECK: ursqrte {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
return|return
name|vrsqrteq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vrsqrtes_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK: vrsqrtes_f32
comment|// CHECK: frsqrte {{s[0-9]+}}, {{s[0-9]+}}
return|return
name|vrsqrtes_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float64_t
name|test_vrsqrted_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK: vrsqrted_f64
comment|// CHECK: frsqrte {{d[0-9]+}}, {{d[0-9]+}}
return|return
name|vrsqrted_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x16_t
name|test_vld1q_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u8
return|return
name|vld1q_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.16b }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vld1q_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u16
return|return
name|vld1q_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.8h }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vld1q_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u32
return|return
name|vld1q_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.4s }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vld1q_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u64
return|return
name|vld1q_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.2d }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16_t
name|test_vld1q_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s8
return|return
name|vld1q_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.16b }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8_t
name|test_vld1q_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s16
return|return
name|vld1q_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.8h }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4_t
name|test_vld1q_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s32
return|return
name|vld1q_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.4s }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2_t
name|test_vld1q_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s64
return|return
name|vld1q_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.2d }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8_t
name|test_vld1q_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f16
return|return
name|vld1q_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.8h }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4_t
name|test_vld1q_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f32
return|return
name|vld1q_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.4s }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2_t
name|test_vld1q_f64
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f64
return|return
name|vld1q_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.2d }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16_t
name|test_vld1q_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p8
return|return
name|vld1q_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.16b }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8_t
name|test_vld1q_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p16
return|return
name|vld1q_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.8h }|ldr q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8_t
name|test_vld1_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u8
return|return
name|vld1_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.8b }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vld1_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u16
return|return
name|vld1_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.4h }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vld1_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u32
return|return
name|vld1_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.2s }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1_t
name|test_vld1_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u64
return|return
name|vld1_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8_t
name|test_vld1_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s8
return|return
name|vld1_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.8b }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4_t
name|test_vld1_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s16
return|return
name|vld1_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.4h }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2_t
name|test_vld1_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s32
return|return
name|vld1_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.2s }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1_t
name|test_vld1_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s64
return|return
name|vld1_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4_t
name|test_vld1_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f16
return|return
name|vld1_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.4h }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2_t
name|test_vld1_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f32
return|return
name|vld1_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.2s }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1_t
name|test_vld1_f64
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f64
return|return
name|vld1_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8_t
name|test_vld1_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p8
return|return
name|vld1_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.8b }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4_t
name|test_vld1_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p16
return|return
name|vld1_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1 { v[0-9]+.4h }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x2_t
name|test_vld2q_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_u8
return|return
name|vld2q_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x2_t
name|test_vld2q_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_u16
return|return
name|vld2q_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x2_t
name|test_vld2q_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_u32
return|return
name|vld2q_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x2_t
name|test_vld2q_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_u64
return|return
name|vld2q_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x2_t
name|test_vld2q_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_s8
return|return
name|vld2q_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x2_t
name|test_vld2q_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_s16
return|return
name|vld2q_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x2_t
name|test_vld2q_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_s32
return|return
name|vld2q_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x2_t
name|test_vld2q_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_s64
return|return
name|vld2q_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x2_t
name|test_vld2q_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_f16
return|return
name|vld2q_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x2_t
name|test_vld2q_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_f32
return|return
name|vld2q_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x2_t
name|test_vld2q_f64
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_f64
return|return
name|vld2q_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x2_t
name|test_vld2q_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_p8
return|return
name|vld2q_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x2_t
name|test_vld2q_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_p16
return|return
name|vld2q_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x2_t
name|test_vld2_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_u8
return|return
name|vld2_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x2_t
name|test_vld2_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_u16
return|return
name|vld2_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x2_t
name|test_vld2_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_u32
return|return
name|vld2_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x2_t
name|test_vld2_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_u64
return|return
name|vld2_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld2}} {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x2_t
name|test_vld2_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_s8
return|return
name|vld2_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x2_t
name|test_vld2_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_s16
return|return
name|vld2_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x2_t
name|test_vld2_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_s32
return|return
name|vld2_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x2_t
name|test_vld2_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_s64
return|return
name|vld2_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld2}} {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x2_t
name|test_vld2_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_f16
return|return
name|vld2_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x2_t
name|test_vld2_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_f32
return|return
name|vld2_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x2_t
name|test_vld2_f64
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_f64
return|return
name|vld2_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld2}} {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x2_t
name|test_vld2_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_p8
return|return
name|vld2_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x2_t
name|test_vld2_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_p16
return|return
name|vld2_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x3_t
name|test_vld3q_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_u8
return|return
name|vld3q_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x3_t
name|test_vld3q_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_u16
return|return
name|vld3q_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x3_t
name|test_vld3q_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_u32
return|return
name|vld3q_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x3_t
name|test_vld3q_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_u64
return|return
name|vld3q_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x3_t
name|test_vld3q_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_s8
return|return
name|vld3q_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x3_t
name|test_vld3q_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_s16
return|return
name|vld3q_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x3_t
name|test_vld3q_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_s32
return|return
name|vld3q_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x3_t
name|test_vld3q_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_s64
return|return
name|vld3q_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x3_t
name|test_vld3q_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_f16
return|return
name|vld3q_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x3_t
name|test_vld3q_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_f32
return|return
name|vld3q_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x3_t
name|test_vld3q_f64
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_f64
return|return
name|vld3q_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x3_t
name|test_vld3q_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_p8
return|return
name|vld3q_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x3_t
name|test_vld3q_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_p16
return|return
name|vld3q_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x3_t
name|test_vld3_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_u8
return|return
name|vld3_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x3_t
name|test_vld3_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_u16
return|return
name|vld3_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x3_t
name|test_vld3_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_u32
return|return
name|vld3_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x3_t
name|test_vld3_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_u64
return|return
name|vld3_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld3}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x3_t
name|test_vld3_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_s8
return|return
name|vld3_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x3_t
name|test_vld3_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_s16
return|return
name|vld3_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x3_t
name|test_vld3_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_s32
return|return
name|vld3_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x3_t
name|test_vld3_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_s64
return|return
name|vld3_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld3}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x3_t
name|test_vld3_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_f16
return|return
name|vld3_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x3_t
name|test_vld3_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_f32
return|return
name|vld3_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x3_t
name|test_vld3_f64
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_f64
return|return
name|vld3_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld3}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x3_t
name|test_vld3_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_p8
return|return
name|vld3_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x3_t
name|test_vld3_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_p16
return|return
name|vld3_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x4_t
name|test_vld4q_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_u8
return|return
name|vld4q_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x4_t
name|test_vld4q_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_u16
return|return
name|vld4q_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x4_t
name|test_vld4q_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_u32
return|return
name|vld4q_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x4_t
name|test_vld4q_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_u64
return|return
name|vld4q_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x4_t
name|test_vld4q_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_s8
return|return
name|vld4q_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x4_t
name|test_vld4q_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_s16
return|return
name|vld4q_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x4_t
name|test_vld4q_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_s32
return|return
name|vld4q_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x4_t
name|test_vld4q_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_s64
return|return
name|vld4q_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x4_t
name|test_vld4q_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_f16
return|return
name|vld4q_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x4_t
name|test_vld4q_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_f32
return|return
name|vld4q_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x4_t
name|test_vld4q_f64
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_f64
return|return
name|vld4q_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x4_t
name|test_vld4q_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_p8
return|return
name|vld4q_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x4_t
name|test_vld4q_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_p16
return|return
name|vld4q_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x4_t
name|test_vld4_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_u8
return|return
name|vld4_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x4_t
name|test_vld4_u16
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_u16
return|return
name|vld4_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x4_t
name|test_vld4_u32
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_u32
return|return
name|vld4_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x4_t
name|test_vld4_u64
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_u64
return|return
name|vld4_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld4}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x4_t
name|test_vld4_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_s8
return|return
name|vld4_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x4_t
name|test_vld4_s16
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_s16
return|return
name|vld4_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x4_t
name|test_vld4_s32
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_s32
return|return
name|vld4_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x4_t
name|test_vld4_s64
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_s64
return|return
name|vld4_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld4}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x4_t
name|test_vld4_f16
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_f16
return|return
name|vld4_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x4_t
name|test_vld4_f32
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_f32
return|return
name|vld4_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x4_t
name|test_vld4_f64
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_f64
return|return
name|vld4_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld4}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x4_t
name|test_vld4_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_p8
return|return
name|vld4_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x4_t
name|test_vld4_p16
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_p16
return|return
name|vld4_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u8
name|vst1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.16b }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u16
name|vst1q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.8h }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u32
name|vst1q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.4s }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u64
name|vst1q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.2d }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s8
name|vst1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.16b }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s16
name|vst1q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.8h }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s32
name|vst1q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.4s }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s64
name|vst1q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.2d }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f16
name|vst1q_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.8h }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f32
name|vst1q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.4s }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f64
name|vst1q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.2d }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p8
name|vst1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.16b }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p16
name|vst1q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.8h }|str q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u8
name|vst1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.8b }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u16
name|vst1_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.4h }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u32
name|vst1_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.2s }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u64
name|vst1_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.1d }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s8
name|vst1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.8b }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s16
name|vst1_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.4h }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s32
name|vst1_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.2s }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s64
name|vst1_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.1d }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f16
name|vst1_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.4h }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f32
name|vst1_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.2s }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f64
name|vst1_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.1d }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p8
name|vst1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.8b }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p16
name|vst1_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.4h }|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_u8
name|vst2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_u16
name|vst2q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_u32
name|vst2q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_u64
name|vst2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_s8
name|vst2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_s16
name|vst2q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_s32
name|vst2q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_s64
name|vst2q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_f16
name|vst2q_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_f32
name|vst2q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_f64
name|vst2q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_p8
name|vst2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_p16
name|vst2q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_u8
name|vst2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_u16
name|vst2_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_u32
name|vst2_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_u64
name|vst2_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1|st2}} {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_s8
name|vst2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_s16
name|vst2_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_s32
name|vst2_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_s64
name|vst2_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1|st2}} {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_f16
name|vst2_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_f32
name|vst2_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_f64
name|vst2_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1|st2}} {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_p8
name|vst2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_p16
name|vst2_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_u8
name|vst3q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_u16
name|vst3q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_u32
name|vst3q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_u64
name|vst3q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_s8
name|vst3q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_s16
name|vst3q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_s32
name|vst3q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_s64
name|vst3q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_f16
name|vst3q_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_f32
name|vst3q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_f64
name|vst3q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_p8
name|vst3q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_p16
name|vst3q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_u8
name|vst3_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_u16
name|vst3_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_u32
name|vst3_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_u64
name|vst3_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1|st3}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_s8
name|vst3_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_s16
name|vst3_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_s32
name|vst3_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_s64
name|vst3_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1|st3}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_f16
name|vst3_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_f32
name|vst3_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_f64
name|vst3_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1|st3}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_p8
name|vst3_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_p16
name|vst3_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_u8
name|vst4q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_u16
name|vst4q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_u32
name|vst4q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_u64
name|vst4q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_s8
name|vst4q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_s16
name|vst4q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_s32
name|vst4q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_s64
name|vst4q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_f16
name|vst4q_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_f32
name|vst4q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_f64
name|vst4q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_p8
name|vst4q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_p16
name|vst4q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_u8
name|vst4_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_u16
name|vst4_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_u32
name|vst4_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_u64
name|vst4_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1|st4}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_s8
name|vst4_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_s16
name|vst4_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_s32
name|vst4_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_s64
name|vst4_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1|st4}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_f16
name|vst4_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_f32
name|vst4_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_f64
name|vst4_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1|st4}} {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_p8
name|vst4_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_p16
name|vst4_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x2_t
name|test_vld1q_u8_x2
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u8_x2
return|return
name|vld1q_u8_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x2_t
name|test_vld1q_u16_x2
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u16_x2
return|return
name|vld1q_u16_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x2_t
name|test_vld1q_u32_x2
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u32_x2
return|return
name|vld1q_u32_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x2_t
name|test_vld1q_u64_x2
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u64_x2
return|return
name|vld1q_u64_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x2_t
name|test_vld1q_s8_x2
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s8_x2
return|return
name|vld1q_s8_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x2_t
name|test_vld1q_s16_x2
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s16_x2
return|return
name|vld1q_s16_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x2_t
name|test_vld1q_s32_x2
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s32_x2
return|return
name|vld1q_s32_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x2_t
name|test_vld1q_s64_x2
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s64_x2
return|return
name|vld1q_s64_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x2_t
name|test_vld1q_f16_x2
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f16_x2
return|return
name|vld1q_f16_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x2_t
name|test_vld1q_f32_x2
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f32_x2
return|return
name|vld1q_f32_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x2_t
name|test_vld1q_f64_x2
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f64_x2
return|return
name|vld1q_f64_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x2_t
name|test_vld1q_p8_x2
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p8_x2
return|return
name|vld1q_p8_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x2_t
name|test_vld1q_p16_x2
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p16_x2
return|return
name|vld1q_p16_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x2_t
name|test_vld1q_p64_x2
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p64_x2
return|return
name|vld1q_p64_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x2_t
name|test_vld1_u8_x2
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u8_x2
return|return
name|vld1_u8_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x2_t
name|test_vld1_u16_x2
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u16_x2
return|return
name|vld1_u16_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x2_t
name|test_vld1_u32_x2
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u32_x2
return|return
name|vld1_u32_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x2_t
name|test_vld1_u64_x2
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u64_x2
return|return
name|vld1_u64_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x2_t
name|test_vld1_s8_x2
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s8_x2
return|return
name|vld1_s8_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x2_t
name|test_vld1_s16_x2
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s16_x2
return|return
name|vld1_s16_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x2_t
name|test_vld1_s32_x2
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s32_x2
return|return
name|vld1_s32_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x2_t
name|test_vld1_s64_x2
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s64_x2
return|return
name|vld1_s64_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x2_t
name|test_vld1_f16_x2
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f16_x2
return|return
name|vld1_f16_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x2_t
name|test_vld1_f32_x2
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f32_x2
return|return
name|vld1_f32_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x2_t
name|test_vld1_f64_x2
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f64_x2
return|return
name|vld1_f64_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x2_t
name|test_vld1_p8_x2
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p8_x2
return|return
name|vld1_p8_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x2_t
name|test_vld1_p16_x2
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p16_x2
return|return
name|vld1_p16_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x2_t
name|test_vld1_p64_x2
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p64_x2
return|return
name|vld1_p64_x2
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x3_t
name|test_vld1q_u8_x3
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u8_x3
return|return
name|vld1q_u8_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x3_t
name|test_vld1q_u16_x3
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u16_x3
return|return
name|vld1q_u16_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x3_t
name|test_vld1q_u32_x3
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u32_x3
return|return
name|vld1q_u32_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x3_t
name|test_vld1q_u64_x3
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u64_x3
return|return
name|vld1q_u64_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x3_t
name|test_vld1q_s8_x3
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s8_x3
return|return
name|vld1q_s8_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x3_t
name|test_vld1q_s16_x3
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s16_x3
return|return
name|vld1q_s16_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x3_t
name|test_vld1q_s32_x3
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s32_x3
return|return
name|vld1q_s32_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x3_t
name|test_vld1q_s64_x3
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s64_x3
return|return
name|vld1q_s64_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x3_t
name|test_vld1q_f16_x3
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f16_x3
return|return
name|vld1q_f16_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x3_t
name|test_vld1q_f32_x3
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f32_x3
return|return
name|vld1q_f32_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x3_t
name|test_vld1q_f64_x3
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f64_x3
return|return
name|vld1q_f64_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x3_t
name|test_vld1q_p8_x3
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p8_x3
return|return
name|vld1q_p8_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x3_t
name|test_vld1q_p16_x3
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p16_x3
return|return
name|vld1q_p16_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x3_t
name|test_vld1q_p64_x3
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p64_x3
return|return
name|vld1q_p64_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x3_t
name|test_vld1_u8_x3
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u8_x3
return|return
name|vld1_u8_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x3_t
name|test_vld1_u16_x3
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u16_x3
return|return
name|vld1_u16_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x3_t
name|test_vld1_u32_x3
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u32_x3
return|return
name|vld1_u32_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x3_t
name|test_vld1_u64_x3
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u64_x3
return|return
name|vld1_u64_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x3_t
name|test_vld1_s8_x3
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s8_x3
return|return
name|vld1_s8_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x3_t
name|test_vld1_s16_x3
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s16_x3
return|return
name|vld1_s16_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x3_t
name|test_vld1_s32_x3
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s32_x3
return|return
name|vld1_s32_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x3_t
name|test_vld1_s64_x3
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s64_x3
return|return
name|vld1_s64_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x3_t
name|test_vld1_f16_x3
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f16_x3
return|return
name|vld1_f16_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x3_t
name|test_vld1_f32_x3
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f32_x3
return|return
name|vld1_f32_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x3_t
name|test_vld1_f64_x3
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f64_x3
return|return
name|vld1_f64_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x3_t
name|test_vld1_p8_x3
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p8_x3
return|return
name|vld1_p8_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x3_t
name|test_vld1_p16_x3
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p16_x3
return|return
name|vld1_p16_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x3_t
name|test_vld1_p64_x3
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p64_x3
return|return
name|vld1_p64_x3
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x4_t
name|test_vld1q_u8_x4
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u8_x4
return|return
name|vld1q_u8_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x4_t
name|test_vld1q_u16_x4
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u16_x4
return|return
name|vld1q_u16_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x4_t
name|test_vld1q_u32_x4
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u32_x4
return|return
name|vld1q_u32_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x4_t
name|test_vld1q_u64_x4
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_u64_x4
return|return
name|vld1q_u64_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x4_t
name|test_vld1q_s8_x4
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s8_x4
return|return
name|vld1q_s8_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x4_t
name|test_vld1q_s16_x4
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s16_x4
return|return
name|vld1q_s16_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x4_t
name|test_vld1q_s32_x4
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s32_x4
return|return
name|vld1q_s32_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x4_t
name|test_vld1q_s64_x4
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_s64_x4
return|return
name|vld1q_s64_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x4_t
name|test_vld1q_f16_x4
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f16_x4
return|return
name|vld1q_f16_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x4_t
name|test_vld1q_f32_x4
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f32_x4
return|return
name|vld1q_f32_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x4_t
name|test_vld1q_f64_x4
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_f64_x4
return|return
name|vld1q_f64_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x4_t
name|test_vld1q_p8_x4
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p8_x4
return|return
name|vld1q_p8_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x4_t
name|test_vld1q_p16_x4
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p16_x4
return|return
name|vld1q_p16_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x4_t
name|test_vld1q_p64_x4
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p64_x4
return|return
name|vld1q_p64_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x4_t
name|test_vld1_u8_x4
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u8_x4
return|return
name|vld1_u8_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x4_t
name|test_vld1_u16_x4
parameter_list|(
name|uint16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u16_x4
return|return
name|vld1_u16_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x4_t
name|test_vld1_u32_x4
parameter_list|(
name|uint32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u32_x4
return|return
name|vld1_u32_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x4_t
name|test_vld1_u64_x4
parameter_list|(
name|uint64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_u64_x4
return|return
name|vld1_u64_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x4_t
name|test_vld1_s8_x4
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s8_x4
return|return
name|vld1_s8_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x4_t
name|test_vld1_s16_x4
parameter_list|(
name|int16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s16_x4
return|return
name|vld1_s16_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x4_t
name|test_vld1_s32_x4
parameter_list|(
name|int32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s32_x4
return|return
name|vld1_s32_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x4_t
name|test_vld1_s64_x4
parameter_list|(
name|int64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_s64_x4
return|return
name|vld1_s64_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x4_t
name|test_vld1_f16_x4
parameter_list|(
name|float16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f16_x4
return|return
name|vld1_f16_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x4_t
name|test_vld1_f32_x4
parameter_list|(
name|float32_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f32_x4
return|return
name|vld1_f32_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x4_t
name|test_vld1_f64_x4
parameter_list|(
name|float64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_f64_x4
return|return
name|vld1_f64_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x4_t
name|test_vld1_p8_x4
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p8_x4
return|return
name|vld1_p8_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x4_t
name|test_vld1_p16_x4
parameter_list|(
name|poly16_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p16_x4
return|return
name|vld1_p16_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x4_t
name|test_vld1_p64_x4
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p64_x4
return|return
name|vld1_p64_x4
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u8_x2
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u8_x2
name|vst1q_u8_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u16_x2
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u16_x2
name|vst1q_u16_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u32_x2
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u32_x2
name|vst1q_u32_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u64_x2
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u64_x2
name|vst1q_u64_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s8_x2
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s8_x2
name|vst1q_s8_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s16_x2
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s16_x2
name|vst1q_s16_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s32_x2
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s32_x2
name|vst1q_s32_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s64_x2
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s64_x2
name|vst1q_s64_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f16_x2
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f16_x2
name|vst1q_f16_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f32_x2
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f32_x2
name|vst1q_f32_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f64_x2
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f64_x2
name|vst1q_f64_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p8_x2
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p8_x2
name|vst1q_p8_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p16_x2
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p16_x2
name|vst1q_p16_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p64_x2
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p64_x2
name|vst1q_p64_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u8_x2
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u8_x2
name|vst1_u8_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u16_x2
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u16_x2
name|vst1_u16_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u32_x2
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u32_x2
name|vst1_u32_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u64_x2
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u64_x2
name|vst1_u64_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s8_x2
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s8_x2
name|vst1_s8_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s16_x2
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s16_x2
name|vst1_s16_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s32_x2
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s32_x2
name|vst1_s32_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s64_x2
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s64_x2
name|vst1_s64_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f16_x2
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f16_x2
name|vst1_f16_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f32_x2
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f32_x2
name|vst1_f32_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f64_x2
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f64_x2
name|vst1_f64_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p8_x2
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p8_x2
name|vst1_p8_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p16_x2
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p16_x2
name|vst1_p16_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p64_x2
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p64_x2
name|vst1_p64_x2
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u8_x3
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u8_x3
name|vst1q_u8_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u16_x3
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u16_x3
name|vst1q_u16_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u32_x3
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u32_x3
name|vst1q_u32_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u64_x3
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u64_x3
name|vst1q_u64_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s8_x3
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s8_x3
name|vst1q_s8_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s16_x3
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s16_x3
name|vst1q_s16_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s32_x3
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s32_x3
name|vst1q_s32_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s64_x3
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s64_x3
name|vst1q_s64_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f16_x3
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f16_x3
name|vst1q_f16_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f32_x3
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f32_x3
name|vst1q_f32_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f64_x3
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f64_x3
name|vst1q_f64_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p8_x3
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p8_x3
name|vst1q_p8_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p16_x3
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p16_x3
name|vst1q_p16_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p64_x3
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p64_x3
name|vst1q_p64_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u8_x3
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u8_x3
name|vst1_u8_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u16_x3
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u16_x3
name|vst1_u16_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u32_x3
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u32_x3
name|vst1_u32_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u64_x3
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u64_x3
name|vst1_u64_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s8_x3
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s8_x3
name|vst1_s8_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s16_x3
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s16_x3
name|vst1_s16_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s32_x3
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s32_x3
name|vst1_s32_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s64_x3
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s64_x3
name|vst1_s64_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f16_x3
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f16_x3
name|vst1_f16_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f32_x3
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f32_x3
name|vst1_f32_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f64_x3
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f64_x3
name|vst1_f64_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p8_x3
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p8_x3
name|vst1_p8_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p16_x3
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p16_x3
name|vst1_p16_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p64_x3
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p64_x3
name|vst1_p64_x3
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u8_x4
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u8_x4
name|vst1q_u8_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u16_x4
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u16_x4
name|vst1q_u16_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u32_x4
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u32_x4
name|vst1q_u32_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_u64_x4
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_u64_x4
name|vst1q_u64_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s8_x4
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s8_x4
name|vst1q_s8_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s16_x4
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s16_x4
name|vst1q_s16_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s32_x4
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s32_x4
name|vst1q_s32_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_s64_x4
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_s64_x4
name|vst1q_s64_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f16_x4
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f16_x4
name|vst1q_f16_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f32_x4
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f32_x4
name|vst1q_f32_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_f64_x4
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_f64_x4
name|vst1q_f64_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p8_x4
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p8_x4
name|vst1q_p8_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p16_x4
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p16_x4
name|vst1q_p16_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p64_x4
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p64_x4
name|vst1q_p64_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u8_x4
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u8_x4
name|vst1_u8_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u16_x4
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u16_x4
name|vst1_u16_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u32_x4
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u32_x4
name|vst1_u32_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_u64_x4
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_u64_x4
name|vst1_u64_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s8_x4
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s8_x4
name|vst1_s8_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s16_x4
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s16_x4
name|vst1_s16_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s32_x4
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s32_x4
name|vst1_s32_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_s64_x4
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_s64_x4
name|vst1_s64_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f16_x4
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f16_x4
name|vst1_f16_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f32_x4
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f32_x4
name|vst1_f32_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_f64_x4
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_f64_x4
name|vst1_f64_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p8_x4
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p8_x4
name|vst1_p8_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p16_x4
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p16_x4
name|vst1_p16_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p64_x4
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p64_x4
name|vst1_p64_x4
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ ?v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d ?}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64_t
name|test_vceqd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqd_s64
comment|// CHECK: {{cmeq d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|int64_t
operator|)
name|vceqd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vceqd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqd_u64
comment|// CHECK: {{cmeq d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|int64_t
operator|)
name|vceqd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vceqzd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqzd_s64
comment|// CHECK: {{cmeq d[0-9]+, d[0-9]+, #0x0|cmp x0, #0}}
return|return
operator|(
name|int64_t
operator|)
name|vceqzd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vceqzd_u64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqzd_u64
comment|// CHECK: {{cmeq d[0-9]+, d[0-9]+, #0x0|cmp x0, #0}}
return|return
operator|(
name|int64_t
operator|)
name|vceqzd_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcged_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcged_s64
comment|// CHECK: {{cmge d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|int64_t
operator|)
name|vcged_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcged_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcged_u64
comment|// CHECK: {{cmhs d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|uint64_t
operator|)
name|vcged_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcgezd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgezd_s64
comment|// CHECK: {{cmge d[0-9]+, d[0-9]+, #0x0|eor x0, x[0-9]+, x0, asr #63}}
return|return
operator|(
name|int64_t
operator|)
name|vcgezd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcgtd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtd_s64
comment|// CHECK: {{cmgt d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|int64_t
operator|)
name|vcgtd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcgtd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtd_u64
comment|// CHECK: {{cmhi d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|uint64_t
operator|)
name|vcgtd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcgtzd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtzd_s64
comment|// CHECK: {{cmgt d[0-9]+, d[0-9]+, #0x0|cmp x0, #0}}
return|return
operator|(
name|int64_t
operator|)
name|vcgtzd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcled_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcled_s64
comment|// CHECK: {{cmge d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|int64_t
operator|)
name|vcled_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcled_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcled_u64
comment|// CHECK: {{cmhs d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|uint64_t
operator|)
name|vcled_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vclezd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclezd_s64
comment|// CHECK: {{cmle d[0-9]+, d[0-9]+, #0x0|cmp x0, #1}}
return|return
operator|(
name|int64_t
operator|)
name|vclezd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcltd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltd_s64
comment|// CHECK: {{cmgt d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|int64_t
operator|)
name|vcltd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcltd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltd_u64
comment|// CHECK: {{cmhi d[0-9]+, d[0-9]+, d[0-9]+|cmp x0, x1}}
return|return
operator|(
name|uint64_t
operator|)
name|vcltd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcltzd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltzd_s64
comment|// CHECK: {{cmlt d[0-9]+, d[0-9]+, #0x0|asr x0, x0, #63}}
return|return
operator|(
name|int64_t
operator|)
name|vcltzd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vtstd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstd_s64
comment|// CHECK: {{cmtst d[0-9]+, d[0-9]+, d[0-9]+|tst x1, x0}}
return|return
operator|(
name|int64_t
operator|)
name|vtstd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vtstd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstd_u64
comment|// CHECK: {{cmtst d[0-9]+, d[0-9]+, d[0-9]+|tst x1, x0}}
return|return
operator|(
name|uint64_t
operator|)
name|vtstd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vabsd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabsd_s64
comment|// CHECK: abs {{d[0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vabsd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqabsb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabsb_s8
comment|// CHECK: sqabs {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
return|return
operator|(
name|int8_t
operator|)
name|vqabsb_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqabsh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabsh_s16
comment|// CHECK: sqabs {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
return|return
operator|(
name|int16_t
operator|)
name|vqabsh_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqabss_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabss_s32
comment|// CHECK: sqabs {{s[0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vqabss_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vqabsd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabsd_s64
comment|// CHECK: sqabs {{d[0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vqabsd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vnegd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vnegd_s64
comment|// CHECK: neg {{[xd][0-9]+}}, {{[xd][0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vnegd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqnegb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqnegb_s8
comment|// CHECK: sqneg {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
return|return
operator|(
name|int8_t
operator|)
name|vqnegb_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqnegh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqnegh_s16
comment|// CHECK: sqneg {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
return|return
operator|(
name|int16_t
operator|)
name|vqnegh_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqnegs_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqnegs_s32
comment|// CHECK: sqneg {{s[0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vqnegs_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vqnegd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqnegd_s64
comment|// CHECK: sqneg {{d[0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vqnegd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vuqaddb_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqaddb_s8
comment|// CHECK: suqadd {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
return|return
operator|(
name|int8_t
operator|)
name|vuqaddb_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vuqaddh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqaddh_s16
comment|// CHECK: suqadd {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
return|return
operator|(
name|int16_t
operator|)
name|vuqaddh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vuqadds_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqadds_s32
comment|// CHECK: suqadd {{s[0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vuqadds_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vuqaddd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqaddd_s64
comment|// CHECK: suqadd {{d[0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vuqaddd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8_t
name|test_vsqaddb_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqaddb_u8
comment|// CHECK: usqadd {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}
return|return
operator|(
name|uint8_t
operator|)
name|vsqaddb_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16_t
name|test_vsqaddh_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqaddh_u16
comment|// CHECK: usqadd {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
return|return
operator|(
name|uint16_t
operator|)
name|vsqaddh_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vsqadds_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqadds_u32
comment|// CHECK: usqadd {{s[0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|uint32_t
operator|)
name|vsqadds_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vsqaddd_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqaddd_u64
comment|// CHECK: usqadd {{d[0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|uint64_t
operator|)
name|vsqaddd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqdmlalh_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-ARM64-LABEL: test_vqdmlalh_s16
comment|// CHECK-ARM64: sqdmull v[[PROD:[0-9]+]].4s, {{v[0-9]+.4h}}, {{v[0-9]+.4h}}
comment|// CHECK-ARM64: sqadd {{s[0-9]+}}, {{s[0-9]+}}, s[[PROD]]
return|return
operator|(
name|int32_t
operator|)
name|vqdmlalh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vqdmlals_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlals_s32
comment|// CHECK: sqdmlal {{d[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vqdmlals_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqdmlslh_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
comment|// CHECK-ARM64-LABEL: test_vqdmlslh_s16
comment|// CHECK-ARM64: sqdmull v[[PROD:[0-9]+]].4s, {{v[0-9]+.4h}}, {{v[0-9]+.4h}}
comment|// CHECK-ARM64: sqsub {{s[0-9]+}}, {{s[0-9]+}}, s[[PROD]]
return|return
operator|(
name|int32_t
operator|)
name|vqdmlslh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vqdmlsls_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmlsls_s32
comment|// CHECK: sqdmlsl {{d[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vqdmlsls_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqdmullh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmullh_s16
comment|// CHECK: sqdmull {{s[0-9]+|v[0-9]+.4s}}, {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}
return|return
operator|(
name|int32_t
operator|)
name|vqdmullh_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vqdmulls_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqdmulls_s32
comment|// CHECK: sqdmull {{d[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vqdmulls_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqmovunh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovunh_s16
comment|// CHECK: sqxtun {{b[0-9]+|v[0-9]+.8b}}, {{h[0-9]+|v[0-9]+.8h}}
return|return
operator|(
name|int8_t
operator|)
name|vqmovunh_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqmovuns_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovuns_s32
comment|// CHECK: sqxtun {{h[0-9]+|v[0-9]+.4h}}, {{s[0-9]+|v[0-9]+.4s}}
return|return
operator|(
name|int16_t
operator|)
name|vqmovuns_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqmovund_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovund_s64
comment|// CHECK: sqxtun {{s[0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vqmovund_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqmovnh_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovnh_s16
comment|// CHECK: sqxtn {{b[0-9]+|v[0-9]+.8b}}, {{h[0-9]+|v[0-9]+.8h}}
return|return
operator|(
name|int8_t
operator|)
name|vqmovnh_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqmovns_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovns_s32
comment|// CHECK: sqxtn {{h[0-9]+|v[0-9]+.4h}}, {{s[0-9]+|v[0-9]+.4s}}
return|return
operator|(
name|int16_t
operator|)
name|vqmovns_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqmovnd_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovnd_s64
comment|// CHECK: sqxtn {{s[0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vqmovnd_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqmovnh_u16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovnh_u16
comment|// CHECK: uqxtn {{b[0-9]+|v[0-9]+.8b}}, {{h[0-9]+|v[0-9]+.8h}}
return|return
operator|(
name|int8_t
operator|)
name|vqmovnh_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqmovns_u32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovns_u32
comment|// CHECK: uqxtn {{h[0-9]+|v[0-9]+.4h}}, {{s[0-9]+|v[0-9]+.4s}}
return|return
operator|(
name|int16_t
operator|)
name|vqmovns_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqmovnd_u64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqmovnd_u64
comment|// CHECK: uqxtn {{s[0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vqmovnd_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vceqs_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqs_f32
comment|// CHECK: {{fcmeq s0, s0, s1|fcmp s0, s1}}
return|return
operator|(
name|uint32_t
operator|)
name|vceqs_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vceqd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqd_f64
comment|// CHECK: {{fcmeq d0, d0, d1|fcmp d0, d1}}
return|return
operator|(
name|uint64_t
operator|)
name|vceqd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vceqzs_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqzs_f32
comment|// CHECK: {{fcmeq s0, s0, #0.0|fcmp s0, #0.0}}
return|return
operator|(
name|uint32_t
operator|)
name|vceqzs_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vceqzd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqzd_f64
comment|// CHECK: {{fcmeq d0, d0, #0.0|fcmp d0, #0.0}}
return|return
operator|(
name|uint64_t
operator|)
name|vceqzd_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcges_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcges_f32
comment|// CHECK: {{fcmge s0, s0, s1|fcmp s0, s1}}
return|return
operator|(
name|uint32_t
operator|)
name|vcges_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcged_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcged_f64
comment|// CHECK: {{fcmge d0, d0, d1|fcmp d0, d1}}
return|return
operator|(
name|uint64_t
operator|)
name|vcged_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcgezs_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgezs_f32
comment|// CHECK: {{fcmge s0, s0, #0.0|fcmp s0, #0.0}}
return|return
operator|(
name|uint32_t
operator|)
name|vcgezs_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcgezd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgezd_f64
comment|// CHECK: {{fcmge d0, d0, #0.0|fcmp d0, #0.0}}
return|return
operator|(
name|uint64_t
operator|)
name|vcgezd_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcgts_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgts_f32
comment|// CHECK: {{fcmgt s0, s0, s1|fcmp s0, s1}}
return|return
operator|(
name|uint32_t
operator|)
name|vcgts_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcgtd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtd_f64
comment|// CHECK: {{fcmgt d0, d0, d1|fcmp d0, d1}}
return|return
operator|(
name|uint64_t
operator|)
name|vcgtd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcgtzs_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtzs_f32
comment|// CHECK: {{fcmgt s0, s0, #0.0|fcmp s0, #0.0}}
return|return
operator|(
name|uint32_t
operator|)
name|vcgtzs_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcgtzd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcgtzd_f64
comment|// CHECK: {{fcmgt d0, d0, #0.0|fcmp d0, #0.0}}
return|return
operator|(
name|uint64_t
operator|)
name|vcgtzd_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcles_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcles_f32
comment|// CHECK: {{fcmge s0, s1, s0|fcmp s0, s1}}
return|return
operator|(
name|uint32_t
operator|)
name|vcles_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcled_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcled_f64
comment|// CHECK: {{fcmge d0, d1, d0|fcmp d0, d1}}
return|return
operator|(
name|uint64_t
operator|)
name|vcled_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vclezs_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclezs_f32
comment|// CHECK: {{fcmle s0, s0, #0.0|fcmp s0, #0.0}}
return|return
operator|(
name|uint32_t
operator|)
name|vclezs_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vclezd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclezd_f64
comment|// CHECK: {{fcmle d0, d0, #0.0|fcmp d0, #0.0}}
return|return
operator|(
name|uint64_t
operator|)
name|vclezd_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vclts_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vclts_f32
comment|// CHECK: {{fcmgt s0, s1, s0|fcmp s0, s1}}
return|return
operator|(
name|uint32_t
operator|)
name|vclts_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcltd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltd_f64
comment|// CHECK: {{fcmgt d0, d1, d0|fcmp d0, d1}}
return|return
operator|(
name|uint64_t
operator|)
name|vcltd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcltzs_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltzs_f32
comment|// CHECK: {{fcmlt s0, s0, #0.0|fcmp s0, #0.0}}
return|return
operator|(
name|uint32_t
operator|)
name|vcltzs_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcltzd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcltzd_f64
comment|// CHECK: {{fcmlt d0, d0, #0.0|fcmp d0, #0.0}}
return|return
operator|(
name|uint64_t
operator|)
name|vcltzd_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcages_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcages_f32
comment|// CHECK: facge s0, s0, s1
return|return
operator|(
name|uint32_t
operator|)
name|vcages_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcaged_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcaged_f64
comment|// CHECK: facge d0, d0, d1
return|return
operator|(
name|uint64_t
operator|)
name|vcaged_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcagts_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcagts_f32
comment|// CHECK: facgt s0, s0, s1
return|return
operator|(
name|uint32_t
operator|)
name|vcagts_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcagtd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcagtd_f64
comment|// CHECK: facgt d0, d0, d1
return|return
operator|(
name|uint64_t
operator|)
name|vcagtd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcales_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcales_f32
comment|// CHECK: facge s0, s1, s0
return|return
operator|(
name|uint32_t
operator|)
name|vcales_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcaled_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcaled_f64
comment|// CHECK: facge d0, d1, d0
return|return
operator|(
name|uint64_t
operator|)
name|vcaled_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcalts_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcalts_f32
comment|// CHECK: facgt s0, s1, s0
return|return
operator|(
name|uint32_t
operator|)
name|vcalts_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcaltd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcaltd_f64
comment|// CHECK: facgt d0, d1, d0
return|return
operator|(
name|uint64_t
operator|)
name|vcaltd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vshrd_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshrd_n_s64
comment|// CHECK: {{sshr d[0-9]+, d[0-9]+, #1|asr x0, x0, #1}}
return|return
operator|(
name|int64_t
operator|)
name|vshrd_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vshr_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshr_n_s64
comment|// CHECK: sshr {{d[0-9]+}}, {{d[0-9]+}}, #1
return|return
name|vshr_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vshrd_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK-ARM64-LABEL: test_vshrd_n_u64
comment|// CHECK-ARM64: mov x0, xzr
return|return
operator|(
name|uint64_t
operator|)
name|vshrd_n_u64
argument_list|(
name|a
argument_list|,
literal|64
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vshrd_n_u64_2
parameter_list|()
block|{
comment|// CHECK-ARM64-LABEL: test_vshrd_n_u64_2
comment|// CHECK-ARM64: mov x0, xzr
name|uint64_t
name|a
init|=
name|UINT64_C
argument_list|(
literal|0xf000000000000000
argument_list|)
decl_stmt|;
return|return
name|vshrd_n_u64
argument_list|(
name|a
argument_list|,
literal|64
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vshr_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshr_n_u64
comment|// CHECK: ushr {{d[0-9]+}}, {{d[0-9]+}}, #1
return|return
name|vshr_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vrshrd_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrd_n_s64
comment|// CHECK: srshr {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|int64_t
operator|)
name|vrshrd_n_s64
argument_list|(
name|a
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vrshr_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshr_n_s64
comment|// CHECK: srshr d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vrshr_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vrshrd_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshrd_n_u64
comment|// CHECK: urshr {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|uint64_t
operator|)
name|vrshrd_n_u64
argument_list|(
name|a
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vrshr_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrshr_n_u64
comment|// CHECK: urshr d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vrshr_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vsrad_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsrad_n_s64
comment|// CHECK: {{ssra d[0-9]+, d[0-9]+, #63|add x0, x0, x1, asr #63}}
return|return
operator|(
name|int64_t
operator|)
name|vsrad_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vsra_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsra_n_s64
comment|// CHECK: ssra d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vsra_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vsrad_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsrad_n_u64
comment|// CHECK: {{usra d[0-9]+, d[0-9]+, #63|add x0, x0, x1, lsr #63}}
return|return
operator|(
name|uint64_t
operator|)
name|vsrad_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vsrad_n_u64_2
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-ARM64-LABEL: test_vsrad_n_u64_2
comment|// CHECK-ARM64-NOT: add
return|return
operator|(
name|uint64_t
operator|)
name|vsrad_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|64
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vsra_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsra_n_u64
comment|// CHECK: usra d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vsra_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vrsrad_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsrad_n_s64
comment|// CHECK: {{srsra d[0-9]+, d[0-9]+, #63}}
return|return
operator|(
name|int64_t
operator|)
name|vrsrad_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vrsra_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsra_n_s64
comment|// CHECK: srsra d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vrsra_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vrsrad_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsrad_n_u64
comment|// CHECK: ursra {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|uint64_t
operator|)
name|vrsrad_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vrsra_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsra_n_u64
comment|// CHECK: ursra d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vrsra_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vshld_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshld_n_s64
comment|// CHECK: {{shl d[0-9]+, d[0-9]+, #1|lsl x0, x0, #1}}
return|return
operator|(
name|int64_t
operator|)
name|vshld_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vshl_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_n_s64
comment|// CHECK: shl d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vshl_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vshld_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshld_n_u64
comment|// CHECK: {{shl d[0-9]+, d[0-9]+, #63|lsl x0, x0, #63}}
return|return
operator|(
name|uint64_t
operator|)
name|vshld_n_u64
argument_list|(
name|a
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vshl_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vshl_n_u64
comment|// CHECK: shl d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vshl_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqshlb_n_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlb_n_s8
comment|// CHECK: sqshl {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, #7
return|return
operator|(
name|int8_t
operator|)
name|vqshlb_n_s8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqshlh_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlh_n_s16
comment|// CHECK: sqshl {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, #15
return|return
operator|(
name|int16_t
operator|)
name|vqshlh_n_s16
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqshls_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshls_n_s32
comment|// CHECK: sqshl {{s[0-9]+}}, {{s[0-9]+}}, #31
return|return
operator|(
name|int32_t
operator|)
name|vqshls_n_s32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vqshld_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshld_n_s64
comment|// CHECK: sqshl {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|int64_t
operator|)
name|vqshld_n_s64
argument_list|(
name|a
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x8_t
name|test_vqshl_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_n_s8
return|return
name|vqshl_n_s8
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #0
block|}
end_function

begin_function
name|int8x16_t
name|test_vqshlq_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_n_s8
return|return
name|vqshlq_n_s8
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #0
block|}
end_function

begin_function
name|int16x4_t
name|test_vqshl_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_n_s16
return|return
name|vqshl_n_s16
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #0
block|}
end_function

begin_function
name|int16x8_t
name|test_vqshlq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_n_s16
return|return
name|vqshlq_n_s16
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #0
block|}
end_function

begin_function
name|int32x2_t
name|test_vqshl_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_n_s32
return|return
name|vqshl_n_s32
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #0
block|}
end_function

begin_function
name|int32x4_t
name|test_vqshlq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_n_s32
return|return
name|vqshlq_n_s32
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #0
block|}
end_function

begin_function
name|int64x2_t
name|test_vqshlq_n_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_n_s64
return|return
name|vqshlq_n_s64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: sqshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #0
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqshl_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_n_u8
return|return
name|vqshl_n_u8
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, #0
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqshlq_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_n_u8
return|return
name|vqshlq_n_u8
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, #0
block|}
end_function

begin_function
name|uint16x4_t
name|test_vqshl_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_n_u16
return|return
name|vqshl_n_u16
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.4h, {{v[0-9]+}}.4h, #0
block|}
end_function

begin_function
name|uint16x8_t
name|test_vqshlq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_n_u16
return|return
name|vqshlq_n_u16
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.8h, {{v[0-9]+}}.8h, #0
block|}
end_function

begin_function
name|uint32x2_t
name|test_vqshl_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_n_u32
return|return
name|vqshl_n_u32
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, #0
block|}
end_function

begin_function
name|uint32x4_t
name|test_vqshlq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_n_u32
return|return
name|vqshlq_n_u32
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, #0
block|}
end_function

begin_function
name|uint64x2_t
name|test_vqshlq_n_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlq_n_u64
return|return
name|vqshlq_n_u64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: uqshl {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #0
block|}
end_function

begin_function
name|int64x1_t
name|test_vqshl_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_n_s64
comment|// CHECK: sqshl d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vqshl_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8_t
name|test_vqshlb_n_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlb_n_u8
comment|// CHECK: uqshl {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, #7
return|return
operator|(
name|uint8_t
operator|)
name|vqshlb_n_u8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16_t
name|test_vqshlh_n_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlh_n_u16
comment|// CHECK: uqshl {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, #15
return|return
operator|(
name|uint16_t
operator|)
name|vqshlh_n_u16
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vqshls_n_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshls_n_u32
comment|// CHECK: uqshl {{s[0-9]+}}, {{s[0-9]+}}, #31
return|return
operator|(
name|uint32_t
operator|)
name|vqshls_n_u32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vqshld_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshld_n_u64
comment|// CHECK: uqshl {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|uint64_t
operator|)
name|vqshld_n_u64
argument_list|(
name|a
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vqshl_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshl_n_u64
comment|// CHECK: uqshl d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vqshl_n_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqshlub_n_s8
parameter_list|(
name|int8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlub_n_s8
comment|// CHECK: sqshlu {{b[0-9]+|v[0-9]+.8b}}, {{b[0-9]+|v[0-9]+.8b}}, #7
return|return
operator|(
name|int8_t
operator|)
name|vqshlub_n_s8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqshluh_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshluh_n_s16
comment|// CHECK: sqshlu {{h[0-9]+|v[0-9]+.4h}}, {{h[0-9]+|v[0-9]+.4h}}, #15
return|return
operator|(
name|int16_t
operator|)
name|vqshluh_n_s16
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqshlus_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlus_n_s32
comment|// CHECK: sqshlu {{s[0-9]+}}, {{s[0-9]+}}, #31
return|return
operator|(
name|int32_t
operator|)
name|vqshlus_n_s32
argument_list|(
name|a
argument_list|,
literal|31
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vqshlud_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlud_n_s64
comment|// CHECK: sqshlu {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|int64_t
operator|)
name|vqshlud_n_s64
argument_list|(
name|a
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vqshlu_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshlu_n_s64
comment|// CHECK: sqshlu d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vqshlu_n_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vsrid_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsrid_n_s64
comment|// CHECK: sri {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|int64_t
operator|)
name|vsrid_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vsri_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_s64
comment|// CHECK: sri d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vsri_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vsrid_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsrid_n_u64
comment|// CHECK: sri {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|uint64_t
operator|)
name|vsrid_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vsri_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_u64
comment|// CHECK: sri d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vsri_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vslid_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vslid_n_s64
comment|// CHECK: sli {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|int64_t
operator|)
name|vslid_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vsli_n_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_s64
comment|// CHECK: sli d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vsli_n_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vslid_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vslid_n_u64
comment|// CHECK: sli {{d[0-9]+}}, {{d[0-9]+}}, #63
return|return
operator|(
name|uint64_t
operator|)
name|vslid_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|63
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vsli_n_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsli_n_u64
comment|// CHECK: sli d{{[0-9]+}}, d{{[0-9]+}}, #1
return|return
name|vsli_n_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqshrnh_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrnh_n_s16
comment|// CHECK: sqshrn {{b[0-9]+|v[0-9]+.8b}}, {{h[0-9]+|v[0-9]+.8h}}, #8
return|return
operator|(
name|int8_t
operator|)
name|vqshrnh_n_s16
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqshrns_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrns_n_s32
comment|// CHECK: sqshrn {{h[0-9]+|v[0-9]+.4h}}, {{s[0-9]+|v[0-9]+.4s}}, #16
return|return
operator|(
name|int16_t
operator|)
name|vqshrns_n_s32
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqshrnd_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrnd_n_s64
comment|// CHECK: sqshrn {{s[0-9]+}}, {{d[0-9]+}}, #32
return|return
operator|(
name|int32_t
operator|)
name|vqshrnd_n_s64
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8_t
name|test_vqshrnh_n_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrnh_n_u16
comment|// CHECK: uqshrn {{b[0-9]+|v[0-9]+.8b}}, {{h[0-9]+|v[0-9]+.8h}}, #8
return|return
operator|(
name|uint8_t
operator|)
name|vqshrnh_n_u16
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16_t
name|test_vqshrns_n_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrns_n_u32
comment|// CHECK: uqshrn {{h[0-9]+|v[0-9]+.4h}}, {{s[0-9]+|v[0-9]+.4s}}, #16
return|return
operator|(
name|uint16_t
operator|)
name|vqshrns_n_u32
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vqshrnd_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrnd_n_u64
comment|// CHECK: uqshrn {{s[0-9]+}}, {{d[0-9]+}}, #32
return|return
operator|(
name|uint32_t
operator|)
name|vqshrnd_n_u64
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqrshrnh_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrnh_n_s16
comment|// CHECK: sqrshrn {{b[0-9]+|v[0-9]+.8b}}, {{h[0-9]+|v[0-9]+.8h}}, #8
return|return
operator|(
name|int8_t
operator|)
name|vqrshrnh_n_s16
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqrshrns_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrns_n_s32
comment|// CHECK: sqrshrn {{h[0-9]+|v[0-9]+.4h}}, {{s[0-9]+|v[0-9]+.4s}}, #16
return|return
operator|(
name|int16_t
operator|)
name|vqrshrns_n_s32
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqrshrnd_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrnd_n_s64
comment|// CHECK: sqrshrn {{s[0-9]+}}, {{d[0-9]+}}, #32
return|return
operator|(
name|int32_t
operator|)
name|vqrshrnd_n_s64
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8_t
name|test_vqrshrnh_n_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrnh_n_u16
comment|// CHECK: uqrshrn {{b[0-9]+|v[0-9]+.8b}}, {{h[0-9]+|v[0-9]+.8h}}, #8
return|return
operator|(
name|uint8_t
operator|)
name|vqrshrnh_n_u16
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16_t
name|test_vqrshrns_n_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrns_n_u32
comment|// CHECK: uqrshrn {{h[0-9]+|v[0-9]+.4h}}, {{s[0-9]+|v[0-9]+.4s}}, #16
return|return
operator|(
name|uint16_t
operator|)
name|vqrshrns_n_u32
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vqrshrnd_n_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrnd_n_u64
comment|// CHECK: uqrshrn {{s[0-9]+}}, {{d[0-9]+}}, #32
return|return
operator|(
name|uint32_t
operator|)
name|vqrshrnd_n_u64
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqshrunh_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrunh_n_s16
comment|// CHECK: sqshrun {{b[0-9]+|v[0-9]+.8b}}, {{h[0-9]+|v[0-9]+.8h}}, #8
return|return
operator|(
name|int8_t
operator|)
name|vqshrunh_n_s16
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqshruns_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshruns_n_s32
comment|// CHECK: sqshrun {{h[0-9]+|v[0-9]+.4h}}, {{s[0-9]+|v[0-9]+.4s}}, #16
return|return
operator|(
name|int16_t
operator|)
name|vqshruns_n_s32
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqshrund_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqshrund_n_s64
comment|// CHECK: sqshrun {{s[0-9]+}}, {{d[0-9]+}}, #32
return|return
operator|(
name|int32_t
operator|)
name|vqshrund_n_s64
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vqrshrunh_n_s16
parameter_list|(
name|int16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrunh_n_s16
comment|// CHECK: sqrshrun {{b[0-9]+|v[0-9]+.8b}}, {{h[0-9]+|v[0-9]+.8h}}, #8
return|return
operator|(
name|int8_t
operator|)
name|vqrshrunh_n_s16
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vqrshruns_n_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshruns_n_s32
comment|// CHECK: sqrshrun {{h[0-9]+|v[0-9]+.4h}}, {{s[0-9]+|v[0-9]+.4s}}, #16
return|return
operator|(
name|int16_t
operator|)
name|vqrshruns_n_s32
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vqrshrund_n_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqrshrund_n_s64
comment|// CHECK: sqrshrun {{s[0-9]+}}, {{d[0-9]+}}, #32
return|return
operator|(
name|int32_t
operator|)
name|vqrshrund_n_s64
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vcvts_n_f32_s32
parameter_list|(
name|int32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvts_n_f32_s32
comment|// CHECK: scvtf {{s[0-9]+}}, {{s[0-9]+}}, #1
return|return
name|vcvts_n_f32_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|float64_t
name|test_vcvtd_n_f64_s64
parameter_list|(
name|int64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtd_n_f64_s64
comment|// CHECK: scvtf {{d[0-9]+}}, {{d[0-9]+}}, #1
return|return
name|vcvtd_n_f64_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vcvts_n_f32_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvts_n_f32_u32
comment|// CHECK: ucvtf {{s[0-9]+}}, {{s[0-9]+}}, #32
return|return
name|vcvts_n_f32_u32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|float64_t
name|test_vcvtd_n_f64_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtd_n_f64_u64
comment|// CHECK: ucvtf {{d[0-9]+}}, {{d[0-9]+}}, #64
return|return
name|vcvtd_n_f64_u64
argument_list|(
name|a
argument_list|,
literal|64
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vcvts_n_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvts_n_s32_f32
comment|// CHECK: fcvtzs {{s[0-9]+}}, {{s[0-9]+}}, #1
return|return
operator|(
name|int32_t
operator|)
name|vcvts_n_s32_f32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcvtd_n_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtd_n_s64_f64
comment|// CHECK: fcvtzs {{d[0-9]+}}, {{d[0-9]+}}, #1
return|return
operator|(
name|int64_t
operator|)
name|vcvtd_n_s64_f64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcvts_n_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvts_n_u32_f32
comment|// CHECK: fcvtzu {{s[0-9]+}}, {{s[0-9]+}}, #32
return|return
operator|(
name|uint32_t
operator|)
name|vcvts_n_u32_f32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcvtd_n_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtd_n_u64_f64
comment|// CHECK: fcvtzu {{d[0-9]+}}, {{d[0-9]+}}, #64
return|return
operator|(
name|uint64_t
operator|)
name|vcvtd_n_u64_f64
argument_list|(
name|a
argument_list|,
literal|64
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s8_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x8_t
name|test_vreinterpret_s8_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s8_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s16_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x4_t
name|test_vreinterpret_s16_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s16_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s32_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x2_t
name|test_vreinterpret_s32_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s32_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_s64_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x1_t
name|test_vreinterpret_s64_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_s64_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u8_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x8_t
name|test_vreinterpret_u8_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u8_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u16_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x4_t
name|test_vreinterpret_u16_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u16_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u32_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x2_t
name|test_vreinterpret_u32_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u32_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_u64_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x1_t
name|test_vreinterpret_u64_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_u64_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f16_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x4_t
name|test_vreinterpret_f16_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f16_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f32_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x2_t
name|test_vreinterpret_f32_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f32_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_f64_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x1_t
name|test_vreinterpret_f64_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_f64_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p8_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x8_t
name|test_vreinterpret_p8_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p8_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p16_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x4_t
name|test_vreinterpret_p16_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p16_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpret_p64_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x1_t
name|test_vreinterpret_p64_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpret_p64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f16_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float16x8_t
name|test_vreinterpretq_f16_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f16_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_p64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_s8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_s16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_s32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_s64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_u8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_u16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_u32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_u64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_f16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_f32:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_f64:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_p8:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_p16:
end_comment

begin_comment
comment|// CHECK-NEXT: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vabds_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabds_f32
comment|// CHECK: fabd {{s[0-9]+}}, {{s[0-9]+}}, {{s[0-9]+}}
return|return
name|vabds_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|float64_t
name|test_vabdd_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabdd_f64
comment|// CHECK: fabd {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
return|return
name|vabdd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vuqadd_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuqadd_s64
return|return
name|vuqadd_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: suqadd d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vsqadd_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqadd_u64
return|return
name|vsqadd_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usqadd d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|uint8x8_t
name|test_vsqadd_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqadd_u8
return|return
name|vsqadd_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usqadd {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint8x16_t
name|test_vsqaddq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqaddq_u8
return|return
name|vsqaddq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usqadd {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16x4_t
name|test_vsqadd_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqadd_u16
return|return
name|vsqadd_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usqadd {{v[0-9]+}}.4h, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsqaddq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqaddq_u16
return|return
name|vsqaddq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usqadd {{v[0-9]+}}.8h, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32x2_t
name|test_vsqadd_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqadd_u32
return|return
name|vsqadd_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usqadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsqaddq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqaddq_u32
return|return
name|vsqaddq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usqadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint64x2_t
name|test_vsqaddq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqaddq_u64
return|return
name|vsqaddq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: usqadd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int64x1_t
name|test_vabs_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabs_s64
return|return
name|vabs_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: abs d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vqabs_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqabs_s64
return|return
name|vqabs_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqabs d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vqneg_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vqneg_s64
return|return
name|vqneg_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sqneg d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vneg_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vneg_s64
return|return
name|vneg_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: neg d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float32_t
name|test_vaddv_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddv_f32
return|return
name|vaddv_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: faddp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float32_t
name|test_vaddvq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_f32
return|return
name|vaddvq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: faddp {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK: faddp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float64_t
name|test_vaddvq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_f64
return|return
name|vaddvq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: faddp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32_t
name|test_vmaxv_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxv_f32
return|return
name|vmaxv_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float64_t
name|test_vmaxvq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxvq_f64
return|return
name|vmaxvq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32_t
name|test_vminv_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminv_f32
return|return
name|vminv_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float64_t
name|test_vminvq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminvq_f64
return|return
name|vminvq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float64_t
name|test_vmaxnmvq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxnmvq_f64
return|return
name|vmaxnmvq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxnmp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32_t
name|test_vmaxnmv_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxnmv_f32
return|return
name|vmaxnmv_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxnmp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|float64_t
name|test_vminnmvq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminnmvq_f64
return|return
name|vminnmvq_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminnmp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float32_t
name|test_vminnmv_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminnmv_f32
return|return
name|vminnmv_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminnmp {{s[0-9]+}}, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64x2_t
name|test_vpaddq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_s64
return|return
name|vpaddq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64x2_t
name|test_vpaddq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddq_u64
return|return
name|vpaddq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64_t
name|test_vpaddd_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vpaddd_u64
return|return
name|vpaddd_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|int64_t
name|test_vaddvq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_s64
return|return
name|vaddvq_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64_t
name|test_vaddvq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_u64
return|return
name|vaddvq_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addp {{d[0-9]+}}, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|float64x1_t
name|test_vadd_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vadd_f64
return|return
name|vadd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fadd d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vmul_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmul_f64
return|return
name|vmul_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmul d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vdiv_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdiv_f64
return|return
name|vdiv_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fdiv d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vmla_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x1_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmla_f64
return|return
name|vmla_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: fmadd d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vmls_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x1_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmls_f64
return|return
name|vmls_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: fmsub d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vfma_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x1_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfma_f64
return|return
name|vfma_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: fmadd d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vfms_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x1_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vfms_f64
return|return
name|vfms_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: fmsub d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vsub_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsub_f64
return|return
name|vsub_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fsub d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vabd_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabd_f64
return|return
name|vabd_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fabd d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vmax_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmax_f64
return|return
name|vmax_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmax d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vmin_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmin_f64
return|return
name|vmin_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmin d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vmaxnm_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxnm_f64
return|return
name|vmaxnm_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fmaxnm d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vminnm_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminnm_f64
return|return
name|vminnm_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: fminnm d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vabs_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vabs_f64
return|return
name|vabs_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fabs d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vneg_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vneg_f64
return|return
name|vneg_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fneg d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vcvt_s64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_s64_f64
return|return
name|vcvt_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtzs {{[xd][0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcvt_u64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_u64_f64
return|return
name|vcvt_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtzu {{[xd][0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vcvtn_s64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtn_s64_f64
return|return
name|vcvtn_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtns d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcvtn_u64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtn_u64_f64
return|return
name|vcvtn_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtnu d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vcvtp_s64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtp_s64_f64
return|return
name|vcvtp_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtps d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcvtp_u64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtp_u64_f64
return|return
name|vcvtp_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtpu d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vcvtm_s64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtm_s64_f64
return|return
name|vcvtm_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtms d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcvtm_u64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtm_u64_f64
return|return
name|vcvtm_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtmu d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vcvta_s64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvta_s64_f64
return|return
name|vcvta_s64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtas d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcvta_u64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvta_u64_f64
return|return
name|vcvta_u64_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fcvtau d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vcvt_f64_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_f64_s64
return|return
name|vcvt_f64_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: scvtf d{{[0-9]+}}, {{[xd][0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vcvt_f64_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_f64_u64
return|return
name|vcvt_f64_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ucvtf d{{[0-9]+}}, {{[xd][0-9]+}}
block|}
end_function

begin_function
name|int64x1_t
name|test_vcvt_n_s64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_n_s64_f64
return|return
name|vcvt_n_s64_f64
argument_list|(
name|a
argument_list|,
literal|64
argument_list|)
return|;
comment|// CHECK: fcvtzs d{{[0-9]+}}, d{{[0-9]+}}, #64
block|}
end_function

begin_function
name|uint64x1_t
name|test_vcvt_n_u64_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_n_u64_f64
return|return
name|vcvt_n_u64_f64
argument_list|(
name|a
argument_list|,
literal|64
argument_list|)
return|;
comment|// CHECK: fcvtzu d{{[0-9]+}}, d{{[0-9]+}}, #64
block|}
end_function

begin_function
name|float64x1_t
name|test_vcvt_n_f64_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_n_f64_s64
return|return
name|vcvt_n_f64_s64
argument_list|(
name|a
argument_list|,
literal|64
argument_list|)
return|;
comment|// CHECK: scvtf d{{[0-9]+}}, d{{[0-9]+}}, #64
block|}
end_function

begin_function
name|float64x1_t
name|test_vcvt_n_f64_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvt_n_f64_u64
return|return
name|vcvt_n_f64_u64
argument_list|(
name|a
argument_list|,
literal|64
argument_list|)
return|;
comment|// CHECK: ucvtf d{{[0-9]+}}, d{{[0-9]+}}, #64
block|}
end_function

begin_function
name|float64x1_t
name|test_vrndn_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndn_f64
return|return
name|vrndn_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintn d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrnda_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrnda_f64
return|return
name|vrnda_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frinta d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrndp_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndp_f64
return|return
name|vrndp_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintp d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrndm_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndm_f64
return|return
name|vrndm_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintm d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrndx_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndx_f64
return|return
name|vrndx_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintx d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrnd_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrnd_f64
return|return
name|vrnd_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frintz d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrndi_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndi_f64
return|return
name|vrndi_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frinti d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrsqrte_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsqrte_f64
return|return
name|vrsqrte_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frsqrte d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrecpe_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecpe_f64
return|return
name|vrecpe_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: frecpe d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vsqrt_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsqrt_f64
return|return
name|vsqrt_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fsqrt d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrecps_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrecps_f64
return|return
name|vrecps_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: frecps d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|float64x1_t
name|test_vrsqrts_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrsqrts_f64
return|return
name|vrsqrts_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: frsqrts d{{[0-9]+}}, d{{[0-9]+}}, d{{[0-9]+}}
block|}
end_function

begin_function
name|int32_t
name|test_vminv_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminv_s32
return|return
name|vminv_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sminp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32_t
name|test_vminv_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminv_u32
return|return
name|vminv_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uminp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32_t
name|test_vmaxv_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxv_s32
return|return
name|vmaxv_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: smaxp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32_t
name|test_vmaxv_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxv_u32
return|return
name|vmaxv_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: umaxp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int32_t
name|test_vaddv_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddv_s32
return|return
name|vaddv_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint32_t
name|test_vaddv_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddv_u32
return|return
name|vaddv_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addp {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|int64_t
name|test_vaddlv_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlv_s32
return|return
name|vaddlv_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlp {{v[0-9]+}}.1d, {{v[0-9]+}}.2s
block|}
end_function

begin_function
name|uint64_t
name|test_vaddlv_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlv_u32
return|return
name|vaddlv_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlp {{v[0-9]+}}.1d, {{v[0-9]+}}.2s
block|}
end_function

end_unit

