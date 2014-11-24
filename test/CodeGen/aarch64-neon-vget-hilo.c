begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -ffp-contract=fast -S -O3 -o - %s | FileCheck %s --check-prefix CHECK-COMMON --check-prefix CHECK-ARM64
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
name|test_vget_high_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_s8:
return|return
name|vget_high_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|int16x4_t
name|test_vget_high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_s16:
return|return
name|vget_high_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|int32x2_t
name|test_vget_high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_s32:
return|return
name|vget_high_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|int64x1_t
name|test_vget_high_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_s64:
return|return
name|vget_high_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|uint8x8_t
name|test_vget_high_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_u8:
return|return
name|vget_high_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|uint16x4_t
name|test_vget_high_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_u16:
return|return
name|vget_high_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|uint32x2_t
name|test_vget_high_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_u32:
return|return
name|vget_high_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|uint64x1_t
name|test_vget_high_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_u64:
return|return
name|vget_high_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|poly64x1_t
name|test_vget_high_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_p64:
return|return
name|vget_high_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|float16x4_t
name|test_vget_high_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_f16:
return|return
name|vget_high_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|float32x2_t
name|test_vget_high_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_f32:
return|return
name|vget_high_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|poly8x8_t
name|test_vget_high_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_p8:
return|return
name|vget_high_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|poly16x4_t
name|test_vget_high_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_p16
return|return
name|vget_high_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|float64x1_t
name|test_vget_high_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_high_f64
return|return
name|vget_high_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-ARM64: ext v0.16b, v0.16b, v0.16b, #8
block|}
end_function

begin_function
name|int8x8_t
name|test_vget_low_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_s8:
return|return
name|vget_low_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|int16x4_t
name|test_vget_low_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_s16:
return|return
name|vget_low_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|int32x2_t
name|test_vget_low_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_s32:
return|return
name|vget_low_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|int64x1_t
name|test_vget_low_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_s64:
return|return
name|vget_low_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|uint8x8_t
name|test_vget_low_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_u8:
return|return
name|vget_low_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|uint16x4_t
name|test_vget_low_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_u16:
return|return
name|vget_low_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|uint32x2_t
name|test_vget_low_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_u32:
return|return
name|vget_low_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|uint64x1_t
name|test_vget_low_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_u64:
return|return
name|vget_low_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|poly64x1_t
name|test_vget_low_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_p64:
return|return
name|vget_low_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|float16x4_t
name|test_vget_low_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_f16:
return|return
name|vget_low_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|float32x2_t
name|test_vget_low_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_f32:
return|return
name|vget_low_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|poly8x8_t
name|test_vget_low_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_p8:
return|return
name|vget_low_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|poly16x4_t
name|test_vget_low_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_p16:
return|return
name|vget_low_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

begin_function
name|float64x1_t
name|test_vget_low_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-COMMON-LABEL: test_vget_low_f64:
return|return
name|vget_low_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK-COMMON-NEXT: ret
block|}
end_function

end_unit

