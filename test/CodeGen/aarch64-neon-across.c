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
name|int16_t
name|test_vaddlv_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlv_s8
return|return
name|vaddlv_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlv {{h[0-9]+}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int32_t
name|test_vaddlv_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlv_s16
return|return
name|vaddlv_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlv {{s[0-9]+}}, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint16_t
name|test_vaddlv_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlv_u8
return|return
name|vaddlv_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlv {{h[0-9]+}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint32_t
name|test_vaddlv_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlv_u16
return|return
name|vaddlv_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlv {{s[0-9]+}}, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int16_t
name|test_vaddlvq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlvq_s8
return|return
name|vaddlvq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlv {{h[0-9]+}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int32_t
name|test_vaddlvq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlvq_s16
return|return
name|vaddlvq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlv {{s[0-9]+}}, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int64_t
name|test_vaddlvq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlvq_s32
return|return
name|vaddlvq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: saddlv {{d[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint16_t
name|test_vaddlvq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlvq_u8
return|return
name|vaddlvq_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlv {{h[0-9]+}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint32_t
name|test_vaddlvq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlvq_u16
return|return
name|vaddlvq_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlv {{s[0-9]+}}, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint64_t
name|test_vaddlvq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddlvq_u32
return|return
name|vaddlvq_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uaddlv {{d[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int8_t
name|test_vmaxv_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxv_s8
return|return
name|vmaxv_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: smaxv {{b[0-9]+}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16_t
name|test_vmaxv_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxv_s16
return|return
name|vmaxv_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: smaxv {{h[0-9]+}}, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint8_t
name|test_vmaxv_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxv_u8
return|return
name|vmaxv_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: umaxv {{b[0-9]+}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16_t
name|test_vmaxv_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxv_u16
return|return
name|vmaxv_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: umaxv {{h[0-9]+}}, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int8_t
name|test_vmaxvq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxvq_s8
return|return
name|vmaxvq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: smaxv {{b[0-9]+}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16_t
name|test_vmaxvq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxvq_s16
return|return
name|vmaxvq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: smaxv {{h[0-9]+}}, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32_t
name|test_vmaxvq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxvq_s32
return|return
name|vmaxvq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: smaxv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8_t
name|test_vmaxvq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxvq_u8
return|return
name|vmaxvq_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: umaxv {{b[0-9]+}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16_t
name|test_vmaxvq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxvq_u16
return|return
name|vmaxvq_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: umaxv {{h[0-9]+}}, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32_t
name|test_vmaxvq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxvq_u32
return|return
name|vmaxvq_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: umaxv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int8_t
name|test_vminv_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminv_s8
return|return
name|vminv_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sminv {{b[0-9]+}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16_t
name|test_vminv_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminv_s16
return|return
name|vminv_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sminv {{h[0-9]+}}, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint8_t
name|test_vminv_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminv_u8
return|return
name|vminv_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uminv {{b[0-9]+}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16_t
name|test_vminv_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminv_u16
return|return
name|vminv_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uminv {{h[0-9]+}}, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int8_t
name|test_vminvq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminvq_s8
return|return
name|vminvq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sminv {{b[0-9]+}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16_t
name|test_vminvq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminvq_s16
return|return
name|vminvq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sminv {{h[0-9]+}}, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32_t
name|test_vminvq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminvq_s32
return|return
name|vminvq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: sminv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8_t
name|test_vminvq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminvq_u8
return|return
name|vminvq_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uminv {{b[0-9]+}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16_t
name|test_vminvq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminvq_u16
return|return
name|vminvq_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uminv {{h[0-9]+}}, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32_t
name|test_vminvq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminvq_u32
return|return
name|vminvq_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: uminv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|int8_t
name|test_vaddv_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddv_s8
return|return
name|vaddv_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{b[0-9]+}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|int16_t
name|test_vaddv_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddv_s16
return|return
name|vaddv_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{h[0-9]+}}, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|uint8_t
name|test_vaddv_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddv_u8
return|return
name|vaddv_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{b[0-9]+}}, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|uint16_t
name|test_vaddv_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddv_u16
return|return
name|vaddv_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{h[0-9]+}}, {{v[0-9]+}}.4h
block|}
end_function

begin_function
name|int8_t
name|test_vaddvq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_s8
return|return
name|vaddvq_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{b[0-9]+}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|int16_t
name|test_vaddvq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_s16
return|return
name|vaddvq_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{h[0-9]+}}, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|int32_t
name|test_vaddvq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_s32
return|return
name|vaddvq_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|uint8_t
name|test_vaddvq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_u8
return|return
name|vaddvq_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{b[0-9]+}}, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|uint16_t
name|test_vaddvq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_u16
return|return
name|vaddvq_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{h[0-9]+}}, {{v[0-9]+}}.8h
block|}
end_function

begin_function
name|uint32_t
name|test_vaddvq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vaddvq_u32
return|return
name|vaddvq_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: addv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32_t
name|test_vmaxvq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxvq_f32
return|return
name|vmaxvq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32_t
name|test_vminvq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminvq_f32
return|return
name|vminvq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32_t
name|test_vmaxnmvq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxnmvq_f32
return|return
name|vmaxnmvq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmaxnmv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

begin_function
name|float32_t
name|test_vminnmvq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminnmvq_f32
return|return
name|vminnmvq_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fminnmv {{s[0-9]+}}, {{v[0-9]+}}.4s
block|}
end_function

end_unit

