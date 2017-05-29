begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon -target-cpu cyclone \
end_comment

begin_comment
comment|// RUN: -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK-LABEL: define float @test_vmuls_lane_f32(float %a,<2 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<2 x float> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul float %a, [[VGET_LANE]]
end_comment

begin_comment
comment|// CHECK:   ret float [[MUL]]
end_comment

begin_function
name|float32_t
name|test_vmuls_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmuls_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @test_vmuld_lane_f64(double %a,<1 x double> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x double> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul double %a, [[VGET_LANE]]
end_comment

begin_comment
comment|// CHECK:   ret double [[MUL]]
end_comment

begin_function
name|float64_t
name|test_vmuld_lane_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
return|return
name|vmuld_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vmuls_laneq_f32(float %a,<4 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x float> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul float %a, [[VGETQ_LANE]]
end_comment

begin_comment
comment|// CHECK:   ret float [[MUL]]
end_comment

begin_function
name|float32_t
name|test_vmuls_laneq_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmuls_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @test_vmuld_laneq_f64(double %a,<2 x double> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x double> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul double %a, [[VGETQ_LANE]]
end_comment

begin_comment
comment|// CHECK:   ret double [[MUL]]
end_comment

begin_function
name|float64_t
name|test_vmuld_laneq_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
return|return
name|vmuld_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vmul_n_f64(<1 x double> %a, double %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<1 x double> %a to double
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = fmul double [[TMP2]], %b
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast double [[TMP3]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[TMP4]]
end_comment

begin_function
name|float64x1_t
name|test_vmul_n_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|)
block|{
return|return
name|vmul_n_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vmulxs_lane_f32(float %a,<2 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<2 x float> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VMULXS_F32_I:%.*]] = call float @llvm.aarch64.neon.fmulx.f32(float %a, float [[VGET_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret float [[VMULXS_F32_I]]
end_comment

begin_function
name|float32_t
name|test_vmulxs_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|)
block|{
return|return
name|vmulxs_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vmulxs_laneq_f32(float %a,<4 x float> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x float> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x float>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x float> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[VMULXS_F32_I:%.*]] = call float @llvm.aarch64.neon.fmulx.f32(float %a, float [[VGETQ_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret float [[VMULXS_F32_I]]
end_comment

begin_function
name|float32_t
name|test_vmulxs_laneq_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|)
block|{
return|return
name|vmulxs_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @test_vmulxd_lane_f64(double %a,<1 x double> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x double> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double %a, double [[VGET_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret double [[VMULXD_F64_I]]
end_comment

begin_function
name|float64_t
name|test_vmulxd_lane_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
return|return
name|vmulxd_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @test_vmulxd_laneq_f64(double %a,<2 x double> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x double> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double %a, double [[VGETQ_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret double [[VMULXD_F64_I]]
end_comment

begin_function
name|float64_t
name|test_vmulxd_laneq_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
return|return
name|vmulxd_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vmulx_lane_f64(<1 x double> %a,<1 x double> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x double> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<1 x double> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE6:%.*]] = extractelement<1 x double> [[TMP3]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGET_LANE6]])
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<8 x i8> [[TMP4]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<1 x double> [[TMP5]], double [[VMULXD_F64_I]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[VSET_LANE]]
end_comment

begin_function
name|float64x1_t
name|test_vmulx_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|)
block|{
return|return
name|vmulx_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vmulx_laneq_f64_0(<1 x double> %a,<2 x double> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x double> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x double> [[TMP3]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGETQ_LANE]])
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<8 x i8> [[TMP4]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<1 x double> [[TMP5]], double [[VMULXD_F64_I]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[VSET_LANE]]
end_comment

begin_function
name|float64x1_t
name|test_vmulx_laneq_f64_0
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
return|return
name|vmulx_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vmulx_laneq_f64_1(<1 x double> %a,<2 x double> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x double> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x double> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x double> [[TMP3]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGETQ_LANE]])
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<8 x i8> [[TMP4]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<1 x double> [[TMP5]], double [[VMULXD_F64_I]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[VSET_LANE]]
end_comment

begin_function
name|float64x1_t
name|test_vmulx_laneq_f64_1
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|)
block|{
return|return
name|vmulx_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vfmas_lane_f32(float %a, float %b,<2 x float> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %c to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<2 x float> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = call float @llvm.fma.f32(float %b, float [[EXTRACT]], float %a)
end_comment

begin_comment
comment|// CHECK:   ret float [[TMP2]]
end_comment

begin_function
name|float32_t
name|test_vfmas_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vfmas_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @test_vfmad_lane_f64(double %a, double %b,<1 x double> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %c to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<1 x double> [[TMP1]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = call double @llvm.fma.f64(double %b, double [[EXTRACT]], double %a)
end_comment

begin_comment
comment|// CHECK:   ret double [[TMP2]]
end_comment

begin_function
name|float64_t
name|test_vfmad_lane_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|,
name|float64x1_t
name|c
parameter_list|)
block|{
return|return
name|vfmad_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define double @test_vfmad_laneq_f64(double %a, double %b,<2 x double> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x double> %c to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<2 x double> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = call double @llvm.fma.f64(double %b, double [[EXTRACT]], double %a)
end_comment

begin_comment
comment|// CHECK:   ret double [[TMP2]]
end_comment

begin_function
name|float64_t
name|test_vfmad_laneq_f64
parameter_list|(
name|float64_t
name|a
parameter_list|,
name|float64_t
name|b
parameter_list|,
name|float64x2_t
name|c
parameter_list|)
block|{
return|return
name|vfmad_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define float @test_vfmss_lane_f32(float %a, float %b,<2 x float> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub float -0.000000e+00, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x float> %c to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x float>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<2 x float> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = call float @llvm.fma.f32(float [[SUB]], float [[EXTRACT]], float %a)
end_comment

begin_comment
comment|// CHECK:   ret float [[TMP2]]
end_comment

begin_function
name|float32_t
name|test_vfmss_lane_f32
parameter_list|(
name|float32_t
name|a
parameter_list|,
name|float32_t
name|b
parameter_list|,
name|float32x2_t
name|c
parameter_list|)
block|{
return|return
name|vfmss_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vfma_lane_f64(<1 x double> %a,<1 x double> %b,<1 x double> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x double> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<1 x double> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<1 x double> [[TMP3]],<1 x double> [[TMP3]],<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<8 x i8> [[TMP1]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<1 x double> @llvm.fma.v1f64(<1 x double> [[FMLA]],<1 x double> [[LANE]],<1 x double> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[FMLA2]]
end_comment

begin_function
name|float64x1_t
name|test_vfma_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vfma_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vfms_lane_f64(<1 x double> %a,<1 x double> %b,<1 x double> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<1 x double><double -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x double> [[SUB]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<1 x double> %v to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = shufflevector<1 x double> [[TMP3]],<1 x double> [[TMP3]],<1 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[FMLA:%.*]] = bitcast<8 x i8> [[TMP1]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[FMLA1:%.*]] = bitcast<8 x i8> [[TMP0]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[FMLA2:%.*]] = call<1 x double> @llvm.fma.v1f64(<1 x double> [[FMLA]],<1 x double> [[LANE]],<1 x double> [[FMLA1]])
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[FMLA2]]
end_comment

begin_function
name|float64x1_t
name|test_vfms_lane_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x1_t
name|v
parameter_list|)
block|{
return|return
name|vfms_lane_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vfma_laneq_f64(<1 x double> %a,<1 x double> %b,<2 x double> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x double> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x double> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP0]] to double
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<8 x i8> [[TMP1]] to double
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<2 x double> [[TMP5]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call double @llvm.fma.f64(double [[TMP4]], double [[EXTRACT]], double [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = bitcast double [[TMP6]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[TMP7]]
end_comment

begin_function
name|float64x1_t
name|test_vfma_laneq_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vfma_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vfms_laneq_f64(<1 x double> %a,<1 x double> %b,<2 x double> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<1 x double><double -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<1 x double> %a to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<1 x double> [[SUB]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<2 x double> %v to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP0]] to double
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<8 x i8> [[TMP1]] to double
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP2]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[EXTRACT:%.*]] = extractelement<2 x double> [[TMP5]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call double @llvm.fma.f64(double [[TMP4]], double [[EXTRACT]], double [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = bitcast double [[TMP6]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[TMP7]]
end_comment

begin_function
name|float64x1_t
name|test_vfms_laneq_f64
parameter_list|(
name|float64x1_t
name|a
parameter_list|,
name|float64x1_t
name|b
parameter_list|,
name|float64x2_t
name|v
parameter_list|)
block|{
return|return
name|vfms_laneq_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqdmullh_lane_s16(i16 %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<4 x i16> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %a, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[VGET_LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMULLH_S16_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = extractelement<4 x i32> [[VQDMULLH_S16_I]], i64 0
end_comment

begin_comment
comment|// CHECK:   ret i32 [[TMP4]]
end_comment

begin_function
name|int32_t
name|test_vqdmullh_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmullh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vqdmulls_lane_s32(i32 %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<2 x i32> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VQDMULLS_S32_I:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 %a, i32 [[VGET_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VQDMULLS_S32_I]]
end_comment

begin_function
name|int64_t
name|test_vqdmulls_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulls_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqdmullh_laneq_s16(i16 %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %a, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[VGETQ_LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMULLH_S16_I:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = extractelement<4 x i32> [[VQDMULLH_S16_I]], i64 0
end_comment

begin_comment
comment|// CHECK:   ret i32 [[TMP4]]
end_comment

begin_function
name|int32_t
name|test_vqdmullh_laneq_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqdmullh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vqdmulls_laneq_s32(i32 %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x i32> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[VQDMULLS_S32_I:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 %a, i32 [[VGETQ_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VQDMULLS_S32_I]]
end_comment

begin_function
name|int64_t
name|test_vqdmulls_laneq_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulls_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vqdmulhh_lane_s16(i16 %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<4 x i16> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %a, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[VGET_LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHH_S16_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqdmulh.v4i16(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = extractelement<4 x i16> [[VQDMULHH_S16_I]], i64 0
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP4]]
end_comment

begin_function
name|int16_t
name|test_vqdmulhh_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqdmulhs_lane_s32(i32 %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<2 x i32> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHS_S32_I:%.*]] = call i32 @llvm.aarch64.neon.sqdmulh.i32(i32 %a, i32 [[VGET_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VQDMULHS_S32_I]]
end_comment

begin_function
name|int32_t
name|test_vqdmulhs_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhs_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vqdmulhh_laneq_s16(i16 %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %a, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[VGETQ_LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHH_S16_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqdmulh.v4i16(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = extractelement<4 x i16> [[VQDMULHH_S16_I]], i64 0
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP4]]
end_comment

begin_function
name|int16_t
name|test_vqdmulhh_laneq_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqdmulhs_laneq_s32(i32 %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x i32> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[VQDMULHS_S32_I:%.*]] = call i32 @llvm.aarch64.neon.sqdmulh.i32(i32 %a, i32 [[VGETQ_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VQDMULHS_S32_I]]
end_comment

begin_function
name|int32_t
name|test_vqdmulhs_laneq_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqdmulhs_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vqrdmulhh_lane_s16(i16 %a,<4 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<4 x i16> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %a, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[VGET_LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHH_S16_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqrdmulh.v4i16(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = extractelement<4 x i16> [[VQRDMULHH_S16_I]], i64 0
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP4]]
end_comment

begin_function
name|int16_t
name|test_vqrdmulhh_lane_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqrdmulhs_lane_s32(i32 %a,<2 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %b to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<2 x i32> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHS_S32_I:%.*]] = call i32 @llvm.aarch64.neon.sqrdmulh.i32(i32 %a, i32 [[VGET_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VQRDMULHS_S32_I]]
end_comment

begin_function
name|int32_t
name|test_vqrdmulhs_lane_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x2_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhs_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i16 @test_vqrdmulhh_laneq_s16(i16 %a,<8 x i16> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %a, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[VGETQ_LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHH_S16_I:%.*]] = call<4 x i16> @llvm.aarch64.neon.sqrdmulh.v4i16(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = extractelement<4 x i16> [[VQRDMULHH_S16_I]], i64 0
end_comment

begin_comment
comment|// CHECK:   ret i16 [[TMP4]]
end_comment

begin_function
name|int16_t
name|test_vqrdmulhh_laneq_s16
parameter_list|(
name|int16_t
name|a
parameter_list|,
name|int16x8_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqrdmulhs_laneq_s32(i32 %a,<4 x i32> %b) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %b to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<4 x i32> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[VQRDMULHS_S32_I:%.*]] = call i32 @llvm.aarch64.neon.sqrdmulh.i32(i32 %a, i32 [[VGETQ_LANE]])
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VQRDMULHS_S32_I]]
end_comment

begin_function
name|int32_t
name|test_vqrdmulhs_laneq_s32
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int32x4_t
name|b
parameter_list|)
block|{
return|return
name|vqrdmulhs_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqdmlalh_lane_s16(i32 %a, i16 %b,<4 x i16> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %c to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = extractelement<4 x i16> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %b, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[LANE0:%.*]] = extractelement<4 x i32> [[VQDMLXL]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL1:%.*]] = call i32 @llvm.aarch64.neon.sqadd.i32(i32 %a, i32 [[LANE0]])
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VQDMLXL1]]
end_comment

begin_function
name|int32_t
name|test_vqdmlalh_lane_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlalh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vqdmlals_lane_s32(i64 %a, i32 %b,<2 x i32> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %c to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = extractelement<2 x i32> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 %b, i32 [[LANE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL1:%.*]] = call i64 @llvm.aarch64.neon.sqadd.i64(i64 %a, i64 [[VQDMLXL]])
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VQDMLXL1]]
end_comment

begin_function
name|int64_t
name|test_vqdmlals_lane_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlals_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqdmlalh_laneq_s16(i32 %a, i16 %b,<8 x i16> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %c to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %b, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[LANE0:%.*]] = extractelement<4 x i32> [[VQDMLXL]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL1:%.*]] = call i32 @llvm.aarch64.neon.sqadd.i32(i32 %a, i32 [[LANE0]])
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VQDMLXL1]]
end_comment

begin_function
name|int32_t
name|test_vqdmlalh_laneq_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlalh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vqdmlals_laneq_s32(i64 %a, i32 %b,<4 x i32> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %c to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = extractelement<4 x i32> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 %b, i32 [[LANE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL1:%.*]] = call i64 @llvm.aarch64.neon.sqadd.i64(i64 %a, i64 [[VQDMLXL]])
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VQDMLXL1]]
end_comment

begin_function
name|int64_t
name|test_vqdmlals_laneq_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlals_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqdmlslh_lane_s16(i32 %a, i16 %b,<4 x i16> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i16> %c to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<4 x i16>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = extractelement<4 x i16> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %b, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[LANE0:%.*]] = extractelement<4 x i32> [[VQDMLXL]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL1:%.*]] = call i32 @llvm.aarch64.neon.sqsub.i32(i32 %a, i32 [[LANE0]])
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VQDMLXL1]]
end_comment

begin_function
name|int32_t
name|test_vqdmlslh_lane_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlslh_lane_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vqdmlsls_lane_s32(i64 %a, i32 %b,<2 x i32> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<2 x i32> %c to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<8 x i8> [[TMP0]] to<2 x i32>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = extractelement<2 x i32> [[TMP1]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 %b, i32 [[LANE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL1:%.*]] = call i64 @llvm.aarch64.neon.sqsub.i64(i64 %a, i64 [[VQDMLXL]])
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VQDMLXL1]]
end_comment

begin_function
name|int64_t
name|test_vqdmlsls_lane_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32x2_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsls_lane_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i32 @test_vqdmlslh_laneq_s16(i32 %a, i16 %b,<8 x i16> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<8 x i16> %c to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<8 x i16>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = extractelement<8 x i16> [[TMP1]], i32 7
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = insertelement<4 x i16> undef, i16 %b, i64 0
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = insertelement<4 x i16> undef, i16 [[LANE]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL:%.*]] = call<4 x i32> @llvm.aarch64.neon.sqdmull.v4i32(<4 x i16> [[TMP2]],<4 x i16> [[TMP3]])
end_comment

begin_comment
comment|// CHECK:   [[LANE0:%.*]] = extractelement<4 x i32> [[VQDMLXL]], i64 0
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL1:%.*]] = call i32 @llvm.aarch64.neon.sqsub.i32(i32 %a, i32 [[LANE0]])
end_comment

begin_comment
comment|// CHECK:   ret i32 [[VQDMLXL1]]
end_comment

begin_function
name|int32_t
name|test_vqdmlslh_laneq_s16
parameter_list|(
name|int32_t
name|a
parameter_list|,
name|int16_t
name|b
parameter_list|,
name|int16x8_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlslh_laneq_s16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define i64 @test_vqdmlsls_laneq_s32(i64 %a, i32 %b,<4 x i32> %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast<4 x i32> %c to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast<16 x i8> [[TMP0]] to<4 x i32>
end_comment

begin_comment
comment|// CHECK:   [[LANE:%.*]] = extractelement<4 x i32> [[TMP1]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL:%.*]] = call i64 @llvm.aarch64.neon.sqdmulls.scalar(i32 %b, i32 [[LANE]])
end_comment

begin_comment
comment|// CHECK:   [[VQDMLXL1:%.*]] = call i64 @llvm.aarch64.neon.sqsub.i64(i64 %a, i64 [[VQDMLXL]])
end_comment

begin_comment
comment|// CHECK:   ret i64 [[VQDMLXL1]]
end_comment

begin_function
name|int64_t
name|test_vqdmlsls_laneq_s32
parameter_list|(
name|int64_t
name|a
parameter_list|,
name|int32_t
name|b
parameter_list|,
name|int32x4_t
name|c
parameter_list|)
block|{
return|return
name|vqdmlsls_laneq_s32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vmulx_lane_f64_0() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i64 4599917171378402754 to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i64 4606655882138939123 to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<1 x double> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x double> [[TMP3]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<1 x double> [[TMP1]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<8 x i8> [[TMP4]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE7:%.*]] = extractelement<1 x double> [[TMP5]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGET_LANE7]])
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<1 x double> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = bitcast<8 x i8> [[TMP6]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<1 x double> [[TMP7]], double [[VMULXD_F64_I]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[VSET_LANE]]
end_comment

begin_function
name|float64x1_t
name|test_vmulx_lane_f64_0
parameter_list|()
block|{
name|float64x1_t
name|arg1
decl_stmt|;
name|float64x1_t
name|arg2
decl_stmt|;
name|float64x1_t
name|result
decl_stmt|;
name|float64_t
name|sarg1
decl_stmt|,
name|sarg2
decl_stmt|,
name|sres
decl_stmt|;
name|arg1
operator|=
name|vcreate_f64
argument_list|(
name|UINT64_C
argument_list|(
literal|0x3fd6304bc43ab5c2
argument_list|)
argument_list|)
expr_stmt|;
name|arg2
operator|=
name|vcreate_f64
argument_list|(
name|UINT64_C
argument_list|(
literal|0x3fee211e215aeef3
argument_list|)
argument_list|)
expr_stmt|;
name|result
operator|=
name|vmulx_lane_f64
argument_list|(
name|arg1
argument_list|,
name|arg2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<1 x double> @test_vmulx_laneq_f64_2() #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = bitcast i64 4599917171378402754 to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[TMP1:%.*]] = bitcast i64 4606655882138939123 to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE_I:%.*]] = shufflevector<1 x double> [[TMP0]],<1 x double> [[TMP1]],<2 x i32><i32 0, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[TMP2:%.*]] = bitcast<1 x double> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP3:%.*]] = bitcast<8 x i8> [[TMP2]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGET_LANE:%.*]] = extractelement<1 x double> [[TMP3]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[TMP4:%.*]] = bitcast<2 x double> [[SHUFFLE_I]] to<16 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP5:%.*]] = bitcast<16 x i8> [[TMP4]] to<2 x double>
end_comment

begin_comment
comment|// CHECK:   [[VGETQ_LANE:%.*]] = extractelement<2 x double> [[TMP5]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VMULXD_F64_I:%.*]] = call double @llvm.aarch64.neon.fmulx.f64(double [[VGET_LANE]], double [[VGETQ_LANE]])
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = bitcast<1 x double> [[TMP0]] to<8 x i8>
end_comment

begin_comment
comment|// CHECK:   [[TMP7:%.*]] = bitcast<8 x i8> [[TMP6]] to<1 x double>
end_comment

begin_comment
comment|// CHECK:   [[VSET_LANE:%.*]] = insertelement<1 x double> [[TMP7]], double [[VMULXD_F64_I]], i32 0
end_comment

begin_comment
comment|// CHECK:   ret<1 x double> [[VSET_LANE]]
end_comment

begin_function
name|float64x1_t
name|test_vmulx_laneq_f64_2
parameter_list|()
block|{
name|float64x1_t
name|arg1
decl_stmt|;
name|float64x1_t
name|arg2
decl_stmt|;
name|float64x2_t
name|arg3
decl_stmt|;
name|float64x1_t
name|result
decl_stmt|;
name|float64_t
name|sarg1
decl_stmt|,
name|sarg2
decl_stmt|,
name|sres
decl_stmt|;
name|arg1
operator|=
name|vcreate_f64
argument_list|(
name|UINT64_C
argument_list|(
literal|0x3fd6304bc43ab5c2
argument_list|)
argument_list|)
expr_stmt|;
name|arg2
operator|=
name|vcreate_f64
argument_list|(
name|UINT64_C
argument_list|(
literal|0x3fee211e215aeef3
argument_list|)
argument_list|)
expr_stmt|;
name|arg3
operator|=
name|vcombine_f64
argument_list|(
name|arg1
argument_list|,
name|arg2
argument_list|)
expr_stmt|;
name|result
operator|=
name|vmulx_laneq_f64
argument_list|(
name|arg1
argument_list|,
name|arg3
argument_list|,
literal|1
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_function

end_unit

