begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:  -disable-O0-optnone -fallow-half-arguments-and-returns -emit-llvm -o - %s \
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
comment|// CHECK-LABEL: @test_vceqz_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp eq<8 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<8 x i1> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCEQZ_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vceqz_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<4 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCEQZ_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vceqz_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<2 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCEQZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vceqz_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<1 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCEQZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vceqz_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_u64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<1 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCEQZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vceqz_u64
parameter_list|(
name|uint64x1_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_p64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<1 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCEQZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vceqz_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp eq<16 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<16 x i1> [[TMP0]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCEQZ_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vceqzq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<8 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<8 x i1> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCEQZ_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vceqzq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<4 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCEQZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vceqzq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<2 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCEQZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vceqzq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_u8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp eq<8 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<8 x i1> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCEQZ_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vceqz_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<4 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCEQZ_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vceqz_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<2 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCEQZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vceqz_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_u8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp eq<16 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<16 x i1> [[TMP0]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCEQZ_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vceqzq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<8 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<8 x i1> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCEQZ_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vceqzq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<4 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCEQZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vceqzq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_u64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<2 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCEQZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vceqzq_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp oeq<2 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCEQZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vceqz_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp oeq<1 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCEQZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vceqz_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp oeq<4 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCEQZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vceqzq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_p8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp eq<8 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<8 x i1> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCEQZ_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vceqz_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_p8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp eq<16 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<16 x i1> [[TMP0]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCEQZ_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vceqzq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqz_p16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<4 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCEQZ_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vceqz_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vceqz_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_p16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<8 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<8 x i1> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCEQZ_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vceqzq_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp oeq<2 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCEQZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vceqzq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vceqzq_p64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp eq<2 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCEQZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCEQZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vceqzq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vceqzq_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgez_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp sge<8 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<8 x i1> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCGEZ_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vcgez_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgez_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sge<4 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCGEZ_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vcgez_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgez_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sge<2 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCGEZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcgez_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgez_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sge<1 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCGEZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vcgez_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgezq_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp sge<16 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<16 x i1> [[TMP0]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCGEZ_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vcgezq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgezq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sge<8 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<8 x i1> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCGEZ_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vcgezq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgezq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sge<4 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCGEZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcgezq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgezq_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sge<2 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCGEZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcgezq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgez_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp oge<2 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCGEZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcgez_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgez_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp oge<1 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCGEZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vcgez_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcgez_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgezq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp oge<4 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCGEZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcgezq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgezq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp oge<2 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGEZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCGEZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcgezq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgezq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclez_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp sle<8 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<8 x i1> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCLEZ_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vclez_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vclez_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclez_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sle<4 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCLEZ_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vclez_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vclez_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclez_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sle<2 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCLEZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vclez_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vclez_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclez_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sle<1 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCLEZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vclez_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vclez_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclezq_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp sle<16 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<16 x i1> [[TMP0]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCLEZ_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vclezq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclezq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sle<8 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<8 x i1> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCLEZ_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vclezq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclezq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sle<4 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCLEZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vclezq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclezq_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sle<2 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCLEZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vclezq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclez_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp ole<2 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCLEZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vclez_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vclez_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclez_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp ole<1 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCLEZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vclez_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vclez_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclezq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp ole<4 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCLEZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vclezq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclezq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp ole<2 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLEZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCLEZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vclezq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vclezq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtz_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp sgt<8 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<8 x i1> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCGTZ_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vcgtz_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtz_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sgt<4 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCGTZ_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vcgtz_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtz_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sgt<2 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCGTZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcgtz_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtz_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sgt<1 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCGTZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vcgtz_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtzq_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp sgt<16 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<16 x i1> [[TMP0]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCGTZ_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vcgtzq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtzq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sgt<8 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<8 x i1> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCGTZ_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vcgtzq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtzq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sgt<4 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCGTZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcgtzq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtzq_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp sgt<2 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCGTZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcgtzq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtz_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp ogt<2 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCGTZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcgtz_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtz_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp ogt<1 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCGTZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vcgtz_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcgtz_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtzq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp ogt<4 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCGTZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcgtzq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcgtzq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp ogt<2 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCGTZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCGTZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcgtzq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcgtzq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltz_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp slt<8 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<8 x i1> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCLTZ_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vcltz_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltz_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp slt<4 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCLTZ_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vcltz_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltz_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp slt<2 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCLTZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcltz_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltz_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp slt<1 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCLTZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vcltz_s64
parameter_list|(
name|int64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltzq_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = icmp slt<16 x i8> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<16 x i1> [[TMP0]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCLTZ_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vcltzq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltzq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp slt<8 x i16> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<8 x i1> [[TMP1]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCLTZ_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vcltzq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltzq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp slt<4 x i32> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCLTZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcltzq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltzq_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = icmp slt<2 x i64> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCLTZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcltzq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltz_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp olt<2 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCLTZ_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcltz_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltz_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp olt<1 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<1 x i1> [[TMP1]] to<1 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VCLTZ_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vcltz_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|)
block|{
return|return
name|vcltz_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltzq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp olt<4 x float> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<4 x i1> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCLTZ_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcltzq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcltzq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fcmp olt<2 x double> %a, zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[VCLTZ_I:%.*]] = sext<2 x i1> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCLTZ_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcltzq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcltzq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev16_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %a,<8 x i32><i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|int8x8_t
name|test_vrev16_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev16_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev16_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %a,<8 x i32><i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vrev16_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev16_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev16_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %a,<8 x i32><i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|poly8x8_t
name|test_vrev16_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev16_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev16q_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<16 x i32><i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6, i32 9, i32 8, i32 11, i32 10, i32 13, i32 12, i32 15, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|int8x16_t
name|test_vrev16q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev16q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev16q_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<16 x i32><i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6, i32 9, i32 8, i32 11, i32 10, i32 13, i32 12, i32 15, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vrev16q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev16q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev16q_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<16 x i32><i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6, i32 9, i32 8, i32 11, i32 10, i32 13, i32 12, i32 15, i32 14>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|poly8x16_t
name|test_vrev16q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev16q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %a,<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|int8x8_t
name|test_vrev32_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %a,<4 x i32><i32 1, i32 0, i32 3, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|int16x4_t
name|test_vrev32_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %a,<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vrev32_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %a,<4 x i32><i32 1, i32 0, i32 3, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vrev32_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %a,<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|poly8x8_t
name|test_vrev32_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %a,<4 x i32><i32 1, i32 0, i32 3, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|poly16x4_t
name|test_vrev32_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev32_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32q_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<16 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4, i32 11, i32 10, i32 9, i32 8, i32 15, i32 14, i32 13, i32 12>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|int8x16_t
name|test_vrev32q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32q_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<8 x i32><i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|int16x8_t
name|test_vrev32q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32q_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<16 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4, i32 11, i32 10, i32 9, i32 8, i32 15, i32 14, i32 13, i32 12>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vrev32q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32q_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<8 x i32><i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vrev32q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32q_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<16 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4, i32 11, i32 10, i32 9, i32 8, i32 15, i32 14, i32 13, i32 12>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|poly8x16_t
name|test_vrev32q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev32q_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<8 x i32><i32 1, i32 0, i32 3, i32 2, i32 5, i32 4, i32 7, i32 6>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|poly16x8_t
name|test_vrev32q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev32q_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %a,<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|int8x8_t
name|test_vrev64_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %a,<4 x i32><i32 3, i32 2, i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|int16x4_t
name|test_vrev64_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %a,<2 x i32><i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

begin_function
name|int32x2_t
name|test_vrev64_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %a,<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vrev64_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %a,<4 x i32><i32 3, i32 2, i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vrev64_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> %a,<2 x i32><i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SHUFFLE_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vrev64_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> %a,<8 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|poly8x8_t
name|test_vrev64_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> %a,<4 x i32><i32 3, i32 2, i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|poly16x4_t
name|test_vrev64_p16
parameter_list|(
name|poly16x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<2 x float> %a,<2 x float> %a,<2 x i32><i32 1, i32 0>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SHUFFLE_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrev64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrev64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64q_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<16 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|int8x16_t
name|test_vrev64q_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64q_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|int16x8_t
name|test_vrev64q_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64q_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<4 x i32><i32 1, i32 0, i32 3, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

begin_function
name|int32x4_t
name|test_vrev64q_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64q_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<16 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vrev64q_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64q_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vrev64q_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64q_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<4 x i32><i32 1, i32 0, i32 3, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vrev64q_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64q_p8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<16 x i32><i32 7, i32 6, i32 5, i32 4, i32 3, i32 2, i32 1, i32 0, i32 15, i32 14, i32 13, i32 12, i32 11, i32 10, i32 9, i32 8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I]]
end_comment

begin_function
name|poly8x16_t
name|test_vrev64q_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64q_p16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I]]
end_comment

begin_function
name|poly16x8_t
name|test_vrev64q_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrev64q_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %a,<4 x i32><i32 1, i32 0, i32 3, i32 2>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrev64q_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrev64q_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddl_s8(
end_comment

begin_comment
comment|// CHECK:   [[VPADDL_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.saddlp.v4i16.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VPADDL_I]]
end_comment

begin_function
name|int16x4_t
name|test_vpaddl_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddl_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADDL1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.saddlp.v2i32.v4i16(<4 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VPADDL1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vpaddl_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddl_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADDL1_I:%.*]] = call<1 x i64> @llvm.aarch64.neon.saddlp.v1i64.v2i32(<2 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VPADDL1_I]]
end_comment

begin_function
name|int64x1_t
name|test_vpaddl_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddl_u8(
end_comment

begin_comment
comment|// CHECK:   [[VPADDL_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.uaddlp.v4i16.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VPADDL_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vpaddl_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddl_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADDL1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.uaddlp.v2i32.v4i16(<4 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VPADDL1_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vpaddl_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddl_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADDL1_I:%.*]] = call<1 x i64> @llvm.aarch64.neon.uaddlp.v1i64.v2i32(<2 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[VPADDL1_I]]
end_comment

begin_function
name|uint64x1_t
name|test_vpaddl_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vpaddl_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddlq_s8(
end_comment

begin_comment
comment|// CHECK:   [[VPADDL_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.saddlp.v8i16.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VPADDL_I]]
end_comment

begin_function
name|int16x8_t
name|test_vpaddlq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddlq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADDL1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.saddlp.v4i32.v8i16(<8 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VPADDL1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vpaddlq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddlq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADDL1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.saddlp.v2i64.v4i32(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VPADDL1_I]]
end_comment

begin_function
name|int64x2_t
name|test_vpaddlq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddlq_u8(
end_comment

begin_comment
comment|// CHECK:   [[VPADDL_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.uaddlp.v8i16.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VPADDL_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vpaddlq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddlq_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADDL1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.uaddlp.v4i32.v8i16(<8 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VPADDL1_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vpaddlq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpaddlq_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADDL1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.uaddlp.v2i64.v4i32(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VPADDL1_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vpaddlq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vpaddlq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadal_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.saddlp.v4i16.v8i8(<8 x i8> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = add<4 x i16> [[VPADAL_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[TMP1]]
end_comment

begin_function
name|int16x4_t
name|test_vpadal_s8
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vpadal_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadal_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.saddlp.v2i32.v4i16(<4 x i16> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = add<2 x i32> [[VPADAL1_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[TMP2]]
end_comment

begin_function
name|int32x2_t
name|test_vpadal_s16
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vpadal_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadal_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL1_I:%.*]] = call<1 x i64> @llvm.aarch64.neon.saddlp.v1i64.v2i32(<2 x i32> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = add<1 x i64> [[VPADAL1_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[TMP2]]
end_comment

begin_function
name|int64x1_t
name|test_vpadal_s32
parameter_list|(
name|int64x1_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpadal_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadal_u8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.uaddlp.v4i16.v8i8(<8 x i8> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = add<4 x i16> [[VPADAL_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[TMP1]]
end_comment

begin_function
name|uint16x4_t
name|test_vpadal_u8
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint8x8_t
name|b
parameter_list|)
block|{
return|return
name|vpadal_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadal_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.uaddlp.v2i32.v4i16(<4 x i16> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = add<2 x i32> [[VPADAL1_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[TMP2]]
end_comment

begin_function
name|uint32x2_t
name|test_vpadal_u16
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint16x4_t
name|b
parameter_list|)
block|{
return|return
name|vpadal_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadal_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL1_I:%.*]] = call<1 x i64> @llvm.aarch64.neon.uaddlp.v1i64.v2i32(<2 x i32> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = add<1 x i64> [[VPADAL1_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<1 x i64> [[TMP2]]
end_comment

begin_function
name|uint64x1_t
name|test_vpadal_u32
parameter_list|(
name|uint64x1_t
name|a
parameter_list|,
name|uint32x2_t
name|b
parameter_list|)
block|{
return|return
name|vpadal_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadalq_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.saddlp.v8i16.v16i8(<16 x i8> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = add<8 x i16> [[VPADAL_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[TMP1]]
end_comment

begin_function
name|int16x8_t
name|test_vpadalq_s8
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vpadalq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadalq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.saddlp.v4i32.v8i16(<8 x i16> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = add<4 x i32> [[VPADAL1_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[TMP2]]
end_comment

begin_function
name|int32x4_t
name|test_vpadalq_s16
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vpadalq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadalq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.saddlp.v2i64.v4i32(<4 x i32> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = add<2 x i64> [[VPADAL1_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[TMP2]]
end_comment

begin_function
name|int64x2_t
name|test_vpadalq_s32
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vpadalq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadalq_u8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.uaddlp.v8i16.v16i8(<16 x i8> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = add<8 x i16> [[VPADAL_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[TMP1]]
end_comment

begin_function
name|uint16x8_t
name|test_vpadalq_u8
parameter_list|(
name|uint16x8_t
name|a
parameter_list|,
name|uint8x16_t
name|b
parameter_list|)
block|{
return|return
name|vpadalq_u8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadalq_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.uaddlp.v4i32.v8i16(<8 x i16> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = add<4 x i32> [[VPADAL1_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[TMP2]]
end_comment

begin_function
name|uint32x4_t
name|test_vpadalq_u16
parameter_list|(
name|uint32x4_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vpadalq_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vpadalq_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VPADAL1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.uaddlp.v2i64.v4i32(<4 x i32> %b)
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = add<2 x i64> [[VPADAL1_I]], %a
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[TMP2]]
end_comment

begin_function
name|uint64x2_t
name|test_vpadalq_u32
parameter_list|(
name|uint64x2_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vpadalq_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqabs_s8(
end_comment

begin_comment
comment|// CHECK:   [[VQABS_V_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.sqabs.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VQABS_V_I]]
end_comment

begin_function
name|int8x8_t
name|test_vqabs_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vqabs_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqabsq_s8(
end_comment

begin_comment
comment|// CHECK:   [[VQABSQ_V_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.sqabs.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VQABSQ_V_I]]
end_comment

begin_function
name|int8x16_t
name|test_vqabsq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vqabsq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqabs_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQABS_V1_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqabs.v4i16(<4 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQABS_V2_I:%.*]] = bitcast<4 x i16> [[VQABS_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQABS_V1_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqabs_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vqabs_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqabsq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQABSQ_V1_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqabs.v8i16(<8 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQABSQ_V2_I:%.*]] = bitcast<8 x i16> [[VQABSQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQABSQ_V1_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqabsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqabsq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqabs_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQABS_V1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqabs.v2i32(<2 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQABS_V2_I:%.*]] = bitcast<2 x i32> [[VQABS_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQABS_V1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqabs_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vqabs_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqabsq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQABSQ_V1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqabs.v4i32(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQABSQ_V2_I:%.*]] = bitcast<4 x i32> [[VQABSQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQABSQ_V1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqabsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqabsq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqabsq_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQABSQ_V1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqabs.v2i64(<2 x i64> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQABSQ_V2_I:%.*]] = bitcast<2 x i64> [[VQABSQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQABSQ_V1_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqabsq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqabsq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqneg_s8(
end_comment

begin_comment
comment|// CHECK:   [[VQNEG_V_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.sqneg.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VQNEG_V_I]]
end_comment

begin_function
name|int8x8_t
name|test_vqneg_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vqneg_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqnegq_s8(
end_comment

begin_comment
comment|// CHECK:   [[VQNEGQ_V_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.sqneg.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VQNEGQ_V_I]]
end_comment

begin_function
name|int8x16_t
name|test_vqnegq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vqnegq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqneg_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQNEG_V1_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqneg.v4i16(<4 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQNEG_V2_I:%.*]] = bitcast<4 x i16> [[VQNEG_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQNEG_V1_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqneg_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vqneg_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqnegq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQNEGQ_V1_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.sqneg.v8i16(<8 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQNEGQ_V2_I:%.*]] = bitcast<8 x i16> [[VQNEGQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VQNEGQ_V1_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqnegq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqnegq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqneg_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQNEG_V1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqneg.v2i32(<2 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQNEG_V2_I:%.*]] = bitcast<2 x i32> [[VQNEG_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQNEG_V1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqneg_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vqneg_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqnegq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQNEGQ_V1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqneg.v4i32(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQNEGQ_V2_I:%.*]] = bitcast<4 x i32> [[VQNEGQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VQNEGQ_V1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqnegq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqnegq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqnegq_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQNEGQ_V1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.sqneg.v2i64(<2 x i64> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQNEGQ_V2_I:%.*]] = bitcast<2 x i64> [[VQNEGQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VQNEGQ_V1_I]]
end_comment

begin_function
name|int64x2_t
name|test_vqnegq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqnegq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vneg_s8(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<8 x i8> zeroinitializer, %a
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[SUB_I]]
end_comment

begin_function
name|int8x8_t
name|test_vneg_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vneg_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vnegq_s8(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<16 x i8> zeroinitializer, %a
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SUB_I]]
end_comment

begin_function
name|int8x16_t
name|test_vnegq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vneg_s16(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<4 x i16> zeroinitializer, %a
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[SUB_I]]
end_comment

begin_function
name|int16x4_t
name|test_vneg_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vneg_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vnegq_s16(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<8 x i16> zeroinitializer, %a
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SUB_I]]
end_comment

begin_function
name|int16x8_t
name|test_vnegq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vneg_s32(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<2 x i32> zeroinitializer, %a
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[SUB_I]]
end_comment

begin_function
name|int32x2_t
name|test_vneg_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vneg_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vnegq_s32(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<4 x i32> zeroinitializer, %a
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SUB_I]]
end_comment

begin_function
name|int32x4_t
name|test_vnegq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vnegq_s64(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = sub<2 x i64> zeroinitializer, %a
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[SUB_I]]
end_comment

begin_function
name|int64x2_t
name|test_vnegq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vneg_f32(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = fsub<2 x float><float -0.000000e+00, float -0.000000e+00>, %a
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SUB_I]]
end_comment

begin_function
name|float32x2_t
name|test_vneg_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vneg_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vnegq_f32(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = fsub<4 x float><float -0.000000e+00, float -0.000000e+00, float -0.000000e+00, float -0.000000e+00>, %a
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SUB_I]]
end_comment

begin_function
name|float32x4_t
name|test_vnegq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vnegq_f64(
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %a
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SUB_I]]
end_comment

begin_function
name|float64x2_t
name|test_vnegq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vnegq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabs_s8(
end_comment

begin_comment
comment|// CHECK:   [[VABS_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.abs.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VABS_I]]
end_comment

begin_function
name|int8x8_t
name|test_vabs_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vabs_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabsq_s8(
end_comment

begin_comment
comment|// CHECK:   [[VABS_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.abs.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VABS_I]]
end_comment

begin_function
name|int8x16_t
name|test_vabsq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabs_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VABS1_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.abs.v4i16(<4 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VABS1_I]]
end_comment

begin_function
name|int16x4_t
name|test_vabs_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vabs_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabsq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VABS1_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.abs.v8i16(<8 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VABS1_I]]
end_comment

begin_function
name|int16x8_t
name|test_vabsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabs_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VABS1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.abs.v2i32(<2 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VABS1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vabs_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vabs_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabsq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VABS1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.abs.v4i32(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VABS1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vabsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabsq_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VABS1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.abs.v2i64(<2 x i64> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VABS1_I]]
end_comment

begin_function
name|int64x2_t
name|test_vabsq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabs_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VABS1_I:%.*]] = call<2 x float> @llvm.fabs.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VABS1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vabs_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vabs_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabsq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VABS1_I:%.*]] = call<4 x float> @llvm.fabs.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VABS1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vabsq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vabsq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VABS1_I:%.*]] = call<2 x double> @llvm.fabs.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VABS1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vabsq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vabsq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuqadd_s8(
end_comment

begin_comment
comment|// CHECK:   [[VUQADD_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.suqadd.v8i8(<8 x i8> %a,<8 x i8> %b)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VUQADD_I]]
end_comment

begin_function
name|int8x8_t
name|test_vuqadd_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int8x8_t
name|b
parameter_list|)
block|{
return|return
name|vuqadd_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuqaddq_s8(
end_comment

begin_comment
comment|// CHECK:   [[VUQADD_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.suqadd.v16i8(<16 x i8> %a,<16 x i8> %b)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VUQADD_I]]
end_comment

begin_function
name|int8x16_t
name|test_vuqaddq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|,
name|int8x16_t
name|b
parameter_list|)
block|{
return|return
name|vuqaddq_s8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuqadd_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VUQADD2_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.suqadd.v4i16(<4 x i16> %a,<4 x i16> %b)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VUQADD2_I]]
end_comment

begin_function
name|int16x4_t
name|test_vuqadd_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vuqadd_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuqaddq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VUQADD2_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.suqadd.v8i16(<8 x i16> %a,<8 x i16> %b)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VUQADD2_I]]
end_comment

begin_function
name|int16x8_t
name|test_vuqaddq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vuqaddq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuqadd_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VUQADD2_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.suqadd.v2i32(<2 x i32> %a,<2 x i32> %b)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VUQADD2_I]]
end_comment

begin_function
name|int32x2_t
name|test_vuqadd_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vuqadd_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuqaddq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VUQADD2_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.suqadd.v4i32(<4 x i32> %a,<4 x i32> %b)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VUQADD2_I]]
end_comment

begin_function
name|int32x4_t
name|test_vuqaddq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vuqaddq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vuqaddq_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VUQADD2_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.suqadd.v2i64(<2 x i64> %a,<2 x i64> %b)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VUQADD2_I]]
end_comment

begin_function
name|int64x2_t
name|test_vuqaddq_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vuqaddq_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcls_s8(
end_comment

begin_comment
comment|// CHECK:   [[VCLS_V_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.cls.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCLS_V_I]]
end_comment

begin_function
name|int8x8_t
name|test_vcls_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcls_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclsq_s8(
end_comment

begin_comment
comment|// CHECK:   [[VCLSQ_V_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.cls.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCLSQ_V_I]]
end_comment

begin_function
name|int8x16_t
name|test_vclsq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vclsq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcls_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLS_V1_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.cls.v4i16(<4 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   [[VCLS_V2_I:%.*]] = bitcast<4 x i16> [[VCLS_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCLS_V1_I]]
end_comment

begin_function
name|int16x4_t
name|test_vcls_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcls_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclsq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLSQ_V1_I:%.*]] = call<8 x i16> @llvm.aarch64.neon.cls.v8i16(<8 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   [[VCLSQ_V2_I:%.*]] = bitcast<8 x i16> [[VCLSQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCLSQ_V1_I]]
end_comment

begin_function
name|int16x8_t
name|test_vclsq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vclsq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcls_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLS_V1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.cls.v2i32(<2 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   [[VCLS_V2_I:%.*]] = bitcast<2 x i32> [[VCLS_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCLS_V1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vcls_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcls_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclsq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLSQ_V1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.cls.v4i32(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   [[VCLSQ_V2_I:%.*]] = bitcast<4 x i32> [[VCLSQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCLSQ_V1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vclsq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclsq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclz_s8(
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V_I:%.*]] = call<8 x i8> @llvm.ctlz.v8i8(<8 x i8> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCLZ_V_I]]
end_comment

begin_function
name|int8x8_t
name|test_vclz_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclzq_s8(
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V_I:%.*]] = call<16 x i8> @llvm.ctlz.v16i8(<16 x i8> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCLZQ_V_I]]
end_comment

begin_function
name|int8x16_t
name|test_vclzq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclz_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V1_I:%.*]] = call<4 x i16> @llvm.ctlz.v4i16(<4 x i16> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast<4 x i16> [[VCLZ_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCLZ_V1_I]]
end_comment

begin_function
name|int16x4_t
name|test_vclz_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclzq_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V1_I:%.*]] = call<8 x i16> @llvm.ctlz.v8i16(<8 x i16> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V2_I:%.*]] = bitcast<8 x i16> [[VCLZQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCLZQ_V1_I]]
end_comment

begin_function
name|int16x8_t
name|test_vclzq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclz_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V1_I:%.*]] = call<2 x i32> @llvm.ctlz.v2i32(<2 x i32> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast<2 x i32> [[VCLZ_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCLZ_V1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vclz_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vclz_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclzq_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V1_I:%.*]] = call<4 x i32> @llvm.ctlz.v4i32(<4 x i32> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V2_I:%.*]] = bitcast<4 x i32> [[VCLZQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCLZQ_V1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vclzq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclz_u8(
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V_I:%.*]] = call<8 x i8> @llvm.ctlz.v8i8(<8 x i8> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCLZ_V_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vclz_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vclz_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclzq_u8(
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V_I:%.*]] = call<16 x i8> @llvm.ctlz.v16i8(<16 x i8> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCLZQ_V_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vclzq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclz_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V1_I:%.*]] = call<4 x i16> @llvm.ctlz.v4i16(<4 x i16> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast<4 x i16> [[VCLZ_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VCLZ_V1_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vclz_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vclz_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclzq_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V1_I:%.*]] = call<8 x i16> @llvm.ctlz.v8i16(<8 x i16> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V2_I:%.*]] = bitcast<8 x i16> [[VCLZQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VCLZQ_V1_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vclzq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclz_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V1_I:%.*]] = call<2 x i32> @llvm.ctlz.v2i32(<2 x i32> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[VCLZ_V2_I:%.*]] = bitcast<2 x i32> [[VCLZ_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCLZ_V1_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vclz_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vclz_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vclzq_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V1_I:%.*]] = call<4 x i32> @llvm.ctlz.v4i32(<4 x i32> %a, i1 false)
end_comment

begin_comment
comment|// CHECK:   [[VCLZQ_V2_I:%.*]] = bitcast<4 x i32> [[VCLZQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCLZQ_V1_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vclzq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vclzq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcnt_s8(
end_comment

begin_comment
comment|// CHECK:   [[VCNT_V_I:%.*]] = call<8 x i8> @llvm.ctpop.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCNT_V_I]]
end_comment

begin_function
name|int8x8_t
name|test_vcnt_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcnt_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcntq_s8(
end_comment

begin_comment
comment|// CHECK:   [[VCNTQ_V_I:%.*]] = call<16 x i8> @llvm.ctpop.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCNTQ_V_I]]
end_comment

begin_function
name|int8x16_t
name|test_vcntq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcntq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcnt_u8(
end_comment

begin_comment
comment|// CHECK:   [[VCNT_V_I:%.*]] = call<8 x i8> @llvm.ctpop.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCNT_V_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vcnt_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcnt_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcntq_u8(
end_comment

begin_comment
comment|// CHECK:   [[VCNTQ_V_I:%.*]] = call<16 x i8> @llvm.ctpop.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCNTQ_V_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vcntq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcntq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcnt_p8(
end_comment

begin_comment
comment|// CHECK:   [[VCNT_V_I:%.*]] = call<8 x i8> @llvm.ctpop.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VCNT_V_I]]
end_comment

begin_function
name|poly8x8_t
name|test_vcnt_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vcnt_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcntq_p8(
end_comment

begin_comment
comment|// CHECK:   [[VCNTQ_V_I:%.*]] = call<16 x i8> @llvm.ctpop.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VCNTQ_V_I]]
end_comment

begin_function
name|poly8x16_t
name|test_vcntq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vcntq_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvn_s8(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i8> %a,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[NEG_I]]
end_comment

begin_function
name|int8x8_t
name|test_vmvn_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvnq_s8(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<16 x i8> %a,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[NEG_I]]
end_comment

begin_function
name|int8x16_t
name|test_vmvnq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvn_s16(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i16> %a,<i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[NEG_I]]
end_comment

begin_function
name|int16x4_t
name|test_vmvn_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvnq_s16(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i16> %a,<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[NEG_I]]
end_comment

begin_function
name|int16x8_t
name|test_vmvnq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvn_s32(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i32> %a,<i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[NEG_I]]
end_comment

begin_function
name|int32x2_t
name|test_vmvn_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvnq_s32(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i32> %a,<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[NEG_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmvnq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvn_u8(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i8> %a,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[NEG_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vmvn_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvnq_u8(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<16 x i8> %a,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[NEG_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vmvnq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvn_u16(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i16> %a,<i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[NEG_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vmvn_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvnq_u16(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i16> %a,<i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[NEG_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vmvnq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvn_u32(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<2 x i32> %a,<i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[NEG_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vmvn_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvnq_u32(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<4 x i32> %a,<i32 -1, i32 -1, i32 -1, i32 -1>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[NEG_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vmvnq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvn_p8(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<8 x i8> %a,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[NEG_I]]
end_comment

begin_function
name|poly8x8_t
name|test_vmvn_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmvn_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmvnq_p8(
end_comment

begin_comment
comment|// CHECK:   [[NEG_I:%.*]] = xor<16 x i8> %a,<i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[NEG_I]]
end_comment

begin_function
name|poly8x16_t
name|test_vmvnq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vmvnq_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrbit_s8(
end_comment

begin_comment
comment|// CHECK:   [[VRBIT_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.rbit.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VRBIT_I]]
end_comment

begin_function
name|int8x8_t
name|test_vrbit_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrbit_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrbitq_s8(
end_comment

begin_comment
comment|// CHECK:   [[VRBIT_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.rbit.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VRBIT_I]]
end_comment

begin_function
name|int8x16_t
name|test_vrbitq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrbitq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrbit_u8(
end_comment

begin_comment
comment|// CHECK:   [[VRBIT_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.rbit.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VRBIT_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vrbit_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrbit_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrbitq_u8(
end_comment

begin_comment
comment|// CHECK:   [[VRBIT_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.rbit.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VRBIT_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vrbitq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrbitq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrbit_p8(
end_comment

begin_comment
comment|// CHECK:   [[VRBIT_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.rbit.v8i8(<8 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VRBIT_I]]
end_comment

begin_function
name|poly8x8_t
name|test_vrbit_p8
parameter_list|(
name|poly8x8_t
name|a
parameter_list|)
block|{
return|return
name|vrbit_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrbitq_p8(
end_comment

begin_comment
comment|// CHECK:   [[VRBIT_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.rbit.v16i8(<16 x i8> %a)
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[VRBIT_I]]
end_comment

begin_function
name|poly8x16_t
name|test_vrbitq_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vrbitq_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I:%.*]] = trunc<8 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VMOVN_I]]
end_comment

begin_function
name|int8x8_t
name|test_vmovn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I:%.*]] = trunc<4 x i32> %a to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VMOVN_I]]
end_comment

begin_function
name|int16x4_t
name|test_vmovn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I:%.*]] = trunc<2 x i64> %a to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VMOVN_I]]
end_comment

begin_function
name|int32x2_t
name|test_vmovn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I:%.*]] = trunc<8 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VMOVN_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vmovn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I:%.*]] = trunc<4 x i32> %a to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VMOVN_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vmovn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_u64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I:%.*]] = trunc<2 x i64> %a to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VMOVN_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vmovn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vmovn_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_high_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I_I:%.*]] = trunc<8 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> [[VMOVN_I_I]],<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int8x16_t
name|test_vmovn_high_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vmovn_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_high_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I_I:%.*]] = trunc<4 x i32> %b to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> [[VMOVN_I_I]],<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int16x8_t
name|test_vmovn_high_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmovn_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_high_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I_I:%.*]] = trunc<2 x i64> %b to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> [[VMOVN_I_I]],<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmovn_high_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vmovn_high_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_high_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I_I:%.*]] = trunc<8 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> [[VMOVN_I_I]],<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int8x16_t
name|test_vmovn_high_u16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vmovn_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_high_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I_I:%.*]] = trunc<4 x i32> %b to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> [[VMOVN_I_I]],<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int16x8_t
name|test_vmovn_high_u32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmovn_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vmovn_high_u64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMOVN_I_I:%.*]] = trunc<2 x i64> %b to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> [[VMOVN_I_I]],<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vmovn_high_u64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vmovn_high_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovun_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V1_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.sqxtun.v8i8(<8 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VQMOVUN_V1_I]]
end_comment

begin_function
name|int8x8_t
name|test_vqmovun_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqmovun_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovun_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V1_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqxtun.v4i16(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V2_I:%.*]] = bitcast<4 x i16> [[VQMOVUN_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQMOVUN_V1_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqmovun_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqmovun_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovun_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqxtun.v2i32(<2 x i64> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V2_I:%.*]] = bitcast<2 x i32> [[VQMOVUN_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQMOVUN_V1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqmovun_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqmovun_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovun_high_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V1_I_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.sqxtun.v8i8(<8 x i16> %b)
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> [[VQMOVUN_V1_I_I]],<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int8x16_t
name|test_vqmovun_high_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqmovun_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovun_high_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V1_I_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqxtun.v4i16(<4 x i32> %b)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V2_I_I:%.*]] = bitcast<4 x i16> [[VQMOVUN_V1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> [[VQMOVUN_V1_I_I]],<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqmovun_high_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqmovun_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovun_high_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V1_I_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqxtun.v2i32(<2 x i64> %b)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVUN_V2_I_I:%.*]] = bitcast<2 x i32> [[VQMOVUN_V1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> [[VQMOVUN_V1_I_I]],<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqmovun_high_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqmovun_high_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.sqxtn.v8i8(<8 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VQMOVN_V1_I]]
end_comment

begin_function
name|int8x8_t
name|test_vqmovn_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqxtn.v4i16(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V2_I:%.*]] = bitcast<4 x i16> [[VQMOVN_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQMOVN_V1_I]]
end_comment

begin_function
name|int16x4_t
name|test_vqmovn_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqxtn.v2i32(<2 x i64> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V2_I:%.*]] = bitcast<2 x i32> [[VQMOVN_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQMOVN_V1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vqmovn_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_high_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.sqxtn.v8i8(<8 x i16> %b)
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> [[VQMOVN_V1_I_I]],<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int8x16_t
name|test_vqmovn_high_s16
parameter_list|(
name|int8x8_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqmovn_high_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_high_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqxtn.v4i16(<4 x i32> %b)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V2_I_I:%.*]] = bitcast<4 x i16> [[VQMOVN_V1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> [[VQMOVN_V1_I_I]],<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int16x8_t
name|test_vqmovn_high_s32
parameter_list|(
name|int16x4_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqmovn_high_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_high_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.sqxtn.v2i32(<2 x i64> %b)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V2_I_I:%.*]] = bitcast<2 x i32> [[VQMOVN_V1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> [[VQMOVN_V1_I_I]],<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I_I]]
end_comment

begin_function
name|int32x4_t
name|test_vqmovn_high_s64
parameter_list|(
name|int32x2_t
name|a
parameter_list|,
name|int64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqmovn_high_s64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.uqxtn.v8i8(<8 x i16> %a)
end_comment

begin_comment
comment|// CHECK:   ret<8 x i8> [[VQMOVN_V1_I]]
end_comment

begin_function
name|uint8x8_t
name|test_vqmovn_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.uqxtn.v4i16(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V2_I:%.*]] = bitcast<4 x i16> [[VQMOVN_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i16> [[VQMOVN_V1_I]]
end_comment

begin_function
name|uint16x4_t
name|test_vqmovn_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_u64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.uqxtn.v2i32(<2 x i64> %a)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V2_I:%.*]] = bitcast<2 x i32> [[VQMOVN_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VQMOVN_V1_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vqmovn_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vqmovn_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_high_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I_I:%.*]] = call<8 x i8> @llvm.aarch64.neon.uqxtn.v8i8(<8 x i16> %b)
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x i8> %a,<8 x i8> [[VQMOVN_V1_I_I]],<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[SHUFFLE_I_I]]
end_comment

begin_function
name|uint8x16_t
name|test_vqmovn_high_u16
parameter_list|(
name|uint8x8_t
name|a
parameter_list|,
name|uint16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqmovn_high_u16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_high_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.uqxtn.v4i16(<4 x i32> %b)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V2_I_I:%.*]] = bitcast<4 x i16> [[VQMOVN_V1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x i16> %a,<4 x i16> [[VQMOVN_V1_I_I]],<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[SHUFFLE_I_I]]
end_comment

begin_function
name|uint16x8_t
name|test_vqmovn_high_u32
parameter_list|(
name|uint16x4_t
name|a
parameter_list|,
name|uint32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqmovn_high_u32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vqmovn_high_u64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V1_I_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.uqxtn.v2i32(<2 x i64> %b)
end_comment

begin_comment
comment|// CHECK:   [[VQMOVN_V2_I_I:%.*]] = bitcast<2 x i32> [[VQMOVN_V1_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<2 x i32> %a,<2 x i32> [[VQMOVN_V1_I_I]],<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[SHUFFLE_I_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vqmovn_high_u64
parameter_list|(
name|uint32x2_t
name|a
parameter_list|,
name|uint64x2_t
name|b
parameter_list|)
block|{
return|return
name|vqmovn_high_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_n_s8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = sext<8 x i8> %a to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<8 x i16> [[TMP0]],<i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VSHLL_N]]
end_comment

begin_function
name|int16x8_t
name|test_vshll_n_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_s8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = sext<4 x i16> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<4 x i32> [[TMP2]],<i32 16, i32 16, i32 16, i32 16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VSHLL_N]]
end_comment

begin_function
name|int32x4_t
name|test_vshll_n_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_s16
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = sext<2 x i32> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<2 x i64> [[TMP2]],<i64 32, i64 32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSHLL_N]]
end_comment

begin_function
name|int64x2_t
name|test_vshll_n_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_s32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_n_u8(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = zext<8 x i8> %a to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<8 x i16> [[TMP0]],<i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VSHLL_N]]
end_comment

begin_function
name|uint16x8_t
name|test_vshll_n_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_u8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = zext<4 x i16> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<4 x i32> [[TMP2]],<i32 16, i32 16, i32 16, i32 16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VSHLL_N]]
end_comment

begin_function
name|uint32x4_t
name|test_vshll_n_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_u16
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = zext<2 x i32> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<2 x i64> [[TMP2]],<i64 32, i64 32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSHLL_N]]
end_comment

begin_function
name|uint64x2_t
name|test_vshll_n_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vshll_n_u32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_high_n_s8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = sext<8 x i8> [[SHUFFLE_I]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<8 x i16> [[TMP0]],<i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VSHLL_N]]
end_comment

begin_function
name|int16x8_t
name|test_vshll_high_n_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vshll_high_n_s8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_high_n_s16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = sext<4 x i16> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<4 x i32> [[TMP2]],<i32 16, i32 16, i32 16, i32 16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VSHLL_N]]
end_comment

