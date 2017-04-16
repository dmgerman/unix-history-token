begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512f -target-feature +avx512vl -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__mmask8
name|test_mm_cmpeq_epu32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epu32_mask
comment|// CHECK: icmp eq<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: shufflevector<4 x i1> %{{.*}},<4 x i1> zeroinitializer,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpeq_epu32_mask
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
name|test_mm_mask_cmpeq_epu32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epu32_mask
comment|// CHECK: icmp eq<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpeq_epu32_mask
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
name|test_mm_cmpeq_epu64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epu64_mask
comment|// CHECK: icmp eq<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: shufflevector<2 x i1> %{{.*}},<2 x i1> zeroinitializer,<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 2, i32 3, i32 2, i32 3>
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpeq_epu64_mask
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
name|test_mm_mask_cmpeq_epu64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epu64_mask
comment|// CHECK: icmp eq<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpeq_epu64_mask
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
name|test_mm_cmpge_epi32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epi32_mask
comment|// CHECK: icmp sge<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpge_epi32_mask
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
name|test_mm_mask_cmpge_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epi32_mask
comment|// CHECK: icmp sge<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpge_epi32_mask
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
name|test_mm_cmpge_epi64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epi64_mask
comment|// CHECK: icmp sge<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpge_epi64_mask
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
name|test_mm_mask_cmpge_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epi64_mask
comment|// CHECK: icmp sge<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpge_epi64_mask
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
name|test_mm256_cmpge_epi32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epi32_mask
comment|// CHECK: icmp sge<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpge_epi32_mask
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
name|test_mm256_mask_cmpge_epi32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epi32_mask
comment|// CHECK: icmp sge<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpge_epi32_mask
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
name|test_mm256_cmpge_epi64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epi64_mask
comment|// CHECK: icmp sge<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpge_epi64_mask
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
name|test_mm256_mask_cmpge_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epi64_mask
comment|// CHECK: icmp sge<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpge_epi64_mask
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
name|test_mm_cmpge_epu32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epu32_mask
comment|// CHECK: icmp uge<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpge_epu32_mask
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
name|test_mm_mask_cmpge_epu32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epu32_mask
comment|// CHECK: icmp uge<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpge_epu32_mask
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
name|test_mm_cmpge_epu64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpge_epu64_mask
comment|// CHECK: icmp uge<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpge_epu64_mask
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
name|test_mm_mask_cmpge_epu64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpge_epu64_mask
comment|// CHECK: icmp uge<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpge_epu64_mask
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
name|test_mm256_cmpge_epu32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epu32_mask
comment|// CHECK: icmp uge<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpge_epu32_mask
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
name|test_mm256_mask_cmpge_epu32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epu32_mask
comment|// CHECK: icmp uge<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpge_epu32_mask
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
name|test_mm256_cmpge_epu64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpge_epu64_mask
comment|// CHECK: icmp uge<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpge_epu64_mask
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
name|test_mm256_mask_cmpge_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpge_epu64_mask
comment|// CHECK: icmp uge<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpge_epu64_mask
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
name|test_mm_cmpgt_epu32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epu32_mask
comment|// CHECK: icmp ugt<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpgt_epu32_mask
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
name|test_mm_mask_cmpgt_epu32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epu32_mask
comment|// CHECK: icmp ugt<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpgt_epu32_mask
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
name|test_mm_cmpgt_epu64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epu64_mask
comment|// CHECK: icmp ugt<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpgt_epu64_mask
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
name|test_mm_mask_cmpgt_epu64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epu64_mask
comment|// CHECK: icmp ugt<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpgt_epu64_mask
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
name|test_mm256_cmpgt_epu32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epu32_mask
comment|// CHECK: icmp ugt<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpgt_epu32_mask
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
name|test_mm256_mask_cmpgt_epu32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epu32_mask
comment|// CHECK: icmp ugt<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpgt_epu32_mask
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
name|test_mm256_cmpgt_epu64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epu64_mask
comment|// CHECK: icmp ugt<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpgt_epu64_mask
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
name|test_mm256_mask_cmpgt_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epu64_mask
comment|// CHECK: icmp ugt<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpgt_epu64_mask
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
name|test_mm_cmple_epi32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epi32_mask
comment|// CHECK: icmp sle<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmple_epi32_mask
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
name|test_mm_mask_cmple_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmple_epi32_mask
comment|// CHECK: icmp sle<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmple_epi32_mask
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
name|test_mm_cmple_epi64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epi64_mask
comment|// CHECK: icmp sle<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmple_epi64_mask
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
name|test_mm_mask_cmple_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmple_epi64_mask
comment|// CHECK: icmp sle<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmple_epi64_mask
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
name|test_mm256_cmple_epi32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epi32_mask
comment|// CHECK: icmp sle<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmple_epi32_mask
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
name|test_mm256_mask_cmple_epi32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epi32_mask
comment|// CHECK: icmp sle<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmple_epi32_mask
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
name|test_mm256_cmple_epi64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epi64_mask
comment|// CHECK: icmp sle<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmple_epi64_mask
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
name|test_mm256_mask_cmple_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epi64_mask
comment|// CHECK: icmp sle<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmple_epi64_mask
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
name|test_mm_cmple_epu32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epu32_mask
comment|// CHECK: icmp ule<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmple_epu32_mask
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
name|test_mm_mask_cmple_epu32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmple_epu32_mask
comment|// CHECK: icmp ule<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmple_epu32_mask
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
name|test_mm_cmple_epu64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmple_epu64_mask
comment|// CHECK: icmp ule<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmple_epu64_mask
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
name|test_mm_mask_cmple_epu64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmple_epu64_mask
comment|// CHECK: icmp ule<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmple_epu64_mask
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
name|test_mm256_cmple_epu32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epu32_mask
comment|// CHECK: icmp ule<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmple_epu32_mask
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
name|test_mm256_mask_cmple_epu32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epu32_mask
comment|// CHECK: icmp ule<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmple_epu32_mask
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
name|test_mm256_cmple_epu64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmple_epu64_mask
comment|// CHECK: icmp ule<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmple_epu64_mask
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
name|test_mm256_mask_cmple_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmple_epu64_mask
comment|// CHECK: icmp ule<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmple_epu64_mask
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
name|test_mm_cmplt_epi32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epi32_mask
comment|// CHECK: icmp slt<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmplt_epi32_mask
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
name|test_mm_mask_cmplt_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epi32_mask
comment|// CHECK: icmp slt<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmplt_epi32_mask
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
name|test_mm_cmplt_epi64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epi64_mask
comment|// CHECK: icmp slt<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmplt_epi64_mask
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
name|test_mm_mask_cmplt_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epi64_mask
comment|// CHECK: icmp slt<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmplt_epi64_mask
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
name|test_mm256_cmplt_epi32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epi32_mask
comment|// CHECK: icmp slt<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmplt_epi32_mask
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
name|test_mm256_mask_cmplt_epi32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epi32_mask
comment|// CHECK: icmp slt<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmplt_epi32_mask
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
name|test_mm256_cmplt_epi64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epi64_mask
comment|// CHECK: icmp slt<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmplt_epi64_mask
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
name|test_mm256_mask_cmplt_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epi64_mask
comment|// CHECK: icmp slt<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmplt_epi64_mask
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
name|test_mm_cmplt_epu32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epu32_mask
comment|// CHECK: icmp ult<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmplt_epu32_mask
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
name|test_mm_mask_cmplt_epu32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epu32_mask
comment|// CHECK: icmp ult<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmplt_epu32_mask
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
name|test_mm_cmplt_epu64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmplt_epu64_mask
comment|// CHECK: icmp ult<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmplt_epu64_mask
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
name|test_mm_mask_cmplt_epu64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmplt_epu64_mask
comment|// CHECK: icmp ult<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmplt_epu64_mask
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
name|test_mm256_cmplt_epu32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epu32_mask
comment|// CHECK: icmp ult<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmplt_epu32_mask
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
name|test_mm256_mask_cmplt_epu32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epu32_mask
comment|// CHECK: icmp ult<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmplt_epu32_mask
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
name|test_mm256_cmplt_epu64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmplt_epu64_mask
comment|// CHECK: icmp ult<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmplt_epu64_mask
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
name|test_mm256_mask_cmplt_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmplt_epu64_mask
comment|// CHECK: icmp ult<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmplt_epu64_mask
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
name|test_mm_cmpneq_epi32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epi32_mask
comment|// CHECK: icmp ne<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpneq_epi32_mask
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
name|test_mm_mask_cmpneq_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epi32_mask
comment|// CHECK: icmp ne<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpneq_epi32_mask
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
name|test_mm_cmpneq_epi64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epi64_mask
comment|// CHECK: icmp ne<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpneq_epi64_mask
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
name|test_mm_mask_cmpneq_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epi64_mask
comment|// CHECK: icmp ne<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpneq_epi64_mask
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
name|test_mm256_cmpneq_epi32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epi32_mask
comment|// CHECK: icmp ne<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpneq_epi32_mask
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
name|test_mm256_mask_cmpneq_epi32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epi32_mask
comment|// CHECK: icmp ne<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpneq_epi32_mask
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
name|test_mm256_cmpneq_epi64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epi64_mask
comment|// CHECK: icmp ne<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpneq_epi64_mask
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
name|test_mm256_mask_cmpneq_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epi64_mask
comment|// CHECK: icmp ne<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpneq_epi64_mask
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
name|test_mm_cmpneq_epu32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epu32_mask
comment|// CHECK: icmp ne<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpneq_epu32_mask
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
name|test_mm_mask_cmpneq_epu32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epu32_mask
comment|// CHECK: icmp ne<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpneq_epu32_mask
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
name|test_mm_cmpneq_epu64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpneq_epu64_mask
comment|// CHECK: icmp ne<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpneq_epu64_mask
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
name|test_mm_mask_cmpneq_epu64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpneq_epu64_mask
comment|// CHECK: icmp ne<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpneq_epu64_mask
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
name|test_mm256_cmpneq_epu32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epu32_mask
comment|// CHECK: icmp ne<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpneq_epu32_mask
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
name|test_mm256_mask_cmpneq_epu32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epu32_mask
comment|// CHECK: icmp ne<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpneq_epu32_mask
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
name|test_mm256_cmpneq_epu64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpneq_epu64_mask
comment|// CHECK: icmp ne<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpneq_epu64_mask
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
name|test_mm256_mask_cmpneq_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpneq_epu64_mask
comment|// CHECK: icmp ne<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpneq_epu64_mask
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
name|test_mm_cmp_eq_epi32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_eq_epi32_mask
comment|// CHECK: icmp eq<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmp_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_EQ
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_lt_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_lt_epi32_mask
comment|// CHECK: icmp slt<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmp_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_LT
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_lt_epi64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_lt_epi64_mask
comment|// CHECK: icmp slt<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmp_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_LT
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_eq_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_eq_epi64_mask
comment|// CHECK: icmp eq<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmp_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_EQ
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_cmp_eq_epi32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_eq_epi32_mask
comment|// CHECK: icmp eq<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmp_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_EQ
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_cmp_le_epi32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_le_epi32_mask
comment|// CHECK: icmp sle<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmp_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_LE
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_cmp_eq_epi64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_eq_epi64_mask
comment|// CHECK: icmp eq<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmp_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_EQ
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_cmp_eq_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_eq_epi64_mask
comment|// CHECK: icmp eq<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmp_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
name|_MM_CMPINT_EQ
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_epu32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epu32_mask
comment|// CHECK: icmp eq<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmp_epu32_mask
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
name|test_mm_mask_cmp_epu32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_epu32_mask
comment|// CHECK: icmp eq<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmp_epu32_mask
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
name|test_mm_cmp_epu64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epu64_mask
comment|// CHECK: icmp eq<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmp_epu64_mask
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
name|test_mm_mask_cmp_epu64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_epu64_mask
comment|// CHECK: icmp eq<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmp_epu64_mask
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
name|test_mm256_cmp_epu32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epu32_mask
comment|// CHECK: icmp eq<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmp_epu32_mask
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
name|test_mm256_mask_cmp_epu32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epu32_mask
comment|// CHECK: icmp eq<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmp_epu32_mask
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
name|test_mm256_cmp_epu64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epu64_mask
comment|// CHECK: icmp eq<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmp_epu64_mask
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
name|test_mm256_mask_cmp_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epu64_mask
comment|// CHECK: icmp eq<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmp_epu64_mask
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
name|test_mm256_mask_add_epi32
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
comment|//CHECK-LABEL: @test_mm256_mask_add_epi32
comment|//CHECK: add<8 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_add_epi32
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
name|test_mm256_maskz_add_epi32
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
comment|//CHECK-LABEL: @test_mm256_maskz_add_epi32
comment|//CHECK: add<8 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_add_epi32
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
name|test_mm256_mask_add_epi64
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
comment|//CHECK-LABEL: @test_mm256_mask_add_epi64
comment|//CHECK: add<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_add_epi64
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
name|test_mm256_maskz_add_epi64
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
comment|//CHECK-LABEL: @test_mm256_maskz_add_epi64
comment|//CHECK: add<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_add_epi64
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
name|test_mm256_mask_sub_epi32
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
comment|//CHECK-LABEL: @test_mm256_mask_sub_epi32
comment|//CHECK: sub<8 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_sub_epi32
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
name|test_mm256_maskz_sub_epi32
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
comment|//CHECK-LABEL: @test_mm256_maskz_sub_epi32
comment|//CHECK: sub<8 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_sub_epi32
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
name|test_mm256_mask_sub_epi64
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
comment|//CHECK-LABEL: @test_mm256_mask_sub_epi64
comment|//CHECK: sub<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_sub_epi64
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
name|test_mm256_maskz_sub_epi64
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
comment|//CHECK-LABEL: @test_mm256_maskz_sub_epi64
comment|//CHECK: sub<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_sub_epi64
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
name|test_mm_mask_add_epi32
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
comment|//CHECK-LABEL: @test_mm_mask_add_epi32
comment|//CHECK: add<4 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_add_epi32
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
name|test_mm_maskz_add_epi32
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
comment|//CHECK-LABEL: @test_mm_maskz_add_epi32
comment|//CHECK: add<4 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_add_epi32
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
name|test_mm_mask_add_epi64
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
comment|//CHECK-LABEL: @test_mm_mask_add_epi64
comment|//CHECK: add<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_add_epi64
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
name|test_mm_maskz_add_epi64
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
comment|//CHECK-LABEL: @test_mm_maskz_add_epi64
comment|//CHECK: add<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_add_epi64
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
name|test_mm_mask_sub_epi32
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
comment|//CHECK-LABEL: @test_mm_mask_sub_epi32
comment|//CHECK: sub<4 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_sub_epi32
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
name|test_mm_maskz_sub_epi32
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
comment|//CHECK-LABEL: @test_mm_maskz_sub_epi32
comment|//CHECK: sub<4 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_sub_epi32
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
name|test_mm_mask_sub_epi64
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
comment|//CHECK-LABEL: @test_mm_mask_sub_epi64
comment|//CHECK: sub<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_sub_epi64
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
name|test_mm_maskz_sub_epi64
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
comment|//CHECK-LABEL: @test_mm_maskz_sub_epi64
comment|//CHECK: sub<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_sub_epi64
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
name|test_mm256_mask_mul_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_mul_epi32
comment|//CHECK: @llvm.x86.avx2.pmul.dq
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_mul_epi32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm256_maskz_mul_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_mul_epi32
comment|//CHECK: @llvm.x86.avx2.pmul.dq
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_mul_epi32
argument_list|(
name|__M
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
name|test_mm_mask_mul_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_mul_epi32
comment|//CHECK: @llvm.x86.sse41.pmuldq
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_mul_epi32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm_maskz_mul_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_mul_epi32
comment|//CHECK: @llvm.x86.sse41.pmuldq
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_mul_epi32
argument_list|(
name|__M
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
name|test_mm256_mask_mul_epu32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_mul_epu32
comment|//CHECK: @llvm.x86.avx2.pmulu.dq
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_mul_epu32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm256_maskz_mul_epu32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_mul_epu32
comment|//CHECK: @llvm.x86.avx2.pmulu.dq
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_mul_epu32
argument_list|(
name|__M
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
name|test_mm_mask_mul_epu32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_mask_mul_epu32
comment|//CHECK: @llvm.x86.sse2.pmulu.dq
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_mul_epu32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm_maskz_mul_epu32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm_maskz_mul_epu32
comment|//CHECK: @llvm.x86.sse2.pmulu.dq
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_mul_epu32
argument_list|(
name|__M
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
name|test_mm_maskz_mullo_epi32
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
comment|//CHECK-LABEL: @test_mm_maskz_mullo_epi32
comment|//CHECK: mul<4 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_mullo_epi32
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
name|test_mm_mask_mullo_epi32
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
comment|//CHECK-LABEL: @test_mm_mask_mullo_epi32
comment|//CHECK: mul<4 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_mullo_epi32
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
name|test_mm256_maskz_mullo_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_maskz_mullo_epi32
comment|//CHECK: mul<8 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_mullo_epi32
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
name|test_mm256_mask_mullo_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm256_mask_mullo_epi32
comment|//CHECK: mul<8 x i32> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_mullo_epi32
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
name|test_mm256_mask_and_epi32
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
comment|//CHECK-LABEL: @test_mm256_mask_and_epi32
comment|//CHECK: and<4 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm256_mask_and_epi32
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
name|test_mm256_maskz_and_epi32
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
comment|//CHECK-LABEL: @test_mm256_maskz_and_epi32
comment|//CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_and_epi32
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
name|test_mm_mask_and_epi32
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
comment|//CHECK-LABEL: @test_mm_mask_and_epi32
comment|//CHECK: and<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_mask_and_epi32
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
name|test_mm_maskz_and_epi32
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
comment|//CHECK-LABEL: @test_mm_maskz_and_epi32
comment|//CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_and_epi32
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
name|test_mm256_mask_andnot_epi32
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
comment|//CHECK-LABEL: @test_mm256_mask_andnot_epi32
comment|//CHECK: xor<4 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1>
comment|//CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_andnot_epi32
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
name|test_mm256_maskz_andnot_epi32
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
comment|//CHECK-LABEL: @test_mm256_maskz_andnot_epi32
comment|//CHECK: xor<4 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1>
comment|//CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_andnot_epi32
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
name|test_mm_mask_andnot_epi32
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
comment|//CHECK-LABEL: @test_mm_mask_andnot_epi32
comment|//CHECK: xor<2 x i64> %{{.*}},<i64 -1, i64 -1>
comment|//CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_andnot_epi32
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
name|test_mm_maskz_andnot_epi32
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
comment|//CHECK-LABEL: @test_mm_maskz_andnot_epi32
comment|//CHECK: xor<2 x i64> %{{.*}},<i64 -1, i64 -1>
comment|//CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_andnot_epi32
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
name|test_mm256_mask_or_epi32
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
comment|//CHECK-LABEL: @test_mm256_mask_or_epi32
comment|//CHECK: or<4 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm256_mask_or_epi32
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
name|test_mm256_maskz_or_epi32
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
comment|//CHECK-LABEL: @test_mm256_maskz_or_epi32
comment|//CHECK: or<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_or_epi32
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
name|test_mm_mask_or_epi32
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
comment|//CHECK-LABEL: @test_mm_mask_or_epi32
comment|//CHECK: or<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_mask_or_epi32
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
name|test_mm_maskz_or_epi32
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
comment|//CHECK-LABEL: @test_mm_maskz_or_epi32
comment|//CHECK: or<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_or_epi32
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
name|test_mm256_mask_xor_epi32
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
comment|//CHECK-LABEL: @test_mm256_mask_xor_epi32
comment|//CHECK: xor<4 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm256_mask_xor_epi32
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
name|test_mm256_maskz_xor_epi32
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
comment|//CHECK-LABEL: @test_mm256_maskz_xor_epi32
comment|//CHECK: xor<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_xor_epi32
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
name|test_mm_mask_xor_epi32
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
comment|//CHECK-LABEL: @test_mm_mask_xor_epi32
comment|//CHECK: xor<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_mask_xor_epi32
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
name|test_mm_maskz_xor_epi32
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
comment|//CHECK-LABEL: @test_mm_maskz_xor_epi32
comment|//CHECK: xor<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_xor_epi32
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
name|test_mm256_mask_and_epi64
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
comment|//CHECK-LABEL: @test_mm256_mask_and_epi64
comment|//CHECK: and<4 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm256_mask_and_epi64
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
name|test_mm256_maskz_and_epi64
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
comment|//CHECK-LABEL: @test_mm256_maskz_and_epi64
comment|//CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_and_epi64
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
name|test_mm_mask_and_epi64
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
comment|//CHECK-LABEL: @test_mm_mask_and_epi64
comment|//CHECK: and<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_mask_and_epi64
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
name|test_mm_maskz_and_epi64
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
comment|//CHECK-LABEL: @test_mm_maskz_and_epi64
comment|//CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_and_epi64
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
name|test_mm256_mask_andnot_epi64
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
comment|//CHECK-LABEL: @test_mm256_mask_andnot_epi64
comment|//CHECK: xor<4 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1>
comment|//CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_andnot_epi64
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
name|test_mm256_maskz_andnot_epi64
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
comment|//CHECK-LABEL: @test_mm256_maskz_andnot_epi64
comment|//CHECK: xor<4 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1>
comment|//CHECK: and<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_andnot_epi64
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
name|test_mm_mask_andnot_epi64
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
comment|//CHECK-LABEL: @test_mm_mask_andnot_epi64
comment|//CHECK: xor<2 x i64> %{{.*}},<i64 -1, i64 -1>
comment|//CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_andnot_epi64
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
name|test_mm_maskz_andnot_epi64
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
comment|//CHECK-LABEL: @test_mm_maskz_andnot_epi64
comment|//CHECK: xor<2 x i64> %{{.*}},<i64 -1, i64 -1>
comment|//CHECK: and<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_andnot_epi64
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
name|test_mm256_mask_or_epi64
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
comment|//CHECK-LABEL: @test_mm256_mask_or_epi64
comment|//CHECK: or<4 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm256_mask_or_epi64
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
name|test_mm256_maskz_or_epi64
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
comment|//CHECK-LABEL: @test_mm256_maskz_or_epi64
comment|//CHECK: or<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_or_epi64
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
name|test_mm_mask_or_epi64
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
comment|//CHECK-LABEL: @test_mm_mask_or_epi64
comment|//CHECK: or<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_mask_or_epi64
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
name|test_mm_maskz_or_epi64
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
comment|//CHECK-LABEL: @test_mm_maskz_or_epi64
comment|//CHECK: or<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_or_epi64
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
name|test_mm256_mask_xor_epi64
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
comment|//CHECK-LABEL: @test_mm256_mask_xor_epi64
comment|//CHECK: xor<4 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm256_mask_xor_epi64
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
name|test_mm256_maskz_xor_epi64
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
comment|//CHECK-LABEL: @test_mm256_maskz_xor_epi64
comment|//CHECK: xor<4 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_xor_epi64
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
name|test_mm_mask_xor_epi64
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
comment|//CHECK-LABEL: @test_mm_mask_xor_epi64
comment|//CHECK: xor<2 x i64> %{{.*}}, %{{.*}}
return|return
name|_mm_mask_xor_epi64
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
name|test_mm_maskz_xor_epi64
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
comment|//CHECK-LABEL: @test_mm_maskz_xor_epi64
comment|//CHECK: xor<2 x i64> %{{.*}}, %{{.*}}
comment|//CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_xor_epi64
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
name|test_mm256_cmp_ps_mask
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.256
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmp_ps_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_cmp_ps_mask
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.256
return|return
name|_mm256_mask_cmp_ps_mask
argument_list|(
name|m
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_ps_mask
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmp_ps_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_ps_mask
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.128
return|return
name|_mm_mask_cmp_ps_mask
argument_list|(
name|m
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_cmp_pd_mask
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.256
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmp_pd_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_cmp_pd_mask
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmp_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.256
return|return
name|_mm256_mask_cmp_pd_mask
argument_list|(
name|m
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_pd_mask
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmp_pd_mask
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_pd_mask
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cmp_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.128
return|return
name|_mm_mask_cmp_pd_mask
argument_list|(
name|m
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fmadd_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.128
return|return
name|_mm_mask_fmadd_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fmsub_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.128
return|return
name|_mm_mask_fmsub_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fmadd_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.pd.128
return|return
name|_mm_mask3_fmadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fnmadd_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.pd.128
return|return
name|_mm_mask3_fnmadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fmadd_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.128
return|return
name|_mm_maskz_fmadd_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fmsub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.128
return|return
name|_mm_maskz_fmsub_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fnmadd_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.128
return|return
name|_mm_maskz_fnmadd_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fnmsub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.128
return|return
name|_mm_maskz_fnmsub_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_fmadd_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.256
return|return
name|_mm256_mask_fmadd_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_fmsub_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.pd.256
return|return
name|_mm256_mask_fmsub_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask3_fmadd_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.pd.256
return|return
name|_mm256_mask3_fmadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask3_fnmadd_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.pd.256
return|return
name|_mm256_mask3_fnmadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_fmadd_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fmadd_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.256
return|return
name|_mm256_maskz_fmadd_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_fmsub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.256
return|return
name|_mm256_maskz_fmsub_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_fnmadd_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.256
return|return
name|_mm256_maskz_fnmadd_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_fnmsub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.pd.256
return|return
name|_mm256_maskz_fnmsub_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fmadd_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.128
return|return
name|_mm_mask_fmadd_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fmsub_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.128
return|return
name|_mm_mask_fmsub_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fmadd_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ps.128
return|return
name|_mm_mask3_fmadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fnmadd_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ps.128
return|return
name|_mm_mask3_fnmadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fmadd_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.128
return|return
name|_mm_maskz_fmadd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fmsub_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.128
return|return
name|_mm_maskz_fmsub_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fnmadd_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.128
return|return
name|_mm_maskz_fnmadd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fnmsub_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.128
return|return
name|_mm_maskz_fnmsub_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_fmadd_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.256
return|return
name|_mm256_mask_fmadd_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_fmsub_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmadd.ps.256
return|return
name|_mm256_mask_fmsub_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask3_fmadd_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ps.256
return|return
name|_mm256_mask3_fmadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask3_fnmadd_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmadd.ps.256
return|return
name|_mm256_mask3_fnmadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_fmadd_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fmadd_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.256
return|return
name|_mm256_maskz_fmadd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_fmsub_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.256
return|return
name|_mm256_maskz_fmsub_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_fnmadd_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.256
return|return
name|_mm256_maskz_fnmadd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_fnmsub_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmadd.ps.256
return|return
name|_mm256_maskz_fnmsub_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fmaddsub_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.128
return|return
name|_mm_mask_fmaddsub_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fmsubadd_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.128
return|return
name|_mm_mask_fmsubadd_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fmaddsub_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmaddsub.pd.128
return|return
name|_mm_mask3_fmaddsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fmaddsub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.pd.128
return|return
name|_mm_maskz_fmaddsub_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fmsubadd_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.pd.128
return|return
name|_mm_maskz_fmsubadd_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_fmaddsub_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.256
return|return
name|_mm256_mask_fmaddsub_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_fmsubadd_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.pd.256
return|return
name|_mm256_mask_fmsubadd_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask3_fmaddsub_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmaddsub.pd.256
return|return
name|_mm256_mask3_fmaddsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_fmaddsub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fmaddsub_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.pd.256
return|return
name|_mm256_maskz_fmaddsub_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_fmsubadd_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.pd.256
return|return
name|_mm256_maskz_fmsubadd_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fmaddsub_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.128
return|return
name|_mm_mask_fmaddsub_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fmsubadd_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.128
return|return
name|_mm_mask_fmsubadd_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fmaddsub_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmaddsub.ps.128
return|return
name|_mm_mask3_fmaddsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fmaddsub_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.ps.128
return|return
name|_mm_maskz_fmaddsub_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fmsubadd_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.ps.128
return|return
name|_mm_maskz_fmsubadd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_fmaddsub_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.256
return|return
name|_mm256_mask_fmaddsub_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_fmsubadd_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfmaddsub.ps.256
return|return
name|_mm256_mask_fmsubadd_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask3_fmaddsub_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmaddsub.ps.256
return|return
name|_mm256_mask3_fmaddsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_fmaddsub_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fmaddsub_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.ps.256
return|return
name|_mm256_maskz_fmaddsub_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_fmsubadd_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vfmaddsub.ps.256
return|return
name|_mm256_maskz_fmsubadd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fmsub_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.pd.128
return|return
name|_mm_mask3_fmsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask3_fmsub_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.pd.256
return|return
name|_mm256_mask3_fmsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fmsub_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.ps.128
return|return
name|_mm_mask3_fmsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask3_fmsub_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsub.ps.256
return|return
name|_mm256_mask3_fmsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fmsubadd_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsubadd.pd.128
return|return
name|_mm_mask3_fmsubadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask3_fmsubadd_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fmsubadd_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsubadd.pd.256
return|return
name|_mm256_mask3_fmsubadd_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fmsubadd_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsubadd.ps.128
return|return
name|_mm_mask3_fmsubadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask3_fmsubadd_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fmsubadd_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfmsubadd.ps.256
return|return
name|_mm256_mask3_fmsubadd_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fnmadd_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfnmadd.pd.128
return|return
name|_mm_mask_fnmadd_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_fnmadd_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fnmadd_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfnmadd.pd.256
return|return
name|_mm256_mask_fnmadd_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fnmadd_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfnmadd.ps.128
return|return
name|_mm_mask_fnmadd_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_fnmadd_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fnmadd_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfnmadd.ps.256
return|return
name|_mm256_mask_fnmadd_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fnmsub_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfnmsub.pd.128
return|return
name|_mm_mask_fnmsub_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask3_fnmsub_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.pd.128
return|return
name|_mm_mask3_fnmsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_fnmsub_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask.vfnmsub.pd.256
return|return
name|_mm256_mask_fnmsub_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask3_fnmsub_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256d
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fnmsub_pd
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.pd.256
return|return
name|_mm256_mask3_fnmsub_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fnmsub_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfnmsub.ps.128
return|return
name|_mm_mask_fnmsub_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask3_fnmsub_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask3_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.ps.128
return|return
name|_mm_mask3_fnmsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_fnmsub_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask.vfnmsub.ps.256
return|return
name|_mm256_mask_fnmsub_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask3_fnmsub_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256
name|__C
parameter_list|,
name|__mmask8
name|__U
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask3_fnmsub_ps
comment|// CHECK: @llvm.x86.avx512.mask3.vfnmsub.ps.256
return|return
name|_mm256_mask3_fnmsub_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
name|__U
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_add_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_add_pd
comment|// CHECK: fadd<2 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_add_pd
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
name|__m128d
name|test_mm_maskz_add_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_add_pd
comment|// CHECK: fadd<2 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_add_pd
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
name|__m256d
name|test_mm256_mask_add_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_add_pd
comment|// CHECK: fadd<4 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_add_pd
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
name|__m256d
name|test_mm256_maskz_add_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_add_pd
comment|// CHECK: fadd<4 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_add_pd
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
name|__m128
name|test_mm_mask_add_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_add_ps
comment|// CHECK: fadd<4 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_add_ps
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
name|__m128
name|test_mm_maskz_add_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_add_ps
comment|// CHECK: fadd<4 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_add_ps
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
name|__m256
name|test_mm256_mask_add_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_add_ps
comment|// CHECK: fadd<8 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_add_ps
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
name|__m256
name|test_mm256_maskz_add_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_add_ps
comment|// CHECK: fadd<8 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_add_ps
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
name|test_mm_mask_blend_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_blend_epi32
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_blend_epi32
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
name|test_mm256_mask_blend_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_blend_epi32
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_blend_epi32
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
name|__m128d
name|test_mm_mask_blend_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_blend_pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_blend_pd
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
name|__m256d
name|test_mm256_mask_blend_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_blend_pd
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_blend_pd
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
name|__m128
name|test_mm_mask_blend_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_blend_ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_blend_ps
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
name|__m256
name|test_mm256_mask_blend_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_blend_ps
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_blend_ps
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
name|test_mm_mask_blend_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_blend_epi64
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_blend_epi64
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
name|test_mm256_mask_blend_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__W
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_blend_epi64
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_blend_epi64
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
name|__m128d
name|test_mm_mask_compress_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_compress_pd
comment|// CHECK: @llvm.x86.avx512.mask.compress.pd.128
return|return
name|_mm_mask_compress_pd
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
name|__m128d
name|test_mm_maskz_compress_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_compress_pd
comment|// CHECK: @llvm.x86.avx512.mask.compress.pd.128
return|return
name|_mm_maskz_compress_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_compress_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_compress_pd
comment|// CHECK: @llvm.x86.avx512.mask.compress.pd.256
return|return
name|_mm256_mask_compress_pd
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
name|__m256d
name|test_mm256_maskz_compress_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_compress_pd
comment|// CHECK: @llvm.x86.avx512.mask.compress.pd.256
return|return
name|_mm256_maskz_compress_pd
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
name|test_mm_mask_compress_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_compress_epi64
comment|// CHECK: @llvm.x86.avx512.mask.compress.q.128
return|return
name|_mm_mask_compress_epi64
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
name|test_mm_maskz_compress_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_compress_epi64
comment|// CHECK: @llvm.x86.avx512.mask.compress.q.128
return|return
name|_mm_maskz_compress_epi64
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
name|test_mm256_mask_compress_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_compress_epi64
comment|// CHECK: @llvm.x86.avx512.mask.compress.q.256
return|return
name|_mm256_mask_compress_epi64
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
name|test_mm256_maskz_compress_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_compress_epi64
comment|// CHECK: @llvm.x86.avx512.mask.compress.q.256
return|return
name|_mm256_maskz_compress_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_compress_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_compress_ps
comment|// CHECK: @llvm.x86.avx512.mask.compress.ps.128
return|return
name|_mm_mask_compress_ps
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
name|__m128
name|test_mm_maskz_compress_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_compress_ps
comment|// CHECK: @llvm.x86.avx512.mask.compress.ps.128
return|return
name|_mm_maskz_compress_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_compress_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_compress_ps
comment|// CHECK: @llvm.x86.avx512.mask.compress.ps.256
return|return
name|_mm256_mask_compress_ps
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
name|__m256
name|test_mm256_maskz_compress_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_compress_ps
comment|// CHECK: @llvm.x86.avx512.mask.compress.ps.256
return|return
name|_mm256_maskz_compress_ps
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
name|test_mm_mask_compress_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_compress_epi32
comment|// CHECK: @llvm.x86.avx512.mask.compress.d.128
return|return
name|_mm_mask_compress_epi32
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
name|test_mm_maskz_compress_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_compress_epi32
comment|// CHECK: @llvm.x86.avx512.mask.compress.d.128
return|return
name|_mm_maskz_compress_epi32
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
name|test_mm256_mask_compress_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_compress_epi32
comment|// CHECK: @llvm.x86.avx512.mask.compress.d.256
return|return
name|_mm256_mask_compress_epi32
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
name|test_mm256_maskz_compress_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_compress_epi32
comment|// CHECK: @llvm.x86.avx512.mask.compress.d.256
return|return
name|_mm256_maskz_compress_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_compressstoreu_pd
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_compressstoreu_pd
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.pd.128
return|return
name|_mm_mask_compressstoreu_pd
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
name|test_mm256_mask_compressstoreu_pd
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_compressstoreu_pd
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.pd.256
return|return
name|_mm256_mask_compressstoreu_pd
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
name|test_mm_mask_compressstoreu_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_compressstoreu_epi64
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.q.128
return|return
name|_mm_mask_compressstoreu_epi64
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
name|test_mm256_mask_compressstoreu_epi64
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_compressstoreu_epi64
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.q.256
return|return
name|_mm256_mask_compressstoreu_epi64
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
name|test_mm_mask_compressstoreu_ps
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_compressstoreu_ps
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.ps.128
return|return
name|_mm_mask_compressstoreu_ps
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
name|test_mm256_mask_compressstoreu_ps
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_compressstoreu_ps
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.ps.256
return|return
name|_mm256_mask_compressstoreu_ps
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
name|test_mm_mask_compressstoreu_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_compressstoreu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.d.128
return|return
name|_mm_mask_compressstoreu_epi32
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
name|test_mm256_mask_compressstoreu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_compressstoreu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.compress.store.d.256
return|return
name|_mm256_mask_compressstoreu_epi32
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
name|__m128d
name|test_mm_mask_cvtepi32_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepi32_pd
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: sitofp<2 x i32> %{{.*}} to<2 x double>
comment|// CHECK: select<2 x i1> {{.*}},<2 x double> {{.*}},<2 x double> {{.*}}
return|return
name|_mm_mask_cvtepi32_pd
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
name|__m128d
name|test_mm_maskz_cvtepi32_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi32_pd
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: sitofp<2 x i32> %{{.*}} to<2 x double>
comment|// CHECK: select<2 x i1> {{.*}},<2 x double> {{.*}},<2 x double> {{.*}}
return|return
name|_mm_maskz_cvtepi32_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_cvtepi32_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi32_pd
comment|// CHECK: sitofp<4 x i32> %{{.*}} to<4 x double>
comment|// CHECK: select<4 x i1> {{.*}},<4 x double> {{.*}},<4 x double> {{.*}}
return|return
name|_mm256_mask_cvtepi32_pd
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
name|__m256d
name|test_mm256_maskz_cvtepi32_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi32_pd
comment|// CHECK: sitofp<4 x i32> %{{.*}} to<4 x double>
comment|// CHECK: select<4 x i1> {{.*}},<4 x double> {{.*}},<4 x double> {{.*}}
return|return
name|_mm256_maskz_cvtepi32_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_cvtepi32_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepi32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2ps.128
return|return
name|_mm_mask_cvtepi32_ps
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
name|__m128
name|test_mm_maskz_cvtepi32_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2ps.128
return|return
name|_mm_maskz_cvtepi32_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_cvtepi32_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2ps.256
return|return
name|_mm256_mask_cvtepi32_ps
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
name|__m256
name|test_mm256_maskz_cvtepi32_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2ps.256
return|return
name|_mm256_maskz_cvtepi32_ps
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
name|test_mm_mask_cvtpd_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2dq.128
return|return
name|_mm_mask_cvtpd_epi32
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
name|test_mm_maskz_cvtpd_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2dq.128
return|return
name|_mm_maskz_cvtpd_epi32
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
name|test_mm256_mask_cvtpd_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2dq.256
return|return
name|_mm256_mask_cvtpd_epi32
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
name|test_mm256_maskz_cvtpd_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2dq.256
return|return
name|_mm256_maskz_cvtpd_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_cvtpd_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtpd_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps
return|return
name|_mm_mask_cvtpd_ps
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
name|__m128
name|test_mm_maskz_cvtpd_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtpd_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps
return|return
name|_mm_maskz_cvtpd_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_mask_cvtpd_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtpd_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps.256
return|return
name|_mm256_mask_cvtpd_ps
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
name|__m128
name|test_mm256_maskz_cvtpd_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtpd_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2ps.256
return|return
name|_mm256_maskz_cvtpd_ps
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
name|test_mm_cvtpd_epu32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.128
return|return
name|_mm_cvtpd_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtpd_epu32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.128
return|return
name|_mm_mask_cvtpd_epu32
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
name|test_mm_maskz_cvtpd_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.128
return|return
name|_mm_maskz_cvtpd_epu32
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
name|test_mm256_cvtpd_epu32
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.256
return|return
name|_mm256_cvtpd_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtpd_epu32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.256
return|return
name|_mm256_mask_cvtpd_epu32
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
name|test_mm256_maskz_cvtpd_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2udq.256
return|return
name|_mm256_maskz_cvtpd_epu32
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
name|test_mm_mask_cvtps_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2dq.128
return|return
name|_mm_mask_cvtps_epi32
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
name|test_mm_maskz_cvtps_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2dq.128
return|return
name|_mm_maskz_cvtps_epi32
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
name|test_mm256_mask_cvtps_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2dq.256
return|return
name|_mm256_mask_cvtps_epi32
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
name|test_mm256_maskz_cvtps_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2dq.256
return|return
name|_mm256_maskz_cvtps_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_cvtps_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.128
return|return
name|_mm_mask_cvtps_pd
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
name|__m128d
name|test_mm_maskz_cvtps_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.128
return|return
name|_mm_maskz_cvtps_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_cvtps_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.256
return|return
name|_mm256_mask_cvtps_pd
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
name|__m256d
name|test_mm256_maskz_cvtps_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtps_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2pd.256
return|return
name|_mm256_maskz_cvtps_pd
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
name|test_mm_cvtps_epu32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.128
return|return
name|_mm_cvtps_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtps_epu32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.128
return|return
name|_mm_mask_cvtps_epu32
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
name|test_mm_maskz_cvtps_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.128
return|return
name|_mm_maskz_cvtps_epu32
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
name|test_mm256_cvtps_epu32
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.256
return|return
name|_mm256_cvtps_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtps_epu32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.256
return|return
name|_mm256_mask_cvtps_epu32
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
name|test_mm256_maskz_cvtps_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2udq.256
return|return
name|_mm256_maskz_cvtps_epu32
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
name|test_mm_mask_cvttpd_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvttpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2dq.128
return|return
name|_mm_mask_cvttpd_epi32
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
name|test_mm_maskz_cvttpd_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2dq.128
return|return
name|_mm_maskz_cvttpd_epi32
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
name|test_mm256_mask_cvttpd_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2dq.256
return|return
name|_mm256_mask_cvttpd_epi32
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
name|test_mm256_maskz_cvttpd_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttpd_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2dq.256
return|return
name|_mm256_maskz_cvttpd_epi32
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
name|test_mm_cvttpd_epu32
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.128
return|return
name|_mm_cvttpd_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttpd_epu32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvttpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.128
return|return
name|_mm_mask_cvttpd_epu32
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
name|test_mm_maskz_cvttpd_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.128
return|return
name|_mm_maskz_cvttpd_epu32
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
name|test_mm256_cvttpd_epu32
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.256
return|return
name|_mm256_cvttpd_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvttpd_epu32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.256
return|return
name|_mm256_mask_cvttpd_epu32
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
name|test_mm256_maskz_cvttpd_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttpd_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2udq.256
return|return
name|_mm256_maskz_cvttpd_epu32
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
name|test_mm_mask_cvttps_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvttps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2dq.128
return|return
name|_mm_mask_cvttps_epi32
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
name|test_mm_maskz_cvttps_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2dq.128
return|return
name|_mm_maskz_cvttps_epi32
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
name|test_mm256_mask_cvttps_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2dq.256
return|return
name|_mm256_mask_cvttps_epi32
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
name|test_mm256_maskz_cvttps_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttps_epi32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2dq.256
return|return
name|_mm256_maskz_cvttps_epi32
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
name|test_mm_cvttps_epu32
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.128
return|return
name|_mm_cvttps_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttps_epu32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvttps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.128
return|return
name|_mm_mask_cvttps_epu32
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
name|test_mm_maskz_cvttps_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.128
return|return
name|_mm_maskz_cvttps_epu32
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
name|test_mm256_cvttps_epu32
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.256
return|return
name|_mm256_cvttps_epu32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvttps_epu32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.256
return|return
name|_mm256_mask_cvttps_epu32
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
name|test_mm256_maskz_cvttps_epu32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttps_epu32
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2udq.256
return|return
name|_mm256_maskz_cvttps_epu32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtepu32_pd
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepu32_pd
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: uitofp<2 x i32> %{{.*}} to<2 x double>
return|return
name|_mm_cvtepu32_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_cvtepu32_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepu32_pd
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: uitofp<2 x i32> %{{.*}} to<2 x double>
comment|// CHECK: select<2 x i1> {{.*}},<2 x double> {{.*}},<2 x double> {{.*}}
return|return
name|_mm_mask_cvtepu32_pd
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
name|__m128d
name|test_mm_maskz_cvtepu32_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu32_pd
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: uitofp<2 x i32> %{{.*}} to<2 x double>
comment|// CHECK: select<2 x i1> {{.*}},<2 x double> {{.*}},<2 x double> {{.*}}
return|return
name|_mm_maskz_cvtepu32_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_cvtepu32_pd
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepu32_pd
comment|// CHECK: uitofp<4 x i32> %{{.*}} to<4 x double>
return|return
name|_mm256_cvtepu32_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_cvtepu32_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu32_pd
comment|// CHECK: uitofp<4 x i32> %{{.*}} to<4 x double>
comment|// CHECK: select<4 x i1> {{.*}},<4 x double> {{.*}},<4 x double> {{.*}}
return|return
name|_mm256_mask_cvtepu32_pd
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
name|__m256d
name|test_mm256_maskz_cvtepu32_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu32_pd
comment|// CHECK: uitofp<4 x i32> %{{.*}} to<4 x double>
comment|// CHECK: select<4 x i1> {{.*}},<4 x double> {{.*}},<4 x double> {{.*}}
return|return
name|_mm256_maskz_cvtepu32_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtepu32_ps
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.128
return|return
name|_mm_cvtepu32_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_cvtepu32_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.128
return|return
name|_mm_mask_cvtepu32_ps
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
name|__m128
name|test_mm_maskz_cvtepu32_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.128
return|return
name|_mm_maskz_cvtepu32_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_cvtepu32_ps
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.256
return|return
name|_mm256_cvtepu32_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_cvtepu32_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.256
return|return
name|_mm256_mask_cvtepu32_ps
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
name|__m256
name|test_mm256_maskz_cvtepu32_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu32_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2ps.256
return|return
name|_mm256_maskz_cvtepu32_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_div_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_div_pd
comment|// CHECK: fdiv<2 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_div_pd
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
name|__m128d
name|test_mm_maskz_div_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_div_pd
comment|// CHECK: fdiv<2 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_div_pd
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
name|__m256d
name|test_mm256_mask_div_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_div_pd
comment|// CHECK: fdiv<4 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_div_pd
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
name|__m256d
name|test_mm256_maskz_div_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_div_pd
comment|// CHECK: fdiv<4 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_div_pd
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
name|__m128
name|test_mm_mask_div_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_div_ps
comment|// CHECK: fdiv<4 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_div_ps
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
name|__m128
name|test_mm_maskz_div_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_div_ps
comment|// CHECK: fdiv<4 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_div_ps
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
name|__m256
name|test_mm256_mask_div_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_div_ps
comment|// CHECK: fdiv<8 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_div_ps
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
name|__m256
name|test_mm256_maskz_div_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_div_ps
comment|// CHECK: fdiv<8 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_div_ps
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
name|__m128d
name|test_mm_mask_expand_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_expand_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.pd.128
return|return
name|_mm_mask_expand_pd
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
name|__m128d
name|test_mm_maskz_expand_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_expand_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.pd.128
return|return
name|_mm_maskz_expand_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_expand_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_expand_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.pd.256
return|return
name|_mm256_mask_expand_pd
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
name|__m256d
name|test_mm256_maskz_expand_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_expand_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.pd.256
return|return
name|_mm256_maskz_expand_pd
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
name|test_mm_mask_expand_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_expand_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.q.128
return|return
name|_mm_mask_expand_epi64
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
name|test_mm_maskz_expand_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_expand_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.q.128
return|return
name|_mm_maskz_expand_epi64
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
name|test_mm256_mask_expand_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_expand_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.q.256
return|return
name|_mm256_mask_expand_epi64
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
name|test_mm256_maskz_expand_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_expand_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.q.256
return|return
name|_mm256_maskz_expand_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_expandloadu_pd
parameter_list|(
name|__m128d
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
comment|// CHECK-LABEL: @test_mm_mask_expandloadu_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.pd.128
return|return
name|_mm_mask_expandloadu_pd
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
name|__m128d
name|test_mm_maskz_expandloadu_pd
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
comment|// CHECK-LABEL: @test_mm_maskz_expandloadu_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.pd.128
return|return
name|_mm_maskz_expandloadu_pd
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_expandloadu_pd
parameter_list|(
name|__m256d
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
comment|// CHECK-LABEL: @test_mm256_mask_expandloadu_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.pd.256
return|return
name|_mm256_mask_expandloadu_pd
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
name|__m256d
name|test_mm256_maskz_expandloadu_pd
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
comment|// CHECK-LABEL: @test_mm256_maskz_expandloadu_pd
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.pd.256
return|return
name|_mm256_maskz_expandloadu_pd
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
name|test_mm_mask_expandloadu_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_expandloadu_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.q.128
return|return
name|_mm_mask_expandloadu_epi64
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
name|test_mm_maskz_expandloadu_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_expandloadu_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.q.128
return|return
name|_mm_maskz_expandloadu_epi64
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
name|test_mm256_mask_expandloadu_epi64
parameter_list|(
name|__m256i
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
comment|// CHECK-LABEL: @test_mm256_mask_expandloadu_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.q.256
return|return
name|_mm256_mask_expandloadu_epi64
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
name|test_mm256_maskz_expandloadu_epi64
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
comment|// CHECK-LABEL: @test_mm256_maskz_expandloadu_epi64
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.q.256
return|return
name|_mm256_maskz_expandloadu_epi64
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_expandloadu_ps
parameter_list|(
name|__m128
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
comment|// CHECK-LABEL: @test_mm_mask_expandloadu_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.ps.128
return|return
name|_mm_mask_expandloadu_ps
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
name|__m128
name|test_mm_maskz_expandloadu_ps
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
comment|// CHECK-LABEL: @test_mm_maskz_expandloadu_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.ps.128
return|return
name|_mm_maskz_expandloadu_ps
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_expandloadu_ps
parameter_list|(
name|__m256
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
comment|// CHECK-LABEL: @test_mm256_mask_expandloadu_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.ps.256
return|return
name|_mm256_mask_expandloadu_ps
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
name|__m256
name|test_mm256_maskz_expandloadu_ps
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
comment|// CHECK-LABEL: @test_mm256_maskz_expandloadu_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.ps.256
return|return
name|_mm256_maskz_expandloadu_ps
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
name|test_mm_mask_expandloadu_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_expandloadu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.d.128
return|return
name|_mm_mask_expandloadu_epi32
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
name|test_mm_maskz_expandloadu_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_expandloadu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.d.128
return|return
name|_mm_maskz_expandloadu_epi32
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
name|test_mm256_mask_expandloadu_epi32
parameter_list|(
name|__m256i
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
comment|// CHECK-LABEL: @test_mm256_mask_expandloadu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.d.256
return|return
name|_mm256_mask_expandloadu_epi32
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
name|test_mm256_maskz_expandloadu_epi32
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
comment|// CHECK-LABEL: @test_mm256_maskz_expandloadu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.load.d.256
return|return
name|_mm256_maskz_expandloadu_epi32
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_expand_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_expand_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.ps.128
return|return
name|_mm_mask_expand_ps
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
name|__m128
name|test_mm_maskz_expand_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_expand_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.ps.128
return|return
name|_mm_maskz_expand_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_expand_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_expand_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.ps.256
return|return
name|_mm256_mask_expand_ps
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
name|__m256
name|test_mm256_maskz_expand_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_expand_ps
comment|// CHECK: @llvm.x86.avx512.mask.expand.ps.256
return|return
name|_mm256_maskz_expand_ps
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
name|test_mm_mask_expand_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_expand_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.d.128
return|return
name|_mm_mask_expand_epi32
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
name|test_mm_maskz_expand_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_expand_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.d.128
return|return
name|_mm_maskz_expand_epi32
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
name|test_mm256_mask_expand_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_expand_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.d.256
return|return
name|_mm256_mask_expand_epi32
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
name|test_mm256_maskz_expand_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_expand_epi32
comment|// CHECK: @llvm.x86.avx512.mask.expand.d.256
return|return
name|_mm256_maskz_expand_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_getexp_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getexp_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.128
return|return
name|_mm_getexp_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_getexp_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_getexp_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.128
return|return
name|_mm_mask_getexp_pd
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
name|__m128d
name|test_mm_maskz_getexp_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_getexp_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.128
return|return
name|_mm_maskz_getexp_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_getexp_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_getexp_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.256
return|return
name|_mm256_getexp_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_getexp_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_getexp_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.256
return|return
name|_mm256_mask_getexp_pd
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
name|__m256d
name|test_mm256_maskz_getexp_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_getexp_pd
comment|// CHECK: @llvm.x86.avx512.mask.getexp.pd.256
return|return
name|_mm256_maskz_getexp_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_getexp_ps
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getexp_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.128
return|return
name|_mm_getexp_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_getexp_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_getexp_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.128
return|return
name|_mm_mask_getexp_ps
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
name|__m128
name|test_mm_maskz_getexp_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_getexp_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.128
return|return
name|_mm_maskz_getexp_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_getexp_ps
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_getexp_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.256
return|return
name|_mm256_getexp_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_getexp_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_getexp_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.256
return|return
name|_mm256_mask_getexp_ps
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
name|__m256
name|test_mm256_maskz_getexp_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_getexp_ps
comment|// CHECK: @llvm.x86.avx512.mask.getexp.ps.256
return|return
name|_mm256_maskz_getexp_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_max_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_max_pd
comment|// CHECK: @llvm.x86.sse2.max.pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_max_pd
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
name|__m128d
name|test_mm_maskz_max_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_max_pd
comment|// CHECK: @llvm.x86.sse2.max.pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_max_pd
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
name|__m256d
name|test_mm256_mask_max_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_pd
comment|// CHECK: @llvm.x86.avx.max.pd.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_max_pd
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
name|__m256d
name|test_mm256_maskz_max_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_pd
comment|// CHECK: @llvm.x86.avx.max.pd.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_max_pd
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
name|__m128
name|test_mm_mask_max_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_max_ps
comment|// CHECK: @llvm.x86.sse.max.ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_max_ps
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
name|__m128
name|test_mm_maskz_max_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_max_ps
comment|// CHECK: @llvm.x86.sse.max.ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_max_ps
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
name|__m256
name|test_mm256_mask_max_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_ps
comment|// CHECK: @llvm.x86.avx.max.ps.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_max_ps
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
name|__m256
name|test_mm256_maskz_max_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_ps
comment|// CHECK: @llvm.x86.avx.max.ps.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_max_ps
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
name|__m128d
name|test_mm_mask_min_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_min_pd
comment|// CHECK: @llvm.x86.sse2.min.pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_min_pd
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
name|__m128d
name|test_mm_maskz_min_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_min_pd
comment|// CHECK: @llvm.x86.sse2.min.pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_min_pd
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
name|__m256d
name|test_mm256_mask_min_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_pd
comment|// CHECK: @llvm.x86.avx.min.pd.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_min_pd
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
name|__m256d
name|test_mm256_maskz_min_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_pd
comment|// CHECK: @llvm.x86.avx.min.pd.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_min_pd
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
name|__m128
name|test_mm_mask_min_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_min_ps
comment|// CHECK: @llvm.x86.sse.min.ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_min_ps
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
name|__m128
name|test_mm_maskz_min_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_min_ps
comment|// CHECK: @llvm.x86.sse.min.ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_min_ps
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
name|__m256
name|test_mm256_mask_min_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_ps
comment|// CHECK: @llvm.x86.avx.min.ps.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_min_ps
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
name|__m256
name|test_mm256_maskz_min_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_ps
comment|// CHECK: @llvm.x86.avx.min.ps.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_min_ps
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
name|__m128d
name|test_mm_mask_mul_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_mul_pd
comment|// CHECK: fmul<2 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_mul_pd
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
name|__m128d
name|test_mm_maskz_mul_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mul_pd
comment|// CHECK: fmul<2 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_mul_pd
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
name|__m256d
name|test_mm256_mask_mul_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mul_pd
comment|// CHECK: fmul<4 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_mul_pd
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
name|__m256d
name|test_mm256_maskz_mul_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mul_pd
comment|// CHECK: fmul<4 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_mul_pd
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
name|__m128
name|test_mm_mask_mul_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_mul_ps
comment|// CHECK: fmul<4 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_mul_ps
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
name|__m128
name|test_mm_maskz_mul_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mul_ps
comment|// CHECK: fmul<4 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_mul_ps
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
name|__m256
name|test_mm256_mask_mul_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mul_ps
comment|// CHECK: fmul<8 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_mul_ps
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
name|__m256
name|test_mm256_maskz_mul_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mul_ps
comment|// CHECK: fmul<8 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_mul_ps
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
name|test_mm_mask_abs_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_abs_epi32
comment|// CHECK: @llvm.x86.ssse3.pabs.d.128
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_abs_epi32
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
name|test_mm_maskz_abs_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_abs_epi32
comment|// CHECK: @llvm.x86.ssse3.pabs.d.128
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_abs_epi32
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
name|test_mm256_mask_abs_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_abs_epi32
comment|// CHECK: @llvm.x86.avx2.pabs.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_abs_epi32
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
name|test_mm256_maskz_abs_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_abs_epi32
comment|// CHECK: @llvm.x86.avx2.pabs.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_abs_epi32
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
name|test_mm_abs_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_abs_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pabs.q.128
return|return
name|_mm_abs_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_abs_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_abs_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pabs.q.128
return|return
name|_mm_mask_abs_epi64
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
name|test_mm_maskz_abs_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_abs_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pabs.q.128
return|return
name|_mm_maskz_abs_epi64
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
name|test_mm256_abs_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_abs_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pabs.q.256
return|return
name|_mm256_abs_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_abs_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_abs_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pabs.q.256
return|return
name|_mm256_mask_abs_epi64
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
name|test_mm256_maskz_abs_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_abs_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pabs.q.256
return|return
name|_mm256_maskz_abs_epi64
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
name|test_mm_maskz_max_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_max_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i32> [[RES]],<4 x i32> {{.*}}
return|return
name|_mm_maskz_max_epi32
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
name|test_mm_mask_max_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_max_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i32> [[RES]],<4 x i32> {{.*}}
return|return
name|_mm_mask_max_epi32
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
name|test_mm256_maskz_max_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i32> [[RES]],<8 x i32> {{.*}}
return|return
name|_mm256_maskz_max_epi32
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
name|test_mm256_mask_max_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i32> [[RES]],<8 x i32> {{.*}}
return|return
name|_mm256_mask_max_epi32
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
name|test_mm_maskz_max_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_max_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
comment|// CHECK:       select<2 x i1> {{.*}},<2 x i64> [[RES]],<2 x i64> {{.*}}
return|return
name|_mm_maskz_max_epi64
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
name|test_mm_mask_max_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_max_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
comment|// CHECK:       select<2 x i1> {{.*}},<2 x i64> [[RES]],<2 x i64> {{.*}}
return|return
name|_mm_mask_max_epi64
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
name|test_mm_max_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_max_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
return|return
name|_mm_max_epi64
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
name|test_mm256_maskz_max_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i64> [[RES]],<4 x i64> {{.*}}
return|return
name|_mm256_maskz_max_epi64
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
name|test_mm256_mask_max_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i64> [[RES]],<4 x i64> {{.*}}
return|return
name|_mm256_mask_max_epi64
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
name|test_mm256_max_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_max_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
return|return
name|_mm256_max_epi64
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
name|test_mm_maskz_max_epu32
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
comment|// CHECK-LABEL: @test_mm_maskz_max_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i32> [[RES]],<4 x i32> {{.*}}
return|return
name|_mm_maskz_max_epu32
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
name|test_mm_mask_max_epu32
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
comment|// CHECK-LABEL: @test_mm_mask_max_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i32> [[RES]],<4 x i32> {{.*}}
return|return
name|_mm_mask_max_epu32
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
name|test_mm256_maskz_max_epu32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i32> [[RES]],<8 x i32> {{.*}}
return|return
name|_mm256_maskz_max_epu32
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
name|test_mm256_mask_max_epu32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i32> [[RES]],<8 x i32> {{.*}}
return|return
name|_mm256_mask_max_epu32
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
name|test_mm_maskz_max_epu64
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
comment|// CHECK-LABEL: @test_mm_maskz_max_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
comment|// CHECK:       select<2 x i1> {{.*}},<2 x i64> [[RES]],<2 x i64> {{.*}}
return|return
name|_mm_maskz_max_epu64
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
name|test_mm_max_epu64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_max_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
return|return
name|_mm_max_epu64
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
name|test_mm_mask_max_epu64
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
comment|// CHECK-LABEL: @test_mm_mask_max_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
comment|// CHECK:       select<2 x i1> {{.*}},<2 x i64> [[RES]],<2 x i64> {{.*}}
return|return
name|_mm_mask_max_epu64
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
name|test_mm256_maskz_max_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_max_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i64> [[RES]],<4 x i64> {{.*}}
return|return
name|_mm256_maskz_max_epu64
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
name|test_mm256_max_epu64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_max_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
return|return
name|_mm256_max_epu64
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
name|test_mm256_mask_max_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_max_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i64> [[RES]],<4 x i64> {{.*}}
return|return
name|_mm256_mask_max_epu64
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
name|test_mm_maskz_min_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_min_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp slt<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i32> [[RES]],<4 x i32> {{.*}}
return|return
name|_mm_maskz_min_epi32
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
name|test_mm_mask_min_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_min_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp slt<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i32> [[RES]],<4 x i32> {{.*}}
return|return
name|_mm_mask_min_epi32
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
name|test_mm256_maskz_min_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp slt<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i32> [[RES]],<8 x i32> {{.*}}
return|return
name|_mm256_maskz_min_epi32
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
name|test_mm256_mask_min_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp slt<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i32> [[RES]],<8 x i32> {{.*}}
return|return
name|_mm256_mask_min_epi32
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
name|test_mm_min_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_min_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp slt<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
return|return
name|_mm_min_epi64
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
name|test_mm_mask_min_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_min_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp slt<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
comment|// CHECK:       select<2 x i1> {{.*}},<2 x i64> [[RES]],<2 x i64> {{.*}}
return|return
name|_mm_mask_min_epi64
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
name|test_mm_maskz_min_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_min_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp slt<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
comment|// CHECK:       select<2 x i1> {{.*}},<2 x i64> [[RES]],<2 x i64> {{.*}}
return|return
name|_mm_maskz_min_epi64
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
name|test_mm256_min_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_min_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp slt<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
return|return
name|_mm256_min_epi64
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
name|test_mm256_mask_min_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp slt<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i64> [[RES]],<4 x i64> {{.*}}
return|return
name|_mm256_mask_min_epi64
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
name|test_mm256_maskz_min_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_epi64
comment|// CHECK:       [[CMP:%.*]] = icmp slt<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i64> [[RES]],<4 x i64> {{.*}}
return|return
name|_mm256_maskz_min_epi64
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
name|test_mm_maskz_min_epu32
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
comment|// CHECK-LABEL: @test_mm_maskz_min_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ult<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i32> [[RES]],<4 x i32> {{.*}}
return|return
name|_mm_maskz_min_epu32
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
name|test_mm_mask_min_epu32
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
comment|// CHECK-LABEL: @test_mm_mask_min_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ult<4 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i32> [[X]],<4 x i32> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i32> [[RES]],<4 x i32> {{.*}}
return|return
name|_mm_mask_min_epu32
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
name|test_mm256_maskz_min_epu32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ult<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i32> [[RES]],<8 x i32> {{.*}}
return|return
name|_mm256_maskz_min_epu32
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
name|test_mm256_mask_min_epu32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ult<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
comment|// CHECK:       select<8 x i1> {{.*}},<8 x i32> [[RES]],<8 x i32> {{.*}}
return|return
name|_mm256_mask_min_epu32
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
name|test_mm_min_epu64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_min_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ult<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
return|return
name|_mm_min_epu64
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
name|test_mm_mask_min_epu64
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
comment|// CHECK-LABEL: @test_mm_mask_min_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ult<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
comment|// CHECK:       select<2 x i1> {{.*}},<2 x i64> [[RES]],<2 x i64> {{.*}}
return|return
name|_mm_mask_min_epu64
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
name|test_mm_maskz_min_epu64
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
comment|// CHECK-LABEL: @test_mm_maskz_min_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ult<2 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<2 x i1> [[CMP]],<2 x i64> [[X]],<2 x i64> [[Y]]
comment|// CHECK:       select<2 x i1> {{.*}},<2 x i64> [[RES]],<2 x i64> {{.*}}
return|return
name|_mm_maskz_min_epu64
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
name|test_mm256_min_epu64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_min_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ult<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
return|return
name|_mm256_min_epu64
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
name|test_mm256_mask_min_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_min_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ult<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i64> [[RES]],<4 x i64> {{.*}}
return|return
name|_mm256_mask_min_epu64
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
name|test_mm256_maskz_min_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_min_epu64
comment|// CHECK:       [[CMP:%.*]] = icmp ult<4 x i64> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  [[RES:%.*]] = select<4 x i1> [[CMP]],<4 x i64> [[X]],<4 x i64> [[Y]]
comment|// CHECK:       select<4 x i1> {{.*}},<4 x i64> [[RES]],<4 x i64> {{.*}}
return|return
name|_mm256_maskz_min_epu64
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
name|__m128d
name|test_mm_roundscale_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_roundscale_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.128
return|return
name|_mm_roundscale_pd
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_roundscale_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_roundscale_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.128
return|return
name|_mm_mask_roundscale_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_roundscale_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_roundscale_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.128
return|return
name|_mm_maskz_roundscale_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_roundscale_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_roundscale_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.256
return|return
name|_mm256_roundscale_pd
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_roundscale_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_roundscale_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.256
return|return
name|_mm256_mask_roundscale_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_roundscale_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_roundscale_pd
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.pd.256
return|return
name|_mm256_maskz_roundscale_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_roundscale_ps
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_roundscale_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.128
return|return
name|_mm_roundscale_ps
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_roundscale_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_roundscale_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.128
return|return
name|_mm_mask_roundscale_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_roundscale_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_roundscale_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.128
return|return
name|_mm_maskz_roundscale_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_roundscale_ps
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_roundscale_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.256
return|return
name|_mm256_roundscale_ps
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_roundscale_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_roundscale_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.256
return|return
name|_mm256_mask_roundscale_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_roundscale_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_roundscale_ps
comment|// CHECK: @llvm.x86.avx512.mask.rndscale.ps.256
return|return
name|_mm256_maskz_roundscale_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_scalef_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_scalef_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.128
return|return
name|_mm_scalef_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_scalef_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_scalef_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.128
return|return
name|_mm_mask_scalef_pd
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
name|__m128d
name|test_mm_maskz_scalef_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_scalef_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.128
return|return
name|_mm_maskz_scalef_pd
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
name|__m256d
name|test_mm256_scalef_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_scalef_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.256
return|return
name|_mm256_scalef_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_scalef_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_scalef_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.256
return|return
name|_mm256_mask_scalef_pd
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
name|__m256d
name|test_mm256_maskz_scalef_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_scalef_pd
comment|// CHECK: @llvm.x86.avx512.mask.scalef.pd.256
return|return
name|_mm256_maskz_scalef_pd
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
name|__m128
name|test_mm_scalef_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_scalef_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.128
return|return
name|_mm_scalef_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_scalef_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_scalef_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.128
return|return
name|_mm_mask_scalef_ps
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
name|__m128
name|test_mm_maskz_scalef_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_scalef_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.128
return|return
name|_mm_maskz_scalef_ps
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
name|__m256
name|test_mm256_scalef_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_scalef_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.256
return|return
name|_mm256_scalef_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_scalef_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_scalef_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.256
return|return
name|_mm256_mask_scalef_ps
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
name|__m256
name|test_mm256_maskz_scalef_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_scalef_ps
comment|// CHECK: @llvm.x86.avx512.mask.scalef.ps.256
return|return
name|_mm256_maskz_scalef_ps
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
name|void
name|test_mm_i64scatter_pd
parameter_list|(
name|double
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_i64scatter_pd
comment|// CHECK: @llvm.x86.avx512.scatterdiv2.df
return|return
name|_mm_i64scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_i64scatter_pd
parameter_list|(
name|double
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i64scatter_pd
comment|// CHECK: @llvm.x86.avx512.scatterdiv2.df
return|return
name|_mm_mask_i64scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_i64scatter_epi64
parameter_list|(
name|long
name|long
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_i64scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scatterdiv2.di
return|return
name|_mm_i64scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_i64scatter_epi64
parameter_list|(
name|long
name|long
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i64scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scatterdiv2.di
return|return
name|_mm_mask_i64scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_i64scatter_pd
parameter_list|(
name|double
modifier|*
name|__addr
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m256d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_i64scatter_pd
comment|// CHECK: @llvm.x86.avx512.scatterdiv4.df
return|return
name|_mm256_i64scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_i64scatter_pd
parameter_list|(
name|double
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m256d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i64scatter_pd
comment|// CHECK: @llvm.x86.avx512.scatterdiv4.df
return|return
name|_mm256_mask_i64scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_i64scatter_epi64
parameter_list|(
name|long
name|long
modifier|*
name|__addr
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m256i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_i64scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scatterdiv4.di
return|return
name|_mm256_i64scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_i64scatter_epi64
parameter_list|(
name|long
name|long
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m256i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i64scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scatterdiv4.di
return|return
name|_mm256_mask_i64scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_i64scatter_ps
parameter_list|(
name|float
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_i64scatter_ps
comment|// CHECK: @llvm.x86.avx512.scatterdiv4.sf
return|return
name|_mm_i64scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_i64scatter_ps
parameter_list|(
name|float
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i64scatter_ps
comment|// CHECK: @llvm.x86.avx512.scatterdiv4.sf
return|return
name|_mm_mask_i64scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_i64scatter_epi32
parameter_list|(
name|int
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_i64scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scatterdiv4.si
return|return
name|_mm_i64scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_i64scatter_epi32
parameter_list|(
name|int
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i64scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scatterdiv4.si
return|return
name|_mm_mask_i64scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_i64scatter_ps
parameter_list|(
name|float
modifier|*
name|__addr
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m128
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_i64scatter_ps
comment|// CHECK: @llvm.x86.avx512.scatterdiv8.sf
return|return
name|_mm256_i64scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_i64scatter_ps
parameter_list|(
name|float
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m128
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i64scatter_ps
comment|// CHECK: @llvm.x86.avx512.scatterdiv8.sf
return|return
name|_mm256_mask_i64scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_i64scatter_epi32
parameter_list|(
name|int
modifier|*
name|__addr
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_i64scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scatterdiv8.si
return|return
name|_mm256_i64scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_i64scatter_epi32
parameter_list|(
name|int
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i64scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scatterdiv8.si
return|return
name|_mm256_mask_i64scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_i32scatter_pd
parameter_list|(
name|double
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_i32scatter_pd
comment|// CHECK: @llvm.x86.avx512.scattersiv2.df
return|return
name|_mm_i32scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_i32scatter_pd
parameter_list|(
name|double
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i32scatter_pd
comment|// CHECK: @llvm.x86.avx512.scattersiv2.df
return|return
name|_mm_mask_i32scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_i32scatter_epi64
parameter_list|(
name|long
name|long
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_i32scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scattersiv2.di
return|return
name|_mm_i32scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_i32scatter_epi64
parameter_list|(
name|long
name|long
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i32scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scattersiv2.di
return|return
name|_mm_mask_i32scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_i32scatter_pd
parameter_list|(
name|double
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m256d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_i32scatter_pd
comment|// CHECK: @llvm.x86.avx512.scattersiv4.df
return|return
name|_mm256_i32scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_i32scatter_pd
parameter_list|(
name|double
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m256d
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i32scatter_pd
comment|// CHECK: @llvm.x86.avx512.scattersiv4.df
return|return
name|_mm256_mask_i32scatter_pd
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_i32scatter_epi64
parameter_list|(
name|long
name|long
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m256i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_i32scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scattersiv4.di
return|return
name|_mm256_i32scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_i32scatter_epi64
parameter_list|(
name|long
name|long
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m256i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i32scatter_epi64
comment|// CHECK: @llvm.x86.avx512.scattersiv4.di
return|return
name|_mm256_mask_i32scatter_epi64
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_i32scatter_ps
parameter_list|(
name|float
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_i32scatter_ps
comment|// CHECK: @llvm.x86.avx512.scattersiv4.sf
return|return
name|_mm_i32scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_i32scatter_ps
parameter_list|(
name|float
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i32scatter_ps
comment|// CHECK: @llvm.x86.avx512.scattersiv4.sf
return|return
name|_mm_mask_i32scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_i32scatter_epi32
parameter_list|(
name|int
modifier|*
name|__addr
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_i32scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scattersiv4.si
return|return
name|_mm_i32scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_i32scatter_epi32
parameter_list|(
name|int
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|__m128i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i32scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scattersiv4.si
return|return
name|_mm_mask_i32scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_i32scatter_ps
parameter_list|(
name|float
modifier|*
name|__addr
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m256
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_i32scatter_ps
comment|// CHECK: @llvm.x86.avx512.scattersiv8.sf
return|return
name|_mm256_i32scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_i32scatter_ps
parameter_list|(
name|float
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m256
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i32scatter_ps
comment|// CHECK: @llvm.x86.avx512.scattersiv8.sf
return|return
name|_mm256_mask_i32scatter_ps
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_i32scatter_epi32
parameter_list|(
name|int
modifier|*
name|__addr
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m256i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_i32scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scattersiv8.si
return|return
name|_mm256_i32scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_i32scatter_epi32
parameter_list|(
name|int
modifier|*
name|__addr
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|__m256i
name|__v1
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i32scatter_epi32
comment|// CHECK: @llvm.x86.avx512.scattersiv8.si
return|return
name|_mm256_mask_i32scatter_epi32
argument_list|(
name|__addr
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__v1
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_sqrt_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_sqrt_pd
comment|// CHECK: @llvm.x86.sse2.sqrt.pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_sqrt_pd
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
name|__m128d
name|test_mm_maskz_sqrt_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_sqrt_pd
comment|// CHECK: @llvm.x86.sse2.sqrt.pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_sqrt_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_sqrt_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sqrt_pd
comment|// CHECK: @llvm.x86.avx.sqrt.pd.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_sqrt_pd
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
name|__m256d
name|test_mm256_maskz_sqrt_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sqrt_pd
comment|// CHECK: @llvm.x86.avx.sqrt.pd.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_sqrt_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_sqrt_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_sqrt_ps
comment|// CHECK: @llvm.x86.sse.sqrt.ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_sqrt_ps
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
name|__m128
name|test_mm_maskz_sqrt_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_sqrt_ps
comment|// CHECK: @llvm.x86.sse.sqrt.ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_sqrt_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_sqrt_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sqrt_ps
comment|// CHECK: @llvm.x86.avx.sqrt.ps.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_sqrt_ps
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
name|__m256
name|test_mm256_maskz_sqrt_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sqrt_ps
comment|// CHECK: @llvm.x86.avx.sqrt.ps.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_sqrt_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_sub_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_sub_pd
comment|// CHECK: fsub<2 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_sub_pd
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
name|__m128d
name|test_mm_maskz_sub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_sub_pd
comment|// CHECK: fsub<2 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_sub_pd
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
name|__m256d
name|test_mm256_mask_sub_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sub_pd
comment|// CHECK: fsub<4 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_sub_pd
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
name|__m256d
name|test_mm256_maskz_sub_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sub_pd
comment|// CHECK: fsub<4 x double> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_sub_pd
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
name|__m128
name|test_mm_mask_sub_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_sub_ps
comment|// CHECK: fsub<4 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_sub_ps
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
name|__m128
name|test_mm_maskz_sub_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_sub_ps
comment|// CHECK: fsub<4 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_sub_ps
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
name|__m256
name|test_mm256_mask_sub_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sub_ps
comment|// CHECK: fsub<8 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_sub_ps
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
name|__m256
name|test_mm256_maskz_sub_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sub_ps
comment|// CHECK: fsub<8 x float> %{{.*}}, %{{.*}}
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_sub_ps
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
name|test_mm_mask2_permutex2var_epi32
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
comment|// CHECK-LABEL: @test_mm_mask2_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.d.128
return|return
name|_mm_mask2_permutex2var_epi32
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
name|test_mm256_mask2_permutex2var_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask2_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.d.256
return|return
name|_mm256_mask2_permutex2var_epi32
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
name|__m128d
name|test_mm_mask2_permutex2var_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask2_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.pd.128
return|return
name|_mm_mask2_permutex2var_pd
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
name|__m256d
name|test_mm256_mask2_permutex2var_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask2_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.pd.256
return|return
name|_mm256_mask2_permutex2var_pd
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
name|__m128
name|test_mm_mask2_permutex2var_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask2_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.ps.128
return|return
name|_mm_mask2_permutex2var_ps
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
name|__m256
name|test_mm256_mask2_permutex2var_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask2_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.ps.256
return|return
name|_mm256_mask2_permutex2var_ps
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
name|test_mm_mask2_permutex2var_epi64
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
comment|// CHECK-LABEL: @test_mm_mask2_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.q.128
return|return
name|_mm_mask2_permutex2var_epi64
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
name|test_mm256_mask2_permutex2var_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask2_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.q.256
return|return
name|_mm256_mask2_permutex2var_epi64
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
name|test_mm_permutex2var_epi32
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
comment|// CHECK-LABEL: @test_mm_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.d.128
return|return
name|_mm_permutex2var_epi32
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
name|test_mm_mask_permutex2var_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.d.128
return|return
name|_mm_mask_permutex2var_epi32
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
name|test_mm_maskz_permutex2var_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.d.128
return|return
name|_mm_maskz_permutex2var_epi32
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
name|test_mm256_permutex2var_epi32
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
comment|// CHECK-LABEL: @test_mm256_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.d.256
return|return
name|_mm256_permutex2var_epi32
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
name|test_mm256_mask_permutex2var_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.d.256
return|return
name|_mm256_mask_permutex2var_epi32
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
name|test_mm256_maskz_permutex2var_epi32
parameter_list|(
name|__mmask8
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
comment|// CHECK-LABEL: @test_mm256_maskz_permutex2var_epi32
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.d.256
return|return
name|_mm256_maskz_permutex2var_epi32
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
name|__m128d
name|test_mm_permutex2var_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.pd.128
return|return
name|_mm_permutex2var_pd
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
name|__m128d
name|test_mm_mask_permutex2var_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.pd.128
return|return
name|_mm_mask_permutex2var_pd
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
name|__m128d
name|test_mm_maskz_permutex2var_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.pd.128
return|return
name|_mm_maskz_permutex2var_pd
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
name|__m256d
name|test_mm256_permutex2var_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.pd.256
return|return
name|_mm256_permutex2var_pd
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
name|__m256d
name|test_mm256_mask_permutex2var_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.pd.256
return|return
name|_mm256_mask_permutex2var_pd
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
name|__m256d
name|test_mm256_maskz_permutex2var_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutex2var_pd
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.pd.256
return|return
name|_mm256_maskz_permutex2var_pd
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
name|__m128
name|test_mm_permutex2var_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.ps.128
return|return
name|_mm_permutex2var_ps
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
name|__m128
name|test_mm_mask_permutex2var_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.ps.128
return|return
name|_mm_mask_permutex2var_ps
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
name|__m128
name|test_mm_maskz_permutex2var_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.ps.128
return|return
name|_mm_maskz_permutex2var_ps
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
name|__m256
name|test_mm256_permutex2var_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.ps.256
return|return
name|_mm256_permutex2var_ps
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
name|__m256
name|test_mm256_mask_permutex2var_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.ps.256
return|return
name|_mm256_mask_permutex2var_ps
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
name|__m256
name|test_mm256_maskz_permutex2var_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutex2var_ps
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.ps.256
return|return
name|_mm256_maskz_permutex2var_ps
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
name|test_mm_permutex2var_epi64
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
comment|// CHECK-LABEL: @test_mm_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.q.128
return|return
name|_mm_permutex2var_epi64
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
name|test_mm_mask_permutex2var_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.q.128
return|return
name|_mm_mask_permutex2var_epi64
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
name|test_mm_maskz_permutex2var_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.q.128
return|return
name|_mm_maskz_permutex2var_epi64
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
name|test_mm256_permutex2var_epi64
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
comment|// CHECK-LABEL: @test_mm256_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.q.256
return|return
name|_mm256_permutex2var_epi64
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
name|test_mm256_mask_permutex2var_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.q.256
return|return
name|_mm256_mask_permutex2var_epi64
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
name|test_mm256_maskz_permutex2var_epi64
parameter_list|(
name|__mmask8
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
comment|// CHECK-LABEL: @test_mm256_maskz_permutex2var_epi64
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.q.256
return|return
name|_mm256_maskz_permutex2var_epi64
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
name|test_mm_mask_cvtepi8_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi8_epi32
comment|// CHECK: sext<4 x i8> %{{.*}} to<4 x i32>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_cvtepi8_epi32
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
name|test_mm_maskz_cvtepi8_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi8_epi32
comment|// CHECK: sext<4 x i8> %{{.*}} to<4 x i32>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_cvtepi8_epi32
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
name|test_mm256_mask_cvtepi8_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi8_epi32
comment|// CHECK: sext<8 x i8> %{{.*}} to<8 x i32>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_cvtepi8_epi32
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
name|test_mm256_maskz_cvtepi8_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi8_epi32
comment|// CHECK: sext<8 x i8> %{{.*}} to<8 x i32>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_cvtepi8_epi32
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
name|test_mm_mask_cvtepi8_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi8_epi64
comment|// CHECK: sext<2 x i8> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_cvtepi8_epi64
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
name|test_mm_maskz_cvtepi8_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi8_epi64
comment|// CHECK: sext<2 x i8> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_cvtepi8_epi64
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
name|test_mm256_mask_cvtepi8_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi8_epi64
comment|// CHECK: sext<4 x i8> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_cvtepi8_epi64
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
name|test_mm256_maskz_cvtepi8_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi8_epi64
comment|// CHECK: sext<4 x i8> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_cvtepi8_epi64
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
name|test_mm_mask_cvtepi32_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepi32_epi64
comment|// CHECK: sext<2 x i32> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_cvtepi32_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_cvtepi32_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi32_epi64
comment|// CHECK: sext<2 x i32> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_cvtepi32_epi64
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtepi32_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi32_epi64
comment|// CHECK: sext<4 x i32> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_cvtepi32_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_cvtepi32_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi32_epi64
comment|// CHECK: sext<4 x i32> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_cvtepi32_epi64
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepi16_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi16_epi32
comment|// CHECK: sext<4 x i16> %{{.*}} to<4 x i32>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_cvtepi16_epi32
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
name|test_mm_maskz_cvtepi16_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi16_epi32
comment|// CHECK: sext<4 x i16> %{{.*}} to<4 x i32>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_cvtepi16_epi32
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
name|test_mm256_mask_cvtepi16_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi16_epi32
comment|// CHECK: sext<8 x i16> %{{.*}} to<8 x i32>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_cvtepi16_epi32
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
name|test_mm256_maskz_cvtepi16_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi16_epi32
comment|// CHECK: sext<8 x i16> %{{.*}} to<8 x i32>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_cvtepi16_epi32
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
name|test_mm_mask_cvtepi16_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi16_epi64
comment|// CHECK: sext<2 x i16> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_cvtepi16_epi64
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
name|test_mm_maskz_cvtepi16_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi16_epi64
comment|// CHECK: sext<2 x i16> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_cvtepi16_epi64
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
name|test_mm256_mask_cvtepi16_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi16_epi64
comment|// CHECK: sext<4 x i16> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_cvtepi16_epi64
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
name|test_mm256_maskz_cvtepi16_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi16_epi64
comment|// CHECK: sext<4 x i16> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_cvtepi16_epi64
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
name|test_mm_mask_cvtepu8_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepu8_epi32
comment|// CHECK: zext<4 x i8> %{{.*}} to<4 x i32>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_cvtepu8_epi32
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
name|test_mm_maskz_cvtepu8_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu8_epi32
comment|// CHECK: zext<4 x i8> %{{.*}} to<4 x i32>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_cvtepu8_epi32
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
name|test_mm256_mask_cvtepu8_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu8_epi32
comment|// CHECK: zext<8 x i8> %{{.*}} to<8 x i32>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_cvtepu8_epi32
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
name|test_mm256_maskz_cvtepu8_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu8_epi32
comment|// CHECK: zext<8 x i8> %{{.*}} to<8 x i32>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_cvtepu8_epi32
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
name|test_mm_mask_cvtepu8_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepu8_epi64
comment|// CHECK: zext<2 x i8> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_cvtepu8_epi64
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
name|test_mm_maskz_cvtepu8_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu8_epi64
comment|// CHECK: zext<2 x i8> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_cvtepu8_epi64
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
name|test_mm256_mask_cvtepu8_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu8_epi64
comment|// CHECK: zext<4 x i8> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_cvtepu8_epi64
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
name|test_mm256_maskz_cvtepu8_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu8_epi64
comment|// CHECK: zext<4 x i8> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_cvtepu8_epi64
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
name|test_mm_mask_cvtepu32_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtepu32_epi64
comment|// CHECK: zext<2 x i32> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_cvtepu32_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_cvtepu32_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu32_epi64
comment|// CHECK: zext<2 x i32> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_cvtepu32_epi64
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtepu32_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu32_epi64
comment|// CHECK: zext<4 x i32> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_cvtepu32_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_cvtepu32_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu32_epi64
comment|// CHECK: zext<4 x i32> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_cvtepu32_epi64
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepu16_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepu16_epi32
comment|// CHECK: zext<4 x i16> %{{.*}} to<4 x i32>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_cvtepu16_epi32
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
name|test_mm_maskz_cvtepu16_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu16_epi32
comment|// CHECK: zext<4 x i16> %{{.*}} to<4 x i32>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_cvtepu16_epi32
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
name|test_mm256_mask_cvtepu16_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu16_epi32
comment|// CHECK: zext<8 x i16> %{{.*}} to<8 x i32>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_cvtepu16_epi32
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
name|test_mm256_maskz_cvtepu16_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu16_epi32
comment|// CHECK: zext<8 x i16> %{{.*}} to<8 x i32>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_cvtepu16_epi32
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
name|test_mm_mask_cvtepu16_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepu16_epi64
comment|// CHECK: zext<2 x i16> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_cvtepu16_epi64
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
name|test_mm_maskz_cvtepu16_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu16_epi64
comment|// CHECK: zext<2 x i16> %{{.*}} to<2 x i64>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_cvtepu16_epi64
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
name|test_mm256_mask_cvtepu16_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu16_epi64
comment|// CHECK: zext<4 x i16> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_cvtepu16_epi64
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
name|test_mm256_maskz_cvtepu16_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu16_epi64
comment|// CHECK: zext<4 x i16> %{{.*}} to<4 x i64>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_cvtepu16_epi64
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
name|test_mm_rol_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rol_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prol.d.128
return|return
name|_mm_rol_epi32
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_rol_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_rol_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prol.d.128
return|return
name|_mm_mask_rol_epi32
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
name|test_mm_maskz_rol_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rol_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prol.d.128
return|return
name|_mm_maskz_rol_epi32
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
name|test_mm256_rol_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rol_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prol.d.256
return|return
name|_mm256_rol_epi32
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_rol_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_rol_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prol.d.256
return|return
name|_mm256_mask_rol_epi32
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
name|test_mm256_maskz_rol_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_rol_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prol.d.256
return|return
name|_mm256_maskz_rol_epi32
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
name|test_mm_rol_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rol_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prol.q.128
return|return
name|_mm_rol_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_rol_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_rol_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prol.q.128
return|return
name|_mm_mask_rol_epi64
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
name|test_mm_maskz_rol_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rol_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prol.q.128
return|return
name|_mm_maskz_rol_epi64
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
name|test_mm256_rol_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rol_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prol.q.256
return|return
name|_mm256_rol_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_rol_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_rol_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prol.q.256
return|return
name|_mm256_mask_rol_epi64
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
name|test_mm256_maskz_rol_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_rol_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prol.q.256
return|return
name|_mm256_maskz_rol_epi64
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
name|test_mm_rolv_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rolv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prolv.d.128
return|return
name|_mm_rolv_epi32
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
name|test_mm_mask_rolv_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_rolv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prolv.d.128
return|return
name|_mm_mask_rolv_epi32
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
name|test_mm_maskz_rolv_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_rolv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prolv.d.128
return|return
name|_mm_maskz_rolv_epi32
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
name|test_mm256_rolv_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rolv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prolv.d.256
return|return
name|_mm256_rolv_epi32
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
name|test_mm256_mask_rolv_epi32
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
comment|// CHECK-LABEL: @test_mm256_mask_rolv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prolv.d.256
return|return
name|_mm256_mask_rolv_epi32
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
name|test_mm256_maskz_rolv_epi32
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
comment|// CHECK-LABEL: @test_mm256_maskz_rolv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prolv.d.256
return|return
name|_mm256_maskz_rolv_epi32
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
name|test_mm_rolv_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rolv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prolv.q.128
return|return
name|_mm_rolv_epi64
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
name|test_mm_mask_rolv_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_rolv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prolv.q.128
return|return
name|_mm_mask_rolv_epi64
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
name|test_mm_maskz_rolv_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_rolv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prolv.q.128
return|return
name|_mm_maskz_rolv_epi64
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
name|test_mm256_rolv_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rolv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prolv.q.256
return|return
name|_mm256_rolv_epi64
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
name|test_mm256_mask_rolv_epi64
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
comment|// CHECK-LABEL: @test_mm256_mask_rolv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prolv.q.256
return|return
name|_mm256_mask_rolv_epi64
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
name|test_mm256_maskz_rolv_epi64
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
comment|// CHECK-LABEL: @test_mm256_maskz_rolv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prolv.q.256
return|return
name|_mm256_maskz_rolv_epi64
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
name|test_mm_ror_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_ror_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pror.d.128
return|return
name|_mm_ror_epi32
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_ror_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_ror_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pror.d.128
return|return
name|_mm_mask_ror_epi32
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
name|test_mm_maskz_ror_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_ror_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pror.d.128
return|return
name|_mm_maskz_ror_epi32
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
name|test_mm256_ror_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_ror_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pror.d.256
return|return
name|_mm256_ror_epi32
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_ror_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_ror_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pror.d.256
return|return
name|_mm256_mask_ror_epi32
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
name|test_mm256_maskz_ror_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_ror_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pror.d.256
return|return
name|_mm256_maskz_ror_epi32
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
name|test_mm_ror_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_ror_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pror.q.128
return|return
name|_mm_ror_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_ror_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_ror_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pror.q.128
return|return
name|_mm_mask_ror_epi64
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
name|test_mm_maskz_ror_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_ror_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pror.q.128
return|return
name|_mm_maskz_ror_epi64
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
name|test_mm256_ror_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_ror_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pror.q.256
return|return
name|_mm256_ror_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_ror_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_ror_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pror.q.256
return|return
name|_mm256_mask_ror_epi64
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
name|test_mm256_maskz_ror_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_ror_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pror.q.256
return|return
name|_mm256_maskz_ror_epi64
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
name|test_mm_rorv_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rorv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prorv.d.128
return|return
name|_mm_rorv_epi32
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
name|test_mm_mask_rorv_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_rorv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prorv.d.128
return|return
name|_mm_mask_rorv_epi32
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
name|test_mm_maskz_rorv_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_rorv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prorv.d.128
return|return
name|_mm_maskz_rorv_epi32
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
name|test_mm256_rorv_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rorv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prorv.d.256
return|return
name|_mm256_rorv_epi32
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
name|test_mm256_mask_rorv_epi32
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
comment|// CHECK-LABEL: @test_mm256_mask_rorv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prorv.d.256
return|return
name|_mm256_mask_rorv_epi32
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
name|test_mm256_maskz_rorv_epi32
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
comment|// CHECK-LABEL: @test_mm256_maskz_rorv_epi32
comment|// CHECK: @llvm.x86.avx512.mask.prorv.d.256
return|return
name|_mm256_maskz_rorv_epi32
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
name|test_mm_rorv_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rorv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prorv.q.128
return|return
name|_mm_rorv_epi64
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
name|test_mm_mask_rorv_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_rorv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prorv.q.128
return|return
name|_mm_mask_rorv_epi64
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
name|test_mm_maskz_rorv_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_rorv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prorv.q.128
return|return
name|_mm_maskz_rorv_epi64
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
name|test_mm256_rorv_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rorv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prorv.q.256
return|return
name|_mm256_rorv_epi64
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
name|test_mm256_mask_rorv_epi64
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
comment|// CHECK-LABEL: @test_mm256_mask_rorv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prorv.q.256
return|return
name|_mm256_mask_rorv_epi64
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
name|test_mm256_maskz_rorv_epi64
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
comment|// CHECK-LABEL: @test_mm256_maskz_rorv_epi64
comment|// CHECK: @llvm.x86.avx512.mask.prorv.q.256
return|return
name|_mm256_maskz_rorv_epi64
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
name|test_mm_mask_sllv_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_sllv_epi64
comment|// CHECK: @llvm.x86.avx2.psllv.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_sllv_epi64
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
name|test_mm_maskz_sllv_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_sllv_epi64
comment|// CHECK: @llvm.x86.avx2.psllv.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_sllv_epi64
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
name|test_mm256_mask_sllv_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sllv_epi64
comment|// CHECK: @llvm.x86.avx2.psllv.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_sllv_epi64
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
name|test_mm256_maskz_sllv_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sllv_epi64
comment|// CHECK: @llvm.x86.avx2.psllv.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_sllv_epi64
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
name|test_mm_mask_sllv_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_sllv_epi32
comment|// CHECK: @llvm.x86.avx2.psllv.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_sllv_epi32
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
name|test_mm_maskz_sllv_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_sllv_epi32
comment|// CHECK: @llvm.x86.avx2.psllv.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_sllv_epi32
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
name|test_mm256_mask_sllv_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sllv_epi32
comment|// CHECK: @llvm.x86.avx2.psllv.d.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_sllv_epi32
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
name|test_mm256_maskz_sllv_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sllv_epi32
comment|// CHECK: @llvm.x86.avx2.psllv.d.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_sllv_epi32
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
name|test_mm_mask_srlv_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_srlv_epi64
comment|// CHECK: @llvm.x86.avx2.psrlv.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_srlv_epi64
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
name|test_mm_maskz_srlv_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_srlv_epi64
comment|// CHECK: @llvm.x86.avx2.psrlv.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_srlv_epi64
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
name|test_mm256_mask_srlv_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srlv_epi64
comment|// CHECK: @llvm.x86.avx2.psrlv.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_srlv_epi64
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
name|test_mm256_maskz_srlv_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srlv_epi64
comment|// CHECK: @llvm.x86.avx2.psrlv.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_srlv_epi64
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
name|test_mm_mask_srlv_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_srlv_epi32
comment|// CHECK: @llvm.x86.avx2.psrlv.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_srlv_epi32
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
name|test_mm_maskz_srlv_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_srlv_epi32
comment|// CHECK: @llvm.x86.avx2.psrlv.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_srlv_epi32
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
name|test_mm256_mask_srlv_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srlv_epi32
comment|// CHECK: @llvm.x86.avx2.psrlv.d.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_srlv_epi32
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
name|test_mm256_maskz_srlv_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srlv_epi32
comment|// CHECK: @llvm.x86.avx2.psrlv.d.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_srlv_epi32
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
name|test_mm_mask_srl_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_srl_epi32
comment|// CHECK: @llvm.x86.sse2.psrl.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_srl_epi32
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
name|test_mm_maskz_srl_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_srl_epi32
comment|// CHECK: @llvm.x86.sse2.psrl.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_srl_epi32
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
name|test_mm256_mask_srl_epi32
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srl_epi32
comment|// CHECK: @llvm.x86.avx2.psrl.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_srl_epi32
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
name|test_mm256_maskz_srl_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srl_epi32
comment|// CHECK: @llvm.x86.avx2.psrl.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_srl_epi32
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
name|test_mm_mask_srli_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_srli_epi32
comment|// CHECK: @llvm.x86.sse2.psrli.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_srli_epi32
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
name|test_mm_maskz_srli_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_srli_epi32
comment|// CHECK: @llvm.x86.sse2.psrli.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_srli_epi32
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
name|test_mm256_mask_srli_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srli_epi32
comment|// CHECK: @llvm.x86.avx2.psrli.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_srli_epi32
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
name|test_mm256_maskz_srli_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srli_epi32
comment|// CHECK: @llvm.x86.avx2.psrli.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_srli_epi32
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
name|test_mm_mask_srl_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_srl_epi64
comment|// CHECK: @llvm.x86.sse2.psrl.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_srl_epi64
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
name|test_mm_maskz_srl_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_srl_epi64
comment|// CHECK: @llvm.x86.sse2.psrl.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_srl_epi64
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
name|test_mm256_mask_srl_epi64
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srl_epi64
comment|// CHECK: @llvm.x86.avx2.psrl.q
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_srl_epi64
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
name|test_mm256_maskz_srl_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srl_epi64
comment|// CHECK: @llvm.x86.avx2.psrl.q
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_srl_epi64
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
name|test_mm_mask_srli_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_srli_epi64
comment|// CHECK: @llvm.x86.sse2.psrli.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_srli_epi64
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
name|test_mm_maskz_srli_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_srli_epi64
comment|// CHECK: @llvm.x86.sse2.psrli.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_srli_epi64
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
name|test_mm256_mask_srli_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srli_epi64
comment|// CHECK: @llvm.x86.avx2.psrli.q
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_srli_epi64
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
name|test_mm256_maskz_srli_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srli_epi64
comment|// CHECK: @llvm.x86.avx2.psrli.q
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_srli_epi64
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
name|test_mm_mask_sll_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_sll_epi32
comment|// CHECK: @llvm.x86.sse2.psll.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_sll_epi32
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
name|test_mm_maskz_sll_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_sll_epi32
comment|// CHECK: @llvm.x86.sse2.psll.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_sll_epi32
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
name|test_mm256_mask_sll_epi32
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sll_epi32
comment|// CHECK: @llvm.x86.avx2.psll.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_sll_epi32
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
name|test_mm256_maskz_sll_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sll_epi32
comment|// CHECK: @llvm.x86.avx2.psll.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_sll_epi32
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
name|test_mm_mask_slli_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_slli_epi32
comment|// CHECK: @llvm.x86.sse2.pslli.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_slli_epi32
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
name|test_mm_maskz_slli_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_slli_epi32
comment|// CHECK: @llvm.x86.sse2.pslli.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_slli_epi32
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
name|test_mm256_mask_slli_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_slli_epi32
comment|// CHECK: @llvm.x86.avx2.pslli.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_slli_epi32
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
name|test_mm256_maskz_slli_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_slli_epi32
comment|// CHECK: @llvm.x86.avx2.pslli.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_slli_epi32
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
name|test_mm_mask_sll_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_sll_epi64
comment|// CHECK: @llvm.x86.sse2.psll.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_sll_epi64
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
name|test_mm_maskz_sll_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_sll_epi64
comment|// CHECK: @llvm.x86.sse2.psll.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_sll_epi64
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
name|test_mm256_mask_sll_epi64
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sll_epi64
comment|// CHECK: @llvm.x86.avx2.psll.q
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_sll_epi64
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
name|test_mm256_maskz_sll_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sll_epi64
comment|// CHECK: @llvm.x86.avx2.psll.q
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_sll_epi64
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
name|test_mm_mask_slli_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_slli_epi64
comment|// CHECK: @llvm.x86.sse2.pslli.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_slli_epi64
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
name|test_mm_maskz_slli_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_slli_epi64
comment|// CHECK: @llvm.x86.sse2.pslli.q
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_slli_epi64
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
name|test_mm256_mask_slli_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_slli_epi64
comment|// CHECK: @llvm.x86.avx2.pslli.q
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_slli_epi64
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
name|test_mm256_maskz_slli_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_slli_epi64
comment|// CHECK: @llvm.x86.avx2.pslli.q
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_slli_epi64
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
name|test_mm_mask_srav_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_srav_epi32
comment|// CHECK: @llvm.x86.avx2.psrav.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_srav_epi32
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
name|test_mm_maskz_srav_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_srav_epi32
comment|// CHECK: @llvm.x86.avx2.psrav.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_srav_epi32
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
name|test_mm256_mask_srav_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srav_epi32
comment|// CHECK: @llvm.x86.avx2.psrav.d.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_srav_epi32
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
name|test_mm256_maskz_srav_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srav_epi32
comment|// CHECK: @llvm.x86.avx2.psrav.d.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_srav_epi32
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
name|test_mm_srav_epi64
parameter_list|(
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_srav_epi64
comment|// CHECK: @llvm.x86.avx512.psrav.q.128
return|return
name|_mm_srav_epi64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_srav_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_srav_epi64
comment|// CHECK: @llvm.x86.avx512.psrav.q.128
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_srav_epi64
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
name|test_mm_maskz_srav_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_srav_epi64
comment|// CHECK: @llvm.x86.avx512.psrav.q.128
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_srav_epi64
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
name|test_mm256_srav_epi64
parameter_list|(
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_srav_epi64
comment|// CHECK: @llvm.x86.avx512.psrav.q.256
return|return
name|_mm256_srav_epi64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_srav_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srav_epi64
comment|// CHECK: @llvm.x86.avx512.psrav.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_srav_epi64
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
name|test_mm256_maskz_srav_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srav_epi64
comment|// CHECK: @llvm.x86.avx512.psrav.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_srav_epi64
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
name|void
name|test_mm_mask_store_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_store_epi32
comment|// CHECK: @llvm.masked.store.v4i32.p0v4i32(<4 x i32> %{{.*}},<4 x i32>* %{{.}}, i32 16,<4 x i1> %{{.*}})
return|return
name|_mm_mask_store_epi32
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
name|test_mm256_mask_store_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_store_epi32
comment|// CHECK: @llvm.masked.store.v8i32.p0v8i32(<8 x i32> %{{.*}},<8 x i32>* %{{.}}, i32 32,<8 x i1> %{{.*}})
return|return
name|_mm256_mask_store_epi32
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
name|__m128i
name|test_mm_mask_mov_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_mov_epi32
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_mov_epi32
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
name|test_mm_maskz_mov_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mov_epi32
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_mov_epi32
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
name|test_mm256_mask_mov_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mov_epi32
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_mov_epi32
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
name|test_mm256_maskz_mov_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mov_epi32
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_mov_epi32
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
name|test_mm_mask_mov_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_mov_epi64
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_mov_epi64
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
name|test_mm_maskz_mov_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mov_epi64
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_mov_epi64
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
name|test_mm256_mask_mov_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mov_epi64
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_mov_epi64
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
name|test_mm256_maskz_mov_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mov_epi64
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_mov_epi64
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
name|test_mm_mask_load_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_load_epi32
comment|// CHECK: @llvm.masked.load.v4i32.p0v4i32(<4 x i32>* %{{.*}}, i32 16,<4 x i1> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_mask_load_epi32
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
name|test_mm_maskz_load_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_load_epi32
comment|// CHECK: @llvm.masked.load.v4i32.p0v4i32(<4 x i32>* %{{.*}}, i32 16,<4 x i1> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_maskz_load_epi32
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
name|test_mm256_mask_load_epi32
parameter_list|(
name|__m256i
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
comment|// CHECK-LABEL: @test_mm256_mask_load_epi32
comment|// CHECK: @llvm.masked.load.v8i32.p0v8i32(<8 x i32>* %{{.*}}, i32 32,<8 x i1> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_mask_load_epi32
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
name|test_mm256_maskz_load_epi32
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
comment|// CHECK-LABEL: @test_mm256_maskz_load_epi32
comment|// CHECK: @llvm.masked.load.v8i32.p0v8i32(<8 x i32>* %{{.*}}, i32 32,<8 x i1> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_maskz_load_epi32
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
name|test_mm_mask_load_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_load_epi64
comment|// CHECK: @llvm.masked.load.v2i64.p0v2i64(<2 x i64>* %{{.*}}, i32 16,<2 x i1> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_mask_load_epi64
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
name|test_mm_maskz_load_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_load_epi64
comment|// CHECK: @llvm.masked.load.v2i64.p0v2i64(<2 x i64>* %{{.*}}, i32 16,<2 x i1> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_maskz_load_epi64
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
name|test_mm256_mask_load_epi64
parameter_list|(
name|__m256i
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
comment|// CHECK-LABEL: @test_mm256_mask_load_epi64
comment|// CHECK: @llvm.masked.load.v4i64.p0v4i64(<4 x i64>* %{{.*}}, i32 32,<4 x i1> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_mask_load_epi64
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
name|test_mm256_maskz_load_epi64
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
comment|// CHECK-LABEL: @test_mm256_maskz_load_epi64
comment|// CHECK: @llvm.masked.load.v4i64.p0v4i64(<4 x i64>* %{{.*}}, i32 32,<4 x i1> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_maskz_load_epi64
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
name|test_mm_mask_store_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_store_epi64
comment|// CHECK: @llvm.masked.store.v2i64.p0v2i64(<2 x i64> %{{.*}},<2 x i64>* %{{.*}}, i32 16,<2 x i1> %{{.*}})
return|return
name|_mm_mask_store_epi64
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
name|test_mm256_mask_store_epi64
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_store_epi64
comment|// CHECK: @llvm.masked.store.v4i64.p0v4i64(<4 x i64> %{{.*}},<4 x i64>* %{{.*}}, i32 32,<4 x i1> %{{.*}})
return|return
name|_mm256_mask_store_epi64
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
name|__m128d
name|test_mm_mask_movedup_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_movedup_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32> zeroinitializer
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_movedup_pd
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
name|__m128d
name|test_mm_maskz_movedup_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_movedup_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32> zeroinitializer
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_movedup_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_movedup_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_movedup_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 0, i32 2, i32 2>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_movedup_pd
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
name|__m256d
name|test_mm256_maskz_movedup_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_movedup_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 0, i32 2, i32 2>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_movedup_pd
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
name|test_mm_mask_set1_epi32
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_set1_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.d.gpr.128
return|return
name|_mm_mask_set1_epi32
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_set1_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_set1_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.d.gpr.128
return|return
name|_mm_maskz_set1_epi32
argument_list|(
name|__M
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_set1_epi32
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_set1_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.d.gpr.256
return|return
name|_mm256_mask_set1_epi32
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_set1_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_set1_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.d.gpr.256
return|return
name|_mm256_maskz_set1_epi32
argument_list|(
name|__M
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_ifdef
ifdef|#
directive|ifdef
name|__x86_64__
end_ifdef

begin_function
name|__m128i
name|test_mm_mask_set1_epi64
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|long
name|long
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_set1_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.q.gpr.128
return|return
name|_mm_mask_set1_epi64
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
name|test_mm_maskz_set1_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|long
name|long
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_set1_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.q.gpr.128
return|return
name|_mm_maskz_set1_epi64
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
name|test_mm256_mask_set1_epi64
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|long
name|long
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_set1_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.q.gpr.256
return|return
name|_mm256_mask_set1_epi64
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
name|test_mm256_maskz_set1_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|long
name|long
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_set1_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pbroadcast.q.gpr.256
return|return
name|_mm256_maskz_set1_epi64
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|__m128d
name|test_mm_fixupimm_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fixupimm_pd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.pd.128
return|return
name|_mm_fixupimm_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_fixupimm_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fixupimm_pd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.pd.128
return|return
name|_mm_mask_fixupimm_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_fixupimm_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fixupimm_pd
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm.pd.128
return|return
name|_mm_maskz_fixupimm_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_fixupimm_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_fixupimm_pd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.pd.256
return|return
name|_mm256_fixupimm_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_fixupimm_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fixupimm_pd
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.pd.256
return|return
name|_mm256_mask_fixupimm_pd
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_fixupimm_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fixupimm_pd
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm.pd.256
return|return
name|_mm256_maskz_fixupimm_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_fixupimm_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fixupimm_ps
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.ps.128
return|return
name|_mm_fixupimm_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_fixupimm_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fixupimm_ps
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.ps.128
return|return
name|_mm_mask_fixupimm_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_fixupimm_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_fixupimm_ps
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm.ps.128
return|return
name|_mm_maskz_fixupimm_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_fixupimm_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_fixupimm_ps
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.ps.256
return|return
name|_mm256_fixupimm_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_fixupimm_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fixupimm_ps
comment|// CHECK: @llvm.x86.avx512.mask.fixupimm.ps.256
return|return
name|_mm256_mask_fixupimm_ps
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_fixupimm_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_fixupimm_ps
comment|// CHECK: @llvm.x86.avx512.maskz.fixupimm.ps.256
return|return
name|_mm256_maskz_fixupimm_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_load_pd
parameter_list|(
name|__m128d
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
comment|// CHECK-LABEL: @test_mm_mask_load_pd
comment|// CHECK: @llvm.masked.load.v2f64.p0v2f64(<2 x double>* %{{.*}}, i32 16,<2 x i1> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_mask_load_pd
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
name|__m128d
name|test_mm_maskz_load_pd
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
comment|// CHECK-LABEL: @test_mm_maskz_load_pd
comment|// CHECK: @llvm.masked.load.v2f64.p0v2f64(<2 x double>* %{{.*}}, i32 16,<2 x i1> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_maskz_load_pd
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_load_pd
parameter_list|(
name|__m256d
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
comment|// CHECK-LABEL: @test_mm256_mask_load_pd
comment|// CHECK: @llvm.masked.load.v4f64.p0v4f64(<4 x double>* %{{.*}}, i32 32,<4 x i1> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_mask_load_pd
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
name|__m256d
name|test_mm256_maskz_load_pd
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
comment|// CHECK-LABEL: @test_mm256_maskz_load_pd
comment|// CHECK: @llvm.masked.load.v4f64.p0v4f64(<4 x double>* %{{.*}}, i32 32,<4 x i1> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_maskz_load_pd
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_load_ps
parameter_list|(
name|__m128
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
comment|// CHECK-LABEL: @test_mm_mask_load_ps
comment|// CHECK: @llvm.masked.load.v4f32.p0v4f32(<4 x float>* %{{.*}}, i32 16,<4 x i1> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_mask_load_ps
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
name|__m128
name|test_mm_maskz_load_ps
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
comment|// CHECK-LABEL: @test_mm_maskz_load_ps
comment|// CHECK: @llvm.masked.load.v4f32.p0v4f32(<4 x float>* %{{.*}}, i32 16,<4 x i1> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_maskz_load_ps
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_load_ps
parameter_list|(
name|__m256
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
comment|// CHECK-LABEL: @test_mm256_mask_load_ps
comment|// CHECK: @llvm.masked.load.v8f32.p0v8f32(<8 x float>* %{{.*}}, i32 32,<8 x i1> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_mask_load_ps
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
name|__m256
name|test_mm256_maskz_load_ps
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
comment|// CHECK-LABEL: @test_mm256_maskz_load_ps
comment|// CHECK: @llvm.masked.load.v8f32.p0v8f32(<8 x float>* %{{.*}}, i32 32,<8 x i1> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_maskz_load_ps
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
name|test_mm_mask_loadu_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_loadu_epi64
comment|// CHECK: @llvm.masked.load.v2i64.p0v2i64(<2 x i64>* %{{.*}}, i32 1,<2 x i1> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_mask_loadu_epi64
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
name|test_mm_maskz_loadu_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_loadu_epi64
comment|// CHECK: @llvm.masked.load.v2i64.p0v2i64(<2 x i64>* %{{.*}}, i32 1,<2 x i1> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_maskz_loadu_epi64
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
name|test_mm256_mask_loadu_epi64
parameter_list|(
name|__m256i
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
comment|// CHECK-LABEL: @test_mm256_mask_loadu_epi64
comment|// CHECK: @llvm.masked.load.v4i64.p0v4i64(<4 x i64>* %{{.*}}, i32 1,<4 x i1> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_mask_loadu_epi64
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
name|test_mm256_maskz_loadu_epi64
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
comment|// CHECK-LABEL: @test_mm256_maskz_loadu_epi64
comment|// CHECK: @llvm.masked.load.v4i64.p0v4i64(<4 x i64>* %{{.*}}, i32 1,<4 x i1> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_maskz_loadu_epi64
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
name|test_mm_mask_loadu_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_loadu_epi32
comment|// CHECK: @llvm.masked.load.v4i32.p0v4i32(<4 x i32>* %{{.*}}, i32 1,<4 x i1> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_mask_loadu_epi32
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
name|test_mm_maskz_loadu_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_loadu_epi32
comment|// CHECK: @llvm.masked.load.v4i32.p0v4i32(<4 x i32>* %{{.*}}, i32 1,<4 x i1> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_maskz_loadu_epi32
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
name|test_mm256_mask_loadu_epi32
parameter_list|(
name|__m256i
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
comment|// CHECK-LABEL: @test_mm256_mask_loadu_epi32
comment|// CHECK: @llvm.masked.load.v8i32.p0v8i32(<8 x i32>* %{{.*}}, i32 1,<8 x i1> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_mask_loadu_epi32
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
name|test_mm256_maskz_loadu_epi32
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
comment|// CHECK-LABEL: @test_mm256_maskz_loadu_epi32
comment|// CHECK: @llvm.masked.load.v8i32.p0v8i32(<8 x i32>* %{{.*}}, i32 1,<8 x i1> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_maskz_loadu_epi32
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_loadu_pd
parameter_list|(
name|__m128d
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
comment|// CHECK-LABEL: @test_mm_mask_loadu_pd
comment|// CHECK: @llvm.masked.load.v2f64.p0v2f64(<2 x double>* %{{.*}}, i32 1,<2 x i1> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_mask_loadu_pd
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
name|__m128d
name|test_mm_maskz_loadu_pd
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
comment|// CHECK-LABEL: @test_mm_maskz_loadu_pd
comment|// CHECK: @llvm.masked.load.v2f64.p0v2f64(<2 x double>* %{{.*}}, i32 1,<2 x i1> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_maskz_loadu_pd
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_loadu_pd
parameter_list|(
name|__m256d
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
comment|// CHECK-LABEL: @test_mm256_mask_loadu_pd
comment|// CHECK: @llvm.masked.load.v4f64.p0v4f64(<4 x double>* %{{.*}}, i32 1,<4 x i1> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_mask_loadu_pd
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
name|__m256d
name|test_mm256_maskz_loadu_pd
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
comment|// CHECK-LABEL: @test_mm256_maskz_loadu_pd
comment|// CHECK: @llvm.masked.load.v4f64.p0v4f64(<4 x double>* %{{.*}}, i32 1,<4 x i1> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_maskz_loadu_pd
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_loadu_ps
parameter_list|(
name|__m128
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
comment|// CHECK-LABEL: @test_mm_mask_loadu_ps
comment|// CHECK: @llvm.masked.load.v4f32.p0v4f32(<4 x float>* %{{.*}}, i32 1,<4 x i1> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_mask_loadu_ps
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
name|__m128
name|test_mm_maskz_loadu_ps
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
comment|// CHECK-LABEL: @test_mm_maskz_loadu_ps
comment|// CHECK: @llvm.masked.load.v4f32.p0v4f32(<4 x float>* %{{.*}}, i32 1,<4 x i1> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_maskz_loadu_ps
argument_list|(
name|__U
argument_list|,
name|__P
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_loadu_ps
parameter_list|(
name|__m256
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
comment|// CHECK-LABEL: @test_mm256_mask_loadu_ps
comment|// CHECK: @llvm.masked.load.v8f32.p0v8f32(<8 x float>* %{{.*}}, i32 1,<8 x i1> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_mask_loadu_ps
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
name|__m256
name|test_mm256_maskz_loadu_ps
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
comment|// CHECK-LABEL: @test_mm256_maskz_loadu_ps
comment|// CHECK: @llvm.masked.load.v8f32.p0v8f32(<8 x float>* %{{.*}}, i32 1,<8 x i1> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_maskz_loadu_ps
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
name|test_mm_mask_store_pd
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_store_pd
comment|// CHECK: @llvm.masked.store.v2f64.p0v2f64(<2 x double> %{{.*}},<2 x double>* %{{.*}}, i32 16,<2 x i1> %{{.*}})
return|return
name|_mm_mask_store_pd
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
name|test_mm256_mask_store_pd
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_store_pd
comment|// CHECK: @llvm.masked.store.v4f64.p0v4f64(<4 x double> %{{.*}},<4 x double>* %{{.*}}, i32 32,<4 x i1> %{{.*}})
return|return
name|_mm256_mask_store_pd
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
name|test_mm_mask_store_ps
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_store_ps
comment|// CHECK: @llvm.masked.store.v4f32.p0v4f32(<4 x float> %{{.*}},<4 x float>* %{{.*}}, i32 16,<4 x i1> %{{.*}})
return|return
name|_mm_mask_store_ps
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
name|test_mm256_mask_store_ps
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_store_ps
comment|// CHECK: @llvm.masked.store.v8f32.p0v8f32(<8 x float> %{{.*}},<8 x float>* %{{.*}}, i32 32,<8 x i1> %{{.*}})
return|return
name|_mm256_mask_store_ps
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
name|test_mm_mask_storeu_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_storeu_epi64
comment|// CHECK: @llvm.masked.store.v2i64.p0v2i64(<2 x i64> %{{.*}},<2 x i64>* %{{.*}}, i32 1,<2 x i1> %{{.*}})
return|return
name|_mm_mask_storeu_epi64
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
name|test_mm256_mask_storeu_epi64
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_storeu_epi64
comment|// CHECK: @llvm.masked.store.v4i64.p0v4i64(<4 x i64> %{{.*}},<4 x i64>* %{{.*}}, i32 1,<4 x i1> %{{.*}})
return|return
name|_mm256_mask_storeu_epi64
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
name|test_mm_mask_storeu_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_storeu_epi32
comment|// CHECK: @llvm.masked.store.v4i32.p0v4i32(<4 x i32> %{{.*}},<4 x i32>* %{{.*}}, i32 1,<4 x i1> %{{.*}})
return|return
name|_mm_mask_storeu_epi32
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
name|test_mm256_mask_storeu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_storeu_epi32
comment|// CHECK: @llvm.masked.store.v8i32.p0v8i32(<8 x i32> %{{.*}},<8 x i32>* %{{.*}}, i32 1,<8 x i1> %{{.*}})
return|return
name|_mm256_mask_storeu_epi32
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
name|test_mm_mask_storeu_pd
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_storeu_pd
comment|// CHECK: @llvm.masked.store.v2f64.p0v2f64(<2 x double> %{{.*}},<2 x double>* %{{.*}}, i32 1,<2 x i1> %{{.*}})
return|return
name|_mm_mask_storeu_pd
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
name|test_mm256_mask_storeu_pd
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_storeu_pd
comment|// CHECK: @llvm.masked.store.v4f64.p0v4f64(<4 x double> %{{.*}},<4 x double>* %{{.*}}, i32 1,<4 x i1> %{{.*}})
return|return
name|_mm256_mask_storeu_pd
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
name|test_mm_mask_storeu_ps
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_storeu_ps
comment|// CHECK: @llvm.masked.store.v4f32.p0v4f32(<4 x float> %{{.*}},<4 x float>* %{{.*}}, i32 1,<4 x i1> %{{.*}})
return|return
name|_mm_mask_storeu_ps
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
name|test_mm256_mask_storeu_ps
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_storeu_ps
comment|// CHECK: @llvm.masked.store.v8f32.p0v8f32(<8 x float> %{{.*}},<8 x float>* %{{.*}}, i32 1,<8 x i1> %{{.*}})
return|return
name|_mm256_mask_storeu_ps
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
name|__m128d
name|test_mm_mask_unpackhi_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_unpackhi_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 1, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_unpackhi_pd
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
name|__m128d
name|test_mm_maskz_unpackhi_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_unpackhi_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 1, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_unpackhi_pd
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
name|__m256d
name|test_mm256_mask_unpackhi_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_unpackhi_pd
comment|// CHECK: shufflevector<8 x i1> %{{.*}},<8 x i1> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_unpackhi_pd
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
name|__m256d
name|test_mm256_maskz_unpackhi_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_unpackhi_pd
comment|// CHECK: shufflevector<8 x i1> %{{.*}},<8 x i1> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_unpackhi_pd
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
name|__m128
name|test_mm_mask_unpackhi_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_unpackhi_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 2, i32 6, i32 3, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}}<4 x float> %{{.*}}
return|return
name|_mm_mask_unpackhi_ps
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
name|__m128
name|test_mm_maskz_unpackhi_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_unpackhi_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 2, i32 6, i32 3, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}}<4 x float> %{{.*}}
return|return
name|_mm_maskz_unpackhi_ps
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
name|__m256
name|test_mm256_mask_unpackhi_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_unpackhi_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 2, i32 10, i32 3, i32 11, i32 6, i32 14, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_unpackhi_ps
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
name|__m256
name|test_mm256_maskz_unpackhi_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_unpackhi_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 2, i32 10, i32 3, i32 11, i32 6, i32 14, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_unpackhi_ps
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
name|__m128d
name|test_mm_mask_unpacklo_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_unpacklo_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 0, i32 2>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_unpacklo_pd
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
name|__m128d
name|test_mm_maskz_unpacklo_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_unpacklo_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 0, i32 2>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_unpacklo_pd
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
name|__m256d
name|test_mm256_mask_unpacklo_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_unpacklo_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 4, i32 2, i32 6>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_unpacklo_pd
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
name|__m256d
name|test_mm256_maskz_unpacklo_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_unpacklo_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 4, i32 2, i32 6>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_unpacklo_pd
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
name|__m128
name|test_mm_mask_unpacklo_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_unpacklo_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 4, i32 1, i32 5>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_unpacklo_ps
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
name|__m128
name|test_mm_maskz_unpacklo_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_unpacklo_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 4, i32 1, i32 5>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_unpacklo_ps
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
name|__m256
name|test_mm256_mask_unpacklo_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_unpacklo_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 4, i32 12, i32 5, i32 13>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_unpacklo_ps
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
name|__m256
name|test_mm256_maskz_unpacklo_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_unpacklo_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 4, i32 12, i32 5, i32 13>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_unpacklo_ps
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
name|__m128d
name|test_mm_rcp14_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rcp14_pd
comment|// CHECK: @llvm.x86.avx512.rcp14.pd.128
return|return
name|_mm_rcp14_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_rcp14_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rcp14_pd
comment|// CHECK: @llvm.x86.avx512.rcp14.pd.128
return|return
name|_mm_mask_rcp14_pd
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
name|__m128d
name|test_mm_maskz_rcp14_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rcp14_pd
comment|// CHECK: @llvm.x86.avx512.rcp14.pd.128
return|return
name|_mm_maskz_rcp14_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_rcp14_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rcp14_pd
comment|// CHECK: @llvm.x86.avx512.rcp14.pd.256
return|return
name|_mm256_rcp14_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_rcp14_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_rcp14_pd
comment|// CHECK: @llvm.x86.avx512.rcp14.pd.256
return|return
name|_mm256_mask_rcp14_pd
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
name|__m256d
name|test_mm256_maskz_rcp14_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_rcp14_pd
comment|// CHECK: @llvm.x86.avx512.rcp14.pd.256
return|return
name|_mm256_maskz_rcp14_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_rcp14_ps
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rcp14_ps
comment|// CHECK: @llvm.x86.avx512.rcp14.ps.128
return|return
name|_mm_rcp14_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_rcp14_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rcp14_ps
comment|// CHECK: @llvm.x86.avx512.rcp14.ps.128
return|return
name|_mm_mask_rcp14_ps
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
name|__m128
name|test_mm_maskz_rcp14_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rcp14_ps
comment|// CHECK: @llvm.x86.avx512.rcp14.ps.128
return|return
name|_mm_maskz_rcp14_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_rcp14_ps
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rcp14_ps
comment|// CHECK: @llvm.x86.avx512.rcp14.ps.256
return|return
name|_mm256_rcp14_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_rcp14_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_rcp14_ps
comment|// CHECK: @llvm.x86.avx512.rcp14.ps.256
return|return
name|_mm256_mask_rcp14_ps
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
name|__m256
name|test_mm256_maskz_rcp14_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_rcp14_ps
comment|// CHECK: @llvm.x86.avx512.rcp14.ps.256
return|return
name|_mm256_maskz_rcp14_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_permute_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_permute_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> zeroinitializer,<2 x i32><i32 1, i32 0>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_permute_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_permute_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_permute_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> zeroinitializer,<2 x i32><i32 1, i32 0>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_permute_pd
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_permute_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permute_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<4 x i32><i32 1, i32 0, i32 3, i32 2>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_permute_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_permute_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permute_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<4 x i32><i32 1, i32 0, i32 3, i32 2>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_permute_pd
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_permute_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_permute_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> zeroinitializer,<4 x i32><i32 3, i32 2, i32 1, i32 0>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_permute_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
literal|0x1b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_permute_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_permute_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> zeroinitializer,<4 x i32><i32 3, i32 2, i32 1, i32 0>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_permute_ps
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
literal|0x1b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_permute_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permute_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> zeroinitializer,<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_permute_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
literal|0x1b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_permute_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permute_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> zeroinitializer,<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_permute_ps
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
literal|0x1b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_permutevar_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_permutevar_pd
comment|// CHECK: @llvm.x86.avx.vpermilvar.pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_permutevar_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_permutevar_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_permutevar_pd
comment|// CHECK: @llvm.x86.avx.vpermilvar.pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_permutevar_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_permutevar_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutevar_pd
comment|// CHECK: @llvm.x86.avx.vpermilvar.pd.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_permutevar_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_permutevar_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutevar_pd
comment|// CHECK: @llvm.x86.avx.vpermilvar.pd.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_permutevar_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_permutevar_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_permutevar_ps
comment|// CHECK: @llvm.x86.avx.vpermilvar.ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_permutevar_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_permutevar_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_permutevar_ps
comment|// CHECK: @llvm.x86.avx.vpermilvar.ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_permutevar_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_permutevar_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutevar_ps
comment|// CHECK: @llvm.x86.avx.vpermilvar.ps.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_permutevar_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_permutevar_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutevar_ps
comment|// CHECK: @llvm.x86.avx.vpermilvar.ps.256
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_permutevar_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__C
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_test_epi32_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_test_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.d.128
return|return
name|_mm_test_epi32_mask
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
name|test_mm_mask_test_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_test_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.d.128
return|return
name|_mm_mask_test_epi32_mask
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
name|test_mm256_test_epi32_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_test_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.d.256
return|return
name|_mm256_test_epi32_mask
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
name|test_mm256_mask_test_epi32_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_test_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.d.256
return|return
name|_mm256_mask_test_epi32_mask
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
name|test_mm_test_epi64_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_test_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.q.128
return|return
name|_mm_test_epi64_mask
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
name|test_mm_mask_test_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_test_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.q.128
return|return
name|_mm_mask_test_epi64_mask
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
name|test_mm256_test_epi64_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_test_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.q.256
return|return
name|_mm256_test_epi64_mask
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
name|test_mm256_mask_test_epi64_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_test_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestm.q.256
return|return
name|_mm256_mask_test_epi64_mask
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
name|test_mm_testn_epi32_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_testn_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.d.128
return|return
name|_mm_testn_epi32_mask
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
name|test_mm_mask_testn_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_testn_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.d.128
return|return
name|_mm_mask_testn_epi32_mask
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
name|test_mm256_testn_epi32_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_testn_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.d.256
return|return
name|_mm256_testn_epi32_mask
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
name|test_mm256_mask_testn_epi32_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_testn_epi32_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.d.256
return|return
name|_mm256_mask_testn_epi32_mask
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
name|test_mm_testn_epi64_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_testn_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.q.128
return|return
name|_mm_testn_epi64_mask
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
name|test_mm_mask_testn_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_testn_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.q.128
return|return
name|_mm_mask_testn_epi64_mask
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
name|test_mm256_testn_epi64_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_testn_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.q.256
return|return
name|_mm256_testn_epi64_mask
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
name|test_mm256_mask_testn_epi64_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_testn_epi64_mask
comment|// CHECK: @llvm.x86.avx512.ptestnm.q.256
return|return
name|_mm256_mask_testn_epi64_mask
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
name|test_mm_mask_unpackhi_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_unpackhi_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 2, i32 6, i32 3, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_unpackhi_epi32
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
name|test_mm_maskz_unpackhi_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_unpackhi_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 2, i32 6, i32 3, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_unpackhi_epi32
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
name|test_mm256_mask_unpackhi_epi32
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
comment|// CHECK-LABEL: @test_mm256_mask_unpackhi_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 2, i32 10, i32 3, i32 11, i32 6, i32 14, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_unpackhi_epi32
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
name|test_mm256_maskz_unpackhi_epi32
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
comment|// CHECK-LABEL: @test_mm256_maskz_unpackhi_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 2, i32 10, i32 3, i32 11, i32 6, i32 14, i32 7, i32 15>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_unpackhi_epi32
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
name|test_mm_mask_unpackhi_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_unpackhi_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 1, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_unpackhi_epi64
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
name|test_mm_maskz_unpackhi_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_unpackhi_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 1, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_unpackhi_epi64
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
name|test_mm256_mask_unpackhi_epi64
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
comment|// CHECK-LABEL: @test_mm256_mask_unpackhi_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 1, i32 5, i32 3, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_unpackhi_epi64
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
name|test_mm256_maskz_unpackhi_epi64
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
comment|// CHECK-LABEL: @test_mm256_maskz_unpackhi_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 1, i32 5, i32 3, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_unpackhi_epi64
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
name|test_mm_mask_unpacklo_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_unpacklo_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 0, i32 4, i32 1, i32 5>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_unpacklo_epi32
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
name|test_mm_maskz_unpacklo_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_unpacklo_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 0, i32 4, i32 1, i32 5>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_unpacklo_epi32
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
name|test_mm256_mask_unpacklo_epi32
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
comment|// CHECK-LABEL: @test_mm256_mask_unpacklo_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 4, i32 12, i32 5, i32 13>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_unpacklo_epi32
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
name|test_mm256_maskz_unpacklo_epi32
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
comment|// CHECK-LABEL: @test_mm256_maskz_unpacklo_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 4, i32 12, i32 5, i32 13>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_unpacklo_epi32
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
name|test_mm_mask_unpacklo_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_unpacklo_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 0, i32 2>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_unpacklo_epi64
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
name|test_mm_maskz_unpacklo_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_unpacklo_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 0, i32 2>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_unpacklo_epi64
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
name|test_mm256_mask_unpacklo_epi64
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
comment|// CHECK-LABEL: @test_mm256_mask_unpacklo_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 0, i32 4, i32 2, i32 6>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_unpacklo_epi64
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
name|test_mm256_maskz_unpacklo_epi64
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
comment|// CHECK-LABEL: @test_mm256_maskz_unpacklo_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 0, i32 4, i32 2, i32 6>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_unpacklo_epi64
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
name|test_mm_mask_sra_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_sra_epi32
comment|// CHECK: @llvm.x86.sse2.psra.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_sra_epi32
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
name|test_mm_maskz_sra_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_sra_epi32
comment|// CHECK: @llvm.x86.sse2.psra.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_sra_epi32
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
name|test_mm256_mask_sra_epi32
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sra_epi32
comment|// CHECK: @llvm.x86.avx2.psra.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_sra_epi32
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
name|test_mm256_maskz_sra_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sra_epi32
comment|// CHECK: @llvm.x86.avx2.psra.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_sra_epi32
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
name|test_mm_mask_srai_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_srai_epi32
comment|// CHECK: @llvm.x86.sse2.psrai.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_srai_epi32
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
name|test_mm_maskz_srai_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_srai_epi32
comment|// CHECK: @llvm.x86.sse2.psrai.d
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_srai_epi32
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
name|test_mm256_mask_srai_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srai_epi32
comment|// CHECK: @llvm.x86.avx2.psrai.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_srai_epi32
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
name|test_mm256_maskz_srai_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srai_epi32
comment|// CHECK: @llvm.x86.avx2.psrai.d
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_srai_epi32
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
name|test_mm_sra_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_sra_epi64
comment|// CHECK: @llvm.x86.avx512.psra.q.128
return|return
name|_mm_sra_epi64
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
name|test_mm_mask_sra_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_sra_epi64
comment|// CHECK: @llvm.x86.avx512.psra.q.128
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_sra_epi64
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
name|test_mm_maskz_sra_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_sra_epi64
comment|// CHECK: @llvm.x86.avx512.psra.q.128
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_sra_epi64
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
name|test_mm256_sra_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_sra_epi64
comment|// CHECK: @llvm.x86.avx512.psra.q.256
return|return
name|_mm256_sra_epi64
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
name|test_mm256_mask_sra_epi64
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_sra_epi64
comment|// CHECK: @llvm.x86.avx512.psra.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_sra_epi64
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
name|test_mm256_maskz_sra_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_sra_epi64
comment|// CHECK: @llvm.x86.avx512.psra.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_sra_epi64
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
name|test_mm_srai_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_srai_epi64
comment|// CHECK: @llvm.x86.avx512.psrai.q.128
return|return
name|_mm_srai_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_srai_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_srai_epi64
comment|// CHECK: @llvm.x86.avx512.psrai.q.128
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_srai_epi64
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
name|test_mm_maskz_srai_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_srai_epi64
comment|// CHECK: @llvm.x86.avx512.psrai.q.128
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_srai_epi64
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
name|test_mm256_srai_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_srai_epi64
comment|// CHECK: @llvm.x86.avx512.psrai.q.256
return|return
name|_mm256_srai_epi64
argument_list|(
name|__A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_srai_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_srai_epi64
comment|// CHECK: @llvm.x86.avx512.psrai.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_srai_epi64
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
name|test_mm256_maskz_srai_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_srai_epi64
comment|// CHECK: @llvm.x86.avx512.psrai.q.256
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_srai_epi64
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
name|test_mm_ternarylogic_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_ternarylogic_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.d.128
return|return
name|_mm_ternarylogic_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_ternarylogic_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_ternarylogic_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.d.128
return|return
name|_mm_mask_ternarylogic_epi32
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_ternarylogic_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_ternarylogic_epi32
comment|// CHECK: @llvm.x86.avx512.maskz.pternlog.d.128
return|return
name|_mm_maskz_ternarylogic_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_ternarylogic_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_ternarylogic_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.d.256
return|return
name|_mm256_ternarylogic_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_ternarylogic_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_ternarylogic_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.d.256
return|return
name|_mm256_mask_ternarylogic_epi32
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_ternarylogic_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_ternarylogic_epi32
comment|// CHECK: @llvm.x86.avx512.maskz.pternlog.d.256
return|return
name|_mm256_maskz_ternarylogic_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_ternarylogic_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_ternarylogic_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.q.128
return|return
name|_mm_ternarylogic_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_ternarylogic_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_ternarylogic_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.q.128
return|return
name|_mm_mask_ternarylogic_epi64
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_ternarylogic_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|,
name|__m128i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_ternarylogic_epi64
comment|// CHECK: @llvm.x86.avx512.maskz.pternlog.q.128
return|return
name|_mm_maskz_ternarylogic_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_ternarylogic_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_ternarylogic_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.q.256
return|return
name|_mm256_ternarylogic_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_ternarylogic_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_ternarylogic_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pternlog.q.256
return|return
name|_mm256_mask_ternarylogic_epi64
argument_list|(
name|__A
argument_list|,
name|__U
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_ternarylogic_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|,
name|__m256i
name|__C
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_ternarylogic_epi64
comment|// CHECK: @llvm.x86.avx512.maskz.pternlog.q.256
return|return
name|_mm256_maskz_ternarylogic_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
name|__C
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_shuffle_f32x4
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_shuffle_f32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f32x4
return|return
name|_mm256_shuffle_f32x4
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_shuffle_f32x4
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_shuffle_f32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f32x4
return|return
name|_mm256_mask_shuffle_f32x4
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_shuffle_f32x4
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_shuffle_f32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f32x4
return|return
name|_mm256_maskz_shuffle_f32x4
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_shuffle_f64x2
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_shuffle_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f64x2
return|return
name|_mm256_shuffle_f64x2
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_shuffle_f64x2
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_shuffle_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f64x2
return|return
name|_mm256_mask_shuffle_f64x2
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_shuffle_f64x2
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_shuffle_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.f64x2
return|return
name|_mm256_maskz_shuffle_f64x2
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_shuffle_i32x4
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_shuffle_i32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i32x4
return|return
name|_mm256_shuffle_i32x4
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_shuffle_i32x4
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
comment|// CHECK-LABEL: @test_mm256_mask_shuffle_i32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i32x4
return|return
name|_mm256_mask_shuffle_i32x4
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_shuffle_i32x4
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
comment|// CHECK-LABEL: @test_mm256_maskz_shuffle_i32x4
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i32x4
return|return
name|_mm256_maskz_shuffle_i32x4
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_shuffle_i64x2
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_shuffle_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i64x2
return|return
name|_mm256_shuffle_i64x2
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_shuffle_i64x2
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
comment|// CHECK-LABEL: @test_mm256_mask_shuffle_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i64x2
return|return
name|_mm256_mask_shuffle_i64x2
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_shuffle_i64x2
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
comment|// CHECK-LABEL: @test_mm256_maskz_shuffle_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.shuf.i64x2
return|return
name|_mm256_maskz_shuffle_i64x2
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_shuffle_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_shuffle_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 1, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_shuffle_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_shuffle_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_shuffle_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32><i32 1, i32 3>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_shuffle_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_shuffle_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_shuffle_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 1, i32 5, i32 2, i32 6>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_shuffle_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_shuffle_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_shuffle_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 1, i32 5, i32 2, i32 6>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_shuffle_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_shuffle_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_shuffle_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 4>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_shuffle_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_shuffle_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_shuffle_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 4>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_shuffle_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_shuffle_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_shuffle_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 8, i32 8, i32 4, i32 5, i32 12, i32 12>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_shuffle_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_shuffle_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_shuffle_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 8, i32 8, i32 4, i32 5, i32 12, i32 12>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_shuffle_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_rsqrt14_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.128
return|return
name|_mm_rsqrt14_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_rsqrt14_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.128
return|return
name|_mm_mask_rsqrt14_pd
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
name|__m128d
name|test_mm_maskz_rsqrt14_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.128
return|return
name|_mm_maskz_rsqrt14_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_rsqrt14_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.256
return|return
name|_mm256_rsqrt14_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_rsqrt14_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.256
return|return
name|_mm256_mask_rsqrt14_pd
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
name|__m256d
name|test_mm256_maskz_rsqrt14_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.256
return|return
name|_mm256_maskz_rsqrt14_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_rsqrt14_ps
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.128
return|return
name|_mm_rsqrt14_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_rsqrt14_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.128
return|return
name|_mm_mask_rsqrt14_ps
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
name|__m128
name|test_mm_maskz_rsqrt14_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.128
return|return
name|_mm_maskz_rsqrt14_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_rsqrt14_ps
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.256
return|return
name|_mm256_rsqrt14_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_rsqrt14_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.256
return|return
name|_mm256_mask_rsqrt14_ps
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
name|__m256
name|test_mm256_maskz_rsqrt14_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.256
return|return
name|_mm256_maskz_rsqrt14_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_broadcast_f32x4
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_f32x4
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm256_broadcast_f32x4
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_broadcast_f32x4
parameter_list|(
name|__m256
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_f32x4
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_broadcast_f32x4
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
name|__m256
name|test_mm256_maskz_broadcast_f32x4
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_f32x4
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_broadcast_f32x4
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
name|test_mm256_broadcast_i32x4
parameter_list|(
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_i32x4
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm256_broadcast_i32x4
argument_list|(
name|_mm_loadu_si128
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_broadcast_i32x4
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_i32x4
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_broadcast_i32x4
argument_list|(
name|__O
argument_list|,
name|__M
argument_list|,
name|_mm_loadu_si128
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_broadcast_i32x4
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
specifier|const
modifier|*
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_i32x4
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_broadcast_i32x4
argument_list|(
name|__M
argument_list|,
name|_mm_loadu_si128
argument_list|(
name|__A
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_broadcastsd_pd
parameter_list|(
name|__m256d
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcastsd_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_broadcastsd_pd
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
name|__m256d
name|test_mm256_maskz_broadcastsd_pd
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcastsd_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_broadcastsd_pd
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_broadcastss_ps
parameter_list|(
name|__m128
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_broadcastss_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_broadcastss_ps
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
name|__m128
name|test_mm_maskz_broadcastss_ps
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_broadcastss_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_broadcastss_ps
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_broadcastss_ps
parameter_list|(
name|__m256
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcastss_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_broadcastss_ps
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
name|__m256
name|test_mm256_maskz_broadcastss_ps
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcastss_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_broadcastss_ps
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
name|test_mm_mask_broadcastd_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_broadcastd_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_broadcastd_epi32
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
name|test_mm_maskz_broadcastd_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_broadcastd_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_broadcastd_epi32
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
name|test_mm256_mask_broadcastd_epi32
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcastd_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_broadcastd_epi32
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
name|test_mm256_maskz_broadcastd_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcastd_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<8 x i32> zeroinitializer
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_broadcastd_epi32
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
name|test_mm_mask_broadcastq_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_broadcastq_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32> zeroinitializer
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_broadcastq_epi64
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
name|test_mm_maskz_broadcastq_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_broadcastq_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32> zeroinitializer
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_broadcastq_epi64
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
name|test_mm256_mask_broadcastq_epi64
parameter_list|(
name|__m256i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_broadcastq_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_broadcastq_epi64
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
name|test_mm256_maskz_broadcastq_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcastq_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32> zeroinitializer
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_broadcastq_epi64
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
name|test_mm_cvtsepi32_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtsepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.128
return|return
name|_mm_cvtsepi32_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtsepi32_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.128
return|return
name|_mm_mask_cvtsepi32_epi8
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
name|test_mm_maskz_cvtsepi32_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtsepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.128
return|return
name|_mm_maskz_cvtsepi32_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtsepi32_storeu_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi32_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.mem.128
return|return
name|_mm_mask_cvtsepi32_storeu_epi8
argument_list|(
name|__P
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
name|test_mm256_cvtsepi32_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtsepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.256
return|return
name|_mm256_cvtsepi32_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtsepi32_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.256
return|return
name|_mm256_mask_cvtsepi32_epi8
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
name|test_mm256_maskz_cvtsepi32_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtsepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.256
return|return
name|_mm256_maskz_cvtsepi32_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtsepi32_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi32_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.db.mem.256
return|return
name|_mm256_mask_cvtsepi32_storeu_epi8
argument_list|(
name|__P
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
name|test_mm_cvtsepi32_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtsepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.128
return|return
name|_mm_cvtsepi32_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtsepi32_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.128
return|return
name|_mm_mask_cvtsepi32_epi16
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
name|test_mm_maskz_cvtsepi32_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtsepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.128
return|return
name|_mm_maskz_cvtsepi32_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtsepi32_storeu_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi32_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.mem.128
return|return
name|_mm_mask_cvtsepi32_storeu_epi16
argument_list|(
name|__P
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
name|test_mm256_cvtsepi32_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtsepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.256
return|return
name|_mm256_cvtsepi32_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtsepi32_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.256
return|return
name|_mm256_mask_cvtsepi32_epi16
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
name|test_mm256_maskz_cvtsepi32_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtsepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.256
return|return
name|_mm256_maskz_cvtsepi32_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtsepi32_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi32_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.dw.mem.256
return|return
name|_mm256_mask_cvtsepi32_storeu_epi16
argument_list|(
name|__P
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
name|test_mm_cvtsepi64_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtsepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.128
return|return
name|_mm_cvtsepi64_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtsepi64_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.128
return|return
name|_mm_mask_cvtsepi64_epi8
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
name|test_mm_maskz_cvtsepi64_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtsepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.128
return|return
name|_mm_maskz_cvtsepi64_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtsepi64_storeu_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi64_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.mem.128
return|return
name|_mm_mask_cvtsepi64_storeu_epi8
argument_list|(
name|__P
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
name|test_mm256_cvtsepi64_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtsepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.256
return|return
name|_mm256_cvtsepi64_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtsepi64_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.256
return|return
name|_mm256_mask_cvtsepi64_epi8
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
name|test_mm256_maskz_cvtsepi64_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtsepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.256
return|return
name|_mm256_maskz_cvtsepi64_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtsepi64_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi64_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qb.mem.256
return|return
name|_mm256_mask_cvtsepi64_storeu_epi8
argument_list|(
name|__P
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
name|test_mm_cvtsepi64_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtsepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.128
return|return
name|_mm_cvtsepi64_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtsepi64_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.128
return|return
name|_mm_mask_cvtsepi64_epi32
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
name|test_mm_maskz_cvtsepi64_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtsepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.128
return|return
name|_mm_maskz_cvtsepi64_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtsepi64_storeu_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi64_storeu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.mem.128
return|return
name|_mm_mask_cvtsepi64_storeu_epi32
argument_list|(
name|__P
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
name|test_mm256_cvtsepi64_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtsepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.256
return|return
name|_mm256_cvtsepi64_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtsepi64_epi32
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.256
return|return
name|_mm256_mask_cvtsepi64_epi32
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
name|test_mm256_maskz_cvtsepi64_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtsepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.256
return|return
name|_mm256_maskz_cvtsepi64_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtsepi64_storeu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi64_storeu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qd.mem.256
return|return
name|_mm256_mask_cvtsepi64_storeu_epi32
argument_list|(
name|__P
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
name|test_mm_cvtsepi64_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtsepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.128
return|return
name|_mm_cvtsepi64_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtsepi64_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.128
return|return
name|_mm_mask_cvtsepi64_epi16
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
name|test_mm_maskz_cvtsepi64_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtsepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.128
return|return
name|_mm_maskz_cvtsepi64_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtsepi64_storeu_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtsepi64_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.mem.128
return|return
name|_mm_mask_cvtsepi64_storeu_epi16
argument_list|(
name|__P
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
name|test_mm256_cvtsepi64_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtsepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.256
return|return
name|_mm256_cvtsepi64_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtsepi64_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.256
return|return
name|_mm256_mask_cvtsepi64_epi16
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
name|test_mm256_maskz_cvtsepi64_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtsepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.256
return|return
name|_mm256_maskz_cvtsepi64_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtsepi64_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtsepi64_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovs.qw.mem.256
return|return
name|_mm256_mask_cvtsepi64_storeu_epi16
argument_list|(
name|__P
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
name|test_mm_cvtusepi32_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtusepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.128
return|return
name|_mm_cvtusepi32_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtusepi32_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.128
return|return
name|_mm_mask_cvtusepi32_epi8
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
name|test_mm_maskz_cvtusepi32_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtusepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.128
return|return
name|_mm_maskz_cvtusepi32_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtusepi32_storeu_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi32_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.mem.128
return|return
name|_mm_mask_cvtusepi32_storeu_epi8
argument_list|(
name|__P
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
name|test_mm256_cvtusepi32_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtusepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.256
return|return
name|_mm256_cvtusepi32_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtusepi32_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.256
return|return
name|_mm256_mask_cvtusepi32_epi8
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
name|test_mm256_maskz_cvtusepi32_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtusepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.256
return|return
name|_mm256_maskz_cvtusepi32_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtusepi32_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi32_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.db.mem.256
return|return
name|_mm256_mask_cvtusepi32_storeu_epi8
argument_list|(
name|__P
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
name|test_mm_cvtusepi32_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtusepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.128
return|return
name|_mm_cvtusepi32_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtusepi32_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.128
return|return
name|_mm_mask_cvtusepi32_epi16
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
name|test_mm_maskz_cvtusepi32_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtusepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.128
return|return
name|_mm_maskz_cvtusepi32_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtusepi32_storeu_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi32_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.mem.128
return|return
name|_mm_mask_cvtusepi32_storeu_epi16
argument_list|(
name|__P
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
name|test_mm256_cvtusepi32_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtusepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.256
return|return
name|_mm256_cvtusepi32_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtusepi32_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.256
return|return
name|_mm256_mask_cvtusepi32_epi16
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
name|test_mm256_maskz_cvtusepi32_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtusepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.256
return|return
name|_mm256_maskz_cvtusepi32_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtusepi32_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi32_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.dw.mem.256
return|return
name|_mm256_mask_cvtusepi32_storeu_epi16
argument_list|(
name|__P
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
name|test_mm_cvtusepi64_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtusepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.128
return|return
name|_mm_cvtusepi64_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtusepi64_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.128
return|return
name|_mm_mask_cvtusepi64_epi8
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
name|test_mm_maskz_cvtusepi64_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtusepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.128
return|return
name|_mm_maskz_cvtusepi64_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtusepi64_storeu_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi64_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.mem.128
return|return
name|_mm_mask_cvtusepi64_storeu_epi8
argument_list|(
name|__P
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
name|test_mm256_cvtusepi64_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtusepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.256
return|return
name|_mm256_cvtusepi64_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtusepi64_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.256
return|return
name|_mm256_mask_cvtusepi64_epi8
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
name|test_mm256_maskz_cvtusepi64_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtusepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.256
return|return
name|_mm256_maskz_cvtusepi64_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtusepi64_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi64_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qb.mem.256
return|return
name|_mm256_mask_cvtusepi64_storeu_epi8
argument_list|(
name|__P
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
name|test_mm_cvtusepi64_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtusepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.128
return|return
name|_mm_cvtusepi64_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtusepi64_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.128
return|return
name|_mm_mask_cvtusepi64_epi32
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
name|test_mm_maskz_cvtusepi64_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtusepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.128
return|return
name|_mm_maskz_cvtusepi64_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtusepi64_storeu_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi64_storeu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.mem.128
return|return
name|_mm_mask_cvtusepi64_storeu_epi32
argument_list|(
name|__P
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
name|test_mm256_cvtusepi64_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtusepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.256
return|return
name|_mm256_cvtusepi64_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtusepi64_epi32
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.256
return|return
name|_mm256_mask_cvtusepi64_epi32
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
name|test_mm256_maskz_cvtusepi64_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtusepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.256
return|return
name|_mm256_maskz_cvtusepi64_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtusepi64_storeu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi64_storeu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qd.mem.256
return|return
name|_mm256_mask_cvtusepi64_storeu_epi32
argument_list|(
name|__P
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
name|test_mm_cvtusepi64_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtusepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.128
return|return
name|_mm_cvtusepi64_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtusepi64_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.128
return|return
name|_mm_mask_cvtusepi64_epi16
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
name|test_mm_maskz_cvtusepi64_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtusepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.128
return|return
name|_mm_maskz_cvtusepi64_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtusepi64_storeu_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtusepi64_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.mem.128
return|return
name|_mm_mask_cvtusepi64_storeu_epi16
argument_list|(
name|__P
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
name|test_mm256_cvtusepi64_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtusepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.256
return|return
name|_mm256_cvtusepi64_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtusepi64_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.256
return|return
name|_mm256_mask_cvtusepi64_epi16
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
name|test_mm256_maskz_cvtusepi64_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtusepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.256
return|return
name|_mm256_maskz_cvtusepi64_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtusepi64_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtusepi64_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmovus.qw.mem.256
return|return
name|_mm256_mask_cvtusepi64_storeu_epi16
argument_list|(
name|__P
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
name|test_mm_cvtepi32_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.128
return|return
name|_mm_cvtepi32_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepi32_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.128
return|return
name|_mm_mask_cvtepi32_epi8
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
name|test_mm_maskz_cvtepi32_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.128
return|return
name|_mm_maskz_cvtepi32_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtepi32_storeu_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi32_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.mem.128
return|return
name|_mm_mask_cvtepi32_storeu_epi8
argument_list|(
name|__P
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
name|test_mm256_cvtepi32_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.256
return|return
name|_mm256_cvtepi32_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtepi32_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.256
return|return
name|_mm256_mask_cvtepi32_epi8
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
name|test_mm256_maskz_cvtepi32_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi32_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.256
return|return
name|_mm256_maskz_cvtepi32_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtepi32_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi32_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.db.mem.256
return|return
name|_mm256_mask_cvtepi32_storeu_epi8
argument_list|(
name|__P
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
name|test_mm_cvtepi32_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.128
return|return
name|_mm_cvtepi32_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepi32_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.128
return|return
name|_mm_mask_cvtepi32_epi16
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
name|test_mm_maskz_cvtepi32_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.128
return|return
name|_mm_maskz_cvtepi32_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtepi32_storeu_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi32_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.mem.128
return|return
name|_mm_mask_cvtepi32_storeu_epi16
argument_list|(
name|__P
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
name|test_mm256_cvtepi32_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.256
return|return
name|_mm256_cvtepi32_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtepi32_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.256
return|return
name|_mm256_mask_cvtepi32_epi16
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
name|test_mm256_maskz_cvtepi32_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi32_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.256
return|return
name|_mm256_maskz_cvtepi32_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtepi32_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi32_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.dw.mem.256
return|return
name|_mm256_mask_cvtepi32_storeu_epi16
argument_list|(
name|__P
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
name|test_mm_cvtepi64_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.128
return|return
name|_mm_cvtepi64_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepi64_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.128
return|return
name|_mm_mask_cvtepi64_epi8
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
name|test_mm_maskz_cvtepi64_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.128
return|return
name|_mm_maskz_cvtepi64_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtepi64_storeu_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.mem.128
return|return
name|_mm_mask_cvtepi64_storeu_epi8
argument_list|(
name|__P
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
name|test_mm256_cvtepi64_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.256
return|return
name|_mm256_cvtepi64_epi8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtepi64_epi8
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.256
return|return
name|_mm256_mask_cvtepi64_epi8
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
name|test_mm256_maskz_cvtepi64_epi8
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.256
return|return
name|_mm256_maskz_cvtepi64_epi8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtepi64_storeu_epi8
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_storeu_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qb.mem.256
return|return
name|_mm256_mask_cvtepi64_storeu_epi8
argument_list|(
name|__P
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
name|test_mm_cvtepi64_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.128
return|return
name|_mm_cvtepi64_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepi64_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.128
return|return
name|_mm_mask_cvtepi64_epi32
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
name|test_mm_maskz_cvtepi64_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.128
return|return
name|_mm_maskz_cvtepi64_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtepi64_storeu_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_storeu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.mem.128
return|return
name|_mm_mask_cvtepi64_storeu_epi32
argument_list|(
name|__P
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
name|test_mm256_cvtepi64_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.256
return|return
name|_mm256_cvtepi64_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtepi64_epi32
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.256
return|return
name|_mm256_mask_cvtepi64_epi32
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
name|test_mm256_maskz_cvtepi64_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi64_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.256
return|return
name|_mm256_maskz_cvtepi64_epi32
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtepi64_storeu_epi32
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_storeu_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qd.mem.256
return|return
name|_mm256_mask_cvtepi64_storeu_epi32
argument_list|(
name|__P
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
name|test_mm_cvtepi64_epi16
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.128
return|return
name|_mm_cvtepi64_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtepi64_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.128
return|return
name|_mm_mask_cvtepi64_epi16
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
name|test_mm_maskz_cvtepi64_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.128
return|return
name|_mm_maskz_cvtepi64_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_mask_cvtepi64_storeu_epi16
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.mem.128
return|return
name|_mm_mask_cvtepi64_storeu_epi16
argument_list|(
name|__P
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
name|test_mm256_cvtepi64_epi16
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.256
return|return
name|_mm256_cvtepi64_epi16
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvtepi64_epi16
parameter_list|(
name|__m128i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.256
return|return
name|_mm256_mask_cvtepi64_epi16
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
name|test_mm256_maskz_cvtepi64_epi16
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi64_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.256
return|return
name|_mm256_maskz_cvtepi64_epi16
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_mask_cvtepi64_storeu_epi16
parameter_list|(
name|void
modifier|*
name|__P
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_storeu_epi16
comment|// CHECK: @llvm.x86.avx512.mask.pmov.qw.mem.256
return|return
name|_mm256_mask_cvtepi64_storeu_epi16
argument_list|(
name|__P
argument_list|,
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_extractf32x4_ps
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extractf32x4_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_extractf32x4_ps
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_mask_extractf32x4_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_extractf32x4_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm256_mask_extractf32x4_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_maskz_extractf32x4_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_extractf32x4_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm256_maskz_extractf32x4_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_extracti32x4_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extracti32x4_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<4 x i32><i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_extracti32x4_epi32
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_extracti32x4_epi32
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_extracti32x4_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm256_mask_extracti32x4_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_maskz_extracti32x4_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_extracti32x4_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm256_maskz_extracti32x4_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_insertf32x4
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_insertf32x4
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
return|return
name|_mm256_insertf32x4
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_insertf32x4
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_insertf32x4
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_insertf32x4
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_insertf32x4
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_insertf32x4
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_insertf32x4
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_inserti32x4
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_inserti32x4
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
return|return
name|_mm256_inserti32x4
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_inserti32x4
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_inserti32x4
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_inserti32x4
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_inserti32x4
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_inserti32x4
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_inserti32x4
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_getmant_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getmant_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.128
return|return
name|_mm_getmant_pd
argument_list|(
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_getmant_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_getmant_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.128
return|return
name|_mm_mask_getmant_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_getmant_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_getmant_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.128
return|return
name|_mm_maskz_getmant_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_getmant_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_getmant_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.256
return|return
name|_mm256_getmant_pd
argument_list|(
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_getmant_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_getmant_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.256
return|return
name|_mm256_mask_getmant_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_getmant_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_getmant_pd
comment|// CHECK: @llvm.x86.avx512.mask.getmant.pd.256
return|return
name|_mm256_maskz_getmant_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_getmant_ps
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_getmant_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.128
return|return
name|_mm_getmant_ps
argument_list|(
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_getmant_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_getmant_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.128
return|return
name|_mm_mask_getmant_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_getmant_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_getmant_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.128
return|return
name|_mm_maskz_getmant_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_getmant_ps
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_getmant_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.256
return|return
name|_mm256_getmant_ps
argument_list|(
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_getmant_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_getmant_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.256
return|return
name|_mm256_mask_getmant_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_maskz_getmant_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_getmant_ps
comment|// CHECK: @llvm.x86.avx512.mask.getmant.ps.256
return|return
name|_mm256_maskz_getmant_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_MANT_NORM_p5_2
argument_list|,
name|_MM_MANT_SIGN_nan
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mmask_i64gather_pd
parameter_list|(
name|__m128d
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mmask_i64gather_pd
comment|// CHECK: @llvm.x86.avx512.gather3div2.df
return|return
name|_mm_mmask_i64gather_pd
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mmask_i64gather_epi64
parameter_list|(
name|__m128i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mmask_i64gather_epi64
comment|// CHECK: @llvm.x86.avx512.gather3div2.di
return|return
name|_mm_mmask_i64gather_epi64
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mmask_i64gather_pd
parameter_list|(
name|__m256d
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mmask_i64gather_pd
comment|// CHECK: @llvm.x86.avx512.gather3div4.df
return|return
name|_mm256_mmask_i64gather_pd
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mmask_i64gather_epi64
parameter_list|(
name|__m256i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mmask_i64gather_epi64
comment|// CHECK: @llvm.x86.avx512.gather3div4.di
return|return
name|_mm256_mmask_i64gather_epi64
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mmask_i64gather_ps
parameter_list|(
name|__m128
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mmask_i64gather_ps
comment|// CHECK: @llvm.x86.avx512.gather3div4.sf
return|return
name|_mm_mmask_i64gather_ps
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mmask_i64gather_epi32
parameter_list|(
name|__m128i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mmask_i64gather_epi32
comment|// CHECK: @llvm.x86.avx512.gather3div4.si
return|return
name|_mm_mmask_i64gather_epi32
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_mmask_i64gather_ps
parameter_list|(
name|__m128
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mmask_i64gather_ps
comment|// CHECK: @llvm.x86.avx512.gather3div8.sf
return|return
name|_mm256_mmask_i64gather_ps
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mmask_i64gather_epi32
parameter_list|(
name|__m128i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mmask_i64gather_epi32
comment|// CHECK: @llvm.x86.avx512.gather3div8.si
return|return
name|_mm256_mmask_i64gather_epi32
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_i32gather_pd
parameter_list|(
name|__m128d
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i32gather_pd
comment|// CHECK: @llvm.x86.avx512.gather3siv2.df
return|return
name|_mm_mmask_i32gather_pd
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_i32gather_epi64
parameter_list|(
name|__m128i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i32gather_epi64
comment|// CHECK: @llvm.x86.avx512.gather3siv2.di
return|return
name|_mm_mmask_i32gather_epi64
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_i32gather_pd
parameter_list|(
name|__m256d
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i32gather_pd
comment|// CHECK: @llvm.x86.avx512.gather3siv4.df
return|return
name|_mm256_mmask_i32gather_pd
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_i32gather_epi64
parameter_list|(
name|__m256i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i32gather_epi64
comment|// CHECK: @llvm.x86.avx512.gather3siv4.di
return|return
name|_mm256_mmask_i32gather_epi64
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_i32gather_ps
parameter_list|(
name|__m128
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i32gather_ps
comment|// CHECK: @llvm.x86.avx512.gather3siv4.sf
return|return
name|_mm_mmask_i32gather_ps
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_i32gather_epi32
parameter_list|(
name|__m128i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m128i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_i32gather_epi32
comment|// CHECK: @llvm.x86.avx512.gather3siv4.si
return|return
name|_mm_mmask_i32gather_epi32
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_i32gather_ps
parameter_list|(
name|__m256
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i32gather_ps
comment|// CHECK: @llvm.x86.avx512.gather3siv8.sf
return|return
name|_mm256_mmask_i32gather_ps
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_i32gather_epi32
parameter_list|(
name|__m256i
name|__v1_old
parameter_list|,
name|__mmask8
name|__mask
parameter_list|,
name|__m256i
name|__index
parameter_list|,
name|void
specifier|const
modifier|*
name|__addr
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_i32gather_epi32
comment|// CHECK: @llvm.x86.avx512.gather3siv8.si
return|return
name|_mm256_mmask_i32gather_epi32
argument_list|(
name|__v1_old
argument_list|,
name|__mask
argument_list|,
name|__index
argument_list|,
name|__addr
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_permutex_pd
parameter_list|(
name|__m256d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutex_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<4 x i32><i32 3, i32 0, i32 0, i32 0>
return|return
name|_mm256_permutex_pd
argument_list|(
name|__X
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_permutex_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutex_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<4 x i32><i32 1, i32 0, i32 0, i32 0>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_permutex_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__X
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskz_permutex_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutex_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<4 x i32><i32 1, i32 0, i32 0, i32 0>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_permutex_pd
argument_list|(
name|__U
argument_list|,
name|__X
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_permutex_epi64
parameter_list|(
name|__m256i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutex_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<4 x i32><i32 3, i32 0, i32 0, i32 0>
return|return
name|_mm256_permutex_epi64
argument_list|(
name|__X
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_permutex_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutex_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<4 x i32><i32 3, i32 0, i32 0, i32 0>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_permutex_epi64
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__X
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_permutex_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutex_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<4 x i32><i32 3, i32 0, i32 0, i32 0>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_permutex_epi64
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_permutexvar_pd
parameter_list|(
name|__m256i
name|__X
parameter_list|,
name|__m256d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutexvar_pd
comment|// CHECK: @llvm.x86.avx512.mask.permvar.df.256
return|return
name|_mm256_permutexvar_pd
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_permutexvar_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutexvar_pd
comment|// CHECK: @llvm.x86.avx512.mask.permvar.df.256
return|return
name|_mm256_mask_permutexvar_pd
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
name|__m256d
name|test_mm256_maskz_permutexvar_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256d
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutexvar_pd
comment|// CHECK: @llvm.x86.avx512.mask.permvar.df.256
return|return
name|_mm256_maskz_permutexvar_pd
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
name|test_mm256_maskz_permutexvar_epi64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutexvar_epi64
comment|// CHECK: @llvm.x86.avx512.mask.permvar.di.256
return|return
name|_mm256_maskz_permutexvar_epi64
argument_list|(
name|__M
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
name|test_mm256_mask_permutexvar_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutexvar_epi64
comment|// CHECK: @llvm.x86.avx512.mask.permvar.di.256
return|return
name|_mm256_mask_permutexvar_epi64
argument_list|(
name|__W
argument_list|,
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_permutexvar_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutexvar_ps
comment|// CHECK: @llvm.x86.avx512.mask.permvar.sf.256
return|return
name|_mm256_mask_permutexvar_ps
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
name|__m256
name|test_mm256_maskz_permutexvar_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutexvar_ps
comment|// CHECK: @llvm.x86.avx512.mask.permvar.sf.256
return|return
name|_mm256_maskz_permutexvar_ps
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
name|__m256
name|test_mm256_permutexvar_ps
parameter_list|(
name|__m256i
name|__X
parameter_list|,
name|__m256
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutexvar_ps
comment|// CHECK: @llvm.x86.avx512.mask.permvar.sf.256
return|return
name|_mm256_permutexvar_ps
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_permutexvar_epi32
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_permutexvar_epi32
comment|// CHECK: @llvm.x86.avx512.mask.permvar.si.256
return|return
name|_mm256_maskz_permutexvar_epi32
argument_list|(
name|__M
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
name|test_mm256_permutexvar_epi32
parameter_list|(
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutexvar_epi32
comment|// CHECK: @llvm.x86.avx512.mask.permvar.si.256
return|return
name|_mm256_permutexvar_epi32
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_permutexvar_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutexvar_epi32
comment|// CHECK: @llvm.x86.avx512.mask.permvar.si.256
return|return
name|_mm256_mask_permutexvar_epi32
argument_list|(
name|__W
argument_list|,
name|__M
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
name|test_mm_alignr_epi32
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_alignr_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 1, i32 2, i32 3, i32 4>
return|return
name|_mm_alignr_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_alignr_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_alignr_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 1, i32 2, i32 3, i32 4>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_alignr_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_alignr_epi32
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
comment|// CHECK-LABEL: @test_mm_maskz_alignr_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 1, i32 2, i32 3, i32 4>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_alignr_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_alignr_epi32
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_alignr_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8>
return|return
name|_mm256_alignr_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_alignr_epi32
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
comment|// CHECK-LABEL: @test_mm256_mask_alignr_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_alignr_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_alignr_epi32
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
comment|// CHECK-LABEL: @test_mm256_maskz_alignr_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_alignr_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_alignr_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_alignr_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 1, i32 2>
return|return
name|_mm_alignr_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_alignr_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_alignr_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 1, i32 2>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_mask_alignr_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_alignr_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_alignr_epi64
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32><i32 1, i32 2>
comment|// CHECK: select<2 x i1> %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}
return|return
name|_mm_maskz_alignr_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_alignr_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_alignr_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 1, i32 2, i32 3, i32 4>
return|return
name|_mm256_alignr_epi64
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_alignr_epi64
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
comment|// CHECK-LABEL: @test_mm256_mask_alignr_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 1, i32 2, i32 3, i32 4>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_mask_alignr_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_alignr_epi64
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
comment|// CHECK-LABEL: @test_mm256_maskz_alignr_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 1, i32 2, i32 3, i32 4>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}
return|return
name|_mm256_maskz_alignr_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_movehdup_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_movehdup_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 1, i32 1, i32 3, i32 3>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_movehdup_ps
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
name|__m128
name|test_mm_maskz_movehdup_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_movehdup_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 1, i32 1, i32 3, i32 3>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_movehdup_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_movehdup_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_movehdup_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 1, i32 1, i32 3, i32 3, i32 5, i32 5, i32 7, i32 7>
comment|// CHECK: select<8 x i1> %{{.*}}<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_movehdup_ps
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
name|__m256
name|test_mm256_maskz_movehdup_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_movehdup_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 1, i32 1, i32 3, i32 3, i32 5, i32 5, i32 7, i32 7>
comment|// CHECK: select<8 x i1> %{{.*}}<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_movehdup_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_moveldup_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_moveldup_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 0, i32 2, i32 2>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_moveldup_ps
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
name|__m128
name|test_mm_maskz_moveldup_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_moveldup_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32><i32 0, i32 0, i32 2, i32 2>
comment|// CHECK: select<4 x i1> %{{.*}}<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_moveldup_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_moveldup_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_moveldup_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 0, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6>
comment|// CHECK: select<8 x i1> %{{.*}}<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_moveldup_ps
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
name|__m256
name|test_mm256_maskz_moveldup_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_moveldup_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 0, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6>
comment|// CHECK: select<8 x i1> %{{.*}}<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_moveldup_ps
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
name|test_mm_mask_shuffle_epi32
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
comment|// CHECK-LABEL: @test_mm_mask_shuffle_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 1, i32 0, i32 0, i32 0>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_mask_shuffle_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_shuffle_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_shuffle_epi32
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 2, i32 0, i32 0, i32 0>
comment|// CHECK: select<4 x i1> %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}
return|return
name|_mm_maskz_shuffle_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_shuffle_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_shuffle_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 2, i32 0, i32 0, i32 0, i32 6, i32 4, i32 4, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_mask_shuffle_epi32
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskz_shuffle_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_shuffle_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 2, i32 0, i32 0, i32 0, i32 6, i32 4, i32 4, i32 4>
comment|// CHECK: select<8 x i1> %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}
return|return
name|_mm256_maskz_shuffle_epi32
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_mov_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_mov_pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_mask_mov_pd
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
name|__m128d
name|test_mm_maskz_mov_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mov_pd
comment|// CHECK: select<2 x i1> %{{.*}},<2 x double> %{{.*}},<2 x double> %{{.*}}
return|return
name|_mm_maskz_mov_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_mov_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mov_pd
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_mask_mov_pd
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
name|__m256d
name|test_mm256_maskz_mov_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mov_pd
comment|// CHECK: select<4 x i1> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}}
return|return
name|_mm256_maskz_mov_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_mov_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_mov_ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_mask_mov_ps
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
name|__m128
name|test_mm_maskz_mov_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_mov_ps
comment|// CHECK: select<4 x i1> %{{.*}},<4 x float> %{{.*}},<4 x float> %{{.*}}
return|return
name|_mm_maskz_mov_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_mov_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_mov_ps
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_mask_mov_ps
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
name|__m256
name|test_mm256_maskz_mov_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_mov_ps
comment|// CHECK: select<8 x i1> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}}
return|return
name|_mm256_maskz_mov_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_cvtph_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtph_ps
comment|// CHECK: @llvm.x86.avx512.mask.vcvtph2ps.128
return|return
name|_mm_mask_cvtph_ps
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
name|__m128
name|test_mm_maskz_cvtph_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtph_ps
comment|// CHECK: @llvm.x86.avx512.mask.vcvtph2ps.128
return|return
name|_mm_maskz_cvtph_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_cvtph_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtph_ps
comment|// CHECK: @llvm.x86.avx512.mask.vcvtph2ps.256
return|return
name|_mm256_mask_cvtph_ps
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
name|__m256
name|test_mm256_maskz_cvtph_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtph_ps
comment|// CHECK: @llvm.x86.avx512.mask.vcvtph2ps.256
return|return
name|_mm256_maskz_cvtph_ps
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
name|test_mm_mask_cvtps_ph
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvtps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.128
return|return
name|_mm_mask_cvtps_ph
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
name|test_mm_maskz_cvtps_ph
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.128
return|return
name|_mm_maskz_cvtps_ph
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
name|test_mm256_mask_cvtps_ph
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.256
return|return
name|_mm256_mask_cvtps_ph
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
name|test_mm256_maskz_cvtps_ph
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.256
return|return
name|_mm256_maskz_cvtps_ph
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
name|test_mm_mask_cvt_roundps_ph
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_cvt_roundps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.128
return|return
name|_mm_mask_cvt_roundps_ph
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskz_cvt_roundps_ph
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvt_roundps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.128
return|return
name|_mm_maskz_cvt_roundps_ph
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_cvt_roundps_ph
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvt_roundps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.256
return|return
name|_mm256_mask_cvt_roundps_ph
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_maskz_cvt_roundps_ph
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvt_roundps_ph
comment|// CHECK: @llvm.x86.avx512.mask.vcvtps2ph.256
return|return
name|_mm256_maskz_cvt_roundps_ph
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmpeq_epi32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epi32_mask
comment|// CHECK: icmp eq<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpeq_epi32_mask
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
name|test_mm_mask_cmpeq_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epi32_mask
comment|// CHECK: icmp eq<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpeq_epi32_mask
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
name|test_mm_mask_cmpeq_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpeq_epi64_mask
comment|// CHECK: icmp eq<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpeq_epi64_mask
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
name|test_mm_cmpeq_epi64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpeq_epi64_mask
comment|// CHECK: icmp eq<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpeq_epi64_mask
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
name|test_mm_cmpgt_epi32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epi32_mask
comment|// CHECK: icmp sgt<4 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpgt_epi32_mask
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
name|test_mm_mask_cmpgt_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epi32_mask
comment|// CHECK: icmp sgt<4 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpgt_epi32_mask
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
name|test_mm_mask_cmpgt_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmpgt_epi64_mask
comment|// CHECK: icmp sgt<2 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<2 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_mask_cmpgt_epi64_mask
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
name|test_mm_cmpgt_epi64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmpgt_epi64_mask
comment|// CHECK: icmp sgt<2 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm_cmpgt_epi64_mask
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
name|test_mm256_cmpeq_epi32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epi32_mask
comment|// CHECK: icmp eq<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpeq_epi32_mask
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
name|test_mm256_mask_cmpeq_epi32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epi32_mask
comment|// CHECK: icmp eq<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpeq_epi32_mask
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
name|test_mm256_mask_cmpeq_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpeq_epi64_mask
comment|// CHECK: icmp eq<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpeq_epi64_mask
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
name|test_mm256_cmpeq_epi64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpeq_epi64_mask
comment|// CHECK: icmp eq<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpeq_epi64_mask
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
name|test_mm256_cmpgt_epi32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epi32_mask
comment|// CHECK: icmp sgt<8 x i32> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpgt_epi32_mask
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
name|test_mm256_mask_cmpgt_epi32_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epi32_mask
comment|// CHECK: icmp sgt<8 x i32> %{{.*}}, %{{.*}}
comment|// CHECK: and<8 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpgt_epi32_mask
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
name|test_mm256_mask_cmpgt_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cmpgt_epi64_mask
comment|// CHECK: icmp sgt<4 x i64> %{{.*}}, %{{.*}}
comment|// CHECK: and<4 x i1> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_mask_cmpgt_epi64_mask
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
name|test_mm256_cmpgt_epi64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmpgt_epi64_mask
comment|// CHECK: icmp sgt<4 x i64> %{{.*}}, %{{.*}}
return|return
operator|(
name|__mmask8
operator|)
name|_mm256_cmpgt_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

end_unit

