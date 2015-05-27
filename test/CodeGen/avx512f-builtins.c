begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 %s -O0 -triple=x86_64-apple-darwin -target-feature +avx512f -emit-llvm -o - -Werror | FileCheck %s
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
name|__m512d
name|test_mm512_sqrt_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sqrt_pd
comment|// CHECK: @llvm.x86.avx512.sqrt.pd.512
return|return
name|_mm512_sqrt_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_sqrt_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_sqrt_ps
comment|// CHECK: @llvm.x86.avx512.sqrt.ps.512
return|return
name|_mm512_sqrt_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_rsqrt14_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rsqrt14_pd
comment|// CHECK: @llvm.x86.avx512.rsqrt14.pd.512
return|return
name|_mm512_rsqrt14_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_rsqrt14_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_rsqrt14_ps
comment|// CHECK: @llvm.x86.avx512.rsqrt14.ps.512
return|return
name|_mm512_rsqrt14_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_add_ps
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_add_ps
comment|// CHECK: fadd<16 x float>
return|return
name|_mm512_add_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_add_pd
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_add_pd
comment|// CHECK: fadd<8 x double>
return|return
name|_mm512_add_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_mul_ps
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mul_ps
comment|// CHECK: fmul<16 x float>
return|return
name|_mm512_mul_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_mul_pd
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mul_pd
comment|// CHECK: fmul<8 x double>
return|return
name|_mm512_mul_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm512_storeu_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_storeu_ps
comment|// CHECK: @llvm.x86.avx512.mask.storeu.ps.512
name|_mm512_storeu_ps
argument_list|(
name|p
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_storeu_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_storeu_pd
comment|// CHECK: @llvm.x86.avx512.mask.storeu.pd.512
name|_mm512_storeu_pd
argument_list|(
name|p
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_store_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__mmask16
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_store_ps
comment|// CHECK: @llvm.x86.avx512.mask.store.ps.512
name|_mm512_mask_store_ps
argument_list|(
name|p
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_store_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_store_ps
comment|// CHECK: store<16 x float>
name|_mm512_store_ps
argument_list|(
name|p
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_mask_store_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__mmask8
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_store_pd
comment|// CHECK: @llvm.x86.avx512.mask.store.pd.512
name|_mm512_mask_store_pd
argument_list|(
name|p
argument_list|,
name|m
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm512_store_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_store_pd
comment|// CHECK: store<8 x double>
name|_mm512_store_pd
argument_list|(
name|p
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_loadu_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_loadu_ps
comment|// CHECK: load<16 x float>,<16 x float>* {{.*}}, align 1{{$}}
return|return
name|_mm512_loadu_ps
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_loadu_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_loadu_pd
comment|// CHECK: load<8 x double>,<8 x double>* {{.*}}, align 1{{$}}
return|return
name|_mm512_loadu_pd
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_maskz_load_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__mmask16
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_load_ps
comment|// CHECK: @llvm.x86.avx512.mask.load.ps.512
return|return
name|_mm512_maskz_load_ps
argument_list|(
name|m
argument_list|,
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_load_ps
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_load_ps
comment|// CHECK: @llvm.x86.avx512.mask.load.ps.512
return|return
name|_mm512_load_ps
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_maskz_load_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|,
name|__mmask8
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_load_pd
comment|// CHECK: @llvm.x86.avx512.mask.load.pd.512
return|return
name|_mm512_maskz_load_pd
argument_list|(
name|m
argument_list|,
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_load_pd
parameter_list|(
name|void
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_load_pd
comment|// CHECK: @llvm.x86.avx512.mask.load.pd.512
return|return
name|_mm512_load_pd
argument_list|(
name|p
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_set1_pd
parameter_list|(
name|double
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_set1_pd
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 0
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 1
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 2
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 3
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 4
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 5
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 6
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 7
return|return
name|_mm512_set1_pd
argument_list|(
name|d
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_castpd256_pd512
parameter_list|(
name|__m256d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_castpd256_pd512
comment|// CHECK: shufflevector<4 x double> {{.*}}<i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef>
return|return
name|_mm512_castpd256_pd512
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_knot
parameter_list|(
name|__mmask16
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_knot
comment|// CHECK: @llvm.x86.avx512.knot.w
return|return
name|_mm512_knot
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_alignr_epi32
parameter_list|(
name|__m512i
name|a
parameter_list|,
name|__m512i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_alignr_epi32
comment|// CHECK: @llvm.x86.avx512.mask.valign.d.512
return|return
name|_mm512_alignr_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_alignr_epi64
parameter_list|(
name|__m512i
name|a
parameter_list|,
name|__m512i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_alignr_epi64
comment|// CHECK: @llvm.x86.avx512.mask.valign.q.512
return|return
name|_mm512_alignr_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_broadcastsd_pd
parameter_list|(
name|__m128d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_broadcastsd_pd
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 0
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 1
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 2
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 3
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 4
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 5
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 6
comment|// CHECK: insertelement<8 x double> {{.*}}, i32 7
return|return
name|_mm512_broadcastsd_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_fmadd_pd
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|,
name|__m512d
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_fmadd_pd
comment|// CHECK: @llvm.x86.fma.mask.vfmadd.pd.512
return|return
name|_mm512_fmadd_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmpeq_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.d.512
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpeq_epi32_mask
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
name|test_mm512_mask_cmpeq_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.d.512
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpeq_epi32_mask
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
name|test_mm512_mask_cmpeq_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.q.512
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpeq_epi64_mask
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
name|test_mm512_cmpeq_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpeq.q.512
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpeq_epi64_mask
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
name|test_mm512_cmpgt_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.d.512
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpgt_epi32_mask
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
name|test_mm512_mask_cmpgt_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.d.512
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpgt_epi32_mask
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
name|test_mm512_mask_cmpgt_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.q.512
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpgt_epi64_mask
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
name|test_mm512_cmpgt_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.pcmpgt.q.512
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpgt_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_unpackhi_pd
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpackhi_pd
comment|// CHECK: shufflevector<8 x double> {{.*}}<i32 1, i32 9, i32 3, i32 11, i32 5, i32 13, i32 7, i32 15>
return|return
name|_mm512_unpackhi_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512d
name|test_mm512_unpacklo_pd
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpacklo_pd
comment|// CHECK: shufflevector<8 x double> {{.*}}<i32 0, i32 8, i32 2, i32 10, i32 4, i32 12, i32 6, i32 14>
return|return
name|_mm512_unpacklo_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_unpackhi_ps
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpackhi_ps
comment|// CHECK: shufflevector<16 x float> {{.*}}<i32 2, i32 18, i32 3, i32 19, i32 6, i32 22, i32 7, i32 23, i32 10, i32 26, i32 11, i32 27, i32 14, i32 30, i32 15, i32 31>
return|return
name|_mm512_unpackhi_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512
name|test_mm512_unpacklo_ps
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_unpacklo_ps
comment|// CHECK: shufflevector<16 x float> {{.*}}<i32 0, i32 16, i32 1, i32 17, i32 4, i32 20, i32 5, i32 21, i32 8, i32 24, i32 9, i32 25, i32 12, i32 28, i32 13, i32 29>
return|return
name|_mm512_unpacklo_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmp_round_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_round_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmp_round_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmp_round_ps_mask
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_round_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmp_round_ps_mask
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmp_ps_mask
parameter_list|(
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// check-label: @test_mm512_cmp_ps_mask
comment|// check: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_cmp_ps_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmp_ps_mask
parameter_list|(
name|__mmask16
name|m
parameter_list|,
name|__m512
name|a
parameter_list|,
name|__m512
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_ps_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.ps.512
return|return
name|_mm512_mask_cmp_ps_mask
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmp_round_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_round_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmp_round_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmp_round_pd_mask
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_round_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmp_round_pd_mask
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|,
name|_MM_FROUND_TO_NEAREST_INT
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmp_pd_mask
parameter_list|(
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// check-label: @test_mm512_cmp_pd_mask
comment|// check: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_cmp_pd_mask
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmp_pd_mask
parameter_list|(
name|__mmask8
name|m
parameter_list|,
name|__m512d
name|a
parameter_list|,
name|__m512d
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_pd_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.pd.512
return|return
name|_mm512_mask_cmp_pd_mask
argument_list|(
name|m
argument_list|,
name|a
argument_list|,
name|b
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm512_extractf64x4_pd
parameter_list|(
name|__m512d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extractf64x4_pd
comment|// CHECK: @llvm.x86.avx512.mask.vextractf64x4.512
return|return
name|_mm512_extractf64x4_pd
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm512_extractf32x4_ps
parameter_list|(
name|__m512
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_extractf32x4_ps
comment|// CHECK: @llvm.x86.avx512.mask.vextractf32x4.512
return|return
name|_mm512_extractf32x4_ps
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmpeq_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 0, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpeq_epu32_mask
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
name|test_mm512_mask_cmpeq_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 0, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpeq_epu32_mask
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
name|test_mm512_cmpeq_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpeq_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 0, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpeq_epu64_mask
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
name|test_mm512_mask_cmpeq_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpeq_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 0, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpeq_epu64_mask
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
name|test_mm512_cmpge_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 5, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpge_epi32_mask
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
name|test_mm512_mask_cmpge_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 5, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpge_epi32_mask
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
name|test_mm512_cmpge_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 5, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpge_epi64_mask
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
name|test_mm512_mask_cmpge_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 5, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpge_epi64_mask
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
name|test_mm512_cmpge_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 5, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpge_epu32_mask
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
name|test_mm512_mask_cmpge_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 5, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpge_epu32_mask
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
name|test_mm512_cmpge_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpge_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 5, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpge_epu64_mask
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
name|test_mm512_mask_cmpge_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpge_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 5, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpge_epu64_mask
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
name|test_mm512_cmpgt_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 6, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpgt_epu32_mask
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
name|test_mm512_mask_cmpgt_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 6, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpgt_epu32_mask
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
name|test_mm512_cmpgt_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpgt_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 6, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpgt_epu64_mask
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
name|test_mm512_mask_cmpgt_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpgt_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 6, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpgt_epu64_mask
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
name|test_mm512_cmple_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 2, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmple_epi32_mask
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
name|test_mm512_mask_cmple_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 2, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmple_epi32_mask
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
name|test_mm512_cmple_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 2, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmple_epi64_mask
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
name|test_mm512_mask_cmple_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 2, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmple_epi64_mask
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
name|test_mm512_cmple_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 2, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmple_epu32_mask
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
name|test_mm512_mask_cmple_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 2, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmple_epu32_mask
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
name|test_mm512_cmple_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmple_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 2, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmple_epu64_mask
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
name|test_mm512_mask_cmple_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmple_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 2, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmple_epu64_mask
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
name|test_mm512_cmplt_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 1, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmplt_epi32_mask
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
name|test_mm512_mask_cmplt_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 1, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmplt_epi32_mask
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
name|test_mm512_cmplt_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 1, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmplt_epi64_mask
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
name|test_mm512_mask_cmplt_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 1, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmplt_epi64_mask
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
name|test_mm512_cmplt_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 1, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmplt_epu32_mask
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
name|test_mm512_mask_cmplt_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 1, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmplt_epu32_mask
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
name|test_mm512_cmplt_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmplt_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 1, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmplt_epu64_mask
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
name|test_mm512_mask_cmplt_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmplt_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 1, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmplt_epu64_mask
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
name|test_mm512_cmpneq_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 4, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpneq_epi32_mask
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
name|test_mm512_mask_cmpneq_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 4, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpneq_epi32_mask
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
name|test_mm512_cmpneq_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 4, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpneq_epi64_mask
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
name|test_mm512_mask_cmpneq_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 4, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpneq_epi64_mask
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
name|test_mm512_cmpneq_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 4, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmpneq_epu32_mask
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
name|test_mm512_mask_cmpneq_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 4, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmpneq_epu32_mask
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
name|test_mm512_cmpneq_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmpneq_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 4, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmpneq_epu64_mask
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
name|test_mm512_mask_cmpneq_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmpneq_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 4, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmpneq_epu64_mask
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
name|test_mm512_cmp_epi32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 3, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmp_epi32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmp_epi32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epi32_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 3, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmp_epi32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmp_epi64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 3, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmp_epi64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmp_epi64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epi64_mask
comment|// CHECK: @llvm.x86.avx512.mask.cmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 3, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmp_epi64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_cmp_epu32_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 3, i16 -1)
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_cmp_epu32_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask16
name|test_mm512_mask_cmp_epu32_mask
parameter_list|(
name|__mmask16
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epu32_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.d.512(<16 x i32> {{.*}},<16 x i32> {{.*}}, i32 3, i16 {{.*}})
return|return
operator|(
name|__mmask16
operator|)
name|_mm512_mask_cmp_epu32_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_cmp_epu64_mask
parameter_list|(
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_cmp_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 3, i8 -1)
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_cmp_epu64_mask
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__mmask8
name|test_mm512_mask_cmp_epu64_mask
parameter_list|(
name|__mmask8
name|__u
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_cmp_epu64_mask
comment|// CHECK: @llvm.x86.avx512.mask.ucmp.q.512(<8 x i64> {{.*}},<8 x i64> {{.*}}, i32 3, i8 {{.*}})
return|return
operator|(
name|__mmask8
operator|)
name|_mm512_mask_cmp_epu64_mask
argument_list|(
name|__u
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_and_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_and_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pand.d.512
return|return
name|_mm512_mask_and_epi32
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_and_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_and_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pand.d.512
return|return
name|_mm512_maskz_and_epi32
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_and_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_and_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pand.q.512
return|return
name|_mm512_mask_and_epi64
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_and_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_and_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pand.q.512
return|return
name|_mm512_maskz_and_epi64
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_or_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_or_epi32
comment|// CHECK: @llvm.x86.avx512.mask.por.d.512
return|return
name|_mm512_mask_or_epi32
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_or_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_or_epi32
comment|// CHECK: @llvm.x86.avx512.mask.por.d.512
return|return
name|_mm512_maskz_or_epi32
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_or_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_or_epi64
comment|// CHECK: @llvm.x86.avx512.mask.por.q.512
return|return
name|_mm512_mask_or_epi64
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_or_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_or_epi64
comment|// CHECK: @llvm.x86.avx512.mask.por.q.512
return|return
name|_mm512_maskz_or_epi64
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_xor_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_xor_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pxor.d.512
return|return
name|_mm512_mask_xor_epi32
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_xor_epi32
parameter_list|(
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_xor_epi32
comment|// CHECK: @llvm.x86.avx512.mask.pxor.d.512
return|return
name|_mm512_maskz_xor_epi32
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_mask_xor_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_mask_xor_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pxor.q.512
return|return
name|_mm512_mask_xor_epi64
argument_list|(
name|__src
argument_list|,
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_maskz_xor_epi64
parameter_list|(
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_maskz_xor_epi64
comment|// CHECK: @llvm.x86.avx512.mask.pxor.q.512
return|return
name|_mm512_maskz_xor_epi64
argument_list|(
name|__k
argument_list|,
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_and_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_and_epi32
comment|// CHECK: and<8 x i64>
return|return
name|_mm512_and_epi32
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_and_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_and_epi64
comment|// CHECK: and<8 x i64>
return|return
name|_mm512_and_epi64
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_or_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_or_epi32
comment|// CHECK: or<8 x i64>
return|return
name|_mm512_or_epi32
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_or_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_or_epi64
comment|// CHECK: or<8 x i64>
return|return
name|_mm512_or_epi64
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_xor_epi32
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask16
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_xor_epi32
comment|// CHECK: xor<8 x i64>
return|return
name|_mm512_xor_epi32
argument_list|(
name|__a
argument_list|,
name|__b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m512i
name|test_mm512_xor_epi64
parameter_list|(
name|__m512i
name|__src
parameter_list|,
name|__mmask8
name|__k
parameter_list|,
name|__m512i
name|__a
parameter_list|,
name|__m512i
name|__b
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm512_xor_epi64
comment|// CHECK: xor<8 x i64>
return|return
name|_mm512_xor_epi64
argument_list|(
name|__a
argument_list|,
name|__b
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
name|__m512i
name|test_mm512_maskz_sub_epi32
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
comment|//CHECK-LABEL: @test_mm512_maskz_sub_epi32
comment|//CHECK: @llvm.x86.avx512.mask.psub.d.512
return|return
name|_mm512_maskz_sub_epi32
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
name|test_mm512_mask_sub_epi32
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
comment|//CHECK-LABEL: @test_mm512_mask_sub_epi32
comment|//CHECK: @llvm.x86.avx512.mask.psub.d.512
return|return
name|_mm512_mask_sub_epi32
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
name|test_mm512_sub_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_sub_epi32
comment|//CHECK: sub<16 x i32>
return|return
name|_mm512_sub_epi32
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
name|test_mm512_maskz_sub_epi64
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
comment|//CHECK-LABEL: @test_mm512_maskz_sub_epi64
comment|//CHECK: @llvm.x86.avx512.mask.psub.q.512
return|return
name|_mm512_maskz_sub_epi64
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
name|test_mm512_mask_sub_epi64
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
comment|//CHECK-LABEL: @test_mm512_mask_sub_epi64
comment|//CHECK: @llvm.x86.avx512.mask.psub.q.512
return|return
name|_mm512_mask_sub_epi64
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
name|test_mm512_sub_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_sub_epi64
comment|//CHECK: sub<8 x i64>
return|return
name|_mm512_sub_epi64
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
name|test_mm512_maskz_add_epi32
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
comment|//CHECK-LABEL: @test_mm512_maskz_add_epi32
comment|//CHECK: @llvm.x86.avx512.mask.padd.d.512
return|return
name|_mm512_maskz_add_epi32
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
name|test_mm512_mask_add_epi32
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
comment|//CHECK-LABEL: @test_mm512_mask_add_epi32
comment|//CHECK: @llvm.x86.avx512.mask.padd.d.512
return|return
name|_mm512_mask_add_epi32
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
name|test_mm512_add_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_add_epi32
comment|//CHECK: add<16 x i32>
return|return
name|_mm512_add_epi32
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
name|test_mm512_maskz_add_epi64
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
comment|//CHECK-LABEL: @test_mm512_maskz_add_epi64
comment|//CHECK: @llvm.x86.avx512.mask.padd.q.512
return|return
name|_mm512_maskz_add_epi64
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
name|test_mm512_mask_add_epi64
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
comment|//CHECK-LABEL: @test_mm512_mask_add_epi64
comment|//CHECK: @llvm.x86.avx512.mask.padd.q.512
return|return
name|_mm512_mask_add_epi64
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
name|test_mm512_add_epi64
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_add_epi64
comment|//CHECK: add<8 x i64>
return|return
name|_mm512_add_epi64
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
name|test_mm512_maskz_mul_epi32
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
comment|//CHECK-LABEL: @test_mm512_maskz_mul_epi32
comment|//CHECK: @llvm.x86.avx512.mask.pmul.dq.512
return|return
name|_mm512_maskz_mul_epi32
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
name|test_mm512_mask_mul_epi32
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
comment|//CHECK-LABEL: @test_mm512_mask_mul_epi32
comment|//CHECK: @llvm.x86.avx512.mask.pmul.dq.512
return|return
name|_mm512_mask_mul_epi32
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
name|test_mm512_maskz_mul_epu32
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
comment|//CHECK-LABEL: @test_mm512_maskz_mul_epu32
comment|//CHECK: @llvm.x86.avx512.mask.pmulu.dq.512
return|return
name|_mm512_maskz_mul_epu32
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
name|test_mm512_mask_mul_epu32
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
comment|//CHECK-LABEL: @test_mm512_mask_mul_epu32
comment|//CHECK: @llvm.x86.avx512.mask.pmulu.dq.512
return|return
name|_mm512_mask_mul_epu32
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
name|test_mm512_maskz_mullo_epi32
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
comment|//CHECK-LABEL: @test_mm512_maskz_mullo_epi32
comment|//CHECK: @llvm.x86.avx512.mask.pmull.d.512
return|return
name|_mm512_maskz_mullo_epi32
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
name|test_mm512_mask_mullo_epi32
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
comment|//CHECK-LABEL: @test_mm512_mask_mullo_epi32
comment|//CHECK: @llvm.x86.avx512.mask.pmull.d.512
return|return
name|_mm512_mask_mullo_epi32
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
name|test_mm512_mullo_epi32
parameter_list|(
name|__m512i
name|__A
parameter_list|,
name|__m512i
name|__B
parameter_list|)
block|{
comment|//CHECK-LABEL: @test_mm512_mullo_epi32
comment|//CHECK: mul<16 x i32>
return|return
name|_mm512_mullo_epi32
argument_list|(
name|__A
argument_list|,
name|__B
argument_list|)
return|;
block|}
end_function

end_unit

