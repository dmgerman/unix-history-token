begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O0 -triple=x86_64-apple-darwin -ffreestanding -target-feature +avx512bw -target-feature +avx512vl -emit-llvm -o - -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__mmask32
name|test_mm256_cmpeq_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.256
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpeq_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmpeq_epi8_mask
parameter_list|(
name|__mmask32
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.256
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpeq_epi8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_cmpeq_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.128
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpeq_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_mask_cmpeq_epi8_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epi8_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.b.128
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpeq_epi8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_cmpeq_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.256
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpeq_epi16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_mask_cmpeq_epi16_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.256
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpeq_epi16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmpeq_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpeq_epi16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmpeq_epi16_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epi16_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.w.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpeq_epi16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

end_unit

