begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +avx512f -target-feature +avx512vl -emit-llvm -o - -Werror | FileCheck %s
end_comment

begin_comment
comment|// Don't include mm_malloc.h, it's system specific.
end_comment

begin_define
define|#
directive|define
name|__MM_MALLOC_H
end_define

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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 0, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 0, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 0, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 0, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 5, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 5, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 5, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 5, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 5, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 5, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 5, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 5, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 5, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 5, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 5, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 5, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 5, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 5, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 5, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 5, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 6, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 6, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 6, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 6, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 6, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 6, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 6, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 6, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 2, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 2, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 2, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 2, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 2, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 2, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 2, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 2, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 2, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 2, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 2, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 2, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 2, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 2, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 2, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 2, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 1, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 1, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 1, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 1, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 1, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 1, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 1, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 1, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 1, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 1, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 1, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 1, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 1, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 1, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 1, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 1, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 4, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 4, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 4, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 4, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 4, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 4, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 4, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 4, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 4, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 4, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 4, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 4, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 4, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 4, i8 {{.*}})
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 4, i8 -1)
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 4, i8 {{.*}})
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
name|test_mm_cmp_epi32_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 7, i8 -1)
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
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_epi32_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 7, i8 {{.*}})
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
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_cmp_epi64_mask
parameter_list|(
name|__m128i
name|__a
parameter_list|,
name|__m128i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cmp_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 7, i8 -1)
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
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_cmp_epi64_mask
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
comment|// CHECK-LABEL: @test_mm_mask_cmp_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 7, i8 {{.*}})
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
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_cmp_epi32_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 7, i8 -1)
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
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_cmp_epi32_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 7, i8 {{.*}})
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
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_cmp_epi64_mask
parameter_list|(
name|__m256i
name|__a
parameter_list|,
name|__m256i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cmp_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 7, i8 -1)
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
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_cmp_epi64_mask
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
comment|// CHECK-LABEL: @test_mm256_mask_cmp_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 7, i8 {{.*}})
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
literal|7
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 7, i8 -1)
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
literal|7
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.128(<4 x i32> {{.*}},<4 x i32> {{.*}}, i32 7, i8 {{.*}})
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
literal|7
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 7, i8 -1)
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
literal|7
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.128(<2 x i64> {{.*}},<2 x i64> {{.*}}, i32 7, i8 {{.*}})
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
literal|7
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 7, i8 -1)
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
literal|7
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.256(<8 x i32> {{.*}},<8 x i32> {{.*}}, i32 7, i8 {{.*}})
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
literal|7
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 7, i8 -1)
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
literal|7
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
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.256(<4 x i64> {{.*}},<4 x i64> {{.*}}, i32 7, i8 {{.*}})
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
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_andnot_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_andnot_epi32
comment|//CHECK: @llvm.x86.avx512.mask.pandn.d.512
return|return
name|_mm512_maskz_andnot_epi32
argument_list|(
name|__k
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_andnot_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_andnot_epi32
comment|//CHECK: @llvm.x86.avx512.mask.pandn.d.512
return|return
name|_mm512_mask_andnot_epi32
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_andnot_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_andnot_epi32
comment|//CHECK: @llvm.x86.avx512.mask.pandn.d.512
return|return
name|_mm512_andnot_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_andnot_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_maskz_andnot_epi64
comment|//CHECK: @llvm.x86.avx512.mask.pandn.q.512
return|return
name|_mm512_maskz_andnot_epi64
argument_list|(
name|__k
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_andnot_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|,
name|__m512i
name|__src
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mask_andnot_epi64
comment|//CHECK: @llvm.x86.avx512.mask.pandn.q.512
return|return
name|_mm512_mask_andnot_epi64
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_andnot_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_andnot_epi64
comment|//CHECK: @llvm.x86.avx512.mask.pandn.q.512
return|return
name|_mm512_andnot_epi64
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
comment|//CHECK: @llvm.x86.avx512.mask.padd.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.padd.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.padd.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.padd.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.psub.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.psub.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.psub.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.psub.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.padd.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.padd.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.padd.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.padd.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.psub.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.psub.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.psub.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.psub.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pmul.dq.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pmul.dq.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pmul.dq.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pmul.dq.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pmulu.dq.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pmulu.dq.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pmulu.dq.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pmulu.dq.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pmull.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pmull.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pmull.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pmull.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pand.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pand.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pand.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pand.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pandn.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pandn.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pandn.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pandn.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.por.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.por.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.por.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.por.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pxor.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pxor.d.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pxor.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pxor.d.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pand.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pand.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pand.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pand.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pandn.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pandn.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pandn.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pandn.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.por.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.por.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.por.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.por.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pxor.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pxor.q.256
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
comment|//CHECK: @llvm.x86.avx512.mask.pxor.q.128
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
comment|//CHECK: @llvm.x86.avx512.mask.pxor.q.128
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
name|test_mm128_cmp_ps_mask
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm128_cmp_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm128_cmp_ps_mask
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
name|test_mm128_mask_cmp_ps_mask
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
comment|// CHECK-LABEL: @test_mm128_mask_cmp_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.128
return|return
name|_mm128_mask_cmp_ps_mask
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
name|test_mm128_cmp_pd_mask
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm128_cmp_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.128
return|return
operator|(
name|__mmask8
operator|)
name|_mm128_cmp_pd_mask
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
name|test_mm128_mask_cmp_pd_mask
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
comment|// CHECK-LABEL: @test_mm128_mask_cmp_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.128
return|return
name|_mm128_mask_cmp_pd_mask
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

begin_comment
comment|//igorb
end_comment

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
comment|// CHECK: @llvm.x86.avx512.mask.add.pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.add.pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.add.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.add.pd.256
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
comment|// CHECK-LABEL: @test_mm_mask_add_ps
comment|// CHECK: @llvm.x86.avx512.mask.add.ps.128
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
comment|// CHECK: @llvm.x86.avx512.mask.add.ps.128
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
name|__mmask16
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
comment|// CHECK: @llvm.x86.avx512.mask.add.ps.256
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
name|__mmask16
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
comment|// CHECK: @llvm.x86.avx512.mask.add.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.blend.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.blend.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.blend.pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.blend.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.blend.ps.128
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
comment|// CHECK: @llvm.x86.avx512.mask.blend.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.blend.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.blend.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtdq2pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.cvtudq2pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.div.pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.div.pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.div.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.div.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.div.ps.128
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
comment|// CHECK-LABEL: @test_mm_maskz_div_ps
comment|// CHECK: @llvm.x86.avx512.mask.div.ps.128
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
comment|// CHECK: @llvm.x86.avx512.mask.div.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.div.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.max.pd
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
comment|// CHECK: @llvm.x86.avx512.mask.max.pd
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
comment|// CHECK: @llvm.x86.avx512.mask.max.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.max.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.max.ps
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
comment|// CHECK: @llvm.x86.avx512.mask.max.ps
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
comment|// CHECK: @llvm.x86.avx512.mask.max.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.max.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.min.pd
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
comment|// CHECK: @llvm.x86.avx512.mask.min.pd
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
comment|// CHECK: @llvm.x86.avx512.mask.min.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.min.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.min.ps
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
comment|// CHECK: @llvm.x86.avx512.mask.min.ps
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
comment|// CHECK: @llvm.x86.avx512.mask.min.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.min.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.mul.pd
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
comment|// CHECK: @llvm.x86.avx512.mask.mul.pd
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
comment|// CHECK: @llvm.x86.avx512.mask.mul.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.mul.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.mul.ps
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
comment|// CHECK: @llvm.x86.avx512.mask.mul.ps
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
comment|// CHECK: @llvm.x86.avx512.mask.mul.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.mul.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pabs.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pabs.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pabs.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pabs.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxs.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmaxu.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pmins.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.d.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.d.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.q.128
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.pminu.q.256
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.128
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.128
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.sqrt.ps.256
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
comment|// CHECK: @llvm.x86.avx512.mask.sub.pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.sub.pd.128
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
comment|// CHECK: @llvm.x86.avx512.mask.sub.pd.256
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
comment|// CHECK: @llvm.x86.avx512.mask.sub.pd.256
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
comment|// CHECK-LABEL: @test_mm_mask_sub_ps
comment|// CHECK: @llvm.x86.avx512.mask.sub.ps.128
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
comment|// CHECK-LABEL: @test_mm_maskz_sub_ps
comment|// CHECK: @llvm.x86.avx512.mask.sub.ps.128
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
name|__mmask16
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
comment|// CHECK: @llvm.x86.avx512.mask.sub.ps.256
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
name|__mmask16
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
comment|// CHECK: @llvm.x86.avx512.mask.sub.ps.256
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

end_unit

