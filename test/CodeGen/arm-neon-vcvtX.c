begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv8-linux-gnueabihf -target-cpu cortex-a57 -ffreestanding -O1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int32x2_t
name|test_vcvta_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvta_s32_f32
comment|// CHECK-LABEL: call<2 x i32> @llvm.arm.neon.vcvtas.v2i32.v2f32(<2 x float> %a)
return|return
name|vcvta_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvta_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvta_u32_f32
comment|// CHECK-LABEL: call<2 x i32> @llvm.arm.neon.vcvtau.v2i32.v2f32(<2 x float> %a)
return|return
name|vcvta_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtaq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtaq_s32_f32
comment|// CHECK-LABEL: call<4 x i32> @llvm.arm.neon.vcvtas.v4i32.v4f32(<4 x float> %a)
return|return
name|vcvtaq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtaq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtaq_u32_f32
comment|// CHECK-LABEL: call<4 x i32> @llvm.arm.neon.vcvtau.v4i32.v4f32(<4 x float> %a)
return|return
name|vcvtaq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|test_vcvtn_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtn_s32_f32
comment|// CHECK-LABEL: call<2 x i32> @llvm.arm.neon.vcvtns.v2i32.v2f32(<2 x float> %a)
return|return
name|vcvtn_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvtn_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtn_u32_f32
comment|// CHECK-LABEL: call<2 x i32> @llvm.arm.neon.vcvtnu.v2i32.v2f32(<2 x float> %a)
return|return
name|vcvtn_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtnq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtnq_s32_f32
comment|// CHECK-LABEL: call<4 x i32> @llvm.arm.neon.vcvtns.v4i32.v4f32(<4 x float> %a)
return|return
name|vcvtnq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtnq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtnq_u32_f32
comment|// CHECK-LABEL: call<4 x i32> @llvm.arm.neon.vcvtnu.v4i32.v4f32(<4 x float> %a)
return|return
name|vcvtnq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|test_vcvtp_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtp_s32_f32
comment|// CHECK-LABEL: call<2 x i32> @llvm.arm.neon.vcvtps.v2i32.v2f32(<2 x float> %a)
return|return
name|vcvtp_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvtp_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtp_u32_f32
comment|// CHECK-LABEL: call<2 x i32> @llvm.arm.neon.vcvtpu.v2i32.v2f32(<2 x float> %a)
return|return
name|vcvtp_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtpq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtpq_s32_f32
comment|// CHECK-LABEL: call<4 x i32> @llvm.arm.neon.vcvtps.v4i32.v4f32(<4 x float> %a)
return|return
name|vcvtpq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtpq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtpq_u32_f32
comment|// CHECK-LABEL: call<4 x i32> @llvm.arm.neon.vcvtpu.v4i32.v4f32(<4 x float> %a)
return|return
name|vcvtpq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x2_t
name|test_vcvtm_s32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtm_s32_f32
comment|// CHECK-LABEL: call<2 x i32> @llvm.arm.neon.vcvtms.v2i32.v2f32(<2 x float> %a)
return|return
name|vcvtm_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x2_t
name|test_vcvtm_u32_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtm_u32_f32
comment|// CHECK-LABEL: call<2 x i32> @llvm.arm.neon.vcvtmu.v2i32.v2f32(<2 x float> %a)
return|return
name|vcvtm_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32x4_t
name|test_vcvtmq_s32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtmq_s32_f32
comment|// CHECK-LABEL: call<4 x i32> @llvm.arm.neon.vcvtms.v4i32.v4f32(<4 x float> %a)
return|return
name|vcvtmq_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vcvtmq_u32_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtmq_u32_f32
comment|// CHECK-LABEL: call<4 x i32> @llvm.arm.neon.vcvtmu.v4i32.v4f32(<4 x float> %a)
return|return
name|vcvtmq_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