begin_function
name|int32x4_t
name|test_vshll_high_n_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vshll_high_n_s16
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_high_n_s32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = sext<2 x i32> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<2 x i64> [[TMP2]],<i64 32, i64 32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSHLL_N]]
end_comment

begin_function
name|int64x2_t
name|test_vshll_high_n_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vshll_high_n_s32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_high_n_u8(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<16 x i8> %a,<16 x i8> %a,<8 x i32><i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = zext<8 x i8> [[SHUFFLE_I]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<8 x i16> [[TMP0]],<i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8, i16 8>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[VSHLL_N]]
end_comment

begin_function
name|uint16x8_t
name|test_vshll_high_n_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vshll_high_n_u8
argument_list|(
name|a
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_high_n_u16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<8 x i16> %a,<8 x i16> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = zext<4 x i16> [[TMP1]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<4 x i32> [[TMP2]],<i32 16, i32 16, i32 16, i32 16>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VSHLL_N]]
end_comment

begin_function
name|uint32x4_t
name|test_vshll_high_n_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vshll_high_n_u16
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vshll_high_n_u32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<4 x i32> %a,<4 x i32> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> [[SHUFFLE_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = zext<2 x i32> [[TMP1]] to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   [[VSHLL_N:%.*]] = shl<2 x i64> [[TMP2]],<i64 32, i64 32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VSHLL_N]]
end_comment

begin_function
name|uint64x2_t
name|test_vshll_high_n_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vshll_high_n_u32
argument_list|(
name|a
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_f16_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F16_F321_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.vcvtfp2hf(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F16_F322_I:%.*]] = bitcast<4 x i16> [[VCVT_F16_F321_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[VCVT_F16_F322_I]] to<4 x half>
end_comment

begin_comment
comment|// CHECK:   ret<4 x half> [[TMP1]]
end_comment

begin_function
name|float16x4_t
name|test_vcvt_f16_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f16_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_high_f16_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F16_F321_I_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.vcvtfp2hf(<4 x float> %b)
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F16_F322_I_I:%.*]] = bitcast<4 x i16> [[VCVT_F16_F321_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[VCVT_F16_F322_I_I]] to<4 x half>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x half> %a,<4 x half> [[TMP1]],<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   ret<8 x half> [[SHUFFLE_I_I]]
end_comment

begin_function
name|float16x8_t
name|test_vcvt_high_f16_f32
parameter_list|(
name|float16x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vcvt_high_f16_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_f32_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I:%.*]] = fptrunc<2 x double> %a to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VCVT_I]]
end_comment

