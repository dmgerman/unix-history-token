begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:  -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK-LABEL: define i16 @test_vaddlv_s8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLV_I:%.*]] = call i32 @llvm.aarch64.neon.saddlv.i32.v8i8(<8 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VADDLV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP0]]
end_comment

begin_function
name|int16_t
name|test_vaddlv_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vaddlv_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vaddlv_s16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLV_I:%.*]] = call i32 @llvm.aarch64.neon.saddlv.i32.v4i16(<4 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VADDLV_I]]
end_comment

begin_function
name|int32_t
name|test_vaddlv_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vaddlv_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vaddlv_u8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLV_I:%.*]] = call i32 @llvm.aarch64.neon.uaddlv.i32.v8i8(<8 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VADDLV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP0]]
end_comment

begin_function
name|uint16_t
name|test_vaddlv_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vaddlv_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vaddlv_u16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLV_I:%.*]] = call i32 @llvm.aarch64.neon.uaddlv.i32.v4i16(<4 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VADDLV_I]]
end_comment

begin_function
name|uint32_t
name|test_vaddlv_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vaddlv_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vaddlvq_s8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLV_I:%.*]] = call i32 @llvm.aarch64.neon.saddlv.i32.v16i8(<16 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VADDLV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP0]]
end_comment

begin_function
name|int16_t
name|test_vaddlvq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vaddlvq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vaddlvq_s16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLV_I:%.*]] = call i32 @llvm.aarch64.neon.saddlv.i32.v8i16(<8 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VADDLV_I]]
end_comment

begin_function
name|int32_t
name|test_vaddlvq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vaddlvq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vaddlvq_s32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLVQ_S32_I:%.*]] = call i64 @llvm.aarch64.neon.saddlv.i64.v4i32(<4 x i32> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VADDLVQ_S32_I]]
end_comment

begin_function
name|int64_t
name|test_vaddlvq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vaddlvq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vaddlvq_u8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLV_I:%.*]] = call i32 @llvm.aarch64.neon.uaddlv.i32.v16i8(<16 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VADDLV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP0]]
end_comment

begin_function
name|uint16_t
name|test_vaddlvq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vaddlvq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vaddlvq_u16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLV_I:%.*]] = call i32 @llvm.aarch64.neon.uaddlv.i32.v8i16(<8 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VADDLV_I]]
end_comment

begin_function
name|uint32_t
name|test_vaddlvq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vaddlvq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vaddlvq_u32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDLVQ_U32_I:%.*]] = call i64 @llvm.aarch64.neon.uaddlv.i64.v4i32(<4 x i32> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VADDLVQ_U32_I]]
end_comment

begin_function
name|uint64_t
name|test_vaddlvq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vaddlvq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vmaxv_s8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXV_I:%.*]] = call i32 @llvm.aarch64.neon.smaxv.i32.v8i8(<8 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VMAXV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|int8_t
name|test_vmaxv_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmaxv_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vmaxv_s16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXV_I:%.*]] = call i32 @llvm.aarch64.neon.smaxv.i32.v4i16(<4 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VMAXV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|int16_t
name|test_vmaxv_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vmaxv_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vmaxv_u8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXV_I:%.*]] = call i32 @llvm.aarch64.neon.umaxv.i32.v8i8(<8 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VMAXV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|uint8_t
name|test_vmaxv_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vmaxv_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vmaxv_u16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXV_I:%.*]] = call i32 @llvm.aarch64.neon.umaxv.i32.v4i16(<4 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VMAXV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|uint16_t
name|test_vmaxv_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vmaxv_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vmaxvq_s8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXV_I:%.*]] = call i32 @llvm.aarch64.neon.smaxv.i32.v16i8(<16 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VMAXV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|int8_t
name|test_vmaxvq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vmaxvq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vmaxvq_s16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXV_I:%.*]] = call i32 @llvm.aarch64.neon.smaxv.i32.v8i16(<8 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VMAXV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|int16_t
name|test_vmaxvq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmaxvq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vmaxvq_s32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXVQ_S32_I:%.*]] = call i32 @llvm.aarch64.neon.smaxv.i32.v4i32(<4 x i32> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VMAXVQ_S32_I]]
end_comment

begin_function
name|int32_t
name|test_vmaxvq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmaxvq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vmaxvq_u8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXV_I:%.*]] = call i32 @llvm.aarch64.neon.umaxv.i32.v16i8(<16 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VMAXV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|uint8_t
name|test_vmaxvq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vmaxvq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vmaxvq_u16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXV_I:%.*]] = call i32 @llvm.aarch64.neon.umaxv.i32.v8i16(<8 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VMAXV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|uint16_t
name|test_vmaxvq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vmaxvq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vmaxvq_u32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXVQ_U32_I:%.*]] = call i32 @llvm.aarch64.neon.umaxv.i32.v4i32(<4 x i32> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VMAXVQ_U32_I]]
end_comment

