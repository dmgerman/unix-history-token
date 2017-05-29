begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK-LABEL: @test_vmla_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD]]
end_comment

begin_function
name|int16x4_t
name|test_vmla_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32><i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD]]
end_comment

begin_function
name|int16x8_t
name|test_vmlaq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD]]
end_comment

begin_function
name|int32x2_t
name|test_vmla_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlaq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD]]
end_comment

begin_function
name|int16x4_t
name|test_vmla_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32><i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD]]
end_comment

begin_function
name|int16x8_t
name|test_vmlaq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD]]
end_comment

begin_function
name|int32x2_t
name|test_vmla_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlaq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB]]
end_comment

begin_function
name|int16x4_t
name|test_vmls_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32><i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB]]
end_comment

begin_function
name|int16x8_t
name|test_vmlsq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB]]
end_comment

begin_function
name|int32x2_t
name|test_vmls_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB]]
end_comment

begin_function
name|int16x4_t
name|test_vmls_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32><i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB]]
end_comment

begin_function
name|int16x8_t
name|test_vmlsq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB]]
end_comment

begin_function
name|int32x2_t
name|test_vmls_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL]]
end_comment

begin_function
name|int16x4_t
name|test_vmul_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32><i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL]]
end_comment

begin_function
name|int16x8_t
name|test_vmulq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL]]
end_comment

begin_function
name|int32x2_t
name|test_vmul_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL]]
end_comment

begin_function
name|int32x4_t
name|test_vmulq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL]]
end_comment

begin_function
name|uint16x4_t
name|test_vmul_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32><i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL]]
end_comment

begin_function
name|uint16x8_t
name|test_vmulq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL]]
end_comment

begin_function
name|uint32x2_t
name|test_vmul_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL]]
end_comment

begin_function
name|uint32x4_t
name|test_vmulq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL]]
end_comment

begin_function
name|int16x4_t
name|test_vmul_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32><i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL]]
end_comment

begin_function
name|int16x8_t
name|test_vmulq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL]]
end_comment

begin_function
name|int32x2_t
name|test_vmul_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL]]
end_comment

begin_function
name|int32x4_t
name|test_vmulq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL]]
end_comment

begin_function
name|uint16x4_t
name|test_vmul_laneq_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32><i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL]]
end_comment

begin_function
name|uint16x8_t
name|test_vmulq_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL]]
end_comment

begin_function
name|uint32x2_t
name|test_vmul_laneq_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL]]
end_comment

begin_function
name|uint32x4_t
name|test_vmulq_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfma_lane_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x float> [[TMP3]],<2 x float> [[TMP3]],<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> [[FMLA]],<2 x float> [[LANE]],<2 x float> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[FMLA2]]
end_comment

begin_function
name|float32x2_t
name|test_vfma_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vfma_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmaq_lane_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x float> [[TMP3]],<2 x float> [[TMP3]],<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> [[FMLA]],<4 x float> [[LANE]],<4 x float> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[FMLA2]]
end_comment

begin_function
name|float32x4_t
name|test_vfmaq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vfmaq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfma_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<4 x float> [[TMP5]],<4 x float> [[TMP5]],<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> [[LANE]],<2 x float> [[TMP4]],<2 x float> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP6]]
end_comment

begin_function
name|float32x2_t
name|test_vfma_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfma_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmaq_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<4 x float> [[TMP5]],<4 x float> [[TMP5]],<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> [[LANE]],<4 x float> [[TMP4]],<4 x float> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP6]]
end_comment

begin_function
name|float32x4_t
name|test_vfmaq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfmaq_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfms_lane_f32(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x float><float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> [[SUB]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x float> [[TMP3]],<2 x float> [[TMP3]],<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> [[FMLA]],<2 x float> [[LANE]],<2 x float> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[FMLA2]]
end_comment

begin_function
name|float32x2_t
name|test_vfms_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vfms_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsq_lane_f32(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> [[SUB]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x float> [[TMP3]],<2 x float> [[TMP3]],<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> [[FMLA]],<4 x float> [[LANE]],<4 x float> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[FMLA2]]
end_comment

begin_function
name|float32x4_t
name|test_vfmsq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vfmsq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfms_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x float><float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> [[SUB]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<4 x float> [[TMP5]],<4 x float> [[TMP5]],<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> [[LANE]],<2 x float> [[TMP4]],<2 x float> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP6]]
end_comment

begin_function
name|float32x2_t
name|test_vfms_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfms_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsq_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> [[SUB]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<4 x float> [[TMP5]],<4 x float> [[TMP5]],<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> [[LANE]],<4 x float> [[TMP4]],<4 x float> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP6]]
end_comment

begin_function
name|float32x4_t
name|test_vfmsq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfmsq_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmaq_lane_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<1 x double> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<1 x double> [[TMP3]],<1 x double> [[TMP3]],<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<2 x double> @llvm.fma.v2f64(<2 x double> [[FMLA]],<2 x double> [[LANE]],<2 x double> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[FMLA2]]
end_comment

begin_function
name|float64x2_t
name|test_vfmaq_lane_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vfmaq_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmaq_laneq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x double> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x double> [[TMP5]],<2 x double> [[TMP5]],<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x double> @llvm.fma.v2f64(<2 x double> [[LANE]],<2 x double> [[TMP4]],<2 x double> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[TMP6]]
end_comment