begin_function
name|float32x2_t
name|test_vcvt_f32_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_high_f32_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I_I:%.*]] = fptrunc<2 x double> %b to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<2 x float> %a,<2 x float> [[VCVT_I_I]],<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I_I]]
end_comment

begin_function
name|float32x4_t
name|test_vcvt_high_f32_f64
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
return|return
name|vcvt_high_f32_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtx_f32_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTX_F32_V1_I:%.*]] = call<2 x float> @llvm.aarch64.neon.fcvtxn.v2f32.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VCVTX_F32_V1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vcvtx_f32_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtx_f32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtx_high_f32_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTX_F32_V1_I_I:%.*]] = call<2 x float> @llvm.aarch64.neon.fcvtxn.v2f32.v2f64(<2 x double> %b)
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<2 x float> %a,<2 x float> [[VCVTX_F32_V1_I_I]],<4 x i32><i32 0, i32 1, i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SHUFFLE_I_I]]
end_comment

begin_function
name|float32x4_t
name|test_vcvtx_high_f32_f64
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
return|return
name|vcvtx_high_f32_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_f32_f16(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x half> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F32_F16_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F32_F161_I:%.*]] = call<4 x float> @llvm.aarch64.neon.vcvthf2fp(<4 x i16> [[VCVT_F32_F16_I]])
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F32_F162_I:%.*]] = bitcast<4 x float> [[VCVT_F32_F161_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VCVT_F32_F161_I]]
end_comment

