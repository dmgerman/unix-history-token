begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN: -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: define float @test_vdups_lane_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VDUPS_LANE:%.*]] = extractelement<2 x float> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret float [[VDUPS_LANE]]
end_comment

begin_function
name|float32_t
name|test_vdups_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdups_lane_f32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @test_vdupd_lane_f64(<1 x double> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VDUPD_LANE:%.*]] = extractelement<1 x double> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret double [[VDUPD_LANE]]
end_comment

begin_function
name|float64_t
name|test_vdupd_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_lane_f64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vdups_laneq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x float> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret float [[VGETQ_LANE]]
end_comment

begin_function
name|float32_t
name|test_vdups_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vdups_laneq_f32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @test_vdupd_laneq_f64(<2 x double> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x double> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret double [[VGETQ_LANE]]
end_comment

begin_function
name|float64_t
name|test_vdupd_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_laneq_f64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vdupb_lane_s8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<8 x i8> %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGET_LANE]]
end_comment

begin_function
name|int8_t
name|test_vdupb_lane_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_lane_s8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vduph_lane_s16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<4 x i16> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret i16 [[VGET_LANE]]
end_comment

begin_function
name|int16_t
name|test_vduph_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vduph_lane_s16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vdups_lane_s32(<2 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<2 x i32> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VGET_LANE]]
end_comment

begin_function
name|int32_t
name|test_vdups_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdups_lane_s32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vdupd_lane_s64(<1 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x i64> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VGET_LANE]]
end_comment

begin_function
name|int64_t
name|test_vdupd_lane_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_lane_s64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vdupb_lane_u8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<8 x i8> %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGET_LANE]]
end_comment

begin_function
name|uint8_t
name|test_vdupb_lane_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_lane_u8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vduph_lane_u16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<4 x i16> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret i16 [[VGET_LANE]]
end_comment

begin_function
name|uint16_t
name|test_vduph_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vduph_lane_u16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vdups_lane_u32(<2 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<2 x i32> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VGET_LANE]]
end_comment

begin_function
name|uint32_t
name|test_vdups_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vdups_lane_u32
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vdupd_lane_u64(<1 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x i64> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VGET_LANE]]
end_comment

begin_function
name|uint64_t
name|test_vdupd_lane_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_lane_u64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vdupb_laneq_s8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<16 x i8> %a, i32 15
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGETQ_LANE]]
end_comment

begin_function
name|int8_t
name|test_vdupb_laneq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_laneq_s8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vduph_laneq_s16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   ret i16 [[VGETQ_LANE]]
end_comment

begin_function
name|int16_t
name|test_vduph_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vduph_laneq_s16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vdups_laneq_s32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x i32> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VGETQ_LANE]]
end_comment

begin_function
name|int32_t
name|test_vdups_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vdups_laneq_s32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vdupd_laneq_s64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x i64> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VGETQ_LANE]]
end_comment

begin_function
name|int64_t
name|test_vdupd_laneq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_laneq_s64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vdupb_laneq_u8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<16 x i8> %a, i32 15
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGETQ_LANE]]
end_comment

begin_function
name|uint8_t
name|test_vdupb_laneq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_laneq_u8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vduph_laneq_u16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   ret i16 [[VGETQ_LANE]]
end_comment

begin_function
name|uint16_t
name|test_vduph_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vduph_laneq_u16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vdups_laneq_u32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x i32> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VGETQ_LANE]]
end_comment

begin_function
name|uint32_t
name|test_vdups_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vdups_laneq_u32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vdupd_laneq_u64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x i64> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VGETQ_LANE]]
end_comment

begin_function
name|uint64_t
name|test_vdupd_laneq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vdupd_laneq_u64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vdupb_lane_p8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<8 x i8> %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGET_LANE]]
end_comment

begin_function
name|poly8_t
name|test_vdupb_lane_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_lane_p8
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vduph_lane_p16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<4 x i16> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret i16 [[VGET_LANE]]
end_comment

begin_function
name|poly16_t
name|test_vduph_lane_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vduph_lane_p16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vdupb_laneq_p8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<16 x i8> %a, i32 15
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGETQ_LANE]]
end_comment

begin_function
name|poly8_t
name|test_vdupb_laneq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vdupb_laneq_p8
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vduph_laneq_p16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   ret i16 [[VGETQ_LANE]]
end_comment

begin_function
name|poly16_t
name|test_vduph_laneq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vduph_laneq_p16
argument_list|(
name|a
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

end_unit

