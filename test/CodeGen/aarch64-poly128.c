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
comment|// Test new aarch64 intrinsics with poly128
end_comment

begin_comment
comment|// FIXME: Currently, poly128_t equals to uint128, which will be spilt into
end_comment

begin_comment
comment|// two 64-bit GPR(eg X0, X1). Now moving data from X0, X1 to FPR128 will
end_comment

begin_comment
comment|// introduce 2 store and 1 load instructions(store X0, X1 to memory and
end_comment

begin_comment
comment|// then load back to Q0). If target has NEON, this is better replaced by
end_comment

begin_comment
comment|// FMOV or INS.
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|void
name|test_vstrq_p128
parameter_list|(
name|poly128_t
modifier|*
name|ptr
parameter_list|,
name|poly128_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vstrq_p128
name|vstrq_p128
argument_list|(
name|ptr
argument_list|,
name|val
argument_list|)
expr_stmt|;
comment|// CHECK-ARM64: stp {{x[0-9]+}}, {{x[0-9]+}}, [x0]
block|}
end_function

begin_function
name|poly128_t
name|test_vldrq_p128
parameter_list|(
name|poly128_t
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vldrq_p128
return|return
name|vldrq_p128
argument_list|(
name|ptr
argument_list|)
return|;
comment|// CHECK-ARM64: ldp {{x[0-9]+}}, {{x[0-9]+}}, [x0]
block|}
end_function

begin_function
name|void
name|test_ld_st_p128
parameter_list|(
name|poly128_t
modifier|*
name|ptr
parameter_list|)
block|{
comment|// CHECK-LABEL: test_ld_st_p128
name|vstrq_p128
argument_list|(
name|ptr
operator|+
literal|1
argument_list|,
name|vldrq_p128
argument_list|(
name|ptr
argument_list|)
argument_list|)
expr_stmt|;
comment|// CHECK-ARM64: ldp [[PLO:x[0-9]+]], [[PHI:x[0-9]+]], [{{x[0-9]+}}]
comment|// CHECK-ARM64-NEXT: stp [[PLO]], [[PHI]], [{{x[0-9]+}}, #16]
block|}
end_function

begin_function
name|poly128_t
name|test_vmull_p64
parameter_list|(
name|poly64_t
name|a
parameter_list|,
name|poly64_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_p64
return|return
name|vmull_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: pmull {{v[0-9]+}}.1q, {{v[0-9]+}}.1d, {{v[0-9]+}}.1d
block|}
end_function

begin_function
name|poly128_t
name|test_vmull_high_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|,
name|poly64x2_t
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_vmull_high_p64
return|return
name|vmull_high_p64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
comment|// CHECK: pmull2 {{v[0-9]+}}.1q, {{v[0-9]+}}.2d, {{v[0-9]+}}.2d
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_s8
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_s8
parameter_list|(
name|int8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_s8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_s16
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_s16
parameter_list|(
name|int16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_s16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_s32
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_s32
parameter_list|(
name|int32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_s32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_s64
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_s64
parameter_list|(
name|int64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_s64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_u8
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_u8
parameter_list|(
name|uint8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_u8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_u16
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_u16
parameter_list|(
name|uint16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_u16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_u32
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_u32
parameter_list|(
name|uint32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_u32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_u64
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_u64
parameter_list|(
name|uint64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_u64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_f32
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_f32
parameter_list|(
name|float32x4_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_f32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_f64
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_f64
parameter_list|(
name|float64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_f64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_p8
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_p8
parameter_list|(
name|poly8x16_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_p8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_p16
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_p16
parameter_list|(
name|poly16x8_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_p16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p128_p64
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly128_t
name|test_vreinterpretq_p128_p64
parameter_list|(
name|poly64x2_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p128_p64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s8_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|int8x16_t
name|test_vreinterpretq_s8_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s8_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s16_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|int16x8_t
name|test_vreinterpretq_s16_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s16_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s32_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|int32x4_t
name|test_vreinterpretq_s32_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s32_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_s64_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|int64x2_t
name|test_vreinterpretq_s64_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_s64_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u8_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|uint8x16_t
name|test_vreinterpretq_u8_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u8_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u16_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|uint16x8_t
name|test_vreinterpretq_u16_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u16_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u32_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|uint32x4_t
name|test_vreinterpretq_u32_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u32_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_u64_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|uint64x2_t
name|test_vreinterpretq_u64_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_u64_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f32_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|float32x4_t
name|test_vreinterpretq_f32_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f32_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_f64_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|float64x2_t
name|test_vreinterpretq_f64_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_f64_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p8_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly8x16_t
name|test_vreinterpretq_p8_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p8_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p16_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly16x8_t
name|test_vreinterpretq_p16_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p16_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: test_vreinterpretq_p64_p128
end_comment

begin_comment
comment|// CHECK: ret
end_comment

begin_function
name|poly64x2_t
name|test_vreinterpretq_p64_p128
parameter_list|(
name|poly128_t
name|a
parameter_list|)
block|{
return|return
name|vreinterpretq_p64_p128
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

end_unit

