begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:  -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK-LABEL: define<8 x i8> @test_vext_s8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VEXT]]
end_comment

begin_function
name|int8x8_t
name|test_vext_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vext_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vext_s16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<4 x i16> [[TMP2]],<4 x i16> [[TMP3]],<4 x i32><i32 3, i32 4, i32 5, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VEXT]]
end_comment

begin_function
name|int16x4_t
name|test_vext_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vext_s16
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

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vext_s32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<2 x i32> [[TMP2]],<2 x i32> [[TMP3]],<2 x i32><i32 1, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VEXT]]
end_comment

begin_function
name|int32x2_t
name|test_vext_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vext_s32
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

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vext_s64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x i64> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<1 x i64> [[TMP2]],<1 x i64> [[TMP3]],<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VEXT]]
end_comment

begin_function
name|int64x1_t
name|test_vext_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vext_s64
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

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vextq_s8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VEXT]]
end_comment

begin_function
name|int8x16_t
name|test_vextq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vextq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vextq_s16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<8 x i16> [[TMP2]],<8 x i16> [[TMP3]],<8 x i32><i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VEXT]]
end_comment

begin_function
name|int16x8_t
name|test_vextq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vextq_s16
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

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vextq_s32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<4 x i32> [[TMP2]],<4 x i32> [[TMP3]],<4 x i32><i32 1, i32 2, i32 3, i32 4>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VEXT]]
end_comment

begin_function
name|int32x4_t
name|test_vextq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vextq_s32
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

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vextq_s64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<2 x i64> [[TMP2]],<2 x i64> [[TMP3]],<2 x i32><i32 1, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VEXT]]
end_comment

begin_function
name|int64x2_t
name|test_vextq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vextq_s64
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

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vext_u8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VEXT]]
end_comment

begin_function
name|uint8x8_t
name|test_vext_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vext_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vext_u16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<4 x i16> [[TMP2]],<4 x i16> [[TMP3]],<4 x i32><i32 3, i32 4, i32 5, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VEXT]]
end_comment

begin_function
name|uint16x4_t
name|test_vext_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vext_u16
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

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vext_u32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<2 x i32> [[TMP2]],<2 x i32> [[TMP3]],<2 x i32><i32 1, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VEXT]]
end_comment

begin_function
name|uint32x2_t
name|test_vext_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vext_u32
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

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vext_u64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x i64> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<1 x i64> [[TMP2]],<1 x i64> [[TMP3]],<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VEXT]]
end_comment

begin_function
name|uint64x1_t
name|test_vext_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vext_u64
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

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vextq_u8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VEXT]]
end_comment

begin_function
name|uint8x16_t
name|test_vextq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vextq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vextq_u16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<8 x i16> [[TMP2]],<8 x i16> [[TMP3]],<8 x i32><i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VEXT]]
end_comment

begin_function
name|uint16x8_t
name|test_vextq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vextq_u16
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

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vextq_u32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<4 x i32> [[TMP2]],<4 x i32> [[TMP3]],<4 x i32><i32 1, i32 2, i32 3, i32 4>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VEXT]]
end_comment

begin_function
name|uint32x4_t
name|test_vextq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vextq_u32
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

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vextq_u64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<2 x i64> [[TMP2]],<2 x i64> [[TMP3]],<2 x i32><i32 1, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VEXT]]
end_comment

begin_function
name|uint64x2_t
name|test_vextq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vextq_u64
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

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vext_f32(<2 x float> %a,<2 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<2 x float> [[TMP2]],<2 x float> [[TMP3]],<2 x i32><i32 1, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VEXT]]
end_comment

begin_function
name|float32x2_t
name|test_vext_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vext_f32
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

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vext_f64(<1 x double> %a,<1 x double> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x double> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<1 x double> [[TMP2]],<1 x double> [[TMP3]],<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[VEXT]]
end_comment

begin_function
name|float64x1_t
name|test_vext_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
return|return
name|vext_f64
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

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vextq_f32(<4 x float> %a,<4 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<4 x float> [[TMP2]],<4 x float> [[TMP3]],<4 x i32><i32 1, i32 2, i32 3, i32 4>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VEXT]]
end_comment

begin_function
name|float32x4_t
name|test_vextq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vextq_f32
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

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vextq_f64(<2 x double> %a,<2 x double> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<2 x double> [[TMP2]],<2 x double> [[TMP3]],<2 x i32><i32 1, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VEXT]]
end_comment

begin_function
name|float64x2_t
name|test_vextq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
return|return
name|vextq_f64
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

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vext_p8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %b,<8 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VEXT]]
end_comment

begin_function
name|poly8x8_t
name|test_vext_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|,
name|poly8x8_t
name|b
parameter_list|)
block|{
return|return
name|vext_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vext_p16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<4 x i16> [[TMP2]],<4 x i16> [[TMP3]],<4 x i32><i32 3, i32 4, i32 5, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VEXT]]
end_comment

begin_function
name|poly16x4_t
name|test_vext_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|,
name|poly16x4_t
name|b
parameter_list|)
block|{
return|return
name|vext_p16
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

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vextq_p8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %b,<16 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VEXT]]
end_comment

begin_function
name|poly8x16_t
name|test_vextq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|,
name|poly8x16_t
name|b
parameter_list|)
block|{
return|return
name|vextq_p8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vextq_p16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VEXT:%.*]] = shufflevector<8 x i16> [[TMP2]],<8 x i16> [[TMP3]],<8 x i32><i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VEXT]]
end_comment

begin_function
name|poly16x8_t
name|test_vextq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|,
name|poly16x8_t
name|b
parameter_list|)
block|{
return|return
name|vextq_p16
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

end_unit