begin_function
name|float32x4_t
name|test_vcvt_f32_f16
parameter_list|(
name|float16x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_high_f32_f16(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<8 x half> %a,<8 x half> %a,<4 x i32><i32 4, i32 5, i32 6, i32 7>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x half> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F32_F16_I_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F32_F161_I_I:%.*]] = call<4 x float> @llvm.aarch64.neon.vcvthf2fp(<4 x i16> [[VCVT_F32_F16_I_I]])
end_comment

begin_comment
comment|// CHECK:   [[VCVT_F32_F162_I_I:%.*]] = bitcast<4 x float> [[VCVT_F32_F161_I_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VCVT_F32_F161_I_I]]
end_comment

begin_function
name|float32x4_t
name|test_vcvt_high_f32_f16
parameter_list|(
name|float16x8_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_high_f32_f16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_f64_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I:%.*]] = fpext<2 x float> %a to<2 x double>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VCVT_I]]
end_comment

begin_function
name|float64x2_t
name|test_vcvt_f64_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_high_f64_f32(
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<4 x float> %a,<4 x float> %a,<2 x i32><i32 2, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> [[SHUFFLE_I_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I_I:%.*]] = fpext<2 x float> [[SHUFFLE_I_I]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VCVT_I_I]]
end_comment

begin_function
name|float64x2_t
name|test_vcvt_high_f64_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_high_f64_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndn_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDN1_I:%.*]] = call<2 x float> @llvm.aarch64.neon.frintn.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VRNDN1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrndn_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndn_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndnq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDN1_I:%.*]] = call<4 x float> @llvm.aarch64.neon.frintn.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VRNDN1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrndnq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndnq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndnq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDN1_I:%.*]] = call<2 x double> @llvm.aarch64.neon.frintn.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VRNDN1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vrndnq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndnq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrnda_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDA1_I:%.*]] = call<2 x float> @llvm.round.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VRNDA1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrnda_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrnda_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndaq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDA1_I:%.*]] = call<4 x float> @llvm.round.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VRNDA1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrndaq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndaq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndaq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDA1_I:%.*]] = call<2 x double> @llvm.round.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VRNDA1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vrndaq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndaq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndp_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDP1_I:%.*]] = call<2 x float> @llvm.ceil.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VRNDP1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrndp_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndp_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndpq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDP1_I:%.*]] = call<4 x float> @llvm.ceil.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VRNDP1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrndpq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndpq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndpq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDP1_I:%.*]] = call<2 x double> @llvm.ceil.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VRNDP1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vrndpq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndpq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndm_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDM1_I:%.*]] = call<2 x float> @llvm.floor.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VRNDM1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrndm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndm_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndmq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDM1_I:%.*]] = call<4 x float> @llvm.floor.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VRNDM1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrndmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndmq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndmq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDM1_I:%.*]] = call<2 x double> @llvm.floor.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VRNDM1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vrndmq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndmq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndx_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDX1_I:%.*]] = call<2 x float> @llvm.rint.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VRNDX1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrndx_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndx_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndxq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDX1_I:%.*]] = call<4 x float> @llvm.rint.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VRNDX1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrndxq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndxq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndxq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDX1_I:%.*]] = call<2 x double> @llvm.rint.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VRNDX1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vrndxq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndxq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrnd_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDZ1_I:%.*]] = call<2 x float> @llvm.trunc.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VRNDZ1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrnd_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrnd_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDZ1_I:%.*]] = call<4 x float> @llvm.trunc.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VRNDZ1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrndq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDZ1_I:%.*]] = call<2 x double> @llvm.trunc.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VRNDZ1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vrndq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndi_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDI1_I:%.*]] = call<2 x float> @llvm.nearbyint.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VRNDI1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrndi_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndi_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndiq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDI1_I:%.*]] = call<4 x float> @llvm.nearbyint.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VRNDI1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrndiq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndiq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrndiq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDI1_I:%.*]] = call<2 x double> @llvm.nearbyint.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VRNDI1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vrndiq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndiq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fptosi<2 x float> %a to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[TMP1]]
end_comment

