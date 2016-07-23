begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +avx512dq -target-feature +avx512vl -emit-llvm -o - -Werror | FileCheck %s
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
name|__m256i
name|test_mm256_mullo_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mullo_epi64
comment|// CHECK: mul<4 x i64>
return|return
name|_mm256_mullo_epi64
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
name|test_mm256_mask_mullo_epi64
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
comment|// CHECK-LABEL: @test_mm256_mask_mullo_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pmull.q.256
return|return
operator|(
name|__m256i
operator|)
name|_mm256_mask_mullo_epi64
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
name|test_mm256_maskz_mullo_epi64
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
comment|// CHECK-LABEL: @test_mm256_maskz_mullo_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pmull.q.256
return|return
operator|(
name|__m256i
operator|)
name|_mm256_maskz_mullo_epi64
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
name|test_mm_mullo_epi64
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mullo_epi64
comment|// CHECK: mul<2 x i64>
return|return
operator|(
name|__m128i
operator|)
name|_mm_mullo_epi64
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
name|test_mm_mask_mullo_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_mullo_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pmull.q.128
return|return
operator|(
name|__m128i
operator|)
name|_mm_mask_mullo_epi64
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
name|test_mm_maskz_mullo_epi64
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
comment|// CHECK-LABEL: @test_mm_maskz_mullo_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pmull.q.128
return|return
operator|(
name|__m128i
operator|)
name|_mm_maskz_mullo_epi64
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
name|test_mm256_mask_andnot_pd
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
comment|// CHECK-LABEL: @test_mm256_mask_andnot_pd
comment|// CHECK: @llvm.x86.avx512.mask.andn.pd.256
return|return
operator|(
name|__m256d
operator|)
name|_mm256_mask_andnot_pd
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
name|test_mm256_maskz_andnot_pd
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
comment|// CHECK-LABEL: @test_mm256_maskz_andnot_pd
comment|// CHECK: @llvm.x86.avx512.mask.andn.pd.256
return|return
operator|(
name|__m256d
operator|)
name|_mm256_maskz_andnot_pd
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
name|test_mm_mask_andnot_pd
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
comment|// CHECK-LABEL: @test_mm_mask_andnot_pd
comment|// CHECK: @llvm.x86.avx512.mask.andn.pd.128
return|return
operator|(
name|__m128d
operator|)
name|_mm_mask_andnot_pd
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
name|test_mm_maskz_andnot_pd
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
comment|// CHECK-LABEL: @test_mm_maskz_andnot_pd
comment|// CHECK: @llvm.x86.avx512.mask.andn.pd.128
return|return
operator|(
name|__m128d
operator|)
name|_mm_maskz_andnot_pd
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
name|test_mm256_mask_andnot_ps
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
comment|// CHECK-LABEL: @test_mm256_mask_andnot_ps
comment|// CHECK: @llvm.x86.avx512.mask.andn.ps.256
return|return
operator|(
name|__m256
operator|)
name|_mm256_mask_andnot_ps
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
name|test_mm256_maskz_andnot_ps
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
comment|// CHECK-LABEL: @test_mm256_maskz_andnot_ps
comment|// CHECK: @llvm.x86.avx512.mask.andn.ps.256
return|return
operator|(
name|__m256
operator|)
name|_mm256_maskz_andnot_ps
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
name|test_mm_mask_andnot_ps
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
comment|// CHECK-LABEL: @test_mm_mask_andnot_ps
comment|// CHECK: @llvm.x86.avx512.mask.andn.ps.128
return|return
operator|(
name|__m128
operator|)
name|_mm_mask_andnot_ps
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
name|test_mm_maskz_andnot_ps
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
comment|// CHECK-LABEL: @test_mm_maskz_andnot_ps
comment|// CHECK: @llvm.x86.avx512.mask.andn.ps.128
return|return
operator|(
name|__m128
operator|)
name|_mm_maskz_andnot_ps
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
name|test_mm256_mask_and_pd
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
comment|// CHECK-LABEL: @test_mm256_mask_and_pd
comment|// CHECK: @llvm.x86.avx512.mask.and.pd.256
return|return
operator|(
name|__m256d
operator|)
name|_mm256_mask_and_pd
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
name|test_mm256_maskz_and_pd
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
comment|// CHECK-LABEL: @test_mm256_maskz_and_pd
comment|// CHECK: @llvm.x86.avx512.mask.and.pd.256
return|return
operator|(
name|__m256d
operator|)
name|_mm256_maskz_and_pd
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
name|test_mm_mask_and_pd
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
comment|// CHECK-LABEL: @test_mm_mask_and_pd
comment|// CHECK: @llvm.x86.avx512.mask.and.pd.128
return|return
operator|(
name|__m128d
operator|)
name|_mm_mask_and_pd
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
name|test_mm_maskz_and_pd
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
comment|// CHECK-LABEL: @test_mm_maskz_and_pd
comment|// CHECK: @llvm.x86.avx512.mask.and.pd.128
return|return
operator|(
name|__m128d
operator|)
name|_mm_maskz_and_pd
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
name|test_mm256_mask_and_ps
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
comment|// CHECK-LABEL: @test_mm256_mask_and_ps
comment|// CHECK: @llvm.x86.avx512.mask.and.ps.256
return|return
operator|(
name|__m256
operator|)
name|_mm256_mask_and_ps
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
name|test_mm256_maskz_and_ps
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
comment|// CHECK-LABEL: @test_mm256_maskz_and_ps
comment|// CHECK: @llvm.x86.avx512.mask.and.ps.256
return|return
operator|(
name|__m256
operator|)
name|_mm256_maskz_and_ps
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
name|test_mm_mask_and_ps
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
comment|// CHECK-LABEL: @test_mm_mask_and_ps
comment|// CHECK: @llvm.x86.avx512.mask.and.ps.128
return|return
operator|(
name|__m128
operator|)
name|_mm_mask_and_ps
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
name|test_mm_maskz_and_ps
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
comment|// CHECK-LABEL: @test_mm_maskz_and_ps
comment|// CHECK: @llvm.x86.avx512.mask.and.ps.128
return|return
operator|(
name|__m128
operator|)
name|_mm_maskz_and_ps
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
name|test_mm256_mask_xor_pd
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
comment|// CHECK-LABEL: @test_mm256_mask_xor_pd
comment|// CHECK: @llvm.x86.avx512.mask.xor.pd.256
return|return
operator|(
name|__m256d
operator|)
name|_mm256_mask_xor_pd
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
name|test_mm256_maskz_xor_pd
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
comment|// CHECK-LABEL: @test_mm256_maskz_xor_pd
comment|// CHECK: @llvm.x86.avx512.mask.xor.pd.256
return|return
operator|(
name|__m256d
operator|)
name|_mm256_maskz_xor_pd
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
name|test_mm_mask_xor_pd
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
comment|// CHECK-LABEL: @test_mm_mask_xor_pd
comment|// CHECK: @llvm.x86.avx512.mask.xor.pd.128
return|return
operator|(
name|__m128d
operator|)
name|_mm_mask_xor_pd
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
name|test_mm_maskz_xor_pd
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
comment|// CHECK-LABEL: @test_mm_maskz_xor_pd
comment|// CHECK: @llvm.x86.avx512.mask.xor.pd.128
return|return
operator|(
name|__m128d
operator|)
name|_mm_maskz_xor_pd
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
name|test_mm256_mask_xor_ps
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
comment|// CHECK-LABEL: @test_mm256_mask_xor_ps
comment|// CHECK: @llvm.x86.avx512.mask.xor.ps.256
return|return
operator|(
name|__m256
operator|)
name|_mm256_mask_xor_ps
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
name|test_mm256_maskz_xor_ps
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
comment|// CHECK-LABEL: @test_mm256_maskz_xor_ps
comment|// CHECK: @llvm.x86.avx512.mask.xor.ps.256
return|return
operator|(
name|__m256
operator|)
name|_mm256_maskz_xor_ps
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
name|test_mm_mask_xor_ps
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
comment|// CHECK-LABEL: @test_mm_mask_xor_ps
comment|// CHECK: @llvm.x86.avx512.mask.xor.ps.128
return|return
operator|(
name|__m128
operator|)
name|_mm_mask_xor_ps
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
name|test_mm_maskz_xor_ps
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
comment|// CHECK-LABEL: @test_mm_maskz_xor_ps
comment|// CHECK: @llvm.x86.avx512.mask.xor.ps.128
return|return
operator|(
name|__m128
operator|)
name|_mm_maskz_xor_ps
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
name|test_mm256_mask_or_pd
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
comment|// CHECK-LABEL: @test_mm256_mask_or_pd
comment|// CHECK: @llvm.x86.avx512.mask.or.pd.256
return|return
operator|(
name|__m256d
operator|)
name|_mm256_mask_or_pd
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
name|test_mm256_maskz_or_pd
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
comment|// CHECK-LABEL: @test_mm256_maskz_or_pd
comment|// CHECK: @llvm.x86.avx512.mask.or.pd.256
return|return
operator|(
name|__m256d
operator|)
name|_mm256_maskz_or_pd
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
name|test_mm_mask_or_pd
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
comment|// CHECK-LABEL: @test_mm_mask_or_pd
comment|// CHECK: @llvm.x86.avx512.mask.or.pd.128
return|return
operator|(
name|__m128d
operator|)
name|_mm_mask_or_pd
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
name|test_mm_maskz_or_pd
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
comment|// CHECK-LABEL: @test_mm_maskz_or_pd
comment|// CHECK: @llvm.x86.avx512.mask.or.pd.128
return|return
operator|(
name|__m128d
operator|)
name|_mm_maskz_or_pd
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
name|test_mm256_mask_or_ps
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
comment|// CHECK-LABEL: @test_mm256_mask_or_ps
comment|// CHECK: @llvm.x86.avx512.mask.or.ps.256
return|return
operator|(
name|__m256
operator|)
name|_mm256_mask_or_ps
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
name|test_mm256_maskz_or_ps
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
comment|// CHECK-LABEL: @test_mm256_maskz_or_ps
comment|// CHECK: @llvm.x86.avx512.mask.or.ps.256
return|return
operator|(
name|__m256
operator|)
name|_mm256_maskz_or_ps
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
name|test_mm_mask_or_ps
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
comment|// CHECK-LABEL: @test_mm_mask_or_ps
comment|// CHECK: @llvm.x86.avx512.mask.or.ps.128
return|return
operator|(
name|__m128
operator|)
name|_mm_mask_or_ps
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
name|test_mm_maskz_or_ps
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
comment|// CHECK-LABEL: @test_mm_maskz_or_ps
comment|// CHECK: @llvm.x86.avx512.mask.or.ps.128
return|return
operator|(
name|__m128
operator|)
name|_mm_maskz_or_ps
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
name|test_mm_cvtpd_epi64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.128
return|return
name|_mm_cvtpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtpd_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.128
return|return
name|_mm_mask_cvtpd_epi64
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
name|test_mm_maskz_cvtpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.128
return|return
name|_mm_maskz_cvtpd_epi64
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
name|test_mm256_cvtpd_epi64
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.256
return|return
name|_mm256_cvtpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtpd_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.256
return|return
name|_mm256_mask_cvtpd_epi64
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
name|test_mm256_maskz_cvtpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.256
return|return
name|_mm256_maskz_cvtpd_epi64
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
name|test_mm_cvtpd_epu64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.128
return|return
name|_mm_cvtpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtpd_epu64
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
comment|// CHECK-LABEL: @test_mm_mask_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.128
return|return
name|_mm_mask_cvtpd_epu64
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
name|test_mm_maskz_cvtpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.128
return|return
name|_mm_maskz_cvtpd_epu64
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
name|test_mm256_cvtpd_epu64
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.256
return|return
name|_mm256_cvtpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtpd_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.256
return|return
name|_mm256_mask_cvtpd_epu64
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
name|test_mm256_maskz_cvtpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.256
return|return
name|_mm256_maskz_cvtpd_epu64
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
name|test_mm_cvtps_epi64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.128
return|return
name|_mm_cvtps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtps_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.128
return|return
name|_mm_mask_cvtps_epi64
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
name|test_mm_maskz_cvtps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.128
return|return
name|_mm_maskz_cvtps_epi64
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
name|test_mm256_cvtps_epi64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.256
return|return
name|_mm256_cvtps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtps_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.256
return|return
name|_mm256_mask_cvtps_epi64
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
name|test_mm256_maskz_cvtps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.256
return|return
name|_mm256_maskz_cvtps_epi64
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
name|test_mm_cvtps_epu64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.128
return|return
name|_mm_cvtps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvtps_epu64
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
comment|// CHECK-LABEL: @test_mm_mask_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.128
return|return
name|_mm_mask_cvtps_epu64
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
name|test_mm_maskz_cvtps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.128
return|return
name|_mm_maskz_cvtps_epu64
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
name|test_mm256_cvtps_epu64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.256
return|return
name|_mm256_cvtps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvtps_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.256
return|return
name|_mm256_mask_cvtps_epu64
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
name|test_mm256_maskz_cvtps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.256
return|return
name|_mm256_maskz_cvtps_epu64
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
name|test_mm_cvtepi64_pd
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.128
return|return
name|_mm_cvtepi64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_cvtepi64_pd
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.128
return|return
name|_mm_mask_cvtepi64_pd
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
name|test_mm_maskz_cvtepi64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.128
return|return
name|_mm_maskz_cvtepi64_pd
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
name|test_mm256_cvtepi64_pd
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.256
return|return
name|_mm256_cvtepi64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_cvtepi64_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.256
return|return
name|_mm256_mask_cvtepi64_pd
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
name|test_mm256_maskz_cvtepi64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.256
return|return
name|_mm256_maskz_cvtepi64_pd
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
name|test_mm_cvtepi64_ps
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.128
return|return
name|_mm_cvtepi64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_cvtepi64_ps
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.128
return|return
name|_mm_mask_cvtepi64_ps
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
name|test_mm_maskz_cvtepi64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.128
return|return
name|_mm_maskz_cvtepi64_ps
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
name|test_mm256_cvtepi64_ps
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.256
return|return
name|_mm256_cvtepi64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_mask_cvtepi64_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.256
return|return
name|_mm256_mask_cvtepi64_ps
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
name|test_mm256_maskz_cvtepi64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.256
return|return
name|_mm256_maskz_cvtepi64_ps
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
name|test_mm_cvttpd_epi64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.128
return|return
name|_mm_cvttpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttpd_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.128
return|return
name|_mm_mask_cvttpd_epi64
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
name|test_mm_maskz_cvttpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.128
return|return
name|_mm_maskz_cvttpd_epi64
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
name|test_mm256_cvttpd_epi64
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.256
return|return
name|_mm256_cvttpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvttpd_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.256
return|return
name|_mm256_mask_cvttpd_epi64
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
name|test_mm256_maskz_cvttpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.256
return|return
name|_mm256_maskz_cvttpd_epi64
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
name|test_mm_cvttpd_epu64
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.128
return|return
name|_mm_cvttpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttpd_epu64
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
comment|// CHECK-LABEL: @test_mm_mask_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.128
return|return
name|_mm_mask_cvttpd_epu64
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
name|test_mm_maskz_cvttpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.128
return|return
name|_mm_maskz_cvttpd_epu64
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
name|test_mm256_cvttpd_epu64
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.256
return|return
name|_mm256_cvttpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvttpd_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.256
return|return
name|_mm256_mask_cvttpd_epu64
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
name|test_mm256_maskz_cvttpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.256
return|return
name|_mm256_maskz_cvttpd_epu64
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
name|test_mm_cvttps_epi64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.128
return|return
name|_mm_cvttps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttps_epi64
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
comment|// CHECK-LABEL: @test_mm_mask_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.128
return|return
name|_mm_mask_cvttps_epi64
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
name|test_mm_maskz_cvttps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.128
return|return
name|_mm_maskz_cvttps_epi64
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
name|test_mm256_cvttps_epi64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.256
return|return
name|_mm256_cvttps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvttps_epi64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.256
return|return
name|_mm256_mask_cvttps_epi64
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
name|test_mm256_maskz_cvttps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.256
return|return
name|_mm256_maskz_cvttps_epi64
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
name|test_mm_cvttps_epu64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.128
return|return
name|_mm_cvttps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_cvttps_epu64
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
comment|// CHECK-LABEL: @test_mm_mask_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.128
return|return
name|_mm_mask_cvttps_epu64
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
name|test_mm_maskz_cvttps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.128
return|return
name|_mm_maskz_cvttps_epu64
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
name|test_mm256_cvttps_epu64
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.256
return|return
name|_mm256_cvttps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_cvttps_epu64
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.256
return|return
name|_mm256_mask_cvttps_epu64
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
name|test_mm256_maskz_cvttps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.256
return|return
name|_mm256_maskz_cvttps_epu64
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
name|test_mm_cvtepu64_pd
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.128
return|return
name|_mm_cvtepu64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_cvtepu64_pd
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.128
return|return
name|_mm_mask_cvtepu64_pd
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
name|test_mm_maskz_cvtepu64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.128
return|return
name|_mm_maskz_cvtepu64_pd
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
name|test_mm256_cvtepu64_pd
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.256
return|return
name|_mm256_cvtepu64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_cvtepu64_pd
parameter_list|(
name|__m256d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.256
return|return
name|_mm256_mask_cvtepu64_pd
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
name|test_mm256_maskz_cvtepu64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.256
return|return
name|_mm256_maskz_cvtepu64_pd
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
name|test_mm_cvtepu64_ps
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.128
return|return
name|_mm_cvtepu64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_cvtepu64_ps
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
comment|// CHECK-LABEL: @test_mm_mask_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.128
return|return
name|_mm_mask_cvtepu64_ps
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
name|test_mm_maskz_cvtepu64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.128
return|return
name|_mm_maskz_cvtepu64_ps
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
name|test_mm256_cvtepu64_ps
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.256
return|return
name|_mm256_cvtepu64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_mask_cvtepu64_ps
parameter_list|(
name|__m128
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.256
return|return
name|_mm256_mask_cvtepu64_ps
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
name|test_mm256_maskz_cvtepu64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.256
return|return
name|_mm256_maskz_cvtepu64_ps
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
name|test_mm_range_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.128
return|return
name|_mm_range_pd
argument_list|(
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
name|test_mm_mask_range_pd
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
comment|// CHECK-LABEL: @test_mm_mask_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.128
return|return
name|_mm_mask_range_pd
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
name|__m128d
name|test_mm_maskz_range_pd
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
comment|// CHECK-LABEL: @test_mm_maskz_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.128
return|return
name|_mm_maskz_range_pd
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
name|__m256d
name|test_mm256_range_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m256d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.256
return|return
name|_mm256_range_pd
argument_list|(
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
name|__m256d
name|test_mm256_mask_range_pd
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
comment|// CHECK-LABEL: @test_mm256_mask_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.256
return|return
name|_mm256_mask_range_pd
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
name|__m256d
name|test_mm256_maskz_range_pd
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
comment|// CHECK-LABEL: @test_mm256_maskz_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.256
return|return
name|_mm256_maskz_range_pd
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
name|__m128
name|test_mm_range_ps
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.128
return|return
name|_mm_range_ps
argument_list|(
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
name|test_mm_mask_range_ps
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
comment|// CHECK-LABEL: @test_mm_mask_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.128
return|return
name|_mm_mask_range_ps
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
name|test_mm_maskz_range_ps
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
comment|// CHECK-LABEL: @test_mm_maskz_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.128
return|return
name|_mm_maskz_range_ps
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
name|test_mm256_range_ps
parameter_list|(
name|__m256
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.256
return|return
name|_mm256_range_ps
argument_list|(
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
name|test_mm256_mask_range_ps
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
comment|// CHECK-LABEL: @test_mm256_mask_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.256
return|return
name|_mm256_mask_range_ps
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
name|test_mm256_maskz_range_ps
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
comment|// CHECK-LABEL: @test_mm256_maskz_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.256
return|return
name|_mm256_maskz_range_ps
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
name|test_mm_reduce_pd
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.128
return|return
name|_mm_reduce_pd
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
name|test_mm_mask_reduce_pd
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
comment|// CHECK-LABEL: @test_mm_mask_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.128
return|return
name|_mm_mask_reduce_pd
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
name|test_mm_maskz_reduce_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.128
return|return
name|_mm_maskz_reduce_pd
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
name|test_mm256_reduce_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.256
return|return
name|_mm256_reduce_pd
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
name|test_mm256_mask_reduce_pd
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
comment|// CHECK-LABEL: @test_mm256_mask_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.256
return|return
name|_mm256_mask_reduce_pd
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
name|test_mm256_maskz_reduce_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.256
return|return
name|_mm256_maskz_reduce_pd
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
name|test_mm_reduce_ps
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.128
return|return
name|_mm_reduce_ps
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
name|test_mm_mask_reduce_ps
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
comment|// CHECK-LABEL: @test_mm_mask_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.128
return|return
name|_mm_mask_reduce_ps
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
name|test_mm_maskz_reduce_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.128
return|return
name|_mm_maskz_reduce_ps
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
name|test_mm256_reduce_ps
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.256
return|return
name|_mm256_reduce_ps
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
name|test_mm256_mask_reduce_ps
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
comment|// CHECK-LABEL: @test_mm256_mask_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.256
return|return
name|_mm256_mask_reduce_ps
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
name|test_mm256_maskz_reduce_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.256
return|return
name|_mm256_maskz_reduce_ps
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
name|__mmask8
name|test_mm_movepi32_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movepi32_mask
comment|// CHECK: @llvm.x86.avx512.cvtd2mask.128
return|return
name|_mm_movepi32_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_movepi32_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movepi32_mask
comment|// CHECK: @llvm.x86.avx512.cvtd2mask.256
return|return
name|_mm256_movepi32_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_movm_epi32
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movm_epi32
comment|// CHECK: @llvm.x86.avx512.cvtmask2d.128
return|return
name|_mm_movm_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_movm_epi32
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movm_epi32
comment|// CHECK: @llvm.x86.avx512.cvtmask2d.256
return|return
name|_mm256_movm_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_movm_epi64
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movm_epi64
comment|// CHECK: @llvm.x86.avx512.cvtmask2q.128
return|return
name|_mm_movm_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_movm_epi64
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movm_epi64
comment|// CHECK: @llvm.x86.avx512.cvtmask2q.256
return|return
name|_mm256_movm_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_movepi64_mask
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_movepi64_mask
comment|// CHECK: @llvm.x86.avx512.cvtq2mask.128
return|return
name|_mm_movepi64_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_movepi64_mask
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_movepi64_mask
comment|// CHECK: @llvm.x86.avx512.cvtq2mask.256
return|return
name|_mm256_movepi64_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_broadcast_f32x2
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm256_broadcast_f32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_broadcast_f32x2
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
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm256_mask_broadcast_f32x2
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
name|test_mm256_maskz_broadcast_f32x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm256_maskz_broadcast_f32x2
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_broadcast_f64x2
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf64x2
return|return
name|_mm256_broadcast_f64x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_broadcast_f64x2
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
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf64x2
return|return
name|_mm256_mask_broadcast_f64x2
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
name|test_mm256_maskz_broadcast_f64x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf64x2
return|return
name|_mm256_maskz_broadcast_f64x2
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
name|test_mm_broadcast_i32x2
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm_broadcast_i32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_broadcast_i32x2
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
comment|// CHECK-LABEL: @test_mm_mask_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm_mask_broadcast_i32x2
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
name|test_mm_maskz_broadcast_i32x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm_maskz_broadcast_i32x2
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
name|test_mm256_broadcast_i32x2
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm256_broadcast_i32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_broadcast_i32x2
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
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm256_mask_broadcast_i32x2
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
name|test_mm256_maskz_broadcast_i32x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm256_maskz_broadcast_i32x2
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
name|test_mm256_broadcast_i64x2
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_broadcast_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti64x2
return|return
name|_mm256_broadcast_i64x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_broadcast_i64x2
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
comment|// CHECK-LABEL: @test_mm256_mask_broadcast_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti64x2
return|return
name|_mm256_mask_broadcast_i64x2
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
name|test_mm256_maskz_broadcast_i64x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_broadcast_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti64x2
return|return
name|_mm256_maskz_broadcast_i64x2
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm256_extractf64x2_pd
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extractf64x2_pd
comment|// CHECK: @llvm.x86.avx512.mask.vextractf64x2
return|return
name|_mm256_extractf64x2_pd
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm256_mask_extractf64x2_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_extractf64x2_pd
comment|// CHECK: @llvm.x86.avx512.mask.vextractf64x2
return|return
name|_mm256_mask_extractf64x2_pd
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
name|__m128d
name|test_mm256_maskz_extractf64x2_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_extractf64x2_pd
comment|// CHECK: @llvm.x86.avx512.mask.vextractf64x2
return|return
name|_mm256_maskz_extractf64x2_pd
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
name|test_mm256_extracti64x2_epi64
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_extracti64x2_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vextracti64x2
return|return
name|_mm256_extracti64x2_epi64
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
name|test_mm256_mask_extracti64x2_epi64
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
comment|// CHECK-LABEL: @test_mm256_mask_extracti64x2_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vextracti64x2
return|return
name|_mm256_mask_extracti64x2_epi64
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
name|test_mm256_maskz_extracti64x2_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_extracti64x2_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vextracti64x2
return|return
name|_mm256_maskz_extracti64x2_epi64
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
name|__m256d
name|test_mm256_insertf64x2
parameter_list|(
name|__m256d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_insertf64x2
comment|// CHECK: @llvm.x86.avx512.mask.insertf64x2
return|return
name|_mm256_insertf64x2
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
name|__m256d
name|test_mm256_mask_insertf64x2
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
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_insertf64x2
comment|// CHECK: @llvm.x86.avx512.mask.insertf64x2
return|return
name|_mm256_mask_insertf64x2
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
name|__m256d
name|test_mm256_maskz_insertf64x2
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_insertf64x2
comment|// CHECK: @llvm.x86.avx512.mask.insertf64x2
return|return
name|_mm256_maskz_insertf64x2
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
name|test_mm256_inserti64x2
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_inserti64x2
comment|// CHECK: @llvm.x86.avx512.mask.inserti64x2
return|return
name|_mm256_inserti64x2
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
name|test_mm256_mask_inserti64x2
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
comment|// CHECK-LABEL: @test_mm256_mask_inserti64x2
comment|// CHECK: @llvm.x86.avx512.mask.inserti64x2
return|return
name|_mm256_mask_inserti64x2
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
name|test_mm256_maskz_inserti64x2
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
comment|// CHECK-LABEL: @test_mm256_maskz_inserti64x2
comment|// CHECK: @llvm.x86.avx512.mask.inserti64x2
return|return
name|_mm256_maskz_inserti64x2
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
name|__mmask8
name|test_mm_mask_fpclass_pd_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.128
return|return
name|_mm_mask_fpclass_pd_mask
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
name|__mmask8
name|test_mm_fpclass_pd_mask
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.128
return|return
name|_mm_fpclass_pd_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_fpclass_pd_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.256
return|return
name|_mm256_mask_fpclass_pd_mask
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
name|__mmask8
name|test_mm256_fpclass_pd_mask
parameter_list|(
name|__m256d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.256
return|return
name|_mm256_fpclass_pd_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_mask_fpclass_ps_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.128
return|return
name|_mm_mask_fpclass_ps_mask
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
name|__mmask8
name|test_mm_fpclass_ps_mask
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.128
return|return
name|_mm_fpclass_ps_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm256_mask_fpclass_ps_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.256
return|return
name|_mm256_mask_fpclass_ps_mask
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
name|__mmask8
name|test_mm256_fpclass_ps_mask
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.256
return|return
name|_mm256_fpclass_ps_mask
argument_list|(
name|__A
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

end_unit

