begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple arm64-apple-ios7.0 -target-feature +neon -ffreestanding -emit-llvm -O1 -o - %s | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_function
name|uint32x2_t
name|test_vrsqrte_u32
parameter_list|(
name|uint32x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsqrte_u32
comment|// CHECK: call<2 x i32> @llvm.aarch64.neon.ursqrte.v2i32(<2 x i32> %in)
return|return
name|vrsqrte_u32
argument_list|(
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|test_vrsqrte_f32
parameter_list|(
name|float32x2_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsqrte_f32
comment|// CHECK: call<2 x float> @llvm.aarch64.neon.frsqrte.v2f32(<2 x float> %in)
return|return
name|vrsqrte_f32
argument_list|(
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|uint32x4_t
name|test_vrsqrteq_u32
parameter_list|(
name|uint32x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsqrteq_u32
comment|// CHECK: call<4 x i32> @llvm.aarch64.neon.ursqrte.v4i32(<4 x i32> %in)
return|return
name|vrsqrteq_u32
argument_list|(
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vrsqrteq_f32
parameter_list|(
name|float32x4_t
name|in
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsqrteq_f32
comment|// CHECK: call<4 x float> @llvm.aarch64.neon.frsqrte.v4f32(<4 x float> %in)
return|return
name|vrsqrteq_f32
argument_list|(
name|in
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x2_t
name|test_vrsqrts_f32
parameter_list|(
name|float32x2_t
name|est
parameter_list|,
name|float32x2_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsqrts_f32
comment|// CHECK: call<2 x float> @llvm.aarch64.neon.frsqrts.v2f32(<2 x float> %est,<2 x float> %val)
return|return
name|vrsqrts_f32
argument_list|(
name|est
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

begin_function
name|float32x4_t
name|test_vrsqrtsq_f32
parameter_list|(
name|float32x4_t
name|est
parameter_list|,
name|float32x4_t
name|val
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_vrsqrtsq_f32
comment|// CHECK: call<4 x float> @llvm.aarch64.neon.frsqrts.v4f32(<4 x float> %est,<4 x float> %val)
return|return
name|vrsqrtsq_f32
argument_list|(
name|est
argument_list|,
name|val
argument_list|)
return|;
block|}
end_function

end_unit

