begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon -S -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
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
comment|// CHECK-LABEL: define<2 x float> @test_vmla_n_f32(<2 x float> %a,<2 x float> %b, float %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x float> undef, float %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x float> [[VECINIT_I]], float %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = fmul<2 x float> %b, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = fadd<2 x float> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[ADD_I]]
end_comment

begin_function
name|float32x2_t
name|test_vmla_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32_t
name|c
parameter_list|)
block|{
return|return
name|vmla_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vmlaq_n_f32(<4 x float> %a,<4 x float> %b, float %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x float> undef, float %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x float> [[VECINIT_I]], float %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x float> [[VECINIT1_I]], float %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x float> [[VECINIT2_I]], float %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = fmul<4 x float> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = fadd<4 x float> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[ADD_I]]
end_comment

begin_function
name|float32x4_t
name|test_vmlaq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vmlaq_n_f64(<2 x double> %a,<2 x double> %b, double %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x double> undef, double %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x double> [[VECINIT_I]], double %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = fmul<2 x double> %b, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   [[ADD_I:%.*]] = fadd<2 x double> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[ADD_I]]
end_comment

begin_function
name|float64x2_t
name|test_vmlaq_n_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64_t
name|c
parameter_list|)
block|{
return|return
name|vmlaq_n_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vmlsq_n_f32(<4 x float> %a,<4 x float> %b, float %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x float> undef, float %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x float> [[VECINIT_I]], float %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x float> [[VECINIT1_I]], float %c, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x float> [[VECINIT2_I]], float %c, i32 3
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = fmul<4 x float> %b, [[VECINIT3_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = fsub<4 x float> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SUB_I]]
end_comment

begin_function
name|float32x4_t
name|test_vmlsq_n_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vmls_n_f32(<2 x float> %a,<2 x float> %b, float %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x float> undef, float %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x float> [[VECINIT_I]], float %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = fmul<2 x float> %b, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = fsub<2 x float> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SUB_I]]
end_comment

begin_function
name|float32x2_t
name|test_vmls_n_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32_t
name|c
parameter_list|)
block|{
return|return
name|vmls_n_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vmlsq_n_f64(<2 x double> %a,<2 x double> %b, double %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x double> undef, double %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x double> [[VECINIT_I]], double %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[MUL_I:%.*]] = fmul<2 x double> %b, [[VECINIT1_I]]
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = fsub<2 x double> %a, [[MUL_I]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SUB_I]]
end_comment

begin_function
name|float64x2_t
name|test_vmlsq_n_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64_t
name|c
parameter_list|)
block|{
return|return
name|vmlsq_n_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vmla_lane_f32_0(<2 x float> %a,<2 x float> %b,<2 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = fadd<2 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[ADD]]
end_comment

begin_function
name|float32x2_t
name|test_vmla_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_f32
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
comment|// CHECK-LABEL: define<4 x float> @test_vmlaq_lane_f32_0(<4 x float> %a,<4 x float> %b,<2 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = fadd<4 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[ADD]]
end_comment

begin_function
name|float32x4_t
name|test_vmlaq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_f32
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
comment|// CHECK-LABEL: define<2 x float> @test_vmla_laneq_f32_0(<2 x float> %a,<2 x float> %b,<4 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = fadd<2 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[ADD]]
end_comment

begin_function
name|float32x2_t
name|test_vmla_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_f32
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
comment|// CHECK-LABEL: define<4 x float> @test_vmlaq_laneq_f32_0(<4 x float> %a,<4 x float> %b,<4 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = fadd<4 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[ADD]]
end_comment

begin_function
name|float32x4_t
name|test_vmlaq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_f32
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
comment|// CHECK-LABEL: define<2 x float> @test_vmls_lane_f32_0(<2 x float> %a,<2 x float> %b,<2 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SUB]]
end_comment

begin_function
name|float32x2_t
name|test_vmls_lane_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_f32
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
comment|// CHECK-LABEL: define<4 x float> @test_vmlsq_lane_f32_0(<4 x float> %a,<4 x float> %b,<2 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<4 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SUB]]
end_comment

begin_function
name|float32x4_t
name|test_vmlsq_lane_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_f32
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
comment|// CHECK-LABEL: define<2 x float> @test_vmls_laneq_f32_0(<2 x float> %a,<2 x float> %b,<4 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SUB]]
end_comment

begin_function
name|float32x2_t
name|test_vmls_laneq_f32_0
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_f32
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
comment|// CHECK-LABEL: define<4 x float> @test_vmlsq_laneq_f32_0(<4 x float> %a,<4 x float> %b,<4 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<4 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<4 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SUB]]
end_comment

begin_function
name|float32x4_t
name|test_vmlsq_laneq_f32_0
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_f32
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
comment|// CHECK-LABEL: define<2 x float> @test_vmla_lane_f32(<2 x float> %a,<2 x float> %b,<2 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = fadd<2 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[ADD]]
end_comment

begin_function
name|float32x2_t
name|test_vmla_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmla_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vmlaq_lane_f32(<4 x float> %a,<4 x float> %b,<2 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = fadd<4 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[ADD]]
end_comment

begin_function
name|float32x4_t
name|test_vmlaq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vmla_laneq_f32(<2 x float> %a,<2 x float> %b,<4 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = fadd<2 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[ADD]]
end_comment

begin_function
name|float32x2_t
name|test_vmla_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmla_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vmlaq_laneq_f32(<4 x float> %a,<4 x float> %b,<4 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[ADD:%.*]] = fadd<4 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[ADD]]
end_comment

