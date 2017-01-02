begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx512f -target-feature +avx512er -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<immintrin.h>
end_include

begin_function
name|__m512d
name|test_mm512_rsqrt28_round_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rsqrt28_round_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt28.pd
return|return
name|_mm512_rsqrt28_round_pd
argument_list|(
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_rsqrt28_round_pd
parameter_list|(
name|__m512d
name|s
parameter_list|,
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rsqrt28_round_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt28.pd
return|return
name|_mm512_mask_rsqrt28_round_pd
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_rsqrt28_round_pd
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rsqrt28_round_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt28.pd
return|return
name|_mm512_maskz_rsqrt28_round_pd
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_rsqrt28_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rsqrt28_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt28.pd
return|return
name|_mm512_rsqrt28_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_rsqrt28_pd
parameter_list|(
name|__m512d
name|s
parameter_list|,
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rsqrt28_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt28.pd
return|return
name|_mm512_mask_rsqrt28_pd
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_rsqrt28_pd
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rsqrt28_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt28.pd
return|return
name|_mm512_maskz_rsqrt28_pd
argument_list|(
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_rsqrt28_round_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rsqrt28_round_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ps
return|return
name|_mm512_rsqrt28_round_ps
argument_list|(
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_rsqrt28_round_ps
parameter_list|(
name|__m512
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rsqrt28_round_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ps
return|return
name|_mm512_mask_rsqrt28_round_ps
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_rsqrt28_round_ps
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rsqrt28_round_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ps
return|return
name|_mm512_maskz_rsqrt28_round_ps
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_rsqrt28_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rsqrt28_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ps
return|return
name|_mm512_rsqrt28_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_rsqrt28_ps
parameter_list|(
name|__m512
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rsqrt28_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ps
return|return
name|_mm512_mask_rsqrt28_ps
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_rsqrt28_ps
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rsqrt28_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ps
return|return
name|_mm512_maskz_rsqrt28_ps
argument_list|(
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_rsqrt28_round_ss
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rsqrt28_round_ss
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ss
return|return
name|_mm_rsqrt28_round_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_rsqrt28_round_ss
parameter_list|(
name|__m128
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rsqrt28_round_ss
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ss
return|return
name|_mm_mask_rsqrt28_round_ss
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_rsqrt28_round_ss
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rsqrt28_round_ss
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ss
return|return
name|_mm_maskz_rsqrt28_round_ss
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_rsqrt28_ss
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rsqrt28_ss
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ss
return|return
name|_mm_rsqrt28_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_rsqrt28_ss
parameter_list|(
name|__m128
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rsqrt28_ss
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ss
return|return
name|_mm_mask_rsqrt28_ss
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_rsqrt28_ss
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rsqrt28_ss
comment|// CHECK: @llvm.x86.avx512.rsqrt28.ss
return|return
name|_mm_maskz_rsqrt28_ss
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_rsqrt28_round_sd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rsqrt28_round_sd
comment|// CHECK: @llvm.x86.avx512.rsqrt28.sd
return|return
name|_mm_rsqrt28_round_sd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_rsqrt28_round_sd
parameter_list|(
name|__m128d
name|s
parameter_list|,
name|__mmask8
name|m
parameter_list|,
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rsqrt28_round_sd
comment|// CHECK: @llvm.x86.avx512.rsqrt28.sd
return|return
name|_mm_mask_rsqrt28_round_sd
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_rsqrt28_round_sd
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rsqrt28_round_sd
comment|// CHECK: @llvm.x86.avx512.rsqrt28.sd
return|return
name|_mm_maskz_rsqrt28_round_sd
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_rcp28_round_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rcp28_round_pd
comment|// CHECK: @llvm.x86.avx512.rcp28.pd
return|return
name|_mm512_rcp28_round_pd
argument_list|(
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_rcp28_round_pd
parameter_list|(
name|__m512d
name|s
parameter_list|,
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rcp28_round_pd
comment|// CHECK: @llvm.x86.avx512.rcp28.pd
return|return
name|_mm512_mask_rcp28_round_pd
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_rcp28_round_pd
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rcp28_round_pd
comment|// CHECK: @llvm.x86.avx512.rcp28.pd
return|return
name|_mm512_maskz_rcp28_round_pd
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_rcp28_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rcp28_pd
comment|// CHECK: @llvm.x86.avx512.rcp28.pd
return|return
name|_mm512_rcp28_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_rcp28_pd
parameter_list|(
name|__m512d
name|s
parameter_list|,
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rcp28_pd
comment|// CHECK: @llvm.x86.avx512.rcp28.pd
return|return
name|_mm512_mask_rcp28_pd
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_rcp28_pd
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rcp28_pd
comment|// CHECK: @llvm.x86.avx512.rcp28.pd
return|return
name|_mm512_maskz_rcp28_pd
argument_list|(
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_rcp28_round_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rcp28_round_ps
comment|// CHECK: @llvm.x86.avx512.rcp28.ps
return|return
name|_mm512_rcp28_round_ps
argument_list|(
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_rcp28_round_ps
parameter_list|(
name|__m512
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rcp28_round_ps
comment|// CHECK: @llvm.x86.avx512.rcp28.ps
return|return
name|_mm512_mask_rcp28_round_ps
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_rcp28_round_ps
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rcp28_round_ps
comment|// CHECK: @llvm.x86.avx512.rcp28.ps
return|return
name|_mm512_maskz_rcp28_round_ps
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_rcp28_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rcp28_ps
comment|// CHECK: @llvm.x86.avx512.rcp28.ps
return|return
name|_mm512_rcp28_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_rcp28_ps
parameter_list|(
name|__m512
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_rcp28_ps
comment|// CHECK: @llvm.x86.avx512.rcp28.ps
return|return
name|_mm512_mask_rcp28_ps
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_rcp28_ps
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_rcp28_ps
comment|// CHECK: @llvm.x86.avx512.rcp28.ps
return|return
name|_mm512_maskz_rcp28_ps
argument_list|(
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_rcp28_round_ss
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rcp28_round_ss
comment|// CHECK: @llvm.x86.avx512.rcp28.ss
return|return
name|_mm_rcp28_round_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_rcp28_round_ss
parameter_list|(
name|__m128
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rcp28_round_ss
comment|// CHECK: @llvm.x86.avx512.rcp28.ss
return|return
name|_mm_mask_rcp28_round_ss
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_rcp28_round_ss
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rcp28_round_ss
comment|// CHECK: @llvm.x86.avx512.rcp28.ss
return|return
name|_mm_maskz_rcp28_round_ss
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_rcp28_ss
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rcp28_ss
comment|// CHECK: @llvm.x86.avx512.rcp28.ss
return|return
name|_mm_rcp28_ss
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_rcp28_ss
parameter_list|(
name|__m128
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rcp28_ss
comment|// CHECK: @llvm.x86.avx512.rcp28.ss
return|return
name|_mm_mask_rcp28_ss
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskz_rcp28_ss
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m128
name|a
parameter_list|,
name|__m128
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rcp28_ss
comment|// CHECK: @llvm.x86.avx512.rcp28.ss
return|return
name|_mm_maskz_rcp28_ss
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_rcp28_round_sd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rcp28_round_sd
comment|// CHECK: @llvm.x86.avx512.rcp28.sd
return|return
name|_mm_rcp28_round_sd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_rcp28_round_sd
parameter_list|(
name|__m128d
name|s
parameter_list|,
name|__mmask8
name|m
parameter_list|,
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rcp28_round_sd
comment|// CHECK: @llvm.x86.avx512.rcp28.sd
return|return
name|_mm_mask_rcp28_round_sd
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_rcp28_round_sd
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rcp28_round_sd
comment|// CHECK: @llvm.x86.avx512.rcp28.sd
return|return
name|_mm_maskz_rcp28_round_sd
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_rcp28_sd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_rcp28_sd
comment|// CHECK: @llvm.x86.avx512.rcp28.sd
return|return
name|_mm_rcp28_sd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_rcp28_sd
parameter_list|(
name|__m128d
name|s
parameter_list|,
name|__mmask8
name|m
parameter_list|,
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_rcp28_sd
comment|// CHECK: @llvm.x86.avx512.rcp28.sd
return|return
name|_mm_mask_rcp28_sd
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskz_rcp28_sd
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m128d
name|a
parameter_list|,
name|__m128d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_maskz_rcp28_sd
comment|// CHECK: @llvm.x86.avx512.rcp28.sd
return|return
name|_mm_maskz_rcp28_sd
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_exp2a23_round_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_exp2a23_round_pd
comment|// CHECK: @llvm.x86.avx512.exp2.pd
return|return
name|_mm512_exp2a23_round_pd
argument_list|(
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_exp2a23_round_pd
parameter_list|(
name|__m512d
name|s
parameter_list|,
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_exp2a23_round_pd
comment|// CHECK: @llvm.x86.avx512.exp2.pd
return|return
name|_mm512_mask_exp2a23_round_pd
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_exp2a23_round_pd
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_exp2a23_round_pd
comment|// CHECK: @llvm.x86.avx512.exp2.pd
return|return
name|_mm512_maskz_exp2a23_round_pd
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_exp2a23_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_exp2a23_pd
comment|// CHECK: @llvm.x86.avx512.exp2.pd
return|return
name|_mm512_exp2a23_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_exp2a23_pd
parameter_list|(
name|__m512d
name|s
parameter_list|,
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_exp2a23_pd
comment|// CHECK: @llvm.x86.avx512.exp2.pd
return|return
name|_mm512_mask_exp2a23_pd
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_exp2a23_pd
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_exp2a23_pd
comment|// CHECK: @llvm.x86.avx512.exp2.pd
return|return
name|_mm512_maskz_exp2a23_pd
argument_list|(
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_exp2a23_round_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_exp2a23_round_ps
comment|// CHECK: @llvm.x86.avx512.exp2.ps
return|return
name|_mm512_exp2a23_round_ps
argument_list|(
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_exp2a23_round_ps
parameter_list|(
name|__m512
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_exp2a23_round_ps
comment|// CHECK: @llvm.x86.avx512.exp2.ps
return|return
name|_mm512_mask_exp2a23_round_ps
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_exp2a23_round_ps
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_exp2a23_round_ps
comment|// CHECK: @llvm.x86.avx512.exp2.ps
return|return
name|_mm512_maskz_exp2a23_round_ps
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|_MM_FROUND_CUR_DIRECTION
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_exp2a23_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_exp2a23_ps
comment|// CHECK: @llvm.x86.avx512.exp2.ps
return|return
name|_mm512_exp2a23_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_exp2a23_ps
parameter_list|(
name|__m512
name|s
parameter_list|,
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_exp2a23_ps
comment|// CHECK: @llvm.x86.avx512.exp2.ps
return|return
name|_mm512_mask_exp2a23_ps
argument_list|(
name|s
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_exp2a23_ps
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_exp2a23_ps
comment|// CHECK: @llvm.x86.avx512.exp2.ps
return|return
name|_mm512_maskz_exp2a23_ps
argument_list|(
name|m
argument_list|,
name|a
argument_list|)
return|;
block|}
end_function

end_unit

