begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7 -target-feature +neon -ffreestanding -S -o - -emit-llvm %s | FileCheck %s
end_comment

begin_comment
comment|// Test ARM64 extract intrinsics
end_comment

begin_comment
comment|// can use as back end test by adding a run line with
end_comment

begin_comment
comment|// -check-prefix=CHECK-CODEGEN on the FileCheck
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|void
name|test_vext_s8
parameter_list|()
block|{
comment|// CHECK: test_vext_s8
name|int8x8_t
name|xS8x8
decl_stmt|;
name|xS8x8
operator|=
name|vext_s8
argument_list|(
name|xS8x8
argument_list|,
name|xS8x8
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_s8:
comment|// CHECK-CODEGEN: {{ext.8.*#1}}
block|}
end_function

begin_function
name|void
name|test_vext_u8
parameter_list|()
block|{
comment|// CHECK: test_vext_u8
name|uint8x8_t
name|xU8x8
decl_stmt|;
name|xU8x8
operator|=
name|vext_u8
argument_list|(
name|xU8x8
argument_list|,
name|xU8x8
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_u8:
comment|// CHECK-CODEGEN: {{ext.8.*#2}}
block|}
end_function

begin_function
name|void
name|test_vext_p8
parameter_list|()
block|{
comment|// CHECK: test_vext_p8
name|poly8x8_t
name|xP8x8
decl_stmt|;
name|xP8x8
operator|=
name|vext_p8
argument_list|(
name|xP8x8
argument_list|,
name|xP8x8
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_p8:
comment|// CHECK-CODEGEN: {{ext.8.*#3}}
block|}
end_function

begin_function
name|void
name|test_vext_s16
parameter_list|()
block|{
comment|// CHECK: test_vext_s16
name|int16x4_t
name|xS16x4
decl_stmt|;
name|xS16x4
operator|=
name|vext_s16
argument_list|(
name|xS16x4
argument_list|,
name|xS16x4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_s16:
comment|// CHECK-CODEGEN: {{ext.8.*#2}}
block|}
end_function

begin_function
name|void
name|test_vext_u16
parameter_list|()
block|{
comment|// CHECK: test_vext_u16
name|uint16x4_t
name|xU16x4
decl_stmt|;
name|xU16x4
operator|=
name|vext_u16
argument_list|(
name|xU16x4
argument_list|,
name|xU16x4
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_u16:
comment|// CHECK-CODEGEN: {{ext.8.*#4}}
block|}
end_function

begin_function
name|void
name|test_vext_p16
parameter_list|()
block|{
comment|// CHECK: test_vext_p16
name|poly16x4_t
name|xP16x4
decl_stmt|;
name|xP16x4
operator|=
name|vext_p16
argument_list|(
name|xP16x4
argument_list|,
name|xP16x4
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_p16:
comment|// CHECK-CODEGEN: {{ext.8.*#6}}
block|}
end_function

begin_function
name|void
name|test_vext_s32
parameter_list|()
block|{
comment|// CHECK: test_vext_s32
name|int32x2_t
name|xS32x2
decl_stmt|;
name|xS32x2
operator|=
name|vext_s32
argument_list|(
name|xS32x2
argument_list|,
name|xS32x2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_s32:
comment|// CHECK-CODEGEN: {{ext.8.*#4}}
block|}
end_function

begin_function
name|void
name|test_vext_u32
parameter_list|()
block|{
comment|// CHECK: test_vext_u32
name|uint32x2_t
name|xU32x2
decl_stmt|;
name|xU32x2
operator|=
name|vext_u32
argument_list|(
name|xU32x2
argument_list|,
name|xU32x2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_u32:
comment|// CHECK-CODEGEN: {{ext.8.*#4}}
block|}
end_function

begin_function
name|void
name|test_vext_f32
parameter_list|()
block|{
comment|// CHECK: test_vext_f32
name|float32x2_t
name|xF32x2
decl_stmt|;
name|xF32x2
operator|=
name|vext_f32
argument_list|(
name|xF32x2
argument_list|,
name|xF32x2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_f32:
comment|// CHECK-CODEGEN: {{ext.8.*#4}}
block|}
end_function

begin_function
name|void
name|test_vext_s64
parameter_list|()
block|{
comment|// CHECK: test_vext_s64
name|int64x1_t
name|xS64x1
decl_stmt|;
comment|// FIXME don't use 1 as index or check for now, clang has a bug?
name|xS64x1
operator|=
name|vext_s64
argument_list|(
name|xS64x1
argument_list|,
name|xS64x1
argument_list|,
comment|/*1*/
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_s64:
comment|// CHECK_FIXME: {{ext.8.*#0}}
block|}
end_function

begin_function
name|void
name|test_vext_u64
parameter_list|()
block|{
comment|// CHECK: test_vext_u64
name|uint64x1_t
name|xU64x1
decl_stmt|;
comment|// FIXME don't use 1 as index or check for now, clang has a bug?
name|xU64x1
operator|=
name|vext_u64
argument_list|(
name|xU64x1
argument_list|,
name|xU64x1
argument_list|,
comment|/*1*/
literal|0
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vext_u64:
comment|// CHECK_FIXME: {{ext.8.*#0}}
block|}
end_function

begin_function
name|void
name|test_vextq_s8
parameter_list|()
block|{
comment|// CHECK: test_vextq_s8
name|int8x16_t
name|xS8x16
decl_stmt|;
name|xS8x16
operator|=
name|vextq_s8
argument_list|(
name|xS8x16
argument_list|,
name|xS8x16
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_s8:
comment|// CHECK-CODEGEN: {{ext.16.*#4}}
block|}
end_function

begin_function
name|void
name|test_vextq_u8
parameter_list|()
block|{
comment|// CHECK: test_vextq_u8
name|uint8x16_t
name|xU8x16
decl_stmt|;
name|xU8x16
operator|=
name|vextq_u8
argument_list|(
name|xU8x16
argument_list|,
name|xU8x16
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_u8:
comment|// CHECK-CODEGEN: {{ext.16.*#5}}
block|}
end_function

begin_function
name|void
name|test_vextq_p8
parameter_list|()
block|{
comment|// CHECK: test_vextq_p8
name|poly8x16_t
name|xP8x16
decl_stmt|;
name|xP8x16
operator|=
name|vextq_p8
argument_list|(
name|xP8x16
argument_list|,
name|xP8x16
argument_list|,
literal|6
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_p8:
comment|// CHECK-CODEGEN: {{ext.16.*#6}}
block|}
end_function

begin_function
name|void
name|test_vextq_s16
parameter_list|()
block|{
comment|// CHECK: test_vextq_s16
name|int16x8_t
name|xS16x8
decl_stmt|;
name|xS16x8
operator|=
name|vextq_s16
argument_list|(
name|xS16x8
argument_list|,
name|xS16x8
argument_list|,
literal|7
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_s16:
comment|// CHECK-CODEGEN: {{ext.16.*#14}}
block|}
end_function

begin_function
name|void
name|test_vextq_u16
parameter_list|()
block|{
comment|// CHECK: test_vextq_u16
name|uint16x8_t
name|xU16x8
decl_stmt|;
name|xU16x8
operator|=
name|vextq_u16
argument_list|(
name|xU16x8
argument_list|,
name|xU16x8
argument_list|,
literal|4
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_u16:
comment|// CHECK-CODEGEN: {{ext.16.*#8}}
block|}
end_function

begin_function
name|void
name|test_vextq_p16
parameter_list|()
block|{
comment|// CHECK: test_vextq_p16
name|poly16x8_t
name|xP16x8
decl_stmt|;
name|xP16x8
operator|=
name|vextq_p16
argument_list|(
name|xP16x8
argument_list|,
name|xP16x8
argument_list|,
literal|5
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_p16:
comment|// CHECK-CODEGEN: {{ext.16.*#10}}
block|}
end_function

begin_function
name|void
name|test_vextq_s32
parameter_list|()
block|{
comment|// CHECK: test_vextq_s32
name|int32x4_t
name|xS32x4
decl_stmt|;
name|xS32x4
operator|=
name|vextq_s32
argument_list|(
name|xS32x4
argument_list|,
name|xS32x4
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_s32:
comment|// CHECK-CODEGEN: {{ext.16.*#4}}
block|}
end_function

begin_function
name|void
name|test_vextq_u32
parameter_list|()
block|{
comment|// CHECK: test_vextq_u32
name|uint32x4_t
name|xU32x4
decl_stmt|;
name|xU32x4
operator|=
name|vextq_u32
argument_list|(
name|xU32x4
argument_list|,
name|xU32x4
argument_list|,
literal|2
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_u32:
comment|// CHECK-CODEGEN: {{ext.16.*#8}}
block|}
end_function

begin_function
name|void
name|test_vextq_f32
parameter_list|()
block|{
comment|// CHECK: test_vextq_f32
name|float32x4_t
name|xF32x4
decl_stmt|;
name|xF32x4
operator|=
name|vextq_f32
argument_list|(
name|xF32x4
argument_list|,
name|xF32x4
argument_list|,
literal|3
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_f32:
comment|// CHECK-CODEGEN: {{ext.16.*#12}}
block|}
end_function

begin_function
name|void
name|test_vextq_s64
parameter_list|()
block|{
comment|// CHECK: test_vextq_s64
name|int64x2_t
name|xS64x2
decl_stmt|;
name|xS64x2
operator|=
name|vextq_s64
argument_list|(
name|xS64x2
argument_list|,
name|xS64x2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_s64:
comment|// CHECK-CODEGEN: {{ext.16.*#8}}
block|}
end_function

begin_function
name|void
name|test_vextq_u64
parameter_list|()
block|{
comment|// CHECK: test_vextq_u64
name|uint64x2_t
name|xU64x2
decl_stmt|;
name|xU64x2
operator|=
name|vextq_u64
argument_list|(
name|xU64x2
argument_list|,
name|xU64x2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_u64:
comment|// CHECK-CODEGEN: {{ext.16.*#8}}
block|}
end_function

begin_function
name|void
name|test_vextq_f64
parameter_list|()
block|{
comment|// CHECK: test_vextq_f64
name|float64x2_t
name|xF64x2
decl_stmt|;
name|xF64x2
operator|=
name|vextq_f64
argument_list|(
name|xF64x2
argument_list|,
name|xF64x2
argument_list|,
literal|1
argument_list|)
expr_stmt|;
comment|// CHECK: shufflevector
comment|// CHECK-CODEGEN: test_vextq_u64:
comment|// CHECK-CODEGEN: {{ext.16.*#8}}
block|}
end_function

end_unit

