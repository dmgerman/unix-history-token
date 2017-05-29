begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv8-linux-gnueabihf -target-cpu cortex-a57 -ffreestanding -disable-O0-optnone -emit-llvm %s -o - | opt -S -mem2reg | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: define<2 x i32> @test_vcvta_s32_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTA_S32_V1_I:%.*]] = call<2 x i32> @llvm.arm.neon.vcvtas.v2i32.v2f32(<2 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTA_S32_V1_I]]
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
comment|// CHECK-LABEL: define<2 x i32> @test_vcvta_u32_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTA_U32_V1_I:%.*]] = call<2 x i32> @llvm.arm.neon.vcvtau.v2i32.v2f32(<2 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTA_U32_V1_I]]
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
comment|// CHECK-LABEL: define<4 x i32> @test_vcvtaq_s32_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTAQ_S32_V1_I:%.*]] = call<4 x i32> @llvm.arm.neon.vcvtas.v4i32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTAQ_S32_V1_I]]
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
comment|// CHECK-LABEL: define<4 x i32> @test_vcvtaq_u32_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTAQ_U32_V1_I:%.*]] = call<4 x i32> @llvm.arm.neon.vcvtau.v4i32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTAQ_U32_V1_I]]
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
comment|// CHECK-LABEL: define<2 x i32> @test_vcvtn_s32_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTN_S32_V1_I:%.*]] = call<2 x i32> @llvm.arm.neon.vcvtns.v2i32.v2f32(<2 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTN_S32_V1_I]]
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
comment|// CHECK-LABEL: define<2 x i32> @test_vcvtn_u32_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTN_U32_V1_I:%.*]] = call<2 x i32> @llvm.arm.neon.vcvtnu.v2i32.v2f32(<2 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTN_U32_V1_I]]
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
comment|// CHECK-LABEL: define<4 x i32> @test_vcvtnq_s32_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTNQ_S32_V1_I:%.*]] = call<4 x i32> @llvm.arm.neon.vcvtns.v4i32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTNQ_S32_V1_I]]
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
comment|// CHECK-LABEL: define<4 x i32> @test_vcvtnq_u32_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTNQ_U32_V1_I:%.*]] = call<4 x i32> @llvm.arm.neon.vcvtnu.v4i32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTNQ_U32_V1_I]]
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
comment|// CHECK-LABEL: define<2 x i32> @test_vcvtp_s32_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTP_S32_V1_I:%.*]] = call<2 x i32> @llvm.arm.neon.vcvtps.v2i32.v2f32(<2 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTP_S32_V1_I]]
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
comment|// CHECK-LABEL: define<2 x i32> @test_vcvtp_u32_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTP_U32_V1_I:%.*]] = call<2 x i32> @llvm.arm.neon.vcvtpu.v2i32.v2f32(<2 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTP_U32_V1_I]]
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
comment|// CHECK-LABEL: define<4 x i32> @test_vcvtpq_s32_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTPQ_S32_V1_I:%.*]] = call<4 x i32> @llvm.arm.neon.vcvtps.v4i32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTPQ_S32_V1_I]]
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
comment|// CHECK-LABEL: define<4 x i32> @test_vcvtpq_u32_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTPQ_U32_V1_I:%.*]] = call<4 x i32> @llvm.arm.neon.vcvtpu.v4i32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTPQ_U32_V1_I]]
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
comment|// CHECK-LABEL: define<2 x i32> @test_vcvtm_s32_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTM_S32_V1_I:%.*]] = call<2 x i32> @llvm.arm.neon.vcvtms.v2i32.v2f32(<2 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTM_S32_V1_I]]
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
comment|// CHECK-LABEL: define<2 x i32> @test_vcvtm_u32_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTM_U32_V1_I:%.*]] = call<2 x i32> @llvm.arm.neon.vcvtmu.v2i32.v2f32(<2 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x i32> [[VCVTM_U32_V1_I]]
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
comment|// CHECK-LABEL: define<4 x i32> @test_vcvtmq_s32_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTMQ_S32_V1_I:%.*]] = call<4 x i32> @llvm.arm.neon.vcvtms.v4i32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTMQ_S32_V1_I]]
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
comment|// CHECK-LABEL: define<4 x i32> @test_vcvtmq_u32_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VCVTMQ_U32_V1_I:%.*]] = call<4 x i32> @llvm.arm.neon.vcvtmu.v4i32.v4f32(<4 x float> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x i32> [[VCVTMQ_U32_V1_I]]
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

end_unit

