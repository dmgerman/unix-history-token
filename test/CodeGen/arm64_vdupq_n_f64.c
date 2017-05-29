begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -fallow-half-arguments-and-returns -S -o - -disable-O0-optnone -emit-llvm %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// vdupq_n_f64 -> dup.2d v0, v0[0]
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vdupq_n_f64(double %w) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x double> undef, double %w, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x double> [[VECINIT_I]], double %w, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VECINIT1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vdupq_n_f64
parameter_list|(
name|float64_t
name|w
parameter_list|)
block|{
return|return
name|vdupq_n_f64
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// might as well test this while we're here
end_comment

begin_comment
comment|// vdupq_n_f32 -> dup.4s v0, v0[0]
end_comment

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_vdupq_n_f32(float %w) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<4 x float> undef, float %w, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<4 x float> [[VECINIT_I]], float %w, i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2_I:%.*]] = insertelement<4 x float> [[VECINIT1_I]], float %w, i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3_I:%.*]] = insertelement<4 x float> [[VECINIT2_I]], float %w, i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[VECINIT3_I]]
end_comment

begin_function
name|float32x4_t
name|test_vdupq_n_f32
parameter_list|(
name|float32_t
name|w
parameter_list|)
block|{
return|return
name|vdupq_n_f32
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// vdupq_lane_f64 -> dup.2d v0, v0[0]
end_comment

begin_comment
comment|// this was in<rdar://problem/11778405>, but had already been implemented,
end_comment

begin_comment
comment|// test anyway
end_comment

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vdupq_lane_f64(<1 x double> %V) #0 {
end_comment

begin_comment
comment|// CHECK:   [[SHUFFLE:%.*]] = shufflevector<1 x double> %V,<1 x double> %V,<2 x i32> zeroinitializer
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[SHUFFLE]]
end_comment

begin_function
name|float64x2_t
name|test_vdupq_lane_f64
parameter_list|(
name|float64x1_t
name|V
parameter_list|)
block|{
return|return
name|vdupq_lane_f64
argument_list|(
name|V
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// vmovq_n_f64 -> dup Vd.2d,X0
end_comment

begin_comment
comment|// this wasn't in<rdar://problem/11778405>, but it was between the vdups
end_comment

begin_comment
comment|// CHECK-LABEL: define<2 x double> @test_vmovq_n_f64(double %w) #0 {
end_comment

begin_comment
comment|// CHECK:   [[VECINIT_I:%.*]] = insertelement<2 x double> undef, double %w, i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1_I:%.*]] = insertelement<2 x double> [[VECINIT_I]], double %w, i32 1
end_comment

begin_comment
comment|// CHECK:   ret<2 x double> [[VECINIT1_I]]
end_comment

begin_function
name|float64x2_t
name|test_vmovq_n_f64
parameter_list|(
name|float64_t
name|w
parameter_list|)
block|{
return|return
name|vmovq_n_f64
argument_list|(
name|w
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x half> @test_vmov_n_f16(half* %a1) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load half, half* %a1, align 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT:%.*]] = insertelement<4 x half> undef, half [[TMP0]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1:%.*]] = insertelement<4 x half> [[VECINIT]], half [[TMP0]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2:%.*]] = insertelement<4 x half> [[VECINIT1]], half [[TMP0]], i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3:%.*]] = insertelement<4 x half> [[VECINIT2]], half [[TMP0]], i32 3
end_comment

begin_comment
comment|// CHECK:   ret<4 x half> [[VECINIT3]]
end_comment

begin_function
name|float16x4_t
name|test_vmov_n_f16
parameter_list|(
name|float16_t
modifier|*
name|a1
parameter_list|)
block|{
return|return
name|vmov_n_f16
argument_list|(
operator|*
name|a1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* float64x1_t test_vmov_n_f64(float64_t a1) {   return vmov_n_f64(a1); } */
end_comment

begin_comment
comment|// CHECK-LABEL: define<8 x half> @test_vmovq_n_f16(half* %a1) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP0:%.*]] = load half, half* %a1, align 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT:%.*]] = insertelement<8 x half> undef, half [[TMP0]], i32 0
end_comment

begin_comment
comment|// CHECK:   [[VECINIT1:%.*]] = insertelement<8 x half> [[VECINIT]], half [[TMP0]], i32 1
end_comment

begin_comment
comment|// CHECK:   [[VECINIT2:%.*]] = insertelement<8 x half> [[VECINIT1]], half [[TMP0]], i32 2
end_comment

begin_comment
comment|// CHECK:   [[VECINIT3:%.*]] = insertelement<8 x half> [[VECINIT2]], half [[TMP0]], i32 3
end_comment

begin_comment
comment|// CHECK:   [[VECINIT4:%.*]] = insertelement<8 x half> [[VECINIT3]], half [[TMP0]], i32 4
end_comment

begin_comment
comment|// CHECK:   [[VECINIT5:%.*]] = insertelement<8 x half> [[VECINIT4]], half [[TMP0]], i32 5
end_comment

begin_comment
comment|// CHECK:   [[VECINIT6:%.*]] = insertelement<8 x half> [[VECINIT5]], half [[TMP0]], i32 6
end_comment

begin_comment
comment|// CHECK:   [[VECINIT7:%.*]] = insertelement<8 x half> [[VECINIT6]], half [[TMP0]], i32 7
end_comment

begin_comment
comment|// CHECK:   ret<8 x half> [[VECINIT7]]
end_comment

begin_function
name|float16x8_t
name|test_vmovq_n_f16
parameter_list|(
name|float16_t
modifier|*
name|a1
parameter_list|)
block|{
return|return
name|vmovq_n_f16
argument_list|(
operator|*
name|a1
argument_list|)
return|;
block|}
end_function

end_unit

