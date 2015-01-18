begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:  -ffp-contract=fast -S -O3 -o - %s | FileCheck %s --check-prefix=CHECK \
end_comment

begin_comment
comment|// RUN:  --check-prefix=CHECK-ARM64
end_comment

begin_comment
comment|// Test new aarch64 intrinsics with poly64
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|uint64x1_t
name|test_vceq_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceq_p64
return|return
name|vceq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmeq {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vceqq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vceqq_p64
return|return
name|vceqq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmeq {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|uint64x1_t
name|test_vtst_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtst_p64
return|return
name|vtst_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmtst {{d[0-9]+}}, {{d[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|uint64x2_t
name|test_vtstq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtstq_p64
return|return
name|vtstq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: cmtst {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|poly64x1_t
name|test_vbsl_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|,
name|poly64x1_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbsl_p64
return|return
name|vbsl_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.8b, {{v[0-9]+}}.8b, {{v[0-9]+}}.8b
block|}
end_function

begin_function
name|poly64x2_t
name|test_vbslq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|,
name|poly64x2_t
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vbslq_p64
return|return
name|vbslq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
comment|// CHECK: bsl {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b
block|}
end_function

begin_function
name|poly64_t
name|test_vget_lane_p64
parameter_list|(
name|poly64x1_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vget_lane_p64
return|return
name|vget_lane_p64
argument_list|(
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov  {{x[0-9]+}}, {{d[0-9]+}}
block|}
end_function

begin_function
name|poly64_t
name|test_vgetq_lane_p64
parameter_list|(
name|poly64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vgetq_lane_p64
return|return
name|vgetq_lane_p64
argument_list|(
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: {{mov|umov}}  {{x[0-9]+}}, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|poly64x1_t
name|test_vset_lane_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|,
name|poly64x1_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vset_lane_p64
return|return
name|vset_lane_p64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: fmov  {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly64x2_t
name|test_vsetq_lane_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|,
name|poly64x2_t
name|v
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsetq_lane_p64
return|return
name|vsetq_lane_p64
argument_list|(
name|a
argument_list|,
name|v
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ins  {{v[0-9]+}}.d[1], {{x[0-9]+}}
block|}
end_function

begin_function
name|poly64x1_t
name|test_vcopy_lane_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcopy_lane_p64
return|return
name|vcopy_lane_p64
argument_list|(
name|a
argument_list|,
literal|0
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK-ARM64: mov v0.16b, v1.16b
block|}
end_function

begin_function
name|poly64x2_t
name|test_vcopyq_lane_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcopyq_lane_p64
return|return
name|vcopyq_lane_p64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ins  {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|poly64x2_t
name|test_vcopyq_laneq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcopyq_laneq_p64
return|return
name|vcopyq_laneq_p64
argument_list|(
name|a
argument_list|,
literal|1
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|poly64x1_t
name|test_vcreate_p64
parameter_list|(
name|uint64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcreate_p64
return|return
name|vcreate_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmov  {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly64x1_t
name|test_vdup_n_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdup_n_p64
return|return
name|vdup_n_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly64x2_t
name|test_vdupq_n_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdupq_n_p64
return|return
name|vdupq_n_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly64x1_t
name|test_vmov_n_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmov_n_p64
return|return
name|vmov_n_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: fmov {{d[0-9]+}}, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly64x2_t
name|test_vmovq_n_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmovq_n_p64
return|return
name|vmovq_n_p64
argument_list|(
name|a
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{x[0-9]+}}
block|}
end_function

begin_function
name|poly64x1_t
name|test_vdup_lane_p64
parameter_list|(
name|poly64x1_t
name|vec
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdup_lane_p64
return|return
name|vdup_lane_p64
argument_list|(
name|vec
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: ret
block|}
end_function

begin_function
name|poly64x2_t
name|test_vdupq_lane_p64
parameter_list|(
name|poly64x1_t
name|vec
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdupq_lane_p64
return|return
name|vdupq_lane_p64
argument_list|(
name|vec
argument_list|,
literal|0
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|poly64x2_t
name|test_vdupq_laneq_p64
parameter_list|(
name|poly64x2_t
name|vec
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vdupq_laneq_p64
return|return
name|vdupq_laneq_p64
argument_list|(
name|vec
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: dup {{v[0-9]+}}.2d, {{v[0-9]+}}.d[1]
block|}
end_function

begin_function
name|poly64x2_t
name|test_vcombine_p64
parameter_list|(
name|poly64x1_t
name|low
parameter_list|,
name|poly64x1_t
name|high
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcombine_p64
return|return
name|vcombine_p64
argument_list|(
name|low
argument_list|,
name|high
argument_list|)
return|;
comment|// CHECK: ins {{v[0-9]+}}.d[1], {{v[0-9]+}}.d[0]
block|}
end_function

begin_function
name|poly64x1_t
name|test_vld1_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1_p64
return|return
name|vld1_p64
argument_list|(
name|ptr
argument_list|)
return|;
comment|// CHECK-ARM64: ldr {{d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2_t
name|test_vld1q_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld1q_p64
return|return
name|vld1q_p64
argument_list|(
name|ptr
argument_list|)
return|;
comment|// CHECK-ARM64: ldr {{q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x1_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1_p64
return|return
name|vst1_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
comment|// CHECK-ARM64: str {{d[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst1q_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x2_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst1q_p64
return|return
name|vst1q_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
comment|// CHECK-ARM64: str {{q[0-9]+}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x2_t
name|test_vld2_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2_p64
return|return
name|vld2_p64
argument_list|(
name|ptr
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x2_t
name|test_vld2q_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld2q_p64
return|return
name|vld2q_p64
argument_list|(
name|ptr
argument_list|)
return|;
comment|// CHECK: ld2 {{{ *v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x3_t
name|test_vld3_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3_p64
return|return
name|vld3_p64
argument_list|(
name|ptr
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x3_t
name|test_vld3q_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld3q_p64
return|return
name|vld3q_p64
argument_list|(
name|ptr
argument_list|)
return|;
comment|// CHECK: ld3 {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1x4_t
name|test_vld4_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4_p64
return|return
name|vld4_p64
argument_list|(
name|ptr
argument_list|)
return|;
comment|// CHECK: ld1 {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x2x4_t
name|test_vld4q_p64
parameter_list|(
name|poly64_t
specifier|const
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vld4q_p64
return|return
name|vld4q_p64
argument_list|(
name|ptr
argument_list|)
return|;
comment|// CHECK: ld4 {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x1x2_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2_p64
return|return
name|vst2_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
comment|// CHECK:  st1 {{{ *v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst2q_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x2x2_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst2q_p64
return|return
name|vst2q_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
comment|// CHECK:  st2 {{{ *v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x1x3_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3_p64
return|return
name|vst3_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
comment|// CHECK:  st1 {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst3q_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x2x3_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst3q_p64
return|return
name|vst3q_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
comment|// CHECK:  st3 {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x1x4_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4_p64
return|return
name|vst4_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
comment|// CHECK:  st1 {{{ *v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d, v[0-9]+.1d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|void
name|test_vst4q_p64
parameter_list|(
name|poly64_t
modifier|*
name|ptr
parameter_list|,
name|poly64x2x4_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vst4q_p64
return|return
name|vst4q_p64
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
return|;
comment|// CHECK:  st4 {{{ *v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d, v[0-9]+.2d *}}}, [{{x[0-9]+|sp}}]
block|}
end_function

begin_function
name|poly64x1_t
name|test_vext_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vext_p64
return|return
name|vext_u64
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

begin_function
name|poly64x2_t
name|test_vextq_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vextq_p64
return|return
name|vextq_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: ext {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{v[0-9]+}}.16b, {{#0x8|#8}}
block|}
end_function

begin_function
name|poly64x2_t
name|test_vzip1q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip1q_p64
return|return
name|vzip1q_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK-ARM64: zip1 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|poly64x2_t
name|test_vzip2q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vzip2q_p64
return|return
name|vzip2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK-ARM64: zip2 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|poly64x2_t
name|test_vuzp1q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp1q_p64
return|return
name|vuzp1q_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK-ARM64: zip1 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|poly64x2_t
name|test_vuzp2q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vuzp2q_p64
return|return
name|vuzp2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK-ARM64: zip2 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|poly64x2_t
name|test_vtrn1q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn1q_p64
return|return
name|vtrn1q_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK-ARM64: zip1 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|poly64x2_t
name|test_vtrn2q_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vtrn2q_p64
return|return
name|vtrn2q_u64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK-ARM64: zip2 {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_function
name|poly64x1_t
name|test_vsri_n_p64
parameter_list|(
name|poly64x1_t
name|a
parameter_list|,
name|poly64x1_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsri_n_p64
return|return
name|vsri_n_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|33
argument_list|)
return|;
comment|// CHECK: sri {{d[0-9]+}}, {{d[0-9]+}}, #33
block|}
end_function

begin_function
name|poly64x2_t
name|test_vsriq_n_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vsriq_n_p64
return|return
name|vsriq_n_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|64
argument_list|)
return|;
comment|// CHECK: sri {{v[0-9]+}}.2d, {{v[0-9]+}}.2d, #64
block|}
end_function

end_unit