begin_function
name|float32x4_t
name|test_vmlaq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlaq_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vmls_lane_f32(<2 x float> %a,<2 x float> %b,<2 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<2 x i32><i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SUB]]
end_comment

begin_function
name|float32x2_t
name|test_vmls_lane_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmls_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vmlsq_lane_f32(<4 x float> %a,<4 x float> %b,<2 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<2 x float> %v,<2 x float> %v,<4 x i32><i32 1, i32 1, i32 1, i32 1>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<4 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SUB]]
end_comment

begin_function
name|float32x4_t
name|test_vmlsq_lane_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x2_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_lane_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_vmls_laneq_f32(<2 x float> %a,<2 x float> %b,<4 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<2 x i32><i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<2 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<2 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[SUB]]
end_comment

begin_function
name|float32x2_t
name|test_vmls_laneq_f32
parameter_list|(
name|float32x2_t
name|a
parameter_list|,
name|float32x2_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmls_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vmlsq_laneq_f32(<4 x float> %a,<4 x float> %b,<4 x float> %v) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<4 x float> %v,<4 x float> %v,<4 x i32><i32 3, i32 3, i32 3, i32 3>
end_comment

begin_comment
comment|// CHECK:   [[MUL:%.*]] = fmul<4 x float> %b, [[SHUFFLE]]
end_comment

begin_comment
comment|// CHECK:   [[SUB:%.*]] = fsub<4 x float> %a, [[MUL]]
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[SUB]]
end_comment

begin_function
name|float32x4_t
name|test_vmlsq_laneq_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|,
name|float32x4_t
name|b
parameter_list|,
name|float32x4_t
name|v
parameter_list|)
block|{
return|return
name|vmlsq_laneq_f32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|v
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vfmaq_n_f64(<2 x double> %a,<2 x double> %b, double %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x double> undef, double %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x double> [[VECINIT_I]], double %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x double> @llvm.fma.v2f64(<2 x double> %b,<2 x double> [[VECINIT1_I]],<2 x double> %a)
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[TMP6]]
end_comment

begin_function
name|float64x2_t
name|test_vfmaq_n_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64_t
name|c
parameter_list|)
block|{
return|return
name|vfmaq_n_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vfmsq_n_f64(<2 x double> %a,<2 x double> %b, double %c) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SUB_I:%.*]] = fsub<2 x double><double -0.000000e+00, double -0.000000e+00>, %b
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x double> undef, double %c, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x double> [[VECINIT_I]], double %c, i32 1
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x double> @llvm.fma.v2f64(<2 x double> [[SUB_I]],<2 x double> [[VECINIT1_I]],<2 x double> %a) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[TMP6]]
end_comment

begin_function
name|float64x2_t
name|test_vfmsq_n_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|,
name|float64x2_t
name|b
parameter_list|,
name|float64_t
name|c
parameter_list|)
block|{
return|return
name|vfmsq_n_f64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

end_unit

