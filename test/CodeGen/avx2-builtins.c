begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx2 -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_comment
comment|// RUN: %clang_cc1 -ffreestanding %s -triple=x86_64-apple-darwin -target-feature +avx2 -fno-signed-char -emit-llvm -o - -Wall -Werror | FileCheck %s
end_comment

begin_include
include|#
directive|include
file|<x86intrin.h>
end_include

begin_comment
comment|// NOTE: This should match the tests in llvm/test/CodeGen/X86/avx2-intrinsics-fast-isel.ll
end_comment

begin_function
name|__m256i
name|test_mm256_abs_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_abs_epi8
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.pabs.b(<32 x i8> %{{.*}})
return|return
name|_mm256_abs_epi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_abs_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_abs_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.pabs.w(<16 x i16> %{{.*}})
return|return
name|_mm256_abs_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_abs_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_abs_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.pabs.d(<8 x i32> %{{.*}})
return|return
name|_mm256_abs_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_add_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_add_epi8
comment|// CHECK: add<32 x i8>
return|return
name|_mm256_add_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_add_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_add_epi16
comment|// CHECK: add<16 x i16>
return|return
name|_mm256_add_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_add_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_add_epi32
comment|// CHECK: add<8 x i32>
return|return
name|_mm256_add_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_add_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_add_epi64
comment|// CHECK: add<4 x i64>
return|return
name|_mm256_add_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_adds_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_adds_epi8
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.padds.b(<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_adds_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_adds_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_adds_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.padds.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_adds_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_adds_epu8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_adds_epu8
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.paddus.b(<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_adds_epu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_adds_epu16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_adds_epu16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.paddus.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_adds_epu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_alignr_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_alignr_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 32, i32 33, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30, i32 31, i32 48, i32 49>
return|return
name|_mm256_alignr_epi8
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
name|__m256i
name|test2_mm256_alignr_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test2_mm256_alignr_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> zeroinitializer,<32 x i32><i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 32, i32 17, i32 18, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30, i32 31, i32 48>
return|return
name|_mm256_alignr_epi8
argument_list|(
name|a
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
name|test_mm256_and_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_and_si256
comment|// CHECK: and<4 x i64>
return|return
name|_mm256_and_si256
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_andnot_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_andnot_si256
comment|// CHECK: xor<4 x i64>
comment|// CHECK: and<4 x i64>
return|return
name|_mm256_andnot_si256
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_avg_epu8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_avg_epu8
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.pavg.b(<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_avg_epu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_avg_epu16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_avg_epu16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.pavg.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_avg_epu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// FIXME: We should also lower the __builtin_ia32_pblendw128 (and similar)
end_comment

begin_comment
comment|// functions to this IR. In the future we could delete the corresponding
end_comment

begin_comment
comment|// intrinsic in LLVM if it's not being used anymore.
end_comment

begin_function
name|__m256i
name|test_mm256_blend_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_blend_epi16
comment|// CHECK-NOT: @llvm.x86.avx2.pblendw
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 0, i32 17, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 25, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm256_blend_epi16
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
name|__m128i
name|test_mm_blend_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_blend_epi32
comment|// CHECK-NOT: @llvm.x86.avx2.pblendd.128
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32><i32 4, i32 1, i32 6, i32 3>
return|return
name|_mm_blend_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0x35
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_blend_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_blend_epi32
comment|// CHECK-NOT: @llvm.x86.avx2.pblendd.256
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 8, i32 1, i32 10, i32 3, i32 12, i32 13, i32 6, i32 7>
return|return
name|_mm256_blend_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0x35
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_blendv_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|,
name|__m256i
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_blendv_epi8
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.pblendvb(<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_blendv_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_broadcastb_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_broadcastb_epi8
comment|// CHECK-NOT: @llvm.x86.avx2.pbroadcastb.128
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<16 x i32> zeroinitializer
return|return
name|_mm_broadcastb_epi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_broadcastb_epi8
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcastb_epi8
comment|// CHECK-NOT: @llvm.x86.avx2.pbroadcastb.256
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<32 x i32> zeroinitializer
return|return
name|_mm256_broadcastb_epi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_broadcastd_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_broadcastd_epi32
comment|// CHECK-NOT: @llvm.x86.avx2.pbroadcastd.128
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<4 x i32> zeroinitializer
return|return
name|_mm_broadcastd_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_broadcastd_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcastd_epi32
comment|// CHECK-NOT: @llvm.x86.avx2.pbroadcastd.256
comment|// CHECK: shufflevector<4 x i32> %{{.*}},<4 x i32> %{{.*}},<8 x i32> zeroinitializer
return|return
name|_mm256_broadcastd_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_broadcastq_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_broadcastq_epi64
comment|// CHECK-NOT: @llvm.x86.avx2.pbroadcastq.128
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<2 x i32> zeroinitializer
return|return
name|_mm_broadcastq_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_broadcastq_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcastq_epi64
comment|// CHECK-NOT: @llvm.x86.avx2.pbroadcastq.256
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32> zeroinitializer
return|return
name|_mm256_broadcastq_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_broadcastsd_pd
parameter_list|(
name|__m128d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_broadcastsd_pd
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<2 x i32> zeroinitializer
return|return
name|_mm_broadcastsd_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_broadcastsd_pd
parameter_list|(
name|__m128d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcastsd_pd
comment|// CHECK-NOT: @llvm.x86.avx2.vbroadcast.sd.pd.256
comment|// CHECK: shufflevector<2 x double> %{{.*}},<2 x double> %{{.*}},<4 x i32> zeroinitializer
return|return
name|_mm256_broadcastsd_pd
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_broadcastsi128_si256
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcastsi128_si256
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 0, i32 1>
return|return
name|_mm256_broadcastsi128_si256
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_broadcastss_ps
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_broadcastss_ps
comment|// CHECK-NOT: @llvm.x86.avx2.vbroadcast.ss.ps
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<4 x i32> zeroinitializer
return|return
name|_mm_broadcastss_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_broadcastss_ps
parameter_list|(
name|__m128
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcastss_ps
comment|// CHECK-NOT: @llvm.x86.avx2.vbroadcast.ss.ps.256
comment|// CHECK: shufflevector<4 x float> %{{.*}},<4 x float> %{{.*}},<8 x i32> zeroinitializer
return|return
name|_mm256_broadcastss_ps
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_broadcastw_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_broadcastw_epi16
comment|// CHECK-NOT: @llvm.x86.avx2.pbroadcastw.128
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<8 x i32> zeroinitializer
return|return
name|_mm_broadcastw_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_broadcastw_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_broadcastw_epi16
comment|// CHECK-NOT: @llvm.x86.avx2.pbroadcastw.256
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<16 x i32> zeroinitializer
return|return
name|_mm256_broadcastw_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_bslli_epi128
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_bslli_epi128
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 13, i32 14, i32 15, i32 32, i32 33, i32 34, i32 35, i32 36, i32 37, i32 38, i32 39, i32 40, i32 41, i32 42, i32 43, i32 44, i32 29, i32 30, i32 31, i32 48, i32 49, i32 50, i32 51, i32 52, i32 53, i32 54, i32 55, i32 56, i32 57, i32 58, i32 59, i32 60>
return|return
name|_mm256_bslli_epi128
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_bsrli_epi128
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_bsrli_epi128
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 32, i32 33, i32 34, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30, i32 31, i32 48, i32 49, i32 50>
return|return
name|_mm256_bsrli_epi128
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cmpeq_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmpeq_epi8
comment|// CHECK: icmp eq<32 x i8>
return|return
name|_mm256_cmpeq_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cmpeq_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmpeq_epi16
comment|// CHECK: icmp eq<16 x i16>
return|return
name|_mm256_cmpeq_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cmpeq_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmpeq_epi32
comment|// CHECK: icmp eq<8 x i32>
return|return
name|_mm256_cmpeq_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cmpeq_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmpeq_epi64
comment|// CHECK: icmp eq<4 x i64>
return|return
name|_mm256_cmpeq_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cmpgt_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmpgt_epi8
comment|// CHECK: icmp sgt<32 x i8>
return|return
name|_mm256_cmpgt_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cmpgt_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmpgt_epi16
comment|// CHECK: icmp sgt<16 x i16>
return|return
name|_mm256_cmpgt_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cmpgt_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmpgt_epi32
comment|// CHECK: icmp sgt<8 x i32>
return|return
name|_mm256_cmpgt_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cmpgt_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cmpgt_epi64
comment|// CHECK: icmp sgt<4 x i64>
return|return
name|_mm256_cmpgt_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepi8_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepi8_epi16
comment|// CHECK: sext<16 x i8> %{{.*}} to<16 x i16>
return|return
name|_mm256_cvtepi8_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepi8_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepi8_epi32
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: sext<8 x i8> %{{.*}} to<8 x i32>
return|return
name|_mm256_cvtepi8_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepi8_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepi8_epi64
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: sext<4 x i8> %{{.*}} to<4 x i64>
return|return
name|_mm256_cvtepi8_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepi16_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepi16_epi32
comment|// CHECK: sext<8 x i16> %{{.*}} to<8 x i32>
return|return
name|_mm256_cvtepi16_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepi16_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepi16_epi64
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: sext<4 x i16> %{{.*}} to<4 x i64>
return|return
name|_mm256_cvtepi16_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepi32_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepi32_epi64
comment|// CHECK: sext<4 x i32> %{{.*}} to<4 x i64>
return|return
name|_mm256_cvtepi32_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepu8_epi16
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepu8_epi16
comment|// CHECK: zext<16 x i8> %{{.*}} to<16 x i16>
return|return
name|_mm256_cvtepu8_epi16
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepu8_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepu8_epi32
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<8 x i32><i32 0, i32 1, i32 2, i32 3, i32 4, i32 5, i32 6, i32 7>
comment|// CHECK: zext<8 x i8> %{{.*}} to<8 x i32>
return|return
name|_mm256_cvtepu8_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepu8_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepu8_epi64
comment|// CHECK: shufflevector<16 x i8> %{{.*}},<16 x i8> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: zext<4 x i8> %{{.*}} to<4 x i64>
return|return
name|_mm256_cvtepu8_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepu16_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepu16_epi32
comment|// CHECK: zext<8 x i16> {{.*}} to<8 x i32>
return|return
name|_mm256_cvtepu16_epi32
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepu16_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepu16_epi64
comment|// CHECK: shufflevector<8 x i16> %{{.*}},<8 x i16> %{{.*}},<4 x i32><i32 0, i32 1, i32 2, i32 3>
comment|// CHECK: zext<4 x i16> %{{.*}} to<4 x i64>
return|return
name|_mm256_cvtepu16_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_cvtepu32_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_cvtepu32_epi64
comment|// CHECK: zext<4 x i32> %{{.*}} to<4 x i64>
return|return
name|_mm256_cvtepu32_epi64
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test0_mm256_extracti128_si256_0
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test0_mm256_extracti128_si256
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<2 x i32><i32 0, i32 1>
return|return
name|_mm256_extracti128_si256
argument_list|(
name|a
argument_list|,
literal|0
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test1_mm256_extracti128_si256_1
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test1_mm256_extracti128_si256
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<2 x i32><i32 2, i32 3>
return|return
name|_mm256_extracti128_si256
argument_list|(
name|a
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Immediate should be truncated to one bit.
end_comment

begin_function
name|__m128i
name|test2_mm256_extracti128_si256
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test2_mm256_extracti128_si256
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<2 x i32><i32 0, i32 1>
return|return
name|_mm256_extracti128_si256
argument_list|(
name|a
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_hadd_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hadd_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.phadd.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_hadd_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_hadd_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hadd_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.phadd.d(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_hadd_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_hadds_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hadds_epi16
comment|// CHECK:call<16 x i16> @llvm.x86.avx2.phadd.sw(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_hadds_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_hsub_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hsub_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.phsub.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_hsub_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_hsub_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hsub_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.phsub.d(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_hsub_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_hsubs_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_hsubs_epi16
comment|// CHECK:call<16 x i16> @llvm.x86.avx2.phsub.sw(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_hsubs_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_i32gather_epi32
parameter_list|(
name|int
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_i32gather_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.gather.d.d(<4 x i32> %{{.*}}, i8* %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 2)
return|return
name|_mm_i32gather_epi32
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_i32gather_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|int
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m128i
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mask_i32gather_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.gather.d.d(<4 x i32> %{{.*}}, i8* %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}}, i8 2)
return|return
name|_mm_mask_i32gather_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_i32gather_epi32
parameter_list|(
name|int
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_i32gather_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.gather.d.d.256(<8 x i32> %{{.*}}, i8* %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}, i8 2)
return|return
name|_mm256_i32gather_epi32
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_i32gather_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|int
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|,
name|__m256i
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mask_i32gather_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.gather.d.d.256(<8 x i32> %{{.*}}, i8* %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}}, i8 2)
return|return
name|_mm256_mask_i32gather_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_i32gather_epi64
parameter_list|(
name|long
name|long
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_i32gather_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.avx2.gather.d.q(<2 x i64> zeroinitializer, i8* %{{.*}},<4 x i32> %{{.*}},<2 x i64> %{{.*}}, i8 2)
return|return
name|_mm_i32gather_epi64
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_i32gather_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|long
name|long
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m128i
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mask_i32gather_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.avx2.gather.d.q(<2 x i64> %{{.*}}, i8* %{{.*}},<4 x i32> %{{.*}},<2 x i64> %{{.*}}, i8 2)
return|return
name|_mm_mask_i32gather_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_i32gather_epi64
parameter_list|(
name|long
name|long
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_i32gather_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.gather.d.q.256(<4 x i64> zeroinitializer, i8* %{{.*}},<4 x i32> %{{.*}},<4 x i64> %{{.*}}, i8 2)
return|return
name|_mm256_i32gather_epi64
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_i32gather_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|long
name|long
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m256i
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mask_i32gather_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.gather.d.q.256(<4 x i64> %{{.*}}, i8* %{{.*}},<4 x i32> %{{.*}},<4 x i64> %{{.*}}, i8 2)
return|return
name|_mm256_mask_i32gather_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_i32gather_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_i32gather_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK: call<2 x double> @llvm.x86.avx2.gather.d.pd(<2 x double> zeroinitializer, i8* %{{.*}},<4 x i32> %{{.*}},<2 x double> %{{.*}}, i8 2)
return|return
name|_mm_i32gather_pd
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_i32gather_pd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|double
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m128d
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mask_i32gather_pd
comment|// CHECK: call<2 x double> @llvm.x86.avx2.gather.d.pd(<2 x double> %{{.*}}, i8* %{{.*}},<4 x i32> %{{.*}},<2 x double> %{{.*}}, i8 2)
return|return
name|_mm_mask_i32gather_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_i32gather_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_i32gather_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<4 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i64> [[SEXT]] to<4 x double>
comment|// CHECK: call<4 x double> @llvm.x86.avx2.gather.d.pd.256(<4 x double> zeroinitializer, i8* %{{.*}},<4 x i32> %{{.*}},<4 x double> %{{.*}}, i8 2)
return|return
name|_mm256_i32gather_pd
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_i32gather_pd
parameter_list|(
name|__m256d
name|a
parameter_list|,
name|double
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m256d
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mask_i32gather_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx2.gather.d.pd.256(<4 x double> %{{.*}}, i8* %{{.*}},<4 x i32> %{{.*}},<4 x double> %{{.*}}, i8 2)
return|return
name|_mm256_mask_i32gather_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_i32gather_ps
parameter_list|(
name|float
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_i32gather_ps
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK: call<4 x float> @llvm.x86.avx2.gather.d.ps(<4 x float> zeroinitializer, i8* %{{.*}},<4 x i32> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm_i32gather_ps
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_i32gather_ps
parameter_list|(
name|__m128
name|a
parameter_list|,
name|float
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m128
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mask_i32gather_ps
comment|// CHECK: call<4 x float> @llvm.x86.avx2.gather.d.ps(<4 x float> %{{.*}}, i8* %{{.*}},<4 x i32> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm_mask_i32gather_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_i32gather_ps
parameter_list|(
name|float
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_i32gather_ps
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<8 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<8 x i1> [[CMP]] to<8 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<8 x i32> [[SEXT]] to<8 x float>
comment|// CHECK: call<8 x float> @llvm.x86.avx2.gather.d.ps.256(<8 x float> zeroinitializer, i8* %{{.*}},<8 x i32> %{{.*}},<8 x float> %{{.*}}, i8 2)
return|return
name|_mm256_i32gather_ps
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_mask_i32gather_ps
parameter_list|(
name|__m256
name|a
parameter_list|,
name|float
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|,
name|__m256
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mask_i32gather_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx2.gather.d.ps.256(<8 x float> %{{.*}}, i8* %{{.*}},<8 x i32> %{{.*}},<8 x float> %{{.*}}, i8 2)
return|return
name|_mm256_mask_i32gather_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_i64gather_epi32
parameter_list|(
name|int
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_i64gather_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.gather.q.d(<4 x i32> %{{.*}}, i8* %{{.*}},<2 x i64> %{{.*}},<4 x i32> %{{.*}}, i8 2)
return|return
name|_mm_i64gather_epi32
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_i64gather_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|int
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m128i
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mask_i64gather_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.gather.q.d(<4 x i32> %{{.*}}, i8* %{{.*}},<2 x i64> %{{.*}},<4 x i32> %{{.*}}, i8 2)
return|return
name|_mm_mask_i64gather_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_i64gather_epi32
parameter_list|(
name|int
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_i64gather_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.gather.q.d.256(<4 x i32> %{{.*}}, i8* %{{.*}},<4 x i64> %{{.*}},<4 x i32> %{{.*}}, i8 2)
return|return
name|_mm256_i64gather_epi32
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm256_mask_i64gather_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|int
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|,
name|__m128i
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mask_i64gather_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.gather.q.d.256(<4 x i32> %{{.*}}, i8* %{{.*}},<4 x i64> %{{.*}},<4 x i32> %{{.*}}, i8 2)
return|return
name|_mm256_mask_i64gather_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_i64gather_epi64
parameter_list|(
name|long
name|long
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_i64gather_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.avx2.gather.q.q(<2 x i64> zeroinitializer, i8* %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 2)
return|return
name|_mm_i64gather_epi64
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_mask_i64gather_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|long
name|long
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m128i
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mask_i64gather_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.avx2.gather.q.q(<2 x i64> %{{.*}}, i8* %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}}, i8 2)
return|return
name|_mm_mask_i64gather_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_i64gather_epi64
parameter_list|(
name|long
name|long
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_i64gather_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.gather.q.q.256(<4 x i64> zeroinitializer, i8* %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}, i8 2)
return|return
name|_mm256_i64gather_epi64
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mask_i64gather_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|long
name|long
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|,
name|__m256i
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mask_i64gather_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.gather.q.q.256(<4 x i64> %{{.*}}, i8* %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}}, i8 2)
return|return
name|_mm256_mask_i64gather_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_i64gather_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_i64gather_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<2 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<2 x i1> [[CMP]] to<2 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<2 x i64> [[SEXT]] to<2 x double>
comment|// CHECK: call<2 x double> @llvm.x86.avx2.gather.q.pd(<2 x double> zeroinitializer, i8* %{{.*}},<2 x i64> %{{.*}},<2 x double> %{{.*}}, i8 2)
return|return
name|_mm_i64gather_pd
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128d
name|test_mm_mask_i64gather_pd
parameter_list|(
name|__m128d
name|a
parameter_list|,
name|double
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m128d
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mask_i64gather_pd
comment|// CHECK: call<2 x double> @llvm.x86.avx2.gather.q.pd(<2 x double> %{{.*}}, i8* %{{.*}},<2 x i64> %{{.*}},<2 x double> %{{.*}}, i8 2)
return|return
name|_mm_mask_i64gather_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_i64gather_pd
parameter_list|(
name|double
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_i64gather_pd
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<4 x double>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i64>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i64> [[SEXT]] to<4 x double>
comment|// CHECK: call<4 x double> @llvm.x86.avx2.gather.q.pd.256(<4 x double> zeroinitializer, i8* %{{.*}},<4 x i64> %{{.*}},<4 x double> %{{.*}}, i8 2)
return|return
name|_mm256_i64gather_pd
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_mask_i64gather_pd
parameter_list|(
name|__m256d
name|a
parameter_list|,
name|double
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|,
name|__m256d
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mask_i64gather_pd
comment|// CHECK: call<4 x double> @llvm.x86.avx2.gather.q.pd.256(<4 x double> %{{.*}}, i8* %{{.*}},<4 x i64> %{{.*}},<4 x double> %{{.*}}, i8 2)
return|return
name|_mm256_mask_i64gather_pd
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_i64gather_ps
parameter_list|(
name|float
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_i64gather_ps
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK: call<4 x float> @llvm.x86.avx2.gather.q.ps(<4 x float> zeroinitializer, i8* %{{.*}},<2 x i64> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm_i64gather_ps
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm_mask_i64gather_ps
parameter_list|(
name|__m128
name|a
parameter_list|,
name|float
specifier|const
modifier|*
name|b
parameter_list|,
name|__m128i
name|c
parameter_list|,
name|__m128
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_mask_i64gather_ps
comment|// CHECK: call<4 x float> @llvm.x86.avx2.gather.q.ps(<4 x float> %{{.*}}, i8* %{{.*}},<2 x i64> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm_mask_i64gather_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_i64gather_ps
parameter_list|(
name|float
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_i64gather_ps
comment|// CHECK:         [[CMP:%.*]] = fcmp oeq<4 x float>
comment|// CHECK-NEXT:    [[SEXT:%.*]] = sext<4 x i1> [[CMP]] to<4 x i32>
comment|// CHECK-NEXT:    [[BC:%.*]] = bitcast<4 x i32> [[SEXT]] to<4 x float>
comment|// CHECK: call<4 x float> @llvm.x86.avx2.gather.q.ps.256(<4 x float> zeroinitializer, i8* %{{.*}},<4 x i64> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm256_i64gather_ps
argument_list|(
name|b
argument_list|,
name|c
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128
name|test_mm256_mask_i64gather_ps
parameter_list|(
name|__m128
name|a
parameter_list|,
name|float
specifier|const
modifier|*
name|b
parameter_list|,
name|__m256i
name|c
parameter_list|,
name|__m128
name|d
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mask_i64gather_ps
comment|// CHECK: call<4 x float> @llvm.x86.avx2.gather.q.ps.256(<4 x float> %{{.*}}, i8* %{{.*}},<4 x i64> %{{.*}},<4 x float> %{{.*}}, i8 2)
return|return
name|_mm256_mask_i64gather_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
name|c
argument_list|,
name|d
argument_list|,
literal|2
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test0_mm256_inserti128_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test0_mm256_inserti128_si256
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 4, i32 5, i32 2, i32 3>
return|return
name|_mm256_inserti128_si256
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
name|__m256i
name|test1_mm256_inserti128_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test1_mm256_inserti128_si256
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 4, i32 5>
return|return
name|_mm256_inserti128_si256
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|1
argument_list|)
return|;
block|}
end_function

begin_comment
comment|// Immediate should be truncated to one bit.
end_comment

begin_function
name|__m256i
name|test2_mm256_inserti128_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test2_mm256_inserti128_si256
comment|// CHECK: shufflevector<2 x i64> %{{.*}},<2 x i64> %{{.*}},<4 x i32><i32 0, i32 1, i32 undef, i32 undef>
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 4, i32 5, i32 2, i32 3>
return|return
name|_mm256_inserti128_si256
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
name|__m256i
name|test_mm256_madd_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_madd_epi16
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.pmadd.wd(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_madd_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maddubs_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_maddubs_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.pmadd.ub.sw(<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_maddubs_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskload_epi32
parameter_list|(
name|int
specifier|const
modifier|*
name|a
parameter_list|,
name|__m128i
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskload_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.maskload.d(i8* %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_maskload_epi32
argument_list|(
name|a
argument_list|,
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskload_epi32
parameter_list|(
name|int
specifier|const
modifier|*
name|a
parameter_list|,
name|__m256i
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_maskload_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.maskload.d.256(i8* %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_maskload_epi32
argument_list|(
name|a
argument_list|,
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_maskload_epi64
parameter_list|(
name|long
name|long
specifier|const
modifier|*
name|a
parameter_list|,
name|__m128i
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskload_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.avx2.maskload.q(i8* %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_maskload_epi64
argument_list|(
name|a
argument_list|,
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_maskload_epi64
parameter_list|(
name|long
name|long
specifier|const
modifier|*
name|a
parameter_list|,
name|__m256i
name|m
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_maskload_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.maskload.q.256(i8* %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_maskload_epi64
argument_list|(
name|a
argument_list|,
name|m
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|test_mm_maskstore_epi32
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|__m128i
name|m
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskstore_epi32
comment|// CHECK: call void @llvm.x86.avx2.maskstore.d(i8* %{{.*}},<4 x i32> %{{.*}},<4 x i32> %{{.*}})
name|_mm_maskstore_epi32
argument_list|(
name|a
argument_list|,
name|m
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_maskstore_epi32
parameter_list|(
name|int
modifier|*
name|a
parameter_list|,
name|__m256i
name|m
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_maskstore_epi32
comment|// CHECK: call void @llvm.x86.avx2.maskstore.d.256(i8* %{{.*}},<8 x i32> %{{.*}},<8 x i32> %{{.*}})
name|_mm256_maskstore_epi32
argument_list|(
name|a
argument_list|,
name|m
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm_maskstore_epi64
parameter_list|(
name|long
name|long
modifier|*
name|a
parameter_list|,
name|__m128i
name|m
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_maskstore_epi64
comment|// CHECK: call void @llvm.x86.avx2.maskstore.q(i8* %{{.*}},<2 x i64> %{{.*}},<2 x i64> %{{.*}})
name|_mm_maskstore_epi64
argument_list|(
name|a
argument_list|,
name|m
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|test_mm256_maskstore_epi64
parameter_list|(
name|long
name|long
modifier|*
name|a
parameter_list|,
name|__m256i
name|m
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_maskstore_epi64
comment|// CHECK: call void @llvm.x86.avx2.maskstore.q.256(i8* %{{.*}},<4 x i64> %{{.*}},<4 x i64> %{{.*}})
name|_mm256_maskstore_epi64
argument_list|(
name|a
argument_list|,
name|m
argument_list|,
name|b
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_max_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_max_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
return|return
name|_mm256_max_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_max_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_max_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
return|return
name|_mm256_max_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_max_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_max_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp sgt<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
return|return
name|_mm256_max_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_max_epu8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_max_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
return|return
name|_mm256_max_epu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_max_epu16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_max_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
return|return
name|_mm256_max_epu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_max_epu32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_max_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ugt<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
return|return
name|_mm256_max_epu32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_min_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_min_epi8
comment|// CHECK:       [[CMP:%.*]] = icmp slt<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
return|return
name|_mm256_min_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_min_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_min_epi16
comment|// CHECK:       [[CMP:%.*]] = icmp slt<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
return|return
name|_mm256_min_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_min_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_min_epi32
comment|// CHECK:       [[CMP:%.*]] = icmp slt<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
return|return
name|_mm256_min_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_min_epu8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_min_epu8
comment|// CHECK:       [[CMP:%.*]] = icmp ult<32 x i8> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<32 x i1> [[CMP]],<32 x i8> [[X]],<32 x i8> [[Y]]
return|return
name|_mm256_min_epu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_min_epu16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_min_epu16
comment|// CHECK:       [[CMP:%.*]] = icmp ult<16 x i16> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<16 x i1> [[CMP]],<16 x i16> [[X]],<16 x i16> [[Y]]
return|return
name|_mm256_min_epu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_min_epu32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_min_epu32
comment|// CHECK:       [[CMP:%.*]] = icmp ult<8 x i32> [[X:%.*]], [[Y:%.*]]
comment|// CHECK-NEXT:  select<8 x i1> [[CMP]],<8 x i32> [[X]],<8 x i32> [[Y]]
return|return
name|_mm256_min_epu32
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
name|test_mm256_movemask_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_movemask_epi8
comment|// CHECK: call i32 @llvm.x86.avx2.pmovmskb(<32 x i8> %{{.*}})
return|return
name|_mm256_movemask_epi8
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mpsadbw_epu8
parameter_list|(
name|__m256i
name|x
parameter_list|,
name|__m256i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mpsadbw_epu8
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.mpsadbw(<32 x i8> %{{.*}},<32 x i8> %{{.*}}, i8 3)
return|return
name|_mm256_mpsadbw_epu8
argument_list|(
name|x
argument_list|,
name|y
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mul_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mul_epi32
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.pmul.dq(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_mul_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mul_epu32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mul_epu32
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.pmulu.dq(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_mul_epu32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mulhi_epu16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mulhi_epu16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.pmulhu.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_mulhi_epu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mulhi_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mulhi_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.pmulh.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_mulhi_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mulhrs_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mulhrs_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.pmul.hr.sw(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_mulhrs_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mullo_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mullo_epi16
comment|// CHECK: mul<16 x i16>
return|return
name|_mm256_mullo_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_mullo_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_mullo_epi32
comment|// CHECK: mul<8 x i32>
return|return
name|_mm256_mullo_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_or_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_or_si256
comment|// CHECK: or<4 x i64>
return|return
name|_mm256_or_si256
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_packs_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_packs_epi16
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.packsswb(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_packs_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_packs_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_packs_epi32
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.packssdw(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_packs_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_packs_epu16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_packs_epu16
comment|// CHECK:  call<32 x i8> @llvm.x86.avx2.packuswb(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_packus_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_packs_epu32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_packs_epu32
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.packusdw(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_packus_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_permute2x128_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute2x128_si256
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.vperm2i128(<4 x i64> %{{.*}},<4 x i64> %{{.*}}, i8 49)
return|return
name|_mm256_permute2x128_si256
argument_list|(
name|a
argument_list|,
name|b
argument_list|,
literal|0x31
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_permute4x64_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute4x64_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> zeroinitializer,<4 x i32><i32 3, i32 0, i32 2, i32 0>
return|return
name|_mm256_permute4x64_epi64
argument_list|(
name|a
argument_list|,
literal|35
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256d
name|test_mm256_permute4x64_pd
parameter_list|(
name|__m256d
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permute4x64_pd
comment|// CHECK: shufflevector<4 x double> %{{.*}},<4 x double> zeroinitializer,<4 x i32><i32 1, i32 2, i32 1, i32 0>
return|return
name|_mm256_permute4x64_pd
argument_list|(
name|a
argument_list|,
literal|25
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_permutevar8x32_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permutevar8x32_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.permd(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_permutevar8x32_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256
name|test_mm256_permutevar8x32_ps
parameter_list|(
name|__m256
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_permutevar8x32_ps
comment|// CHECK: call<8 x float> @llvm.x86.avx2.permps(<8 x float> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_permutevar8x32_ps
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sad_epu8
parameter_list|(
name|__m256i
name|x
parameter_list|,
name|__m256i
name|y
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sad_epu8
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.psad.bw(<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_sad_epu8
argument_list|(
name|x
argument_list|,
name|y
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_shuffle_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_shuffle_epi8
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.pshuf.b(<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_shuffle_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_shuffle_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_shuffle_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 3, i32 3, i32 0, i32 0, i32 7, i32 7, i32 4, i32 4>
return|return
name|_mm256_shuffle_epi32
argument_list|(
name|a
argument_list|,
literal|15
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_shufflehi_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_shufflehi_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 0, i32 1, i32 2, i32 3, i32 7, i32 6, i32 6, i32 5, i32 8, i32 9, i32 10, i32 11, i32 15, i32 14, i32 14, i32 13>
return|return
name|_mm256_shufflehi_epi16
argument_list|(
name|a
argument_list|,
literal|107
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_shufflelo_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_shufflelo_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 3, i32 0, i32 1, i32 1, i32 4, i32 5, i32 6, i32 7, i32 11, i32 8, i32 9, i32 9, i32 12, i32 13, i32 14, i32 15>
return|return
name|_mm256_shufflelo_epi16
argument_list|(
name|a
argument_list|,
literal|83
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sign_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sign_epi8
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.psign.b(<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_sign_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sign_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sign_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.psign.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_sign_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sign_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sign_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.psign.d(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_sign_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_slli_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_slli_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.pslli.w(<16 x i16> %{{.*}}, i32 %{{.*}})
return|return
name|_mm256_slli_epi16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_slli_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_slli_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.pslli.d(<8 x i32> %{{.*}}, i32 %{{.*}})
return|return
name|_mm256_slli_epi32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_slli_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_slli_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.pslli.q(<4 x i64> %{{.*}}, i32 %{{.*}})
return|return
name|_mm256_slli_epi64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_slli_si256
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_slli_si256
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 13, i32 14, i32 15, i32 32, i32 33, i32 34, i32 35, i32 36, i32 37, i32 38, i32 39, i32 40, i32 41, i32 42, i32 43, i32 44, i32 29, i32 30, i32 31, i32 48, i32 49, i32 50, i32 51, i32 52, i32 53, i32 54, i32 55, i32 56, i32 57, i32 58, i32 59, i32 60>
return|return
name|_mm256_slli_si256
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sllv_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sllv_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.psllv.d(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_sllv_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sllv_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sllv_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.psllv.d.256(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_sllv_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_sllv_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_sllv_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.avx2.psllv.q(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_sllv_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sllv_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sllv_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.psllv.q.256(<4 x i64> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_sllv_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sra_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sra_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.psra.w(<16 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm256_sra_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sra_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sra_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.psra.d(<8 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm256_sra_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srai_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srai_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.psrai.w(<16 x i16> %{{.*}}, i32 %{{.*}})
return|return
name|_mm256_srai_epi16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srai_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srai_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.psrai.d(<8 x i32> %{{.*}}, i32 %{{.*}})
return|return
name|_mm256_srai_epi32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srav_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srav_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.psrav.d(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_srav_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srav_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srav_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.psrav.d.256(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_srav_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srl_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srl_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.psrl.w(<16 x i16> %{{.*}},<8 x i16> %{{.*}})
return|return
name|_mm256_srl_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srl_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srl_epi32
comment|// CHECK:call<8 x i32> @llvm.x86.avx2.psrl.d(<8 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm256_srl_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srl_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srl_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.psrl.q(<4 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm256_srl_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srli_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srli_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.psrli.w(<16 x i16> %{{.*}}, i32 %{{.*}})
return|return
name|_mm256_srli_epi16
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srli_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srli_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.psrli.d(<8 x i32> %{{.*}}, i32 %{{.*}})
return|return
name|_mm256_srli_epi32
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srli_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srli_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.psrli.q(<4 x i64> %{{.*}}, i32 %{{.*}})
return|return
name|_mm256_srli_epi64
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srli_si256
parameter_list|(
name|__m256i
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srli_si256
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 3, i32 4, i32 5, i32 6, i32 7, i32 8, i32 9, i32 10, i32 11, i32 12, i32 13, i32 14, i32 15, i32 32, i32 33, i32 34, i32 19, i32 20, i32 21, i32 22, i32 23, i32 24, i32 25, i32 26, i32 27, i32 28, i32 29, i32 30, i32 31, i32 48, i32 49, i32 50>
return|return
name|_mm256_srli_si256
argument_list|(
name|a
argument_list|,
literal|3
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srlv_epi32
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srlv_epi32
comment|// CHECK: call<4 x i32> @llvm.x86.avx2.psrlv.d(<4 x i32> %{{.*}},<4 x i32> %{{.*}})
return|return
name|_mm_srlv_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srlv_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srlv_epi32
comment|// CHECK: call<8 x i32> @llvm.x86.avx2.psrlv.d.256(<8 x i32> %{{.*}},<8 x i32> %{{.*}})
return|return
name|_mm256_srlv_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m128i
name|test_mm_srlv_epi64
parameter_list|(
name|__m128i
name|a
parameter_list|,
name|__m128i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm_srlv_epi64
comment|// CHECK: call<2 x i64> @llvm.x86.avx2.psrlv.q(<2 x i64> %{{.*}},<2 x i64> %{{.*}})
return|return
name|_mm_srlv_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_srlv_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_srlv_epi64
comment|// CHECK: call<4 x i64> @llvm.x86.avx2.psrlv.q.256(<4 x i64> %{{.*}},<4 x i64> %{{.*}})
return|return
name|_mm256_srlv_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_stream_load_si256
parameter_list|(
name|__m256i
specifier|const
modifier|*
name|a
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_stream_load_si256
comment|// CHECK: load<4 x i64>,<4 x i64>* %{{.*}}, align 32, !nontemporal
return|return
name|_mm256_stream_load_si256
argument_list|(
name|a
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sub_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sub_epi8
comment|// CHECK: sub<32 x i8>
return|return
name|_mm256_sub_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sub_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sub_epi16
comment|// CHECK: sub<16 x i16>
return|return
name|_mm256_sub_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sub_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sub_epi32
comment|// CHECK: sub<8 x i32>
return|return
name|_mm256_sub_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_sub_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_sub_epi64
comment|// CHECK: sub<4 x i64>
return|return
name|_mm256_sub_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_subs_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_subs_epi8
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.psubs.b(<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_subs_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_subs_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_subs_epi16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.psubs.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_subs_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_subs_epu8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_subs_epu8
comment|// CHECK: call<32 x i8> @llvm.x86.avx2.psubus.b(<32 x i8> %{{.*}},<32 x i8> %{{.*}})
return|return
name|_mm256_subs_epu8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_subs_epu16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_subs_epu16
comment|// CHECK: call<16 x i16> @llvm.x86.avx2.psubus.w(<16 x i16> %{{.*}},<16 x i16> %{{.*}})
return|return
name|_mm256_subs_epu16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_unpackhi_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpackhi_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 8, i32 40, i32 9, i32 41, i32 10, i32 42, i32 11, i32 43, i32 12, i32 44, i32 13, i32 45, i32 14, i32 46, i32 15, i32 47, i32 24, i32 56, i32 25, i32 57, i32 26, i32 58, i32 27, i32 59, i32 28, i32 60, i32 29, i32 61, i32 30, i32 62, i32 31, i32 63>
return|return
name|_mm256_unpackhi_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_unpackhi_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpackhi_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 4, i32 20, i32 5, i32 21, i32 6, i32 22, i32 7, i32 23, i32 12, i32 28, i32 13, i32 29, i32 14, i32 30, i32 15, i32 31>
return|return
name|_mm256_unpackhi_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_unpackhi_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpackhi_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 2, i32 10, i32 3, i32 11, i32 6, i32 14, i32 7, i32 15>
return|return
name|_mm256_unpackhi_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_unpackhi_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpackhi_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 1, i32 5, i32 3, i32 7>
return|return
name|_mm256_unpackhi_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_unpacklo_epi8
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpacklo_epi8
comment|// CHECK: shufflevector<32 x i8> %{{.*}},<32 x i8> %{{.*}},<32 x i32><i32 0, i32 32, i32 1, i32 33, i32 2, i32 34, i32 3, i32 35, i32 4, i32 36, i32 5, i32 37, i32 6, i32 38, i32 7, i32 39, i32 16, i32 48, i32 17, i32 49, i32 18, i32 50, i32 19, i32 51, i32 20, i32 52, i32 21, i32 53, i32 22, i32 54, i32 23, i32 55>
return|return
name|_mm256_unpacklo_epi8
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_unpacklo_epi16
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpacklo_epi16
comment|// CHECK: shufflevector<16 x i16> %{{.*}},<16 x i16> %{{.*}},<16 x i32><i32 0, i32 16, i32 1, i32 17, i32 2, i32 18, i32 3, i32 19, i32 8, i32 24, i32 9, i32 25, i32 10, i32 26, i32 11, i32 27>
return|return
name|_mm256_unpacklo_epi16
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_unpacklo_epi32
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpacklo_epi32
comment|// CHECK: shufflevector<8 x i32> %{{.*}},<8 x i32> %{{.*}},<8 x i32><i32 0, i32 8, i32 1, i32 9, i32 4, i32 12, i32 5, i32 13>
return|return
name|_mm256_unpacklo_epi32
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_unpacklo_epi64
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_unpacklo_epi64
comment|// CHECK: shufflevector<4 x i64> %{{.*}},<4 x i64> %{{.*}},<4 x i32><i32 0, i32 4, i32 2, i32 6>
return|return
name|_mm256_unpacklo_epi64
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

begin_function
name|__m256i
name|test_mm256_xor_si256
parameter_list|(
name|__m256i
name|a
parameter_list|,
name|__m256i
name|b
parameter_list|)
block|{
comment|// CHECK-LABEL: test_mm256_xor_si256
comment|// CHECK: xor<4 x i64>
return|return
name|_mm256_xor_si256
argument_list|(
name|a
argument_list|,
name|b
argument_list|)
return|;
block|}
end_function

end_unit

