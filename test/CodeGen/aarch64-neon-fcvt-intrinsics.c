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
comment|// CHECK-LABEL: define float @test_vcvtxd_f32_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTXD_F32_F64_I:%.*]] = call float @llvm.aarch64.sisd.fcvtxn(double %a) #2
end_comment

begin_comment
comment|// CHECK:   ret float [[VCVTXD_F32_F64_I]]
end_comment

begin_function
name|float32_t
name|test_vcvtxd_f32_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|float32_t
operator|)
name|vcvtxd_f32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvtas_s32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTAS_S32_F32_I:%.*]] = call i32 @llvm.aarch64.neon.fcvtas.i32.f32(float %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VCVTAS_S32_F32_I]]
end_comment

begin_function
name|int32_t
name|test_vcvtas_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int32_t
operator|)
name|vcvtas_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_test_vcvtad_s64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTAD_S64_F64_I:%.*]] = call i64 @llvm.aarch64.neon.fcvtas.i64.f64(double %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VCVTAD_S64_F64_I]]
end_comment

begin_function
name|int64_t
name|test_test_vcvtad_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int64_t
operator|)
name|vcvtad_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvtas_u32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTAS_U32_F32_I:%.*]] = call i32 @llvm.aarch64.neon.fcvtau.i32.f32(float %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VCVTAS_U32_F32_I]]
end_comment

begin_function
name|uint32_t
name|test_vcvtas_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint32_t
operator|)
name|vcvtas_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vcvtad_u64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTAD_U64_F64_I:%.*]] = call i64 @llvm.aarch64.neon.fcvtau.i64.f64(double %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VCVTAD_U64_F64_I]]
end_comment

begin_function
name|uint64_t
name|test_vcvtad_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint64_t
operator|)
name|vcvtad_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvtms_s32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTMS_S32_F32_I:%.*]] = call i32 @llvm.aarch64.neon.fcvtms.i32.f32(float %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VCVTMS_S32_F32_I]]
end_comment

begin_function
name|int32_t
name|test_vcvtms_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int32_t
operator|)
name|vcvtms_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vcvtmd_s64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTMD_S64_F64_I:%.*]] = call i64 @llvm.aarch64.neon.fcvtms.i64.f64(double %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VCVTMD_S64_F64_I]]
end_comment

begin_function
name|int64_t
name|test_vcvtmd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int64_t
operator|)
name|vcvtmd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvtms_u32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTMS_U32_F32_I:%.*]] = call i32 @llvm.aarch64.neon.fcvtmu.i32.f32(float %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VCVTMS_U32_F32_I]]
end_comment

begin_function
name|uint32_t
name|test_vcvtms_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint32_t
operator|)
name|vcvtms_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vcvtmd_u64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTMD_U64_F64_I:%.*]] = call i64 @llvm.aarch64.neon.fcvtmu.i64.f64(double %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VCVTMD_U64_F64_I]]
end_comment

begin_function
name|uint64_t
name|test_vcvtmd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint64_t
operator|)
name|vcvtmd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvtns_s32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTNS_S32_F32_I:%.*]] = call i32 @llvm.aarch64.neon.fcvtns.i32.f32(float %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VCVTNS_S32_F32_I]]
end_comment

begin_function
name|int32_t
name|test_vcvtns_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int32_t
operator|)
name|vcvtns_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vcvtnd_s64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTND_S64_F64_I:%.*]] = call i64 @llvm.aarch64.neon.fcvtns.i64.f64(double %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VCVTND_S64_F64_I]]
end_comment

begin_function
name|int64_t
name|test_vcvtnd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int64_t
operator|)
name|vcvtnd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvtns_u32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTNS_U32_F32_I:%.*]] = call i32 @llvm.aarch64.neon.fcvtnu.i32.f32(float %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VCVTNS_U32_F32_I]]
end_comment

begin_function
name|uint32_t
name|test_vcvtns_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint32_t
operator|)
name|vcvtns_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vcvtnd_u64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTND_U64_F64_I:%.*]] = call i64 @llvm.aarch64.neon.fcvtnu.i64.f64(double %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VCVTND_U64_F64_I]]
end_comment

begin_function
name|uint64_t
name|test_vcvtnd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint64_t
operator|)
name|vcvtnd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvtps_s32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTPS_S32_F32_I:%.*]] = call i32 @llvm.aarch64.neon.fcvtps.i32.f32(float %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VCVTPS_S32_F32_I]]
end_comment

begin_function
name|int32_t
name|test_vcvtps_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int32_t
operator|)
name|vcvtps_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vcvtpd_s64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTPD_S64_F64_I:%.*]] = call i64 @llvm.aarch64.neon.fcvtps.i64.f64(double %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VCVTPD_S64_F64_I]]
end_comment

begin_function
name|int64_t
name|test_vcvtpd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int64_t
operator|)
name|vcvtpd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvtps_u32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTPS_U32_F32_I:%.*]] = call i32 @llvm.aarch64.neon.fcvtpu.i32.f32(float %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VCVTPS_U32_F32_I]]
end_comment

begin_function
name|uint32_t
name|test_vcvtps_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint32_t
operator|)
name|vcvtps_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vcvtpd_u64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTPD_U64_F64_I:%.*]] = call i64 @llvm.aarch64.neon.fcvtpu.i64.f64(double %a) #2
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VCVTPD_U64_F64_I]]
end_comment

begin_function
name|uint64_t
name|test_vcvtpd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint64_t
operator|)
name|vcvtpd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvts_s32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = fptosi float %a to i32
end_comment

begin_comment
comment|// CHECK:   ret i32 [[TMP0]]
end_comment

begin_function
name|int32_t
name|test_vcvts_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int32_t
operator|)
name|vcvts_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vcvtd_s64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = fptosi double %a to i64
end_comment

begin_comment
comment|// CHECK:   ret i64 [[TMP0]]
end_comment

begin_function
name|int64_t
name|test_vcvtd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|int64_t
operator|)
name|vcvtd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vcvts_u32_f32(float %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = fptoui float %a to i32
end_comment

begin_comment
comment|// CHECK:   ret i32 [[TMP0]]
end_comment

begin_function
name|uint32_t
name|test_vcvts_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint32_t
operator|)
name|vcvts_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vcvtd_u64_f64(double %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = fptoui double %a to i64
end_comment

begin_comment
comment|// CHECK:   ret i64 [[TMP0]]
end_comment

begin_function
name|uint64_t
name|test_vcvtd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
return|return
operator|(
name|uint64_t
operator|)
name|vcvtd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

