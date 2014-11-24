begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - %s | FileCheck -check-prefix=CHECK-CODEGEN %s
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// Test ARM64 SIMD max/min intrinsics
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// Test a represntative sample of 8 and 16, signed and unsigned, 64 and 128 bit reduction
end_comment

begin_function
name|int8_t
name|test_vmaxv_s8
parameter_list|(
name|int8x8_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vmaxv_s8
return|return
name|vmaxv_s8
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK @llvm.aarch64.neon.smaxv.i32.v8i8
block|}
end_function

begin_function
name|uint16_t
name|test_vminvq_u16
parameter_list|(
name|uint16x8_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vminvq_u16
return|return
name|vminvq_u16
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.uminv.i16.v8i16
block|}
end_function

begin_comment
comment|// Test a represntative sample of 8 and 16, signed and unsigned, 64 and 128 bit pairwise
end_comment

begin_function
name|uint8x8_t
name|test_vmin_u8
parameter_list|(
name|uint8x8_t
name|a1
parameter_list|,
name|uint8x8_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vmin_u8
return|return
name|vmin_u8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.umin.v8i8
block|}
end_function

begin_function
name|uint8x16_t
name|test_vminq_u8
parameter_list|(
name|uint8x16_t
name|a1
parameter_list|,
name|uint8x16_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vminq_u8
return|return
name|vminq_u8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.umin.v16i8
block|}
end_function

begin_function
name|int16x8_t
name|test_vmaxq_s16
parameter_list|(
name|int16x8_t
name|a1
parameter_list|,
name|int16x8_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vmaxq_s16
return|return
name|vmaxq_s16
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.smax.v8i16
block|}
end_function

begin_comment
comment|// Test the more complicated cases of [suf]32 and f64
end_comment

begin_function
name|float64x2_t
name|test_vmaxq_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vmaxq_f64
return|return
name|vmaxq_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.fmax.v2f64
block|}
end_function

begin_function
name|float32x4_t
name|test_vmaxq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|,
name|float32x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vmaxq_f32
return|return
name|vmaxq_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.fmax.v4f32
block|}
end_function

begin_function
name|float64x2_t
name|test_vminq_f64
parameter_list|(
name|float64x2_t
name|a1
parameter_list|,
name|float64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vminq_f64
return|return
name|vminq_f64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.fmin.v2f64
block|}
end_function

begin_function
name|float32x2_t
name|test_vmax_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|,
name|float32x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vmax_f32
return|return
name|vmax_f32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.fmax.v2f32
block|}
end_function

begin_function
name|int32x2_t
name|test_vmax_s32
parameter_list|(
name|int32x2_t
name|a1
parameter_list|,
name|int32x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vmax_s32
return|return
name|vmax_s32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.smax.v2i32
block|}
end_function

begin_function
name|uint32x2_t
name|test_vmin_u32
parameter_list|(
name|uint32x2_t
name|a1
parameter_list|,
name|uint32x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vmin_u32
return|return
name|vmin_u32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|)
return|;
comment|// CHECK llvm.aarch64.neon.umin.v2i32
block|}
end_function

begin_function
name|float32_t
name|test_vmaxnmv_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vmaxnmv_f32
return|return
name|vmaxnmv_f32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fmaxnmv.f32.v2f32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_comment
comment|// this doesn't translate into a valid instruction, regardless of what the
end_comment

begin_comment
comment|// ARM doc says.
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|float64_t test_vmaxnmvq_f64(float64x2_t a1) {
comment|// CHECK@ test_vmaxnmvq_f64
end_comment

begin_comment
unit|return vmaxnmvq_f64(a1);
comment|// CHECK@ llvm.aarch64.neon.saddlv.i64.v2i32
end_comment

begin_comment
comment|// CHECK-NEXT@ ret
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_function
name|float32_t
name|test_vmaxnmvq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vmaxnmvq_f32
return|return
name|vmaxnmvq_f32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fmaxnmv.f32.v4f32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32_t
name|test_vmaxv_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vmaxv_f32
return|return
name|vmaxv_f32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fmaxv.f32.v2f32
comment|// FIXME check that the 2nd and 3rd arguments are the same V register below
comment|// CHECK-CODEGEN: fmaxp.2s
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|int32_t
name|test_vmaxv_s32
parameter_list|(
name|int32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vmaxv_s32
return|return
name|vmaxv_s32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.smaxv.i32.v2i32
comment|// FIXME check that the 2nd and 3rd arguments are the same V register below
comment|// CHECK-CODEGEN: smaxp.2s
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|uint32_t
name|test_vmaxv_u32
parameter_list|(
name|uint32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vmaxv_u32
return|return
name|vmaxv_u32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.umaxv.i32.v2i32
comment|// FIXME check that the 2nd and 3rd arguments are the same V register below
comment|// CHECK-CODEGEN: umaxp.2s
comment|// CHECK-NEXT: ret
block|}
end_function

begin_comment
comment|// FIXME punt on this for now; don't forget to fix CHECKs
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|float64_t test_vmaxvq_f64(float64x2_t a1) {
comment|// CHECK@ test_vmaxvq_f64
end_comment

begin_comment
unit|return vmaxvq_f64(a1);
comment|// CHECK@ llvm.aarch64.neon.fmaxv.i64.v2f64
end_comment

begin_comment
comment|// CHECK-NEXT@ ret
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_function
name|float32_t
name|test_vmaxvq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vmaxvq_f32
return|return
name|vmaxvq_f32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fmaxv.f32.v4f32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32_t
name|test_vminnmv_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vminnmv_f32
return|return
name|vminnmv_f32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fminnmv.f32.v2f32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32_t
name|test_vminvq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vminvq_f32
return|return
name|vminvq_f32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fminv.f32.v4f32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_comment
comment|// this doesn't translate into a valid instruction, regardless of what the ARM
end_comment

begin_comment
comment|// doc says.
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|float64_t test_vminnmvq_f64(float64x2_t a1) {
comment|// CHECK@ test_vminnmvq_f64
end_comment

begin_comment
unit|return vminnmvq_f64(a1);
comment|// CHECK@ llvm.aarch64.neon.saddlv.i64.v2i32
end_comment

begin_comment
comment|// CHECK-NEXT@ ret
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_function
name|float32_t
name|test_vminnmvq_f32
parameter_list|(
name|float32x4_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vminnmvq_f32
return|return
name|vminnmvq_f32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fminnmv.f32.v4f32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|float32_t
name|test_vminv_f32
parameter_list|(
name|float32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vminv_f32
return|return
name|vminv_f32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fminv.f32.v2f32
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|int32_t
name|test_vminv_s32
parameter_list|(
name|int32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vminv_s32
return|return
name|vminv_s32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.sminv.i32.v2i32
comment|// CHECK-CODEGEN: sminp.2s
comment|// CHECK-NEXT: ret
block|}
end_function

begin_function
name|uint32_t
name|test_vminv_u32
parameter_list|(
name|uint32x2_t
name|a1
parameter_list|)
block|{
comment|// CHECK: test_vminv_u32
return|return
name|vminv_u32
argument_list|(
name|a1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.fminv.f32.v2f32
block|}
end_function

begin_comment
comment|// FIXME punt on this for now; don't forget to fix CHECKs
end_comment

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
unit|float64_t test_vminvq_f64(float64x2_t a1) {
comment|// CHECK@ test_vminvq_f64
end_comment

begin_comment
unit|return vminvq_f64(a1);
comment|// CHECK@ llvm.aarch64.neon.saddlv.i64.v2i32
end_comment

begin_comment
comment|// CHECK-NEXT@ ret
end_comment

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

