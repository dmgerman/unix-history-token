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
comment|// CHECK-LABEL: define<2 x float> @test_vrnda_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDA_V_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDA_V1_I:%.*]] = call<2 x float> @llvm.arm.neon.vrinta.v2f32(<2 x float> [[VRNDA_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDA_V2_I:%.*]] = bitcast<2 x float> [[VRNDA_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[VRNDA_V2_I]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP1]]
end_comment

begin_function
name|float32x2_t
name|test_vrnda_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrnda_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vrndaq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDAQ_V_I:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDAQ_V1_I:%.*]] = call<4 x float> @llvm.arm.neon.vrinta.v4f32(<4 x float> [[VRNDAQ_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDAQ_V2_I:%.*]] = bitcast<4 x float> [[VRNDAQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[VRNDAQ_V2_I]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP1]]
end_comment

begin_function
name|float32x4_t
name|test_vrndaq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndaq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vrndm_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDM_V_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDM_V1_I:%.*]] = call<2 x float> @llvm.arm.neon.vrintm.v2f32(<2 x float> [[VRNDM_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDM_V2_I:%.*]] = bitcast<2 x float> [[VRNDM_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[VRNDM_V2_I]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP1]]
end_comment

begin_function
name|float32x2_t
name|test_vrndm_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndm_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vrndmq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDMQ_V_I:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDMQ_V1_I:%.*]] = call<4 x float> @llvm.arm.neon.vrintm.v4f32(<4 x float> [[VRNDMQ_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDMQ_V2_I:%.*]] = bitcast<4 x float> [[VRNDMQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[VRNDMQ_V2_I]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP1]]
end_comment

begin_function
name|float32x4_t
name|test_vrndmq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndmq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vrndn_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDN_V_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDN_V1_I:%.*]] = call<2 x float> @llvm.arm.neon.vrintn.v2f32(<2 x float> [[VRNDN_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDN_V2_I:%.*]] = bitcast<2 x float> [[VRNDN_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[VRNDN_V2_I]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP1]]
end_comment

begin_function
name|float32x2_t
name|test_vrndn_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndn_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vrndnq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDNQ_V_I:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDNQ_V1_I:%.*]] = call<4 x float> @llvm.arm.neon.vrintn.v4f32(<4 x float> [[VRNDNQ_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDNQ_V2_I:%.*]] = bitcast<4 x float> [[VRNDNQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[VRNDNQ_V2_I]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP1]]
end_comment

begin_function
name|float32x4_t
name|test_vrndnq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndnq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vrndp_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDP_V_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDP_V1_I:%.*]] = call<2 x float> @llvm.arm.neon.vrintp.v2f32(<2 x float> [[VRNDP_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDP_V2_I:%.*]] = bitcast<2 x float> [[VRNDP_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[VRNDP_V2_I]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP1]]
end_comment

begin_function
name|float32x2_t
name|test_vrndp_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndp_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vrndpq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDPQ_V_I:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDPQ_V1_I:%.*]] = call<4 x float> @llvm.arm.neon.vrintp.v4f32(<4 x float> [[VRNDPQ_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDPQ_V2_I:%.*]] = bitcast<4 x float> [[VRNDPQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[VRNDPQ_V2_I]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP1]]
end_comment

begin_function
name|float32x4_t
name|test_vrndpq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndpq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vrndx_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDX_V_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDX_V1_I:%.*]] = call<2 x float> @llvm.arm.neon.vrintx.v2f32(<2 x float> [[VRNDX_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDX_V2_I:%.*]] = bitcast<2 x float> [[VRNDX_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[VRNDX_V2_I]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP1]]
end_comment

begin_function
name|float32x2_t
name|test_vrndx_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrndx_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vrndxq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDXQ_V_I:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDXQ_V1_I:%.*]] = call<4 x float> @llvm.arm.neon.vrintx.v4f32(<4 x float> [[VRNDXQ_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDXQ_V2_I:%.*]] = bitcast<4 x float> [[VRNDXQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[VRNDXQ_V2_I]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP1]]
end_comment

begin_function
name|float32x4_t
name|test_vrndxq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndxq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vrnd_f32(<2 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRND_V_I:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRND_V1_I:%.*]] = call<2 x float> @llvm.arm.neon.vrintz.v2f32(<2 x float> [[VRND_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRND_V2_I:%.*]] = bitcast<2 x float> [[VRND_V1_I]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[VRND_V2_I]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP1]]
end_comment

begin_function
name|float32x2_t
name|test_vrnd_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|)
block|{
return|return
name|vrnd_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vrndq_f32(<4 x float> %a) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %a to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[VRNDQ_V_I:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VRNDQ_V1_I:%.*]] = call<4 x float> @llvm.arm.neon.vrintz.v4f32(<4 x float> [[VRNDQ_V_I]]) #2
end_comment

begin_comment
comment|// CHECK:   [[VRNDQ_V2_I:%.*]] = bitcast<4 x float> [[VRNDQ_V1_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[VRNDQ_V2_I]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP1]]
end_comment

begin_function
name|float32x4_t
name|test_vrndq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vrndq_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

