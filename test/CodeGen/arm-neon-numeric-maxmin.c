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
comment|// CHECK-LABEL: define<2 x float> @test_vmaxnm_f32(<2 x float> %a,<2 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXNM_V2_I:%.*]] = call<2 x float> @llvm.arm.neon.vmaxnm.v2f32(<2 x float> %a,<2 x float> %b) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VMAXNM_V2_I]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vmaxnmq_f32(<4 x float> %a,<4 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMAXNMQ_V2_I:%.*]] = call<4 x float> @llvm.arm.neon.vmaxnm.v4f32(<4 x float> %a,<4 x float> %b) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VMAXNMQ_V2_I]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vminnm_f32(<2 x float> %a,<2 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINNM_V2_I:%.*]] = call<2 x float> @llvm.arm.neon.vminnm.v2f32(<2 x float> %a,<2 x float> %b) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[VMINNM_V2_I]]
end_comment

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

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vminnmq_f32(<4 x float> %a,<4 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VMINNMQ_V2_I:%.*]] = call<4 x float> @llvm.arm.neon.vminnm.v4f32(<4 x float> %a,<4 x float> %b) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VMINNMQ_V2_I]]
end_comment

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

