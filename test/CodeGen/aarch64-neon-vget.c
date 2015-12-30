begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-darwin -target-feature +neon \
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
name|uint8_t
name|test_vget_lane_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_u8:
comment|// CHECK-NEXT:  umov.b w0, v0[7]
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_u8
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
name|test_vget_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_u16:
comment|// CHECK-NEXT:  umov.h w0, v0[3]
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vget_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_u32:
comment|// CHECK-NEXT:  mov.s  w0, v0[1]
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_u32
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
name|test_vget_lane_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_s8:
comment|// CHECK-NEXT:  umov.b w0, v0[7]
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_s8
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
name|test_vget_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_s16:
comment|// CHECK-NEXT:  umov.h w0, v0[3]
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vget_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_s32:
comment|// CHECK-NEXT:  mov.s  w0, v0[1]
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|poly8_t
name|test_vget_lane_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_p8:
comment|// CHECK-NEXT:  umov.b w0, v0[7]
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_p8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|poly16_t
name|test_vget_lane_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_p16:
comment|// CHECK-NEXT:  umov.h w0, v0[3]
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_p16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vget_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_f32:
comment|// CHECK-NEXT:  mov s0, v0[1]
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_f32
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
name|test_vget_lane_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_f16:
comment|// CHECK-NEXT:  umov.h w8, v0[1]
comment|// CHECK-NEXT:  fmov s0, w8
comment|// CHECK-NEXT:  fcvt s0, h0
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_f16
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
name|test_vgetq_lane_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_u8:
comment|// CHECK-NEXT:  umov.b w0, v0[15]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_u8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16_t
name|test_vgetq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_u16:
comment|// CHECK-NEXT:  umov.h w0, v0[7]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_u16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vgetq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_u32:
comment|// CHECK-NEXT:  mov.s  w0, v0[3]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|int8_t
name|test_vgetq_lane_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_s8:
comment|// CHECK-NEXT:  umov.b w0, v0[15]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_s8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|int16_t
name|test_vgetq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_s16:
comment|// CHECK-NEXT:  umov.h w0, v0[7]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_s16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vgetq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_s32:
comment|// CHECK-NEXT:  mov.s  w0, v0[3]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|poly8_t
name|test_vgetq_lane_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_p8:
comment|// CHECK-NEXT:  umov.b w0, v0[15]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_p8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|poly16_t
name|test_vgetq_lane_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_p16:
comment|// CHECK-NEXT:  umov.h w0, v0[7]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_p16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vgetq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_f32:
comment|// CHECK-NEXT:  mov s0, v0[3]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_f32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|float32_t
name|test_vgetq_lane_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_f16:
comment|// CHECK-NEXT:  umov.h w8, v0[3]
comment|// CHECK-NEXT:  fmov s0, w8
comment|// CHECK-NEXT:  fcvt s0, h0
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_f16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vget_lane_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_s64:
comment|// CHECK-NEXT:  fmov x0, d0
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_s64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vget_lane_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_u64:
comment|// CHECK-NEXT:  fmov x0, d0
comment|// CHECK-NEXT:  ret
return|return
name|vget_lane_u64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vgetq_lane_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_s64:
comment|// CHECK-NEXT:  mov.d  x0, v0[1]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_s64
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
name|test_vgetq_lane_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_u64:
comment|// CHECK-NEXT:  mov.d  x0, v0[1]
comment|// CHECK-NEXT:  ret
return|return
name|vgetq_lane_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x8_t
name|test_vset_lane_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_u8:
comment|// CHECK-NEXT:  ins.b v0[7], w0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x4_t
name|test_vset_lane_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_u16:
comment|// CHECK-NEXT:  ins.h v0[3], w0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|test_vset_lane_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_u32:
comment|// CHECK-NEXT:  ins.s v0[1], w0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_u32
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
name|int8x8_t
name|test_vset_lane_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_s8:
comment|// CHECK-NEXT:  ins.b v0[7], w0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x4_t
name|test_vset_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_s16:
comment|// CHECK-NEXT:  ins.h v0[3], w0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|test_vset_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_s32:
comment|// CHECK-NEXT:  ins.s v0[1], w0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_s32
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
name|poly8x8_t
name|test_vset_lane_p8
parameter_list|(
name|poly8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_p8:
comment|// CHECK-NEXT:  ins.b v0[7], w0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|poly16x4_t
name|test_vset_lane_p16
parameter_list|(
name|poly16_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_p16:
comment|// CHECK-NEXT:  ins.h v0[3], w0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|test_vset_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_f32:
comment|// CHECK-NEXT:  ins.s v1[1], v0[0]
comment|// CHECK-NEXT:  mov.16b  v0, v1
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_f32
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
name|float16x4_t
name|test_vset_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_f16:
comment|// CHECK-NEXT:  ld1.h { v0 }[3], [x0]
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_f16
argument_list|(
operator|*
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x16_t
name|test_vsetq_lane_u8
parameter_list|(
name|uint8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_u8:
comment|// CHECK-NEXT:  ins.b v0[15], w0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsetq_lane_u16
parameter_list|(
name|uint16_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_u16:
comment|// CHECK-NEXT:  ins.h v0[7], w0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsetq_lane_u32
parameter_list|(
name|uint32_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_u32:
comment|// CHECK-NEXT:  ins.s v0[3], w0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x16_t
name|test_vsetq_lane_s8
parameter_list|(
name|int8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_s8:
comment|// CHECK-NEXT:  ins.b v0[15], w0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x8_t
name|test_vsetq_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_s16:
comment|// CHECK-NEXT:  ins.h v0[7], w0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x4_t
name|test_vsetq_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_s32:
comment|// CHECK-NEXT:  ins.s v0[3], w0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|poly8x16_t
name|test_vsetq_lane_p8
parameter_list|(
name|poly8_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_p8:
comment|// CHECK-NEXT:  ins.b v0[15], w0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|poly16x8_t
name|test_vsetq_lane_p16
parameter_list|(
name|poly16_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_p16:
comment|// CHECK-NEXT:  ins.h v0[7], w0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vsetq_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_f32:
comment|// CHECK-NEXT:  ins.s v1[3], v0[0]
comment|// CHECK-NEXT:  mov.16b  v0, v1
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|float16x8_t
name|test_vsetq_lane_f16
parameter_list|(
name|float16_t
modifier|*
name|a
parameter_list|,
name|float16x8_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_f16:
comment|// CHECK-NEXT:  ld1.h { v0 }[7], [x0]
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_f16
argument_list|(
operator|*
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vset_lane_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_s64:
comment|// CHECK-NEXT:  fmov d0, x0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vset_lane_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_u64:
comment|// CHECK-NEXT:  fmov d0, x0
comment|// CHECK-NEXT:  ret
return|return
name|vset_lane_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x2_t
name|test_vsetq_lane_s64
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_s64:
comment|// CHECK-NEXT:  ins.d v0[1], x0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_s64
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
name|uint64x2_t
name|test_vsetq_lane_u64
parameter_list|(
name|uint64_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_u64:
comment|// CHECK-NEXT:  ins.d v0[1], x0
comment|// CHECK-NEXT:  ret
return|return
name|vsetq_lane_u64
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

end_unit