begin_function
name|int32x2_t
name|test_vcvt_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtq_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fptosi<4 x float> %a to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[TMP1]]
end_comment

begin_function
name|int32x4_t
name|test_vcvtq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtq_s64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fptosi<2 x double> %a to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[TMP1]]
end_comment

begin_function
name|int64x2_t
name|test_vcvtq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fptoui<2 x float> %a to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[TMP1]]
end_comment

begin_function
name|uint32x2_t
name|test_vcvt_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtq_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fptoui<4 x float> %a to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[TMP1]]
end_comment

begin_function
name|uint32x4_t
name|test_vcvtq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtq_u64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = fptoui<2 x double> %a to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[TMP1]]
end_comment

begin_function
name|uint64x2_t
name|test_vcvtq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtn_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTN1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.fcvtns.v2i32.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTN1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vcvtn_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtn_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtnq_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTN1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.fcvtns.v4i32.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTN1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vcvtnq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtnq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtnq_s64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTN1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.fcvtns.v2i64.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCVTN1_I]]
end_comment

begin_function
name|int64x2_t
name|test_vcvtnq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtnq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtn_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTN1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.fcvtnu.v2i32.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTN1_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcvtn_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtn_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtnq_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTN1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.fcvtnu.v4i32.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTN1_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcvtnq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtnq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtnq_u64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTN1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.fcvtnu.v2i64.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCVTN1_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcvtnq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtnq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtp_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTP1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.fcvtps.v2i32.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTP1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vcvtp_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtp_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtpq_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTP1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.fcvtps.v4i32.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTP1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vcvtpq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtpq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtpq_s64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTP1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.fcvtps.v2i64.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCVTP1_I]]
end_comment

