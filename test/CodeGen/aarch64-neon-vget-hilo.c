begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:  -fallow-half-arguments-and-returns -disable-O0-optnone -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN: | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK-LABEL: define<8 x i8> @test_vget_high_s8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|int8x8_t
name|test_vget_high_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vget_high_s16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|int16x4_t
name|test_vget_high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vget_high_s32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

begin_function
name|int32x2_t
name|test_vget_high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vget_high_s64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32><i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|int64x1_t
name|test_vget_high_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vget_high_u8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vget_high_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vget_high_u16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vget_high_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vget_high_u32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vget_high_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vget_high_u64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32><i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vget_high_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vget_high_p64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32><i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|poly64x1_t
name|test_vget_high_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x half> @test_vget_high_f16(<8 x half> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x half> %a,<8 x half> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x half> [[SHUFFLE_I]]
end_comment

begin_function
name|float16x4_t
name|test_vget_high_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vget_high_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SHUFFLE_I]]
end_comment

begin_function
name|float32x2_t
name|test_vget_high_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vget_high_p8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|poly8x8_t
name|test_vget_high_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vget_high_p16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|poly16x4_t
name|test_vget_high_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vget_high_f64(<2 x double> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x double> %a,<2 x double> %a,<1 x i32><i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[SHUFFLE_I]]
end_comment

begin_function
name|float64x1_t
name|test_vget_high_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_high_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vget_low_s8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|int8x8_t
name|test_vget_low_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vget_low_s16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|int16x4_t
name|test_vget_low_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vget_low_s32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

begin_function
name|int32x2_t
name|test_vget_low_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vget_low_s64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|int64x1_t
name|test_vget_low_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vget_low_u8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vget_low_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vget_low_u16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vget_low_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vget_low_u32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vget_low_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vget_low_u64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vget_low_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vget_low_p64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[SHUFFLE_I]]
end_comment

begin_function
name|poly64x1_t
name|test_vget_low_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x half> @test_vget_low_f16(<8 x half> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x half> %a,<8 x half> %a,<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x half> [[SHUFFLE_I]]
end_comment

begin_function
name|float16x4_t
name|test_vget_low_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vget_low_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %a,<2 x i32><i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SHUFFLE_I]]
end_comment

begin_function
name|float32x2_t
name|test_vget_low_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vget_low_p8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|poly8x8_t
name|test_vget_low_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vget_low_p16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|poly16x4_t
name|test_vget_low_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vget_low_f64(<2 x double> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x double> %a,<2 x double> %a,<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[SHUFFLE_I]]
end_comment

begin_function
name|float64x1_t
name|test_vget_low_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vget_low_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

