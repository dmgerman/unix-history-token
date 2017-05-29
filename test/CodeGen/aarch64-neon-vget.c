begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-darwin -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -fallow-half-arguments-and-returns -disable-O0-optnone -emit-llvm -o - %s \
end_comment

begin_comment
comment|// RUN: | opt -S -mem2reg | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: define i8 @test_vget_lane_u8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<8 x i8> %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGET_LANE]]
end_comment

begin_function
name|uint8_t
name|test_vget_lane_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i16 @test_vget_lane_u16(<4 x i16> %a) #0 {
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
name|test_vget_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i32 @test_vget_lane_u32(<2 x i32> %a) #0 {
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
name|test_vget_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i8 @test_vget_lane_s8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<8 x i8> %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGET_LANE]]
end_comment

begin_function
name|int8_t
name|test_vget_lane_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i16 @test_vget_lane_s16(<4 x i16> %a) #0 {
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
name|test_vget_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i32 @test_vget_lane_s32(<2 x i32> %a) #0 {
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
name|test_vget_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i8 @test_vget_lane_p8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<8 x i8> %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGET_LANE]]
end_comment

begin_function
name|poly8_t
name|test_vget_lane_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i16 @test_vget_lane_p16(<4 x i16> %a) #0 {
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
name|test_vget_lane_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define float @test_vget_lane_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<2 x float> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   ret float [[VGET_LANE]]
end_comment

begin_function
name|float32_t
name|test_vget_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define float @test_vget_lane_f16(<4 x half> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[__REINT_242:%.*]] = alloca<4 x half>, align 8
end_comment

begin_comment
comment|// CHECK:   [[__REINT1_242:%.*]] = alloca i16, align 2
end_comment

begin_comment
comment|// CHECK:   store<4 x half> %a,<4 x half>* [[__REINT_242]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x half>* [[__REINT_242]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load<4 x i16>,<4 x i16>* [[TMP0]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[TMP1]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<4 x i16> [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   store i16 [[VGET_LANE]], i16* [[__REINT1_242]], align 2
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast i16* [[__REINT1_242]] to half*
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load half, half* [[TMP4]], align 2
end_comment

begin_comment
comment|// CHECK:   [[CONV:%.*]] = fpext half [[TMP5]] to float
end_comment

begin_comment
comment|// CHECK:   ret float [[CONV]]
end_comment

begin_function
name|float32_t
name|test_vget_lane_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i8 @test_vgetq_lane_u8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<16 x i8> %a, i32 15
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGETQ_LANE]]
end_comment

begin_function
name|uint8_t
name|test_vgetq_lane_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i16 @test_vgetq_lane_u16(<8 x i16> %a) #0 {
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
name|test_vgetq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i32 @test_vgetq_lane_u32(<4 x i32> %a) #0 {
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
name|test_vgetq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i8 @test_vgetq_lane_s8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<16 x i8> %a, i32 15
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGETQ_LANE]]
end_comment

begin_function
name|int8_t
name|test_vgetq_lane_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i16 @test_vgetq_lane_s16(<8 x i16> %a) #0 {
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
name|test_vgetq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i32 @test_vgetq_lane_s32(<4 x i32> %a) #0 {
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
name|test_vgetq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i8 @test_vgetq_lane_p8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<16 x i8> %a, i32 15
end_comment

begin_comment
comment|// CHECK:   ret i8 [[VGETQ_LANE]]
end_comment

begin_function
name|poly8_t
name|test_vgetq_lane_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i16 @test_vgetq_lane_p16(<8 x i16> %a) #0 {
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
name|test_vgetq_lane_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define float @test_vgetq_lane_f32(<4 x float> %a) #0 {
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
name|test_vgetq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define float @test_vgetq_lane_f16(<8 x half> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[__REINT_244:%.*]] = alloca<8 x half>, align 16
end_comment

begin_comment
comment|// CHECK:   [[__REINT1_244:%.*]] = alloca i16, align 2
end_comment

begin_comment
comment|// CHECK:   store<8 x half> %a,<8 x half>* [[__REINT_244]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x half>* [[__REINT_244]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = load<8 x i16>,<8 x i16>* [[TMP0]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i16> [[TMP1]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<8 x i16> [[TMP3]], i32 3
end_comment

begin_comment
comment|// CHECK:   store i16 [[VGETQ_LANE]], i16* [[__REINT1_244]], align 2
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast i16* [[__REINT1_244]] to half*
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = load half, half* [[TMP4]], align 2
end_comment

begin_comment
comment|// CHECK:   [[CONV:%.*]] = fpext half [[TMP5]] to float
end_comment

begin_comment
comment|// CHECK:   ret float [[CONV]]
end_comment

