begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -triple thumbv7-none-linux-gnueabihf \
end_comment

begin_comment
comment|// RUN:   -target-abi aapcs \
end_comment

begin_comment
comment|// RUN:   -target-cpu cortex-a7 \
end_comment

begin_comment
comment|// RUN:   -mfloat-abi hard \
end_comment

begin_comment
comment|// RUN:   -ffreestanding \
end_comment

begin_comment
comment|// RUN:   -disable-O0-optnone -emit-llvm -o - %s | opt -S -mem2reg | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<arm_neon.h>
end_include

begin_comment
comment|// CHECK-LABEL: define<2 x float> @test_fma_order(<2 x float> %accum,<2 x float> %lhs,<2 x float> %rhs) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<2 x float> @llvm.fma.v2f32(<2 x float> %lhs,<2 x float> %rhs,<2 x float> %accum) #2
end_comment

begin_comment
comment|// CHECK:   ret<2 x float> [[TMP6]]
end_comment

begin_function
name|float32x2_t
name|test_fma_order
parameter_list|(
name|float32x2_t
name|accum
parameter_list|,
name|float32x2_t
name|lhs
parameter_list|,
name|float32x2_t
name|rhs
parameter_list|)
block|{
return|return
name|vfma_f32
argument_list|(
name|accum
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// CHECK-LABEL: define<4 x float> @test_fmaq_order(<4 x float> %accum,<4 x float> %lhs,<4 x float> %rhs) #0 {
end_comment

begin_comment
comment|// CHECK:   [[TMP6:%.*]] = call<4 x float> @llvm.fma.v4f32(<4 x float> %lhs,<4 x float> %rhs,<4 x float> %accum) #2
end_comment

begin_comment
comment|// CHECK:   ret<4 x float> [[TMP6]]
end_comment

begin_function
name|float32x4_t
name|test_fmaq_order
parameter_list|(
name|float32x4_t
name|accum
parameter_list|,
name|float32x4_t
name|lhs
parameter_list|,
name|float32x4_t
name|rhs
parameter_list|)
block|{
return|return
name|vfmaq_f32
argument_list|(
name|accum
argument_list|,
name|lhs
argument_list|,
name|rhs
argument_list|)
return|;
block|}
end_function

end_unit

