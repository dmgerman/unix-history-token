begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7.0 -target-feature +neon -ffreestanding -emit-llvm -o - -O1 %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int8x8_t
name|test_vqshl_n_s8
parameter_list|(
name|int8x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshl_n_s8
comment|// CHECK: call<8 x i8> @llvm.aarch64.neon.sqshl.v8i8(<8 x i8> %in,<8 x i8><i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
return|return
name|vqshl_n_s8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x4_t
name|test_vqshl_n_s16
parameter_list|(
name|int16x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshl_n_s16
comment|// CHECK: call<4 x i16> @llvm.aarch64.neon.sqshl.v4i16(<4 x i16> %in,<4 x i16><i16 1, i16 1, i16 1, i16 1>)
return|return
name|vqshl_n_s16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|test_vqshl_n_s32
parameter_list|(
name|int32x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshl_n_s32
comment|// CHECK: call<2 x i32> @llvm.aarch64.neon.sqshl.v2i32(<2 x i32> %in,<2 x i32><i32 1, i32 1>)
return|return
name|vqshl_n_s32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vqshl_n_s64
parameter_list|(
name|int64x1_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshl_n_s64
comment|// CHECK: call<1 x i64> @llvm.aarch64.neon.sqshl.v1i64(<1 x i64> %in,<1 x i64><i64 1>)
return|return
name|vqshl_n_s64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x16_t
name|test_vqshlq_n_s8
parameter_list|(
name|int8x16_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlq_n_s8
comment|// CHECK: call<16 x i8> @llvm.aarch64.neon.sqshl.v16i8(<16 x i8> %in,<16 x i8><i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
return|return
name|vqshlq_n_s8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x8_t
name|test_vqshlq_n_s16
parameter_list|(
name|int16x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlq_n_s16
comment|// CHECK: call<8 x i16> @llvm.aarch64.neon.sqshl.v8i16(<8 x i16> %in,<8 x i16><i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>)
return|return
name|vqshlq_n_s16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x4_t
name|test_vqshlq_n_s32
parameter_list|(
name|int32x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlq_n_s32
comment|// CHECK: call<4 x i32> @llvm.aarch64.neon.sqshl.v4i32(<4 x i32> %in,<4 x i32><i32 1, i32 1, i32 1, i32 1>)
return|return
name|vqshlq_n_s32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x2_t
name|test_vqshlq_n_s64
parameter_list|(
name|int64x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlq_n_s64
comment|// CHECK: call<2 x i64> @llvm.aarch64.neon.sqshl.v2i64(<2 x i64> %in,<2 x i64><i64 1, i64 1>
return|return
name|vqshlq_n_s64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x8_t
name|test_vqshl_n_u8
parameter_list|(
name|uint8x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshl_n_u8
comment|// CHECK: call<8 x i8> @llvm.aarch64.neon.uqshl.v8i8(<8 x i8> %in,<8 x i8><i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
return|return
name|vqshl_n_u8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x4_t
name|test_vqshl_n_u16
parameter_list|(
name|uint16x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshl_n_u16
comment|// CHECK: call<4 x i16> @llvm.aarch64.neon.uqshl.v4i16(<4 x i16> %in,<4 x i16><i16 1, i16 1, i16 1, i16 1>)
return|return
name|vqshl_n_u16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|test_vqshl_n_u32
parameter_list|(
name|uint32x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshl_n_u32
comment|// CHECK: call<2 x i32> @llvm.aarch64.neon.uqshl.v2i32(<2 x i32> %in,<2 x i32><i32 1, i32 1>)
return|return
name|vqshl_n_u32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vqshl_n_u64
parameter_list|(
name|uint64x1_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshl_n_u64
comment|// CHECK: call<1 x i64> @llvm.aarch64.neon.uqshl.v1i64(<1 x i64> %in,<1 x i64><i64 1>)
return|return
name|vqshl_n_u64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x16_t
name|test_vqshlq_n_u8
parameter_list|(
name|uint8x16_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlq_n_u8
comment|// CHECK: call<16 x i8> @llvm.aarch64.neon.uqshl.v16i8(<16 x i8> %in,<16 x i8><i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
return|return
name|vqshlq_n_u8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x8_t
name|test_vqshlq_n_u16
parameter_list|(
name|uint16x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlq_n_u16
comment|// CHECK: call<8 x i16> @llvm.aarch64.neon.uqshl.v8i16(<8 x i16> %in,<8 x i16><i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>)
return|return
name|vqshlq_n_u16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vqshlq_n_u32
parameter_list|(
name|uint32x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlq_n_u32
comment|// CHECK: call<4 x i32> @llvm.aarch64.neon.uqshl.v4i32(<4 x i32> %in,<4 x i32><i32 1, i32 1, i32 1, i32 1>)
return|return
name|vqshlq_n_u32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x2_t
name|test_vqshlq_n_u64
parameter_list|(
name|uint64x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlq_n_u64
comment|// CHECK: call<2 x i64> @llvm.aarch64.neon.uqshl.v2i64(<2 x i64> %in,<2 x i64><i64 1, i64 1>
return|return
name|vqshlq_n_u64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x8_t
name|test_vrshr_n_s8
parameter_list|(
name|int8x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshr_n_s8
comment|// CHECK: call<8 x i8> @llvm.aarch64.neon.srshl.v8i8(<8 x i8> %in,<8 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
return|return
name|vrshr_n_s8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x4_t
name|test_vrshr_n_s16
parameter_list|(
name|int16x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshr_n_s16
comment|// CHECK: call<4 x i16> @llvm.aarch64.neon.srshl.v4i16(<4 x i16> %in,<4 x i16><i16 -1, i16 -1, i16 -1, i16 -1>)
return|return
name|vrshr_n_s16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|test_vrshr_n_s32
parameter_list|(
name|int32x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshr_n_s32
comment|// CHECK: call<2 x i32> @llvm.aarch64.neon.srshl.v2i32(<2 x i32> %in,<2 x i32><i32 -1, i32 -1>)
return|return
name|vrshr_n_s32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vrshr_n_s64
parameter_list|(
name|int64x1_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshr_n_s64
comment|// CHECK: call<1 x i64> @llvm.aarch64.neon.srshl.v1i64(<1 x i64> %in,<1 x i64><i64 -1>)
return|return
name|vrshr_n_s64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x16_t
name|test_vrshrq_n_s8
parameter_list|(
name|int8x16_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshrq_n_s8
comment|// CHECK: call<16 x i8> @llvm.aarch64.neon.srshl.v16i8(<16 x i8> %in,<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
return|return
name|vrshrq_n_s8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x8_t
name|test_vrshrq_n_s16
parameter_list|(
name|int16x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshrq_n_s16
comment|// CHECK: call<8 x i16> @llvm.aarch64.neon.srshl.v8i16(<8 x i16> %in,<8 x i16><i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
return|return
name|vrshrq_n_s16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x4_t
name|test_vrshrq_n_s32
parameter_list|(
name|int32x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshrq_n_s32
comment|// CHECK: call<4 x i32> @llvm.aarch64.neon.srshl.v4i32(<4 x i32> %in,<4 x i32><i32 -1, i32 -1, i32 -1, i32 -1>)
return|return
name|vrshrq_n_s32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x2_t
name|test_vrshrq_n_s64
parameter_list|(
name|int64x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshrq_n_s64
comment|// CHECK: call<2 x i64> @llvm.aarch64.neon.srshl.v2i64(<2 x i64> %in,<2 x i64><i64 -1, i64 -1>
return|return
name|vrshrq_n_s64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x8_t
name|test_vrshr_n_u8
parameter_list|(
name|uint8x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshr_n_u8
comment|// CHECK: call<8 x i8> @llvm.aarch64.neon.urshl.v8i8(<8 x i8> %in,<8 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
return|return
name|vrshr_n_u8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x4_t
name|test_vrshr_n_u16
parameter_list|(
name|uint16x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshr_n_u16
comment|// CHECK: call<4 x i16> @llvm.aarch64.neon.urshl.v4i16(<4 x i16> %in,<4 x i16><i16 -1, i16 -1, i16 -1, i16 -1>)
return|return
name|vrshr_n_u16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|test_vrshr_n_u32
parameter_list|(
name|uint32x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshr_n_u32
comment|// CHECK: call<2 x i32> @llvm.aarch64.neon.urshl.v2i32(<2 x i32> %in,<2 x i32><i32 -1, i32 -1>)
return|return
name|vrshr_n_u32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vrshr_n_u64
parameter_list|(
name|uint64x1_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshr_n_u64
comment|// CHECK: call<1 x i64> @llvm.aarch64.neon.urshl.v1i64(<1 x i64> %in,<1 x i64><i64 -1>)
return|return
name|vrshr_n_u64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x16_t
name|test_vrshrq_n_u8
parameter_list|(
name|uint8x16_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshrq_n_u8
comment|// CHECK: call<16 x i8> @llvm.aarch64.neon.urshl.v16i8(<16 x i8> %in,<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
return|return
name|vrshrq_n_u8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x8_t
name|test_vrshrq_n_u16
parameter_list|(
name|uint16x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshrq_n_u16
comment|// CHECK: call<8 x i16> @llvm.aarch64.neon.urshl.v8i16(<8 x i16> %in,<8 x i16><i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
return|return
name|vrshrq_n_u16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vrshrq_n_u32
parameter_list|(
name|uint32x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshrq_n_u32
comment|// CHECK: call<4 x i32> @llvm.aarch64.neon.urshl.v4i32(<4 x i32> %in,<4 x i32><i32 -1, i32 -1, i32 -1, i32 -1>)
return|return
name|vrshrq_n_u32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x2_t
name|test_vrshrq_n_u64
parameter_list|(
name|uint64x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrshrq_n_u64
comment|// CHECK: call<2 x i64> @llvm.aarch64.neon.urshl.v2i64(<2 x i64> %in,<2 x i64><i64 -1, i64 -1>
return|return
name|vrshrq_n_u64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x8_t
name|test_vqshlu_n_s8
parameter_list|(
name|int8x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlu_n_s8
comment|// CHECK: call<8 x i8> @llvm.aarch64.neon.sqshlu.v8i8(<8 x i8> %in,<8 x i8><i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
return|return
name|vqshlu_n_s8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x4_t
name|test_vqshlu_n_s16
parameter_list|(
name|int16x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlu_n_s16
comment|// CHECK: call<4 x i16> @llvm.aarch64.neon.sqshlu.v4i16(<4 x i16> %in,<4 x i16><i16 1, i16 1, i16 1, i16 1>)
return|return
name|vqshlu_n_s16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|test_vqshlu_n_s32
parameter_list|(
name|int32x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlu_n_s32
comment|// CHECK: call<2 x i32> @llvm.aarch64.neon.sqshlu.v2i32(<2 x i32> %in,<2 x i32><i32 1, i32 1>)
return|return
name|vqshlu_n_s32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vqshlu_n_s64
parameter_list|(
name|int64x1_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshlu_n_s64
comment|// CHECK: call<1 x i64> @llvm.aarch64.neon.sqshlu.v1i64(<1 x i64> %in,<1 x i64><i64 1>)
return|return
name|vqshlu_n_s64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x16_t
name|test_vqshluq_n_s8
parameter_list|(
name|int8x16_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshluq_n_s8
comment|// CHECK: call<16 x i8> @llvm.aarch64.neon.sqshlu.v16i8(<16 x i8> %in,<16 x i8><i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1, i8 1>)
return|return
name|vqshluq_n_s8
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x8_t
name|test_vqshluq_n_s16
parameter_list|(
name|int16x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshluq_n_s16
comment|// CHECK: call<8 x i16> @llvm.aarch64.neon.sqshlu.v8i16(<8 x i16> %in,<8 x i16><i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1, i16 1>)
return|return
name|vqshluq_n_s16
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x4_t
name|test_vqshluq_n_s32
parameter_list|(
name|int32x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshluq_n_s32
comment|// CHECK: call<4 x i32> @llvm.aarch64.neon.sqshlu.v4i32(<4 x i32> %in,<4 x i32><i32 1, i32 1, i32 1, i32 1>)
return|return
name|vqshluq_n_s32
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x2_t
name|test_vqshluq_n_s64
parameter_list|(
name|int64x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vqshluq_n_s64
comment|// CHECK: call<2 x i64> @llvm.aarch64.neon.sqshlu.v2i64(<2 x i64> %in,<2 x i64><i64 1, i64 1>
return|return
name|vqshluq_n_s64
argument_list|(
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x8_t
name|test_vrsra_n_s8
parameter_list|(
name|int8x8_t
name|acc
parameter_list|,
name|int8x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsra_n_s8
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<8 x i8> @llvm.aarch64.neon.srshl.v8i8(<8 x i8> %in,<8 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
comment|// CHECK: add<8 x i8> [[TMP]], %acc
return|return
name|vrsra_n_s8
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x4_t
name|test_vrsra_n_s16
parameter_list|(
name|int16x4_t
name|acc
parameter_list|,
name|int16x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsra_n_s16
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<4 x i16> @llvm.aarch64.neon.srshl.v4i16(<4 x i16> %in,<4 x i16><i16 -1, i16 -1, i16 -1, i16 -1>)
comment|// CHECK: add<4 x i16> [[TMP]], %acc
return|return
name|vrsra_n_s16
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|test_vrsra_n_s32
parameter_list|(
name|int32x2_t
name|acc
parameter_list|,
name|int32x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsra_n_s32
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<2 x i32> @llvm.aarch64.neon.srshl.v2i32(<2 x i32> %in,<2 x i32><i32 -1, i32 -1>)
comment|// CHECK: add<2 x i32> [[TMP]], %acc
return|return
name|vrsra_n_s32
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x1_t
name|test_vrsra_n_s64
parameter_list|(
name|int64x1_t
name|acc
parameter_list|,
name|int64x1_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsra_n_s64
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<1 x i64> @llvm.aarch64.neon.srshl.v1i64(<1 x i64> %in,<1 x i64><i64 -1>)
comment|// CHECK: add<1 x i64> [[TMP]], %acc
return|return
name|vrsra_n_s64
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int8x16_t
name|test_vrsraq_n_s8
parameter_list|(
name|int8x16_t
name|acc
parameter_list|,
name|int8x16_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsraq_n_s8
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<16 x i8> @llvm.aarch64.neon.srshl.v16i8(<16 x i8> %in,<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
comment|// CHECK: add<16 x i8> [[TMP]], %acc
return|return
name|vrsraq_n_s8
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int16x8_t
name|test_vrsraq_n_s16
parameter_list|(
name|int16x8_t
name|acc
parameter_list|,
name|int16x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsraq_n_s16
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<8 x i16> @llvm.aarch64.neon.srshl.v8i16(<8 x i16> %in,<8 x i16><i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
comment|// CHECK: add<8 x i16> [[TMP]], %acc
return|return
name|vrsraq_n_s16
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x4_t
name|test_vrsraq_n_s32
parameter_list|(
name|int32x4_t
name|acc
parameter_list|,
name|int32x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsraq_n_s32
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<4 x i32> @llvm.aarch64.neon.srshl.v4i32(<4 x i32> %in,<4 x i32><i32 -1, i32 -1, i32 -1, i32 -1>)
comment|// CHECK: add<4 x i32> [[TMP]], %acc
return|return
name|vrsraq_n_s32
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|int64x2_t
name|test_vrsraq_n_s64
parameter_list|(
name|int64x2_t
name|acc
parameter_list|,
name|int64x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsraq_n_s64
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<2 x i64> @llvm.aarch64.neon.srshl.v2i64(<2 x i64> %in,<2 x i64><i64 -1, i64 -1>)
comment|// CHECK: add<2 x i64> [[TMP]], %acc
return|return
name|vrsraq_n_s64
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x8_t
name|test_vrsra_n_u8
parameter_list|(
name|uint8x8_t
name|acc
parameter_list|,
name|uint8x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsra_n_u8
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<8 x i8> @llvm.aarch64.neon.urshl.v8i8(<8 x i8> %in,<8 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
comment|// CHECK: add<8 x i8> [[TMP]], %acc
return|return
name|vrsra_n_u8
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x4_t
name|test_vrsra_n_u16
parameter_list|(
name|uint16x4_t
name|acc
parameter_list|,
name|uint16x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsra_n_u16
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<4 x i16> @llvm.aarch64.neon.urshl.v4i16(<4 x i16> %in,<4 x i16><i16 -1, i16 -1, i16 -1, i16 -1>)
comment|// CHECK: add<4 x i16> [[TMP]], %acc
return|return
name|vrsra_n_u16
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|test_vrsra_n_u32
parameter_list|(
name|uint32x2_t
name|acc
parameter_list|,
name|uint32x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsra_n_u32
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<2 x i32> @llvm.aarch64.neon.urshl.v2i32(<2 x i32> %in,<2 x i32><i32 -1, i32 -1>)
comment|// CHECK: add<2 x i32> [[TMP]], %acc
return|return
name|vrsra_n_u32
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x1_t
name|test_vrsra_n_u64
parameter_list|(
name|uint64x1_t
name|acc
parameter_list|,
name|uint64x1_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsra_n_u64
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<1 x i64> @llvm.aarch64.neon.urshl.v1i64(<1 x i64> %in,<1 x i64><i64 -1>)
comment|// CHECK: add<1 x i64> [[TMP]], %acc
return|return
name|vrsra_n_u64
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint8x16_t
name|test_vrsraq_n_u8
parameter_list|(
name|uint8x16_t
name|acc
parameter_list|,
name|uint8x16_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsraq_n_u8
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<16 x i8> @llvm.aarch64.neon.urshl.v16i8(<16 x i8> %in,<16 x i8><i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1, i8 -1>)
comment|// CHECK: add<16 x i8> [[TMP]], %acc
return|return
name|vrsraq_n_u8
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint16x8_t
name|test_vrsraq_n_u16
parameter_list|(
name|uint16x8_t
name|acc
parameter_list|,
name|uint16x8_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsraq_n_u16
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<8 x i16> @llvm.aarch64.neon.urshl.v8i16(<8 x i16> %in,<8 x i16><i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1, i16 -1>)
comment|// CHECK: add<8 x i16> [[TMP]], %acc
return|return
name|vrsraq_n_u16
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vrsraq_n_u32
parameter_list|(
name|uint32x4_t
name|acc
parameter_list|,
name|uint32x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsraq_n_u32
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<4 x i32> @llvm.aarch64.neon.urshl.v4i32(<4 x i32> %in,<4 x i32><i32 -1, i32 -1, i32 -1, i32 -1>)
comment|// CHECK: add<4 x i32> [[TMP]], %acc
return|return
name|vrsraq_n_u32
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64x2_t
name|test_vrsraq_n_u64
parameter_list|(
name|uint64x2_t
name|acc
parameter_list|,
name|uint64x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsraq_n_u64
comment|// CHECK: [[TMP:%[0-9a-zA-Z._]+]] = tail call<2 x i64> @llvm.aarch64.neon.urshl.v2i64(<2 x i64> %in,<2 x i64><i64 -1, i64 -1>)
comment|// CHECK: add<2 x i64> [[TMP]], %acc
return|return
name|vrsraq_n_u64
argument_list|(
name|acc
argument_list|,
name|in
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

end_unit

