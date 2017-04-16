begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +ssse3 -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +ssse3 -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_function
name|__m64
name|test_mm_abs_pi8
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_abs_pi8
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.pabs.b
return|return
name|_mm_abs_pi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_abs_pi16
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_abs_pi16
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.pabs.w
return|return
name|_mm_abs_pi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_abs_pi32
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_abs_pi32
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.pabs.d
return|return
name|_mm_abs_pi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_add_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_pi8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.padd.b
return|return
name|_mm_add_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_add_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.padd.w
return|return
name|_mm_add_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_add_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.padd.d
return|return
name|_mm_add_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_add_si64
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_add_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.padd.q(x86_mmx %{{.*}}, x86_mmx %{{.*}})
return|return
name|_mm_add_si64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_adds_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_adds_pi8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.padds.b
return|return
name|_mm_adds_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_adds_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_adds_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.padds.w
return|return
name|_mm_adds_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_adds_pu8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_adds_pu8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.paddus.b
return|return
name|_mm_adds_pu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_adds_pu16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_adds_pu16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.paddus.w
return|return
name|_mm_adds_pu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_alignr_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_alignr_pi8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.palignr.b
return|return
name|_mm_alignr_pi8
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
name|__m64
name|test_mm_and_si64
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_and_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pand
return|return
name|_mm_and_si64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_andnot_si64
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_andnot_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pandn
return|return
name|_mm_andnot_si64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_avg_pu8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_avg_pu8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pavg.b
return|return
name|_mm_avg_pu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_avg_pu16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_avg_pu16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pavg.w
return|return
name|_mm_avg_pu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cmpeq_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpeq_pi8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pcmpeq.b
return|return
name|_mm_cmpeq_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cmpeq_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpeq_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pcmpeq.w
return|return
name|_mm_cmpeq_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cmpeq_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpeq_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pcmpeq.d
return|return
name|_mm_cmpeq_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cmpgt_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpgt_pi8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pcmpgt.b
return|return
name|_mm_cmpgt_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cmpgt_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpgt_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pcmpgt.w
return|return
name|_mm_cmpgt_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cmpgt_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmpgt_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pcmpgt.d
return|return
name|_mm_cmpgt_pi32
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
name|test_mm_cvt_pi2ps
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvt_pi2ps
comment|// CHECK:<4 x float> @llvm.x86.sse.cvtpi2ps
return|return
name|_mm_cvt_pi2ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cvt_ps2pi
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvt_ps2pi
comment|// CHECK: call x86_mmx @llvm.x86.sse.cvtps2pi
return|return
name|_mm_cvt_ps2pi
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cvtpd_pi32
parameter_list|(
name|__m128d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtpd_pi32
comment|// CHECK: call x86_mmx @llvm.x86.sse.cvtpd2pi
return|return
name|_mm_cvtpd_pi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtpi16_ps
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtpi16_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse.cvtpi2ps
return|return
name|_mm_cvtpi16_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cvtpi32_pd
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtpi32_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse.cvtpi2pd
return|return
name|_mm_cvtpi32_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cvtpi32_ps
parameter_list|(
name|__m128
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtpi32_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse.cvtpi2ps
return|return
name|_mm_cvtpi32_ps
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
name|test_mm_cvtpi32x2_ps
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtpi32x2_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse.cvtpi2ps
comment|// CHECK: call<4 x float> @llvm.x86.sse.cvtpi2ps
return|return
name|_mm_cvtpi32x2_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cvtps_pi16
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtps_pi16
comment|// CHECK: call x86_mmx @llvm.x86.sse.cvtps2pi
return|return
name|_mm_cvtps_pi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cvtps_pi32
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtps_pi32
comment|// CHECK: call x86_mmx @llvm.x86.sse.cvtps2pi
return|return
name|_mm_cvtps_pi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cvtsi32_si64
parameter_list|(
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi32_si64
comment|// CHECK: insertelement<2 x i32>
return|return
name|_mm_cvtsi32_si64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_cvtsi64_si32
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvtsi64_si32
comment|// CHECK: extractelement<2 x i32>
return|return
name|_mm_cvtsi64_si32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cvttpd_pi32
parameter_list|(
name|__m128d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvttpd_pi32
comment|// CHECK: call x86_mmx @llvm.x86.sse.cvttpd2pi
return|return
name|_mm_cvttpd_pi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_cvttps_pi32
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cvttps_pi32
comment|// CHECK: call x86_mmx @llvm.x86.sse.cvttps2pi
return|return
name|_mm_cvttps_pi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_extract_pi16
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_extract_pi16
comment|// CHECK: call i32 @llvm.x86.mmx.pextr.w
return|return
name|_mm_extract_pi16
argument_list|(
name|a
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_from_int
parameter_list|(
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_m_from_int
comment|// CHECK: insertelement<2 x i32>
return|return
name|_m_from_int
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_m_from_int64
parameter_list|(
name|long
name|long
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_m_from_int64
comment|// CHECK: bitcast
return|return
name|_m_from_int64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_hadd_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hadd_pi16
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.phadd.w
return|return
name|_mm_hadd_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_hadd_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hadd_pi32
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.phadd.d
return|return
name|_mm_hadd_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_hadds_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hadds_pi16
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.phadd.sw
return|return
name|_mm_hadds_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_hsub_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsub_pi16
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.phsub.w
return|return
name|_mm_hsub_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_hsub_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsub_pi32
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.phsub.d
return|return
name|_mm_hsub_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_hsubs_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_hsubs_pi16
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.phsub.sw
return|return
name|_mm_hsubs_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_insert_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|int
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_insert_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pinsr.w
return|return
name|_mm_insert_pi16
argument_list|(
name|a
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_madd_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_madd_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pmadd.wd
return|return
name|_mm_madd_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_maddubs_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maddubs_pi16
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.pmadd.ub.sw
return|return
name|_mm_maddubs_pi16
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
name|test_mm_maskmove_si64
parameter_list|(
name|__m64
name|d
parameter_list|,
name|__m64
name|n
parameter_list|,
name|char
modifier|*
name|p
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskmove_si64
comment|// CHECK: call void @llvm.x86.mmx.maskmovq
name|_mm_maskmove_si64
argument_list|(
name|d
argument_list|,
name|n
argument_list|,
name|p
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m64
name|test_mm_max_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pmaxs.w
return|return
name|_mm_max_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_max_pu8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_max_pu8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pmaxu.b
return|return
name|_mm_max_pu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_min_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pmins.w
return|return
name|_mm_min_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_min_pu8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_min_pu8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pminu.b
return|return
name|_mm_min_pu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_movemask_pi8
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_movemask_pi8
comment|// CHECK: call i32 @llvm.x86.mmx.pmovmskb
return|return
name|_mm_movemask_pi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_mul_su32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mul_su32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pmulu.dq(x86_mmx %{{.*}}, x86_mmx %{{.*}})
return|return
name|_mm_mul_su32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_mulhi_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mulhi_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pmulh.w
return|return
name|_mm_mulhi_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_mulhi_pu16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mulhi_pu16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pmulhu.w
return|return
name|_mm_mulhi_pu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_mulhrs_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mulhrs_pi16
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.pmul.hr.sw
return|return
name|_mm_mulhrs_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_mullo_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mullo_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pmull.w
return|return
name|_mm_mullo_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_or_si64
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_or_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.por
return|return
name|_mm_or_si64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_packs_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_packs_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.packsswb
return|return
name|_mm_packs_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_packs_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_packs_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.packssdw
return|return
name|_mm_packs_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_packs_pu16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_packs_pu16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.packuswb
return|return
name|_mm_packs_pu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sad_pu8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sad_pu8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psad.bw
return|return
name|_mm_sad_pu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_set_pi8
parameter_list|(
name|char
name|a
parameter_list|,
name|char
name|b
parameter_list|,
name|char
name|c
parameter_list|,
name|char
name|d
parameter_list|,
name|char
name|e
parameter_list|,
name|char
name|f
parameter_list|,
name|char
name|g
parameter_list|,
name|char
name|h
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_pi8
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
return|return
name|_mm_set_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|f
argument_list|,
name|g
argument_list|,
name|h
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_set_pi16
parameter_list|(
name|short
name|a
parameter_list|,
name|short
name|b
parameter_list|,
name|short
name|c
parameter_list|,
name|short
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_pi16
comment|// CHECK: insertelement<4 x i16>
comment|// CHECK: insertelement<4 x i16>
comment|// CHECK: insertelement<4 x i16>
comment|// CHECK: insertelement<4 x i16>
return|return
name|_mm_set_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_set_pi32
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set_pi32
comment|// CHECK: insertelement<2 x i32>
comment|// CHECK: insertelement<2 x i32>
return|return
name|_mm_set_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_setr_pi8
parameter_list|(
name|char
name|a
parameter_list|,
name|char
name|b
parameter_list|,
name|char
name|c
parameter_list|,
name|char
name|d
parameter_list|,
name|char
name|e
parameter_list|,
name|char
name|f
parameter_list|,
name|char
name|g
parameter_list|,
name|char
name|h
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setr_pi8
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
return|return
name|_mm_setr_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
name|e
argument_list|,
name|f
argument_list|,
name|g
argument_list|,
name|h
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_setr_pi16
parameter_list|(
name|short
name|a
parameter_list|,
name|short
name|b
parameter_list|,
name|short
name|c
parameter_list|,
name|short
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setr_pi16
comment|// CHECK: insertelement<4 x i16>
comment|// CHECK: insertelement<4 x i16>
comment|// CHECK: insertelement<4 x i16>
comment|// CHECK: insertelement<4 x i16>
return|return
name|_mm_setr_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_setr_pi32
parameter_list|(
name|int
name|a
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_setr_pi32
comment|// CHECK: insertelement<2 x i32>
comment|// CHECK: insertelement<2 x i32>
return|return
name|_mm_setr_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_set1_pi8
parameter_list|(
name|char
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_pi8
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
comment|// CHECK: insertelement<8 x i8>
return|return
name|_mm_set1_pi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_set1_pi16
parameter_list|(
name|short
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_pi16
comment|// CHECK: insertelement<4 x i16>
comment|// CHECK: insertelement<4 x i16>
comment|// CHECK: insertelement<4 x i16>
comment|// CHECK: insertelement<4 x i16>
return|return
name|_mm_set1_pi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_set1_pi32
parameter_list|(
name|int
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_set1_pi32
comment|// CHECK: insertelement<2 x i32>
comment|// CHECK: insertelement<2 x i32>
return|return
name|_mm_set1_pi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_shuffle_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shuffle_pi8
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.pshuf.b
return|return
name|_mm_shuffle_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_shuffle_pi16
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_shuffle_pi16
comment|// CHECK: call x86_mmx @llvm.x86.sse.pshuf.w
return|return
name|_mm_shuffle_pi16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sign_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sign_pi8
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.psign.b
return|return
name|_mm_sign_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sign_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sign_pi16
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.psign.w
return|return
name|_mm_sign_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sign_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sign_pi32
comment|// CHECK: call x86_mmx @llvm.x86.ssse3.psign.d
return|return
name|_mm_sign_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sll_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sll_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psll.w
return|return
name|_mm_sll_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sll_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sll_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psll.d
return|return
name|_mm_sll_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sll_si64
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sll_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psll.q
return|return
name|_mm_sll_si64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_slli_pi16
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_slli_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pslli.w
return|return
name|_mm_slli_pi16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_slli_pi32
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_slli_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pslli.d
return|return
name|_mm_slli_pi32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_slli_si64
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_slli_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pslli.q
return|return
name|_mm_slli_si64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sra_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sra_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psra.w
return|return
name|_mm_sra_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sra_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sra_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psra.d
return|return
name|_mm_sra_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_srai_pi16
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srai_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psrai.w
return|return
name|_mm_srai_pi16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_srai_pi32
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srai_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psrai.d
return|return
name|_mm_srai_pi32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_srl_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srl_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psrl.w
return|return
name|_mm_srl_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_srl_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srl_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psrl.d
return|return
name|_mm_srl_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_srl_si64
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srl_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psrl.q
return|return
name|_mm_srl_si64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_srli_pi16
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srli_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psrli.w
return|return
name|_mm_srli_pi16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_srli_pi32
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srli_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psrli.d
return|return
name|_mm_srli_pi32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_srli_si64
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srli_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psrli.q
return|return
name|_mm_srli_si64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_stream_pi
parameter_list|(
name|__m64
modifier|*
name|p
parameter_list|,
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_stream_pi
comment|// CHECK: call void @llvm.x86.mmx.movnt.dq
name|_mm_stream_pi
argument_list|(
name|p
argument_list|,
name|a
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sub_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_pi8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psub.b
return|return
name|_mm_sub_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sub_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psub.w
return|return
name|_mm_sub_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sub_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psub.d
return|return
name|_mm_sub_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_sub_si64
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sub_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psub.q(x86_mmx %{{.*}}, x86_mmx %{{.*}})
return|return
name|_mm_sub_si64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_subs_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_subs_pi8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psubs.b
return|return
name|_mm_subs_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_subs_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_subs_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psubs.w
return|return
name|_mm_subs_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_subs_pu8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_subs_pu8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psubus.b
return|return
name|_mm_subs_pu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_subs_pu16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_subs_pu16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.psubus.w
return|return
name|_mm_subs_pu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_m_to_int
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_m_to_int
comment|// CHECK: extractelement<2 x i32>
return|return
name|_m_to_int
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_m_to_int64
parameter_list|(
name|__m64
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_m_to_int64
comment|// CHECK: bitcast
return|return
name|_m_to_int64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_unpackhi_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpackhi_pi8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.punpckhbw
return|return
name|_mm_unpackhi_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_unpackhi_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpackhi_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.punpckhwd
return|return
name|_mm_unpackhi_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_unpackhi_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpackhi_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.punpckhdq
return|return
name|_mm_unpackhi_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_unpacklo_pi8
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpacklo_pi8
comment|// CHECK: call x86_mmx @llvm.x86.mmx.punpcklbw
return|return
name|_mm_unpacklo_pi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_unpacklo_pi16
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpacklo_pi16
comment|// CHECK: call x86_mmx @llvm.x86.mmx.punpcklwd
return|return
name|_mm_unpacklo_pi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_unpacklo_pi32
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_unpacklo_pi32
comment|// CHECK: call x86_mmx @llvm.x86.mmx.punpckldq
return|return
name|_mm_unpacklo_pi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m64
name|test_mm_xor_si64
parameter_list|(
name|__m64
name|a
parameter_list|,
name|__m64
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_xor_si64
comment|// CHECK: call x86_mmx @llvm.x86.mmx.pxor
return|return
name|_mm_xor_si64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

