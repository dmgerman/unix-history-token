begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -disable-O0-optnone -emit-llvm %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD copy vector element to vector element: vcopyq_lane*
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vcopyq_laneq_s8(<16 x i8> %a1,<16 x i8> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<16 x i8> %a2, i32 13
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<16 x i8> %a1, i8 [[VGETQ_LANE]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VSET_LANE]]
end_comment

begin_function
name|int8x16_t
name|test_vcopyq_laneq_s8
parameter_list|(
name|int8x16_t
name|a1
parameter_list|,
name|int8x16_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_s8
argument_list|(
name|a1
argument_list|,
operator|(
name|int64_t
operator|)
literal|3
argument_list|,
name|a2
argument_list|,
operator|(
name|int64_t
operator|)
literal|13
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vcopyq_laneq_u8(<16 x i8> %a1,<16 x i8> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<16 x i8> %a2, i32 13
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<16 x i8> %a1, i8 [[VGETQ_LANE]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VSET_LANE]]
end_comment

begin_function
name|uint8x16_t
name|test_vcopyq_laneq_u8
parameter_list|(
name|uint8x16_t
name|a1
parameter_list|,
name|uint8x16_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_u8
argument_list|(
name|a1
argument_list|,
operator|(
name|int64_t
operator|)
literal|3
argument_list|,
name|a2
argument_list|,
operator|(
name|int64_t
operator|)
literal|13
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vcopyq_laneq_s16(<8 x i16> %a1,<8 x i16> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a2 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %a1 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<8 x i16> [[TMP3]], i16 [[VGETQ_LANE]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VSET_LANE]]
end_comment

begin_function
name|int16x8_t
name|test_vcopyq_laneq_s16
parameter_list|(
name|int16x8_t
name|a1
parameter_list|,
name|int16x8_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_s16
argument_list|(
name|a1
argument_list|,
operator|(
name|int64_t
operator|)
literal|3
argument_list|,
name|a2
argument_list|,
operator|(
name|int64_t
operator|)
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vcopyq_laneq_u16(<8 x i16> %a1,<8 x i16> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a2 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> %a1 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<8 x i16> [[TMP3]], i16 [[VGETQ_LANE]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VSET_LANE]]
end_comment

begin_function
name|uint16x8_t
name|test_vcopyq_laneq_u16
parameter_list|(
name|uint16x8_t
name|a1
parameter_list|,
name|uint16x8_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_u16
argument_list|(
name|a1
argument_list|,
operator|(
name|int64_t
operator|)
literal|3
argument_list|,
name|a2
argument_list|,
operator|(
name|int64_t
operator|)
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vcopyq_laneq_s32(<4 x i32> %a1,<4 x i32> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a2 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x i32> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i32> %a1 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x i32> [[TMP3]], i32 [[VGETQ_LANE]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VSET_LANE]]
end_comment

begin_function
name|int32x4_t
name|test_vcopyq_laneq_s32
parameter_list|(
name|int32x4_t
name|a1
parameter_list|,
name|int32x4_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_s32
argument_list|(
name|a1
argument_list|,
operator|(
name|int64_t
operator|)
literal|3
argument_list|,
name|a2
argument_list|,
operator|(
name|int64_t
operator|)
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vcopyq_laneq_u32(<4 x i32> %a1,<4 x i32> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a2 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x i32> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i32> %a1 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x i32> [[TMP3]], i32 [[VGETQ_LANE]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VSET_LANE]]
end_comment

begin_function
name|uint32x4_t
name|test_vcopyq_laneq_u32
parameter_list|(
name|uint32x4_t
name|a1
parameter_list|,
name|uint32x4_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_u32
argument_list|(
name|a1
argument_list|,
operator|(
name|int64_t
operator|)
literal|3
argument_list|,
name|a2
argument_list|,
operator|(
name|int64_t
operator|)
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcopyq_laneq_s64(<2 x i64> %a1,<2 x i64> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a2 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x i64> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i64> %a1 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x i64> [[TMP3]], i64 [[VGETQ_LANE]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSET_LANE]]
end_comment

begin_function
name|int64x2_t
name|test_vcopyq_laneq_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|,
name|int64x2_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_s64
argument_list|(
name|a1
argument_list|,
operator|(
name|int64_t
operator|)
literal|0
argument_list|,
name|a2
argument_list|,
operator|(
name|int64_t
operator|)
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vcopyq_laneq_u64(<2 x i64> %a1,<2 x i64> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a2 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x i64> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i64> %a1 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x i64> [[TMP3]], i64 [[VGETQ_LANE]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSET_LANE]]
end_comment

begin_function
name|uint64x2_t
name|test_vcopyq_laneq_u64
parameter_list|(
name|uint64x2_t
name|a1
parameter_list|,
name|uint64x2_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_u64
argument_list|(
name|a1
argument_list|,
operator|(
name|int64_t
operator|)
literal|0
argument_list|,
name|a2
argument_list|,
operator|(
name|int64_t
operator|)
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vcopyq_laneq_f32(<4 x float> %a1,<4 x float> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a2 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x float> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %a1 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x float> [[TMP3]], float [[VGETQ_LANE]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VSET_LANE]]
end_comment

begin_function
name|float32x4_t
name|test_vcopyq_laneq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|,
name|float32x4_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_f32
argument_list|(
name|a1
argument_list|,
literal|0
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vcopyq_laneq_f64(<2 x double> %a1,<2 x double> %a2) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a2 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x double> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x double> %a1 to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x double> [[TMP3]], double [[VGETQ_LANE]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VSET_LANE]]
end_comment

begin_function
name|float64x2_t
name|test_vcopyq_laneq_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|)
block|{
return|return
name|vcopyq_laneq_f64
argument_list|(
name|a1
argument_list|,
literal|0
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

end_unit

