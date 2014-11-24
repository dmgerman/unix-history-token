begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -O1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - %s | \
end_comment

begin_comment
comment|// RUN:   FileCheck -check-prefix=CHECK_CODEGEN %s
end_comment

begin_comment
comment|// REQUIRES: aarch64-registered-target
end_comment

begin_comment
comment|// Test ARM64 SIMD vector shift right and insert: vsri[q]_n_*
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|int8x8_t
name|test_vsri_n_s8
parameter_list|(
name|int8x8_t
name|a1
parameter_list|,
name|int8x8_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_s8
return|return
name|vsri_n_s8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v8i8
comment|// CHECK_CODEGEN: sri.8b  v0, v1, #3
block|}
end_function

begin_function
name|int16x4_t
name|test_vsri_n_s16
parameter_list|(
name|int16x4_t
name|a1
parameter_list|,
name|int16x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_s16
return|return
name|vsri_n_s16
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v4i16
comment|// CHECK_CODEGEN: sri.4h  v0, v1, #3
block|}
end_function

begin_function
name|int32x2_t
name|test_vsri_n_s32
parameter_list|(
name|int32x2_t
name|a1
parameter_list|,
name|int32x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_s32
return|return
name|vsri_n_s32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v2i32
comment|// CHECK_CODEGEN: sri.2s  v0, v1, #1
block|}
end_function

begin_function
name|int64x1_t
name|test_vsri_n_s64
parameter_list|(
name|int64x1_t
name|a1
parameter_list|,
name|int64x1_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_s64
return|return
name|vsri_n_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v1i64
comment|// CHECK_CODEGEN: sri     d0, d1, #1
block|}
end_function

begin_function
name|uint8x8_t
name|test_vsri_n_u8
parameter_list|(
name|uint8x8_t
name|a1
parameter_list|,
name|uint8x8_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_u8
return|return
name|vsri_n_u8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v8i8
comment|// CHECK_CODEGEN: sri.8b  v0, v1, #3
block|}
end_function

begin_function
name|uint16x4_t
name|test_vsri_n_u16
parameter_list|(
name|uint16x4_t
name|a1
parameter_list|,
name|uint16x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_u16
return|return
name|vsri_n_u16
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v4i16
comment|// CHECK_CODEGEN: sri.4h  v0, v1, #3
block|}
end_function

begin_function
name|uint32x2_t
name|test_vsri_n_u32
parameter_list|(
name|uint32x2_t
name|a1
parameter_list|,
name|uint32x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_u32
return|return
name|vsri_n_u32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v2i32
comment|// CHECK_CODEGEN: sri.2s  v0, v1, #1
block|}
end_function

begin_function
name|uint64x1_t
name|test_vsri_n_u64
parameter_list|(
name|uint64x1_t
name|a1
parameter_list|,
name|uint64x1_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_u64
return|return
name|vsri_n_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v1i64
comment|// CHECK_CODEGEN: sri     d0, d1, #1
block|}
end_function

begin_function
name|poly8x8_t
name|test_vsri_n_p8
parameter_list|(
name|poly8x8_t
name|a1
parameter_list|,
name|poly8x8_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_p8
return|return
name|vsri_n_p8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v8i8
comment|// CHECK_CODEGEN: sri.8b  v0, v1, #1
block|}
end_function

begin_function
name|poly16x4_t
name|test_vsri_n_p16
parameter_list|(
name|poly16x4_t
name|a1
parameter_list|,
name|poly16x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsri_n_p16
return|return
name|vsri_n_p16
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v4i16
comment|// CHECK_CODEGEN: sri.4h  v0, v1, #1
block|}
end_function

begin_function
name|int8x16_t
name|test_vsriq_n_s8
parameter_list|(
name|int8x16_t
name|a1
parameter_list|,
name|int8x16_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_s8
return|return
name|vsriq_n_s8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v16i8
comment|// CHECK_CODEGEN: sri.16b v0, v1, #3
block|}
end_function

begin_function
name|int16x8_t
name|test_vsriq_n_s16
parameter_list|(
name|int16x8_t
name|a1
parameter_list|,
name|int16x8_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_s16
return|return
name|vsriq_n_s16
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v8i16
comment|// CHECK_CODEGEN: sri.8h  v0, v1, #3
block|}
end_function

begin_function
name|int32x4_t
name|test_vsriq_n_s32
parameter_list|(
name|int32x4_t
name|a1
parameter_list|,
name|int32x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_s32
return|return
name|vsriq_n_s32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v4i32
comment|// CHECK_CODEGEN: sri.4s  v0, v1, #1
block|}
end_function

begin_function
name|int64x2_t
name|test_vsriq_n_s64
parameter_list|(
name|int64x2_t
name|a1
parameter_list|,
name|int64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_s64
return|return
name|vsriq_n_s64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v2i64
comment|// CHECK_CODEGEN: sri.2d  v0, v1, #1
block|}
end_function

begin_function
name|uint8x16_t
name|test_vsriq_n_u8
parameter_list|(
name|uint8x16_t
name|a1
parameter_list|,
name|uint8x16_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_u8
return|return
name|vsriq_n_u8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v16i8
comment|// CHECK_CODEGEN: sri.16b v0, v1, #3
block|}
end_function

begin_function
name|uint16x8_t
name|test_vsriq_n_u16
parameter_list|(
name|uint16x8_t
name|a1
parameter_list|,
name|uint16x8_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_u16
return|return
name|vsriq_n_u16
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|3
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v8i16
comment|// CHECK_CODEGEN: sri.8h  v0, v1, #3
block|}
end_function

begin_function
name|uint32x4_t
name|test_vsriq_n_u32
parameter_list|(
name|uint32x4_t
name|a1
parameter_list|,
name|uint32x4_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_u32
return|return
name|vsriq_n_u32
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v4i32
comment|// CHECK_CODEGEN: sri.4s  v0, v1, #1
block|}
end_function

begin_function
name|uint64x2_t
name|test_vsriq_n_u64
parameter_list|(
name|uint64x2_t
name|a1
parameter_list|,
name|uint64x2_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_u64
return|return
name|vsriq_n_u64
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v2i64
comment|// CHECK_CODEGEN: sri.2d  v0, v1, #1
block|}
end_function

begin_function
name|poly8x16_t
name|test_vsriq_n_p8
parameter_list|(
name|poly8x16_t
name|a1
parameter_list|,
name|poly8x16_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_p8
return|return
name|vsriq_n_p8
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v16i8
comment|// CHECK_CODEGEN: sri.16b v0, v1, #1
block|}
end_function

begin_function
name|poly16x8_t
name|test_vsriq_n_p16
parameter_list|(
name|poly16x8_t
name|a1
parameter_list|,
name|poly16x8_t
name|a2
parameter_list|)
block|{
comment|// CHECK: test_vsriq_n_p16
return|return
name|vsriq_n_p16
argument_list|(
name|a1
argument_list|,
name|a2
argument_list|,
literal|1
argument_list|)
return|;
comment|// CHECK: llvm.aarch64.neon.vsri.v8i16
comment|// CHECK_CODEGEN: sri.8h  v0, v1, #1
block|}
end_function

end_unit

