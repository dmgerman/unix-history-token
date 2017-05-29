begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple aarch64_be-linux-gnu -target-feature +neon -ffreestanding -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s --check-prefix CHECK-BE
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int8_t
name|test_vdupb_lane_s8
parameter_list|(
name|int8x8_t
name|src
parameter_list|)
block|{
return|return
name|vdupb_lane_s8
argument_list|(
name|src
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vdupb_lane_s8
comment|// CHECK: extractelement<8 x i8> %src, i32 2
comment|// CHECK-BE-LABEL: @test_vdupb_lane_s8
comment|// CHECK-BE: [[REV:%.*]] = shufflevector<8 x i8> {{.*}},<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-BE: extractelement<8 x i8> [[REV]], i32 2
block|}
end_function

begin_function
name|uint8_t
name|test_vdupb_lane_u8
parameter_list|(
name|uint8x8_t
name|src
parameter_list|)
block|{
return|return
name|vdupb_lane_u8
argument_list|(
name|src
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vdupb_lane_u8
comment|// CHECK: extractelement<8 x i8> %src, i32 2
comment|// CHECK-BE-LABEL: @test_vdupb_lane_u8
comment|// CHECK-BE: [[REV:%.*]] = shufflevector<8 x i8> {{.*}},<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-BE: extractelement<8 x i8> [[REV]], i32 2
block|}
end_function

begin_function
name|int16_t
name|test_vduph_lane_s16
parameter_list|(
name|int16x4_t
name|src
parameter_list|)
block|{
return|return
name|vduph_lane_s16
argument_list|(
name|src
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vduph_lane_s16
comment|// CHECK: [[TMP1:%.*]] = bitcast<4 x i16> %src to [[TYPE:.*]]
comment|// CHECK: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<4 x i16>
comment|// CHECK: extractelement<4 x i16> [[TMP2]], i32 2
comment|// CHECK-BE-LABEL: @test_vduph_lane_s16
comment|// CHECK-BE: [[REV:%.*]] = shufflevector<4 x i16> {{.*}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-BE: [[TMP1:%.*]] = bitcast<4 x i16> [[REV]] to [[TYPE:.*]]
comment|// CHECK-BE: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<4 x i16>
comment|// CHECK-BE: extractelement<4 x i16> [[TMP2]], i32 2
block|}
end_function

begin_function
name|uint16_t
name|test_vduph_lane_u16
parameter_list|(
name|uint16x4_t
name|src
parameter_list|)
block|{
return|return
name|vduph_lane_u16
argument_list|(
name|src
argument_list|,
literal|2
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vduph_lane_u16
comment|// CHECK: [[TMP1:%.*]] = bitcast<4 x i16> %src to [[TYPE:.*]]
comment|// CHECK: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<4 x i16>
comment|// CHECK: extractelement<4 x i16> [[TMP2]], i32 2
comment|// CHECK-BE-LABEL: @test_vduph_lane_u16
comment|// CHECK-BE: [[REV:%.*]] = shufflevector<4 x i16> {{.*}},<4 x i32><i32 3, i32 2, i32 1, i32 0>
comment|// CHECK-BE: [[TMP1:%.*]] = bitcast<4 x i16> [[REV]] to [[TYPE:.*]]
comment|// CHECK-BE: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<4 x i16>
comment|// CHECK-BE: extractelement<4 x i16> [[TMP2]], i32 2
block|}
end_function

begin_function
name|int32_t
name|test_vdups_lane_s32
parameter_list|(
name|int32x2_t
name|src
parameter_list|)
block|{
return|return
name|vdups_lane_s32
argument_list|(
name|src
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vdups_lane_s32
comment|// CHECK: [[TMP1:%.*]] = bitcast<2 x i32> %src to [[TYPE:.*]]
comment|// CHECK: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<2 x i32>
comment|// CHECK: extractelement<2 x i32> [[TMP2]], i32 0
comment|// CHECK-BE-LABEL: @test_vdups_lane_s32
comment|// CHECK-BE: [[REV:%.*]] = shufflevector<2 x i32> {{.*}},<2 x i32><i32 1, i32 0>
comment|// CHECK-BE: [[TMP1:%.*]] = bitcast<2 x i32> [[REV]] to [[TYPE:.*]]
comment|// CHECK-BE: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<2 x i32>
comment|// CHECK-BE: extractelement<2 x i32> [[TMP2]], i32 0
block|}
end_function

begin_function
name|uint32_t
name|test_vdups_lane_u32
parameter_list|(
name|uint32x2_t
name|src
parameter_list|)
block|{
return|return
name|vdups_lane_u32
argument_list|(
name|src
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vdups_lane_u32
comment|// CHECK: [[TMP1:%.*]] = bitcast<2 x i32> %src to [[TYPE:.*]]
comment|// CHECK: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<2 x i32>
comment|// CHECK: extractelement<2 x i32> [[TMP2]], i32 0
comment|// CHECK-BE-LABEL: @test_vdups_lane_u32
comment|// CHECK-BE: [[REV:%.*]] = shufflevector<2 x i32> {{.*}},<2 x i32><i32 1, i32 0>
comment|// CHECK-BE: [[TMP1:%.*]] = bitcast<2 x i32> [[REV]] to [[TYPE:.*]]
comment|// CHECK-BE: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<2 x i32>
comment|// CHECK-BE: extractelement<2 x i32> [[TMP2]], i32 0
block|}
end_function

begin_function
name|float32_t
name|test_vdups_lane_f32
parameter_list|(
name|float32x2_t
name|src
parameter_list|)
block|{
return|return
name|vdups_lane_f32
argument_list|(
name|src
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vdups_lane_f32
comment|// CHECK: [[TMP1:%.*]] = bitcast<2 x float> %src to [[TYPE:.*]]
comment|// CHECK: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<2 x float>
comment|// CHECK: extractelement<2 x float> [[TMP2]], i32 0
comment|// CHECK-BE-LABEL: @test_vdups_lane_f32
comment|// CHECK-BE: [[REV:%.*]] = shufflevector<2 x float> {{.*}},<2 x i32><i32 1, i32 0>
comment|// CHECK-BE: [[TMP1:%.*]] = bitcast<2 x float> [[REV]] to [[TYPE:.*]]
comment|// CHECK-BE: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<2 x float>
comment|// CHECK-BE: extractelement<2 x float> [[TMP2]], i32 0
block|}
end_function

begin_function
name|int64_t
name|test_vdupd_lane_s64
parameter_list|(
name|int64x1_t
name|src
parameter_list|)
block|{
return|return
name|vdupd_lane_s64
argument_list|(
name|src
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vdupd_lane_s64
comment|// CHECK: [[TMP1:%.*]] = bitcast<1 x i64> %src to [[TYPE:.*]]
comment|// CHECK: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<1 x i64>
comment|// CHECK: extractelement<1 x i64> [[TMP2]], i32 0
comment|// CHECK-BE-LABEL: @test_vdupd_lane_s64
comment|// CHECK-BE: extractelement<1 x i64> {{.*}}, i32 0
block|}
end_function

begin_function
name|uint64_t
name|test_vdupd_lane_u64
parameter_list|(
name|uint64x1_t
name|src
parameter_list|)
block|{
return|return
name|vdupd_lane_u64
argument_list|(
name|src
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vdupd_lane_u64
comment|// CHECK: [[TMP1:%.*]] = bitcast<1 x i64> %src to [[TYPE:.*]]
comment|// CHECK: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<1 x i64>
comment|// CHECK: extractelement<1 x i64> [[TMP2]], i32 0
comment|// CHECK-BE-LABEL: @test_vdupd_lane_u64
comment|// CHECK-BE: extractelement<1 x i64> {{.*}}, i32 0
block|}
end_function

begin_function
name|float64_t
name|test_vdupd_lane_f64
parameter_list|(
name|float64x1_t
name|src
parameter_list|)
block|{
return|return
name|vdupd_lane_f64
argument_list|(
name|src
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK-LABEL: @test_vdupd_lane_f64
comment|// CHECK: [[TMP1:%.*]] = bitcast<1 x double> %src to [[TYPE:.*]]
comment|// CHECK: [[TMP2:%.*]] = bitcast [[TYPE]] [[TMP1]] to<1 x double>
comment|// CHECK: extractelement<1 x double> [[TMP2]], i32 0
comment|// CHECK-BE-LABEL: @test_vdupd_lane_f64
comment|// CHECK-BE: extractelement<1 x double> {{.*}}, i32 0
block|}
end_function

end_unit