begin_function
name|float32_t
name|test_vgetq_lane_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i64 @test_vget_lane_s64(<1 x i64> %a) #0 {
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
name|test_vget_lane_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i64 @test_vget_lane_u64(<1 x i64> %a) #0 {
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
name|test_vget_lane_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i64 @test_vgetq_lane_s64(<2 x i64> %a) #0 {
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
name|test_vgetq_lane_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define i64 @test_vgetq_lane_u64(<2 x i64> %a) #0 {
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
name|test_vgetq_lane_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
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

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vset_lane_u8(i8 %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<8 x i8> %b, i8 %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vset_lane_u16(i16 %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x i16> [[TMP1]], i16 %a, i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vset_lane_u32(i32 %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x i32> [[TMP1]], i32 %a, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vset_lane_s8(i8 %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<8 x i8> %b, i8 %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vset_lane_s16(i16 %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x i16> [[TMP1]], i16 %a, i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vset_lane_s32(i32 %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x i32> [[TMP1]], i32 %a, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vset_lane_p8(i8 %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<8 x i8> %b, i8 %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vset_lane_p16(i16 %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x i16> [[TMP1]], i16 %a, i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vset_lane_f32(float %a,<2 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x float> [[TMP1]], float %a, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<4 x half> @test_vset_lane_f16(half* %a,<4 x half> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[__REINT_246:%.*]] = alloca half, align 2
end_comment

begin_comment
comment|// CHECK:   [[__REINT1_246:%.*]] = alloca<4 x half>, align 8
end_comment

begin_comment
comment|// CHECK:   [[__REINT2_246:%.*]] = alloca<4 x i16>, align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load half, half* %a, align 2
end_comment

begin_comment
comment|// CHECK:   store half [[TMP0]], half* [[__REINT_246]], align 2
end_comment

begin_comment
comment|// CHECK:   store<4 x half> %b,<4 x half>* [[__REINT1_246]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast half* [[__REINT_246]] to i16*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load i16, i16* [[TMP1]], align 2
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<4 x half>* [[__REINT1_246]] to<4 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load<4 x i16>,<4 x i16>* [[TMP3]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<4 x i16> [[TMP4]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<8 x i8> [[TMP5]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x i16> [[TMP6]], i16 [[TMP2]], i32 3
end_comment

begin_comment
comment|// CHECK:   store<4 x i16> [[VSET_LANE]],<4 x i16>* [[__REINT2_246]], align 8
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = bitcast<4 x i16>* [[__REINT2_246]] to<4 x half>*
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load<4 x half>,<4 x half>* [[TMP7]], align 8
end_comment

begin_comment
comment|// CHECK:   ret<4 x half> [[TMP8]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vsetq_lane_u8(i8 %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<16 x i8> %b, i8 %a, i32 15
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vsetq_lane_u16(i16 %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<8 x i16> [[TMP1]], i16 %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vsetq_lane_u32(i32 %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x i32> [[TMP1]], i32 %a, i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vsetq_lane_s8(i8 %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<16 x i8> %b, i8 %a, i32 15
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vsetq_lane_s16(i16 %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<8 x i16> [[TMP1]], i16 %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vsetq_lane_s32(i32 %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x i32> [[TMP1]], i32 %a, i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vsetq_lane_p8(i8 %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<16 x i8> %b, i8 %a, i32 15
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vsetq_lane_p16(i16 %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<8 x i16> [[TMP1]], i16 %a, i32 7
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vsetq_lane_f32(float %a,<4 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<4 x float> [[TMP1]], float %a, i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<8 x half> @test_vsetq_lane_f16(half* %a,<8 x half> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[__REINT_248:%.*]] = alloca half, align 2
end_comment

begin_comment
comment|// CHECK:   [[__REINT1_248:%.*]] = alloca<8 x half>, align 16
end_comment

begin_comment
comment|// CHECK:   [[__REINT2_248:%.*]] = alloca<8 x i16>, align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load half, half* %a, align 2
end_comment

begin_comment
comment|// CHECK:   store half [[TMP0]], half* [[__REINT_248]], align 2
end_comment

begin_comment
comment|// CHECK:   store<8 x half> %b,<8 x half>* [[__REINT1_248]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast half* [[__REINT_248]] to i16*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load i16, i16* [[TMP1]], align 2
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x half>* [[__REINT1_248]] to<8 x i16>*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = load<8 x i16>,<8 x i16>* [[TMP3]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<8 x i16> [[TMP4]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<16 x i8> [[TMP5]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<8 x i16> [[TMP6]], i16 [[TMP2]], i32 7
end_comment

begin_comment
comment|// CHECK:   store<8 x i16> [[VSET_LANE]],<8 x i16>* [[__REINT2_248]], align 16
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = bitcast<8 x i16>* [[__REINT2_248]] to<8 x half>*
end_comment

begin_comment
comment|// CHECK:   [[TMP8:%.*]] = load<8 x half>,<8 x half>* [[TMP7]], align 16
end_comment

begin_comment
comment|// CHECK:   ret<8 x half> [[TMP8]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vset_lane_s64(i64 %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<1 x i64> [[TMP1]], i64 %a, i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vset_lane_u64(i64 %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<1 x i64> [[TMP1]], i64 %a, i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vsetq_lane_s64(i64 %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x i64> [[TMP1]], i64 %a, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSET_LANE]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vsetq_lane_u64(i64 %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<2 x i64> [[TMP1]], i64 %a, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSET_LANE]]
end_comment

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

