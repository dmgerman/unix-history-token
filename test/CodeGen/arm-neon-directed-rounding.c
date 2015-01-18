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
name|float32x2_t
name|test_vrnda_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrnda_f32
comment|// CHECK: call<2 x float> @llvm.arm.neon.vrinta.v2f32(<2 x float> %a)
return|return
name|vrnda_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndaq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndaq_f32
comment|// CHECK: call<4 x float> @llvm.arm.neon.vrinta.v4f32(<4 x float> %a)
return|return
name|vrndaq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|test_vrndm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndm_f32
comment|// CHECK: call<2 x float> @llvm.arm.neon.vrintm.v2f32(<2 x float> %a)
return|return
name|vrndm_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndmq_f32
comment|// CHECK: call<4 x float> @llvm.arm.neon.vrintm.v4f32(<4 x float> %a)
return|return
name|vrndmq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|test_vrndn_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndn_f32
comment|// CHECK: call<2 x float> @llvm.arm.neon.vrintn.v2f32(<2 x float> %a)
return|return
name|vrndn_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndnq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndnq_f32
comment|// CHECK: call<4 x float> @llvm.arm.neon.vrintn.v4f32(<4 x float> %a)
return|return
name|vrndnq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|test_vrndp_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndp_f32
comment|// CHECK: call<2 x float> @llvm.arm.neon.vrintp.v2f32(<2 x float> %a)
return|return
name|vrndp_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndpq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndpq_f32
comment|// CHECK: call<4 x float> @llvm.arm.neon.vrintp.v4f32(<4 x float> %a)
return|return
name|vrndpq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|test_vrndx_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndx_f32
comment|// CHECK: call<2 x float> @llvm.arm.neon.vrintx.v2f32(<2 x float> %a)
return|return
name|vrndx_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndxq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndxq_f32
comment|// CHECK: call<4 x float> @llvm.arm.neon.vrintx.v4f32(<4 x float> %a)
return|return
name|vrndxq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|test_vrnd_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrnd_f32
comment|// CHECK: call<2 x float> @llvm.arm.neon.vrintz.v2f32(<2 x float> %a)
return|return
name|vrnd_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vrndq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vrndq_f32
comment|// CHECK: call<4 x float> @llvm.arm.neon.vrintz.v4f32(<4 x float> %a)
return|return
name|vrndq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

