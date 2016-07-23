begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +avx512ifma -target-feature +avx512vl -emit-llvm -o - -Werror | FileCheck %s
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
name|__m128i
name|test_mm_madd52hi_epu64
parameter_list|(
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|,
name|__m128i
name|__Z
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_madd52hi_epu64
comment|// CHECK: @llvm.x86.avx512.mask.vpmadd52h.uq.128
return|return
name|_mm_madd52hi_epu64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_madd52hi_epu64
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
comment|// CHECK-LABEL: @test_mm_mask_madd52hi_epu64
comment|// CHECK: @llvm.x86.avx512.mask.vpmadd52h.uq.128
return|return
name|_mm_mask_madd52hi_epu64
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
name|test_mm_maskz_madd52hi_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|,
name|__m128i
name|__Z
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_madd52hi_epu64
comment|// CHECK: @llvm.x86.avx512.maskz.vpmadd52h.uq.128
return|return
name|_mm_maskz_madd52hi_epu64
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_madd52hi_epu64
parameter_list|(
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|,
name|__m256i
name|__Z
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_madd52hi_epu64
comment|// CHECK: @llvm.x86.avx512.mask.vpmadd52h.uq.256
return|return
name|_mm256_madd52hi_epu64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_madd52hi_epu64
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
comment|// CHECK-LABEL: @test_mm256_mask_madd52hi_epu64
comment|// CHECK: @llvm.x86.avx512.mask.vpmadd52h.uq.256
return|return
name|_mm256_mask_madd52hi_epu64
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
name|test_mm256_maskz_madd52hi_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|,
name|__m256i
name|__Z
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_madd52hi_epu64
comment|// CHECK: @llvm.x86.avx512.maskz.vpmadd52h.uq.256
return|return
name|_mm256_maskz_madd52hi_epu64
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_madd52lo_epu64
parameter_list|(
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|,
name|__m128i
name|__Z
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_madd52lo_epu64
comment|// CHECK: @llvm.x86.avx512.mask.vpmadd52l.uq.128
return|return
name|_mm_madd52lo_epu64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_madd52lo_epu64
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
comment|// CHECK-LABEL: @test_mm_mask_madd52lo_epu64
comment|// CHECK: @llvm.x86.avx512.mask.vpmadd52l.uq.128
return|return
name|_mm_mask_madd52lo_epu64
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
name|test_mm_maskz_madd52lo_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__X
parameter_list|,
name|__m128i
name|__Y
parameter_list|,
name|__m128i
name|__Z
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_madd52lo_epu64
comment|// CHECK: @llvm.x86.avx512.maskz.vpmadd52l.uq.128
return|return
name|_mm_maskz_madd52lo_epu64
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_madd52lo_epu64
parameter_list|(
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|,
name|__m256i
name|__Z
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_madd52lo_epu64
comment|// CHECK: @llvm.x86.avx512.mask.vpmadd52l.uq.256
return|return
name|_mm256_madd52lo_epu64
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_madd52lo_epu64
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
comment|// CHECK-LABEL: @test_mm256_mask_madd52lo_epu64
comment|// CHECK: @llvm.x86.avx512.mask.vpmadd52l.uq.256
return|return
name|_mm256_mask_madd52lo_epu64
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
name|test_mm256_maskz_madd52lo_epu64
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m256i
name|__X
parameter_list|,
name|__m256i
name|__Y
parameter_list|,
name|__m256i
name|__Z
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_maskz_madd52lo_epu64
comment|// CHECK: @llvm.x86.avx512.mask.vpmadd52l.uq.256
return|return
name|_mm256_maskz_madd52lo_epu64
argument_list|(
name|__M
argument_list|,
name|__X
argument_list|,
name|__Y
argument_list|,
name|__Z
argument_list|)
return|;
block|}
end_function

end_unit

