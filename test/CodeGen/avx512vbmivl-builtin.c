begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512vbmi -target-feature +avx512vl -target-feature +avx512bw -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m128i
name|test_mm_permutexvar_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_permutexvar_epi8
comment|// CHECK: @llvm.x86.avx512.mask.permvar.qi.128
return|return
name|_mm_permutexvar_epi8
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
name|test_mm_maskz_permutexvar_epi8
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
comment|// CHECK-LABEL: @test_mm_maskz_permutexvar_epi8
comment|// CHECK: @llvm.x86.avx512.mask.permvar.qi.128
return|return
name|_mm_maskz_permutexvar_epi8
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
name|test_mm_mask_permutexvar_epi8
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
comment|// CHECK-LABEL: @test_mm_mask_permutexvar_epi8
comment|// CHECK: @llvm.x86.avx512.mask.permvar.qi.128
return|return
name|_mm_mask_permutexvar_epi8
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
name|test_mm256_permutexvar_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_permutexvar_epi8
comment|// CHECK: @llvm.x86.avx512.mask.permvar.qi.256
return|return
name|_mm256_permutexvar_epi8
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
name|test_mm256_maskz_permutexvar_epi8
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
comment|// CHECK-LABEL: @test_mm256_maskz_permutexvar_epi8
comment|// CHECK: @llvm.x86.avx512.mask.permvar.qi.256
return|return
name|_mm256_maskz_permutexvar_epi8
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
name|test_mm256_mask_permutexvar_epi8
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
comment|// CHECK-LABEL: @test_mm256_mask_permutexvar_epi8
comment|// CHECK: @llvm.x86.avx512.mask.permvar.qi.256
return|return
name|_mm256_mask_permutexvar_epi8
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
name|test_mm_mask2_permutex2var_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask2_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.qi.128
return|return
name|_mm_mask2_permutex2var_epi8
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
name|test_mm256_mask2_permutex2var_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask2_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.qi.256
return|return
name|_mm256_mask2_permutex2var_epi8
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
name|test_mm_permutex2var_epi8
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
comment|// CHECK-LABEL: @test_mm_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.128
return|return
name|_mm_permutex2var_epi8
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
name|test_mm_mask_permutex2var_epi8
parameter_list|(
name|__m128i
name|__A
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m128i
name|__I
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.128
return|return
name|_mm_mask_permutex2var_epi8
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
name|test_mm_maskz_permutex2var_epi8
parameter_list|(
name|__mmask16
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
comment|// CHECK-LABEL: @test_mm_maskz_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.qi.128
return|return
name|_mm_maskz_permutex2var_epi8
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
name|test_mm256_permutex2var_epi8
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
comment|// CHECK-LABEL: @test_mm256_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.256
return|return
name|_mm256_permutex2var_epi8
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
name|test_mm256_mask_permutex2var_epi8
parameter_list|(
name|__m256i
name|__A
parameter_list|,
name|__mmask32
name|__U
parameter_list|,
name|__m256i
name|__I
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.256
return|return
name|_mm256_mask_permutex2var_epi8
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
name|test_mm256_maskz_permutex2var_epi8
parameter_list|(
name|__mmask32
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
comment|// CHECK-LABEL: @test_mm256_maskz_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.qi.256
return|return
name|_mm256_maskz_permutex2var_epi8
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
name|test_mm_mask_multishift_epi64_epi8
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_multishift_epi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmultishift.qb.128
return|return
name|_mm_mask_multishift_epi64_epi8
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
name|test_mm_maskz_multishift_epi64_epi8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_multishift_epi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmultishift.qb.128
return|return
name|_mm_maskz_multishift_epi64_epi8
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
name|test_mm_multishift_epi64_epi8
parameter_list|(
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_multishift_epi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmultishift.qb.128
return|return
name|_mm_multishift_epi64_epi8
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
name|test_mm256_mask_multishift_epi64_epi8
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_mask_multishift_epi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmultishift.qb.256
return|return
name|_mm256_mask_multishift_epi64_epi8
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
name|test_mm256_maskz_multishift_epi64_epi8
parameter_list|(
name|__mmask32
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_multishift_epi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmultishift.qb.256
return|return
name|_mm256_maskz_multishift_epi64_epi8
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
name|test_mm256_multishift_epi64_epi8
parameter_list|(
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_multishift_epi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmultishift.qb.256
return|return
name|_mm256_multishift_epi64_epi8
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

end_unit