begin_function
name|float64x2_t
name|test_vfmaq_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vfmaq_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsq_lane_f64(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> [[SUB]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<1 x double> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<1 x double> [[TMP3]],<1 x double> [[TMP3]],<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<2 x double> @llvm.fma.v2f64(<2 x double> [[FMLA]],<2 x double> [[LANE]],<2 x double> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[FMLA2]]
end_comment

begin_function
name|float64x2_t
name|test_vfmsq_lane_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vfmsq_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsq_laneq_f64(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> [[SUB]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x double> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x double> [[TMP5]],<2 x double> [[TMP5]],<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x double> @llvm.fma.v2f64(<2 x double> [[LANE]],<2 x double> [[TMP4]],<2 x double> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[TMP6]]
end_comment

begin_function
name|float64x2_t
name|test_vfmsq_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vfmsq_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmas_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<4 x float> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = call float @llvm.fma.f32(float %b, float [[EXTRACT]], float %a)
end_comment

begin_comment
comment|// CHECK:   ret float [[TMP2]]
end_comment

begin_function
name|float32_t
name|test_vfmas_laneq_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfmas_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsd_lane_f64(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub double -0.000000e+00, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<1 x double> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = call double @llvm.fma.f64(double [[SUB]], double [[EXTRACT]], double %a)
end_comment

begin_comment
comment|// CHECK:   ret double [[TMP2]]
end_comment

begin_function
name|float64_t
name|test_vfmsd_lane_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vfmsd_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmss_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub float -0.000000e+00, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<4 x float> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = call float @llvm.fma.f32(float [[SUB]], float [[EXTRACT]], float %a)
end_comment

begin_comment
comment|// CHECK:   ret float [[TMP2]]
end_comment

begin_function
name|float32_t
name|test_vfmss_laneq_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfmss_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsd_laneq_f64(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub double -0.000000e+00, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<2 x double> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = call double @llvm.fma.f64(double [[SUB]], double [[EXTRACT]], double %a)
end_comment

begin_comment
comment|// CHECK:   ret double [[TMP2]]
end_comment

begin_function
name|float64_t
name|test_vfmsd_laneq_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vfmsd_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_high_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_high_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_high_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_high_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_high_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_high_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_high_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_high_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_lane_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_lane_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_laneq_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_laneq_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_high_lane_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_high_lane_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_high_laneq_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_high_laneq_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_lane_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_lane_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_laneq_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_laneq_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_high_lane_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_high_lane_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_high_laneq_u16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_high_laneq_u32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmull_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmull_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_high_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_high_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_high_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_high_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmull_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_laneq_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmull_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_laneq_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_high_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_high_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_high_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_high_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_high_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_high_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_high_lane_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_high_lane_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_high_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_high_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_high_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_high_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_high_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_high_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V2_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqdmulh.v4i16(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast<4 x i16> [[VQDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQDMULH_V2_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqdmulh_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32><i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqdmulh.v8i16(<8 x i16> %a,<8 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast<8 x i16> [[VQDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQDMULHQ_V2_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqdmulhq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V2_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqdmulh.v2i32(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast<2 x i32> [[VQDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQDMULH_V2_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqdmulh_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmulh.v4i32(<4 x i32> %a,<4 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULHQ_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmulhq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V2_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqrdmulh.v4i16(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast<4 x i16> [[VQRDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQRDMULH_V2_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqrdmulh_lane_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_lane_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32><i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqrdmulh.v8i16(<8 x i16> %a,<8 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast<8 x i16> [[VQRDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQRDMULHQ_V2_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqrdmulhq_lane_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V2_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqrdmulh.v2i32(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast<2 x i32> [[VQRDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQRDMULH_V2_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqrdmulh_lane_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_lane_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqrdmulh.v4i32(<4 x i32> %a,<4 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast<4 x i32> [[VQRDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQRDMULHQ_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqrdmulhq_lane_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[MUL]]
end_comment

begin_function
name|float32x2_t
name|test_vmul_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x double> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to double
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP1]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<1 x double> [[TMP3]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = fmul double [[TMP2]], [[EXTRACT]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast double [[TMP4]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[TMP5]]
end_comment

begin_function
name|float64x1_t
name|test_vmul_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[MUL]]
end_comment

begin_function
name|float32x4_t
name|test_vmulq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<1 x double> %v,<1 x double> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x double> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[MUL]]
end_comment

begin_function
name|float64x2_t
name|test_vmulq_lane_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[MUL]]
end_comment

begin_function
name|float32x2_t
name|test_vmul_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to double
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<2 x double> [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = fmul double [[TMP2]], [[EXTRACT]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast double [[TMP4]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[TMP5]]
end_comment

begin_function
name|float64x1_t
name|test_vmul_laneq_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[MUL]]
end_comment

begin_function
name|float32x4_t
name|test_vmulq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x double> %v,<2 x double> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x double> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[MUL]]
end_comment

begin_function
name|float64x2_t
name|test_vmulq_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulx_lane_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<2 x float> @llvm.aarch64.neon.fmulx.v2f32(<2 x float> %a,<2 x float> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VMULX2_I]]
end_comment

begin_function
name|float32x2_t
name|test_vmulx_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulx_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulxq_lane_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<4 x float> @llvm.aarch64.neon.fmulx.v4f32(<4 x float> %a,<4 x float> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VMULX2_I]]
end_comment

begin_function
name|float32x4_t
name|test_vmulxq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulxq_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulxq_lane_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<1 x double> %v,<1 x double> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<2 x double> @llvm.aarch64.neon.fmulx.v2f64(<2 x double> %a,<2 x double> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VMULX2_I]]
end_comment

begin_function
name|float64x2_t
name|test_vmulxq_lane_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vmulxq_lane_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulx_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<2 x float> @llvm.aarch64.neon.fmulx.v2f32(<2 x float> %a,<2 x float> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VMULX2_I]]
end_comment

begin_function
name|float32x2_t
name|test_vmulx_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulx_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulxq_laneq_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<4 x float> @llvm.aarch64.neon.fmulx.v4f32(<4 x float> %a,<4 x float> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VMULX2_I]]
end_comment

begin_function
name|float32x4_t
name|test_vmulxq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulxq_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulxq_laneq_f64(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x double> %v,<2 x double> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<2 x double> @llvm.aarch64.neon.fmulx.v2f64(<2 x double> %a,<2 x double> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VMULX2_I]]
end_comment

begin_function
name|float64x2_t
name|test_vmulxq_laneq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulxq_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD]]
end_comment

begin_function
name|int16x4_t
name|test_vmla_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD]]
end_comment

begin_function
name|int16x8_t
name|test_vmlaq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD]]
end_comment

begin_function
name|int32x2_t
name|test_vmla_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlaq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD]]
end_comment

begin_function
name|int16x4_t
name|test_vmla_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD]]
end_comment

begin_function
name|int16x8_t
name|test_vmlaq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD]]
end_comment

begin_function
name|int32x2_t
name|test_vmla_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlaq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB]]
end_comment

begin_function
name|int16x4_t
name|test_vmls_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB]]
end_comment

begin_function
name|int16x8_t
name|test_vmlsq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB]]
end_comment

begin_function
name|int32x2_t
name|test_vmls_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB]]
end_comment

