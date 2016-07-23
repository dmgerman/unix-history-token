begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv8-linux-gnueabihf -target-cpu cortex-a57 -ffreestanding -emit-llvm %s -o - | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMAXNM_V_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VMAXNM_V1_I:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VMAXNM_V2_I:%.*]] = call<2 x float> @llvm.arm.neon.vmaxnm.v2f32(<2 x float> [[VMAXNM_V_I]],<2 x float> [[VMAXNM_V1_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VMAXNM_V3_I:%.*]] = bitcast<2 x float> [[VMAXNM_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[VMAXNM_V3_I]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP2]]
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
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMAXNMQ_V_I:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VMAXNMQ_V1_I:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VMAXNMQ_V2_I:%.*]] = call<4 x float> @llvm.arm.neon.vmaxnm.v4f32(<4 x float> [[VMAXNMQ_V_I]],<4 x float> [[VMAXNMQ_V1_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VMAXNMQ_V3_I:%.*]] = bitcast<4 x float> [[VMAXNMQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[VMAXNMQ_V3_I]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP2]]
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
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMINNM_V_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VMINNM_V1_I:%.*]] = bitcast<8 x i8> [[TMP1]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VMINNM_V2_I:%.*]] = call<2 x float> @llvm.arm.neon.vminnm.v2f32(<2 x float> [[VMINNM_V_I]],<2 x float> [[VMINNM_V1_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VMINNM_V3_I:%.*]] = bitcast<2 x float> [[VMINNM_V2_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<8 x i8> [[VMINNM_V3_I]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP2]]
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
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VMINNMQ_V_I:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VMINNMQ_V1_I:%.*]] = bitcast<16 x i8> [[TMP1]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VMINNMQ_V2_I:%.*]] = call<4 x float> @llvm.arm.neon.vminnm.v4f32(<4 x float> [[VMINNMQ_V_I]],<4 x float> [[VMINNMQ_V1_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VMINNMQ_V3_I:%.*]] = bitcast<4 x float> [[VMINNMQ_V2_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<16 x i8> [[VMINNMQ_V3_I]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP2]]
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

