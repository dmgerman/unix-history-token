begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN: -disable-O0-optnone -ffp-contract=fast -emit-llvm -o - %s | opt -S -mem2reg \
end_comment

begin_comment
comment|// RUN:  | FileCheck %s
end_comment

begin_comment
comment|// Test new aarch64 intrinsics with poly128
end_comment

begin_comment
comment|// FIXME: Currently, poly128_t equals to uint128, which will be spilt into
end_comment

begin_comment
comment|// two 64-bit GPR(eg X0, X1). Now moving data from X0, X1 to FPR128 will
end_comment

begin_comment
comment|// introduce 2 store and 1 load instructions(store X0, X1 to memory and
end_comment

begin_comment
comment|// then load back to Q0). If target has NEON, this is better replaced by
end_comment

begin_comment
comment|// FMOV or INS.
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: define void @test_vstrq_p128(i128* %ptr, i128 %val) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to i128*
end_comment

begin_comment
comment|// CHECK:   store i128 %val, i128* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_vstrq_p128
parameter_list|(
name|poly128_t
modifier|*
name|ptr
parameter_list|,
name|poly128_t
name|val
parameter_list|)
block|{
name|vstrq_p128
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vldrq_p128(i128* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to i128*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load i128, i128* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP2]]
end_comment

begin_function
name|poly128_t
name|test_vldrq_p128
parameter_list|(
name|poly128_t
modifier|*
name|ptr
parameter_list|)
block|{
return|return
name|vldrq_p128
argument_list|(
name|ptr
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define void @test_ld_st_p128(i128* %ptr) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128* %ptr to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i8* [[TMP0]] to i128*
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = load i128, i128* [[TMP1]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_PTR:%.*]] = getelementptr inbounds i128, i128* %ptr, i64 1
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast i128* [[ADD_PTR]] to i8*
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast i8* [[TMP3]] to i128*
end_comment

begin_comment
comment|// CHECK:   store i128 [[TMP2]], i128* [[TMP4]]
end_comment

begin_comment
comment|// CHECK:   ret void
end_comment

begin_function
name|void
name|test_ld_st_p128
parameter_list|(
name|poly128_t
modifier|*
name|ptr
parameter_list|)
block|{
name|vstrq_p128
argument_list|(
name|ptr
operator|+
literal|1
argument_list|,
name|vldrq_p128
argument_list|(
name|ptr
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vmull_p64(i64 %a, i64 %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMULL_P64_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.pmull64(i64 %a, i64 %b) #2
end_comment

begin_comment
comment|// CHECK:   [[VMULL_P641_I:%.*]] = bitcast<16 x i8> [[VMULL_P64_I]] to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[VMULL_P641_I]]
end_comment

begin_function
name|poly128_t
name|test_vmull_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|,
name|poly64_t
name|b
parameter_list|)
block|{
return|return
name|vmull_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vmull_high_p64(<2 x i64> %a,<2 x i64> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I_I:%.*]] = shufflevector<2 x i64> %a,<2 x i64> %a,<1 x i32><i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x i64> [[SHUFFLE_I_I]] to i64
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I7_I:%.*]] = shufflevector<2 x i64> %b,<2 x i64> %b,<1 x i32><i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x i64> [[SHUFFLE_I7_I]] to i64
end_comment

begin_comment
comment|// CHECK:   [[VMULL_P64_I_I:%.*]] = call<16 x i8> @llvm.aarch64.neon.pmull64(i64 [[TMP0]], i64 [[TMP1]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VMULL_P641_I_I:%.*]] = bitcast<16 x i8> [[VMULL_P64_I_I]] to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[VMULL_P641_I_I]]
end_comment

begin_function
name|poly128_t
name|test_vmull_high_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
return|return
name|vmull_high_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_s8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<16 x i8> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_s16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_s32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_s64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_u8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<16 x i8> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_u16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_u32(<4 x i32> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_u64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_f64(<2 x double> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_p8(<16 x i8> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<16 x i8> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_p16(<8 x i16> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i128 @test_vreinterpretq_p128_p64(<2 x i64> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i64> %a to i128
end_comment

begin_comment
comment|// CHECK:   ret i128 [[TMP0]]
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vreinterpretq_s8_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[TMP0]]
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vreinterpretq_s16_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[TMP0]]
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vreinterpretq_s32_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[TMP0]]
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vreinterpretq_s64_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[TMP0]]
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vreinterpretq_u8_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[TMP0]]
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vreinterpretq_u16_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[TMP0]]
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x i32> @test_vreinterpretq_u32_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[TMP0]]
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vreinterpretq_u64_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[TMP0]]
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vreinterpretq_f32_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP0]]
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vreinterpretq_f64_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<2 x double>
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[TMP0]]
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<16 x i8> @test_vreinterpretq_p8_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   ret<16 x i8> [[TMP0]]
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<8 x i16> @test_vreinterpretq_p16_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   ret<8 x i16> [[TMP0]]
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x i64> @test_vreinterpretq_p64_p128(i128 %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i128 %a to<2 x i64>
end_comment

begin_comment
comment|// CHECK:   ret<2 x i64> [[TMP0]]
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

