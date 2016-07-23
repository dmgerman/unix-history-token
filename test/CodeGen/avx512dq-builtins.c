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
name|__m128d
name|test_mm512_range_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_range_round_sd
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
name|__m128d
name|test_mm512_mask_range_round_sd
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
comment|// CHECK-LABEL: test_mm512_mask_range_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_mask_range_round_sd
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
name|__m128d
name|test_mm512_maskz_range_round_sd
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
comment|// CHECK-LABEL: @test_mm512_maskz_range_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_maskz_range_round_sd
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
name|__m128d
name|test_mm512_range_round_ss
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_range_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_range_round_ss
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
name|__m128d
name|test_mm512_mask_range_round_ss
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
comment|// CHECK-LABEL: @test_mm512_mask_range_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_mask_range_round_ss
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
name|__m128
name|test_mm512_maskz_range_round_ss
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
comment|// CHECK-LABEL: @test_mm512_maskz_range_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_maskz_range_round_ss
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
name|__m128d
name|test_mm_range_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_range_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_range_sd
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
name|test_mm_mask_range_sd
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
comment|// CHECK-LABEL: test_mm_mask_range_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_mask_range_sd
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
name|test_mm_maskz_range_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_range_sd
comment|// CHECK: @llvm.x86.avx512.mask.range.sd
return|return
name|_mm_maskz_range_sd
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
name|test_mm_range_ss
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_range_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_range_ss
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
name|test_mm_mask_range_ss
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
comment|// CHECK-LABEL: @test_mm_mask_range_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_mask_range_ss
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
name|test_mm_maskz_range_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_range_ss
comment|// CHECK: @llvm.x86.avx512.mask.range.ss
return|return
name|_mm_maskz_range_ss
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

