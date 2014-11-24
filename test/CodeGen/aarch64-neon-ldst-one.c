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

begin_function
name|uint8x16_t
name|test_vld1q_dup_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_u8
return|return
name|vld1q_dup_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.16b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vld1q_dup_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_u16
return|return
name|vld1q_dup_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vld1q_dup_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_u32
return|return
name|vld1q_dup_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.4s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vld1q_dup_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_u64
return|return
name|vld1q_dup_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16_t
name|test_vld1q_dup_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_s8
return|return
name|vld1q_dup_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.16b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8_t
name|test_vld1q_dup_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_s16
return|return
name|vld1q_dup_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4_t
name|test_vld1q_dup_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_s32
return|return
name|vld1q_dup_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.4s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2_t
name|test_vld1q_dup_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_s64
return|return
name|vld1q_dup_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8_t
name|test_vld1q_dup_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_f16
return|return
name|vld1q_dup_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4_t
name|test_vld1q_dup_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_f32
return|return
name|vld1q_dup_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.4s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2_t
name|test_vld1q_dup_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_f64
return|return
name|vld1q_dup_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16_t
name|test_vld1q_dup_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_p8
return|return
name|vld1q_dup_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.16b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8_t
name|test_vld1q_dup_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_p16
return|return
name|vld1q_dup_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2_t
name|test_vld1q_dup_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_dup_p64
return|return
name|vld1q_dup_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8_t
name|test_vld1_dup_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_u8
return|return
name|vld1_dup_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.8b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vld1_dup_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_u16
return|return
name|vld1_dup_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vld1_dup_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_u32
return|return
name|vld1_dup_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.2s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1_t
name|test_vld1_dup_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_u64
return|return
name|vld1_dup_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1r { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8_t
name|test_vld1_dup_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_s8
return|return
name|vld1_dup_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.8b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4_t
name|test_vld1_dup_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_s16
return|return
name|vld1_dup_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2_t
name|test_vld1_dup_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_s32
return|return
name|vld1_dup_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.2s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1_t
name|test_vld1_dup_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_s64
return|return
name|vld1_dup_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1r { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4_t
name|test_vld1_dup_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_f16
return|return
name|vld1_dup_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2_t
name|test_vld1_dup_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_f32
return|return
name|vld1_dup_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.2s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1_t
name|test_vld1_dup_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_f64
return|return
name|vld1_dup_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1r { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8_t
name|test_vld1_dup_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_p8
return|return
name|vld1_dup_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.8b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4_t
name|test_vld1_dup_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_p16
return|return
name|vld1_dup_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld1r {{{ *v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1_t
name|test_vld1_dup_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_dup_p64
return|return
name|vld1_dup_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1r { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x2_t
name|test_vld2q_dup_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_u8
return|return
name|vld2q_dup_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.16b, v[0-9]+.16b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x2_t
name|test_vld2q_dup_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_u16
return|return
name|vld2q_dup_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.8h, v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x2_t
name|test_vld2q_dup_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_u32
return|return
name|vld2q_dup_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.4s, v[0-9]+.4s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x2_t
name|test_vld2q_dup_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_u64
return|return
name|vld2q_dup_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x2_t
name|test_vld2q_dup_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_s8
return|return
name|vld2q_dup_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.16b, v[0-9]+.16b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x2_t
name|test_vld2q_dup_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_s16
return|return
name|vld2q_dup_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.8h, v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x2_t
name|test_vld2q_dup_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_s32
return|return
name|vld2q_dup_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.4s, v[0-9]+.4s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x2_t
name|test_vld2q_dup_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_s64
return|return
name|vld2q_dup_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x2_t
name|test_vld2q_dup_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_f16
return|return
name|vld2q_dup_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.8h, v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x2_t
name|test_vld2q_dup_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_f32
return|return
name|vld2q_dup_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.4s, v[0-9]+.4s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x2_t
name|test_vld2q_dup_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_f64
return|return
name|vld2q_dup_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x2_t
name|test_vld2q_dup_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_p8
return|return
name|vld2q_dup_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.16b, v[0-9]+.16b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x2_t
name|test_vld2q_dup_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_p16
return|return
name|vld2q_dup_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.8h, v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x2_t
name|test_vld2q_dup_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_dup_p64
return|return
name|vld2q_dup_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x2_t
name|test_vld2_dup_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_u8
return|return
name|vld2_dup_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.8b, v[0-9]+.8b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x2_t
name|test_vld2_dup_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_u16
return|return
name|vld2_dup_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.4h, v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x2_t
name|test_vld2_dup_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_u32
return|return
name|vld2_dup_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.2s, v[0-9]+.2s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x2_t
name|test_vld2_dup_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_u64
return|return
name|vld2_dup_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld2r}} {{{ *v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x2_t
name|test_vld2_dup_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_s8
return|return
name|vld2_dup_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.8b, v[0-9]+.8b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x2_t
name|test_vld2_dup_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_s16
return|return
name|vld2_dup_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.4h, v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x2_t
name|test_vld2_dup_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_s32
return|return
name|vld2_dup_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.2s, v[0-9]+.2s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x2_t
name|test_vld2_dup_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_s64
return|return
name|vld2_dup_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld2r}} {{{ *v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x2_t
name|test_vld2_dup_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_f16
return|return
name|vld2_dup_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.4h, v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x2_t
name|test_vld2_dup_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_f32
return|return
name|vld2_dup_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.2s, v[0-9]+.2s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x2_t
name|test_vld2_dup_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_f64
return|return
name|vld2_dup_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld2r}} {{{ *v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x2_t
name|test_vld2_dup_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_p8
return|return
name|vld2_dup_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.8b, v[0-9]+.8b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x2_t
name|test_vld2_dup_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_p16
return|return
name|vld2_dup_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld2r {{{ *v[0-9]+.4h, v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x2_t
name|test_vld2_dup_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_dup_p64
return|return
name|vld2_dup_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld2r}} {{{ *v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x3_t
name|test_vld3q_dup_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_u8
return|return
name|vld3q_dup_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x3_t
name|test_vld3q_dup_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_u16
return|return
name|vld3q_dup_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x3_t
name|test_vld3q_dup_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_u32
return|return
name|vld3q_dup_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x3_t
name|test_vld3q_dup_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_u64
return|return
name|vld3q_dup_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x3_t
name|test_vld3q_dup_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_s8
return|return
name|vld3q_dup_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x3_t
name|test_vld3q_dup_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_s16
return|return
name|vld3q_dup_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x3_t
name|test_vld3q_dup_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_s32
return|return
name|vld3q_dup_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x3_t
name|test_vld3q_dup_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_s64
return|return
name|vld3q_dup_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x3_t
name|test_vld3q_dup_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_f16
return|return
name|vld3q_dup_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x3_t
name|test_vld3q_dup_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_f32
return|return
name|vld3q_dup_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x3_t
name|test_vld3q_dup_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_f64
return|return
name|vld3q_dup_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x3_t
name|test_vld3q_dup_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_p8
return|return
name|vld3q_dup_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x3_t
name|test_vld3q_dup_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_p16
return|return
name|vld3q_dup_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x3_t
name|test_vld3q_dup_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_dup_p64
return|return
name|vld3q_dup_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x3_t
name|test_vld3_dup_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_u8
return|return
name|vld3_dup_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x3_t
name|test_vld3_dup_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_u16
return|return
name|vld3_dup_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x3_t
name|test_vld3_dup_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_u32
return|return
name|vld3_dup_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x3_t
name|test_vld3_dup_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_u64
return|return
name|vld3_dup_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld3r}} {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x3_t
name|test_vld3_dup_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_s8
return|return
name|vld3_dup_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x3_t
name|test_vld3_dup_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_s16
return|return
name|vld3_dup_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x3_t
name|test_vld3_dup_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_s32
return|return
name|vld3_dup_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x3_t
name|test_vld3_dup_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_s64
return|return
name|vld3_dup_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld3r}} {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x3_t
name|test_vld3_dup_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_f16
return|return
name|vld3_dup_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x3_t
name|test_vld3_dup_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_f32
return|return
name|vld3_dup_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x3_t
name|test_vld3_dup_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_f64
return|return
name|vld3_dup_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld3r}} {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x3_t
name|test_vld3_dup_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_p8
return|return
name|vld3_dup_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x3_t
name|test_vld3_dup_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_p16
return|return
name|vld3_dup_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld3r {{{ *v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x3_t
name|test_vld3_dup_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_dup_p64
return|return
name|vld3_dup_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld3r}} {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}},
comment|// [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x4_t
name|test_vld4q_dup_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_u8
return|return
name|vld4q_dup_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x4_t
name|test_vld4q_dup_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_u16
return|return
name|vld4q_dup_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x4_t
name|test_vld4q_dup_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_u32
return|return
name|vld4q_dup_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x4_t
name|test_vld4q_dup_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_u64
return|return
name|vld4q_dup_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x4_t
name|test_vld4q_dup_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_s8
return|return
name|vld4q_dup_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x4_t
name|test_vld4q_dup_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_s16
return|return
name|vld4q_dup_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x4_t
name|test_vld4q_dup_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_s32
return|return
name|vld4q_dup_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x4_t
name|test_vld4q_dup_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_s64
return|return
name|vld4q_dup_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x4_t
name|test_vld4q_dup_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_f16
return|return
name|vld4q_dup_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x4_t
name|test_vld4q_dup_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_f32
return|return
name|vld4q_dup_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s, v[0-9]+.4s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x4_t
name|test_vld4q_dup_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_f64
return|return
name|vld4q_dup_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x4_t
name|test_vld4q_dup_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_p8
return|return
name|vld4q_dup_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b, v[0-9]+.16b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x4_t
name|test_vld4q_dup_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_p16
return|return
name|vld4q_dup_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h, v[0-9]+.8h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x4_t
name|test_vld4q_dup_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_dup_p64
return|return
name|vld4q_dup_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x4_t
name|test_vld4_dup_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_u8
return|return
name|vld4_dup_u8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x4_t
name|test_vld4_dup_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_u16
return|return
name|vld4_dup_u16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x4_t
name|test_vld4_dup_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_u32
return|return
name|vld4_dup_u32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x4_t
name|test_vld4_dup_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_u64
return|return
name|vld4_dup_u64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld4r}} {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x4_t
name|test_vld4_dup_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_s8
return|return
name|vld4_dup_s8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x4_t
name|test_vld4_dup_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_s16
return|return
name|vld4_dup_s16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x4_t
name|test_vld4_dup_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_s32
return|return
name|vld4_dup_s32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x4_t
name|test_vld4_dup_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_s64
return|return
name|vld4_dup_s64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld4r}} {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x4_t
name|test_vld4_dup_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_f16
return|return
name|vld4_dup_f16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x4_t
name|test_vld4_dup_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_f32
return|return
name|vld4_dup_f32
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s, v[0-9]+.2s *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x4_t
name|test_vld4_dup_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_f64
return|return
name|vld4_dup_f64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld4r}} {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x4_t
name|test_vld4_dup_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_p8
return|return
name|vld4_dup_p8
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b, v[0-9]+.8b *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x4_t
name|test_vld4_dup_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_p16
return|return
name|vld4_dup_p16
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: ld4r {{{ *v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h, v[0-9]+.4h *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x4_t
name|test_vld4_dup_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_dup_p64
return|return
name|vld4_dup_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: {{ld1|ld4r}} {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16_t
name|test_vld1q_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_u8
return|return
name|vld1q_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8_t
name|test_vld1q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_u16
return|return
name|vld1q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4_t
name|test_vld1q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_u32
return|return
name|vld1q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2_t
name|test_vld1q_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_u64
return|return
name|vld1q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16_t
name|test_vld1q_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_s8
return|return
name|vld1q_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8_t
name|test_vld1q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_s16
return|return
name|vld1q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4_t
name|test_vld1q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_s32
return|return
name|vld1q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2_t
name|test_vld1q_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_s64
return|return
name|vld1q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8_t
name|test_vld1q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_f16
return|return
name|vld1q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4_t
name|test_vld1q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_f32
return|return
name|vld1q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2_t
name|test_vld1q_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_f64
return|return
name|vld1q_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16_t
name|test_vld1q_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_p8
return|return
name|vld1q_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8_t
name|test_vld1q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_p16
return|return
name|vld1q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2_t
name|test_vld1q_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_lane_p64
return|return
name|vld1q_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8_t
name|test_vld1_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_u8
return|return
name|vld1_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4_t
name|test_vld1_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_u16
return|return
name|vld1_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2_t
name|test_vld1_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_u32
return|return
name|vld1_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1_t
name|test_vld1_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_u64
return|return
name|vld1_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: {{ld1r { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8_t
name|test_vld1_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_s8
return|return
name|vld1_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4_t
name|test_vld1_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_s16
return|return
name|vld1_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2_t
name|test_vld1_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_s32
return|return
name|vld1_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1_t
name|test_vld1_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_s64
return|return
name|vld1_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: {{ld1r { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4_t
name|test_vld1_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_f16
return|return
name|vld1_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2_t
name|test_vld1_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_f32
return|return
name|vld1_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1_t
name|test_vld1_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_f64
return|return
name|vld1_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: {{ld1r { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8_t
name|test_vld1_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_p8
return|return
name|vld1_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4_t
name|test_vld1_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_p16
return|return
name|vld1_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1_t
name|test_vld1_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_lane_p64
return|return
name|vld1_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: {{ld1r { v[0-9]+.1d }|ldr d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x2_t
name|test_vld2q_lane_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|ptr
parameter_list|,
name|int8x16x2_t
name|src
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_s8
return|return
name|vld2q_lane_s8
argument_list|(
name|ptr
argument_list|,
name|src
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.b,  v[0-9]+.b *}}}[15], [x0]
block|}
end_function

begin_function
name|uint8x16x2_t
name|test_vld2q_lane_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|ptr
parameter_list|,
name|uint8x16x2_t
name|src
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_u8
return|return
name|vld2q_lane_u8
argument_list|(
name|ptr
argument_list|,
name|src
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[15], [x0]
block|}
end_function

begin_function
name|poly8x16x2_t
name|test_vld2q_lane_p8
parameter_list|(
name|poly8_t
specifier|const
modifier|*
name|ptr
parameter_list|,
name|poly8x16x2_t
name|src
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_p8
return|return
name|vld2q_lane_p8
argument_list|(
name|ptr
argument_list|,
name|src
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[15], [x0]
block|}
end_function

begin_function
name|int8x16x3_t
name|test_vld3q_lane_s8
parameter_list|(
name|int8_t
specifier|const
modifier|*
name|ptr
parameter_list|,
name|int8x16x3_t
name|src
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_s8
return|return
name|vld3q_lane_s8
argument_list|(
name|ptr
argument_list|,
name|src
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [x0]
block|}
end_function

begin_function
name|uint8x16x3_t
name|test_vld3q_lane_u8
parameter_list|(
name|uint8_t
specifier|const
modifier|*
name|ptr
parameter_list|,
name|uint8x16x3_t
name|src
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_u8
return|return
name|vld3q_lane_u8
argument_list|(
name|ptr
argument_list|,
name|src
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [x0]
block|}
end_function

begin_function
name|uint16x8x2_t
name|test_vld2q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_u16
return|return
name|vld2q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x2_t
name|test_vld2q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_u32
return|return
name|vld2q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x2_t
name|test_vld2q_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_u64
return|return
name|vld2q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x2_t
name|test_vld2q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_s16
return|return
name|vld2q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x2_t
name|test_vld2q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_s32
return|return
name|vld2q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x2_t
name|test_vld2q_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_s64
return|return
name|vld2q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x2_t
name|test_vld2q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_f16
return|return
name|vld2q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x2_t
name|test_vld2q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_f32
return|return
name|vld2q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x2_t
name|test_vld2q_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_f64
return|return
name|vld2q_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x2_t
name|test_vld2q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_p16
return|return
name|vld2q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x2_t
name|test_vld2q_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_lane_p64
return|return
name|vld2q_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x2_t
name|test_vld2_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_u8
return|return
name|vld2_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x2_t
name|test_vld2_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_u16
return|return
name|vld2_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x2_t
name|test_vld2_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_u32
return|return
name|vld2_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x2_t
name|test_vld2_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_u64
return|return
name|vld2_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x2_t
name|test_vld2_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_s8
return|return
name|vld2_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x2_t
name|test_vld2_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_s16
return|return
name|vld2_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x2_t
name|test_vld2_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_s32
return|return
name|vld2_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x2_t
name|test_vld2_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_s64
return|return
name|vld2_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x2_t
name|test_vld2_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_f16
return|return
name|vld2_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x2_t
name|test_vld2_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_f32
return|return
name|vld2_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x2_t
name|test_vld2_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_f64
return|return
name|vld2_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x2_t
name|test_vld2_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_p8
return|return
name|vld2_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x2_t
name|test_vld2_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_p16
return|return
name|vld2_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x2_t
name|test_vld2_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_lane_p64
return|return
name|vld2_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x3_t
name|test_vld3q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_u16
return|return
name|vld3q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x3_t
name|test_vld3q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_u32
return|return
name|vld3q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x3_t
name|test_vld3q_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_u64
return|return
name|vld3q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x3_t
name|test_vld3q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_s16
return|return
name|vld3q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x3_t
name|test_vld3q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_s32
return|return
name|vld3q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x3_t
name|test_vld3q_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_s64
return|return
name|vld3q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x3_t
name|test_vld3q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_f16
return|return
name|vld3q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x3_t
name|test_vld3q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_f32
return|return
name|vld3q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x3_t
name|test_vld3q_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_f64
return|return
name|vld3q_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x3_t
name|test_vld3q_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_p8
return|return
name|vld3q_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x3_t
name|test_vld3q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_p16
return|return
name|vld3q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x3_t
name|test_vld3q_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_lane_p64
return|return
name|vld3q_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x3_t
name|test_vld3_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_u8
return|return
name|vld3_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x3_t
name|test_vld3_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_u16
return|return
name|vld3_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x3_t
name|test_vld3_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_u32
return|return
name|vld3_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x3_t
name|test_vld3_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_u64
return|return
name|vld3_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x3_t
name|test_vld3_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_s8
return|return
name|vld3_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x3_t
name|test_vld3_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_s16
return|return
name|vld3_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x3_t
name|test_vld3_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_s32
return|return
name|vld3_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x3_t
name|test_vld3_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_s64
return|return
name|vld3_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x3_t
name|test_vld3_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_f16
return|return
name|vld3_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x3_t
name|test_vld3_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_f32
return|return
name|vld3_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x3_t
name|test_vld3_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_f64
return|return
name|vld3_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x3_t
name|test_vld3_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_p8
return|return
name|vld3_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x3_t
name|test_vld3_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_p16
return|return
name|vld3_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x3_t
name|test_vld3_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_lane_p64
return|return
name|vld3_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x16x4_t
name|test_vld4q_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_u8
return|return
name|vld4q_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x8x4_t
name|test_vld4q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_u16
return|return
name|vld4q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x4x4_t
name|test_vld4q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_u32
return|return
name|vld4q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x2x4_t
name|test_vld4q_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_u64
return|return
name|vld4q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x16x4_t
name|test_vld4q_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_s8
return|return
name|vld4q_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x8x4_t
name|test_vld4q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_s16
return|return
name|vld4q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x4x4_t
name|test_vld4q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_s32
return|return
name|vld4q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x2x4_t
name|test_vld4q_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_s64
return|return
name|vld4q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x8x4_t
name|test_vld4q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_f16
return|return
name|vld4q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x4x4_t
name|test_vld4q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_f32
return|return
name|vld4q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x2x4_t
name|test_vld4q_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_f64
return|return
name|vld4q_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x16x4_t
name|test_vld4q_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_p8
return|return
name|vld4q_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x8x4_t
name|test_vld4q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_p16
return|return
name|vld4q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x4_t
name|test_vld4q_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_lane_p64
return|return
name|vld4q_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint8x8x4_t
name|test_vld4_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_u8
return|return
name|vld4_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint16x4x4_t
name|test_vld4_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_u16
return|return
name|vld4_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint32x2x4_t
name|test_vld4_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_u32
return|return
name|vld4_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|uint64x1x4_t
name|test_vld4_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_u64
return|return
name|vld4_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int8x8x4_t
name|test_vld4_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_s8
return|return
name|vld4_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int16x4x4_t
name|test_vld4_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_s16
return|return
name|vld4_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int32x2x4_t
name|test_vld4_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_s32
return|return
name|vld4_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|int64x1x4_t
name|test_vld4_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_s64
return|return
name|vld4_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float16x4x4_t
name|test_vld4_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_f16
return|return
name|vld4_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float32x2x4_t
name|test_vld4_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_f32
return|return
name|vld4_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|float64x1x4_t
name|test_vld4_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_f64
return|return
name|vld4_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly8x8x4_t
name|test_vld4_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_p8
return|return
name|vld4_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly16x4x4_t
name|test_vld4_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_p16
return|return
name|vld4_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x4_t
name|test_vld4_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_lane_p64
return|return
name|vld4_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_u8
name|vst1q_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_u16
name|vst1q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_u32
name|vst1q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_u64
name|vst1q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_s8
name|vst1q_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_s16
name|vst1q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_s32
name|vst1q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_s64
name|vst1q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_f16
name|vst1q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_f32
name|vst1q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_f64
name|vst1q_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_p8
name|vst1q_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_p16
name|vst1q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_lane_p64
name|vst1q_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_u8
name|vst1_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_u16
name|vst1_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_u32
name|vst1_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_u64
name|vst1_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_s8
name|vst1_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_s16
name|vst1_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_s32
name|vst1_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_s64
name|vst1_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_f16
name|vst1_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_f32
name|vst1_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_f64
name|vst1_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: {{st1 { v[0-9]+.d }\[0]|str d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_p8
name|vst1_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_p16
name|vst1_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_lane_p64
name|vst1_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st1 {{{ *v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_u8
name|vst2q_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_u16
name|vst2q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_u32
name|vst2q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_u64
name|vst2q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_s8
name|vst2q_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_s16
name|vst2q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_s32
name|vst2q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_s64
name|vst2q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_f16
name|vst2q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_f32
name|vst2q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_f64
name|vst2q_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_p8
name|vst2q_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_p16
name|vst2q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_lane_p64
name|vst2q_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_u8
name|vst2_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_u16
name|vst2_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_u32
name|vst2_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_u64
name|vst2_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_s8
name|vst2_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_s16
name|vst2_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_s32
name|vst2_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_s64
name|vst2_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_f16
name|vst2_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_f32
name|vst2_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_f64
name|vst2_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_p8
name|vst2_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_p16
name|vst2_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_lane_p64
name|vst2_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st2 {{{ *v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_u8
name|vst3q_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_u16
name|vst3q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_u32
name|vst3q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_u64
name|vst3q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_s8
name|vst3q_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_s16
name|vst3q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_s32
name|vst3q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_s64
name|vst3q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_f16
name|vst3q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_f32
name|vst3q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_f64
name|vst3q_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_p8
name|vst3q_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_p16
name|vst3q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_lane_p64
name|vst3q_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_u8
name|vst3_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_u16
name|vst3_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_u32
name|vst3_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_u64
name|vst3_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_s8
name|vst3_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_s16
name|vst3_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_s32
name|vst3_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_s64
name|vst3_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_f16
name|vst3_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_f32
name|vst3_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_f64
name|vst3_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_p8
name|vst3_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_p16
name|vst3_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1x3_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_lane_p64
name|vst3_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st3 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_u8
name|vst4q_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_u16
name|vst4q_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_u32
name|vst4q_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_u64
name|vst4q_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_s8
name|vst4q_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_s16
name|vst4q_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_s32
name|vst4q_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_s64
name|vst4q_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_f16
name|vst4q_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_f32
name|vst4q_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_f64
name|vst4q_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_p8
name|vst4q_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[15], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_p16
name|vst4q_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_lane_p64
name|vst4q_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_u8
parameter_list|(
name|uint8_t
modifier|*
name|a
parameter_list|,
name|uint8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_u8
name|vst4_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_u16
parameter_list|(
name|uint16_t
modifier|*
name|a
parameter_list|,
name|uint16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_u16
name|vst4_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_u32
parameter_list|(
name|uint32_t
modifier|*
name|a
parameter_list|,
name|uint32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_u32
name|vst4_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_u64
parameter_list|(
name|uint64_t
modifier|*
name|a
parameter_list|,
name|uint64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_u64
name|vst4_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_s8
parameter_list|(
name|int8_t
modifier|*
name|a
parameter_list|,
name|int8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_s8
name|vst4_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_s16
parameter_list|(
name|int16_t
modifier|*
name|a
parameter_list|,
name|int16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_s16
name|vst4_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_s32
parameter_list|(
name|int32_t
modifier|*
name|a
parameter_list|,
name|int32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_s32
name|vst4_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_s64
parameter_list|(
name|int64_t
modifier|*
name|a
parameter_list|,
name|int64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_s64
name|vst4_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_f16
name|vst4_lane_f16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_f32
parameter_list|(
name|float32_t
modifier|*
name|a
parameter_list|,
name|float32x2x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_f32
name|vst4_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.s, v[0-9]+.s, v[0-9]+.s, v[0-9]+.s *}}}[1], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_f64
parameter_list|(
name|float64_t
modifier|*
name|a
parameter_list|,
name|float64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_f64
name|vst4_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_p8
parameter_list|(
name|poly8_t
modifier|*
name|a
parameter_list|,
name|poly8x8x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_p8
name|vst4_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.b, v[0-9]+.b, v[0-9]+.b, v[0-9]+.b *}}}[7], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_p16
parameter_list|(
name|poly16_t
modifier|*
name|a
parameter_list|,
name|poly16x4x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_p16
name|vst4_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.h, v[0-9]+.h, v[0-9]+.h, v[0-9]+.h *}}}[3], [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_lane_p64
parameter_list|(
name|poly64_t
modifier|*
name|a
parameter_list|,
name|poly64x1x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_lane_p64
name|vst4_lane_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: st4 {{{ *v[0-9]+.d, v[0-9]+.d, v[0-9]+.d, v[0-9]+.d *}}}[0], [{{x[0-9]+|sp}}]
block|}
end_function

end_unit

