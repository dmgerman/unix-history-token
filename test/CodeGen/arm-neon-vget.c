begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-apple-darwin \
end_comment

begin_comment
comment|// RUN:   -target-abi apcs-gnu \
end_comment

begin_comment
comment|// RUN:   -target-cpu cortex-a8 \
end_comment

begin_comment
comment|// RUN:   -mfloat-abi soft \
end_comment

begin_comment
comment|// RUN:   -target-feature +soft-float-abi \
end_comment

begin_comment
comment|// RUN:   -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -disable-O0-optnone -emit-llvm -w -o - %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// Check that the vget_low/vget_high intrinsics generate a single shuffle
end_comment

begin_comment
comment|// without any bitcasting.
end_comment

begin_function
name|int8x8_t
name|low_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|vget_low_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x8_t
name|low_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|vget_low_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x4_t
name|low_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 0, i32 1, i32 2, i32 3>
return|return
name|vget_low_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x4_t
name|low_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 0, i32 1, i32 2, i32 3>
return|return
name|vget_low_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|low_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 0, i32 1>
return|return
name|vget_low_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|low_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 0, i32 1>
return|return
name|vget_low_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|low_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32> zeroinitializer
return|return
name|vget_low_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|low_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32> zeroinitializer
return|return
name|vget_low_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|poly8x8_t
name|low_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|vget_low_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|poly16x4_t
name|low_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 0, i32 1, i32 2, i32 3>
return|return
name|vget_low_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|low_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<4 x float> %a,<4 x float> %a,<2 x i32><i32 0, i32 1>
return|return
name|vget_low_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x8_t
name|high_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|vget_high_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x8_t
name|high_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|vget_high_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x4_t
name|high_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
return|return
name|vget_high_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x4_t
name|high_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
return|return
name|vget_high_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|high_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
return|return
name|vget_high_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|high_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
return|return
name|vget_high_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|high_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32><i32 1>
return|return
name|vget_high_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|high_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32><i32 1>
return|return
name|vget_high_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|poly8x8_t
name|high_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|vget_high_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|poly16x4_t
name|high_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
return|return
name|vget_high_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|high_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK: shufflevector<4 x float> %a,<4 x float> %a,<2 x i32><i32 2, i32 3>
return|return
name|vget_high_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