begin_function
name|int64x2_t
name|test_vcvtpq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtpq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtp_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTP1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.fcvtpu.v2i32.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTP1_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcvtp_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtp_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtpq_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTP1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.fcvtpu.v4i32.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTP1_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcvtpq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtpq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtpq_u64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTP1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.fcvtpu.v2i64.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCVTP1_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcvtpq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtpq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtm_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTM1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.fcvtms.v2i32.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTM1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vcvtm_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtm_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtmq_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTM1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.fcvtms.v4i32.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTM1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vcvtmq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtmq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtmq_s64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTM1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.fcvtms.v2i64.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCVTM1_I]]
end_comment

begin_function
name|int64x2_t
name|test_vcvtmq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtmq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtm_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTM1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.fcvtmu.v2i32.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTM1_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcvtm_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtm_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtmq_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTM1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.fcvtmu.v4i32.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTM1_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcvtmq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtmq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtmq_u64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTM1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.fcvtmu.v2i64.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCVTM1_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcvtmq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtmq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvta_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTA1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.fcvtas.v2i32.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTA1_I]]
end_comment

begin_function
name|int32x2_t
name|test_vcvta_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvta_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtaq_s32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTA1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.fcvtas.v4i32.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTA1_I]]
end_comment

begin_function
name|int32x4_t
name|test_vcvtaq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtaq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtaq_s64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTA1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.fcvtas.v2i64.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCVTA1_I]]
end_comment

