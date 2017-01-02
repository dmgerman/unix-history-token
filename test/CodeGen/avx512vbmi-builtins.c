begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512vbmi -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m512i
name|test_mm512_mask2_permutex2var_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask2_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.mask.vpermi2var.qi.512
return|return
name|_mm512_mask2_permutex2var_epi8
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
name|__m512i
name|test_mm512_permutex2var_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.512
return|return
name|_mm512_permutex2var_epi8
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
name|__m512i
name|test_mm512_mask_permutex2var_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.mask.vpermt2var.qi.512
return|return
name|_mm512_mask_permutex2var_epi8
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
name|__m512i
name|test_mm512_maskz_permutex2var_epi8
parameter_list|(
name|__mmask64
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__I
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutex2var_epi8
comment|// CHECK: @llvm.x86.avx512.maskz.vpermt2var.qi.512
return|return
name|_mm512_maskz_permutex2var_epi8
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
name|__m512i
name|test_mm512_permutexvar_epi8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_permutexvar_epi8
comment|// CHECK: @llvm.x86.avx512.mask.permvar.qi.512
return|return
name|_mm512_permutexvar_epi8
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
name|test_mm512_maskz_permutexvar_epi8
parameter_list|(
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_permutexvar_epi8
comment|// CHECK: @llvm.x86.avx512.mask.permvar.qi.512
return|return
name|_mm512_maskz_permutexvar_epi8
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
name|__m512i
name|test_mm512_mask_permutexvar_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_permutexvar_epi8
comment|// CHECK: @llvm.x86.avx512.mask.permvar.qi.512
return|return
name|_mm512_mask_permutexvar_epi8
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
name|__m512i
name|test_mm512_mask_multishift_epi64_epi8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_multishift_epi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmultishift.qb.512
return|return
name|_mm512_mask_multishift_epi64_epi8
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
name|__m512i
name|test_mm512_maskz_multishift_epi64_epi8
parameter_list|(
name|__mmask64
name|__M
parameter_list|,
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_multishift_epi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmultishift.qb.512
return|return
name|_mm512_maskz_multishift_epi64_epi8
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
name|__m512i
name|test_mm512_multishift_epi64_epi8
parameter_list|(
name|__m512i
name|__X
parameter_list|,
name|__m512i
name|__Y
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_multishift_epi64_epi8
comment|// CHECK: @llvm.x86.avx512.mask.pmultishift.qb.512
return|return
name|_mm512_multishift_epi64_epi8
argument_list|(
name|__X
argument_list|,
name|__Y
argument_list|)
return|;
block|}
end_function

end_unit

