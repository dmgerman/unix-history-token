begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -triple=x86_64-apple-darwin -target-feature +avx512dq -emit-llvm -o - -Werror | FileCheck %s
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
name|__m512i
name|test_mm512_mullo_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mullo_epi64
comment|// CHECK: mul<8 x i64>
return|return
call|(
name|__m512i
call|)
argument_list|(
operator|(
name|__v8di
operator|)
name|__A
operator|*
operator|(
name|__v8di
operator|)
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_mullo_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_mullo_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pmull.q.512
return|return
operator|(
name|__m512i
operator|)
name|_mm512_mask_mullo_epi64
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
name|__m512i
name|test_mm512_maskz_mullo_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_mullo_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pmull.q.512
return|return
operator|(
name|__m512i
operator|)
name|_mm512_maskz_mullo_epi64
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
name|__m512d
name|test_mm512_xor_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_xor_pd
comment|// CHECK: xor<8 x i64>
return|return
operator|(
name|__m512d
operator|)
name|_mm512_xor_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_xor_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_xor_pd
comment|// CHECK: @llvm.x86.avx512.mask.xor.pd.512
return|return
operator|(
name|__m512d
operator|)
name|_mm512_mask_xor_pd
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
name|__m512d
name|test_mm512_maskz_xor_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_xor_pd
comment|// CHECK: @llvm.x86.avx512.mask.xor.pd.512
return|return
operator|(
name|__m512d
operator|)
name|_mm512_maskz_xor_pd
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
name|__m512
name|test_mm512_xor_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_xor_ps
comment|// CHECK: xor<16 x i32>
return|return
operator|(
name|__m512
operator|)
name|_mm512_xor_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_xor_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_xor_ps
comment|// CHECK: @llvm.x86.avx512.mask.xor.ps.512
return|return
operator|(
name|__m512
operator|)
name|_mm512_mask_xor_ps
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
name|__m512
name|test_mm512_maskz_xor_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_xor_ps
comment|// CHECK: @llvm.x86.avx512.mask.xor.ps.512
return|return
operator|(
name|__m512
operator|)
name|_mm512_maskz_xor_ps
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
name|__m512d
name|test_mm512_or_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_or_pd
comment|// CHECK: or<8 x i64>
return|return
operator|(
name|__m512d
operator|)
name|_mm512_or_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_or_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_or_pd
comment|// CHECK: @llvm.x86.avx512.mask.or.pd.512
return|return
operator|(
name|__m512d
operator|)
name|_mm512_mask_or_pd
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
name|__m512d
name|test_mm512_maskz_or_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_or_pd
comment|// CHECK: @llvm.x86.avx512.mask.or.pd.512
return|return
operator|(
name|__m512d
operator|)
name|_mm512_maskz_or_pd
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
name|__m512
name|test_mm512_or_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_or_ps
comment|// CHECK: or<16 x i32>
return|return
operator|(
name|__m512
operator|)
name|_mm512_or_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_or_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_or_ps
comment|// CHECK: @llvm.x86.avx512.mask.or.ps.512
return|return
operator|(
name|__m512
operator|)
name|_mm512_mask_or_ps
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
name|__m512
name|test_mm512_maskz_or_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_or_ps
comment|// CHECK: @llvm.x86.avx512.mask.or.ps.512
return|return
operator|(
name|__m512
operator|)
name|_mm512_maskz_or_ps
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
name|__m512d
name|test_mm512_and_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_and_pd
comment|// CHECK: and<8 x i64>
return|return
operator|(
name|__m512d
operator|)
name|_mm512_and_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_and_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_and_pd
comment|// CHECK: @llvm.x86.avx512.mask.and.pd.512
return|return
operator|(
name|__m512d
operator|)
name|_mm512_mask_and_pd
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
name|__m512d
name|test_mm512_maskz_and_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_and_pd
comment|// CHECK: @llvm.x86.avx512.mask.and.pd.512
return|return
operator|(
name|__m512d
operator|)
name|_mm512_maskz_and_pd
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
name|__m512
name|test_mm512_and_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_and_ps
comment|// CHECK: and<16 x i32>
return|return
operator|(
name|__m512
operator|)
name|_mm512_and_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_and_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_and_ps
comment|// CHECK: @llvm.x86.avx512.mask.and.ps.512
return|return
operator|(
name|__m512
operator|)
name|_mm512_mask_and_ps
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
name|__m512
name|test_mm512_maskz_and_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_and_ps
comment|// CHECK: @llvm.x86.avx512.mask.and.ps.512
return|return
operator|(
name|__m512
operator|)
name|_mm512_maskz_and_ps
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
name|__m512d
name|test_mm512_andnot_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_andnot_pd
comment|// CHECK: @llvm.x86.avx512.mask.andn.pd.512
return|return
operator|(
name|__m512d
operator|)
name|_mm512_andnot_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_andnot_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_andnot_pd
comment|// CHECK: @llvm.x86.avx512.mask.andn.pd.512
return|return
operator|(
name|__m512d
operator|)
name|_mm512_mask_andnot_pd
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
name|__m512d
name|test_mm512_maskz_andnot_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_andnot_pd
comment|// CHECK: @llvm.x86.avx512.mask.andn.pd.512
return|return
operator|(
name|__m512d
operator|)
name|_mm512_maskz_andnot_pd
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
name|__m512
name|test_mm512_andnot_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_andnot_ps
comment|// CHECK: @llvm.x86.avx512.mask.andn.ps.512
return|return
operator|(
name|__m512
operator|)
name|_mm512_andnot_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_andnot_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_andnot_ps
comment|// CHECK: @llvm.x86.avx512.mask.andn.ps.512
return|return
operator|(
name|__m512
operator|)
name|_mm512_mask_andnot_ps
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
name|__m512
name|test_mm512_maskz_andnot_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_andnot_ps
comment|// CHECK: @llvm.x86.avx512.mask.andn.ps.512
return|return
operator|(
name|__m512
operator|)
name|_mm512_maskz_andnot_ps
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
name|__m512i
name|test_mm512_cvtpd_epi64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_cvtpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtpd_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_mask_cvtpd_epi64
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
name|__m512i
name|test_mm512_maskz_cvtpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_maskz_cvtpd_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvt_roundpd_epi64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_cvt_roundpd_epi64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundpd_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_mask_cvt_roundpd_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvt_roundpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2qq.512
return|return
name|_mm512_maskz_cvt_roundpd_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtpd_epu64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_cvtpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtpd_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_mask_cvtpd_epu64
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
name|__m512i
name|test_mm512_maskz_cvtpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_maskz_cvtpd_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvt_roundpd_epu64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_cvt_roundpd_epu64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundpd_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_mask_cvt_roundpd_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvt_roundpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtpd2uqq.512
return|return
name|_mm512_maskz_cvt_roundpd_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtps_epi64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_cvtps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtps_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_mask_cvtps_epi64
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
name|__m512i
name|test_mm512_maskz_cvtps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_maskz_cvtps_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvt_roundps_epi64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_cvt_roundps_epi64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundps_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_mask_cvt_roundps_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvt_roundps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2qq.512
return|return
name|_mm512_maskz_cvt_roundps_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtps_epu64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_cvtps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtps_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_mask_cvtps_epu64
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
name|__m512i
name|test_mm512_maskz_cvtps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_maskz_cvtps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvt_roundps_epu64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_cvt_roundps_epu64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvt_roundps_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_mask_cvt_roundps_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvt_roundps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvtps2uqq.512
return|return
name|_mm512_maskz_cvt_roundps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_cvtepi64_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_cvtepi64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtepi64_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_mask_cvtepi64_pd
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
name|__m512d
name|test_mm512_maskz_cvtepi64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_maskz_cvtepi64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_cvt_roundepi64_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_cvt_roundepi64_pd
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvt_roundepi64_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_mask_cvt_roundepi64_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_cvt_roundepi64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepi64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2pd.512
return|return
name|_mm512_maskz_cvt_roundepi64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_cvtepi64_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_cvtepi64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_cvtepi64_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_mask_cvtepi64_ps
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
name|test_mm512_maskz_cvtepi64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_maskz_cvtepi64_ps
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
name|test_mm512_cvt_roundepi64_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_cvt_roundepi64_ps
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_cvt_roundepi64_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_mask_cvt_roundepi64_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_maskz_cvt_roundepi64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepi64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtqq2ps.512
return|return
name|_mm512_maskz_cvt_roundepi64_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvttpd_epi64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_cvttpd_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvttpd_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_mask_cvttpd_epi64
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
name|__m512i
name|test_mm512_maskz_cvttpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_maskz_cvttpd_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtt_roundpd_epi64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_cvtt_roundpd_epi64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtt_roundpd_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_mask_cvtt_roundpd_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtt_roundpd_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundpd_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2qq.512
return|return
name|_mm512_maskz_cvtt_roundpd_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvttpd_epu64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_cvttpd_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvttpd_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_mask_cvttpd_epu64
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
name|__m512i
name|test_mm512_maskz_cvttpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_maskz_cvttpd_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtt_roundpd_epu64
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_cvtt_roundpd_epu64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtt_roundpd_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_mask_cvtt_roundpd_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtt_roundpd_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundpd_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttpd2uqq.512
return|return
name|_mm512_maskz_cvtt_roundpd_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvttps_epi64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_cvttps_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvttps_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_mask_cvttps_epi64
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
name|__m512i
name|test_mm512_maskz_cvttps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_maskz_cvttps_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtt_roundps_epi64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_cvtt_roundps_epi64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtt_roundps_epi64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_mask_cvtt_roundps_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtt_roundps_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundps_epi64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2qq.512
return|return
name|_mm512_maskz_cvtt_roundps_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvttps_epu64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_cvttps_epu64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvttps_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_mask_cvttps_epu64
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
name|__m512i
name|test_mm512_maskz_cvttps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvttps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_maskz_cvttps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_cvtt_roundps_epu64
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_cvtt_roundps_epu64
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_cvtt_roundps_epu64
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_mask_cvtt_roundps_epu64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_cvtt_roundps_epu64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtt_roundps_epu64
comment|// CHECK: @llvm.x86.avx512.mask.cvttps2uqq.512
return|return
name|_mm512_maskz_cvtt_roundps_epu64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_cvtepu64_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_cvtepu64_pd
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvtepu64_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_mask_cvtepu64_pd
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
name|__m512d
name|test_mm512_maskz_cvtepu64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_maskz_cvtepu64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_cvt_roundepu64_pd
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_cvt_roundepu64_pd
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_cvt_roundepu64_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_mask_cvt_roundepu64_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_cvt_roundepu64_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepu64_pd
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2pd.512
return|return
name|_mm512_maskz_cvt_roundepu64_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_cvtepu64_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_cvtepu64_ps
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_cvtepu64_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_mask_cvtepu64_ps
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
name|test_mm512_maskz_cvtepu64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvtepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_maskz_cvtepu64_ps
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
name|test_mm512_cvt_roundepu64_ps
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cvt_roundepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_cvt_roundepu64_ps
argument_list|(
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_cvt_roundepu64_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cvt_roundepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_mask_cvt_roundepu64_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_maskz_cvt_roundepu64_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_cvt_roundepu64_ps
comment|// CHECK: @llvm.x86.avx512.mask.cvtuqq2ps.512
return|return
name|_mm512_maskz_cvt_roundepu64_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_range_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_range_pd
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
name|__m512d
name|test_mm512_mask_range_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_mask_range_pd
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
name|__m512d
name|test_mm512_maskz_range_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_maskz_range_pd
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
name|__m512d
name|test_mm512_range_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_range_round_pd
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_range_round_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_range_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_mask_range_round_pd
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
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_range_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m512d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.range.pd.512
return|return
name|_mm512_maskz_range_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_range_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_range_ps
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
name|__m512
name|test_mm512_mask_range_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_mask_range_ps
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
name|__m512
name|test_mm512_maskz_range_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_maskz_range_ps
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
name|__m512
name|test_mm512_range_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_range_round_ps
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_range_round_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_range_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_mask_range_round_ps
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
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_range_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m512
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_range_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.range.ps.512
return|return
name|_mm512_maskz_range_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
name|__B
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_reduce_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_reduce_pd
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_reduce_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_mask_reduce_pd
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
name|__m512d
name|test_mm512_maskz_reduce_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_reduce_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_maskz_reduce_pd
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
name|__m512
name|test_mm512_reduce_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_reduce_ps
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_reduce_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_mask_reduce_ps
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
name|__m512
name|test_mm512_maskz_reduce_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_reduce_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_maskz_reduce_ps
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
name|__m512d
name|test_mm512_reduce_round_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_reduce_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_reduce_round_pd
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_reduce_round_pd
parameter_list|(
name|__m512d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_reduce_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_mask_reduce_round_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_reduce_round_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_reduce_round_pd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.pd.512
return|return
name|_mm512_maskz_reduce_round_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_reduce_round_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_reduce_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_reduce_round_ps
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_reduce_round_ps
parameter_list|(
name|__m512
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_reduce_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_mask_reduce_round_ps
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_reduce_round_ps
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_reduce_round_ps
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ps.512
return|return
name|_mm512_maskz_reduce_round_ps
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|4
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

end_unit

