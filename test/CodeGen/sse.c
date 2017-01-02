begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding -O3 -triple x86_64-apple-macosx10.8.0 -target-feature +sse4.1 -emit-llvm %s -o - | FileCheck %s
end_comment

begin_comment
comment|// FIXME: This test currently depends on optimization - it should be rewritten to avoid it.
end_comment

begin_include
include|#
directive|include
file|<emmintrin.h>
end_include

begin_comment
comment|// Byte-shifts look reversed due to xmm register layout
end_comment

begin_function
name|__m128
name|test_mm_slli_si128
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_slli_si128
comment|// CHECK: shufflevector<16 x i8><{{.*}}, i8 0, i8 0, i8 0, i8 0, i8 0>,<16 x i8> {{.*}},<16 x i32><i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26>
return|return
name|_mm_slli_si128
argument_list|(
name|a
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_slli_si128_0
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_slli_si128_0
comment|// CHECK-NOT: shufflevector
return|return
name|_mm_slli_si128
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_slli_si128_16
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_slli_si128_16
comment|// CHECK-NOT: shufflevector
return|return
name|_mm_slli_si128
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_srli_si128
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_srli_si128
comment|// CHECK: shufflevector<16 x i8> {{.*}},<16 x i8><i8 0, i8 0, i8 0, i8 0, i8 0, {{.*}}>,<16 x i32><i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17, i32 18, i32 19, i32 20>
return|return
name|_mm_srli_si128
argument_list|(
name|a
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_srli_si128_0
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_srli_si128_0
comment|// CHECK-NOT: shufflevector
return|return
name|_mm_srli_si128
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_srli_si128_16
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_srli_si128_16
comment|// CHECK-NOT: shufflevector
return|return
name|_mm_srli_si128
argument_list|(
name|a
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

end_unit