begin_function
name|int64x2_t
name|test_vcvtaq_s64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtaq_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvta_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTA1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.fcvtau.v2i32.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTA1_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vcvta_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvta_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtaq_u32_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTA1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.fcvtau.v4i32.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTA1_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vcvtaq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtaq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtaq_u64_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVTA1_I:%.*]] = call<2 x i64> @llvm.aarch64.neon.fcvtau.v2i64.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[VCVTA1_I]]
end_comment

begin_function
name|uint64x2_t
name|test_vcvtaq_u64_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtaq_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrsqrte_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRSQRTE_V1_I:%.*]] = call<2 x float> @llvm.aarch64.neon.frsqrte.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VRSQRTE_V1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrsqrte_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrsqrte_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrsqrteq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRSQRTEQ_V1_I:%.*]] = call<4 x float> @llvm.aarch64.neon.frsqrte.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VRSQRTEQ_V1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrsqrteq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrsqrteq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrsqrteq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRSQRTEQ_V1_I:%.*]] = call<2 x double> @llvm.aarch64.neon.frsqrte.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VRSQRTEQ_V1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vrsqrteq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrsqrteq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrecpe_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRECPE_V1_I:%.*]] = call<2 x float> @llvm.aarch64.neon.frecpe.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VRECPE_V1_I]]
end_comment