begin_function
name|int16x4_t
name|test_vmls_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB]]
end_comment

begin_function
name|int16x8_t
name|test_vmlsq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB]]
end_comment

begin_function
name|int32x2_t
name|test_vmls_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL]]
end_comment

begin_function
name|int16x4_t
name|test_vmul_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL]]
end_comment

begin_function
name|int16x8_t
name|test_vmulq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL]]
end_comment

begin_function
name|int32x2_t
name|test_vmul_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL]]
end_comment

begin_function
name|int32x4_t
name|test_vmulq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL]]
end_comment

begin_function
name|uint16x4_t
name|test_vmul_lane_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL]]
end_comment

begin_function
name|uint16x8_t
name|test_vmulq_lane_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL]]
end_comment

begin_function
name|uint32x2_t
name|test_vmul_lane_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL]]
end_comment

begin_function
name|uint32x4_t
name|test_vmulq_lane_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL]]
end_comment

begin_function
name|int16x4_t
name|test_vmul_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL]]
end_comment

begin_function
name|int16x8_t
name|test_vmulq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL]]
end_comment

begin_function
name|int32x2_t
name|test_vmul_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL]]
end_comment

begin_function
name|int32x4_t
name|test_vmulq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL]]
end_comment

begin_function
name|uint16x4_t
name|test_vmul_laneq_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL]]
end_comment

begin_function
name|uint16x8_t
name|test_vmulq_laneq_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL]]
end_comment

begin_function
name|uint32x2_t
name|test_vmul_laneq_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL]]
end_comment

begin_function
name|uint32x4_t
name|test_vmulq_laneq_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfma_lane_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x float> [[TMP3]],<2 x float> [[TMP3]],<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> [[FMLA]],<2 x float> [[LANE]],<2 x float> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[FMLA2]]
end_comment

begin_function
name|float32x2_t
name|test_vfma_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vfma_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmaq_lane_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x float> [[TMP3]],<2 x float> [[TMP3]],<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> [[FMLA]],<4 x float> [[LANE]],<4 x float> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[FMLA2]]
end_comment

begin_function
name|float32x4_t
name|test_vfmaq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vfmaq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfma_laneq_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<4 x float> [[TMP5]],<4 x float> [[TMP5]],<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> [[LANE]],<2 x float> [[TMP4]],<2 x float> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP6]]
end_comment

begin_function
name|float32x2_t
name|test_vfma_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfma_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmaq_laneq_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<4 x float> [[TMP5]],<4 x float> [[TMP5]],<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> [[LANE]],<4 x float> [[TMP4]],<4 x float> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP6]]
end_comment

begin_function
name|float32x4_t
name|test_vfmaq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfmaq_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfms_lane_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x float><float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> [[SUB]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x float> [[TMP3]],<2 x float> [[TMP3]],<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> [[FMLA]],<2 x float> [[LANE]],<2 x float> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[FMLA2]]
end_comment

begin_function
name|float32x2_t
name|test_vfms_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vfms_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsq_lane_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> [[SUB]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x float> [[TMP3]],<2 x float> [[TMP3]],<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> [[FMLA]],<4 x float> [[LANE]],<4 x float> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[FMLA2]]
end_comment

begin_function
name|float32x4_t
name|test_vfmsq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vfmsq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfms_laneq_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x float><float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> [[SUB]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<4 x float> [[TMP5]],<4 x float> [[TMP5]],<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> [[LANE]],<2 x float> [[TMP4]],<2 x float> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP6]]
end_comment

begin_function
name|float32x2_t
name|test_vfms_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfms_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsq_laneq_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> [[SUB]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<4 x float> [[TMP5]],<4 x float> [[TMP5]],<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> [[LANE]],<4 x float> [[TMP4]],<4 x float> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP6]]
end_comment

