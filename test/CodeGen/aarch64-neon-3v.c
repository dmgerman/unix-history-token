begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon  -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK-LABEL: define<8 x i8> @test_vand_s8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<8 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[AND_I]]
end_comment

begin_function
name|int8x8_t
name|test_vand_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vand_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vandq_s8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<16 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[AND_I]]
end_comment

begin_function
name|int8x16_t
name|test_vandq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vandq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vand_s16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<4 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[AND_I]]
end_comment

begin_function
name|int16x4_t
name|test_vand_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vand_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vandq_s16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<8 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[AND_I]]
end_comment

begin_function
name|int16x8_t
name|test_vandq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vandq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vand_s32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<2 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[AND_I]]
end_comment

begin_function
name|int32x2_t
name|test_vand_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vand_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vandq_s32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<4 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[AND_I]]
end_comment

begin_function
name|int32x4_t
name|test_vandq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vandq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vand_s64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<1 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[AND_I]]
end_comment

begin_function
name|int64x1_t
name|test_vand_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vand_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vandq_s64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<2 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[AND_I]]
end_comment

begin_function
name|int64x2_t
name|test_vandq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vandq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vand_u8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<8 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[AND_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vand_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vand_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vandq_u8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<16 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[AND_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vandq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vandq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vand_u16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<4 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[AND_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vand_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vand_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vandq_u16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<8 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[AND_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vandq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vandq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vand_u32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<2 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[AND_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vand_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vand_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vandq_u32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<4 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[AND_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vandq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vandq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vand_u64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<1 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[AND_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vand_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vand_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vandq_u64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<2 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[AND_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vandq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vandq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vorr_s8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<8 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[OR_I]]
end_comment

begin_function
name|int8x8_t
name|test_vorr_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vorr_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vorrq_s8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<16 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[OR_I]]
end_comment

begin_function
name|int8x16_t
name|test_vorrq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vorr_s16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<4 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[OR_I]]
end_comment

begin_function
name|int16x4_t
name|test_vorr_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vorr_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vorrq_s16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<8 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[OR_I]]
end_comment

begin_function
name|int16x8_t
name|test_vorrq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vorr_s32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<2 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[OR_I]]
end_comment

begin_function
name|int32x2_t
name|test_vorr_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vorr_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vorrq_s32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<4 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[OR_I]]
end_comment

begin_function
name|int32x4_t
name|test_vorrq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vorr_s64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<1 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[OR_I]]
end_comment

begin_function
name|int64x1_t
name|test_vorr_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vorr_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vorrq_s64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<2 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[OR_I]]
end_comment

begin_function
name|int64x2_t
name|test_vorrq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vorr_u8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<8 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[OR_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vorr_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vorr_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vorrq_u8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<16 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[OR_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vorrq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vorr_u16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<4 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[OR_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vorr_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vorr_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vorrq_u16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<8 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[OR_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vorrq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vorr_u32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<2 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[OR_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vorr_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vorr_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vorrq_u32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<4 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[OR_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vorrq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vorr_u64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<1 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[OR_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vorr_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vorr_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vorrq_u64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<2 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[OR_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vorrq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vorrq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_veor_s8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<8 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[XOR_I]]
end_comment

begin_function
name|int8x8_t
name|test_veor_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|veor_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_veorq_s8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<16 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[XOR_I]]
end_comment

begin_function
name|int8x16_t
name|test_veorq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|veorq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_veor_s16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<4 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[XOR_I]]
end_comment

begin_function
name|int16x4_t
name|test_veor_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|veor_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_veorq_s16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<8 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[XOR_I]]
end_comment

begin_function
name|int16x8_t
name|test_veorq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|veorq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_veor_s32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<2 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[XOR_I]]
end_comment

begin_function
name|int32x2_t
name|test_veor_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|veor_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_veorq_s32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<4 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[XOR_I]]
end_comment

begin_function
name|int32x4_t
name|test_veorq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|veorq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_veor_s64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<1 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[XOR_I]]
end_comment

begin_function
name|int64x1_t
name|test_veor_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|veor_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_veorq_s64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<2 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[XOR_I]]
end_comment

begin_function
name|int64x2_t
name|test_veorq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|veorq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_veor_u8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<8 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[XOR_I]]
end_comment

begin_function
name|uint8x8_t
name|test_veor_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|veor_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_veorq_u8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<16 x i8> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[XOR_I]]
end_comment

begin_function
name|uint8x16_t
name|test_veorq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|veorq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_veor_u16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<4 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[XOR_I]]
end_comment

begin_function
name|uint16x4_t
name|test_veor_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|veor_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_veorq_u16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<8 x i16> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[XOR_I]]
end_comment

begin_function
name|uint16x8_t
name|test_veorq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|veorq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_veor_u32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<2 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[XOR_I]]
end_comment

begin_function
name|uint32x2_t
name|test_veor_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|veor_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_veorq_u32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<4 x i32> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[XOR_I]]
end_comment