begin_function
name|float32x2_t
name|test_vrecpe_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrecpe_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrecpeq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRECPEQ_V1_I:%.*]] = call<4 x float> @llvm.aarch64.neon.frecpe.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VRECPEQ_V1_I]]
end_comment

begin_function
name|float32x4_t
name|test_vrecpeq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrecpeq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrecpeq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRECPEQ_V1_I:%.*]] = call<2 x double> @llvm.aarch64.neon.frecpe.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VRECPEQ_V1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vrecpeq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vrecpeq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrecpe_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRECPE_V1_I:%.*]] = call<2 x i32> @llvm.aarch64.neon.urecpe.v2i32(<2 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VRECPE_V1_I]]
end_comment

begin_function
name|uint32x2_t
name|test_vrecpe_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrecpe_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vrecpeq_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRECPEQ_V1_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.urecpe.v4i32(<4 x i32> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VRECPEQ_V1_I]]
end_comment

begin_function
name|uint32x4_t
name|test_vrecpeq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrecpeq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vsqrt_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VSQRT_I:%.*]] = call<2 x float> @llvm.sqrt.v2f32(<2 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VSQRT_I]]
end_comment

begin_function
name|float32x2_t
name|test_vsqrt_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vsqrt_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vsqrtq_f32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VSQRT_I:%.*]] = call<4 x float> @llvm.sqrt.v4f32(<4 x float> %a)
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VSQRT_I]]
end_comment

begin_function
name|float32x4_t
name|test_vsqrtq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vsqrtq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vsqrtq_f64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VSQRT_I:%.*]] = call<2 x double> @llvm.sqrt.v2f64(<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VSQRT_I]]
end_comment

begin_function
name|float64x2_t
name|test_vsqrtq_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vsqrtq_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_f32_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I:%.*]] = sitofp<2 x i32> %a to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VCVT_I]]
end_comment

begin_function
name|float32x2_t
name|test_vcvt_f32_s32
parameter_list|(
name|int32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvt_f32_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I:%.*]] = uitofp<2 x i32> %a to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VCVT_I]]
end_comment

begin_function
name|float32x2_t
name|test_vcvt_f32_u32
parameter_list|(
name|uint32x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvt_f32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtq_f32_s32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I:%.*]] = sitofp<4 x i32> %a to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VCVT_I]]
end_comment

begin_function
name|float32x4_t
name|test_vcvtq_f32_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_f32_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtq_f32_u32(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I:%.*]] = uitofp<4 x i32> %a to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VCVT_I]]
end_comment

begin_function
name|float32x4_t
name|test_vcvtq_f32_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_f32_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtq_f64_s64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I:%.*]] = sitofp<2 x i64> %a to<2 x double>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VCVT_I]]
end_comment

begin_function
name|float64x2_t
name|test_vcvtq_f64_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_f64_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: @test_vcvtq_f64_u64(
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VCVT_I:%.*]] = uitofp<2 x i64> %a to<2 x double>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VCVT_I]]
end_comment

begin_function
name|float64x2_t
name|test_vcvtq_f64_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vcvtq_f64_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