begin_function
name|float32x4_t
name|test_vfmsq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vfmsq_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmaq_laneq_f64_0(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x double> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x double> [[TMP5]],<2 x double> [[TMP5]],<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x double> @llvm.fma.v2f64(<2 x double> [[LANE]],<2 x double> [[TMP4]],<2 x double> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[TMP6]]
end_comment

begin_function
name|float64x2_t
name|test_vfmaq_laneq_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vfmaq_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsq_laneq_f64_0(
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> [[SUB]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x double> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<2 x double> [[TMP5]],<2 x double> [[TMP5]],<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x double> @llvm.fma.v2f64(<2 x double> [[LANE]],<2 x double> [[TMP4]],<2 x double> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[TMP6]]
end_comment

begin_function
name|float64x2_t
name|test_vfmsq_laneq_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vfmsq_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_high_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_high_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_high_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_high_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_high_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_high_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_high_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_high_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_lane_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_lane_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_laneq_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_laneq_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_high_lane_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_high_lane_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_high_laneq_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_high_laneq_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlal_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_lane_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_lane_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_laneq_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_laneq_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_high_lane_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_high_lane_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_high_laneq_u16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i64> %a, [[VMULL2_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_high_laneq_u32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsl_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmull_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_lane_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_lane_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmull_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_high_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_high_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_high_lane_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_lane_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_high_lane_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_lane_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmull_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_laneq_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmull_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_laneq_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_high_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_high_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL2_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_high_laneq_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_laneq_u16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL2_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_high_laneq_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmull_high_laneq_u32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_high_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_high_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_high_lane_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_high_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_high_lane_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_high_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_high_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_high_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_high_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_high_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_high_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_high_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmull_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V2_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqdmulh.v4i16(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast<4 x i16> [[VQDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQDMULH_V2_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqdmulh_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqdmulh.v8i16(<8 x i16> %a,<8 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast<8 x i16> [[VQDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQDMULHQ_V2_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqdmulhq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V2_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqdmulh.v2i32(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast<2 x i32> [[VQDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQDMULH_V2_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqdmulh_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmulh.v4i32(<4 x i32> %a,<4 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULHQ_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmulhq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V2_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqrdmulh.v4i16(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast<4 x i16> [[VQRDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQRDMULH_V2_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqrdmulh_lane_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulh_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_lane_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqrdmulh.v8i16(<8 x i16> %a,<8 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQRDMULHQ_V2_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqrdmulhq_lane_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x4_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulhq_lane_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V2_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqrdmulh.v2i32(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast<2 x i32> [[VQRDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQRDMULH_V2_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqrdmulh_lane_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulh_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_lane_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqrdmulh.v4i32(<4 x i32> %a,<4 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQRDMULHQ_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqrdmulhq_lane_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x2_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulhq_lane_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_lane_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[MUL]]
end_comment

begin_function
name|float32x2_t
name|test_vmul_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmul_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_lane_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[MUL]]
end_comment

begin_function
name|float32x4_t
name|test_vmulq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[MUL]]
end_comment

begin_function
name|float32x2_t
name|test_vmul_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_laneq_f64_0(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[TMP0]] to double
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP1]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<2 x double> [[TMP3]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = fmul double [[TMP2]], [[EXTRACT]]
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast double [[TMP4]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[TMP5]]
end_comment

begin_function
name|float64x1_t
name|test_vmul_laneq_f64_0
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vmul_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[MUL]]
end_comment

begin_function
name|float32x4_t
name|test_vmulq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_laneq_f64_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x double> %v,<2 x double> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x double> %a, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[MUL]]
end_comment

begin_function
name|float64x2_t
name|test_vmulq_laneq_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulq_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulx_lane_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<2 x float> @llvm.aarch64.neon.fmulx.v2f32(<2 x float> %a,<2 x float> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VMULX2_I]]
end_comment

begin_function
name|float32x2_t
name|test_vmulx_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulx_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulxq_lane_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<4 x float> @llvm.aarch64.neon.fmulx.v4f32(<4 x float> %a,<4 x float> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VMULX2_I]]
end_comment

begin_function
name|float32x4_t
name|test_vmulxq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulxq_lane_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulxq_lane_f64_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<1 x double> %v,<1 x double> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<2 x double> @llvm.aarch64.neon.fmulx.v2f64(<2 x double> %a,<2 x double> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VMULX2_I]]
end_comment

begin_function
name|float64x2_t
name|test_vmulxq_lane_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vmulxq_lane_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulx_laneq_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<2 x float> @llvm.aarch64.neon.fmulx.v2f32(<2 x float> %a,<2 x float> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VMULX2_I]]
end_comment

begin_function
name|float32x2_t
name|test_vmulx_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulx_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulxq_laneq_f32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<4 x float> @llvm.aarch64.neon.fmulx.v4f32(<4 x float> %a,<4 x float> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VMULX2_I]]
end_comment

begin_function
name|float32x4_t
name|test_vmulxq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmulxq_laneq_f32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulxq_laneq_f64_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x double> %v,<2 x double> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x double> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULX2_I:%.*]] = call<2 x double> @llvm.aarch64.neon.fmulx.v2f64(<2 x double> %a,<2 x double> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VMULX2_I]]
end_comment

begin_function
name|float64x2_t
name|test_vmulxq_laneq_f64_0
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vmulxq_laneq_f64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<4 x i16> [[VECINIT_I_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL5_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I_I]],<4 x i16> [[VECINIT3_I_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL5_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_high_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vmull_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<2 x i32> [[VECINIT_I_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL3_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I_I]],<2 x i32> [[VECINIT1_I_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL3_I_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_high_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vmull_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<4 x i16> [[VECINIT_I_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL5_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I_I]],<4 x i16> [[VECINIT3_I_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL5_I_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_high_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vmull_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_high_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<2 x i32> [[VECINIT_I_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL3_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I_I]],<2 x i32> [[VECINIT1_I_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL3_I_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_high_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vmull_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<4 x i16> [[VECINIT_I_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V5_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I_I]],<4 x i16> [[VECINIT3_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V6_I_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V5_I_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V5_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_high_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_high_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<2 x i32> [[VECINIT_I_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I_I]],<2 x i32> [[VECINIT1_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V4_I_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V3_I_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V3_I_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_high_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<4 x i16> [[VECINIT_I_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I_I]],<4 x i16> [[VECINIT3_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[ADD_I_I:%.*]] = add<4 x i32> %a, [[VMULL2_I_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_high_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<2 x i32> [[VECINIT_I_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I_I]],<2 x i32> [[VECINIT1_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[ADD_I_I:%.*]] = add<2 x i64> %a, [[VMULL2_I_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD_I_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_high_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<4 x i16> [[VECINIT_I_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I_I]],<4 x i16> [[VECINIT3_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[ADD_I_I:%.*]] = add<4 x i32> %a, [[VMULL2_I_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD_I_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlal_high_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_high_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<2 x i32> [[VECINIT_I_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I_I]],<2 x i32> [[VECINIT1_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[ADD_I_I:%.*]] = add<2 x i64> %a, [[VMULL2_I_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD_I_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmlal_high_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<4 x i16> [[VECINIT_I_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[VECINIT3_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL5_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I_I]],<4 x i16> [[VECINIT3_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V6_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL5_I_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V6_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_high_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<2 x i32> [[VECINIT_I_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[VECINIT1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL3_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I_I]],<2 x i32> [[VECINIT1_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V4_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL3_I_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V4_I_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_high_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<4 x i16> [[VECINIT_I_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> [[SHUFFLE_I_I]],<4 x i16> [[VECINIT3_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[SUB_I_I:%.*]] = sub<4 x i32> %a, [[VMULL2_I_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_high_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<2 x i32> [[VECINIT_I_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> [[SHUFFLE_I_I]],<2 x i32> [[VECINIT1_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[SUB_I_I:%.*]] = sub<2 x i64> %a, [[VMULL2_I_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB_I_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_high_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<4 x i16> [[VECINIT_I_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> [[SHUFFLE_I_I]],<4 x i16> [[VECINIT3_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[SUB_I_I:%.*]] = sub<4 x i32> %a, [[VMULL2_I_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB_I_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlsl_high_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_high_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_high_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<2 x i32> [[VECINIT_I_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> [[SHUFFLE_I_I]],<2 x i32> [[VECINIT1_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[SUB_I_I:%.*]] = sub<2 x i64> %a, [[VMULL2_I_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB_I_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmlsl_high_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_high_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<4 x i16> [[VECINIT_I_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[VECINIT3_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL5_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I_I]],<4 x i16> [[VECINIT3_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V6_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL5_I_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V6_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_high_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_high_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I_I:%.*]] = insertelement<2 x i32> [[VECINIT_I_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[VECINIT1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL3_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I_I]],<2 x i32> [[VECINIT1_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V4_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL3_I_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V4_I_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_high_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_high_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_n_f32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x float> undef, float %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x float> [[VECINIT_I]], float %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = fmul<2 x float> %a, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[MUL_I]]
end_comment

begin_function
name|float32x2_t
name|test_vmul_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_n_f32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x float> undef, float %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x float> [[VECINIT_I]], float %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x float> [[VECINIT1_I]], float %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x float> [[VECINIT2_I]], float %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = fmul<4 x float> %a, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[MUL_I]]
end_comment

begin_function
name|float32x4_t
name|test_vmulq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_n_f64(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x double> undef, double %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x double> [[VECINIT_I]], double %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = fmul<2 x double> %a, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[MUL_I]]
end_comment

begin_function
name|float64x2_t
name|test_vmulq_n_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfma_n_f32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x float> undef, float %n, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x float> [[VECINIT_I]], float %n, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> %b,<2 x float> [[VECINIT1_I]],<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP3]]
end_comment

begin_function
name|float32x2_t
name|test_vfma_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32_t
name|n
parameter_list|)
block|{
return|return
name|vfma_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmaq_n_f32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x float> undef, float %n, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x float> [[VECINIT_I]], float %n, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x float> [[VECINIT1_I]], float %n, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x float> [[VECINIT2_I]], float %n, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> [[VECINIT3_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> %b,<4 x float> [[VECINIT3_I]],<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP3]]
end_comment

begin_function
name|float32x4_t
name|test_vfmaq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32_t
name|n
parameter_list|)
block|{
return|return
name|vfmaq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfms_n_f32(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = fsub<2 x float><float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x float> undef, float %n, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x float> [[VECINIT_I]], float %n, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> [[SUB_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x float> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> [[SUB_I]],<2 x float> [[VECINIT1_I]],<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP3]]
end_comment

begin_function
name|float32x2_t
name|test_vfms_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32_t
name|n
parameter_list|)
block|{
return|return
name|vfms_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vfmsq_n_f32(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x float> undef, float %n, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x float> [[VECINIT_I]], float %n, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x float> [[VECINIT1_I]], float %n, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x float> [[VECINIT2_I]], float %n, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> [[SUB_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x float> [[VECINIT3_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> [[SUB_I]],<4 x float> [[VECINIT3_I]],<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP3]]
end_comment

begin_function
name|float32x4_t
name|test_vfmsq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32_t
name|n
parameter_list|)
block|{
return|return
name|vfmsq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|n
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i16> %a, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL_I]]
end_comment

begin_function
name|int16x4_t
name|test_vmul_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<8 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<8 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<8 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<8 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[VECINIT4_I:%.*]] = insertelement<8 x i16> [[VECINIT3_I]], i16 %b, i32 4
end_comment

begin_comment
comment|// CHECK:   [[VECINIT5_I:%.*]] = insertelement<8 x i16> [[VECINIT4_I]], i16 %b, i32 5
end_comment

begin_comment
comment|// CHECK:   [[VECINIT6_I:%.*]] = insertelement<8 x i16> [[VECINIT5_I]], i16 %b, i32 6
end_comment

begin_comment
comment|// CHECK:   [[VECINIT7_I:%.*]] = insertelement<8 x i16> [[VECINIT6_I]], i16 %b, i32 7
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<8 x i16> %a, [[VECINIT7_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL_I]]
end_comment

begin_function
name|int16x8_t
name|test_vmulq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<2 x i32> %a, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL_I]]
end_comment

begin_function
name|int32x2_t
name|test_vmul_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i32> [[VECINIT1_I]], i32 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i32> [[VECINIT2_I]], i32 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i32> %a, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmulq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i16> %a, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[MUL_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vmul_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<8 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<8 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<8 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<8 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[VECINIT4_I:%.*]] = insertelement<8 x i16> [[VECINIT3_I]], i16 %b, i32 4
end_comment

begin_comment
comment|// CHECK:   [[VECINIT5_I:%.*]] = insertelement<8 x i16> [[VECINIT4_I]], i16 %b, i32 5
end_comment

begin_comment
comment|// CHECK:   [[VECINIT6_I:%.*]] = insertelement<8 x i16> [[VECINIT5_I]], i16 %b, i32 6
end_comment

begin_comment
comment|// CHECK:   [[VECINIT7_I:%.*]] = insertelement<8 x i16> [[VECINIT6_I]], i16 %b, i32 7
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<8 x i16> %a, [[VECINIT7_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[MUL_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vmulq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmul_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<2 x i32> %a, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[MUL_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vmul_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmulq_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i32> [[VECINIT1_I]], i32 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i32> [[VECINIT2_I]], i32 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i32> %a, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[MUL_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmulq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vmulq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL5_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %a,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL5_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmull_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vmull_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %a,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmull_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vmull_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL5_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %a,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VMULL5_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmull_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16_t
name|b
parameter_list|)
block|{
return|return
name|vmull_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmull_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %a,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VMULL3_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmull_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32_t
name|b
parameter_list|)
block|{
return|return
name|vmull_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V5_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %a,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V6_I:%.*]] = bitcast<4 x i32> [[VQDMULL_V5_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULL_V5_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmull_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmull_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %a,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULL_V4_I:%.*]] = bitcast<2 x i64> [[VQDMULL_V3_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMULL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmull_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqdmull_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V5_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqdmulh.v4i16(<4 x i16> %a,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V6_I:%.*]] = bitcast<4 x i16> [[VQDMULH_V5_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQDMULH_V5_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqdmulh_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulh_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<8 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<8 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<8 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<8 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[VECINIT4_I:%.*]] = insertelement<8 x i16> [[VECINIT3_I]], i16 %b, i32 4
end_comment

begin_comment
comment|// CHECK:   [[VECINIT5_I:%.*]] = insertelement<8 x i16> [[VECINIT4_I]], i16 %b, i32 5
end_comment

begin_comment
comment|// CHECK:   [[VECINIT6_I:%.*]] = insertelement<8 x i16> [[VECINIT5_I]], i16 %b, i32 6
end_comment

begin_comment
comment|// CHECK:   [[VECINIT7_I:%.*]] = insertelement<8 x i16> [[VECINIT6_I]], i16 %b, i32 7
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[VECINIT7_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V9_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqdmulh.v8i16(<8 x i16> %a,<8 x i16> [[VECINIT7_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V10_I:%.*]] = bitcast<8 x i16> [[VQDMULHQ_V9_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQDMULHQ_V9_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqdmulhq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V3_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqdmulh.v2i32(<2 x i32> %a,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V4_I:%.*]] = bitcast<2 x i32> [[VQDMULH_V3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQDMULH_V3_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqdmulh_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulh_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i32> [[VECINIT1_I]], i32 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i32> [[VECINIT2_I]], i32 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[VECINIT3_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V5_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmulh.v4i32(<4 x i32> %a,<4 x i32> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V6_I:%.*]] = bitcast<4 x i32> [[VQDMULHQ_V5_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULHQ_V5_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmulhq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V5_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqrdmulh.v4i16(<4 x i16> %a,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V6_I:%.*]] = bitcast<4 x i16> [[VQRDMULH_V5_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQRDMULH_V5_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqrdmulh_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulh_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<8 x i16> undef, i16 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<8 x i16> [[VECINIT_I]], i16 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<8 x i16> [[VECINIT1_I]], i16 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<8 x i16> [[VECINIT2_I]], i16 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[VECINIT4_I:%.*]] = insertelement<8 x i16> [[VECINIT3_I]], i16 %b, i32 4
end_comment

begin_comment
comment|// CHECK:   [[VECINIT5_I:%.*]] = insertelement<8 x i16> [[VECINIT4_I]], i16 %b, i32 5
end_comment

begin_comment
comment|// CHECK:   [[VECINIT6_I:%.*]] = insertelement<8 x i16> [[VECINIT5_I]], i16 %b, i32 6
end_comment

begin_comment
comment|// CHECK:   [[VECINIT7_I:%.*]] = insertelement<8 x i16> [[VECINIT6_I]], i16 %b, i32 7
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[VECINIT7_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V9_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqrdmulh.v8i16(<8 x i16> %a,<8 x i16> [[VECINIT7_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V10_I:%.*]] = bitcast<8 x i16> [[VQRDMULHQ_V9_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQRDMULHQ_V9_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqrdmulhq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V3_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqrdmulh.v2i32(<2 x i32> %a,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V4_I:%.*]] = bitcast<2 x i32> [[VQRDMULH_V3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQRDMULH_V3_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqrdmulh_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulh_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i32> undef, i32 %b, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i32> [[VECINIT_I]], i32 %b, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i32> [[VECINIT1_I]], i32 %b, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i32> [[VECINIT2_I]], i32 %b, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[VECINIT3_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V5_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqrdmulh.v4i32(<4 x i32> %a,<4 x i32> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V6_I:%.*]] = bitcast<4 x i32> [[VQRDMULHQ_V5_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQRDMULHQ_V5_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqrdmulhq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i16> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<4 x i16> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD_I]]
end_comment

begin_function
name|int16x4_t
name|test_vmla_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<8 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<8 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<8 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<8 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[VECINIT4_I:%.*]] = insertelement<8 x i16> [[VECINIT3_I]], i16 %c, i32 4
end_comment

begin_comment
comment|// CHECK:   [[VECINIT5_I:%.*]] = insertelement<8 x i16> [[VECINIT4_I]], i16 %c, i32 5
end_comment

begin_comment
comment|// CHECK:   [[VECINIT6_I:%.*]] = insertelement<8 x i16> [[VECINIT5_I]], i16 %c, i32 6
end_comment

begin_comment
comment|// CHECK:   [[VECINIT7_I:%.*]] = insertelement<8 x i16> [[VECINIT6_I]], i16 %c, i32 7
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<8 x i16> %b, [[VECINIT7_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<8 x i16> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD_I]]
end_comment

begin_function
name|int16x8_t
name|test_vmlaq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<2 x i32> %b, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<2 x i32> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD_I]]
end_comment

begin_function
name|int32x2_t
name|test_vmla_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i32> [[VECINIT1_I]], i32 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i32> [[VECINIT2_I]], i32 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i32> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<4 x i32> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmlaq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i16> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<4 x i16> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vmla_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<8 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<8 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<8 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<8 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[VECINIT4_I:%.*]] = insertelement<8 x i16> [[VECINIT3_I]], i16 %c, i32 4
end_comment

begin_comment
comment|// CHECK:   [[VECINIT5_I:%.*]] = insertelement<8 x i16> [[VECINIT4_I]], i16 %c, i32 5
end_comment

begin_comment
comment|// CHECK:   [[VECINIT6_I:%.*]] = insertelement<8 x i16> [[VECINIT5_I]], i16 %c, i32 6
end_comment

begin_comment
comment|// CHECK:   [[VECINIT7_I:%.*]] = insertelement<8 x i16> [[VECINIT6_I]], i16 %c, i32 7
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<8 x i16> %b, [[VECINIT7_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<8 x i16> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlaq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<2 x i32> %b, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<2 x i32> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vmla_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i32> [[VECINIT1_I]], i32 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i32> [[VECINIT2_I]], i32 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i32> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<4 x i32> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlaq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<4 x i32> %a, [[VMULL2_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmlal_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<2 x i64> %a, [[VMULL2_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmlal_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<4 x i32> %a, [[VMULL2_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlal_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlal_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = add<2 x i64> %a, [[VMULL2_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[ADD_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmlal_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlal_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL5_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V6_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL5_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V6_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V4_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL3_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V4_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlal_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i16> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<4 x i16> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB_I]]
end_comment

begin_function
name|int16x4_t
name|test_vmls_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<8 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<8 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<8 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<8 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[VECINIT4_I:%.*]] = insertelement<8 x i16> [[VECINIT3_I]], i16 %c, i32 4
end_comment

begin_comment
comment|// CHECK:   [[VECINIT5_I:%.*]] = insertelement<8 x i16> [[VECINIT4_I]], i16 %c, i32 5
end_comment

begin_comment
comment|// CHECK:   [[VECINIT6_I:%.*]] = insertelement<8 x i16> [[VECINIT5_I]], i16 %c, i32 6
end_comment

begin_comment
comment|// CHECK:   [[VECINIT7_I:%.*]] = insertelement<8 x i16> [[VECINIT6_I]], i16 %c, i32 7
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<8 x i16> %b, [[VECINIT7_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<8 x i16> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB_I]]
end_comment

begin_function
name|int16x8_t
name|test_vmlsq_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<2 x i32> %b, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<2 x i32> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB_I]]
end_comment

begin_function
name|int32x2_t
name|test_vmls_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i32> [[VECINIT1_I]], i32 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i32> [[VECINIT2_I]], i32 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i32> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<4 x i32> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsq_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i16> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<4 x i16> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vmls_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<8 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<8 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<8 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<8 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[VECINIT4_I:%.*]] = insertelement<8 x i16> [[VECINIT3_I]], i16 %c, i32 4
end_comment

begin_comment
comment|// CHECK:   [[VECINIT5_I:%.*]] = insertelement<8 x i16> [[VECINIT4_I]], i16 %c, i32 5
end_comment

begin_comment
comment|// CHECK:   [[VECINIT6_I:%.*]] = insertelement<8 x i16> [[VECINIT5_I]], i16 %c, i32 6
end_comment

begin_comment
comment|// CHECK:   [[VECINIT7_I:%.*]] = insertelement<8 x i16> [[VECINIT6_I]], i16 %c, i32 7
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<8 x i16> %b, [[VECINIT7_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<8 x i16> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlsq_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<2 x i32> %b, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<2 x i32> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vmls_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i32> [[VECINIT1_I]], i32 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i32> [[VECINIT2_I]], i32 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = mul<4 x i32> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<4 x i32> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlsq_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.smull.v4i32(<4 x i16> %b,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<4 x i32> %a, [[VMULL2_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmlsl_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.smull.v2i64(<2 x i32> %b,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<2 x i64> %a, [[VMULL2_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB_I]]
end_comment

begin_function
name|int64x2_t
name|test_vmlsl_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.umull.v4i32(<4 x i16> %b,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<4 x i32> %a, [[VMULL2_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlsl_n_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_n_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsl_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMULL2_I_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.umull.v2i64(<2 x i32> %b,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<2 x i64> %a, [[VMULL2_I_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vmlsl_n_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsl_n_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x i16> undef, i16 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x i16> [[VECINIT_I]], i16 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x i16> [[VECINIT1_I]], i16 %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x i16> [[VECINIT2_I]], i16 %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[VECINIT3_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL5_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[VECINIT3_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V6_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL5_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V6_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_n_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_n_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x i32> undef, i32 %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x i32> [[VECINIT_I]], i32 %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[VECINIT1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[VECINIT1_I]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V4_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL3_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V4_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_n_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsl_n_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD]]
end_comment

begin_function
name|uint16x4_t
name|test_vmla_lane_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlaq_lane_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD]]
end_comment

begin_function
name|uint32x2_t
name|test_vmla_lane_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlaq_lane_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD]]
end_comment

begin_function
name|uint16x4_t
name|test_vmla_laneq_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlaq_laneq_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD]]
end_comment

begin_function
name|uint32x2_t
name|test_vmla_laneq_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlaq_laneq_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_high_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_high_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB]]
end_comment

begin_function
name|uint16x4_t
name|test_vmls_lane_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_lane_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlsq_lane_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB]]
end_comment

begin_function
name|uint32x2_t
name|test_vmls_lane_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_lane_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlsq_lane_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB]]
end_comment

begin_function
name|uint16x4_t
name|test_vmls_laneq_u16_0
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_laneq_u16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlsq_laneq_u16_0
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB]]
end_comment

begin_function
name|uint32x2_t
name|test_vmls_laneq_u32_0
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_laneq_u32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlsq_laneq_u32_0
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_high_laneq_s16_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_high_laneq_s32_0
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V2_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqdmulh.v4i16(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast<4 x i16> [[VQDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQDMULH_V2_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqdmulh_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulh_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqdmulh.v8i16(<8 x i16> %a,<8 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast<8 x i16> [[VQDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQDMULHQ_V2_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqdmulhq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulhq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V2_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqdmulh.v2i32(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast<2 x i32> [[VQDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQDMULH_V2_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqdmulh_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulh_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmulh.v4i32(<4 x i32> %a,<4 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULHQ_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmulhq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulhq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V2_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqrdmulh.v4i16(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast<4 x i16> [[VQRDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQRDMULH_V2_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqrdmulh_laneq_s16_0
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulh_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_laneq_s16_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqrdmulh.v8i16(<8 x i16> %a,<8 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast<8 x i16> [[VQRDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQRDMULHQ_V2_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqrdmulhq_laneq_s16_0
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulhq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V2_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqrdmulh.v2i32(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast<2 x i32> [[VQRDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQRDMULH_V2_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqrdmulh_laneq_s32_0
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulh_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_laneq_s32_0(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqrdmulh.v4i32(<4 x i32> %a,<4 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast<4 x i32> [[VQRDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQRDMULHQ_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqrdmulhq_laneq_s32_0
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulhq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD]]
end_comment

begin_function
name|uint16x4_t
name|test_vmla_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32><i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlaq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD]]
end_comment

begin_function
name|uint32x2_t
name|test_vmla_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlaq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[ADD]]
end_comment

begin_function
name|uint16x4_t
name|test_vmla_laneq_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32><i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[ADD]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlaq_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmla_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[ADD]]
end_comment

begin_function
name|uint32x2_t
name|test_vmla_laneq_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlaq_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = add<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[ADD]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlaq_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqadd.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlal_high_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlal_high_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqadd.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLAL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlal_high_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlal_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB]]
end_comment

begin_function
name|uint16x4_t
name|test_vmls_lane_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_lane_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i16> %v,<4 x i16> %v,<8 x i32><i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlsq_lane_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB]]
end_comment

begin_function
name|uint32x2_t
name|test_vmls_lane_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_lane_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x i32> %v,<2 x i32> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlsq_lane_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB]]
end_comment

begin_function
name|uint16x4_t
name|test_vmls_laneq_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_laneq_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32><i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<8 x i16> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<8 x i16> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB]]
end_comment

begin_function
name|uint16x8_t
name|test_vmlsq_laneq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|,
name|uint16x8_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmls_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<2 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<2 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB]]
end_comment

begin_function
name|uint32x2_t
name|test_vmls_laneq_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmlsq_laneq_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = mul<4 x i32> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = sub<4 x i32> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB]]
end_comment

begin_function
name|uint32x4_t
name|test_vmlsq_laneq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|,
name|uint32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> %b,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> %b,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %b,<8 x i16> %b,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[SHUFFLE_I]],<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqsub.v4i32(<4 x i32> %a,<4 x i32> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmlsl_high_laneq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_high_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmlsl_high_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %b,<4 x i32> %b,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMLAL2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqdmull.v2i64(<2 x i32> [[SHUFFLE_I]],<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLSL_V3_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqsub.v2i64(<2 x i64> %a,<2 x i64> [[VQDMLAL2_I]])
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQDMLSL_V3_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqdmlsl_high_laneq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmlsl_high_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V2_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqdmulh.v4i16(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast<4 x i16> [[VQDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQDMULH_V2_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqdmulh_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulh_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32><i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqdmulh.v8i16(<8 x i16> %a,<8 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast<8 x i16> [[VQDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQDMULHQ_V2_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqdmulhq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulhq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulh_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V2_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqdmulh.v2i32(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULH_V3_I:%.*]] = bitcast<2 x i32> [[VQDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQDMULH_V2_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqdmulh_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulh_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqdmulhq_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmulh.v4i32(<4 x i32> %a,<4 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHQ_V3_I:%.*]] = bitcast<4 x i32> [[VQDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQDMULHQ_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqdmulhq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqdmulhq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<4 x i32><i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V2_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqrdmulh.v4i16(<4 x i16> %a,<4 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast<4 x i16> [[VQRDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQRDMULH_V2_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqrdmulh_laneq_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulh_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_laneq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<8 x i16> %v,<8 x i16> %v,<8 x i32><i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqrdmulh.v8i16(<8 x i16> %a,<8 x i16> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast<8 x i16> [[VQRDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQRDMULHQ_V2_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqrdmulhq_laneq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulhq_laneq_s16
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulh_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> [[SHUFFLE]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V2_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqrdmulh.v2i32(<2 x i32> %a,<2 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULH_V3_I:%.*]] = bitcast<2 x i32> [[VQRDMULH_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQRDMULH_V2_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqrdmulh_laneq_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulh_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqrdmulhq_laneq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x i32> %v,<4 x i32> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> [[SHUFFLE]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqrdmulh.v4i32(<4 x i32> %a,<4 x i32> [[SHUFFLE]])
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHQ_V3_I:%.*]] = bitcast<4 x i32> [[VQRDMULHQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQRDMULHQ_V2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqrdmulhq_laneq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|v
parameter_list|)
block|{
return|return
name|vqrdmulhq_laneq_s32
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

end_unit

