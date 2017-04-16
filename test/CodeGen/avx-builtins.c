begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/sse-intrinsics-fast-isel.ll
end_comment

begin_function
name|__m256d
name|test_mm256_add_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_add_pd
comment|// CHECK: fadd<4 x double>
return|return
name|_mm256_add_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_add_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_add_ps
comment|// CHECK: fadd<8 x float>
return|return
name|_mm256_add_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_addsub_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_addsub_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.addsub.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_addsub_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_addsub_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_addsub_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.addsub.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_addsub_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_and_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_and_pd
comment|// CHECK: and<4 x i64>
return|return
name|_mm256_and_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_and_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_and_ps
comment|// CHECK: and<8 x i32>
return|return
name|_mm256_and_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_andnot_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_andnot_pd
comment|// CHECK: xor<4 x i64> %{{.*}},<i64 -1, i64 -1, i64 -1, i64 -1>
comment|// CHECK: and<4 x i64>
return|return
name|_mm256_andnot_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_andnot_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_andnot_ps
comment|// CHECK: xor<8 x i32> %{{.*}},<i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1, i32 -1>
comment|// CHECK: and<8 x i32>
return|return
name|_mm256_andnot_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_blend_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_blend_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 4, i32 1, i32 6, i32 3>
return|return
name|_mm256_blend_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0x35
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_blend_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_blend_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 8, i32 1, i32 10, i32 3, i32 12, i32 13, i32 6, i32 7>
return|return
name|_mm256_blend_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0x35
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_blendv_pd
parameter_list|(
name|__m256d
name|V1
parameter_list|,
name|__m256d
name|V2
parameter_list|,
name|__m256d
name|V3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_blendv_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.blendv.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_blendv_pd
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|V3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_blendv_ps
parameter_list|(
name|__m256
name|V1
parameter_list|,
name|__m256
name|V2
parameter_list|,
name|__m256
name|V3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_blendv_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.blendv.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_blendv_ps
argument_list|(
name|V1
argument_list|,
name|V2
argument_list|,
name|V3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_broadcast_pd
parameter_list|(
name|__m128d
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcast_pd
comment|// CHECK: load<2 x double>,<2 x double>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 0, i32 1>
return|return
name|_mm256_broadcast_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_broadcast_ps
parameter_list|(
name|__m128
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcast_ps
comment|// CHECK: load<4 x float>,<4 x float>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm256_broadcast_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_broadcast_sd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcast_sd
comment|// CHECK: load double, double* %{{.*}}
comment|// CHECK: insertelement<4 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 3
return|return
name|_mm256_broadcast_sd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_broadcast_ss
parameter_list|(
name|float
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_broadcast_ss
comment|// CHECK: load float, float* %{{.*}}
comment|// CHECK: insertelement<4 x float> undef, float %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x float> %{{.*}}, float %{{.*}}, i32 3
return|return
name|_mm_broadcast_ss
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_broadcast_ss
parameter_list|(
name|float
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcast_ss
comment|// CHECK: load float, float* %{{.*}}
comment|// CHECK: insertelement<8 x float> undef, float %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 7
return|return
name|_mm256_broadcast_ss
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_castpd_ps
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castpd_ps
comment|// CHECK: bitcast<4 x double> %{{.*}} to<8 x float>
return|return
name|_mm256_castpd_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_castpd_si256
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castpd_si256
comment|// CHECK: bitcast<4 x double> %{{.*}} to<4 x i64>
return|return
name|_mm256_castpd_si256
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_castpd128_pd256
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castpd128_pd256
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
return|return
name|_mm256_castpd128_pd256
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm256_castpd256_pd128
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castpd256_pd128
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<2 x i32><i32 0, i32 1>
return|return
name|_mm256_castpd256_pd128
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_castps_pd
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castps_pd
comment|// CHECK: bitcast<8 x float> %{{.*}} to<4 x double>
return|return
name|_mm256_castps_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_castps_si256
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castps_si256
comment|// CHECK: bitcast<8 x float> %{{.*}} to<4 x i64>
return|return
name|_mm256_castps_si256
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_castps128_ps256
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castps128_ps256
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef>
return|return
name|_mm256_castps128_ps256
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_castps256_ps128
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castps256_ps128
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
return|return
name|_mm256_castps256_ps128
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_castsi128_si256
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castsi128_si256
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
return|return
name|_mm256_castsi128_si256
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_castsi256_pd
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castsi256_pd
comment|// CHECK: bitcast<4 x i64> %{{.*}} to<4 x double>
return|return
name|_mm256_castsi256_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_castsi256_ps
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castsi256_ps
comment|// CHECK: bitcast<4 x i64> %{{.*}} to<8 x float>
return|return
name|_mm256_castsi256_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_castsi256_si128
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_castsi256_si128
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<2 x i32><i32 0, i32 1>
return|return
name|_mm256_castsi256_si128
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_ceil_pd
parameter_list|(
name|__m256d
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_ceil_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.round.pd.256(<4 x double> %{{.*}}, i32 2)
return|return
name|_mm256_ceil_pd
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm_ceil_ps
parameter_list|(
name|__m256
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_ceil_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.round.ps.256(<8 x float> %{{.*}}, i32 2)
return|return
name|_mm256_ceil_ps
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmp_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmp_pd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.pd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 13)
return|return
name|_mm_cmp_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_cmp_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmp_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.cmp.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}}, i8 13)
return|return
name|_mm256_cmp_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmp_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmp_ps
comment|// CHECK: call<4 x float> @llvm.x86.sse.cmp.ps(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 13)
return|return
name|_mm_cmp_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_cmp_ps
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmp_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.cmp.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}}, i8 13)
return|return
name|_mm256_cmp_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_cmp_sd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmp_sd
comment|// CHECK: call<2 x double> @llvm.x86.sse2.cmp.sd(<2 x double> %{{.*}},<2 x double> %{{.*}}, i8 13)
return|return
name|_mm_cmp_sd
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_cmp_ss
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_cmp_ss
comment|// CHECK: call<4 x float> @llvm.x86.sse.cmp.ss(<4 x float> %{{.*}},<4 x float> %{{.*}}, i8 13)
return|return
name|_mm_cmp_ss
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|_CMP_GE_OS
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_cvtepi32_pd
parameter_list|(
name|__m128i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepi32_pd
comment|// CHECK: sitofp<4 x i32> %{{.*}} to<4 x double>
return|return
name|_mm256_cvtepi32_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_cvtepi32_ps
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepi32_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.cvtdq2.ps.256(<8 x i32> %{{.*}})
return|return
name|_mm256_cvtepi32_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_cvtpd_epi32
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtpd_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx.cvt.pd2dq.256(<4 x double> %{{.*}})
return|return
name|_mm256_cvtpd_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_cvtpd_ps
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtpd_ps
comment|// CHECK: call<4 x float> @llvm.x86.avx.cvt.pd2.ps.256(<4 x double> %{{.*}})
return|return
name|_mm256_cvtpd_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtps_epi32
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtps_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx.cvt.ps2dq.256(<8 x float> %{{.*}})
return|return
name|_mm256_cvtps_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_cvtps_pd
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtps_pd
comment|// CHECK: fpext<4 x float> %{{.*}} to<4 x double>
return|return
name|_mm256_cvtps_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_cvttpd_epi32
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvttpd_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx.cvtt.pd2dq.256(<4 x double> %{{.*}})
return|return
name|_mm256_cvttpd_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvttps_epi32
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvttps_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx.cvtt.ps2dq.256(<8 x float> %{{.*}})
return|return
name|_mm256_cvttps_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_div_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_div_pd
comment|// CHECK: fdiv<4 x double>
return|return
name|_mm256_div_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_div_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_div_ps
comment|// CHECK: fdiv<8 x float>
return|return
name|_mm256_div_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_dp_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_dp_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.dp.ps.256(<8 x float> {{.*}},<8 x float> {{.*}}, i8 7)
return|return
name|_mm256_dp_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|7
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_extract_epi8
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_extract_epi8
comment|// CHECK: and i32 %{{.*}}, 31
comment|// CHECK: extractelement<32 x i8> %{{.*}}, i32 %{{.*}}
comment|// CHECK: zext i8 %{{.*}} to i32
return|return
name|_mm256_extract_epi8
argument_list|(
name|A
argument_list|,
literal|32
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_extract_epi16
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_extract_epi16
comment|// CHECK: and i32 %{{.*}}, 15
comment|// CHECK: extractelement<16 x i16> %{{.*}}, i32 %{{.*}}
comment|// CHECK: zext i16 %{{.*}} to i32
return|return
name|_mm256_extract_epi16
argument_list|(
name|A
argument_list|,
literal|16
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_extract_epi32
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_extract_epi32
comment|// CHECK: and i32 %{{.*}}, 7
comment|// CHECK: extractelement<8 x i32> %{{.*}}, i32 %{{.*}}
return|return
name|_mm256_extract_epi32
argument_list|(
name|A
argument_list|,
literal|8
argument_list|)
return|;
block|}
end_function

begin_function
name|long
name|long
name|test_mm256_extract_epi64
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_extract_epi64
comment|// CHECK: and i32 %{{.*}}, 3
comment|// CHECK: extractelement<4 x i64> %{{.*}}, i32 %{{.*}}
return|return
name|_mm256_extract_epi64
argument_list|(
name|A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm256_extractf128_pd
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_extractf128_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<2 x i32><i32 2, i32 3>
return|return
name|_mm256_extractf128_pd
argument_list|(
name|A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_extractf128_ps
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_extractf128_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_extractf128_ps
argument_list|(
name|A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_extractf128_si256
parameter_list|(
name|__m256i
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_extractf128_si256
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<2 x i32><i32 2, i32 3>
return|return
name|_mm256_extractf128_si256
argument_list|(
name|A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_floor_pd
parameter_list|(
name|__m256d
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_floor_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.round.pd.256(<4 x double> %{{.*}}, i32 1)
return|return
name|_mm256_floor_pd
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm_floor_ps
parameter_list|(
name|__m256
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_floor_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.round.ps.256(<8 x float> %{{.*}}, i32 1)
return|return
name|_mm256_floor_ps
argument_list|(
name|x
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_hadd_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hadd_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.hadd.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_hadd_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_hadd_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hadd_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.hadd.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_hadd_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_hsub_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hsub_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.hsub.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_hsub_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_hsub_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hsub_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.hsub.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_hsub_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_insert_epi8
parameter_list|(
name|__m256i
name|x
parameter_list|,
name|char
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_insert_epi8
comment|// CHECK: and i32 %{{.*}}, 31
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 %{{.*}}
return|return
name|_mm256_insert_epi8
argument_list|(
name|x
argument_list|,
name|b
argument_list|,
literal|17
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_insert_epi16
parameter_list|(
name|__m256i
name|x
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_insert_epi16
comment|// CHECK: and i32 %{{.*}}, 15
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 %{{.*}}
return|return
name|_mm256_insert_epi16
argument_list|(
name|x
argument_list|,
name|b
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_insert_epi32
parameter_list|(
name|__m256i
name|x
parameter_list|,
name|int
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_insert_epi32
comment|// CHECK: and i32 %{{.*}}, 7
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 %{{.*}}
return|return
name|_mm256_insert_epi32
argument_list|(
name|x
argument_list|,
name|b
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_insert_epi64
parameter_list|(
name|__m256i
name|x
parameter_list|,
name|long
name|long
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_insert_epi64
comment|// CHECK: and i32 %{{.*}}, 3
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 %{{.*}}
return|return
name|_mm256_insert_epi64
argument_list|(
name|x
argument_list|,
name|b
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_insertf128_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_insertf128_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 4, i32 5, i32 2, i32 3>
return|return
name|_mm256_insertf128_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_insertf128_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_insertf128_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
return|return
name|_mm256_insertf128_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_insertf128_si256
parameter_list|(
name|__m256i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_insertf128_si256
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 4, i32 5, i32 2, i32 3>
return|return
name|_mm256_insertf128_si256
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_lddqu_si256
parameter_list|(
name|__m256i
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_lddqu_si256
comment|// CHECK: call<32 x i8> @llvm.x86.avx.ldu.dq.256(i8* %{{.*}})
return|return
name|_mm256_lddqu_si256
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_load_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_load_pd
comment|// CHECK: load<4 x double>,<4 x double>* %{{.*}}, align 32
return|return
name|_mm256_load_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_load_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_load_ps
comment|// CHECK: load<8 x float>,<8 x float>* %{{.*}}, align 32
return|return
name|_mm256_load_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_load_si256
parameter_list|(
name|__m256i
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_load_si256
comment|// CHECK: load<4 x i64>,<4 x i64>* %{{.*}}, align 32
return|return
name|_mm256_load_si256
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_loadu_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_loadu_pd
comment|// CHECK: load<4 x double>,<4 x double>* %{{.*}}, align 1{{$}}
return|return
name|_mm256_loadu_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_loadu_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_loadu_ps
comment|// CHECK: load<8 x float>,<8 x float>* %{{.*}}, align 1{{$}}
return|return
name|_mm256_loadu_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_loadu_si256
parameter_list|(
name|__m256i
modifier|*
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_loadu_si256
comment|// CHECK: load<4 x i64>,<4 x i64>* %{{.+}}, align 1{{$}}
return|return
name|_mm256_loadu_si256
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_loadu2_m128
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|float
modifier|*
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_loadu2_m128
comment|// CHECK: load<4 x float>,<4 x float>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: load<4 x float>,<4 x float>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 undef, i32 undef, i32 undef, i32 undef>
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 8, i32 9, i32 10, i32 11>
return|return
name|_mm256_loadu2_m128
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_loadu2_m128d
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|double
modifier|*
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_loadu2_m128d
comment|// CHECK: load<2 x double>,<2 x double>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
comment|// CHECK: load<2 x double>,<2 x double>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
return|return
name|_mm256_loadu2_m128d
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_loadu2_m128i
parameter_list|(
name|__m128i
modifier|*
name|A
parameter_list|,
name|__m128i
modifier|*
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_loadu2_m128i
comment|// CHECK: load<2 x i64>,<2 x i64>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
comment|// CHECK: load<2 x i64>,<2 x i64>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
return|return
name|_mm256_loadu2_m128i
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_maskload_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskload_pd
comment|// CHECK: call<2 x double> @llvm.x86.avx.maskload.pd(i8* %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_maskload_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskload_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_maskload_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.maskload.pd.256(i8* %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_maskload_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_maskload_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskload_ps
comment|// CHECK: call<4 x float> @llvm.x86.avx.maskload.ps(i8* %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_maskload_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_maskload_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_maskload_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.maskload.ps.256(i8* %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_maskload_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_maskstore_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|__m128d
name|C
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskstore_pd
comment|// CHECK: call void @llvm.x86.avx.maskstore.pd(i8* %{{.*}},<2 x i64> %{{.*}},<2 x double> %{{.*}})
name|_mm_maskstore_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_maskstore_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|,
name|__m256d
name|C
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_maskstore_pd
comment|// CHECK: call void @llvm.x86.avx.maskstore.pd.256(i8* %{{.*}},<4 x i64> %{{.*}},<4 x double> %{{.*}})
name|_mm256_maskstore_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_maskstore_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|,
name|__m128
name|C
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskstore_ps
comment|// CHECK: call void @llvm.x86.avx.maskstore.ps(i8* %{{.*}},<4 x i32> %{{.*}},<4 x float> %{{.*}})
name|_mm_maskstore_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_maskstore_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|,
name|__m256
name|C
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_maskstore_ps
comment|// CHECK: call void @llvm.x86.avx.maskstore.ps.256(i8* %{{.*}},<8 x i32> %{{.*}},<8 x float> %{{.*}})
name|_mm256_maskstore_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_max_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_max_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.max.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_max_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_max_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_max_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.max.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_max_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_min_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_min_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.min.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_min_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_min_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_min_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.min.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_min_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_movedup_pd
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_movedup_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 0, i32 2, i32 2>
return|return
name|_mm256_movedup_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_movehdup_ps
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_movehdup_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 1, i32 1, i32 3, i32 3, i32 5, i32 5, i32 7, i32 7>
return|return
name|_mm256_movehdup_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_moveldup_ps
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_moveldup_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 0, i32 2, i32 2, i32 4, i32 4, i32 6, i32 6>
return|return
name|_mm256_moveldup_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_movemask_pd
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_movemask_pd
comment|// CHECK: call i32 @llvm.x86.avx.movmsk.pd.256(<4 x double> %{{.*}})
return|return
name|_mm256_movemask_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_movemask_ps
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_movemask_ps
comment|// CHECK: call i32 @llvm.x86.avx.movmsk.ps.256(<8 x float> %{{.*}})
return|return
name|_mm256_movemask_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mul_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mul_pd
comment|// CHECK: fmul<4 x double>
return|return
name|_mm256_mul_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mul_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mul_ps
comment|// CHECK: fmul<8 x float>
return|return
name|_mm256_mul_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_or_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_or_pd
comment|// CHECK: or<4 x i64>
return|return
name|_mm256_or_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_or_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_or_ps
comment|// CHECK: or<8 x i32>
return|return
name|_mm256_or_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_permute_pd
parameter_list|(
name|__m128d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_permute_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> zeroinitializer,<2 x i32><i32 1, i32 0>
return|return
name|_mm_permute_pd
argument_list|(
name|A
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_permute_pd
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<4 x i32><i32 1, i32 0, i32 3, i32 2>
return|return
name|_mm256_permute_pd
argument_list|(
name|A
argument_list|,
literal|5
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_permute_ps
parameter_list|(
name|__m128
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_permute_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> zeroinitializer,<4 x i32><i32 3, i32 2, i32 1, i32 0>
return|return
name|_mm_permute_ps
argument_list|(
name|A
argument_list|,
literal|0x1b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Test case for PR12401
end_comment

begin_function
name|__m128
name|test2_mm_permute_ps
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test2_mm_permute_ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> zeroinitializer,<4 x i32><i32 2, i32 1, i32 2, i32 3>
return|return
name|_mm_permute_ps
argument_list|(
name|a
argument_list|,
literal|0xe6
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_permute_ps
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> zeroinitializer,<8 x i32><i32 3, i32 2, i32 1, i32 0, i32 7, i32 6, i32 5, i32 4>
return|return
name|_mm256_permute_ps
argument_list|(
name|A
argument_list|,
literal|0x1b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_permute2f128_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute2f128_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.vperm2f128.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}}, i8 49)
return|return
name|_mm256_permute2f128_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0x31
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_permute2f128_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute2f128_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.vperm2f128.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}}, i8 19)
return|return
name|_mm256_permute2f128_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0x13
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_permute2f128_si256
parameter_list|(
name|__m256i
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute2f128_si256
comment|// CHECK: call<8 x i32> @llvm.x86.avx.vperm2f128.si.256(<8 x i32> %{{.*}},<8 x i32> %{{.*}}, i8 32)
return|return
name|_mm256_permute2f128_si256
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0x20
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_permutevar_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_permutevar_pd
comment|// CHECK: call<2 x double> @llvm.x86.avx.vpermilvar.pd(<2 x double> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_permutevar_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_permutevar_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permutevar_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.vpermilvar.pd.256(<4 x double> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_permutevar_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_permutevar_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_permutevar_ps
comment|// CHECK: call<4 x float> @llvm.x86.avx.vpermilvar.ps(<4 x float> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_permutevar_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_permutevar_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permutevar_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.vpermilvar.ps.256(<8 x float> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_permutevar_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_rcp_ps
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_rcp_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.rcp.ps.256(<8 x float> %{{.*}})
return|return
name|_mm256_rcp_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_round_pd
parameter_list|(
name|__m256d
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_round_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.round.pd.256(<4 x double> %{{.*}}, i32 4)
return|return
name|_mm256_round_pd
argument_list|(
name|x
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_round_ps
parameter_list|(
name|__m256
name|x
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_round_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.round.ps.256(<8 x float> %{{.*}}, i32 4)
return|return
name|_mm256_round_ps
argument_list|(
name|x
argument_list|,
literal|4
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_rsqrt_ps
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_rsqrt_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.rsqrt.ps.256(<8 x float> %{{.*}})
return|return
name|_mm256_rsqrt_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set_epi8
parameter_list|(
name|char
name|A0
parameter_list|,
name|char
name|A1
parameter_list|,
name|char
name|A2
parameter_list|,
name|char
name|A3
parameter_list|,
name|char
name|A4
parameter_list|,
name|char
name|A5
parameter_list|,
name|char
name|A6
parameter_list|,
name|char
name|A7
parameter_list|,
name|char
name|A8
parameter_list|,
name|char
name|A9
parameter_list|,
name|char
name|A10
parameter_list|,
name|char
name|A11
parameter_list|,
name|char
name|A12
parameter_list|,
name|char
name|A13
parameter_list|,
name|char
name|A14
parameter_list|,
name|char
name|A15
parameter_list|,
name|char
name|A16
parameter_list|,
name|char
name|A17
parameter_list|,
name|char
name|A18
parameter_list|,
name|char
name|A19
parameter_list|,
name|char
name|A20
parameter_list|,
name|char
name|A21
parameter_list|,
name|char
name|A22
parameter_list|,
name|char
name|A23
parameter_list|,
name|char
name|A24
parameter_list|,
name|char
name|A25
parameter_list|,
name|char
name|A26
parameter_list|,
name|char
name|A27
parameter_list|,
name|char
name|A28
parameter_list|,
name|char
name|A29
parameter_list|,
name|char
name|A30
parameter_list|,
name|char
name|A31
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set_epi8
comment|// CHECK: insertelement<32 x i8> undef, i8 %{{.*}}, i32 0
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 1
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 2
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 3
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 4
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 5
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 6
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 7
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 8
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 9
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 10
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 11
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 12
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 13
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 14
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 15
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 16
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 17
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 18
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 19
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 20
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 21
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 22
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 23
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 24
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 25
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 26
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 27
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 28
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 29
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 30
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 31
return|return
name|_mm256_set_epi8
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|A4
argument_list|,
name|A5
argument_list|,
name|A6
argument_list|,
name|A7
argument_list|,
name|A8
argument_list|,
name|A9
argument_list|,
name|A10
argument_list|,
name|A11
argument_list|,
name|A12
argument_list|,
name|A13
argument_list|,
name|A14
argument_list|,
name|A15
argument_list|,
name|A16
argument_list|,
name|A17
argument_list|,
name|A18
argument_list|,
name|A19
argument_list|,
name|A20
argument_list|,
name|A21
argument_list|,
name|A22
argument_list|,
name|A23
argument_list|,
name|A24
argument_list|,
name|A25
argument_list|,
name|A26
argument_list|,
name|A27
argument_list|,
name|A28
argument_list|,
name|A29
argument_list|,
name|A30
argument_list|,
name|A31
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set_epi16
parameter_list|(
name|short
name|A0
parameter_list|,
name|short
name|A1
parameter_list|,
name|short
name|A2
parameter_list|,
name|short
name|A3
parameter_list|,
name|short
name|A4
parameter_list|,
name|short
name|A5
parameter_list|,
name|short
name|A6
parameter_list|,
name|short
name|A7
parameter_list|,
name|short
name|A8
parameter_list|,
name|short
name|A9
parameter_list|,
name|short
name|A10
parameter_list|,
name|short
name|A11
parameter_list|,
name|short
name|A12
parameter_list|,
name|short
name|A13
parameter_list|,
name|short
name|A14
parameter_list|,
name|short
name|A15
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set_epi16
comment|// CHECK: insertelement<16 x i16> undef, i16 %{{.*}}, i32 0
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 1
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 2
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 3
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 4
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 5
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 6
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 7
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 8
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 9
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 10
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 11
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 12
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 13
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 14
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 15
return|return
name|_mm256_set_epi16
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|A4
argument_list|,
name|A5
argument_list|,
name|A6
argument_list|,
name|A7
argument_list|,
name|A8
argument_list|,
name|A9
argument_list|,
name|A10
argument_list|,
name|A11
argument_list|,
name|A12
argument_list|,
name|A13
argument_list|,
name|A14
argument_list|,
name|A15
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set_epi32
parameter_list|(
name|int
name|A0
parameter_list|,
name|int
name|A1
parameter_list|,
name|int
name|A2
parameter_list|,
name|int
name|A3
parameter_list|,
name|int
name|A4
parameter_list|,
name|int
name|A5
parameter_list|,
name|int
name|A6
parameter_list|,
name|int
name|A7
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set_epi32
comment|// CHECK: insertelement<8 x i32> undef, i32 %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 7
return|return
name|_mm256_set_epi32
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|A4
argument_list|,
name|A5
argument_list|,
name|A6
argument_list|,
name|A7
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set_epi64x
parameter_list|(
name|long
name|long
name|A0
parameter_list|,
name|long
name|long
name|A1
parameter_list|,
name|long
name|long
name|A2
parameter_list|,
name|long
name|long
name|A3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set_epi64x
comment|// CHECK: insertelement<4 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 3
return|return
name|_mm256_set_epi64x
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_set_m128
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set_m128
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_set_m128
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_set_m128d
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set_m128d
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_set_m128d
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set_m128i
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set_m128i
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_set_m128i
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_set_pd
parameter_list|(
name|double
name|A0
parameter_list|,
name|double
name|A1
parameter_list|,
name|double
name|A2
parameter_list|,
name|double
name|A3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set_pd
comment|// CHECK: insertelement<4 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 3
return|return
name|_mm256_set_pd
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_set_ps
parameter_list|(
name|float
name|A0
parameter_list|,
name|float
name|A1
parameter_list|,
name|float
name|A2
parameter_list|,
name|float
name|A3
parameter_list|,
name|float
name|A4
parameter_list|,
name|float
name|A5
parameter_list|,
name|float
name|A6
parameter_list|,
name|float
name|A7
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set_ps
comment|// CHECK: insertelement<8 x float> undef, float %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 7
return|return
name|_mm256_set_ps
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|A4
argument_list|,
name|A5
argument_list|,
name|A6
argument_list|,
name|A7
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set1_epi8
parameter_list|(
name|char
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set1_epi8
comment|// CHECK: insertelement<32 x i8> undef, i8 %{{.*}}, i32 0
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 1
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 2
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 3
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 4
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 5
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 6
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 7
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 8
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 9
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 10
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 11
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 12
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 13
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 14
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 15
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 16
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 17
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 18
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 19
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 20
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 21
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 22
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 23
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 24
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 25
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 26
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 27
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 28
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 29
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 30
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 31
return|return
name|_mm256_set1_epi8
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set1_epi16
parameter_list|(
name|short
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set1_epi16
comment|// CHECK: insertelement<16 x i16> undef, i16 %{{.*}}, i32 0
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 1
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 2
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 3
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 4
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 5
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 6
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 7
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 8
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 9
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 10
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 11
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 12
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 13
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 14
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 15
return|return
name|_mm256_set1_epi16
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set1_epi32
parameter_list|(
name|int
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set1_epi32
comment|// CHECK: insertelement<8 x i32> undef, i32 %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 7
return|return
name|_mm256_set1_epi32
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_set1_epi64x
parameter_list|(
name|long
name|long
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set1_epi64x
comment|// CHECK: insertelement<4 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 3
return|return
name|_mm256_set1_epi64x
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_set1_pd
parameter_list|(
name|double
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set1_pd
comment|// CHECK: insertelement<4 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 3
return|return
name|_mm256_set1_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_set1_ps
parameter_list|(
name|float
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_set1_ps
comment|// CHECK: insertelement<8 x float> undef, float %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 7
return|return
name|_mm256_set1_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_setr_epi8
parameter_list|(
name|char
name|A0
parameter_list|,
name|char
name|A1
parameter_list|,
name|char
name|A2
parameter_list|,
name|char
name|A3
parameter_list|,
name|char
name|A4
parameter_list|,
name|char
name|A5
parameter_list|,
name|char
name|A6
parameter_list|,
name|char
name|A7
parameter_list|,
name|char
name|A8
parameter_list|,
name|char
name|A9
parameter_list|,
name|char
name|A10
parameter_list|,
name|char
name|A11
parameter_list|,
name|char
name|A12
parameter_list|,
name|char
name|A13
parameter_list|,
name|char
name|A14
parameter_list|,
name|char
name|A15
parameter_list|,
name|char
name|A16
parameter_list|,
name|char
name|A17
parameter_list|,
name|char
name|A18
parameter_list|,
name|char
name|A19
parameter_list|,
name|char
name|A20
parameter_list|,
name|char
name|A21
parameter_list|,
name|char
name|A22
parameter_list|,
name|char
name|A23
parameter_list|,
name|char
name|A24
parameter_list|,
name|char
name|A25
parameter_list|,
name|char
name|A26
parameter_list|,
name|char
name|A27
parameter_list|,
name|char
name|A28
parameter_list|,
name|char
name|A29
parameter_list|,
name|char
name|A30
parameter_list|,
name|char
name|A31
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_setr_epi8
comment|// CHECK: insertelement<32 x i8> undef, i8 %{{.*}}, i32 0
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 1
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 2
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 3
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 4
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 5
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 6
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 7
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 8
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 9
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 10
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 11
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 12
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 13
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 14
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 15
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 16
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 17
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 18
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 19
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 20
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 21
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 22
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 23
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 24
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 25
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 26
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 27
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 28
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 29
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 30
comment|// CHECK: insertelement<32 x i8> %{{.*}}, i8 %{{.*}}, i32 31
return|return
name|_mm256_setr_epi8
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|A4
argument_list|,
name|A5
argument_list|,
name|A6
argument_list|,
name|A7
argument_list|,
name|A8
argument_list|,
name|A9
argument_list|,
name|A10
argument_list|,
name|A11
argument_list|,
name|A12
argument_list|,
name|A13
argument_list|,
name|A14
argument_list|,
name|A15
argument_list|,
name|A16
argument_list|,
name|A17
argument_list|,
name|A18
argument_list|,
name|A19
argument_list|,
name|A20
argument_list|,
name|A21
argument_list|,
name|A22
argument_list|,
name|A23
argument_list|,
name|A24
argument_list|,
name|A25
argument_list|,
name|A26
argument_list|,
name|A27
argument_list|,
name|A28
argument_list|,
name|A29
argument_list|,
name|A30
argument_list|,
name|A31
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_setr_epi16
parameter_list|(
name|short
name|A0
parameter_list|,
name|short
name|A1
parameter_list|,
name|short
name|A2
parameter_list|,
name|short
name|A3
parameter_list|,
name|short
name|A4
parameter_list|,
name|short
name|A5
parameter_list|,
name|short
name|A6
parameter_list|,
name|short
name|A7
parameter_list|,
name|short
name|A8
parameter_list|,
name|short
name|A9
parameter_list|,
name|short
name|A10
parameter_list|,
name|short
name|A11
parameter_list|,
name|short
name|A12
parameter_list|,
name|short
name|A13
parameter_list|,
name|short
name|A14
parameter_list|,
name|short
name|A15
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_setr_epi16
comment|// CHECK: insertelement<16 x i16> undef, i16 %{{.*}}, i32 0
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 1
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 2
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 3
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 4
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 5
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 6
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 7
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 8
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 9
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 10
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 11
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 12
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 13
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 14
comment|// CHECK: insertelement<16 x i16> %{{.*}}, i16 %{{.*}}, i32 15
return|return
name|_mm256_setr_epi16
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|A4
argument_list|,
name|A5
argument_list|,
name|A6
argument_list|,
name|A7
argument_list|,
name|A8
argument_list|,
name|A9
argument_list|,
name|A10
argument_list|,
name|A11
argument_list|,
name|A12
argument_list|,
name|A13
argument_list|,
name|A14
argument_list|,
name|A15
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_setr_epi32
parameter_list|(
name|int
name|A0
parameter_list|,
name|int
name|A1
parameter_list|,
name|int
name|A2
parameter_list|,
name|int
name|A3
parameter_list|,
name|int
name|A4
parameter_list|,
name|int
name|A5
parameter_list|,
name|int
name|A6
parameter_list|,
name|int
name|A7
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_setr_epi32
comment|// CHECK: insertelement<8 x i32> undef, i32 %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x i32> %{{.*}}, i32 %{{.*}}, i32 7
return|return
name|_mm256_setr_epi32
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|A4
argument_list|,
name|A5
argument_list|,
name|A6
argument_list|,
name|A7
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_setr_epi64x
parameter_list|(
name|long
name|long
name|A0
parameter_list|,
name|long
name|long
name|A1
parameter_list|,
name|long
name|long
name|A2
parameter_list|,
name|long
name|long
name|A3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_setr_epi64x
comment|// CHECK: insertelement<4 x i64> undef, i64 %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x i64> %{{.*}}, i64 %{{.*}}, i32 3
return|return
name|_mm256_setr_epi64x
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_setr_m128
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_setr_m128
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_setr_m128
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_setr_m128d
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_setr_m128d
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_setr_m128d
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_setr_m128i
parameter_list|(
name|__m128i
name|A
parameter_list|,
name|__m128i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_setr_m128i
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
return|return
name|_mm256_setr_m128i
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_setr_pd
parameter_list|(
name|double
name|A0
parameter_list|,
name|double
name|A1
parameter_list|,
name|double
name|A2
parameter_list|,
name|double
name|A3
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_setr_pd
comment|// CHECK: insertelement<4 x double> undef, double %{{.*}}, i32 0
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 1
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 2
comment|// CHECK: insertelement<4 x double> %{{.*}}, double %{{.*}}, i32 3
return|return
name|_mm256_setr_pd
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_setr_ps
parameter_list|(
name|float
name|A0
parameter_list|,
name|float
name|A1
parameter_list|,
name|float
name|A2
parameter_list|,
name|float
name|A3
parameter_list|,
name|float
name|A4
parameter_list|,
name|float
name|A5
parameter_list|,
name|float
name|A6
parameter_list|,
name|float
name|A7
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_setr_ps
comment|// CHECK: insertelement<8 x float> undef, float %{{.*}}, i32 0
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 1
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 2
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 3
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 4
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 5
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 6
comment|// CHECK: insertelement<8 x float> %{{.*}}, float %{{.*}}, i32 7
return|return
name|_mm256_setr_ps
argument_list|(
name|A0
argument_list|,
name|A1
argument_list|,
name|A2
argument_list|,
name|A3
argument_list|,
name|A4
argument_list|,
name|A5
argument_list|,
name|A6
argument_list|,
name|A7
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_setzero_pd
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm256_setzero_pd
comment|// CHECK: store<4 x double> zeroinitializer
return|return
name|_mm256_setzero_pd
argument_list|()
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_setzero_ps
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm256_setzero_ps
comment|// CHECK: store<8 x float> zeroinitializer
return|return
name|_mm256_setzero_ps
argument_list|()
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_setzero_si256
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm256_setzero_si256
comment|// CHECK: store<4 x i64> zeroinitializer
return|return
name|_mm256_setzero_si256
argument_list|()
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_shuffle_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_shuffle_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 4, i32 2, i32 6>
return|return
name|_mm256_shuffle_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_shuffle_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_shuffle_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 0, i32 8, i32 8, i32 4, i32 4, i32 12, i32 12>
return|return
name|_mm256_shuffle_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_sqrt_pd
parameter_list|(
name|__m256d
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sqrt_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx.sqrt.pd.256(<4 x double> %{{.*}})
return|return
name|_mm256_sqrt_pd
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_sqrt_ps
parameter_list|(
name|__m256
name|A
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sqrt_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx.sqrt.ps.256(<8 x float> %{{.*}})
return|return
name|_mm256_sqrt_ps
argument_list|(
name|A
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_store_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_store_pd
comment|// CHECK: store<4 x double> %{{.*}},<4 x double>* %{{.*}}, align 32
name|_mm256_store_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_store_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_store_ps
comment|// CHECK: store<8 x float> %{{.*}},<8 x float>* %{{.*}}, align 32
name|_mm256_store_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_store_si256
parameter_list|(
name|__m256i
modifier|*
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_store_si256
comment|// CHECK: store<4 x i64> %{{.*}},<4 x i64>* %{{.*}}, align 32
name|_mm256_store_si256
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_storeu_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_storeu_pd
comment|// CHECK:   store<4 x double> %{{.*}},<4 x double>* %{{.*}}, align 1{{$}}
comment|// CHECK-NEXT: ret void
name|_mm256_storeu_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_storeu_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_storeu_ps
comment|// CHECK: store<8 x float> %{{.*}},<8 x float>* %{{.*}}, align 1{{$}}
comment|// CHECk-NEXT: ret void
name|_mm256_storeu_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_storeu_si256
parameter_list|(
name|__m256i
modifier|*
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_storeu_si256
comment|// CHECK: store<4 x i64> %{{.*}},<4 x i64>* %{{.*}}, align 1{{$}}
comment|// CHECk-NEXT: ret void
name|_mm256_storeu_si256
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_storeu2_m128
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|float
modifier|*
name|B
parameter_list|,
name|__m256
name|C
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_storeu2_m128
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: store<4 x float> %{{.*}},<4 x float>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> zeroinitializer,<4 x i32><i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: store<4 x float> %{{.*}},<4 x float>* %{{.*}}, align 1{{$}}
name|_mm256_storeu2_m128
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_storeu2_m128d
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|double
modifier|*
name|B
parameter_list|,
name|__m256d
name|C
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_storeu2_m128d
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: store<2 x double> %{{.*}},<2 x double>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<2 x i32><i32 2, i32 3>
comment|// CHECK: store<2 x double> %{{.*}},<2 x double>* %{{.*}}, align 1{{$}}
name|_mm256_storeu2_m128d
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_storeu2_m128i
parameter_list|(
name|__m128i
modifier|*
name|A
parameter_list|,
name|__m128i
modifier|*
name|B
parameter_list|,
name|__m256i
name|C
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_storeu2_m128i
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<2 x i32><i32 0, i32 1>
comment|// CHECK: store<2 x i64> %{{.*}},<2 x i64>* %{{.*}}, align 1{{$}}
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<2 x i32><i32 2, i32 3>
comment|// CHECK: store<2 x i64> %{{.*}},<2 x i64>* %{{.*}}, align 1{{$}}
name|_mm256_storeu2_m128i
argument_list|(
name|A
argument_list|,
name|B
argument_list|,
name|C
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_stream_pd
parameter_list|(
name|double
modifier|*
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_stream_pd
comment|// CHECK: store<4 x double> %{{.*}},<4 x double>* %{{.*}}, align 32, !nontemporal
name|_mm256_stream_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_stream_ps
parameter_list|(
name|float
modifier|*
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_stream_ps
comment|// CHECK: store<8 x float> %{{.*}},<8 x float>* %{{.*}}, align 32, !nontemporal
name|_mm256_stream_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_stream_si256
parameter_list|(
name|__m256i
modifier|*
name|A
parameter_list|,
name|__m256i
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_stream_si256
comment|// CHECK: store<4 x i64> %{{.*}},<4 x i64>* %{{.*}}, align 32, !nontemporal
name|_mm256_stream_si256
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_sub_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sub_pd
comment|// CHECK: fsub<4 x double>
return|return
name|_mm256_sub_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_sub_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sub_ps
comment|// CHECK: fsub<8 x float>
return|return
name|_mm256_sub_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_testc_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_testc_pd
comment|// CHECK: call i32 @llvm.x86.avx.vtestc.pd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_testc_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_testc_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_testc_pd
comment|// CHECK: call i32 @llvm.x86.avx.vtestc.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_testc_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_testc_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_testc_ps
comment|// CHECK: call i32 @llvm.x86.avx.vtestc.ps(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_testc_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_testc_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_testc_ps
comment|// CHECK: call i32 @llvm.x86.avx.vtestc.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_testc_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_testc_si256
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_testc_si256
comment|// CHECK: call i32 @llvm.x86.avx.ptestc.256(<4 x i64> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_testc_si256
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_testnzc_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_testnzc_pd
comment|// CHECK: call i32 @llvm.x86.avx.vtestnzc.pd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_testnzc_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_testnzc_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_testnzc_pd
comment|// CHECK: call i32 @llvm.x86.avx.vtestnzc.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_testnzc_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_testnzc_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_testnzc_ps
comment|// CHECK: call i32 @llvm.x86.avx.vtestnzc.ps(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_testnzc_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_testnzc_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_testnzc_ps
comment|// CHECK: call i32 @llvm.x86.avx.vtestnzc.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_testnzc_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_testnzc_si256
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_testnzc_si256
comment|// CHECK: call i32 @llvm.x86.avx.ptestnzc.256(<4 x i64> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_testnzc_si256
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_testz_pd
parameter_list|(
name|__m128d
name|A
parameter_list|,
name|__m128d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_testz_pd
comment|// CHECK: call i32 @llvm.x86.avx.vtestz.pd(<2 x double> %{{.*}},<2 x double> %{{.*}})
return|return
name|_mm_testz_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_testz_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_testz_pd
comment|// CHECK: call i32 @llvm.x86.avx.vtestz.pd.256(<4 x double> %{{.*}},<4 x double> %{{.*}})
return|return
name|_mm256_testz_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm_testz_ps
parameter_list|(
name|__m128
name|A
parameter_list|,
name|__m128
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_testz_ps
comment|// CHECK: call i32 @llvm.x86.avx.vtestz.ps(<4 x float> %{{.*}},<4 x float> %{{.*}})
return|return
name|_mm_testz_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_testz_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_testz_ps
comment|// CHECK: call i32 @llvm.x86.avx.vtestz.ps.256(<8 x float> %{{.*}},<8 x float> %{{.*}})
return|return
name|_mm256_testz_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_testz_si256
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_testz_si256
comment|// CHECK: call i32 @llvm.x86.avx.ptestz.256(<4 x i64> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_testz_si256
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_undefined_ps
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm256_undefined_ps
comment|// CHECK: ret<8 x float> zeroinitializer
return|return
name|_mm256_undefined_ps
argument_list|()
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_undefined_pd
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm256_undefined_pd
comment|// CHECK: ret<4 x double> zeroinitializer
return|return
name|_mm256_undefined_pd
argument_list|()
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_undefined_si256
parameter_list|()
block|{
comment|// CHECK-LABEL: @test_mm256_undefined_si256
comment|// CHECK: ret<4 x i64> zeroinitializer
return|return
name|_mm256_undefined_si256
argument_list|()
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_unpackhi_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpackhi_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 1, i32 5, i32 3, i32 7>
return|return
name|_mm256_unpackhi_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_unpackhi_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpackhi_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 2, i32 10, i32 3, i32 11, i32 6, i32 14, i32 7, i32 15>
return|return
name|_mm256_unpackhi_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_unpacklo_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpacklo_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> %{{.*}},<4 x i32><i32 0, i32 4, i32 2, i32 6>
return|return
name|_mm256_unpacklo_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_unpacklo_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpacklo_ps
comment|// CHECK: shufflevector<8 x float> %{{.*}},<8 x float> %{{.*}},<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 4, i32 12, i32 5, i32 13>
return|return
name|_mm256_unpacklo_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_xor_pd
parameter_list|(
name|__m256d
name|A
parameter_list|,
name|__m256d
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_xor_pd
comment|// CHECK: xor<4 x i64>
return|return
name|_mm256_xor_pd
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_xor_ps
parameter_list|(
name|__m256
name|A
parameter_list|,
name|__m256
name|B
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_xor_ps
comment|// CHECK: xor<8 x i32>
return|return
name|_mm256_xor_ps
argument_list|(
name|A
argument_list|,
name|B
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_zeroall
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm256_zeroall
comment|// CHECK: call void @llvm.x86.avx.vzeroall()
return|return
name|_mm256_zeroall
argument_list|()
return|;
block|}
end_function

begin_function
name|void
name|test_mm256_zeroupper
parameter_list|()
block|{
comment|// CHECK-LABEL: test_mm256_zeroupper
comment|// CHECK: call void @llvm.x86.avx.vzeroupper()
return|return
name|_mm256_zeroupper
argument_list|()
return|;
block|}
end_function

begin_function
name|double
name|test_mm256_cvtsd_f64
parameter_list|(
name|__m256d
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtsd_f64
comment|// CHECK: extractelement<4 x double> %{{.*}}, i32 0
return|return
name|_mm256_cvtsd_f64
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
name|int
name|test_mm256_cvtsi256_si32
parameter_list|(
name|__m256i
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtsi256_si32
comment|// CHECK: extractelement<8 x i32> %{{.*}}, i32 0
return|return
name|_mm256_cvtsi256_si32
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

begin_function
name|float
name|test_mm256_cvtss_f32
parameter_list|(
name|__m256
name|__a
parameter_list|)
block|{
comment|// CHECK-LABEL: @test_mm256_cvtss_f32
comment|// CHECK: extractelement<8 x float> %{{.*}}, i32 0
return|return
name|_mm256_cvtss_f32
argument_list|(
name|__a
argument_list|)
return|;
block|}
end_function

end_unit

