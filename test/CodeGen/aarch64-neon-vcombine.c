begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon -fallow-half-arguments-and-returns -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK-LABEL: define<16 x i8> @test_vcombine_s8(<8 x i8> %low,<8 x i8> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %low,<8 x i8> %high,<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_s8
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vcombine_s16(<4 x i16> %low,<4 x i16> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %low,<4 x i16> %high,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_s16
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vcombine_s32(<2 x i32> %low,<2 x i32> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %low,<2 x i32> %high,<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_s32
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcombine_s64(<1 x i64> %low,<1 x i64> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<1 x i64> %low,<1 x i64> %high,<2 x i32><i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_s64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vcombine_u8(<8 x i8> %low,<8 x i8> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %low,<8 x i8> %high,<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_u8
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vcombine_u16(<4 x i16> %low,<4 x i16> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %low,<4 x i16> %high,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_u16
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vcombine_u32(<2 x i32> %low,<2 x i32> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %low,<2 x i32> %high,<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_u32
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcombine_u64(<1 x i64> %low,<1 x i64> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<1 x i64> %low,<1 x i64> %high,<2 x i32><i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_u64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcombine_p64(<1 x i64> %low,<1 x i64> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<1 x i64> %low,<1 x i64> %high,<2 x i32><i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_p64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x half> @test_vcombine_f16(<4 x half> %low,<4 x half> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x half> %low,<4 x half> %high,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x half> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_f16
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vcombine_f32(<2 x float> %low,<2 x float> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x float> %low,<2 x float> %high,<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_f32
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vcombine_p8(<8 x i8> %low,<8 x i8> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %low,<8 x i8> %high,<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_p8
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vcombine_p16(<4 x i16> %low,<4 x i16> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %low,<4 x i16> %high,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_p16
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vcombine_f64(<1 x double> %low,<1 x double> %high) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<1 x double> %low,<1 x double> %high,<2 x i32><i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SHUFFLE_I]]
end_comment

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
return|return
name|vcombine_f64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
block|}
end_function

end_unit

