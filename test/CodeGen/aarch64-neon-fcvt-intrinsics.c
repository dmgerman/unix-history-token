begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// RUN: %clang_cc1 -triple arm64-none-linux-gnu -target-feature +neon \
end_comment

begin_comment
comment|// RUN:   -ffp-contract=fast -S -O3 -o - %s | FileCheck %s
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
name|float32_t
name|test_vcvtxd_f32_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtxd_f32_f64
comment|// CHECK: fcvtxn {{s[0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|float32_t
operator|)
name|vcvtxd_f32_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vcvtas_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtas_s32_f32
comment|// CHECK: fcvtas {{[ws][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vcvtas_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_test_vcvtad_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_test_vcvtad_s64_f64
comment|// CHECK: fcvtas {{[dx][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vcvtad_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcvtas_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtas_u32_f32
comment|// CHECK: fcvtau {{[ws][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|uint32_t
operator|)
name|vcvtas_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcvtad_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtad_u64_f64
comment|// CHECK: fcvtau {{[xd][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|uint64_t
operator|)
name|vcvtad_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vcvtms_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtms_s32_f32
comment|// CHECK: fcvtms {{[sw][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vcvtms_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcvtmd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtmd_s64_f64
comment|// CHECK: fcvtms {{[dx][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vcvtmd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcvtms_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtms_u32_f32
comment|// CHECK: fcvtmu {{[ws][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|uint32_t
operator|)
name|vcvtms_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcvtmd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtmd_u64_f64
comment|// CHECK: fcvtmu {{[xd][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|uint64_t
operator|)
name|vcvtmd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vcvtns_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtns_s32_f32
comment|// CHECK: fcvtns {{[sw][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vcvtns_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcvtnd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtnd_s64_f64
comment|// CHECK: fcvtns {{[dx][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vcvtnd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcvtns_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtns_u32_f32
comment|// CHECK: fcvtnu {{[sw][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|uint32_t
operator|)
name|vcvtns_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcvtnd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtnd_u64_f64
comment|// CHECK: fcvtnu {{[dx][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|uint64_t
operator|)
name|vcvtnd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vcvtps_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtps_s32_f32
comment|// CHECK: fcvtps {{[sw][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vcvtps_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcvtpd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtpd_s64_f64
comment|// CHECK: fcvtps {{[dx][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vcvtpd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcvtps_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtps_u32_f32
comment|// CHECK: fcvtpu {{[sw][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|uint32_t
operator|)
name|vcvtps_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcvtpd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtpd_u64_f64
comment|// CHECK: fcvtpu {{[dx][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|uint64_t
operator|)
name|vcvtpd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int32_t
name|test_vcvts_s32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvts_s32_f32
comment|// CHECK: fcvtzs {{[sw][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|int32_t
operator|)
name|vcvts_s32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int64_t
name|test_vcvtd_s64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtd_s64_f64
comment|// CHECK: fcvtzs {{[dx][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|int64_t
operator|)
name|vcvtd_s64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32_t
name|test_vcvts_u32_f32
parameter_list|(
name|float32_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvts_u32_f32
comment|// CHECK: fcvtzu {{[sw][0-9]+}}, {{s[0-9]+}}
return|return
operator|(
name|uint32_t
operator|)
name|vcvts_u32_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|uint64_t
name|test_vcvtd_u64_f64
parameter_list|(
name|float64_t
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vcvtd_u64_f64
comment|// CHECK: fcvtzu {{[dx][0-9]+}}, {{d[0-9]+}}
return|return
operator|(
name|uint64_t
operator|)
name|vcvtd_u64_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

