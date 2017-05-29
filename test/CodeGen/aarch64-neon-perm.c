begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN: -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_comment
comment|// Test new aarch64 intrinsics and types
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: @test_vuzp1_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14, i32 16, i32 18, i32 20, i32 22, i32 24, i32 26, i32 28, i32 30>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_s64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14, i32 16, i32 18, i32 20, i32 22, i32 24, i32 26, i32 28, i32 30>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_u64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x double> %a,<2 x double> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14, i32 16, i32 18, i32 20, i32 22, i32 24, i32 26, i32 28, i32 30>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp1q_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp1q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15, i32 17, i32 19, i32 21, i32 23, i32 25, i32 27, i32 29, i32 31>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_s64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15, i32 17, i32 19, i32 21, i32 23, i32 25, i32 27, i32 29, i32 31>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_u64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x double> %a,<2 x double> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15, i32 17, i32 19, i32 21, i32 23, i32 25, i32 27, i32 29, i32 31>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp2q_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vuzp2q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_s64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_u64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x double> %a,<2 x double> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip1q_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip1q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_s64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_u64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x double> %a,<2 x double> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip2q_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vzip2q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 2, i32 18, i32 4, i32 20, i32 6, i32 22, i32 8, i32 24, i32 10, i32 26, i32 12, i32 28, i32 14, i32 30>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_s64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 2, i32 18, i32 4, i32 20, i32 6, i32 22, i32 8, i32 24, i32 10, i32 26, i32 12, i32 28, i32 14, i32 30>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_u64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x double> %a,<2 x double> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 2, i32 18, i32 4, i32 20, i32 6, i32 22, i32 8, i32 24, i32 10, i32 26, i32 12, i32 28, i32 14, i32 30>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn1q_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn1q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 17, i32 3, i32 19, i32 5, i32 21, i32 7, i32 23, i32 9, i32 25, i32 11, i32 27, i32 13, i32 29, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_s64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 17, i32 3, i32 19, i32 5, i32 21, i32 7, i32 23, i32 9, i32 25, i32 11, i32 27, i32 13, i32 29, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_u64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x double> %a,<2 x double> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 17, i32 3, i32 19, i32 5, i32 21, i32 7, i32 23, i32 9, i32 25, i32 11, i32 27, i32 13, i32 29, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn2q_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vtrn2q_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp_s8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VUZP_I]],<8 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<8 x i8>,<8 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VUZP1_I]],<8 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.int8x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.int8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.int8x8x2_t, %struct.int8x8x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.int8x8x2_t, %struct.int8x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.int8x8x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i8>] [[TMP7]], [2 x<8 x i8>]* [[TMP6]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.int8x8x2_t, %struct.int8x8x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.int8x8x2_t [[TMP8]]
end_comment

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
return|return
name|vuzp_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp_s16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VUZP_I]],<4 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i16>,<4 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VUZP1_I]],<4 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int16x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int16x4x2_t, %struct.int16x4x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int16x4x2_t, %struct.int16x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int16x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i16>] [[TMP9]], [2 x<4 x i16>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int16x4x2_t, %struct.int16x4x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.int16x4x2_t [[TMP10]]
end_comment

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
return|return
name|vuzp_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp_s32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<2 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VUZP_I]],<2 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<2 x i32>,<2 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VUZP1_I]],<2 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int32x2x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int32x2x2_t, %struct.int32x2x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int32x2x2_t, %struct.int32x2x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int32x2x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x i32>] [[TMP9]], [2 x<2 x i32>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int32x2x2_t, %struct.int32x2x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.int32x2x2_t [[TMP10]]
end_comment

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
return|return
name|vuzp_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp_u8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VUZP_I]],<8 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<8 x i8>,<8 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VUZP1_I]],<8 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.uint8x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.uint8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.uint8x8x2_t, %struct.uint8x8x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, %struct.uint8x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.uint8x8x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i8>] [[TMP7]], [2 x<8 x i8>]* [[TMP6]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.uint8x8x2_t, %struct.uint8x8x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint8x8x2_t [[TMP8]]
end_comment

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
return|return
name|vuzp_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp_u16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VUZP_I]],<4 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i16>,<4 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VUZP1_I]],<4 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint16x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint16x4x2_t, %struct.uint16x4x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, %struct.uint16x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint16x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i16>] [[TMP9]], [2 x<4 x i16>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint16x4x2_t, %struct.uint16x4x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint16x4x2_t [[TMP10]]
end_comment

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
return|return
name|vuzp_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp_u32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<2 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VUZP_I]],<2 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<2 x i32>,<2 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VUZP1_I]],<2 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint32x2x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint32x2x2_t, %struct.uint32x2x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, %struct.uint32x2x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint32x2x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x i32>] [[TMP9]], [2 x<2 x i32>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint32x2x2_t, %struct.uint32x2x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint32x2x2_t [[TMP10]]
end_comment

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
return|return
name|vuzp_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp_f32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.float32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.float32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.float32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.float32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<2 x float>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   store<2 x float> [[VUZP_I]],<2 x float>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<2 x float>,<2 x float>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   store<2 x float> [[VUZP1_I]],<2 x float>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.float32x2x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.float32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.float32x2x2_t, %struct.float32x2x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.float32x2x2_t, %struct.float32x2x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.float32x2x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x float>] [[TMP9]], [2 x<2 x float>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.float32x2x2_t, %struct.float32x2x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.float32x2x2_t [[TMP10]]
end_comment

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
return|return
name|vuzp_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp_p8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VUZP_I]],<8 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<8 x i8>,<8 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VUZP1_I]],<8 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.poly8x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.poly8x8x2_t, %struct.poly8x8x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, %struct.poly8x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.poly8x8x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i8>] [[TMP7]], [2 x<8 x i8>]* [[TMP6]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.poly8x8x2_t, %struct.poly8x8x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly8x8x2_t [[TMP8]]
end_comment

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
return|return
name|vuzp_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzp_p16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VUZP_I]],<4 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i16>,<4 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VUZP1_I]],<4 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly16x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.poly16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.poly16x4x2_t, %struct.poly16x4x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, %struct.poly16x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.poly16x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i16>] [[TMP9]], [2 x<4 x i16>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.poly16x4x2_t, %struct.poly16x4x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly16x4x2_t [[TMP10]]
end_comment

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
return|return
name|vuzp_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzpq_s8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14, i32 16, i32 18, i32 20, i32 22, i32 24, i32 26, i32 28, i32 30>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VUZP_I]],<16 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<16 x i8>,<16 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15, i32 17, i32 19, i32 21, i32 23, i32 25, i32 27, i32 29, i32 31>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VUZP1_I]],<16 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.int8x16x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.int8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.int8x16x2_t, %struct.int8x16x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.int8x16x2_t, %struct.int8x16x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.int8x16x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<16 x i8>] [[TMP7]], [2 x<16 x i8>]* [[TMP6]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.int8x16x2_t, %struct.int8x16x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.int8x16x2_t [[TMP8]]
end_comment

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
return|return
name|vuzpq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzpq_s16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VUZP_I]],<8 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<8 x i16>,<8 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VUZP1_I]],<8 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int16x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int16x8x2_t, %struct.int16x8x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int16x8x2_t, %struct.int16x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int16x8x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i16>] [[TMP9]], [2 x<8 x i16>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int16x8x2_t, %struct.int16x8x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.int16x8x2_t [[TMP10]]
end_comment

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
return|return
name|vuzpq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzpq_s32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VUZP_I]],<4 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i32>,<4 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VUZP1_I]],<4 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int32x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int32x4x2_t, %struct.int32x4x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int32x4x2_t, %struct.int32x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int32x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i32>] [[TMP9]], [2 x<4 x i32>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int32x4x2_t, %struct.int32x4x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.int32x4x2_t [[TMP10]]
end_comment

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
return|return
name|vuzpq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzpq_u8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14, i32 16, i32 18, i32 20, i32 22, i32 24, i32 26, i32 28, i32 30>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VUZP_I]],<16 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<16 x i8>,<16 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15, i32 17, i32 19, i32 21, i32 23, i32 25, i32 27, i32 29, i32 31>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VUZP1_I]],<16 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.uint8x16x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.uint8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.uint8x16x2_t, %struct.uint8x16x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.uint8x16x2_t, %struct.uint8x16x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.uint8x16x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<16 x i8>] [[TMP7]], [2 x<16 x i8>]* [[TMP6]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.uint8x16x2_t, %struct.uint8x16x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint8x16x2_t [[TMP8]]
end_comment

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
return|return
name|vuzpq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzpq_u16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VUZP_I]],<8 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<8 x i16>,<8 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VUZP1_I]],<8 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint16x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint16x8x2_t, %struct.uint16x8x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, %struct.uint16x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint16x8x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i16>] [[TMP9]], [2 x<8 x i16>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint16x8x2_t, %struct.uint16x8x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint16x8x2_t [[TMP10]]
end_comment

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
return|return
name|vuzpq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzpq_u32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VUZP_I]],<4 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i32>,<4 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VUZP1_I]],<4 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint32x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint32x4x2_t, %struct.uint32x4x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, %struct.uint32x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint32x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i32>] [[TMP9]], [2 x<4 x i32>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint32x4x2_t, %struct.uint32x4x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint32x4x2_t [[TMP10]]
end_comment

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
return|return
name|vuzpq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzpq_f32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.float32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.float32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.float32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.float32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x float>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 0, i32 2, i32 4, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x float> [[VUZP_I]],<4 x float>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x float>,<4 x float>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 1, i32 3, i32 5, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x float> [[VUZP1_I]],<4 x float>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.float32x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.float32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.float32x4x2_t, %struct.float32x4x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.float32x4x2_t, %struct.float32x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.float32x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x float>] [[TMP9]], [2 x<4 x float>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.float32x4x2_t, %struct.float32x4x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.float32x4x2_t [[TMP10]]
end_comment

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
return|return
name|vuzpq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzpq_p8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14, i32 16, i32 18, i32 20, i32 22, i32 24, i32 26, i32 28, i32 30>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VUZP_I]],<16 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<16 x i8>,<16 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15, i32 17, i32 19, i32 21, i32 23, i32 25, i32 27, i32 29, i32 31>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VUZP1_I]],<16 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.poly8x16x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.poly8x16x2_t, %struct.poly8x16x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.poly8x16x2_t, %struct.poly8x16x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.poly8x16x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<16 x i8>] [[TMP7]], [2 x<16 x i8>]* [[TMP6]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.poly8x16x2_t, %struct.poly8x16x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly8x16x2_t [[TMP8]]
end_comment

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
return|return
name|vuzpq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuzpq_p16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VUZP_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 2, i32 4, i32 6, i32 8, i32 10, i32 12, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VUZP_I]],<8 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<8 x i16>,<8 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VUZP1_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 3, i32 5, i32 7, i32 9, i32 11, i32 13, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VUZP1_I]],<8 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly16x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.poly16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.poly16x8x2_t, %struct.poly16x8x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, %struct.poly16x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.poly16x8x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i16>] [[TMP9]], [2 x<8 x i16>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.poly16x8x2_t, %struct.poly16x8x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly16x8x2_t [[TMP10]]
end_comment

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
return|return
name|vuzpq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip_s8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VZIP_I]],<8 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<8 x i8>,<8 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VZIP1_I]],<8 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.int8x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.int8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.int8x8x2_t, %struct.int8x8x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.int8x8x2_t, %struct.int8x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.int8x8x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i8>] [[TMP7]], [2 x<8 x i8>]* [[TMP6]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.int8x8x2_t, %struct.int8x8x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.int8x8x2_t [[TMP8]]
end_comment

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
return|return
name|vzip_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip_s16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VZIP_I]],<4 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i16>,<4 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VZIP1_I]],<4 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int16x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int16x4x2_t, %struct.int16x4x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int16x4x2_t, %struct.int16x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int16x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i16>] [[TMP9]], [2 x<4 x i16>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int16x4x2_t, %struct.int16x4x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.int16x4x2_t [[TMP10]]
end_comment

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
return|return
name|vzip_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip_s32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<2 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VZIP_I]],<2 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<2 x i32>,<2 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VZIP1_I]],<2 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int32x2x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int32x2x2_t, %struct.int32x2x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int32x2x2_t, %struct.int32x2x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int32x2x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x i32>] [[TMP9]], [2 x<2 x i32>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int32x2x2_t, %struct.int32x2x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.int32x2x2_t [[TMP10]]
end_comment

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
return|return
name|vzip_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip_u8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VZIP_I]],<8 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<8 x i8>,<8 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VZIP1_I]],<8 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.uint8x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.uint8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.uint8x8x2_t, %struct.uint8x8x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, %struct.uint8x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.uint8x8x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i8>] [[TMP7]], [2 x<8 x i8>]* [[TMP6]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.uint8x8x2_t, %struct.uint8x8x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint8x8x2_t [[TMP8]]
end_comment

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
return|return
name|vzip_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip_u16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VZIP_I]],<4 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i16>,<4 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VZIP1_I]],<4 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint16x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint16x4x2_t, %struct.uint16x4x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, %struct.uint16x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint16x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i16>] [[TMP9]], [2 x<4 x i16>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint16x4x2_t, %struct.uint16x4x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint16x4x2_t [[TMP10]]
end_comment

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
return|return
name|vzip_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip_u32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<2 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VZIP_I]],<2 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<2 x i32>,<2 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VZIP1_I]],<2 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint32x2x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint32x2x2_t, %struct.uint32x2x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, %struct.uint32x2x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint32x2x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x i32>] [[TMP9]], [2 x<2 x i32>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint32x2x2_t, %struct.uint32x2x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint32x2x2_t [[TMP10]]
end_comment

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
return|return
name|vzip_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip_f32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.float32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.float32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.float32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.float32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<2 x float>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   store<2 x float> [[VZIP_I]],<2 x float>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<2 x float>,<2 x float>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   store<2 x float> [[VZIP1_I]],<2 x float>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.float32x2x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.float32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.float32x2x2_t, %struct.float32x2x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.float32x2x2_t, %struct.float32x2x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.float32x2x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x float>] [[TMP9]], [2 x<2 x float>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.float32x2x2_t, %struct.float32x2x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.float32x2x2_t [[TMP10]]
end_comment

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
return|return
name|vzip_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip_p8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VZIP_I]],<8 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<8 x i8>,<8 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VZIP1_I]],<8 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.poly8x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.poly8x8x2_t, %struct.poly8x8x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, %struct.poly8x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.poly8x8x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i8>] [[TMP7]], [2 x<8 x i8>]* [[TMP6]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.poly8x8x2_t, %struct.poly8x8x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly8x8x2_t [[TMP8]]
end_comment

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
return|return
name|vzip_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzip_p16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VZIP_I]],<4 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i16>,<4 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VZIP1_I]],<4 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly16x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.poly16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.poly16x4x2_t, %struct.poly16x4x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, %struct.poly16x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.poly16x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i16>] [[TMP9]], [2 x<4 x i16>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.poly16x4x2_t, %struct.poly16x4x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly16x4x2_t [[TMP10]]
end_comment

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
return|return
name|vzip_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzipq_s8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VZIP_I]],<16 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<16 x i8>,<16 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VZIP1_I]],<16 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.int8x16x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.int8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.int8x16x2_t, %struct.int8x16x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.int8x16x2_t, %struct.int8x16x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.int8x16x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<16 x i8>] [[TMP7]], [2 x<16 x i8>]* [[TMP6]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.int8x16x2_t, %struct.int8x16x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.int8x16x2_t [[TMP8]]
end_comment

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
return|return
name|vzipq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzipq_s16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VZIP_I]],<8 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<8 x i16>,<8 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VZIP1_I]],<8 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int16x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int16x8x2_t, %struct.int16x8x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int16x8x2_t, %struct.int16x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int16x8x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i16>] [[TMP9]], [2 x<8 x i16>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int16x8x2_t, %struct.int16x8x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.int16x8x2_t [[TMP10]]
end_comment

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
return|return
name|vzipq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzipq_s32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VZIP_I]],<4 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i32>,<4 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VZIP1_I]],<4 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int32x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int32x4x2_t, %struct.int32x4x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int32x4x2_t, %struct.int32x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int32x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i32>] [[TMP9]], [2 x<4 x i32>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int32x4x2_t, %struct.int32x4x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.int32x4x2_t [[TMP10]]
end_comment

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
return|return
name|vzipq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzipq_u8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VZIP_I]],<16 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<16 x i8>,<16 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VZIP1_I]],<16 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.uint8x16x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.uint8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.uint8x16x2_t, %struct.uint8x16x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.uint8x16x2_t, %struct.uint8x16x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.uint8x16x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<16 x i8>] [[TMP7]], [2 x<16 x i8>]* [[TMP6]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.uint8x16x2_t, %struct.uint8x16x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint8x16x2_t [[TMP8]]
end_comment

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
return|return
name|vzipq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzipq_u16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VZIP_I]],<8 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<8 x i16>,<8 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VZIP1_I]],<8 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint16x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint16x8x2_t, %struct.uint16x8x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, %struct.uint16x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint16x8x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i16>] [[TMP9]], [2 x<8 x i16>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint16x8x2_t, %struct.uint16x8x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint16x8x2_t [[TMP10]]
end_comment

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
return|return
name|vzipq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzipq_u32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VZIP_I]],<4 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i32>,<4 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VZIP1_I]],<4 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint32x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint32x4x2_t, %struct.uint32x4x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, %struct.uint32x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint32x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i32>] [[TMP9]], [2 x<4 x i32>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint32x4x2_t, %struct.uint32x4x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint32x4x2_t [[TMP10]]
end_comment

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
return|return
name|vzipq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzipq_f32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.float32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.float32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.float32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.float32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x float>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 0, i32 4, i32 1, i32 5>
end_comment

begin_comment
comment|// CHECK:   store<4 x float> [[VZIP_I]],<4 x float>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x float>,<4 x float>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 2, i32 6, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x float> [[VZIP1_I]],<4 x float>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.float32x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.float32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.float32x4x2_t, %struct.float32x4x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.float32x4x2_t, %struct.float32x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.float32x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x float>] [[TMP9]], [2 x<4 x float>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.float32x4x2_t, %struct.float32x4x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.float32x4x2_t [[TMP10]]
end_comment

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
return|return
name|vzipq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzipq_p8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VZIP_I]],<16 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<16 x i8>,<16 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VZIP1_I]],<16 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.poly8x16x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.poly8x16x2_t, %struct.poly8x16x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.poly8x16x2_t, %struct.poly8x16x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.poly8x16x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<16 x i8>] [[TMP7]], [2 x<16 x i8>]* [[TMP6]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.poly8x16x2_t, %struct.poly8x16x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly8x16x2_t [[TMP8]]
end_comment

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
return|return
name|vzipq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vzipq_p16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VZIP_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VZIP_I]],<8 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<8 x i16>,<8 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VZIP1_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VZIP1_I]],<8 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly16x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.poly16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.poly16x8x2_t, %struct.poly16x8x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, %struct.poly16x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.poly16x8x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i16>] [[TMP9]], [2 x<8 x i16>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.poly16x8x2_t, %struct.poly16x8x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly16x8x2_t [[TMP10]]
end_comment

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
return|return
name|vzipq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn_s8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VTRN_I]],<8 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<8 x i8>,<8 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VTRN1_I]],<8 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.int8x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.int8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.int8x8x2_t, %struct.int8x8x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.int8x8x2_t, %struct.int8x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.int8x8x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i8>] [[TMP7]], [2 x<8 x i8>]* [[TMP6]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.int8x8x2_t, %struct.int8x8x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.int8x8x2_t [[TMP8]]
end_comment

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
return|return
name|vtrn_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn_s16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VTRN_I]],<4 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i16>,<4 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VTRN1_I]],<4 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int16x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int16x4x2_t, %struct.int16x4x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int16x4x2_t, %struct.int16x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int16x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i16>] [[TMP9]], [2 x<4 x i16>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int16x4x2_t, %struct.int16x4x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.int16x4x2_t [[TMP10]]
end_comment

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
return|return
name|vtrn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn_s32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<2 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VTRN_I]],<2 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<2 x i32>,<2 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VTRN1_I]],<2 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int32x2x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int32x2x2_t, %struct.int32x2x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int32x2x2_t, %struct.int32x2x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int32x2x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x i32>] [[TMP9]], [2 x<2 x i32>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int32x2x2_t, %struct.int32x2x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.int32x2x2_t [[TMP10]]
end_comment

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
return|return
name|vtrn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn_u8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VTRN_I]],<8 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<8 x i8>,<8 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VTRN1_I]],<8 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.uint8x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.uint8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.uint8x8x2_t, %struct.uint8x8x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.uint8x8x2_t, %struct.uint8x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.uint8x8x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i8>] [[TMP7]], [2 x<8 x i8>]* [[TMP6]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.uint8x8x2_t, %struct.uint8x8x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint8x8x2_t [[TMP8]]
end_comment

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
return|return
name|vtrn_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn_u16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VTRN_I]],<4 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i16>,<4 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VTRN1_I]],<4 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint16x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint16x4x2_t, %struct.uint16x4x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint16x4x2_t, %struct.uint16x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint16x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i16>] [[TMP9]], [2 x<4 x i16>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint16x4x2_t, %struct.uint16x4x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint16x4x2_t [[TMP10]]
end_comment

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
return|return
name|vtrn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn_u32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<2 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VTRN_I]],<2 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<2 x i32>,<2 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   store<2 x i32> [[VTRN1_I]],<2 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint32x2x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint32x2x2_t, %struct.uint32x2x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint32x2x2_t, %struct.uint32x2x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint32x2x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x i32>] [[TMP9]], [2 x<2 x i32>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint32x2x2_t, %struct.uint32x2x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint32x2x2_t [[TMP10]]
end_comment

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
return|return
name|vtrn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn_f32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.float32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.float32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.float32x2x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.float32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<2 x float>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 0, i32 2>
end_comment

begin_comment
comment|// CHECK:   store<2 x float> [[VTRN_I]],<2 x float>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<2 x float>,<2 x float>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %b,<2 x i32><i32 1, i32 3>
end_comment

begin_comment
comment|// CHECK:   store<2 x float> [[VTRN1_I]],<2 x float>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.float32x2x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.float32x2x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.float32x2x2_t, %struct.float32x2x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.float32x2x2_t, %struct.float32x2x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.float32x2x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<2 x float>] [[TMP9]], [2 x<2 x float>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.float32x2x2_t, %struct.float32x2x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.float32x2x2_t [[TMP10]]
end_comment

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
return|return
name|vtrn_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn_p8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly8x8x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<8 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VTRN_I]],<8 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<8 x i8>,<8 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i8> [[VTRN1_I]],<8 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.poly8x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly8x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.poly8x8x2_t, %struct.poly8x8x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.poly8x8x2_t, %struct.poly8x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.poly8x8x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i8>] [[TMP7]], [2 x<8 x i8>]* [[TMP6]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.poly8x8x2_t, %struct.poly8x8x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly8x8x2_t [[TMP8]]
end_comment

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
return|return
name|vtrn_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrn_p16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly16x4x2_t, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VTRN_I]],<4 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i16>,<4 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VTRN1_I]],<4 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly16x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.poly16x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 16, i32 8, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.poly16x4x2_t, %struct.poly16x4x2_t* [[RETVAL_I]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.poly16x4x2_t, %struct.poly16x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.poly16x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i16>] [[TMP9]], [2 x<4 x i16>]* [[TMP8]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.poly16x4x2_t, %struct.poly16x4x2_t* [[RETVAL]], align 8
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly16x4x2_t [[TMP10]]
end_comment

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
return|return
name|vtrn_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrnq_s8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 2, i32 18, i32 4, i32 20, i32 6, i32 22, i32 8, i32 24, i32 10, i32 26, i32 12, i32 28, i32 14, i32 30>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VTRN_I]],<16 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<16 x i8>,<16 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 17, i32 3, i32 19, i32 5, i32 21, i32 7, i32 23, i32 9, i32 25, i32 11, i32 27, i32 13, i32 29, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VTRN1_I]],<16 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.int8x16x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.int8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.int8x16x2_t, %struct.int8x16x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.int8x16x2_t, %struct.int8x16x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.int8x16x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<16 x i8>] [[TMP7]], [2 x<16 x i8>]* [[TMP6]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.int8x16x2_t, %struct.int8x16x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.int8x16x2_t [[TMP8]]
end_comment

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
return|return
name|vtrnq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrnq_s16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VTRN_I]],<8 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<8 x i16>,<8 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VTRN1_I]],<8 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int16x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int16x8x2_t, %struct.int16x8x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int16x8x2_t, %struct.int16x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int16x8x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i16>] [[TMP9]], [2 x<8 x i16>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int16x8x2_t, %struct.int16x8x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.int16x8x2_t [[TMP10]]
end_comment

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
return|return
name|vtrnq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrnq_s32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.int32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.int32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.int32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.int32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VTRN_I]],<4 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i32>,<4 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VTRN1_I]],<4 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.int32x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.int32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.int32x4x2_t, %struct.int32x4x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.int32x4x2_t, %struct.int32x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.int32x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i32>] [[TMP9]], [2 x<4 x i32>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.int32x4x2_t, %struct.int32x4x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.int32x4x2_t [[TMP10]]
end_comment

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
return|return
name|vtrnq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrnq_u8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 2, i32 18, i32 4, i32 20, i32 6, i32 22, i32 8, i32 24, i32 10, i32 26, i32 12, i32 28, i32 14, i32 30>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VTRN_I]],<16 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<16 x i8>,<16 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 17, i32 3, i32 19, i32 5, i32 21, i32 7, i32 23, i32 9, i32 25, i32 11, i32 27, i32 13, i32 29, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VTRN1_I]],<16 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.uint8x16x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.uint8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.uint8x16x2_t, %struct.uint8x16x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.uint8x16x2_t, %struct.uint8x16x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.uint8x16x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<16 x i8>] [[TMP7]], [2 x<16 x i8>]* [[TMP6]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.uint8x16x2_t, %struct.uint8x16x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint8x16x2_t [[TMP8]]
end_comment

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
return|return
name|vtrnq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrnq_u16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VTRN_I]],<8 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<8 x i16>,<8 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VTRN1_I]],<8 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint16x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint16x8x2_t, %struct.uint16x8x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint16x8x2_t, %struct.uint16x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint16x8x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i16>] [[TMP9]], [2 x<8 x i16>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint16x8x2_t, %struct.uint16x8x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint16x8x2_t [[TMP10]]
end_comment

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
return|return
name|vtrnq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrnq_u32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.uint32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.uint32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.uint32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.uint32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x i32>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VTRN_I]],<4 x i32>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x i32>,<4 x i32>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x i32> [[VTRN1_I]],<4 x i32>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.uint32x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.uint32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.uint32x4x2_t, %struct.uint32x4x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.uint32x4x2_t, %struct.uint32x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.uint32x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x i32>] [[TMP9]], [2 x<4 x i32>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.uint32x4x2_t, %struct.uint32x4x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.uint32x4x2_t [[TMP10]]
end_comment

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
return|return
name|vtrnq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrnq_f32(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.float32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.float32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.float32x4x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.float32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<4 x float>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 0, i32 4, i32 2, i32 6>
end_comment

begin_comment
comment|// CHECK:   store<4 x float> [[VTRN_I]],<4 x float>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<4 x float>,<4 x float>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %b,<4 x i32><i32 1, i32 5, i32 3, i32 7>
end_comment

begin_comment
comment|// CHECK:   store<4 x float> [[VTRN1_I]],<4 x float>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.float32x4x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.float32x4x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.float32x4x2_t, %struct.float32x4x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.float32x4x2_t, %struct.float32x4x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.float32x4x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<4 x float>] [[TMP9]], [2 x<4 x float>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.float32x4x2_t, %struct.float32x4x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.float32x4x2_t [[TMP10]]
end_comment

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
return|return
name|vtrnq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrnq_p8(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly8x16x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to<16 x i8>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 0, i32 16, i32 2, i32 18, i32 4, i32 20, i32 6, i32 22, i32 8, i32 24, i32 10, i32 26, i32 12, i32 28, i32 14, i32 30>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VTRN_I]],<16 x i8>* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = getelementptr inbounds<16 x i8>,<16 x i8>* [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 1, i32 17, i32 3, i32 19, i32 5, i32 21, i32 7, i32 23, i32 9, i32 25, i32 11, i32 27, i32 13, i32 29, i32 15, i32 31>
end_comment

begin_comment
comment|// CHECK:   store<16 x i8> [[VTRN1_I]],<16 x i8>* [[TMP2]]
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast %struct.poly8x16x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast %struct.poly8x16x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP3]], i8* [[TMP4]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load %struct.poly8x16x2_t, %struct.poly8x16x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = getelementptr inbounds %struct.poly8x16x2_t, %struct.poly8x16x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = extractvalue %struct.poly8x16x2_t [[TMP5]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<16 x i8>] [[TMP7]], [2 x<16 x i8>]* [[TMP6]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load %struct.poly8x16x2_t, %struct.poly8x16x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly8x16x2_t [[TMP8]]
end_comment

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
return|return
name|vtrnq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vtrnq_p16(
end_comment

begin_comment
comment|// CHECK:   [[RETVAL_I:%.*]] = alloca %struct.poly16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[__RET_I:%.*]] = alloca %struct.poly16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[RETVAL:%.*]] = alloca %struct.poly16x8x2_t, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast %struct.poly16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i8* [[TMP0]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[VTRN_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VTRN_I]],<8 x i16>* [[TMP3]]
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = getelementptr inbounds<8 x i16>,<8 x i16>* [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VTRN1_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %b,<8 x i32><i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VTRN1_I]],<8 x i16>* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast %struct.poly16x8x2_t* [[RETVAL_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast %struct.poly16x8x2_t* [[__RET_I]] to i8*
end_comment

begin_comment
comment|// CHECK:   call void @llvm.memcpy.p0i8.p0i8.i64(i8* [[TMP5]], i8* [[TMP6]], i64 32, i32 16, i1 false) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = load %struct.poly16x8x2_t, %struct.poly16x8x2_t* [[RETVAL_I]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = getelementptr inbounds %struct.poly16x8x2_t, %struct.poly16x8x2_t* [[RETVAL]], i32 0, i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP9:%.*]] = extractvalue %struct.poly16x8x2_t [[TMP7]], 0
end_comment

begin_comment
comment|// CHECK:   store [2 x<8 x i16>] [[TMP9]], [2 x<8 x i16>]* [[TMP8]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP10:%.*]] = load %struct.poly16x8x2_t, %struct.poly16x8x2_t* [[RETVAL]], align 16
end_comment

begin_comment
comment|// CHECK:   ret %struct.poly16x8x2_t [[TMP10]]
end_comment

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
return|return
name|vtrnq_p16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

