begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512bw -target-feature +avx512vl -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512bw -target-feature +avx512vl -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s
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
comment|// CHECK: icmp eq<32 x i8> %{{.*}}, %{{.*}}
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
comment|// CHECK: icmp eq<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
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
comment|// CHECK: icmp eq<16 x i8> %{{.*}}, %{{.*}}
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
comment|// CHECK: icmp eq<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
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
comment|// CHECK: icmp eq<16 x i16> %{{.*}}, %{{.*}}
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
comment|// CHECK: icmp eq<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
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
comment|// CHECK: icmp eq<8 x i16> %{{.*}}, %{{.*}}
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
comment|// CHECK: icmp eq<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
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

begin_function
name|__mmask32
name|test_mm256_cmpgt_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epi8_mask
comment|// CHECK: icmp sgt<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpgt_epi8_mask
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
name|test_mm256_mask_cmpgt_epi8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epi8_mask
comment|// CHECK: icmp sgt<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpgt_epi8_mask
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
name|test_mm_cmpgt_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epi8_mask
comment|// CHECK: icmp sgt<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpgt_epi8_mask
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
name|test_mm_mask_cmpgt_epi8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epi8_mask
comment|// CHECK: icmp sgt<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpgt_epi8_mask
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
name|test_mm256_cmpgt_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epi16_mask
comment|// CHECK: icmp sgt<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpgt_epi16_mask
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
name|test_mm256_mask_cmpgt_epi16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epi16_mask
comment|// CHECK: icmp sgt<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpgt_epi16_mask
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
name|test_mm_cmpgt_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epi16_mask
comment|// CHECK: icmp sgt<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpgt_epi16_mask
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
name|test_mm_mask_cmpgt_epi16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epi16_mask
comment|// CHECK: icmp sgt<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpgt_epi16_mask
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
name|test_mm_cmpeq_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epu8_mask
comment|// CHECK: icmp eq<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpeq_epu8_mask
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
name|test_mm_mask_cmpeq_epu8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epu8_mask
comment|// CHECK: icmp eq<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpeq_epu8_mask
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
name|test_mm_cmpeq_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epu16_mask
comment|// CHECK: icmp eq<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpeq_epu16_mask
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
name|test_mm_mask_cmpeq_epu16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epu16_mask
comment|// CHECK: icmp eq<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpeq_epu16_mask
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
name|__mmask32
name|test_mm256_cmpeq_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epu8_mask
comment|// CHECK: icmp eq<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpeq_epu8_mask
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
name|test_mm256_mask_cmpeq_epu8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epu8_mask
comment|// CHECK: icmp eq<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpeq_epu8_mask
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
name|test_mm256_cmpeq_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epu16_mask
comment|// CHECK: icmp eq<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpeq_epu16_mask
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
name|test_mm256_mask_cmpeq_epu16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epu16_mask
comment|// CHECK: icmp eq<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpeq_epu16_mask
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
name|test_mm_cmpgt_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epu8_mask
comment|// CHECK: icmp ugt<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpgt_epu8_mask
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
name|test_mm_mask_cmpgt_epu8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epu8_mask
comment|// CHECK: icmp ugt<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpgt_epu8_mask
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
name|test_mm_cmpgt_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epu16_mask
comment|// CHECK: icmp ugt<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpgt_epu16_mask
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
name|test_mm_mask_cmpgt_epu16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epu16_mask
comment|// CHECK: icmp ugt<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpgt_epu16_mask
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
name|__mmask32
name|test_mm256_cmpgt_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epu8_mask
comment|// CHECK: icmp ugt<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpgt_epu8_mask
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
name|test_mm256_mask_cmpgt_epu8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epu8_mask
comment|// CHECK: icmp ugt<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpgt_epu8_mask
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
name|test_mm256_cmpgt_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epu16_mask
comment|// CHECK: icmp ugt<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpgt_epu16_mask
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
name|test_mm256_mask_cmpgt_epu16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epu16_mask
comment|// CHECK: icmp ugt<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpgt_epu16_mask
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
name|test_mm_cmpge_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epi8_mask
comment|// CHECK: icmp sge<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpge_epi8_mask
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
name|test_mm_mask_cmpge_epi8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epi8_mask
comment|// CHECK: icmp sge<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpge_epi8_mask
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
name|test_mm_cmpge_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epu8_mask
comment|// CHECK: icmp uge<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpge_epu8_mask
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
name|test_mm_mask_cmpge_epu8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epu8_mask
comment|// CHECK: icmp uge<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpge_epu8_mask
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
name|test_mm_cmpge_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epi16_mask
comment|// CHECK: icmp sge<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpge_epi16_mask
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
name|test_mm_mask_cmpge_epi16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epi16_mask
comment|// CHECK: icmp sge<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpge_epi16_mask
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
name|test_mm_cmpge_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epu16_mask
comment|// CHECK: icmp uge<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpge_epu16_mask
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
name|test_mm_mask_cmpge_epu16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epu16_mask
comment|// CHECK: icmp uge<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpge_epu16_mask
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
name|__mmask32
name|test_mm256_cmpge_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epi8_mask
comment|// CHECK: icmp sge<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpge_epi8_mask
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
name|test_mm256_mask_cmpge_epi8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epi8_mask
comment|// CHECK: icmp sge<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpge_epi8_mask
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
name|__mmask32
name|test_mm256_cmpge_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epu8_mask
comment|// CHECK: icmp uge<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpge_epu8_mask
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
name|test_mm256_mask_cmpge_epu8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epu8_mask
comment|// CHECK: icmp uge<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpge_epu8_mask
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
name|test_mm256_cmpge_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epi16_mask
comment|// CHECK: icmp sge<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpge_epi16_mask
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
name|test_mm256_mask_cmpge_epi16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epi16_mask
comment|// CHECK: icmp sge<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpge_epi16_mask
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
name|test_mm256_cmpge_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epu16_mask
comment|// CHECK: icmp uge<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpge_epu16_mask
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
name|test_mm256_mask_cmpge_epu16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epu16_mask
comment|// CHECK: icmp uge<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpge_epu16_mask
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
name|test_mm_cmple_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epi8_mask
comment|// CHECK: icmp sle<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmple_epi8_mask
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
name|test_mm_mask_cmple_epi8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmple_epi8_mask
comment|// CHECK: icmp sle<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmple_epi8_mask
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
name|test_mm_cmple_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epu8_mask
comment|// CHECK: icmp ule<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmple_epu8_mask
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
name|test_mm_mask_cmple_epu8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmple_epu8_mask
comment|// CHECK: icmp ule<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmple_epu8_mask
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
name|test_mm_cmple_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epi16_mask
comment|// CHECK: icmp sle<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmple_epi16_mask
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
name|test_mm_mask_cmple_epi16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmple_epi16_mask
comment|// CHECK: icmp sle<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmple_epi16_mask
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
name|test_mm_cmple_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epu16_mask
comment|// CHECK: icmp ule<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmple_epu16_mask
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
name|test_mm_mask_cmple_epu16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmple_epu16_mask
comment|// CHECK: icmp ule<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmple_epu16_mask
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
name|__mmask32
name|test_mm256_cmple_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epi8_mask
comment|// CHECK: icmp sle<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmple_epi8_mask
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
name|test_mm256_mask_cmple_epi8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epi8_mask
comment|// CHECK: icmp sle<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmple_epi8_mask
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
name|__mmask32
name|test_mm256_cmple_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epu8_mask
comment|// CHECK: icmp ule<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmple_epu8_mask
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
name|test_mm256_mask_cmple_epu8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epu8_mask
comment|// CHECK: icmp ule<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmple_epu8_mask
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
name|test_mm256_cmple_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epi16_mask
comment|// CHECK: icmp sle<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmple_epi16_mask
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
name|test_mm256_mask_cmple_epi16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epi16_mask
comment|// CHECK: icmp sle<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmple_epi16_mask
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
name|test_mm256_cmple_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epu16_mask
comment|// CHECK: icmp ule<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmple_epu16_mask
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
name|test_mm256_mask_cmple_epu16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epu16_mask
comment|// CHECK: icmp ule<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmple_epu16_mask
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
name|test_mm_cmplt_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epi8_mask
comment|// CHECK: icmp slt<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmplt_epi8_mask
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
name|test_mm_mask_cmplt_epi8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epi8_mask
comment|// CHECK: icmp slt<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmplt_epi8_mask
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
name|test_mm_cmplt_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epu8_mask
comment|// CHECK: icmp ult<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmplt_epu8_mask
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
name|test_mm_mask_cmplt_epu8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epu8_mask
comment|// CHECK: icmp ult<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmplt_epu8_mask
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
name|test_mm_cmplt_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epi16_mask
comment|// CHECK: icmp slt<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmplt_epi16_mask
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
name|test_mm_mask_cmplt_epi16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epi16_mask
comment|// CHECK: icmp slt<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmplt_epi16_mask
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
name|test_mm_cmplt_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epu16_mask
comment|// CHECK: icmp ult<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmplt_epu16_mask
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
name|test_mm_mask_cmplt_epu16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epu16_mask
comment|// CHECK: icmp ult<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmplt_epu16_mask
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
name|__mmask32
name|test_mm256_cmplt_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epi8_mask
comment|// CHECK: icmp slt<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmplt_epi8_mask
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
name|test_mm256_mask_cmplt_epi8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epi8_mask
comment|// CHECK: icmp slt<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmplt_epi8_mask
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
name|__mmask32
name|test_mm256_cmplt_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epu8_mask
comment|// CHECK: icmp ult<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmplt_epu8_mask
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
name|test_mm256_mask_cmplt_epu8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epu8_mask
comment|// CHECK: icmp ult<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmplt_epu8_mask
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
name|test_mm256_cmplt_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epi16_mask
comment|// CHECK: icmp slt<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmplt_epi16_mask
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
name|test_mm256_mask_cmplt_epi16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epi16_mask
comment|// CHECK: icmp slt<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmplt_epi16_mask
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
name|test_mm256_cmplt_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epu16_mask
comment|// CHECK: icmp ult<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmplt_epu16_mask
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
name|test_mm256_mask_cmplt_epu16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epu16_mask
comment|// CHECK: icmp ult<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmplt_epu16_mask
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
name|test_mm_cmpneq_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epi8_mask
comment|// CHECK: icmp ne<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpneq_epi8_mask
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
name|test_mm_mask_cmpneq_epi8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epi8_mask
comment|// CHECK: icmp ne<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpneq_epi8_mask
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
name|test_mm_cmpneq_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epu8_mask
comment|// CHECK: icmp ne<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmpneq_epu8_mask
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
name|test_mm_mask_cmpneq_epu8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epu8_mask
comment|// CHECK: icmp ne<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmpneq_epu8_mask
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
name|test_mm_cmpneq_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epi16_mask
comment|// CHECK: icmp ne<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpneq_epi16_mask
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
name|test_mm_mask_cmpneq_epi16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epi16_mask
comment|// CHECK: icmp ne<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpneq_epi16_mask
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
name|test_mm_cmpneq_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epu16_mask
comment|// CHECK: icmp ne<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpneq_epu16_mask
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
name|test_mm_mask_cmpneq_epu16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epu16_mask
comment|// CHECK: icmp ne<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpneq_epu16_mask
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
name|__mmask32
name|test_mm256_cmpneq_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epi8_mask
comment|// CHECK: icmp ne<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpneq_epi8_mask
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
name|test_mm256_mask_cmpneq_epi8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epi8_mask
comment|// CHECK: icmp ne<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpneq_epi8_mask
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
name|__mmask32
name|test_mm256_cmpneq_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epu8_mask
comment|// CHECK: icmp ne<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmpneq_epu8_mask
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
name|test_mm256_mask_cmpneq_epu8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epu8_mask
comment|// CHECK: icmp ne<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmpneq_epu8_mask
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
name|test_mm256_cmpneq_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epi16_mask
comment|// CHECK: icmp ne<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpneq_epi16_mask
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
name|test_mm256_mask_cmpneq_epi16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epi16_mask
comment|// CHECK: icmp ne<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpneq_epi16_mask
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
name|test_mm256_cmpneq_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epu16_mask
comment|// CHECK: icmp ne<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmpneq_epu16_mask
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
name|test_mm256_mask_cmpneq_epu16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epu16_mask
comment|// CHECK: icmp ne<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmpneq_epu16_mask
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
name|test_mm_cmp_epi8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epi8_mask
comment|// CHECK: icmp eq<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmp_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_mask_cmp_epi8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_epi8_mask
comment|// CHECK: icmp eq<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmp_epi8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_cmp_epu8_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epu8_mask
comment|// CHECK: icmp eq<16 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_cmp_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_mask_cmp_epu8_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_epu8_mask
comment|// CHECK: icmp eq<16 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm_mask_cmp_epu8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_epi16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epi16_mask
comment|// CHECK: icmp eq<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmp_epi16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_epi16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_epi16_mask
comment|// CHECK: icmp eq<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmp_epi16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_epu16_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epu16_mask
comment|// CHECK: icmp eq<8 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmp_epu16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_epu16_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_epu16_mask
comment|// CHECK: icmp eq<8 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmp_epu16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_cmp_epi8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epi8_mask
comment|// CHECK: icmp eq<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmp_epi8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmp_epi8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epi8_mask
comment|// CHECK: icmp eq<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmp_epi8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_cmp_epu8_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epu8_mask
comment|// CHECK: icmp eq<32 x i8> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_cmp_epu8_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_cmp_epu8_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epu8_mask
comment|// CHECK: icmp eq<32 x i8> %{{.*}}, %{{.*}}
comment|// CHECK: and<32 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask32
operator|)
name|_mm256_mask_cmp_epu8_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_cmp_epi16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epi16_mask
comment|// CHECK: icmp eq<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmp_epi16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_mask_cmp_epi16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epi16_mask
comment|// CHECK: icmp eq<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmp_epi16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_cmp_epu16_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epu16_mask
comment|// CHECK: icmp eq<16 x i16> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_cmp_epu16_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_mask_cmp_epu16_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epu16_mask
comment|// CHECK: icmp eq<16 x i16> %{{.*}}, %{{.*}}
comment|// CHECK: and<16 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask16
operator|)
name|_mm256_mask_cmp_epu16_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_add_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_add_epi8
comment|//CHECK: add<32 x i8> %{{.*}}, %{{.*}}
comment|//CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_add_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_add_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_add_epi8
comment|//CHECK: add<32 x i8> %{{.*}}, %{{.*}}
comment|//CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_add_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_add_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_add_epi16
comment|//CHECK: add<16 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_add_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_add_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_add_epi16
comment|//CHECK: add<16 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_add_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_sub_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_sub_epi8
comment|//CHECK: sub<32 x i8> %{{.*}}, %{{.*}}
comment|//CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_sub_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_sub_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_sub_epi8
comment|//CHECK: sub<32 x i8> %{{.*}}, %{{.*}}
comment|//CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_sub_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_sub_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_sub_epi16
comment|//CHECK: sub<16 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_sub_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_sub_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_sub_epi16
comment|//CHECK: sub<16 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_sub_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_add_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_add_epi8
comment|//CHECK: add<16 x i8> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_add_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_add_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_add_epi8
comment|//CHECK: add<16 x i8> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_add_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_add_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_add_epi16
comment|//CHECK: add<8 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_add_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_add_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_add_epi16
comment|//CHECK: add<8 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_add_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_sub_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_sub_epi8
comment|//CHECK: sub<16 x i8> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_sub_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_sub_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_sub_epi8
comment|//CHECK: sub<16 x i8> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_sub_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_sub_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_sub_epi16
comment|//CHECK: sub<8 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_sub_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_sub_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_sub_epi16
comment|//CHECK: sub<8 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_sub_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_mullo_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_mullo_epi16
comment|//CHECK: mul<16 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_mullo_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_mullo_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_mullo_epi16
comment|//CHECK: mul<16 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_mullo_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_mullo_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_mullo_epi16
comment|//CHECK: mul<8 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_mullo_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_mullo_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_mullo_epi16
comment|//CHECK: mul<8 x i16> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_mullo_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_blend_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_blend_epi8
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_blend_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_blend_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_blend_epi8
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_blend_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_blend_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_blend_epi16
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_blend_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_blend_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_blend_epi16
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_blend_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__W
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_abs_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_abs_epi8
comment|// CHECK: @llvm.x86.ssse3.pabs.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_abs_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_abs_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_abs_epi8
comment|// CHECK: @llvm.x86.ssse3.pabs.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_abs_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_abs_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_abs_epi8
comment|// CHECK: @llvm.x86.avx2.pabs.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_abs_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_abs_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_abs_epi8
comment|// CHECK: @llvm.x86.avx2.pabs.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_abs_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_abs_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_abs_epi16
comment|// CHECK: @llvm.x86.ssse3.pabs.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_abs_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_abs_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_abs_epi16
comment|// CHECK: @llvm.x86.ssse3.pabs.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_abs_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_abs_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_abs_epi16
comment|// CHECK: @llvm.x86.avx2.pabs.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_abs_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_abs_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_abs_epi16
comment|// CHECK: @llvm.x86.avx2.pabs.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_abs_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_packs_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_packs_epi32
comment|// CHECK: @llvm.x86.sse2.packssdw
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_packs_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_packs_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_packs_epi32
comment|// CHECK: @llvm.x86.sse2.packssdw
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_packs_epi32
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_packs_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_packs_epi32
comment|// CHECK: @llvm.x86.avx2.packssdw
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_packs_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_packs_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_packs_epi32
comment|// CHECK: @llvm.x86.avx2.packssdw
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_packs_epi32
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_packs_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_packs_epi16
comment|// CHECK: @llvm.x86.sse2.packsswb
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_packs_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_packs_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_packs_epi16
comment|// CHECK: @llvm.x86.sse2.packsswb
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_packs_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_packs_epi16
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_packs_epi16
comment|// CHECK: @llvm.x86.avx2.packsswb
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_packs_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_packs_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_packs_epi16
comment|// CHECK: @llvm.x86.avx2.packsswb
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_packs_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_packus_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_packus_epi32
comment|// CHECK: @llvm.x86.sse41.packusdw
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_packus_epi32
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_packus_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_packus_epi32
comment|// CHECK: @llvm.x86.sse41.packusdw
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_packus_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_packus_epi32
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_packus_epi32
comment|// CHECK: @llvm.x86.avx2.packusdw
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_packus_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_packus_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_packus_epi32
comment|// CHECK: @llvm.x86.avx2.packusdw
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_packus_epi32
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_packus_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_packus_epi16
comment|// CHECK: @llvm.x86.sse2.packuswb
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_packus_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_packus_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_packus_epi16
comment|// CHECK: @llvm.x86.sse2.packuswb
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_packus_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_packus_epi16
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_packus_epi16
comment|// CHECK: @llvm.x86.avx2.packuswb
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_packus_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_packus_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_packus_epi16
comment|// CHECK: @llvm.x86.avx2.packuswb
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_packus_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_adds_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_adds_epi8
comment|// CHECK: @llvm.x86.sse2.padds.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_adds_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_adds_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_adds_epi8
comment|// CHECK: @llvm.x86.sse2.padds.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_adds_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_adds_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_adds_epi8
comment|// CHECK: @llvm.x86.avx2.padds.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_adds_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_adds_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_adds_epi8
comment|// CHECK: @llvm.x86.avx2.padds.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_adds_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_adds_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_adds_epi16
comment|// CHECK: @llvm.x86.sse2.padds.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_adds_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_adds_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_adds_epi16
comment|// CHECK: @llvm.x86.sse2.padds.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_adds_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_adds_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_adds_epi16
comment|// CHECK: @llvm.x86.avx2.padds.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_adds_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_adds_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_adds_epi16
comment|// CHECK: @llvm.x86.avx2.padds.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_adds_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_adds_epu8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_adds_epu8
comment|// CHECK: @llvm.x86.sse2.paddus.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_adds_epu8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_adds_epu8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_adds_epu8
comment|// CHECK: @llvm.x86.sse2.paddus.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_adds_epu8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_adds_epu8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_adds_epu8
comment|// CHECK: @llvm.x86.avx2.paddus.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_adds_epu8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_adds_epu8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_adds_epu8
comment|// CHECK: @llvm.x86.avx2.paddus.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_adds_epu8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_adds_epu16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_adds_epu16
comment|// CHECK: @llvm.x86.sse2.paddus.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_adds_epu16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_adds_epu16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_adds_epu16
comment|// CHECK: @llvm.x86.sse2.paddus.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_adds_epu16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_adds_epu16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_adds_epu16
comment|// CHECK: @llvm.x86.avx2.paddus.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_adds_epu16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_adds_epu16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_adds_epu16
comment|// CHECK: @llvm.x86.avx2.paddus.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_adds_epu16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_avg_epu8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_avg_epu8
comment|// CHECK: @llvm.x86.sse2.pavg.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_avg_epu8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_avg_epu8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_avg_epu8
comment|// CHECK: @llvm.x86.sse2.pavg.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_avg_epu8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_avg_epu8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_avg_epu8
comment|// CHECK: @llvm.x86.avx2.pavg.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_avg_epu8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_avg_epu8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_avg_epu8
comment|// CHECK: @llvm.x86.avx2.pavg.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_avg_epu8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_avg_epu16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_avg_epu16
comment|// CHECK: @llvm.x86.sse2.pavg.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_avg_epu16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_avg_epu16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_avg_epu16
comment|// CHECK: @llvm.x86.sse2.pavg.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_avg_epu16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_avg_epu16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_avg_epu16
comment|// CHECK: @llvm.x86.avx2.pavg.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_avg_epu16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_avg_epu16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_avg_epu16
comment|// CHECK: @llvm.x86.avx2.pavg.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_avg_epu16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_max_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_max_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i8> [[RES]],<16 x i8> {{.*}}
return|return
name|_mm_maskz_max_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_max_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_max_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i8> [[RES]],<16 x i8> {{.*}}
return|return
name|_mm_mask_max_epi8
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_max_epi8
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
comment|// CHECK:       select<32 x i1> {{.*}},<32 x i8> [[RES]],<32 x i8> {{.*}}
return|return
name|_mm256_maskz_max_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_max_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
comment|// CHECK:       select<32 x i1> {{.*}},<32 x i8> [[RES]],<32 x i8> {{.*}}
return|return
name|_mm256_mask_max_epi8
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_max_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_max_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i16> [[RES]],<8 x i16> {{.*}}
return|return
name|_mm_maskz_max_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_max_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_max_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i16> [[RES]],<8 x i16> {{.*}}
return|return
name|_mm_mask_max_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_max_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i16> [[RES]],<16 x i16> {{.*}}
return|return
name|_mm256_maskz_max_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_max_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i16> [[RES]],<16 x i16> {{.*}}
return|return
name|_mm256_mask_max_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_max_epu8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_max_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i8> [[RES]],<16 x i8> {{.*}}
return|return
name|_mm_maskz_max_epu8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_max_epu8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_max_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i8> [[RES]],<16 x i8> {{.*}}
return|return
name|_mm_mask_max_epu8
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_max_epu8
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
comment|// CHECK:       select<32 x i1> {{.*}},<32 x i8> [[RES]],<32 x i8> {{.*}}
return|return
name|_mm256_maskz_max_epu8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_max_epu8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
comment|// CHECK:       select<32 x i1> {{.*}},<32 x i8> [[RES]],<32 x i8> {{.*}}
return|return
name|_mm256_mask_max_epu8
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_max_epu16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_max_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i16> [[RES]],<8 x i16> {{.*}}
return|return
name|_mm_maskz_max_epu16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_max_epu16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_max_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i16> [[RES]],<8 x i16> {{.*}}
return|return
name|_mm_mask_max_epu16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_max_epu16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i16> [[RES]],<16 x i16> {{.*}}
return|return
name|_mm256_maskz_max_epu16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_max_epu16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i16> [[RES]],<16 x i16> {{.*}}
return|return
name|_mm256_mask_max_epu16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_min_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_min_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp slt<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i8> [[RES]],<16 x i8> {{.*}}
return|return
name|_mm_maskz_min_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_min_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_min_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp slt<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i8> [[RES]],<16 x i8> {{.*}}
return|return
name|_mm_mask_min_epi8
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_min_epi8
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp slt<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
comment|// CHECK:       select<32 x i1> {{.*}},<32 x i8> [[RES]],<32 x i8> {{.*}}
return|return
name|_mm256_maskz_min_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_min_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp slt<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
comment|// CHECK:       select<32 x i1> {{.*}},<32 x i8> [[RES]],<32 x i8> {{.*}}
return|return
name|_mm256_mask_min_epi8
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_min_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_min_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp slt<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i16> [[RES]],<8 x i16> {{.*}}
return|return
name|_mm_maskz_min_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_min_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_min_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp slt<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i16> [[RES]],<8 x i16> {{.*}}
return|return
name|_mm_mask_min_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_min_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp slt<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i16> [[RES]],<16 x i16> {{.*}}
return|return
name|_mm256_maskz_min_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_min_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp slt<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i16> [[RES]],<16 x i16> {{.*}}
return|return
name|_mm256_mask_min_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_min_epu8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_min_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ult<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i8> [[RES]],<16 x i8> {{.*}}
return|return
name|_mm_maskz_min_epu8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_min_epu8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_min_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ult<16 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i8> [[X]],<16 x i8> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i8> [[RES]],<16 x i8> {{.*}}
return|return
name|_mm_mask_min_epu8
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_min_epu8
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ult<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
comment|// CHECK:       select<32 x i1> {{.*}},<32 x i8> [[RES]],<32 x i8> {{.*}}
return|return
name|_mm256_maskz_min_epu8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_min_epu8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ult<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
comment|// CHECK:       select<32 x i1> {{.*}},<32 x i8> [[RES]],<32 x i8> {{.*}}
return|return
name|_mm256_mask_min_epu8
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_min_epu16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_min_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ult<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i16> [[RES]],<8 x i16> {{.*}}
return|return
name|_mm_maskz_min_epu16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_min_epu16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_min_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ult<8 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i16> [[X]],<8 x i16> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i16> [[RES]],<8 x i16> {{.*}}
return|return
name|_mm_mask_min_epu16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_min_epu16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ult<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i16> [[RES]],<16 x i16> {{.*}}
return|return
name|_mm256_maskz_min_epu16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_min_epu16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ult<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
comment|// CHECK:       select<16 x i1> {{.*}},<16 x i16> [[RES]],<16 x i16> {{.*}}
return|return
name|_mm256_mask_min_epu16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_shuffle_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_shuffle_epi8
comment|// CHECK: @llvm.x86.ssse3.pshuf.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_shuffle_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_shuffle_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_shuffle_epi8
comment|// CHECK: @llvm.x86.ssse3.pshuf.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_shuffle_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_shuffle_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_shuffle_epi8
comment|// CHECK: @llvm.x86.avx2.pshuf.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_shuffle_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_shuffle_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_shuffle_epi8
comment|// CHECK: @llvm.x86.avx2.pshuf.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_shuffle_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_subs_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_subs_epi8
comment|// CHECK: @llvm.x86.sse2.psubs.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_subs_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_subs_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_subs_epi8
comment|// CHECK: @llvm.x86.sse2.psubs.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_subs_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_subs_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_subs_epi8
comment|// CHECK: @llvm.x86.avx2.psubs.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_subs_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_subs_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_subs_epi8
comment|// CHECK: @llvm.x86.avx2.psubs.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_subs_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_subs_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_subs_epi16
comment|// CHECK: @llvm.x86.sse2.psubs.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_subs_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_subs_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_subs_epi16
comment|// CHECK: @llvm.x86.sse2.psubs.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_subs_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_subs_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_subs_epi16
comment|// CHECK: @llvm.x86.avx2.psubs.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_subs_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_subs_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_subs_epi16
comment|// CHECK: @llvm.x86.avx2.psubs.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_subs_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_subs_epu8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_subs_epu8
comment|// CHECK: @llvm.x86.sse2.psubus.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_subs_epu8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_subs_epu8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_subs_epu8
comment|// CHECK: @llvm.x86.sse2.psubus.b
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_subs_epu8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_subs_epu8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_subs_epu8
comment|// CHECK: @llvm.x86.avx2.psubus.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_subs_epu8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_subs_epu8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_subs_epu8
comment|// CHECK: @llvm.x86.avx2.psubus.b
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_subs_epu8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_subs_epu16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_subs_epu16
comment|// CHECK: @llvm.x86.sse2.psubus.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_subs_epu16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_subs_epu16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_subs_epu16
comment|// CHECK: @llvm.x86.sse2.psubus.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_subs_epu16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_subs_epu16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_subs_epu16
comment|// CHECK: @llvm.x86.avx2.psubus.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_subs_epu16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_subs_epu16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_subs_epu16
comment|// CHECK: @llvm.x86.avx2.psubus.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_subs_epu16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask2_permutex2var_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask2_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.hi.128
return|return
name|_mm_mask2_permutex2var_epi16
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask2_permutex2var_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask2_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.hi.256
return|return
name|_mm256_mask2_permutex2var_epi16
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_permutex2var_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.hi.128
return|return
name|_mm_permutex2var_epi16
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_permutex2var_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.hi.128
return|return
name|_mm_mask_permutex2var_epi16
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_permutex2var_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.hi.128
return|return
name|_mm_maskz_permutex2var_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_permutex2var_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.hi.256
return|return
name|_mm256_permutex2var_epi16
argument_list|(
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_permutex2var_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.hi.256
return|return
name|_mm256_mask_permutex2var_epi16
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_permutex2var_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutex2var_epi16
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.hi.256
return|return
name|_mm256_maskz_permutex2var_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__I
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_maddubs_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_maddubs_epi16
comment|// CHECK: @llvm.x86.ssse3.pmadd.ub.sw
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_maddubs_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_maddubs_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_maddubs_epi16
comment|// CHECK: @llvm.x86.ssse3.pmadd.ub.sw
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_maddubs_epi16
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_maddubs_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_maddubs_epi16
comment|// CHECK: @llvm.x86.avx2.pmadd.ub.sw
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_maddubs_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_maddubs_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_maddubs_epi16
comment|// CHECK: @llvm.x86.avx2.pmadd.ub.sw
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_maddubs_epi16
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_madd_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_madd_epi16
comment|// CHECK: @llvm.x86.sse2.pmadd.wd
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_madd_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_madd_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_madd_epi16
comment|// CHECK: @llvm.x86.sse2.pmadd.wd
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_madd_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_madd_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_madd_epi16
comment|// CHECK: @llvm.x86.avx2.pmadd.wd
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_madd_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_madd_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_madd_epi16
comment|// CHECK: @llvm.x86.avx2.pmadd.wd
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_madd_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtsepi16_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtsepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.128
return|return
name|_mm_cvtsepi16_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtsepi16_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.128
return|return
name|_mm_mask_cvtsepi16_epi8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_cvtsepi16_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtsepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.128
return|return
name|_mm_maskz_cvtsepi16_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_cvtsepi16_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtsepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.256
return|return
name|_mm256_cvtsepi16_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtsepi16_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.256
return|return
name|_mm256_mask_cvtsepi16_epi8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_maskz_cvtsepi16_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtsepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.256
return|return
name|_mm256_maskz_cvtsepi16_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtusepi16_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtusepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.128
return|return
name|_mm_cvtusepi16_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtusepi16_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.128
return|return
name|_mm_mask_cvtusepi16_epi8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_cvtusepi16_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtusepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.128
return|return
name|_mm_maskz_cvtusepi16_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_cvtusepi16_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtusepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.256
return|return
name|_mm256_cvtusepi16_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtusepi16_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.256
return|return
name|_mm256_mask_cvtusepi16_epi8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_maskz_cvtusepi16_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtusepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.256
return|return
name|_mm256_maskz_cvtusepi16_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_cvtepi16_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.128
return|return
name|_mm_cvtepi16_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepi16_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.128
return|return
name|_mm_mask_cvtepi16_epi8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_cvtepi16_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.128
return|return
name|_mm_maskz_cvtepi16_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_cvtepi16_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.256
return|return
name|_mm256_cvtepi16_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtepi16_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.256
return|return
name|_mm256_mask_cvtepi16_epi8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_maskz_cvtepi16_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi16_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.256
return|return
name|_mm256_maskz_cvtepi16_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_mulhrs_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_mulhrs_epi16
comment|// CHECK: @llvm.x86.ssse3.pmul.hr.sw
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_mulhrs_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_mulhrs_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mulhrs_epi16
comment|// CHECK: @llvm.x86.ssse3.pmul.hr.sw
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_mulhrs_epi16
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_mulhrs_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mulhrs_epi16
comment|// CHECK: @llvm.x86.avx2.pmul.hr.sw
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_mulhrs_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_mulhrs_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mulhrs_epi16
comment|// CHECK: @llvm.x86.avx2.pmul.hr.sw
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_mulhrs_epi16
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_mulhi_epu16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_mulhi_epu16
comment|// CHECK: @llvm.x86.sse2.pmulhu.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_mulhi_epu16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_mulhi_epu16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mulhi_epu16
comment|// CHECK: @llvm.x86.sse2.pmulhu.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_mulhi_epu16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_mulhi_epu16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mulhi_epu16
comment|// CHECK: @llvm.x86.avx2.pmulhu.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_mulhi_epu16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_mulhi_epu16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mulhi_epu16
comment|// CHECK: @llvm.x86.avx2.pmulhu.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_mulhi_epu16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_mulhi_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_mulhi_epi16
comment|// CHECK: @llvm.x86.sse2.pmulh.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_mulhi_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_mulhi_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mulhi_epi16
comment|// CHECK: @llvm.x86.sse2.pmulh.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_mulhi_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_mulhi_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mulhi_epi16
comment|// CHECK: @llvm.x86.avx2.pmulh.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_mulhi_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_mulhi_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mulhi_epi16
comment|// CHECK: @llvm.x86.avx2.pmulh.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_mulhi_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_unpackhi_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_unpackhi_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_unpackhi_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_unpackhi_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_unpackhi_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_unpackhi_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_unpackhi_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_unpackhi_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 8, i32 40, i32 9, i32 41, i32 10, i32 42, i32 11, i32 43, i32 12, i32 44, i32 13, i32 45, i32 14, i32 46, i32 15, i32 47, i32 24, i32 56, i32 25, i32 57, i32 26, i32 58, i32 27, i32 59, i32 28, i32 60, i32 29, i32 61, i32 30, i32 62, i32 31, i32 63>
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_unpackhi_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_unpackhi_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_unpackhi_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 8, i32 40, i32 9, i32 41, i32 10, i32 42, i32 11, i32 43, i32 12, i32 44, i32 13, i32 45, i32 14, i32 46, i32 15, i32 47, i32 24, i32 56, i32 25, i32 57, i32 26, i32 58, i32 27, i32 59, i32 28, i32 60, i32 29, i32 61, i32 30, i32 62, i32 31, i32 63>
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_unpackhi_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_unpackhi_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_unpackhi_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_unpackhi_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_unpackhi_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_unpackhi_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 4, i32 12, i32 5, i32 13, i32 6, i32 14, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_unpackhi_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_unpackhi_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_unpackhi_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_unpackhi_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_unpackhi_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_unpackhi_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_unpackhi_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_unpacklo_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_unpacklo_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_unpacklo_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_unpacklo_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_unpacklo_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_unpacklo_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_unpacklo_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_unpacklo_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 0, i32 32, i32 1, i32 33, i32 2, i32 34, i32 3, i32 35, i32 4, i32 36, i32 5, i32 37, i32 6, i32 38, i32 7, i32 39, i32 16, i32 48, i32 17, i32 49, i32 18, i32 50, i32 19, i32 51, i32 20, i32 52, i32 21, i32 53, i32 22, i32 54, i32 23, i32 55>
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_unpacklo_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_unpacklo_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_unpacklo_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 0, i32 32, i32 1, i32 33, i32 2, i32 34, i32 3, i32 35, i32 4, i32 36, i32 5, i32 37, i32 6, i32 38, i32 7, i32 39, i32 16, i32 48, i32 17, i32 49, i32 18, i32 50, i32 19, i32 51, i32 20, i32 52, i32 21, i32 53, i32 22, i32 54, i32 23, i32 55>
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_unpacklo_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_unpacklo_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_unpacklo_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_unpacklo_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_unpacklo_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_unpacklo_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 2, i32 10, i32 3, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_unpacklo_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_unpacklo_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_unpacklo_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_unpacklo_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_unpacklo_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_unpacklo_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_unpacklo_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepi8_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepi8_epi16
comment|// CHECK: sext<8 x i8> %{{.*}} to<8 x i16>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_cvtepi8_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_cvtepi8_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi8_epi16
comment|// CHECK: sext<8 x i8> %{{.*}} to<8 x i16>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_cvtepi8_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtepi8_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi8_epi16
comment|// CHECK: sext<16 x i8> %{{.*}} to<16 x i16>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_cvtepi8_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_cvtepi8_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi8_epi16
comment|// CHECK: sext<16 x i8> %{{.*}} to<16 x i16>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_cvtepi8_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepu8_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepu8_epi16
comment|// CHECK: zext<8 x i8> %{{.*}} to<8 x i16>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_cvtepu8_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_cvtepu8_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu8_epi16
comment|// CHECK: zext<8 x i8> %{{.*}} to<8 x i16>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_cvtepu8_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtepu8_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu8_epi16
comment|// CHECK: zext<16 x i8> %{{.*}} to<16 x i16>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_cvtepu8_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_cvtepu8_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu8_epi16
comment|// CHECK: zext<16 x i8> %{{.*}} to<16 x i16>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_cvtepu8_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sllv_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_sllv_epi16
comment|// CHECK: @llvm.x86.avx512.psllv.w.256(
return|return
name|_mm256_sllv_epi16
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_sllv_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sllv_epi16
comment|// CHECK: @llvm.x86.avx512.psllv.w.256(
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_sllv_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_sllv_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sllv_epi16
comment|// CHECK: @llvm.x86.avx512.psllv.w.256(
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_sllv_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sllv_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_sllv_epi16
comment|// CHECK: @llvm.x86.avx512.psllv.w.128(
return|return
name|_mm_sllv_epi16
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_sllv_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_sllv_epi16
comment|// CHECK: @llvm.x86.avx512.psllv.w.128(
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_sllv_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_sllv_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_sllv_epi16
comment|// CHECK: @llvm.x86.avx512.psllv.w.128(
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_sllv_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_sll_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_sll_epi16
comment|// CHECK: @llvm.x86.sse2.psll.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_sll_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_sll_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_sll_epi16
comment|// CHECK: @llvm.x86.sse2.psll.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_sll_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_sll_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sll_epi16
comment|// CHECK: @llvm.x86.avx2.psll.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_sll_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_sll_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sll_epi16
comment|// CHECK: @llvm.x86.avx2.psll.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_sll_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_slli_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_slli_epi16
comment|// CHECK: @llvm.x86.sse2.pslli.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_slli_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_slli_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_slli_epi16
comment|// CHECK: @llvm.x86.sse2.pslli.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_slli_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_slli_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_slli_epi16
comment|// CHECK: @llvm.x86.avx2.pslli.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_slli_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_slli_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_slli_epi16
comment|// CHECK: @llvm.x86.avx2.pslli.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_slli_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srlv_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_srlv_epi16
comment|// CHECK: @llvm.x86.avx512.psrlv.w.256(
return|return
name|_mm256_srlv_epi16
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_srlv_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srlv_epi16
comment|// CHECK: @llvm.x86.avx512.psrlv.w.256(
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_srlv_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_srlv_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srlv_epi16
comment|// CHECK: @llvm.x86.avx512.psrlv.w.256(
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_srlv_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srlv_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_srlv_epi16
comment|// CHECK: @llvm.x86.avx512.psrlv.w.128(
return|return
name|_mm_srlv_epi16
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_srlv_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_srlv_epi16
comment|// CHECK: @llvm.x86.avx512.psrlv.w.128(
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_srlv_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_srlv_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_srlv_epi16
comment|// CHECK: @llvm.x86.avx512.psrlv.w.128(
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_srlv_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_srl_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_srl_epi16
comment|// CHECK: @llvm.x86.sse2.psrl.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_srl_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_srl_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_srl_epi16
comment|// CHECK: @llvm.x86.sse2.psrl.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_srl_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_srl_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srl_epi16
comment|// CHECK: @llvm.x86.avx2.psrl.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_srl_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_srl_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srl_epi16
comment|// CHECK: @llvm.x86.avx2.psrl.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_srl_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_srli_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_srli_epi16
comment|// CHECK: @llvm.x86.sse2.psrli.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_srli_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_srli_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_srli_epi16
comment|// CHECK: @llvm.x86.sse2.psrli.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_srli_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_srli_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srli_epi16
comment|// CHECK: @llvm.x86.avx2.psrli.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_srli_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_srli_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srli_epi16
comment|// CHECK: @llvm.x86.avx2.psrli.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_srli_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srav_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_srav_epi16
comment|// CHECK: @llvm.x86.avx512.psrav.w.256(
return|return
name|_mm256_srav_epi16
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_srav_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srav_epi16
comment|// CHECK: @llvm.x86.avx512.psrav.w.256(
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_srav_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_srav_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srav_epi16
comment|// CHECK: @llvm.x86.avx512.psrav.w.256(
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_srav_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srav_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_srav_epi16
comment|// CHECK: @llvm.x86.avx512.psrav.w.128(
return|return
name|_mm_srav_epi16
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_srav_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_srav_epi16
comment|// CHECK: @llvm.x86.avx512.psrav.w.128(
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_srav_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_srav_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_srav_epi16
comment|// CHECK: @llvm.x86.avx512.psrav.w.128(
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_srav_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_sra_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_sra_epi16
comment|// CHECK: @llvm.x86.sse2.psra.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_sra_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_sra_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_sra_epi16
comment|// CHECK: @llvm.x86.sse2.psra.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_sra_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_sra_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sra_epi16
comment|// CHECK: @llvm.x86.avx2.psra.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_sra_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_sra_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sra_epi16
comment|// CHECK: @llvm.x86.avx2.psra.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_sra_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_srai_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_srai_epi16
comment|// CHECK: @llvm.x86.sse2.psrai.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_srai_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_srai_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_srai_epi16
comment|// CHECK: @llvm.x86.sse2.psrai.w
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_srai_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_srai_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srai_epi16
comment|// CHECK: @llvm.x86.avx2.psrai.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_srai_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_srai_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srai_epi16
comment|// CHECK: @llvm.x86.avx2.psrai.w
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_srai_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_mov_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_mov_epi16
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_mov_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_mov_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mov_epi16
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_mov_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_mov_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mov_epi16
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_mov_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_mov_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mov_epi16
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_mov_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_mov_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_mov_epi8
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_mov_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_mov_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mov_epi8
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_mov_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_mov_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mov_epi8
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_mov_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_mov_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mov_epi8
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_mov_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_loadu_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_loadu_epi16
comment|// CHECK: @llvm.masked.load.v8i16.p0v8i16(<8 x i16>* %{{.*}}, i32 1,<8 x i1> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_mask_loadu_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_loadu_epi16
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_loadu_epi16
comment|// CHECK: @llvm.masked.load.v8i16.p0v8i16(<8 x i16>* %{{.*}}, i32 1,<8 x i1> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm_maskz_loadu_epi16
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_loadu_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_loadu_epi16
comment|// CHECK: @llvm.masked.load.v16i16.p0v16i16(<16 x i16>* %{{.*}}, i32 1,<16 x i1> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_mask_loadu_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_loadu_epi16
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_loadu_epi16
comment|// CHECK: @llvm.masked.load.v16i16.p0v16i16(<16 x i16>* %{{.*}}, i32 1,<16 x i1> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_maskz_loadu_epi16
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_loadu_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_loadu_epi8
comment|// CHECK: @llvm.masked.load.v16i8.p0v16i8(<16 x i8>* %{{.*}}, i32 1,<16 x i1> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_mask_loadu_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_loadu_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_loadu_epi8
comment|// CHECK: @llvm.masked.load.v16i8.p0v16i8(<16 x i8>* %{{.*}}, i32 1,<16 x i1> %{{.*}},<16 x i8> %{{.*}})
return|return
name|_mm_maskz_loadu_epi8
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_loadu_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_loadu_epi8
comment|// CHECK: @llvm.masked.load.v32i8.p0v32i8(<32 x i8>* %{{.*}}, i32 1,<32 x i1> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_mask_loadu_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_loadu_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|void
specifier|const
modifier|*
name|__P
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_loadu_epi8
comment|// CHECK: @llvm.masked.load.v32i8.p0v32i8(<32 x i8>* %{{.*}}, i32 1,<32 x i1> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_maskz_loadu_epi8
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_storeu_epi16
comment|// CHECK: @llvm.masked.store.v8i16.p0v8i16(<8 x i16> %{{.*}},<8 x i16>* %{{.*}}, i32 1,<8 x i1> %{{.*}})
return|return
name|_mm_mask_storeu_epi16
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_storeu_epi16
comment|// CHECK: @llvm.masked.store.v16i16.p0v16i16(<16 x i16> %{{.*}},<16 x i16>* %{{.*}}, i32 1,<16 x i1> %{{.*}})
return|return
name|_mm256_mask_storeu_epi16
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_storeu_epi8
comment|// CHECK: @llvm.masked.store.v16i8.p0v16i8(<16 x i8> %{{.*}},<16 x i8>* %{{.*}}, i32 1,<16 x i1> %{{.*}})
return|return
name|_mm_mask_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_storeu_epi8
comment|// CHECK: @llvm.masked.store.v32i8.p0v32i8(<32 x i8> %{{.*}},<32 x i8>* %{{.*}}, i32 1,<32 x i1> %{{.*}})
return|return
name|_mm256_mask_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_test_epi8_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_test_epi8_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.b.128
return|return
name|_mm_test_epi8_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_mask_test_epi8_mask
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_test_epi8_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.b.128
return|return
name|_mm_mask_test_epi8_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_test_epi8_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_test_epi8_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.b.256
return|return
name|_mm256_test_epi8_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_test_epi8_mask
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_test_epi8_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.b.256
return|return
name|_mm256_mask_test_epi8_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_test_epi16_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_test_epi16_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.w.128
return|return
name|_mm_test_epi16_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_test_epi16_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_test_epi16_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.w.128
return|return
name|_mm_mask_test_epi16_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_test_epi16_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_test_epi16_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.w.256
return|return
name|_mm256_test_epi16_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_mask_test_epi16_mask
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_test_epi16_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.w.256
return|return
name|_mm256_mask_test_epi16_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_testn_epi8_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_testn_epi8_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.b.128
return|return
name|_mm_testn_epi8_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_mask_testn_epi8_mask
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_testn_epi8_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.b.128
return|return
name|_mm_mask_testn_epi8_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_testn_epi8_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_testn_epi8_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.b.256
return|return
name|_mm256_testn_epi8_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_mask_testn_epi8_mask
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_testn_epi8_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.b.256
return|return
name|_mm256_mask_testn_epi8_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_testn_epi16_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_testn_epi16_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.w.128
return|return
name|_mm_testn_epi16_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_testn_epi16_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_testn_epi16_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.w.128
return|return
name|_mm_mask_testn_epi16_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_testn_epi16_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_testn_epi16_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.w.256
return|return
name|_mm256_testn_epi16_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_mask_testn_epi16_mask
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_testn_epi16_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.w.256
return|return
name|_mm256_mask_testn_epi16_mask
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm_movepi8_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movepi8_mask
comment|// CHECK: @llvm.x86.avx512.cvtb2mask.128
return|return
name|_mm_movepi8_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask32
name|test_mm256_movepi8_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movepi8_mask
comment|// CHECK: @llvm.x86.avx512.cvtb2mask.256
return|return
name|_mm256_movepi8_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_movm_epi8
parameter_list|(
name|__mmask16
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movm_epi8
comment|// CHECK: %{{.*}} = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: %vpmovm2.i = sext<16 x i1> %{{.*}} to<16 x i8>
return|return
name|_mm_movm_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_movm_epi8
parameter_list|(
name|__mmask32
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movm_epi8
comment|// CHECK: %{{.*}} = bitcast i32 %{{.*}} to<32 x i1>
comment|// CHECK: %vpmovm2.i = sext<32 x i1> %{{.*}} to<32 x i8>
return|return
name|_mm256_movm_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_movm_epi16
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movm_epi16
comment|// CHECK: %{{.*}} = bitcast i8 %{{.*}} to<8 x i1>
comment|// CHECK: %vpmovm2.i = sext<8 x i1> %{{.*}} to<8 x i16>
return|return
name|_mm_movm_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_movm_epi16
parameter_list|(
name|__mmask16
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movm_epi16
comment|// CHECK: %{{.*}} = bitcast i16 %{{.*}} to<16 x i1>
comment|// CHECK: %vpmovm2.i = sext<16 x i1> %{{.*}} to<16 x i16>
return|return
name|_mm256_movm_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_broadcastb_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_broadcastb_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32> zeroinitializer
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_broadcastb_epi8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_broadcastb_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_broadcastb_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32> zeroinitializer
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_broadcastb_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_broadcastb_epi8
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcastb_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<32 x i32> zeroinitializer
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_broadcastb_epi8
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_broadcastb_epi8
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcastb_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<32 x i32> zeroinitializer
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_broadcastb_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_broadcastw_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_broadcastw_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_broadcastw_epi16
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_broadcastw_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_broadcastw_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_broadcastw_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_broadcastw_epi16
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcastw_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<16 x i32> zeroinitializer
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_broadcastw_epi16
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_broadcastw_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcastw_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<16 x i32> zeroinitializer
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_broadcastw_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_set1_epi16
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|short
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_set1_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.w.gpr.256
return|return
name|_mm256_mask_set1_epi16
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_set1_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|short
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_set1_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.w.gpr.256
return|return
name|_mm256_maskz_set1_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_set1_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|short
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_set1_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.w.gpr.128
return|return
name|_mm_mask_set1_epi16
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_set1_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|short
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_set1_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.w.gpr.128
return|return
name|_mm_maskz_set1_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_permutexvar_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_permutexvar_epi16
comment|// CHECK: @llvm.x86.avx512.mask.permvar.hi.128
return|return
name|_mm_permutexvar_epi16
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_permutexvar_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_permutexvar_epi16
comment|// CHECK: @llvm.x86.avx512.mask.permvar.hi.128
return|return
name|_mm_maskz_permutexvar_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_permutexvar_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_permutexvar_epi16
comment|// CHECK: @llvm.x86.avx512.mask.permvar.hi.128
return|return
name|_mm_mask_permutexvar_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_permutexvar_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutexvar_epi16
comment|// CHECK: @llvm.x86.avx512.mask.permvar.hi.256
return|return
name|_mm256_permutexvar_epi16
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_permutexvar_epi16
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutexvar_epi16
comment|// CHECK: @llvm.x86.avx512.mask.permvar.hi.256
return|return
name|_mm256_maskz_permutexvar_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_permutexvar_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutexvar_epi16
comment|// CHECK: @llvm.x86.avx512.mask.permvar.hi.256
return|return
name|_mm256_mask_permutexvar_epi16
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_alignr_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_alignr_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_mask_alignr_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_alignr_epi8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_alignr_epi8
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 16, i32 17>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i8> %{{.*}},<16 x i8> %{{.*}}
return|return
name|_mm_maskz_alignr_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_alignr_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_alignr_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 32, i32 33, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30, i32 31, i32 48, i32 49>
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_mask_alignr_epi8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_alignr_epi8
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_alignr_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 32, i32 33, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30, i32 31, i32 48, i32 49>
comment|// CHECK: select<32 x i1> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}}
return|return
name|_mm256_maskz_alignr_epi8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_dbsad_epu8
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_dbsad_epu8
comment|// CHECK: @llvm.x86.avx512.mask.dbpsadbw.128
return|return
name|_mm_dbsad_epu8
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|170
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_dbsad_epu8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_dbsad_epu8
comment|// CHECK: @llvm.x86.avx512.mask.dbpsadbw.128
return|return
name|_mm_mask_dbsad_epu8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|170
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_dbsad_epu8
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_dbsad_epu8
comment|// CHECK: @llvm.x86.avx512.mask.dbpsadbw.128
return|return
name|_mm_maskz_dbsad_epu8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|170
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_dbsad_epu8
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_dbsad_epu8
comment|// CHECK: @llvm.x86.avx512.mask.dbpsadbw.256
return|return
name|_mm256_dbsad_epu8
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|170
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_dbsad_epu8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_dbsad_epu8
comment|// CHECK: @llvm.x86.avx512.mask.dbpsadbw.256
return|return
name|_mm256_mask_dbsad_epu8
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|170
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_dbsad_epu8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_dbsad_epu8
comment|// CHECK: @llvm.x86.avx512.mask.dbpsadbw.256
return|return
name|_mm256_maskz_dbsad_epu8
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|170
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_movepi16_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movepi16_mask
comment|// CHECK: @llvm.x86.avx512.cvtw2mask.128
return|return
name|_mm_movepi16_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm256_movepi16_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movepi16_mask
comment|// CHECK: @llvm.x86.avx512.cvtw2mask.256
return|return
name|_mm256_movepi16_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_shufflehi_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_shufflehi_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 5, i32 5, i32 4, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_shufflehi_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_shufflehi_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_shufflehi_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 5, i32 5, i32 4, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_shufflehi_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_shufflelo_epi16
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_shufflelo_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 1, i32 1, i32 0, i32 0, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_mask_shufflelo_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_shufflelo_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_shufflelo_epi16
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32><i32 1, i32 1, i32 0, i32 0, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i16> %{{.*}},<8 x i16> %{{.*}}
return|return
name|_mm_maskz_shufflelo_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_shufflehi_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_shufflehi_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 5, i32 5, i32 4, i32 4, i32 8, i32 9, i32 10, i32 11, i32 13, i32 13, i32 12, i32 12>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_shufflehi_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_shufflehi_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_shufflehi_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 5, i32 5, i32 4, i32 4, i32 8, i32 9, i32 10, i32 11, i32 13, i32 13, i32 12, i32 12>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_shufflehi_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_shufflelo_epi16
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_shufflelo_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 1, i32 1, i32 0, i32 0, i32 4, i32 5, i32 6, i32 7, i32 9, i32 9, i32 8, i32 8, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_mask_shufflelo_epi16
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_shufflelo_epi16
parameter_list|(
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_shufflelo_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 1, i32 1, i32 0, i32 0, i32 4, i32 5, i32 6, i32 7, i32 9, i32 9, i32 8, i32 8, i32 12, i32 13, i32 14, i32 15>
comment|// CHECK: select<16 x i1> %{{.*}},<16 x i16> %{{.*}},<16 x i16> %{{.*}}
return|return
name|_mm256_maskz_shufflelo_epi16
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtepi16_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm_mask_cvtepi16_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.mem.128
name|_mm_mask_cvtepi16_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtsepi16_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm_mask_cvtsepi16_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.mem.128
name|_mm_mask_cvtsepi16_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtusepi16_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm_mask_cvtusepi16_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.mem.128
name|_mm_mask_cvtusepi16_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtusepi16_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm256_mask_cvtusepi16_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.wb.mem.256
name|_mm256_mask_cvtusepi16_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtepi16_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm256_mask_cvtepi16_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.wb.mem.256
name|_mm256_mask_cvtepi16_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtsepi16_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL:@test_mm256_mask_cvtsepi16_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.wb.mem.256
name|_mm256_mask_cvtsepi16_storeu_epi8
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

