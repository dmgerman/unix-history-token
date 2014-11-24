begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon -S -O3 -o - %s | FileCheck %s
end_comment

begin_comment
comment|// Test new aarch64 intrinsics and types
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

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
comment|// CHECK-LABEL: test_vmla_n_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
comment|// CHECK: fadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
comment|// CHECK-FMA: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlaq_n_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
comment|// CHECK: fadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
comment|// CHECK-FMA: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlaq_n_f64
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
comment|// CHECK: fmul {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
comment|// CHECK: fadd {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
comment|// CHECK-FMA: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
comment|// CHECK-FMA: fmla {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlsq_n_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
comment|// CHECK: fsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: dup {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
comment|// CHECK-FMA: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
block|}
end_function

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
comment|// CHECK-LABEL: test_vmls_n_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
comment|// CHECK: fsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: dup {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
comment|// CHECK-FMA: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlsq_n_f64
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
comment|// CHECK: fmul {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
comment|// CHECK: fsub {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
comment|// CHECK-FMA: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
comment|// CHECK-FMA: fmls {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

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
comment|// CHECK-LABEL: test_vmla_lane_f32_0
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
comment|// CHECK: fadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlaq_lane_f32_0
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
comment|// CHECK: fadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmla_laneq_f32_0
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
comment|// CHECK: fadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlaq_laneq_f32_0
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
comment|// CHECK: fadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmls_lane_f32_0
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
comment|// CHECK: fsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlsq_lane_f32_0
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
comment|// CHECK: fsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmls_laneq_f32_0
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
comment|// CHECK: fsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[0]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlsq_laneq_f32_0
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
comment|// CHECK: fsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[0]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmla_lane_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
comment|// CHECK: fadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlaq_lane_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
comment|// CHECK: fadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmla_laneq_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
comment|// CHECK: fadd {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: fmla {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlaq_laneq_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
comment|// CHECK: fadd {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: fmla {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmls_lane_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
comment|// CHECK: fsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[1]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlsq_lane_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
comment|// CHECK: fsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[1]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmls_laneq_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
comment|// CHECK: fsub {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.2s
comment|// CHECK-FMA: fmls {{v[0-9]+}}.2s, {{v[0-9]+}}.2s, {{v[0-9]+}}.s[3]
block|}
end_function

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
comment|// CHECK-LABEL: test_vmlsq_laneq_f32
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
comment|// CHECK: fmul {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
comment|// CHECK: fsub {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.4s
comment|// CHECK-FMA: fmls {{v[0-9]+}}.4s, {{v[0-9]+}}.4s, {{v[0-9]+}}.s[3]
block|}
end_function

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
comment|// CHECK-LABEL: test_vfmaq_n_f64:
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
comment|// CHECK: fmla {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+\.2d|v[0-9]+\.d\[0\]}}
block|}
end_function

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
comment|// CHECK-LABEL: test_vfmsq_n_f64:
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
comment|// CHECK: fmls {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+\.2d|v[0-9]+\.d\[0\]}}
block|}
end_function

end_unit