begin_function
name|uint32_t
name|test_vmaxvq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmaxvq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vminv_s8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINV_I:%.*]] = call i32 @llvm.aarch64.neon.sminv.i32.v8i8(<8 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VMINV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|int8_t
name|test_vminv_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vminv_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vminv_s16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINV_I:%.*]] = call i32 @llvm.aarch64.neon.sminv.i32.v4i16(<4 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VMINV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|int16_t
name|test_vminv_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vminv_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vminv_u8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINV_I:%.*]] = call i32 @llvm.aarch64.neon.uminv.i32.v8i8(<8 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VMINV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|uint8_t
name|test_vminv_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vminv_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vminv_u16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINV_I:%.*]] = call i32 @llvm.aarch64.neon.uminv.i32.v4i16(<4 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VMINV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|uint16_t
name|test_vminv_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vminv_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vminvq_s8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINV_I:%.*]] = call i32 @llvm.aarch64.neon.sminv.i32.v16i8(<16 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VMINV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|int8_t
name|test_vminvq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vminvq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vminvq_s16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINV_I:%.*]] = call i32 @llvm.aarch64.neon.sminv.i32.v8i16(<8 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VMINV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|int16_t
name|test_vminvq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vminvq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vminvq_s32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINVQ_S32_I:%.*]] = call i32 @llvm.aarch64.neon.sminv.i32.v4i32(<4 x i32> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VMINVQ_S32_I]]
end_comment

begin_function
name|int32_t
name|test_vminvq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vminvq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vminvq_u8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINV_I:%.*]] = call i32 @llvm.aarch64.neon.uminv.i32.v16i8(<16 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VMINV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|uint8_t
name|test_vminvq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vminvq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vminvq_u16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINV_I:%.*]] = call i32 @llvm.aarch64.neon.uminv.i32.v8i16(<8 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VMINV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|uint16_t
name|test_vminvq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vminvq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vminvq_u32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINVQ_U32_I:%.*]] = call i32 @llvm.aarch64.neon.uminv.i32.v4i32(<4 x i32> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VMINVQ_U32_I]]
end_comment

begin_function
name|uint32_t
name|test_vminvq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vminvq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vaddv_s8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDV_I:%.*]] = call i32 @llvm.aarch64.neon.saddv.i32.v8i8(<8 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VADDV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|int8_t
name|test_vaddv_s8
parameter_list|(
name|int8x8_t
name|a
parameter_list|)
block|{
return|return
name|vaddv_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vaddv_s16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDV_I:%.*]] = call i32 @llvm.aarch64.neon.saddv.i32.v4i16(<4 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VADDV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|int16_t
name|test_vaddv_s16
parameter_list|(
name|int16x4_t
name|a
parameter_list|)
block|{
return|return
name|vaddv_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vaddv_u8(<8 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDV_I:%.*]] = call i32 @llvm.aarch64.neon.uaddv.i32.v8i8(<8 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VADDV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|uint8_t
name|test_vaddv_u8
parameter_list|(
name|uint8x8_t
name|a
parameter_list|)
block|{
return|return
name|vaddv_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vaddv_u16(<4 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDV_I:%.*]] = call i32 @llvm.aarch64.neon.uaddv.i32.v4i16(<4 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VADDV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|uint16_t
name|test_vaddv_u16
parameter_list|(
name|uint16x4_t
name|a
parameter_list|)
block|{
return|return
name|vaddv_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vaddvq_s8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDV_I:%.*]] = call i32 @llvm.aarch64.neon.saddv.i32.v16i8(<16 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VADDV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|int8_t
name|test_vaddvq_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vaddvq_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vaddvq_s16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDV_I:%.*]] = call i32 @llvm.aarch64.neon.saddv.i32.v8i16(<8 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VADDV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|int16_t
name|test_vaddvq_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vaddvq_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vaddvq_s32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDVQ_S32_I:%.*]] = call i32 @llvm.aarch64.neon.saddv.i32.v4i32(<4 x i32> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VADDVQ_S32_I]]
end_comment

begin_function
name|int32_t
name|test_vaddvq_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vaddvq_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i8 @test_vaddvq_u8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDV_I:%.*]] = call i32 @llvm.aarch64.neon.uaddv.i32.v16i8(<16 x i8> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = trunc i32 [[VADDV_I]] to i8
end_comment

begin_comment
comment|// CHECK:   ret i8 [[TMP0]]
end_comment

begin_function
name|uint8_t
name|test_vaddvq_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vaddvq_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vaddvq_u16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDV_I:%.*]] = call i32 @llvm.aarch64.neon.uaddv.i32.v8i16(<8 x i16> %a) #2
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = trunc i32 [[VADDV_I]] to i16
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP2]]
end_comment

begin_function
name|uint16_t
name|test_vaddvq_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vaddvq_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vaddvq_u32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VADDVQ_U32_I:%.*]] = call i32 @llvm.aarch64.neon.uaddv.i32.v4i32(<4 x i32> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VADDVQ_U32_I]]
end_comment

begin_function
name|uint32_t
name|test_vaddvq_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vaddvq_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vmaxvq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXVQ_F32_I:%.*]] = call float @llvm.aarch64.neon.fmaxv.f32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret float [[VMAXVQ_F32_I]]
end_comment

begin_function
name|float32_t
name|test_vmaxvq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmaxvq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vminvq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINVQ_F32_I:%.*]] = call float @llvm.aarch64.neon.fminv.f32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret float [[VMINVQ_F32_I]]
end_comment

begin_function
name|float32_t
name|test_vminvq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vminvq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vmaxnmvq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXNMVQ_F32_I:%.*]] = call float @llvm.aarch64.neon.fmaxnmv.f32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret float [[VMAXNMVQ_F32_I]]
end_comment

begin_function
name|float32_t
name|test_vmaxnmvq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vmaxnmvq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vminnmvq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINNMVQ_F32_I:%.*]] = call float @llvm.aarch64.neon.fminnmv.f32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret float [[VMINNMVQ_F32_I]]
end_comment

begin_function
name|float32_t
name|test_vminnmvq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vminnmvq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

