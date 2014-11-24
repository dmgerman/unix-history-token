begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 SIMD copy vector element to vector element: vcopyq_lane*
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

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
comment|// CHECK-LABEL: test_vcopyq_laneq_s8
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
comment|// CHECK: shufflevector<16 x i8> %a1,<16 x i8> %a2,<16 x i32><i32 0, i32 1, i32 2, i32 29, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
block|}
end_function

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
comment|// CHECK-LABEL: test_vcopyq_laneq_u8
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
comment|// CHECK: shufflevector<16 x i8> %a1,<16 x i8> %a2,<16 x i32><i32 0, i32 1, i32 2, i32 29, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
block|}
end_function

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
comment|// CHECK-LABEL: test_vcopyq_laneq_s16
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
comment|// CHECK: shufflevector<8 x i16> %a1,<8 x i16> %a2,<8 x i32><i32 0, i32 1, i32 2, i32 15, i32 4, i32 5, i32 6, i32 7>
block|}
end_function

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
comment|// CHECK-LABEL: test_vcopyq_laneq_u16
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
comment|// CHECK: shufflevector<8 x i16> %a1,<8 x i16> %a2,<8 x i32><i32 0, i32 1, i32 2, i32 15, i32 4, i32 5, i32 6, i32 7>
block|}
end_function

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
comment|// CHECK-LABEL: test_vcopyq_laneq_s32
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
comment|// CHECK: shufflevector<4 x i32> %a1,<4 x i32> %a2,<4 x i32><i32 0, i32 1, i32 2, i32 7>
block|}
end_function

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
comment|// CHECK-LABEL: test_vcopyq_laneq_u32
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
comment|// CHECK: shufflevector<4 x i32> %a1,<4 x i32> %a2,<4 x i32><i32 0, i32 1, i32 2, i32 7>
block|}
end_function

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
comment|// CHECK-LABEL: test_vcopyq_laneq_s64
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
comment|// CHECK: shufflevector<2 x i64> %a1,<2 x i64> %a2,<2 x i32><i32 3, i32 1>
block|}
end_function

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
comment|// CHECK-LABEL: test_vcopyq_laneq_u64
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
comment|// CHECK: shufflevector<2 x i64> %a1,<2 x i64> %a2,<2 x i32><i32 3, i32 1>
block|}
end_function

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
comment|// CHECK-LABEL: test_vcopyq_laneq_f32
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
comment|// CHECK: shufflevector<4 x float> %a1,<4 x float> %a2,<4 x i32><i32 7, i32 1, i32 2, i32 3>
block|}
end_function

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
comment|// CHECK-LABEL: test_vcopyq_laneq_f64
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
comment|// CHECK: shufflevector<2 x double> %a1,<2 x double> %a2,<2 x i32><i32 3, i32 1>
block|}
end_function

end_unit

