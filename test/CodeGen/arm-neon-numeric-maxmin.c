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
name|test_vmaxnm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxnm_f32
comment|// CHECK: call<2 x float> @llvm.arm.neon.vmaxnm.v2f32(<2 x float> %a,<2 x float> %b)
return|return
name|vmaxnm_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vmaxnmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmaxnmq_f32
comment|// CHECK: call<4 x float> @llvm.arm.neon.vmaxnm.v4f32(<4 x float> %a,<4 x float> %b)
return|return
name|vmaxnmq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|test_vminnm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminnm_f32
comment|// CHECK: call<2 x float> @llvm.arm.neon.vminnm.v2f32(<2 x float> %a,<2 x float> %b)
return|return
name|vminnm_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vminnmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vminnmq_f32
comment|// CHECK: call<4 x float> @llvm.arm.neon.vminnm.v4f32(<4 x float> %a,<4 x float> %b)
return|return
name|vminnmq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