begin_function
name|__m128
name|test_mm_reduce_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_reduce_ss
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
name|test_mm_mask_reduce_ss
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
comment|// CHECK-LABEL: @test_mm_mask_reduce_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_mask_reduce_ss
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
name|test_mm_maskz_reduce_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_reduce_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_maskz_reduce_ss
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
name|test_mm_reduce_round_ss
parameter_list|(
name|__m128
name|__A
parameter_list|,
name|__m128
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_reduce_round_ss
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
name|__m128
name|test_mm_mask_reduce_round_ss
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
comment|// CHECK-LABEL: @test_mm_mask_reduce_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_mask_reduce_round_ss
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
name|__m128
name|test_mm_maskz_reduce_round_ss
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
comment|// CHECK-LABEL: @test_mm_maskz_reduce_round_ss
comment|// CHECK: @llvm.x86.avx512.mask.reduce.ss
return|return
name|_mm_maskz_reduce_round_ss
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
name|__m128d
name|test_mm_reduce_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_reduce_sd
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
name|test_mm_mask_reduce_sd
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
comment|// CHECK-LABEL: @test_mm_mask_reduce_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_mask_reduce_sd
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
name|test_mm_maskz_reduce_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_reduce_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_maskz_reduce_sd
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
name|test_mm_reduce_round_sd
parameter_list|(
name|__m128d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_reduce_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_reduce_round_sd
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
name|__m128d
name|test_mm_mask_reduce_round_sd
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
comment|// CHECK-LABEL: @test_mm_mask_reduce_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_mask_reduce_round_sd
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
name|__m128d
name|test_mm_maskz_reduce_round_sd
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
comment|// CHECK-LABEL: @test_mm_maskz_reduce_round_sd
comment|// CHECK: @llvm.x86.avx512.mask.reduce.sd
return|return
name|_mm_maskz_reduce_round_sd
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
name|__mmask16
name|test_mm512_movepi32_mask
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movepi32_mask
comment|// CHECK: @llvm.x86.avx512.cvtd2mask.512
return|return
name|_mm512_movepi32_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_movm_epi32
parameter_list|(
name|__mmask16
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movm_epi32
comment|// CHECK: @llvm.x86.avx512.cvtmask2d.512
return|return
name|_mm512_movm_epi32
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_movm_epi64
parameter_list|(
name|__mmask8
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movm_epi64
comment|// CHECK: @llvm.x86.avx512.cvtmask2q.512
return|return
name|_mm512_movm_epi64
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_movepi64_mask
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_movepi64_mask
comment|// CHECK: @llvm.x86.avx512.cvtq2mask.512
return|return
name|_mm512_movepi64_mask
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_broadcast_f32x2
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm512_broadcast_f32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_broadcast_f32x2
parameter_list|(
name|__m512
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm512_mask_broadcast_f32x2
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
name|__m512
name|test_mm512_maskz_broadcast_f32x2
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_f32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x2
return|return
name|_mm512_maskz_broadcast_f32x2
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_broadcast_f32x8
parameter_list|(
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_f32x8
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x8
return|return
name|_mm512_broadcast_f32x8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mask_broadcast_f32x8
parameter_list|(
name|__m512
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_f32x8
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x8
return|return
name|_mm512_mask_broadcast_f32x8
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
name|__m512
name|test_mm512_maskz_broadcast_f32x8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_f32x8
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf32x8
return|return
name|_mm512_maskz_broadcast_f32x8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_broadcast_f64x2
parameter_list|(
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf64x2
return|return
name|_mm512_broadcast_f64x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mask_broadcast_f64x2
parameter_list|(
name|__m512d
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf64x2
return|return
name|_mm512_mask_broadcast_f64x2
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
name|__m512d
name|test_mm512_maskz_broadcast_f64x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_f64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcastf64x2
return|return
name|_mm512_maskz_broadcast_f64x2
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_broadcast_i32x2
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm512_broadcast_i32x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_broadcast_i32x2
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm512_mask_broadcast_i32x2
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
name|__m512i
name|test_mm512_maskz_broadcast_i32x2
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_i32x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x2
return|return
name|_mm512_maskz_broadcast_i32x2
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_broadcast_i32x8
parameter_list|(
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_i32x8
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x8
return|return
name|_mm512_broadcast_i32x8
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_broadcast_i32x8
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_i32x8
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x8
return|return
name|_mm512_mask_broadcast_i32x8
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
name|__m512i
name|test_mm512_maskz_broadcast_i32x8
parameter_list|(
name|__mmask16
name|__M
parameter_list|,
name|__m256i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_i32x8
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti32x8
return|return
name|_mm512_maskz_broadcast_i32x8
argument_list|(
name|__M
argument_list|,
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_broadcast_i64x2
parameter_list|(
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcast_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti64x2
return|return
name|_mm512_broadcast_i64x2
argument_list|(
name|__A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_broadcast_i64x2
parameter_list|(
name|__m512i
name|__O
parameter_list|,
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_broadcast_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti64x2
return|return
name|_mm512_mask_broadcast_i64x2
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
name|__m512i
name|test_mm512_maskz_broadcast_i64x2
parameter_list|(
name|__mmask8
name|__M
parameter_list|,
name|__m128i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_broadcast_i64x2
comment|// CHECK: @llvm.x86.avx512.mask.broadcasti64x2
return|return
name|_mm512_maskz_broadcast_i64x2
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
name|test_mm512_extractf32x8_ps
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extractf32x8_ps
comment|// CHECK: @llvm.x86.avx512.mask.vextractf32x8
return|return
name|_mm512_extractf32x8_ps
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm512_mask_extractf32x8_ps
parameter_list|(
name|__m256
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_extractf32x8_ps
comment|// CHECK: @llvm.x86.avx512.mask.vextractf32x8
return|return
name|_mm512_mask_extractf32x8_ps
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
name|__m256
name|test_mm512_maskz_extractf32x8_ps
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extractf32x8_ps
comment|// CHECK: @llvm.x86.avx512.mask.vextractf32x8
return|return
name|_mm512_maskz_extractf32x8_ps
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
name|__m128d
name|test_mm512_extractf64x2_pd
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extractf64x2_pd
comment|// CHECK: @llvm.x86.avx512.mask.vextractf64x2
return|return
name|_mm512_extractf64x2_pd
argument_list|(
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_mask_extractf64x2_pd
parameter_list|(
name|__m128d
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_extractf64x2_pd
comment|// CHECK: @llvm.x86.avx512.mask.vextractf64x2
return|return
name|_mm512_mask_extractf64x2_pd
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm512_maskz_extractf64x2_pd
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extractf64x2_pd
comment|// CHECK: @llvm.x86.avx512.mask.vextractf64x2
return|return
name|_mm512_maskz_extractf64x2_pd
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_extracti32x8_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extracti32x8_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vextracti32x8
return|return
name|_mm512_extracti32x8_epi32
argument_list|(
name|__A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm512_mask_extracti32x8_epi32
parameter_list|(
name|__m256i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_extracti32x8_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vextracti32x8
return|return
name|_mm512_mask_extracti32x8_epi32
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
name|__m256i
name|test_mm512_maskz_extracti32x8_epi32
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extracti32x8_epi32
comment|// CHECK: @llvm.x86.avx512.mask.vextracti32x8
return|return
name|_mm512_maskz_extracti32x8_epi32
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
name|test_mm512_extracti64x2_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extracti64x2_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vextracti64x2
return|return
name|_mm512_extracti64x2_epi64
argument_list|(
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_mask_extracti64x2_epi64
parameter_list|(
name|__m128i
name|__W
parameter_list|,
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_extracti64x2_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vextracti64x2
return|return
name|_mm512_mask_extracti64x2_epi64
argument_list|(
name|__W
argument_list|,
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm512_maskz_extracti64x2_epi64
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_extracti64x2_epi64
comment|// CHECK: @llvm.x86.avx512.mask.vextracti64x2
return|return
name|_mm512_maskz_extracti64x2_epi64
argument_list|(
name|__U
argument_list|,
name|__A
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_insertf32x8
parameter_list|(
name|__m512
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_insertf32x8
comment|// CHECK: @llvm.x86.avx512.mask.insertf32x8
return|return
name|_mm512_insertf32x8
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
name|__m512
name|test_mm512_mask_insertf32x8
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
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_insertf32x8
comment|// CHECK: @llvm.x86.avx512.mask.insertf32x8
return|return
name|_mm512_mask_insertf32x8
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
name|__m512
name|test_mm512_maskz_insertf32x8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|,
name|__m256
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_insertf32x8
comment|// CHECK: @llvm.x86.avx512.mask.insertf32x8
return|return
name|_mm512_maskz_insertf32x8
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
name|__m512d
name|test_mm512_insertf64x2
parameter_list|(
name|__m512d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_insertf64x2
comment|// CHECK: @llvm.x86.avx512.mask.insertf64x2
return|return
name|_mm512_insertf64x2
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
name|__m512d
name|test_mm512_mask_insertf64x2
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
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_insertf64x2
comment|// CHECK: @llvm.x86.avx512.mask.insertf64x2
return|return
name|_mm512_mask_insertf64x2
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
name|__m512d
name|test_mm512_maskz_insertf64x2
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|,
name|__m128d
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_insertf64x2
comment|// CHECK: @llvm.x86.avx512.mask.insertf64x2
return|return
name|_mm512_maskz_insertf64x2
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
name|__m512i
name|test_mm512_inserti32x8
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_inserti32x8
comment|// CHECK: @llvm.x86.avx512.mask.inserti32x8
return|return
name|_mm512_inserti32x8
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
name|__m512i
name|test_mm512_mask_inserti32x8
parameter_list|(
name|__m512i
name|__W
parameter_list|,
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_inserti32x8
comment|// CHECK: @llvm.x86.avx512.mask.inserti32x8
return|return
name|_mm512_mask_inserti32x8
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
name|__m512i
name|test_mm512_maskz_inserti32x8
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m256i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_inserti32x8
comment|// CHECK: @llvm.x86.avx512.mask.inserti32x8
return|return
name|_mm512_maskz_inserti32x8
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
name|__m512i
name|test_mm512_inserti64x2
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_inserti64x2
comment|// CHECK: @llvm.x86.avx512.mask.inserti64x2
return|return
name|_mm512_inserti64x2
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
name|__m512i
name|test_mm512_mask_inserti64x2
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
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_inserti64x2
comment|// CHECK: @llvm.x86.avx512.mask.inserti64x2
return|return
name|_mm512_mask_inserti64x2
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
name|__m512i
name|test_mm512_maskz_inserti64x2
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512i
name|__A
parameter_list|,
name|__m128i
name|__B
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_inserti64x2
comment|// CHECK: @llvm.x86.avx512.mask.inserti64x2
return|return
name|_mm512_maskz_inserti64x2
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
name|test_mm512_mask_fpclass_pd_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.512
return|return
name|_mm512_mask_fpclass_pd_mask
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
name|test_mm512_fpclass_pd_mask
parameter_list|(
name|__m512d
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fpclass_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.pd.512
return|return
name|_mm512_fpclass_pd_mask
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_fpclass_ps_mask
parameter_list|(
name|__mmask16
name|__U
parameter_list|,
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.512
return|return
name|_mm512_mask_fpclass_ps_mask
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
name|__mmask16
name|test_mm512_fpclass_ps_mask
parameter_list|(
name|__m512
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fpclass_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ps.512
return|return
name|_mm512_fpclass_ps_mask
argument_list|(
name|__A
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm_fpclass_sd_mask
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fpclass_sd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.sd
return|return
name|_mm_fpclass_sd_mask
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
name|test_mm_mask_fpclass_sd_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fpclass_sd_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.sd
return|return
name|_mm_mask_fpclass_sd_mask
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
name|test_mm_fpclass_ss_mask
parameter_list|(
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_fpclass_ss_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ss
return|return
name|_mm_fpclass_ss_mask
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
name|test_mm_mask_fpclass_ss_mask
parameter_list|(
name|__mmask8
name|__U
parameter_list|,
name|__m128
name|__A
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm_mask_fpclass_ss_mask
comment|// CHECK: @llvm.x86.avx512.mask.fpclass.ss
return|return
name|_mm_mask_fpclass_ss_mask
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

end_unit

