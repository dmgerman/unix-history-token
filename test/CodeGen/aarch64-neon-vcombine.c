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
name|int8x16_t
name|test_vcombine_s8
parameter_list|(
name|int8x8_t
name|low
parameter_list|,
name|int8x8_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_s8:
return|return
name|vcombine_s8
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|int16x8_t
name|test_vcombine_s16
parameter_list|(
name|int16x4_t
name|low
parameter_list|,
name|int16x4_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_s16:
return|return
name|vcombine_s16
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|int32x4_t
name|test_vcombine_s32
parameter_list|(
name|int32x2_t
name|low
parameter_list|,
name|int32x2_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_s32:
return|return
name|vcombine_s32
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|int64x2_t
name|test_vcombine_s64
parameter_list|(
name|int64x1_t
name|low
parameter_list|,
name|int64x1_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_s64:
return|return
name|vcombine_s64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|uint8x16_t
name|test_vcombine_u8
parameter_list|(
name|uint8x8_t
name|low
parameter_list|,
name|uint8x8_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_u8:
return|return
name|vcombine_u8
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vcombine_u16
parameter_list|(
name|uint16x4_t
name|low
parameter_list|,
name|uint16x4_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_u16:
return|return
name|vcombine_u16
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcombine_u32
parameter_list|(
name|uint32x2_t
name|low
parameter_list|,
name|uint32x2_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_u32:
return|return
name|vcombine_u32
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vcombine_u64
parameter_list|(
name|uint64x1_t
name|low
parameter_list|,
name|uint64x1_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_u64:
return|return
name|vcombine_u64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|poly64x2_t
name|test_vcombine_p64
parameter_list|(
name|poly64x1_t
name|low
parameter_list|,
name|poly64x1_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_p64:
return|return
name|vcombine_p64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|float16x8_t
name|test_vcombine_f16
parameter_list|(
name|float16x4_t
name|low
parameter_list|,
name|float16x4_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_f16:
return|return
name|vcombine_f16
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|float32x4_t
name|test_vcombine_f32
parameter_list|(
name|float32x2_t
name|low
parameter_list|,
name|float32x2_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_f32:
return|return
name|vcombine_f32
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|poly8x16_t
name|test_vcombine_p8
parameter_list|(
name|poly8x8_t
name|low
parameter_list|,
name|poly8x8_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_p8:
return|return
name|vcombine_p8
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|poly16x8_t
name|test_vcombine_p16
parameter_list|(
name|poly16x4_t
name|low
parameter_list|,
name|poly16x4_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_p16:
return|return
name|vcombine_p16
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

begin_function
name|float64x2_t
name|test_vcombine_f64
parameter_list|(
name|float64x1_t
name|low
parameter_list|,
name|float64x1_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_f64:
return|return
name|vcombine_f64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins	v0.d[1], v1.d[0]
block|}
end_function

end_unit