begin_function
name|uint32x4_t
name|test_veorq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|veorq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_veor_u64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<1 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[XOR_I]]
end_comment

begin_function
name|uint64x1_t
name|test_veor_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|veor_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_veorq_u64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[XOR_I:%.*]] = xor<2 x i64> %a, %b
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[XOR_I]]
end_comment

begin_function
name|uint64x2_t
name|test_veorq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|veorq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vbic_s8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i8> %b,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<8 x i8> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[AND_I]]
end_comment

begin_function
name|int8x8_t
name|test_vbic_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vbic_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vbicq_s8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<16 x i8> %b,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<16 x i8> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[AND_I]]
end_comment

begin_function
name|int8x16_t
name|test_vbicq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vbic_s16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i16> %b,<i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<4 x i16> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[AND_I]]
end_comment

begin_function
name|int16x4_t
name|test_vbic_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vbic_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vbicq_s16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i16> %b,<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<8 x i16> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[AND_I]]
end_comment

begin_function
name|int16x8_t
name|test_vbicq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vbic_s32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i32> %b,<i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<2 x i32> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[AND_I]]
end_comment

begin_function
name|int32x2_t
name|test_vbic_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vbic_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vbicq_s32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i32> %b,<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<4 x i32> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[AND_I]]
end_comment

begin_function
name|int32x4_t
name|test_vbicq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vbic_s64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<1 x i64> %b,<i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<1 x i64> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[AND_I]]
end_comment

begin_function
name|int64x1_t
name|test_vbic_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vbic_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vbicq_s64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i64> %b,<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<2 x i64> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[AND_I]]
end_comment

begin_function
name|int64x2_t
name|test_vbicq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vbic_u8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i8> %b,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<8 x i8> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[AND_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vbic_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vbic_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vbicq_u8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<16 x i8> %b,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<16 x i8> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[AND_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vbicq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vbic_u16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i16> %b,<i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<4 x i16> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[AND_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vbic_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vbic_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vbicq_u16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i16> %b,<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<8 x i16> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[AND_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vbicq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vbic_u32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i32> %b,<i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<2 x i32> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[AND_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vbic_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vbic_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vbicq_u32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i32> %b,<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<4 x i32> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[AND_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vbicq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vbic_u64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<1 x i64> %b,<i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<1 x i64> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[AND_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vbic_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vbic_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vbicq_u64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i64> %b,<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[AND_I:%.*]] = and<2 x i64> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[AND_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vbicq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vbicq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vorn_s8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i8> %b,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<8 x i8> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[OR_I]]
end_comment

begin_function
name|int8x8_t
name|test_vorn_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vorn_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vornq_s8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<16 x i8> %b,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<16 x i8> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[OR_I]]
end_comment

begin_function
name|int8x16_t
name|test_vornq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vornq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vorn_s16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i16> %b,<i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<4 x i16> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[OR_I]]
end_comment

begin_function
name|int16x4_t
name|test_vorn_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vorn_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vornq_s16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i16> %b,<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<8 x i16> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[OR_I]]
end_comment

begin_function
name|int16x8_t
name|test_vornq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vornq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vorn_s32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i32> %b,<i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<2 x i32> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[OR_I]]
end_comment

begin_function
name|int32x2_t
name|test_vorn_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vorn_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vornq_s32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i32> %b,<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<4 x i32> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[OR_I]]
end_comment

begin_function
name|int32x4_t
name|test_vornq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vornq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vorn_s64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<1 x i64> %b,<i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<1 x i64> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[OR_I]]
end_comment

begin_function
name|int64x1_t
name|test_vorn_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int64x1_t
name|b
parameter_list|)
block|{
return|return
name|vorn_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vornq_s64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i64> %b,<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<2 x i64> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[OR_I]]
end_comment

begin_function
name|int64x2_t
name|test_vornq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vornq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i8> @test_vorn_u8(<8 x i8> %a,<8 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i8> %b,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<8 x i8> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[OR_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vorn_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vorn_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vornq_u8(<16 x i8> %a,<16 x i8> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<16 x i8> %b,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<16 x i8> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[OR_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vornq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vornq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i16> @test_vorn_u16(<4 x i16> %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i16> %b,<i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<4 x i16> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[OR_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vorn_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vorn_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vornq_u16(<8 x i16> %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i16> %b,<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<8 x i16> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[OR_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vornq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vornq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vorn_u32(<2 x i32> %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i32> %b,<i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<2 x i32> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[OR_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vorn_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vorn_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vornq_u32(<4 x i32> %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i32> %b,<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<4 x i32> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[OR_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vornq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vornq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x i64> @test_vorn_u64(<1 x i64> %a,<1 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<1 x i64> %b,<i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<1 x i64> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[OR_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vorn_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint64x1_t
name|b
parameter_list|)
block|{
return|return
name|vorn_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vornq_u64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i64> %b,<i64 -1, i64 -1>
end_comment

begin_comment
comment|// CHECK:   [[OR_I:%.*]] = or<2 x i64> %a, [[NEG_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[OR_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vornq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vornq_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

